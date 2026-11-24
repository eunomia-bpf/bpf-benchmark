import KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall
import KProgFormal.ClightRefinement.Arm64MovKeepWordRights

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovKeepRights

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryMovCall

/-- The real MOVK callsite, handler and return retain producer permissions. -/
theorem execute_keep {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (bits : BitVec 64) (priority : BitVec 32)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont)
    (loaded : le.get Arm64ProgramFixture._t'167 = some (.Vint priority)) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 =
        some (.Vlong (Arm64MovKeep.mergeWord bits (priority.setWidth 64) 1)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      InternalRun world 206
        (.State Arm64ProgramFixture.f_arm64_execute_compile nextCall (.Kseq afterKeep k)
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterKeep k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate s 1 (Arm64MovKeep.mergeWord bits (priority.setWidth 64) 1) false) ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after 1 ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
        CC.PMap.get block after.access = CC.PMap.get block before.access) := by
  obtain ⟨written, after, finalStorage, finalWord, finalTag, call, registers, frame, freed,
      freeFrame, contents, next, released, kept, finalBound,permissionFrame⟩ :=
    Arm64MovKeep.LinkedWordRights.call storage bound (keepOperands entry.block priority) addresses origins s
      1 bits (priority.setWidth 64) 1 false word tag represented (keepCont initial le k) rfl
  have entered := keep_enter entry le k before priority loaded
  have returned := keep_leave initial le k after
  refine ⟨written, after, finalStorage, finalWord, finalTag, ?_, registers, frame, freed,
    freeFrame, contents, next, released, kept, finalBound,permissionFrame⟩
  exact (entered.trans call).trans returned

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovKeepRights
