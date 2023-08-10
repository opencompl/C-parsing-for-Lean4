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

private def mkResultDbg (s : ParserState) (iniSz : Nat) : ParserState :=
  if s.stackSize == iniSz + 1 then s
  else s.mkNode nullKind iniSz -- throw error instead?

def indexedDbg (map : TokenMap (Parser × Nat)) (c : ParserContext) (s : ParserState) (behavior : LeadingIdentBehavior) : ParserState × List (Parser × Nat) :=
  -- dbg_trace "index"
  -- dbg_trace c.input
  let (s, stx) := peekToken c s
  dbg_trace map.toList.map (fun x => toString x.fst)
  let find (n : Name) : ParserState × List (Parser × Nat) :=
    match map.find? n with
    -- | some as => dbg_trace as[0]!.fst.info.firstTokens
    --              (s, as)
    | some as => (s, as)
    | _       => dbg_trace ("not found " ++ n.toString)   -- void: not found void, does not reach here for char
                 (s, [])
  match stx with
  | .ok (.atom _ sym)      => dbg_trace ("atom " ++ sym)
                              find (.mkSimple sym)
  -- Commenting this out seems to have fixed the issue
  -- We suspect that it is because the input passed was mapping to the possible Lean identifiers that are present in the syntax
  -- Since char is the only atom in lean which is also in our token table, the issue only arises for char

  | .ok (.ident _ _ val _) => dbg_trace ("ident " ++ val)
    match behavior with
    | .default => find identKind
    | .symbol =>
      match map.find? val with
      | some as => (s, as)
      | none    => find identKind
    | .both =>
      match map.find? val with
      | some as =>
        if val == identKind then
          (s, as)  -- avoid running the same parsers twice
        else
          match map.find? identKind with
          | some as' => (s, as ++ as')
          | _        => (s, as)
      | none    => find identKind
  | .ok (.node _ k _) => find k
  | .ok _             => (s, [])
  | .error s'         => (s', [])


def runLongestMatchParserDbg (left? : Option Syntax) (startLhsPrec : Nat) (p : ParserFn) : ParserFn := fun c s => Id.run do
  let mut s := { s with lhsPrec := if left?.isSome then startLhsPrec else maxPrec }
  let startSize := s.stackSize
  if let some left := left? then
    s := s.pushSyntax left
  s := p c s
  -- stack contains `[..., result ]`
  if s.stackSize == startSize + 1 then
    s -- success or error with the expected number of nodes
  else if s.hasError then
    -- error with an unexpected number of nodes.
    s.shrinkStack startSize |>.pushSyntax Syntax.missing
  else
    -- parser succeded with incorrect number of nodes
    invalidLongestMatchParser s

def longestMatchFnDbg (left? : Option Syntax) : List (Parser × Nat) → ParserFn
  | []    => fun _ s => s.mkError "longestMatch: empty list"
  | [p]   => fun c s => -- dbg_trace "case 2"
                        runLongestMatchParserDbg left? s.lhsPrec p.1.fn c s
  | p::ps => fun c s =>
    let startSize := s.stackSize
    let startLhsPrec := s.lhsPrec
    let startPos  := s.pos
    let s         := runLongestMatchParserDbg left? s.lhsPrec p.1.fn c s
    longestMatchFnAux left? startSize startLhsPrec startPos p.2 ps c s

def leadingParserAuxDbg (kind : Name) (tables : PrattParsingTables) (behavior : LeadingIdentBehavior) : ParserFn := fun c s => Id.run do
  let iniSz   := s.stackSize
  let (s, ps) := indexedDbg tables.leadingTable c s behavior
  if s.hasError then
    return s
  let ps      := tables.leadingParsers ++ ps
  -- dbg_trace ps.isEmpty -- char: false, void: true
  -- if !ps.isEmpty then dbg_trace ps[0]!.snd
  if ps.isEmpty then
    return s.mkError (toString kind)
  let s := longestMatchFnDbg none ps c s
  mkResultDbg s iniSz

def leadingParserDbg (kind : Name) (tables : PrattParsingTables) (behavior : LeadingIdentBehavior) (antiquotParser : ParserFn) : ParserFn :=
  withAntiquotFn (isCatAntiquot := true) antiquotParser (leadingParserAuxDbg kind tables behavior)


