import KProgFormal.ClightRefinement.Arm64NumericProducerVectors
import KProgFormal.ClightRefinement.Arm64ProducerContext

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerContext

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)
open Arm64Producer

/-- The pure 90-transition stack/SP/context suffix retains the 98 input
traces and derives the actual RAW x0 and RETURN x30 source-tag updates. -/
theorem initialized_context (addresses : Arm64Registers.PointerOrigins)
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
    ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      (∀ i, (allocation initialMemory).1.get (flagDeclaration i).name = some (flagBlocks i, CC.tuchar)) ∧
      (allocation initialMemory).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
      (allocation initialMemory).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
      CC.Star (CC.Step2 Arm64NumericProgram.ge)
        (.Callstate (.Internal producer) [ctx, continuation] k initialMemory)
        traces.flatten (.State producer afterContext k (allocation initialMemory).1 finalLe after) ∧
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
        CC.Mem.loadv .Mint64 after (.Vptr cache.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr cache.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow (CC.Positive.ofNat 204) initialMemory after ∧
      after.access = (allocation initialMemory).2.access ∧
      after.nextblock = (allocation initialMemory).2.nextblock ∧
      finalLe.get Arm64Entry._ctx = some ctx ∧
      finalLe.get Arm64Entry._continuation = some continuation := by
  obtain ⟨init, words, tags, flagBlocks, lrBlock, vector, before, le, traces, length,
      flagBindings, lrBinding, prefixRun, wordPointers, tagPointers, reads, flagReads,
      lrRead, vectorReads, caches, frame, access, next, ctxRead⟩ :=
    Arm64NumericProducerVectors.initialized_vectors ctx continuation k values flagValues vectorValues
      gprProvider flagProvider vectorProvider
  obtain ⟨stackTags, spBlock, cells, after, spBinding, suffix, stackReads, spRead,
      contextReads, other, suffixFrame, suffixAccess, suffixNext⟩ :=
    stack_sp_and_context_bound Arm64NumericProgram.ge composites_same represented
      initialMemory before le ctxRead.1 k access
  have tableSeparate : ∀ selected,
      tableName selected ≠ Arm64Entry.___a64_stack_tag ∧ tableName selected ≠ Arm64Entry.___a64_sp ∧
      (∀ j, tableName selected ≠ contextName j) := by
    intro selected; cases selected <;> decide +kernel
  have wordSeparate : ∀ i : Fin 31, i ≠ 0 →
      tableCellName false i ≠ Arm64Entry.___a64_stack_tag ∧ tableCellName false i ≠ Arm64Entry.___a64_sp ∧
      (∀ j, tableCellName false i ≠ contextName j) := by decide +kernel
  have tagSeparate : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 →
      tableCellName true i ≠ Arm64Entry.___a64_stack_tag ∧ tableCellName true i ≠ Arm64Entry.___a64_sp ∧
      (∀ j, tableCellName true i ≠ contextName j) := by decide +kernel
  have x0Binding : (allocation initialMemory).1.get (tableCellName false 0) =
      some ((cells 2).block, tableCellType false) := (cells 2).binding
  have x0TagBinding : (allocation initialMemory).1.get (tableCellName true 0) =
      some ((cells 4).block, tableCellType true) := (cells 4).binding
  have x30TagBinding : (allocation initialMemory).1.get (tableCellName true 30) =
      some ((cells 3).block, tableCellType true) := (cells 3).binding
  have x0Same : (cells 2).block = words.cellBlock 0 := congrArg Prod.fst (Option.some.inj (x0Binding.symm.trans (words.cellBinding 0)))
  have x0TagSame : (cells 4).block = tags.cellBlock 0 := congrArg Prod.fst (Option.some.inj (x0TagBinding.symm.trans (tags.cellBinding 0)))
  have x30TagSame : (cells 3).block = tags.cellBlock 30 := congrArg Prod.fst (Option.some.inj (x30TagBinding.symm.trans (tags.cellBinding 30)))
  have x0Read := contextReads 2
  have x0TagRead := contextReads 4
  have x30TagRead := contextReads 3
  change CC.Mem.load .Mint64 after (cells 2).block 0 = some ctx at x0Read
  change CC.Mem.load .Mint8unsigned after (cells 4).block 0 = some (.Vint 1) at x0TagRead
  change CC.Mem.load .Mint8unsigned after (cells 3).block 0 = some (.Vint 10) at x30TagRead
  rw [x0Same] at x0Read
  rw [x0TagSame] at x0TagRead
  rw [x30TagSame] at x30TagRead
  have finalFrame : FrameBelow (CC.Positive.ofNat 204) before after := by
    intro b below
    apply suffixFrame b
    rw [CC.Positive.toNat_ofNat _ (by decide)] at below
    simpa only [Arm64NumericMemory.initial_next] using below
  refine ⟨init, words, tags, flagBlocks, lrBlock, vector, stackTags, spBlock, cells, after, le,
    traces, length, flagBindings, lrBinding, spBinding, ?_, ?_, ?_, ?_, ?_, ?_, ?_,
    stackReads, spRead, contextReads, ?_, frame.trans finalFrame,
    suffixAccess.trans access, suffixNext.trans next, ctxRead⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans prefixRun suffix.sound
  · intro i
    have s := tableSeparate false
    exact (other _ _ _ words.binding s.1 s.2.1 s.2.2 CC.Mptr (8 * (i.val : Int))).trans (wordPointers i)
  · intro i
    have s := tableSeparate true
    exact (other _ _ _ tags.binding s.1 s.2.1 s.2.2 CC.Mptr (8 * (i.val : Int))).trans (tagPointers i)
  · intro i
    constructor
    · by_cases zero : i = 0
      · subst i; simpa only [↓reduceIte] using x0Read
      · have s := wordSeparate i zero
        simpa only [ite_eq_right zero] using
          (other _ _ _ (words.cellBinding i) s.1 s.2.1 s.2.2 .Mint64 0).trans (reads i).1
    · by_cases zero : i = 0
      · subst i; simpa only [↓reduceIte] using x0TagRead
      · by_cases last : i = 30
        · subst i; simpa only [ite_eq_right (by decide : (30 : Fin 31) ≠ 0), ↓reduceIte] using x30TagRead
        · have s := tagSeparate i zero last
          simpa only [ite_eq_right zero, ite_eq_right last] using
            (other _ _ _ (tags.cellBinding i) s.1 s.2.1 s.2.2 .Mint8unsigned 0).trans (reads i).2
  · intro i
    have s : (flagDeclaration i).name ≠ Arm64Entry.___a64_stack_tag ∧
        (flagDeclaration i).name ≠ Arm64Entry.___a64_sp ∧
        (∀ j, (flagDeclaration i).name ≠ contextName j) := by
      have all : ∀ i : Fin 4, (flagDeclaration i).name ≠ Arm64Entry.___a64_stack_tag ∧
          (flagDeclaration i).name ≠ Arm64Entry.___a64_sp ∧
          (∀ j, (flagDeclaration i).name ≠ contextName j) := by decide +kernel
      exact all i
    exact ⟨(other _ _ _ (flagBindings i) s.1 s.2.1 s.2.2 .Mint8unsigned 0).trans (flagReads i).1,
      (flagReads i).2⟩
  · exact (other _ _ _ lrBinding (by decide +kernel) (by decide +kernel)
      (by decide +kernel) .Mint64 0).trans lrRead
  · intro i
    exact (other _ _ _ vector.binding (by decide +kernel) (by decide +kernel)
      (by decide +kernel) .Mint64 (8 * (i.val : Int))).trans (vectorReads i)
  · intro returns
    obtain ⟨cache, base, valid⟩ := caches returns
    have baseSeparate : baseName returns ≠ Arm64Entry.___a64_stack_tag ∧
        baseName returns ≠ Arm64Entry.___a64_sp ∧ (∀ j, baseName returns ≠ contextName j) := by
      cases returns <;> decide +kernel
    have validSeparate : validName returns ≠ Arm64Entry.___a64_stack_tag ∧
        validName returns ≠ Arm64Entry.___a64_sp ∧ (∀ j, validName returns ≠ contextName j) := by
      cases returns <;> decide +kernel
    exact ⟨cache,
      (other _ _ _ cache.baseBinding baseSeparate.1 baseSeparate.2.1 baseSeparate.2.2 .Mint64 0).trans base,
      (other _ _ _ cache.validBinding validSeparate.1 validSeparate.2.1 validSeparate.2.2 .Mint8unsigned 0).trans valid⟩

end KProgFormal.ClightRefinement.Arm64NumericProducerContext
