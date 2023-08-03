import CParser.AST.AST

open AST
instance : Inhabited PrimaryExpr where default := PrimaryExpr.StringLit "defaultPE" 
instance : Inhabited TranslUnit where default := TranslUnit.PrimaryExpr (default : PrimaryExpr)

mutual
partial def primaryExprToString : PrimaryExpr → String
  | .Identifier s => s
  | .CharLit c => "'" ++ toString c ++ "'"
  | .StringLit s => "\"" ++ s ++ "\""

partial def translUnitToString : TranslUnit → String
  | .PrimaryExpr p => primaryExprToString p

end

instance : ToString PrimaryExpr where toString := primaryExprToString
instance : ToString TranslUnit where toString := translUnitToString
