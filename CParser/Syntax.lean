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

-- type_specifier
syntax "void" : type_specifier
syntax "char": type_specifier
-- syntax "int": type_specifier
syntax "`[type_specifier| " type_specifier "]" : term

-- syntax declaration : external_declaration
syntax ";" : external_declaration
syntax "`[external_declaration| " external_declaration "]" : term

-- translation unit
syntax external_declaration+ : translation_unit

syntax "`[translation_unit| " translation_unit "]" : term
