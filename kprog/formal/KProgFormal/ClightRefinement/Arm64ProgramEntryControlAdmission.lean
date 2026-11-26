import KProgFormal.ClightRefinement.Arm64ProgramEntryRepeatMovAdmission

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryControlAdmission

/-- The actual fourteenth imported native step, after the repeated MOV. -/
def afterFourteen (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32) : Reference.AArch64.State :=
  (Reference.AArch64.step (Arm64ProgramEntryRepeatMovAdmission.afterThirteen origins
    (Arm64ProgramEntryBodyView.nativeSetup s origins fields))).state

open Arm64ProgramEntryRepeatMovAdmission (afterThirteen)

/-- Original fourteen-word code admission derives the current control PC,
error and same complete program. The original machine/code remains the anchor. -/
theorem admission (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
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
    (fourteenthDecoded : fourteenth.decoded = .DPI (.Move_wide_imm
      (Arm64MovImmediate.Wide.fields 2 (16#16) 0 false false)))
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
    read_pc (afterFourteen s origins fields).machine = read_pc s.machine + 56#64 ∧
    read_err (afterFourteen s origins fields).machine = .None ∧
    (afterFourteen s origins fields).machine.program = s.machine.program := by
  have previous := Arm64ProgramEntryRepeatMovAdmission.next_admission s origins fields
    first keep third fourth fifth sixth seventh eighth ninth tenth eleventh twelfth thirteenth fourteenth
    imm column negate literal firstDecoded keepDecoded thirdDecoded fourthDecoded fifthDecoded sixthDecoded
    seventhDecoded eighthDecoded ninthDecoded tenthDecoded eleventhDecoded twelfthDecoded thirteenthDecoded
    noError firstFetched keepFetched thirdFetched fourthFetched fifthFetched sixthFetched seventhFetched
    eighthFetched ninthFetched tenthFetched eleventhFetched twelfthFetched thirteenthFetched fourteenthFetched
  let prior := afterThirteen origins (Arm64ProgramEntryBodyView.nativeSetup s origins fields)
  have last := Arm64MovImmediate.Wide.reference_step prior fourteenth 2 (16#16) 0 false false
    (by intro impossible; cases impossible) fourteenthDecoded previous.2.1 previous.2.2.1
  have pc : read_pc (afterFourteen s origins fields).machine = read_pc s.machine + 56#64 := by
    unfold afterFourteen
    rw [last]
    simp only [Arm64Nop.atCursor,read_pc,write_pc,r_of_w_same]
    change read_pc prior.machine + 4#64 = _
    rw [previous.1,BitVec.add_assoc]
    rfl
  have error : read_err (afterFourteen s origins fields).machine = .None := by
    unfold afterFourteen
    rw [last]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,read_err,write_pc,r_of_w_different] using previous.2.1
  have program : (afterFourteen s origins fields).machine.program = s.machine.program := by
    unfold afterFourteen
    rw [last]
    simpa [Arm64Nop.atCursor,Arm64RegisterWrite.nativeUpdate,write_pc,w,write_base_pc,write_base_gpr] using previous.2.2.2
  exact ⟨pc,error,program⟩

/-- The first control word is fetched at the proved physical PC. -/
theorem fetch_current (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32)
    (pc : read_pc (afterFourteen s origins fields).machine = read_pc s.machine + 56#64)
    (program : (afterFourteen s origins fields).machine.program = s.machine.program)
    (word : BitVec 32)
    (fetched : fetch_inst (read_pc s.machine + 56#64) s.machine = some word) :
    fetch_inst (read_pc (afterFourteen s origins fields).machine)
      (afterFourteen s origins fields).machine = some word := by
  simpa only [fetch_inst,pc,program] using fetched

/-- The following branch word belongs to the SAME original program at PC+60. -/
theorem fetch_next (s : Reference.AArch64.State) (origins : Reference.Provenance.AArch64.Origins)
    (fields : Fin 3 → BitVec 32)
    (pc : read_pc (afterFourteen s origins fields).machine = read_pc s.machine + 56#64)
    (program : (afterFourteen s origins fields).machine.program = s.machine.program)
    (word : BitVec 32)
    (fetched : fetch_inst (read_pc s.machine + 60#64) s.machine = some word) :
    fetch_inst (read_pc (afterFourteen s origins fields).machine + 4#64)
      (afterFourteen s origins fields).machine = some word := by
  simpa only [fetch_inst,pc,program,BitVec.add_assoc,
    (by decide +kernel : (56#64) + (4#64) = (60#64))] using fetched

end KProgFormal.ClightRefinement.Arm64ProgramEntryControlAdmission
