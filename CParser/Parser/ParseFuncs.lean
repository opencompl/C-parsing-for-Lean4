import CParser.AST
import CParser.AST.ClassDec
import CParser.Syntax
import CParser.Util
import CParser.Parser.MakeFuncs
open AST


-- Parse a primary expression into 
def parsePrimaryExpression : String → Lean.Environment → Except ParseError PrimaryExpr := 
  mkNonTerminalParser `primary_expression mkPrimaryExpression

def parsePostfixExpression : String → Lean.Environment → Except ParseError PostfixExpr :=
  mkNonTerminalParser `postfix_expression mkPostfixExpression

def parseUnaryOperator : String → Lean.Environment → Except ParseError UnaryOp :=
  mkNonTerminalParser `unary_operator mkUnaryOperator

def parseUnaryExpression : String → Lean.Environment → Except ParseError UnaryExpr :=
  mkNonTerminalParser `unary_expression mkUnaryExpression

def parseCastExpression : String → Lean.Environment → Except ParseError CastExpr :=
  mkNonTerminalParser `cast_expression mkCastExpression

def parseMultExpression : String → Lean.Environment → Except ParseError MultExpr :=
  mkNonTerminalParser `multiplicative_expression mkMultExpression

def parseAddExpression : String → Lean.Environment → Except ParseError AddExpr :=
  mkNonTerminalParser `additive_expression mkAddExpression

def parseShiftExpression : String → Lean.Environment → Except ParseError ShiftExpr :=
  mkNonTerminalParser `shift_expression mkShiftExpression

def parseRelExpression : String → Lean.Environment → Except ParseError RelExpr :=
  mkNonTerminalParser `relational_expression mkRelExpression

def parseEqExpression : String → Lean.Environment → Except ParseError EqExpr :=
  mkNonTerminalParser `equality_expression mkEqExpression

def parseAndExpression : String → Lean.Environment → Except ParseError AndExpr :=
  mkNonTerminalParser `and_expression mkAndExpression

def parseXOrExpression : String → Lean.Environment → Except ParseError XOrExpr :=
  mkNonTerminalParser `exclusive_or_expression mkXOrExpression

def parseIOrExpression : String → Lean.Environment → Except ParseError IOrExpr :=
  mkNonTerminalParser `inclusive_or_expression mkIOrExpression

def parseLAndExpression : String → Lean.Environment → Except ParseError LAndExpr :=
  mkNonTerminalParser `logical_and_expression mkLAndExpression

def parseLOrExpression : String → Lean.Environment → Except ParseError LOrExpr :=
  mkNonTerminalParser `logical_or_expression mkLOrExpression

def parseCondExpression : String → Lean.Environment → Except ParseError CondExpr :=
  mkNonTerminalParser `conditional_expression mkCondExpression

def parseAssmtOperator : String → Lean.Environment → Except ParseError AssmtOp :=
  mkNonTerminalParser `assignment_operator mkAssmtOperator

def parseAssmtExpression : String → Lean.Environment → Except ParseError AssmtExpr :=
  mkNonTerminalParser `assignment_expression mkAssmtExpression

def parseArgExprList : String → Lean.Environment → Except ParseError ArgExprList :=
  mkNonTerminalParser `argument_expression_list mkArgExprList

def parseExpression : String → Lean.Environment → Except ParseError Expression :=
  mkNonTerminalParser `expression mkExpression

def parseConstantExpression : String → Lean.Environment → Except ParseError ConstantExpr := 
  mkNonTerminalParser `constant_expression mkConstExpr

def parseDirAbstrDecl : String → Lean.Environment → Except ParseError DirAbstrDecl := 
  mkNonTerminalParser `direct_abstract_declarator mkDirAbstrDecl

def parseAbstrDecl : String → Lean.Environment → Except ParseError AbstrDecl := 
  mkNonTerminalParser `abstract_declarator mkAbstrDecl

def parseIdentList : String → Lean.Environment → Except ParseError IdentList := 
  mkNonTerminalParser `identifier_list mkIdentList

def parseDirDecl : String → Lean.Environment → Except ParseError DirDecl := 
  mkNonTerminalParser `direct_declarator mkDirDecl

def parseTypeQualList : String → Lean.Environment → Except ParseError TypeQualList := 
  mkNonTerminalParser `type_qualifier_list mkTypeQualList

def parseTypeQual : String → Lean.Environment → Except ParseError TypeQual := 
  mkNonTerminalParser `type_qualifier mkTypeQual

def parsePointer : String → Lean.Environment → Except ParseError Pointer :=
  mkNonTerminalParser `pointer mkPointer

def parseDeclarator : String → Lean.Environment → Except ParseError Declarator := 
  mkNonTerminalParser `declarator mkDeclarator

def parseInitList : String → Lean.Environment → Except ParseError InitList :=
  mkNonTerminalParser `initializer_list mkInitList

def parseInitializer : String → Lean.Environment → Except ParseError Initializer := 
  mkNonTerminalParser `initializer mkInitializer

def parseInitDecl : String → Lean.Environment → Except ParseError InitDecl := 
  mkNonTerminalParser `init_declarator mkInitDecl

