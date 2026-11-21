import KProgFormal.ClightRefinement.Arm64ProgramEntryAddAdmission
import KProgFormal.ClightRefinement.Arm64AddImmediateNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterAdmission
open Arm64ProgramEntryAddAdmission (afterPair)

/-- The three actual imported reference transitions preceding the fourth word. -/
def afterThree (s : Reference.AArch64.State) : Reference.AArch64.State :=
  (Reference.AArch64.step (afterPair s)).state

/-- Transport the original fourth fetch through actual MOV/MOVK/ADD native
steps; no fetched/error premise at a synthetic successor is supplied. -/
theorem next_admission (s : Reference.AArch64.State)
    (first keep third fourth : Reference.AArch64.Instruction) (mark priority : BitVec 32)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 ((priority.setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding) :
    read_pc (afterThree s).machine = read_pc s.machine + 12#64 ∧
    read_err (afterThree s).machine = .None ∧
    fetch_inst (read_pc (afterThree s).machine) (afterThree s).machine = some fourth.encoding := by
  have admitted := Arm64ProgramEntryAddAdmission.next_admission s first keep third mark priority imm column negate
    literal firstDecoded keepDecoded noError firstFetched keepFetched thirdFetched
  have checked := Arm64MovPairNative.steps s first keep mark priority imm column negate literal
    firstDecoded keepDecoded noError firstFetched keepFetched
  have actual : afterPair s = Arm64Nop.atCursor (read_pc s.machine + 8#64)
      (Arm64RegisterWrite.nativeUpdate (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)
        1 (Arm64MovKeep.mergeWord (mark.setWidth 64) (priority.setWidth 64) 1) false) :=
    by unfold afterPair; rw [checked.2]
  have nativeStep := Arm64AddImmediate.Native.reference_step (afterPair s) third 2 (16#12) false
    thirdDecoded admitted.2.1 admitted.2.2
  have pc : read_pc (afterThree s).machine = read_pc s.machine + 12#64 := by
    simp only [afterThree, nativeStep]
    simp only [Arm64Nop.atCursor, read_pc, write_pc, r_of_w_same]
    change read_pc (afterPair s).machine + 4#64 = read_pc s.machine + 12#64
    rw [admitted.1, BitVec.add_assoc]
    rfl
  have error : read_err (afterThree s).machine = .None := by
    simp only [afterThree, nativeStep]
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different]
      using admitted.2.1
  have program : (afterThree s).machine.program = s.machine.program := by
    simp only [afterThree, nativeStep]
    rw [actual]
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, write_pc, w, write_base_pc, write_base_gpr]
  exact ⟨pc, error, by simpa only [fetch_inst, pc, program] using fourthFetched⟩

/-- Architectural input-view setup preserves original fourth-word admission. -/
theorem setup_next (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32) (first keep third fourth : Reference.AArch64.Instruction)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding) :
    read_pc (afterThree (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = read_pc s.machine + 12#64 ∧
    read_err (afterThree (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = .None ∧
    fetch_inst (read_pc (afterThree (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine)
      (afterThree (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = some fourth.encoding := by
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
  have f4 : fetch_inst (read_pc setup.machine + 12#64) setup.machine = some fourth.encoding := by
    rw [pc]
    simpa only [fetch_inst, program] using fourthFetched
  have result := next_admission setup first keep third fourth (fields 0) (fields 1) imm column negate
    literal firstDecoded keepDecoded thirdDecoded error f1 f2 f3 f4
  exact ⟨result.1.trans (congrArg (fun cursor => cursor + 12#64) pc), result.2⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterAdmission
