import KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzCall
import KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzLabels

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzExit

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryTbnz Arm64ProgramEntryTbnzLabels

private theorem save_source : saveTaken = .Sset Arm64ProgramFixture.___a64_l_taken__1
    (.Etempvar Arm64ProgramFixture._t'141 CC.tint) := rfl
private theorem xor_source : xorResult = .Sset Arm64ProgramFixture._result
    (.Ebinop .Oxor (.Etempvar Arm64ProgramFixture._result CC.tulong) (.Econst_int (4#32) CC.tint) CC.tulong) := rfl

def choiceTemps (le : CC.TempEnv) (s : Reference.AArch64.State) : CC.TempEnv :=
  ((Arm64ProgramEntryTbnzCall.temps le s).set Arm64ProgramFixture.___a64_l_taken__1
    (.Vint (if Arm64BranchBit63.taken s then 1#32 else 0#32))).set Arm64ProgramFixture._t'142 (.Vint 1)
def result (before : BitVec 64) (s : Reference.AArch64.State) : BitVec 64 :=
  if Arm64BranchBit63.taken s then before else before ^^^ (4#64)
def temps (le : CC.TempEnv) (before : BitVec 64) (s : Reference.AArch64.State) : CC.TempEnv :=
  if Arm64BranchBit63.taken s then choiceTemps le s
  else (choiceTemps le s).set Arm64ProgramFixture._result (.Vlong (before ^^^ (4#64)))

theorem xor_step {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (before : BitVec 64) (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile xorResult k (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set Arm64ProgramFixture._result (.Vlong (before ^^^ (4#64)))) m) := by
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
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [taken_cont,Prod.fst,Prod.snd,CC.callCont,call,
          temps,choiceTemps,Arm64ProgramEntryTbnzCall.temps,chosen,ite_true,ite_false]; exact InternalRun.refl _))
        Lean.logInfo m!"actual TBNZ exit transitions: {i}"
        finished := true
        break
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt)
      if actual.isAppOfArity ``CC.Stmt.Sgoto 1 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        let target := actual.getAppArgs[0]!
        if ← Lean.Meta.isDefEq target (Lean.mkConst ``Arm64ProgramFixture._tbz_taken) then
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
    Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,
      branchCont,loopCont,save_source,choice,after_source,Arm64ProgramEntryTbnzCall.temps,chosen,
      CC.Cop.semUnaryOperation,CC.Cop.semNotbool,CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeof,
      CC.tint,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Val.ofBool,
      CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero,
      fallthrough_cont,CC.callCont,call,ite_true,ite_false]))
    Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
  unless finished do throwError "original TBNZ exit did not reach the next labelled body"

set_option hygiene false in
/-- The true Numeric caller result follows the original backward-TBNZ choice.
Both paths reach the original next label; only fallthrough executes XOR4. -/
theorem execute {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hk : CC.isCallCont k = true) (before : BitVec 64) (s : Reference.AArch64.State)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (branchCont k)
        (allocation initial).1 (Arm64ProgramEntryTbnzCall.temps le s) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile takenBody (.Kseq takenAfter k)
        (allocation initial).1 (temps le before s) m) := by
  have call : CC.callCont k = k := by cases k <;> simp_all [CC.isCallCont,CC.callCont]
  by_cases chosen : Arm64BranchBit63.taken s
  · refine ⟨?countTaken,?executionTaken⟩
    case executionTaken => run_tac runExit
  · refine ⟨?countFallthrough,?executionFallthrough⟩
    case executionFallthrough => run_tac runExit

end KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzExit
