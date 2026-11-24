import KProgFormal.ClightRefinement.X86RegisterReadTag

namespace KProgFormal.ClightRefinement.X86RegisterReadRsp

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_rsp_read_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def materialize : CC.Stmt := by
  run_tac cachePart (← `(match X86RegisterReadValue.afterValue with
    | .Ssequence first _ => first | _ => .Sskip))

/-- Bind the RSP materialization gate and its suffix to the real reader. -/
theorem source : X86RegisterReadValue.afterValue =
    .Ssequence materialize X86RegisterReadTag.lanes := rfl

private def members : List CC.Member := by
  run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))

/-- The original binding header stores native_stack_base at112, after its
actual six inline-value records. The imported value layout determines this. -/
theorem base_offset (ge : CC.CGenv)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord) :
    CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._native_stack_base
      X86ShiftLeftCarry.bindingsRecord.co_members = .OK (112, .Full) := by
  change CC.fieldOffset ge.genv_cenv X86_program_profile_bpf._native_stack_base members = _
  have valueSize : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl
  have valueAlign : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl
  have cells : X86_program_profile_bpf._native_stack_base ≠ X86_program_profile_bpf._cells := by decide +kernel
  have stack : X86_program_profile_bpf._native_stack_base ≠ X86_program_profile_bpf._stack := by decide +kernel
  have values : X86_program_profile_bpf._native_stack_base ≠ X86_program_profile_bpf._values := by decide +kernel
  simp only [members, CC.fieldOffset, CC.fieldOffsetRec, CC.Member.name, cells, stack, values,
    beq_self_eq_true, ite_false, ite_true]
  simp +decide [CC.layoutField, CC.nextField, CC.bitalignof, CC.bitsizeof,
    CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr, CC.align, CC.zdiv,
    CC.noattr, CC.tptr, CC.tarray, valueLayout, valueSize, valueAlign]

def temps (le : CC.TempEnv) (baseBlock : CC.Block) (baseOffset : CC.Integers.Ptrofs)
    (offset nativeBase : BitVec 64) : CC.TempEnv :=
  ((le.set X86_program_profile_bpf._t'11 (.Vptr baseBlock baseOffset)).set
    X86_program_profile_bpf._t'12 (.Vlong nativeBase)).set
    X86_program_profile_bpf.___x86_rd_value (.Vlong (offset + nativeBase))

/-- RSP takes its actual branch, reads the real native-base pointer and word,
and materializes the numerical value in ten source transitions. No tag load
or numerical-result premise substitutes for either original read. -/
theorem materialize_rsp (ge : CC.CGenv)
    (bindingLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (bindingBlock baseBlock : CC.Block) (baseOffset : CC.Integers.Ptrofs)
    (offset nativeBase : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (reg : le.get X86_program_profile_bpf.___x86_rd_reg = some (.Vint (4#32)))
    (value : le.get X86_program_profile_bpf.___x86_rd_value = some (.Vlong offset))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 112 = some (.Vptr baseBlock baseOffset))
    (native : CC.Mem.load .Mint64 memory baseBlock (CC.Integers.Ptrofs.unsigned baseOffset) =
      some (.Vlong nativeBase)) :
    InternalRun ge 10
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadValue.afterValue k e le memory)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadTag.lanes k e
        (temps le baseBlock baseOffset offset nativeBase) memory) := by
  have field : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._native_stack_base (.Vptr bindingBlock (0#64)) =
      some (bindingBlock, 112, .Full) := by
    simp only [CC.lvalOfField, bindingLayout, base_offset ge valueLayout]
    rfl
  have structAccess : CC.accessMode
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (CC.tptr CC.tulong) = .By_value CC.Mptr := rfl
  have longAccess : CC.accessMode CC.tulong = .By_value .Mint64 := rfl
  have unsigned112 : CC.Integers.Ptrofs.unsigned (112#64) = 112 := rfl
  rw [source]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep, materialize, temps,
    CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr, CC.Archi.ptr64_eq, binding, reg, value, field, structAccess,
    ptrAccess, longAccess, CC.accessMode, CC.Mem.loadv, header, native, unsigned112, CC.PTree.gss, CC.PTree.gso,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
    CC.Cop.semAdd, CC.Cop.classifyAdd, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
    CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
    CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Integers.Int.one, CC.Integers.MI.one,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue,
    CC.Integers.Int64.add, CC.Integers.MI.add, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Eapp, CC.E0, List.nil_append, true_and, ite_true, ite_false]

end KProgFormal.ClightRefinement.X86RegisterReadRsp
