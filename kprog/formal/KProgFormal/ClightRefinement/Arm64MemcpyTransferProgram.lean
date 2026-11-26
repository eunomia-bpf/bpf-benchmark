import KProgFormal.ClightRefinement.Arm64MemcpyTransferSequential

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferProgram

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)

/-- The genuine program memcpy call, its actual eight-local frame and
all sixteen reader/store copies precede the complete original copy=1
tag-transfer loop. The same packet and initialized flag reach the actual
shared clobber statement in memcpy's saved program-call continuation. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) (addresses : Arm64Registers.PointerOrigins)
    (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe, ∃ _current : Arm64MemcpyLoopState.Invariant base abi byte
        (Arm64MemcpyLengthState.words gprs) flags values before 16 after nextLe,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before) CC.E0
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers
          (Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k))
          (Arm64MemcpySource.allocation before).1 nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        (80+(j.val : Int)) = some (.Vint (byte.setWidth 32))) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation before).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨middle,copyLe,copyCurrent,copyRun,_copied,copyFlag,copyFrame,pbound,cbound⟩ :=
    Arm64MemcpyCopyProgram.execute prior bound le k cell flagValue flag
  let cont := Arm64MemcpySource.continuation (Arm64MemcpyProgramEntry.callCont initial le k)
  obtain ⟨after,nextLe,next,transferRun,written,transferFrame,flagAfter,frontier⟩ :=
    Arm64MemcpyTransferSequential.execute copyLe cont addresses copyCurrent pbound cbound cell flagValue copyFlag
  have initialBound : initial.nextblock.toNat ≤ middle.nextblock.toNat := by
    have allocated := (FrameBelow.allocVariables (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (Arm64Producer.allocation initial)).symm) initial.nextblock (Nat.le_refl _)).1
    exact Nat.le_trans allocated pbound
  have olderFrame : FrameBelow initial.nextblock middle after :=
    fun block below => transferFrame block (Nat.lt_of_lt_of_le below initialBound)
  refine ⟨after,nextLe,next,?_,written,flagAfter,copyFrame.trans olderFrame,?_,?_⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans copyRun transferRun
  · rw [frontier]
    exact pbound
  · rw [frontier]
    exact cbound

end KProgFormal.ClightRefinement.Arm64MemcpyTransferProgram
