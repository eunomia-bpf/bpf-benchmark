import KProgFormal.ClightRefinement.Arm64PointerWriteLinked

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64PointerWrite

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64RegisterWrite (storage_gpr storage_flag storage_vector)

private theorem cell_header : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ Arm64Entry._entry := by decide +kernel
private theorem cell_table : ∀ tags selected (i : Fin 31),
    tableCellName tags i ≠ tableName selected := by decide +kernel
private theorem cell_sp : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ headerSourceName 5 := by decide +kernel

/-- The actual stores retain the same allocation-bound tables, writable cells
and SP local. No second producer run or new choice of storage is used. -/
def ValueResult.storage {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after) : Storage m after entry where
  tables := storage.tables
  roots := fun tags =>
    (result.local_load _ _ _ entry.binding (cell_header false i) (cell_header true i)
      CC.Mptr _).trans (storage.roots tags)
  slots := fun tags j =>
    (result.local_load _ _ _ (storage.tables tags).binding (cell_table false tags i)
      (cell_table true tags i) CC.Mptr _).trans (storage.slots tags j)
  writable := fun tags j =>
    (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (chunk := cellChunk tags) (b := (storage.tables tags).cellBlock j) (ofs := 0)
      (p := .Writable) (fun offset => by simp only [CC.Mem.perm, result.access])).trans
        (storage.writable tags j)
  sp := storage.sp
  spPointer :=
    (result.local_load _ _ _ entry.binding (cell_header false i) (cell_header true i)
      CC.Mptr 40).trans storage.spPointer
  spValue := storage.spValue
  spRead :=
    (result.local_load _ _ _ storage.sp.binding (cell_sp false i) (cell_sp true i)
      .Mint64 0).trans storage.spRead
  flags := storage.flags
  flagPointers := fun flag =>
    (result.local_load _ _ _ entry.binding (cell_header false i) (cell_header true i)
      CC.Mptr _).trans (storage.flagPointers flag)
  flagWritable := fun flag =>
    (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
      (chunk := .Mint8unsigned) (b := (storage.flags flag).block) (ofs := 0) (p := .Writable)
      (fun ofs => by simp only [CC.Mem.perm, result.access])).trans (storage.flagWritable flag)
  vectors := storage.vectors
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,result.access])).trans storage.vectorWritable
  vectorPointers := fun high j =>
    (result.local_load _ _ _ entry.binding (cell_header false i) (cell_header true i)
      CC.Mptr _).trans (storage.vectorPointers high j)

/-- One reader equation for the complete GPR bank, including failed or
undefined unselected reads. The established reader frontier stays unchanged. -/
theorem ValueResult.gpr {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after) (j : Fin 31) :
    Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) j.val =
      if j = i then some (value, .Vint (tag.setWidth 32))
      else Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [← result.nextblock, storage_gpr result.storage j]
  by_cases same : j = i
  · subst j
    simp only [eq_self, ite_true]
    change (do let word ← CC.Mem.load .Mint64 after ((storage.tables false).cellBlock i) 0
               let tag ← CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock i) 0
               pure (word, tag)) = _
    rw [result.word, result.tag]
    rfl
  · rw [ite_eq_right same, result.nextblock, storage_gpr storage j]
    change (do let word ← CC.Mem.load .Mint64 after ((storage.tables false).cellBlock j) 0
               let tag ← CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock j) 0
               pure (word, tag)) = _
    rw [result.other_cell false j same .Mint64 0,
      result.other_cell true j same .Mint8unsigned 0]

/-- SP still follows the actual signed-long producer local, at the same
reader frontier. Its value is unaffected by the ordinary GPR writes. -/
theorem ValueResult.sp {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after) :
    Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0) Arm64Program._sp =
      Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0) Arm64Program._sp := by
  have initial : Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong storage.spValue) :=
    header_borrowed_readback before entry.block 5 .Mint64 storage.sp.block 0 _ storage.spPointer storage.spRead
  have final : Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong storage.spValue) :=
    header_borrowed_readback after entry.block 5 .Mint64 storage.sp.block 0 _
      result.storage.spPointer result.storage.spRead
  simpa only [result.nextblock] using final.trans initial.symm


