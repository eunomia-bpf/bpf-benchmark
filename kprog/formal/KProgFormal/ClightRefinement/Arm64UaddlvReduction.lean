import KProgFormal.ClightRefinement.Arm64ProgramEntryLinked
import KProgFormal.ClightRefinement.InternalExecution

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Uaddlv.Reduction

abbrev handler := Arm64Numeric.f_kprog_arm64_reduction

private def body : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none
    Lean.Elab.Tactic.closeMainGoal `actual_uaddlv_reduction_body
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private theorem body_source : handler.fn_body = body := rfl

private structure Choice where
  statement : CC.Stmt
  labels : CC.LStmts
  selected : CC.Stmt

private def choice : Choice := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original UADDLV reduction control changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(body)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel root[0]! ``CC.Stmt.Sloop 2
    let mut rest := loop[0]!
    for _ in [:4] do
      let seq ← peel rest ``CC.Stmt.Ssequence 2
      rest := seq[1]!
    let seq ← peel rest ``CC.Stmt.Ssequence 2
    let switch ← peel seq[0]! ``CC.Stmt.Sswitch 2
    let selected ← Lean.Meta.mkAppM ``CC.selectSwitch #[(← Lean.Elab.Term.elabTerm (← `((37 : Int))) none),switch[1]!]
    let selected ← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement #[selected]
    Lean.Elab.Tactic.closeMainGoal `actual_uaddlv_reduction_choice
      (← Lean.Meta.mkAppM ``Choice.mk #[seq[0]!,switch[1]!,
        (← Lean.Meta.withTransparency .all (Lean.Meta.whnf selected))])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_uaddlv_reduction_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def choose : CC.Stmt := by run_tac cachePart (← `(choice.statement))
private def labels : CC.LStmts := by run_tac cachePart (← `(choice.labels))
private def selected : CC.Stmt := by run_tac cachePart (← `(choice.selected))
private theorem choose_source : choose = .Sswitch
    (.Etempvar Arm64Numeric.___kprog_a64_red_op CC.tulong) labels := rfl
private theorem selected_source : CC.seqOfLabeledStatement (CC.selectSwitch 37 labels) = selected := rfl

private theorem op_ne_result : Arm64Numeric.___kprog_a64_red_op ≠ Arm64Numeric.___kprog_a64_red_result := by decide +kernel
private theorem op_ne_out : Arm64Numeric.___kprog_a64_red_op ≠ Arm64Numeric.___kprog_a64_red_out := by decide +kernel
private theorem op_ne_value : Arm64Numeric.___kprog_a64_red_op ≠ Arm64Numeric.___kprog_a64_red_value := by decide +kernel

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (op : le.get Arm64Numeric.___kprog_a64_red_op = some (.Vlong (37#64))) :
    CC.Step2 world (.State handler choose k e le m) CC.E0
      (.State handler selected (.Kswitch k) e le m) := by
  apply CC.doStep_sound
  simp only [choose_source,CC.doStep,CC.doEvalExpr,op,CC.Cop.semSwitchArg,
    CC.Cop.classifySwitch,CC.typeof,CC.tulong,CC.Integers.Int64.unsigned,
    CC.Integers.MI.unsigned,selected_source]
  rfl

private def undefTemps : CC.TempEnv := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(CC.createUndefTemps handler.fn_temps)) none
    Lean.Elab.Tactic.closeMainGoal `actual_uaddlv_undef_temps (← Lean.Meta.reduce term)

private def initialTemps (value : BitVec 64) : CC.TempEnv :=
  (undefTemps.set Arm64Numeric._op (.Vlong (37#64))).set Arm64Numeric._value (.Vlong value)

private theorem enter (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 1 (.Callstate (.Internal handler) [.Vlong (37#64),.Vlong value] k m)
      (.State handler body k CC.emptyEnv (initialTemps value) m) := by
  have entry : CC.FunctionEntry2 world handler [.Vlong (37#64),.Vlong value] m
      CC.emptyEnv (initialTemps value) m :=
    .intro (by decide +kernel) (by decide +kernel) (by decide +kernel) (.nil _ _) rfl
  rw [← body_source]
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entry) (.refl _)

/-- The original C expression for each shifted and masked byte. -/
def lane (value : BitVec 64) (slot : Fin 8) : BitVec 64 :=
  (value >>> (8 * slot.val)) &&& (255#64)

/-- The original eight additions, in their actual C accumulator order. -/
def sum (value : BitVec 64) : BitVec 64 :=
  ((((((((0#64 + lane value 0) + lane value 1) + lane value 2) + lane value 3) +
    lane value 4) + lane value 5) + lane value 6) + lane value 7)

set_option hygiene false in
/-- Execute the complete original op37 C function, retaining arbitrary
memory and its actual return continuation. The step count follows the source. -/
theorem execute (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    ∃ count, InternalRun world count
      (.Callstate (.Internal handler) [.Vlong (37#64),.Vlong value] k m)
      (.Returnstate (.Vlong (sum value)) (CC.callCont k) m) := by
  suffices rest : ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (initialTemps value) m)
      (.Returnstate (.Vlong (sum value)) (CC.callCont k) m) by
    obtain ⟨count,run⟩ := rest
    exact ⟨1+count,(enter world value k m).trans run⟩
  refine ⟨?_,?_⟩
  rotate_left
  run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:150] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.Returnstate 3 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual UADDLV reduction transitions including entry: {1+i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf state.getAppArgs[1]!)
        if stmt.isAppOfArity ``CC.Stmt.Sswitch 2 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply choose_step))
          Lean.Elab.Tactic.evalTactic (← `(tactic|
            rw [CC.PTree.gso _ _ _ _ (Ne.symm op_ne_result),
                CC.PTree.gso _ _ _ _ (Ne.symm op_ne_out),
                CC.PTree.gso _ _ _ _ (Ne.symm op_ne_value)]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact CC.PTree.gss _ _ _))
          continue
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Meta.withTransparency .all do
        (← Lean.Elab.Tactic.getMainGoal).applyRfl
    unless finished do throwError "UADDLV reduction has further original source transitions"

end KProgFormal.ClightRefinement.Arm64Uaddlv.Reduction
