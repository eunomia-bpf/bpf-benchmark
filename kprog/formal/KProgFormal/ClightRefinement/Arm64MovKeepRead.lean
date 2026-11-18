import KProgFormal.ClightRefinement.Arm64MovKeepCall
import KProgFormal.ClightRefinement.Arm64RegisterReads

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovKeep

/-- Kernel-check the relevant actual layout facts in the linked world.
The standalone and linked composite environments are not identified. -/
theorem reader_layout : Arm64RegisterReads.GprLayout Arm64NumericProgram.ge := by
  constructor <;> decide +kernel

/-- Genuine combined-reader execution in MOVK's linked Numeric world, with
its original arbitrary continuation and exact post-memory. -/
theorem read_nonrelative (addresses : Arm64Registers.PointerOrigins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (memory : CC.Mem) (k : CC.Cont) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (observed : Arm64EntryMemory.gpr frontier memory (.Vptr b ofs) i.val =
      some (value, .Vint (tag.setWidth 32)))
    (represented : Arm64Registers.ValueRep addresses value raw)
    (notStack : tag ≠ 4) (notReturn : tag ≠ 10) :
    InternalRun Arm64NumericProgram.ge 73
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong (BitVec.ofNat 64 i.val)] k memory)
      (.Returnstate value (CC.callCont k) memory) :=
  Arm64RegisterReads.gpr_read_nonrelative_bound Arm64NumericProgram.ge reader_layout
    addresses frontier b ofs i memory k value raw tag observed represented notStack notReturn

/-- Derive the scalar read from the actual producer cell loads. A tag or a
ValueRep witness alone is not used to claim the word is a Vlong. -/
theorem read_scalar {m memory : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m memory entry)
    (addresses : Arm64Registers.PointerOrigins) (i : Fin 31) (bits : BitVec 64) (k : CC.Cont)
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    InternalRun Arm64NumericProgram.ge 73
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0, .Vlong (BitVec.ofNat 64 i.val)] k memory)
      (.Returnstate (.Vlong bits) (CC.callCont k) memory) := by
  have observed : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong bits, .Vint ((0#8).setWidth 32)) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  exact read_nonrelative addresses memory.nextblock entry.block 0 i memory k
    (.Vlong bits) bits 0 observed rfl (by decide) (by decide)

/-- A real scalar writer's successful word/tag stores discharge the next
reader's scalar admission at its reached memory, with the same storage. -/
theorem read_after_write {m before after : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    {storage : Arm64ProducerRegisterStorage.Storage m before entry}
    {i : Fin 31} {bits : BitVec 64} {narrow : Bool}
    (result : Arm64RegisterWrite.Result storage i bits narrow after)
    (addresses : Arm64Registers.PointerOrigins) (k : CC.Cont) :
    InternalRun Arm64NumericProgram.ge 73
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0, .Vlong (BitVec.ofNat 64 i.val)] k after)
      (.Returnstate (.Vlong (Arm64RegisterWrite.written narrow bits)) (CC.callCont k) after) := by
  exact read_scalar result.storage addresses i (Arm64RegisterWrite.written narrow bits) k result.word result.tag

/-- Actual scalar observation and the established register relation identify
the native input bits. No pointer value is coerced into an integer. -/
theorem scalar_native_bits (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (frontier : CC.Block) (memory : CC.Mem) (entry : CC.Val) (i : Fin 31) (bits : BitVec 64)
    (observed : Arm64EntryMemory.gpr frontier memory entry i.val = some (.Vlong bits, .Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier memory entry s) :
    Reference.AArch64.gpr s i = bits := by
  obtain ⟨value, raw, tag, loaded, bitRep, native⟩ := represented.gpr i
  obtain ⟨equalValue, equalTag⟩ := Prod.mk.inj (Option.some.inj (loaded.symm.trans observed))
  cases equalValue
  have tagZero : tag = 0 := by
    have same := CC.Val.Vint.inj equalTag
    simpa using congrArg (fun v : BitVec 32 => v.setWidth 8) same
  subst tag
  change raw = bits at bitRep
  simpa +decide only [Reference.Provenance.AArch64.materialize, bitRep, ite_false] using native

/-- The actual scalar reader returns the native ordinary-register bits in
MOVK's world, from the same cells and complete pre-read register relation. -/
theorem read_scalar_corresponds {m memory : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m memory entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (i : Fin 31) (bits : BitVec 64) (k : CC.Cont)
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      memory.nextblock memory (.Vptr entry.block 0) s) :
    InternalRun Arm64NumericProgram.ge 73
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0, .Vlong (BitVec.ofNat 64 i.val)] k memory)
      (.Returnstate (.Vlong (Reference.AArch64.gpr s i)) (CC.callCont k) memory) := by
  have observed : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong bits, .Vint 0) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  rw [scalar_native_bits addresses origins s memory.nextblock memory (.Vptr entry.block 0)
    i bits observed represented]
  exact read_scalar storage addresses i bits k word tag

/-- Ordinary MOVK reaches the actual writer in 105 transitions from its
branch, including the genuine scalar DST read and unchanged read memory. -/
theorem scalar_writer_call {m memory : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m memory entry)
    (addresses : Arm64Registers.PointerOrigins) (e : CC.Env) (le : CC.TempEnv)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (readerUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writerUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hdst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (himm : le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)))
    (haux : le.get Arm64Program._aux = some (.Vint (aux column)))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow))
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    InternalRun Arm64NumericProgram.ge 105
      (.State Arm64Nop.handler Arm64MovImmediate.Dispatch.Keep.branch
        Arm64MovImmediate.Dispatch.continuation e le memory)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr entry.block 0, .Vlong (BitVec.ofNat 64 i.val), .Vlong (merge bits imm column), Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e (writerTemps le bits imm column)
          Arm64MovImmediate.Dispatch.continuation) memory) := by
  have enter := read_call e le memory entry.block (BitVec.ofNat 64 i.val) readerUnshadowed hentry hdst
  have read := read_scalar storage addresses i bits
    (.Kcall (some Arm64Program._t'6) Arm64Nop.handler e le readCont) word tag
  have finish := writer_call e le memory entry.block (BitVec.ofNat 64 i.val) bits imm column narrow
    writerUnshadowed hentry hdst himm haux hwidth
  simpa only [CC.callCont] using (enter.trans read).trans finish

end KProgFormal.ClightRefinement.Arm64MovKeep
