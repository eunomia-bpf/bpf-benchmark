import KProgFormal.ClightRefinement.Arm64ProgramEntryRepeatMovNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvAdmission
import KProgFormal.ClightRefinement.Arm64UaddlvNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryRepeatMovAdmission

open Arm64ProgramEntryUaddlvAdmission (afterEleven)
open Arm64ProgramEntryCntAdmission (afterTen)
open Arm64ProgramEntryRepeatMovNative (beforeNative)

/-- Twelve actual imported instruction steps, before the genuine pointer setup. -/
def afterTwelve (s : Reference.AArch64.State) : Reference.AArch64.State :=
  (Reference.AArch64.step (afterEleven s)).state

/-- Original input setup, all twelve instruction steps and the actual pointer
write transport the original thirteenth PC, error and fetched program word. -/
theorem admission (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32) (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth : Reference.AArch64.Instruction)
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
    (twelfthDecoded : twelfth.decoded = .DPSFP (.Advanced_simd_across_lanes Arm64Uaddlv.Native.fields))
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
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding)
    (thirteenthFetched : fetch_inst (read_pc s.machine + 48#64) s.machine = some thirteenth.encoding) :
    read_pc (beforeNative origins (afterTwelve (Arm64ProgramEntryBodyView.nativeSetup s origins fields))).machine =
      read_pc s.machine + 48#64 ∧
    read_err (beforeNative origins (afterTwelve (Arm64ProgramEntryBodyView.nativeSetup s origins fields))).machine = .None ∧
    fetch_inst (read_pc (beforeNative origins (afterTwelve (Arm64ProgramEntryBodyView.nativeSetup s origins fields))).machine)
      (beforeNative origins (afterTwelve (Arm64ProgramEntryBodyView.nativeSetup s origins fields))).machine = some thirteenth.encoding ∧
    (beforeNative origins (afterTwelve (Arm64ProgramEntryBodyView.nativeSetup s origins fields))).machine.program = s.machine.program := by
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
  have previous := Arm64ProgramEntryUaddlvAdmission.next_admission setup first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth (fields 0) (fields 1) imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded error f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12
  have ten := Arm64ProgramEntryCntAdmission.admission_with_program setup first keep third fourth fifth sixth seventh eighth ninth tenth eleventh (fields 0) (fields 1) imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded error f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11
  have cntStep := Arm64Cnt.Native.reference_step (afterTen setup) eleventh eleventhDecoded ten.2.1 ten.2.2.1
  have program11 : (afterEleven setup).machine.program = setup.machine.program := by
    unfold afterEleven
    rw [cntStep]
    simpa [Arm64Cnt.Native.after,Arm64Nop.atCursor,write_pc,write_sfp,w,write_base_pc,write_base_sfp] using ten.2.2.2
  have step12 := Arm64Uaddlv.Native.reference_step (afterEleven setup) twelfth twelfthDecoded previous.2.1 previous.2.2
  have pc12 : read_pc (afterTwelve setup).machine = read_pc s.machine + 48#64 := by
    unfold afterTwelve
    rw [step12]
    simp only [Arm64Uaddlv.Native.after,Arm64Nop.atCursor,read_pc,write_pc,r_of_w_same]
    change read_pc (afterEleven setup).machine + 4#64 = _
    rw [previous.1,pc,BitVec.add_assoc]
    rfl
  have error12 : read_err (afterTwelve setup).machine = .None := by
    unfold afterTwelve
    rw [step12]
    simpa [Arm64Uaddlv.Native.after,Arm64Nop.atCursor,read_err,write_sfp,write_pc,r_of_w_different] using previous.2.1
  have program12 : (afterTwelve setup).machine.program = s.machine.program := by
    unfold afterTwelve
    rw [step12]
    simpa [Arm64Uaddlv.Native.after,Arm64Nop.atCursor,write_pc,write_sfp,w,write_base_pc,write_base_sfp] using program11.trans program
  have control := Arm64ProgramEntryRepeatMovNative.pointer_control origins (afterTwelve setup)
  have finalPC := control.1.trans pc12
  have finalProgram := control.2.2.trans program12
  have fetched : fetch_inst (read_pc (beforeNative origins (afterTwelve setup)).machine)
      (beforeNative origins (afterTwelve setup)).machine = some thirteenth.encoding := by
    unfold fetch_inst
    rw [finalPC,finalProgram]
    simpa only [fetch_inst] using thirteenthFetched
  exact ⟨finalPC,control.2.1.trans error12,fetched,finalProgram⟩

/-- Actual thirteenth imported step, following the genuine pointer setup. -/
def afterThirteen (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State) :
    Reference.AArch64.State := (Reference.AArch64.step (beforeNative origins (afterTwelve s))).state

/-- Original fourteenth PC, error, fetched word and program are transported
through the actual repeated MOV, using its imported Wide step. -/
theorem next_admission (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32) (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth : Reference.AArch64.Instruction)
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
    (twelfthDecoded : twelfth.decoded = .DPSFP (.Advanced_simd_across_lanes Arm64Uaddlv.Native.fields))
    (thirteenthDecoded : thirteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
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
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding)
    (thirteenthFetched : fetch_inst (read_pc s.machine + 48#64) s.machine = some thirteenth.encoding)
    (fourteenthFetched : fetch_inst (read_pc s.machine + 52#64) s.machine = some fourteenth.encoding) :
    read_pc (afterThirteen origins (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = read_pc s.machine + 52#64 ∧
    read_err (afterThirteen origins (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = .None ∧
    fetch_inst (read_pc (afterThirteen origins (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine)
      (afterThirteen origins (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine = some fourteenth.encoding ∧
    (afterThirteen origins (Arm64ProgramEntryBodyView.nativeSetup s origins fields)).machine.program = s.machine.program := by
  have previous := admission s origins fields first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth imm column negate literal
    firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched thirteenthFetched
  let setup := Arm64ProgramEntryBodyView.nativeSetup s origins fields
  let reached := beforeNative origins (afterTwelve setup)
  have step13 := Arm64MovImmediate.Wide.reference_step reached thirteenth 1 imm column false negate
    (by intro impossible; cases impossible) thirteenthDecoded previous.2.1 previous.2.2.1
  have pc13 : read_pc (afterThirteen origins setup).machine = read_pc s.machine + 52#64 := by
    unfold afterThirteen
    rw [step13]
    simp only [Arm64Nop.atCursor,read_pc,write_pc,r_of_w_same]
    change read_pc reached.machine + 4#64 = _
    rw [previous.1,BitVec.add_assoc]
    rfl
  have error13 : read_err (afterThirteen origins setup).machine = .None := by
    unfold afterThirteen
    rw [step13]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,read_err,write_pc,r_of_w_different] using previous.2.1
  have program13 : (afterThirteen origins setup).machine.program = s.machine.program := by
    unfold afterThirteen
    rw [step13]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,write_pc,w,write_base_pc,write_base_gpr] using previous.2.2.2
  have fetched : fetch_inst (read_pc (afterThirteen origins setup).machine)
      (afterThirteen origins setup).machine = some fourteenth.encoding := by
    unfold fetch_inst
    rw [pc13,program13]
    simpa only [fetch_inst] using fourteenthFetched
  exact ⟨pc13,error13,fetched,program13⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryRepeatMovAdmission
