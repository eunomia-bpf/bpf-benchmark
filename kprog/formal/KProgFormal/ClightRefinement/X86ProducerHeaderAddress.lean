import KProgFormal.ClightRefinement.X86ProducerHeaderSource

namespace KProgFormal.ClightRefinement.X86ProducerHeaderAddress
open X86ProducerHeaderSource

private def memberRows (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_header_members
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def bindingMembers : List CC.Member := by
  run_tac memberRows (← `(X86ShiftLeftCarry.bindingsRecord.co_members))
private def valueMembers : List CC.Member := by
  run_tac memberRows (← `(X86ShiftLeftCarry.valueRecord.co_members))

private theorem value_size : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl
private theorem value_align : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl

local macro "header_offset" layout:term : tactic =>
  `(tactic|
    (simp_all only [CC.fieldOffset, bindingMembers, CC.fieldOffsetRec, CC.Member.name, ite_true, ite_false]
     simp +decide [CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof,
       CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv,
       CC.tptr, CC.tarray, CC.noattr, ($layout), value_size, value_align]))

/-- Direct source fields occupy their original pointer slots. -/
theorem direct_offset (ge : CC.CGenv)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (i : Fin 24) (direct : i.val < 2 ∨ 14 ≤ i.val) :
    CC.fieldOffset ge.genv_cenv (fieldName i) X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (8 * (i.val : Int), .Full) := by
  by_cases first : i = 0
  · subst i
    exact X86RegisterLayout.cells_offset ge.genv_cenv
  by_cases second : i = 1
  · subst i
    change CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._stack bindingMembers = .OK (8, .Full)
    have names : X86_program_profile_bpf._stack ≠ X86_program_profile_bpf._cells := by decide +kernel
    header_offset valueLayout
  have choices : ∀ j : Fin 24, j.val < 2 ∨ 14 ≤ j.val → j ≠ 0 → j ≠ 1 →
      j = 14 ∨ j = 15 ∨ j = 16 ∨ j = 17 ∨ j = 18 ∨ j = 19 ∨ j = 20 ∨ j = 21 ∨ j = 22 ∨ j = 23 := by decide +kernel
  have rest := choices i direct first second
  rcases rest with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  · exact X86RegisterReadRsp.base_offset ge valueLayout
  · exact X86ShiftLeftCarry.cf_offset ge.genv_cenv valueLayout
  · exact X86ShiftFlagZF.zf_offset ge.genv_cenv valueLayout
  · exact X86ShiftFlagSF.sf_offset ge.genv_cenv valueLayout
  · exact X86ShiftFlagOF.of_offset ge.genv_cenv valueLayout
  · exact X86ShiftFlagPF.pf_offset ge.genv_cenv valueLayout
  · change CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._af bindingMembers = .OK (160, .Full)
    have names : X86_program_profile_bpf._af ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._af ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._af ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._af ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._af ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._af ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._af ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._af ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._af ≠ X86_program_profile_bpf._pf := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8⟩
    header_offset valueLayout
  · change CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._xmm0_lo bindingMembers = .OK (168, .Full)
    have names : X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._pf ∧ X86_program_profile_bpf._xmm0_lo ≠ X86_program_profile_bpf._af := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8, n9⟩
    header_offset valueLayout
  · change CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._xmm0_hi bindingMembers = .OK (176, .Full)
    have names : X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._pf ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._af ∧ X86_program_profile_bpf._xmm0_hi ≠ X86_program_profile_bpf._xmm0_lo := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10⟩
    header_offset valueLayout
  · change CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._sim_ret_addr bindingMembers = .OK (184, .Full)
    have names : X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._pf ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._af ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._xmm0_lo ∧ X86_program_profile_bpf._sim_ret_addr ≠ X86_program_profile_bpf._xmm0_hi := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11⟩
    header_offset valueLayout

theorem values_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._values X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (16, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._values bindingMembers = _
  simp +decide [bindingMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.tarray, CC.noattr, valueLayout, value_size, value_align]

theorem ghost_offset (ce : CC.CompositeEnv) (isPointer : Bool) :
    CC.fieldOffset ce (if isPointer then X86_program_profile_bpf._pointer else X86_program_profile_bpf._tag)
      X86ShiftLeftCarry.valueRecord.co_members = .OK ((if isPointer then 8 else 0), .Full) := by
  change CC.fieldOffset ce _ valueMembers = _
  cases isPointer <;> simp +decide [valueMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]

end KProgFormal.ClightRefinement.X86ProducerHeaderAddress
