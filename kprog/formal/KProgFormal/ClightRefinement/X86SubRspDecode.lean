import KProgFormal.Reference.X86

namespace KProgFormal.ClightRefinement.X86SubRspDecode

/-- Concrete qword SUB RSP,32 through the SAME native decoder. Signed imm8
and actual four-byte fall-through are decoder outputs, not supplied results.
Binding these bytes to a producer/native artifact is a separate obligation. -/
theorem decode (state : Reference.X86.State) :
    Reference.X86.decode #[(0x48 : Reference.Byte),0x83,0xec,0x20] state =
      .ok (.arithmetic .w64 .sub (.register (.low 4)) (.immediate 32) (state.pc + 4)) := by
  canonical_x86_decode

end KProgFormal.ClightRefinement.X86SubRspDecode
