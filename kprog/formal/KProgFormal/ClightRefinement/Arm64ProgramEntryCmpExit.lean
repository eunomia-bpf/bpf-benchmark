import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpWritten
import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpGt
import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpLabels

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpExit
open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryCmpLabels (xorResult takenBody takenAfter)

private theorem xor_source : xorResult = .Sset Arm64ProgramFixture._result
    (.Ebinop .Oxor (.Etempvar Arm64ProgramFixture._result CC.tulong) (.Econst_int (8#32) CC.tint) CC.tulong) := rfl

def result (before : BitVec 64) (s : Reference.AArch64.State) (lhs rhs : BitVec 64) : BitVec 64 :=
  if Arm64ProgramEntryCmpGt.taken s lhs rhs then before else before ^^^ (8#64)
def temps (le : CC.TempEnv) (before : BitVec 64) (s : Reference.AArch64.State) (lhs rhs : BitVec 64) : CC.TempEnv :=
  if Arm64ProgramEntryCmpGt.taken s lhs rhs then le
  else le.set Arm64ProgramFixture._result (.Vlong (before ^^^ (8#64)))

theorem xor_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (before : BitVec 64) (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile xorResult k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._result (.Vlong (before ^^^ (8#64)))) m) := by
  rw [xor_source]
  apply CC.doStep_sound
  simp only [CC.doStep,CC.doEvalExpr,prior]
  rfl

set_option hygiene false in
private theorem fallthrough {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (before : BitVec 64) (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    InternalRun world 8
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (Arm64ProgramEntryCmpBranch.loopCont k)
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile takenBody (.Kseq takenAfter k)
        (allocation initial).1 (le.set Arm64ProgramFixture._result (.Vlong (before ^^^ (8#64)))) m) := by
  run_tac do
    for i in [:8] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 4 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact xor_step _ m _ before prior))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,Arm64ProgramEntryCmpBranch.loopCont,
          Arm64ProgramEntryCmpLabels.after_source] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Both original source exits use the imported GT condition. The taken goto
and true XOR8 fallthrough reach the original CALL body on the same heap. -/
theorem execute {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hk : CC.isCallCont k = true) (before : BitVec 64)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before))
    (s : Reference.AArch64.State) (lhs rhs : BitVec 64)
    (hw : le.get Arm64ProgramFixture.___a64_cmp_width = some (.Vint 8))
    (hl : le.get Arm64ProgramFixture.___a64_cmp_lhs = some (.Vlong lhs))
    (hr : le.get Arm64ProgramFixture.___a64_cmp_rhs = some (.Vlong rhs)) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpBranch.choice
        (Arm64ProgramEntryCmpBranch.loopCont k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile takenBody (.Kseq takenAfter k)
        (allocation initial).1 (temps le before s lhs rhs) m) := by
  have call : CC.callCont k = k := by cases k <;> simp_all [CC.isCallCont,CC.callCont]
  have selected := Arm64ProgramEntryCmpGt.execute world (allocation initial).1 le m
    (Arm64ProgramEntryCmpBranch.loopCont k) s lhs rhs hw hl hr
  cases chosen : Arm64ProgramEntryCmpGt.taken s lhs rhs with
  | true =>
    simp only [chosen,ite_true,temps] at selected ⊢
    have step := Arm64ProgramEntryCmpLabels.taken_step (initial := initial) le m (Arm64ProgramEntryCmpBranch.loopCont k)
    have jumped : InternalRun world 1
        (.State Arm64ProgramFixture.f_arm64_execute_compile (.Sgoto Arm64ProgramFixture._cmp_taken)
          (Arm64ProgramEntryCmpBranch.loopCont k) (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile takenBody (.Kseq takenAfter k) (allocation initial).1 le m) := by
      apply InternalRun.step
      · trivial
      · simpa only [Arm64ProgramEntryCmpLabels.taken_cont,Prod.fst,Prod.snd,
          Arm64ProgramEntryCmpBranch.loopCont,CC.callCont,call] using step
      · exact .refl _
    exact ⟨4,selected.trans jumped⟩
  | false =>
    simp only [chosen,ite_false,temps] at selected ⊢
    exact ⟨11,selected.trans (fallthrough le m k before prior)⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpExit
