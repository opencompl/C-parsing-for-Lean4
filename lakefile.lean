import Lake
open Lake DSL

package «CParser» {
  -- add configuration options here
  supportInterpreter := true
  libName := "CParser"
  binRoot := `CParser
  libRoots := #[`CParser] 
}
