import CParser.AST
import CParser.Syntax
import CParser.Util
import Lean

open AST
open Lean -- for SepArray

def getIdent (x : TSyntax [`ident, `type_name_token]) : Except String String :=
  match x.raw with
    | Syntax.node _ name #[Syntax.atom _ val] => if (String.substrEq (name.toString) 0 "type_name_token" 0 15) then return val else throw name.toString
    | Syntax.ident _ _ val _ => return val.toString
    | _ => throw s!"{x.raw}"

mutual
partial def mkPrimaryExpression : Lean.Syntax → Except String PrimaryExpr
  | `(primary_expression| $s:ident) => return (PrimaryExpr.Identifier s.getId.toString)
  -- | `(primary_expression| $s:type_name_token) => PrimaryExpr.Identifier <$> (getIdent s)
  | `(primary_expression| $n:extended_num) => return PrimaryExpr.Constant (n.raw.getArg 0).toNat
  | `(primary_expression| $s:scientific) => let ⟨a, b, c⟩ := s.getScientific
                                            return PrimaryExpr.FloatConstant $ Float.ofScientific a b c 
  | `(primary_expression| $c:char) => return PrimaryExpr.CharLit c.getChar
  | `(primary_expression| $s:str) => return PrimaryExpr.StringLit s.getString
  | `(primary_expression| ($s:expression)) => PrimaryExpr.BracketExpr <$> (mkExpression s)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for primary expression " ++ x)
          | .none => throw "unexpected syntax for primary expression" 

partial def mkPostfixExpression : Lean.Syntax → Except String PostfixExpr
  | `(postfix_expression| $p:primary_expression) => PostfixExpr.Primary <$> (mkPrimaryExpression p)
  | `(postfix_expression| $p:postfix_expression [ $e:expression ]) => PostfixExpr.SquareBrack <$> (mkPostfixExpression p) <*> (mkExpression e)
  | `(postfix_expression| $p:postfix_expression ( )) => PostfixExpr.CurlyBrack <$> (mkPostfixExpression p)
  | `(postfix_expression| $p:postfix_expression . $i:ident) => PostfixExpr.Identifier <$> (mkPostfixExpression p) <*> (return i.getId.toString)
  | `(postfix_expression| $p:postfix_expression . $i:type_name_token) => PostfixExpr.Identifier <$> (mkPostfixExpression p) <*> (getIdent i)
  | `(postfix_expression| $p:postfix_expression ( $args:argument_expression_list )) => PostfixExpr.AEL <$> (mkPostfixExpression p) <*> (mkArgExprList args)
  | `(postfix_expression| $p:postfix_expression -> $i:ident) => PostfixExpr.PtrIdent <$> (mkPostfixExpression p) <*> (return i.getId.toString)
  | `(postfix_expression| $p:postfix_expression -> $i:type_name_token) => PostfixExpr.PtrIdent <$> (mkPostfixExpression p) <*> (getIdent i)
  | `(postfix_expression| $p:postfix_expression ++) => PostfixExpr.IncOp <$> (mkPostfixExpression p)
  | `(postfix_expression| $p:postfix_expression –) => PostfixExpr.DecOp <$> (mkPostfixExpression p)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for postfix expression " ++ x)
          | .none => throw "unexpected syntax for postfix expression" 

partial def mkUnaryOperator : Lean.Syntax → Except String UnaryOp
  | `(unary_operator| &) => return UnaryOp.Address
  | `(unary_operator| *) => return UnaryOp.Indirection
  | `(unary_operator| +) => return UnaryOp.Plus
  | `(unary_operator| -) => return UnaryOp.Minus
  | `(unary_operator| ~) => return UnaryOp.Complement
  | `(unary_operator| !) => return UnaryOp.LogicalNegation
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for unary operator " ++ x)
          | .none => throw "unexpected syntax for unary operator" 

partial def mkUnaryExpression : Lean.Syntax → Except String UnaryExpr
  | `(unary_expression| $p:postfix_expression) => UnaryExpr.PostFix <$> (mkPostfixExpression p)
  | `(unary_expression| ++ $un:unary_expression) => UnaryExpr.IncUnary <$> (mkUnaryExpression un)
  | `(unary_expression| – $un:unary_expression) => UnaryExpr.DecUnary <$> (mkUnaryExpression un)
  | `(unary_expression| $o:unary_operator $c:cast_expression) => UnaryExpr.UnaryOpCast <$> (mkUnaryOperator o) <*> (mkCastExpression c)
  | `(unary_expression| sizeof $un:unary_expression) => UnaryExpr.SizeOf <$> (mkUnaryExpression un)
  | `(unary_expression| sizeof ( $t:type_name )) => UnaryExpr.SizeOfType <$> (mkTypeName t)
  | `(unary_expression| sizeof ( $t:type_name_token )) => UnaryExpr.SizeOfTypeName <$> (getIdent t)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for unary expression " ++ x)
          | .none => throw "unexpected syntax for unary expression" 

-- -- partial def mkCastExpression : Lean.Syntax → Except String CastExpr
-- partial def mkCastExpression : Lean.Syntax → Except String CastExpr := λ stx => dbg_trace stx
--   match stx with
--       | `(cast_expression| $un:unary_expression) => CastExpr.Unary <$> (mkUnaryExpression un)
--       | `(cast_expression| ( $t:type_name ) $c:cast_expression) => CastExpr.TypeNameCast <$> (mkTypeName t) <*> (mkCastExpression c)
--       -- | s => dbg_trace s
--       | s => match s.reprint with
--               | .some x => dbg_trace s
--                           throw ("unexpected syntax for cast expression " ++ x)
--               | .none => dbg_trace s
--                         throw "unexpected syntax for cast expression" 

