-- https://mlir.llvm.org/docs/Dialects/EmitC/
-- https://www.lysator.liu.se/c/ANSI-C-grammar-y.html
import CParser.Util
import Lean
import Lean.Elab
import Lean.Meta
import Lean.Parser
import Lean.PrettyPrinter
import Lean.PrettyPrinter.Formatter
import Lean.Parser
import Lean.Parser.Extra

open Lean
open Lean.Parser
open Lean.Elab
open Lean.Meta
open Lean.Parser
open Lean.Parser.ParserState
open Lean.PrettyPrinter
open Lean.PrettyPrinter.Formatter

declare_syntax_cat extended_num
declare_syntax_cat primary_expression
-- declare_syntax_cat postfix_expression
declare_syntax_cat argument_expression_list
-- declare_syntax_cat unary_expression
-- declare_syntax_cat cast_expression
-- declare_syntax_cat multiplicative_expression
-- declare_syntax_cat additive_expression
-- declare_syntax_cat shift_expression
-- declare_syntax_cat relational_expression
-- declare_syntax_cat equality_expression
-- declare_syntax_cat and_expression
-- declare_syntax_cat exclusive_or_expression
-- declare_syntax_cat inclusive_or_expression
-- declare_syntax_cat logical_and_expression
-- declare_syntax_cat logical_or_expression
-- declare_syntax_cat conditional_expression
-- declare_syntax_cat assignment_expression
-- declare_syntax_cat assignment_operator
-- declare_syntax_cat expression
-- declare_syntax_cat constant_expression
declare_syntax_cat declaration
declare_syntax_cat declaration_specifiers
-- declare_syntax_cat init_declarator_list
-- declare_syntax_cat init_declarator
declare_syntax_cat storage_class_specifier
declare_syntax_cat type_specifier
-- declare_syntax_cat struct_or_union_specifier
-- declare_syntax_cat struct_or_union
-- declare_syntax_cat struct_declaration_list
-- declare_syntax_cat struct_declaration
declare_syntax_cat specifier_qualifier
declare_syntax_cat specifier_qualifier_list
-- declare_syntax_cat struct_declarator_list
-- declare_syntax_cat struct_declarator
declare_syntax_cat enum_specifier
declare_syntax_cat enumerator_list
declare_syntax_cat enumerator
declare_syntax_cat type_qualifier
-- declare_syntax_cat declarator
declare_syntax_cat direct_declarator
declare_syntax_cat pointer
declare_syntax_cat type_qualifier_list
declare_syntax_cat parameter_type_list
declare_syntax_cat parameter_list
declare_syntax_cat parameter_declaration
declare_syntax_cat identifier_list
-- declare_syntax_cat type_name
-- declare_syntax_cat type_name_token
-- declare_syntax_cat abstract_declarator
declare_syntax_cat direct_abstract_declarator
declare_syntax_cat initializer
declare_syntax_cat initializer_list
declare_syntax_cat statement
-- declare_syntax_cat labeled_statement
declare_syntax_cat compound_statement
declare_syntax_cat declaration_list
declare_syntax_cat statement_list
-- declare_syntax_cat expression_statement
-- declare_syntax_cat selection_statement
-- declare_syntax_cat iteration_statement
-- declare_syntax_cat jump_statement
declare_syntax_cat translation_unit
declare_syntax_cat external_declaration
-- declare_syntax_cat function_definition
