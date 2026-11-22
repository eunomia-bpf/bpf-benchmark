import KProgFormal.Reference.AArch64

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Native

/-- Actual mature decoded CMP X4,X1 alias: SUBS XZR,X4,X1,LSL0. -/
def fields : Add_sub_shifted_reg_cls :=
  {sf := 1, op := 1, S := 1, shift := 0, Rm := 1, imm6 := 0, Rn := 4, Rd := 31}

/-- Bind the external arithmetic and state writers; there is no local ISA
arithmetic or replacement decoder. -/
def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  let flags := AddWithCarry (Reference.AArch64.gpr s 4) (~~~Reference.AArch64.gpr s 1) (1#1)
  {s with machine := write_pstate flags.snd (write_pc (read_pc s.machine + 4#64) s.machine)}


/-- The real imported instruction performs exactly the external carry/flag
update, advances PC and discards the zero-register destination. -/
theorem execute (s : Reference.AArch64.State) :
    DPR.exec_add_sub_shifted_reg fields s.machine = (after s).machine := by
  simp +decide [DPR.exec_add_sub_shifted_reg,fields,after,read_gpr_zr,read_gpr,
    write_gpr_zr,decode_shift,shift_reg,Reference.AArch64.gpr]
  change write_pstate (AddWithCarry (Reference.AArch64.gpr s 4)
    (~~~(Reference.AArch64.gpr s 1 <<< (0 : Nat))) (1#1)).snd
    (write_pc (read_pc s.machine + 4#64) s.machine) = (after s).machine
  rw [BitVec.shiftLeft_zero]
  rfl

/-- Bind the same external operation to the genuine fetched/decoded word. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Add_sub_shifted_reg fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (after s).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPR (.Add_sub_shifted_reg fields)) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s

/-- Complete native histories are retained, with no new event or fault. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Add_sub_shifted_reg fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ := by
  have history : read_memory_accesses (after s).machine = read_memory_accesses s.machine := by
    simp [after,read_memory_accesses,write_pstate,write_pc,w,write_base_pc,write_base_flag]
  have afterError : read_err (after s).machine = .None := by
    simpa [after,write_pstate,read_err,write_pc,r_of_w_different] using noError
  simp only [Reference.AArch64.step,native_step s instruction decoded noError fetched,
    history,List.drop_length,afterError,noError]
  rfl

/-- CMP does not write any general-purpose register or the stack pointer. -/
theorem registers (s : Reference.AArch64.State) :
    (∀ i, Reference.AArch64.gpr (after s) i = Reference.AArch64.gpr s i) ∧
    Reference.AArch64.sp (after s) = Reference.AArch64.sp s ∧
    (∀ i, Reference.AArch64.readVector (after s) i = Reference.AArch64.readVector s i) ∧
    (after s).extraFlags = s.extraFlags := by
  simp [after,Reference.AArch64.gpr,Reference.AArch64.sp,Reference.AArch64.readVector,
    write_pstate,write_pc,r_of_w_different]

end KProgFormal.ClightRefinement.Arm64Compare.Native
