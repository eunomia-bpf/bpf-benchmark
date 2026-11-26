import KProgFormal.ClightRefinement.Arm64ProgramEntryLinked
import KProgFormal.ClightRefinement.InternalExecution
import KProgFormal.Reference.AArch64

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64BranchBit63

abbrev handler := Arm64Numeric.f_kprog_arm64_branch_test

def instruction : Test_branch_cls := { b5 := 1, op := 1, b40 := 31, imm14 := (-8#14), Rt := 4 }
def taken (s : Reference.AArch64.State) : Bool := BR.Test_branch_inst.condition_holds instruction s.machine

/-- The original C shift/mask observes the same bit as the imported ISA reader. -/
theorem masked_bit (value : BitVec 64) :
    ((value >>> 63) &&& (1#64)) = (BitVec.ofBool (value.getLsbD 63)).setWidth 64 := by
  apply BitVec.eq_of_getLsbD_eq
  intro i
  by_cases atZero : i = 0 <;>
    simp [atZero,BitVec.getLsbD_and,BitVec.getLsbD_ushiftRight,BitVec.getLsbD_setWidth,BitVec.getLsbD_ofBool]

theorem condition_value (s : Reference.AArch64.State) (value : BitVec 64)
    (native : Reference.AArch64.gpr s 4 = value) :
    (!(((value >>> 63) &&& (1#64)) == (0#64))) = taken s := by
  have read : read_gpr 64 (4#5) s.machine = value := by
    change (r (.GPR (4#5)) s.machine).setWidth 64 = value
    rw [BitVec.setWidth_eq]
    change Reference.AArch64.gpr s 4 = value
    exact native
  have actual : taken s = value.getLsbD 63 := by
    change ((read_gpr 64 (4#5) s.machine).getLsbD 63 == true) = value.getLsbD 63
    rw [read]
    cases value.getLsbD 63 <;> rfl
  rw [actual,masked_bit]
  cases value.getLsbD 63 <;> rfl

private def body : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none
    Lean.Elab.Tactic.closeMainGoal `actual_branch_bit63_body (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private theorem body_source : handler.fn_body = body := rfl
private theorem return_type : handler.fn_return = CC.tint := rfl
private theorem empty_elements : (CC.PTree.empty : CC.Env).elements = [] := rfl

def arguments (value : BitVec 64) : List CC.Val := [.Vlong 3,.Vlong value,.Vlong 63]
def temps (value : BitVec 64) : CC.TempEnv :=
  (((CC.createUndefTemps handler.fn_temps).set Arm64Numeric._kind (.Vlong 3)).set
    Arm64Numeric._value (.Vlong value)).set Arm64Numeric._bit (.Vlong 63)

theorem enter (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 1 (.Callstate (.Internal handler) (arguments value) k m)
      (.State handler body k CC.emptyEnv (temps value) m) := by
  have entry : CC.FunctionEntry2 world handler (arguments value) m CC.emptyEnv (temps value) m :=
    .intro (by decide +kernel) (by decide +kernel) (by decide +kernel) (.nil _ _) rfl
  rw [← body_source]
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entry) (.refl _)

private def comparison : CC.Stmt := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original branch bit63 comparison changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(body)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel root[0]! ``CC.Stmt.Sloop 2
    let mut rest := loop[0]!
    for _ in [:4] do
      let seq ← peel rest ``CC.Stmt.Ssequence 2
      rest := seq[1]!
    let pair ← peel rest ``CC.Stmt.Ssequence 2
    let switch ← peel pair[0]! ``CC.Stmt.Sswitch 2
    let mut row := switch[1]!
    for _ in [:3] do
      let label ← peel row ``CC.LStmts.LScons 3
      row := label[2]!
    let label ← peel row ``CC.LStmts.LScons 3
    let selected ← peel label[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_branch_bit63_comparison selected[0]!
private def shiftExpr : CC.Expr := .Ebinop .Oshr
  (.Etempvar Arm64Numeric.___kprog_a64_br_value CC.tulong)
  (.Etempvar Arm64Numeric.___kprog_a64_br_bit CC.tulong) CC.tulong
private def maskExpr : CC.Expr := .Ebinop .Oand shiftExpr (.Econst_long (1#64) CC.tulong) CC.tulong
private theorem comparison_source : comparison = .Sset Arm64Numeric.___kprog_a64_br_taken
    (.Ebinop .One maskExpr (.Econst_int 0 CC.tint) CC.tint) := rfl

private theorem comparison_step (world : CC.CGenv) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (value : BitVec 64) (s : Reference.AArch64.State)
    (read : le.get Arm64Numeric.___kprog_a64_br_value = some (.Vlong value))
    (bit : le.get Arm64Numeric.___kprog_a64_br_bit = some (.Vlong (63#64)))
    (equal : (!(((value >>> 63) &&& (1#64)) == (0#64))) = taken s) :
    CC.Step2 world (.State handler comparison k CC.emptyEnv le m) CC.E0
      (.State handler .Sskip k CC.emptyEnv
        (le.set Arm64Numeric.___kprog_a64_br_taken (.Vint (if taken s then 1#32 else 0#32))) m) := by
  have shifted : CC.doEvalExpr world CC.emptyEnv le m shiftExpr = some (.Vlong (value >>> 63)) := by
    simp only [shiftExpr,CC.doEvalExpr,read,bit]
    rfl
  have masked : CC.doEvalExpr world CC.emptyEnv le m maskExpr = some (.Vlong ((value >>> 63) &&& (1#64))) := by
    simp only [maskExpr,CC.doEvalExpr,shifted]
    rfl
  have binary : CC.Cop.semBinaryOperation world.genv_cenv .One (.Vlong ((value >>> 63) &&& (1#64))) CC.tulong
      (.Vint 0) CC.tint m = some (.Vint (if taken s then 1#32 else 0#32)) := by
    change some (CC.Val.ofBool (!(((value >>> 63) &&& (1#64)) == (0#64)))) = _
    rw [equal]
    cases taken s <;> rfl
  rw [comparison_source]
  apply CC.Step.set
  apply CC.doEvalExpr_sound
  rw [CC.doEvalExpr,masked]
  exact binary

set_option hygiene false in
/-- The complete original Numeric op3 function refines the imported 64-bit
test-branch condition and returns on the same arbitrary heap. -/
theorem execute (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem)
    (s : Reference.AArch64.State) (native : Reference.AArch64.gpr s 4 = value) :
    ∃ count, InternalRun world count (.Callstate (.Internal handler) (arguments value) k m)
      (.Returnstate (.Vint (if taken s then 1#32 else 0#32)) (CC.callCont k) m) := by
  suffices rest : ∃ count, InternalRun world count (.State handler body k CC.emptyEnv (temps value) m)
      (.Returnstate (.Vint (if taken s then 1#32 else 0#32)) (CC.callCont k) m) by
    obtain ⟨count,run⟩ := rest
    exact ⟨_,(enter world value k m).trans run⟩
  have equal := condition_value s value native
  refine ⟨?count,?execution⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:80] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.Returnstate 3 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual branch-test op3 transitions including entry: {i+1}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf state.getAppArgs[1]!)
        let mut compare := false
        if stmt.isAppOfArity ``CC.Stmt.Sset 2 then
          let rhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
          if rhs.isAppOfArity ``CC.Expr.Ebinop 4 then
            compare := rhs.getAppArgs[0]!.isConstOf ``CC.Binop.One
        if compare then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply comparison_step _ _ _ _ value s _ _ equal))
          Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [temps,CC.PTree.gss,CC.PTree.gso,CC.Integers.Int64.and,CC.Integers.MI.and] <;> rfl))
          Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [temps,CC.PTree.gss,CC.PTree.gso,CC.Integers.Int64.and,CC.Integers.MI.and] <;> rfl))
          continue
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [body,CC.doStep,CC.doEvalExpr,CC.typeof,
        temps,CC.PTree.gss,CC.PTree.gso,CC.Cop.semSwitchArg,CC.Cop.classifySwitch,
        CC.selectSwitch,CC.seqOfLabeledStatement,
        CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semCmp,CC.Cop.classifyCmp,
        CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tint,CC.tulong,CC.Archi.ptr64,
        CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.cmpu,CC.Integers.MI.cmpu,
        CC.Integers.Int64.eq,CC.Integers.MI.eq,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,equal,
        CC.blocksOfEnv,CC.emptyEnv,CC.Mem.freeList,empty_elements,return_type,
        ite_true,ite_false,eq_self,CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
      let remaining ← Lean.Elab.Tactic.getMainTarget
      unless remaining.isAppOfArity ``InternalRun 4 do throwError m!"original branch-test step {i} remains: {remaining}"
    unless finished do throwError "original branch-test op3 did not return"

end KProgFormal.ClightRefinement.Arm64BranchBit63