/-- The selected raw Clight value, including a pointer, represents the mature
native register value through the same explicit address binding as the reader. -/
theorem ValueResult.gpr_update {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (raw : BitVec 64)
    (valueRep : Arm64Registers.ValueRep addresses value raw)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) (j : Reference.AArch64.Gpr) :
    ∃ word bits observedTag,
      Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) j.val =
        some (word, .Vint (observedTag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses word bits ∧
      Reference.AArch64.gpr (nativeUpdate origins s i raw tag) j =
        Reference.Provenance.AArch64.materialize origins bits observedTag := by
  by_cases same : j = i
  · subst j
    refine ⟨value, raw, tag, ?_, valueRep, ?_⟩
    · simpa only [eq_self, ite_true] using result.gpr i
    · rw [native_gpr, ite_eq_left rfl]
  · obtain ⟨word, bits, observedTag, read, rep, native⟩ := represented.gpr j
    refine ⟨word, bits, observedTag, ?_, rep, ?_⟩
    · rw [result.gpr, ite_eq_right same]
      exact read
    · rw [native_gpr, ite_eq_right same]
      exact native

/-- Both source stores leave the existing stack observation unchanged. -/
theorem ValueResult.sp_update {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (raw : BitVec 64)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ offset, Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong offset) ∧
      Reference.AArch64.sp (nativeUpdate origins s i raw tag) = offset + origins.stack := by
  simp only [result.sp, native_sp]
  exact represented.sp
private theorem cell_flag : ∀ tags (i : Fin 31) (flag : Fin 4),
    tableCellName tags i ≠ headerSourceName (flagIndex flag) := by decide +kernel
private theorem cell_vector : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- Every actual flag-byte local is separate from both written cells. -/
theorem ValueResult.flag {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after) (flag : Fin 4) :
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (headerField (flagIndex flag)) =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      (headerField (flagIndex flag)) := by
  rw [← result.nextblock, storage_flag result.storage, result.nextblock, storage_flag storage]
  exact result.local_load _ _ _ (storage.flags flag).binding
    (cell_flag false i flag) (cell_flag true i flag) .Mint8unsigned 0

/-- Preserve the actual four-field flag reader, without assuming its success. -/
theorem ValueResult.flags {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after) :
    Arm64EntryMemory.flags before.nextblock after (.Vptr entry.block 0) =
      Arm64EntryMemory.flags before.nextblock before (.Vptr entry.block 0) := by
  have n := result.flag 0
  have z := result.flag 1
  have c := result.flag 2
  have v := result.flag 3
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._n = Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before
      (.Vptr entry.block 0) Arm64Program._n at n
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._z = Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before
      (.Vptr entry.block 0) Arm64Program._z at z
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._c = Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before
      (.Vptr entry.block 0) Arm64Program._c at c
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._v = Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before
      (.Vptr entry.block 0) Arm64Program._v at v
  simp only [Arm64EntryMemory.flags, n, z, c, v]

/-- All 32 vector pairs retain their actual borrowed reads. -/
theorem ValueResult.vector {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after) (j : Fin 32) :
    Arm64EntryMemory.vector before.nextblock after (.Vptr entry.block 0) j =
      Arm64EntryMemory.vector before.nextblock before (.Vptr entry.block 0) j := by
  rw [← result.nextblock, storage_vector result.storage, result.nextblock, storage_vector storage]
  change (do let lo ← CC.Mem.load .Mint64 after storage.vectors.block
               (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false j))
             let hi ← CC.Mem.load .Mint64 after storage.vectors.block
               (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true j))
             pure (lo, hi)) = _
  rw [result.local_load _ _ _ storage.vectors.binding (cell_vector false i) (cell_vector true i)
        .Mint64 (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false j)),
      result.local_load _ _ _ storage.vectors.binding (cell_vector false i) (cell_vector true i)
        .Mint64 (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true j))]


/-- The original pointer writer refines the full register bank for both
represented raw constructors, preserving all eight provenance bits. -/
theorem ValueResult.represents {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : CC.Val} {tag : BitVec 8}
    (result : ValueResult storage i value tag after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (raw : BitVec 64)
    (valueRep : Arm64Registers.ValueRep addresses value raw)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock after (.Vptr entry.block 0) (nativeUpdate origins s i raw tag) := by
  refine ⟨result.gpr_update addresses origins s raw valueRep represented,
    result.sp_update addresses origins s raw represented, ?_, ?_⟩
  · intro j
    rw [result.vector, native_vector]
    exact represented.vectors j
  · simpa only [Arm64Nop.FlagsRepresent, result.flags, native_flag] using represented.flags

/-- Successful stores and their complete register relation follow from the
producer storage and pre-relation, including for an explicitly bound Vptr. -/
theorem write_value_represents {m before : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m before entry) (i : Fin 31) (value : CC.Val) (tag : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (raw : BitVec 64)
    (valueRep : Arm64Registers.ValueRep addresses value raw)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, ValueResult storage i value tag after ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeUpdate origins s i raw tag) := by
  obtain ⟨after, result⟩ := write_value storage i value tag addresses raw valueRep
  exact ⟨after, result, result.represents addresses origins s raw valueRep represented⟩

/-- The linked writer uses the original continuation and actual composite
layouts. Its stores and cache frame are derived, rather than postulated. -/
theorem Linked.write_value {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 31) (value : CC.Val) (tag : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (raw : BitVec 64)
    (valueRep : Arm64Registers.ValueRep addresses value raw)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ after, ValueResult storage i value tag after ∧
      InternalRun Arm64ProgramEntryLinked.ge 53
        (.Callstate (.Internal procedure) (valueArguments entry.block i value tag) k before)
        (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeUpdate origins native i raw tag) ∧
      Arm64CacheLocalFrame.Kept initial before after i := by
  obtain ⟨after, result, registers⟩ := write_value_represents storage i value tag addresses origins native raw valueRep represented
  obtain ⟨middle, payload, provenance⟩ := result.stores
  have cast : ∀ memory, CC.Cop.semCast value (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) memory = some value := by
    cases value <;> try contradiction
    all_goals intro memory; rfl
  exact ⟨after, result,
    execute_value_stores_layout Arm64ProgramEntryLinked.ge Linked.layout k valid initial before middle after
      entry storage i value tag cast payload provenance, registers, result.kept⟩

end KProgFormal.ClightRefinement.Arm64PointerWrite
