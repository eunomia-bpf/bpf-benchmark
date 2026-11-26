import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpBranch
import KProgFormal.ClightRefinement.Arm64CompareFlagArithmetic
import KProgFormal.ClightRefinement.Arm64CompareMath

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpArithmetic
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_fixture_cmp_math_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private structure Parts where
  body : CC.Stmt
  mask : CC.Stmt
  sign : CC.Stmt
  lhs : CC.Stmt
  rhs : CC.Stmt
  result : CC.Stmt
  stores : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original inline CMP arithmetic source changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCmpBranch.arithmetic)) none) ``CC.Stmt.Sloop 2
    let mask ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let sign ← peel mask[1]! ``CC.Stmt.Ssequence 2
    let lhs ← peel sign[1]! ``CC.Stmt.Ssequence 2
    let rhs ← peel lhs[1]! ``CC.Stmt.Ssequence 2
    let result ← peel rhs[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_fixture_cmp_math_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,mask[0]!,sign[0]!,lhs[0]!,rhs[0]!,result[0]!,result[1]!])
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def maskCode : CC.Stmt := by run_tac cachePart (← `(parts.mask))
private def signCode : CC.Stmt := by run_tac cachePart (← `(parts.sign))
private def lhsCode : CC.Stmt := by run_tac cachePart (← `(parts.lhs))
private def rhsCode : CC.Stmt := by run_tac cachePart (← `(parts.rhs))
private def resultCode : CC.Stmt := by run_tac cachePart (← `(parts.result))
def stores : CC.Stmt := by run_tac cachePart (← `(parts.stores))
def arithmetic : CC.Stmt := .Ssequence lhsCode (.Ssequence rhsCode (.Ssequence resultCode stores))
theorem loop_source : Arm64ProgramEntryCmpBranch.arithmetic = .Sloop body .Sbreak := rfl
private theorem sub_source : body = .Ssequence maskCode (.Ssequence signCode arithmetic) := rfl
theorem stores_source : stores = Arm64ProgramFixture.s_arm64_execute_compile_56 := rfl
def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

abbrev mask := Arm64Compare.Math.mask
abbrev sign := Arm64Compare.Math.sign
abbrev left := Arm64Compare.Math.left
abbrev right := Arm64Compare.Math.right
abbrev result := Arm64Compare.Math.result

