import KProgFormal.ClightRefinement.Arm64ProgramEntryRawSetup
import KProgFormal.ClightRefinement.Arm64ProgramEntryResources
import KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryInitialized

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (tableCellName tableCellType tableName tableType TableLocals HeaderLocal
  HeaderSourceLocal TailLocal VectorLocal contextName contextLocalType contextChunk contextValue)

/-- Initialized data at a reached memory, retaining actual and canonical source
bindings. Native-state relations and provider purity are not assumed. -/
structure Values (initial memory : CC.Mem) (ctx : CC.Val) (values : Fin 31 → BitVec 64)
    (flags : Fin 4 → BitVec 64) (vectors : Fin 64 → BitVec 64) where
  blocks : Bool → Fin 31 → CC.Block
  bindings : ∀ tags i, (Arm64Producer.allocation initial).1.get (tableCellName tags i) =
    some (blocks tags i, tableCellType tags)
  actualBindings : ∀ tags i, (allocation initial).1.get (tableCellName tags i) =
    some (blocks tags i, tableCellType tags)
  registers : ∀ i, CC.Mem.load .Mint64 memory (blocks false i) 0 =
      some (Arm64EntryAdmissibility.rawValue ctx values i) ∧
    CC.Mem.load .Mint8unsigned memory (blocks true i) 0 =
      some (.Vint (Arm64ProgramEntryRawSetup.tagWord i))
  tables : ∀ tags, ∃ locals : TableLocals tags initial,
    (allocation initial).1.get (tableName tags) = some (locals.tableBlock, tableType tags) ∧
    (∀ i, (allocation initial).1.get (tableCellName tags i) =
      some (locals.cellBlock i, tableCellType tags)) ∧
    ∀ i, CC.Mem.load CC.Mptr memory locals.tableBlock (8 * (i.val : Int)) =
      some (.Vptr (blocks tags i) 0)
  flagReads : Arm64ProgramEntryFlags.Readbacks initial memory flags
  vectorReads : Arm64ProgramEntryVectorInputs.Readbacks initial memory vectors
  rawReads : Arm64ProgramEntryRawSetup.Readbacks initial memory ctx
  cacheReads : Arm64ProgramEntryInputs.CacheReadbacks initial memory

/-- Exact local-load frame of header-only writes; memories may differ. -/
def LocalsAgree (initial before after : CC.Mem) : Prop :=
  ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
    id ≠ Arm64Entry._entry → ∀ chunk offset,
      CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset

private theorem cell_names : ∀ tags (i : Fin 31), tableCellName tags i ≠ Arm64Entry._entry := by decide +kernel
private theorem table_names : ∀ tags, tableName tags ≠ Arm64Entry._entry := by decide +kernel
private theorem flag_names : ∀ i : Fin 4,
    (Arm64ProgramEntryFlags.declaration i).name ≠ Arm64Entry._entry := by decide +kernel
private theorem context_names : ∀ i : Fin 5, contextName i ≠ Arm64Entry._entry := by decide +kernel
private theorem cache_names : ∀ returns,
    Arm64Producer.baseName returns ≠ Arm64Entry._entry ∧
    Arm64Producer.validName returns ≠ Arm64Entry._entry := by decide +kernel
private theorem fixed_names :
    Arm64Entry.___a64_lr ≠ Arm64Entry._entry ∧
    Arm64Entry.___a64_vectors ≠ Arm64Entry._entry ∧
    Arm64Entry.___a64_stack_tag ≠ Arm64Entry._entry ∧
    Arm64Entry.___a64_sp ≠ Arm64Entry._entry := by decide +kernel

/-- Transport all initialized observations through header-only writes by typed
local identity, including cold-cache bytes and the pointer payload in x0. -/
theorem Values.transport {initial before after : CC.Mem} {ctx values flags vectors}
    (data : Values initial before ctx values flags vectors)
    (keep : LocalsAgree initial before after) : Nonempty (Values initial after ctx values flags vectors) := by
  refine ⟨⟨data.blocks, data.bindings, data.actualBindings, ?_, ?_, ?_, ?_, ?_, ?_⟩⟩
  · intro i
    exact ⟨(keep _ _ _ (data.bindings false i) (cell_names false i) .Mint64 0).trans (data.registers i).1,
      (keep _ _ _ (data.bindings true i) (cell_names true i) .Mint8unsigned 0).trans (data.registers i).2⟩
  · intro tags
    obtain ⟨locals, bound, cells, reads⟩ := data.tables tags
    exact ⟨locals, bound, cells, fun i =>
      (keep _ _ _ locals.binding (table_names tags) CC.Mptr (8 * (i.val : Int))).trans (reads i)⟩
  · obtain ⟨blocks, lr, bound, actual, lrBound, actualLr, reads, lrRead⟩ := data.flagReads
    exact ⟨blocks, lr, bound, actual, lrBound, actualLr,
      fun i => (keep _ _ _ (bound i) (flag_names i) .Mint8unsigned 0).trans (reads i),
      (keep _ _ _ lrBound fixed_names.1 .Mint64 0).trans lrRead⟩
  · obtain ⟨localVector, bound, reads⟩ := data.vectorReads
    exact ⟨localVector, bound, fun i =>
      (keep _ _ _ localVector.binding fixed_names.2.1 .Mint64 (8 * (i.val : Int))).trans (reads i)⟩
  · obtain ⟨tags, sp, cells, tagBound, spBound, actualSp, actualCells, tagReads, spRead, reads⟩ := data.rawReads
    exact ⟨tags, sp, cells, tagBound, spBound, actualSp, actualCells,
      fun i => (keep _ _ _ tags.binding fixed_names.2.2.1 .Mint8unsigned (i.val : Int)).trans (tagReads i),
      (keep _ _ _ spBound fixed_names.2.2.2 .Mint64 0).trans spRead,
      fun i => (keep _ _ _ (cells i).binding (context_names i) (contextChunk i) 0).trans (reads i)⟩
  · intro returns
    obtain ⟨locals, baseBound, validBound, base, valid⟩ := data.cacheReads returns
    exact ⟨locals, baseBound, validBound,
      (keep _ _ _ locals.baseBinding (cache_names returns).1 .Mint64 0).trans base,
      (keep _ _ _ locals.validBinding (cache_names returns).2 .Mint8unsigned 0).trans valid⟩

/-- Derive the existing borrowed register storage from this same reached
memory, including SP0 and current write permissions, without replaying stores. -/
theorem Values.storage {initial memory : CC.Mem} {ctx values flags vectors}
    (data : Values initial memory ctx values flags vectors)
    (entry : HeaderLocal initial) (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (localVector : VectorLocal initial)
    (access : memory.access = (allocation initial).2.access)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0))
    (vectorPointers : ∀ high (i : Fin 32), CC.Mem.load CC.Mptr memory entry.block
      ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr localVector.block (Arm64Producer.vectorLoopSourceOffset high i))) :
    Nonempty (Arm64ProducerRegisterStorage.Storage initial memory entry) := by
  obtain ⟨wordTable, _, _, wordReads⟩ := data.tables false
  obtain ⟨tagTable, _, _, tagReads⟩ := data.tables true
  let tables : (tags : Bool) → TableLocals tags initial
    | false => wordTable
    | true => tagTable
  have slots : ∀ tags (i : Fin 31), CC.Mem.load CC.Mptr memory (tables tags).tableBlock
      (8 * (i.val : Int)) = some (.Vptr ((tables tags).cellBlock i) 0) := by
    intro tags i
    have cellSame : (tables tags).cellBlock i = data.blocks tags i :=
      congrArg Prod.fst (Option.some.inj (((tables tags).cellBinding i).symm.trans (data.bindings tags i)))
    rw [cellSame]
    cases tags
    · exact wordReads i
    · exact tagReads i
  obtain ⟨_, spBlock, _, _, spBound, _, _, _, spRead, _⟩ := data.rawReads
  have spSame : (header 5).block = spBlock :=
    congrArg Prod.fst (Option.some.inj ((header 5).binding.symm.trans spBound))
  have spValue : CC.Mem.load .Mint64 memory (header 5).block 0 = some (.Vlong 0) := by
    rw [spSame]
    exact spRead
  have sourceAccess : memory.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  exact ⟨Arm64ProducerRegisterStorage.of_header initial memory entry header tables localVector
    vectorPointers sourceAccess pointers slots 0 spValue⟩

/-- Both real table roots, their31 pointers and the initialized cells feed
the existing borrowed GPR reader, including context x0 and the two RAW tags. -/
theorem Values.gpr_reads {initial memory : CC.Mem} {ctx values flags vectors}
    (data : Values initial memory ctx values flags vectors)
    (entry : HeaderLocal initial) (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0)) :
    ∀ i : Fin 31, Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (Arm64EntryAdmissibility.rawValue ctx values i, .Vint (Arm64ProgramEntryRawSetup.tagWord i)) := by
  obtain ⟨words, _, _, wordSlots⟩ := data.tables false
  obtain ⟨tags, _, _, tagSlots⟩ := data.tables true
  have wordRoot : CC.Mem.load CC.Mptr memory entry.block 0 = some (.Vptr words.tableBlock 0) := by
    have same : (header 0).block = words.tableBlock :=
      congrArg Prod.fst (Option.some.inj ((header 0).binding.symm.trans words.binding))
    have read := pointers 0
    rw [same] at read
    exact read
  have tagRoot : CC.Mem.load CC.Mptr memory entry.block 8 = some (.Vptr tags.tableBlock 0) := by
    have same : (header 1).block = tags.tableBlock :=
      congrArg Prod.fst (Option.some.inj ((header 1).binding.symm.trans tags.binding))
    have read := pointers 1
    rw [same] at read
    exact read
  intro i
  exact Arm64ProducerGprView.gpr_readback memory entry.block words.tableBlock tags.tableBlock
    (data.blocks false i) (data.blocks true i) i _ _ wordRoot tagRoot
    (wordSlots i) (tagSlots i) (data.registers i).1 (data.registers i).2

