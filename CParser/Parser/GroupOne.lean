import CParser.AST
import CParser.AST.ClassDec
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
  | `(postfix_expression| $p:postfix_expression . $i:ident) => PostfixExpr.Identifier <$> (mkPostfixExpression p) <*> (return i.getId.toString)
  | `(postfix_expression| $p:postfix_expression ( $args:argument_expression_list )) => PostfixExpr.AEL <$> (mkPostfixExpression p) <*> (mkArgExprList args)
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

partial def mkMultExpression : Lean.Syntax → Except String MultExpr
  | `(multiplicative_expression| $c:cast_expression) => MultExpr.Cast <$> (mkCastExpression c)
  | `(multiplicative_expression| $m:multiplicative_expression * $c:cast_expression) => MultExpr.MultStar <$> (mkMultExpression m) <*> (mkCastExpression c)
  | `(multiplicative_expression| $m:multiplicative_expression / $c:cast_expression) => MultExpr.MultDiv <$> (mkMultExpression m) <*> (mkCastExpression c)
  | `(multiplicative_expression| $m:multiplicative_expression % $c:cast_expression) => MultExpr.MultMod <$> (mkMultExpression m) <*> (mkCastExpression c)
  | _ => throw "unexpected syntax"

partial def mkAddExpression : Lean.Syntax → Except String AddExpr
  | `(additive_expression| $m:multiplicative_expression) => AddExpr.Mult <$> (mkMultExpression m)
  | `(additive_expression| $a:additive_expression + $m:multiplicative_expression) => AddExpr.AddPlus <$> (mkAddExpression a) <*> (mkMultExpression m)
  | `(additive_expression| $a:additive_expression - $m:multiplicative_expression) => AddExpr.AddMinus <$> (mkAddExpression a) <*> (mkMultExpression m)
  | _ => throw "unexpected syntax"

partial def mkShiftExpression : Lean.Syntax → Except String ShiftExpr
  | `(shift_expression| $a:additive_expression) => ShiftExpr.Add <$> (mkAddExpression a)
  | `(shift_expression| $s:shift_expression << $a:additive_expression) => ShiftExpr.ShiftLeft <$> (mkShiftExpression s) <*> (mkAddExpression a)
  | `(shift_expression| $s:shift_expression >> $a:additive_expression) => ShiftExpr.ShiftRight <$> (mkShiftExpression s) <*> (mkAddExpression a)
  | _ => throw "unexpected syntax"

partial def mkRelExpression : Lean.Syntax → Except String RelExpr
  | `(relational_expression| $s:shift_expression) => RelExpr.Shift <$> (mkShiftExpression s)
  | `(relational_expression| $r:relational_expression < $s:shift_expression) => RelExpr.RelLesser <$> (mkRelExpression r) <*> (mkShiftExpression s)
  | `(relational_expression| $r:relational_expression > $s:shift_expression) => RelExpr.RelGreater <$> (mkRelExpression r) <*> (mkShiftExpression s)
  | `(relational_expression| $r:relational_expression <= $s:shift_expression) => RelExpr.RelLE <$> (mkRelExpression r) <*> (mkShiftExpression s)
  | `(relational_expression| $r:relational_expression >= $s:shift_expression) => RelExpr.RelGE <$> (mkRelExpression r) <*> (mkShiftExpression s)
  | _ => throw "unexpected syntax"

partial def mkEqExpression : Lean.Syntax → Except String EqExpr
  | `(equality_expression| $r:relational_expression) => EqExpr.Rel <$> (mkRelExpression r)
  | `(equality_expression| $e:equality_expression == $r:relational_expression) => EqExpr.EqEqual <$> (mkEqExpression e) <*> (mkRelExpression r)
  | `(equality_expression| $e:equality_expression != $r:relational_expression) => EqExpr.EqNotEqual <$> (mkEqExpression e) <*> (mkRelExpression r)
  | _ => throw "unexpected syntax"

partial def mkAndExpression : Lean.Syntax → Except String AndExpr
  | `(and_expression| $e:equality_expression) => AndExpr.Eq <$> (mkEqExpression e)
  | `(and_expression| $a:and_expression & $e:equality_expression) => AndExpr.AndAmp <$> (mkAndExpression a) <*> (mkEqExpression e)
  | _ => throw "unexpected syntax"

partial def mkXOrExpression : Lean.Syntax → Except String XOrExpr
  | `(exclusive_or_expression| $a:and_expression) => XOrExpr.And <$> (mkAndExpression a)
  | `(exclusive_or_expression| $x:exclusive_or_expression ^ $a:and_expression) => XOrExpr.XOrCaret <$> (mkXOrExpression x) <*> (mkAndExpression a)
  | _ => throw "unexpected syntax"

partial def mkIOrExpression : Lean.Syntax → Except String IOrExpr
  | `(inclusive_or_expression| $x:exclusive_or_expression) => IOrExpr.XOr <$> (mkXOrExpression x)
  | `(inclusive_or_expression| $i:inclusive_or_expression | $x:exclusive_or_expression) => IOrExpr.IOrPipe <$> (mkIOrExpression i) <*> (mkXOrExpression x)
  | _ => throw "unexpected syntax"

partial def mkLAndExpression : Lean.Syntax → Except String LAndExpr
  | `(logical_and_expression| $i:inclusive_or_expression) => LAndExpr.IOr <$> (mkIOrExpression i)
    | `(logical_and_expression| $l:logical_and_expression && $i:inclusive_or_expression) => LAndExpr.LAndDblAmp <$> (mkLAndExpression l) <*> (mkIOrExpression i)
  | _ => throw "unexpected syntax"

