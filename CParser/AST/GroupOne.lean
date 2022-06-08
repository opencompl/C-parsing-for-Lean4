declare_syntax_cat assignment_operator
declare_syntax_cat primary_expression
declare_syntax_cat postfix_expression
declare_syntax_cat argument_expression_list
declare_syntax_cat unary_expression
declare_syntax_cat unary_operator
declare_syntax_cat expression
declare_syntax_cat conditional_expression
declare_syntax_cat logical_or_expression
declare_syntax_cat logical_and_expression
declare_syntax_cat inclusive_or_expression
declare_syntax_cat exclusive_or_expression
declare_syntax_cat and_expression
declare_syntax_cat equality_expression
declare_syntax_cat relational_expression
declare_syntax_cat shift_expression
declare_syntax_cat additive_expression
declare_syntax_cat multiplicative_expression
declare_syntax_cat cast_expression

-- Expression is incomplete, temporarily made for primary_expression
inductive Expression : Type where
  | Foo: Int → Expression

syntax num : expression

syntax "`[Expression| " expression "]" : term

inductive PrimaryExpr where
  | Identifier : String → PrimaryExpr
  | Constant : Int → PrimaryExpr
  | StringLit : String → PrimaryExpr
  | BracketExpr : Expression → PrimaryExpr

syntax str : primary_expression
syntax ident : primary_expression
syntax num : primary_expression
syntax "(" expression ")" : primary_expression

syntax "`[primary_expression| " primary_expression "]" : term

partial def mkPrimaryExpression : Lean.Syntax → Except String PrimaryExpr
  | `(`[primary_expression| $s:ident]) => return (PrimaryExpr.Identifier s.getId.toString)
  | u => throw "unexpected syntax"

def primary_expr_ident : PrimaryExpr := `[primary_expression| foo]
def primary_expr_num : PrimaryExpr := `[primary_expression| 42]
def primary_expr_expr : PrimaryExpr := `[primary_expression| (42)]
def primary_expr_str : PrimaryExpr := `[primary_expression| "bar"]

def getVal (p : PrimaryExpr) : String :=
  match p with
  | PrimaryExpr.Identifier x => x
  | PrimaryExpr.Constant x => toString x
  | PrimaryExpr.StringLit x => x
  | _ => "lmao"

#check primary_expr_ident
#eval getVal primary_expr_ident

