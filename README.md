# C-parsing-for-Lean4
A parser for ANSI C, in Lean4.

# Running

Run `lake build` at the toplevel folder.

# TODOS
The order in which the nonterminals of the C grammar ([reference](https://www.lysator.liu.se/c/ANSI-C-grammar-y.html#shift-expression)) is as follows:
```
+ assignment_expression
    + assignment_operator
    + assignment_expression
    + unary_expression
    + unary_operator
    + postfix_expression
    + primary_expression
    + argument_expression_list
    + expression
    + conditional_expression ... cast_expression [leads to type_name]

+ init_declarator_list
    + init_declarator
    + initializer [leads to assignment_expression]
    + initializer_list
    + declarator
    + pointer
    + type_qualifier_list [leads to type_qualifier]
    + direct_declarator [leads to parameter_type_list]
    + identifier_list
    + abstract_declarator
    + direct_abstract_declarator [leads to parameter_type_list]
    + constant_expression

+ declarator_list
    - declaration
    - init_declarator_list
    - init_declarator [leads to declarator]
    - parameter_type_list
    - parameter_list
    - parameter_declaration
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
