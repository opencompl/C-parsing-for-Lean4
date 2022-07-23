import CParser.SyntaxDecl
import CParser.Syntax.GroupOne
import CParser.Syntax.GroupTwo
import Lean

open AST
open Lean -- for (sepBy ...)
open Lean.Parser -- for (sepBy ...)
open Lean.Elab
open Lean.Elab.Command

-- syntax declaration
-- syntax declaration_specifiers ";" : declaration
syntax declaration_specifiers (init_declarator_list)? ";" : declaration
syntax "`[declaration| " declaration "]" : term

-- declaration_list
-- syntax declaration : declaration_list
-- syntax declaration_list declaration : declaration_list
syntax declaration+ : declaration_list

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
-- syntax init_declarator : init_declarator_list
-- syntax init_declarator_list "," init_declarator : init_declarator_list
syntax sepBy(init_declarator, ",", ", ") : init_declarator_list

syntax "`[init_declarator_list| " init_declarator_list "]" : term

-- storage_class_specifier
syntax "typedef" : storage_class_specifier
syntax "extern": storage_class_specifier
syntax "static": storage_class_specifier
syntax "auto": storage_class_specifier
syntax "register": storage_class_specifier
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
syntax "typename" : type_specifier
syntax "`[type_specifier| " type_specifier "]" : term


-- struct_or_union_specifier
syntax struct_or_union ident "{" struct_declaration_list "}" : struct_or_union_specifier
syntax struct_or_union "{" struct_declaration_list "}" : struct_or_union_specifier
syntax struct_or_union ident : struct_or_union_specifier
syntax "`[struct_or_union_specifier| " struct_or_union_specifier "]" : term

-- struct_or_union
syntax "struct" : struct_or_union
syntax "union" : struct_or_union
syntax "`[struct_or_union| " struct_or_union "]" : term

-- struct_declaration_list
-- syntax struct_declaration : struct_declaration_list
-- syntax struct_declaration_list struct_declaration : struct_declaration_list
syntax struct_declaration+ : struct_declaration_list

syntax "`[struct_declaration_list| " struct_declaration_list "]" : term

-- struct_declaration
syntax specifier_qualifier_list struct_declarator_list ";" : struct_declaration
syntax "`[struct_declaration| " struct_declaration "]" : term

-- specifier_qualifier_list
syntax type_specifier specifier_qualifier_list : specifier_qualifier_list
syntax type_specifier : specifier_qualifier_list
syntax type_qualifier specifier_qualifier_list : specifier_qualifier_list
syntax type_qualifier : specifier_qualifier_list
syntax "`[specifier_qualifier_list| " specifier_qualifier_list "]" : term

-- struct_declarator_list
-- syntax struct_declarator : struct_declarator_list
-- syntax struct_declarator_list "," struct_declarator : struct_declarator_list
syntax sepBy(struct_declarator, ",", ", ") : struct_declarator_list

syntax "`[struct_declarator_list| " struct_declarator_list "]" : term

-- struct_declarator
syntax declarator : struct_declarator
syntax ":" constant_expression : struct_declarator
syntax declarator ":" constant_expression : struct_declarator
syntax "`[declarator| " declarator "]" : term

-- enum_specifier
syntax "enum" "{" enumerator_list "}"  : enum_specifier
syntax "enum" ident "{" enumerator_list "}" : enum_specifier
syntax "enum" ident : enum_specifier
syntax "`[enum_specifier| " enum_specifier "]" : term

-- enumerator_list
-- syntax enumerator : enumerator_list
-- syntax enumerator_list "," enumerator : enumerator_list
syntax sepBy(enumerator, ",", ", ") : enumerator_list

syntax "`[enumerator_list| " enumerator_list "]" : term


-- enumerator
-- syntax ident : enumerator
syntax ident ("=" constant_expression)? : enumerator
syntax "`[enumerator| " enumerator "]" : term

-- parameter_type_list
-- syntax parameter_list : parameter_type_list
syntax parameter_list ("," "...")? : parameter_type_list
syntax "`[parameter_type_list| " parameter_type_list "]" : term

-- parameter_list
-- syntax parameter_declaration : parameter_list
-- syntax parameter_list "," parameter_declaration : parameter_list
syntax sepBy(parameter_declaration, ",", ", " notFollowedBy("...")) : parameter_list

syntax "`[parameter_list| " parameter_list "]" : term

-- parameter_declaration
syntax declaration_specifiers declarator : parameter_declaration
syntax declaration_specifiers abstract_declarator : parameter_declaration
syntax declaration_specifiers : parameter_declaration
syntax "`[parameter_declaration| " parameter_declaration "]" : term

-- type_name
-- syntax specifier_qualifier_list : type_name
syntax specifier_qualifier_list (abstract_declarator)? : type_name
syntax "`[type_name| " type_name "]" : term