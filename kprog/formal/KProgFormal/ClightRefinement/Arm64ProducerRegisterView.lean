import KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerRegisterView

open Arm64Producer
open Arm64ProducerEntryView

/-- One real header/loop execution establishes the existing complete register
relation over one reached memory and frontier. Source data and native ABI
bindings are explicit; provider outcomes, physical origins and the architectural
cell map are not inferred from values or independently chosen executions. -/
theorem producer_registers_with_storage
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (cells : Reference.AArch64.Gpr → Fin 31)
    (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (s : Reference.AArch64.State)
    (values : Fin 31 → CC.Val) (raw : Fin 31 → BitVec 64) (kinds : Fin 31 → BitVec 8)
    (sp : BitVec 64) (access : before.access = (allocation m).2.access)
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (values i))
    (tagsBefore : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint ((kinds i).setWidth 32)))
    (flagsBefore : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (flagIndex i)) = some (block, headerSourceType (flagIndex i)) →
      CC.Mem.load .Mint8unsigned before block 0 = some (flagValues s i))
    (vectorsBefore : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType) →
      ∀ high i, CC.Mem.load .Mint64 before block
        (16 * (i.val : Int) + (if high then 8 else 0)) =
        some (.Vlong (Arm64ProducerVectorView.vectorHalf s high i)))
    (spBefore : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong sp))
    (represented : ∀ i, Arm64Registers.ValueRep addresses (values i) (raw i))
    (nativeGpr : ∀ r, Reference.AArch64.gpr s r =
      Reference.Provenance.AArch64.materialize origins (raw (cells r)) (kinds (cells r)))
    (nativeSp : Reference.AArch64.sp s = sp + origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => (cells r).val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      Nonempty (Arm64ProducerRegisterStorage.Storage m after entry) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, header, _, vectors, after, finalLe, run, _, _, pointers, vectorPointers, _,
      locals, frame, accessAfter, next⟩ := header_initialized_before_consumer m before le k access
  obtain ⟨words, wordSlots⟩ := tablesBefore false
  obtain ⟨tags, tagSlots⟩ := tablesBefore true
  have tableOther : ∀ tags, tableName tags ≠ Arm64Entry._entry := by decide +kernel
  have cellOther : ∀ tags (i : Fin 31), tableCellName tags i ≠ Arm64Entry._entry := by decide +kernel
  let sourceTables : (selected : Bool) → TableLocals selected m
    | false => words
    | true => tags
  have tableSlots : ∀ selected (i : Fin 31),
      CC.Mem.load CC.Mptr after (sourceTables selected).tableBlock (8 * (i.val : Int)) =
        some (.Vptr ((sourceTables selected).cellBlock i) 0) := by
    intro selected i
    cases selected
    · rw [locals _ _ _ words.binding (tableOther false) CC.Mptr (8 * (i.val : Int))]
      exact wordSlots i
    · rw [locals _ _ _ tags.binding (tableOther true) CC.Mptr (8 * (i.val : Int))]
      exact tagSlots i
  have gprs : ∀ i : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val =
      some (values i, .Vint ((kinds i).setWidth 32)) := by
    apply Arm64ProducerGprView.table_gpr_readbacks m after entry header words tags values kinds pointers
    · exact tableSlots false
    · exact tableSlots true
    · intro i
      rw [locals _ _ _ (words.cellBinding i) (cellOther false i) .Mint64 0]
      exact wordsBefore i _ (words.cellBinding i)
    · intro i
      rw [locals _ _ _ (tags.cellBinding i) (cellOther true i) .Mint8unsigned 0]
      exact tagsBefore i _ (tags.cellBinding i)
  have flagReads : Arm64Nop.FlagsRepresent after.nextblock after (.Vptr entry.block 0) s := by
    apply header_flags_represent after entry.block (fun i => (header i).block) s pointers
    intro i
    have different : ∀ i : Fin 4, headerSourceName (flagIndex i) ≠ Arm64Entry._entry := by decide +kernel
    rw [locals _ _ _ (header (flagIndex i)).binding (different i) .Mint8unsigned 0]
    exact flagsBefore i _ (header (flagIndex i)).binding
  have vectorReads : ∀ i : Fin 32, Arm64EntryMemory.vector after.nextblock after (.Vptr entry.block 0) i =
      some (.Vlong ((Reference.AArch64.readVector s i).setWidth 64),
        .Vlong (((Reference.AArch64.readVector s i) >>> 64).setWidth 64)) := by
    apply Arm64ProducerVectorView.vector_readbacks m after entry vectors
      (fun high i => .Vlong (Arm64ProducerVectorView.vectorHalf s high i)) vectorPointers
    intro high i
    have different : Arm64Entry.___a64_vectors ≠ Arm64Entry._entry := by decide +kernel
    rw [locals _ _ _ vectors.binding different .Mint64 (16 * (i.val : Int) + (if high then 8 else 0))]
    exact vectorsBefore vectors.block vectors.binding high i
  have spData : CC.Mem.load .Mint64 after (header 5).block 0 = some (.Vlong sp) := by
    have different : headerSourceName 5 ≠ Arm64Entry._entry := by decide +kernel
    rw [locals _ _ _ (header 5).binding different .Mint64 0]
    exact spBefore _ (header 5).binding
  have spRead : Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong sp) :=
    header_borrowed_readback after entry.block 5 .Mint64 (header 5).block 0 (.Vlong sp) (pointers 5) spData
  have storage : Nonempty (Arm64ProducerRegisterStorage.Storage m after entry) :=
    ⟨Arm64ProducerRegisterStorage.of_header m after entry header sourceTables (accessAfter.trans access)
      pointers tableSlots sp spData⟩
  refine ⟨entry, after, finalLe, run, ?_, storage, frame, accessAfter, next⟩
  refine ⟨?_, ⟨sp, spRead, nativeSp⟩, vectorReads, flagReads⟩
  intro r
  exact ⟨values (cells r), raw (cells r), kinds (cells r), gprs (cells r), represented _, nativeGpr r⟩

