import KProgFormal.ClightRefinement.Arm64MemcpyTransferActiveBody

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferIteration

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

/-- The actual transfer counter and controls accompany the same complete
sixteen-copy packet and live memcpy frame on the reached heap. -/
structure Invariant {initial seed : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : Arm64Producer.TailLocal initial 6) (byte : BitVec 8)
    (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) (values : Fin 64 → BitVec 64)
    (calleeBefore : CC.Mem) (n : Nat) (m : CC.Mem) (le : CC.TempEnv) where
  ready : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le
  counter : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 n))
  destination : le.get Arm64Program.___a64_mt_dst = some (.Vlong 80)
  length : le.get Arm64Program.___a64_mt_len = some (.Vlong 16)

section Current
variable {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}

private def prepared_current {le : CC.TempEnv} (i : Fin 16)
    (prior : Invariant base abi byte gprs flags values calleeBefore i.val before le) :
    Invariant base abi byte gprs flags values calleeBefore i.val before (Arm64MemcpyTransferLoop.temps le i) := by
  have obs := Arm64MemcpyTransferLoop.observations le i
  exact {
    ready := {prior.ready with
      entryRead := obs.2.2.2.1.trans prior.ready.entryRead
      counter := obs.2.2.2.2.1.trans prior.ready.counter
      length := obs.2.2.2.2.2.1.trans prior.ready.length
      sourceTag := obs.2.2.2.2.2.2.1.trans prior.ready.sourceTag}
    counter := obs.1.trans prior.counter
    destination := obs.2.1.trans prior.destination
    length := obs.2.2.1.trans prior.length }

private theorem successor : ∀ i : Fin 16,
    BitVec.ofNat 64 i.val+(1#64) = BitVec.ofNat 64 (i.val+1) := by decide +kernel

private def advanced {le : CC.TempEnv} (i : Fin 16)
    (prior : Invariant base abi byte gprs flags values calleeBefore i.val before le) :
    Invariant base abi byte gprs flags values calleeBefore (i.val+1) before
      (le.set Arm64Program.___a64_mt_i (.Vlong (BitVec.ofNat 64 i.val+(1#64)))) := by
  refine {
    ready := {prior.ready with entryRead := ?_,counter := ?_,length := ?_,sourceTag := ?_}
    counter := ?_
    destination := ?_
    length := ?_ }
  · simpa +decide only [CC.PTree.gso] using prior.ready.entryRead
  · simpa +decide only [CC.PTree.gso] using prior.ready.length
  · simpa +decide only [CC.PTree.gso] using prior.ready.counter
  · simpa +decide only [CC.PTree.gso] using prior.ready.sourceTag
  · simp only [CC.PTree.gss,successor]
  · simpa +decide only [CC.PTree.gso] using prior.destination
  · simpa +decide only [CC.PTree.gso] using prior.length

/-- Each original transfer iteration takes its real active or inactive
branch and actual unsigned backedge. Active positions retain both genuine
tag effects; all current observations and the same typed flag survive. -/
theorem execute (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (addresses : Arm64Registers.PointerOrigins)
    (prior : Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after nextLe, ∃ _next : Invariant base abi byte gprs flags values calleeBefore (i.val+1) after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyTransferSetup.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64MemcpyTransferSetup.loop k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      FrameBelow before.nextblock before after ∧ Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      after.nextblock = before.nextblock := by
  let prepared := prepared_current i prior
  by_cases chosen : Arm64MemcpyTransferLoop.active i = true
  · have setupRun := Arm64MemcpyTransferLoop.setup (Arm64MemcpySource.allocation calleeBefore).1 le before k i
      prior.counter prior.length prior.destination
    have first : CC.Star (CC.Step2 world)
        (.State handler Arm64MemcpyTransferSetup.loop k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_110 (Arm64MemcpyTransferLoop.continuation k)
          (Arm64MemcpySource.allocation calleeBefore).1 (Arm64MemcpyTransferLoop.temps le i) before) := by
      simpa only [chosen,ite_true] using setupRun.sound
    obtain ⟨after,bodyLe,bodyCurrent,bodyRun,_stored,frame,flagAfter,frontier,counter,dst,len,_atRead⟩ :=
      Arm64MemcpyTransferActiveBody.execute (Arm64MemcpyTransferLoop.temps le i) (Arm64MemcpyTransferLoop.continuation k)
        i addresses prepared.ready producerBound callerBound chosen prepared.counter prepared.length
        (Arm64MemcpyTransferLoop.observations le i).2.2.2.2.2.2.2 cell flagValue flag
    let current : Invariant base abi byte gprs flags values calleeBefore i.val after bodyLe :=
      ⟨bodyCurrent,counter.trans prepared.counter,dst.trans prepared.destination,len.trans prepared.length⟩
    have last := Arm64MemcpyTransferLoop.advance (Arm64MemcpySource.allocation calleeBefore).1 bodyLe after k
      (BitVec.ofNat 64 i.val) current.counter
    refine ⟨after,_,advanced i current,?_,frame,flagAfter,frontier⟩
    simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans first bodyRun) last.sound
  · have notActive : Arm64MemcpyTransferLoop.active i = false := Bool.eq_false_iff.mpr chosen
    have inactiveRun := Arm64MemcpyTransferLoop.inactive (Arm64MemcpySource.allocation calleeBefore).1 le before k i
      prior.counter prior.length prior.destination notActive
    exact ⟨before,_,advanced i prepared,inactiveRun.sound,FrameBelow.refl _ _,flag,rfl⟩

end Current
end KProgFormal.ClightRefinement.Arm64MemcpyTransferIteration
