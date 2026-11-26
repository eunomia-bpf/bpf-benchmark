import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpFlags

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpGt

def taken (s : Reference.AArch64.State) (lhs rhs : BitVec 64) : Bool :=
  ConditionHolds (12#4) (Arm64ProgramEntryCmpFlags.native s lhs rhs).machine

/-- Reuse the imported model's signed-GT subtraction theorem for arbitrary
full64 operands; no numerical instruction semantics are introduced here. -/
theorem signed_gt (s : Reference.AArch64.State) (lhs rhs : BitVec 64) :
    decide (rhs.toInt < lhs.toInt) = taken s lhs rhs := by
  have imported := sgt_iff_n_eq_v_and_z_eq_0_64 lhs rhs
  have reduced : taken s lhs rhs = decide
      ((AddWithCarry lhs (~~~rhs) (1#1)).snd.n = (AddWithCarry lhs (~~~rhs) (1#1)).snd.v ∧
       (AddWithCarry lhs (~~~rhs) (1#1)).snd.z = 0#1) := by
    simp +decide [taken,ConditionHolds,Arm64ProgramEntryCmpFlags.native,write_pstate,read_flag,
      r_of_w_same,r_of_w_different]
  rw [reduced]
  apply Bool.eq_iff_iff.mpr
  simpa only [BitVec.slt_eq_decide,decide_eq_true_eq] using imported.symm

private structure Parts where
  narrow : CC.Stmt
  wide : CC.Stmt
  rejected : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original signed CMP choice changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCmpBranch.choice)) none)
    let inner ← peel outer[2]!
    Lean.Elab.Tactic.closeMainGoal `actual_signed_cmp_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[1]!,inner[1]!,inner[2]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_signed_cmp_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def narrow : CC.Stmt := by run_tac cachePart (← `(parts.narrow))
def wide : CC.Stmt := by run_tac cachePart (← `(parts.wide))
private def rejected : CC.Stmt := by run_tac cachePart (← `(parts.rejected))
private def widthIs (n : BitVec 32) : CC.Expr := .Ebinop .Oeq
  (.Etempvar Arm64ProgramFixture.___a64_cmp_width CC.tuchar) (.Econst_int n CC.tuint) CC.tint

theorem choice_source : Arm64ProgramEntryCmpBranch.choice =
    .Sifthenelse (widthIs 4) narrow (.Sifthenelse (widthIs 8) wide rejected) := rfl
private def comparison : CC.Expr := .Ebinop .Ogt
  (.Ecast (.Etempvar Arm64ProgramFixture.___a64_cmp_lhs CC.tulong) CC.tlong)
  (.Ecast (.Etempvar Arm64ProgramFixture.___a64_cmp_rhs CC.tulong) CC.tlong) CC.tint
theorem wide_source : wide = .Sifthenelse comparison (.Sgoto Arm64ProgramFixture._cmp_taken) .Sskip := rfl

/-- The true source signed64 casts and Ogt evaluate to the imported GT test. -/
theorem comparison_eval (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (s : Reference.AArch64.State) (lhs rhs : BitVec 64)
    (hl : le.get Arm64ProgramFixture.___a64_cmp_lhs = some (.Vlong lhs))
    (hr : le.get Arm64ProgramFixture.___a64_cmp_rhs = some (.Vlong rhs)) :
    CC.doEvalExpr world e le m comparison = some (CC.Val.ofBool (taken s lhs rhs)) := by
  have left : CC.doEvalExpr world e le m
      (.Ecast (.Etempvar Arm64ProgramFixture.___a64_cmp_lhs CC.tulong) CC.tlong) = some (.Vlong lhs) := by
    simp only [CC.doEvalExpr,hl]
    rfl
  have right : CC.doEvalExpr world e le m
      (.Ecast (.Etempvar Arm64ProgramFixture.___a64_cmp_rhs CC.tulong) CC.tlong) = some (.Vlong rhs) := by
    simp only [CC.doEvalExpr,hr]
    rfl
  have binary : CC.Cop.semBinaryOperation world.genv_cenv .Ogt (.Vlong lhs) CC.tlong
      (.Vlong rhs) CC.tlong m = some (CC.Val.ofBool (taken s lhs rhs)) := by
    change some (CC.Val.ofBool (decide (rhs.toInt < lhs.toInt))) = _
    rw [signed_gt s lhs rhs]
  rw [comparison,CC.doEvalExpr,left,right]
  exact binary

set_option hygiene false in
private theorem width_prefix (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hw : le.get Arm64ProgramFixture.___a64_cmp_width = some (.Vint 8)) :
    InternalRun world 2
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpBranch.choice k e le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile wide k e le m) := by
  run_tac do
    for _ in [:2] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [choice_source,widthIs,CC.doStep,CC.doEvalExpr,
        hw,CC.typeof,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,
        CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,
        CC.tuchar,CC.tuint,CC.tint,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
        CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.eq,CC.Integers.MI.eq,
        CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
        CC.Integers.Int.repr,CC.Integers.MI.repr,ite_true,ite_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- All three actual width/GT source choices select their true goto or skip,
using the imported condition on the already-derived subtraction flags. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (s : Reference.AArch64.State) (lhs rhs : BitVec 64)
    (hw : le.get Arm64ProgramFixture.___a64_cmp_width = some (.Vint 8))
    (hl : le.get Arm64ProgramFixture.___a64_cmp_lhs = some (.Vlong lhs))
    (hr : le.get Arm64ProgramFixture.___a64_cmp_rhs = some (.Vlong rhs)) :
    InternalRun world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpBranch.choice k e le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (if taken s lhs rhs then .Sgoto Arm64ProgramFixture._cmp_taken else .Sskip) k e le m) := by
  have choose : CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile wide k e le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (if taken s lhs rhs then .Sgoto Arm64ProgramFixture._cmp_taken else .Sskip) k e le m) := by
    rw [wide_source]
    apply CC.Step.ifthenelse (v1 := CC.Val.ofBool (taken s lhs rhs)) (b := taken s lhs rhs)
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ (comparison_eval world e le m s lhs rhs hl hr)
    · cases taken s lhs rhs <;> rfl
  exact (width_prefix world e le m k hw).trans (.step (by rw [wide_source]; trivial) choose (.refl _))

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpGt
