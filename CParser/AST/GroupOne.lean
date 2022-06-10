import CParser.SyntaxDecl
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

inductive PrimaryExpr where
  | Identifier : String → PrimaryExpr
  | Constant : Int → PrimaryExpr
  | StringLit : String → PrimaryExpr
  | BracketExpr : Expression → PrimaryExpr

syntax str : primary_expression
syntax ident : primary_expression
syntax num : primary_expression
syntax "(" expression ")" : primary_expression

syntax "`[primary_expression| " primary_expression "]" : term

inductive PostfixExpr where
  | Primary : PrimaryExpr → PostfixExpr
  | SquareBrack : Expression → PostfixExpr
  | CurlyBrack : PostfixExpr → PostfixExpr      -- I am not sure of this case
  | AEL : ArgumentExpressionList → PostfixExpr
  | Identifier : String → PostfixExpr
  | PtrIdent : String → PostfixExpr
  | IncOp : String → PostfixExpr
  | DecOp : String → PostfixExpr

syntax primary_expression : postfix_expression
syntax "[" expression "]" : postfix_expression
syntax "(" ")"  : postfix_expression
syntax "(" argument_expression_list ")" : postfix_expression
syntax "." ident : postfix_expression
syntax "->" ident : postfix_expression
syntax "++" : postfix_expression
syntax "--" : postfix_expression

syntax "`[postfix_expression| " postfix_expression "]" : term

inductive UnaryOp where
  | Address : String → UnaryOp
  | Indirection : String → UnaryOp
  | Plus : String → UnaryOp
  | Minus : String → UnaryOp
  | Complement : String → UnaryOp
  | LogicalNegation: String → UnaryOp

syntax "&" : unary_operator
syntax "*" : unary_operator
syntax "+" : unary_operator
syntax "-" : unary_operator
syntax "~" : unary_operator
syntax "!" : unary_operator

syntax "`[unary_operator| " unary_operator "]" : term

inductive UnaryExpr where
  | PostFix : PostfixExpr → UnaryExpr
  | IncUnary : UnaryExpr → UnaryExpr
  | DecUnary : UnaryExpr → UnaryExpr
  | UnaryOpCast : UnaryOp → UnaryExpr
  | SizeOf : UnaryExpr → UnaryExpr
  | SizeOfType : TypeName → UnaryExpr

syntax postfix_expression : unary_expression
syntax "++" unary_expression : unary_expression
syntax "--" unary_expression : unary_expression
syntax unary_operator cast_expression : unary_expression
syntax "sizeof" unary_expression : unary_expression
-- syntax "sizeof" "(" type_name ")" : unary_expression   -- type_name not in group one

syntax "`[unary_expression| " unary_expression "]" : term



-- Expression is incomplete, temporarily made for primary_expression
inductive Expression : Type where
  | Foo: Int → Expression

syntax num : expression

syntax "`[Expression| " expression "]" : term
