import KProgFormal.ClightRefinement.X86ProducerLayout

namespace KProgFormal.ClightRefinement.X86ProducerGprLayout
open X86ProducerLayout (ge registersRecord)

def fieldName (i : Fin 16) : CC.Ident :=
  [X86_program_profile_bpf._rax, X86_program_profile_bpf._rcx, X86_program_profile_bpf._rdx, X86_program_profile_bpf._rbx, X86_program_profile_bpf._rsp, X86_program_profile_bpf._rbp, X86_program_profile_bpf._rsi, X86_program_profile_bpf._rdi, X86_program_profile_bpf._r8, X86_program_profile_bpf._r9, X86_program_profile_bpf._r10, X86_program_profile_bpf._r11, X86_program_profile_bpf._r12, X86_program_profile_bpf._r13, X86_program_profile_bpf._r14, X86_program_profile_bpf._r15][i]
def tagName (i : Fin 16) : CC.Ident :=
  [X86_program_profile_bpf._rax_tag, X86_program_profile_bpf._rcx_tag, X86_program_profile_bpf._rdx_tag, X86_program_profile_bpf._rbx_tag, X86_program_profile_bpf._rsp_tag, X86_program_profile_bpf._rbp_tag, X86_program_profile_bpf._rsi_tag, X86_program_profile_bpf._rdi_tag, X86_program_profile_bpf._r8_tag, X86_program_profile_bpf._r9_tag, X86_program_profile_bpf._r10_tag, X86_program_profile_bpf._r11_tag, X86_program_profile_bpf._r12_tag, X86_program_profile_bpf._r13_tag, X86_program_profile_bpf._r14_tag, X86_program_profile_bpf._r15_tag][i]

def namedRecord : CC.Composite := by
  run_tac do
    let lookup ← Lean.Elab.Term.elabTerm (← `(ge.genv_cenv.get X86_program_profile_bpf.__3130)) none
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf lookup)
    unless result.isAppOfArity ``Option.some 2 do throwError "original named GPR struct missing"
    Lean.Elab.Tactic.closeMainGoal `original_x86_named_gpr_record result.getAppArgs[1]!

private def source_equality : Lean.Elab.Tactic.TacticM Unit := do
  let goal ← Lean.Elab.Tactic.getMainGoal
  let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
  unless target.isAppOfArity ``Eq 3 do throwError "expected original GPR layout equality"
  goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
  Lean.Elab.Tactic.replaceMainGoal []

/-- The same complete original source environment supplies each nested record. -/
theorem source_layouts :
    ge.genv_cenv.get X86_program_profile_bpf.__3130 = some namedRecord ∧
    ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr = some X86RegisterLayout.gprRecord ∧
    ge.genv_cenv.get X86_program_profile_bpf._x86_sim_gpr_cell = some X86RegisterLayout.cellRecord := by
  refine ⟨?_, ?_, ?_⟩ <;> run_tac source_equality

/-- Named and array register views use the same original sixteen-byte stride. -/
theorem field_offsets : ∀ i : Fin 16,
    CC.fieldOffset ge.genv_cenv (fieldName i) namedRecord.co_members = .OK (16 * (i.val : Int), .Full) ∧
    CC.fieldOffset ge.genv_cenv (tagName i) namedRecord.co_members = .OK (16 * (i.val : Int) + 8, .Full) := by decide +kernel

/-- The enclosing anonymous member and each register's pointer union member start at zero. -/
theorem nested_offsets :
    CC.unionFieldOffset ge.genv_cenv (CC.Positive.ofNat 18727075383868559167) registersRecord.co_members = .OK (0, .Full) ∧
    CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._ptr X86RegisterLayout.gprRecord.co_members = .OK (0, .Full) := by
  constructor <;> run_tac source_equality

end KProgFormal.ClightRefinement.X86ProducerGprLayout
