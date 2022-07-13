import CParser.SyntaxDecl
import CParser.AST
open AST

-- function definition
syntax declaration_specifiers declarator declaration_list compound_statement : function_definition
syntax declaration_specifiers declarator compound_statement : function_definition
syntax declarator declaration_list compound_statement : function_definition
syntax declarator compound_statement : function_definition
syntax "`[function_definition| " function_definition "]" : term

-- external declaration
syntax function_definition : external_declaration
syntax declaration : external_declaration
syntax "`[external_declaration| " external_declaration "]" : term

-- translation unit
syntax external_declaration : translation_unit
syntax translation_unit external_declaration : translation_unit
syntax "`[translation_unit| " translation_unit "]" : term