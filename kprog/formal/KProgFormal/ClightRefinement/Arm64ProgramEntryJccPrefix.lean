import KProgFormal.ClightRefinement.Arm64ProgramEntryJcc

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryJccPrefix

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryJcc

def outerCont (k : CC.Cont) : CC.Cont := .Kloop1 outer .Sbreak (.Kseq after k)
def innerCont (k : CC.Cont) : CC.Cont := .Kloop1 inner .Sbreak (outerCont k)
def conditionCont (k : CC.Cont) : CC.Cont := .Kseq decision (.Kseq finish (innerCont k))
def selectorTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64ProgramFixture._t'136 (.Vint 1)

set_option hygiene false in
/-- The constant width comparison enters the original true loop and reads
ctx.mark on the reached heap before the actual condition call. -/
theorem execute {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (block : CC.Block) (ofs : CC.Integers.Ptrofs) (value : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr block ofs))
    (read : CC.Mem.loadv .Mint32 m
      (.Vptr block (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr 8))) = some (.Vint value)) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAfterMemcpy.branches k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile conditionCall (conditionCont k)
        (allocation initial).1 (markTemps (selectorTemps le) value) m) := by
  have selectedCtx : (selectorTemps le).get Arm64ProgramFixture._ctx = some (.Vptr block ofs) := by
    simpa +decide [selectorTemps,CC.PTree.gso] using ctx
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:32] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt := state.getAppArgs[1]!
        if ← Lean.Meta.isDefEq stmt (Lean.mkConst ``conditionCall) then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual JCC prefix transitions: {i}"
          finished := true
          break
        if ← Lean.Meta.isDefEq stmt (Lean.mkConst ``mark) then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact mark_step (selectorTemps le) m _ block ofs value selectedCtx read))
          continue
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,CC.doEvalExpr,CC.PTree.gss]))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    unless finished do throwError "original JCC prefix did not reach its condition call"

end KProgFormal.ClightRefinement.Arm64ProgramEntryJccPrefix
