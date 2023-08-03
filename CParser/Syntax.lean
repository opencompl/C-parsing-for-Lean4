import CParser.SyntaxDecl
import CParser.AST
open AST

open Lean -- for (sepBy ...)
open Lean.Parser -- for (sepBy ...)
open Lean.Elab
open Lean.Elab.Command

syntax ident : primary_expression
syntax char : primary_expression
syntax str+ : primary_expression

syntax "`[primary_expression| " primary_expression "]" : term

-- translation unit
syntax primary_expression : translation_unit

syntax "`[translation_unit| " translation_unit "]" : term
