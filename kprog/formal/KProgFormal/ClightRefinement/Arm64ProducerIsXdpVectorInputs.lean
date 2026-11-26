import KProgFormal.ClightRefinement.Arm64ProducerIsXdpFlags
import KProgFormal.ClightRefinement.Arm64ProgramEntryVectorInputs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerIsXdpVectorInputs

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryVectorInputs (Readbacks afterVectorInputs metadata)
open Arm64Producer (TableLocals TailLocal tableCellName tableCellType tableName tableType)

private theorem cells_separate : ∀ selected (i : Fin 31),
    tableCellName selected i ≠ Arm64Entry.___a64_vectors := by decide +kernel

private theorem tables_separate : ∀ selected,
    tableName selected ≠ Arm64Entry.___a64_vectors := by decide +kernel

private theorem flags_separate : ∀ i : Fin 4,
    (Arm64ProgramEntryFlags.declaration i).name ≠ Arm64Entry.___a64_vectors := by
  have different : ∀ i : Fin 4, (Arm64Producer.flagDeclaration i).name ≠ Arm64Entry.___a64_vectors := by
    decide +kernel
  intro i
  rw [(Arm64ProgramEntryFlags.metadata i).1]
  exact different i

private theorem caches_separate : ∀ returns,
    Arm64Producer.baseName returns ≠ Arm64Entry.___a64_vectors ∧
    Arm64Producer.validName returns ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- Actual entry through all98 provider visits, with every prior observation
framed by the same reached memory and actual production environment. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : TailLocal initial 6) (cell : TailLocal initial 5)
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
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterVectorInputs
          k (allocation initial).1 le after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 =
          some (.Vlong (Arm64ProgramEntryGprInputs.wordValue values i)) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      (∀ selected, ∃ locals : TableLocals selected initial,
        (allocation initial).1.get (tableName selected) = some (locals.tableBlock, tableType selected) ∧
        (∀ i, (allocation initial).1.get (tableCellName selected i) =
          some (locals.cellBlock i, tableCellType selected)) ∧
        ∀ i, CC.Mem.load CC.Mptr after locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (blocks selected i) 0)) ∧
      Arm64ProgramEntryFlags.Readbacks initial after flags ∧
      Readbacks initial after vectors ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ le.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock ∧
      CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) ∧
      CC.Mem.load .Mint8unsigned after cell.block 0 = some (.Vint 0) := by
  obtain ⟨blocks, before, le, priorTraces, priorLength, bindings, actualBindings,
      priorRun, registers, tables, flagReadbacks, caches, context, frame, access, next,abi,isXdp⟩ :=
    Arm64ProducerIsXdpFlags.entry_initialized initial ctx k kind cell values provider flags flagProvider
  obtain ⟨localVector, after, finalLe, vectorTraces, vectorLength, vectorBinding,
      vectorRun, vectorReads, other, temps, vectorFrame, vectorAccess, vectorNext⟩ :=
    Arm64ProgramEntryVectorInputs.initialized initial before le k vectors vectorProvider access
  refine ⟨blocks, after, finalLe, priorTraces ++ vectorTraces, ?_, bindings, actualBindings,
    ?_, ?_, ?_, ?_, ⟨localVector, vectorBinding, vectorReads⟩, ?_, ?_,
    frame.trans vectorFrame, vectorAccess.trans access, vectorNext.trans next,?_,?_⟩
  · simp only [List.length_append, priorLength, vectorLength]
  · simpa only [List.flatten_append, CC.Eapp] using star_trans priorRun vectorRun
  · intro i
    exact ⟨(other _ _ _ (bindings false i) (cells_separate false i) .Mint64 0).trans (registers i).1,
      (other _ _ _ (bindings true i) (cells_separate true i) .Mint8unsigned 0).trans (registers i).2⟩
  · intro selected
    obtain ⟨locals, bound, cells, reads⟩ := tables selected
    refine ⟨locals, bound, cells, ?_⟩
    intro i
    exact (other _ _ _ locals.binding (tables_separate selected) CC.Mptr (8 * (i.val : Int))).trans (reads i)
  · obtain ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding,
        flagsRead, lrRead⟩ := flagReadbacks
    refine ⟨flagBlocks, lrBlock, flagBindings, actualFlagBindings, lrBinding, actualLrBinding, ?_, ?_⟩
    · intro i
      exact (other _ _ _ (flagBindings i) (flags_separate i) .Mint8unsigned 0).trans (flagsRead i)
    · exact (other _ _ _ lrBinding (by decide +kernel) .Mint64 0).trans lrRead
  · intro returns
    obtain ⟨locals, baseBound, validBound, base, valid⟩ := caches returns
    refine ⟨locals, baseBound, validBound, ?_, ?_⟩
    · exact (other _ _ _ locals.baseBinding (caches_separate returns).1 .Mint64 0).trans base
    · exact (other _ _ _ locals.validBinding (caches_separate returns).2 .Mint8unsigned 0).trans valid
  · exact (temps _ (fun i => Ne.symm (metadata i).2.2)).trans context

  · exact (other _ _ _ kind.binding (by decide +kernel) .Mint8unsigned 0).trans abi

  · have separate : Arm64Producer.tailLocalName 5 ≠ Arm64Entry.___a64_vectors := by decide +kernel
    exact (other _ _ _ cell.binding separate .Mint8unsigned 0).trans isXdp

end KProgFormal.ClightRefinement.Arm64ProducerIsXdpVectorInputs