/-- Existing observer API is the projection of the same stronger execution;
no independent header run or reached-memory identification is introduced. -/
theorem producer_registers_initialized
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (cells : Reference.AArch64.Gpr → Fin 31)
    (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (s : Reference.AArch64.State)
    (values : Fin 31 → CC.Val) (raw : Fin 31 → BitVec 64) (kinds : Fin 31 → BitVec 8)
    (sp : BitVec 64) (access : before.access = (allocation m).2.access)
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (values i))
    (tagsBefore : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint ((kinds i).setWidth 32)))
    (flagsBefore : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (flagIndex i)) = some (block, headerSourceType (flagIndex i)) →
      CC.Mem.load .Mint8unsigned before block 0 = some (flagValues s i))
    (vectorsBefore : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType) →
      ∀ high i, CC.Mem.load .Mint64 before block
        (16 * (i.val : Int) + (if high then 8 else 0)) =
        some (.Vlong (Arm64ProducerVectorView.vectorHalf s high i)))
    (spBefore : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong sp))
    (represented : ∀ i, Arm64Registers.ValueRep addresses (values i) (raw i))
    (nativeGpr : ∀ r, Reference.AArch64.gpr s r =
      Reference.Provenance.AArch64.materialize origins (raw (cells r)) (kinds (cells r)))
    (nativeSp : Reference.AArch64.sp s = sp + origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => (cells r).val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, after, finalLe, run, registers, _, frame, finalAccess, next⟩ :=
    producer_registers_with_storage addresses origins cells m before le k s values raw kinds sp access tablesBefore wordsBefore tagsBefore flagsBefore vectorsBefore spBefore represented nativeGpr nativeSp
  exact ⟨entry, after, finalLe, run, registers, frame, finalAccess, next⟩

end KProgFormal.ClightRefinement.Arm64ProducerRegisterView