partial def mkCastExpression : Lean.Syntax → Except String CastExpr
  | `(cast_expression| $un:unary_expression) => CastExpr.Unary <$> (mkUnaryExpression un)
  | `(cast_expression| ( $t:type_name ) $c:cast_expression) => CastExpr.TypeNameCast <$> (mkTypeName t) <*> (mkCastExpression c)
  | s => 
          if s.getKind == "choice" then
            let args := s.getArgs
            let c := args.find? (λ stx => stx.getKind.toString == "«cast_expression(_)_»")
            match c with
              | .some stx => mkCastExpression stx
              | .none => match s.reprint with
                          | .some x => throw ("unexpected syntax for cast expression " ++ x)
                          | .none => throw "unexpected syntax for cast expression" 
         else match s.reprint with
                | .some x => throw ("unexpected syntax for cast expression " ++ x)
                | .none => throw "unexpected syntax for cast expression" 

partial def mkMultExpression : Lean.Syntax → Except String MultExpr
  | `(multiplicative_expression| $c:cast_expression) => MultExpr.Cast <$> (mkCastExpression c)
  | `(multiplicative_expression| $m:multiplicative_expression * $c:cast_expression) => MultExpr.MultStar <$> (mkMultExpression m) <*> (mkCastExpression c)
  | `(multiplicative_expression| $m:multiplicative_expression / $c:cast_expression) => MultExpr.MultDiv <$> (mkMultExpression m) <*> (mkCastExpression c)
  | `(multiplicative_expression| $m:multiplicative_expression % $c:cast_expression) => MultExpr.MultMod <$> (mkMultExpression m) <*> (mkCastExpression c)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for multiplication expression " ++ x)
          | .none => throw "unexpected syntax for multiplication expression" 

partial def mkAddExpression : Lean.Syntax → Except String AddExpr
  | `(additive_expression| $m:multiplicative_expression) => AddExpr.Mult <$> (mkMultExpression m)
  | `(additive_expression| $a:additive_expression + $m:multiplicative_expression) => AddExpr.AddPlus <$> (mkAddExpression a) <*> (mkMultExpression m)
  | `(additive_expression| $a:additive_expression - $m:multiplicative_expression) => AddExpr.AddMinus <$> (mkAddExpression a) <*> (mkMultExpression m)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for addition expression " ++ x)
          | .none => throw "unexpected syntax for addition expression" 

partial def mkShiftExpression : Lean.Syntax → Except String ShiftExpr
  | `(shift_expression| $a:additive_expression) => ShiftExpr.Add <$> (mkAddExpression a)
  | `(shift_expression| $s:shift_expression << $a:additive_expression) => ShiftExpr.ShiftLeft <$> (mkShiftExpression s) <*> (mkAddExpression a)
  | `(shift_expression| $s:shift_expression >> $a:additive_expression) => ShiftExpr.ShiftRight <$> (mkShiftExpression s) <*> (mkAddExpression a)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for shift expression " ++ x)
          | .none => throw "unexpected syntax for shift expression" 

partial def mkRelExpression : Lean.Syntax → Except String RelExpr
  | `(relational_expression| $s:shift_expression) => RelExpr.Shift <$> (mkShiftExpression s)
  | `(relational_expression| $r:relational_expression < $s:shift_expression) => RelExpr.RelLesser <$> (mkRelExpression r) <*> (mkShiftExpression s)
  | `(relational_expression| $r:relational_expression > $s:shift_expression) => RelExpr.RelGreater <$> (mkRelExpression r) <*> (mkShiftExpression s)
  | `(relational_expression| $r:relational_expression <= $s:shift_expression) => RelExpr.RelLE <$> (mkRelExpression r) <*> (mkShiftExpression s)
  | `(relational_expression| $r:relational_expression >= $s:shift_expression) => RelExpr.RelGE <$> (mkRelExpression r) <*> (mkShiftExpression s)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for relational expression " ++ x)
          | .none => throw "unexpected syntax for relational expression" 

partial def mkEqExpression : Lean.Syntax → Except String EqExpr
  | `(equality_expression| $r:relational_expression) => EqExpr.Rel <$> (mkRelExpression r)
  | `(equality_expression| $e:equality_expression == $r:relational_expression) => EqExpr.EqEqual <$> (mkEqExpression e) <*> (mkRelExpression r)
  | `(equality_expression| $e:equality_expression != $r:relational_expression) => EqExpr.EqNotEqual <$> (mkEqExpression e) <*> (mkRelExpression r)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for equation expression " ++ x)
          | .none => throw "unexpected syntax for equation expression" 

partial def mkAndExpression : Lean.Syntax → Except String AndExpr
  | `(and_expression| $e:equality_expression) => AndExpr.Eq <$> (mkEqExpression e)
  | `(and_expression| $a:and_expression & $e:equality_expression) => AndExpr.AndAmp <$> (mkAndExpression a) <*> (mkEqExpression e)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for and expression " ++ x)
          | .none => throw "unexpected syntax for and expression" 

partial def mkXOrExpression : Lean.Syntax → Except String XOrExpr
  | `(exclusive_or_expression| $a:and_expression) => XOrExpr.And <$> (mkAndExpression a)
  | `(exclusive_or_expression| $x:exclusive_or_expression ^ $a:and_expression) => XOrExpr.XOrCaret <$> (mkXOrExpression x) <*> (mkAndExpression a)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for exclusive or expression " ++ x)
          | .none => throw "unexpected syntax for exclusive or expression" 

partial def mkIOrExpression : Lean.Syntax → Except String IOrExpr
  | `(inclusive_or_expression| $x:exclusive_or_expression) => IOrExpr.XOr <$> (mkXOrExpression x)
  | `(inclusive_or_expression| $i:inclusive_or_expression | $x:exclusive_or_expression) => IOrExpr.IOrPipe <$> (mkIOrExpression i) <*> (mkXOrExpression x)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for inclusive or expression " ++ x)
          | .none => throw "unexpected syntax for inclusive or expression" 

