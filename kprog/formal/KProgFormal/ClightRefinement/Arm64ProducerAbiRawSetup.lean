import KProgFormal.ClightRefinement.Arm64ProducerAbiVectorInputs
import KProgFormal.ClightRefinement.Arm64ProgramEntryRawSetup

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerAbiRawSetup

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryRawSetup (Readbacks beforeHeader tagWord)
open Arm64Producer (StackTagLocal ContextLocal TailLocal tableCellName tableCellType tableName tableType TableLocals
  contextName contextLocalType contextChunk contextValue)

private abbrev Protected (id : CC.Ident) : Prop :=
  id ≠ Arm64Entry.___a64_stack_tag ∧ id ≠ Arm64Entry.___a64_sp ∧ ∀ i : Fin 5, id ≠ contextName i

private theorem words_protected : ∀ i : Fin 31, i ≠ 0 → Protected (tableCellName false i) := by decide +kernel
private theorem tags_protected : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Protected (tableCellName true i) := by decide +kernel
private theorem tables_protected : ∀ selected, Protected (tableName selected) := by decide +kernel
private theorem flags_protected : ∀ i : Fin 4, Protected (Arm64ProgramEntryFlags.declaration i).name := by
  have different : ∀ i : Fin 4, Protected (Arm64Producer.flagDeclaration i).name := by decide +kernel
  intro i
  rw [(Arm64ProgramEntryFlags.metadata i).1]
  exact different i
private theorem lr_protected : Protected Arm64Entry.___a64_lr := by decide +kernel
private theorem vectors_protected : Protected Arm64Entry.___a64_vectors := by decide +kernel
private theorem caches_protected : ∀ returns,
    Protected (Arm64Producer.baseName returns) ∧ Protected (Arm64Producer.validName returns) := by decide +kernel

private theorem word_expected (values : Fin 31 → BitVec 64) (ctx : CC.Val) (i : Fin 31) (nonzero : i ≠ 0) :
    .Vlong (Arm64ProgramEntryGprInputs.wordValue values i) = Arm64EntryAdmissibility.rawValue ctx values i := by
  simp only [Arm64EntryAdmissibility.rawValue, ite_eq_right nonzero]
  by_cases last : i = 30
  · subst i; rfl
  · have notLast : i.val ≠ 30 := fun same => last (Fin.ext same)
    simp only [Arm64ProgramEntryGprInputs.wordValue, ite_eq_right notLast, ite_eq_right last]

