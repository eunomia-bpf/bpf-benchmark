import KProgFormal.ClightRefinement.Arm64MovImmediateView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate.Movz

/-- A binding to mature decoded fields, not another decoder or ISA body.
Instruction.valid below binds these fields to the actual fetched native word. -/
def fields (i : Fin 31) (imm : BitVec 16) (narrow : Bool) : Move_wide_imm_cls :=
  { sf := if narrow then 0 else 1, opc := 2, hw := 0,
    imm16 := imm, Rd := BitVec.ofNat 5 i.val }

private theorem ordinary (i : Fin 31) : BitVec.ofNat 5 i.val ≠ 31#5 := by
  intro equal
  have bits := congrArg BitVec.toNat equal
  change i.val % 32 = 31 at bits
  have bound := i.isLt
  omega

private theorem install_zero {n : Nat} (imm : BitVec 16) :
    BitVec.partInstall 0 16 imm (0#n) = imm.setWidth n := by
  simp only [BitVec.partInstall, BitVec.zero_and, BitVec.shiftLeft_zero, BitVec.zero_or]

private theorem execute_x (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16) :
    DPI.exec_move_wide_imm (fields i imm false) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (imm.setWidth 64) false)).machine := by
  simp +decide only [fields, DPI.exec_move_wide_imm]
  change write_pc (read_pc (write_gpr_zr 64 (BitVec.ofNat 5 i.val)
      (BitVec.partInstall 0 16 imm (0#64)) s.machine) + 4#64)
    (write_gpr_zr 64 (BitVec.ofNat 5 i.val) (BitVec.partInstall 0 16 imm (0#64)) s.machine) = _
  rw [install_zero]
  simp [write_gpr_zr, write_gpr, ordinary i, Arm64Nop.atCursor,
    Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written, read_pc, r_of_w_different]

private theorem execute_w (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16) :
    DPI.exec_move_wide_imm (fields i imm true) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (imm.setWidth 64) true)).machine := by
  simp +decide only [fields, DPI.exec_move_wide_imm]
  change write_pc (read_pc (write_gpr_zr 32 (BitVec.ofNat 5 i.val)
      (BitVec.partInstall 0 16 imm (0#32)) s.machine) + 4#64)
    (write_gpr_zr 32 (BitVec.ofNat 5 i.val) (BitVec.partInstall 0 16 imm (0#32)) s.machine) = _
  rw [install_zero]
  simp [write_gpr_zr, write_gpr, ordinary i, Arm64Nop.atCursor,
    Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written, read_pc, r_of_w_different]

/-- Evaluate the mature MOVZ body at shift zero for both ordinary W/X forms.
All architectural fields come from LNSym's actual public write operations. -/
private theorem execute (s : Reference.AArch64.State) (i : Fin 31) (imm : BitVec 16) (narrow : Bool) :
    DPI.exec_move_wide_imm (fields i imm narrow) s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (imm.setWidth 64) narrow)).machine := by
  cases narrow
  · exact execute_x s i imm
  · exact execute_w s i imm

/-- Execute the fetched word through LNSym's checked step. Its own decoder
certificate is required; the proof supplies no local instruction classifier. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 16) (narrow : Bool)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (imm.setWidth 64) narrow)).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPI (.Move_wide_imm (fields i imm narrow))) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using execute s i imm narrow

/-- Preserve existing native histories and all frame fields while reporting
exactly the new empty event/fault delta and actual PC+4 update. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (imm : BitVec 16) (narrow : Bool)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (imm.setWidth 64) narrow), [], none⟩ := by
  have history : read_memory_accesses
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (imm.setWidth 64) narrow)).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_memory_accesses, write_pc, w, write_base_pc, write_base_gpr]
  have afterError : read_err
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s i (imm.setWidth 64) narrow)).machine = .None := by
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err, write_pc, r_of_w_different] using noError
  simp only [Reference.AArch64.step, native_step s instruction i imm narrow decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl

/-- The real Clight MOV_IMM call returns the complete register view of the
actual checked native MOVZ result. Native fetch/decoding, ordinary destination,
zero shift and source operand bindings are explicit. Physical memory/control
and producer initialization remain separate program-level obligations. -/
theorem call_corresponds {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (i : Fin 31) (imm : BitVec 16) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, InternalRun Arm64NumericProgram.ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.arguments (operands unused entry.block i (imm.setWidth 64)) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  obtain ⟨after, run, rep⟩ := call_represents storage unused i (imm.setWidth 64) narrow addresses origins s represented
  rw [reference_step s instruction i imm narrow decoded noError fetched]
  exact ⟨after, run,
    (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate s i (imm.setWidth 64) narrow) (read_pc s.machine + 4#64)).mpr rep,
    rfl, rfl⟩

end KProgFormal.ClightRefinement.Arm64MovImmediate.Movz
