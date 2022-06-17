import CParser.AST.GroupOne

open AST
instance : Inhabited PrimaryExpr where default := PrimaryExpr.Constant 0
instance : Inhabited PostfixExpr where default := PostfixExpr.Primary (default : PrimaryExpr)
instance : Inhabited UnaryOp where default := UnaryOp.Address
instance : Inhabited UnaryExpr where default := UnaryExpr.PostFix (default : PostfixExpr)
instance : Inhabited CastExpr where default := CastExpr.Unary (default : UnaryExpr)
instance : Inhabited MultExpr where default := MultExpr.Cast (default : CastExpr)
instance : Inhabited AddExpr where default := AddExpr.Mult (default : MultExpr)
instance : Inhabited ShiftExpr where default := ShiftExpr.Add (default : AddExpr)
instance : Inhabited RelExpr where default := RelExpr.Shift (default : ShiftExpr)
instance : Inhabited Expression where default := Expression.Foo 0

mutual
def primaryExprToString : PrimaryExpr → String
  | .Identifier s => s
  | .Constant c => toString c
  | .StringLit s => "\"" ++ s ++ "\""
  | .BracketExpr e => "(" ++ (exprToString e) ++ ")"

def postfixExprToString : PostfixExpr → String
  | .Primary p => primaryExprToString p
  | .SquareBrack p e => (postfixExprToString p) ++ "[" ++ (exprToString e) ++ "]"
  | .CurlyBrack p => (postfixExprToString p) ++ "()"
  | .AEL p ael => (postfixExprToString p) ++ "(" ++ (aelToString ael) ++ ")"
  | .Identifier p s => (postfixExprToString p) ++ "." ++ s
  | .PtrIdent p s => (postfixExprToString p) ++ "->" ++ s
  | .IncOp p => (postfixExprToString p) ++ "++"
  | .DecOp p => (postfixExprToString p) ++ "--"

def unaryOpToString : UnaryOp → String
  | .Address => "&"
  | .Indirection => "*"
  | .Plus => "+"
  | .Minus => "-"
  | .Complement => "~"
  | .LogicalNegation => "!"

def unaryExprToString : UnaryExpr → String
  | .PostFix p => (postfixExprToString p)
  | .IncUnary p => "++" ++ (unaryExprToString p)
  | .DecUnary p => "--" ++ (unaryExprToString p)
  | .UnaryOpCast o c => (unaryOpToString o) ++ (castExprToString c)
  | .SizeOf u => "sizeof " ++ (unaryExprToString u)
  | .SizeOfType t => "sizeof(" ++ (typeNametoString t) ++ ")"

def castExprToString : CastExpr → String
  | .Unary u => (unaryExprToString u)
  | .TypeNameCast t c => "(" ++ (typeNametoString t) ++ ")" ++ (castExprToString c)

def multExprToString : MultExpr → String
  | .Cast c => (castExprToString c)
  | .MultStar m c => (multExprToString m) ++ " * " ++ (castExprToString c)
  | .MultDiv m c => (multExprToString m) ++ " / " ++ (castExprToString c)
  | .MultMod m c => (multExprToString m) ++ " % " ++ (castExprToString c)

def addExprToString : AddExpr → String
  | .Mult m => (multExprToString m)
  | .AddPlus a m => (addExprToString a) ++ " + " ++ (multExprToString m)
  | .AddMinus a m => (addExprToString a) ++ " - " ++ (multExprToString m)

def shiftExprToString : ShiftExpr → String
  | .Add a => (addExprToString a)
  | .ShiftLeft s a => (shiftExprToString s) ++ " << " ++ (addExprToString a)
  | .ShiftRight s a => (shiftExprToString s) ++ " >> " ++ (addExprToString a)

def relExprToString : RelExpr → String
  | .Shift s => (shiftExprToString s)
  | .RelLesser r s => (relExprToString r) ++ " < " ++ (shiftExprToString s)
  | .RelGreater r s => (relExprToString r) ++ " > " ++ (shiftExprToString s)
  | .RelLE r s => (relExprToString r) ++ " <= " ++ (shiftExprToString s)
  | .RelGE r s => (relExprToString r) ++ " >= " ++ (shiftExprToString s)

def exprToString : Expression → String
  | .Foo n => toString n

def aelToString : ArgumentExpressionList → String
  | _ => "arg_expr_list"

def typeNametoString : TypeName → String
  | _ => "type_name"

end

instance : ToString PrimaryExpr where toString := primaryExprToString
instance : ToString PostfixExpr where toString := postfixExprToString
instance : ToString UnaryOp where toString := unaryOpToString
instance : ToString UnaryExpr where toString := unaryExprToString
instance : ToString CastExpr where toString := castExprToString
instance : ToString MultExpr where toString := multExprToString
instance : ToString AddExpr where toString := addExprToString
instance : ToString ShiftExpr where toString := shiftExprToString
instance : ToString RelExpr where toString := relExprToString
instance : ToString Expression where toString := exprToString