/-- Actual entry through the silent RAW setup. x0 is replaced by context,
x0/x30 tags change to1/10, and all other previously derived observations survive. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : TailLocal initial 6)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after le, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      (∀ selected i, (allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile beforeHeader
          k (allocation initial).1 le after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 =
          some (Arm64EntryAdmissibility.rawValue ctx values i) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint (tagWord i))) ∧
      (∀ selected, ∃ locals : TableLocals selected initial,
        (allocation initial).1.get (tableName selected) = some (locals.tableBlock, tableType selected) ∧
        (∀ i, (allocation initial).1.get (tableCellName selected i) =
          some (locals.cellBlock i, tableCellType selected)) ∧
        ∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (blocks selected i) 0)) ∧
      Arm64ProgramEntryFlags.Readbacks initial after flags ∧
      Arm64ProgramEntryVectorInputs.Readbacks initial after vectors ∧
      Readbacks initial after ctx ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ le.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock ∧
      CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) := by
  obtain ⟨blocks, before, le, traces, length, bindings, actualBindings, priorRun,
      registers, tables, flagReads, vectorReads, caches, context, frame, access, next,abi⟩ :=
    Arm64ProducerAbiVectorInputs.entry_initialized initial ctx k kind values provider flags flagProvider vectors vectorProvider
  obtain ⟨after, rawRun, rawReads, other, rawFrame, rawAccess, rawNext⟩ :=
    Arm64ProgramEntryRawSetup.initialized represented initial before le context k access
  obtain ⟨stackTags, spBlock, cells, tagsBinding, spBinding, actualSpBinding, cellBindings,
      stackReads, spRead, contextReads⟩ := rawReads
  refine ⟨blocks, after, le, traces, length, bindings, actualBindings, ?_, ?_, ?_, ?_, ?_,
    ⟨stackTags, spBlock, cells, tagsBinding, spBinding, actualSpBinding, cellBindings, stackReads, spRead, contextReads⟩,
    ?_, context, frame.trans rawFrame, rawAccess.trans access, rawNext.trans next,?_⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans priorRun rawRun.sound
  · intro i
    constructor
    · by_cases zero : i = 0
      · subst i
        have cellBound := (cells 2).binding
        change (Arm64Producer.allocation initial).1.get (tableCellName false 0) =
          some ((cells 2).block, tableCellType false) at cellBound
        have same : (cells 2).block = blocks false 0 :=
          congrArg Prod.fst (Option.some.inj (cellBound.symm.trans (bindings false 0)))
        have read := contextReads 2
        change CC.Mem.load .Mint64 after (cells 2).block 0 = some ctx at read
        simpa only [Arm64EntryAdmissibility.rawValue, ite_eq_left rfl, ite_true, same] using read
      · have keep := other _ _ _ (bindings false i) (words_protected i zero).1
          (words_protected i zero).2.1 (words_protected i zero).2.2 .Mint64 0
        rw [← word_expected values ctx i zero]
        exact keep.trans (registers i).1
    · by_cases zero : i = 0
      · subst i
        have cellBound := (cells 4).binding
        change (Arm64Producer.allocation initial).1.get (tableCellName true 0) =
          some ((cells 4).block, tableCellType true) at cellBound
        have same : (cells 4).block = blocks true 0 :=
          congrArg Prod.fst (Option.some.inj (cellBound.symm.trans (bindings true 0)))
        have read := contextReads 4
        change CC.Mem.load .Mint8unsigned after (cells 4).block 0 = some (.Vint 1) at read
        simpa only [tagWord, ite_eq_left rfl, ite_true, same] using read
      · by_cases last : i = 30
        · subst i
          have cellBound := (cells 3).binding
          change (Arm64Producer.allocation initial).1.get (tableCellName true 30) =
            some ((cells 3).block, tableCellType true) at cellBound
          have same : (cells 3).block = blocks true 30 :=
            congrArg Prod.fst (Option.some.inj (cellBound.symm.trans (bindings true 30)))
          have read := contextReads 3
          change CC.Mem.load .Mint8unsigned after (cells 3).block 0 = some (.Vint 10) at read
          simpa only [tagWord, ite_eq_right zero, ite_eq_left rfl, ite_true, same] using read
        · have keep := other _ _ _ (bindings true i) (tags_protected i zero last).1
            (tags_protected i zero last).2.1 (tags_protected i zero last).2.2 .Mint8unsigned 0
          simpa only [tagWord, ite_eq_right zero, ite_eq_right last] using keep.trans (registers i).2
  · intro selected
    obtain ⟨locals, bound, cellBounds, reads⟩ := tables selected
    refine ⟨locals, bound, cellBounds, ?_⟩
    intro i
    exact (other _ _ _ locals.binding (tables_protected selected).1 (tables_protected selected).2.1
      (tables_protected selected).2.2 CC.Mptr (8 * (i.val : Int))).trans (reads i)
  · obtain ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding,
        reads, lrRead⟩ := flagReads
    refine ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding, ?_, ?_⟩
    · intro i
      exact (other _ _ _ (flagBindings i) (flags_protected i).1 (flags_protected i).2.1
        (flags_protected i).2.2 .Mint8unsigned 0).trans (reads i)
    · exact (other _ _ _ lrBinding lr_protected.1 lr_protected.2.1 lr_protected.2.2 .Mint64 0).trans lrRead
  · obtain ⟨localVector, bound, reads⟩ := vectorReads
    refine ⟨localVector, bound, ?_⟩
    intro i
    exact (other _ _ _ localVector.binding vectors_protected.1 vectors_protected.2.1
      vectors_protected.2.2 .Mint64 (8 * (i.val : Int))).trans (reads i)
  · intro returns
    obtain ⟨locals, baseBound, validBound, base, valid⟩ := caches returns
    refine ⟨locals, baseBound, validBound, ?_, ?_⟩
    · exact (other _ _ _ locals.baseBinding (caches_protected returns).1.1
        (caches_protected returns).1.2.1 (caches_protected returns).1.2.2 .Mint64 0).trans base
    · exact (other _ _ _ locals.validBinding (caches_protected returns).2.1
        (caches_protected returns).2.2.1 (caches_protected returns).2.2.2 .Mint8unsigned 0).trans valid

  · have keptKind : Protected (Arm64Producer.tailLocalName 6) := by decide +kernel
    exact (other _ _ _ kind.binding keptKind.1 keptKind.2.1 keptKind.2.2 .Mint8unsigned 0).trans abi

end KProgFormal.ClightRefinement.Arm64ProducerAbiRawSetup
