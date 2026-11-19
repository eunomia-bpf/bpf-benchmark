import KProgFormal.ClightRefinement.Arm64NumericProducerVectorLoop
import KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericProducerRegisterStorage

open Arm64NumericProgram
open Arm64NumericMemory (initialMemory)
open Arm64Producer
open Arm64NumericProducerVectorLoop (vectorInputIndex)

/-- Storage and every register reader are derived at the same actual reached
memory. The joint architectural relation keeps native state bindings explicit. -/
theorem initialized_storage (addresses : Arm64Registers.PointerOrigins)
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
      Nonempty (Arm64ProducerRegisterStorage.Storage initialMemory after entry) ∧
      (∀ i : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val =
        some (Arm64EntryAdmissibility.rawValue ctx values i,
          .Vint ((Arm64EntryAdmissibility.rawTag i).setWidth 32))) ∧
      Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0)
        Arm64Program._sp = some (.Vlong 0) ∧
      Arm64EntryMemory.flags after.nextblock after (.Vptr entry.block 0) =
        some (.Vint (flagWord (flagValues 0)), .Vint (flagWord (flagValues 1)),
          .Vint (flagWord (flagValues 2)), .Vint (flagWord (flagValues 3))) ∧
      (∀ (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State),
        (∀ r, Reference.AArch64.gpr s r = Reference.Provenance.AArch64.materialize origins
          (Arm64EntryAdmissibility.rawWord ctxWord values r) (Arm64EntryAdmissibility.rawTag r)) →
        Reference.AArch64.sp s = origins.stack →
        (∀ i, Arm64ProducerEntryView.flagValues s i = .Vint (flagWord (flagValues i))) →
        (∀ high i, Arm64ProducerVectorView.vectorHalf s high i =
          vectorValues (vectorInputIndex high i)) →
        Arm64Registers.Represents addresses origins (fun r => r.val)
          after.nextblock after (.Vptr entry.block 0) s) ∧
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
      tailSources, after, le, traces, length, flagBindings, lrBinding, spBinding, run,
      headerReads, pointerReads, vectorViews, tailReads, stackEqual, contextEqual, abiEqual,
      wordsEqual, tagsEqual, lrEqual, spEqual, wordPointers, tagPointers, reads, flagReads,
      lrRead, vectorReads, stackReads, spRead, contextReads, caches, frame, access, next,
      index, ctxRead⟩ :=
    Arm64NumericProducerVectorLoop.initialized_vectors addresses ctx continuation ctxWord represented
      k values flagValues vectorValues gprProvider flagProvider vectorProvider
  let tables : (selected : Bool) → TableLocals selected initialMemory
    | false => words
    | true => tags
  have slots : ∀ selected (i : Fin 31), CC.Mem.load CC.Mptr after
      (tables selected).tableBlock (8 * (i.val : Int)) =
      some (.Vptr ((tables selected).cellBlock i) 0) := by
    intro selected i
    cases selected
    · exact wordPointers i
    · exact tagPointers i
  have spData : CC.Mem.load .Mint64 after (sources 5).block 0 = some (.Vlong 0) := by
    rw [spEqual]; exact spRead
  have storage : Nonempty (Arm64ProducerRegisterStorage.Storage initialMemory after entry) :=
    ⟨Arm64ProducerRegisterStorage.of_header initialMemory after entry sources tables vector
      pointerReads access headerReads slots 0 spData⟩
  have tagBits : ∀ i : Fin 31, (Arm64EntryAdmissibility.rawTag i).setWidth 32 =
      (if i = 0 then 1 else if i = 30 then 10 else 0) := by decide +kernel
  have gprs : ∀ i : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val =
      some (Arm64EntryAdmissibility.rawValue ctx values i,
        .Vint ((Arm64EntryAdmissibility.rawTag i).setWidth 32)) := by
    apply Arm64ProducerGprView.table_gpr_readbacks initialMemory after entry sources words tags
      (Arm64EntryAdmissibility.rawValue ctx values) Arm64EntryAdmissibility.rawTag
      headerReads wordPointers tagPointers
    · intro i
      exact (reads i).1
    · intro i
      simpa only [tagBits] using (reads i).2
  have spView : Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0)
      Arm64Program._sp = some (.Vlong 0) :=
    Arm64ProducerEntryView.header_borrowed_readback after entry.block 5 .Mint64
      (sources 5).block 0 (.Vlong 0) (headerReads 5) spData
  have flagMetadata : ∀ i : Fin 4,
      headerSourceName (Arm64ProducerEntryView.flagIndex i) = (flagDeclaration i).name ∧
      headerSourceType (Arm64ProducerEntryView.flagIndex i) = CC.tuchar := by decide +kernel
  have flagBytes : ∀ i, CC.Mem.load .Mint8unsigned after
      (sources (Arm64ProducerEntryView.flagIndex i)).block 0 =
      some (.Vint (flagWord (flagValues i))) := by
    intro i
    have binding := (sources (Arm64ProducerEntryView.flagIndex i)).binding
    rw [(flagMetadata i).1, (flagMetadata i).2] at binding
    have same : (sources (Arm64ProducerEntryView.flagIndex i)).block = flagBlocks i :=
      congrArg Prod.fst (Option.some.inj (binding.symm.trans (flagBindings i)))
    rw [same]; exact (flagReads i).1
  have flagsView := Arm64ProducerEntryView.flags_readback after entry.block
    (fun i => (sources i).block) (fun i => .Vint (flagWord (flagValues i))) headerReads flagBytes
  have representedWords : ∀ i, Arm64Registers.ValueRep addresses
      (Arm64EntryAdmissibility.rawValue ctx values i)
      (Arm64EntryAdmissibility.rawWord ctxWord values i) := by
    intro i
    by_cases zero : i = 0
    · simpa [Arm64EntryAdmissibility.rawValue, Arm64EntryAdmissibility.rawWord, zero] using represented
    · simp [Arm64EntryAdmissibility.rawValue, Arm64EntryAdmissibility.rawWord, zero, Arm64Registers.ValueRep]
  refine ⟨init, words, tags, flagBlocks, lrBlock, vector, stackTags, spBlock, cells, entry, sources,
    tailSources, after, le, traces, length, flagBindings, lrBinding, spBinding, run,
    headerReads, pointerReads, vectorViews, storage, gprs, spView, flagsView, ?_, tailReads,
    stackEqual, contextEqual, abiEqual, wordsEqual, tagsEqual, lrEqual, spEqual,
    wordPointers, tagPointers, reads, flagReads, lrRead, vectorReads, stackReads, spRead,
    contextReads, caches, frame, access, next, index, ctxRead⟩
  intro origins s nativeGpr nativeSp nativeFlags nativeVectors
  refine ⟨?_, ⟨0, spView, by simpa using nativeSp⟩, ?_, ?_⟩
  · intro r
    exact ⟨Arm64EntryAdmissibility.rawValue ctx values r,
      Arm64EntryAdmissibility.rawWord ctxWord values r, Arm64EntryAdmissibility.rawTag r,
      gprs r, representedWords r, nativeGpr r⟩
  · intro i
    have read := vectorViews i
    rw [← nativeVectors false i, ← nativeVectors true i] at read
    simpa only [Arm64ProducerVectorView.vectorHalf, Bool.false_eq_true, ite_false, ite_true] using read
  · apply Arm64ProducerEntryView.header_flags_represent after entry.block
      (fun i => (sources i).block) s headerReads
    intro i
    rw [nativeFlags i]
    exact flagBytes i

end KProgFormal.ClightRefinement.Arm64NumericProducerRegisterStorage
