import CParser.SyntaxDecl
import CParser.AST
open AST

open Lean -- for (sepBy ...)
open Lean.Parser -- for (sepBy ...)
open Lean.Elab
open Lean.Elab.Command

syntax ident : primary_expression
syntax scientific : primary_expression
syntax char : primary_expression
syntax str+ : primary_expression

syntax "`[primary_expression| " primary_expression "]" : term

-- type_specifier
syntax "void" : type_specifier
syntax "char": type_specifier
-- syntax "int": type_specifier
syntax "`[type_specifier| " type_specifier "]" : term

-- translation unit
syntax ";" : translation_unit
syntax "`[translation_unit| " translation_unit "]" : term
