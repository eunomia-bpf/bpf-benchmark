import KProgFormal.ClightRefinement.Arm64MovKeepNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkedBindings

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovKeep.Linked

open Arm64ProgramEntryLinked

/-- Closed checks for the actual merged layouts, with no equality between
complete composite environments or global symbol tables. -/
theorem reader_layout : Arm64RegisterReads.GprLayout ge := by
  constructor <;> decide +kernel

theorem writer_layout : Arm64RegisterWrite.GprLayout ge := by
  constructor <;> decide +kernel

/-- These are the actual linked symbols and original C definitions. -/
theorem reader_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_read =
      some (CC.Positive.ofNat 66) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 66) =
      some (.Internal Arm64Program.f_kprog_arm64_program_read) := by
  constructor <;> run_tac sourceEquality

theorem writer_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_write =
      some (CC.Positive.ofNat 107) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 107) =
      some (.Internal Arm64RegisterWrite.procedure) := by
  constructor <;> run_tac sourceEquality

/-- The same real scalar reader executes in the actual fixture/handler link. -/
theorem read_scalar {m memory : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m memory entry)
    (addresses : Arm64Registers.PointerOrigins) (i : Fin 31) (bits : BitVec 64) (k : CC.Cont)
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    InternalRun ge 73
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0, .Vlong (BitVec.ofNat 64 i.val)] k memory)
      (.Returnstate (.Vlong bits) (CC.callCont k) memory) :=
  Arm64MovKeep.read_scalar_bound ge reader_layout storage addresses i bits k word tag

/-- Writable producer cells derive both successful stores. Their original
memory-effect certificate is paired with execution in this linked world and
an arbitrary call continuation; no post-state or successful store is assumed. -/
theorem write_scalar {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after, Arm64RegisterWrite.Result storage i value narrow after ∧
      InternalRun ge 67
        (.Callstate (.Internal Arm64RegisterWrite.procedure)
          (Arm64RegisterWrite.arguments entry.block i value narrow) k before)
        (.Returnstate .Vundef k after) := by
  obtain ⟨after, result⟩ := Arm64RegisterWrite.write storage i value narrow
  obtain ⟨middle, wordStore, tagStore⟩ := result.stores
  exact ⟨after, result, Arm64RegisterWrite.execute_stores_layout ge writer_layout k hk
    m before middle after entry storage i value narrow wordStore tagStore⟩

/-- Execute the actual scalar MOVK branch, including its reader call,
read, merge, writer call, stores and return to the live generic frame. -/
theorem branch_returns {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (addresses : Arm64Registers.PointerOrigins) (e : CC.Env) (le : CC.TempEnv)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (readerUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writerUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (himm : le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column)))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow))
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    ∃ after, Arm64RegisterWrite.Result storage i (merge bits imm column) narrow after ∧
      InternalRun ge 175
        (.State Arm64Nop.handler Arm64MovImmediate.Dispatch.Keep.branch
          Arm64MovImmediate.Dispatch.continuation e le before)
        (.State Arm64Nop.handler .Sskip .Kstop e (writerTemps le bits imm column) after) := by
  have call := scalar_writer_call_bound ge (CC.Positive.ofNat 66) (CC.Positive.ofNat 107)
    reader_binding writer_binding reader_layout storage addresses e le i bits imm column narrow
    readerUnshadowed writerUnshadowed hentry hdst himm haux hwidth word tag
  obtain ⟨after, result, write⟩ := write_scalar storage i (merge bits imm column) narrow
    (.Kcall none Arm64Nop.handler e (writerTemps le bits imm column)
      Arm64MovImmediate.Dispatch.continuation) rfl
  have finish := Arm64MovImmediate.Suffix.after_writer_bound ge e (writerTemps le bits imm column) after
  exact ⟨after, result, (call.trans write).trans finish⟩

/-- The complete reached branch refines the fetched LNSym MOVK step in the
actual linked world. Generic dispatch, frame release and the outer fixture
call remain separate; this theorem does not claim a complete handler call. -/
theorem branch_corresponds {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (e : CC.Env) (le : CC.TempEnv)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (readerUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writerUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (himm : le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column)))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow))
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (Native.fields i imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, Arm64RegisterWrite.Result storage i (merge bits imm column) narrow after ∧
      InternalRun ge 175
        (.State Arm64Nop.handler Arm64MovImmediate.Dispatch.Keep.branch
          Arm64MovImmediate.Dispatch.continuation e le before)
        (.State Arm64Nop.handler .Sskip .Kstop e (writerTemps le bits imm column) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  have observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) i.val =
      some (.Vlong bits, .Vint 0) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  have nativeBits := scalar_native_bits addresses origins s before.nextblock before
    (.Vptr entry.block 0) i bits observed represented
  obtain ⟨after, result, run⟩ := branch_returns storage addresses e le i bits imm column narrow
    readerUnshadowed writerUnshadowed hentry hdst himm haux hwidth word tag
  have registers := result.represents addresses origins s represented
  rw [Native.reference_step s instruction i imm column narrow valid decoded noError fetched]
  rw [← nativeBits] at registers
  exact ⟨after, result, run,
    (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow)
        (read_pc s.machine + 4#64)).mpr registers, rfl, rfl⟩

end KProgFormal.ClightRefinement.Arm64MovKeep.Linked
