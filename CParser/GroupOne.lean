import CParser.SyntaxDecl

partial def mkPrimaryExpression : Lean.Syntax → Except String PrimaryExpr
  | `(`[primary_expression| $s:ident]) => return (PrimaryExpr.Identifier s.getId.toString)
  | u => throw "unexpected syntax"