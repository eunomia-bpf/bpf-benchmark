import KProgFormal.ClightRefinement.X86ShiftLeftCarry

namespace KProgFormal.ClightRefinement.X86ShiftLeftClassify

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_shift_classifier
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Pieces where
  dispatch : CC.Stmt
  switch : CC.Stmt

private def pieces : Pieces :=
  match X86ShiftLeftCarry.classify with
  | .Ssequence dispatch switch => ⟨dispatch, switch⟩
  | _ => ⟨.Sskip, .Sskip⟩

private def dispatch : CC.Stmt := by run_tac cachePart (← `(pieces.dispatch))
def flagSwitch : CC.Stmt := by run_tac cachePart (← `(pieces.switch))

/-- The complete classifier and following switch are the original source statements. -/
theorem source : X86ShiftLeftCarry.classify = .Ssequence dispatch flagSwitch := rfl

private def choice : CC.Stmt := by
  run_tac do
    let mut term ← Lean.Elab.Term.elabTerm (← `(dispatch)) none
    for _ in [0:8] do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "expected source classifier gate"
      term := node.getAppArgs[2]!
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "expected selected SHL gate"
    Lean.Elab.Tactic.closeMainGoal `actual_x86_shl_flag_choice node.getAppArgs[1]!

def afterTemps (le : CC.TempEnv) : CC.TempEnv :=
  (List.replicate 9 ()).foldl
    (fun temps _ => temps.set X86_program_profile_bpf._t'43 (.Vint (7#32))) le

private theorem test_value (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (n : BitVec 32) :
    CC.doEvalExpr ge e le m
      (.Ebinop .Oeq (.Ecast (.Etempvar X86_program_profile_bpf.___x86_l_alu CC.tuchar) CC.tuchar)
        (.Econst_int n CC.tuint) CC.tint) =
      some (.Vint (if (5#32) == n then (1#32) else (0#32))) := by
  by_cases equal : (5#32) = n
  all_goals try subst n
  all_goals simp_all +decide [CC.doEvalExpr, CC.typeof, CC.tuchar, CC.tuint, CC.tint, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
      CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.cmpu,
      CC.Integers.MI.cmpu, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext]

private theorem route_steps (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 9 (.State function dispatch k e le m)
      (.State function choice k e le m) := by
  have bool_zero : CC.Cop.boolVal (.Vint (0#32)) CC.tint m = some false := rfl
  have bool_one : CC.Cop.boolVal (.Vint (1#32)) CC.tint m = some true := rfl
  apply internalRun_of_steps
  · simp +decide [InternalPath, InternalState, dispatch, X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_67,
      CC.doStep, test_value ge e le m operation, CC.typeof, bool_zero, bool_one, CC.Integers.Int.repr,
      CC.Integers.MI.repr, CC.E0]
  · simp +decide [steps, dispatch, choice, X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_67,
      CC.doStep, test_value ge e le m operation, CC.typeof, bool_zero, bool_one,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Eapp, CC.E0]

private theorem write_steps (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 25 (.State function choice k e le m)
      (.State function .Sskip k e (afterTemps le) m) := by
  apply internalRun_of_steps
  · simp +decide [InternalPath, InternalState, choice, CC.doStep, CC.doEvalExpr, CC.typeof, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuint, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.E0]
  · simp +decide [steps, choice, afterTemps, List.replicate, List.foldl,
      CC.doStep, CC.doEvalExpr, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast,
      CC.Cop.castIntInt, CC.tuint, CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Eapp, CC.E0]

private theorem classify_steps (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 34 (.State function dispatch k e le m)
      (.State function .Sskip k e (afterTemps le) m) :=
  (route_steps ge function e le k m operation).trans (write_steps ge function e le k m)

/-- Operation five selects the real shift flag kind seven, preserving full
memory, locals and caller continuation for every incoming temporary map. -/
theorem internal (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 36 (.State function X86ShiftLeftCarry.classify k e le m)
      (.State function flagSwitch k e (afterTemps le) m) := by
  have first : CC.doStep ge (.State function X86ShiftLeftCarry.classify k e le m) =
      some (CC.E0, .State function dispatch (.Kseq flagSwitch k) e le m) := by
    rw [source]; rfl
  have start : InternalRun ge 1 (.State function X86ShiftLeftCarry.classify k e le m)
      (.State function dispatch (.Kseq flagSwitch k) e le m) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ first) (.refl _)
  have last : CC.doStep ge (.State function .Sskip (.Kseq flagSwitch k) e (afterTemps le) m) =
      some (CC.E0, .State function flagSwitch k e (afterTemps le) m) := rfl
  have finish : InternalRun ge 1
      (.State function .Sskip (.Kseq flagSwitch k) e (afterTemps le) m)
      (.State function flagSwitch k e (afterTemps le) m) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ last) (.refl _)
  exact (start.trans (classify_steps ge function e le (.Kseq flagSwitch k) m operation)).trans finish

/-- The relational source execution retains the same complete memory. -/
theorem returns (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    CC.Star (CC.Step2 ge) (.State function X86ShiftLeftCarry.classify k e le m) CC.E0
      (.State function flagSwitch k e (afterTemps le) m) :=
  (internal ge function e le k m operation).sound

/-- The classifier writes kind seven and frames all other temporaries. -/
theorem temps (le : CC.TempEnv) :
    (afterTemps le).get X86_program_profile_bpf._t'43 = some (.Vint (7#32)) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'43 → (afterTemps le).get id = le.get id := by
  refine ⟨by simp [afterTemps, List.replicate, List.foldl], ?_⟩
  intro id different
  simp [afterTemps, List.replicate, List.foldl, CC.PTree.gso, Ne.symm different]

private def cases : CC.LStmts := by
  run_tac cachePart (← `(match flagSwitch with
    | .Sswitch _ cases => cases
    | _ => .LSnil))

def shiftBranch : CC.Stmt := by
  run_tac cachePart (← `(CC.seqOfLabeledStatement (CC.selectSwitch 7 cases)))

/-- The original source switch reads the classifier temporary and original cases. -/
theorem switch_source : flagSwitch =
    .Sswitch (.Etempvar X86_program_profile_bpf._t'43 CC.tuint) cases := rfl

private theorem branch_source : CC.seqOfLabeledStatement (CC.selectSwitch 7 cases) = shiftBranch := rfl

/-- The actual switch selects its original shift flag branch and fallthrough continuation. -/
theorem to_shift (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 37 (.State function X86ShiftLeftCarry.classify k e le m)
      (.State function shiftBranch (.Kswitch k) e (afterTemps le) m) := by
  have evaluated : CC.doEvalExpr ge e (afterTemps le) m
      (.Etempvar X86_program_profile_bpf._t'43 CC.tuint) = some (.Vint (7#32)) := by
    simp [CC.doEvalExpr, afterTemps, List.replicate, List.foldl]
  have number : CC.Cop.semSwitchArg (.Vint (7#32)) CC.tuint = some 7 := rfl
  have selected : CC.doStep ge (.State function flagSwitch k e (afterTemps le) m) =
      some (CC.E0, .State function shiftBranch (.Kswitch k) e (afterTemps le) m) := by
    rw [switch_source]
    simp only [CC.doStep, evaluated, CC.typeof, number, branch_source]
  have last : InternalRun ge 1 (.State function flagSwitch k e (afterTemps le) m)
      (.State function shiftBranch (.Kswitch k) e (afterTemps le) m) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ selected) (.refl _)
  exact (internal ge function e le k m operation).trans last

end KProgFormal.ClightRefinement.X86ShiftLeftClassify
