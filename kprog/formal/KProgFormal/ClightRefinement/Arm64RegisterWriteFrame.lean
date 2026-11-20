import KProgFormal.ClightRefinement.Arm64RegisterWriteView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64RegisterWrite

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView

private theorem cell_flag : ∀ tags (i : Fin 31) (flag : Fin 4),
    tableCellName tags i ≠ headerSourceName (flagIndex flag) := by decide +kernel
private theorem cell_vector : ∀ tags (i : Fin 31),
    tableCellName tags i ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- The flag reader follows the actual initialized producer pointer. -/
private theorem storage_flag {m memory : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m memory entry) (flag : Fin 4) :
    Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry.block 0)
      (headerField (flagIndex flag)) =
      CC.Mem.load .Mint8unsigned memory (storage.flags flag).block 0 := by
  have pointer := header_field_readback memory entry.block (flagIndex flag) _ (storage.flagPointers flag)
  simp only [Arm64EntryMemory.borrowed, pointer, bind, Option.bind_some, checked_load_eq]
  rfl

/-- Every actual flag-byte local is separate from both written cells. -/
theorem Result.flag {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after) (flag : Fin 4) :
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (headerField (flagIndex flag)) =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      (headerField (flagIndex flag)) := by
  rw [← result.nextblock, storage_flag result.storage, result.nextblock, storage_flag storage]
  exact result.local_load _ _ _ (storage.flags flag).binding
    (cell_flag false i flag) (cell_flag true i flag) .Mint8unsigned 0

/-- Preserve the actual four-field flag reader, without assuming its success. -/
theorem Result.flags {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after) :
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

/-- Reuse the exported-layout vector addresses and initialized pointer slots.
The final raw loads retain failures and undefined values. -/
theorem storage_vector {m memory : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m memory entry) (j : Fin 32) :
    Arm64EntryMemory.vector memory.nextblock memory (.Vptr entry.block 0) j =
      (do let lo ← CC.Mem.load .Mint64 memory storage.vectors.block
            (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false j))
          let hi ← CC.Mem.load .Mint64 memory storage.vectors.block
            (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true j))
          pure (lo, hi)) := by
  have loAddress : Arm64EntryMemory.fieldAddress (.Vptr entry.block 0) Arm64Program._vector_lo =
      some (.Vptr entry.block (CC.Integers.Ptrofs.repr 96)) :=
    Arm64ProducerVectorView.array_address entry.block false
  have hiAddress : Arm64EntryMemory.fieldAddress (.Vptr entry.block 0) Arm64Program._vector_hi =
      some (.Vptr entry.block (CC.Integers.Ptrofs.repr 352)) :=
    Arm64ProducerVectorView.array_address entry.block true
  have loSlot : Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr 96))
        (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val))) =
      some (.Vptr storage.vectors.block (vectorLoopSourceOffset false j)) :=
    Arm64ProducerVectorView.slot_readback memory entry.block false j _ (storage.vectorPointers false j)
  have hiSlot : Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr 352))
        (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val))) =
      some (.Vptr storage.vectors.block (vectorLoopSourceOffset true j)) :=
    Arm64ProducerVectorView.slot_readback memory entry.block true j _ (storage.vectorPointers true j)
  simp only [Arm64EntryMemory.vector, loAddress, hiAddress, bind, Option.bind_some]
  change (do
    let loPointer ← Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr 96))
        (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val)))
    let hiPointer ← Arm64EntryMemory.load memory.nextblock CC.Mptr memory
      (CC.Val.offsetPtr (.Vptr entry.block (CC.Integers.Ptrofs.repr 352))
        (CC.Integers.Ptrofs.repr (CC.sizeof Arm64EntryMemory.composites (CC.tptr CC.tvoid) * j.val)))
    let lo ← Arm64EntryMemory.load memory.nextblock .Mint64 memory loPointer
    let hi ← Arm64EntryMemory.load memory.nextblock .Mint64 memory hiPointer
    pure (lo, hi)) = _
  simp only [loSlot, hiSlot, bind, pure, Option.bind_some, checked_load_eq]

/-- All 32 vector pairs retain their actual borrowed reads. -/
theorem Result.vector {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after) (j : Fin 32) :
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

theorem native_vector (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (j : Fin 32) :
    Reference.AArch64.readVector (nativeUpdate s i value narrow) j = Reference.AArch64.readVector s j := by
  apply r_of_w_different
  intro equal
  cases equal

theorem native_flag (s : Reference.AArch64.State) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (flag : PFlag) :
    read_flag flag (nativeUpdate s i value narrow).machine = read_flag flag s.machine := by
  apply r_of_w_different
  intro equal
  cases equal

/-- The same actual writer result preserves the full existing register
relation: all GPRs, SP, SIMD pairs and NZCV. Native physical memory and the
source caller/instruction step remain separate obligations. -/
theorem Result.represents {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock after (.Vptr entry.block 0) (nativeUpdate s i value narrow) := by
  refine ⟨result.gpr_update addresses origins s represented,
    result.sp_update addresses origins s represented, ?_, ?_⟩
  · intro j
    rw [result.vector, native_vector]
    exact represented.vectors j
  · simpa only [Arm64Nop.FlagsRepresent, result.flags, native_flag] using represented.flags

/-- Store success, all 67 actual internal transitions and full register
correspondence are derived from the same producer resource and pre-relation. -/
theorem write_represents {m before : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, Result storage i value narrow after ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeUpdate s i value narrow) := by
  obtain ⟨after, result⟩ := write storage i value narrow
  exact ⟨after, result, result.represents addresses origins s represented⟩

/-- All finite executions are silent prefixes of this same register-refining
return. Every stuck endpoint is that return; an infinite execution is impossible.
Candidate relational traces are arbitrary, not assumed silent. -/
theorem write_all_behaviors {m before : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, Result storage i value narrow after ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (nativeUpdate s i value narrow) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) (arguments entry.block i value narrow) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal procedure) (arguments entry.block i value narrow) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal procedure) (arguments entry.block i value narrow) .Kstop before ∧
        ∀ j, ∃ t, CC.Step2 ge (states j) t (states (j + 1))) := by
  obtain ⟨after, result, registers⟩ := write_represents storage i value narrow addresses origins s represented
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨after, result, registers,
    fun _ _ observed => result.run.finish_prefix stuck observed,
    fun _ _ observed endpoint => result.run.endpoint_unique stuck observed endpoint,
    result.run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64RegisterWrite
