import KProgFormal.ClightRefinement.Arm64ProgramEntryCbz

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCbzPrefix

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryCbz
open Arm64Producer (HeaderLocal TailLocal)

def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq Arm64ProgramEntryJccLabels.takenAfter k)
def readCont (k : CC.Cont) : CC.Cont := .Kseq castValue (.Kseq tail (loopCont k))
def branchCont (k : CC.Cont) : CC.Cont := .Kseq saveTaken (.Kseq choice (loopCont k))
def temps (le : CC.TempEnv) (raw : BitVec 64) : CC.TempEnv :=
  (le.set Arm64ProgramFixture._t'137 (.Vlong raw)).set Arm64ProgramFixture.___a64_l_value
    (.Vlong ((raw.setWidth 32).setWidth 64))

private theorem cast_source : castValue = .Sset Arm64ProgramFixture.___a64_l_value
    (.Ecast (.Ecast (.Etempvar Arm64ProgramFixture._t'137 CC.tulong) CC.tuint) CC.tulong) := rfl

/-- The original C casts truncate to uint32 and zero-extend the same returned word. -/
theorem cast_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (raw : BitVec 64) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile castValue k (allocation initial).1
        (le.set Arm64ProgramFixture._t'137 (.Vlong raw)) m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le raw) m) := by
  have widthEq : BitVec.ofNat 64 (BitVec.ofNat 32 raw.toNat).toNat = (raw.setWidth 32).setWidth 64 := by
    apply BitVec.eq_of_toNat_eq
    simp only [BitVec.toNat_ofNat,BitVec.toNat_setWidth]
  rw [cast_source]
  apply CC.doStep_sound
  simp +decide only [CC.doStep,CC.doEvalExpr,CC.PTree.gss,CC.typeof,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tulong,
    CC.Integers.Int.repr,CC.Integers.Int64.unsigned,CC.Integers.Int.unsigned,CC.Integers.Int64.repr,
    CC.Integers.MI.repr,CC.Integers.MI.unsigned,BitVec.ofInt_natCast,CC.Archi.ptr64,temps,ite_true,ite_false]
  rw [widthEq]

set_option hygiene false in
private theorem after_read {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (raw : BitVec 64) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (readCont k) (allocation initial).1
        (le.set Arm64ProgramFixture._t'137 (.Vlong raw)) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile branchCall (branchCont k) (allocation initial).1 (temps le raw) m) := by
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:16] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt := state.getAppArgs[1]!
        if ← Lean.Meta.isDefEq stmt (Lean.mkConst ``branchCall) then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual CBZ post-reader transitions: {i}"
          finished := true
          break
        if ← Lean.Meta.isDefEq stmt (Lean.mkConst ``castValue) then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact cast_step le m _ raw))
          continue
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact CC.doStep_sound _ _ _ _ rfl))
    unless finished do throwError "original CBZ prefix did not reach its Numeric call"

/-- The actual CBZ loop enters its original reader, executes the complete
same-packet X3 call/return and casts, then reaches its real Numeric call. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryJccLabels.takenBody
        (.Kseq Arm64ProgramEntryJccLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile branchCall (branchCont k)
        (allocation initial).1 (temps le (gprs 2)) m) := by
  have start : InternalRun world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryJccLabels.takenBody
        (.Kseq Arm64ProgramEntryJccLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile readCall (readCont k) (allocation initial).1 le m) := by
    rw [source,body_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
  obtain ⟨readCount,reads⟩ := current_read packet le (readCont k)
  obtain ⟨tailCount,rest⟩ := after_read le m k (gprs 2)
  exact ⟨_,(start.trans reads).trans rest⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCbzPrefix
