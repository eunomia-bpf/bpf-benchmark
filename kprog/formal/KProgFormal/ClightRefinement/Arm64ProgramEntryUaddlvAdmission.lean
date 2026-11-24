import KProgFormal.ClightRefinement.Arm64ProgramEntryCntAdmission
import KProgFormal.ClightRefinement.Arm64CntNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvAdmission

open Arm64ProgramEntryCntAdmission (afterTen)

/-- Eleven genuine imported steps reach the original twelfth UADDLV word. -/
def afterEleven (s : Reference.AArch64.State) : Reference.AArch64.State :=
  (Reference.AArch64.step (afterTen s)).state

/-- The original eleventh CNT step transports PC, error, code and twelfth fetch. -/
theorem next_admission (s : Reference.AArch64.State)
    (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth : Reference.AArch64.Instruction) (mark priority : BitVec 32)
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
    (tenthDecoded : tenth.decoded = .DPSFP (.Conversion_between_FP_and_Int Arm64Fmov.Native.fields))
    (eleventhDecoded : eleventh.decoded = .DPSFP (.Advanced_simd_two_reg_misc Arm64Cnt.Native.fields))
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
    (tenthFetched : fetch_inst (read_pc s.machine + 36#64) s.machine = some tenth.encoding)
    (eleventhFetched : fetch_inst (read_pc s.machine + 40#64) s.machine = some eleventh.encoding)
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding) :
    read_pc (afterEleven s).machine = read_pc s.machine + 44#64 ∧
    read_err (afterEleven s).machine = .None ∧
    fetch_inst (read_pc (afterEleven s).machine) (afterEleven s).machine = some twelfth.encoding := by
  have previous := Arm64ProgramEntryCntAdmission.admission_with_program s first keep third fourth fifth sixth seventh eighth ninth tenth eleventh mark priority imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched
  have step := Arm64Cnt.Native.reference_step (afterTen s) eleventh eleventhDecoded
    previous.2.1 previous.2.2.1
  have pc : read_pc (afterEleven s).machine = read_pc s.machine + 44#64 := by
    unfold afterEleven
    rw [step]
    simp only [Arm64Cnt.Native.after,Arm64Nop.atCursor,read_pc,write_pc,r_of_w_same]
    change read_pc (afterTen s).machine + 4#64 = _
    rw [previous.1,BitVec.add_assoc]
    rfl
  have error : read_err (afterEleven s).machine = .None := by
    unfold afterEleven
    rw [step]
    simpa [Arm64Cnt.Native.after,Arm64Nop.atCursor,read_err,write_sfp,write_pc,r_of_w_different] using previous.2.1
  have program : (afterEleven s).machine.program = s.machine.program := by
    unfold afterEleven
    rw [step]
    simpa [Arm64Cnt.Native.after,Arm64Nop.atCursor,write_pc,write_sfp,w,write_base_pc,write_base_sfp] using previous.2.2.2
  exact ⟨pc,error,by simpa only [fetch_inst,pc,program] using twelfthFetched⟩

/-- Architectural input-view setup preserves original twelfth-word admission. -/
theorem setup_next (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32) (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth : Reference.AArch64.Instruction)
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
    (tenthDecoded : tenth.decoded = .DPSFP (.Conversion_between_FP_and_Int Arm64Fmov.Native.fields))
    (eleventhDecoded : eleventh.decoded = .DPSFP (.Advanced_simd_two_reg_misc Arm64Cnt.Native.fields))
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
    (tenthFetched : fetch_inst (read_pc s.machine + 36#64) s.machine = some tenth.encoding)
    (eleventhFetched : fetch_inst (read_pc s.machine + 40#64) s.machine = some eleventh.encoding)
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding) :
    read_pc (afterEleven (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = read_pc s.machine + 44#64 ∧
    read_err (afterEleven (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = .None ∧
    fetch_inst (read_pc (afterEleven (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine)
      (afterEleven (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = some twelfth.encoding := by
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
  have f11 : fetch_inst (read_pc setup.machine + 40#64) setup.machine = some eleventh.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using eleventhFetched
  have f12 : fetch_inst (read_pc setup.machine + 44#64) setup.machine = some twelfth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using twelfthFetched
  have result := next_admission setup first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth (fields 0) (fields 1) imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded error f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12
  exact ⟨result.1.trans (congrArg (fun cursor => cursor + 44#64) pc),result.2⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvAdmission
