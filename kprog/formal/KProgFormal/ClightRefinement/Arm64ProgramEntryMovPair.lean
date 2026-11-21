import KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovPair

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryMovCall

/-- Execute both original source calls on the same heap. Their advancing
allocation frontiers are transported using actual owned storage; the single
origin-provider trace and both real frame releases remain explicit. -/
theorem execute {initial before supplied : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr before entry.block (8 * (i.val : Int)) = some (.Vptr (header i).block 0))
    (access : ∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
      CC.PMap.get block before.access = CC.PMap.get block (Arm64Producer.allocation initial).2.access)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cold : Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      Arm64Program._sp_valid = some (.Vint 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (mark priority : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (old : ctxBlock.toNat < initial.nextblock.toNat)
    (markRead : CC.Mem.loadv .Mint32 before (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (priorityRead : CC.Mem.loadv .Mint32 before (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 32))) = some (.Vint priority))
    (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint 1] (Arm64Nop.allocation world before).2 trace (.Vlong origins.stack) supplied)
    (outcome : Arm64ProgramEntryCacheFrame.Frame initial false (Arm64Nop.allocation world before).2 supplied) :
    ∃ firstWritten middle secondWritten after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord (mark.setWidth 64) (priority.setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryBody.afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        trace (.State Arm64ProgramFixture.f_arm64_execute_compile afterKeep k
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps le mark) priority) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate
          (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)
          1 (Arm64MovKeep.mergeWord (mark.setWidth 64) (priority.setWidth 64) 1) false) ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList firstWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some middle ∧
      FrameBelow before.nextblock firstWritten middle ∧
      middle.contents = firstWritten.contents ∧
      middle.nextblock = (Arm64Nop.allocation world before).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm middle row.1 ofs kind permission = false) ∧
      CC.Mem.freeList secondWritten (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1) = some after ∧
      FrameBelow middle.nextblock secondWritten after ∧
      after.contents = secondWritten.contents ∧ after.nextblock = secondWritten.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world middle).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨firstWritten, middle, middleStorage, word, tag, first, firstRegisters, firstFrame,
      priorityLoaded, firstFree, firstFreeFrame, firstContents, middleNext, firstReleased, middlePointers, middleWarm⟩ :=
    Arm64ProgramEntryMovCall.execute storage header pointers access bound cold addresses origins s represented
      le k ctxBlock ctxOfs mark priority ctx old markRead priorityRead trace provider outcome
  have middleRegisters := (Arm64RegisterStorageFrontier.represents_iff middleStorage before.nextblock bound
    addresses origins (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)).mp firstRegisters
  have middleBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ middle.nextblock.toNat := by
    rw [middleNext]
    exact Nat.le_trans bound (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound world before)
      before.nextblock (Nat.le_refl _)).1
  obtain ⟨secondWritten, after, finalStorage, finalWord, finalTag, second, secondRegisters, secondFrame,
      secondFree, secondFreeFrame, secondContents, afterNext, secondReleased, kept, finalBound⟩ :=
    execute_keep middleStorage middleBound addresses origins
      (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false) (mark.setWidth 64) priority word tag
      middleRegisters (priorityTemps (markTemps le mark) priority) k priorityLoaded
  have finalRegisters := (Arm64RegisterStorageFrontier.represents_iff finalStorage before.nextblock bound
    addresses origins _).mpr ((Arm64RegisterStorageFrontier.represents_iff finalStorage middle.nextblock middleBound
      addresses origins _).mp secondRegisters)
  have finalPointers := kept.pointers header middlePointers
  have finalWarm := kept.warm before.nextblock header bound middlePointers false origins.stack middleWarm
  refine ⟨firstWritten, middle, secondWritten, after, finalStorage, finalWord, finalTag, ?_, finalRegisters,
    firstFrame.trans secondFrame, firstFree, firstFreeFrame, firstContents, middleNext, firstReleased,
    secondFree, secondFreeFrame, secondContents, afterNext, secondReleased, finalPointers, finalWarm, finalBound⟩
  simpa only [CC.Eapp, CC.E0, List.append_nil] using star_trans first second.sound

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovPair
