import CParser.AST
import CParser.Syntax
open AST

macro_rules
  | `(`[primary_expression| $s:ident]) => `(PrimaryExpr.Identifier $(Lean.quote s.getId.toString))
  | `(`[primary_expression| $n:num]) => `(PrimaryExpr.Constant $n)
  | `(`[primary_expression| $s:str]) => `(PrimaryExpr.StringLit $s)
  | `(`[primary_expression| ($s:expression)]) => `(PrimaryExpr.BracketExpr `[expression| $s ])

macro_rules
  | `(`[postfix_expression| $p:primary_expression]) => `(PostfixExpr.Primary `[primary_expression| $p])
  | `(`[postfix_expression| $p:postfix_expression [ $e:expression ]]) => `(PostfixExpr.SquareBrack `[postfix_expression| $p] `[Expression| $e])
  | `(`[postfix_expression| $p:postfix_expression ( )]) => `(PostfixExpr.CurlyBrack `[postfix_expression| $p])
--   | `(`[postfix_expression| $p($args)]) => `(PostfixExpr.AEL `[postfix_expression| $p] `[argument_expression_list| $args])
  | `(`[postfix_expression| $p:postfix_expression . $i:ident]) => `(PostfixExpr.Identifier `[postfix_expression| $p] $(Lean.quote i.getId.toString))
  | `(`[postfix_expression| $p:postfix_expression -> $i:ident]) => `(PostfixExpr.PtrIdent `[postfix_expression| $p] $(Lean.quote i.getId.toString))
  | `(`[postfix_expression| $p:postfix_expression ++]) => `(PostfixExpr.IncOp `[postfix_expression| $p])
--  | `(`[postfix_expression| $p:postfix_expression -]) => `(PostfixExpr.DecOp `[postfix_expression| $p])

macro_rules
  | `(`[unary_operator| &]) => `(UnaryOp.Address)
  | `(`[unary_operator| *]) => `(UnaryOp.Indirection)
  | `(`[unary_operator| +]) => `(UnaryOp.Plus)
  | `(`[unary_operator| -]) => `(UnaryOp.Minus)
  | `(`[unary_operator| ~]) => `(UnaryOp.Complement)
  | `(`[unary_operator| !]) => `(UnaryOp.LogicalNegation)

macro_rules
  | `(`[unary_expression| $p:postfix_expression]) => `(UnaryExpr.PostFix `[postfix_expression| $p])
  | `(`[unary_expression| ++ $u:unary_expression]) => `(UnaryExpr.IncUnary `[unary_expression| $u])
--  | `(`[unary_expression| - $u:unary_expression]) => `(UnaryExpr.DecUnary `[unary_expression| $u])
  | `(`[unary_expression| $o:unary_operator $c:cast_expression]) => `(UnaryOp.UnaryOpCast `[unary_operator| $o] `[cast_expression| $c])
  | `(`[unary_expression| sizeof $u:unary_expression]) => `(UnaryExpr.SizeOf `[unary_expression| $u])
--  | `(`[unary_expression| sizeof ( $t:type_name )]) => `(UnaryExpr.SizeOfType `[type_name| $t])

macro_rules
  | `(`[cast_expression| $u:unary_expression]) => `(CastExpr.Unary `[unary_expression| $u])
--  | `(`[cast_expression| ( $t:type_name ) $c:cast_expression]) => `(CastExpr.TypeNameCast `[type_name| $t] `[cast_expression| $c])

macro_rules
  | `(`[expression| $n:num]) => `(Expression.Foo $n)
