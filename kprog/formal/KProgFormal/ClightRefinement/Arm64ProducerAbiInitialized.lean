import KProgFormal.ClightRefinement.Arm64ProducerAbiRawSetup
import KProgFormal.ClightRefinement.Arm64ProgramEntryInitialized

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerAbiInitialized

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryInitialized (Values)
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal VectorLocal)

/-- The original98-provider entry and actual complete header/vector-pointer
initialization retain every source readback plus the SAME ABI byte and pointer. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : TailLocal initial 6)
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
      after.nextblock = (allocation initial).2.nextblock ∧
      CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) ∧
      CC.Mem.load CC.Mptr after entry.block 704 = some (.Vptr kind.block 0) := by
  obtain ⟨blocks, before, temps, traces, length, bindings, actualBindings, priorRun, registers,
    tables, flagReads, vectorReads, rawReads, cacheReads, context, frame, access, next,abi⟩ :=
    Arm64ProducerAbiRawSetup.entry_initialized initial ctx k kind addresses ctxWord represented
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
    resources, frame.trans suffixFrame, finalAccess, suffixNext.trans next,?_,?_⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans priorRun suffix.sound
  · exact (otherTemps _ (by decide +kernel)).trans context

  · exact (locals _ _ _ kind.binding (by decide +kernel) .Mint8unsigned 0).trans abi
  · have pointer := tailPointers (13 : Fin 16)
    change CC.Mem.load CC.Mptr after entry.block 704 = some (.Vptr (sources 6).block 0) at pointer
    have same : (sources 6).block = kind.block :=
      congrArg Prod.fst (Option.some.inj ((sources 6).binding.symm.trans kind.binding))
    simpa only [same] using pointer

end KProgFormal.ClightRefinement.Arm64ProducerAbiInitialized
