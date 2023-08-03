import Lean
import CParser
import CParser.AST
import CParser.Parser

open Lean
open IO
open IO.FS
open System
open AST
open Elab.Command

abbrev ParseOutput := String

abbrev Checker := (String → Lean.Environment → CommandElabM ParseOutput)

def directory_checker_map : List (FilePath × Checker) :=
 [(FilePath.mk "./Tests/GroupOne/PrimaryExpr", fun str env => (Functor.map ToString.toString $ parsePrimaryExpression str env))
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
def checkFileParse (env: Lean.Environment)
  (filepath: FilePath)
  (checker: Checker) : IO TestResult := do
  let lines <- IO.FS.lines filepath
  let preprocessed := Array.filter (λ line => line.length > 0 && line.get 0 ≠ '#') lines --preprocess lines
  let fileStr := preprocessed.foldl (λ s₁ s₂ => s₁ ++ "\n" ++ s₂) ""

-- Extracting string from CommandElabM
  let parsed := checker fileStr env
  let runOnce := parsed.run {fileName := filepath.toString, fileMap := FileMap.ofString "", tacticCache? := .none}
  let runTwice := runOnce.run {env := env, maxRecDepth := defaultMaxRecDepth}
  match (runTwice .unit) with
    | .ok (ast, _) _ => do IO.println $ s!"{filepath}, ok, AST:\n" ++ ast
                        return TestResult.Success
    | .error e _ => do match e with
                        | .error ref msg => IO.println s!"{filepath}, error {ref}"
                                            IO.println (← msg.toString)
                        | _ => IO.println s!"{filepath}, internal error" -- should be unreachable
                    return TestResult.Failure

def runTestHarness: IO UInt32 := do
  let isFile (p: FilePath) : IO Bool := do
      return (<- p.metadata).type == FileType.file

  Lean.initSearchPath (← Lean.findSysroot) ["build/lib"]
  let env ← Lean.importModules [{ module := `CParser }] {}

  let mut returnValue := TestResult.Success
  for (dir_path, checker) in directory_checker_map do
    let paths <- dir_path.walkDir -- walk the directory
    let paths <- paths.filterM isFile -- keep only files
    let result <- paths.toList.foldlM (init := TestResult.Success)
         (f := fun resultAccum file => do
           let result <- checkFileParse env (checker := checker) file
           return resultAccum.and result)
    returnValue := TestResult.and result returnValue
  return (if returnValue.success? then 0 else 1)
 

def main: IO UInt32 := runTestHarness