partial def mkLAndExpression : Lean.Syntax → Except String LAndExpr
  | `(logical_and_expression| $i:inclusive_or_expression) => LAndExpr.IOr <$> (mkIOrExpression i)
    | `(logical_and_expression| $lo:logical_and_expression && $i:inclusive_or_expression) => LAndExpr.LAndDblAmp <$> (mkLAndExpression lo) <*> (mkIOrExpression i)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for logical and expression " ++ x)
          | .none => throw "unexpected syntax for logical and expression" 

partial def mkLOrExpression : Lean.Syntax → Except String LOrExpr
  | `(logical_or_expression| $lo:logical_and_expression) => LOrExpr.LAnd <$> (mkLAndExpression lo)
  | `(logical_or_expression| $lo:logical_or_expression || $la:logical_and_expression) => LOrExpr.LOrDblPipe <$> (mkLOrExpression lo) <*> (mkLAndExpression la)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for logical or expression " ++ x)
          | .none => throw "unexpected syntax for logical or expression" 

partial def mkCondExpression : Lean.Syntax → Except String CondExpr
  | `(conditional_expression| $lo:logical_or_expression) => CondExpr.LOr <$> (mkLOrExpression lo)
  | `(conditional_expression| $lo:logical_or_expression ? $e:expression : $c:conditional_expression) => CondExpr.CondTernary <$> (mkLOrExpression lo) <*> (mkExpression e) <*> (mkCondExpression c)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for conditional expression " ++ x)
          | .none => throw "unexpected syntax for conditional expression" 

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
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for assignment operator " ++ x)
          | .none => throw "unexpected syntax for assignment operator" 

partial def mkAssmtExpression : Lean.Syntax → Except String AssmtExpr
  | `(assignment_expression| $c:conditional_expression) => AssmtExpr.Cond <$> (mkCondExpression c)
  | `(assignment_expression| $un:unary_expression $ao:assignment_operator $ae:assignment_expression) => AssmtExpr.AssignAssmtOp <$> (mkUnaryExpression un) <*> (mkAssmtOperator ao) <*> (mkAssmtExpression ae)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for assignment expression " ++ x)
          | .none => throw "unexpected syntax for assignment expression" 

partial def mkArgExprList : Lean.Syntax → Except String ArgExprList
  | `(argument_expression_list| $[$xs],*) => do
      let aes <- xs.mapM mkAssmtExpression
      return ArgExprList.AssmtExprList aes.toList
--  | `(argument_expression_list| $a:assignment_expression) => ArgExprList.AssmtExpr <$> (mkAssmtExpression a)
--  | `(argument_expression_list| $ael:argument_expression_list , $ae:assignment_expression) => ArgExprList.ArgExprListAssign <$> (mkArgExprList ael) <*> (mkAssmtExpression ae)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for argument expression list " ++ x)
          | .none => throw "unexpected syntax for argument expression list" 

partial def mkExpression : Lean.Syntax → Except String Expression
  | `(expression| $[$xs],*) => do
      let aes <- xs.mapM mkAssmtExpression
      return Expression.AssmtExprList aes.toList
--  | `(expression| $a:assignment_expression) => Expression.ExprAssmtExpr <$> (mkAssmtExpression a)
--  | `(expression| $e:expression , $ae:assignment_expression) => Expression.ExprAssign <$> (mkExpression e) <*> (mkAssmtExpression ae)
  | `(expression| ( $c:compound_statement )) => Expression.CompStmt <$> (mkCompStmt c)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for expression " ++ x)
          | .none => throw "unexpected syntax for expression" 

partial def mkConstExpr : Lean.Syntax → Except String ConstantExpr
  | `(constant_expression| $c:conditional_expression) => ConstantExpr.ConExpr <$> (mkCondExpression c)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for constant expression " ++ x)
          | .none => throw "unexpected syntax for constant expression" 

partial def mkDirAbstrDecl : Lean.Syntax → Except String DirAbstrDecl
  | `(direct_abstract_declarator| ( $a:abstract_declarator )) => DirAbstrDecl.DirAbDecAbsRnd <$> (mkAbstrDecl a)
  | `(direct_abstract_declarator| [ ]) => return (DirAbstrDecl.DirAbDecSqr)
  | `(direct_abstract_declarator| [ $c:constant_expression ]) => DirAbstrDecl.DirAbDecConSqr <$> (mkConstExpr c)
  | `(direct_abstract_declarator| $d:direct_abstract_declarator [ ]) => DirAbstrDecl.DirAbDecDirSqr <$> (mkDirAbstrDecl d)
  | `(direct_abstract_declarator| $d:direct_abstract_declarator [ $c:constant_expression ]) => DirAbstrDecl.DirAbDecDirConst <$> (mkDirAbstrDecl d) <*> (mkConstExpr c)
  | `(direct_abstract_declarator| ( )) => return (DirAbstrDecl.DirAbDecRnd)
  | `(direct_abstract_declarator| ( $p:parameter_type_list )) => DirAbstrDecl.DirAbDecParamList <$> (mkParamTypeList p)
  | `(direct_abstract_declarator| $d:direct_abstract_declarator ( )) => DirAbstrDecl.DirAbDecDirRnd <$> (mkDirAbstrDecl d)
  | `(direct_abstract_declarator| $d:direct_abstract_declarator ( $p:parameter_type_list )) => DirAbstrDecl.DirAbDecDirParamList <$> (mkDirAbstrDecl d) <*> (mkParamTypeList p)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for direct abstract declarator " ++ x)
          | .none => throw "unexpected syntax for direct abstract declarator" 

partial def mkAbstrDecl : Lean.Syntax → Except String AbstrDecl
  | `(abstract_declarator| $p:pointer) => AbstrDecl.AbstrPtr <$> (mkPointer p)
  | `(abstract_declarator| $d:direct_abstract_declarator) => AbstrDecl.AbstrDirAbDec <$> (mkDirAbstrDecl d)
  | `(abstract_declarator| $p:pointer $d:direct_abstract_declarator) => AbstrDecl.AbstrPtrDirAbDec <$> (mkPointer p) <*> (mkDirAbstrDecl d)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for abstract declarator " ++ x)
          | .none => throw "unexpected syntax for abstract declarator" 