def readyTemps (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  (((((((le.set Arm64ProgramFixture._t'146 (.Vlong (mask narrow))).set
    Arm64ProgramFixture._t'146 (.Vlong (mask narrow))).set Arm64ProgramFixture._t'146 (.Vlong (mask narrow))).set
    Arm64ProgramFixture.___kprog_a64_sub_mask (.Vlong (mask narrow))).set
    Arm64ProgramFixture._t'147 (.Vlong (sign narrow))).set Arm64ProgramFixture._t'147 (.Vlong (sign narrow))).set
    Arm64ProgramFixture._t'147 (.Vlong (sign narrow))).set Arm64ProgramFixture.___kprog_a64_sub_sign (.Vlong (sign narrow))
def temps (le : CC.TempEnv) (lhs rhs : BitVec 64) (narrow : Bool) : CC.TempEnv :=
  (((readyTemps le narrow).set Arm64ProgramFixture.___kprog_a64_sub_lhs (.Vlong (left lhs narrow))).set
    Arm64ProgramFixture.___kprog_a64_sub_rhs (.Vlong (right rhs narrow))).set
    Arm64ProgramFixture.___kprog_a64_sub_res (.Vlong (result lhs rhs narrow))

set_option hygiene false in
private theorem prepare (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (narrow : Bool)
    (hw : le.get Arm64ProgramFixture.___a64_cmp_width = some (Arm64Compare.RhsCall.width narrow)) :
    InternalRun world 30 (.State Arm64ProgramFixture.f_arm64_execute_compile body k e le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile arithmetic k e (readyTemps le narrow) m) := by
  cases narrow <;>
  run_tac do
    for _ in [:30] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [sub_source, maskCode, signCode,
        Arm64ProgramFixture.s_arm64_execute_compile_51, Arm64ProgramFixture.s_arm64_execute_compile_52,
        Arm64ProgramFixture.s_arm64_execute_compile_53, Arm64ProgramFixture.s_arm64_execute_compile_54,
        readyTemps, mask, sign, Arm64Modified.Modifier.mask, hw, Arm64Compare.RhsCall.width,
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
    InternalRun world 3 (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence (.Sset id expr) next) k e le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile next k e (le.set id value) m) := by
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
    (hl : le.get Arm64ProgramFixture.___a64_cmp_lhs = some (.Vlong lhs))
    (hr : le.get Arm64ProgramFixture.___a64_cmp_rhs = some (.Vlong rhs)) :
    InternalRun world 9 (.State Arm64ProgramFixture.f_arm64_execute_compile arithmetic k e (readyTemps le narrow) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile stores k e (temps le lhs rhs narrow) m) := by
  let le0 := readyTemps le narrow
  let le1 := le0.set Arm64ProgramFixture.___kprog_a64_sub_lhs (.Vlong (left lhs narrow))
  let le2 := le1.set Arm64ProgramFixture.___kprog_a64_sub_rhs (.Vlong (right rhs narrow))
  have reads :
      le0.get Arm64ProgramFixture.___a64_cmp_lhs = some (.Vlong lhs) ∧
      le1.get Arm64ProgramFixture.___a64_cmp_rhs = some (.Vlong rhs) ∧
      le0.get Arm64ProgramFixture.___kprog_a64_sub_mask = some (.Vlong (mask narrow)) ∧
      le1.get Arm64ProgramFixture.___kprog_a64_sub_mask = some (.Vlong (mask narrow)) ∧
      le2.get Arm64ProgramFixture.___kprog_a64_sub_lhs = some (.Vlong (left lhs narrow)) ∧
      le2.get Arm64ProgramFixture.___kprog_a64_sub_rhs = some (.Vlong (right rhs narrow)) ∧
      le2.get Arm64ProgramFixture.___kprog_a64_sub_mask = some (.Vlong (mask narrow)) := by
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
  have leftRun := assign_run world e le0 m k Arm64ProgramFixture.___kprog_a64_sub_lhs lhsExpr
    (.Ssequence rhsCode (.Ssequence resultCode stores)) (.Vlong (left lhs narrow)) evalLeft
  have rightRun := assign_run world e le1 m k Arm64ProgramFixture.___kprog_a64_sub_rhs rhsExpr
    (.Ssequence resultCode stores) (.Vlong (right rhs narrow)) evalRight
  have resultRun := assign_run world e le2 m k Arm64ProgramFixture.___kprog_a64_sub_res resultExpr
    stores (.Vlong (result lhs rhs narrow)) evalResult
  exact (leftRun.trans rightRun).trans resultRun

/-- Execute the actual original inline SUB arithmetic, retaining all four
original local flag stores as pending source and the entire incoming heap. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (lhs rhs : BitVec 64) (narrow : Bool)
    (hw : le.get Arm64ProgramFixture.___a64_cmp_width = some (Arm64Compare.RhsCall.width narrow))
    (hl : le.get Arm64ProgramFixture.___a64_cmp_lhs = some (.Vlong lhs))
    (hr : le.get Arm64ProgramFixture.___a64_cmp_rhs = some (.Vlong rhs)) :
    InternalRun world 40 (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpBranch.arithmetic k e le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile stores (continuation k) e (temps le lhs rhs narrow) m) := by
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpBranch.arithmetic k e le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile body (continuation k) e le m) := by
    apply InternalRun.step
    · trivial
    · apply CC.doStep_sound
      simp only [loop_source,continuation,CC.doStep]
      rfl
    · exact .refl _
  exact (enter.trans (prepare world e le m (continuation k) narrow hw)).trans
    (calculate world e le m (continuation k) lhs rhs narrow hl hr)

/-- Full64 C masks return the exact imported AddWithCarry subtraction result. -/
theorem wide_native_result (lhs rhs : BitVec 64) :
    result lhs rhs false = (AddWithCarry lhs (~~~rhs) (1#1)).fst := by
  rw [Arm64Compare.FlagArithmetic.subtraction]
  have all : BitVec.ofInt 64 (-1) = BitVec.allOnes 64 := by decide +kernel
  simp only [result,left,right,mask,Arm64Compare.Math.result,Arm64Compare.Math.left,
    Arm64Compare.Math.right,Arm64Compare.Math.mask,Arm64Modified.Modifier.mask,Bool.false_eq_true,ite_false,
    all,BitVec.and_allOnes]

/-- All five operands consumed by the pending original flag stores are derived
from the exact eleven source temporary writes. -/
theorem values (le : CC.TempEnv) (lhs rhs : BitVec 64) (narrow : Bool) :
    (temps le lhs rhs narrow).get Arm64ProgramFixture.___kprog_a64_sub_mask = some (.Vlong (mask narrow)) ∧
    (temps le lhs rhs narrow).get Arm64ProgramFixture.___kprog_a64_sub_sign = some (.Vlong (sign narrow)) ∧
    (temps le lhs rhs narrow).get Arm64ProgramFixture.___kprog_a64_sub_lhs = some (.Vlong (left lhs narrow)) ∧
    (temps le lhs rhs narrow).get Arm64ProgramFixture.___kprog_a64_sub_rhs = some (.Vlong (right rhs narrow)) ∧
    (temps le lhs rhs narrow).get Arm64ProgramFixture.___kprog_a64_sub_res = some (.Vlong (result lhs rhs narrow)) := by
  dsimp only [temps, readyTemps]
  refine ⟨?_, ?_, ?_, ?_, ?_⟩
  all_goals
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpArithmetic
