import KProgFormal.ClightRefinement.Arm64ProgramEntryAddRegisterAdmission
import KProgFormal.ClightRefinement.Arm64AddRegisterNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMulAdmission
open Arm64ProgramEntryAddAdmission (afterPair)
open Arm64ProgramEntryAddRegisterAdmission (afterThree)

/-- The four actual imported reference transitions preceding the fifth word. -/
def afterFour (s : Reference.AArch64.State) : Reference.AArch64.State :=
  (Reference.AArch64.step (afterThree s)).state

/-- Transport the original fifth fetch through actual MOV/MOVK/ADD/ADD-register native
steps; no fetched/error premise at a synthetic successor is supplied. -/
theorem next_admission (s : Reference.AArch64.State)
    (first keep third fourth fifth : Reference.AArch64.Instruction) (mark priority : BitVec 32)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 ((priority.setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding) :
    read_pc (afterFour s).machine = read_pc s.machine + 16#64 ∧
    read_err (afterFour s).machine = .None ∧
    fetch_inst (read_pc (afterFour s).machine) (afterFour s).machine = some fifth.encoding := by
  have admitted := Arm64ProgramEntryAddRegisterAdmission.next_admission s first keep third fourth
    mark priority imm column negate literal firstDecoded keepDecoded thirdDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched
  have pairAdmission := Arm64ProgramEntryAddAdmission.next_admission s first keep third
    mark priority imm column negate literal firstDecoded keepDecoded noError firstFetched keepFetched thirdFetched
  have pairStep := Arm64MovPairNative.steps s first keep mark priority imm column negate literal
    firstDecoded keepDecoded noError firstFetched keepFetched
  have actualPair : afterPair s = Arm64Nop.atCursor (read_pc s.machine + 8#64)
      (Arm64RegisterWrite.nativeUpdate (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)
        1 (Arm64MovKeep.mergeWord (mark.setWidth 64) (priority.setWidth 64) 1) false) :=
    by unfold afterPair; rw [pairStep.2]
  have thirdStep := Arm64AddImmediate.Native.reference_step (afterPair s) third 2 (16#12) false
    thirdDecoded pairAdmission.2.1 pairAdmission.2.2
  have fourthStep := Arm64AddRegisterNative.reference_step (afterThree s) fourth
    fourthDecoded admitted.2.1 admitted.2.2
  have pc : read_pc (afterFour s).machine = read_pc s.machine + 16#64 := by
    simp only [afterFour, fourthStep]
    simp only [Arm64Nop.atCursor, read_pc, write_pc, r_of_w_same]
    change read_pc (afterThree s).machine + 4#64 = read_pc s.machine + 16#64
    rw [admitted.1, BitVec.add_assoc]
    rfl
  have error : read_err (afterFour s).machine = .None := by
    simp only [afterFour, fourthStep]
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different]
      using admitted.2.1
  have program : (afterFour s).machine.program = s.machine.program := by
    unfold afterFour
    rw [fourthStep]
    simp only [afterThree]
    rw [thirdStep]
    rw [actualPair]
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, write_pc, w, write_base_pc, write_base_gpr]
  exact ⟨pc, error, by simpa only [fetch_inst, pc, program] using fifthFetched⟩

/-- Architectural input-view setup preserves original fifth-word admission. -/
theorem setup_next (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32) (first keep third fourth fifth : Reference.AArch64.Instruction)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding) :
    read_pc (afterFour (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = read_pc s.machine + 16#64 ∧
    read_err (afterFour (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = .None ∧
    fetch_inst (read_pc (afterFour (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine)
      (afterFour (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = some fifth.encoding := by
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
  have f5 : fetch_inst (read_pc setup.machine + 16#64) setup.machine = some fifth.encoding := by
    rw [pc]
    simpa only [fetch_inst, program] using fifthFetched
  have result := next_admission setup first keep third fourth fifth (fields 0) (fields 1) imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded error f1 f2 f3 f4 f5
  exact ⟨result.1.trans (congrArg (fun cursor => cursor + 16#64) pc), result.2⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryMulAdmission
