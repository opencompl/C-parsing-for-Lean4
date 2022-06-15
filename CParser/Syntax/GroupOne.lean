import CParser.SyntaxDecl
import CParser.AST
open AST


syntax str : primary_expression
syntax ident : primary_expression
syntax num : primary_expression
syntax "(" expression ")" : primary_expression

syntax "`[primary_expression| " primary_expression "]" : term

syntax primary_expression : postfix_expression
syntax postfix_expression "[" expression "]" : postfix_expression
syntax postfix_expression "(" ")"  : postfix_expression
syntax postfix_expression "(" argument_expression_list ")" : postfix_expression
syntax postfix_expression "." ident : postfix_expression
syntax postfix_expression "->" ident : postfix_expression
syntax postfix_expression "++" : postfix_expression
syntax postfix_expression "--" : postfix_expression

syntax "`[postfix_expression| " postfix_expression "]" : term

syntax "&" : unary_operator
syntax "*" : unary_operator
syntax "+" : unary_operator
syntax "-" : unary_operator
syntax "~" : unary_operator
syntax "!" : unary_operator

syntax "`[unary_operator| " unary_operator "]" : term

syntax postfix_expression : unary_expression
syntax "++" unary_expression : unary_expression
syntax "--" unary_expression : unary_expression
syntax unary_operator cast_expression : unary_expression
syntax "sizeof" unary_expression : unary_expression
-- syntax "sizeof" "(" type_name ")" : unary_expression   -- type_name not in group one

syntax "`[unary_expression| " unary_expression "]" : term

syntax unary_expression : cast_expression
syntax "(" type_name ")" cast_expression : cast_expression

syntax "`[cast_expression| " cast_expression "]" : term

syntax num : expression

syntax "`[expression| " expression "]" : term