/-- Actual zero cache cells are reached through the header's borrowed readers.
These are derived cold validity bytes, not an assumed cache-state relation. -/
theorem Values.cold_cache_reads {initial memory : CC.Mem} {ctx values flags vectors}
    (data : Values initial memory ctx values flags vectors)
    (entry : HeaderLocal initial) (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0)) :
    ∀ returns : Bool,
      Arm64EntryMemory.borrowed memory.nextblock .Mint64 memory (.Vptr entry.block 0)
        (if returns then Arm64Program._return_base else Arm64Program._sp_base) = some (.Vlong 0) ∧
      Arm64EntryMemory.borrowed memory.nextblock .Mint8unsigned memory (.Vptr entry.block 0)
        (if returns then Arm64Program._return_valid else Arm64Program._sp_valid) = some (.Vint 0) := by
  intro returns
  obtain ⟨locals, _, _, baseRead, validRead⟩ := data.cacheReads returns
  have baseSame : (header (if returns then 3 else 2)).block = locals.baseBlock := by
    cases returns
    · exact congrArg Prod.fst (Option.some.inj ((header 2).binding.symm.trans locals.baseBinding))
    · exact congrArg Prod.fst (Option.some.inj ((header 3).binding.symm.trans locals.baseBinding))
  have validSame : (header (if returns then 7 else 6)).block = locals.validBlock := by
    cases returns
    · exact congrArg Prod.fst (Option.some.inj ((header 6).binding.symm.trans locals.validBinding))
    · exact congrArg Prod.fst (Option.some.inj ((header 7).binding.symm.trans locals.validBinding))
  have basePointer := pointers (if returns then 3 else 2)
  have validPointer := pointers (if returns then 7 else 6)
  rw [baseSame] at basePointer
  rw [validSame] at validPointer
  have base := Arm64ProducerEntryView.header_borrowed_readback memory entry.block
    (if returns then 3 else 2) .Mint64 locals.baseBlock 0 (.Vlong 0) basePointer baseRead
  have valid := Arm64ProducerEntryView.header_borrowed_readback memory entry.block
    (if returns then 7 else 6) .Mint8unsigned locals.validBlock 0 (.Vint 0) validPointer validRead
  cases returns <;> exact ⟨base, valid⟩

/-- The actual call reaches its real body after98 ordered provider visits and
638 silent header/loop transitions. All initialized values, all92 typed header
readbacks, borrowed storage and caller resources hold in that same memory.
Native/provider admission remains an explicit contract. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors) :
    ∃ entry : HeaderLocal initial, ∃ cells : (i : Fin 12) → HeaderSourceLocal initial i,
    ∃ sources : (i : Fin 9) → TailLocal initial i, ∃ localVector : VectorLocal initial,
    ∃ after finalTemps, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntrySource.body
          k (allocation initial).1 finalTemps after) ∧
      finalTemps.get Arm64Entry._i = some (.Vint 32) ∧
      finalTemps.get Arm64ProgramFixture._ctx = some ctx ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ high (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr localVector.block (Arm64Producer.vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (Arm64Producer.tailChunk i) after entry.block (Arm64Producer.tailOffset i) =
        some (Arm64ProgramEntryTail.actualValue sources i)) ∧
      Nonempty (Values initial after ctx values flags vectors) ∧
      Nonempty (Arm64ProducerRegisterStorage.Storage initial after entry) ∧
      Arm64ProgramEntryResources.Resources initial after entry ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨blocks, before, temps, traces, length, bindings, actualBindings, priorRun, registers,
    tables, flagReads, vectorReads, rawReads, cacheReads, context, frame, access, next⟩ :=
    Arm64ProgramEntryRawSetup.entry_initialized initial ctx k addresses ctxWord represented
      values provider flags flagProvider vectors vectorProvider
  rw [Arm64ProgramEntryRawSetup.boundary] at priorRun
  have data : Values initial before ctx values flags vectors :=
    ⟨blocks, bindings, actualBindings, registers, tables, flagReads, vectorReads, rawReads, cacheReads⟩
  have sourceAccess : before.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨entry, cells, sources, localVector, after, finalTemps, suffix, index, otherTemps,
    _, pointers, vectorPointers, tailPointers, locals, resources, suffixFrame, suffixAccess, suffixNext⟩ :=
    Arm64ProgramEntryResources.reached_body initial before temps k sourceAccess
  obtain ⟨finalData⟩ := data.transport locals
  have finalAccess := suffixAccess.trans access
  refine ⟨entry, cells, sources, localVector, after, finalTemps, traces, length, ?_, index, ?_,
    pointers, vectorPointers, tailPointers, ⟨finalData⟩,
    finalData.storage entry cells localVector finalAccess pointers vectorPointers,
    resources, frame.trans suffixFrame, finalAccess, suffixNext.trans next⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans priorRun suffix.sound
  · exact (otherTemps _ (by decide +kernel)).trans context

end KProgFormal.ClightRefinement.Arm64ProgramEntryInitialized
