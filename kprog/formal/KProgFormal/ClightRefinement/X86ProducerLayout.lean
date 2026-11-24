import KProgFormal.ClightRefinement.X86ProducerHeaderComplete

namespace KProgFormal.ClightRefinement.X86ProducerLayout

/-- The complete original exported program supplies this world; its composites
are not replaced by a hand-assembled subset. -/
def ge : CC.CGenv := X86_program_profile_bpf.prog.globalenv

private def close_source_equality : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
  unless target.isAppOfArity ``Eq 3 do throwError "expected original source layout equality"
  goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal []

/-- The original complete composite builder succeeds, so mkprogram's empty
error case is never used by this actual world. -/
theorem built : CC.buildCompositeEnv X86_program_profile_bpf.composites = .OK ge.genv_cenv := by
  run_tac close_source_equality

def registersRecord : CC.Composite := by
  run_tac do
    let lookup ← Lean.Elab.Term.elabTerm
      (← `(ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells)) none
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf lookup)
    unless result.isAppOfArity ``Option.some 2 do throwError "original register union missing"
    Lean.Elab.Tactic.closeMainGoal `original_x86_register_union result.getAppArgs[1]!

/-- All four layout premises of the header proof follow the same complete
source environment. Existing source-derived record definitions are unchanged. -/
theorem layouts :
    ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord ∧
    ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord ∧
    ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord ∧
    ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells = some registersRecord := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> run_tac close_source_equality

/-- The actual GPR-array field in the original register union starts at zero. -/
theorem cells_offset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._gpr_cells
    registersRecord.co_members = .OK (0, .Full) := by
  run_tac close_source_equality

theorem registers_layout : registersRecord.co_sizeof = 256 ∧ registersRecord.co_alignof = 8 ∧ registersRecord.co_rank = 4 := by
  refine ⟨?_, ?_, ?_⟩ <;> run_tac close_source_equality

end KProgFormal.ClightRefinement.X86ProducerLayout
