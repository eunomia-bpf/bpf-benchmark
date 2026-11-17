import KProgFormal.ClightRefinement.Arm64NumericProgram
import KProgFormal.ClightRefinement.Arm64MovPath

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate

open Arm64NumericProgram

private def sourceEquality : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
  unless target.isAppOfArity ``Eq 3 do throwError "expected actual source lookup"
  goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal []

/-- Actual source symbols and bodies, at Clight blocks rather than native addresses. -/
theorem width_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._arm64_width_effective = some (CC.Positive.ofNat 66) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 66) =
      some (.Internal Arm64Program.f_arm64_width_effective) := by
  constructor <;> run_tac sourceEquality

theorem selector_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_mov_path = some (CC.Positive.ofNat 67) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 67) =
      some (.Internal Arm64Numeric.f_kprog_arm64_mov_path) := by
  constructor <;> run_tac sourceEquality

theorem reader_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_read = some (CC.Positive.ofNat 76) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 76) =
      some (.Internal Arm64Program.f_kprog_arm64_program_read) := by
  constructor <;> run_tac sourceEquality

theorem writer_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_write = some (CC.Positive.ofNat 79) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 79) =
      some (.Internal Arm64Program.f_kprog_arm64_program_write) := by
  constructor <;> run_tac sourceEquality

theorem handler_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_program_execute = some (CC.Positive.ofNat 85) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 85) =
      some (.Internal Arm64Nop.handler) := by
  constructor <;> run_tac sourceEquality

end KProgFormal.ClightRefinement.Arm64MovImmediate
