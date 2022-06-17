namespace AST
-- declare_syntax_cat assignment_operator
-- declare_syntax_cat primary_expression
-- declare_syntax_cat postfix_expression
-- declare_syntax_cat argument_expression_list
-- declare_syntax_cat unary_expression
-- declare_syntax_cat unary_operator
-- declare_syntax_cat expression
-- declare_syntax_cat conditional_expression
-- declare_syntax_cat logical_or_expression
-- declare_syntax_cat logical_and_expression
-- declare_syntax_cat inclusive_or_expression
-- declare_syntax_cat exclusive_or_expression
-- declare_syntax_cat and_expression
-- declare_syntax_cat equality_expression
-- declare_syntax_cat relational_expression
-- declare_syntax_cat shift_expression
-- declare_syntax_cat additive_expression
-- declare_syntax_cat multiplicative_expression
-- declare_syntax_cat cast_expression

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
  | AEL : PostfixExpr → ArgumentExpressionList → PostfixExpr
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
  | AssmtExpr : AssmtExpr → ArgExprList
  | ArgExprListAssign : ArgExprList → AssmtExpr → ArgExprList

inductive Expression : Type where
  | ExprAssmtExpr : AssmtExpr → Expression
  | ExprAssign : Expression → AssmtExpr → Expression

end

end AST