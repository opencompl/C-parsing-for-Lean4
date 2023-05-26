import Lean
import CParser.SyntaxDecl
open Lean

macro "typedef" id:ident : command => do
  let stratom : TSyntax `str := ⟨Syntax.mkStrLit id.getId.toString⟩
  let stxstx : Array (TSyntax `stx) := #[( ← `(stx| $stratom:str)) ]
  let cat := mkIdentFrom id `type_name_token
  let stxDecl ← `(syntax  $[$stxstx]* : $cat)
  return stxDecl
--  return mkNullNode #[stxDecl]

typedef foo
#check `(type_name_token| foo)
