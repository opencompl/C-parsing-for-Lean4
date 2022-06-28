import Lean
import CParser

open Lean

-- Check that a file parses correctly.
-- TODO: collect the information into a struct, which
-- prints the information at the end as a CSV.
def check_file (filepath: String): IO Unit := do
  let lines <- IO.FS.lines filepath
  let preprocessed := preprocess lines
  let fileStr := preprocessed.foldl (λ s₁ s₂ => s₁ ++ "\n" ++ s₂) ""
  println! s!"parsing {filepath}: \n {fileStr}"
  -- let pipeline := Lean.quote [file]
  Lean.initSearchPath (← Lean.findSysroot) ["build/lib"]
  let env ← Lean.importModules [{ module := `CParser }] {}
  let parsed := parse fileStr env
  let res_str := match parsed.1 with
    | some msg => "syntax error:\n" ++ msg
    | none => s!"parse ok! parsed: \n---\n{parsed.2}\n---\n"
  println! res_str
  return ()

-- treat each argument as a filepath, and then run the syntax check.
def main (args : List String): IO Unit := do
  let filepaths := args
  for path in filepaths do
    check_file path