def prattParserDbg (kind : Name) (tables : PrattParsingTables) (behavior : LeadingIdentBehavior) (antiquotParser : ParserFn) : ParserFn := fun c s =>
  let s := leadingParserDbg kind tables behavior antiquotParser c s
  -- dbg_trace "pratt"
  -- dbg_trace s.hasError -- char: false, void: true
  if s.hasError then
    s
  else
    trailingLoop tables c s

-- helper decl to work around inlining issue https://github.com/leanprover/lean4/commit/3f6de2af06dd9a25f62294129f64bc05a29ea912#r41340377
@[inline] private def mkCategoryAntiquotParserFnDbg (kind : Name) : ParserFn :=
dbg_trace "CALLED"
  (mkCategoryAntiquotParser kind).fn

def categoryParserFnImplDbg (catName : Name) : ParserFn := fun ctx s => 
  -- dbg_trace "ctx"
  -- dbg_trace ctx.input  -- char: char
  let catName := if catName == `syntax then `stx else catName
  let categories := (parserExtension.getState ctx.env).categories
  -- dbg_trace catName
  match getCategory categories catName with
  | some cat =>
    -- dbg_trace cat.declName -- Lean.Parser.Category.primary_expression for both
    dbg_trace (cat.tables.leadingTable.toList.map Prod.fst)
    prattParserDbg catName cat.tables cat.behavior (mkCategoryAntiquotParserFnDbg catName) ctx s
  | none     => s.mkUnexpectedError ("unknown parser category '" ++ toString catName ++ "'")

def mkParserStateDbg (input : String) : ParserState :=
  -- dbg_trace input.endPos
  { cache := initCacheForInput input }

-- Note: Problem might be here
def runParserCategoryDbg (env : Environment) (catName : Name) (input : String) (fileName := "<input>")
    (tokenFn := tokenFnCore) : Except String Syntax :=
  let p := andthenFn whitespace (categoryParserFnImplDbg catName)
  let c := { mkInputContext input fileName with
    tokens := getTokenTable env
    env
    options := {}
    prec := 0
    tokenFn := tokenFn
  }
  
  -- dbg_trace input -- char: char, void: void
  -- let st := mkParserStateDbg input
  -- dbg_trace st.stxStack.back
  let s := p.run c (mkParserStateDbg input)
  -- let s := p.run c (mkParserState input)

  -- dbg_trace c.tokens         -- this does contain char
  -- dbg_trace s.hasError          -- char: false, void: true
  -- dbg_trace s.stxStack.back     -- char: (primary_expression__2 "char"), void: <missing>

  if s.hasError then
    Except.error (s.toErrorMsg c.toInputContext)
  else if input.atEnd s.pos then
    Except.ok s.stxStack.back
  else
    Except.error ((s.mkError "end of input").toErrorMsg c.toInputContext)


private def mkParseFun {α : Type} [ToString α] (syntaxcat : Name) (ntparser : Syntax → Except ParseError α) :
String → Environment → CommandElabM α := λ s env =>
  if syntaxcat == `translation_unit then do
  let stx ← runParserCategoryTranslationUnit s
  IO.ofExcept $ ntparser stx
 else
  -- dbg_trace s
  let stx := runParserCategoryDbg env syntaxcat s (tokenFn := CParser.tokenFnCore)
  -- dbg_trace stx.map toString
  let stx2 := Except.map ntparser stx
  -- dbg_trace stx2.map toString
  IO.ofExcept $ runParserCategoryDbg env syntaxcat s (tokenFn := CParser.tokenFnCore) >>= ntparser
  -- IO.ofExcept $ runParserCategory env syntaxcat s (tokenFn := CParser.tokenFnCore) >>= ntparser

-- Create a parser for a syntax category named `syntaxcat`, which uses `ntparser` to read a syntax node and produces a value α, or an error.
-- This returns a function that given a string `s` and an environment `env`, tries to parse the string, and produces an error.
def mkNonTerminalParser {α : Type} [ToString α] (syntaxcat : Name) (ntparser : Syntax → Except ParseError α)
(s : String) (env : Environment) : CommandElabM α :=
  let parseFun := mkParseFun syntaxcat ntparser
  parseFun s env
