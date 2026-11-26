import KProgFormal.ClightRefinement.Arm64ProgramEntryTbnz

set_option Elab.async false
set_option hygiene false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzLabels

open Arm64ProgramEntryAllocation (world allocation)

/-- Cache source nodes by the imported label-search traversal. Each node is
unfolded separately; the source equations below are checked against findLabel. -/
private def cacheLabel (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let label ← Lean.Elab.Term.elabTerm source none
  let root ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramFixture.f_arm64_execute_compile.fn_body)) none
  let cont ← Lean.Elab.Term.elabTerm (← `(CC.callCont k)) none
  let mut pending := #[(root,cont)]
  let mut result : Option (Lean.Expr × Lean.Expr) := none
  while !pending.isEmpty do
    let (term,k) := pending.back!
    pending := pending.pop
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    let args := stmt.getAppArgs
    if stmt.isAppOfArity ``CC.Stmt.Ssequence 2 then
      pending := pending.push (args[1]!,k)
      pending := pending.push (args[0]!,← Lean.Meta.mkAppM ``CC.Cont.Kseq #[args[1]!,k])
    else if stmt.isAppOfArity ``CC.Stmt.Sifthenelse 3 then
      pending := pending.push (args[2]!,k) |>.push (args[1]!,k)
    else if stmt.isAppOfArity ``CC.Stmt.Sloop 2 then
      pending := pending.push (args[1]!,← Lean.Meta.mkAppM ``CC.Cont.Kloop2 #[args[0]!,args[1]!,k])
      pending := pending.push (args[0]!,← Lean.Meta.mkAppM ``CC.Cont.Kloop1 #[args[0]!,args[1]!,k])
    else if stmt.isAppOfArity ``CC.Stmt.Slabel 2 then
      if ← Lean.Meta.isDefEq label args[0]! then
        result := some (args[1]!,k)
        break
      else pending := pending.push (args[1]!,k)
    else if stmt.isAppOfArity ``CC.Stmt.Sswitch 2 then
      throwError "TBNZ target traversal reached an earlier source switch"
  let some (body,k) := result | throwError "original TBNZ source label missing"
  Lean.Elab.Tactic.closeMainGoal `original_tbnz_label (← Lean.Meta.mkAppM ``Prod.mk #[body,k])

/-- The full original Clight search binds the actual TBNZ taken target. -/
def taken (k : CC.Cont) : CC.Stmt × CC.Cont := by
  run_tac cacheLabel (← `(Arm64ProgramFixture._tbz_taken))
theorem taken_source (k : CC.Cont) : CC.findLabel Arm64ProgramFixture._tbz_taken
    Arm64ProgramFixture.f_arm64_execute_compile.fn_body (CC.callCont k) = some (taken k) := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

def fallthrough (k : CC.Cont) : CC.Stmt × CC.Cont :=
  (.Sskip,Arm64ProgramEntryTbnz.loopCont (CC.callCont k))
theorem fallthrough_source (k : CC.Cont) : CC.findLabel Arm64ProgramFixture.___a64_sim_tb_fallthrough_40
    Arm64ProgramFixture.f_arm64_execute_compile.fn_body (CC.callCont k) = some (fallthrough k) := by
  run_tac Arm64ProgramEntryLinked.sourceEquality
theorem fallthrough_cont (k : CC.Cont) : fallthrough k = (.Sskip,Arm64ProgramEntryTbnz.loopCont (CC.callCont k)) := rfl

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_tbnz_suffix (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def suffixParts : CC.Stmt × CC.Stmt × CC.Stmt := by
  run_tac do
    let source ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCbzLabels.takenAfter)) none
    let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source)
    unless pair.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original TBNZ after changed"
    let suffix ← Lean.Meta.withTransparency .all (Lean.Meta.whnf pair.getAppArgs[1]!)
    unless suffix.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original TBNZ suffix changed"
    let label ← Lean.Meta.withTransparency .all (Lean.Meta.whnf suffix.getAppArgs[0]!)
    unless label.isAppOfArity ``CC.Stmt.Slabel 2 do throwError "original TBNZ label changed"
    Lean.Elab.Tactic.closeMainGoal `original_tbnz_suffix
      (← Lean.Meta.mkAppM ``Prod.mk #[pair.getAppArgs[0]!,← Lean.Meta.mkAppM ``Prod.mk #[label.getAppArgs[1]!,suffix.getAppArgs[1]!]])
def xorResult : CC.Stmt := by run_tac cachePart (← `(suffixParts.1))
def takenBody : CC.Stmt := by run_tac cachePart (← `(suffixParts.2.1))
def takenAfter : CC.Stmt := by run_tac cachePart (← `(suffixParts.2.2))
theorem after_source : Arm64ProgramEntryCbzLabels.takenAfter = .Ssequence xorResult
    (.Ssequence (.Slabel Arm64ProgramFixture._tbz_taken takenBody) takenAfter) := rfl
theorem taken_cont (k : CC.Cont) : taken k = (takenBody,.Kseq takenAfter (CC.callCont k)) := rfl

theorem taken_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Sgoto Arm64ProgramFixture._tbz_taken) k
        (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile (taken k).1 (taken k).2
        (allocation initial).1 le m) := CC.Step.goto _ _ _ _ _ _ _ _ (taken_source k)

theorem fallthrough_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Sgoto Arm64ProgramFixture.___a64_sim_tb_fallthrough_40) k
        (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile (fallthrough k).1 (fallthrough k).2
        (allocation initial).1 le m) := CC.Step.goto _ _ _ _ _ _ _ _ (fallthrough_source k)

end KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzLabels
