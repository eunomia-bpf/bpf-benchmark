import KProgFormal.ClightRefinement.Arm64MovKeepCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovKeep.Zr

/-- Native register 31 is the zero register for move-wide instructions. -/
abbrev fields (imm : BitVec 16) (column : Fin 4) (narrow : Bool) : Move_wide_imm_cls :=
  { sf := if narrow then 0 else 1, opc := 3,
    hw := BitVec.ofNat 2 column.val, imm16 := imm, Rd := 31#5 }

private theorem column_legal : ∀ c : Fin 4, c.val < 2 →
    (BitVec.ofNat 2 c.val).getLsbD 1 = false := by decide +kernel

private theorem execute (s : Reference.AArch64.State) (imm : BitVec 16)
    (column : Fin 4) (narrow : Bool) (valid : narrow = true → column.val < 2) :
    DPI.exec_move_wide_imm (fields imm column narrow) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64) s).machine := by
  cases narrow
  · simp +decide only [fields, DPI.exec_move_wide_imm,
      false_and, ite_true, ite_false, write_gpr_zr, Arm64Nop.atCursor]
  · simp +decide only [fields, DPI.exec_move_wide_imm,
      column_legal column (valid rfl), ite_true, ite_false, write_gpr_zr, Arm64Nop.atCursor]

/-- Real decode, fetch and checked execution discard the value written to XZR. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine = (Arm64Nop.atCursor (read_pc s.machine + 4#64) s).machine := by
  have decode : decode_raw_inst instruction.encoding =
      some (.DPI (.Move_wide_imm (fields imm column narrow))) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using
    execute s imm column narrow valid

/-- Retain the complete wrapper and histories, with PC+4 and no new fault/event. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64) s, [], none⟩ := by
  have history : read_memory_accesses (Arm64Nop.atCursor (read_pc s.machine + 4#64) s).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, read_memory_accesses, write_pc, w, write_base_pc]
  have afterError : read_err (Arm64Nop.atCursor (read_pc s.machine + 4#64) s).machine = .None := by
    simpa [Arm64Nop.atCursor, read_err, write_pc, r_of_w_different] using noError
  simp only [Reference.AArch64.step,
    native_step s instruction imm column narrow valid decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl

/-- The real no-cell Clight procedure refines fetched, decoded and checked
MOVK to WZR/XZR for every legal halfword column. SP is not this selector. -/
theorem call_corresponds {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (imm : BitVec 16)
    (column : Fin 4) (narrow : Bool) (valid : narrow = true → column.val < 2)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, InternalRun Arm64NumericProgram.ge 156
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.Keep.arguments (operands unused entry.block 31 imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  obtain ⟨after, run, rep⟩ := call_zr_represents storage unused imm column narrow addresses origins s represented
  rw [reference_step s instruction imm column narrow valid decoded noError fetched]
  exact ⟨after, run,
    (Arm64Registers.cursor after (.Vptr entry.block 0) s (read_pc s.machine + 4#64)).mpr rep,
    rfl, rfl⟩

end KProgFormal.ClightRefinement.Arm64MovKeep.Zr
