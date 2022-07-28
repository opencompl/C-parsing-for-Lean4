import Lean
import Init.Data.String

open Lean

-- for now: just single-line comments
-- TODO: this also isn't good enough, it will break if there's a string literal with // inside it, and it shouldn't
-- bollu:
--   Is this correct? This only removes LEADING comments. It does not seem to remove something like:
--   abb // cc
--   ?

-- First argument is 1 iff a double quote is unterminated
def removeCommentsLineCharList (inString: Bool) (xs: List Char): List Char := 
  match xs with
  | /-
      if we see //, and we are not in a string, then remove everything.
     -/ '/'::'/'::xs => if inString then '/'::'/'::removeCommentsLineCharList inString xs else []
  | /-
     if we see \", then we have not entered a string (it is an escaped string quote). So continue as normal
    -/'\\'::'"'::xs => '\\'::'"'::removeCommentsLineCharList inString xs -- escaped string literal
  | /-
     if we see a ", and we have NOT seen a \ " (ie, this double quote is not escaped), then we are now in a string.
    -/ '"'::xs => '"'::removeCommentsLineCharList (!inString) xs
  | /-
     ignore everything else and continue.
    -/x::xs => x::removeCommentsLineCharList inString xs
  | [] => []

#eval (removeCommentsLineCharList (inString := False) ['"', '/', '/', 'b', 'o', 'i', '"'])
#eval (removeCommentsLineCharList (inString := False) ['f', '/', '/', 'b', 'o', 'i', '"'])
#eval (removeCommentsLineCharList (inString := False) ['f', '"', '/', '/', '"', 'b', '/', '/', 'o', 'i', '"'])

def removeCommentsLine : String → String :=
λ s => { data := removeCommentsLineCharList (inString := False) s.data }

-- extra layer of abstraction for when we add
-- more preprocessing funcitons (like multiline comments)
def preprocess (lines : Array String ) : Array String :=
lines.map (λ l => removeCommentsLine l)

private def mkParseFun {α : Type} (syntaxcat : Name) (ntparser : Syntax → Except String α) :
String → Environment → Except String α := λ s env => do
  ntparser (← Parser.runParserCategory env syntaxcat s)

-- Create a parser for a syntax category named `syntaxcat`, which uses `ntparser` to read a syntax node and produces a value α, or an error.
-- This returns a function that given a string `s` and an environment `env`, tries to parse the string, and produces an error.
def mkNonTerminalParser {α : Type} [Inhabited α] (syntaxcat : Name) (ntparser : Syntax → Except String α)
(s : String) (env : Environment) : Option String × α :=
  let parseFun := mkParseFun syntaxcat ntparser
  match parseFun s env with
   | .error msg => (some msg, default)
   | .ok    p   => (none, p)

-- For regex matching
inductive Regex where
  | Concat : List Regex → Regex
  | Union : List Regex → Regex
  | Star : Regex → Regex
  | Base : Char → Regex

open Regex
def empty : Regex := Concat []
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
  |      _          , "" => []
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
