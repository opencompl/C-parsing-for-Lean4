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
instance : Inhabited EqExpr where default := EqExpr.Rel (default : RelExpr)
instance : Inhabited AndExpr where default := AndExpr.Eq (default : EqExpr)
instance : Inhabited XOrExpr where default := XOrExpr.And (default : AndExpr)
instance : Inhabited IOrExpr where default := IOrExpr.XOr (default : XOrExpr)
instance : Inhabited LAndExpr where default := LAndExpr.IOr (default : IOrExpr)
instance : Inhabited LOrExpr where default := LOrExpr.LAnd (default : LAndExpr)
instance : Inhabited CondExpr where default := CondExpr.LOr (default : LOrExpr)
instance : Inhabited AssmtOp where default := AssmtOp.Assign
instance : Inhabited AssmtExpr where default := AssmtExpr.Cond (default : CondExpr)
instance : Inhabited ArgExprList where default := ArgExprList.AssmtExpr (default : AssmtExpr)
instance : Inhabited Expression where default := Expression.ExprAssmtExpr (default : AssmtExpr)

mutual
partial def primaryExprToString : PrimaryExpr → String
  | .Identifier s => s
  | .Constant c => toString c
  | .StringLit s => "\"" ++ s ++ "\""
  | .BracketExpr e => "(" ++ (exprToString e) ++ ")"

partial def postfixExprToString : PostfixExpr → String
  | .Primary p => primaryExprToString p
  | .SquareBrack p e => (postfixExprToString p) ++ "[" ++ (exprToString e) ++ "]"
  | .CurlyBrack p => (postfixExprToString p) ++ "()"
  | .AEL p ael => (postfixExprToString p) ++ "(" ++ (aelToString ael) ++ ")"
  | .Identifier p s => (postfixExprToString p) ++ "." ++ s
  | .PtrIdent p s => (postfixExprToString p) ++ "->" ++ s
  | .IncOp p => (postfixExprToString p) ++ "++"
  | .DecOp p => (postfixExprToString p) ++ "--"

partial def unaryOpToString : UnaryOp → String
  | .Address => "&"
  | .Indirection => "*"
  | .Plus => "+"
  | .Minus => "-"
  | .Complement => "~"
  | .LogicalNegation => "!"

partial def unaryExprToString : UnaryExpr → String
  | .PostFix p => (postfixExprToString p)
  | .IncUnary p => "++" ++ (unaryExprToString p)
  | .DecUnary p => "--" ++ (unaryExprToString p)
  | .UnaryOpCast o c => (unaryOpToString o) ++ (castExprToString c)
  | .SizeOf u => "sizeof " ++ (unaryExprToString u)
--  | .SizeOfType t => "sizeof(" ++ (typeNametoString t) ++ ")"
  | _ => "not implemented"

partial def castExprToString : CastExpr → String
  | .Unary u => (unaryExprToString u)
--  | .TypeNameCast t c => "(" ++ (typeNametoString t) ++ ")" ++ (castExprToString c)
  | _ => "not implemented"

partial def multExprToString : MultExpr → String
  | .Cast c => (castExprToString c)
  | .MultStar m c => (multExprToString m) ++ " * " ++ (castExprToString c)
  | .MultDiv m c => (multExprToString m) ++ " / " ++ (castExprToString c)
  | .MultMod m c => (multExprToString m) ++ " % " ++ (castExprToString c)

partial def addExprToString : AddExpr → String
  | .Mult m => (multExprToString m)
  | .AddPlus a m => (addExprToString a) ++ " + " ++ (multExprToString m)
  | .AddMinus a m => (addExprToString a) ++ " - " ++ (multExprToString m)

partial def shiftExprToString : ShiftExpr → String
  | .Add a => (addExprToString a)
  | .ShiftLeft s a => (shiftExprToString s) ++ " << " ++ (addExprToString a)
  | .ShiftRight s a => (shiftExprToString s) ++ " >> " ++ (addExprToString a)

partial def relExprToString : RelExpr → String
  | .Shift s => (shiftExprToString s)
  | .RelLesser r s => (relExprToString r) ++ " < " ++ (shiftExprToString s)
  | .RelGreater r s => (relExprToString r) ++ " > " ++ (shiftExprToString s)
  | .RelLE r s => (relExprToString r) ++ " <= " ++ (shiftExprToString s)
  | .RelGE r s => (relExprToString r) ++ " >= " ++ (shiftExprToString s)

partial def eqExprToString : EqExpr → String
  | .Rel r => (relExprToString r)
  | .EqEqual e r => (eqExprToString e) ++ " == " ++ (relExprToString r)
  | .EqNotEqual e r => (eqExprToString e) ++ " != " ++ (relExprToString r)

partial def andExprToString : AndExpr → String
  | .Eq e => (eqExprToString e)
  | .AndAmp a e => (andExprToString a) ++ " & " ++ (eqExprToString e)

partial def xorExprToString : XOrExpr → String
  | .And a => (andExprToString a)
  | .XOrCaret x a => (xorExprToString x) ++ " ^ " ++ (andExprToString a)

partial def iorExprToString : IOrExpr → String
  | .XOr x => (xorExprToString x)
  | .IOrPipe i x => (iorExprToString i) ++ " | " ++ (xorExprToString x)

partial def landExprToString : LAndExpr → String
  | .IOr i => (iorExprToString i)
  | .LAndDblAmp l i => (landExprToString l) ++ " && " ++ (iorExprToString i)

partial def lorExprToString : LOrExpr → String
  | .LAnd l => (landExprToString l)
  | .LOrDblPipe lo la => (lorExprToString lo) ++ " || " ++ (landExprToString la)

partial def condExprToString : CondExpr → String
  | .LOr l => (lorExprToString l)
  | .CondTernary l e c => (lorExprToString l) ++ " ? " ++ (exprToString e) ++ " : " ++ (condExprToString c)

partial def assmtOpToString : AssmtOp → String
  | .Assign => "="
  | .MulAssign => "*="
  | .DivAssign => "/="
  | .ModAssign => "%="
  | .AddAssign => "+="
  | .SubAssign => "-="
  | .LeftAssign => "<<="
  | .RightAssign => ">>="
  | .AndAssign => "&="
  | .XOrAssign => "^="
  | .OrAssign => "|="

partial def assmtExprToString : AssmtExpr → String
  | .Cond c => (condExprToString c)
  | .AssignAssmtOp u ao ae => (unaryExprToString u) ++ " " ++ (assmtOpToString ao) ++ " " ++ (assmtExprToString ae)

partial def aelToString : ArgExprList → String
  | .AssmtExpr a => (assmtExprToString a)
  | .ArgExprListAssign ael ae => (aelToString ael) ++ " , " ++ (assmtExprToString ae)

partial def exprToString : Expression → String
  | .ExprAssmtExpr a => (assmtExprToString a)
  | .ExprAssign e a => (exprToString e) ++ " , " ++ (assmtExprToString a)

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
instance : ToString EqExpr where toString := eqExprToString
instance : ToString AndExpr where toString := andExprToString
instance : ToString XOrExpr where toString := xorExprToString
instance : ToString IOrExpr where toString := iorExprToString
instance : ToString LAndExpr where toString := landExprToString
instance : ToString LOrExpr where toString := lorExprToString
instance : ToString CondExpr where toString := condExprToString
instance : ToString AssmtOp where toString := assmtOpToString
instance : ToString AssmtExpr where toString := assmtExprToString
instance : ToString ArgExprList where toString := aelToString
instance : ToString Expression where toString := exprToString