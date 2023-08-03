import CParser.AST.AST

open AST
instance : Inhabited PrimaryExpr where default := PrimaryExpr.Constant 0
instance : Inhabited TypeSpec where default := TypeSpec.Void
instance : Inhabited TranslUnit where default := TranslUnit.Semicolon

mutual
partial def primaryExprToString : PrimaryExpr → String
  | .Identifier s => s
  | .Constant c => toString c
  | .FloatConstant c => toString c
  | .CharLit c => "'" ++ toString c ++ "'"
  | .StringLit s => "\"" ++ s ++ "\""

partial def typeSpecToString : TypeSpec → String
  | .Void => "void"
  | .Char => "char"
  -- | .Int => "int"

partial def translUnitToString : TranslUnit → String
  | .Semicolon => ";"

end

instance : ToString PrimaryExpr where toString := primaryExprToString