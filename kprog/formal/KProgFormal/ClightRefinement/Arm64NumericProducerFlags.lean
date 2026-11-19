import KProgFormal.ClightRefinement.Arm64NumericProducerTables
import KProgFormal.ClightRefinement.Arm64ProducerFlagInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerFlags

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)
open Arm64Producer

/-- Four actual flag visits and the separate LR-zero assignment extend the
initialized GPR/table path, retaining every previously derived local value. -/
theorem initialized_flags (ctx continuation : CC.Val) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (flagValues : Fin 4 → BitVec 64)
    (gprProvider : Arm64ProducerGprInputs.ProviderAt Arm64NumericProgram.ge initialMemory values)
    (flagProvider : Arm64ProducerFlagInputs.ProviderAt Arm64NumericProgram.ge initialMemory flagValues) :
    program.initMem = some initialMemory ∧
    ∃ words : TableLocals false initialMemory, ∃ tags : TableLocals true initialMemory,
    ∃ flagBlocks : Fin 4 → CC.Block, ∃ lrBlock after finalLe, ∃ traces : List CC.Trace,
      traces.length = 34 ∧
      (∀ i, (allocation initialMemory).1.get (flagDeclaration i).name = some (flagBlocks i, CC.tuchar)) ∧
      (allocation initialMemory).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
      CC.Star (CC.Step2 Arm64NumericProgram.ge)
        (.Callstate (.Internal producer) [ctx, continuation] k initialMemory)
        traces.flatten (.State producer vectorStart k (allocation initialMemory).1 finalLe after) ∧
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
      (∀ returns, ∃ cache : CacheLocals returns initialMemory,
        CC.Mem.loadv .Mint64 after (.Vptr cache.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr cache.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow (CC.Positive.ofNat 204) initialMemory after ∧
      after.access = (allocation initialMemory).2.access ∧
      after.nextblock = (allocation initialMemory).2.nextblock ∧
      finalLe.get Arm64Entry._ctx = some ctx ∧
      finalLe.get Arm64Entry._continuation = some continuation := by
  obtain ⟨init, words, tags, before, le, traces, length, prefixRun, wordPointers, tagPointers,
      reads, caches, frame, access, next, ctxRead⟩ :=
    Arm64NumericProducerTables.initialized_pointer_tables ctx continuation k values gprProvider
  obtain ⟨flagBlocks, lrBlock, after, finalLe, flagTraces, flagLength, flagBindings, lrBinding,
      visits, flagReads, lrRead, other, temps, flagsFrame, flagsAccess, flagsNext⟩ :=
    Arm64ProducerFlagInputs.flag_inputs_initialized_bound Arm64NumericProgram.ge
      Arm64NumericProducerPrefix.input_binding initialMemory before le k flagValues flagProvider access
  have tableSeparate : ∀ selected,
      (∀ i : Fin 4, tableName selected ≠ (flagDeclaration i).name) ∧
      tableName selected ≠ Arm64Entry.___a64_lr := by
    intro selected; cases selected <;> decide +kernel
  have cellSeparate : ∀ selected (i : Fin 31),
      (∀ j : Fin 4, tableCellName selected i ≠ (flagDeclaration j).name) ∧
      tableCellName selected i ≠ Arm64Entry.___a64_lr := by
    intro selected; cases selected <;> decide +kernel
  have finalFrame : FrameBelow (CC.Positive.ofNat 204) before after := by
    intro b below
    apply flagsFrame b
    rw [CC.Positive.toNat_ofNat _ (by decide)] at below
    simpa only [Arm64NumericMemory.initial_next] using below
  refine ⟨init, words, tags, flagBlocks, lrBlock, after, finalLe, traces ++ flagTraces,
    by simp only [List.length_append, length, flagLength], flagBindings, lrBinding,
    ?_, ?_, ?_, ?_, ?_, lrRead, ?_, frame.trans finalFrame, flagsAccess.trans access,
    flagsNext.trans next, ?_⟩
  · simpa only [List.flatten_append, CC.Eapp] using star_trans prefixRun visits
  · intro i
    exact (other _ _ _ words.binding (tableSeparate false).1 (tableSeparate false).2
      CC.Mptr (8 * (i.val : Int))).trans (wordPointers i)
  · intro i
    exact (other _ _ _ tags.binding (tableSeparate true).1 (tableSeparate true).2
      CC.Mptr (8 * (i.val : Int))).trans (tagPointers i)
  · intro i
    exact ⟨(other _ _ _ (words.cellBinding i) (cellSeparate false i).1 (cellSeparate false i).2
        .Mint64 0).trans (reads i).1,
      (other _ _ _ (tags.cellBinding i) (cellSeparate true i).1 (cellSeparate true i).2
        .Mint8unsigned 0).trans (reads i).2⟩
  · intro i
    exact ⟨flagReads i, flag_word_bit (flagValues i)⟩
  · intro returns
    obtain ⟨cache, base, valid⟩ := caches returns
    have baseSeparate : (∀ i : Fin 4, baseName returns ≠ (flagDeclaration i).name) ∧
        baseName returns ≠ Arm64Entry.___a64_lr := by
      cases returns <;> decide +kernel
    have validSeparate : (∀ i : Fin 4, validName returns ≠ (flagDeclaration i).name) ∧
        validName returns ≠ Arm64Entry.___a64_lr := by
      cases returns <;> decide +kernel
    exact ⟨cache,
      (other _ _ _ cache.baseBinding baseSeparate.1 baseSeparate.2 .Mint64 0).trans base,
      (other _ _ _ cache.validBinding validSeparate.1 validSeparate.2 .Mint8unsigned 0).trans valid⟩
  · constructor
    · rw [temps Arm64Entry._ctx (by decide +kernel)]
      exact ctxRead.1
    · rw [temps Arm64Entry._continuation (by decide +kernel)]
      exact ctxRead.2

end KProgFormal.ClightRefinement.Arm64NumericProducerFlags
