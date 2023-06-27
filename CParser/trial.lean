import Lean

open Lean
open Parser

def arith_type_specs : Parser where
  fn c s :=
    let startPos := s.pos
    let s := takeWhileFn "uUlL".contains c s
    mkNodeToken `arith_type_specs startPos c s

attribute [combinator_formatter arith_type_specs] PrettyPrinter.Formatter.pushNone.formatter
attribute [combinator_parenthesizer arith_type_specs] PrettyPrinter.Parenthesizer.pushNone.parenthesizer

macro "test" n:num noWs arith_type_specs : term =>
  return n.raw[0].getAtomVal |> Syntax.mkNumLit

#check test 534ul