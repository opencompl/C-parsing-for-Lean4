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
[
 (FilePath.mk "./Tests/GroupOne/PrimaryExpr", fun str env => (Functor.map ToString.toString $ parsePrimaryExpression str env))
]
--  [(FilePath.mk "./Tests/GroupOne/AddExpr", fun str env => (Functor.map ToString.toString $ parseAddExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/AndExpr", fun str env => (Functor.map ToString.toString $ parseAndExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/ArgExprList", fun str env => (Functor.map ToString.toString $ parseArgExprList str env))
--  ,(FilePath.mk "./Tests/GroupOne/AssmtExpr", fun str env => (Functor.map ToString.toString $ parseAssmtExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/AssmtOp", fun str env => (Functor.map ToString.toString $ parseAssmtOperator str env))
--  ,(FilePath.mk "./Tests/GroupOne/CastExpr", fun str env => (Functor.map ToString.toString $ parseCastExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/CondExpr", fun str env => (Functor.map ToString.toString $ parseCondExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/EqExpr", fun str env => (Functor.map ToString.toString $ parseEqExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/Expr", fun str env => (Functor.map ToString.toString $ parseExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/IOrExpr", fun str env => (Functor.map ToString.toString $ parseIOrExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/LAndExpr", fun str env => (Functor.map ToString.toString $ parseLAndExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/LOrExpr", fun str env => (Functor.map ToString.toString $ parseLOrExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/MultExpr", fun str env => (Functor.map ToString.toString $ parseMultExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/PostfixExpr", fun str env => (Functor.map ToString.toString $ parsePostfixExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/PrimaryExpr", fun str env => (Functor.map ToString.toString $ parsePrimaryExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/RelExpr", fun str env => (Functor.map ToString.toString $ parseRelExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/ShiftExpr", fun str env => (Functor.map ToString.toString $ parseShiftExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/UnaryExpr", fun str env => (Functor.map ToString.toString $ parseUnaryExpression str env))
--  ,(FilePath.mk "./Tests/GroupOne/XOrExpr", fun str env => (Functor.map ToString.toString $ parseXOrExpression str env))
--  ]
--  ]  ++
--  [(FilePath.mk "./Tests/GroupTwo/AbstrDecl", fun str env => (Functor.map ToString.toString $ parseAbstrDecl str env))
--  ,(FilePath.mk "./Tests/GroupTwo/ConstExpr", fun str env => (Functor.map ToString.toString $ parseConstantExpression str env))
--  ,(FilePath.mk "./Tests/GroupTwo/Declarator", fun str env => (Functor.map ToString.toString $ parseDeclarator str env))
--  ,(FilePath.mk "./Tests/GroupTwo/DirAbstrDecl", fun str env => (Functor.map ToString.toString $ parseDirAbstrDecl str env))
--  ,(FilePath.mk "./Tests/GroupTwo/DirDecl", fun str env => (Functor.map ToString.toString $ parseDirDecl str env))
--  ,(FilePath.mk "./Tests/GroupTwo/IdentList", fun str env => (Functor.map ToString.toString $ parseIdentList str env))
--  ,(FilePath.mk "./Tests/GroupTwo/InitDecl", fun str env => (Functor.map ToString.toString $ parseInitDecl str env))
--  ,(FilePath.mk "./Tests/GroupTwo/InitList", fun str env => (Functor.map ToString.toString $ parseInitList str env))
--  ,(FilePath.mk "./Tests/GroupTwo/Initializer", fun str env => (Functor.map ToString.toString $ parseInitializer str env))
--  ,(FilePath.mk "./Tests/GroupTwo/Pointer", fun str env => (Functor.map ToString.toString $ parsePointer str env))
--  ,(FilePath.mk "./Tests/GroupTwo/TypeQual", fun str env => (Functor.map ToString.toString $ parseTypeQual str env))
--  ,(FilePath.mk "./Tests/GroupTwo/TypeQualList", fun str env => (Functor.map ToString.toString $ parseTypeQualList str env))
--  ] ++
--  [(FilePath.mk "./Tests/GroupThree/Declaration", fun str env => (Functor.map ToString.toString $ parseDeclaration str env))
--  ,(FilePath.mk "./Tests/GroupThree/DeclList", fun str env => (Functor.map ToString.toString $ parseDeclList str env))
--  ,(FilePath.mk "./Tests/GroupThree/DeclSpec", fun str env => (Functor.map ToString.toString $ parseDeclSpec str env))
--  ,(FilePath.mk "./Tests/GroupThree/Enumerator", fun str env => (Functor.map ToString.toString $ parseEnumerator str env))
--  ,(FilePath.mk "./Tests/GroupThree/EnumList", fun str env => (Functor.map ToString.toString $ parseEnumList str env))
--  ,(FilePath.mk "./Tests/GroupThree/EnumSpec", fun str env => (Functor.map ToString.toString $ parseEnumSpec str env))
--  ,(FilePath.mk "./Tests/GroupThree/InitDeclList", fun str env => (Functor.map ToString.toString $ parseInitDeclList str env))
--  ,(FilePath.mk "./Tests/GroupThree/ParamDecl", fun str env => (Functor.map ToString.toString $ parseParamDecl str env))
--  ,(FilePath.mk "./Tests/GroupThree/ParamList", fun str env => (Functor.map ToString.toString $ parseParamList str env))
--  ,(FilePath.mk "./Tests/GroupThree/ParamTypeList", fun str env => (Functor.map ToString.toString $ parseParamTypeList str env))
--  ,(FilePath.mk "./Tests/GroupThree/SpecQualList", fun str env => (Functor.map ToString.toString $ parseSpecQualList str env))
--  ,(FilePath.mk "./Tests/GroupThree/StorClassSpec", fun str env => (Functor.map ToString.toString $ parseStorClassSpec str env))
--  ,(FilePath.mk "./Tests/GroupThree/StructDecl", fun str env => (Functor.map ToString.toString $ parseStructDecl str env))
--  ,(FilePath.mk "./Tests/GroupThree/StructDeclaration", fun str env => (Functor.map ToString.toString $ parseStructDeclaration str env))
--  ,(FilePath.mk "./Tests/GroupThree/StructDeclarationList", fun str env => (Functor.map ToString.toString $ parseStructDeclarationList str env))
--  ,(FilePath.mk "./Tests/GroupThree/StructDeclList", fun str env => (Functor.map ToString.toString $ parseStructDeclList str env))
--  ,(FilePath.mk "./Tests/GroupThree/StructOrUnion", fun str env => (Functor.map ToString.toString $ parseStructOrUnion str env))
--  ,(FilePath.mk "./Tests/GroupThree/StructOrUnionSpec", fun str env => (Functor.map ToString.toString $ parseStructOrUnionSpec str env))
--  ,(FilePath.mk "./Tests/GroupThree/TypeName", fun str env => (Functor.map ToString.toString $ parseTypeName str env))
--  ,(FilePath.mk "./Tests/GroupThree/TypeSpec", fun str env => (Functor.map ToString.toString $ parseTypeSpec str env))
--  ] ++
--  [(FilePath.mk "./Tests/GroupFour/CompStmt", fun str env => (Functor.map ToString.toString $ parseCompStmt str env))
--  ,(FilePath.mk "./Tests/GroupFour/ExprStmt", fun str env => (Functor.map ToString.toString $ parseExprStmt str env))
--  ,(FilePath.mk "./Tests/GroupFour/IterStmt", fun str env => (Functor.map ToString.toString $ parseIterStmt str env))
--  ,(FilePath.mk "./Tests/GroupFour/JumpStmt", fun str env => (Functor.map ToString.toString $ parseJumpStmt str env))
--  ,(FilePath.mk "./Tests/GroupFour/LabelStmt", fun str env => (Functor.map ToString.toString $ parseLabelStmt str env))
--  ,(FilePath.mk "./Tests/GroupFour/SelStmt", fun str env => (Functor.map ToString.toString $ parseSelStmt str env))
--  ,(FilePath.mk "./Tests/GroupFour/Statement", fun str env => (Functor.map ToString.toString $ parseStatement str env))
--  ,(FilePath.mk "./Tests/GroupFour/StmtList", fun str env => (Functor.map ToString.toString $ parseStmtList str env))
--  ] ++
--  [(FilePath.mk "./Tests/GroupFive/ExternDecl", fun str env => (Functor.map ToString.toString $ parseExternDecl str env))
--  ,(FilePath.mk "./Tests/GroupFive/FuncDef", fun str env => (Functor.map ToString.toString $ parseFuncDef str env))
--  ,(FilePath.mk "./Tests/GroupFive/TranslUnit", fun str env => (Functor.map ToString.toString $ parseTranslUnit str env))
--  ]

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
  
  -- dbg_trace fileStr
  -- char: char, void: void

-- Extracting string from CommandElabM
  let parsed := checker fileStr env
  let runOnce := parsed.run {fileName := filepath.toString, fileMap := FileMap.ofString "", tacticCache? := .none}
  let runTwice := runOnce.run {env := env, maxRecDepth := defaultMaxRecDepth}
  match (runTwice .unit) with
    | .ok (ast, _) _ => do IO.println $ s!"{filepath}, ok, AST:\n" ++ ast
                        -- dbg_trace ast
                        -- char : 'A', void does not reach here because of error
                        -- Note: need to find where ast is coming from
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