partial def mkLOrExpression : Lean.Syntax → Except String LOrExpr
  | `(logical_or_expression| $l:logical_and_expression) => LOrExpr.LAnd <$> (mkLAndExpression l)
  | `(logical_or_expression| $lo:logical_or_expression || $la:logical_and_expression) => LOrExpr.LOrDblPipe <$> (mkLOrExpression lo) <*> (mkLAndExpression la)
  | _ => throw "unexpected syntax"

partial def mkCondExpression : Lean.Syntax → Except String CondExpr
  | `(conditional_expression| $l:logical_or_expression) => CondExpr.LOr <$> (mkLOrExpression l)
  | `(conditional_expression| $l:logical_or_expression ? $e:expression : $c:conditional_expression) => CondExpr.CondTernary <$> (mkLOrExpression l) <*> (mkExpression e) <*> (mkCondExpression c)
  | _ => throw "unexpected syntax"

partial def mkAssmtOperator : Lean.Syntax → Except String AssmtOp
  | `(assignment_operator| =) => return AssmtOp.Assign
  | `(assignment_operator| *=) => return AssmtOp.MulAssign
  | `(assignment_operator| /=) => return AssmtOp.DivAssign
  | `(assignment_operator| %=) => return AssmtOp.ModAssign
  | `(assignment_operator| +=) => return AssmtOp.AddAssign
  | `(assignment_operator| -=) => return AssmtOp.SubAssign
  | `(assignment_operator| <<=) => return AssmtOp.LeftAssign
  | `(assignment_operator| >>=) => return AssmtOp.RightAssign
  | `(assignment_operator| &=) => return AssmtOp.AndAssign
  | `(assignment_operator| ^=) => return AssmtOp.XOrAssign
  | `(assignment_operator| |=) => return AssmtOp.OrAssign
  | _ => throw "unexpected syntax"

partial def mkAssmtExpression : Lean.Syntax → Except String AssmtExpr
  | `(assignment_expression| $c:conditional_expression) => AssmtExpr.Cond <$> (mkCondExpression c)
  | `(assignment_expression| $u:unary_expression $ao:assignment_operator $ae:assignment_expression) => AssmtExpr.AssignAssmtOp <$> (mkUnaryExpression u) <*> (mkAssmtOperator ao) <*> (mkAssmtExpression ae)
  | _ => throw "unexpected syntax"

partial def mkArgExprList : Lean.Syntax → Except String ArgExprList
  | `(argument_expression_list| $a:assignment_expression) => ArgExprList.AssmtExpr <$> (mkAssmtExpression a)
  | `(argument_expression_list| $ael:argument_expression_list , $ae:assignment_expression) => ArgExprList.ArgExprListAssign <$> (mkArgExprList ael) <*> (mkAssmtExpression ae)
  | _ => throw "unexpected syntax"

partial def mkExpression : Lean.Syntax → Except String Expression
  | `(expression| $a:assignment_expression) => Expression.ExprAssmtExpr <$> (mkAssmtExpression a)
  | `(expression| $e:expression , $ae:assignment_expression) => Expression.ExprAssign <$> (mkExpression e) <*> (mkAssmtExpression ae)
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

def parseMultExpression : String → Lean.Environment → Option String × MultExpr :=
  mkNonTerminalParser `multiplicative_expression mkMultExpression

def parseAddExpression : String → Lean.Environment → Option String × AddExpr :=
  mkNonTerminalParser `additive_expression mkAddExpression

def parseShiftExpression : String → Lean.Environment → Option String × ShiftExpr :=
  mkNonTerminalParser `shift_expression mkShiftExpression

def parseRelExpression : String → Lean.Environment → Option String × RelExpr :=
  mkNonTerminalParser `relational_expression mkRelExpression

def parseEqExpression : String → Lean.Environment → Option String × EqExpr :=
  mkNonTerminalParser `equality_expression mkEqExpression

def parseAndExpression : String → Lean.Environment → Option String × AndExpr :=
  mkNonTerminalParser `and_expression mkAndExpression

def parseXOrExpression : String → Lean.Environment → Option String × XOrExpr :=
  mkNonTerminalParser `exclusive_or_expression mkXOrExpression

def parseIOrExpression : String → Lean.Environment → Option String × IOrExpr :=
  mkNonTerminalParser `inclusive_or_expression mkIOrExpression

def parseLAndExpression : String → Lean.Environment → Option String × LAndExpr :=
  mkNonTerminalParser `logical_and_expression mkLAndExpression

def parseLOrExpression : String → Lean.Environment → Option String × LOrExpr :=
  mkNonTerminalParser `logical_or_expression mkLOrExpression

def parseCondExpression : String → Lean.Environment → Option String × CondExpr :=
  mkNonTerminalParser `conditional_expression mkCondExpression

def parseAssmtOperator : String → Lean.Environment → Option String × AssmtOp :=
  mkNonTerminalParser `assignment_operator mkAssmtOperator

def parseAssmtExpression : String → Lean.Environment → Option String × AssmtExpr :=
  mkNonTerminalParser `assignment_expression mkAssmtExpression

def parseArgExprList : String → Lean.Environment → Option String × ArgExprList :=
  mkNonTerminalParser `argument_expression_list mkArgExprList

def parseExpression : String → Lean.Environment → Option String × Expression :=
  mkNonTerminalParser `expression mkExpression

-- Parse the top-level nonterminal of our grammar.
def parseToplevelNonterminal := parseExpression

-- C parser, which invokes the top level nonterminal parser.
def parse := parseToplevelNonterminal
