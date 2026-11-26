import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnTag

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryReturnTarget
open Arm64Producer (HeaderSourceLocal)
open Arm64ProgramEntryAllocation (world allocation)

private structure Parts where
  matched : CC.Stmt
  readLR : CC.Stmt
  dispatch : CC.Stmt
  continuationBody : CC.Stmt
  afterContinuation : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original RET_TO target changed"
      pure actual.getAppArgs
    let choice ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryReturnTag.choice)) none) ``CC.Stmt.Sifthenelse 3
    let matched ← peel choice[2]! ``CC.Stmt.Ssequence 2
    let suffix ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCmpLabels.takenAfter)) none) ``CC.Stmt.Ssequence 2
    let label ← peel suffix[0]! ``CC.Stmt.Slabel 2
    unless ← Lean.Meta.isDefEq label[0]! (Lean.mkConst ``Arm64ProgramFixture._continuation) do
      throwError "original continuation label changed"
    Lean.Elab.Tactic.closeMainGoal `actual_return_target_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[choice[2]!,matched[0]!,matched[1]!,label[1]!,suffix[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_return_target_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def matched : CC.Stmt := by run_tac cachePart (← `(parts.matched))
def readLR : CC.Stmt := by run_tac cachePart (← `(parts.readLR))
def dispatch : CC.Stmt := by run_tac cachePart (← `(parts.dispatch))
def continuationBody : CC.Stmt := by run_tac cachePart (← `(parts.continuationBody))
def afterContinuation : CC.Stmt := by run_tac cachePart (← `(parts.afterContinuation))
theorem matched_source : matched = .Ssequence readLR dispatch := rfl
theorem read_source : readLR = .Sset Arm64ProgramFixture._t'155 (.Evar Arm64ProgramFixture.___a64_lr CC.tulong) := rfl
theorem suffix_source : Arm64ProgramEntryCmpLabels.takenAfter =
    .Ssequence (.Slabel Arm64ProgramFixture._continuation continuationBody) afterContinuation := rfl

def temps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64ProgramFixture._t'155 (.Vlong 64)
def targetCont (k : CC.Cont) : CC.Cont := .Kseq afterContinuation (CC.callCont k)

theorem continuation_source (k : CC.Cont) : CC.findLabel Arm64ProgramFixture._continuation
    Arm64ProgramFixture.f_arm64_execute_compile.fn_body (CC.callCont k) = some (continuationBody,targetCont k) := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

theorem jump_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile (.Sgoto Arm64ProgramFixture._continuation) k
      (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile continuationBody (targetCont k) (allocation initial).1 le m) :=
  CC.Step.goto _ _ _ _ _ _ _ _ (continuation_source k)

private theorem read_step {initial : CC.Mem} (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (read : CC.Mem.load .Mint64 m lr.block 0 = some (.Vlong 64)) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile readLR k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le) m) := by
  have evaluated : CC.doEvalExpr world (allocation initial).1 le m
      (.Evar Arm64ProgramFixture.___a64_lr CC.tulong) = some (.Vlong 64) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,Arm64ProgramEntryLinkCall.local_binding lr]
    change CC.Mem.load .Mint64 m lr.block 0 = some (.Vlong 64)
    exact read
  rw [read_source]
  exact CC.Step.set _ _ _ _ _ _ _ _ (CC.doEvalExpr_sound _ _ _ _ _ _ evaluated)

set_option hygiene false in
/-- Actual tag9 comparison, real LR read, original switch64 and complete
original label search reach continuation with the same heap and saved caller. -/
theorem execute {initial : CC.Mem} (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (read : CC.Mem.load .Mint64 m lr.block 0 = some (.Vlong 64))
    (tag : le.get Arm64ProgramFixture._t'150 = some (.Vint (9#32))) :
    InternalRun world 7
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTag.choice k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile continuationBody (targetCont k) (allocation initial).1 (temps le) m) := by
  run_tac do
    for i in [:7] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 2 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact read_step lr le m _ read))
      else if i == 6 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact jump_step (temps le) m _))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,Arm64ProgramEntryReturnTag.choice,matched_source,dispatch,
          CC.doEvalExpr,tag,temps,CC.PTree.gss] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [targetCont,CC.callCont,temps]; exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64ProgramEntryReturnTarget
