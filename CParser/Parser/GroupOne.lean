import CParser.AST
import CParser.Syntax
import CParser.Util
open AST


-- Parse a piece of lean Syntax into a PrimaryExpr.
partial def mkPrimaryExpression : Lean.Syntax → Except String PrimaryExpr
  | `(primary_expression| $s:ident) => return (PrimaryExpr.Identifier s.getId.toString)
  | _ => throw "unexpected syntax"

-- Parse a primary expression into 
def parsePrimaryExpression : String → Lean.Environment → Option String × PrimaryExpr := 
  mkNonTerminalParser `primary_expression mkPrimaryExpression

-- Parse the top-level nonterminal of our grammar.
def parseToplevelNonterminal := parsePrimaryExpression

-- C parser, which invokes the top level nonterminal parser.
def parse := parseToplevelNonterminal
