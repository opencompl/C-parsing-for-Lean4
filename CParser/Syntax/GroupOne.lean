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

syntax cast_expression : multiplicative_expression
syntax multiplicative_expression "*" cast_expression : multiplicative_expression
syntax multiplicative_expression "/" cast_expression : multiplicative_expression
syntax multiplicative_expression "%" cast_expression : multiplicative_expression

syntax "`[multiplicative_expression| " multiplicative_expression "]" : term

syntax multiplicative_expression : additive_expression
syntax additive_expression "+" multiplicative_expression : additive_expression
syntax additive_expression "-" multiplicative_expression : additive_expression

syntax "`[additive_expression| " additive_expression "]" : term

syntax additive_expression : shift_expression
syntax shift_expression "<<" additive_expression : shift_expression
syntax shift_expression ">>" additive_expression : shift_expression

syntax "`[shift_expression| " shift_expression "]" : term

syntax shift_expression : relational_expression
syntax relational_expression "<" shift_expression : relational_expression
syntax relational_expression ">" shift_expression : relational_expression
syntax relational_expression "<=" shift_expression : relational_expression
syntax relational_expression ">=" shift_expression : relational_expression

syntax "`[relational_expression| " relational_expression "]" : term

syntax relational_expression : equality_expression 
syntax equality_expression "==" relational_expression : equality_expression
syntax equality_expression "!=" relational_expression : equality_expression

syntax "`[equality_expression| " equality_expression "]" : term

syntax equality_expression : and_expression
syntax and_expression "&" equality_expression : and_expression

syntax "`[and_expression| " and_expression "]" : term

syntax and_expression : exclusive_or_expression 
syntax exclusive_or_expression "^" and_expression : exclusive_or_expression 

syntax "`[exclusive_or_expression| " exclusive_or_expression "]" : term

syntax exclusive_or_expression : inclusive_or_expression
syntax inclusive_or_expression "|" exclusive_or_expression : inclusive_or_expression 

syntax "`[inclusive_or_expression| " inclusive_or_expression "]" : term

syntax inclusive_or_expression : logical_and_expression
syntax logical_and_expression "&&" inclusive_or_expression : logical_and_expression

syntax "`[logical_and_expression| " logical_and_expression "]" : term

syntax logical_and_expression : logical_or_expression
syntax logical_or_expression "||" logical_and_expression : logical_or_expression

syntax "`[logical_or_expression| " logical_or_expression "]" : term

syntax logical_or_expression : conditional_expression
syntax logical_or_expression "?" expression ":" conditional_expression : conditional_expression

syntax "`[conditional_expression| " conditional_expression "]" : term

syntax "=" : assignment_operator
syntax "*=" : assignment_operator
syntax "/=" : assignment_operator
syntax "%=" : assignment_operator
syntax "&=" : assignment_operator
syntax "^=" : assignment_operator
syntax "|=" : assignment_operator

syntax "`[assignment_operator| " assignment_operator "]" : term

syntax conditional_expression : assignment_expression
syntax unary_expression assignment_operator assignment_expression : assignment_expression

syntax "`[assignment_expression| " assignment_expression "]" : term

syntax assignment_expression : argument_expression_list
syntax argument_expression_list "," assignment_expression : argument_expression_list

syntax "`[argument_expression_list| " argument_expression_list "]" : term

syntax assignment_expression : expression
syntax expression "," assignment_expression : expression

syntax "`[expression| " expression "]" : term
