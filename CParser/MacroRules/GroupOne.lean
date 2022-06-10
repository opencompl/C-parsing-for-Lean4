import CParser.AST.GroupOne

macro_rules
  | `(`[Expression| $n:num]) => `(Expression.Foo $n)

macro_rules
  | `(`[primary_expression| $s:ident]) => `(PrimaryExpr.Identifier $(Lean.quote s.getId.toString))
  | `(`[primary_expression| $n:num]) => `(PrimaryExpr.Constant $n)
  | `(`[primary_expression| $s:str]) => `(PrimaryExpr.StringLit $s)
  | `(`[primary_expression| ($s:expression)]) => `(PrimaryExpr.BracketExpr `[Expression| $s ])