partial def mkIdentList : Lean.Syntax → Except String IdentList
  | `(identifier_list| $[$xs],*) =>
     let is : Except String (Array String) := xs.mapM getIdent
    IdentList.IdentList <$> (is.map Array.toList)
--  | `(identifier_list| $i:ident) => return (IdentList.Identifier i.getId.toString)
--  | `(identifier_list| $il:identifier_list , $i:ident) => IdentList.IdentListIdent <$> (mkIdentList il) <*> (return i.getId.toString)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for identifier list " ++ x)
          | .none => throw "unexpected syntax for identifier list" 

partial def mkDirDecl : Lean.Syntax → Except String DirDecl
  | `(direct_declarator| $i:ident) => return (DirDecl.Identifier i.getId.toString)
  | `(direct_declarator| $i:type_name_token) => DirDecl.Identifier <$> (getIdent i)
  | `(direct_declarator| ( $d:declarator )) => DirDecl.DeclRnd <$> (mkDeclarator d)
  | `(direct_declarator| $d:direct_declarator [ $c:constant_expression ]) => DirDecl.DirDecConst <$> (mkDirDecl d) <*> (mkConstExpr c)
  | `(direct_declarator| $d:direct_declarator [ ]) => DirDecl.DirDecSqr <$> (mkDirDecl d)
  | `(direct_declarator| $d:direct_declarator ( $i:identifier_list )) => DirDecl.DirDecIdentList <$> (mkDirDecl d) <*> (mkIdentList i)
  | `(direct_declarator| $d:direct_declarator ( $p:parameter_type_list )) => DirDecl.DirDecParamList <$> (mkDirDecl d) <*> (mkParamTypeList p)
  | `(direct_declarator| $d:direct_declarator ( )) => DirDecl.DirDecRnd <$> (mkDirDecl d)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for direct declarator " ++ x)
          | .none => throw "unexpected syntax for direct declarator" 

partial def mkTypeQualList : Lean.Syntax → Except String TypeQualList
  | `(type_qualifier_list| $[$xs]*) => do
      -- let sarr : Array Syntax := listOfSyntaxNodes.getSepElems
      let tqs <- xs.mapM mkTypeQual
      return TypeQualList.TypeQualList tqs.toList
--  | `(type_qualifier_list| $t:type_qualifier) => TypeQualList.TypeQual <$> (mkTypeQual t)
--  | `(type_qualifier_list| $tql:type_qualifier_list $t:type_qualifier) => TypeQualList.TypeQuaListTypeQuq <$> (mkTypeQualList tql) <*> (mkTypeQual t)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for type qualifier list " ++ x)
          | .none => throw "unexpected syntax for type qualifier list" 

partial def mkTypeQual : Lean.Syntax → Except String TypeQual
  | `(type_qualifier| const) => return (TypeQual.Const)
  | `(type_qualifier| volatile) => return (TypeQual.Volatile)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for type qualifier " ++ x)
          | .none => throw "unexpected syntax for type qualifier" 

partial def mkPointer : Lean.Syntax → Except String Pointer
  | `(pointer| *) => return (Pointer.Star)
  | `(pointer| * $t:type_qualifier_list) => Pointer.StarTypeQualList <$> (mkTypeQualList t)
  | `(pointer| * $p:pointer) => Pointer.StarPtr <$> (mkPointer p)
  | `(pointer| * $t:type_qualifier_list $p:pointer) => Pointer.StarTypeQualListPtr <$> (mkTypeQualList t) <*> (mkPointer p)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for pointer " ++ x)
          | .none => throw "unexpected syntax for pointer" 

partial def mkDeclarator : Lean.Syntax → Except String Declarator
  | `(declarator| $p:pointer $d:direct_declarator) => Declarator.PtrDirDecl <$> (mkPointer p) <*> (mkDirDecl d)
  | `(declarator| $d:direct_declarator) => Declarator.DirDecl <$> (mkDirDecl d)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for declarator " ++ x)
          | .none => throw "unexpected syntax for declarator" 

/-
partial def mkInitList : Lean.Syntax → Except String InitList
  | `(initializer_list| $i:initializer) => InitList.Init <$> (mkInitializer i)
  | `(initializer_list| $il:initializer_list , $i:initializer) => InitList.InitListInit <$> (mkInitList il) <*> (mkInitializer i)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax " ++ x)
          | .none => throw "unexpected syntax" 
-/

