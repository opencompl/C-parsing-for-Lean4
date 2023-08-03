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
  | `(primary_expression| $c:char) => return PrimaryExpr.CharLit c.getChar
  | `(primary_expression| $[$xs]*) => return PrimaryExpr.StringLit $ xs |>.map (λ stx => stx.getString)
                                                                        |>.foldl (λ s1 s2 => s1 ++ s2) ""
  | s => throw ("unexpected syntax for primary expression " ++ s!"{s}")

partial def mkTranslUnit : Lean.Syntax → Except String TranslUnit
  | `(translation_unit| $p:primary_expression) => TranslUnit.PrimaryExpr <$> (mkPrimaryExpression p)
  | s => throw ("unexpected syntax for translation unit " ++ s!"{s}")

end
