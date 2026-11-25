import KProgFormal.ClightRefinement.X86ProducerLayout

namespace KProgFormal.ClightRefinement.X86ProducerWidthBindings
open X86ProducerLayout (ge)

private def globalIndex (name : Lean.Name) : Lean.Elab.Tactic.TacticM Unit := do
  let mut rows ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.global_definitions)) none
  let mut index := 0
  while true do
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
    unless node.isAppOfArity ``List.cons 3 do throwError "original producer width global missing"
    let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
    unless row.isAppOfArity ``Prod.mk 4 do throwError "original producer width global changed"
    if row.getAppArgs[2]!.isConstOf name then
      Lean.Elab.Tactic.closeMainGoal `actual_producer_width_index (Lean.mkNatLit index)
      return
    rows := node.getAppArgs[2]!
    index := index+1

private def maskIndex : Nat := by run_tac globalIndex ``X86_program_profile_bpf._x86_width_mask
private def signIndex : Nat := by run_tac globalIndex ``X86_program_profile_bpf._x86_width_sign_mask

def maskBlock : CC.Block := CC.Positive.ofNat (maskIndex+1)
def signBlock : CC.Block := CC.Positive.ofNat (signIndex+1)

private def binding : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
  unless target.isAppOfArity ``Eq 3 do throwError "original producer helper binding equality changed"
  goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal []

/-- Actual mask symbol and internal function in SAME complete producer world. -/
theorem mask_binding :
    CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_mask = some maskBlock ∧
    CC.Genv.findFunctPtr ge.genv_genv maskBlock = some (.Internal X86_program_profile_bpf.f_x86_width_mask) := by
  constructor <;> run_tac binding

/-- Actual sign-mask symbol and internal function, not a callee assumption. -/
theorem sign_binding :
    CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_sign_mask = some signBlock ∧
    CC.Genv.findFunctPtr ge.genv_genv signBlock = some (.Internal X86_program_profile_bpf.f_x86_width_sign_mask) := by
  constructor <;> run_tac binding

end KProgFormal.ClightRefinement.X86ProducerWidthBindings
