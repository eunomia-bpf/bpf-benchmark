import KProgFormal.ClightRefinement.X86ProducerContextSource

namespace KProgFormal.ClightRefinement.X86ProducerContextAddress
open X86ProducerContextSource
open X86ProducerHeaderSource (headerType)

private def bindingMembers : List CC.Member := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(X86ShiftLeftCarry.bindingsRecord.co_members))
      (some (← Lean.Elab.Tactic.getMainTarget))
    Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
    Lean.Elab.Tactic.closeMainGoal `original_context_members
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))
private theorem value_size : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl
private theorem value_align : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl

/-- Actual context members follow the original pointer header and retain byte-sized tail fields. -/
theorem field_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (i : Fin 5) : CC.fieldOffset ce (fieldName i) X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (offset i, .Full) := by
  have cases : ∀ i : Fin 5, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 := by decide +kernel
  rcases cases i with rfl | rfl | rfl | rfl | rfl
  · change CC.fieldOffset ce X86_program_profile_bpf._sim_helper_ctx bindingMembers = .OK (192, .Full)
    have names : X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._pf ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._af ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._xmm0_lo ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._xmm0_hi ∧ X86_program_profile_bpf._sim_helper_ctx ≠ X86_program_profile_bpf._sim_ret_addr := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12⟩
    simp_all only [CC.fieldOffset, bindingMembers, CC.fieldOffsetRec, CC.Member.name, ite_true, ite_false]
    simp +decide [CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof,
      CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv,
      CC.tptr, CC.tarray, CC.tuchar, CC.noattr, valueLayout, value_size, value_align]
  · change CC.fieldOffset ce X86_program_profile_bpf._sim_helper_abi_base bindingMembers = .OK (200, .Full)
    have names : X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._pf ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._af ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._xmm0_lo ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._xmm0_hi ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._sim_ret_addr ∧ X86_program_profile_bpf._sim_helper_abi_base ≠ X86_program_profile_bpf._sim_helper_ctx := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13⟩
    simp_all only [CC.fieldOffset, bindingMembers, CC.fieldOffsetRec, CC.Member.name, ite_true, ite_false]
    simp +decide [CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof,
      CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv,
      CC.tptr, CC.tarray, CC.tuchar, CC.noattr, valueLayout, value_size, value_align]
  · change CC.fieldOffset ce X86_program_profile_bpf._sim_skb_ctx bindingMembers = .OK (208, .Full)
    have names : X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._pf ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._af ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._xmm0_lo ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._xmm0_hi ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._sim_ret_addr ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._sim_helper_ctx ∧ X86_program_profile_bpf._sim_skb_ctx ≠ X86_program_profile_bpf._sim_helper_abi_base := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14⟩
    simp_all only [CC.fieldOffset, bindingMembers, CC.fieldOffsetRec, CC.Member.name, ite_true, ite_false]
    simp +decide [CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof,
      CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv,
      CC.tptr, CC.tarray, CC.tuchar, CC.noattr, valueLayout, value_size, value_align]
  · change CC.fieldOffset ce X86_program_profile_bpf._sim_is_xdp bindingMembers = .OK (216, .Full)
    have names : X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._pf ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._af ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._xmm0_lo ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._xmm0_hi ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._sim_ret_addr ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._sim_helper_ctx ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._sim_helper_abi_base ∧ X86_program_profile_bpf._sim_is_xdp ≠ X86_program_profile_bpf._sim_skb_ctx := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15⟩
    simp_all only [CC.fieldOffset, bindingMembers, CC.fieldOffsetRec, CC.Member.name, ite_true, ite_false]
    simp +decide [CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof,
      CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv,
      CC.tptr, CC.tarray, CC.tuchar, CC.noattr, valueLayout, value_size, value_align]
  · change CC.fieldOffset ce X86_program_profile_bpf._sim_abi_kind bindingMembers = .OK (217, .Full)
    have names : X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._cells ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._stack ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._values ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._native_stack_base ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._cf ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._zf ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._sf ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._of ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._pf ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._af ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._xmm0_lo ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._xmm0_hi ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._sim_ret_addr ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._sim_helper_ctx ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._sim_helper_abi_base ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._sim_skb_ctx ∧ X86_program_profile_bpf._sim_abi_kind ≠ X86_program_profile_bpf._sim_is_xdp := by decide +kernel
    rcases names with ⟨n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16⟩
    simp_all only [CC.fieldOffset, bindingMembers, CC.fieldOffsetRec, CC.Member.name, ite_true, ite_false]
    simp +decide [CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof,
      CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv,
      CC.tptr, CC.tarray, CC.tuchar, CC.noattr, valueLayout, value_size, value_align]

/-- Each actual target evaluates to its source-declared field address. -/
theorem target_address (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (binding : CC.Block) (i : Fin 5)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (bound : e.get X86_program_profile_bpf.___x86_inline_bindings = some (binding, headerType)) :
    CC.doEvalLvalue ge e le memory (target i) =
      some (binding, CC.Integers.Ptrofs.repr (offset i), .Full) := by
  simp only [target, CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar, bound,
    headerType, CC.doDerefLoc, CC.accessMode, CC.lvalOfField, CC.typeof,
    bindingsLayout, field_offset ge.genv_cenv valueLayout i]
  change some (binding, (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (offset i), CC.Bitfield.Full) = _
  exact congrArg (fun ofs : CC.Integers.Ptrofs => some (binding, ofs, CC.Bitfield.Full))
    (BitVec.zero_add (CC.Integers.Ptrofs.repr (offset i)))

end KProgFormal.ClightRefinement.X86ProducerContextAddress
