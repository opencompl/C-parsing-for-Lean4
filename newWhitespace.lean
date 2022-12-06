import Lean.Parser.Types

/- Replace the functions (of the same names) 
   with the following definitions in
   lean4/src/Lean/Parser/Basic.lean -/

partial def finishCommentBlock (nesting : Nat) : ParserFn := fun c s =>
  let input := c.input
  let i     := s.pos
  if input.atEnd i then eoi s
  else
    let curr := input.get i
    let i    := input.next i
    if curr == '*' then
      if input.atEnd i then eoi s
      else
        let curr := input.get i
        if curr == '/' then -- "-/" end of comment
          if nesting == 1 then s.next input i
          else finishCommentBlock (nesting-1) c (s.next input i)
        else
          finishCommentBlock nesting c (s.next input i)
    else if curr == '/' then
      if input.atEnd i then eoi s
      else
        let curr := input.get i
        if curr == '*' then finishCommentBlock (nesting+1) c (s.next input i)
        else finishCommentBlock nesting c (s.setPos i)
    else finishCommentBlock nesting c (s.setPos i)
where
  eoi s := s.mkUnexpectedError "unterminated comment"

partial def whitespace : ParserFn := fun c s =>
  let input := c.input
  let i     := s.pos
  if input.atEnd i then s
  else
    let curr := input.get i
    if curr.isWhitespace then whitespace c (s.next input i)
    else if curr == '/' then
      let i    := input.next i
      let curr := input.get i
      if curr == '/' then andthenFn (takeUntilFn (fun c => c = '\n')) whitespace c (s.next input i)
      else if curr == '*' then
        let i    := input.next i
        andthenFn (finishCommentBlock 1) whitespace c (s.next input i)
      else s
    else s
