import KProgFormal.ClightRefinement.Arm64ProgramEntryJccLabels

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryJccExit

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryJcc Arm64ProgramEntryJccPrefix Arm64ProgramEntryJccLabels

private theorem decision_source : decision = .Sifthenelse
    (.Eunop .Onotbool (.Etempvar Arm64ProgramFixture._t'134 CC.tint) CC.tint)
    (.Sgoto Arm64ProgramFixture.___a64_sim_jcc_fallthrough_34) .Sskip := rfl
private theorem finish_source : finish = .Ssequence (.Sgoto Arm64ProgramFixture._jcc_taken)
    (.Slabel Arm64ProgramFixture.___a64_sim_jcc_fallthrough_34 .Sskip) := rfl
private theorem xor_source : xorResult = .Sset Arm64ProgramFixture._result
    (.Ebinop .Oxor (.Etempvar Arm64ProgramFixture._result CC.tulong)
      (.Econst_int (1#32) CC.tint) CC.tulong) := rfl

def result (before : BitVec 64) (value : BitVec 32) (s : Reference.AArch64.State) : BitVec 64 :=
  if ConditionHolds (BitVec.ofNat 4 (code value).val) s.machine then before else before ^^^ (1#64)
def temps (le : CC.TempEnv) (before : BitVec 64) (value : BitVec 32)
    (s : Reference.AArch64.State) : CC.TempEnv :=
  if ConditionHolds (BitVec.ofNat 4 (code value).val) s.machine then conditionTemps le value s
  else (conditionTemps le value s).set Arm64ProgramFixture._result (.Vlong (before ^^^ (1#64)))

/-- The actual source XOR runs only on the fallthrough route. -/
theorem xor_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (before : BitVec 64) (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile xorResult k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._result (.Vlong (before ^^^ (1#64)))) m) := by
  rw [xor_source]
  apply CC.doStep_sound
  simp only [CC.doStep,CC.doEvalExpr,prior]
  rfl

set_option hygiene false in
private def runExit : Lean.Elab.Tactic.TacticM Unit := Lean.Meta.withAssignableSyntheticOpaque do
  let mut finished := false
  for i in [:48] do
    let goal ← Lean.Elab.Tactic.getMainTarget
    let state ← Lean.instantiateMVars goal.getAppArgs[2]!
    if state.isAppOfArity ``CC.State.State 6 then
      let stmt := state.getAppArgs[1]!
      if ← Lean.Meta.isDefEq stmt (Lean.mkConst ``takenBody) then
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [taken_cont,Prod.fst,Prod.snd,CC.callCont,call,temps,conditionTemps,markTemps,truth,chosen,ite_true,ite_false]; exact InternalRun.refl _))
        Lean.logInfo m!"actual JCC exit transitions: {i}"
        finished := true
        break
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt)
      if actual.isAppOfArity ``CC.Stmt.Sgoto 1 then
        let target := actual.getAppArgs[0]!
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        if ← Lean.Meta.isDefEq target (Lean.mkConst ``Arm64ProgramFixture._jcc_taken) then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact taken_step _ m _))
        else
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact fallthrough_step _ m _))
        continue
      if ← Lean.Meta.isDefEq stmt (Lean.mkConst ``xorResult) then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply xor_step _ m _ before; simpa +decide [CC.PTree.gso] using prior))
        continue
    Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
    Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
    Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
    Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,CC.doEvalExpr,CC.PTree.gss,
      conditionCont,innerCont,outerCont,decision_source,finish_source,after_source,
      conditionTemps,markTemps,truth,chosen,ite_true,ite_false,
      CC.Cop.semUnaryOperation,CC.Cop.semNotbool,CC.Cop.boolVal,CC.Cop.classifyBool,
      CC.typeof,CC.tint,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Val.ofBool,
      CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero,
      CC.callCont,call,fallthrough_source,taken_source,fallthrough_cont,taken_cont]))
    Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
  unless finished do throwError "original JCC exit did not reach the next labelled body"

set_option hygiene false in
/-- Both original goto paths converge at the true next labelled body. The
imported condition decides whether the actual source result XOR executes. -/
theorem execute {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hk : CC.isCallCont k = true) (before : BitVec 64) (value : BitVec 32)
    (s : Reference.AArch64.State)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (conditionCont k)
        (allocation initial).1 (conditionTemps le value s) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile takenBody (.Kseq takenAfter k)
        (allocation initial).1 (temps le before value s) m) := by
  have current : (conditionTemps le value s).get Arm64ProgramFixture._result = some (.Vlong before) := by
    simpa +decide [conditionTemps,markTemps,CC.PTree.gso] using prior
  have call : CC.callCont k = k := by cases k <;> simp_all [CC.isCallCont,CC.callCont]
  by_cases chosen : ConditionHolds (BitVec.ofNat 4 (code value).val) s.machine
  · refine ⟨?countTaken,?executionTaken⟩
    case executionTaken => run_tac runExit
  · refine ⟨?countFallthrough,?executionFallthrough⟩
    case executionFallthrough => run_tac runExit


end KProgFormal.ClightRefinement.Arm64ProgramEntryJccExit
