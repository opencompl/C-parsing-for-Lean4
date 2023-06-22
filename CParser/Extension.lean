import Lean
import CParser.SyntaxDecl
open Lean

macro "typedef" ids:ident+ : command => do
  let idsList := ids.toList
  let id := idsList.getLast!
  let stratom : TSyntax `str := ⟨Syntax.mkStrLit id.getId.toString⟩
  let stxstx : Array (TSyntax `stx) := #[( ← `(stx| $stratom:str)) ]
  let cat := mkIdentFrom id `type_name_token
  `(syntax  $[$stxstx]* : $cat)
--  return mkNullNode #[stxDecl]

typedef struct foo foo
#check `(type_name_token| foo)

syntax "struct" : struct_or_union
syntax "union" : struct_or_union
syntax struct_declaration+ : struct_declaration_list
syntax specifier_qualifier_list struct_declarator_list ";" : struct_declaration
syntax type_specifier : specifier_qualifier
syntax type_qualifier : specifier_qualifier
syntax specifier_qualifier+ : specifier_qualifier_list
syntax "int": type_specifier
syntax struct_or_union_specifier: type_specifier
syntax type_name_token : type_specifier
syntax struct_declarator,* : struct_declarator_list
syntax declarator : struct_declarator
syntax (pointer)? direct_declarator : declarator
syntax ident : direct_declarator
syntax "*" (type_qualifier_list)? (pointer)? : pointer
syntax struct_or_union ident ("{" struct_declaration_list "}")? : struct_or_union_specifier

macro struct_or_union id:ident ("{" struct_declaration_list "}")? : command => do
  let stratom : TSyntax `str := ⟨Syntax.mkStrLit id.getId.toString⟩
  let stxstx : Array (TSyntax `stx) := #[( ← `(stx| $stratom:str)) ]
  let cat := mkIdentFrom id `type_name_token
  `(syntax  $[$stxstx]* : $cat)

struct Node
{
    int Element;
    struct Node *pNext;
}

#check `(type_name_token| Node)