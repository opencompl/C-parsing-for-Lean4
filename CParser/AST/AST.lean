import CParser.SyntaxDecl

namespace AST

mutual
inductive PrimaryExpr where
  | Identifier : String → PrimaryExpr
  | Constant : Int → PrimaryExpr
  | FloatConstant : Float → PrimaryExpr
  | CharLit : Char → PrimaryExpr
  | StringLit : String → PrimaryExpr

inductive IdentList where 
  | IdentList : List String → IdentList

inductive TypeQualList where 
  | TypeQualList : List TypeQual → TypeQualList

inductive TypeQual where
  | Const : TypeQual
  | Volatile : TypeQual

inductive Pointer where
  | Star : Pointer
  | StarTypeQualList : TypeQualList → Pointer
  | StarPtr : Pointer → Pointer
  | StarTypeQualListPtr : TypeQualList → Pointer → Pointer

inductive InitList where
  | InitList : List Initializer → InitList

inductive Initializer where
  | InitListCurl : InitList → Initializer
  | InitListCurlComma : InitList → Initializer

inductive Declaration where
  | Primary : PrimaryExpr → Declaration

inductive DeclList where
  | DeclList : List Declaration → DeclList

inductive DeclSpec where
  | StorClassSpec : StorClassSpec → DeclSpec
  | StorClassSpecDeclSpec : StorClassSpec → DeclSpec → DeclSpec
  | TypeSpec : TypeSpec → DeclSpec
  | TypeSpecDeclSpec : TypeSpec → DeclSpec → DeclSpec
  | TypeQual : TypeQual → DeclSpec
  | TypeQualDeclSpec : TypeQual → DeclSpec → DeclSpec

inductive EnumSpec where
  | Primary : PrimaryExpr → EnumSpec

inductive ParamDecl where
  | Primary : PrimaryExpr → ParamDecl

inductive ParamList where
  | ParamList : List ParamDecl → ParamList
  | ParamDecl : ParamDecl → ParamList
  | ParamListParamDecl : ParamList → ParamDecl → ParamList

inductive ParamTypeList where
  | ParamList : ParamList → ParamTypeList
  | ParamListEllipsis : ParamList → ParamTypeList

inductive SpecQual where
  | TypeSpec : TypeSpec → SpecQual
  | TypeQual : TypeQual → SpecQual

inductive SpecQualList where
  | SpecQualList : List SpecQual → SpecQualList

inductive StorClassSpec where
  | TypeDef : StorClassSpec
  | Extern : StorClassSpec
  | Static : StorClassSpec
  | Auto : StorClassSpec
  | Register : StorClassSpec
  | Inline : StorClassSpec

-- inductive TypeName where
--   | SpecQualList : SpecQualList → TypeName
--   | SpecQualListAbsDec : SpecQualList → AbstrDecl → TypeName

inductive TypeSpec where
  | Void : TypeSpec
  | Char : TypeSpec
  -- | Short : TypeSpec
  -- | Int : TypeSpec
  -- | Long : TypeSpec
  -- | Float : TypeSpec
  -- | Double : TypeSpec
  -- | Signed : TypeSpec
  -- | Unsigned : TypeSpec
  -- | EnumSpec : EnumSpec → TypeSpec
  -- | TypeName : String → TypeSpec

inductive CompStmt where
  | Brackets : CompStmt
  | StmtList : StmtList → CompStmt
  | DeclList : DeclList → CompStmt
  | DeclListStmtList : DeclList → StmtList → CompStmt

inductive Statement where
  | CompStmt : CompStmt → Statement

inductive StmtList where
  | StmtList : List Statement → StmtList

inductive ExternDecl where
  | Declaration : Declaration → ExternDecl
  | Semicolon : ExternDecl

inductive TranslUnit where
  | ExternDeclList : List ExternDecl → TranslUnit

end

end AST