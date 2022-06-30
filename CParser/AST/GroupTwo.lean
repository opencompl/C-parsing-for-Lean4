import CParser.AST.GroupOne

open AST

mutual
inductive ConstantExpr where
  | ConExpr : CondExpr → ConstantExpr

inductive DirAbstrDecl where
  | DirAbDecAbsRnd : AbstrDecl → DirAbstrDecl
  | DirAbDecSqr : DirAbstrDecl
  | DirAbDecConSqr : ConstantExpr → DirAbstrDecl
  | DirAbDecDirSqr : DirAbstrDecl → DirAbstrDecl
  | DirAbDecDirConst : DirAbstrDecl → ConstantExpr → DirAbstrDecl
  | DirAbDecRnd : DirAbstrDecl
  -- | DirAbDecParamList : ParamTypeList → DirAbstrDecl
  | DirAbDecDirRnd : DirAbstrDecl → DirAbstrDecl
  -- | DirAbDecDirParamList : DirAbstrDecl → ParamTypeList → DirAbstrDecl

inductive AbstrDecl where
  | AbstrPtr : Pointer → AbstrDecl
  | AbstrDirAbDec : DirAbstrDecl → AbstrDecl
  | AbstrPtrDirAbDec : Pointer → DirAbstrDecl → AbstrDecl

inductive IdentList where 
  | Identifier : String → IdentList
  | IdentListIdent : IdentList → String → IdentList

inductive DirDecl where
  | Identifier : String → DirDecl
  | DeclRnd : Declarator → DirDecl
  | DirDecConst : DirDecl → ConstantExpr → DirDecl
  | DirDecSqr : DirDecl → DirDecl
  -- | DirDecParamList : DirDecl → ParamTypeList → DirDecl
  | DirDecIdentList : DirDecl → IdentList → DirDecl
  | DirDecRnd : DirDecl → DirDecl

inductive TypeQualList where 
  | TypeQual : TypeQual → TypeQualList
  | TypeQuaListTypeQuq : TypeQualList → TypeQual → TypeQualList

inductive TypeQual where
  | Const : TypeQual
  | Volatile : TypeQual

inductive Pointer where
  | Star : Pointer
  | StarTypeQualList : TypeQualList → Pointer
  | StarPtr : Pointer → Pointer
  | StarTypeQualListPtr : TypeQualList → Pointer → Pointer

inductive Declarator where
  | PtrDirDecl : Pointer → DirDecl → Declarator
  | DirDecl : DirDecl → Declarator

inductive InitList where
  | InitList : List Initializer → InitList

inductive Initializer where
  | AssmtExpr : AssmtExpr → Initializer
  | InitListCurl : InitList → Initializer
  | InitListCurlComma : InitList → Initializer

inductive InitDecl where
  | Declarator : Declarator → InitDecl
  | DeclInit : Declarator → Initializer → InitDecl

end

-- end AST
