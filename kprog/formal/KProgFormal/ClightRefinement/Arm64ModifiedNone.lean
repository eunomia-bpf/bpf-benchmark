import KProgFormal.ClightRefinement.Arm64ModifiedCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Modified.None

open Read (handler modify)
private structure Parts where
  input : CC.Stmt
  kind : CC.Stmt
  shift : CC.Stmt
  mask : CC.Stmt
  amount : CC.Stmt
  choose : CC.Stmt
  output : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original NONE modifier source changed"
      pure actual.getAppArgs
    let input ← peel (← Lean.Elab.Term.elabTerm (← `(Modifier.body)) none)
    let kind ← peel input[1]!
    let shift ← peel kind[1]!
    let rest ← peel shift[1]!
    let mask ← peel rest[0]!
    let tail ← peel rest[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_none_modifier_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[input[0]!,kind[0]!,shift[0]!,mask[0]!,mask[1]!,tail[0]!,tail[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_none_modifier_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def input : CC.Stmt := by run_tac cachePart (← `(parts.input))
private def kind : CC.Stmt := by run_tac cachePart (← `(parts.kind))
private def shift : CC.Stmt := by run_tac cachePart (← `(parts.shift))
private def mask : CC.Stmt := by run_tac cachePart (← `(parts.mask))
private def amount : CC.Stmt := by run_tac cachePart (← `(parts.amount))
private def choose : CC.Stmt := by run_tac cachePart (← `(parts.choose))
private def output : CC.Stmt := by run_tac cachePart (← `(parts.output))
private def cases : CC.LStmts := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(choose)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "original NONE modifier switch changed"
    Lean.Elab.Tactic.closeMainGoal `actual_none_cases actual.getAppArgs[1]!
@[irreducible] private def deadCases : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(CC.seqOfLabeledStatement (CC.selectSwitch 0 cases))) none))
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original NONE case changed"
    Lean.Elab.Tactic.closeMainGoal `actual_none_dead_cases actual.getAppArgs[1]!
private theorem body_source : Modifier.body = .Ssequence input (.Ssequence kind (.Ssequence shift
    (.Ssequence (.Ssequence mask amount) (.Ssequence choose output)))) := rfl
private theorem choose_source : choose = .Sswitch (.Etempvar Arm64Program.___kprog_a64_mod CC.tuchar) cases := rfl
private theorem case_zero : CC.seqOfLabeledStatement (CC.selectSwitch 0 cases) = .Ssequence .Sbreak deadCases := by
  unfold deadCases
  rfl

private theorem output_source : output = .Sset Arm64Program._result
    (.Etempvar Arm64Program.___kprog_a64_mod_value CC.tulong) := rfl

private theorem output_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (value : BitVec 64) (read : le.get Arm64Program.___kprog_a64_mod_value = some (.Vlong value)) :
    CC.Step2 world (.State handler output k e le m) CC.E0
      (.State handler .Sskip k e (le.set Arm64Program._result (.Vlong value)) m) := by
  rw [output_source]
  apply CC.Step.set
  apply CC.doEvalExpr_sound
  simpa only [CC.doEvalExpr] using read

def prefixTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (((((le.set Arm64Program.___kprog_a64_mod_value (.Vlong value)).set Arm64Program.___kprog_a64_mod (.Vint 0)).set
    Arm64Program.___kprog_a64_mod_shift (.Vint 0)).set Arm64Program._t'5 (.Vint 63)).set
    Arm64Program.___kprog_a64_mod_amount (.Vint 0))
def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (prefixTemps le value).set Arm64Program._result (.Vlong value)

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (mode : le.get Arm64Program.___kprog_a64_mod = some (.Vint 0)) :
    CC.Step2 world (.State handler choose k e le m) CC.E0
      (.State handler (.Ssequence .Sbreak deadCases) (.Kswitch k) e le m) := by
  rw [choose_source,←case_zero]
  apply CC.Step.switch (v := .Vint 0) (n := 0)
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,mode]
  · rfl

set_option hygiene false in
private theorem input_prefix (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (hinput : le.get Arm64Program.___a64_modified_input = some (.Vlong value))
    (hkind : le.get Arm64Program._mod = some (.Vint 0))
    (hshift : le.get Arm64Program._shift = some (.Vint 0))
    (hwidth : le.get Arm64Program._width = some (.Vint 8)) :

    InternalRun world 18 (.State handler modify k e le m)
      (.State handler choose (.Kseq output (.Kloop1 Modifier.body .Sbreak k)) e (prefixTemps le value) m) := by
  run_tac do
    for _ in [:18] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [Modifier.modify_source,body_source,
        input,kind,shift,mask,amount,output,CC.doStep,CC.doEvalExpr,CC.typeof,CC.PTree.gss,CC.PTree.gso,
        hinput,hkind,hshift,hwidth,CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semCmp,
        CC.Cop.classifyCmp,CC.Cop.boolVal,CC.Cop.classifyBool,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.Archi.ptr64,
        CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
        CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
        CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.repr,CC.Integers.MI.repr,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,prefixTemps,temps,ite_true,ite_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

set_option hygiene false in
private theorem tail (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) :
    InternalRun world 7
      (.State handler (.Ssequence .Sbreak deadCases) (.Kswitch (.Kseq output (.Kloop1 Modifier.body .Sbreak k)))
        e (prefixTemps le value) m)
      (.State handler .Sskip k e (temps le value) m) := by
  run_tac do
    for i in [:7] do
      Lean.logInfo m!"NONE tail {i}"
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 4 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply output_step _ _ _ _ _ value))
        Lean.Elab.Tactic.evalTactic (← `(tactic| dsimp only [prefixTemps]))
        Lean.Elab.Tactic.evalTactic (← `(tactic| repeat first | rw [CC.PTree.gss] | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Original NONE case, width8 output and complete loop exit preserve the input word. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (hinput : le.get Arm64Program.___a64_modified_input = some (.Vlong value))
    (hkind : le.get Arm64Program._mod = some (.Vint 0))
    (hshift : le.get Arm64Program._shift = some (.Vint 0))
    (hwidth : le.get Arm64Program._width = some (.Vint 8)) :

    InternalRun world 26 (.State handler modify k e le m)
      (.State handler .Sskip k e (temps le value) m) := by
  have entered := input_prefix world e le m k value hinput hkind hshift hwidth
  have selected := choose_step world e (prefixTemps le value) m (.Kseq output (.Kloop1 Modifier.body .Sbreak k))
    (by simp +decide only [prefixTemps,CC.PTree.gss,CC.PTree.gso])
  have switched : InternalRun world 1
      (.State handler choose (.Kseq output (.Kloop1 Modifier.body .Sbreak k)) e (prefixTemps le value) m)
      (.State handler (.Ssequence .Sbreak deadCases) (.Kswitch (.Kseq output (.Kloop1 Modifier.body .Sbreak k)))
        e (prefixTemps le value) m) := .step trivial selected (.refl _)
  exact (entered.trans switched).trans (tail world e le m k value)

end KProgFormal.ClightRefinement.Arm64Modified.None
