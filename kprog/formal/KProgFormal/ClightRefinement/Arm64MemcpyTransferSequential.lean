import KProgFormal.ClightRefinement.Arm64MemcpyTransferIteration

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferSequential

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

section Current
variable {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}

/-- Induction follows the actual reached heaps and temporaries. Both
active source/destination tag effects and all fourteen inactive iterations
remain in the original loop, with its real unsigned counter backedges. -/
theorem iterations (n : Nat) (limit : n ≤ 16) (le : CC.TempEnv) (k : CC.Cont)
    (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyTransferIteration.Invariant base abi byte gprs flags values calleeBefore 0 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyTransferIteration.Invariant base abi byte gprs flags values calleeBefore n after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyTransferSetup.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyTransferSetup.loop k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      FrameBelow before.nextblock before after ∧ Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      after.nextblock = before.nextblock := by
  induction n with
  | zero => exact ⟨before,le,prior,.refl _,FrameBelow.refl _ _,flag,rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,middleCurrent,prefixRun,prefixFrame,middleFlag,middleNext⟩ := ih (by omega)
    have pbound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ middle.nextblock.toNat := by
      rw [middleNext]
      exact producerBound
    have cbound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ middle.nextblock.toNat := by
      rw [middleNext]
      exact callerBound
    let i : Fin 16 := ⟨n,by omega⟩
    obtain ⟨after,nextLe,next,stepRun,stepFrame,flagAfter,nextBlock⟩ :=
      Arm64MemcpyTransferIteration.execute middleLe k i addresses middleCurrent pbound cbound cell flagValue middleFlag
    rw [middleNext] at stepFrame
    refine ⟨after,nextLe,next,?_,prefixFrame.trans stepFrame,flagAfter,nextBlock.trans middleNext⟩
    simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans prefixRun stepRun

/-- The original afterCopy setup, all sixteen actual tag-transfer
iterations, and the real final false guard/outer exits reach the genuine
shared clobber call with the same complete memcpy packet and typed flag. -/
theorem execute (le : CC.TempEnv) (k : CC.Cont) (addresses : Arm64Registers.PointerOrigins)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyCopyEntry.afterCopy k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyTransferSource.clobbers k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        (80+(j.val : Int)) = some (.Vint (byte.setWidth 32))) ∧
      FrameBelow before.nextblock before after ∧ Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      after.nextblock = before.nextblock := by
  obtain ⟨setupCurrent,setupRun⟩ := Arm64MemcpyTransferSetup.current le k addresses prior
  have outputs := Arm64MemcpyTransferSetup.outputs le
  let current : Arm64MemcpyTransferIteration.Invariant base abi byte gprs flags values calleeBefore 0 before
      (Arm64MemcpyTransferSetup.temps le) := ⟨setupCurrent,outputs.2.2,outputs.1,outputs.2.1⟩
  obtain ⟨after,nextLe,next,loopRun,frame,flagAfter,frontier⟩ := iterations 16 (by omega)
    (Arm64MemcpyTransferSetup.temps le) (Arm64MemcpyTransferSetup.continuation k) addresses current
    producerBound callerBound cell flagValue flag
  have finishRun := Arm64MemcpyTransferLoop.finish (Arm64MemcpySource.allocation calleeBefore).1 nextLe after k
    next.counter next.length
  refine ⟨after,nextLe,next.ready,?_,fun j => next.ready.copied j j.isLt,frame,flagAfter,frontier⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans setupRun.sound loopRun) finishRun.sound

end Current
end KProgFormal.ClightRefinement.Arm64MemcpyTransferSequential
