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

inductive Expression : Type where
  | Foo: Int → Expression

syntax num : expression

syntax "`[Expression| " expression "]" : term

macro_rules
  | `(`[Expression| $n:num]) => `(Expression.Foo $n)

inductive PrimaryExpr where
  | Identifier : String → PrimaryExpr
  | Constant : Int → PrimaryExpr
  | StringLit : String → PrimaryExpr
  | BracketExpr : Expression → PrimaryExpr

declare_syntax_cat primary_expr

syntax str : primary_expr
syntax num : primary_expr
syntax "(" expression ")" : primary_expr

syntax "`[PrimaryExpr| " primary_expr "]" : term

macro_rules
  | `(`[PrimaryExpr| $s:str]) => `(PrimaryExpr.Identifier $s)
  | `(`[PrimaryExpr| $n:num]) => `(PrimaryExpr.Constant $n)
  | `(`[PrimaryExpr| $s:str]) => `(PrimaryExpr.StringLit $s)
  | `(`[PrimaryExpr| ($s:expression)]) => `(PrimaryExpr.BracketExpr `[Expression| $s ])

#check `[PrimaryExpr| "foo"]
#check `[PrimaryExpr| (420)]
