import CParser.AST
import CParser.AST.ClassDec
import CParser.Syntax
import CParser.Util
open AST

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

partial def mkConstExpr : Lean.Syntax → Except String ConstantExpr
  | `(constant_expression| $c:conditional_expression) => ConstantExpr.ConExpr <$> (mkCondExpression c)
  | _ => throw "unexpected syntax"

partial def mkDirAbstrDecl : Lean.Syntax → Except String DirAbstrDecl
  | `(direct_abstract_declarator| ( $a:abstract_declarator )) => DirAbstrDecl.DirAbDecAbsRnd <$> (mkAbstrDecl a)
  | `(direct_abstract_declarator| [ ]) => return (DirAbstrDecl.DirAbDecSqr)
  | `(direct_abstract_declarator| [ $c:constant_expression ]) => DirAbstrDecl.DirAbDecConSqr <$> (mkConstExpr c)
  | `(direct_abstract_declarator| $d:direct_abstract_declarator [ ]) => DirAbstrDecl.DirAbDecDirSqr <$> (mkDirAbstrDecl d)
  | `(direct_abstract_declarator| $d:direct_abstract_declarator [ $c:constant_expression ]) => DirAbstrDecl.DirAbDecDirConst <$> (mkDirAbstrDecl d) <*> (mkConstExpr c)
  | `(direct_abstract_declarator| ( )) => return (DirAbstrDecl.DirAbDecRnd)
--  | `(direct_abstract_declarator| ( $p:parameter_type_list )) => DirAbstrDecl.DirAbDecParamList <$> (mkParamList p)
  | `(direct_abstract_declarator| $d:direct_abstract_declarator ( )) => DirAbstrDecl.DirAbDecDirRnd <$> (mkDirAbstrDecl d)
--  | `(direct_abstract_declarator| $d:direct_abstract_declarator ( $p:parameter_type_list )) => DirAbstrDecl.DirAbDecDirParamList <$> (mkDirAbstrDecl d) <*> (mkParamList p)
  | _ => throw "unexpected syntax"

partial def mkAbstrDecl : Lean.Syntax → Except String AbstrDecl
  | `(abstract_declarator| $p:pointer) => AbstrDecl.AbstrPtr <$> (mkPointer p)
  | `(abstract_declarator| $d:direct_abstract_declarator) => AbstrDecl.AbstrDirAbDec <$> (mkDirAbstrDecl d)
  | `(abstract_declarator| $p:pointer $d:direct_abstract_declarator) => AbstrDecl.AbstrPtrDirAbDec <$> (mkPointer p) <*> (mkDirAbstrDecl d)
  | _ => throw "unexpected syntax"

partial def mkIdentList : Lean.Syntax → Except String IdentList
  | `(identifier_list| $i:ident) => return (IdentList.Identifier i.getId.toString)
  | `(identifier_list| $il:identifier_list , $i:ident) => IdentList.IdentListIdent <$> (mkIdentList il) <*> (return i.getId.toString)
  | _ => throw "unexpected syntax"

partial def mkDirDecl : Lean.Syntax → Except String DirDecl
  | `(direct_declarator| $i:ident) => return (DirDecl.Identifier i.getId.toString)
  | `(direct_declarator| ( $d:declarator )) => DirDecl.DeclRnd <$> (mkDeclarator d)
  | `(direct_declarator| $d:direct_declarator [ $c:constant_expression ]) => DirDecl.DirDecConst <$> (mkDirDecl d) <*> (mkConstExpr c)
  | `(direct_declarator| $d:direct_declarator [ ]) => DirDecl.DirDecSqr <$> (mkDirDecl d)
  | `(direct_declarator| $d:direct_declarator ( $i:identifier_list )) => DirDecl.DirDecIdentList <$> (mkDirDecl d) <*> (mkIdentList i)
  | `(direct_declarator| $d:direct_declarator ( )) => DirDecl.DirDecRnd <$> (mkDirDecl d)
  | _ => throw "unexpected syntax"

partial def mkTypeQualList : Lean.Syntax → Except String TypeQualList
  | `(type_qualifier_list| $t:type_qualifier) => TypeQualList.TypeQual <$> (mkTypeQual t)
  | `(type_qualifier_list| $tql:type_qualifier_list $t:type_qualifier) => TypeQualList.TypeQuaListTypeQuq <$> (mkTypeQualList tql) <*> (mkTypeQual t)
  | _ => throw "unexpected syntax"

partial def mkTypeQual : Lean.Syntax → Except String TypeQual
  | `(type_qualifier| const) => return (TypeQual.Const)
  | `(type_qualifier| volatile) => return (TypeQual.Volatile)
  | _ => throw "unexpected syntax"

partial def mkPointer : Lean.Syntax → Except String Pointer
  | `(pointer| *) => return (Pointer.Star)
  | `(pointer| * $t:type_qualifier_list) => Pointer.StarTypeQualList <$> (mkTypeQualList t)
  | `(pointer| * $p:pointer) => Pointer.StarPtr <$> (mkPointer p)
  | `(pointer| * $t:type_qualifier_list $p:pointer) => Pointer.StarTypeQualListPtr <$> (mkTypeQualList t) <*> (mkPointer p)
  | _ => throw "unexpected syntax"

partial def mkDeclarator : Lean.Syntax → Except String Declarator
  | `(declarator| $p:pointer $d:direct_declarator) => Declarator.PtrDirDecl <$> (mkPointer p) <*> (mkDirDecl d)
  | `(declarator| $d:direct_declarator) => Declarator.DirDecl <$> (mkDirDecl d)
  | _ => throw "unexpected syntax"

partial def mkInitList : Lean.Syntax → Except String InitList
  | `(initializer_list| $i:initializer) => InitList.Init <$> (mkInitializer i)
  | `(initializer_list| $il:initializer_list , $i:initializer) => InitList.InitListInit <$> (mkInitList il) <*> (mkInitializer i)
  | _ => throw "unexpected syntax"

partial def mkInitializer : Lean.Syntax → Except String Initializer
  | `(initializer| $a:assignment_expression) => Initializer.AssmtExpr <$> (mkAssmtExpression a)
  | `(initializer| { $i:initializer_list }) => Initializer.InitListCurl <$> (mkInitList i)
--  | `(initializer| { $i:initializer_list , } ) => Initializer.InitListCurlComma <$> (mkInitList i)
  | _ => throw "unexpected syntax"

partial def mkInitDecl : Lean.Syntax → Except String InitDecl
  | `(init_declarator| $d:declarator) => InitDecl.Declarator <$> (mkDeclarator d)
  | `(init_declarator| $d:declarator = $i:initializer) => InitDecl.DeclInit <$> (mkDeclarator d) <*> (mkInitializer i)
  | _ => throw "unexpected syntax"

end