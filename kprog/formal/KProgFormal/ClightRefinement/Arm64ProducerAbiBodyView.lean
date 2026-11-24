import KProgFormal.ClightRefinement.Arm64ProducerAbiInitialized
import KProgFormal.ClightRefinement.Arm64ProgramEntryBodyView

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerAbiBodyView

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBody (flagName afterSetup setupTemps contextOffset)
open Arm64ProgramEntryBodyView (Result nativeSetup setup_represents)

private theorem header_other : Arm64Entry._entry ≠ Arm64Entry.___a64_sp ∧
    ∀ i : Fin 4, Arm64Entry._entry ≠ flagName i := by decide +kernel

/-- Execute the actual context/SP/flag setup after the same98-provider entry,
retaining its native register view, actual result and ABI byte/header pointer. -/
theorem entry_setup_represents (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
    (kind : TailLocal initial 6)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (context : Arm64Registers.ValueRep addresses (.Vptr ctxBlock ctxOfs) ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (native : Arm64ProgramEntryRegisterView.NativeBindings origins ctxWord values flags vectors s)
    (fields : Fin 3 → BitVec 32) (old : ctxBlock.toNat < initial.nextblock.toNat)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (fields i))) :
    ∃ entry : HeaderLocal initial, ∃ cells : (i : Fin 12) → HeaderSourceLocal initial i,
    ∃ sources : (i : Fin 9) → TailLocal initial i, ∃ localVector : VectorLocal initial,
    ∃ before temps after, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup
          k (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
        some (.Vptr (cells i).block 0)) ∧
      (∀ high (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr localVector.block (vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) =
        some (Arm64ProgramEntryTail.actualValue sources i)) ∧
      ∃ storage : Storage initial before entry,
        Result storage temps k ctxBlock ctxOfs fields after ∧
        Arm64Registers.Represents addresses origins (fun r => r.val)
          before.nextblock after (.Vptr entry.block 0) (nativeSetup s origins fields) ∧
        Arm64ProgramEntryResources.Resources initial after entry ∧
        Nonempty (Arm64ProgramEntryInitialized.Values initial before (.Vptr ctxBlock ctxOfs)
          values flags vectors) ∧
        after.access = (Arm64Producer.allocation initial).2.access ∧
        before.nextblock = (Arm64ProgramEntryAllocation.allocation initial).2.nextblock ∧
        CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) ∧
        CC.Mem.load CC.Mptr after entry.block 704 = some (.Vptr kind.block 0) := by
  obtain ⟨entry,cells,sources,localVector,before,temps,traces,length,run,
      index,ctx,pointers,vectorPointers,tailReads,⟨data⟩,⟨storage⟩,
      resources,frame,access,next,abi,abiPointer⟩ :=
    Arm64ProducerAbiInitialized.entry_initialized initial (.Vptr ctxBlock ctxOfs) k kind
      addresses ctxWord context values provider flags flagProvider vectors vectorProvider
  have registers := Arm64ProgramEntryRegisterView.represents data entry cells localVector pointers vectorPointers
    addresses origins ctxWord context s native
  have sourceAccess : before.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨after, result, finalRegisters⟩ := setup_represents storage temps k ctxBlock ctxOfs fields
    ctx old frame reads sourceAccess addresses origins s registers
  refine ⟨entry, cells, sources, localVector, before, temps, after, traces, length,
    ?_, ?_, ?_, ?_, storage, result, finalRegisters, ?_, ⟨data⟩, result.access.trans sourceAccess, next,?_,?_⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans run result.run.sound
  · intro i
    exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 CC.Mptr _).trans (pointers i)
  · intro high i
    exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 CC.Mptr _).trans (vectorPointers high i)
  · intro i
    exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 (tailChunk i) _).trans (tailReads i)
  · apply Arm64ProgramEntryResources.resources initial after entry cells (result.access.trans sourceAccess)
    intro i
    exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 CC.Mptr _).trans (pointers i)

  · have keptKind : Arm64Producer.tailLocalName 6 ≠ Arm64Entry.___a64_sp ∧
        ∀ i : Fin 4, Arm64Producer.tailLocalName 6 ≠ flagName i := by decide +kernel
    exact (result.local_load _ _ _ kind.binding keptKind.1 keptKind.2 .Mint8unsigned 0).trans abi
  · exact (result.local_load _ _ _ entry.binding header_other.1 header_other.2 CC.Mptr 704).trans abiPointer

end KProgFormal.ClightRefinement.Arm64ProducerAbiBodyView
