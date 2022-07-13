import CParser.SyntaxDecl
import CParser.AST
open AST

-- expression statement
syntax ";" : expression_statement
syntax expression ";" : expression_statement
syntax "`[expression_statement| " expression_statement "]" : term

-- selection statement
syntax "if" "(" expression ")" statement : selection_statement
syntax "if" "(" expression ")" statement "else" statement : selection_statement
syntax "switch" "(" expression ")" statement : selection_statement
syntax "`[selection_statement| " selection_statement "]" : term

-- iteration statement
syntax "while" "(" expression ")" statement : iteration_statement
syntax "do" statement "while" "(" expression ")" ";" : iteration_statement
syntax "for" "(" expression_statement expression_statement ")" statement : iteration_statement
syntax "for" "(" expression_statement expression_statement expression_statement ")" statement : iteration_statement
syntax "`[iteration_statement| " iteration_statement "]" : term

-- jump statement
syntax "goto" ident ";" : jump_statement
syntax "continue" ";" : jump_statement
syntax "break" ";" : jump_statement
syntax "return" ";" : jump_statement
syntax "return" expression ";" : jump_statement
syntax "`[jump_statement| " jump_statement "]" : term

-- labelled statement
syntax ident ":" statement : labeled_statement
syntax "case" constant_expression ":" statement_list : labeled_statement
syntax "default" ":" statement : labeled_statement
syntax "`[labeled_statement| " labeled_statement "]" : term

-- compound statement
syntax "{" "}" : compound_statement
syntax "{" statement_list "}" : compound_statement
syntax "{" declaration_list "}" : compound_statement
syntax "{" declaration_list statement_list "}" : compound_statement
syntax "`[compound_statement| " compound_statement "]" : term

-- statement
syntax labeled_statement : statement
syntax compound_statement : statement
syntax expression_statement : statement
syntax selection_statement : statement
syntax iteration_statement : statement
syntax jump_statement : statement
syntax "`[statement| " statement "]" : term

-- statement list
syntax statement : statement_list
syntax statement_list statement : statement
syntax "`[statement_list| " statement_list "]" : term