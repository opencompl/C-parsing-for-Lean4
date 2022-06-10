import Lake
open Lake DSL

package «CParser» {
  -- add configuration options here
  supportInterpreter := true
  libName := "CParser"
  binRoot := `Main
  libRoots := #[`CParser] 
}
