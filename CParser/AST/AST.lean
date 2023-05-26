import CParser.SyntaxDecl

namespace AST

mutual
inductive PrimaryExpr where
  | Identifier : String → PrimaryExpr
  | Constant : Int → PrimaryExpr
  | StringLit : String → PrimaryExpr
  | BracketExpr : Expression → PrimaryExpr

inductive PostfixExpr where
  | Primary : PrimaryExpr → PostfixExpr
  | SquareBrack : PostfixExpr → Expression → PostfixExpr
  | CurlyBrack : PostfixExpr → PostfixExpr
  | AEL : PostfixExpr → ArgExprList → PostfixExpr
  | Identifier : PostfixExpr → String → PostfixExpr
  | PtrIdent : PostfixExpr → String → PostfixExpr
  | IncOp : PostfixExpr → PostfixExpr
  | DecOp : PostfixExpr → PostfixExpr

inductive UnaryOp where
  | Address : UnaryOp
  | Indirection : UnaryOp
  | Plus : UnaryOp
  | Minus : UnaryOp
  | Complement : UnaryOp
  | LogicalNegation : UnaryOp

inductive UnaryExpr where
  | PostFix : PostfixExpr → UnaryExpr
  | IncUnary : UnaryExpr → UnaryExpr
  | DecUnary : UnaryExpr → UnaryExpr
  | UnaryOpCast : UnaryOp → CastExpr → UnaryExpr
  | SizeOf : UnaryExpr → UnaryExpr
  | SizeOfType : TypeName → UnaryExpr

inductive CastExpr where
  | Unary : UnaryExpr → CastExpr
  | TypeNameCast : TypeName → CastExpr → CastExpr

inductive MultExpr where 
  | Cast : CastExpr → MultExpr
  | MultStar : MultExpr → CastExpr → MultExpr
  | MultDiv : MultExpr → CastExpr → MultExpr
  | MultMod : MultExpr → CastExpr → MultExpr

inductive AddExpr where
  | Mult : MultExpr → AddExpr
  | AddPlus : AddExpr → MultExpr → AddExpr
  | AddMinus : AddExpr → MultExpr → AddExpr

inductive ShiftExpr where
  | Add : AddExpr → ShiftExpr
  | ShiftLeft : ShiftExpr → AddExpr → ShiftExpr
  | ShiftRight : ShiftExpr → AddExpr → ShiftExpr

inductive RelExpr where
  | Shift : ShiftExpr → RelExpr
  | RelLesser : RelExpr → ShiftExpr → RelExpr
  | RelGreater : RelExpr → ShiftExpr → RelExpr
  | RelLE : RelExpr → ShiftExpr → RelExpr
  | RelGE : RelExpr → ShiftExpr → RelExpr

inductive EqExpr where
  | Rel : RelExpr → EqExpr
  | EqEqual : EqExpr →  RelExpr → EqExpr
  | EqNotEqual : EqExpr →  RelExpr → EqExpr

inductive AndExpr where
  | Eq : EqExpr → AndExpr
  | AndAmp : AndExpr → EqExpr → AndExpr

inductive XOrExpr where
  | And : AndExpr → XOrExpr
  | XOrCaret : XOrExpr → AndExpr → XOrExpr

inductive IOrExpr where
  | XOr : XOrExpr → IOrExpr
  | IOrPipe : IOrExpr → XOrExpr → IOrExpr

inductive LAndExpr where 
  | IOr : IOrExpr → LAndExpr
  | LAndDblAmp : LAndExpr → IOrExpr → LAndExpr

inductive LOrExpr where
  | LAnd : LAndExpr → LOrExpr
  | LOrDblPipe : LOrExpr → LAndExpr → LOrExpr

inductive CondExpr where
  | LOr : LOrExpr → CondExpr
  | CondTernary : LOrExpr → Expression → CondExpr → CondExpr

