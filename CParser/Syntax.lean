import CParser.SyntaxDecl
import CParser.AST
open AST

open Lean -- for (sepBy ...)
open Lean.Parser -- for (sepBy ...)
open Lean.Elab
open Lean.Elab.Command

def arith_type_specs : Parser where
  fn c s :=
    let startPos := s.pos
    let s := takeWhileFn "uUlL".contains c.toTokenParserContext s
    mkNodeToken `arith_type_specs startPos CParser.whitespace c.toTokenParserContext s

attribute [combinator_formatter arith_type_specs] PrettyPrinter.Formatter.pushNone.formatter
attribute [combinator_parenthesizer arith_type_specs] PrettyPrinter.Parenthesizer.pushNone.parenthesizer

syntax num (noWs arith_type_specs)?: extended_num

syntax ident : primary_expression
syntax type_name_token : primary_expression
syntax extended_num : primary_expression
syntax scientific : primary_expression
syntax char : primary_expression
syntax str+ : primary_expression
syntax "(" expression ")" : primary_expression

syntax "`[primary_expression| " primary_expression "]" : term

syntax dec_sym := "--"

syntax primary_expression : postfix_expression
syntax postfix_expression "[" expression "]" : postfix_expression
syntax postfix_expression "(" ")"  : postfix_expression
syntax postfix_expression "(" argument_expression_list ")" : postfix_expression
syntax "va_arg" "(" assignment_expression "," type_name ")" : postfix_expression
syntax "__builtin_va_arg" "(" assignment_expression "," type_name ")" : postfix_expression
syntax postfix_expression "." ident : postfix_expression
syntax postfix_expression "." type_name_token : postfix_expression
syntax postfix_expression "->" ident : postfix_expression
syntax postfix_expression "->" type_name_token : postfix_expression
syntax postfix_expression "++" : postfix_expression
syntax postfix_expression dec_sym : postfix_expression

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
syntax dec_sym unary_expression : unary_expression
syntax unary_operator cast_expression : unary_expression
syntax "sizeof" unary_expression : unary_expression
syntax "sizeof" "(" type_name ")" : unary_expression
syntax "sizeof" "(" type_name_token ")" : unary_expression

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
syntax "+=" : assignment_operator
syntax "-=" : assignment_operator
syntax "<<=" : assignment_operator
syntax ">>=" : assignment_operator
syntax "&=" : assignment_operator
syntax "^=" : assignment_operator
syntax "|=" : assignment_operator

syntax "`[assignment_operator| " assignment_operator "]" : term

syntax conditional_expression : assignment_expression
syntax unary_expression assignment_operator assignment_expression : assignment_expression
syntax "(" compound_statement ")" : assignment_expression

syntax "`[assignment_expression| " assignment_expression "]" : term

syntax sepBy(assignment_expression, ",", ", ") : argument_expression_list

syntax "`[argument_expression_list| " argument_expression_list "]" : term

syntax sepBy(assignment_expression, ",", ", ") : expression

syntax "`[expression| " expression "]" : term

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

syntax sepBy(ident, ",", ", ") : identifier_list

syntax "`[identifier_list| " identifier_list "]" : term

syntax ident : direct_declarator
syntax type_name_token : direct_declarator
syntax "(" declarator ")" : direct_declarator
syntax direct_declarator "[" constant_expression "]" : direct_declarator
syntax direct_declarator "[" "]" : direct_declarator
syntax direct_declarator "(" parameter_type_list ")" : direct_declarator
syntax direct_declarator "(" identifier_list ")" : direct_declarator
syntax direct_declarator "(" ") " : direct_declarator

syntax "`[direct_declarator| " direct_declarator "]" : term

syntax type_qualifier+ : type_qualifier_list

syntax "`[type_qualifier_list| " type_qualifier_list "]" : term

syntax "const" : type_qualifier
syntax "volatile" : type_qualifier

syntax "`[type_qualifier| " type_qualifier "]" : term

syntax "*" (type_qualifier_list)? (pointer)? : pointer

syntax "`[pointer| " pointer "]" : term

syntax (pointer)? direct_declarator : declarator

syntax "`[declarator| " declarator "]" : term

/-
Original:
--------
syntax initializer : initializer_list
syntax initializer_list "," initializer : initializer_list

syntax "`[initializer_list| " initializer_list "]" : term