partial def mkInitList : Lean.Syntax → Except String InitList
  | `(initializer_list| $[$xs],*) => do
      let inits <- xs.mapM mkInitializer
      return InitList.InitList inits.toList
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for initializer list " ++ x)
          | .none => throw "unexpected syntax for initializer list" 


partial def mkInitializer : Lean.Syntax → Except String Initializer
  | `(initializer| $a:assignment_expression) => Initializer.AssmtExpr <$> (mkAssmtExpression a)
  | `(initializer| { $i:initializer_list }) => Initializer.InitListCurl <$> (mkInitList i)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for initializer " ++ x)
          | .none => throw "unexpected syntax for initializer" 

partial def mkInitDecl : Lean.Syntax → Except String InitDecl
  | `(init_declarator| $d:declarator) => InitDecl.Declarator <$> (mkDeclarator d)
  | `(init_declarator| $d:declarator = $i:initializer) => 
       InitDecl.DeclInit <$> (mkDeclarator d) <*> (mkInitializer i)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for init declarator " ++ x)
          | .none => throw "unexpected syntax for init declarator" 

partial def mkDeclList : Lean.Syntax → Except String DeclList
--  | `(declaration_list| $[$xs]*) => do
--      let decls <- xs.mapM mkDeclaration
--      return DeclList.DeclList decls.toList
  | `(declaration_list| $d:declaration) => (λ d => DeclList.DeclList [d]) <$> (mkDeclaration d)
  | `(declaration_list| $d:declaration $dl:declaration_list) => (λ (DeclList.DeclList dl) d => DeclList.DeclList ([d] ++ dl)) <$> (mkDeclList dl) <*> (mkDeclaration d)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for declaration list " ++ x)
          | .none => throw "unexpected syntax for declaration list" 

partial def mkTypeSpec : Lean.Syntax → Except String TypeSpec
  | `(type_specifier| void) => return TypeSpec.Void
  | `(type_specifier| char) => return TypeSpec.Char
  | `(type_specifier| short) => return TypeSpec.Short
  | `(type_specifier| int) => return TypeSpec.Int
  | `(type_specifier| long) => return TypeSpec.Long
  | `(type_specifier| float) => return TypeSpec.Float
  | `(type_specifier| double) => return TypeSpec.Double
  | `(type_specifier| signed) => return TypeSpec.Signed
  | `(type_specifier| unsigned) => return TypeSpec.Unsigned
  | `(type_specifier| $s:struct_or_union_specifier) => TypeSpec.SoUSpec <$> (mkStructOrUnionSpec s)
  | `(type_specifier| $e:enum_specifier) => TypeSpec.EnumSpec <$> (mkEnumSpec e)
  | `(type_specifier| $t:type_name_token) => TypeSpec.TypeName <$> (getIdent t)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for type specifier " ++ x)
          | .none => throw "unexpected syntax for type specifier" 

partial def mkDeclSpec : Lean.Syntax → Except String DeclSpec
--   | `(declaration_specifiers| $[$xs]*) => do
--       let ds <- xs.mapM (fun x => match x with
--                           | `(storage_class_specifier| $s) => Except.ok $ Sum.inl $ mkStorClassSpec s
--                           | `(type_specifier| $t) => Except.ok $ Sum.inr $ Sum.inl $ mkTypeSpec t
--                           | `(type_qualifier| $t) => Except.ok $ Sum.inr $ Sum.inr $ mkTypeQual t)
--       return DeclSpec.DeclSpec ds.toList
  | `(declaration_specifiers| $s:storage_class_specifier) => DeclSpec.StorClassSpec <$> (mkStorClassSpec s)
  | `(declaration_specifiers| $s:storage_class_specifier $d:declaration_specifiers) => DeclSpec.StorClassSpecDeclSpec <$> (mkStorClassSpec s) <*> (mkDeclSpec d)
  | `(declaration_specifiers| $t:type_specifier) => DeclSpec.TypeSpec <$> (mkTypeSpec t)
  | `(declaration_specifiers| $t:type_specifier $d:declaration_specifiers) => DeclSpec.TypeSpecDeclSpec <$> (mkTypeSpec t) <*> (mkDeclSpec d)
  | `(declaration_specifiers| $t:type_qualifier) => DeclSpec.TypeQual <$> (mkTypeQual t)
  | `(declaration_specifiers| $t:type_qualifier $d:declaration_specifiers) => DeclSpec.TypeQualDeclSpec <$> (mkTypeQual t) <*> (mkDeclSpec d)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for declaration specifier " ++ x)
          | .none => throw "unexpected syntax for declaration specifier" 

partial def mkDeclaration : Lean.Syntax → Except String AST.Declaration
  | `(declaration| $ds:declaration_specifiers ;) => Declaration.DeclSpec <$> (mkDeclSpec ds)
  | `(declaration| $ds:declaration_specifiers $idl:init_declarator_list ;) => Declaration.DeclSpecInitDecList <$> (mkDeclSpec ds) <*> (mkInitDeclList idl)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for declaration " ++ x)
          | .none => throw "unexpected syntax for declaration" 

partial def mkInitDeclList : Lean.Syntax → Except String InitDeclList
  | `(init_declarator_list| $[$xs],*) => do
      let ids <- xs.mapM mkInitDecl
      return InitDeclList.InitDeclList ids.toList
--  | `(init_declarator_list| $i:init_declarator) => InitDeclList.InitDecl <$> (mkInitDecl i)
--  | `(init_declarator_list| $idl:init_declarator_list , $id:init_declarator) => InitDeclList.InitDeclListInitDecl <$> (mkInitDeclList idl) <*> (mkInitDecl id)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for init declarator list " ++ x)
          | .none => throw "unexpected syntax for init declarator list" 

partial def mkParamTypeList : Lean.Syntax → Except String ParamTypeList
  | `(parameter_type_list| $pl:parameter_list ) => ParamTypeList.ParamList <$> (mkParamList pl)
  | `(parameter_type_list| $pl:parameter_list , ... ) => ParamTypeList.ParamListEllipsis <$> (mkParamList pl)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for parameter type list " ++ x)
          | .none => throw "unexpected syntax for parameter type list" 

partial def mkParamDecl : Lean.Syntax → Except String ParamDecl
  | `(parameter_declaration| $ds:declaration_specifiers $d:declarator) => ParamDecl.DeclSpecDecl <$> (mkDeclSpec ds) <*> (mkDeclarator d)
  | `(parameter_declaration| $ds:declaration_specifiers $ad:abstract_declarator) => ParamDecl.DeclSpecAbsDecl <$> (mkDeclSpec ds) <*> (mkAbstrDecl ad)
  | `(parameter_declaration| $ds:declaration_specifiers) => ParamDecl.DeclSpec <$> (mkDeclSpec ds)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for parameter declaration " ++ x)
          | .none => throw "unexpected syntax for parameter declaration" 

