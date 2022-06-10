import Lean
import Init.Data.String

open Lean

-- for now: just single-line comments
def removeCommentsLineCharList : List Char → List Char
| c1::c2::cs => if c1 == '/' && c2 == '/' then [] else c1::(removeCommentsLineCharList (c2::cs))
| l => l

def removeCommentsLine : String → String :=
λ s => { data := removeCommentsLineCharList s.data }

-- extra layer of abstraction for when we add
-- more preprocessing funcitons (like multiline comments)
def preprocess (lines : Array String ) : Array String :=
lines.map (λ l => removeCommentsLine l)

private def mkParseFun {α : Type} (syntaxcat : Name) (ntparser : Syntax → Except String α) :
String → Environment → Except String α := λ s env => do
  ntparser (← Parser.runParserCategory env syntaxcat s)

def mkNonTerminalParser {α : Type} [Inhabited α] (syntaxcat : Name) (ntparser : Syntax → Except String α)
(s : String) (env : Environment) : Option String × α :=
  let parseFun := mkParseFun syntaxcat ntparser
  match parseFun s env with
   | .error msg => (some msg, default)
   | .ok    p   => (none, p)
