import KProgFormal.ClightRefinement.Arm64PointerWrite

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
def Result.storage {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after) : Storage m after entry where
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
theorem Result.gpr {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after) (j : Fin 31) :
    Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) j.val =
      if j = i then some (.Vlong value, .Vint (tag.setWidth 32))
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
theorem Result.sp {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after) :
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

/-- Materialize the retained raw payload/tag exactly once for the mature native write. -/
def nativeUpdate (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8) : Reference.AArch64.State :=
  Arm64RegisterWrite.nativeUpdate s i (Reference.Provenance.AArch64.materialize origins value tag) false

theorem native_gpr (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8) (j : Fin 31) :
    Reference.AArch64.gpr (nativeUpdate origins s i value tag) j =
      if j = i then Reference.Provenance.AArch64.materialize origins value tag else Reference.AArch64.gpr s j := by
  exact Arm64RegisterWrite.native_gpr s i (Reference.Provenance.AArch64.materialize origins value tag) false j

theorem native_sp (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8) :
    Reference.AArch64.sp (nativeUpdate origins s i value tag) = Reference.AArch64.sp s :=
  Arm64RegisterWrite.native_sp s i (Reference.Provenance.AArch64.materialize origins value tag) false

/-- Every GPR observation of the actual writer agrees with the mature native
write. The identity cell map is explicit; no arbitrary map is assumed injective.
This GPR-bank law is not a complete instruction or non-GPR frame theorem. -/
theorem Result.gpr_update {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) (j : Reference.AArch64.Gpr) :
    ∃ word raw observedTag,
      Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) j.val =
        some (word, .Vint (observedTag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses word raw ∧
      Reference.AArch64.gpr (nativeUpdate origins s i value tag) j =
        Reference.Provenance.AArch64.materialize origins raw observedTag := by
  by_cases same : j = i
  · subst j
    refine ⟨.Vlong value, value, tag, ?_, rfl, ?_⟩
    · change Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) i.val =
        some (.Vlong value, .Vint (tag.setWidth 32))
      simpa only [eq_self, ite_true] using result.gpr i
    · rw [native_gpr, ite_eq_left rfl]
  · obtain ⟨word, raw, tag, read, bits, native⟩ := represented.gpr j
    refine ⟨word, raw, tag, ?_, bits, ?_⟩
    · rw [result.gpr, ite_eq_right same]
      exact read
    · rw [native_gpr, ite_eq_right same]
      exact native

/-- The existing SP representation survives the same actual procedure result
and agrees with the external machine's unchanged SP. -/
theorem Result.sp_update {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ offset, Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong offset) ∧
      Reference.AArch64.sp (nativeUpdate origins s i value tag) = offset + origins.stack := by
  simp only [result.sp, native_sp]
  exact represented.sp
private theorem cell_flag : ∀ tags (i : Fin 31) (flag : Fin 4),
    tableCellName tags i ≠ headerSourceName (flagIndex flag) := by decide +kernel
private theorem cell_vector : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- Every actual flag-byte local is separate from both written cells. -/
theorem Result.flag {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after) (flag : Fin 4) :
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (headerField (flagIndex flag)) =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      (headerField (flagIndex flag)) := by
  rw [← result.nextblock, storage_flag result.storage, result.nextblock, storage_flag storage]
  exact result.local_load _ _ _ (storage.flags flag).binding
    (cell_flag false i flag) (cell_flag true i flag) .Mint8unsigned 0

/-- Preserve the actual four-field flag reader, without assuming its success. -/
theorem Result.flags {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after) :
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
theorem Result.vector {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after) (j : Fin 32) :
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

theorem native_vector (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8) (j : Fin 32) :
    Reference.AArch64.readVector (nativeUpdate origins s i value tag) j = Reference.AArch64.readVector s j :=
  Arm64RegisterWrite.native_vector s i (Reference.Provenance.AArch64.materialize origins value tag) false j

theorem native_flag (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8) (flag : PFlag) :
    read_flag flag (nativeUpdate origins s i value tag).machine = read_flag flag s.machine :=
  Arm64RegisterWrite.native_flag s i (Reference.Provenance.AArch64.materialize origins value tag) false flag

/-- The same actual writer result preserves the full existing register
relation: all GPRs, SP, SIMD pairs and NZCV. Native physical memory and the
source caller/instruction step remain separate obligations. -/
theorem Result.represents {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Result storage i value tag after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock after (.Vptr entry.block 0) (nativeUpdate origins s i value tag) := by
  refine ⟨result.gpr_update addresses origins s represented,
    result.sp_update addresses origins s represented, ?_, ?_⟩
  · intro j
    rw [result.vector, native_vector]
    exact represented.vectors j
  · simpa only [Arm64Nop.FlagsRepresent, result.flags, native_flag] using represented.flags

/-- Store success, all 53 actual internal transitions and full register
correspondence are derived from the same producer resource and pre-relation. -/
theorem write_represents {m before : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, Result storage i value tag after ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeUpdate origins s i value tag) := by
  obtain ⟨after, result⟩ := write storage i value tag
  exact ⟨after, result, result.represents addresses origins s represented⟩

/-- All finite executions are silent prefixes of this same register-refining
return. Every stuck endpoint is that return; an infinite execution is impossible.
Candidate relational traces are arbitrary, not assumed silent. -/
theorem write_all_behaviors {m before : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (tag : BitVec 8)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, Result storage i value tag after ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeUpdate origins s i value tag) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) (arguments entry.block i value tag) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) (arguments entry.block i value tag) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal procedure) (arguments entry.block i value tag) .Kstop before ∧
        ∀ j, ∃ t, CC.Step2 ge (states j) t (states (j + 1))) := by
  obtain ⟨after, result, registers⟩ := write_represents storage i value tag addresses origins s represented
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨after, result, registers,
    fun _ _ observed => result.run.finish_prefix stuck observed,
    fun _ _ observed endpoint => result.run.endpoint_unique stuck observed endpoint,
    result.run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64PointerWrite
