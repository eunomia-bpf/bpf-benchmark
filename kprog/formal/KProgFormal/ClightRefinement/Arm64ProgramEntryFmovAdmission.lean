import KProgFormal.ClightRefinement.Arm64ProgramEntryCnegAdmission
import KProgFormal.ClightRefinement.Arm64CnegNative

import KProgFormal.ClightRefinement.Arm64ProgramEntryOrnAdmission
import KProgFormal.ClightRefinement.Arm64OrnNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryFmovAdmission
open Arm64ProgramEntryAddAdmission (afterPair)
open Arm64ProgramEntryAddRegisterAdmission (afterThree)
open Arm64ProgramEntryMulAdmission (afterFour)
open Arm64ProgramEntryCompareAdmission (afterFive)
open Arm64ProgramEntrySelectAdmission (afterSix)

open Arm64ProgramEntryCnegAdmission (afterSeven)

open Arm64ProgramEntryOrnAdmission (afterEight)

/-- Nine actual imported transitions reach the original tenth FMOV word. -/
def afterNine (s : Reference.AArch64.State) : Reference.AArch64.State :=
  (Reference.AArch64.step (afterEight s)).state

/-- Transport PC, error and tenth fetch through nine genuine preceding
steps, retaining the original program and decoder admission premises. -/
theorem next_admission (s : Reference.AArch64.State)
    (first keep third fourth fifth sixth seventh eighth ninth tenth : Reference.AArch64.Instruction) (mark priority : BitVec 32)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 ((priority.setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (fifthDecoded : fifth.decoded = .DPR (.Data_processing_three_source Arm64Mul.Native.fields))
    (sixthDecoded : sixth.decoded = .DPR (.Add_sub_shifted_reg Arm64Compare.Native.fields))
    (seventhDecoded : seventh.decoded = .DPR (.Conditional_select (Arm64Select.Native.fields 5 1 2 (0#4))))
    (eighthDecoded : eighth.decoded = .DPR (.Conditional_select Arm64Cneg.Native.fields))
    (ninthDecoded : ninth.decoded = .DPR (.Logical_shifted_reg Arm64Orn.Native.fields))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding)
    (sixthFetched : fetch_inst (read_pc s.machine + 20#64) s.machine = some sixth.encoding)
    (seventhFetched : fetch_inst (read_pc s.machine + 24#64) s.machine = some seventh.encoding)
    (eighthFetched : fetch_inst (read_pc s.machine + 28#64) s.machine = some eighth.encoding)
    (ninthFetched : fetch_inst (read_pc s.machine + 32#64) s.machine = some ninth.encoding)
    (tenthFetched : fetch_inst (read_pc s.machine + 36#64) s.machine = some tenth.encoding) :
    read_pc (afterNine s).machine = read_pc s.machine + 36#64 ∧
    read_err (afterNine s).machine = .None ∧
    fetch_inst (read_pc (afterNine s).machine) (afterNine s).machine = some tenth.encoding := by
  have admitted := Arm64ProgramEntryMulAdmission.next_admission s first keep third fourth fifth
    mark priority imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched
  have fourthAdmission := Arm64ProgramEntryAddRegisterAdmission.next_admission s first keep third fourth
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
    fourthDecoded fourthAdmission.2.1 fourthAdmission.2.2
  have fifthStep := Arm64Mul.Native.reference_step (afterFour s) fifth
    fifthDecoded admitted.2.1 admitted.2.2
  have sixthAdmission := Arm64ProgramEntryCompareAdmission.next_admission s first keep third fourth fifth sixth
    mark priority imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded
    noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched
  have sixthStep := Arm64Compare.Native.reference_step (afterFive s) sixth sixthDecoded
    sixthAdmission.2.1 sixthAdmission.2.2
  have pc : read_pc (afterSix s).machine = read_pc s.machine + 24#64 := by
    unfold afterSix
    rw [sixthStep]
    simp +decide only [Arm64Compare.Native.after,read_pc,write_pstate,write_pc,r_of_w_different,r_of_w_same]
    change read_pc (afterFive s).machine + 4#64 = read_pc s.machine + 24#64
    rw [sixthAdmission.1,BitVec.add_assoc]
    rfl
  have error : read_err (afterSix s).machine = .None := by
    unfold afterSix
    rw [sixthStep]
    simpa [Arm64Compare.Native.after,read_err,write_pstate,write_pc,r_of_w_different] using sixthAdmission.2.1
  have programFive : (afterFive s).machine.program = s.machine.program := by
    unfold afterFive
    rw [fifthStep]
    simp only [afterFour]
    rw [fourthStep]
    simp only [afterThree]
    rw [thirdStep, actualPair]
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, write_pc, w, write_base_pc, write_base_gpr]
  have program : (afterSix s).machine.program = s.machine.program := by
    unfold afterSix
    rw [sixthStep]
    simpa [Arm64Compare.Native.after,write_pstate,write_pc,w,write_base_pc,write_base_flag] using programFive
  have seventhRead : fetch_inst (read_pc (afterSix s).machine) (afterSix s).machine = some seventh.encoding := by
    simpa only [fetch_inst,pc,program] using seventhFetched
  have seventhStep := Arm64Select.Native.reference_step (afterSix s) seventh 5 1 2 (0#4)
    seventhDecoded error seventhRead
  have nextPc : read_pc (afterSeven s).machine = read_pc s.machine + 28#64 := by
    unfold afterSeven
    rw [seventhStep]
    simp only [Arm64Nop.atCursor,read_pc,write_pc,r_of_w_same]
    change read_pc (afterSix s).machine + 4#64 = _
    rw [pc,BitVec.add_assoc]
    rfl
  have nextError : read_err (afterSeven s).machine = .None := by
    unfold afterSeven
    rw [seventhStep]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,read_err,write_pc,r_of_w_different] using error
  have nextProgram : (afterSeven s).machine.program = s.machine.program := by
    unfold afterSeven
    rw [seventhStep]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,write_pc,w,write_base_pc,write_base_gpr] using program
  have eighthRead : fetch_inst (read_pc (afterSeven s).machine) (afterSeven s).machine = some eighth.encoding := by
    simpa only [fetch_inst,nextPc,nextProgram] using eighthFetched
  have eighthStep := Arm64Cneg.Native.reference_step (afterSeven s) eighth eighthDecoded nextError eighthRead
  have finalPc : read_pc (afterEight s).machine = read_pc s.machine + 32#64 := by
    unfold afterEight
    rw [eighthStep]
    simp only [Arm64Nop.atCursor,read_pc,write_pc,r_of_w_same]
    change read_pc (afterSeven s).machine + 4#64 = _
    rw [nextPc,BitVec.add_assoc]
    rfl
  have finalError : read_err (afterEight s).machine = .None := by
    unfold afterEight
    rw [eighthStep]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,read_err,write_pc,r_of_w_different] using nextError
  have finalProgram : (afterEight s).machine.program = s.machine.program := by
    unfold afterEight
    rw [eighthStep]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,write_pc,w,write_base_pc,write_base_gpr] using nextProgram
  have ninthRead : fetch_inst (read_pc (afterEight s).machine) (afterEight s).machine = some ninth.encoding := by
    simpa only [fetch_inst,finalPc,finalProgram] using ninthFetched
  have ninthStep := Arm64Orn.Native.reference_step (afterEight s) ninth ninthDecoded finalError ninthRead
  have tenthPc : read_pc (afterNine s).machine = read_pc s.machine + 36#64 := by
    unfold afterNine
    rw [ninthStep]
    simp only [Arm64Nop.atCursor,read_pc,write_pc,r_of_w_same]
    change read_pc (afterEight s).machine + 4#64 = _
    rw [finalPc,BitVec.add_assoc]
    rfl
  have tenthError : read_err (afterNine s).machine = .None := by
    unfold afterNine
    rw [ninthStep]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,read_err,write_pc,r_of_w_different] using finalError
  have tenthProgram : (afterNine s).machine.program = s.machine.program := by
    unfold afterNine
    rw [ninthStep]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,write_pc,w,write_base_pc,write_base_gpr] using finalProgram
  exact ⟨tenthPc,tenthError,by simpa only [fetch_inst,tenthPc,tenthProgram] using tenthFetched⟩

/-- Architectural input-view setup preserves original tenth-word admission. -/
theorem setup_next (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32) (first keep third fourth fifth sixth seventh eighth ninth tenth : Reference.AArch64.Instruction)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (fields 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((fields 1).setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (fifthDecoded : fifth.decoded = .DPR (.Data_processing_three_source Arm64Mul.Native.fields))
    (sixthDecoded : sixth.decoded = .DPR (.Add_sub_shifted_reg Arm64Compare.Native.fields))
    (seventhDecoded : seventh.decoded = .DPR (.Conditional_select (Arm64Select.Native.fields 5 1 2 (0#4))))
    (eighthDecoded : eighth.decoded = .DPR (.Conditional_select Arm64Cneg.Native.fields))
    (ninthDecoded : ninth.decoded = .DPR (.Logical_shifted_reg Arm64Orn.Native.fields))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding)
    (sixthFetched : fetch_inst (read_pc s.machine + 20#64) s.machine = some sixth.encoding)
    (seventhFetched : fetch_inst (read_pc s.machine + 24#64) s.machine = some seventh.encoding)
    (eighthFetched : fetch_inst (read_pc s.machine + 28#64) s.machine = some eighth.encoding)
    (ninthFetched : fetch_inst (read_pc s.machine + 32#64) s.machine = some ninth.encoding)
    (tenthFetched : fetch_inst (read_pc s.machine + 36#64) s.machine = some tenth.encoding) :
    read_pc (afterNine (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = read_pc s.machine + 36#64 ∧
    read_err (afterNine (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = .None ∧
    fetch_inst (read_pc (afterNine (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine)
      (afterNine (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = some tenth.encoding := by
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
  have f6 : fetch_inst (read_pc setup.machine + 20#64) setup.machine = some sixth.encoding := by
    rw [pc]
    simpa only [fetch_inst, program] using sixthFetched
  have f7 : fetch_inst (read_pc setup.machine + 24#64) setup.machine = some seventh.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using seventhFetched
  have f8 : fetch_inst (read_pc setup.machine + 28#64) setup.machine = some eighth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using eighthFetched
  have f9 : fetch_inst (read_pc setup.machine + 32#64) setup.machine = some ninth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using ninthFetched
  have f10 : fetch_inst (read_pc setup.machine + 36#64) setup.machine = some tenth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using tenthFetched
  have result := next_admission setup first keep third fourth fifth sixth seventh eighth ninth tenth (fields 0) (fields 1) imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded error f1 f2 f3 f4 f5 f6 f7 f8 f9 f10
  exact ⟨result.1.trans (congrArg (fun cursor => cursor + 36#64) pc),result.2⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryFmovAdmission
