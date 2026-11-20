import KProgFormal.ClightRefinement.Arm64ProducerRegisterView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64EntryAdmissibility

open Arm64Producer

/-- RAW entry replaces x0 with context and gives the zero x30 payload its
actual return origin. The other cells retain their scalar input words. -/
def rawWord (ctxWord : BitVec 64) (inputs : Fin 31 → BitVec 64) (i : Fin 31) : BitVec 64 :=
  if i = 0 then ctxWord else if i = 30 then 0 else inputs i

def rawValue (ctx : CC.Val) (inputs : Fin 31 → BitVec 64) (i : Fin 31) : CC.Val :=
  if i = 0 then ctx else .Vlong (if i = 30 then 0 else inputs i)

def rawTag (i : Fin 31) : BitVec 8 := if i = 0 then 1 else if i = 30 then 10 else 0

/-- The RAW word view reuses the context pointer binding and scalar bits.
No architectural relation is assumed to obtain these value representations. -/
theorem raw_values_represent (addresses : Arm64Registers.PointerOrigins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (inputs : Fin 31 → BitVec 64)
    (represented : Arm64Registers.ValueRep addresses ctx ctxWord) :
    ∀ i, Arm64Registers.ValueRep addresses (rawValue ctx inputs i) (rawWord ctxWord inputs i) := by
  intro i
  by_cases zero : i = 0
  · simpa [rawValue, rawWord, zero] using represented
  · simp [rawValue, rawWord, zero, Arm64Registers.ValueRep]

/-- Actual context/return/ordinary-register ABI bindings imply exactly the
existing M3 materialization law for every RAW cell. -/
theorem raw_native_registers (origins : Reference.Provenance.AArch64.Origins)
    (ctxWord : BitVec 64) (inputs : Fin 31 → BitVec 64) (s : Reference.AArch64.State)
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i) :
    ∀ i, Reference.AArch64.gpr s i =
      Reference.Provenance.AArch64.materialize origins (rawWord ctxWord inputs i) (rawTag i) := by
  intro i
  by_cases zero : i = 0
  · subst i
    simpa [rawWord, rawTag, Reference.Provenance.AArch64.materialize] using nativeContext
  · by_cases lr : i = 30
    · subst i
      simpa [rawWord, rawTag, Reference.Provenance.AArch64.materialize] using nativeReturn
    · simpa [rawWord, rawTag, zero, lr, Reference.Provenance.AArch64.materialize] using nativeOther i zero lr

/-- Compose the actual stack/SP/context stores with the header execution.
Final SP, x0 data and x0/x30 tags are derived from C, not supplied as final
readback premises. Input words, flags/vectors and same-invocation native
bindings remain explicit. The architectural cell map is the source index. -/
theorem raw_registers_initialized_with_storage
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (access : before.access = (allocation m).2.access)
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong (if i = 30 then 0 else inputs i)))
    (tagsBefore : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint 0))
    (flagsBefore : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (Arm64ProducerEntryView.flagIndex i)) =
        some (block, headerSourceType (Arm64ProducerEntryView.flagIndex i)) →
      CC.Mem.load .Mint8unsigned before block 0 = some (Arm64ProducerEntryView.flagValues s i))
    (vectorsBefore : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType) →
      ∀ high i, CC.Mem.load .Mint64 before block (16 * (i.val : Int) + (if high then 8 else 0)) =
        some (.Vlong (Arm64ProducerVectorView.vectorHalf s high i)))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun ge 728 (.State producer afterVectorInputs k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      Nonempty (Arm64ProducerRegisterStorage.Storage m after entry) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨_, spBlock, cells, middle, spBinding, setup, _, spRead, contextReads,
      other, frame, accessMiddle, nextMiddle⟩ :=
    stack_sp_and_context represented m before le input k access
  have wordSeparate : ∀ i : Fin 31, i ≠ 0 →
      tableCellName false i ≠ Arm64Entry.___a64_stack_tag ∧
      tableCellName false i ≠ Arm64Entry.___a64_sp ∧
      ∀ j : Fin 5, tableCellName false i ≠ contextName j := by decide +kernel
  have tagSeparate : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 →
      tableCellName true i ≠ Arm64Entry.___a64_stack_tag ∧
      tableCellName true i ≠ Arm64Entry.___a64_sp ∧
      ∀ j : Fin 5, tableCellName true i ≠ contextName j := by decide +kernel
  have words : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 middle block 0 = some (rawValue ctx inputs i) := by
    intro i block bound
    by_cases zero : i = 0
    · subst i
      have same : block = (cells 2).block :=
        congrArg Prod.fst (Option.some.inj (bound.symm.trans (cells 2).binding))
      subst block
      exact contextReads 2
    · have separate := wordSeparate i zero
      rw [other _ _ _ bound separate.1 separate.2.1 separate.2.2 .Mint64 0]
      simpa [rawValue, zero] using wordsBefore i zero block bound
  have tags : ∀ (i : Fin 31) (block : CC.Block),
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned middle block 0 = some (.Vint ((rawTag i).setWidth 32)) := by
    intro i block bound
    by_cases zero : i = 0
    · subst i
      have same : block = (cells 4).block :=
        congrArg Prod.fst (Option.some.inj (bound.symm.trans (cells 4).binding))
      subst block
      exact contextReads 4
    · by_cases lr : i = 30
      · subst i
        have same : block = (cells 3).block :=
          congrArg Prod.fst (Option.some.inj (bound.symm.trans (cells 3).binding))
        subst block
        exact contextReads 3
      · have separate := tagSeparate i zero lr
        rw [other _ _ _ bound separate.1 separate.2.1 separate.2.2 .Mint8unsigned 0]
        simpa [rawTag, zero, lr] using tagsBefore i zero lr block bound
  have tables : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr middle table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0) := by
    intro tags
    obtain ⟨table, reads⟩ := tablesBefore tags
    have separate : ∀ tags, tableName tags ≠ Arm64Entry.___a64_stack_tag ∧
        tableName tags ≠ Arm64Entry.___a64_sp ∧ ∀ j : Fin 5, tableName tags ≠ contextName j := by decide +kernel
    refine ⟨table, ?_⟩
    intro i
    rw [other _ _ _ table.binding (separate tags).1 (separate tags).2.1 (separate tags).2.2 CC.Mptr (8 * (i.val : Int))]
    exact reads i
  have flags : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (Arm64ProducerEntryView.flagIndex i)) =
        some (block, headerSourceType (Arm64ProducerEntryView.flagIndex i)) →
      CC.Mem.load .Mint8unsigned middle block 0 = some (Arm64ProducerEntryView.flagValues s i) := by
    intro i block bound
    have separate : ∀ i : Fin 4,
        headerSourceName (Arm64ProducerEntryView.flagIndex i) ≠ Arm64Entry.___a64_stack_tag ∧
        headerSourceName (Arm64ProducerEntryView.flagIndex i) ≠ Arm64Entry.___a64_sp ∧
        ∀ j : Fin 5, headerSourceName (Arm64ProducerEntryView.flagIndex i) ≠ contextName j := by decide +kernel
    rw [other _ _ _ bound (separate i).1 (separate i).2.1 (separate i).2.2 .Mint8unsigned 0]
    exact flagsBefore i block bound
  have vectors : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType) →
      ∀ high i, CC.Mem.load .Mint64 middle block (16 * (i.val : Int) + (if high then 8 else 0)) =
        some (.Vlong (Arm64ProducerVectorView.vectorHalf s high i)) := by
    intro block bound high i
    have separate : Arm64Entry.___a64_vectors ≠ Arm64Entry.___a64_stack_tag ∧
        Arm64Entry.___a64_vectors ≠ Arm64Entry.___a64_sp ∧
        ∀ j : Fin 5, Arm64Entry.___a64_vectors ≠ contextName j := by decide +kernel
    rw [other _ _ _ bound separate.1 separate.2.1 separate.2.2 .Mint64 (16 * (i.val : Int) + (if high then 8 else 0))]
    exact vectorsBefore block bound high i
  have sp : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) →
      CC.Mem.load .Mint64 middle block 0 = some (.Vlong 0) := by
    intro block bound
    have same : block = spBlock := congrArg Prod.fst (Option.some.inj (bound.symm.trans spBinding))
    subst block
    exact spRead
  have valuesRep := raw_values_represent addresses ctx ctxWord inputs represented
  have native := raw_native_registers origins ctxWord inputs s nativeContext nativeReturn nativeOther
  obtain ⟨entry, after, finalLe, headerRun, registers, storage, headerFrame, headerAccess, headerNext⟩ :=
    Arm64ProducerRegisterView.producer_registers_with_storage addresses origins (fun i => i)
      m middle le k s (rawValue ctx inputs) (rawWord ctxWord inputs) rawTag 0
      (accessMiddle.trans access) tables words tags flags vectors sp valuesRep native
      (by simpa using nativeSp)
  exact ⟨entry, after, finalLe, setup.trans headerRun, registers, storage, frame.trans headerFrame,
    headerAccess.trans accessMiddle, headerNext.trans nextMiddle⟩

/-- Observer projection of the same resource-carrying source execution. -/
theorem raw_registers_initialized
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (access : before.access = (allocation m).2.access)
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong (if i = 30 then 0 else inputs i)))
    (tagsBefore : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint 0))
    (flagsBefore : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (Arm64ProducerEntryView.flagIndex i)) =
        some (block, headerSourceType (Arm64ProducerEntryView.flagIndex i)) →
      CC.Mem.load .Mint8unsigned before block 0 = some (Arm64ProducerEntryView.flagValues s i))
    (vectorsBefore : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType) →
      ∀ high i, CC.Mem.load .Mint64 before block (16 * (i.val : Int) + (if high then 8 else 0)) =
        some (.Vlong (Arm64ProducerVectorView.vectorHalf s high i)))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun ge 728 (.State producer afterVectorInputs k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, after, finalLe, run, registers, _, frame, access, next⟩ :=
    raw_registers_initialized_with_storage addresses origins ctx ctxWord represented m before le input k s inputs access tablesBefore wordsBefore tagsBefore flagsBefore vectorsBefore nativeContext nativeReturn nativeOther nativeSp
  exact ⟨entry, after, finalLe, run, registers, frame, access, next⟩

end KProgFormal.ClightRefinement.Arm64EntryAdmissibility
