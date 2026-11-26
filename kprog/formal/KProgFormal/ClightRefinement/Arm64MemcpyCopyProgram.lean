import KProgFormal.ClightRefinement.Arm64MemcpyFlagMemory
import KProgFormal.ClightRefinement.Arm64MemcpySequential

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyCopyProgram

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)

/-- Start at the genuine program memcpy statement. Its real linked call,
eight-local frame and input reads precede all sixteen actual reader/store
iterations and their final exit to the original tag-transfer statement. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after copyLe, ∃ _current : Arm64MemcpyLoopState.Invariant base abi byte
        (Arm64MemcpyLengthState.words gprs) flags values before 16 after copyLe,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) CC.E0
        (.State Arm64MemcpySource.handler Arm64MemcpyCopyEntry.afterCopy
          (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k))
          (Arm64MemcpySource.allocation before).1 copyLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        (80+(j.val : Int)) = some (.Vint (byte.setWidth 32))) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨startLe,start,entryRun,startFlag,producerBound⟩ :=
    Arm64MemcpyFlagMemory.entry prior bound le k cell flagValue flag
  let cont := Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k)
  obtain ⟨after,copyLe,current,copies,written,flagAfter,copyFrame,pbound,cbound⟩ :=
    Arm64MemcpySequential.execute startLe cont start producerBound (Nat.le_refl _) cell flagValue startFlag
  have initialBound : initial.nextblock.toNat ≤ before.nextblock.toNat := by
    have allocated := (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (Arm64Producer.allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
    exact Nat.le_trans allocated bound
  have entryFrame : FrameBelow initial.nextblock before (Arm64MemcpySource.allocation before).2 :=
    fun block below => (Arm64MemcpySource.entry_frame before) block (Nat.lt_of_lt_of_le below initialBound)
  refine ⟨after,copyLe,current,?_,written,flagAfter,entryFrame.trans copyFrame,pbound,cbound⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans entryRun.sound copies

end KProgFormal.ClightRefinement.Arm64MemcpyCopyProgram