partial def mkParamList : Lean.Syntax → Except String ParamList
  | `(parameter_list| $[$xs],*) => do
      let params <- xs.mapM mkParamDecl
      return ParamList.ParamList params.toList
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for parameter list " ++ x)
          | .none => throw "unexpected syntax for parameter list" 

partial def mkStructOrUnion : Lean.Syntax → Except String StructOrUnion
  | `(struct_or_union| struct) => return StructOrUnion.Struct
  | `(struct_or_union| union) => return StructOrUnion.Union
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for struct or union " ++ x)
          | .none => throw "unexpected syntax for struct or union" 

partial def mkStructDecl : Lean.Syntax → Except String StructDecl
  | `(struct_declarator| $d:declarator) => StructDecl.Dec <$> (mkDeclarator d)
  | `(struct_declarator| : $ce:constant_expression) => StructDecl.ConstExpr <$> (mkConstExpr ce)
  | `(struct_declarator| $d:declarator : $ce:constant_expression) => StructDecl.DeclConstExpr <$> (mkDeclarator d) <*> (mkConstExpr ce)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for struct declarator " ++ x)
          | .none => throw "unexpected syntax for struct declarator" 

partial def mkStructDeclList : Lean.Syntax → Except String StructDeclList
  | `(struct_declarator_list| $[$xs],*) => do
      let sdls <- xs.mapM mkStructDecl
      return StructDeclList.StructDeclList sdls.toList
--  | `(struct_declarator_list| $sd:struct_declarator) => StructDeclList.StructDecl <$> (mkStructDecl sd)
--  | `(struct_declarator_list| $sdl:struct_declarator_list , $sd:struct_declarator) => StructDeclList.StructDecListStructDec <$> (mkStructDeclList sdl) <*> (mkStructDecl sd)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for struct declarator list " ++ x)
          | .none => throw "unexpected syntax for struct declarator list" 

partial def mkSpecQual : Lean.Syntax → Except String SpecQual
  | `(specifier_qualifier| $t:type_specifier) => SpecQual.TypeSpec <$> (mkTypeSpec t)
  | `(specifier_qualifier| $t:type_qualifier) => SpecQual.TypeQual <$> (mkTypeQual t)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for specifier qualifier " ++ x)
          | .none => throw "unexpected syntax for specifier qualifier"

partial def mkSpecQualList : Lean.Syntax → Except String SpecQualList
--  | `(specifier_qualifier_list| $[$xs]*) => do
--      let sqs <- xs.mapM mkSpecQual
--      return SpecQualList.SpecQualList sqs.toList
  | `(specifier_qualifier_list| $sq:specifier_qualifier) => (λ sq => SpecQualList.SpecQualList [sq]) <$> (mkSpecQual sq)
  | `(specifier_qualifier_list| $sq:specifier_qualifier $sql:specifier_qualifier_list) => (λ sq (SpecQualList.SpecQualList sql) => SpecQualList.SpecQualList $ [sq] ++ sql) <$> (mkSpecQual sq) <*> (mkSpecQualList sql)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for specifier qualifier list " ++ x)
          | .none => throw "unexpected syntax for specifier qualifier list" 

partial def mkStructDeclaration : Lean.Syntax → Except String StructDeclaration
  | `(struct_declaration| $sql:specifier_qualifier_list $sdl:struct_declarator_list ; ) => StructDeclaration.SpecQualListStructDecList <$> (mkSpecQualList sql) <*> (mkStructDeclList sdl)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for struct declaration " ++ x)
          | .none => throw "unexpected syntax for struct declaration" 

partial def mkStructDeclarationList : Lean.Syntax → Except String StructDeclarationList
  | `(struct_declaration_list| $[$xs]*) => do
      let sdls <- xs.mapM mkStructDeclaration
      return StructDeclarationList.StructDeclarationList sdls.toList
--  | `(struct_declaration_list| $sd:struct_declaration) => StructDeclarationList.StructDeclaration <$> (mkStructDeclaration sd)
--  | `(struct_declaration_list| $sdl:struct_declaration_list $sd:struct_declaration) => StructDeclarationList.StructDeclListStructDecl <$> (mkStructDeclarationList sdl) <*> (mkStructDeclaration sd)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for struct declaration list " ++ x)
          | .none => throw "unexpected syntax for struct declaration list" 

partial def mkStructOrUnionSpec : Lean.Syntax → Except String StructOrUnionSpec
  | `(struct_or_union_specifier| $sou:struct_or_union $i:ident { $sdl:struct_declaration_list }) => StructOrUnionSpec.SoUIdentStructDeclarationList <$> (mkStructOrUnion sou) <*> (return i.getId.toString) <*> (mkStructDeclarationList sdl)
  | `(struct_or_union_specifier| $sou:struct_or_union $i:type_name_token { $sdl:struct_declaration_list }) => StructOrUnionSpec.SoUIdentStructDeclarationList <$> (mkStructOrUnion sou) <*> (getIdent i) <*> (mkStructDeclarationList sdl)
  | `(struct_or_union_specifier| $sou:struct_or_union { $sdl:struct_declaration_list }) => StructOrUnionSpec.SoUStructDeclarationList <$> (mkStructOrUnion sou) <*> (mkStructDeclarationList sdl)
  | `(struct_or_union_specifier| $sou:struct_or_union $i:ident) => StructOrUnionSpec.SoUIdent <$> (mkStructOrUnion sou) <*> (return i.getId.toString)
  | `(struct_or_union_specifier| $sou:struct_or_union $i:type_name_token) => StructOrUnionSpec.SoUIdent <$> (mkStructOrUnion sou) <*> (getIdent i)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for struct or union specifier " ++ x)
          | .none => throw "unexpected syntax for struct or union specifier" 

partial def mkStorClassSpec : Lean.Syntax → Except String StorClassSpec
  | `(storage_class_specifier| typedef) => return StorClassSpec.TypeDef
  | `(storage_class_specifier| extern) => return StorClassSpec.Extern
  | `(storage_class_specifier| static) => return StorClassSpec.Static
  | `(storage_class_specifier| auto) => return StorClassSpec.Auto
  | `(storage_class_specifier| register) => return StorClassSpec.Register
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for storage class specifier " ++ x)
          | .none => throw "unexpected syntax for storage class specifier" 

