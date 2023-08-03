import CParser.SyntaxDecl

namespace AST

mutual
inductive PrimaryExpr where
  | Identifier : String → PrimaryExpr
  | Constant : Int → PrimaryExpr
  | FloatConstant : Float → PrimaryExpr
  | CharLit : Char → PrimaryExpr
  | StringLit : String → PrimaryExpr

inductive TypeSpec where
  | Void : TypeSpec
  | Char : TypeSpec
  -- | Int : TypeSpec

inductive ExternDecl where
  | Semicolon : ExternDecl

inductive TranslUnit where
  | ExternDeclList : List ExternDecl → TranslUnit

end

end AST