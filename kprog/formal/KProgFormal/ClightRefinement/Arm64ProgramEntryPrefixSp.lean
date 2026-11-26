import KProgFormal.ClightRefinement.Arm64ProgramEntryCompareAdmission
import KProgFormal.ClightRefinement.Arm64AddOperandReads
import KProgFormal.ClightRefinement.Arm64UaddlvNative
import KProgFormal.ClightRefinement.Arm64FmovNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvAdmission

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPrefixSp
open Arm64ProgramEntryAddAdmission (afterPair)
open Arm64ProgramEntryAddRegisterAdmission (afterThree)
open Arm64ProgramEntryMulAdmission (afterFour)
open Arm64ProgramEntryCompareAdmission (afterFive)
open Arm64ProgramEntrySelectAdmission (afterSix)
open Arm64ProgramEntryCnegAdmission (afterSeven)
open Arm64ProgramEntryOrnAdmission (afterEight)
open Arm64ProgramEntryFmovAdmission (afterNine)
open Arm64ProgramEntryCntAdmission (afterTen)
open Arm64ProgramEntryUaddlvAdmission (afterEleven)

/-- The imported PC writer retains the independent architectural SP field. -/
theorem cursor (s : Reference.AArch64.State) (pc : BitVec 64) :
    Reference.AArch64.sp (Arm64Nop.atCursor pc s) = Reference.AArch64.sp s := by
  simp [Reference.AArch64.sp,Arm64Nop.atCursor,write_pc,r_of_w_different]

