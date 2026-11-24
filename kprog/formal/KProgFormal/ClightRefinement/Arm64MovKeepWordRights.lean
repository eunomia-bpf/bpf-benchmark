import KProgFormal.ClightRefinement.Arm64MovKeepLinkedCall
import KProgFormal.ClightRefinement.Arm64ProgramEntryAllocation
import KProgFormal.ClightRefinement.Arm64CacheLocalFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovKeep.LinkedWordRights

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64RegisterStorageFrontier

/-- Execute the actual linked MOVK with its full immediate parameter. The
result's selected halfword follows mergeWord_low16; all actual compiler temps
and arguments retain the full word where the C source does so. -/
theorem call {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (i : Fin 31) (bits imm : BitVec 64) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock i) 0 =
        some (.Vlong (Arm64RegisterWrite.written narrow (mergeWord bits imm column))) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock i) 0 = some (.Vint 0) ∧
      InternalRun world 203
        (.Callstate (.Internal Arm64Nop.handler)
          (Arm64MovImmediate.Dispatch.Keep.arguments (operandsWord unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow)
          k before) (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate s i (mergeWord bits imm column) narrow) ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after i ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
        CC.PMap.get block after.access = CC.PMap.get block before.access) := by
  obtain ⟨written, after, result, run, freed, freeFrame, contents, next, released⟩ :=
    call_scalar_word_returns_bound world Linked.bindings storage unused addresses i bits imm column narrow word tag
  obtain ⟨comparison, comparisonResult⟩ := Arm64RegisterWrite.write storage i (mergeWord bits imm column) narrow
  obtain ⟨_, comparisonWord, comparisonTag⟩ := comparisonResult.stores
  obtain ⟨_, actualWord, actualTag⟩ := result.stores
  have wordFrame := Arm64MovImmediate.stores_frame (Arm64Nop.entry_frame world before) comparisonWord actualWord
  have tagFrame := Arm64MovImmediate.stores_frame wordFrame comparisonTag actualTag
  have finalRegisters := (Arm64Registers.frame (tagFrame.trans freeFrame) (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s i (mergeWord bits imm column) narrow)).mpr
      (comparisonResult.represents addresses origins s represented)
  let finalStorage := storage_frame result.storage before.nextblock bound freeFrame
  have finalWord : CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock i) 0 =
      some (.Vlong (Arm64RegisterWrite.written narrow (mergeWord bits imm column))) := by
    change CC.Mem.load .Mint64 after ((storage.tables false).cellBlock i) 0 = _
    exact (freeFrame.load .Mint64 ((storage.tables false).cellBlock i) 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables false).cellBinding i)) bound)).trans result.word
  have finalTag : CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock i) 0 = some (.Vint 0) := by
    change CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock i) 0 = _
    exact (freeFrame.load .Mint8unsigned ((storage.tables true).cellBlock i) 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables true).cellBinding i)) bound)).trans result.tag
  have initialBound := Nat.le_trans ((FrameBelow.allocVariables
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm)
    initial.nextblock (Nat.le_refl _)).1) bound
  have allocationCaller : FrameBelow initial.nextblock before (Arm64Nop.allocation world before).2 :=
    fun block owned => (Arm64Nop.entry_frame world before) block (Nat.lt_of_lt_of_le owned initialBound)
  have freeCaller : FrameBelow initial.nextblock written after :=
    fun block owned => freeFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have allocationKept := Arm64CacheLocalFrame.of_frame before.nextblock i bound (Arm64Nop.entry_frame world before)
  have writerKept : Arm64CacheLocalFrame.Kept initial (Arm64Nop.allocation world before).2 written i := result.local_load
  have freeKept := Arm64CacheLocalFrame.of_frame before.nextblock i bound freeFrame
  have kept := (allocationKept.trans writerKept).trans freeKept
  have finalNext : after.nextblock = (Arm64Nop.allocation world before).2.nextblock := next.trans result.nextblock
  have finalBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat :=
    Eq.mpr (congrArg (fun frontier : CC.Block => (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
      finalNext) (Nat.le_trans bound (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound world before)
        before.nextblock (Nat.le_refl _)).1)
  have permissionFrame : ∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
      CC.PMap.get block after.access = CC.PMap.get block before.access := by
    intro block owned
    have oldBlock := Nat.lt_of_lt_of_le owned bound
    exact (freeFrame block oldBlock).2.trans
      ((congrArg (CC.PMap.get block) result.access).trans ((Arm64Nop.entry_frame world before) block oldBlock).2)
  refine ⟨written, after, finalStorage, finalWord, finalTag, ?_, finalRegisters,
    (allocationCaller.trans result.caller).trans freeCaller, freed, freeFrame, contents, next, released, kept, finalBound,permissionFrame⟩
  simpa only [Continuation.state, Continuation.extend] using Continuation.run_extend k valid run

end KProgFormal.ClightRefinement.Arm64MovKeep.LinkedWordRights
