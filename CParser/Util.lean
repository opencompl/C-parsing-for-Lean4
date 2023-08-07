import Lean
import CParser.Token

-- import Lean.Parser.Types

open Lean Parser Elab.Command

abbrev ParseError := String

def addTokenTableOfCategory (accum : TokenTable) (cat : Name) : MetaM TokenTable := do
  let categories := (parserExtension.getState (← getEnv)).categories
  let cat := getCategory categories cat |>.get!
  let mut tt := accum
  for (k, _) in cat.kinds do
    let (_, p) ← mkParserOfConstant categories k
    tt := p.info.collectTokens [] |>.filter (λ t => t ≠ ",*" && t ≠ ",+")
                                  |>.foldl (fun tt tk => tt.insert tk tk) tt
  return tt

def categoriesList : List Name :=
[`primary_expression,
`type_specifier,
`translation_unit,
`external_declaration]

def cTokenTable := categoriesList.foldlM (addTokenTableOfCategory) ∅

-- Get the identifier out of an init_declarator
partial def getIdFrom (s : Syntax) : String := match s.getKind.toString, s.getArgs with
  | "«init_declarator_=_»", #[decl, _] => getIdFrom decl
  | "declarator__", #[_, dirDecl] => getIdFrom dirDecl
  | "direct_declarator_", #[id] => id.getId.toString
  | "«direct_declarator(_)»", #[_, decl, _] => getIdFrom decl
  | "«direct_declarator_[_]»", #[dirDecl, _, _, _] => getIdFrom dirDecl
  | "«direct_declarator_[]»", #[dirDecl, _, _] => getIdFrom dirDecl
  | "«direct_declarator_(_)»", #[dirDecl, _, _, _] => getIdFrom dirDecl
  | "«direct_declarator_()»", #[dirDecl, _, _] => getIdFrom dirDecl
  | _, _ => "" -- only commas
 
def stringToCommand (stx : Syntax) (s : String) : CommandElabM PUnit := do
  let stratom : TSyntax `str := ⟨Syntax.mkStrLit $ s⟩
  let stxstx : Array (TSyntax `stx) := #[← `(stx| $stratom:str)]
  let cat := mkIdentFrom stx `type_name_token
  let newDec ← `(syntax $[$stxstx]* : $cat)
  elabCommand newDec

partial def runParserCategoryTranslationUnitHelper
                                                   (ictx : InputContext)
                                                   (s : ParserState)
                                                   (fileName := "<input>")
                                                   (stack : List Syntax) : CommandElabM $ List Syntax :=
   do 
   let p := andthenFn CParser.whitespace (categoryParserFnImpl `external_declaration)
   let env ← getEnv
   let tt ← liftTermElabM cTokenTable
   let s := p.run { ictx with
     env
     options := {}
     prec := 0
     tokens := tt
     tokenFn := CParser.tokenFnCore
   } (s.setCache $ initCacheForInput ictx.input)
   if s.hasError then throwError (s.toErrorMsg ictx ++ " " ++ toString s.stxStack.back) else
   let stx := s.stxStack.back
   let stack := stack.cons stx
   if (s.pos.byteIdx ≥ ictx.input.length) then return stack else
   match stx with
    | (Syntax.node _ _ -- external declaration
        #[(Syntax.node _ _ -- declaration
           #[(Syntax.node _ _ -- declaration specifiers
               #[(Syntax.node _ _ -- storage class specifier
                   #[Lean.Syntax.atom _ "typedef"]),
                 (Syntax.node _ _ _ -- declaration specifiers
                 )]),
             (Syntax.node _ _ -- null
               #[Syntax.node _ _ -- init declarator list
                  #[Syntax.node _ _ -- null
                     initDeclList]]),
             (Lean.Syntax.atom _ ";")])]) => let newTypeNames : Array String := .filter (λ s => s.length > 0) $
                                                                                  .map getIdFrom initDeclList
                                             let _ ←  Array.mapM (stringToCommand stx) newTypeNames
                                             runParserCategoryTranslationUnitHelper ictx s fileName stack
    | _ => runParserCategoryTranslationUnitHelper ictx s fileName stack

def runParserCategoryTranslationUnit (input : String) (fileName := "<input>") : CommandElabM Syntax :=
   do
      let extDecls ← runParserCategoryTranslationUnitHelper (mkInputContext input fileName) (mkParserState input) fileName []
      -- dbg_trace extDecls
      let info := (extDecls.get! 0).getHeadInfo
      return Syntax.node1 info `translation_unit_ $
              Syntax.node info `null extDecls.toArray.reverse


-- Note: Problem might be here
def runParserCategoryDbg (env : Environment) (catName : Name) (input : String) (fileName := "<input>")
    (tokenFn := tokenFnCore) : Except String Syntax :=
  let p := andthenFn whitespace (categoryParserFnImpl catName)
  let c := { mkInputContext input fileName with
    tokens := getTokenTable env
    env
    options := {}
    prec := 0
    tokenFn := tokenFn
  }
  
  -- dbg_trace input -- char: char, void: void

  let s := p.run c (mkParserState input)

  -- dbg_trace c.tokens         -- this does contain char
  dbg_trace s.hasError          -- char: false, void: true
  dbg_trace s.stxStack.back     -- char: (primary_expression__2 "char"), void: <missing>

  if s.hasError then
    Except.error (s.toErrorMsg c.toInputContext)
  else if input.atEnd s.pos then
    Except.ok s.stxStack.back
  else
    Except.error ((s.mkError "end of input").toErrorMsg c.toInputContext)


private def mkParseFun {α : Type} (syntaxcat : Name) (ntparser : Syntax → Except ParseError α) :
String → Environment → CommandElabM α := λ s env =>
  if syntaxcat == `translation_unit then do
  let stx ← runParserCategoryTranslationUnit s
  IO.ofExcept $ ntparser stx
 else
  dbg_trace s
  IO.ofExcept $ runParserCategoryDbg env syntaxcat s (tokenFn := CParser.tokenFnCore) >>= ntparser
  -- IO.ofExcept $ runParserCategory env syntaxcat s (tokenFn := CParser.tokenFnCore) >>= ntparser

-- Create a parser for a syntax category named `syntaxcat`, which uses `ntparser` to read a syntax node and produces a value α, or an error.
-- This returns a function that given a string `s` and an environment `env`, tries to parse the string, and produces an error.
def mkNonTerminalParser {α : Type}  (syntaxcat : Name) (ntparser : Syntax → Except ParseError α)
(s : String) (env : Environment) : CommandElabM α :=
  let parseFun := mkParseFun syntaxcat ntparser
  parseFun s env