inductive AssmtOp where
  | Assign : AssmtOp
  | MulAssign : AssmtOp
  | DivAssign : AssmtOp
  | ModAssign : AssmtOp
  | AddAssign : AssmtOp
  | SubAssign : AssmtOp
  | LeftAssign : AssmtOp
  | RightAssign : AssmtOp
  | AndAssign : AssmtOp
  | XOrAssign : AssmtOp
  | OrAssign : AssmtOp

inductive AssmtExpr where
  | Cond : CondExpr → AssmtExpr
  | AssignAssmtOp : UnaryExpr → AssmtOp → AssmtExpr → AssmtExpr

inductive ArgExprList where
  | AssmtExprList : List AssmtExpr → ArgExprList
--  | AssmtExpr : AssmtExpr → ArgExprList
--  | ArgExprListAssign : ArgExprList → AssmtExpr → ArgExprList

inductive Expression : Type where
  | AssmtExprList : List AssmtExpr → Expression
--  | ExprAssmtExpr : AssmtExpr → Expression
--  | ExprAssign : Expression → AssmtExpr → Expression

inductive ConstantExpr where
  | ConExpr : CondExpr → ConstantExpr

inductive DirAbstrDecl where
  | DirAbDecAbsRnd : AbstrDecl → DirAbstrDecl
  | DirAbDecSqr : DirAbstrDecl
  | DirAbDecConSqr : ConstantExpr → DirAbstrDecl
  | DirAbDecDirSqr : DirAbstrDecl → DirAbstrDecl
  | DirAbDecDirConst : DirAbstrDecl → ConstantExpr → DirAbstrDecl
  | DirAbDecRnd : DirAbstrDecl
  | DirAbDecParamList : ParamTypeList → DirAbstrDecl
  | DirAbDecDirRnd : DirAbstrDecl → DirAbstrDecl
  | DirAbDecDirParamList : DirAbstrDecl → ParamTypeList → DirAbstrDecl

inductive AbstrDecl where
  | AbstrPtr : Pointer → AbstrDecl
  | AbstrDirAbDec : DirAbstrDecl → AbstrDecl
  | AbstrPtrDirAbDec : Pointer → DirAbstrDecl → AbstrDecl

inductive IdentList where 
  | IdentList : List String → IdentList
--  | Identifier : String → IdentList
--  | IdentListIdent : IdentList → String → IdentList

inductive DirDecl where
  | Identifier : String → DirDecl
  | DeclRnd : Declarator → DirDecl
  | DirDecConst : DirDecl → ConstantExpr → DirDecl
  | DirDecSqr : DirDecl → DirDecl
  | DirDecParamList : DirDecl → ParamTypeList → DirDecl
  | DirDecIdentList : DirDecl → IdentList → DirDecl
  | DirDecRnd : DirDecl → DirDecl

inductive TypeQualList where 
  | TypeQualList : List TypeQual → TypeQualList
--  | TypeQual : TypeQual → TypeQualList
--  | TypeQuaListTypeQuq : TypeQualList → TypeQual → TypeQualList

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

inductive Declaration where
  | DeclSpec : DeclSpec → Declaration
  | DeclSpecInitDecList : DeclSpec → InitDeclList → Declaration

inductive DeclList where
  | DeclList : List Declaration → DeclList
--  | Decl : Declaration → DeclList
--  | DeclListDecl : DeclList → Declaration → DeclList

inductive DeclSpec where
--  | DeclSpec : List (StorClassSpec ⊕ TypeSpec ⊕ TypeQual) → DeclSpec
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
  | EnumList : List Enumerator → EnumList
--  | Enum : Enumerator → EnumList
--  | EnumListEnum : EnumList → Enumerator → EnumList

inductive EnumSpec where
  | EnumList : EnumList → EnumSpec
  | IdentEnumList : String → EnumList → EnumSpec
  | EnumIdent : String → EnumSpec

inductive InitDeclList where
  | InitDeclList : List InitDecl → InitDeclList
