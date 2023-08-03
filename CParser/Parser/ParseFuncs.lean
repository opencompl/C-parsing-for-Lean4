import CParser.AST
import CParser.AST.ClassDec
import CParser.Syntax
import CParser.Util
import CParser.Parser.MakeFuncs

open AST
open Lean
open Lean.Parser
open Lean.Elab.Command


-- Parse a primary expression into 
def parsePrimaryExpression : String → Lean.Environment → CommandElabM PrimaryExpr := 
  mkNonTerminalParser `primary_expression mkPrimaryExpression

-- def parsePostfixExpression : String → Lean.Environment → CommandElabM PostfixExpr :=
--   mkNonTerminalParser `postfix_expression mkPostfixExpression

-- def parseUnaryExpression : String → Lean.Environment → CommandElabM UnaryExpr :=
--   mkNonTerminalParser `unary_expression mkUnaryExpression

-- def parseCastExpression : String → Lean.Environment → CommandElabM CastExpr :=
--   mkNonTerminalParser `cast_expression mkCastExpression

-- def parseMultExpression : String → Lean.Environment → CommandElabM MultExpr :=
--   mkNonTerminalParser `multiplicative_expression mkMultExpression

-- def parseAddExpression : String → Lean.Environment → CommandElabM AddExpr :=
--   mkNonTerminalParser `additive_expression mkAddExpression

-- def parseShiftExpression : String → Lean.Environment → CommandElabM ShiftExpr :=
--   mkNonTerminalParser `shift_expression mkShiftExpression

-- def parseRelExpression : String → Lean.Environment → CommandElabM RelExpr :=
--   mkNonTerminalParser `relational_expression mkRelExpression

-- def parseEqExpression : String → Lean.Environment → CommandElabM EqExpr :=
--   mkNonTerminalParser `equality_expression mkEqExpression

-- def parseAndExpression : String → Lean.Environment → CommandElabM AndExpr :=
--   mkNonTerminalParser `and_expression mkAndExpression

-- def parseXOrExpression : String → Lean.Environment → CommandElabM XOrExpr :=
--   mkNonTerminalParser `exclusive_or_expression mkXOrExpression

-- def parseIOrExpression : String → Lean.Environment → CommandElabM IOrExpr :=
--   mkNonTerminalParser `inclusive_or_expression mkIOrExpression

-- def parseLAndExpression : String → Lean.Environment → CommandElabM LAndExpr :=
--   mkNonTerminalParser `logical_and_expression mkLAndExpression

-- def parseLOrExpression : String → Lean.Environment → CommandElabM LOrExpr :=
--   mkNonTerminalParser `logical_or_expression mkLOrExpression

-- def parseCondExpression : String → Lean.Environment → CommandElabM CondExpr :=
--   mkNonTerminalParser `conditional_expression mkCondExpression

-- def parseAssmtOperator : String → Lean.Environment → CommandElabM AssmtOp :=
--   mkNonTerminalParser `assignment_operator mkAssmtOperator

-- def parseAssmtExpression : String → Lean.Environment → CommandElabM AssmtExpr :=
--   mkNonTerminalParser `assignment_expression mkAssmtExpression

-- def parseArgExprList : String → Lean.Environment → CommandElabM ArgExprList :=
--   mkNonTerminalParser `argument_expression_list mkArgExprList

-- def parseExpression : String → Lean.Environment → CommandElabM Expression :=
--   mkNonTerminalParser `expression mkExpression

-- def parseConstantExpression : String → Lean.Environment → CommandElabM ConstantExpr := 
--   mkNonTerminalParser `constant_expression mkConstExpr

-- def parseDirAbstrDecl : String → Lean.Environment → CommandElabM DirAbstrDecl := 
--   mkNonTerminalParser `direct_abstract_declarator mkDirAbstrDecl

-- def parseAbstrDecl : String → Lean.Environment → CommandElabM AbstrDecl := 
--   mkNonTerminalParser `abstract_declarator mkAbstrDecl

def parseIdentList : String → Lean.Environment → CommandElabM IdentList := 
  mkNonTerminalParser `identifier_list mkIdentList

-- def parseDirDecl : String → Lean.Environment → CommandElabM DirDecl := 
--   mkNonTerminalParser `direct_declarator mkDirDecl

def parseTypeQualList : String → Lean.Environment → CommandElabM TypeQualList := 
  mkNonTerminalParser `type_qualifier_list mkTypeQualList

def parseTypeQual : String → Lean.Environment → CommandElabM TypeQual := 
  mkNonTerminalParser `type_qualifier mkTypeQual

def parsePointer : String → Lean.Environment → CommandElabM Pointer :=
  mkNonTerminalParser `pointer mkPointer

-- def parseDeclarator : String → Lean.Environment → CommandElabM Declarator := 
--   mkNonTerminalParser `declarator mkDeclarator

def parseInitList : String → Lean.Environment → CommandElabM InitList :=
  mkNonTerminalParser `initializer_list mkInitList

def parseInitializer : String → Lean.Environment → CommandElabM Initializer := 
  mkNonTerminalParser `initializer mkInitializer

