import Lean
import CParser
import CParser.AST.GroupOne
import CParser.AST.GroupTwo

open IO
open IO.FS
open System


abbrev Checker := (String → Lean.Environment → Option String)

def directory_checker_map : List (FilePath × Checker) := 
 [(FilePath.mk "./Tests/GroupOne/AddExpr/", fun str env => (parseAddExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/AndExpr/", fun str env => (parseAndExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/AssmtOp/", fun str env => (parseAssmtOperator str env).fst)
 ]

inductive TestResult
| Success
| Failure

def TestResult.and: TestResult → TestResult → TestResult 
| Success,  Success => Success
| _, _ => Failure

def TestResult.success? : TestResult -> Bool
| Success => true
| Failure => false

-- Run the checker, output CSV formatted info about parse
-- success / failure
def checkFileParse (filepath: FilePath) (checker: Checker) : IO TestResult := do
  let lines <- IO.FS.lines filepath
  let preprocessed := preprocess lines
  let fileStr := preprocessed.foldl (λ s₁ s₂ => s₁ ++ "\n" ++ s₂) ""
  -- let pipeline := Lean.quote [file]
  Lean.initSearchPath (← Lean.findSysroot) ["build/lib"]
  let env ← Lean.importModules [{ module := `CParser }] {}
  match checker fileStr env with
    | some msg => do 
       IO.println $ s!"{filepath}, error, {msg}"
       return TestResult.Failure
    | none => do
      IO.println $ s!"{filepath}, ok, "
      return TestResult.Success

def runTestHarness: IO UInt32 := do
  let isFile (p: FilePath) : IO Bool := do
      return (<- p.metadata).type == FileType.file

  let mut returnValue := TestResult.Success
  for (dir_path, checker) in directory_checker_map do
    let paths <- dir_path.walkDir -- walk the directory
    let paths <- paths.filterM isFile -- keep only files
    let results <- paths.mapM (checkFileParse (checker := checker))
    let result := results.foldl (f := TestResult.and) (init := .Success)
    returnValue := TestResult.and result returnValue
  return (if returnValue.success? then 0 else 1)
 

def main: IO UInt32 := runTestHarness
