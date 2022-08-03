import Lean
import CParser
import CParser.AST
import CParser.Parser

open IO
open IO.FS
open System
open AST

inductive AnyNonterminal where
  | AddExpr : AddExpr → AnyNonterminal
  | AndExpr : AndExpr → AnyNonterminal
  | ArgExprList : ArgExprList → AnyNonterminal
  | AssmtExpr : AssmtExpr → AnyNonterminal
  | AssmtOp : AssmtOp → AnyNonterminal
  | CastExpr : CastExpr → AnyNonterminal
  | CondExpr : CondExpr → AnyNonterminal
  | EqExpr : EqExpr → AnyNonterminal
  | Expr : Expression → AnyNonterminal
  | IOrExpr : IOrExpr → AnyNonterminal
  | LAndExpr : LAndExpr → AnyNonterminal
  | LOrExpr : LOrExpr → AnyNonterminal
  | MultExpr : MultExpr → AnyNonterminal
  | PostfixExpr : PostfixExpr → AnyNonterminal
  | PrimaryExpr : PrimaryExpr → AnyNonterminal
  | RelExpr : RelExpr → AnyNonterminal
  | ShiftExpr : ShiftExpr → AnyNonterminal
  | UnaryExpr : UnaryExpr → AnyNonterminal
  | UnaryOp : UnaryOp → AnyNonterminal
  | XOrExpr : XOrExpr → AnyNonterminal
  | AbstrDecl : AbstrDecl → AnyNonterminal
  | ConstExpr : ConstantExpr → AnyNonterminal
  | Declarator : Declarator → AnyNonterminal
  | DirAbstrDecl : DirAbstrDecl → AnyNonterminal
  | DirDecl : DirDecl → AnyNonterminal
  | IdentList : IdentList → AnyNonterminal
  | InitDecl : InitDecl → AnyNonterminal
  | InitList : InitList → AnyNonterminal
  | Initializer : Initializer → AnyNonterminal
  | Pointer : Pointer → AnyNonterminal
  | TypeQual : TypeQual → AnyNonterminal
  | TypeQualList : TypeQualList → AnyNonterminal
  | DeclList : DeclList → AnyNonterminal
  | DeclSpec : DeclSpec → AnyNonterminal
  | Declaration : Declaration → AnyNonterminal
  | EnumList : EnumList → AnyNonterminal
  | EnumSpec : EnumSpec → AnyNonterminal
  | Enumerator : Enumerator → AnyNonterminal
  | InitDeclList : InitDeclList → AnyNonterminal
  | ParamDecl : ParamDecl → AnyNonterminal
  | ParamList : ParamList → AnyNonterminal
  | ParamTypeList : ParamTypeList → AnyNonterminal
  | SpecQualList : SpecQualList → AnyNonterminal
  | StorClassSpec : StorClassSpec → AnyNonterminal
  | StructDecl : StructDecl → AnyNonterminal
  | StructDeclList : StructDeclList → AnyNonterminal
  | StructDeclaration : StructDeclaration → AnyNonterminal
  | StructDeclarationList : StructDeclarationList → AnyNonterminal
  | StructOrUnion : StructOrUnion → AnyNonterminal
  | StructOrUnionSpec : StructOrUnionSpec → AnyNonterminal
  | TypeName : TypeName → AnyNonterminal
  | TypeSpec : TypeSpec → AnyNonterminal
  | CompStmt : CompStmt → AnyNonterminal
  | ExprStmt : ExprStmt → AnyNonterminal
  | IterStmt : IterStmt → AnyNonterminal
  | JumpStmt : JumpStmt → AnyNonterminal
  | LabelStmt : LabelStmt → AnyNonterminal
  | SelStmt : SelStmt → AnyNonterminal
  | Statement : Statement → AnyNonterminal
  | StmtList : StmtList → AnyNonterminal
  | ExternDecl : ExternDecl → AnyNonterminal
  | FuncDef : FuncDef → AnyNonterminal
  | TranslUnit : TranslUnit → AnyNonterminal

