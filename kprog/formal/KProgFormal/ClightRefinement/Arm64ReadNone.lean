import Lean
import KProgFormal.Clight.Arm64Program
import KProgFormal.ClightRefinement.InternalExecution

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate

/-- The actual eager read of NONE (255) returns zero without loading the entry
or changing memory. All 55 transitions use the imported internal semantics. -/
theorem read_none (world : CC.CGenv) (entry : CC.Val) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 55 (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
      [entry, .Vlong 255] k m) (.Returnstate (.Vlong 0) (CC.callCont k) m) := by
  run_tac do
    for _ in [:55] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64MovImmediate
