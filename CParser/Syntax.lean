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
syntax extended_num : primary_expression
syntax scientific : primary_expression
syntax char : primary_expression
syntax str+ : primary_expression

syntax "`[primary_expression| " primary_expression "]" : term

syntax dec_sym := "--"

syntax sepBy(ident, ",", ", ") : identifier_list

syntax "`[identifier_list| " identifier_list "]" : term

syntax type_qualifier+ : type_qualifier_list

syntax "`[type_qualifier_list| " type_qualifier_list "]" : term

syntax "const" : type_qualifier
syntax "volatile" : type_qualifier

syntax "`[type_qualifier| " type_qualifier "]" : term

syntax "*" (type_qualifier_list)? (pointer)? : pointer

syntax "`[pointer| " pointer "]" : term

syntax sepBy(initializer, "," , ",", allowTrailingSep) : initializer_list

syntax "{" initializer_list "}" : initializer

syntax "`[initializer| " initializer "]" : term

-- declaration
syntax primary_expression : declaration
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
-- syntax "short": type_specifier
-- syntax "int": type_specifier
-- syntax "long": type_specifier
-- syntax "float": type_specifier
-- syntax "double": type_specifier
-- syntax "signed" : type_specifier
-- syntax "unsigned": type_specifier
-- syntax enum_specifier: type_specifier
syntax "`[type_specifier| " type_specifier "]" : term

-- specifier_qualifier
syntax type_specifier : specifier_qualifier
syntax type_qualifier : specifier_qualifier
syntax "`[specifier_qualifier| " specifier_qualifier "]" : term

-- specifier_qualifier_list
syntax specifier_qualifier : specifier_qualifier_list
syntax specifier_qualifier specifier_qualifier_list : specifier_qualifier_list
syntax "`[specifier_qualifier_list| " specifier_qualifier_list "]" : term

-- enum_specifier
syntax primary_expression : enum_specifier
syntax "`[enum_specifier| " enum_specifier "]" : term

-- enumerator_list
syntax sepBy(enumerator, ",", ", ") : enumerator_list

syntax "`[enumerator_list| " enumerator_list "]" : term

-- parameter_type_list
syntax parameter_list ("," "...")? : parameter_type_list
syntax "`[parameter_type_list| " parameter_type_list "]" : term

-- parameter_list
syntax sepBy(parameter_declaration, ",", ", " notFollowedBy("...")) : parameter_list

syntax "`[parameter_list| " parameter_list "]" : term

-- parameter_declaration
syntax primary_expression : parameter_declaration
syntax "`[parameter_declaration| " parameter_declaration "]" : term

-- compound statement
syntax "{" "}" : compound_statement
syntax "{" statement_list "}" : compound_statement
syntax "{" declaration_list "}" : compound_statement
syntax "{" declaration_list statement_list "}" : compound_statement
syntax "`[compound_statement| " compound_statement "]" : term

-- statement
syntax compound_statement : statement
syntax "`[statement| " statement "]" : term

-- statement list
syntax statement : statement_list
syntax statement statement_list : statement_list

syntax "`[statement_list| " statement_list "]" : term

-- external declaration
syntax declaration : external_declaration
syntax ";" : external_declaration
syntax "`[external_declaration| " external_declaration "]" : term

-- translation unit
syntax external_declaration+ : translation_unit

syntax "`[translation_unit| " translation_unit "]" : term