instance : ToString AnyNonterminal where toString := fun nont => match nont with
  | .AddExpr x => toString x
  | .AndExpr x => toString x
  | .ArgExprList x => toString x
  | .AssmtExpr x => toString x
  | .AssmtOp x => toString x
  | .CastExpr x => toString x
  | .CondExpr x => toString x
  | .EqExpr x => toString x
  | .Expr x => toString x
  | .IOrExpr x => toString x
  | .LAndExpr x => toString x
  | .LOrExpr x => toString x
  | .MultExpr x => toString x
  | .PostfixExpr x => toString x
  | .PrimaryExpr x => toString x
  | .RelExpr x => toString x
  | .ShiftExpr x => toString x
  | .UnaryExpr x => toString x
  | .UnaryOp x => toString x
  | .XOrExpr x => toString x
  | .AbstrDecl x => toString x
  | .ConstExpr x => toString x
  | .Declarator x => toString x
  | .DirAbstrDecl x => toString x
  | .DirDecl x => toString x
  | .IdentList x => toString x
  | .InitDecl x => toString x
  | .InitList x => toString x
  | .Initializer x => toString x
  | .Pointer x => toString x
  | .TypeQual x => toString x
  | .TypeQualList x => toString x
  | .DeclList x => toString x
  | .DeclSpec x => toString x
  | .Declaration x => toString x
  | .EnumList x => toString x
  | .EnumSpec x => toString x
  | .Enumerator x => toString x
  | .InitDeclList x => toString x
  | .ParamDecl x => toString x
  | .ParamList x => toString x
  | .ParamTypeList x => toString x
  | .SpecQualList x => toString x
  | .StorClassSpec x => toString x
  | .StructDecl x => toString x
  | .StructDeclList x => toString x
  | .StructDeclaration x => toString x
  | .StructDeclarationList x => toString x
  | .StructOrUnion x => toString x
  | .StructOrUnionSpec x => toString x
  | .TypeName x => toString x
  | .TypeSpec x => toString x
  | .CompStmt x => toString x
  | .ExprStmt x => toString x
  | .IterStmt x => toString x
  | .JumpStmt x => toString x
  | .LabelStmt x => toString x
  | .SelStmt x => toString x
  | .Statement x => toString x
  | .StmtList x => toString x
  | .ExternDecl x => toString x
  | .FuncDef x => toString x
  | .TranslUnit x => toString x

abbrev Checker := (String → Lean.Environment → Option String × AnyNonterminal)

