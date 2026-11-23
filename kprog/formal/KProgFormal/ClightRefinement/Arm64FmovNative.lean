import KProgFormal.ClightRefinement.Arm64OrnNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Native

/-- Original tenth native word: FMOV D3,X7. -/
def fields : Conversion_between_FP_and_Int_cls :=
  { sf := 1, S := 0, ftype := 1, rmode := 0, opcode := 7, Rn := 7, Rd := 3 }

/-- The imported decoder identifies the concrete general-register FMOV form. -/
theorem decoded_word : decode_raw_inst (0x9e6700e3#32) =
    some (.DPSFP (.Conversion_between_FP_and_Int fields)) := by decide +kernel

/-- Original imported 64-bit vector write, including upper-half clearing. -/
def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  Arm64Nop.atCursor (read_pc s.machine + 4#64)
    { s with machine := write_sfp 64 (3#5) (Reference.AArch64.gpr s 7) s.machine }

/-- Execute the mature general FMOV conversion semantics. -/
theorem execute (s : Reference.AArch64.State) :
    DPSFP.exec_conversion_between_FP_and_Int fields s.machine = (after s).machine := by
  simp +decide [fields,DPSFP.exec_conversion_between_FP_and_Int,DPSFP.exec_fmov_general,
    DPSFP.fmov_general_aux,Vpart_write,after,Arm64Nop.atCursor,
    Reference.AArch64.gpr,read_gpr_zr,read_gpr]
  simp only [read_pc,write_sfp]
  rw [r_of_w_different (fld1 := .PC) (fld2 := .SFP (3#5)) (by intro equal; cases equal)]
  rfl

/-- The imported vector write puts X7 in D3 and clears the upper64 bits. -/
theorem destination (s : Reference.AArch64.State) :
    Reference.AArch64.readVector (after s) 3 = (Reference.AArch64.gpr s 7).setWidth 128 := by
  change r (.SFP (3#5)) (after s).machine = _
  simp [after,Arm64Nop.atCursor,write_sfp,
    write_pc,r_of_w_different,r_of_w_same]

/-- Admit the original word through its imported decoder and actual fetch. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPSFP (.Conversion_between_FP_and_Int fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPSFP (.Conversion_between_FP_and_Int fields)) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s

/-- Complete original imported step, including PC+4, histories and no fault. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPSFP (.Conversion_between_FP_and_Int fields))
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

end KProgFormal.ClightRefinement.Arm64Fmov.Native
