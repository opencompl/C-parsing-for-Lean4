import CParser.Parser.ParseFuncs

elab "#parse " fileNameStx:str "as " cat:ident : command =>
  open Lean Lean.Elab Command in
  do
     let filename := fileNameStx.getString
     let fileStrIO <- IO.FS.readFile filename
     let res := Parser.runParserCategory (← getEnv) cat.getId fileStrIO "<input>"
     logInfo s!"{res}"
