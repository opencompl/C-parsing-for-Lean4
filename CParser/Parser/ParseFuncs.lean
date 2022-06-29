import CParser.AST
import CParser.AST.ClassDec
import CParser.Syntax
import CParser.Util
import CParser.Parser.MakeFuncs
open AST


-- Parse a primary expression into 
def parsePrimaryExpression : String → Lean.Environment → Option String × PrimaryExpr := 
  mkNonTerminalParser `primary_expression mkPrimaryExpression

def parsePostfixExpression : String → Lean.Environment → Option String × PostfixExpr :=
  mkNonTerminalParser `postfix_expression mkPostfixExpression

def parseUnaryOperator : String → Lean.Environment → Option String × UnaryOp :=
  mkNonTerminalParser `unary_operator mkUnaryOperator

def parseUnaryExpression : String → Lean.Environment → Option String × UnaryExpr :=
  mkNonTerminalParser `unary_expression mkUnaryExpression

def parseCastExpression : String → Lean.Environment → Option String × CastExpr :=
  mkNonTerminalParser `cast_expression mkCastExpression

def parseMultExpression : String → Lean.Environment → Option String × MultExpr :=
  mkNonTerminalParser `multiplicative_expression mkMultExpression

def parseAddExpression : String → Lean.Environment → Option String × AddExpr :=
  mkNonTerminalParser `additive_expression mkAddExpression

def parseShiftExpression : String → Lean.Environment → Option String × ShiftExpr :=
  mkNonTerminalParser `shift_expression mkShiftExpression

def parseRelExpression : String → Lean.Environment → Option String × RelExpr :=
  mkNonTerminalParser `relational_expression mkRelExpression

def parseEqExpression : String → Lean.Environment → Option String × EqExpr :=
  mkNonTerminalParser `equality_expression mkEqExpression

def parseAndExpression : String → Lean.Environment → Option String × AndExpr :=
  mkNonTerminalParser `and_expression mkAndExpression

def parseXOrExpression : String → Lean.Environment → Option String × XOrExpr :=
  mkNonTerminalParser `exclusive_or_expression mkXOrExpression

def parseIOrExpression : String → Lean.Environment → Option String × IOrExpr :=
  mkNonTerminalParser `inclusive_or_expression mkIOrExpression

def parseLAndExpression : String → Lean.Environment → Option String × LAndExpr :=
  mkNonTerminalParser `logical_and_expression mkLAndExpression

def parseLOrExpression : String → Lean.Environment → Option String × LOrExpr :=
  mkNonTerminalParser `logical_or_expression mkLOrExpression

def parseCondExpression : String → Lean.Environment → Option String × CondExpr :=
  mkNonTerminalParser `conditional_expression mkCondExpression

def parseAssmtOperator : String → Lean.Environment → Option String × AssmtOp :=
  mkNonTerminalParser `assignment_operator mkAssmtOperator

def parseAssmtExpression : String → Lean.Environment → Option String × AssmtExpr :=
  mkNonTerminalParser `assignment_expression mkAssmtExpression

def parseArgExprList : String → Lean.Environment → Option String × ArgExprList :=
  mkNonTerminalParser `argument_expression_list mkArgExprList

def parseExpression : String → Lean.Environment → Option String × Expression :=
  mkNonTerminalParser `expression mkExpression

def parseConstantExpression : String → Lean.Environment → Option String × ConstantExpr := 
  mkNonTerminalParser `constant_expression mkConstExpr

def parseDirAbstrDecl : String → Lean.Environment → Option String × DirAbstrDecl := 
  mkNonTerminalParser `direct_abstract_declarator mkDirAbstrDecl

def parseAbstrDecl : String → Lean.Environment → Option String × AbstrDecl := 
  mkNonTerminalParser `abstract_declarator mkAbstrDecl

def parseIdentList : String → Lean.Environment → Option String × IdentList := 
  mkNonTerminalParser `identifier_list mkIdentList

def parseDirDecl : String → Lean.Environment → Option String × DirDecl := 
  mkNonTerminalParser `direct_declarator mkDirDecl

def parseTypeQualList : String → Lean.Environment → Option String × TypeQualList := 
  mkNonTerminalParser `type_qualifier_list mkTypeQualList

def parseTypeQual : String → Lean.Environment → Option String × TypeQual := 
  mkNonTerminalParser `type_qualifier mkTypeQual

def parsePointer : String → Lean.Environment → Option String × Pointer :=
  mkNonTerminalParser `pointer mkPointer

def parseDeclarator : String → Lean.Environment → Option String × Declarator := 
  mkNonTerminalParser `declarator mkDeclarator

def parseInitList : String → Lean.Environment → Option String × InitList :=
  mkNonTerminalParser `initializer_list mkInitList

def parseInitializer : String → Lean.Environment → Option String × Initializer := 
  mkNonTerminalParser `initializer mkInitializer

def parseInitDecl : String → Lean.Environment → Option String × InitDecl := 
  mkNonTerminalParser `init_declarator mkInitDecl

-- Parse the top-level nonterminal of our grammar.
def parseToplevelNonterminal := parseInitDecl

-- C parser, which invokes the top level nonterminal parser.
def parse := parseToplevelNonterminal