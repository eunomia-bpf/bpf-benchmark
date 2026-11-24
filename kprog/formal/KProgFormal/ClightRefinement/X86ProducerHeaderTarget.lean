import KProgFormal.ClightRefinement.X86ProducerHeaderAddress

namespace KProgFormal.ClightRefinement.X86ProducerHeaderTarget
open X86ProducerHeaderSource X86ProducerHeaderAddress
private theorem value_size : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl

private theorem binding_expr (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (binding : CC.Block)
    (bound : e.get X86_program_profile_bpf.___x86_inline_bindings = some (binding, headerType)) :
    CC.doEvalExpr ge e le memory (.Evar X86_program_profile_bpf.___x86_inline_bindings headerType) =
      some (.Vptr binding 0) := by
  simp only [CC.doEvalExpr, CC.lvalOfVar, bound, CC.doDerefLoc, headerType, CC.accessMode]
  rfl

private theorem values_expr (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (binding : CC.Block)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (bound : e.get X86_program_profile_bpf.___x86_inline_bindings = some (binding, headerType)) :
    CC.doEvalExpr ge e le memory
      (.Efield (.Evar X86_program_profile_bpf.___x86_inline_bindings headerType)
        X86_program_profile_bpf._values
        (CC.tarray (.Tstruct X86_program_profile_bpf._x86_sim_inline_value CC.noattr) 6)) =
      some (.Vptr binding (16#64)) := by
  have source := binding_expr ge e le memory binding bound
  rw [CC.doEvalExpr, source]
  simp only [CC.typeof, CC.lvalOfField, headerType, bindingsLayout,
    values_offset ge.genv_cenv valueLayout, CC.doDerefLoc, CC.accessMode, CC.tarray]
  rfl

private theorem normalized_offset : ∀ i : Fin 24, 2 ≤ i.val ∧ i.val < 14 →
    CC.Integers.Ptrofs.repr 16 + CC.Integers.Ptrofs.repr 16 *
      CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr (((i.val : CC.Z) - 2) / 2)) +
      (if i.val % 2 = 0 then CC.Integers.Ptrofs.repr 0 else CC.Integers.Ptrofs.repr 8) =
      CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z)) := by decide +kernel

/-- The original target expression evaluates to its actual eight-byte header
slot, including every nested ghost-array element and field. -/
theorem target_address (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (binding : CC.Block) (i : Fin 24)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (bound : e.get X86_program_profile_bpf.___x86_inline_bindings = some (binding, headerType)) :
    CC.doEvalLvalue ge e le memory (target i) =
      some (binding, CC.Integers.Ptrofs.repr (8 * (i.val : Int)), .Full) := by
  have values := values_expr ge e le memory binding bindingsLayout valueLayout bound
  have tagOffset : CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._tag
      X86ShiftLeftCarry.valueRecord.co_members = .OK (0, .Full) := ghost_offset ge.genv_cenv false
  have pointerOffset : CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._pointer
      X86ShiftLeftCarry.valueRecord.co_members = .OK (8, .Full) := ghost_offset ge.genv_cenv true
  by_cases nested : 2 ≤ i.val ∧ i.val < 14
  · unfold target
    rw [ite_eq_left nested, CC.doEvalLvalue, CC.doEvalExpr, CC.doEvalExpr, values]
    by_cases parity : i.val % 2 = 0
    all_goals simp +decide [parity, CC.doEvalExpr, CC.typeof, CC.doDerefLoc,
      CC.accessMode, CC.lvalOfField, valueLayout,
      tagOffset, pointerOffset,
      CC.Cop.semBinaryOperation, CC.Cop.semAdd, CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt, CC.sizeof, CC.typeconv,
      CC.removeAttributes, CC.tattr, value_size, CC.tint, CC.tarray, CC.noattr,
      CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.mul,
      CC.Integers.Ptrofs.repr, CC.Integers.MI.add, CC.Integers.MI.mul,
      CC.Integers.MI.repr]
    all_goals
      have calculation := normalized_offset i nested
      simp only [parity, ite_true, ite_false] at calculation
      run_tac Lean.Elab.Tactic.withMainContext do
        let fact ← Lean.Elab.Term.elabTerm (Lean.mkIdent `calculation) none
        let pair ← Lean.Elab.Term.elabTerm
          (← `(fun offset : CC.Integers.Ptrofs => (offset, CC.Bitfield.Full))) none
        let proof ← Lean.Meta.mkAppM ``congrArg #[pair, fact]
        Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
        let proof ← Lean.instantiateMVars proof
        let valid ← Lean.Meta.withTransparency .all
          (Lean.Meta.isDefEq (← Lean.Meta.inferType proof) (← Lean.Elab.Tactic.getMainTarget))
        unless valid do throwError "actual pointer arithmetic does not match the source target"
        Lean.Elab.Tactic.closeMainGoal `actual_x86_pointer_offset proof
  · have direct : i.val < 2 ∨ 14 ≤ i.val := by omega
    simp only [target, nested, ite_false, CC.doEvalLvalue, CC.doEvalExpr, CC.lvalOfVar,
      bound, headerType, CC.doDerefLoc, CC.accessMode, CC.lvalOfField, CC.typeof,
      bindingsLayout, direct_offset ge valueLayout i direct]
    change some (binding, (0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr (8 * (i.val : Int)), CC.Bitfield.Full) = _
    exact congrArg (fun offset : CC.Integers.Ptrofs => some (binding, offset, CC.Bitfield.Full))
      (BitVec.zero_add (CC.Integers.Ptrofs.repr (8 * (i.val : Int))))

end KProgFormal.ClightRefinement.X86ProducerHeaderTarget
