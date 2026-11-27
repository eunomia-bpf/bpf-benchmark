import KProgFormal.ClightRefinement.Arm64MemcpyIteration

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpySequential

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

section Current
variable {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}

/-- Induct over actual reached heaps and temporary maps. Each induction
step executes the original reader, real stores and genuine increment; the
current allocation bounds advance with the real reader allocations/frees. -/
theorem iterations_framed (n : Nat) (limit : n ≤ 16) (le : CC.TempEnv) (k : CC.Cont)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 0 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ q : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) q.val =
        Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) q.val) := by
  induction n with
  | zero => exact ⟨before,le,prior,.refl _,flag,FrameBelow.refl _ _,producerBound,callerBound,fun _ => rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,middleCurrent,prefixRun,middleFlag,prefixFrame,pbound,cbound,prefixKept⟩ := ih (by omega)
    let i : Fin 16 := ⟨n,by omega⟩
    obtain ⟨after,nextLe,next,stepRun,flagAfter,stepFrame,nextP,nextC,stepKept⟩ :=
      Arm64MemcpyIteration.execute_framed middleLe k i middleCurrent pbound cbound cell flagValue middleFlag
    refine ⟨after,nextLe,next,?_,flagAfter,prefixFrame.trans stepFrame,nextP,nextC,fun j => (stepKept j).trans (prefixKept j)⟩
    simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans prefixRun stepRun
/-- The original complete interface uses the same actual execution. -/
theorem iterations (n : Nat) (limit : n ≤ 16) (le : CC.TempEnv) (k : CC.Cont)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 0 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyLoop.loop k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨after,nextLe,next,run,flagAfter,frame,pbound,cbound,_kept⟩ := iterations_framed n limit le k prior producerBound callerBound cell flagValue flag
  exact ⟨after,nextLe,next,run,flagAfter,frame,pbound,cbound⟩

/-- All sixteen original iterations and the real final false guard reach
the actual tag-transfer statement. Each destination observation comes from
its own real store; all source bytes and the complete current packet remain. -/
theorem execute_framed (le : CC.TempEnv) (k : CC.Cont)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 0 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop (Arm64MemcpyCopyEntry.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyCopyEntry.afterCopy k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        (80+(j.val : Int)) = some (.Vint (byte.setWidth 32))) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ q : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) q.val =
        Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) q.val) := by
  obtain ⟨after,nextLe,next,copies,flagAfter,frame,pbound,cbound,kept⟩ :=
    iterations_framed 16 (by omega) le (Arm64MemcpyCopyEntry.continuation k) prior producerBound callerBound cell flagValue flag
  have leave := Arm64MemcpyLoop.exit_current (Arm64MemcpySource.allocation calleeBefore).1 nextLe k next
  refine ⟨after,nextLe,next,?_,fun j => next.copied j j.isLt,flagAfter,frame,pbound,cbound,kept⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans copies leave.sound
/-- The original complete interface uses the same actual execution. -/
theorem execute (le : CC.TempEnv) (k : CC.Cont)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 0 before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyLoop.loop (Arm64MemcpyCopyEntry.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyCopyEntry.afterCopy k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        (80+(j.val : Int)) = some (.Vint (byte.setWidth 32))) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧ FrameBelow initial.nextblock before after ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨after,nextLe,next,run,copied,flagAfter,frame,pbound,cbound,_kept⟩ := execute_framed le k prior producerBound callerBound cell flagValue flag
  exact ⟨after,nextLe,next,run,copied,flagAfter,frame,pbound,cbound⟩

end Current
end KProgFormal.ClightRefinement.Arm64MemcpySequential
