import Lean
import CParser
import CParser.AST
import CParser.Parser

open IO
open IO.FS
open System


abbrev Checker := (String → Lean.Environment → Option String)

def directory_checker_map : List (FilePath × Checker) := 
 [(FilePath.mk "./Tests/GroupOne/AddExpr", fun str env => (parseAddExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/AndExpr", fun str env => (parseAndExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/ArgExprList", fun str env => (parseArgExprList str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/AssmtExpr", fun str env => (parseAssmtExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/AssmtOp", fun str env => (parseAssmtOperator str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/CastExpr", fun str env => (parseCastExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/CondExpr", fun str env => (parseCondExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/EqExpr", fun str env => (parseEqExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/Expr", fun str env => (parseExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/IOrExpr", fun str env => (parseIOrExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/LAndExpr", fun str env => (parseLAndExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/LOrExpr", fun str env => (parseLOrExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/MultExpr", fun str env => (parseMultExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/PostfixExpr", fun str env => (parsePostfixExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/PrimaryExpr", fun str env => (parsePrimaryExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/RelExpr", fun str env => (parseRelExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/ShiftExpr", fun str env => (parseShiftExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/UnaryExpr", fun str env => (parseUnaryExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/UnaryOp", fun str env => (parseUnaryOperator str env).fst)
 ,(FilePath.mk "./Tests/GroupOne/XOrExpr", fun str env => (parseXOrExpression str env).fst)
 ] ++
 [(FilePath.mk "./Tests/GroupTwo/AbstrDecl", fun str env => (parseAbstrDecl str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/ConstExpr", fun str env => (parseConstantExpression str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/Declarator", fun str env => (parseDeclarator str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/DirAbstrDecl", fun str env => (parseDirAbstrDecl str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/DirDecl", fun str env => (parseDirDecl str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/IdentList", fun str env => (parseIdentList str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/InitDecl", fun str env => (parseInitDecl str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/InitList", fun str env => (parseInitList str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/Initializer", fun str env => (parseInitializer str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/Pointer", fun str env => (parsePointer str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/TypeQual", fun str env => (parseTypeQual str env).fst)
 ,(FilePath.mk "./Tests/GroupTwo/TypeQualList", fun str env => (parseTypeQualList str env).fst)
 ] ++
 [(FilePath.mk "./Tests/GroupThree/Declaration", fun str env => (parseDeclaration str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/DeclList", fun str env => (parseDeclList str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/DeclSpec", fun str env => (parseDeclSpec str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/Enumerator", fun str env => (parseEnumerator str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/EnumList", fun str env => (parseEnumList str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/EnumSpec", fun str env => (parseEnumSpec str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/InitDeclList", fun str env => (parseInitDeclList str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/ParamDecl", fun str env => (parseParamDecl str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/ParamList", fun str env => (parseParamList str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/ParamTypeList", fun str env => (parseParamTypeList str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/SpecQualList", fun str env => (parseSpecQualList str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/StorClassSpec", fun str env => (parseStorClassSpec str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/StructDecl", fun str env => (parseStructDecl str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/StructDeclaration", fun str env => (parseStructDeclaration str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/StructDeclarationList", fun str env => (parseStructDeclarationList str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/StructDeclList", fun str env => (parseStructDeclList str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/StructOrUnion", fun str env => (parseStructOrUnion str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/StructOrUnionSpec", fun str env => (parseStructOrUnionSpec str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/TypeName", fun str env => (parseTypeName str env).fst)
 ,(FilePath.mk "./Tests/GroupThree/TypeSpec", fun str env => (parseTypeSpec str env).fst)
 ] ++
 [(FilePath.mk "./Tests/GroupFour/CompStmt", fun str env => (parseCompStmt str env).fst)
 ,(FilePath.mk "./Tests/GroupFour/ExprStmt", fun str env => (parseExprStmt str env).fst)
 ,(FilePath.mk "./Tests/GroupFour/IterStmt", fun str env => (parseIterStmt str env).fst)
 ,(FilePath.mk "./Tests/GroupFour/JumpStmt", fun str env => (parseJumpStmt str env).fst)
 ,(FilePath.mk "./Tests/GroupFour/LabelStmt", fun str env => (parseLabelStmt str env).fst)
 ,(FilePath.mk "./Tests/GroupFour/SelStmt", fun str env => (parseSelStmt str env).fst)
 ,(FilePath.mk "./Tests/GroupFour/Statement", fun str env => (parseStatement str env).fst)
 ,(FilePath.mk "./Tests/GroupFour/StmtList", fun str env => (parseStmtList str env).fst)
 ] ++
 [(FilePath.mk "./Tests/GroupFive/ExternDecl", fun str env => (parseExternDecl str env).fst)
 ,(FilePath.mk "./Tests/GroupFive/FuncDef", fun str env => (parseFuncDef str env).fst)
 ,(FilePath.mk "./Tests/GroupFive/TranslUnit", fun str env => (parseTranslUnit str env).fst)
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
  let preprocessed := preprocess lines
  let fileStr := preprocessed.foldl (λ s₁ s₂ => s₁ ++ "\n" ++ s₂) ""
  -- let pipeline := Lean.quote [file]
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
