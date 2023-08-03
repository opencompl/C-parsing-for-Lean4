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
  | `(primary_expression| $n:extended_num) => return PrimaryExpr.Constant (n.raw.getArg 0).toNat
  | `(primary_expression| $s:scientific) => let ⟨a, b, c⟩ := s.getScientific
                                            return PrimaryExpr.FloatConstant $ Float.ofScientific a b c 
  | `(primary_expression| $c:char) => return PrimaryExpr.CharLit c.getChar
  | `(primary_expression| $[$xs]*) => return PrimaryExpr.StringLit $ xs |>.map (λ stx => stx.getString)
                                                                        |>.foldl (λ s1 s2 => s1 ++ s2) ""
  | s => throw ("unexpected syntax for primary expression " ++ s!"{s}")

partial def mkIdentList : Lean.Syntax → Except String IdentList
  | `(identifier_list| $[$xs],*) =>
     let is : Except String (Array String) := xs.mapM getIdent
    IdentList.IdentList <$> (is.map Array.toList)
  | s => throw ("unexpected syntax for identifier list " ++ s!"{s}")

partial def mkTypeQualList : Lean.Syntax → Except String TypeQualList
  | `(type_qualifier_list| $[$xs]*) => do
      let tqs <- xs.mapM mkTypeQual
      return TypeQualList.TypeQualList tqs.toList
  | s => throw ("unexpected syntax for type qualifier list " ++ s!"{s}")

partial def mkTypeQual : Lean.Syntax → Except String TypeQual
  | `(type_qualifier| const) => return (TypeQual.Const)
  | `(type_qualifier| volatile) => return (TypeQual.Volatile)
  | s => throw ("unexpected syntax for type qualifier " ++ s!"{s}")

partial def mkPointer : Lean.Syntax → Except String Pointer
  | `(pointer| *) => return (Pointer.Star)
  | `(pointer| * $t:type_qualifier_list) => Pointer.StarTypeQualList <$> (mkTypeQualList t)
  | `(pointer| * $p:pointer) => Pointer.StarPtr <$> (mkPointer p)
  | `(pointer| * $t:type_qualifier_list $p:pointer) => Pointer.StarTypeQualListPtr <$> (mkTypeQualList t) <*> (mkPointer p)
  | s => throw ("unexpected syntax for pointer " ++ s!"{s}")

partial def mkInitList : Lean.Syntax → Except String InitList
  | `(initializer_list| $[$xs],*) => do
      let inits <- xs.mapM mkInitializer
      return InitList.InitList inits.toList
  | s => throw ("unexpected syntax for initializer list " ++ s!"{s}")

partial def mkInitializer : Lean.Syntax → Except String Initializer
  | `(initializer| { $i:initializer_list }) => Initializer.InitListCurl <$> (mkInitList i)
  | s => throw ("unexpected syntax for initializer " ++ s!"{s}")

partial def mkDeclList : Lean.Syntax → Except String DeclList
  | `(declaration_list| $d:declaration) => (λ d => DeclList.DeclList [d]) <$> (mkDeclaration d)
  | `(declaration_list| $d:declaration $dl:declaration_list) => (λ (DeclList.DeclList dl) d => DeclList.DeclList ([d] ++ dl)) <$> (mkDeclList dl) <*> (mkDeclaration d)
  | s => throw ("unexpected syntax for declaration list " ++ s!"{s}")

partial def mkTypeSpec : Lean.Syntax → Except String TypeSpec
  | `(type_specifier| void) => return TypeSpec.Void
  | `(type_specifier| char) => return TypeSpec.Char
  -- | `(type_specifier| short) => return TypeSpec.Short
  -- | `(type_specifier| int) => return TypeSpec.Int
  -- | `(type_specifier| long) => return TypeSpec.Long
  -- | `(type_specifier| float) => return TypeSpec.Float
  -- | `(type_specifier| double) => return TypeSpec.Double
  -- | `(type_specifier| signed) => return TypeSpec.Signed
  -- | `(type_specifier| unsigned) => return TypeSpec.Unsigned
  -- | `(type_specifier| $e:enum_specifier) => TypeSpec.EnumSpec <$> (mkEnumSpec e)
  | s => throw ("unexpected syntax for type specifier " ++ s!"{s}")

partial def mkDeclSpec : Lean.Syntax → Except String DeclSpec
  | `(declaration_specifiers| $s:storage_class_specifier) => DeclSpec.StorClassSpec <$> (mkStorClassSpec s)
  | `(declaration_specifiers| $s:storage_class_specifier $d:declaration_specifiers) => DeclSpec.StorClassSpecDeclSpec <$> (mkStorClassSpec s) <*> (mkDeclSpec d)
  | `(declaration_specifiers| $t:type_specifier) => DeclSpec.TypeSpec <$> (mkTypeSpec t)
  | `(declaration_specifiers| $t:type_specifier $d:declaration_specifiers) => DeclSpec.TypeSpecDeclSpec <$> (mkTypeSpec t) <*> (mkDeclSpec d)
  | `(declaration_specifiers| $t:type_qualifier) => DeclSpec.TypeQual <$> (mkTypeQual t)
  | `(declaration_specifiers| $t:type_qualifier $d:declaration_specifiers) => DeclSpec.TypeQualDeclSpec <$> (mkTypeQual t) <*> (mkDeclSpec d)
  | s => throw ("unexpected syntax for declaration specifier " ++ s!"{s}")

