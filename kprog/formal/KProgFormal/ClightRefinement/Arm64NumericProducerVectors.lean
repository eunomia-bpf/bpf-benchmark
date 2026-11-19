import KProgFormal.ClightRefinement.Arm64NumericProducerFlags
import KProgFormal.ClightRefinement.Arm64ProducerVectorInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerVectors

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)
open Arm64Producer

/-- All 98 actual input visits from initialization, ending before RAW/header
processing, with every derived scalar and vector local value retained. -/
theorem initialized_vectors (ctx continuation : CC.Val) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (flagValues : Fin 4 → BitVec 64)
    (vectorValues : Fin 64 → BitVec 64)
    (gprProvider : Arm64ProducerGprInputs.ProviderAt Arm64NumericProgram.ge initialMemory values)
    (flagProvider : Arm64ProducerFlagInputs.ProviderAt Arm64NumericProgram.ge initialMemory flagValues)
    (vectorProvider : Arm64ProducerVectorInputs.ProviderAt Arm64NumericProgram.ge initialMemory vectorValues) :
    program.initMem = some initialMemory ∧
    ∃ words : TableLocals false initialMemory, ∃ tags : TableLocals true initialMemory,
    ∃ flagBlocks : Fin 4 → CC.Block, ∃ lrBlock, ∃ vector : VectorLocal initialMemory,
    ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      (∀ i, (allocation initialMemory).1.get (flagDeclaration i).name = some (flagBlocks i, CC.tuchar)) ∧
      (allocation initialMemory).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
      CC.Star (CC.Step2 Arm64NumericProgram.ge)
        (.Callstate (.Internal producer) [ctx, continuation] k initialMemory)
        traces.flatten (.State producer afterVectorInputs k (allocation initialMemory).1 finalLe after) ∧
      (∀ i, CC.Mem.load CC.Mptr after words.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (words.cellBlock i) 0)) ∧
      (∀ i, CC.Mem.load CC.Mptr after tags.tableBlock (8 * (i.val : Int)) =
        some (.Vptr (tags.cellBlock i) 0)) ∧
      (∀ i, CC.Mem.load .Mint64 after (words.cellBlock i) 0 =
        some (.Vlong (if i = 30 then 0 else values i)) ∧
        CC.Mem.load .Mint8unsigned after (tags.cellBlock i) 0 = some (.Vint 0)) ∧
      (∀ i, CC.Mem.load .Mint8unsigned after (flagBlocks i) 0 = some (.Vint (flagWord (flagValues i))) ∧
        (flagWord (flagValues i) = (0#32) ∨ flagWord (flagValues i) = (1#32))) ∧
      CC.Mem.load .Mint64 after lrBlock 0 = some (.Vlong 0) ∧
      (∀ i : Fin 64, CC.Mem.load .Mint64 after vector.block (8 * (i.val : Int)) =
        some (.Vlong (vectorValues i))) ∧
      (∀ returns, ∃ cache : CacheLocals returns initialMemory,
        CC.Mem.loadv .Mint64 after (.Vptr cache.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr cache.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow (CC.Positive.ofNat 204) initialMemory after ∧
      after.access = (allocation initialMemory).2.access ∧
      after.nextblock = (allocation initialMemory).2.nextblock ∧
      finalLe.get Arm64Entry._ctx = some ctx ∧
      finalLe.get Arm64Entry._continuation = some continuation := by
  obtain ⟨init, words, tags, flagBlocks, lrBlock, before, le, traces, length, flagBindings,
      lrBinding, prefixRun, wordPointers, tagPointers, reads, flagReads, lrRead,
      caches, frame, access, next, ctxRead⟩ :=
    Arm64NumericProducerFlags.initialized_flags ctx continuation k values flagValues gprProvider flagProvider
  obtain ⟨vector, after, finalLe, vectorTraces, vectorLength, visits, vectorReads,
      other, temps, vectorFrame, vectorAccess, vectorNext⟩ :=
    Arm64ProducerVectorInputs.vector_inputs_initialized_bound Arm64NumericProgram.ge composites_same
      Arm64NumericProducerPrefix.input_binding initialMemory before le k vectorValues vectorProvider access
  have tableSeparate : ∀ selected, tableName selected ≠ Arm64Entry.___a64_vectors := by
    intro selected; cases selected <;> decide +kernel
  have cellSeparate : ∀ selected (i : Fin 31), tableCellName selected i ≠ Arm64Entry.___a64_vectors := by
    intro selected; cases selected <;> decide +kernel
  have flagSeparate : ∀ i : Fin 4, (flagDeclaration i).name ≠ Arm64Entry.___a64_vectors := by
    decide +kernel
  have finalFrame : FrameBelow (CC.Positive.ofNat 204) before after := by
    intro b below
    apply vectorFrame b
    rw [CC.Positive.toNat_ofNat _ (by decide)] at below
    simpa only [Arm64NumericMemory.initial_next] using below
  refine ⟨init, words, tags, flagBlocks, lrBlock, vector, after, finalLe, traces ++ vectorTraces,
    by simp only [List.length_append, length, vectorLength], flagBindings, lrBinding,
    ?_, ?_, ?_, ?_, ?_, ?_, vectorReads, ?_, frame.trans finalFrame,
    vectorAccess.trans access, vectorNext.trans next, ?_⟩
  · simpa only [List.flatten_append, CC.Eapp] using star_trans prefixRun visits
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
  · intro returns
    obtain ⟨cache, base, valid⟩ := caches returns
    exact ⟨cache,
      (other _ _ _ cache.baseBinding (by cases returns <;> decide +kernel) .Mint64 0).trans base,
      (other _ _ _ cache.validBinding (by cases returns <;> decide +kernel) .Mint8unsigned 0).trans valid⟩
  · constructor
    · rw [temps Arm64Entry._ctx (by decide +kernel)]
      exact ctxRead.1
    · rw [temps Arm64Entry._continuation (by decide +kernel)]
      exact ctxRead.2

end KProgFormal.ClightRefinement.Arm64NumericProducerVectors
