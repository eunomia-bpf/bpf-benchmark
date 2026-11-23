import Lean
import KProgFormal.ClightRefinement.X86ShiftLeftSite

namespace KProgFormal.ClightRefinement.X86ShiftLeftRoute

private structure Pieces where
  initialWidth : CC.Stmt
  p0 : CC.Stmt
  p1 : CC.Stmt
  p2 : CC.Stmt
  p3 : CC.Stmt
  p4 : CC.Stmt
  p5 : CC.Stmt
  p6 : CC.Stmt
  p7 : CC.Stmt
  dispatch : CC.Stmt
  innerExit : CC.Stmt
  outerExit : CC.Stmt

private def pieces : Pieces :=
  match X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_body with
  | (.Sloop (.Ssequence initialWidth (.Sloop (.Ssequence p0 (.Ssequence p1 (.Ssequence p2 (.Ssequence p3 (.Ssequence p4 (.Ssequence p5 (.Ssequence p6 (.Ssequence p7 selected)))))))) innerExit)) outerExit) => ⟨initialWidth, p0, p1, p2, p3, p4, p5, p6, p7, selected, innerExit, outerExit⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private structure Gates where
  sbbTest : CC.Expr
  sbbBody : CC.Stmt
  adcTest : CC.Expr
  adcBody : CC.Stmt

private def gates : Gates :=
  match pieces.dispatch with
  | .Sifthenelse a b (.Sifthenelse c d _) => ⟨a, b, c, d⟩
  | _ => ⟨.Econst_int (0#32) CC.tint, .Sskip, .Econst_int (0#32) CC.tint, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_alu_reg_route_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def sbbTest : CC.Expr := by run_tac cachePart (← `(gates.sbbTest))
private def sbbBody : CC.Stmt := by run_tac cachePart (← `(gates.sbbBody))
private def adcTest : CC.Expr := by run_tac cachePart (← `(gates.adcTest))
private def adcBody : CC.Stmt := by run_tac cachePart (← `(gates.adcBody))

def flags : CC.Stmt := X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_113

private def adcGate : CC.Stmt :=
  .Sifthenelse adcTest adcBody
    (.Ssequence X86ShiftLeftSite.statement flags)

def dispatch : CC.Stmt := .Sifthenelse sbbTest sbbBody adcGate

def body : CC.Stmt :=
  .Sloop (.Ssequence pieces.initialWidth
    (.Sloop ([pieces.p0, pieces.p1, pieces.p2, pieces.p3, pieces.p4, pieces.p5, pieces.p6, pieces.p7].foldr .Ssequence dispatch)
      pieces.innerExit)) pieces.outerExit

/-- The routed statement is extracted from the actual complete ALU_REG body. -/
theorem body_source : X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG.fn_body = body := rfl

/-- Logical operations and SHL pass the actual SBB/ADC gates and reach
the original shared arithmetic statement with its real flag continuation. -/
theorem select_arithmetic (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (code : BitVec 8)
    (supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8) ∨ code = (5#8))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32))) :
    InternalRun ge 3 (.State function dispatch k e le m)
      (.State function X86ShiftLeftSite.statement (.Kseq flags k) e le m) := by
  have tested : CC.doEvalExpr ge e le m sbbTest = some (.Vint (0#32)) ∧
      CC.doEvalExpr ge e le m adcTest = some (.Vint (0#32)) := by
    constructor <;> rcases supported with rfl | rfl | rfl | rfl
    all_goals simp +decide [sbbTest, adcTest, CC.doEvalExpr, CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Val.ofBool, CC.Integers.Int.repr,
      CC.Integers.MI.repr, operation]
  have sbbType : CC.typeof sbbTest = CC.tint := rfl
  have adcType : CC.typeof adcTest = CC.tint := rfl
  have falseInt : CC.Cop.boolVal (.Vint (0#32)) CC.tint m = some false := rfl
  have first : CC.doStep ge (.State function dispatch k e le m) =
      some (CC.E0, .State function adcGate k e le m) := by
    simp only [dispatch, CC.doStep, tested.1, sbbType, falseInt]
    rfl
  have second : CC.doStep ge (.State function adcGate k e le m) =
      some (CC.E0, .State function
        (.Ssequence X86ShiftLeftSite.statement flags) k e le m) := by
    simp only [adcGate, CC.doStep, tested.2, adcType, falseInt]
    rfl
  have third : CC.doStep ge (.State function
      (.Ssequence X86ShiftLeftSite.statement flags) k e le m) =
      some (CC.E0, .State function X86ShiftLeftSite.statement (.Kseq flags k) e le m) := rfl
  exact .step (by trivial) (CC.doStep_sound ge _ _ _ first)
    (.step (by trivial) (CC.doStep_sound ge _ _ _ second)
      (.step (by trivial) (CC.doStep_sound ge _ _ _ third) (.refl _)))

/-- SHL uses the shared checked source route. -/
theorem select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 3 (.State function dispatch k e le m)
      (.State function X86ShiftLeftSite.statement (.Kseq flags k) e le m) :=
  select_arithmetic ge function e le k m (5#8) (.inr (.inr (.inr rfl))) operation

/-- Actual routing, arithmetic call and resume reach the untouched flag stage
with the mature SHL result in the exact source temporary map. -/
theorem to_flags (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (shiftBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some shiftBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv shiftBlock =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_alu_result = none)
    (lhs rhs : BitVec 64) (size : X86.Size)
    (left : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge (3 + X86ShiftLeftSite.length size + 1)
      (.State function dispatch k e le m)
      (.State function flags k e
        (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size)) m) := by
  have arithmetic := X86ShiftLeftSite.internal ge aluBlock shiftBlock binding shiftBinding function e le unshadowed lhs rhs size left right operation width (.Kseq flags k) m
  have resume : InternalRun ge 1
      (.State function .Sskip (.Kseq flags k) e
        (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size)) m)
      (.State function flags k e
        (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size)) m) := by
    apply internalRun_of_steps
    · simp [InternalPath, InternalState, CC.doStep]
    · simp [steps, CC.doStep, CC.Eapp, CC.E0]
  exact ((select ge function e le k m operation).trans arithmetic).trans resume

/-- The relational route preserves the complete memory, caller locals and continuation. -/
theorem returns (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (shiftBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some shiftBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv shiftBlock =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_alu_result = none)
    (lhs rhs : BitVec 64) (size : X86.Size)
    (left : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (k : CC.Cont) (m : CC.Mem) :
    CC.Star (CC.Step2 ge) (.State function dispatch k e le m) CC.E0
      (.State function flags k e
        (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size)) m) :=
  (to_flags ge aluBlock shiftBlock binding shiftBinding function e le unshadowed lhs rhs size left right operation width k m).sound

end KProgFormal.ClightRefinement.X86ShiftLeftRoute
