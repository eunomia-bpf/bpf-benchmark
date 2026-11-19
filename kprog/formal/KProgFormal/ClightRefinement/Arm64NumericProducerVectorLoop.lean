import KProgFormal.ClightRefinement.Arm64NumericProducerHeaderTail
import KProgFormal.ClightRefinement.Arm64ProducerVectorView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerVectorLoop

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)
open Arm64Producer

/-- Flatten the actual low/high words in the allocated vector array. -/
def vectorInputIndex (high : Bool) (i : Fin 32) : Fin 64 :=
  ⟨2 * i.val + (if high then 1 else 0), by have := i.isLt; cases high <;> simp_all <;> omega⟩

private theorem vector_input_offsets (high : Bool) (i : Fin 32) :
    16 * (i.val : Int) + (if high then 8 else 0) =
      8 * ((vectorInputIndex high i).val : Int) := by
  cases high <;> simp [vectorInputIndex] <;> omega

/-- Actual Numeric initialization reaches the consumer sequence with all live
vector pointers, source data and the existing borrowed vector reader view. -/
theorem initialized_vectors (addresses : Arm64Registers.PointerOrigins)
    (ctx continuation : CC.Val) (ctxWord : BitVec 64)
    (represented : Arm64Registers.ValueRep addresses ctx ctxWord) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (flagValues : Fin 4 → BitVec 64)
    (vectorValues : Fin 64 → BitVec 64)
    (gprProvider : Arm64ProducerGprInputs.ProviderAt Arm64NumericProgram.ge initialMemory values)
    (flagProvider : Arm64ProducerFlagInputs.ProviderAt Arm64NumericProgram.ge initialMemory flagValues)
    (vectorProvider : Arm64ProducerVectorInputs.ProviderAt Arm64NumericProgram.ge initialMemory vectorValues) :
    program.initMem = some initialMemory ∧
    ∃ words : TableLocals false initialMemory, ∃ tags : TableLocals true initialMemory,
    ∃ flagBlocks : Fin 4 → CC.Block, ∃ lrBlock, ∃ vector : VectorLocal initialMemory,
    ∃ stackTags : StackTagLocal initialMemory, ∃ spBlock,
    ∃ cells : (i : Fin 5) → ContextLocal initialMemory i,
    ∃ entry : HeaderLocal initialMemory,
    ∃ sources : (i : Fin 12) → HeaderSourceLocal initialMemory i,
    ∃ tailSources : (i : Fin 9) → TailLocal initialMemory i,
    ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      (∀ i, (allocation initialMemory).1.get (flagDeclaration i).name = some (flagBlocks i, CC.tuchar)) ∧
      (allocation initialMemory).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
      (allocation initialMemory).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
      CC.Star (CC.Step2 Arm64NumericProgram.ge)
        (.Callstate (.Internal producer) [ctx, continuation] k initialMemory)
        traces.flatten (.State producer afterVectorLoop k (allocation initialMemory).1 finalLe after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
        some (.Vptr (sources i).block 0)) ∧
      (∀ (high : Bool) (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vector.block (vectorLoopSourceOffset high i))) ∧
      (∀ i, Arm64EntryMemory.vector after.nextblock after (.Vptr entry.block 0) i =
        some (.Vlong (vectorValues (vectorInputIndex false i)),
          .Vlong (vectorValues (vectorInputIndex true i)))) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) =
        some (tailValue tailSources i)) ∧
      (tailSources 2).block = stackTags.block ∧
      (tailSources 3).block = (cells 0).block ∧ (tailSources 4).block = (cells 1).block ∧
      (sources 0).block = words.tableBlock ∧ (sources 1).block = tags.tableBlock ∧
      (sources 4).block = lrBlock ∧ (sources 5).block = spBlock ∧
      (∀ i, CC.Mem.load CC.Mptr after words.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (words.cellBlock i) 0)) ∧
      (∀ i, CC.Mem.load CC.Mptr after tags.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (tags.cellBlock i) 0)) ∧
      (∀ i, CC.Mem.load .Mint64 after (words.cellBlock i) 0 =
        some (if i = 0 then ctx else .Vlong (if i = 30 then 0 else values i)) ∧
        CC.Mem.load .Mint8unsigned after (tags.cellBlock i) 0 =
          some (.Vint (if i = 0 then 1 else if i = 30 then 10 else 0))) ∧
      (∀ i, CC.Mem.load .Mint8unsigned after (flagBlocks i) 0 = some (.Vint (flagWord (flagValues i))) ∧
        (flagWord (flagValues i) = (0#32) ∨ flagWord (flagValues i) = (1#32))) ∧
      CC.Mem.load .Mint64 after lrBlock 0 = some (.Vlong 0) ∧
      (∀ i : Fin 64, CC.Mem.load .Mint64 after vector.block (8 * (i.val : Int)) =
        some (.Vlong (vectorValues i))) ∧
      (∀ i : Fin 24, CC.Mem.load .Mint8unsigned after stackTags.block (i.val : Int) = some (.Vint 0)) ∧
      CC.Mem.load .Mint64 after spBlock 0 = some (.Vlong 0) ∧
      (∀ i, CC.Mem.load (contextChunk i) after (cells i).block 0 = some (contextValue ctx i)) ∧
      (∀ returns, ∃ cache : CacheLocals returns initialMemory,
        cache.entryBlock = entry.block ∧
        Nonempty (Arm64RegisterReads.BorrowedCacheStorage returns
          (allocation initialMemory).2.nextblock entry.block 0 after) ∧
        CC.Mem.loadv .Mint64 after (.Vptr cache.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr cache.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow (CC.Positive.ofNat 204) initialMemory after ∧
      after.access = (allocation initialMemory).2.access ∧
      after.nextblock = (allocation initialMemory).2.nextblock ∧
      finalLe.get Arm64Entry._i = some (.Vint 32) ∧
      finalLe.get Arm64Entry._ctx = some ctx := by
  obtain ⟨init, words, tags, flagBlocks, lrBlock, vector, stackTags, spBlock, cells, entry, sources,
      tailSources, before, le, traces, length, flagBindings, lrBinding, spBinding, prefixRun,
      headerReads, _, tailReads, stackEqual, contextEqual, abiEqual, wordsEqual, tagsEqual,
      lrEqual, spEqual, wordPointers, tagPointers, reads, flagReads, lrRead, vectorReads,
      stackReads, spRead, contextReads, caches, frame, access, next, ctxRead⟩ :=
    Arm64NumericProducerHeaderTail.initialized_tail addresses ctx continuation ctxWord represented
      k values flagValues vectorValues gprProvider flagProvider vectorProvider
  obtain ⟨after, finalLe, suffix, index, temps, pointerReads, outside, suffixFrame, suffixAccess, suffixNext⟩ :=
    vector_pointers_initialized_bound Arm64NumericProgram.ge composites_same
      initialMemory before entry vector le k access
  have other : ∀ id ty block, (allocation initialMemory).1.get id = some (block, ty) →
      id ≠ Arm64Entry._entry → ∀ chunk ofs,
      CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs := by
    intro id ty block binding different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initialMemory)).symm)).2
    exact outside chunk block ofs (.inl (distinct _ _ _ _ binding entry.binding different))
  have finalHeaderReads : ∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
      some (.Vptr (sources i).block 0) := by
    intro i
    exact (outside CC.Mptr entry.block (8 * (i.val : Int)) (.inr (.inl (by
      change 8 * (i.val : Int) + 8 ≤ 96
      have bound := i.isLt
      omega)))).trans (headerReads i)
  have finalTailReads : ∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) =
      some (tailValue tailSources i) := by
    intro i
    exact (outside (tailChunk i) entry.block (tailOffset i)
      (.inr (.inr ((tail_layout.2.2.2.1 i).1)))).trans (tailReads i)
  have retainedVectors : ∀ i : Fin 64, CC.Mem.load .Mint64 after vector.block
      (8 * (i.val : Int)) = some (.Vlong (vectorValues i)) := by
    intro i
    exact (other _ _ _ vector.binding (by decide +kernel) .Mint64 (8 * (i.val : Int))).trans (vectorReads i)
  have inputData : ∀ (high : Bool) (i : Fin 32), CC.Mem.load .Mint64 after vector.block
      (16 * (i.val : Int) + (if high then 8 else 0)) =
      some (.Vlong (vectorValues (vectorInputIndex high i))) := by
    intro high i
    rw [vector_input_offsets]
    exact retainedVectors (vectorInputIndex high i)
  have view := Arm64ProducerVectorView.vector_readbacks initialMemory after entry vector
    (fun high i => .Vlong (vectorValues (vectorInputIndex high i))) pointerReads inputData
  have tableSeparate : ∀ selected, tableName selected ≠ Arm64Entry._entry := by
    intro selected; cases selected <;> decide +kernel
  have cellSeparate : ∀ selected (i : Fin 31), tableCellName selected i ≠ Arm64Entry._entry := by
    intro selected; cases selected <;> decide +kernel
  have flagSeparate : ∀ i : Fin 4, (flagDeclaration i).name ≠ Arm64Entry._entry := by decide +kernel
  have contextSeparate : ∀ i : Fin 5, contextName i ≠ Arm64Entry._entry := by decide +kernel
  have finalFrame : FrameBelow (CC.Positive.ofNat 204) before after := by
    intro b below
    apply suffixFrame b
    rw [CC.Positive.toNat_ofNat _ (by decide)] at below
    simpa only [Arm64NumericMemory.initial_next] using below
  refine ⟨init, words, tags, flagBlocks, lrBlock, vector, stackTags, spBlock, cells, entry, sources,
    tailSources, after, finalLe, traces, length, flagBindings, lrBinding, spBinding, ?_,
    finalHeaderReads, pointerReads, view, finalTailReads, stackEqual, contextEqual, abiEqual,
    wordsEqual, tagsEqual, lrEqual, spEqual, ?_, ?_, ?_, ?_, ?_, retainedVectors, ?_, ?_, ?_, ?_,
    frame.trans finalFrame, suffixAccess.trans access, suffixNext.trans next, index, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans prefixRun suffix.sound
  · intro i
    exact (other _ _ _ words.binding (tableSeparate false) CC.Mptr (8 * (i.val : Int))).trans (wordPointers i)
  · intro i
    exact (other _ _ _ tags.binding (tableSeparate true) CC.Mptr (8 * (i.val : Int))).trans (tagPointers i)
  · intro i
    exact ⟨(other _ _ _ (words.cellBinding i) (cellSeparate false i) .Mint64 0).trans (reads i).1,
      (other _ _ _ (tags.cellBinding i) (cellSeparate true i) .Mint8unsigned 0).trans (reads i).2⟩
  · intro i
    exact ⟨(other _ _ _ (flagBindings i) (flagSeparate i) .Mint8unsigned 0).trans (flagReads i).1,
      (flagReads i).2⟩
  · exact (other _ _ _ lrBinding (by decide +kernel) .Mint64 0).trans lrRead
  · intro i
    exact (other _ _ _ stackTags.binding (by decide +kernel) .Mint8unsigned (i.val : Int)).trans (stackReads i)
  · exact (other _ _ _ spBinding (by decide +kernel) .Mint64 0).trans spRead
  · intro i
    exact (other _ _ _ (cells i).binding (contextSeparate i) (contextChunk i) 0).trans (contextReads i)
  · intro returns
    obtain ⟨old, _, _, base, valid⟩ := caches returns
    obtain ⟨cache, storage⟩ := header_cache_storage returns initialMemory after entry sources
      (suffixAccess.trans access) finalHeaderReads
    have entryEqual : cache.entryBlock = entry.block :=
      congrArg Prod.fst (Option.some.inj (cache.entryBinding.symm.trans entry.binding))
    have baseEqual : cache.baseBlock = old.baseBlock :=
      congrArg Prod.fst (Option.some.inj (cache.baseBinding.symm.trans old.baseBinding))
    have validEqual : cache.validBlock = old.validBlock :=
      congrArg Prod.fst (Option.some.inj (cache.validBinding.symm.trans old.validBinding))
    rw [entryEqual] at storage
    have baseBefore : CC.Mem.loadv .Mint64 before (.Vptr cache.baseBlock 0) = some (.Vlong 0) := by
      rw [baseEqual]; exact base
    have validBefore : CC.Mem.loadv .Mint8unsigned before (.Vptr cache.validBlock 0) = some (.Vint 0) := by
      rw [validEqual]; exact valid
    exact ⟨cache, entryEqual, storage,
      (other _ _ _ cache.baseBinding (by cases returns <;> decide +kernel) .Mint64 0).trans baseBefore,
      (other _ _ _ cache.validBinding (by cases returns <;> decide +kernel) .Mint8unsigned 0).trans validBefore⟩
  · exact (temps Arm64Entry._ctx (by decide +kernel)).trans ctxRead

end KProgFormal.ClightRefinement.Arm64NumericProducerVectorLoop