def parseDeclaration : String → Lean.Environment → Except ParseError Declaration := 
  mkNonTerminalParser `declaration mkDeclaration

def parseDeclList : String → Lean.Environment → Except ParseError DeclList := 
  mkNonTerminalParser `declaration_list mkDeclList

def parseDeclSpec : String → Lean.Environment → Except ParseError DeclSpec := 
  mkNonTerminalParser `declaration_specifiers mkDeclSpec

def parseEnumerator : String → Lean.Environment → Except ParseError Enumerator := 
  mkNonTerminalParser `enumerator mkEnumerator

def parseEnumList : String → Lean.Environment → Except ParseError EnumList := 
  mkNonTerminalParser `enumerator_list mkEnumList

def parseEnumSpec : String → Lean.Environment → Except ParseError EnumSpec := 
  mkNonTerminalParser `enum_specifier mkEnumSpec

def parseInitDeclList : String → Lean.Environment → Except ParseError InitDeclList := 
  mkNonTerminalParser `init_declarator_list mkInitDeclList

def parseParamDecl : String → Lean.Environment → Except ParseError ParamDecl := 
  mkNonTerminalParser `parameter_declaration mkParamDecl

def parseParamList : String → Lean.Environment → Except ParseError ParamList := 
  mkNonTerminalParser `parameter_list mkParamList

def parseParamTypeList : String → Lean.Environment → Except ParseError ParamTypeList := 
  mkNonTerminalParser `parameter_type_list mkParamTypeList

def parseSpecQualList : String → Lean.Environment → Except ParseError SpecQualList := 
  mkNonTerminalParser `specifier_qualifier_list mkSpecQualList

def parseStorClassSpec : String → Lean.Environment → Except ParseError StorClassSpec := 
  mkNonTerminalParser `storage_class_specifier mkStorClassSpec

def parseStructDecl : String → Lean.Environment → Except ParseError StructDecl := 
  mkNonTerminalParser `struct_declarator mkStructDecl

def parseStructDeclaration : String → Lean.Environment → Except ParseError StructDeclaration := 
  mkNonTerminalParser `struct_declaration mkStructDeclaration

def parseStructDeclarationList : String → Lean.Environment → Except ParseError StructDeclarationList := 
  mkNonTerminalParser `struct_declaration_list mkStructDeclarationList

def parseStructDeclList : String → Lean.Environment → Except ParseError StructDeclList := 
  mkNonTerminalParser `struct_declarator_list mkStructDeclList

def parseStructOrUnion : String → Lean.Environment → Except ParseError StructOrUnion := 
  mkNonTerminalParser `struct_or_union mkStructOrUnion

def parseStructOrUnionSpec : String → Lean.Environment → Except ParseError StructOrUnionSpec := 
  mkNonTerminalParser `struct_or_union_specifier mkStructOrUnionSpec

def parseTypeName : String → Lean.Environment → Except ParseError TypeName := 
  mkNonTerminalParser `type_name mkTypeName

def parseTypeSpec : String → Lean.Environment → Except ParseError TypeSpec := 
  mkNonTerminalParser `type_specifier mkTypeSpec

def parseExprStmt : String → Lean.Environment → Except ParseError ExprStmt := 
  mkNonTerminalParser `expression_statement mkExprStmt

def parseSelStmt : String → Lean.Environment → Except ParseError SelStmt := 
  mkNonTerminalParser `selection_statement mkSelStmt

def parseIterStmt : String → Lean.Environment → Except ParseError IterStmt := 
  mkNonTerminalParser `iteration_statement mkIterStmt

def parseJumpStmt : String → Lean.Environment → Except ParseError JumpStmt := 
  mkNonTerminalParser `jump_statement mkJumpStmt

def parseLabelStmt : String → Lean.Environment → Except ParseError LabelStmt := 
  mkNonTerminalParser `labeled_statement mkLabelStmt

def parseCompStmt : String → Lean.Environment → Except ParseError CompStmt := 
  mkNonTerminalParser `compound_statement mkCompStmt

def parseStatement : String → Lean.Environment → Except ParseError Statement := 
  mkNonTerminalParser `statement mkStatement

def parseStmtList : String → Lean.Environment → Except ParseError StmtList := 
  mkNonTerminalParser `statement_list mkStmtList

def parseFuncDef : String → Lean.Environment → Except ParseError FuncDef := 
  mkNonTerminalParser `function_definition mkFuncDef

def parseExternDecl : String → Lean.Environment → Except ParseError ExternDecl := 
  mkNonTerminalParser `external_declaration mkExternDecl

def parseTranslUnit : String → Lean.Environment → Except ParseError TranslUnit := 
  mkNonTerminalParser `translation_unit mkTranslUnit

-- Parse the top-level nonterminal of our grammar.
def parseToplevelNonterminal := parseTranslUnit

-- C parser, which invokes the top level nonterminal parser.
def parse := parseToplevelNonterminal
