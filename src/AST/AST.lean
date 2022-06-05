inductive Expression : Type where
  | Foo: Int → Expression

declare_syntax_cat expression

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
