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
  | MulCast : MultExpr → CastExpr → MultExpr
  | MulDiv : MultExpr → CastExpr → MultExpr
  | MulMod : MultExpr → CastExpr → MultExpr

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

-- Expression is incomplete, temporarily made for primary_expression
inductive Expression : Type where
| Foo: Int → Expression
end

instance : Inhabited PrimaryExpr where default := PrimaryExpr.Constant 0
instance : Inhabited PostfixExpr where default := PostfixExpr.Primary (default : PrimaryExpr)
instance : Inhabited UnaryOp where default := UnaryOp.Address
instance : Inhabited UnaryExpr where default := UnaryExpr.PostFix (default : PostfixExpr)
instance : Inhabited CastExpr where default := CastExpr.Unary (default : UnaryExpr)
instance : Inhabited Expression where default := Expression.Foo 0

mutual
def primaryExprToString : PrimaryExpr → String
  | .Identifier s => s
  | .Constant c => toString c
  | .StringLit s => "\"" ++ s ++ "\""
  | .BracketExpr e => "(" ++ (exprToString e) ++ ")"

def postfixExprToString : PostfixExpr → String
  | .Primary p => primaryExprToString p
  | .SquareBrack p e => (postfixExprToString p) ++ "[" ++ (exprToString e) ++ "]"
  | .CurlyBrack p => (postfixExprToString p) ++ "()"
  | .AEL p ael => (postfixExprToString p) ++ "(" ++ (aelToString ael) ++ ")"
  | .Identifier p s => (postfixExprToString p) ++ "." ++ s
  | .PtrIdent p s => (postfixExprToString p) ++ "->" ++ s
  | .IncOp p => (postfixExprToString p) ++ "++"
  | .DecOp p => (postfixExprToString p) ++ "--"

def unaryOpToString : UnaryOp → String
  | .Address => "&"
  | .Indirection => "*"
  | .Plus => "+"
  | .Minus => "-"
  | .Complement => "~"
  | .LogicalNegation => "!"

def unaryExprToString : UnaryExpr → String
  | .PostFix p => (postfixExprToString p)
  | .IncUnary p => "++" ++ (unaryExprToString p)
  | .DecUnary p => "--" ++ (unaryExprToString p)
  | .UnaryOpCast o c => (unaryOpToString o) ++ (castExprToString c)
  | .SizeOf u => "sizeof " ++ (unaryExprToString u)
  | .SizeOfType t => "sizeof(" ++ (typeNametoString t) ++ ")"

def castExprToString : CastExpr → String
  | .Unary u => (unaryExprToString u)
  | .TypeNameCast t c => "(" ++ (typeNametoString t) ++ ")" ++ (castExprToString c)

def exprToString : Expression → String
  | .Foo n => toString n

def aelToString : ArgumentExpressionList → String
  | _ => "arg_expr_list"

def typeNametoString : TypeName → String
  | _ => "type_name"

end

instance : ToString PrimaryExpr where toString := primaryExprToString
instance : ToString PostfixExpr where toString := postfixExprToString
instance : ToString UnaryOp where toString := unaryOpToString
instance : ToString UnaryExpr where toString := unaryExprToString
instance : ToString CastExpr where toString := castExprToString
instance : ToString Expression where toString := exprToString

end AST