def directory_checker_map : List (FilePath × Checker) := 
 [(FilePath.mk "./Tests/GroupOne/AddExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.AddExpr y)) $ parseAddExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/AndExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.AndExpr y)) $ parseAndExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/ArgExprList", fun str env => ((fun (x, y) => (x, AnyNonterminal.ArgExprList y)) $ parseArgExprList str env))
 ,(FilePath.mk "./Tests/GroupOne/AssmtExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.AssmtExpr y)) $ parseAssmtExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/AssmtOp", fun str env => ((fun (x, y) => (x, AnyNonterminal.AssmtOp y)) $ parseAssmtOperator str env))
 ,(FilePath.mk "./Tests/GroupOne/CastExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.CastExpr y)) $ parseCastExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/CondExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.CondExpr y)) $ parseCondExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/EqExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.EqExpr y)) $ parseEqExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/Expr", fun str env => ((fun (x, y) => (x, AnyNonterminal.Expr y)) $ parseExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/IOrExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.IOrExpr y)) $ parseIOrExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/LAndExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.LAndExpr y)) $ parseLAndExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/LOrExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.LOrExpr y)) $ parseLOrExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/MultExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.MultExpr y)) $ parseMultExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/PostfixExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.PostfixExpr y)) $ parsePostfixExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/PrimaryExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.PrimaryExpr y)) $ parsePrimaryExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/RelExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.RelExpr y)) $ parseRelExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/ShiftExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.ShiftExpr y)) $ parseShiftExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/UnaryExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.UnaryExpr y)) $ parseUnaryExpression str env))
 ,(FilePath.mk "./Tests/GroupOne/UnaryOp", fun str env => ((fun (x, y) => (x, AnyNonterminal.UnaryOp y)) $ parseUnaryOperator str env))
 ,(FilePath.mk "./Tests/GroupOne/XOrExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.XOrExpr y)) $ parseXOrExpression str env))
 ] ++
 [(FilePath.mk "./Tests/GroupTwo/AbstrDecl", fun str env => ((fun (x, y) => (x, AnyNonterminal.AbstrDecl y)) $ parseAbstrDecl str env))
 ,(FilePath.mk "./Tests/GroupTwo/ConstExpr", fun str env => ((fun (x, y) => (x, AnyNonterminal.ConstExpr y)) $ parseConstantExpression str env))
 ,(FilePath.mk "./Tests/GroupTwo/Declarator", fun str env => ((fun (x, y) => (x, AnyNonterminal.Declarator y)) $ parseDeclarator str env))
 ,(FilePath.mk "./Tests/GroupTwo/DirAbstrDecl", fun str env => ((fun (x, y) => (x, AnyNonterminal.DirAbstrDecl y)) $ parseDirAbstrDecl str env))
 ,(FilePath.mk "./Tests/GroupTwo/DirDecl", fun str env => ((fun (x, y) => (x, AnyNonterminal.DirDecl y)) $ parseDirDecl str env))
 ,(FilePath.mk "./Tests/GroupTwo/IdentList", fun str env => ((fun (x, y) => (x, AnyNonterminal.IdentList y)) $ parseIdentList str env))
 ,(FilePath.mk "./Tests/GroupTwo/InitDecl", fun str env => ((fun (x, y) => (x, AnyNonterminal.InitDecl y)) $ parseInitDecl str env))
 ,(FilePath.mk "./Tests/GroupTwo/InitList", fun str env => ((fun (x, y) => (x, AnyNonterminal.InitList y)) $ parseInitList str env))
 ,(FilePath.mk "./Tests/GroupTwo/Initializer", fun str env => ((fun (x, y) => (x, AnyNonterminal.Initializer y)) $ parseInitializer str env))
 ,(FilePath.mk "./Tests/GroupTwo/Pointer", fun str env => ((fun (x, y) => (x, AnyNonterminal.Pointer y)) $ parsePointer str env))
 ,(FilePath.mk "./Tests/GroupTwo/TypeQual", fun str env => ((fun (x, y) => (x, AnyNonterminal.TypeQual y)) $ parseTypeQual str env))
 ,(FilePath.mk "./Tests/GroupTwo/TypeQualList", fun str env => ((fun (x, y) => (x, AnyNonterminal.TypeQualList y)) $ parseTypeQualList str env))
 ] ++
 [(FilePath.mk "./Tests/GroupThree/Declaration", fun str env => ((fun (x, y) => (x, AnyNonterminal.Declaration y)) $ parseDeclaration str env))
 ,(FilePath.mk "./Tests/GroupThree/DeclList", fun str env => ((fun (x, y) => (x, AnyNonterminal.DeclList y)) $ parseDeclList str env))
 ,(FilePath.mk "./Tests/GroupThree/DeclSpec", fun str env => ((fun (x, y) => (x, AnyNonterminal.DeclSpec y)) $ parseDeclSpec str env))
 ,(FilePath.mk "./Tests/GroupThree/Enumerator", fun str env => ((fun (x, y) => (x, AnyNonterminal.Enumerator y)) $ parseEnumerator str env))
 ,(FilePath.mk "./Tests/GroupThree/EnumList", fun str env => ((fun (x, y) => (x, AnyNonterminal.EnumList y)) $ parseEnumList str env))
 ,(FilePath.mk "./Tests/GroupThree/EnumSpec", fun str env => ((fun (x, y) => (x, AnyNonterminal.EnumSpec y)) $ parseEnumSpec str env))
 ,(FilePath.mk "./Tests/GroupThree/InitDeclList", fun str env => ((fun (x, y) => (x, AnyNonterminal.InitDeclList y)) $ parseInitDeclList str env))
 ,(FilePath.mk "./Tests/GroupThree/ParamDecl", fun str env => ((fun (x, y) => (x, AnyNonterminal.ParamDecl y)) $ parseParamDecl str env))
 ,(FilePath.mk "./Tests/GroupThree/ParamList", fun str env => ((fun (x, y) => (x, AnyNonterminal.ParamList y)) $ parseParamList str env))
 ,(FilePath.mk "./Tests/GroupThree/ParamTypeList", fun str env => ((fun (x, y) => (x, AnyNonterminal.ParamTypeList y)) $ parseParamTypeList str env))
 ,(FilePath.mk "./Tests/GroupThree/SpecQualList", fun str env => ((fun (x, y) => (x, AnyNonterminal.SpecQualList y)) $ parseSpecQualList str env))
 ,(FilePath.mk "./Tests/GroupThree/StorClassSpec", fun str env => ((fun (x, y) => (x, AnyNonterminal.StorClassSpec y)) $ parseStorClassSpec str env))
 ,(FilePath.mk "./Tests/GroupThree/StructDecl", fun str env => ((fun (x, y) => (x, AnyNonterminal.StructDecl y)) $ parseStructDecl str env))
 ,(FilePath.mk "./Tests/GroupThree/StructDeclaration", fun str env => ((fun (x, y) => (x, AnyNonterminal.StructDeclaration y)) $ parseStructDeclaration str env))
 ,(FilePath.mk "./Tests/GroupThree/StructDeclarationList", fun str env => ((fun (x, y) => (x, AnyNonterminal.StructDeclarationList y)) $ parseStructDeclarationList str env))
 ,(FilePath.mk "./Tests/GroupThree/StructDeclList", fun str env => ((fun (x, y) => (x, AnyNonterminal.StructDeclList y)) $ parseStructDeclList str env))
 ,(FilePath.mk "./Tests/GroupThree/StructOrUnion", fun str env => ((fun (x, y) => (x, AnyNonterminal.StructOrUnion y)) $ parseStructOrUnion str env))
 ,(FilePath.mk "./Tests/GroupThree/StructOrUnionSpec", fun str env => ((fun (x, y) => (x, AnyNonterminal.StructOrUnionSpec y)) $ parseStructOrUnionSpec str env))
 ,(FilePath.mk "./Tests/GroupThree/TypeName", fun str env => ((fun (x, y) => (x, AnyNonterminal.TypeName y)) $ parseTypeName str env))
 ,(FilePath.mk "./Tests/GroupThree/TypeSpec", fun str env => ((fun (x, y) => (x, AnyNonterminal.TypeSpec y)) $ parseTypeSpec str env))
 ] ++
 [(FilePath.mk "./Tests/GroupFour/CompStmt", fun str env => ((fun (x, y) => (x, AnyNonterminal.CompStmt y)) $ parseCompStmt str env))
 ,(FilePath.mk "./Tests/GroupFour/ExprStmt", fun str env => ((fun (x, y) => (x, AnyNonterminal.ExprStmt y)) $ parseExprStmt str env))
 ,(FilePath.mk "./Tests/GroupFour/IterStmt", fun str env => ((fun (x, y) => (x, AnyNonterminal.IterStmt y)) $ parseIterStmt str env))
 ,(FilePath.mk "./Tests/GroupFour/JumpStmt", fun str env => ((fun (x, y) => (x, AnyNonterminal.JumpStmt y)) $ parseJumpStmt str env))
 ,(FilePath.mk "./Tests/GroupFour/LabelStmt", fun str env => ((fun (x, y) => (x, AnyNonterminal.LabelStmt y)) $ parseLabelStmt str env))
 ,(FilePath.mk "./Tests/GroupFour/SelStmt", fun str env => ((fun (x, y) => (x, AnyNonterminal.SelStmt y)) $ parseSelStmt str env))
 ,(FilePath.mk "./Tests/GroupFour/Statement", fun str env => ((fun (x, y) => (x, AnyNonterminal.Statement y)) $ parseStatement str env))
 ,(FilePath.mk "./Tests/GroupFour/StmtList", fun str env => ((fun (x, y) => (x, AnyNonterminal.StmtList y)) $ parseStmtList str env))
 ] ++
 [(FilePath.mk "./Tests/GroupFive/ExternDecl", fun str env => ((fun (x, y) => (x, AnyNonterminal.ExternDecl y)) $ parseExternDecl str env))
 ,(FilePath.mk "./Tests/GroupFive/FuncDef", fun str env => ((fun (x, y) => (x, AnyNonterminal.FuncDef y)) $ parseFuncDef str env))
 ,(FilePath.mk "./Tests/GroupFive/TranslUnit", fun str env => ((fun (x, y) => (x, AnyNonterminal.TranslUnit y)) $ parseTranslUnit str env))
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
    | (some msg, _) => do 
       IO.println $ s!"{filepath}, error, {msg}"
       return TestResult.Failure
    | (none, ast) => do
      IO.println $ s!"{filepath}, ok,\nAST:\n" ++ toString ast
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
