import Lean
import CParser.Token

-- import Lean.Parser.Types

open Lean Parser Elab.Command

def substituteBackslashTailH (dummy : Bool) (inString : Bool) (input : List Char) (accum : List Char) : List Char :=
  match input with
    | []               => accum.reverse
--    | '\\' :: '0' :: cs => substituteBackslashTailH dummy inString cs ('\u0000' :: accum)
    | '\\' :: 'a' :: cs => substituteBackslashTailH dummy inString cs ('\u0007' :: accum)
    | '\\' :: 'b' :: cs => substituteBackslashTailH dummy inString cs ('\u0008' :: accum)
    | '\\' :: 'e' :: cs => substituteBackslashTailH dummy inString cs ('\u001B' :: accum)
    | '\\' :: 'f' :: cs => substituteBackslashTailH dummy inString cs ('\u000C' :: accum)
    | '\\' :: 'v' :: cs => substituteBackslashTailH dummy inString cs ('\u000B' :: accum)
    | '\\' :: '?' :: cs => substituteBackslashTailH dummy inString cs ('\u003F' :: accum)
    | '\\' :: '\\' :: cs => substituteBackslashTailH dummy inString cs ('\\' :: '\\' :: accum)
    |  c   :: cs    => substituteBackslashTailH dummy inString cs (c :: accum)

def wrapHelperTail (helper : Bool → Bool → List Char → List Char → List Char) : (String → String) :=
  λ i => let charList := helper false false i.toList []
         charList.foldl (λ a b => a ++ b.toString) ""

def substituteBackslash      := wrapHelperTail substituteBackslashTailH

def makeSubstitution := substituteBackslash

abbrev ParseError := String

def addTokenTableOfCategory (accum : TokenTable) (cat : Name) : MetaM TokenTable := do
  let categories := (parserExtension.getState (← getEnv)).categories
  let cat := getCategory categories cat |>.get!
  let mut tt := accum
  for (k, _) in cat.kinds do
    let (_, p) ← mkParserOfConstant categories k
    tt := p.info.collectTokens [] |>.foldl (fun tt tk => tt.insert tk tk) tt
  return tt

def categoriesList : List Name :=
[`extended_num,
`primary_expression,
`postfix_expression,
`argument_expression_list,
`unary_expression,
`unary_operator,
`cast_expression,
`multiplicative_expression,
`additive_expression,
`shift_expression,
`relational_expression,
`equality_expression,
`and_expression,
`exclusive_or_expression,
`inclusive_or_expression,
`logical_and_expression,
`logical_or_expression,
`conditional_expression,
`assignment_expression,
`assignment_operator,
`expression,
`constant_expression,
`declaration,
`declaration_specifiers,
`init_declarator_list,
`init_declarator,
`storage_class_specifier,
`type_specifier,
`struct_or_union_specifier,
`struct_or_union,
`struct_declaration_list,
`struct_declaration,
`specifier_qualifier,
`specifier_qualifier_list,
`struct_declarator_list,
`struct_declarator,
`enum_specifier,
`enumerator_list,
`enumerator,
`type_qualifier,
`declarator,
`direct_declarator,
`pointer,
`type_qualifier_list,
`parameter_type_list,
`parameter_list,
`parameter_declaration,
`identifier_list,
`type_name,
`type_name_token,
`abstract_declarator,
`direct_abstract_declarator,
`initializer,
`initializer_list,
`statement,
`labeled_statement,
`compound_statement,
`declaration_list,
`statement_list,
`expression_statement,
`selection_statement,
`iteration_statement,
`jump_statement,
`translation_unit,
`external_declaration,
`function_definition]

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
      let info := (extDecls.get! 0).getHeadInfo
      return Syntax.node1 info `translation_unit_ $
              Syntax.node info `null extDecls.toArray.reverse

private def mkParseFun {α : Type} (syntaxcat : Name) (ntparser : Syntax → Except ParseError α) :
String → Environment → CommandElabM α := λ s env =>
  if syntaxcat == `translation_unit then do
  let stx ← runParserCategoryTranslationUnit s
  IO.ofExcept (ntparser stx)
 else IO.ofExcept ((runParserCategory env syntaxcat s (tokenFn := CParser.tokenFnCore)) >>= ntparser)

-- Create a parser for a syntax category named `syntaxcat`, which uses `ntparser` to read a syntax node and produces a value α, or an error.
-- This returns a function that given a string `s` and an environment `env`, tries to parse the string, and produces an error.
def mkNonTerminalParser {α : Type}  (syntaxcat : Name) (ntparser : Syntax → Except ParseError α)
(s : String) (env : Environment) : CommandElabM α :=
  let parseFun := mkParseFun syntaxcat ntparser
  let s := makeSubstitution s
  parseFun s env

-- For regex matching
inductive Regex where
  | Concat : List Regex → Regex
  | Union : List Regex → Regex
  | Star : Regex → Regex
  | Base : Char → Regex
  | Empty : Regex

open Regex
def empty : Regex := Empty
def qmark (r : Regex) : Regex := Union [empty, r]
def plus  (r : Regex) : Regex := Concat [r, Star r]

def d : Regex := Union (List.map Base ['0','1','2','3','4','5','6','7','8','9'])
def l : Regex := Union (List.map Base ['a','b','c','d','e','f','g','h',
                                       'i','j','k','l','m','n','o','p',
                                       'q','r','s','t','u','v','w','x',
                                       'y','z','_'])
def h : Regex := Union ((List.map Base ['a','b','c','d','e','f']) ++
                        (List.map Base ['A','B','C','D','E','F']) ++
                        (List.map Base ['0','1','2','3','4','5','6','7','8','9'] ))
def e : Regex := Concat [Union [Base 'e', Base 'E'],
                         qmark $ Union [Base '+', Base '-'],
                         plus d]
def fs : Regex := Union (List.map Base ['f','F','l','L'])
def is : Regex := Star ∘ Union $ List.map Base ['u','U','l','L']

-- return suffix of string after matching prefix with regex
partial def regexConsume : Regex → String → List String
  |     (.Empty    ), s  => if (s == "") then [""] else []
  |     (.Base   c ), s  => if (c == s.front) then [String.mk s.toList.tail!] else []
  |     (.Union  rs), s  => List.bind rs (λ r => regexConsume r s)
  | rgx@(.Star   r ), s  => let rest := regexConsume r s
                            (List.bind rest (regexConsume rgx)) ++ rest ++ [s]
  |     (.Concat rs), s  => List.foldl (λ ss r => List.bind ss (regexConsume r)) [s] rs

-- if the whole string is consumed, the regex matches
def regexMatch (r : Regex) (s : String) : Bool := (regexConsume r s).elem ""

-- example of hex numbers
def c := Concat [Base '0', Union [Base 'x', Base 'X'], plus h, qmark is]
-- #eval regexConsume c "0Xdead291l"
