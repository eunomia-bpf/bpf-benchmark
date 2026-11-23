import KProgFormal.ClightRefinement.Arm64Nop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Native

/-- The original eleventh word is CNT V0.16B,V0.16B. -/
def fields : Advanced_simd_two_reg_misc_cls :=
  { Q := 1, U := 0, size := 0, opcode := 5, Rn := 0, Rd := 0 }

theorem decoded_word : decode_raw_inst (0x4e205800#32) =
    some (.DPSFP (.Advanced_simd_two_reg_misc fields)) := by decide +kernel

/-- The result uses the imported per-byte population count directly. -/
def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  Arm64Nop.atCursor (read_pc s.machine + 4#64)
    { s with machine := write_sfp 128 (0#5) (DPSFP.simd_count_bytes (Reference.AArch64.readVector s 0)) s.machine }

theorem execute (s : Reference.AArch64.State) :
    DPSFP.exec_advanced_simd_two_reg_misc fields s.machine = (after s).machine := by
  simp +decide [fields,DPSFP.exec_advanced_simd_two_reg_misc,after,
    Arm64Nop.atCursor,Reference.AArch64.readVector,read_sfp]
  simp only [read_pc,write_sfp]
  rw [r_of_w_different (fld1 := .PC) (fld2 := .SFP (0#5)) (by intro equal; cases equal)]

theorem destination (s : Reference.AArch64.State) :
    Reference.AArch64.readVector (after s) 0 =
      DPSFP.simd_count_bytes (Reference.AArch64.readVector s 0) := by
  change r (.SFP (0#5)) (after s).machine = _
  simp [after,Arm64Nop.atCursor,write_sfp,write_pc,r_of_w_different,r_of_w_same]

theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPSFP (.Advanced_simd_two_reg_misc fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPSFP (.Advanced_simd_two_reg_misc fields)) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s

theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPSFP (.Advanced_simd_two_reg_misc fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ := by
  have history : read_memory_accesses (after s).machine = read_memory_accesses s.machine := by
    simp [after,Arm64Nop.atCursor,read_memory_accesses,write_sfp,write_pc,w,write_base_pc,write_base_sfp]
  have afterError : read_err (after s).machine = .None := by
    simpa [after,Arm64Nop.atCursor,read_err,write_sfp,write_pc,r_of_w_different] using noError
  simp only [Reference.AArch64.step,native_step s instruction decoded noError fetched,
    history,List.drop_length,afterError,noError]
  rfl

end KProgFormal.ClightRefinement.Arm64Cnt.Native
