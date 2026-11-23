import KProgFormal.ClightRefinement.Arm64CnegNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Orn.Native

/-- Original ninth native word: ORN W7,W6,W3,LSL1. -/
def fields : Logical_shifted_reg_cls :=
  { sf := 0, opc := 1, shift := 0, N := 1, Rm := 3, imm6 := 1, Rn := 6, Rd := 7 }

/-- Execute the imported logical-shifted-register semantics with W32 clearing. -/
theorem execute (s : Reference.AArch64.State) :
    DPR.exec_logical_shifted_reg fields s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 7
          (Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)) true)).machine := by
  change write_gpr_zr 32 (7#5)
    (read_gpr_zr 32 (6#5) s.machine ||| ~~~(read_gpr_zr 32 (3#5) s.machine <<< 1))
    (write_pc (read_pc s.machine + 4#64) s.machine) = _
  simp +decide [read_gpr_zr, read_gpr, write_gpr_zr, write_gpr,
    Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written,
    Reference.AArch64.gpr, read_pc, write_pc, w, write_base_pc, write_base_gpr]
  rfl

/-- Admit only the fetched word carrying the external decoder certificate. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Logical_shifted_reg fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 7
          (Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)) true)).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPR (.Logical_shifted_reg fields)) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using execute s

/-- Complete imported step, retaining histories, PC+4 and the no-fault result. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Logical_shifted_reg fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 7
          (Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)) true), [], none⟩ := by
  have history : read_memory_accesses
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 7
          (Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)) true)).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_memory_accesses,
      write_pc, w, write_base_pc, write_base_gpr]
  have afterError : read_err
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 7
          (Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)) true)).machine = .None := by
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc,
      r_of_w_different] using noError
  simp only [Reference.AArch64.step, native_step s instruction decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl

end KProgFormal.ClightRefinement.Arm64Orn.Native
