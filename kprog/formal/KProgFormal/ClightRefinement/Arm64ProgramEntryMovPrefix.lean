import KProgFormal.ClightRefinement.Arm64ProgramEntryMovPair

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovPrefix

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBody (setupTemps afterSetup contextOffset)
open Arm64ProgramEntryBodyView (nativeSetup)
open Arm64ProgramEntryMovCall (markTemps priorityTemps afterKeep)

/-- From the actual wrapper entry through all98 input visits, setup and both
original MOV calls. The last origin reply/frame is admitted only at the actual
reached generic-call heap; no provider availability on other heaps is assumed. -/
theorem entry_pair (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
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
    ∃ entry : HeaderLocal initial, ∃ ready temps, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) ready) ∧
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
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  obtain ⟨entry, cells, sources, localVector, before, temps, ready, traces, length, entryRun,
      pointers, vectorPointers, tailReads, storage, result, registers, resources, ⟨data⟩, readyAccess, beforeNext⟩ :=
    Arm64ProgramEntryBodyView.entry_setup_represents initial ctxBlock ctxOfs k addresses ctxWord context
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
  refine ⟨entry, ready, temps, traces, length, entryRun, ?_⟩
  intro supplied trace origin outcome
  obtain ⟨firstWritten, middle, secondWritten, after, finalStorage, finalWord, finalTag, pair,
      finalRegisters, frame, firstFree, firstFreeFrame, firstContents, middleNext, firstReleased,
      secondFree, secondFreeFrame, secondContents, afterNext, secondReleased⟩ :=
    Arm64ProgramEntryMovPair.execute result.storage cells pointers access bound cold addresses origins
      (nativeSetup s origins fields) represented (setupTemps temps fields) k ctxBlock ctxOfs
      (fields 0) (fields 1) result.ctx old (result.context 0) (result.context 1) trace origin outcome
  exact ⟨firstWritten, middle, secondWritten, after, finalStorage, finalWord, finalTag,
    star_trans entryRun pair, finalRegisters, result.frame.trans frame, firstFree, firstFreeFrame,
    firstContents, middleNext, firstReleased, secondFree, secondFreeFrame, secondContents, afterNext, secondReleased⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovPrefix
