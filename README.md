# C-parsing-for-Lean4
A parser for ANSI C, in Lean4.

# Running

Run `lake build` at the toplevel folder.

# TODOS
The order in which the nonterminals of the C grammar ([reference](https://www.lysator.liu.se/c/ANSI-C-grammar-y.html#shift-expression)) is as follows:
```
+ assignment_expression
    - assignment_operator
    - assignment_expression
    - unary_expression
    - unary_operator
    - postfix_expression
    - primary_expression
    - argument_expression_list
    - expression
    - conditional_expression ... cast_expression [leads to type_name]

+ init_declarator_list
    - init_declarator
    - initializer [leads to assignment_expression]
    - declarator
    - pointer
    - type_qualifier_list
    - direct_declarator
    - identifier_list
    - parameter_type_list
    - parameter_list
    - parameter_declaration [leads to declaration_specifiers]
    - abstract_declaration
    - direct_abstract_declarator
    - constant_expression

+ declarator_list
    - declaration
    - init_declarator_list
    - init_declarator [leads to declarator]
    - initializer [leads to assignment_expression]
    - declaration_specifiers
    - storage_class_specifier
    - type_qualifier
    - type_specifier
    - enum_specifier
    - enumerator_list
    - enumerator
    - const_expression
    - struct_or_union_specifier
    - struct_or_union
    - struct_declaration_list
    - struct_declaration
    - type_name
    - specifier_qualifier_list
    - struct_declarator_list
    - struct_declarator [leads to declarator]

+ compound_statement [leads to declarator_list]
    - statement_list
    - statement
    - labeled_statement
    - jump_statement
    - iteration_statement
    - selection_statement
    - expression_list
    - expression

+ translation_unit
    - external_declaration
    - function_definition
```
