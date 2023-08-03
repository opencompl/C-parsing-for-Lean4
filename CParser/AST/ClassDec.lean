import CParser.AST.AST

open AST
instance : Inhabited PrimaryExpr where default := PrimaryExpr.Constant 0
-- instance : Inhabited PostfixExpr where default := PostfixExpr.Primary (default : PrimaryExpr)
-- instance : Inhabited CastExpr where default := CastExpr.Primary (default : PrimaryExpr)
-- instance : Inhabited MultExpr where default := MultExpr.Cast (default : CastExpr)
-- instance : Inhabited AddExpr where default := AddExpr.Mult (default : MultExpr)
-- instance : Inhabited ShiftExpr where default := ShiftExpr.Add (default : AddExpr)
-- instance : Inhabited RelExpr where default := RelExpr.Shift (default : ShiftExpr)
-- instance : Inhabited EqExpr where default := EqExpr.Rel (default : RelExpr)
-- instance : Inhabited AndExpr where default := AndExpr.Eq (default : EqExpr)
-- instance : Inhabited XOrExpr where default := XOrExpr.And (default : AndExpr)
-- instance : Inhabited IOrExpr where default := IOrExpr.XOr (default : XOrExpr)
-- instance : Inhabited LAndExpr where default := LAndExpr.IOr (default : IOrExpr)
-- instance : Inhabited LOrExpr where default := LOrExpr.LAnd (default : LAndExpr)
-- instance : Inhabited CondExpr where default := CondExpr.Primary (default : PrimaryExpr)
-- instance : Inhabited AssmtOp where default := AssmtOp.Assign
-- instance : Inhabited AssmtExpr where default := AssmtExpr.Primary (default : PrimaryExpr)
-- instance : Inhabited ArgExprList where default := ArgExprList.AssmtExprList []
-- instance : Inhabited Expression where default := Expression.Primary (default : PrimaryExpr)

-- instance : Inhabited ConstantExpr where default := ConstantExpr.Primary (default : PrimaryExpr)
-- instance : Inhabited DirAbstrDecl where default := DirAbstrDecl.DirAbDecConSqr (default : ConstantExpr)
-- instance : Inhabited AbstrDecl where default := AbstrDecl.Primary (default : PrimaryExpr)
instance : Inhabited IdentList where default := IdentList.IdentList []
-- instance : Inhabited DirDecl where default := DirDecl.Identifier "foo"
instance : Inhabited TypeQual where default := TypeQual.Const
instance : Inhabited TypeQualList where default := TypeQualList.TypeQualList []
instance : Inhabited Pointer where default := Pointer.StarTypeQualList (default : TypeQualList)
-- instance : Inhabited Declarator where default := Declarator.DirDecl (default : DirDecl)
instance : Inhabited InitList where default := InitList.InitList []
instance : Inhabited Initializer where default := Initializer.InitListCurl (default : InitList)
-- instance : Inhabited InitDecl where default := InitDecl.Declarator (default : Declarator)

instance : Inhabited StorClassSpec where default := StorClassSpec.TypeDef
instance : Inhabited DeclSpec where default := DeclSpec.StorClassSpec (default : StorClassSpec)
instance : Inhabited Declaration where default := Declaration.Primary (default : PrimaryExpr)
instance : Inhabited DeclList where default := DeclList.DeclList []
-- instance : Inhabited Enumerator where default := Enumerator.Ident "foo"     -- Default for Identifier?
-- instance : Inhabited EnumList where default := EnumList.EnumList []
instance : Inhabited EnumSpec where default := EnumSpec.Primary (default : PrimaryExpr)
-- instance : Inhabited InitDeclList where default := InitDeclList.InitDeclList []
instance : Inhabited ParamDecl where default := ParamDecl.Primary (default : PrimaryExpr)
instance : Inhabited ParamList where default := ParamList.ParamDecl (default : ParamDecl)
instance : Inhabited ParamList where default := ParamList.ParamList []
instance : Inhabited ParamTypeList where default := ParamTypeList.ParamList (default : ParamList)
instance : Inhabited TypeSpec where default := TypeSpec.Void
instance : Inhabited SpecQual where default := SpecQual.TypeSpec (default : TypeSpec)
instance : Inhabited SpecQualList where default := SpecQualList.SpecQualList []
-- instance : Inhabited StructDecl where default := StructDecl.Dec (default : Declarator)
-- instance : Inhabited StructDeclList where default := StructDeclList.StructDeclList []
-- instance : Inhabited StructDeclaration where default := StructDeclaration.SpecQualListStructDecList (default : SpecQualList) (default : StructDeclList)
-- instance : Inhabited StructDeclarationList where default := StructDeclarationList.StructDeclarationList []
-- instance : Inhabited StructOrUnion where default := StructOrUnion.Struct
-- instance : Inhabited StructOrUnionSpec where default := StructOrUnionSpec.SoUStructDeclarationList (default : StructOrUnion) (default : StructDeclarationList)
-- instance : Inhabited TypeName where default := TypeName.SpecQualList (default : SpecQualList)

