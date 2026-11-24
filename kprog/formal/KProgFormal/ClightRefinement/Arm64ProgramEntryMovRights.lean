import KProgFormal.ClightRefinement.Arm64MovImmediateLinkedRights
import KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovRights

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryMovCall

/-- The original first MOV callsite, actual complete cold call, return and
priority read retain every original effect plus the header/tail load frame. -/
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
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 = some (.Vlong (mark.setWidth 64)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryBody.afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        trace (.State Arm64ProgramFixture.f_arm64_execute_compile nextCall (.Kseq afterKeep k)
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps le mark) priority) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false) ∧
      FrameBelow initial.nextblock before after ∧
      (priorityTemps (markTemps le mark) priority).get Arm64ProgramFixture._t'167 = some (.Vint priority) ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = (Arm64Nop.allocation world before).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      Arm64ProducerTailFrame.Frame initial entry before after ∧
      (∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
        CC.PMap.get block after.access = CC.PMap.get block before.access) := by
  obtain ⟨written, after, finalStorage, word, tag, call, registers, frame, freed, freeFrame, contents, next, released, finalPointers, finalWarm,tailFrame,permissionFrame⟩ :=
    Arm64MovImmediate.LinkedRights.entry_call storage header pointers access bound cold addresses origins s represented mark trace
      provider outcome (callCont initial le k mark) rfl
  have entered := enter entry le k before ctxBlock ctxOfs mark ctx markRead
  have returned := leave initial le k mark after
  have nextCtx : (markTemps le mark).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) := by
    simp +decide only [markTemps, CC.PTree.gso, ctx]
  have nextRead := (Arm64ProgramEntryBody.context_read_frame frame ctxBlock old ctxOfs 1).trans priorityRead
  have priorityLoad := priority_ready initial (markTemps le mark) k after ctxBlock ctxOfs priority nextCtx nextRead
  refine ⟨written, after, finalStorage, word, tag, ?_, registers, frame, CC.PTree.gss _ _ _,
    freed, freeFrame, contents, next, released, finalPointers, finalWarm,tailFrame,permissionFrame⟩
  simpa only [CC.Eapp, CC.E0, List.nil_append, List.append_nil] using
    star_trans (star_trans entered.sound call) (returned.trans priorityLoad).sound

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovRights
