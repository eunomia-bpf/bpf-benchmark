import KProgFormal.ClightRefinement.Arm64ProducerAbiTransport
import KProgFormal.ClightRefinement.Arm64ProgramEntryGprInputs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerAbiGprInputs

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryRegisterSource (declaration afterRegisters)
open Arm64ProgramEntryGprInputs (wordValue)
open Arm64Producer (tableCellName tableCellType TailLocal)

private theorem caches_separate : ∀ returns (i : Fin 31),
    Arm64Producer.baseName returns ≠ (declaration i).word ∧
    Arm64Producer.baseName returns ≠ (declaration i).tag ∧
    Arm64Producer.validName returns ≠ (declaration i).word ∧
    Arm64Producer.validName returns ≠ (declaration i).tag := by decide +kernel

private theorem abi_separate : ∀ i : Fin 31,
    Arm64Producer.tailLocalName 6 ≠ (declaration i).word ∧
    Arm64Producer.tailLocalName 6 ≠ (declaration i).tag := by decide +kernel

/-- The same actual entry and all30 provider outcomes retain their complete
register/cache readbacks and the ABI byte from the real initializer. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : TailLocal initial 6) (values : Fin 31 → BitVec 64)
    (provider : Arm64ProducerGprInputs.ProviderAt world initial values) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      (∀ selected i, (allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterRegisters k
          (allocation initial).1 finalLe after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 = some (.Vlong (wordValue values i)) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ finalLe.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock ∧
      CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) := by
  obtain ⟨ready,prefixRun,caches,frame,access,next⟩ := Arm64ProgramEntryInputs.entry_setup initial ctx k
  have abi := Arm64ProducerAbiTransport.setup_observed initial ready ctx k kind prefixRun
  have canonical : ready.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨blocks,after,finalLe,traces,length,bindings,run,reads,locals,temps,
      resultFrame,resultAccess,resultNext⟩ := Arm64ProgramEntryGprInputs.initialized initial ready
    (Arm64ProgramEntryCall.initialTemps ctx) k values provider canonical
  rw [Arm64ProgramEntryRegisterSource.first_stage] at run
  refine ⟨blocks,after,finalLe,traces,length,bindings,
    (fun selected i => Arm64ProgramEntryGprInputs.actual_cell_binding initial selected i _ (bindings selected i)),
    ?_,reads,?_,?_,frame.trans resultFrame,resultAccess.trans access,resultNext.trans next,?_⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans prefixRun.sound run
  · intro returns
    obtain ⟨cache,baseBinding,validBinding,base,valid⟩ := caches returns
    refine ⟨cache,baseBinding,validBinding,?_,?_⟩
    · exact (locals _ _ _ cache.baseBinding (fun i => ⟨(caches_separate returns i).1,
        (caches_separate returns i).2.1⟩) .Mint64 0).trans base
    · exact (locals _ _ _ cache.validBinding (fun i => ⟨(caches_separate returns i).2.2.1,
        (caches_separate returns i).2.2.2⟩) .Mint8unsigned 0).trans valid
  · exact (temps _ (fun i => ⟨Ne.symm (Arm64ProgramEntryRegisterSource.storage_metadata i).2.2.2.2.2.1,
      Ne.symm (Arm64ProgramEntryRegisterSource.storage_metadata i).2.2.2.2.2.2⟩)).trans
      (Arm64ProgramEntryCall.initial_context ctx)
  · exact (locals _ _ _ kind.binding abi_separate .Mint8unsigned 0).trans abi

end KProgFormal.ClightRefinement.Arm64ProducerAbiGprInputs
