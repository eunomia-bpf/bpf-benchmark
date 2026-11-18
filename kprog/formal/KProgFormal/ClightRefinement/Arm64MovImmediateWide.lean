import KProgFormal.ClightRefinement.Arm64MovImmediateNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate.Wide

/-- Literal binding from the live normalize_alias/encode route: shift the
16-bit immediate, optionally complement it, mask to W/X width, emit as u64.
This has no machine input and does not compute a native execution outcome. -/
def literal (imm : BitVec 16) (column : Fin 4) (narrow negate : Bool) : BitVec 64 :=
  if narrow then
    let value := imm.setWidth 32 <<< (16 * column.val)
    (if negate then ~~~value else value).setWidth 64
  else
    let value := imm.setWidth 64 <<< (16 * column.val)
    if negate then ~~~value else value

/-- Numeric form of the live shift/complement/width-mask literal binding.
This equation concerns emitted metadata, not execution of the Python parser. -/
theorem literal_toNat (imm : BitVec 16) (column : Fin 4) (narrow negate : Bool) :
    (literal imm column narrow negate).toNat =
      let bits := if narrow then 32 else 64
      let value := (imm.toNat <<< (16 * column.val)) % 2^bits
      if negate then 2^bits - 1 - value else value := by
  cases narrow <;> cases negate <;>
    simp +decide only [literal, BitVec.toNat_setWidth_of_le,
      BitVec.toNat_shiftLeft, BitVec.toNat_not, ite_true, ite_false, eq_self]

/-- Bind mature decoded fields to the same normalized source operands. -/
abbrev fields (i : Fin 31) (imm : BitVec 16) (column : Fin 4) (narrow negate : Bool) : Move_wide_imm_cls :=
  { sf := if narrow then 0 else 1, opc := if negate then 0 else 2,
    hw := BitVec.ofNat 2 column.val, imm16 := imm, Rd := BitVec.ofNat 5 i.val }

private theorem ordinary (i : Fin 31) : BitVec.ofNat 5 i.val ≠ 31#5 := by
  intro equal
  have bits := congrArg BitVec.toNat equal
  change i.val % 32 = 31 at bits
  have bound := i.isLt
  omega

private theorem column_offset : ∀ c : Fin 4,
    ((BitVec.ofNat 2 c.val) ++ (0#4)).toNat = 16 * c.val := by decide +kernel

private theorem column_legal : ∀ c : Fin 4, c.val < 2 →
    (BitVec.ofNat 2 c.val).getLsbD 1 = false := by decide +kernel

private theorem install_zero {n : Nat} (imm : BitVec 16) (position : Nat) :
    BitVec.partInstall position 16 imm (BitVec.zero n) = imm.setWidth n <<< position := by
  simp only [BitVec.partInstall, BitVec.zero_eq, BitVec.zero_and, BitVec.zero_or]

private theorem written_literal (imm : BitVec 16) (column : Fin 4) (narrow negate : Bool) :
    Arm64RegisterWrite.written narrow (literal imm column narrow negate) =
      literal imm column narrow negate := by
  cases narrow <;> cases negate <;> simp [literal, Arm64RegisterWrite.written]

private theorem execute_x (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16)
    (column : Fin 4) (negate : Bool) :
    DPI.exec_move_wide_imm (fields i imm column false negate) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (literal imm column false negate) false)).machine := by
  cases negate <;>
    simp +decide only [fields, DPI.exec_move_wide_imm, column_offset, ite_true, ite_false]
  all_goals
    rw [install_zero]
    simp only [Arm64RegisterWrite.nativeUpdate, written_literal]
    simp [write_gpr_zr, write_gpr, ordinary i, Arm64Nop.atCursor,
      literal, read_pc, r_of_w_different]

private theorem execute_w (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16)
    (column : Fin 4) (negate : Bool) (valid : column.val < 2) :
    DPI.exec_move_wide_imm (fields i imm column true negate) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (literal imm column true negate) true)).machine := by
  cases negate <;>
    simp +decide only [fields, DPI.exec_move_wide_imm, column_offset, column_legal column valid, ite_true, ite_false]
  all_goals
    rw [install_zero]
    simp only [Arm64RegisterWrite.nativeUpdate, written_literal]
    simp [write_gpr_zr, write_gpr, ordinary i, Arm64Nop.atCursor,
      literal, read_pc, r_of_w_different]

private theorem execute (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16)
    (column : Fin 4) (narrow negate : Bool) (valid : narrow = true → column.val < 2) :
    DPI.exec_move_wide_imm (fields i imm column narrow negate) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (literal imm column narrow negate) narrow)).machine := by
  cases narrow
  · exact execute_x s i imm column negate
  · exact execute_w s i imm column negate (valid rfl)

/-- All valid W/X halfword columns of ordinary MOVZ/MOVN use the mature
checked step, its real decoder certificate and the actual fetched encoding. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 16) (column : Fin 4) (narrow negate : Bool)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm column narrow negate)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (literal imm column narrow negate) narrow)).machine := by
  have decode : decode_raw_inst instruction.encoding =
      some (.DPI (.Move_wide_imm (fields i imm column narrow negate))) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using
    execute s i imm column narrow negate valid

/-- Exact complete native wrapper state and empty new observation delta;
all existing access history and non-written machine fields are retained. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 16) (column : Fin 4) (narrow negate : Bool)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm column narrow negate)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (literal imm column narrow negate) narrow), [], none⟩ := by
  have history : read_memory_accesses
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (literal imm column narrow negate) narrow)).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_memory_accesses,
      write_pc, w, write_base_pc, write_base_gpr]
  have afterError : read_err
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (literal imm column narrow negate) narrow)).machine = .None := by
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different] using noError
  simp only [Reference.AArch64.step,
    native_step s instruction i imm column narrow negate valid decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl

/-- The actual generic Clight MOV_IMM procedure returns the complete register
view of checked MOVZ/MOVN for every valid native halfword column. The source
literal follows the audited live alias normalizer; Python admission itself,
physical memory bindings and program control remain separate obligations. -/
theorem call_corresponds {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (i : Fin 31) (imm : BitVec 16)
    (column : Fin 4) (narrow negate : Bool) (valid : narrow = true → column.val < 2)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm column narrow negate)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, InternalRun Arm64NumericProgram.ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.arguments (operands unused entry.block i (literal imm column narrow negate)) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  obtain ⟨after, run, rep⟩ := call_represents storage unused i (literal imm column narrow negate) narrow addresses origins s represented
  rw [reference_step s instruction i imm column narrow negate valid decoded noError fetched]
  exact ⟨after, run,
    (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate s i (literal imm column narrow negate) narrow) (read_pc s.machine + 4#64)).mpr rep,
    rfl, rfl⟩

end KProgFormal.ClightRefinement.Arm64MovImmediate.Wide
