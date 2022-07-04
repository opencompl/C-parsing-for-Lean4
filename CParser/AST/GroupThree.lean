import CParser.AST.GroupOne
import CParser.AST.GroupTwo

open AST

mutual
inductive Declaration where
  | DeclSpec : DeclSpec → Declaration
  | DeclSpecInitDecList : DeclSpec → InitDeclList → Declaration

inductive DeclList where
  | Decl : Declaration → DeclList
  | DeclListDecl : DeclList → Declaration → DeclList

inductive DeclSpec where
  | StorClassSpec : StorClassSpec → DeclSpec
  | StorClassSpecDeclSpec : StorClassSpec → DeclSpec → DeclSpec
  | TypeSpec : TypeSpec → DeclSpec
  | TypeSpecDeclSpec : TypeSpec → DeclSpec → DeclSpec
  | TypeQual : TypeQual → DeclSpec
  | TypeQualDeclSpec : TypeQual → DeclSpec → DeclSpec

inductive Enumerator where
  | Ident : String →  Enumerator
  | IdentAssignConst : String → ConstantExpr →  Enumerator

inductive EnumList where
  | Enum : Enumerator → EnumList
  | EnumListEnum : EnumList → Enumerator → EnumList

inductive EnumSpec where
  | EnumList : EnumList → EnumSpec
  | IdentEnumList : String → EnumList → EnumSpec
  | EnumIdent : String → EnumSpec

inductive InitDeclList where
  | InitDecl : InitDecl → InitDeclList
  | InitDeclListInitDecl : InitDeclList → InitDecl → InitDeclList

inductive ParamDecl where
  | DeclSpecDecl : DeclSpec → Declarator → ParamDecl
  | DeclSpecAbsDecl : DeclSpec → AbstrDecl → ParamDecl
  | DeclSpec : DeclSpec → ParamDecl

inductive ParamList where
  | ParamDecl : ParamDecl → ParamList
  | ParamListParamDecl : ParamList → ParamDecl → ParamList

inductive ParamTypeList where
  | ParamList : ParamList → ParamTypeList
  | ParamListElipsis : ParamList → ParamTypeList

inductive SpecQualList where
  | TypeSpecSpecQualList : TypeSpec → SpecQualList → SpecQualList
  | TypeSpec : TypeSpec → SpecQualList
  | TypeQualSpecQualList : TypeQual → SpecQualList → SpecQualList
  | TypeQual : TypeQual → SpecQualList

inductive StorClassSpec where
  | TypeDef : StorClassSpec
  | Extern : StorClassSpec
  | Static : StorClassSpec
  | Auto : StorClassSpec
  | Register : StorClassSpec

inductive StructDecl where
  | Dec : Declarator → StructDecl
  | ConstExpr : ConstantExpr → StructDecl
  | DeclConstExpr : Declarator → ConstantExpr → StructDecl

inductive StructDeclaration where
  | SpecQualListStructDecList : SpecQualList → StructDecList → StructDeclaration

inductive StructDeclarationList where
  | StructDeclaration : StructDeclaration → StructDeclarationList
  | StructDeclListStructDecl : StructDeclarationList → StructDeclaration → StructDeclarationList

inductive StructDeclList where
  | StructDecl : StructDecl → StructDeclList
  | StructDecListStructDec : StructDeclList → StructDecl → StructDeclList

inductive StructOrUnion where
  | Struct : StructOrUnion
  | Union : StructOrUnion

inductive StructOrUnionSpec where
  | SoUIdentStructDeclarationList : StructOrUnion → String → StructDeclarationList → StructOrUnionSpec
  | SoUStructDeclarationList : StructOrUnion → StructDeclarationList → StructOrUnionSpec
  | SoUIdent : StructOrUnion → String → StructOrUnionSpec

inductive TypeName where
  | SpecQualList : SpecQualList → TypeName
  | SpecQualListAbsDec : SpecQualList → AbstrDecl → TypeName

inductive TypeSpec where
  | Void : TypeSpec
  | Char : TypeSpec
  | Short : TypeSpec
  | Int : TypeSpec
  | Long : TypeSpec
  | Float : TypeSpec
  | Double : TypeSpec
  | Signed : TypeSpec
  | Unsigned : TypeSpec
  | SoUSpec : StructOrUnionSpec → TypeSpec
  | EnumSpec : EnumSpec → TypeSpec
  | TypeName : TypeSpec

end

-- end AST
