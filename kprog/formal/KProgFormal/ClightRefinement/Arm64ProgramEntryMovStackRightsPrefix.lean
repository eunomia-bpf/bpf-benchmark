import KProgFormal.ClightRefinement.Arm64ProgramEntryResourceTransport
import KProgFormal.ClightRefinement.Arm64ProgramEntryMovPairRights
import KProgFormal.ClightRefinement.Arm64MemsetHeaderView
import KProgFormal.ClightRefinement.Arm64ProgramEntryMovPairTail
import KProgFormal.ClightRefinement.Arm64ProgramEntryMovPrefix
import KProgFormal.ClightRefinement.Arm64ProducerAbiBodyView

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovStackRightsPrefix

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBody (setupTemps afterSetup contextOffset)
open Arm64ProgramEntryBodyView (nativeSetup)
open Arm64ProgramEntryMovCall (markTemps priorityTemps afterKeep)

private theorem tag_reads {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {ctx : CC.Val} {values : Fin 31 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    (data : Arm64ProgramEntryInitialized.Values initial before ctx values flags vectors)
    (frame : Arm64ProducerTailFrame.Frame initial entry before after) :
    ∀ (tags : StackTagLocal initial) (i : Fin 24),
      CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0) := by
  obtain ⟨actualTags,_sp,_cells,_actualBinding,_spBinding,_actualSp,_cellBindings,reads,_spRead,_context⟩ := data.rawReads
  intro tags i
  have same : tags.block = actualTags.block :=
    congrArg Prod.fst (Option.some.inj (tags.binding.symm.trans actualTags.binding))
  have prior : CC.Mem.load .Mint8unsigned before tags.block (i.val : Int) = some (.Vint 0) := by
    rw [same]
    exact reads i
  exact (frame.tail 2 ⟨tags.block,tags.binding⟩ .Mint8unsigned (i.val : Int)).trans prior

/-- From the actual wrapper entry through all98 input visits, setup and both
original MOV calls. The last origin reply/frame is admitted only at the actual
reached generic-call heap; no provider availability on other heaps is assumed. -/
theorem entry_pair (initial : CC.Mem) (ctxBlock : CC.Block)
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
    ∃ entry : HeaderLocal initial, ∃ header : (j : Fin 12) → HeaderSourceLocal initial j, ∃ ready temps, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      ready.nextblock = (Arm64Producer.allocation initial).2.nextblock ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) ready) ∧
      (setupTemps temps fields).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
      Nonempty (Arm64MemsetHeaderView.Ready initial ready entry) ∧
      ∀ (supplied : CC.Mem) (trace : CC.Trace),
        CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
          [.Vint 1] (Arm64Nop.allocation world ready).2 trace (.Vlong origins.stack) supplied →
        Arm64ProgramEntryCacheFrame.Frame initial false (Arm64Nop.allocation world ready).2 supplied →
    ∃ firstWritten middle secondWritten after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        (CC.Eapp traces.flatten trace) (.State Arm64ProgramFixture.f_arm64_execute_compile afterKeep k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps (setupTemps temps fields) (fields 0)) (fields 1)) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) ready.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate
          (Arm64RegisterWrite.nativeUpdate (nativeSetup s origins fields) 1 ((fields 0).setWidth 64) false)
          1 (Arm64MovKeep.mergeWord ((fields 0).setWidth 64) ((fields 1).setWidth 64) 1) false) ∧
      FrameBelow initial.nextblock initial after ∧
      CC.Mem.freeList firstWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world ready).1) = some middle ∧
      FrameBelow ready.nextblock firstWritten middle ∧
      middle.contents = firstWritten.contents ∧
      middle.nextblock = (Arm64Nop.allocation world ready).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world ready).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm middle row.1 ofs kind permission = false) ∧
      CC.Mem.freeList secondWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1) = some after ∧
      FrameBelow middle.nextblock secondWritten after ∧
      after.contents = secondWritten.contents ∧ after.nextblock = secondWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false ready.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      Arm64ProducerTailFrame.Frame initial entry ready after ∧
      CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) ∧
      CC.Mem.load CC.Mptr after entry.block 704 = some (.Vptr kind.block 0) ∧
      (∀ (tags : StackTagLocal initial) (i : Fin 24),
        CC.Mem.load .Mint8unsigned after tags.block (i.val : Int) = some (.Vint 0)) ∧
      Nonempty (Arm64MemsetHeaderView.View initial after entry) ∧
      Arm64ProgramEntryResources.Resources initial after entry ∧
      (∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
        CC.PMap.get block after.access = CC.PMap.get block ready.access) := by
  obtain ⟨entry, cells, sources, localVector, before, temps, ready, traces, length, entryRun,
      pointers, vectorPointers, tailReads, storage, result, registers, resources, ⟨data⟩, readyAccess, beforeNext,abi,abiPointer,⟨initialView⟩⟩ :=
    Arm64MemsetHeaderView.entry_setup_represents initial ctxBlock ctxOfs k kind addresses ctxWord context
      values provider flags flagProvider vectors vectorProvider origins s native fields old reads
  have readyNext : ready.nextblock = (Arm64Producer.allocation initial).2.nextblock :=
    result.nextblock.trans (beforeNext.trans
      (congrArg CC.Mem.nextblock (Arm64ProgramEntryAllocation.allocation_corresponds initial).1).symm)
  have bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ ready.nextblock.toNat := by
    exact Nat.le_of_eq (congrArg (fun block : CC.Block => block.toNat) readyNext.symm)
  have represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      ready.nextblock ready (.Vptr entry.block 0) (nativeSetup s origins fields) := by
    simpa only [result.nextblock] using registers
  have access : ∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
      CC.PMap.get block ready.access = CC.PMap.get block (Arm64Producer.allocation initial).2.access := by
    intro block _; rw [readyAccess]
  have cold : Arm64EntryMemory.borrowed ready.nextblock .Mint8unsigned ready (.Vptr entry.block 0)
      Arm64Program._sp_valid = some (.Vint 0) := by
    rw [result.nextblock]
    exact (Arm64ProgramEntryColdRead.cold_cache_reads result data cells pointers false).2
  refine ⟨entry, cells, ready, temps, traces, length, readyNext, entryRun, result.ctx, ⟨⟨initialView,resources,readyAccess⟩⟩, ?_⟩
  intro supplied trace origin outcome
  obtain ⟨firstWritten, middle, secondWritten, after, finalStorage, finalWord, finalTag, pair,
      finalRegisters, frame, firstFree, firstFreeFrame, firstContents, middleNext, firstReleased,
      secondFree, secondFreeFrame, secondContents, afterNext, secondReleased, finalPointers, finalWarm, finalBound,pairTail,pairPermissions⟩ :=
    Arm64ProgramEntryMovPairRights.execute result.storage cells pointers access bound cold addresses origins
      (nativeSetup s origins fields) represented (setupTemps temps fields) k ctxBlock ctxOfs
      (fields 0) (fields 1) result.ctx old (result.context 0) (result.context 1) trace origin outcome
  have observed := pairTail.abi kind abiPointer abi
  have initializedTags := tag_reads data ((Arm64ProducerTailFrame.of_setup result).trans pairTail)
  exact ⟨firstWritten, middle, secondWritten, after, finalStorage, finalWord, finalTag,
    star_trans entryRun pair, finalRegisters, result.frame.trans frame, firstFree, firstFreeFrame,
    firstContents, middleNext, firstReleased, secondFree, secondFreeFrame, secondContents, afterNext, secondReleased, finalPointers, finalWarm, finalBound,pairTail,observed.2,observed.1,initializedTags,
    ⟨Arm64MemsetHeaderView.of_frame initialView pairTail⟩,
    Arm64ProgramEntryResourceTransport.resources resources pairTail pairPermissions,pairPermissions⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovStackRightsPrefix
