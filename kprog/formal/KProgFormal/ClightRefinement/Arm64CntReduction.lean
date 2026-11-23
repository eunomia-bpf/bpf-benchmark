import KProgFormal.ClightRefinement.Arm64CntPopcount
import KProgFormal.ClightRefinement.Arm64ProgramEntryLinked

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Reduction

abbrev handler := Arm64Numeric.f_kprog_arm64_reduction

private def body : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none
    Lean.Elab.Tactic.closeMainGoal `actual_cnt_reduction_body
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
      unless actual.isAppOfArity ctor arity do throwError "original CNT reduction control changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(body)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel root[0]! ``CC.Stmt.Sloop 2
    let mut rest := loop[0]!
    for _ in [:4] do
      let seq ← peel rest ``CC.Stmt.Ssequence 2
      rest := seq[1]!
    let seq ← peel rest ``CC.Stmt.Ssequence 2
    let switch ← peel seq[0]! ``CC.Stmt.Sswitch 2
    let selected ← Lean.Meta.mkAppM ``CC.selectSwitch #[(← Lean.Elab.Term.elabTerm (← `((36 : Int))) none),switch[1]!]
    let selected ← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement #[selected]
    Lean.Elab.Tactic.closeMainGoal `actual_cnt_reduction_choice
      (← Lean.Meta.mkAppM ``Choice.mk #[seq[0]!,switch[1]!,
        (← Lean.Meta.withTransparency .all (Lean.Meta.whnf selected))])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cnt_reduction_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def choose : CC.Stmt := by run_tac cachePart (← `(choice.statement))
private def labels : CC.LStmts := by run_tac cachePart (← `(choice.labels))
private def selected : CC.Stmt := by run_tac cachePart (← `(choice.selected))
private theorem choose_source : choose = .Sswitch
    (.Etempvar Arm64Numeric.___kprog_a64_red_op CC.tulong) labels := rfl
private theorem selected_source : CC.seqOfLabeledStatement (CC.selectSwitch 36 labels) = selected := rfl

private theorem op_ne_result : Arm64Numeric.___kprog_a64_red_op ≠
    Arm64Numeric.___kprog_a64_red_result := by decide +kernel
private theorem op_ne_out : Arm64Numeric.___kprog_a64_red_op ≠
    Arm64Numeric.___kprog_a64_red_out := by decide +kernel
