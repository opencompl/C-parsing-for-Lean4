import Lean.Parser.LeanToken

open Lean Parser

namespace CParser

abbrev cCharLitKind : SyntaxNodeKind := `cchar

@[specialize]
def pushToken (f : Substring → SourceInfo → Syntax) (startPos : String.Pos) (whitespaceFn : TokenParserFn) :
    TokenParserFn := fun c s => Id.run do
  if s.hasError then
    return s
  let input     := c.input
  let stopPos   := s.pos
  let leading   := mkEmptySubstringAt input startPos
  let rawVal    := { str := input, startPos := startPos, stopPos := stopPos  : Substring }
  let s         := whitespaceFn c s
  let wsStopPos := s.pos
  let trailing  := { str := input, startPos := stopPos, stopPos := wsStopPos : Substring }
  let info      := SourceInfo.original leading startPos trailing stopPos
  -- dbg_trace rawVal
  -- dbg_trace leading
  -- dbg_trace wsStopPos
  -- dbg_trace stopPos
  -- used dbg_trace on the variables and found that these aren't the ones causing a problem either
  s.pushSyntax (f rawVal info)

partial def whitespace : TokenParserFn := fun c s =>
  s
  -- let input := c.input
  -- let i     := s.pos
  -- if input.atEnd i then s
  -- else
  --   let curr := input.get i
  --   if curr.isWhitespace then whitespace c (s.next input i)
  --   else if curr == '/' then
  --     let i    := input.next i
  --     let curr := input.get i
  --     if curr == '/' then andthenTokenFn (takeUntilFn (fun c => c = '\n')) whitespace c (s.next input i)
  --     else if curr == '*' then
  --       let i    := input.next i
  --       andthenTokenFn (finishCommentBlock 1) whitespace c (s.next input i)
  --     else s
  --   else s

def isQuotableCharDefault (c : Char) : Bool := "\\\"'rntabefv?0".contains c || c.isDigit

def cCharLitFn : ParserFn := fun c s =>
  dbg_trace "CALLED"
  let initStackSz := s.stackSize
  let iniPos := s.pos
  let s := tokenFn ["char literal"] c s
  if !s.hasError && !(s.stxStack.back.isOfKind cCharLitKind) then s.mkErrorAt "character literal" iniPos initStackSz else s

-- Needed
def cCharLitFnAux (startPos : String.Pos) : TokenParserFn := fun c s =>
  let input := c.input
  let i     := s.pos
  if h : input.atEnd i then s.mkEOIError
  else
    let s    := s.setPos (input.next' i h)
    if s.hasError then s
    else
      let i    := s.pos
      let curr := input.get i
      let s    := s.setPos (input.next i)
      if curr == '\'' then mkNodeToken cCharLitKind startPos whitespace c s
      else s.mkUnexpectedError "missing end of character literal"

def isIdCont : String → ParserState → Bool := fun input s =>
  let i    := s.pos
  let curr := input.get i
  if curr == '.' then
    let i := input.next i
    if input.atEnd i then
      false
    else
      let curr := input.get i
      isIdFirst curr || isIdBeginEscape curr
  else
    false

private def isToken (idStartPos idStopPos : String.Pos) (tk : Option Token) : Bool :=
  -- true
  match tk with
  | none    => false
  | some tk =>
     -- if a token is both a symbol and a valid identifier (i.e. a keyword),
     -- we want it to be recognized as a symbol
    tk.endPos ≥ idStopPos - idStartPos

-- Note: This is causing the problem maybe
-- On further analysis, it appears that this is not causing the problem
def mkTokenAndFixPos (startPos : String.Pos) (tk : Option Token) : TokenParserFn := fun c s =>
  match tk with
  | none    => s.mkErrorAt "token" startPos
  | some tk =>
    if c.forbiddenTk? == some tk then
      s.mkErrorAt "forbidden token" startPos
    else
      let stopPos := startPos + tk
      -- dbg_trace startPos    -- char: 1      void: 1 
      -- dbg_trace stopPos     -- char: 5      void: 5
      -- dbg_trace tk          -- char: char   int: void
      -- These dbg_traces are consistent for char and void, yet void throws an error and char does not
      -- So this should not be causing the problem
      let s       := s.setPos stopPos
      pushToken (fun _ info => mkAtom info tk) startPos whitespace c s

def mkIdResult (startPos : String.Pos) (tk : Option Token) (val : Name) : TokenParserFn := fun c s =>
  let stopPos           := s.pos
  -- Note: isToken is true for char (as it should be)
  if isToken startPos stopPos tk then
    mkTokenAndFixPos startPos tk c s
  else
    pushToken (fun ss info => mkIdent info ss val) startPos whitespace c s

-- Needed
partial def identFnAux (startPos : String.Pos) (tk : Option Token) (r : Name) : TokenParserFn :=
  let rec parse (r : Name) (c s) :=
    let input := c.input
    let i     := s.pos
    if h : input.atEnd i then
      s.mkEOIError
    else
      let curr := input.get' i h
      if isIdBeginEscape curr then
        let startPart := input.next' i h
        let s         := takeUntilFn isIdEndEscape c (s.setPos startPart)
        if h : input.atEnd s.pos then
          s.mkUnexpectedErrorAt "unterminated identifier escape" startPart
        else
          let stopPart  := s.pos
          let s         := s.next' c.input s.pos h
          let r := .str r (input.extract startPart stopPart)
          if isIdCont input s then
            let s := s.next input s.pos
            parse r c s
          else
            -- dbg_trace startPos
            -- This is not the one being called
            mkIdResult startPos tk r c s
      else if isIdFirst curr then
        let startPart := i
        let s         := takeWhileFn (λ c => c.isAlphanum || c = '_') c (s.next input i)
        let stopPart  := s.pos
        let r := .str r (input.extract startPart stopPart)
        if isIdCont input s then
          let s := s.next input s.pos
          parse r c s
        else
          -- dbg_trace startPos
          -- dbg_trace tk
          -- dbg_trace r
          -- These are fine as well
          mkIdResult startPos tk r c s
      else
        mkTokenAndFixPos startPos tk c s
  parse r

private def isIdFirstOrBeginEscape (c : Char) : Bool :=
  isIdFirst c || isIdBeginEscape c

def tokenFnCore : TokenParserFn := fun c s =>
  let input := c.input
  let i     := s.pos
  let curr  := input.get i
  if curr == '\'' && getNext input i != '\'' then
    cCharLitFnAux i c (s.next input i)
  else
    let (_, tk) := c.tokens.matchPrefix input i
    -- dbg_trace i
    -- dbg_trace tk
    -- These don't have a problem either
    identFnAux i tk .anonymous c s
