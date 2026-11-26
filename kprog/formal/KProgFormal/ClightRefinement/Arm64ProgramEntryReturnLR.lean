import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnRaw

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryReturnLR
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- This source assignment uses the actual t149 raw-call result, rather than
the earlier CALL's literal assignment; the actual store event remains. -/
theorem store_step {initial before after : CC.Mem} (lr : HeaderSourceLocal initial 4)
    (le : CC.TempEnv) (k : CC.Cont) (read : le.get Arm64ProgramFixture._t'149 = some (.Vlong 64))
    (effect : Arm64ProgramEntryLinkCall.Effect lr before after) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnRaw.storeLR k
      (allocation initial).1 le before) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) := by
  have target : CC.doEvalLvalue world (allocation initial).1 le before
      (.Evar Arm64ProgramFixture.___a64_lr CC.tulong) = some (lr.block,0,.Full) := by
    simp only [CC.doEvalLvalue,CC.lvalOfVar,Arm64ProgramEntryLinkCall.local_binding lr]
    rfl
  have value : CC.doEvalExpr world (allocation initial).1 le before
      (.Etempvar Arm64ProgramFixture._t'149 CC.tulong) = some (.Vlong 64) := by
    simp only [CC.doEvalExpr,read]
  have cast : CC.Cop.semCast (.Vlong 64) CC.tulong CC.tulong before = some (.Vlong 64) := rfl
  have assigned : CC.doAssignLoc world.genv_cenv CC.tulong before lr.block 0 .Full (.Vlong 64) = some after := effect.stored
  apply CC.doStep_sound
  rw [Arm64ProgramEntryReturnRaw.store_source,CC.doStep,target,value]
  simp only [CC.typeof,cast,assigned]

section Effect
variable {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before}
    {lr : HeaderSourceLocal initial 4}

/-- Same typed LR effect supplies the complete original packet after the
actual repeated store, including flags and copied bytes. -/
def packet (effect : Arm64ProgramEntryLinkCall.Effect lr before after) :
    Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue after :=
  Arm64ProgramEntryLinkFrame.packet effect prior

include prior in
theorem link (effect : Arm64ProgramEntryLinkCall.Effect lr before after)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32)) :=
  (Arm64ProgramEntryLinkFrame.gpr effect prior.memory.storage (30 : Fin 31)).trans observed

theorem lr_readback (effect : Arm64ProgramEntryLinkCall.Effect lr before after) :
    CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong 64) := CC.Mem.load_store_same effect.stored

/-- Original raw-call setup and full helper/caller, real LR store and sequence
resume reach the original RET_TO guard with their same memory effect. -/
theorem execute (current : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    ∃ after, Arm64ProgramEntryLinkCall.Effect lr before after ∧ InternalRun world 36
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnRaw.tail
        (Arm64ProgramEntryReturnRaw.outerCont k) (allocation initial).1 (Arm64ProgramEntryReturnRaw.temps le) after) := by
  obtain ⟨after,effect⟩ := Arm64ProgramEntryLinkCall.write current.memory.resources lr
  have read := Arm64ProgramEntryReturnRaw.execute entry le before k observed
  have stored : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnRaw.storeLR
        (Arm64ProgramEntryReturnRaw.storeCont k) (allocation initial).1 (Arm64ProgramEntryReturnRaw.temps le) before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip
        (Arm64ProgramEntryReturnRaw.storeCont k) (allocation initial).1 (Arm64ProgramEntryReturnRaw.temps le) after) :=
    .step (by rw [Arm64ProgramEntryReturnRaw.store_source]; trivial)
      (store_step lr (Arm64ProgramEntryReturnRaw.temps le) _ (by exact CC.PTree.gss _ _ _) effect) (.refl _)
  have resume : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip
        (Arm64ProgramEntryReturnRaw.storeCont k) (allocation initial).1 (Arm64ProgramEntryReturnRaw.temps le) after)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnRaw.tail
        (Arm64ProgramEntryReturnRaw.outerCont k) (allocation initial).1 (Arm64ProgramEntryReturnRaw.temps le) after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨after,effect,(read.trans stored).trans resume⟩

end Effect
end KProgFormal.ClightRefinement.Arm64ProgramEntryReturnLR
