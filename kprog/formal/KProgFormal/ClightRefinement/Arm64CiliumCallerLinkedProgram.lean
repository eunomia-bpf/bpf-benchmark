import KProgFormal.ClightRefinement.Arm64CiliumCallerLink
import KProgFormal.Clight.Arm64Program
import CCLib.Linking

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedProgram

private theorem linked_exists :
    (CC.Link.linkProgramRenaming Arm64CiliumCallerUnit.prog Arm64Program.prog).isSome = true := by
  decide +kernel

/-- Extract only the actual imported linker result after kernel-checked existence. -/
noncomputable def program : CC.Program :=
  (CC.Link.linkProgramRenaming Arm64CiliumCallerUnit.prog Arm64Program.prog).get linked_exists

noncomputable def ge : CC.CGenv := program.globalenv

/-- Both complete exports go through clean's imported private-symbol-aware linker. -/
theorem linked_source :
    CC.Link.linkProgramRenaming Arm64CiliumCallerUnit.prog Arm64Program.prog = some program :=
  (Option.some_get linked_exists).symm

theorem linked_wellformed : CC.compositesWellFormed program = true := by decide +kernel

private theorem caller_resolved :
    (CC.Genv.findSymbol ge.genv_genv Arm64CiliumCallerUnit._trusted_arm64_arm64_sim_xdp).bind
      (CC.Genv.findFunctPtr ge.genv_genv) =
      some (.Internal Arm64CiliumCallerLink.procedure) := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem caller_lookup : ∃ b,
    CC.Genv.findSymbol ge.genv_genv Arm64CiliumCallerUnit._trusted_arm64_arm64_sim_xdp = some b ∧
    CC.Genv.findFunctPtr ge.genv_genv b = some (.Internal Arm64CiliumCallerLink.procedure) :=
  (Option.bind_eq_some_iff
    (x := CC.Genv.findSymbol ge.genv_genv Arm64CiliumCallerUnit._trusted_arm64_arm64_sim_xdp)
    (f := CC.Genv.findFunctPtr ge.genv_genv)
    (b := .Internal Arm64CiliumCallerLink.procedure)).mp caller_resolved

private theorem writer_resolved :
    (CC.Genv.findSymbol ge.genv_genv Arm64CiliumCallerUnit._kprog_arm64_program_write_pointer).bind
      (CC.Genv.findFunctPtr ge.genv_genv) =
      some (.Internal Arm64Program.f_kprog_arm64_program_write_pointer) := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

theorem writer_lookup : ∃ b,
    CC.Genv.findSymbol ge.genv_genv Arm64CiliumCallerUnit._kprog_arm64_program_write_pointer = some b ∧
    CC.Genv.findFunctPtr ge.genv_genv b =
      some (.Internal Arm64Program.f_kprog_arm64_program_write_pointer) :=
  (Option.bind_eq_some_iff
    (x := CC.Genv.findSymbol ge.genv_genv Arm64CiliumCallerUnit._kprog_arm64_program_write_pointer)
    (f := CC.Genv.findFunctPtr ge.genv_genv)
    (b := .Internal Arm64Program.f_kprog_arm64_program_write_pointer)).mp writer_resolved

/-- Allocation-relevant layouts for all795 original caller locals must survive the link. -/
theorem local_layouts : ∀ row ∈ Arm64CiliumCallerLink.procedure.fn_vars,
    CC.sizeof ge.genv_cenv row.2 = CC.sizeof Arm64CiliumCallerLink.ge.genv_cenv row.2 ∧
    CC.alignof ge.genv_cenv row.2 = CC.alignof Arm64CiliumCallerLink.ge.genv_cenv row.2 := by
  decide +kernel

private theorem allocate_sizes (first second : CC.CompositeEnv) (vars : List (CC.Ident × CC.Ty))
    (sizes : ∀ row ∈ vars,CC.sizeof first row.2 = CC.sizeof second row.2)
    (env : CC.Env) (memory : CC.Mem) :
    CC.doAllocVariables first env memory vars = CC.doAllocVariables second env memory vars := by
  induction vars generalizing env memory with
  | nil => rfl
  | cons head rest ih =>
      simp only [CC.doAllocVariables]
      rw [sizes head List.mem_cons_self]
      apply ih
      intro row member
      exact sizes row (List.mem_cons_of_mem _ member)

/-- The actual caller allocator stays the same; this introduces no earlier allocator bridge. -/
theorem linked_allocation (m : CC.Mem) :
    CC.doAllocVariables ge.genv_cenv CC.emptyEnv m Arm64CiliumCallerLink.procedure.fn_vars =
      Arm64CiliumCallerLink.allocation m :=
  allocate_sizes _ _ _ (fun row member => (local_layouts row member).1) _ _

end KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedProgram
