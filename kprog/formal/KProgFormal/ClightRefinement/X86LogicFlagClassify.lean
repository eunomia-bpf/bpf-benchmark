import KProgFormal.ClightRefinement.X86ShiftLeftClassify

namespace KProgFormal.ClightRefinement.X86LogicFlagClassify

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_logical_flag_source
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def choice : CC.Stmt := by
  run_tac do
    let mut term ← Lean.Elab.Term.elabTerm (← `(X86ShiftLeftClassify.dispatch)) none
    for _ in [0:13] do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do
        throwError "expected actual logical flag classifier gate"
      term := node.getAppArgs[2]!
    Lean.Elab.Tactic.closeMainGoal `actual_x86_logical_flag_choice
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def branch : CC.Stmt := by
  run_tac cachePart (← `(CC.seqOfLabeledStatement
    (CC.selectSwitch 9 X86ShiftLeftClassify.cases)))

theorem branch_source : CC.seqOfLabeledStatement
    (CC.selectSwitch 9 X86ShiftLeftClassify.cases) = branch := rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (List.replicate 13 ()).foldl
    (fun ready _ => ready.set X86_program_profile_bpf._t'43 (.Vint (9#32))) le

private theorem route_steps (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (code : BitVec 8)
    (supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32))) :
    InternalRun ge 13 (.State function X86ShiftLeftClassify.dispatch k e le m)
      (.State function choice k e le m) := by
  rcases supported with rfl | rfl | rfl
  all_goals apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep,
      X86ShiftLeftClassify.dispatch, X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_67,
      choice, CC.doEvalExpr, CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
      CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.boolVal,
      CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      operation, CC.Eapp, CC.E0]

private theorem write_steps (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 37 (.State function choice k e le m)
      (.State function .Sskip k e (temps le) m) := by
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, choice,
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_66,
      temps, List.replicate, List.foldl, CC.doStep, CC.doEvalExpr, CC.typeof,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuint,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Eapp, CC.E0]

/-- The original logical classifier assigns kind9 thirteen times and reaches
its original switch in52 steps, preserving every other temporary and the heap. -/
theorem internal (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (code : BitVec 8)
    (supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32))) :
    InternalRun ge 52 (.State function X86ShiftLeftCarry.classify k e le m)
      (.State function X86ShiftLeftClassify.flagSwitch k e (temps le) m) := by
  have start : InternalRun ge 1 (.State function X86ShiftLeftCarry.classify k e le m)
      (.State function X86ShiftLeftClassify.dispatch (.Kseq X86ShiftLeftClassify.flagSwitch k) e le m) := by
    apply internalRun_of_steps
    all_goals simp [steps, InternalPath, InternalState, X86ShiftLeftClassify.source, CC.doStep, CC.Eapp, CC.E0]
  have finish : InternalRun ge 1
      (.State function .Sskip (.Kseq X86ShiftLeftClassify.flagSwitch k) e (temps le) m)
      (.State function X86ShiftLeftClassify.flagSwitch k e (temps le) m) := by
    apply internalRun_of_steps
    all_goals simp [steps, InternalPath, InternalState, CC.doStep, CC.Eapp, CC.E0]
  exact ((start.trans (route_steps ge function e le (.Kseq X86ShiftLeftClassify.flagSwitch k) m
    code supported operation)).trans (write_steps ge function e le
      (.Kseq X86ShiftLeftClassify.flagSwitch k) m)).trans finish

/-- The actual switch selects its original default logical flag branch. -/
theorem to_logic (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (code : BitVec 8)
    (supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32))) :
    InternalRun ge 53 (.State function X86ShiftLeftCarry.classify k e le m)
      (.State function branch (.Kswitch k) e (temps le) m) := by
  have evaluated : CC.doEvalExpr ge e (temps le) m
      (.Etempvar X86_program_profile_bpf._t'43 CC.tuint) = some (.Vint (9#32)) := by
    simp [CC.doEvalExpr, temps, List.replicate, List.foldl]
  have number : CC.Cop.semSwitchArg (.Vint (9#32)) CC.tuint = some 9 := rfl
  have selected : CC.doStep ge (.State function X86ShiftLeftClassify.flagSwitch k e (temps le) m) =
      some (CC.E0, .State function branch (.Kswitch k) e (temps le) m) := by
    rw [X86ShiftLeftClassify.switch_source]
    simp only [CC.doStep, evaluated, CC.typeof, number, branch_source]
  exact (internal ge function e le k m code supported operation).trans
    (.step (by trivial) (CC.doStep_sound ge _ _ _ selected) (.refl _))

/-- The real old-CF load and complete logical classifier compose in64
steps; every pointer, byte and classifier observation is derived in source. -/
theorem from_flags (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (code : BitVec 8) (supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32)))
    (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs) (old : BitVec 8)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (byte : CC.Mem.load .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (old.setWidth 32))) :
    InternalRun ge 64 (.State function X86ShiftLeftRoute.flags k e le m)
      (.State function branch (.Kswitch (X86ShiftLeftCarry.continuation k)) e
        (temps (X86ShiftLeftCarry.afterTemps le cfBlock offset old)) m) := by
  have carried := X86ShiftLeftCarry.enter_classifier ge bindingsLayout valueLayout function e le k m
    bindingBlock cfBlock offset old binding pointer byte
  have kept : (X86ShiftLeftCarry.afterTemps le cfBlock offset old).get
      X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32)) := by
    rw [(X86ShiftLeftCarry.temps le cfBlock offset old).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    exact operation
  exact carried.trans (to_logic ge function e (X86ShiftLeftCarry.afterTemps le cfBlock offset old)
    (X86ShiftLeftCarry.continuation k) m code supported kept)

/-- The actual classifier retains every incoming value except its kind result. -/
theorem observations (le : CC.TempEnv) :
    (temps le).get X86_program_profile_bpf._t'43 = some (.Vint (9#32)) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'43 → (temps le).get id = le.get id := by
  refine ⟨by simp [temps, List.replicate, List.foldl], ?_⟩
  intro id different
  simp [temps, List.replicate, List.foldl, CC.PTree.gso, Ne.symm different]

end KProgFormal.ClightRefinement.X86LogicFlagClassify
