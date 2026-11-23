import KProgFormal.ClightRefinement.Arm64SelectNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cneg.Native

/-- CNEG X6,X5,GE is the imported CSNEG X6,X5,X5,LT alias. -/
def fields : Conditional_select_cls :=
  { sf := 1, op := 1, S := 0, Rm := 5, cond := 11,
    op2 := 1, Rn := 5, Rd := 6 }

/-- GE and its inverted alias condition use the same imported NZCV view. -/
theorem inverse_condition (s : Reference.AArch64.State) :
    ConditionHolds (11#4) s.machine = !(ConditionHolds (10#4) s.machine) := by
  simp +decide [ConditionHolds]

/-- Evaluate the mature CSNEG semantics at the original fixture fields.
The only arithmetic normalization is two's-complement negation. -/
theorem execute (s : Reference.AArch64.State) :
    DPR.exec_conditional_select fields s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 6
          (if ConditionHolds (10#4) s.machine then -Reference.AArch64.gpr s 5
            else Reference.AArch64.gpr s 5) false)).machine := by
  have inverted := inverse_condition s
  by_cases taken : ConditionHolds (10#4) s.machine
  all_goals
    simp +decide [fields, DPR.exec_conditional_select, inverted, taken,
      read_gpr_zr, read_gpr, write_gpr_zr, write_gpr, Reference.AArch64.gpr,
      Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written,
      write_pc, w, write_base_pc, write_base_gpr, BitVec.neg_eq_not_add] <;> rfl

/-- Admit only the fetched word carrying the external decoder certificate. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Conditional_select fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 6
          (if ConditionHolds (10#4) s.machine then -Reference.AArch64.gpr s 5
            else Reference.AArch64.gpr s 5) false)).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPR (.Conditional_select fields)) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using execute s

/-- Complete imported step, retaining histories, PC+4 and the no-fault result. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Conditional_select fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 6
          (if ConditionHolds (10#4) s.machine then -Reference.AArch64.gpr s 5
            else Reference.AArch64.gpr s 5) false), [], none⟩ := by
  have history : read_memory_accesses
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 6
          (if ConditionHolds (10#4) s.machine then -Reference.AArch64.gpr s 5
            else Reference.AArch64.gpr s 5) false)).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_memory_accesses,
      write_pc, w, write_base_pc, write_base_gpr]
  have afterError : read_err
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 6
          (if ConditionHolds (10#4) s.machine then -Reference.AArch64.gpr s 5
            else Reference.AArch64.gpr s 5) false)).machine = .None := by
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc,
      r_of_w_different] using noError
  simp only [Reference.AArch64.step, native_step s instruction decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl

end KProgFormal.ClightRefinement.Arm64Cneg.Native
