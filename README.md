# C-parsing-for-Lean4
A parser for ANSI C, in Lean4.

## Description

The system uses macros to parse C code into an AST represented by a user-defined Lean type `translation_unit`.  
This has been implemented by defining syntax categories according to the ANSI C Grammar (see below), and mapping non-terminal expansions to different constructors of the corresponding datatype.

## Testing

In order to run the tests, first run `lake build`. Then run `./build/bin/cParser`.  
This will run the parser on the files in the `Tests` directory.  
Alternatively, simply run `lake exe cParser`.

Failed tests can be filtered by piping the output of the command through `grep` in the following manner:  
```./build/bin/cParser | grep error```

## Limitations
The file `Tests/SQLite/shell_clanged.c` is the output of `clang -E sqlite-amalgamation-3420000/shell.c`.  
The file `Tests/SQLite/sqlite3_clanged.c` is the output of `clang -E sqlite-amalgamation-3420000/sqlite3.c`.

Before preprocessing, add the following directives to eliminate these macros from the code and include certain type definitions:
```c
#define __attribute__(x)
#define __extension__
#define __restrict
#define restrict
#define __inline
#define  __asm__(x)
#define __asm(x)
#define _Nonnull
#define _Nullable
#define _Null_unspecified
#include <byteswap.h> // for non-Mac OS; else
#  include <libkern/OSByteOrder.h>

 /* We assume little endian. */
#  define htobe64(x) OSSwapHostToBigInt64(x)
#  define htobe32(x) OSSwapHostToBigInt32(x)
#  define htobe16(x) OSSwapHostToBigInt16(x)

#  define be64toh(x) OSSwapBigToHostInt64(x)
#  define be32toh(x) OSSwapBigToHostInt32(x)
#  define be16toh(x) OSSwapBigToHostInt16(x)

// The following are for sqlite3.c
typedef unsigned long long __uint128_t;
typedef void(*LOGFUNC_t)(void*,int,const char*);
typedef int(*sqlite3FaultFuncType)(int);
typedef void (*void_function)(void);
typedef int(*sqlite3LocaltimeType)(const void*,void*);
```

## The `typedef` Issue
In C, a `typedef` statement creates a new type name, which cannot be parsed as an identifier within the scope of that `typedef` statement (global or function).  

Consider the statement
```c
typedef struct Foo Foo;
```
If this statement in the outermost scope, then after it, `Foo` is a type name in that scope, but may be used to declare identifiers (thus hiding the type name) in local scopes.

However, if the statement is in a local scope, `Foo` is a type name only within that scope, and ceases to be one when we return from it.

This property makes C's grammar more context-sensitive than Lean's itself, which makes a straightforward solution infeasible. However, a solution for a limited (and, to our knowledge, fairly common) case of this has been implemented.  
Global `typedef`s create new type names, which cannot be reused as identifiers in any scope after the `typedef`. Local `typedef`s cause no errors, but have no effect on the environment (create no new type names).

Thus, this snippet
```c
typedef struct Foo Foo;

struct Foo { int y ; };

Foo return_Foo(int x)
{
    Foo bar;
    bar.y = x;
    return bar;
}
```
parses, but this one
```c
typedef struct Foo;

struct Foo { int y ; };

Foo return_Foo(int x)
{
    int Foo = x;
    struct Foo bar;
    bar.y = Foo;
    return bar;
}
```
and this one
```c
struct Foo { int y ; };    
struct Foo add_and_wrap(int a, int b)
{
    typedef struct Foo Foo;
    Foo bar;
    bar.y = a + b;
    return bar;
}
```
do not.

## Group-wise list of non-terminals
The order in which the nonterminals of the C grammar ([reference](https://www.lysator.liu.se/c/ANSI-C-grammar-y.html)) is as follows:
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
    + type_qualifier
    + type_qualifier_list
    + direct_declarator [leads to parameter_type_list]
    + identifier_list
    + abstract_declarator
    + direct_abstract_declarator [leads to parameter_type_list]
    + constant_expression

+ declaration_list
    + declaration
    + init_declarator_list
    + parameter_type_list
    + parameter_list
    + parameter_declaration
    + declaration_specifiers
    + storage_class_specifier
    + type_specifier
    + enum_specifier
    + enumerator_list
    + enumerator
    + struct_or_union_specifier
    + struct_or_union
    + struct_declaration_list
    + struct_declaration
    + type_name
    + specifier_qualifier_list
    + struct_declarator_list
    + struct_declarator

+ compound_statement [leads to declaration_list]
    + statement_list
    + statement
    + labeled_statement
    + jump_statement
    + iteration_statement
    + selection_statement
    + expression_statement

+ translation_unit
    + external_declaration
    + function_definition
```