-- def parseInitDecl : String → Lean.Environment → CommandElabM InitDecl := 
--   mkNonTerminalParser `init_declarator mkInitDecl

def parseDeclaration : String → Lean.Environment → CommandElabM AST.Declaration := 
  mkNonTerminalParser `declaration mkDeclaration

def parseDeclList : String → Lean.Environment → CommandElabM DeclList := 
  mkNonTerminalParser `declaration_list mkDeclList

def parseDeclSpec : String → Lean.Environment → CommandElabM DeclSpec := 
  mkNonTerminalParser `declaration_specifiers mkDeclSpec

-- def parseEnumerator : String → Lean.Environment → CommandElabM Enumerator := 
--   mkNonTerminalParser `enumerator mkEnumerator

-- def parseEnumList : String → Lean.Environment → CommandElabM EnumList := 
--   mkNonTerminalParser `enumerator_list mkEnumList

def parseEnumSpec : String → Lean.Environment → CommandElabM EnumSpec := 
  mkNonTerminalParser `enum_specifier mkEnumSpec

-- def parseInitDeclList : String → Lean.Environment → CommandElabM InitDeclList := 
--   mkNonTerminalParser `init_declarator_list mkInitDeclList

def parseParamDecl : String → Lean.Environment → CommandElabM ParamDecl := 
  mkNonTerminalParser `parameter_declaration mkParamDecl

def parseParamList : String → Lean.Environment → CommandElabM ParamList := 
  mkNonTerminalParser `parameter_list mkParamList

def parseParamTypeList : String → Lean.Environment → CommandElabM ParamTypeList := 
  mkNonTerminalParser `parameter_type_list mkParamTypeList

def parseSpecQualList : String → Lean.Environment → CommandElabM SpecQualList := 
  mkNonTerminalParser `specifier_qualifier_list mkSpecQualList

def parseStorClassSpec : String → Lean.Environment → CommandElabM StorClassSpec := 
  mkNonTerminalParser `storage_class_specifier mkStorClassSpec

-- def parseStructDecl : String → Lean.Environment → CommandElabM StructDecl := 
--   mkNonTerminalParser `struct_declarator mkStructDecl

-- def parseStructDeclaration : String → Lean.Environment → CommandElabM StructDeclaration := 
--   mkNonTerminalParser `struct_declaration mkStructDeclaration

-- def parseStructDeclarationList : String → Lean.Environment → CommandElabM StructDeclarationList := 
--   mkNonTerminalParser `struct_declaration_list mkStructDeclarationList

-- def parseStructDeclList : String → Lean.Environment → CommandElabM StructDeclList := 
--   mkNonTerminalParser `struct_declarator_list mkStructDeclList

-- def parseStructOrUnion : String → Lean.Environment → CommandElabM StructOrUnion := 
--   mkNonTerminalParser `struct_or_union mkStructOrUnion

-- def parseStructOrUnionSpec : String → Lean.Environment → CommandElabM StructOrUnionSpec := 
--   mkNonTerminalParser `struct_or_union_specifier mkStructOrUnionSpec

-- def parseTypeName : String → Lean.Environment → CommandElabM TypeName := 
--   mkNonTerminalParser `type_name mkTypeName

def parseTypeSpec : String → Lean.Environment → CommandElabM TypeSpec := 
  mkNonTerminalParser `type_specifier mkTypeSpec

-- def parseExprStmt : String → Lean.Environment → CommandElabM ExprStmt := 
--   mkNonTerminalParser `expression_statement mkExprStmt

-- def parseSelStmt : String → Lean.Environment → CommandElabM SelStmt := 
--   mkNonTerminalParser `selection_statement mkSelStmt

-- def parseIterStmt : String → Lean.Environment → CommandElabM IterStmt := 
--   mkNonTerminalParser `iteration_statement mkIterStmt

-- def parseJumpStmt : String → Lean.Environment → CommandElabM JumpStmt := 
--   mkNonTerminalParser `jump_statement mkJumpStmt

-- def parseLabelStmt : String → Lean.Environment → CommandElabM LabelStmt := 
--   mkNonTerminalParser `labeled_statement mkLabelStmt

def parseCompStmt : String → Lean.Environment → CommandElabM CompStmt := 
  mkNonTerminalParser `compound_statement mkCompStmt

def parseStatement : String → Lean.Environment → CommandElabM Statement := 
  mkNonTerminalParser `statement mkStatement

def parseStmtList : String → Lean.Environment → CommandElabM StmtList := 
  mkNonTerminalParser `statement_list mkStmtList

-- def parseFuncDef : String → Lean.Environment → CommandElabM FuncDef := 
--   mkNonTerminalParser `function_definition mkFuncDef

def parseExternDecl : String → Lean.Environment → CommandElabM ExternDecl :=
  mkNonTerminalParser `external_declaration mkExternDecl

def parseTranslUnit : String → Lean.Environment → CommandElabM TranslUnit :=
  mkNonTerminalParser `translation_unit mkTranslUnit

-- Parse the top-level nonterminal of our grammar.
def parseToplevelNonterminal := parseTranslUnit

-- C parser, which invokes the top level nonterminal parser.
def parse := parseToplevelNonterminal
