import CParser.AST
import CParser.Syntax
import CParser.Util
open AST


-- Parse a piece of lean Syntax into a PrimaryExpr.
mutual
partial def mkPrimaryExpression : Lean.Syntax → Except String PrimaryExpr
  | `(primary_expression| $s:ident) => return (PrimaryExpr.Identifier s.getId.toString)
  | `(primary_expression| $n:num) => return (PrimaryExpr.Constant n.toNat)
  | `(primary_expression| $s:str) => match s.isStrLit? with
                                      | some st => return (PrimaryExpr.StringLit st)
                                      | none => unreachable!
  | `(primary_expression| ($s:expression)) => PrimaryExpr.BracketExpr <$> (mkExpression s)
  | _ => throw "unexpected syntax"

partial def mkPostfixExpression : Lean.Syntax → Except String PostfixExpr
  | `(postfix_expression| $p:primary_expression) => PostfixExpr.Primary <$> (mkPrimaryExpression p)
  | `(postfix_expression| $p:postfix_expression [ $e:expression ]) => PostfixExpr.SquareBrack <$> (mkPostfixExpression p) <*> (mkExpression e)
  | `(postfix_expression| $p:postfix_expression ( )) => PostfixExpr.CurlyBrack <$> (mkPostfixExpression p)
--  | `(postfix_expression| $p:postfix_expression ( $args:argument_expression_list )) => PostfixExpr.AEL <$> (mkPostfixExpression p) (mkAEL args)
  | `(postfix_expression| $p:postfix_expression . $i:ident) => PostfixExpr.Identifier <$> (mkPostfixExpression p) <*> (return i.getId.toString)
  | `(postfix_expression| $p:postfix_expression -> $i:ident) => PostfixExpr.PtrIdent <$> (mkPostfixExpression p) <*> (return i.getId.toString)
  | `(postfix_expression| $p:postfix_expression ++) => PostfixExpr.IncOp <$> (mkPostfixExpression p)
--  | `(postfix_expression| $p:postfix_expression --) => PostfixExpr.DecOp <$> (mkPostfixExpression p)
  | _ => throw "unexpected syntax"

partial def mkUnaryOperator : Lean.Syntax → Except String UnaryOp
  | `(unary_operator| &) => return UnaryOp.Address
  | `(unary_operator| *) => return UnaryOp.Indirection
  | `(unary_operator| +) => return UnaryOp.Plus
  | `(unary_operator| -) => return UnaryOp.Minus
  | `(unary_operator| ~) => return UnaryOp.Complement
  | `(unary_operator| !) => return UnaryOp.LogicalNegation
  | _ => throw "unexpected syntax"

partial def mkUnaryExpression : Lean.Syntax → Except String UnaryExpr
  | `(unary_expression| $p:postfix_expression) => UnaryExpr.PostFix <$> (mkPostfixExpression p)
  | `(unary_expression| ++ $u:unary_expression) => UnaryExpr.IncUnary <$> (mkUnaryExpression u)
--  | `(unary_expression| -- $u:unary_expression) => UnaryExpr.DecUnary <$> (mkUnaryExpression u)
  | `(unary_expression| $o:unary_operator $c:cast_expression) => UnaryExpr.UnaryOpCast <$> (mkUnaryOperator o) <*> (mkCastExpression c)
  | `(unary_expression| sizeof $u:unary_expression) => UnaryExpr.SizeOf <$> (mkUnaryExpression u)
--  | `(unary_expression| sizeof ( $t:type_name )) => UnaryExpr.SizeOfType <$> (mkTypeName t)
  | _ => throw "unexpected syntax"

partial def mkCastExpression : Lean.Syntax → Except String CastExpr
  | `(cast_expression| $u:unary_expression) => CastExpr.Unary <$> (mkUnaryExpression u)
--  | `(cast_expression| ( $t:type_name ) $c:cast_expression) => CastExpr.TypeNameCast <$> (mkTypeName t) <*> (mkCastExpression c)
  | _ => throw "unexpected syntax"

partial def mkExpression : Lean.Syntax → Except String Expression
  | `(expression| $n:num) => return (Expression.Foo n.toNat)
  | _ => throw "unexpected syntax"

end

-- Parse a primary expression into 
def parsePrimaryExpression : String → Lean.Environment → Option String × PrimaryExpr := 
  mkNonTerminalParser `primary_expression mkPrimaryExpression

def parsePostfixExpression : String → Lean.Environment → Option String × PostfixExpr :=
  mkNonTerminalParser `postfix_expression mkPostfixExpression

def parseUnaryOperator : String → Lean.Environment → Option String × UnaryOp :=
  mkNonTerminalParser `unary_operator mkUnaryOperator

def parseUnaryExpression : String → Lean.Environment → Option String × UnaryExpr :=
  mkNonTerminalParser `unary_expression mkUnaryExpression

def parseCastExpression : String → Lean.Environment → Option String × CastExpr :=
  mkNonTerminalParser `cast_expression mkCastExpression

def parseExpression : String → Lean.Environment → Option String × Expression :=
  mkNonTerminalParser `expression mkExpression

-- Parse the top-level nonterminal of our grammar.
def parseToplevelNonterminal := parseCastExpression

-- C parser, which invokes the top level nonterminal parser.
def parse := parseToplevelNonterminal