--  | InitDecl : InitDecl → InitDeclList
--  | InitDeclListInitDecl : InitDeclList → InitDecl → InitDeclList

inductive ParamDecl where
  | DeclSpecDecl : DeclSpec → Declarator → ParamDecl
  | DeclSpecAbsDecl : DeclSpec → AbstrDecl → ParamDecl
  | DeclSpec : DeclSpec → ParamDecl

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
--  | TypeSpecSpecQualList : TypeSpec → SpecQualList → SpecQualList
--  | TypeSpec : TypeSpec → SpecQualList
--  | TypeQualSpecQualList : TypeQual → SpecQualList → SpecQualList
--  | TypeQual : TypeQual → SpecQualList

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
  | SpecQualListStructDecList : SpecQualList → StructDeclList → StructDeclaration

inductive StructDeclarationList where
  | StructDeclarationList : List StructDeclaration → StructDeclarationList
--  | StructDeclaration : StructDeclaration → StructDeclarationList
--  | StructDeclListStructDecl : StructDeclarationList → StructDeclaration → StructDeclarationList

inductive StructDeclList where
  | StructDeclList : List StructDecl → StructDeclList
--  | StructDecl : StructDecl → StructDeclList
--  | StructDecListStructDec : StructDeclList → StructDecl → StructDeclList

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
  | TypeName : String → TypeSpec

inductive ExprStmt where
  | Semicolon : ExprStmt
  | Expression : Expression → ExprStmt

inductive SelStmt where
  | If : Expression → Statement → SelStmt
  | IfElse : Expression → Statement → Statement → SelStmt
  | Switch : Expression → Statement → SelStmt

inductive IterStmt where
  | While : Expression → Statement → IterStmt
  | DoWhile : Statement → Expression → IterStmt
  | For : ExprStmt → ExprStmt → Statement → IterStmt
  | ForExpr : ExprStmt → ExprStmt → Expression → Statement → IterStmt

inductive JumpStmt where
  | Goto : String → JumpStmt
  | Continue : JumpStmt
  | Break : JumpStmt
  | Return : JumpStmt
  | ReturnExpr : Expression → JumpStmt

inductive LabelStmt where
  | Identifier : String → Statement → LabelStmt
  | Case : ConstantExpr → Statement → LabelStmt
  | Default : Statement → LabelStmt

inductive CompStmt where
  | Brackets : CompStmt
  | StmtList : StmtList → CompStmt
  | DeclList : DeclList → CompStmt
  | DeclListStmtList : DeclList → StmtList → CompStmt

inductive Statement where
  | LabelStmt : LabelStmt → Statement
  | CompStmt : CompStmt → Statement
  | ExprStmt : ExprStmt → Statement
  | SelStmt : SelStmt → Statement
  | IterStmt : IterStmt → Statement
  | JumpStmt : JumpStmt → Statement
  | TypeDef : TypeSpec → String → Statement

inductive StmtList where
  | StmtList : List Statement → StmtList
--  | Statement : Statement → StmtList
--  | StmtListStmt : StmtList → Statement → StmtList

inductive FuncDef where
  | DecSpecDeclDecListCompStmt : DeclSpec → Declarator → DeclList → CompStmt → FuncDef
  | DecSpecDeclCompStmt : DeclSpec → Declarator → CompStmt → FuncDef
  | DeclDecListCompStmt : Declarator → DeclList → CompStmt → FuncDef
  | DeclCompStmt : Declarator → CompStmt → FuncDef

inductive ExternDecl where
  | FuncDef : FuncDef → ExternDecl
  | Declaration : Declaration → ExternDecl

inductive TranslUnit where
  | ExternDeclList : List ExternDecl → TranslUnit
--  | ExternDecl : ExternDecl → TranslUnit
--  | TranslUnitExternDecl : TranslUnit → ExternDecl → TranslUnit

end

end AST