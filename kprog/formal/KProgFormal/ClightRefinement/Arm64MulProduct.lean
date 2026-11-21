import KProgFormal.ClightRefinement.Arm64MulOperands

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Mul.Product

private structure Pieces where
  init : CC.Stmt
  choose : CC.Stmt
  copy : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual MUL product constructors changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Operands.product)) none)
    let rest ← peel root[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_mul_product (← Lean.Meta.mkAppM ``Pieces.mk
      #[root[0]!, rest[0]!, rest[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_mul_product_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def init : CC.Stmt := by run_tac cachePart (← `(pieces.init))
private def choose : CC.Stmt := by run_tac cachePart (← `(pieces.choose))
private def copy : CC.Stmt := by run_tac cachePart (← `(pieces.copy))

private structure SwitchPieces where
  selector : CC.Expr
  labels : CC.LStmts
  action : CC.Stmt
  fallthrough : CC.Stmt
  assignment : CC.Stmt

private def switchPieces : SwitchPieces := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(choose)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "actual MUL switch changed"
    let number ← Lean.Elab.Term.elabTerm (← `((12 : Int))) none
    let labels := actual.getAppArgs[1]!
    let selected ← Lean.Meta.mkAppM ``CC.selectSwitch #[number, labels]
    let selected ← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement #[selected]
    let selected ← Lean.Meta.withTransparency .all (Lean.Meta.whnf selected)
    unless selected.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual MUL selected case changed"
    let action := selected.getAppArgs[0]!
    let actionBody ← Lean.Meta.withTransparency .all (Lean.Meta.whnf action)
    unless actionBody.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual MUL case12 body changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mul_case12 (← Lean.Meta.mkAppM ``SwitchPieces.mk
      #[actual.getAppArgs[0]!, labels, action, selected.getAppArgs[1]!, actionBody.getAppArgs[0]!])

private def selector : CC.Expr := by run_tac cachePart (← `(switchPieces.selector))
private def labels : CC.LStmts := by run_tac cachePart (← `(switchPieces.labels))
private def case12 : CC.Stmt := by run_tac cachePart (← `(switchPieces.action))
private def fallthrough : CC.Stmt := by run_tac cachePart (← `(switchPieces.fallthrough))
private def productSet : CC.Stmt := by run_tac cachePart (← `(switchPieces.assignment))

private theorem choose_source : choose = .Sswitch selector labels := rfl
private theorem chosen_source : CC.seqOfLabeledStatement (CC.selectSwitch 12 labels) =
    .Ssequence case12 fallthrough := rfl
private theorem case_source : case12 = .Ssequence productSet .Sbreak := rfl
private theorem selector_source : selector = .Etempvar Arm64Program.___kprog_a64_mul_op CC.tulong := rfl

/-- The original initialization, actual source switch and result copy. -/
theorem product_source : Operands.product = .Ssequence init (.Ssequence choose copy) := rfl

def temps (le : CC.TempEnv) (lhs rhs : BitVec 64) : CC.TempEnv :=
  ((le.set Arm64Program.___kprog_a64_mul_result (.Vlong 0)).set
    Arm64Program.___kprog_a64_mul_result (.Vlong (lhs * rhs))).set
    Arm64Program.___a64_l_result__1 (.Vlong (lhs * rhs))

private theorem op_ne_result : Arm64Program.___kprog_a64_mul_op ≠ Arm64Program.___kprog_a64_mul_result := by decide +kernel
private theorem result_ne_op : Arm64Program.___kprog_a64_mul_result ≠ Arm64Program.___kprog_a64_mul_op := Ne.symm op_ne_result
private theorem lhs_ne_result : Arm64Program.___kprog_a64_mul_lhs ≠ Arm64Program.___kprog_a64_mul_result := by decide +kernel
private theorem result_ne_lhs : Arm64Program.___kprog_a64_mul_result ≠ Arm64Program.___kprog_a64_mul_lhs := Ne.symm lhs_ne_result
private theorem rhs_ne_result : Arm64Program.___kprog_a64_mul_rhs ≠ Arm64Program.___kprog_a64_mul_result := by decide +kernel
private theorem result_ne_rhs : Arm64Program.___kprog_a64_mul_result ≠ Arm64Program.___kprog_a64_mul_rhs := Ne.symm rhs_ne_result

private theorem get_op_after_result (le : CC.TempEnv) (v : CC.Val) :
  (le.set Arm64Program.___kprog_a64_mul_result v).get Arm64Program.___kprog_a64_mul_op =
    le.get Arm64Program.___kprog_a64_mul_op :=
  CC.PTree.gso _ _ _ _ result_ne_op

private theorem get_lhs_after_result (le : CC.TempEnv) (v : CC.Val) :
  (le.set Arm64Program.___kprog_a64_mul_result v).get Arm64Program.___kprog_a64_mul_lhs =
    le.get Arm64Program.___kprog_a64_mul_lhs :=
  CC.PTree.gso _ _ _ _ result_ne_lhs

private theorem get_rhs_after_result (le : CC.TempEnv) (v : CC.Val) :
  (le.set Arm64Program.___kprog_a64_mul_result v).get Arm64Program.___kprog_a64_mul_rhs =
    le.get Arm64Program.___kprog_a64_mul_rhs :=
  CC.PTree.gso _ _ _ _ result_ne_rhs

private theorem product_set_source : productSet =
    .Sset Arm64Program.___kprog_a64_mul_result
      (.Ebinop .Omul (.Etempvar Arm64Program.___kprog_a64_mul_lhs CC.tulong)
        (.Etempvar Arm64Program.___kprog_a64_mul_rhs CC.tulong) CC.tulong) := rfl

private theorem product_set_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (lhs rhs : BitVec 64)
    (left : le.get Arm64Program.___kprog_a64_mul_lhs = some (.Vlong lhs))
    (right : le.get Arm64Program.___kprog_a64_mul_rhs = some (.Vlong rhs)) :
    CC.Step2 world (.State Arm64Nop.handler productSet k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e
        (le.set Arm64Program.___kprog_a64_mul_result (.Vlong (lhs * rhs))) m) := by
  rw [product_set_source]
  apply CC.doStep_sound
  simp only [CC.doStep, CC.doEvalExpr, left, right, CC.typeof,
    CC.Cop.semBinaryOperation, CC.Cop.semMul, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
    CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.classifyBool,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tulong, CC.Val.mul,
    CC.Integers.Int64.mul, CC.Integers.MI.mul]
  rfl

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (op : le.get Arm64Program.___kprog_a64_mul_op = some (.Vlong (12#64))) :
    CC.Step2 world (.State Arm64Nop.handler choose k e le m) CC.E0
      (.State Arm64Nop.handler (.Ssequence case12 fallthrough) (.Kswitch k) e le m) := by
  rw [choose_source]
  apply CC.doStep_sound
  simp only [CC.doStep, selector_source, CC.doEvalExpr, op, CC.Cop.semSwitchArg,
    CC.Cop.classifySwitch, CC.tulong, CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
    chosen_source]
  rfl

set_option hygiene false in
/-- Evaluate actual switch12 multiplication and copy, then leave the real
inner loop to the unchanged scalar writer; no product-result premise. -/
theorem evaluate (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (lhs rhs : BitVec 64)
    (op : le.get Arm64Program.___kprog_a64_mul_op = some (.Vlong (12#64)))
    (left : le.get Arm64Program.___kprog_a64_mul_lhs = some (.Vlong lhs))
    (right : le.get Arm64Program.___kprog_a64_mul_rhs = some (.Vlong rhs)) :
    InternalRun world 16
      (.State Arm64Nop.handler Operands.product (Operands.tailCont k) e le m)
      (.State Arm64Nop.handler Operands.writer k e (temps le lhs rhs) m) := by
  run_tac do
    for i in [:16] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 4 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply choose_step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact (CC.PTree.gso _ _ _ _ result_ne_op).trans op))
      else if i == 7 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply product_set_step (lhs := lhs) (rhs := rhs)))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact (CC.PTree.gso _ _ _ _ result_ne_lhs).trans left))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact (CC.PTree.gso _ _ _ _ result_ne_rhs).trans right))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, product_source,
        init, choose_source, chosen_source, case_source, selector_source, productSet, copy,
        temps, Operands.tailCont, op, left, right,
        CC.doEvalExpr, CC.typeof, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
        op_ne_result, lhs_ne_result, rhs_ne_result, result_ne_op, result_ne_lhs, result_ne_rhs,
        get_op_after_result, get_lhs_after_result, get_rhs_after_result,
        CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
        CC.Cop.semBinaryOperation, CC.Cop.semMul, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Val.mul,
        CC.Integers.Int64.mul, CC.Integers.MI.mul,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint, CC.tuint, CC.tlong, CC.tulong,
        CC.Integers.Int64.unsigned, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
        CC.Integers.Int.zero, CC.Integers.MI.zero, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil, ite_true, ite_false, eq_self] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64Mul.Product
