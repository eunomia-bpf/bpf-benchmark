import KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryCmpView

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryCodeAdmission

/-- Actual fetch observes the same original program at every physical cursor. -/
theorem fetch_same (source target : Reference.AArch64.State)
    (program : target.machine.program = source.machine.program) (cursor : BitVec 64) :
    fetch_inst cursor target.machine = fetch_inst cursor source.machine := by
  simp only [fetch_inst,program]

/-- Every actual BL/RET/continuation decoder/fetch certificate transports on
same program and PC. Arbitrary data, flags and other machine fields remain
those of the real target state, rather than an invented instruction update. -/
def transport (source target : Reference.AArch64.State) (offset : BitVec 26)
    (admitted : Arm64ProgramEntryLinkReturnNative.Admission source offset)
    (program : target.machine.program = source.machine.program)
    (pc : read_pc target.machine = read_pc source.machine) :
    Arm64ProgramEntryLinkReturnNative.Admission target offset where
  call := admitted.call
  decoded := admitted.decoded
  callFetched := by rw [pc,fetch_same source target program]; exact admitted.callFetched
  calleeFetched := by rw [pc,fetch_same source target program]; exact admitted.calleeFetched
  continuation := admitted.continuation
  continuationFetched := by rw [pc,fetch_same source target program]; exact admitted.continuationFetched

theorem same_call (source target : Reference.AArch64.State) (offset : BitVec 26)
    (admitted : Arm64ProgramEntryLinkReturnNative.Admission source offset)
    (program : target.machine.program = source.machine.program)
    (pc : read_pc target.machine = read_pc source.machine) :
    (transport source target offset admitted program pc).call = admitted.call := rfl

theorem same_continuation (source target : Reference.AArch64.State) (offset : BitVec 26)
    (admitted : Arm64ProgramEntryLinkReturnNative.Admission source offset)
    (program : target.machine.program = source.machine.program)
    (pc : read_pc target.machine = read_pc source.machine) :
    (transport source target offset admitted program pc).continuation = admitted.continuation := rfl

/-- Original NZCV/X3/X4 provider observations preserve the complete program. -/
theorem input_program (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) :
    (Arm64ProgramEntryPostMemoryCmpView.native s gprs flags).machine.program = s.machine.program := by
  simp [Arm64ProgramEntryPostMemoryCmpView.native,Arm64ProgramEntryTbnzCall.native,
    Arm64ProgramEntryCbzCall.native,Arm64ClobberNativeFlags.native,write_pstate,make_pstate,w,write_base_flag,write_base_gpr]

/-- Both genuine compare and B.GT state updates preserve that actual code. -/
theorem branch_program (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64)
    (offset : BitVec 19) :
    (Arm64ProgramEntryCmpBgtNative.after (Arm64ProgramEntryPostMemoryCmpView.native s gprs flags) offset).machine.program =
      s.machine.program := by
  have branch := Arm64ProgramEntryJccNative.resources
    (Arm64ProgramEntryCmpNative.after (Arm64ProgramEntryPostMemoryCmpView.native s gprs flags)) (12#4) offset
  exact branch.2.1.trans ((Arm64ProgramEntryCmpNative.resources _).2.1.trans (input_program s gprs flags))

/-- Keep a source label's actual native cursor with the original code. -/
theorem cursor_program (s : Reference.AArch64.State) (cursor : BitVec 64) :
    (Arm64Nop.atCursor cursor s).machine.program = s.machine.program := by
  simp [Arm64Nop.atCursor,write_pc,w,write_base_pc]

theorem cursor_pc (s : Reference.AArch64.State) (cursor : BitVec 64) :
    read_pc (Arm64Nop.atCursor cursor s).machine = cursor := by
  simp [Arm64Nop.atCursor,write_pc,read_pc,r_of_w_same]

end KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryCodeAdmission
