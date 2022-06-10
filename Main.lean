import Lean
import CParser


def default_filename := "Tests/primary_expression.c"

def main (args : List String): IO Unit := do
  let filename := match args.get? 0 with
    | some fn => fn
    | none => default_filename
  let lines <- IO.FS.lines filename
  let preprocessed := preprocess lines
  let fileStr := preprocessed.foldl (λ s₁ s₂ => s₁ ++ "\n" ++ s₂) ""
  println! s!"parsing {filename}: \n {fileStr}"
  -- let pipeline := Lean.quote [file]
  Lean.initSearchPath (← Lean.findSysroot) ["build/lib"]
  let env ← Lean.importModules [{ module := `CParser }] {}
  let parsed := parse fileStr env
  let res_str := match parsed.1 with
    | some msg => "syntax error:\n" ++ msg
    | none => s!"parse ok! parsed: \n---\n{parsed.2}\n---\n"
  println! res_str
  return ()
