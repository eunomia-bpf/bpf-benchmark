import Lean
import KProgFormal.Clight.Arm64Numeric
import KProgFormal.ClightRefinement.InternalExecution

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate

/-- MOV_IMM selects the scalar path for every width argument. Each of the
actual 23 internal transitions is checked by kernel reduction, without
simplifying the unvisited switch alternatives or supplying external effects. -/
theorem selector_internal (world : CC.CGenv) (width : BitVec 64) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 23 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_mov_path)
      [.Vlong 1, .Vlong width] k m) (.Returnstate (.Vlong 0) (CC.callCont k) m) := by
  run_tac do
    for _ in [:23] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64MovImmediate
