import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkLabels
open Arm64ProgramEntryAllocation (world allocation)

def callee : CC.Stmt := by
  run_tac do
    let mut term ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCmpLabels.takenAfter)) none
    let mut body : Option Lean.Expr := none
    for _ in [:64] do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      if actual.isAppOfArity ``CC.Stmt.Ssequence 2 then
        term := actual.getAppArgs[1]!
      else if actual.isAppOfArity ``CC.Stmt.Slabel 2 then
        unless ← Lean.Meta.isDefEq actual.getAppArgs[0]! (Lean.mkConst ``Arm64ProgramFixture._callee) do
          throwError "original final label changed"
        body := some actual.getAppArgs[1]!
        break
      else throwError "original callee suffix changed"
    let some chosenBody := body | throwError "original callee body missing"
    Lean.Elab.Tactic.closeMainGoal `original_link_callee chosenBody

theorem callee_source (k : CC.Cont) : CC.findLabel Arm64ProgramFixture._callee
    Arm64ProgramFixture.f_arm64_execute_compile.fn_body (CC.callCont k) = some (callee,CC.callCont k) := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

theorem jump_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkCall.jump k
      (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile callee (CC.callCont k) (allocation initial).1 le m) := by
  rw [Arm64ProgramEntryLinkCall.jump_source]
  exact CC.Step.goto _ _ _ _ _ _ _ _ (callee_source k)

set_option hygiene false in
/-- Complete the actual pointer-writer caller's inner loop and sequence exit,
then execute the genuine goto into the original callee/RET_TO body. -/
theorem execute {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hk : CC.isCallCont k = true) :
    InternalRun world 4
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (Arm64ProgramEntryLinkCall.innerCont k)
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile callee k (allocation initial).1 le m) := by
  have call : CC.callCont k = k := by cases k <;> simp_all [CC.isCallCont,CC.callCont]
  run_tac do
    for i in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 3 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| simpa only [Arm64ProgramEntryLinkCall.outerCont,CC.callCont,call] using jump_step le m _))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,Arm64ProgramEntryLinkCall.innerCont] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [Arm64ProgramEntryLinkCall.outerCont,CC.callCont,call]; exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkLabels
