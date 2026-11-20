import KProgFormal.ClightRefinement.Arm64MovKeepOrdinary

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovKeep.Native

/-- Narrow the actual source insertion to the native W32 insertion. -/
theorem merge_low_word (old : BitVec 64) (imm : BitVec 16) (column : Fin 4) :
    (merge old imm column).setWidth 32 =
      BitVec.partInstall (16 * column.val) 16 imm (old.setWidth 32) := by
  rw [merge_eq_partInstall]
  simp +decide only [BitVec.partInstall, BitVec.setWidth_or, BitVec.setWidth_and,
    BitVec.setWidth_not, BitVec.setWidth_shiftLeft_of_le, BitVec.setWidth_setWidth_of_le]

abbrev fields (i : Fin 31) (imm : BitVec 16) (column : Fin 4) (narrow : Bool) : Move_wide_imm_cls :=
  { sf := if narrow then 0 else 1, opc := 3,
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

private theorem execute_x (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16)
    (column : Fin 4) :
    DPI.exec_move_wide_imm (fields i imm column false) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) false)).machine := by
  simp +decide only [fields, DPI.exec_move_wide_imm, column_offset, ite_true, ite_false]
  simp +decide [write_gpr_zr, read_gpr_zr,
    ordinary i, read_gpr, write_gpr, Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate,
    Arm64RegisterWrite.written, Reference.AArch64.gpr, merge_eq_partInstall, read_pc, r_of_w_different]

private theorem execute_w (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16)
    (column : Fin 4) (valid : column.val < 2) :
    DPI.exec_move_wide_imm (fields i imm column true) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) true)).machine := by
  simp +decide only [fields, DPI.exec_move_wide_imm, column_offset, column_legal column valid,
    ite_true, ite_false]
  simp only [Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written, ite_true, merge_low_word]
  simp [write_gpr_zr, read_gpr_zr, ordinary i, read_gpr, write_gpr,
    Arm64Nop.atCursor, Reference.AArch64.gpr, read_pc, r_of_w_different]

private theorem execute (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16)
    (column : Fin 4) (narrow : Bool) (valid : narrow = true → column.val < 2) :
    DPI.exec_move_wide_imm (fields i imm column narrow) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow)).machine := by
  cases narrow
  · exact execute_x s i imm column
  · exact execute_w s i imm column (valid rfl)

/-- Genuine fetched/decoded MOVK checked execution, retaining all other
native state and applying the source width's upper-word clearing. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow)).machine := by
  have decode : decode_raw_inst instruction.encoding =
      some (.DPI (.Move_wide_imm (fields i imm column narrow))) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using
    execute s i imm column narrow valid

/-- Exact checked wrapper with PC+4 and preserved histories: no new event
or fault is introduced by MOVK. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow), [], none⟩ := by
  have history : read_memory_accesses
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow)).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_memory_accesses,
      write_pc, w, write_base_pc, write_base_gpr]
  have afterError : read_err
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow)).machine = .None := by
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different] using noError
  simp only [Reference.AArch64.step,
    native_step s instruction i imm column narrow valid decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl

/-- The actual ordinary scalar MOVK203 call refines the real checked step,
using actual typed cell loads and preserving the original reader frontier. -/
theorem call_corresponds_bound (world : CC.CGenv) (binding : CallBindings world)
    {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, InternalRun world 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.Keep.arguments
          (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  obtain ⟨after, run, rep⟩ := call_scalar_represents_bound world binding storage unused addresses origins s i bits imm column narrow
    word tag represented
  rw [reference_step s instruction i imm column narrow valid decoded noError fetched]
  exact ⟨after, run, (Arm64Registers.cursor after (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow)
      (read_pc s.machine + 4#64)).mpr rep, rfl, rfl⟩

theorem call_corresponds {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, InternalRun Arm64NumericProgram.ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.Keep.arguments
          (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none :=
  call_corresponds_bound Arm64NumericProgram.ge numeric_bindings storage unused addresses origins s instruction
    i bits imm column narrow word tag represented valid decoded noError fetched

end KProgFormal.ClightRefinement.Arm64MovKeep.Native