partial def mkDeclaration : Lean.Syntax → Except String AST.Declaration
  | `(declaration| $p:primary_expression) => Declaration.Primary <$> (mkPrimaryExpression p)
  | s => throw ("unexpected syntax for declaration " ++ s!"{s}")

partial def mkParamTypeList : Lean.Syntax → Except String ParamTypeList
  | `(parameter_type_list| $pl:parameter_list ) => ParamTypeList.ParamList <$> (mkParamList pl)
  | `(parameter_type_list| $pl:parameter_list , ... ) => ParamTypeList.ParamListEllipsis <$> (mkParamList pl)
  | s => throw ("unexpected syntax for parameter type list " ++ s!"{s}")

partial def mkParamDecl : Lean.Syntax → Except String ParamDecl
  | `(parameter_declaration| $p:primary_expression) => ParamDecl.Primary <$> (mkPrimaryExpression p)
  | s => throw ("unexpected syntax for parameter declaration " ++ s!"{s}")

partial def mkParamList : Lean.Syntax → Except String ParamList
  | `(parameter_list| $[$xs],*) => do
      let params <- xs.mapM mkParamDecl
      return ParamList.ParamList params.toList
  | s => throw ("unexpected syntax for parameter list " ++ s!"{s}")

partial def mkSpecQual : Lean.Syntax → Except String SpecQual
  | `(specifier_qualifier| $t:type_specifier) => SpecQual.TypeSpec <$> (mkTypeSpec t)
  | `(specifier_qualifier| $t:type_qualifier) => SpecQual.TypeQual <$> (mkTypeQual t)
  | s => throw ("unexpected syntax for specifier qualifier " ++ s!"{s}")

partial def mkSpecQualList : Lean.Syntax → Except String SpecQualList
  | `(specifier_qualifier_list| $sq:specifier_qualifier) => (λ sq => SpecQualList.SpecQualList [sq]) <$> (mkSpecQual sq)
  | `(specifier_qualifier_list| $sq:specifier_qualifier $sql:specifier_qualifier_list) => (λ sq (SpecQualList.SpecQualList sql) => SpecQualList.SpecQualList $ [sq] ++ sql) <$> (mkSpecQual sq) <*> (mkSpecQualList sql)
  | s => throw ("unexpected syntax for specifier qualifier list " ++ s!"{s}")

partial def mkStorClassSpec : Lean.Syntax → Except String StorClassSpec
  | `(storage_class_specifier| typedef) => return StorClassSpec.TypeDef
  | `(storage_class_specifier| extern) => return StorClassSpec.Extern
  | `(storage_class_specifier| static) => return StorClassSpec.Static
  | `(storage_class_specifier| auto) => return StorClassSpec.Auto
  | `(storage_class_specifier| register) => return StorClassSpec.Register
  | `(storage_class_specifier| inline) => return StorClassSpec.Inline
  | s => throw ("unexpected syntax for storage class specifier " ++ s!"{s}")

partial def mkEnumSpec : Lean.Syntax → Except String EnumSpec
  | `(enum_specifier| $p:primary_expression) => EnumSpec.Primary <$> (mkPrimaryExpression p)
  | s => throw ("unexpected syntax for enum specifier " ++ s!"{s}")

partial def mkCompStmt : Lean.Syntax → Except String CompStmt
  | `(compound_statement| { }) => return CompStmt.Brackets
  | `(compound_statement| { $sl:statement_list }) => CompStmt.StmtList <$> (mkStmtList sl)
  | `(compound_statement| { $dl:declaration_list }) => CompStmt.DeclList <$> (mkDeclList dl)
  | `(compound_statement| { $dl:declaration_list $sl:statement_list }) => CompStmt.DeclListStmtList <$> (mkDeclList dl) <*> (mkStmtList sl)
  | s => -- if s.getKind.toString == "choice"
         -- then let args := s.getArgs
         --      let c := args.find? (λ stx => stx.getKind.toString == "«compound_statement{__}»")
         --      match c with
         --        | .some stx => mkCompStmt stx
         --        | .none => throw ("unexpected syntax for compound statement " ++ s!"{s}")
         -- else throw ("unexpected syntax for compound statement " ++ s!"{s}")
         throw ("unexpected syntax for unary expression " ++ s!"{s}")

partial def mkStatement : Lean.Syntax → Except String Statement
  | `(statement| $c:compound_statement) => Statement.CompStmt <$> (mkCompStmt c)
  | s => throw ("unexpected syntax for statement " ++ s!"{s}")

partial def mkStmtList : Lean.Syntax → Except String StmtList
  | `(statement_list| $s:statement) => (λ s => StmtList.StmtList [s]) <$> mkStatement s
  | `(statement_list| $s:statement $sl:statement_list) =>
     (λ (StmtList.StmtList sl) li  => StmtList.StmtList ([li] ++ sl)) <$> (mkStmtList sl) <*> (mkStatement s)
  | s => throw ("unexpected syntax for statement list " ++ s!"{s}")

partial def mkExternDecl : Lean.Syntax → Except String ExternDecl
  | `(external_declaration| $d:declaration) => ExternDecl.Declaration <$> (mkDeclaration d)
  | `(external_declaration| ;) => return ExternDecl.Semicolon
  | s => throw ("unexpected syntax for external declaration " ++ s!"{s}")

partial def mkTranslUnit : Lean.Syntax → Except String TranslUnit
  | `(translation_unit| $[$xs]*) => do
      let es <- xs.mapM mkExternDecl
      return TranslUnit.ExternDeclList es.toList
  | s => throw ("unexpected syntax for translation unit " ++ s!"{s}")

end
