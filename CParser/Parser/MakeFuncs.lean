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
partial def mkPrimaryExpression : Lean.Syntax → Except String PrimaryExpr := fun x => dbg_trace x
  match x with
  | `(primary_expression| $s:ident) => return (PrimaryExpr.Identifier s.getId.toString)
  | `(primary_expression| $s:scientific) => let ⟨a, b, c⟩ := s.getScientific
                                            return PrimaryExpr.FloatConstant $ Float.ofScientific a b c 
  | `(primary_expression| $c:char) => return PrimaryExpr.CharLit c.getChar
  | `(primary_expression| $[$xs]*) => return PrimaryExpr.StringLit $ xs |>.map (λ stx => stx.getString)
                                                                        |>.foldl (λ s1 s2 => s1 ++ s2) ""
  | s => throw ("unexpected syntax for primary expression " ++ s!"{s}")

partial def mkTypeSpec : Lean.Syntax → Except String TypeSpec
  | `(type_specifier| void) => return TypeSpec.Void
  | `(type_specifier| char) => return TypeSpec.Char
  -- | `(type_specifier| int) => return TypeSpec.Int
  | s => throw ("unexpected syntax for type specifier " ++ s!"{s}")

end
