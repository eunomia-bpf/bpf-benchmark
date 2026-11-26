import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpBranch

set_option Elab.async false
set_option hygiene false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpLabels

open Arm64ProgramEntryAllocation (world allocation)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cmp_suffix (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def suffixParts : CC.Stmt × CC.Stmt × CC.Stmt := by
  run_tac do
    let source ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryTbnzLabels.takenAfter)) none
    let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source)
    unless pair.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original CMP after changed"
    let suffix ← Lean.Meta.withTransparency .all (Lean.Meta.whnf pair.getAppArgs[1]!)
    unless suffix.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original CMP suffix changed"
    let label ← Lean.Meta.withTransparency .all (Lean.Meta.whnf suffix.getAppArgs[0]!)
    unless label.isAppOfArity ``CC.Stmt.Slabel 2 do throwError "original CMP label changed"
    Lean.Elab.Tactic.closeMainGoal `original_cmp_suffix
      (← Lean.Meta.mkAppM ``Prod.mk #[pair.getAppArgs[0]!,← Lean.Meta.mkAppM ``Prod.mk #[label.getAppArgs[1]!,suffix.getAppArgs[1]!]])
def xorResult : CC.Stmt := by run_tac cachePart (← `(suffixParts.1))
def takenBody : CC.Stmt := by run_tac cachePart (← `(suffixParts.2.1))
def takenAfter : CC.Stmt := by run_tac cachePart (← `(suffixParts.2.2))
theorem after_source : Arm64ProgramEntryTbnzLabels.takenAfter = .Ssequence xorResult
    (.Ssequence (.Slabel Arm64ProgramFixture._cmp_taken takenBody) takenAfter) := rfl
/-- Bind the actual cached source node and original outer continuation. -/
def taken (k : CC.Cont) : CC.Stmt × CC.Cont := (takenBody,.Kseq takenAfter (CC.callCont k))
/-- Kernel-check the complete original label search against this source node. -/
theorem taken_source (k : CC.Cont) : CC.findLabel Arm64ProgramFixture._cmp_taken
    Arm64ProgramFixture.f_arm64_execute_compile.fn_body (CC.callCont k) = some (taken k) := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

theorem taken_cont (k : CC.Cont) : taken k = (takenBody,.Kseq takenAfter (CC.callCont k)) := rfl

theorem taken_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Sgoto Arm64ProgramFixture._cmp_taken) k
        (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile (taken k).1 (taken k).2
        (allocation initial).1 le m) := CC.Step.goto _ _ _ _ _ _ _ _ (taken_source k)

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpLabels
