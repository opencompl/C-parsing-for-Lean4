import CParser.SyntaxDecl
import CParser.AST
open AST

syntax conditional_expression : constant_expression

syntax "`[constant_expression| " constant_expression "]" : term

syntax "(" abstract_declarator ")" : direct_abstract_declarator
syntax "[" "]" : direct_abstract_declarator
syntax "[" constant_expression "]" : direct_abstract_declarator
syntax direct_abstract_declarator "[" "]" : direct_abstract_declarator
syntax direct_abstract_declarator "[" constant_expression "]" : direct_abstract_declarator
syntax "(" ")" : direct_abstract_declarator
syntax "(" parameter_type_list ")" : direct_abstract_declarator
syntax direct_abstract_declarator "(" ")" : direct_abstract_declarator
syntax direct_abstract_declarator "(" parameter_type_list ")" : direct_abstract_declarator

syntax "`[direct_abstract_declarator| " direct_abstract_declarator "]" : term

syntax pointer : abstract_declarator
syntax direct_abstract_declarator : abstract_declarator
syntax pointer direct_abstract_declarator : abstract_declarator

syntax "`[abstract_declarator| " abstract_declarator "]" : term

syntax ident : identifier_list
syntax identifier_list "," ident : identifier_list

syntax "`[identifier_list| " identifier_list "]" : term

syntax ident : direct_declarator
syntax "(" declarator ")" : direct_declarator
syntax direct_declarator "[" constant_expression "]" : direct_declarator
syntax direct_declarator "[" "]" : direct_declarator
syntax direct_declarator "(" parameter_type_list ")" : direct_declarator
syntax direct_declarator "(" identifier_list ")" : direct_declarator
syntax direct_declarator "(" ") " : direct_declarator

syntax "`[direct_declarator| " direct_declarator "]" : term

syntax type_qualifier : type_qualifier_list
syntax type_qualifier_list type_qualifier : type_qualifier_list

syntax "`[type_qualifier_list| " type_qualifier_list "]" : term

syntax "const" : type_qualifier
syntax "volatile" : type_qualifier

syntax "`[type_qualifier| " type_qualifier "]" : term

syntax "*" : pointer
syntax "*" type_qualifier_list : pointer
syntax "*" pointer : pointer
syntax "*" type_qualifier_list pointer : pointer

syntax "`[pointer| " pointer "]" : term

syntax pointer direct_declarator : declarator
syntax direct_declarator : declarator

syntax "`[declarator| " declarator "]" : term

syntax initializer : initializer_list
syntax initializer_list "," initializer : initializer_list

syntax "`[initializer_list| " initializer_list "]" : term

syntax assignment_expression : initializer
syntax "{" initializer_list "}" : initializer
syntax "{" initializer_list "," "}" : initializer

syntax "`[initializer| " initializer "]" : term

syntax declarator : init_declarator
syntax declarator "=" initializer : init_declarator

syntax "`[init_declarator| " init_declarator "]" : term
