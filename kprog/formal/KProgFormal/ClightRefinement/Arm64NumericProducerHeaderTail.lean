import KProgFormal.ClightRefinement.Arm64NumericProducerHeaderVectors
import KProgFormal.ClightRefinement.Arm64ProducerHeaderTail

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerHeaderTail

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)
open Arm64Producer

/-- Both actual Numeric symbols resolve to the retained exported callbacks. -/
theorem payload_callbacks (store : Bool) :
    CC.Genv.findSymbol Arm64NumericProgram.ge.genv_genv (payloadCallbackName store) =
      some (payloadCallbackBlock store) ∧
    CC.Genv.findFunctPtr Arm64NumericProgram.ge.genv_genv (payloadCallbackBlock store) =
      some (payloadCallbackFunction store) := by
  cases store <;> constructor <;> run_tac sourceEquality

/-- The actual Numeric tail stores retain the complete initialized header and
bind the stack/context addresses to the already derived locals. -/
theorem initialized_tail (addresses : Arm64Registers.PointerOrigins)
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
        traces.flatten (.State producer beforeVectorLoop k (allocation initialMemory).1 finalLe after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
        some (.Vptr (sources i).block 0)) ∧
      (∀ i : Fin 64, CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) =
        some (.Vlong 0)) ∧
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
      finalLe.get Arm64Entry._ctx = some ctx := by
  obtain ⟨init, words, tags, flagBlocks, lrBlock, vector, stackTags, spBlock, cells, entry, sources,
      before, le, traces, length, flagBindings, lrBinding, spBinding, prefixRun, headerReads, nullReads,
      wordsEqual, tagsEqual, lrEqual, spEqual, wordPointers, tagPointers, reads, flagReads,
      lrRead, vectorReads, stackReads, spRead, contextReads, caches, frame, access, next, ctxRead⟩ :=
    Arm64NumericProducerHeaderVectors.initialized_null_vectors addresses ctx continuation ctxWord
      represented k values flagValues vectorValues gprProvider flagProvider vectorProvider
  obtain ⟨tailSources, after, suffix, tailReads, prefixReads, other, suffixFrame, suffixAccess, suffixNext⟩ :=
    tail_initialized_bound Arm64NumericProgram.ge composites_same
      (fun store => (payload_callbacks store).1) initialMemory before entry le k access
  have finalHeaderReads : ∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
      some (.Vptr (sources i).block 0) := by
    intro i
    exact (prefixReads ⟨i.val, by have := i.isLt; omega⟩).trans (headerReads i)
  have finalNullReads : ∀ i : Fin 64,
      CC.Mem.load CC.Mptr after entry.block (96 + 8 * (i.val : Int)) = some (.Vlong 0) := by
    intro i
    have keep := prefixReads ⟨12 + i.val, by have := i.isLt; omega⟩
    have offset : 8 * (((12 + i.val : Nat) : Int)) = 96 + 8 * (i.val : Int) := by omega
    change CC.Mem.load .Mint64 after entry.block (8 * (((12+i.val : Nat) : Int))) =
      CC.Mem.load .Mint64 before entry.block (8 * (((12+i.val : Nat) : Int))) at keep
    rw [offset] at keep
    exact keep.trans (nullReads i)
  have stackBinding : (allocation initialMemory).1.get (tailLocalName 2) =
      some (stackTags.block, tailLocalType 2) := stackTags.binding
  have contextBinding : (allocation initialMemory).1.get (tailLocalName 3) =
      some ((cells 0).block, tailLocalType 3) := (cells 0).binding
  have abiBinding : (allocation initialMemory).1.get (tailLocalName 4) =
      some ((cells 1).block, tailLocalType 4) := (cells 1).binding
  have stackEqual : (tailSources 2).block = stackTags.block :=
    congrArg Prod.fst (Option.some.inj ((tailSources 2).binding.symm.trans stackBinding))
  have contextEqual : (tailSources 3).block = (cells 0).block :=
    congrArg Prod.fst (Option.some.inj ((tailSources 3).binding.symm.trans contextBinding))
  have abiEqual : (tailSources 4).block = (cells 1).block :=
    congrArg Prod.fst (Option.some.inj ((tailSources 4).binding.symm.trans abiBinding))
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
    tailSources, after, le, traces, length, flagBindings, lrBinding, spBinding, ?_, finalHeaderReads,
    finalNullReads, tailReads, stackEqual, contextEqual, abiEqual, wordsEqual, tagsEqual, lrEqual,
    spEqual, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_,
    frame.trans finalFrame, suffixAccess.trans access, suffixNext.trans next, ctxRead⟩
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
    exact (other _ _ _ vector.binding (by decide +kernel) .Mint64 (8 * (i.val : Int))).trans (vectorReads i)
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

end KProgFormal.ClightRefinement.Arm64NumericProducerHeaderTail