syntax assignment_expression : initializer
syntax "{" initializer_list "}" : initializer
syntax "{" initializer_list "," "}" : initializer

Reformat:
---------
Consider `init_declarator_2.c`:
foo(bar, bat, baz) = {i = 5, j = 6 | 2, }

The right-hand-size { i = 5, j = 6 | 2   , } should be parsed as:
initializer ->      { initializer_list  ","} 

However, the Lean parser parses this as:
                    { i = 5, j = 6 | 2    ,                  }
initializer      -> { initializer_list                       } 
initializer_list -> { initializer_list    , initializer      }
                                            ^^^^^^^^^^^

Change to grammar:
------------------
We use Lean4's higher level `sepBy` to create a parser.
-/

syntax sepBy(initializer, "," , ",", allowTrailingSep) : initializer_list

syntax assignment_expression : initializer
syntax "{" initializer_list "}" : initializer

syntax "`[initializer| " initializer "]" : term

syntax declarator ("=" initializer)? : init_declarator
syntax "`[init_declarator| " init_declarator "]" : term

-- declaration
syntax declaration_specifiers (init_declarator_list)? ";" : declaration
syntax "`[declaration| " declaration "]" : term

-- declaration_list
syntax declaration : declaration_list
syntax declaration declaration_list : declaration_list

syntax "`[declaration_list| " declaration_list "]" : term

-- declaration_specifiers
syntax storage_class_specifier : declaration_specifiers
syntax storage_class_specifier declaration_specifiers : declaration_specifiers
syntax type_specifier : declaration_specifiers
syntax type_specifier declaration_specifiers: declaration_specifiers
syntax type_qualifier : declaration_specifiers
syntax type_qualifier declaration_specifiers: declaration_specifiers
syntax "`[declaration_specifiers| " declaration_specifiers "]" : term


-- init_declarator_list
syntax sepBy(init_declarator, ",", ", ") : init_declarator_list

syntax "`[init_declarator_list| " init_declarator_list "]" : term

-- storage_class_specifier
syntax "typedef" : storage_class_specifier
syntax "extern": storage_class_specifier
syntax "static": storage_class_specifier
syntax "auto": storage_class_specifier
syntax "register" : storage_class_specifier
syntax "inline" : storage_class_specifier
syntax "`[storage_class_specifier| " storage_class_specifier "]" : term

-- type_specifier
syntax "void" : type_specifier
syntax "char": type_specifier
syntax "short": type_specifier
syntax "int": type_specifier
syntax "long": type_specifier
syntax "float": type_specifier
syntax "double": type_specifier
syntax "signed" : type_specifier
syntax "unsigned": type_specifier
syntax struct_or_union_specifier: type_specifier
syntax enum_specifier: type_specifier
syntax type_name_token : type_specifier
syntax "`[type_specifier| " type_specifier "]" : term

syntax "__builtin_va_list" : type_name_token
syntax "`[type_name_token| " type_name_token "]" : term

-- struct_or_union_specifier
syntax struct_or_union ident ("{" struct_declaration_list "}")? : struct_or_union_specifier
syntax struct_or_union type_name_token ("{" struct_declaration_list "}")? : struct_or_union_specifier
syntax struct_or_union "{" struct_declaration_list "}" : struct_or_union_specifier
syntax "`[struct_or_union_specifier| " struct_or_union_specifier "]" : term

-- struct_or_union
syntax "struct" : struct_or_union
syntax "union" : struct_or_union
syntax "`[struct_or_union| " struct_or_union "]" : term

-- struct_declaration_list
syntax struct_declaration+ : struct_declaration_list

syntax "`[struct_declaration_list| " struct_declaration_list "]" : term

-- struct_declaration
syntax specifier_qualifier_list struct_declarator_list ";" : struct_declaration
syntax "`[struct_declaration| " struct_declaration "]" : term

-- specifier_qualifier
syntax type_specifier : specifier_qualifier
syntax type_qualifier : specifier_qualifier
syntax "`[specifier_qualifier| " specifier_qualifier "]" : term

-- specifier_qualifier_list
syntax specifier_qualifier : specifier_qualifier_list
syntax specifier_qualifier specifier_qualifier_list : specifier_qualifier_list
syntax "`[specifier_qualifier_list| " specifier_qualifier_list "]" : term

