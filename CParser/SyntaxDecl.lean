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

declare_syntax_cat primary_expression
declare_syntax_cat type_specifier
