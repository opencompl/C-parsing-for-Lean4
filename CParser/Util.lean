import Lean
import Init.Data.String
-- import Lean.Parser.Types

open Lean Parser Elab.Command

-- for now: just single-line comments
-- TODO: this also isn't good enough, it will break if there's a string literal with // inside it, and it shouldn't
-- bollu:
--   Is this correct? This only removes LEADING comments. It does not seem to remove something like:
--   abb // cc
--   ?

-- -- First argument is 1 iff a double quote is unterminated
-- def removeCommentsLineCharList (inString: Bool) (xs: List Char): List Char := 
--   match xs with
--   | /-
--       if we see //, and we are not in a string, then remove everything.
--      -/ '/'::'/'::xs => if inString then '/'::'/'::removeCommentsLineCharList inString xs else []
--   | /-
--      if we see \", then we have not entered a string (it is an escaped string quote). So continue as normal
--     -/'\\'::'"'::xs => '\\'::'"'::removeCommentsLineCharList inString xs -- escaped string literal
--   | /-
--      if we see a ", and we have NOT seen a \ " (ie, this double quote is not escaped), then we are now in a string.
--     -/ '"'::xs => '"'::removeCommentsLineCharList (!inString) xs
--   | /-
--      ignore everything else and continue.
--     -/x::xs => x::removeCommentsLineCharList inString xs
--   | [] => []

-- #eval (removeCommentsLineCharList (inString := False) ['"', '/', '/', 'b', 'o', 'i', '"'])
-- #eval (removeCommentsLineCharList (inString := False) ['f', '/', '/', 'b', 'o', 'i', '"'])
-- #eval (removeCommentsLineCharList (inString := False) ['f', '"', '/', '/', '"', 'b', '/', '/', 'o', 'i', '"'])

-- def removeCommentsLine : String → String :=
-- λ s => { data := removeCommentsLineCharList (inString := False) s.data }

-- -- extra layer of abstraction for when we add
-- -- more preprocessing funcitons (like multiline comments)
-- def preprocess (lines : Array String ) : Array String :=
-- lines.map (λ l => removeCommentsLine l)

-- Helper function
def removeSingleLineCommentsTailH (inComment : Bool) (inString : Bool) (input : List Char) (accum : List Char) : List Char :=
  match inComment, inString, input with
    | _,     _,     []                => accum.reverse
-- if in a comment, leave on newline, otherwise stay
    | true,  _,     '\n' :: cs        => removeSingleLineCommentsTailH false inString cs accum
    | true,  _,     _    :: cs        => removeSingleLineCommentsTailH true inString cs accum
-- if in code, a string can have any character other than '"'
    | false, _,     '"'  :: cs        => removeSingleLineCommentsTailH false (!inString) cs ('"' :: accum)
    | false, true,  c    :: cs        => removeSingleLineCommentsTailH false true cs (c :: accum)
-- if in code, // starts a comment
    | false, false, '/'  :: '/' :: cs => removeSingleLineCommentsTailH true false cs accum
    | false, false, c    :: cs        => removeSingleLineCommentsTailH false false cs (c :: accum)


-- Helper function
def removeMultiLineCommentsTailH (inComment : Bool) (inString : Bool) (input : List Char) (accum : List Char) : List Char :=
  match inComment, inString, input with
    | _,     _,     []                => accum.reverse
-- if in a comment, leave on newline, otherwise stay
    | true,  _,     '*'  :: '/' :: cs => removeMultiLineCommentsTailH false inString cs accum
    | true,  _,     _    :: cs        => removeMultiLineCommentsTailH true inString cs accum
-- if in code, a string can have any character other than '"'
    | false, _,     '"'  :: cs        => removeMultiLineCommentsTailH false (!inString) cs ('"' :: accum)
    | false, true,  c    :: cs        => removeMultiLineCommentsTailH false true cs (c :: accum)
-- if in code, // starts a comment
    | false, false, '/'  :: '*' :: cs => removeMultiLineCommentsTailH true false cs accum
    | false, false, c    :: cs        => removeMultiLineCommentsTailH false false cs (c :: accum)

def substituteMinusTailH (dummy : Bool) (inString : Bool) (input : List Char) (accum : List Char) : List Char :=
  match inString, input with
    | _,     []               => accum.reverse
    | _,     '"' :: cs        => substituteMinusTailH dummy (!inString) cs ('"' :: accum)
    | true,  c   :: cs        => substituteMinusTailH dummy true cs (c :: accum)
    | false, '-' :: '-' :: cs => substituteMinusTailH dummy false cs ('–' :: accum)
    | false, c   :: cs        => substituteMinusTailH dummy false cs (c :: accum)

def substituteBackslashTailH (dummy : Bool) (inString : Bool) (input : List Char) (accum : List Char) : List Char :=
  match inString, input with
    | _,     []               => accum.reverse
    | _,     '"' :: cs        => substituteBackslashTailH dummy (!inString) cs ('"' :: accum)
    | _, '\\' :: c :: cs      => if c == '\\' then substituteBackslashTailH dummy inString cs ('@' :: '@' :: accum)
                                 else if c != '\"' then substituteBackslashTailH dummy inString (c :: cs) ('@' :: accum)
                                 else substituteBackslashTailH dummy inString (c :: cs) ('\\' :: accum)
    | inString,  c   :: cs    => substituteBackslashTailH dummy inString cs (c :: accum)

def wrapHelperTail (helper : Bool → Bool → List Char → List Char → List Char) : (String → String) :=
  λ i => let charList := helper false false i.toList []
         charList.foldl (λ a b => a ++ b.toString) ""

def removeSingleLineComments := wrapHelperTail removeSingleLineCommentsTailH
def removeMultiLineComments  := wrapHelperTail removeMultiLineCommentsTailH
def substituteMinus          := wrapHelperTail substituteMinusTailH
def substituteBackslash      := wrapHelperTail substituteBackslashTailH

def removeComments := removeMultiLineComments ∘ removeSingleLineComments
def makeSubstitution := substituteMinus ∘ substituteBackslash

abbrev ParseError := String

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
   let p := andthenFn whitespace (categoryParserFnImpl `external_declaration)
   -- let ictx := mkInputContext input fileName
   let env ← getEnv
   let s := p.run { ictx with
     env
     options := {}
     prec := 0
     tokens := getTokenTable env
     tokenFn := tokenFnCore
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
                                             let _ ← Array.mapM (stringToCommand stx) newTypeNames
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
 else IO.ofExcept ((runParserCategory env syntaxcat s) >>= ntparser)

-- Create a parser for a syntax category named `syntaxcat`, which uses `ntparser` to read a syntax node and produces a value α, or an error.
-- This returns a function that given a string `s` and an environment `env`, tries to parse the string, and produces an error.
def mkNonTerminalParser {α : Type}  (syntaxcat : Name) (ntparser : Syntax → Except ParseError α)
(s : String) (env : Environment) : CommandElabM α :=
  let parseFun := mkParseFun syntaxcat ntparser
  let s := makeSubstitution (removeComments s)
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