/-- Five genuine fetched/decoded MOV, MOVK, ADD, ADD-register and MUL steps
retain SP. Each numerical step is the existing imported-model theorem. -/
theorem five (s : Reference.AArch64.State)
    (first keep third fourth fifth : Reference.AArch64.Instruction) (mark priority : BitVec 32)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : mark.setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 ((priority.setWidth 64).setWidth 16) 1 false)))
    (thirdDecoded : third.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (fourthDecoded : fourth.decoded = .DPR (.Add_sub_shifted_reg Arm64AddRegisterNative.fields))
    (fifthDecoded : fifth.decoded = .DPR (.Data_processing_three_source Arm64Mul.Native.fields))
    (noError : read_err s.machine = .None)
    (firstFetched : fetch_inst (read_pc s.machine) s.machine = some first.encoding)
    (keepFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some keep.encoding)
    (thirdFetched : fetch_inst (read_pc s.machine + 8#64) s.machine = some third.encoding)
    (fourthFetched : fetch_inst (read_pc s.machine + 12#64) s.machine = some fourth.encoding)
    (fifthFetched : fetch_inst (read_pc s.machine + 16#64) s.machine = some fifth.encoding) :
    Reference.AArch64.sp (afterFive s) = Reference.AArch64.sp s := by
  have pairAdmission := Arm64ProgramEntryAddAdmission.next_admission s first keep third
    mark priority imm column negate literal firstDecoded keepDecoded noError firstFetched keepFetched thirdFetched
  have fourthAdmission := Arm64ProgramEntryAddRegisterAdmission.next_admission s first keep third fourth
    mark priority imm column negate literal firstDecoded keepDecoded thirdDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched
  have fifthAdmission := Arm64ProgramEntryMulAdmission.next_admission s first keep third fourth fifth
    mark priority imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched
  have pairStep := Arm64MovPairNative.steps s first keep mark priority imm column negate literal
    firstDecoded keepDecoded noError firstFetched keepFetched
  have thirdStep := Arm64AddImmediate.Native.reference_step (afterPair s) third 2 (16#12) false
    thirdDecoded pairAdmission.2.1 pairAdmission.2.2
  have fourthStep := Arm64AddRegisterNative.reference_step (afterThree s) fourth
    fourthDecoded fourthAdmission.2.1 fourthAdmission.2.2
  have fifthStep := Arm64Mul.Native.reference_step (afterFour s) fifth
    fifthDecoded fifthAdmission.2.1 fifthAdmission.2.2
  have pairSP : Reference.AArch64.sp (afterPair s) = Reference.AArch64.sp s := by
    unfold afterPair
    rw [pairStep.2]
    simp only [cursor,Arm64RegisterWrite.native_sp]
  have thirdSP : Reference.AArch64.sp (afterThree s) = Reference.AArch64.sp (afterPair s) := by
    unfold afterThree
    rw [thirdStep]
    simp only [cursor,Arm64RegisterWrite.native_sp]
  have fourthSP : Reference.AArch64.sp (afterFour s) = Reference.AArch64.sp (afterThree s) := by
    unfold afterFour
    rw [fourthStep]
    simp only [cursor,Arm64RegisterWrite.native_sp]
  have fifthSP : Reference.AArch64.sp (afterFive s) = Reference.AArch64.sp (afterFour s) := by
    unfold afterFive
    rw [fifthStep]
    simp only [cursor,Arm64RegisterWrite.native_sp]
  exact fifthSP.trans (fourthSP.trans (thirdSP.trans pairSP))

/-- Original FMOV, CNT and UADDLV vector writes retain architectural SP. -/
theorem fmov (s : Reference.AArch64.State) :
    Reference.AArch64.sp (Arm64Fmov.Native.after s) = Reference.AArch64.sp s := by
  rw [Arm64Fmov.Native.after,cursor]
  simp [Reference.AArch64.sp,write_sfp,r_of_w_different]

theorem cnt (s : Reference.AArch64.State) :
    Reference.AArch64.sp (Arm64Cnt.Native.after s) = Reference.AArch64.sp s := by
  rw [Arm64Cnt.Native.after,cursor]
  simp [Reference.AArch64.sp,write_sfp,r_of_w_different]

theorem uaddlv (s : Reference.AArch64.State) :
    Reference.AArch64.sp (Arm64Uaddlv.Native.after s) = Reference.AArch64.sp s := by
  rw [Arm64Uaddlv.Native.after,cursor]
  simp [Reference.AArch64.sp,write_sfp,r_of_w_different]

/-- All twelve actual fetched/decoded prefix instructions retain SP,
using the existing mature step correspondences and their real admissions. -/
theorem twelve (s : Reference.AArch64.State)
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
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding) :
    Reference.AArch64.sp (Reference.AArch64.step (afterEleven s)).state = Reference.AArch64.sp s := by
  have sp5 := five s first keep third fourth fifth mark priority imm column negate literal
    firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched
  have admission6 := Arm64ProgramEntryCompareAdmission.next_admission s first keep third fourth fifth sixth mark priority imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched
  have step6 := Arm64Compare.Native.reference_step (afterFive s) sixth sixthDecoded admission6.2.1 admission6.2.2
  have sp6 : Reference.AArch64.sp (afterSix s) = Reference.AArch64.sp (afterFive s) := by
    unfold afterSix
    rw [step6]
    exact (Arm64Compare.Native.registers _).2.1
  have admission7 := Arm64ProgramEntrySelectAdmission.next_admission s first keep third fourth fifth sixth seventh mark priority imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched
  have step7 := Arm64Select.Native.reference_step (afterSix s) seventh 5 1 2 (0#4) seventhDecoded admission7.2.1 admission7.2.2
  have sp7 : Reference.AArch64.sp (afterSeven s) = Reference.AArch64.sp (afterSix s) := by
    unfold afterSeven
    rw [step7]
    simp only [cursor,Arm64RegisterWrite.native_sp]
  have admission8 := Arm64ProgramEntryCnegAdmission.next_admission s first keep third fourth fifth sixth seventh eighth mark priority imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched
  have step8 := Arm64Cneg.Native.reference_step (afterSeven s) eighth eighthDecoded admission8.2.1 admission8.2.2
  have sp8 : Reference.AArch64.sp (afterEight s) = Reference.AArch64.sp (afterSeven s) := by
    unfold afterEight
    rw [step8]
    simp only [cursor,Arm64RegisterWrite.native_sp]
  have admission9 := Arm64ProgramEntryOrnAdmission.next_admission s first keep third fourth fifth sixth seventh eighth ninth mark priority imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched
  have step9 := Arm64Orn.Native.reference_step (afterEight s) ninth ninthDecoded admission9.2.1 admission9.2.2
  have sp9 : Reference.AArch64.sp (afterNine s) = Reference.AArch64.sp (afterEight s) := by
    unfold afterNine
    rw [step9]
    simp only [cursor,Arm64RegisterWrite.native_sp]
  have admission10 := Arm64ProgramEntryFmovAdmission.next_admission s first keep third fourth fifth sixth seventh eighth ninth tenth mark priority imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched
  have step10 := Arm64Fmov.Native.reference_step (afterNine s) tenth tenthDecoded admission10.2.1 admission10.2.2
  have sp10 : Reference.AArch64.sp (afterTen s) = Reference.AArch64.sp (afterNine s) := by
    unfold afterTen
    rw [step10]
    exact fmov _
  have admission11 := Arm64ProgramEntryCntAdmission.next_admission s first keep third fourth fifth sixth seventh eighth ninth tenth eleventh mark priority imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched
  have step11 := Arm64Cnt.Native.reference_step (afterTen s) eleventh eleventhDecoded admission11.2.1 admission11.2.2
  have sp11 : Reference.AArch64.sp (afterEleven s) = Reference.AArch64.sp (afterTen s) := by
    unfold afterEleven
    rw [step11]
    exact cnt _
  have admission12 := Arm64ProgramEntryUaddlvAdmission.next_admission s first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth mark priority imm column negate
    literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded noError
    firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched
  have step12 := Arm64Uaddlv.Native.reference_step (afterEleven s) twelfth twelfthDecoded admission12.2.1 admission12.2.2
  have sp12 : Reference.AArch64.sp (Reference.AArch64.step (afterEleven s)).state = Reference.AArch64.sp (afterEleven s) := by
    rw [step12]
    exact uaddlv _
  exact sp12.trans (sp11.trans (sp10.trans (sp9.trans (sp8.trans (sp7.trans (sp6.trans (sp5)))))))

/-- The original source setup and those same twelve fetched words derive
the actual raw-SP input, rather than adding a reached-heap read premise. -/
theorem setup (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (values : Fin 3 → BitVec 32)
    (first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth : Reference.AArch64.Instruction)
    (imm : BitVec 16) (column : Fin 4) (negate : Bool)
    (literal : (values 0).setWidth 64 = Arm64MovImmediate.Wide.literal imm column false negate)
    (firstDecoded : first.decoded = .DPI (.Move_wide_imm (Arm64MovImmediate.Wide.fields 1 imm column false negate)))
    (keepDecoded : keep.decoded = .DPI (.Move_wide_imm
      (Arm64MovKeep.Native.fields 1 (((values 1).setWidth 64).setWidth 16) 1 false)))
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
    (twelfthFetched : fetch_inst (read_pc s.machine + 44#64) s.machine = some twelfth.encoding) :
    Reference.AArch64.sp (Reference.AArch64.step (afterEleven (Arm64ProgramEntryBodyView.nativeSetup s origins values))).state =
      (-32#64) + origins.stack := by
  let actual := Arm64ProgramEntryBodyView.nativeSetup s origins values
  have pc : read_pc actual.machine = read_pc s.machine :=
    Arm64ProgramEntryBodyView.native_other s origins values .PC (by intro equal; cases equal) (by intro flag equal; cases equal)
  have error : read_err actual.machine = .None :=
    (Arm64ProgramEntryBodyView.native_other s origins values .ERR (by intro equal; cases equal) (by intro flag equal; cases equal)).trans noError
  have program : actual.machine.program = s.machine.program :=
    (Arm64ProgramEntryBodyView.native_resources s origins values).2.1
  have f1 : fetch_inst (read_pc actual.machine) actual.machine = some first.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using firstFetched
  have f2 : fetch_inst (read_pc actual.machine + 4#64) actual.machine = some keep.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using keepFetched
  have f3 : fetch_inst (read_pc actual.machine + 8#64) actual.machine = some third.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using thirdFetched
  have f4 : fetch_inst (read_pc actual.machine + 12#64) actual.machine = some fourth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using fourthFetched
  have f5 : fetch_inst (read_pc actual.machine + 16#64) actual.machine = some fifth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using fifthFetched
  have f6 : fetch_inst (read_pc actual.machine + 20#64) actual.machine = some sixth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using sixthFetched
  have f7 : fetch_inst (read_pc actual.machine + 24#64) actual.machine = some seventh.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using seventhFetched
  have f8 : fetch_inst (read_pc actual.machine + 28#64) actual.machine = some eighth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using eighthFetched
  have f9 : fetch_inst (read_pc actual.machine + 32#64) actual.machine = some ninth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using ninthFetched
  have f10 : fetch_inst (read_pc actual.machine + 36#64) actual.machine = some tenth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using tenthFetched
  have f11 : fetch_inst (read_pc actual.machine + 40#64) actual.machine = some eleventh.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using eleventhFetched
  have f12 : fetch_inst (read_pc actual.machine + 44#64) actual.machine = some twelfth.encoding := by
    rw [pc]
    simpa only [fetch_inst,program] using twelfthFetched
  exact (twelve actual first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth (values 0) (values 1) imm column negate literal
    firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded error f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12).trans
    (Arm64ProgramEntryBodyView.native_sp s origins values)

/-- The SAME actual storage/native relation recovers the raw source SP from
the established architectural SP and its original stack origin. -/
theorem storage {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (actual : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      memory.nextblock memory (.Vptr entry.block 0) native)
    (nativeSP : Reference.AArch64.sp native = (-32#64) + origins.stack) : actual.spValue = (-32#64) := by
  have raw := (Arm64AddOperandReads.Linked.sp_native actual addresses origins native represented).symm.trans nativeSP
  have cancelled := congrArg (fun word => word - origins.stack) raw
  simpa only [BitVec.add_sub_cancel] using cancelled

end KProgFormal.ClightRefinement.Arm64ProgramEntryPrefixSp