-- struct_declarator_list
syntax struct_declarator,* : struct_declarator_list

syntax "`[struct_declarator_list| " struct_declarator_list "]" : term

-- struct_declarator
syntax declarator : struct_declarator
syntax ":" constant_expression : struct_declarator
syntax declarator ":" constant_expression : struct_declarator
syntax "`[declarator| " declarator "]" : term

-- enum_specifier
syntax "enum" "{" enumerator_list "}"  : enum_specifier
syntax "enum" ident "{" enumerator_list "}" : enum_specifier
syntax "enum" type_name_token "{" enumerator_list "}" : enum_specifier
syntax "enum" ident : enum_specifier
syntax "enum" type_name_token : enum_specifier
syntax "`[enum_specifier| " enum_specifier "]" : term

-- enumerator_list
syntax sepBy(enumerator, ",", ", ") : enumerator_list

syntax "`[enumerator_list| " enumerator_list "]" : term


-- enumerator
syntax ident ("=" constant_expression)? : enumerator
syntax type_name_token ("=" constant_expression)? : enumerator
syntax "`[enumerator| " enumerator "]" : term

-- parameter_type_list
syntax parameter_list ("," "...")? : parameter_type_list
syntax "`[parameter_type_list| " parameter_type_list "]" : term

-- parameter_list
syntax sepBy(parameter_declaration, ",", ", " notFollowedBy("...")) : parameter_list

syntax "`[parameter_list| " parameter_list "]" : term

-- parameter_declaration
syntax declaration_specifiers declarator : parameter_declaration
syntax declaration_specifiers abstract_declarator : parameter_declaration
syntax declaration_specifiers : parameter_declaration
syntax "`[parameter_declaration| " parameter_declaration "]" : term

-- type_name
syntax specifier_qualifier_list (abstract_declarator)? : type_name
syntax "`[type_name| " type_name "]" : term

-- expression statement
syntax (expression)? ";" : expression_statement
syntax "`[expression_statement| " expression_statement "]" : term

-- selection statement
syntax "if" "(" expression ")" statement ("else" statement)? : selection_statement
syntax "switch" "(" expression ")" statement : selection_statement
syntax "`[selection_statement| " selection_statement "]" : term

-- iteration statement
syntax "while" "(" expression ")" statement : iteration_statement
syntax "do" statement "while" "(" expression ")" ";" : iteration_statement
syntax "for" "(" expression_statement expression_statement (expression)? ")" statement : iteration_statement
syntax "`[iteration_statement| " iteration_statement "]" : term

-- jump statement
syntax "goto" ident ";" : jump_statement
syntax "goto" type_name_token ";" : jump_statement
syntax "continue" ";" : jump_statement
syntax "break" ";" : jump_statement
syntax "return" ";" : jump_statement
syntax "return" expression ";" : jump_statement
syntax "`[jump_statement| " jump_statement "]" : term

-- labelled statement
syntax ident ":" statement : labeled_statement
syntax type_name_token ":" statement : labeled_statement
syntax "case" constant_expression ":" statement : labeled_statement
syntax "default" ":" statement : labeled_statement
syntax "`[labeled_statement| " labeled_statement "]" : term

-- compound statement
syntax "{" "}" : compound_statement
syntax "{" statement_list "}" : compound_statement
syntax "{" declaration_list "}" : compound_statement
syntax "{" declaration_list statement_list "}" : compound_statement
syntax "`[compound_statement| " compound_statement "]" : term

-- statement
syntax labeled_statement : statement
syntax compound_statement : statement
syntax expression_statement : statement
syntax selection_statement : statement
syntax iteration_statement : statement
syntax jump_statement : statement
syntax "`[statement| " statement "]" : term

-- statement list
syntax statement : statement_list
syntax statement statement_list : statement_list

syntax "`[statement_list| " statement_list "]" : term

-- function definition
syntax (declaration_specifiers)? declarator (declaration_list)? compound_statement : function_definition
syntax "`[function_definition| " function_definition "]" : term

-- external declaration
syntax function_definition : external_declaration
syntax declaration : external_declaration
syntax ";" : external_declaration
syntax "`[external_declaration| " external_declaration "]" : term

-- translation unit
syntax external_declaration+ : translation_unit

syntax "`[translation_unit| " translation_unit "]" : term
