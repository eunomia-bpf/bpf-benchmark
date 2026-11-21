import KProgFormal.ClightRefinement.Arm64MovPairNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryBodyView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAddAdmission

/-- The actual two imported reference transitions, not a second ISA evaluator. -/
def afterPair (s : Reference.AArch64.State) : Reference.AArch64.State :=
  (Reference.AArch64.step (Reference.AArch64.step s).state).state

/-- Derive the successor fetch, PC and error facts through the two genuine
checked MOV words. The third fetch is supplied only in the original program. -/
theorem next_admission (s : Reference.AArch64.State)
    (first keep third : Reference.AArch64.Instruction) (mark priority : BitVec 32)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 ((priority.setWidth 64).setWidth 16) 1 false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding) :
    read_pc (afterPair s).machine = read_pc s.machine + 8#64 ∧
    read_err (afterPair s).machine = .None ∧
    fetch_inst (read_pc (afterPair s).machine) (afterPair s).machine = some third.encoding := by
  have checked := Arm64MovPairNative.steps s first keep mark priority imm column negate literal
    firstDecoded keepDecoded noError firstFetched keepFetched
  have actual : afterPair s = Arm64Nop.atCursor (read_pc s.machine + 8#64)
      (Arm64RegisterWrite.nativeUpdate (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)
        1 (Arm64MovKeep.mergeWord (mark.setWidth 64) (priority.setWidth 64) 1) false) :=
    by unfold afterPair; rw [checked.2]
  have pc : read_pc (afterPair s).machine = read_pc s.machine + 8#64 := by
    rw [actual]
    simp [Arm64Nop.atCursor, read_pc, write_pc, r_of_w_same]
  have error : read_err (afterPair s).machine = .None := by
    rw [actual]
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different] using noError
  refine ⟨pc, error, ?_⟩
  rw [pc, actual]
  simpa [fetch_inst, Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, write_pc, w,
    write_base_pc, write_base_gpr] using thirdFetched

/-- Architectural input-view setup preserves program/PC/error. It supplies no
fictional native setup instructions and adds no successor-state admission. -/
theorem setup_next (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32) (first keep third : Reference.AArch64.Instruction)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding) :
    read_pc (afterPair (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = read_pc s.machine + 8#64 ∧
    read_err (afterPair (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = .None ∧
    fetch_inst (read_pc (afterPair (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine)
      (afterPair (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = some third.encoding := by
  let setup := Arm64ProgramEntryBodyView.nativeSetup s origins fields
  have pc : read_pc setup.machine = read_pc s.machine :=
    Arm64ProgramEntryBodyView.native_other s origins fields .PC (by intro equal; cases equal)
      (by intro flag equal; cases equal)
  have error : read_err setup.machine = .None :=
    (Arm64ProgramEntryBodyView.native_other s origins fields .ERR (by intro equal; cases equal)
      (by intro flag equal; cases equal)).trans noError
  have program : setup.machine.program = s.machine.program :=
    (Arm64ProgramEntryBodyView.native_resources s origins fields).2.1
  have f1 : fetch_inst (read_pc setup.machine) setup.machine = some first.encoding := by
    rw [pc]
    simpa only [fetch_inst, program] using firstFetched
  have f2 : fetch_inst (read_pc setup.machine + 4#64) setup.machine = some keep.encoding := by
    rw [pc]
    simpa only [fetch_inst, program] using keepFetched
  have f3 : fetch_inst (read_pc setup.machine + 8#64) setup.machine = some third.encoding := by
    rw [pc]
    simpa only [fetch_inst, program] using thirdFetched
  have result := next_admission setup first keep third (fields 0) (fields 1) imm column negate
    literal firstDecoded keepDecoded error f1 f2 f3
  exact ⟨result.1.trans (congrArg (fun cursor => cursor + 8#64) pc), result.2⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryAddAdmission
