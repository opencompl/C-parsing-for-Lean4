import Lake
open Lake DSL

package cParser {
  -- add package configuration options here
}

lean_lib CParser {
  -- add library configuration options here
}

@[default_target]
lean_exe cParser {
  supportInterpreter := true,
  root := `Main
}
