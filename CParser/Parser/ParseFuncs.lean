import CParser.AST
import CParser.AST.ClassDec
import CParser.Syntax
import CParser.Util
import CParser.Parser.MakeFuncs

open AST
open Lean
open Lean.Parser
open Lean.Elab.Command


-- Parse a primary expression into 
def parsePrimaryExpression : String → Lean.Environment → CommandElabM PrimaryExpr := 
  mkNonTerminalParser `primary_expression mkPrimaryExpression

def parseTypeSpec : String → Lean.Environment → CommandElabM TypeSpec := 
  mkNonTerminalParser `type_specifier mkTypeSpec

-- Parse the top-level nonterminal of our grammar.
def parseToplevelNonterminal := parsePrimaryExpression

-- C parser, which invokes the top level nonterminal parser.
def parse := parseToplevelNonterminal