partial def mkEnumerator : Lean.Syntax → Except String Enumerator
  | `(enumerator| $s:ident) => return (Enumerator.Ident s.getId.toString)
  | `(enumerator| $s:type_name_token) => Enumerator.Ident <$> (getIdent s)
  | `(enumerator| $s:ident = $ce:constant_expression) => Enumerator.IdentAssignConst <$> (return s.getId.toString) <*> (mkConstExpr ce)
  | `(enumerator| $s:type_name_token = $ce:constant_expression) => Enumerator.IdentAssignConst <$> (getIdent s) <*> (mkConstExpr ce)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for enumerator " ++ x)
          | .none => throw "unexpected syntax for enumerator" 

partial def mkEnumList : Lean.Syntax → Except String EnumList
  | `(enumerator_list| $[$xs],*) => do
      let es <- xs.mapM mkEnumerator
      return EnumList.EnumList es.toList
--  | `(enumerator_list| $e:enumerator) => EnumList.Enum <$> (mkEnumerator e)
--  | `(enumerator_list| $el:enumerator_list , $e:enumerator) => EnumList.EnumListEnum <$> (mkEnumList el) <*> (mkEnumerator e)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for enumerator list " ++ x)
          | .none => throw "unexpected syntax for enumerator list" 

partial def mkEnumSpec : Lean.Syntax → Except String EnumSpec
  | `(enum_specifier| enum { $e:enumerator_list }) => EnumSpec.EnumList <$> (mkEnumList e)
  | `(enum_specifier| enum $i:ident { $e:enumerator_list }) => EnumSpec.IdentEnumList <$> (return i.getId.toString) <*> (mkEnumList e)
  | `(enum_specifier| enum $i:type_name_token { $e:enumerator_list }) => EnumSpec.IdentEnumList <$> (getIdent i) <*> (mkEnumList e)
  | `(enum_specifier| enum $i:ident) => return EnumSpec.EnumIdent (i.getId.toString)
  | `(enum_specifier| enum $i:type_name_token) => EnumSpec.EnumIdent <$> (getIdent i)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for enum specifier " ++ x)
          | .none => throw "unexpected syntax for enum specifier" 

partial def mkTypeName : Lean.Syntax → Except String TypeName
  | `(type_name| $sql:specifier_qualifier_list) => TypeName.SpecQualList <$> (mkSpecQualList sql)
  | `(type_name| $sql:specifier_qualifier_list $ad:abstract_declarator) => TypeName.SpecQualListAbsDec <$> (mkSpecQualList sql) <*> (mkAbstrDecl ad)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for type name " ++ x)
          | .none => throw "unexpected syntax for type name" 

partial def mkExprStmt : Lean.Syntax → Except String ExprStmt
  | `(expression_statement| ;) => return ExprStmt.Semicolon
  | `(expression_statement| $e:expression ;) => ExprStmt.Expression <$> (mkExpression e)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for expression statement " ++ x)
          | .none => throw "unexpected syntax for expression statement" 