private theorem op_ne_value : Arm64Numeric.___kprog_a64_red_op ≠
    Arm64Numeric.___kprog_a64_red_value := by decide +kernel

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont)
    (op : le.get Arm64Numeric.___kprog_a64_red_op = some (.Vlong (36#64))) :
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
    Lean.Elab.Tactic.closeMainGoal `actual_cnt_undef_temps (← Lean.Meta.reduce term)

private def initialTemps (value : BitVec 64) : CC.TempEnv :=
  (undefTemps.set Arm64Numeric._op (.Vlong (36#64))).set
    Arm64Numeric._value (.Vlong value)

private theorem enter (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 1
      (.Callstate (.Internal handler) [.Vlong (36#64),.Vlong value] k m)
      (.State handler body k CC.emptyEnv (initialTemps value) m) := by
  have entry : CC.FunctionEntry2 world handler [.Vlong (36#64),.Vlong value] m
      CC.emptyEnv (initialTemps value) m :=
    .intro (by decide +kernel) (by decide +kernel) (by decide +kernel) (.nil _ _) rfl
  rw [← body_source]
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entry) (.refl _)

private theorem call_step (world : CC.CGenv) (block : CC.Block)
    (symbol : CC.Genv.findSymbol world.genv_genv
      Arm64Numeric._kprog_x86_popcount_value = some block)
    (function : CC.Genv.findFunctPtr world.genv_genv block =
      some (.Internal Popcount.handler))
    (optid : Option CC.Ident) (argument : CC.Expr) (value : CC.Val)
    (k : CC.Cont) (le : CC.TempEnv) (m : CC.Mem)
    (args : CC.doEvalExprlist world CC.emptyEnv le m
      [argument] [CC.tulong] = some [value]) :
    CC.Step2 world
      (.State handler (.Scall optid
        (.Evar Arm64Numeric._kprog_x86_popcount_value
          (.Tfunction [CC.tulong] CC.tulong CC.cc_default)) [argument]) k CC.emptyEnv le m)
      CC.E0 (.Callstate (.Internal Popcount.handler) [value]
        (.Kcall optid handler CC.emptyEnv le k) m) := by
  apply CC.Step.call (vf := .Vptr block 0) (tyargs := [CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,CC.emptyEnv,CC.PTree.gempty,symbol,
      CC.doDerefLoc,CC.accessMode]
    rfl
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ args
  · change CC.Genv.findFunctPtr world.genv_genv block =
      some (.Internal Popcount.handler)
    exact function
  · rfl

/-- Imported byte results in the actual C accumulator's order. -/
def lane (value : BitVec 64) (slot : Fin 8) : BitVec 64 :=
  (DPSFP.simd_count_bytes ((value >>> (8 * slot.val)).setWidth 8)).setWidth 64

def packed (value : BitVec 64) : BitVec 64 :=
  ((((((((0#64 ||| (lane value 0 <<< 0)) ||| (lane value 1 <<< 8)) |||
    (lane value 2 <<< 16)) ||| (lane value 3 <<< 24)) ||| (lane value 4 <<< 32)) |||
    (lane value 5 <<< 40)) ||| (lane value 6 <<< 48)) ||| (lane value 7 <<< 56))

private theorem binding : ∃ block,
    CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Numeric._kprog_x86_popcount_value = some block ∧
    CC.Genv.findFunctPtr Arm64ProgramEntryLinked.ge.genv_genv block = some (.Internal Popcount.handler) := by
  refine ⟨(CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Numeric._kprog_x86_popcount_value).get
    (by decide +kernel),?_,?_⟩
  all_goals run_tac Arm64ProgramEntryLinked.sourceEquality

set_option hygiene false in
/-- Execute the original CNT reduction function through all eight actual
shared-helper calls, retaining the complete heap and actual return frame. -/
private theorem execute_in (world : CC.CGenv) (block : CC.Block)
    (symbol : CC.Genv.findSymbol world.genv_genv Arm64Numeric._kprog_x86_popcount_value = some block)
    (function : CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Popcount.handler))
    (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    ∃ count, InternalRun world count
      (.Callstate (.Internal handler) [.Vlong (36#64),.Vlong value] k m)
      (.Returnstate (.Vlong (packed value)) (CC.callCont k) m) := by
  suffices rest : ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (initialTemps value) m)
      (.Returnstate (.Vlong (packed value)) (CC.callCont k) m) by
    obtain ⟨count,run⟩ := rest
    exact ⟨1+count,(enter world value k m).trans run⟩
  refine ⟨?_,?_⟩
  rotate_left
  run_tac Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    let mut calls := 0
    let popcount ← Lean.Elab.Term.elabTerm (← `(CC.FunDef.Internal Popcount.handler)) none
    for i in [:200] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      Lean.logInfo m!"CNT reduction source stage {i}, completed helper calls {calls}"
      if state.isAppOfArity ``CC.State.Returnstate 3 then
        let final ← Lean.instantiateMVars goal.getAppArgs[3]!
        if ← Lean.Meta.withTransparency .all (Lean.Meta.isDefEq state.getAppArgs[1]! final.getAppArgs[1]!) then
          unless calls == 8 do throwError "actual CNT reduction helper-call sequence changed"
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual CNT reduction helper calls: {calls}; other transitions: {1+i-calls}; total: {1+i-calls+11*calls}"
          finished := true
          break
      if state.isAppOfArity ``CC.State.State 6 then
        let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf state.getAppArgs[1]!)
        if stmt.isAppOfArity ``CC.Stmt.Sswitch 2 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply choose_step))
          Lean.logInfo m!"CNT actual opcode observation: {← Lean.Elab.Tactic.getMainTarget}"
          Lean.Elab.Tactic.evalTactic (← `(tactic|
            rw [CC.PTree.gso _ _ _ _ (Ne.symm op_ne_result),
                CC.PTree.gso _ _ _ _ (Ne.symm op_ne_out),
                CC.PTree.gso _ _ _ _ (Ne.symm op_ne_value)]))
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact CC.PTree.gss _ _ _))
          continue
        if stmt.isAppOfArity ``CC.Stmt.Scall 3 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
          Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
          Lean.Elab.Tactic.evalTactic (← `(tactic| apply call_step world block symbol function))
          Lean.logInfo m!"CNT actual shared-call argument: {← Lean.Elab.Tactic.getMainTarget}"
          Lean.Meta.withTransparency .all do
            (← Lean.Elab.Tactic.getMainGoal).applyRfl
          continue
      if state.isAppOfArity ``CC.State.Callstate 4 then
        if ← Lean.Meta.withTransparency .all (Lean.Meta.isDefEq state.getAppArgs[0]! popcount) then
          unless calls < 8 do throwError "actual CNT reduction has a further shared-helper call"
          let slot := Lean.Syntax.mkNumLit (toString calls)
          Lean.Elab.Tactic.evalTactic (← `(tactic|
            apply (Popcount.execute_slice world value ($slot : Fin 8) _ m).trans))
          calls := calls + 1
          continue
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Meta.withTransparency .all do
        (← Lean.Elab.Tactic.getMainGoal).applyRfl
    unless finished do throwError "CNT reduction has further original source transitions"

/-- Bind the actual helper symbol in the genuine linked program. -/
theorem execute (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.Callstate (.Internal handler) [.Vlong (36#64),.Vlong value] k m)
      (.Returnstate (.Vlong (packed value)) (CC.callCont k) m) := by
  obtain ⟨block,symbol,function⟩ := binding
  exact execute_in Arm64ProgramEntryLinked.ge block symbol function value k m

end KProgFormal.ClightRefinement.Arm64Cnt.Reduction
