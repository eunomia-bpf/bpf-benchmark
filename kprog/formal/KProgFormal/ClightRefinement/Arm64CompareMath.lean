import KProgFormal.ClightRefinement.Arm64ComparePrefix

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Math

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_compare_math_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private structure Pieces where
  selector : CC.Expr
  cases : CC.LStmts
  arm : CC.Stmt
  dead : CC.Stmt
  subBody : CC.Stmt
  mask : CC.Stmt
  sign : CC.Stmt
  lhs : CC.Stmt
  rhs : CC.Stmt
  result : CC.Stmt
  stores : CC.Stmt
private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual CMP SUB loop changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(RhsCall.flags)) none) ``CC.Stmt.Sloop 2
    let sw ← peel loop[0]! ``CC.Stmt.Sswitch 2
    let chosen ← peel (← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement
      #[← Lean.Meta.mkAppM ``CC.selectSwitch #[Lean.mkIntLit 1, sw[1]!]]) ``CC.Stmt.Ssequence 2
    let arm ← peel chosen[0]! ``CC.Stmt.Ssequence 2
    let sub ← peel arm[0]! ``CC.Stmt.Sloop 2
    let mask ← peel sub[0]! ``CC.Stmt.Ssequence 2
    let sign ← peel mask[1]! ``CC.Stmt.Ssequence 2
    let lhs ← peel sign[1]! ``CC.Stmt.Ssequence 2
    let rhs ← peel lhs[1]! ``CC.Stmt.Ssequence 2
    let res ← peel rhs[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_math (← Lean.Meta.mkAppM ``Pieces.mk
      #[sw[0]!,sw[1]!,chosen[0]!,chosen[1]!,sub[0]!,mask[0]!,sign[0]!,lhs[0]!,rhs[0]!,res[0]!,res[1]!])
private def selector : CC.Expr := by run_tac cachePart (← `(pieces.selector))
private def cases : CC.LStmts := by run_tac cachePart (← `(pieces.cases))
private def arm : CC.Stmt := by run_tac cachePart (← `(pieces.arm))
@[irreducible] private def dead : CC.Stmt := by run_tac cachePart (← `(pieces.dead))
def subBody : CC.Stmt := by run_tac cachePart (← `(pieces.subBody))
private def maskCode : CC.Stmt := by run_tac cachePart (← `(pieces.mask))
private def signCode : CC.Stmt := by run_tac cachePart (← `(pieces.sign))
private def lhsCode : CC.Stmt := by run_tac cachePart (← `(pieces.lhs))
private def rhsCode : CC.Stmt := by run_tac cachePart (← `(pieces.rhs))
private def resultCode : CC.Stmt := by run_tac cachePart (← `(pieces.result))
def stores : CC.Stmt := by run_tac cachePart (← `(pieces.stores))
def arithmetic : CC.Stmt := .Ssequence lhsCode (.Ssequence rhsCode (.Ssequence resultCode stores))

theorem loop_source : RhsCall.flags = .Sloop (.Sswitch selector cases) .Sbreak := rfl
theorem sub_source : subBody = .Ssequence maskCode (.Ssequence signCode arithmetic) := rfl
private theorem arm_source : arm = .Ssequence (.Sloop subBody .Sbreak) .Sbreak := rfl
private theorem select_source : CC.seqOfLabeledStatement (CC.selectSwitch 1 cases) =
    .Ssequence arm dead := by unfold dead; rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 subBody .Sbreak
  (.Kseq .Sbreak (.Kseq dead (.Kswitch (.Kloop1 (.Sswitch selector cases) .Sbreak k))))

def mask (narrow : Bool) : BitVec 64 := Arm64Modified.Modifier.mask narrow
def sign (narrow : Bool) : BitVec 64 := if narrow then 2147483648 else BitVec.ofInt 64 (-9223372036854775808)
def left (lhs : BitVec 64) (narrow : Bool) : BitVec 64 := lhs &&& mask narrow
def right (rhs : BitVec 64) (narrow : Bool) : BitVec 64 := rhs &&& mask narrow
def result (lhs rhs : BitVec 64) (narrow : Bool) : BitVec 64 :=
  (left lhs narrow - right rhs narrow) &&& mask narrow

def readyTemps (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  (((((((le.set Arm64Program._t'111 (.Vlong (mask narrow))).set
    Arm64Program._t'111 (.Vlong (mask narrow))).set Arm64Program._t'111 (.Vlong (mask narrow))).set
    Arm64Program.___kprog_a64_sub_mask__4 (.Vlong (mask narrow))).set
    Arm64Program._t'112 (.Vlong (sign narrow))).set Arm64Program._t'112 (.Vlong (sign narrow))).set
    Arm64Program._t'112 (.Vlong (sign narrow))).set Arm64Program.___kprog_a64_sub_sign__4 (.Vlong (sign narrow))
def temps (le : CC.TempEnv) (lhs rhs : BitVec 64) (narrow : Bool) : CC.TempEnv :=
  (((readyTemps le narrow).set Arm64Program.___kprog_a64_sub_lhs__4 (.Vlong (left lhs narrow))).set
    Arm64Program.___kprog_a64_sub_rhs__4 (.Vlong (right rhs narrow))).set
    Arm64Program.___kprog_a64_sub_res__4 (.Vlong (result lhs rhs narrow))

set_option hygiene false in
private theorem enter (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 5 (.State Arm64Nop.handler RhsCall.flags k e le m)
      (.State Arm64Nop.handler subBody (continuation k) e le m) := by
  have selected : CC.Step2 world
      (.State Arm64Nop.handler (.Sswitch selector cases)
        (.Kloop1 (.Sswitch selector cases) .Sbreak k) e le m) CC.E0
      (.State Arm64Nop.handler (.Ssequence arm dead)
        (.Kswitch (.Kloop1 (.Sswitch selector cases) .Sbreak k)) e le m) := by
    rw [← select_source]
    apply CC.Step.switch (v := .Vint (1#32)) (n := 1)
    · apply CC.doEvalExpr_sound
      rfl
    · rfl
  apply InternalRun.step
  · trivial
  · apply CC.doStep_sound
    simp only [loop_source, CC.doStep]
    rfl
  apply InternalRun.step
  · trivial
  · exact selected
  run_tac do
    for _ in [:3] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep, arm_source, continuation] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

set_option hygiene false in
private theorem prepare (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (narrow : Bool)
    (hw : le.get Arm64Program.___a64_l_width = some (RhsCall.width narrow)) :
    InternalRun world 30 (.State Arm64Nop.handler subBody k e le m)
      (.State Arm64Nop.handler arithmetic k e (readyTemps le narrow) m) := by
  cases narrow <;>
  run_tac do
    for _ in [:30] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [sub_source, maskCode, signCode,
        Arm64Program.s_kprog_arm64_program_execute_87, Arm64Program.s_kprog_arm64_program_execute_88,
        Arm64Program.s_kprog_arm64_program_execute_89, Arm64Program.s_kprog_arm64_program_execute_90,
        readyTemps, mask, sign, Arm64Modified.Modifier.mask, hw, RhsCall.width,
        Arm64Compare.Dispatch.flags, Arm64Width.argument, CC.doStep, CC.doEvalExpr, CC.typeof, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,         CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
        CC.Cop.semBinaryOperation, CC.Cop.semSub, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
    CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
        CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
        CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
        CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
        CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
        CC.Integers.MI.zero, CC.Integers.MI.one,
        BitVec.shiftLeft_zero, BitVec.and_allOnes,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private def lhsExpr : CC.Expr := by
  run_tac do
    let code ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(lhsCode)) none))
    unless code.isAppOfArity ``CC.Stmt.Sset 2 do throwError "actual CMP arithmetic assignment changed"
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_expression code.getAppArgs[1]!
private def rhsExpr : CC.Expr := by
  run_tac do
    let code ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(rhsCode)) none))
    unless code.isAppOfArity ``CC.Stmt.Sset 2 do throwError "actual CMP arithmetic assignment changed"
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_expression code.getAppArgs[1]!
private def resultExpr : CC.Expr := by
  run_tac do
    let code ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(resultCode)) none))
    unless code.isAppOfArity ``CC.Stmt.Sset 2 do throwError "actual CMP arithmetic assignment changed"
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_expression code.getAppArgs[1]!

set_option hygiene false in
private theorem assign_run (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (id : CC.Ident) (expr : CC.Expr) (next : CC.Stmt) (value : CC.Val)
    (evaluated : CC.doEvalExpr world e le m expr = some value) :
    InternalRun world 3 (.State Arm64Nop.handler (.Ssequence (.Sset id expr) next) k e le m)
      (.State Arm64Nop.handler next k e (le.set id value) m) := by
  run_tac do
    for i in [:3] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 1 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.Step.set))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doEvalExpr_sound; exact evaluated))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private theorem calculate (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (lhs rhs : BitVec 64) (narrow : Bool)
    (hl : le.get Arm64Program.___a64_l_lhs__4 = some (.Vlong lhs))
    (hr : le.get Arm64Program.___a64_l_rhs__4 = some (.Vlong rhs)) :
    InternalRun world 9 (.State Arm64Nop.handler arithmetic k e (readyTemps le narrow) m)
      (.State Arm64Nop.handler stores k e (temps le lhs rhs narrow) m) := by
  let le0 := readyTemps le narrow
  let le1 := le0.set Arm64Program.___kprog_a64_sub_lhs__4 (.Vlong (left lhs narrow))
  let le2 := le1.set Arm64Program.___kprog_a64_sub_rhs__4 (.Vlong (right rhs narrow))
  have reads :
      le0.get Arm64Program.___a64_l_lhs__4 = some (.Vlong lhs) ∧
      le1.get Arm64Program.___a64_l_rhs__4 = some (.Vlong rhs) ∧
      le0.get Arm64Program.___kprog_a64_sub_mask__4 = some (.Vlong (mask narrow)) ∧
      le1.get Arm64Program.___kprog_a64_sub_mask__4 = some (.Vlong (mask narrow)) ∧
      le2.get Arm64Program.___kprog_a64_sub_lhs__4 = some (.Vlong (left lhs narrow)) ∧
      le2.get Arm64Program.___kprog_a64_sub_rhs__4 = some (.Vlong (right rhs narrow)) ∧
      le2.get Arm64Program.___kprog_a64_sub_mask__4 = some (.Vlong (mask narrow)) := by
    dsimp only [le0, le1, le2, readyTemps]
    refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_⟩
    all_goals
      repeat first
        | rw [CC.PTree.gss]
        | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    · exact hl
    · exact hr
  obtain ⟨hleft, hright, hm0, hm1, ha, hb, hm2⟩ := reads
  have evalLeft : CC.doEvalExpr world e le0 m lhsExpr = some (.Vlong (left lhs narrow)) := by
    simp only [lhsExpr, CC.doEvalExpr, hleft, hm0, CC.typeof]
    rfl
  have evalRight : CC.doEvalExpr world e le1 m rhsExpr = some (.Vlong (right rhs narrow)) := by
    simp only [rhsExpr, CC.doEvalExpr, hright, hm1, CC.typeof]
    rfl
  have evalResult : CC.doEvalExpr world e le2 m resultExpr = some (.Vlong (result lhs rhs narrow)) := by
    simp only [resultExpr, CC.doEvalExpr, ha, hb, hm2, CC.typeof]
    rfl
  have leftRun := assign_run world e le0 m k Arm64Program.___kprog_a64_sub_lhs__4 lhsExpr
    (.Ssequence rhsCode (.Ssequence resultCode stores)) (.Vlong (left lhs narrow)) evalLeft
  have rightRun := assign_run world e le1 m k Arm64Program.___kprog_a64_sub_rhs__4 rhsExpr
    (.Ssequence resultCode stores) (.Vlong (right rhs narrow)) evalRight
  have resultRun := assign_run world e le2 m k Arm64Program.___kprog_a64_sub_res__4 resultExpr
    stores (.Vlong (result lhs rhs narrow)) evalResult
  exact (leftRun.trans rightRun).trans resultRun

/-- Execute the actual SUB-family selector and W/X arithmetic, reaching the
original four flag stores without changing the heap, locals or caller. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (lhs rhs : BitVec 64) (narrow : Bool)
    (hw : le.get Arm64Program.___a64_l_width = some (RhsCall.width narrow))
    (hl : le.get Arm64Program.___a64_l_lhs__4 = some (.Vlong lhs))
    (hr : le.get Arm64Program.___a64_l_rhs__4 = some (.Vlong rhs)) :
    InternalRun world 44 (.State Arm64Nop.handler RhsCall.flags k e le m)
      (.State Arm64Nop.handler stores (continuation k) e (temps le lhs rhs narrow) m) := by
  exact ((enter world e le m k).trans (prepare world e le m (continuation k) narrow hw)).trans
    (calculate world e le m (continuation k) lhs rhs narrow hl hr)

/-- All five operands consumed by the pending original flag stores are derived
from the exact eleven source temporary writes. -/
theorem values (le : CC.TempEnv) (lhs rhs : BitVec 64) (narrow : Bool) :
    (temps le lhs rhs narrow).get Arm64Program.___kprog_a64_sub_mask__4 = some (.Vlong (mask narrow)) ∧
    (temps le lhs rhs narrow).get Arm64Program.___kprog_a64_sub_sign__4 = some (.Vlong (sign narrow)) ∧
    (temps le lhs rhs narrow).get Arm64Program.___kprog_a64_sub_lhs__4 = some (.Vlong (left lhs narrow)) ∧
    (temps le lhs rhs narrow).get Arm64Program.___kprog_a64_sub_rhs__4 = some (.Vlong (right rhs narrow)) ∧
    (temps le lhs rhs narrow).get Arm64Program.___kprog_a64_sub_res__4 = some (.Vlong (result lhs rhs narrow)) := by
  dsimp only [temps, readyTemps]
  refine ⟨?_, ?_, ?_, ?_, ?_⟩
  all_goals
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

end KProgFormal.ClightRefinement.Arm64Compare.Math