instance : Inhabited CompStmt where default := CompStmt.Brackets
instance : Inhabited Statement where default := Statement.CompStmt (default : CompStmt)
-- instance : Inhabited ExprStmt where default := ExprStmt.Semicolon
-- instance : Inhabited SelStmt where default := SelStmt.If (default : Expression) (default : Statement)
-- instance : Inhabited IterStmt where default := IterStmt.While (default : Expression) (default : Statement)
-- instance : Inhabited JumpStmt where default := JumpStmt.Continue
-- instance : Inhabited LabelStmt where default := LabelStmt.Default (default : Statement)
instance : Inhabited StmtList where default := StmtList.StmtList []
-- instance : Inhabited FuncDef where default := FuncDef.DeclCompStmt (default : Declarator) (default : CompStmt)
instance : Inhabited ExternDecl where default := ExternDecl.Semicolon
instance : Inhabited TranslUnit where default := TranslUnit.ExternDeclList []

mutual
partial def primaryExprToString : PrimaryExpr → String
  | .Identifier s => s
  | .Constant c => toString c
  | .FloatConstant c => toString c
  | .CharLit c => "'" ++ toString c ++ "'"
  | .StringLit s => "\"" ++ s ++ "\""

partial def identListToString : IdentList → String
  | .IdentList idents => " , ".intercalate (idents)

partial def tqlToString : TypeQualList → String
  | .TypeQualList tqs => " ".intercalate (tqs.map typeQualToString)

partial def typeQualToString : TypeQual → String
  | .Const => "const"
  | .Volatile => "volatile"

partial def pointerToString : Pointer → String
  | .Star => "*"
  | .StarTypeQualList tql => "* " ++ (tqlToString tql)
  | .StarPtr p => "* " ++ (pointerToString p)
  | .StarTypeQualListPtr tql p => "* " ++ (tqlToString tql) ++ " " ++ (pointerToString p)

partial def initListToString : InitList → String
  | .InitList inits => " , ".intercalate (inits.map initializerToString)

partial def initializerToString : Initializer → String
  | .InitListCurl il => "{" ++ (initListToString il) ++ "}"
  | .InitListCurlComma il => "{" ++ (initListToString il) ++ ",}"

partial def declarationToString : Declaration → String
  | .Primary p => (primaryExprToString p)

partial def declListToString : DeclList → String
  | .DeclList ds => "\n".intercalate (ds.map declarationToString)

partial def declSpecToString : DeclSpec → String
  | .StorClassSpec d => (storClassSpecToString d)
  | .StorClassSpecDeclSpec d i => (storClassSpecToString d) ++ " " ++ (declSpecToString i)
  | .TypeSpec d => (typeSpecToString d)
  | .TypeSpecDeclSpec d i => (typeSpecToString d) ++ " " ++ (declSpecToString i)
  | .TypeQual d => (typeQualToString d)
  | .TypeQualDeclSpec d i => (typeQualToString d) ++ " " ++ (declSpecToString i)

partial def storClassSpecToString : StorClassSpec → String
  | .TypeDef => "typedef"
  | .Extern => "extern"
  | .Static => "static"
  | .Auto => "auto"
  | .Register => "register"
  | .Inline => "inline"

partial def typeSpecToString : TypeSpec → String
  | .Void => "void"
  | .Char => "char"
  -- | .Short => "short"
  -- | .Int => "int"
  -- | .Long => "long"
  -- | .Float => "float"
  -- | .Double => "double"
  -- | .Signed => "signed"
  -- | .Unsigned => "unsigned"
  -- | .EnumSpec d => (enumSpecToString d)

partial def enumSpecToString : EnumSpec → String
  | .Primary p => (primaryExprToString p)

partial def paramDeclToString : ParamDecl → String
  | .Primary p => (primaryExprToString p)

partial def paramListToString : ParamList → String
  | .ParamList params => " , ".intercalate (params.map paramDeclToString)
  | .ParamDecl d => (paramDeclToString d)
  | .ParamListParamDecl d i => (paramListToString d) ++ " , " ++ (paramDeclToString i)

partial def paramTypeListToString : ParamTypeList → String
  | .ParamList d => (paramListToString d)
  | .ParamListEllipsis d => (paramListToString d) ++ " , " ++ "..."

partial def specQualToString : SpecQual → String
  | .TypeSpec t => (typeSpecToString t)
  | .TypeQual t => (typeQualToString t)

partial def specQualListToString : SpecQualList → String
  | .SpecQualList ts => " ".intercalate (ts.map specQualToString)

partial def compStmtToString : CompStmt → String
  | .Brackets => "{ }"
  | .StmtList sl => "{\n" ++ (stmtListToString sl) ++ "\n}"
  | .DeclList dl => "{\n" ++ (declListToString dl) ++ "\n}"
  | .DeclListStmtList dl sl => "{\n" ++ (declListToString dl) ++ "\n\n" ++ (stmtListToString sl) ++ "\n}"

partial def statementToString : Statement → String
  | .CompStmt s => (compStmtToString s)

partial def stmtListToString : StmtList → String
  | .StmtList ss => "\n".intercalate (ss.map statementToString)

partial def externDeclToString : ExternDecl → String
  | .Declaration d => (declarationToString d)
  | .Semicolon => ";"

partial def translUnitToString : TranslUnit → String
  | .ExternDeclList eds => "\n".intercalate (eds.map externDeclToString)

end

instance : ToString PrimaryExpr where toString := primaryExprToString