import CParser.SyntaxDecl

namespace AST

mutual
inductive PrimaryExpr where
  | Identifier : String → PrimaryExpr
  | CharLit : Char → PrimaryExpr
  | StringLit : String → PrimaryExpr

inductive TranslUnit where
  | PrimaryExpr : PrimaryExpr → TranslUnit

end

end AST