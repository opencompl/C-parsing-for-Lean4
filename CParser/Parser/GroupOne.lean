import CParser.AST
import CParser.Syntax
import CParser.Util
open AST


partial def mkPrimaryExpression : Lean.Syntax → Except String PrimaryExpr
  | `(primary_expression| $s:ident) => return (PrimaryExpr.Identifier s.getId.toString)
  | _ => throw "unexpected syntax"

def parsePrimaryExpression := mkNonTerminalParser `primary_expression mkPrimaryExpression
def parse := parsePrimaryExpression