partial def mkSelStmt : Lean.Syntax → Except String SelStmt
  | `(selection_statement| if ( $e:expression ) $s:statement) => SelStmt.If <$> (mkExpression e) <*> (mkStatement s)
  | `(selection_statement| if ( $e:expression ) $s1:statement else $s2:statement) => SelStmt.IfElse <$> (mkExpression e) <*> (mkStatement s1) <*> (mkStatement s2)
  | `(selection_statement| switch ( $e:expression ) $s:statement) => SelStmt.Switch <$> (mkExpression e) <*> (mkStatement s)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for selection statement " ++ x)
          | .none => throw "unexpected syntax for selection statement" 

partial def mkIterStmt : Lean.Syntax → Except String IterStmt
  | `(iteration_statement| while ( $e:expression ) $s:statement) => IterStmt.While <$> (mkExpression e) <*> (mkStatement s)
  | `(iteration_statement| do $s:statement while ( $e:expression ) ;) => IterStmt.DoWhile <$> (mkStatement s) <*> (mkExpression e)
  | `(iteration_statement| for ( $es1:expression_statement $es2:expression_statement ) $s:statement) => IterStmt.For <$> (mkExprStmt es1) <*> (mkExprStmt es2) <*> (mkStatement s)
  | `(iteration_statement| for ( $es1:expression_statement $es2:expression_statement $es3:expression ) $s:statement) => IterStmt.ForExpr <$> (mkExprStmt es1) <*> (mkExprStmt es2) <*> (mkExpression es3) <*> (mkStatement s)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for iteration statement " ++ x)
          | .none => throw "unexpected syntax for iteration statement" 

partial def mkJumpStmt : Lean.Syntax → Except String JumpStmt
  | `(jump_statement| goto $i:ident ;) => JumpStmt.Goto <$> (return i.getId.toString)
  | `(jump_statement| goto $i:type_name_token ;) => JumpStmt.Goto <$> (getIdent i)
  | `(jump_statement| continue ;) => return JumpStmt.Continue
  | `(jump_statement| break ;) => return JumpStmt.Break
  | `(jump_statement| return ;) => return JumpStmt.Return
  | `(jump_statement| return $e:expression ;) => JumpStmt.ReturnExpr <$> (mkExpression e)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for jump statement " ++ x)
          | .none => throw "unexpected syntax for jump statement" 

partial def mkLabelStmt : Lean.Syntax → Except String LabelStmt
  | `(labeled_statement| $i:ident : $s:statement) => LabelStmt.Identifier <$> (return i.getId.toString) <*> (mkStatement s)
  | `(labeled_statement| $i:type_name_token : $s:statement) => LabelStmt.Identifier <$> (getIdent i) <*> (mkStatement s)
  | `(labeled_statement| case $c:constant_expression : $s:statement) => LabelStmt.Case <$> (mkConstExpr c) <*> (mkStatement s)
  | `(labeled_statement| default : $s:statement) => LabelStmt.Default <$> (mkStatement s)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for label statement " ++ x)
          | .none => throw "foo"

partial def mkCompStmt : Lean.Syntax → Except String CompStmt
  | `(compound_statement| { }) => return CompStmt.Brackets
  | `(compound_statement| { $sl:statement_list }) => CompStmt.StmtList <$> (mkStmtList sl)
  | `(compound_statement| { $dl:declaration_list }) => CompStmt.DeclList <$> (mkDeclList dl)
  | `(compound_statement| { $dl:declaration_list $sl:statement_list }) => CompStmt.DeclListStmtList <$> (mkDeclList dl) <*> (mkStmtList sl)
  | s => if s.getKind.toString == "choice"
         then let args := s.getArgs
              let c := args.find? (λ stx => stx.getKind.toString == "«compound_statement{__}»")
              match c with
                | .some stx => mkCompStmt stx
                | .none => match s.reprint with
                            | .some x => throw ("unexpected syntax for compound statement " ++ x ++ "\n" ++ s!"{s}")
                            | .none => throw "unexpected syntax for compound statement" 
         else match s.reprint with
                            | .some x => throw ("unexpected syntax for compound statement " ++ x ++ "\n" ++ s!"{s}")
                            | .none => throw "unexpected syntax for compound statement" 

partial def mkStatement : Lean.Syntax → Except String Statement
  | `(statement| $ls:labeled_statement) => Statement.LabelStmt <$> (mkLabelStmt ls)
  | `(statement| $c:compound_statement) => Statement.CompStmt <$> (mkCompStmt c)
  | `(statement| $e:expression_statement) => Statement.ExprStmt <$> (mkExprStmt e)
  | `(statement| $s:selection_statement) => Statement.SelStmt <$> (mkSelStmt s)
  | `(statement| $i:iteration_statement) => Statement.IterStmt <$> (mkIterStmt i)
  | `(statement| $j:jump_statement) => Statement.JumpStmt <$> (mkJumpStmt j)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for statement " ++ x)
          | .none => throw "unexpected syntax for statement" 

partial def mkStmtList : Lean.Syntax → Except String StmtList
--  | `(statement_list| $[$xs]*) => do
--      let ss <- xs.mapM mkStatement
--      return StmtList.StmtList ss.toList
  | `(statement_list| $s:statement) => (λ s => StmtList.StmtList [s]) <$> mkStatement s
  | `(statement_list| $s:statement $sl:statement_list) =>
     (λ (StmtList.StmtList sl) li  => StmtList.StmtList ([li] ++ sl)) <$> (mkStmtList sl) <*> (mkStatement s)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for statement list " ++ x)
          | .none => throw "unexpected syntax for statement list" 

partial def mkFuncDef : Lean.Syntax → Except String FuncDef
  | `(function_definition| $ds:declaration_specifiers $d:declarator $dl:declaration_list $c:compound_statement)
      => FuncDef.DecSpecDeclDecListCompStmt <$> (mkDeclSpec ds) <*> (mkDeclarator d) <*> (mkDeclList dl) <*> (mkCompStmt c)
  | `(function_definition| $ds:declaration_specifiers $d:declarator $c:compound_statement)
      => FuncDef.DecSpecDeclCompStmt <$> (mkDeclSpec ds) <*> (mkDeclarator d) <*> (mkCompStmt c)
  | `(function_definition| $d:declarator $dl:declaration_list $c:compound_statement)
      => FuncDef.DeclDecListCompStmt <$> (mkDeclarator d) <*> (mkDeclList dl) <*> (mkCompStmt c)
  | `(function_definition| $d:declarator $c:compound_statement)
      => FuncDef.DeclCompStmt <$> (mkDeclarator d) <*> (mkCompStmt c)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for function definition " ++ x)
          | .none => throw "unexpected syntax for function definition" 

partial def mkExternDecl : Lean.Syntax → Except String ExternDecl
  | `(external_declaration| $f:function_definition) => ExternDecl.FuncDef <$> (mkFuncDef f)
  | `(external_declaration| $d:declaration) => ExternDecl.Declaration <$> (mkDeclaration d)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for external declaration " ++ x)
          | .none => throw "unexpected syntax for external declaration" 

partial def mkTranslUnit : Lean.Syntax → Except String TranslUnit
  | `(translation_unit| $[$xs]*) => do
      let es <- xs.mapM mkExternDecl
      return TranslUnit.ExternDeclList es.toList
--  | `(translation_unit| $e:external_declaration) => TranslUnit.ExternDecl <$> (mkExternDecl e)
--  | `(translation_unit| $t:translation_unit $e:external_declaration) => TranslUnit.TranslUnitExternDecl <$> (mkTranslUnit t) <*> (mkExternDecl e)
  | s => match s.reprint with
          | .some x => throw ("unexpected syntax for translation unit " ++ x)
          | .none => throw "unexpected syntax for translation unit" 

end
