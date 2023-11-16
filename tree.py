# First run
#sed -ik -r '/#.*/d ; /^\s*$/d' shell_input.c
#sed -ik -r '/#.*/d ; /^\s*$/d' shell_output.c


from tree_sitter import Language, Parser

def p(t, i, f):
  if t.type in ['char_literal', 'string_literal', 'concatenated_string', ',', 'comment', 'ERROR', 'identifier']:
    return
  f.write("".join(' ' for _ in range(i)) + "(" + t.type + "\n")
  for c in t.children:
    p(c, i+2, f)
  f.write("".join(' ' for _ in range(i)) + ")" + "\n")

Language.build_library(
    # Store the library in the `build` directory
    "build/my-languages.so",
    # Include one or more languages
    ["/Users/abhinavmenon/tree-sitter-c"])

C_LANGUAGE = Language("build/my-languages.so", "c")

parser = Parser()
parser.set_language(C_LANGUAGE)

file = 'sqlite'

with open(f'{file}_input.c', 'r') as f:
  tree = parser.parse(bytes(f.read(), 'utf-8'))
  with open(f'{file}_input_sexp.txt', 'w') as g:
    p(tree.root_node, 0, g)

with open(f'{file}_output.c', 'r') as f:
  tree = parser.parse(bytes(f.read(), 'utf-8'))
  with open(f'{file}_output_sexp.txt', 'w') as g:
    p(tree.root_node, 0, g)
