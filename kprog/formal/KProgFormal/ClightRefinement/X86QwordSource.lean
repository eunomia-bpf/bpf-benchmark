import KProgFormal.ClightRefinement.X86ShiftWriteback

namespace KProgFormal.ClightRefinement.X86QwordSource

private structure Parts where
  first : CC.Stmt
  second : CC.Stmt
  destination : CC.Stmt
  source : CC.Stmt
  gate : CC.Stmt

private def parts : Parts :=
  match X86ShiftWriteback.sourceWriter with
  | .Ssequence (.Ssequence (.Ssequence (.Ssequence first second) destination) source) gate =>
    ⟨first, second, destination, source, gate⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_qword_source_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def first : CC.Stmt := by run_tac cachePart (← `(parts.first))
private def second : CC.Stmt := by run_tac cachePart (← `(parts.second))
private def destination : CC.Stmt := by run_tac cachePart (← `(parts.destination))
private def sourcePart : CC.Stmt := by run_tac cachePart (← `(parts.source))
private def gate : CC.Stmt := by run_tac cachePart (← `(parts.gate))

/-- The full source-pointer selector is the original statement. Its ALU0
condition precedes both tag-dependent gates. -/
theorem source : X86ShiftWriteback.sourceWriter =
    .Ssequence (.Ssequence (.Ssequence (.Ssequence first second) destination) sourcePart) gate := rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  ((((le.set X86_program_profile_bpf._t'119 (.Vint (1#32))).set
    X86_program_profile_bpf._t'120 (.Vint (1#32))).set
    X86_program_profile_bpf._t'121 (.Vint (0#32))).set
    X86_program_profile_bpf._t'122 (.Vint (0#32))).set
    X86_program_profile_bpf._t'124 (.Vint (0#32))

/-- In qword aligned-lane XOR/OR/AND paths, the actual ALU0 test short-circuits
both source-pointer tag gates. Twenty-one real transitions reach the original
default writer, preserving every caller byte without a tag-call assumption. -/
theorem execute (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (code : BitVec 32)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .q))
    (dstShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (0#32)))
    (srcShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (.Vint (0#32)))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint code))
    (notAdd : code ≠ (0#32)) :
    InternalRun ge 21 (.State function X86ShiftWriteback.sourceWriter k e le memory)
      (.State function X86ShiftWriteback.defaultWriter k e (temps le) memory) := by
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, first, second, destination, sourcePart, gate,
      temps, CC.doStep, CC.doEvalExpr, CC.typeof, width, dstShift, srcShift, operation, notAdd,
      X86ShiftLeft.argument, X86.Size.bytes, CC.PTree.gss, CC.PTree.gso,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]
  rfl

end KProgFormal.ClightRefinement.X86QwordSource
