import KProgFormal.ClightRefinement.Arm64OrnRhsCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Orn.Numeric

/-- Original caller inputs and the materialized operand survive the numeric suffix. -/
def retained : List CC.Ident :=
  [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
    Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,
    Arm64Program.___a64_l_width,Arm64Program.___kprog_a64_orn_op,
    Arm64Program.___kprog_a64_orn_lhs,Arm64Program.___kprog_a64_orn_rhs]

private structure Pieces where
  widthSet : CC.Stmt
  maskChoice : CC.Stmt
  maskSet : CC.Stmt
  init : CC.Stmt
  choose : CC.Stmt
  copy : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual ORN numeric sequence changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(RhsCall.tail)) none)
    let suffix ← peel root[1]!
    let mask ← peel suffix[0]!
    let result ← peel suffix[1]!
    let switch ← peel result[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_orn_numeric
      (← Lean.Meta.mkAppM ``Pieces.mk #[root[0]!,mask[0]!,mask[1]!,result[0]!,switch[0]!,switch[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_orn_numeric_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def widthSet : CC.Stmt := by run_tac cachePart (← `(pieces.widthSet))
private def maskChoice : CC.Stmt := by run_tac cachePart (← `(pieces.maskChoice))
private def maskSet : CC.Stmt := by run_tac cachePart (← `(pieces.maskSet))
private def init : CC.Stmt := by run_tac cachePart (← `(pieces.init))
private def choose : CC.Stmt := by run_tac cachePart (← `(pieces.choose))
private def copy : CC.Stmt := by run_tac cachePart (← `(pieces.copy))
private def rest : CC.Stmt := .Ssequence init (.Ssequence choose copy)
private def widthPrefix : CC.Stmt := .Ssequence widthSet (.Ssequence (.Ssequence maskChoice maskSet) rest)

/-- Original width/mask preparation and switch/result-copy suffix. -/
theorem source : RhsCall.tail = widthPrefix := rfl

private def preparedTemps (le : CC.TempEnv) : CC.TempEnv :=
  (((((le.set Arm64Program.___kprog_a64_orn_width (.Vlong (4#64))).set
    Arm64Program._t'139 (.Vlong ((4294967295#64)))).set
    Arm64Program._t'139 (.Vlong ((4294967295#64)))).set
    Arm64Program._t'139 (.Vlong ((4294967295#64)))).set
    Arm64Program.___kprog_a64_orn_wmask (.Vlong ((4294967295#64))))

private theorem outside0 : Arm64Program.___kprog_a64_orn_width ∉ retained := by decide +kernel
private theorem outside1 : Arm64Program._t'139 ∉ retained := by decide +kernel
private theorem outside2 : Arm64Program.___kprog_a64_orn_wmask ∉ retained := by decide +kernel
private theorem outside3 : Arm64Program.___kprog_a64_orn_result ∉ retained := by decide +kernel
private theorem outside5 : Arm64Program.___a64_l_result__7 ∉ retained := by decide +kernel

private theorem get_kept (key id : CC.Ident) (value : CC.Val) (le : CC.TempEnv)
    (outside : key ∉ retained) (inside : id ∈ retained) :
    (le.set key value).get id = le.get id := by
  apply CC.PTree.gso
  intro equal
  exact outside (equal.symm ▸ inside)

private def finalTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (((preparedTemps le).set Arm64Program.___kprog_a64_orn_result (.Vlong 0)).set
    Arm64Program.___kprog_a64_orn_result (.Vlong value)).set
    Arm64Program.___a64_l_result__7 (.Vlong value)

private theorem final_kept (le : CC.TempEnv) (value : BitVec 64) (id : CC.Ident)
    (inside : id ∈ retained) : (finalTemps le value).get id = le.get id := by
  unfold finalTemps preparedTemps
  rw [get_kept Arm64Program.___a64_l_result__7 id _ _ outside5 inside,
    get_kept Arm64Program.___kprog_a64_orn_result id _ _ outside3 inside,
    get_kept Arm64Program.___kprog_a64_orn_result id _ _ outside3 inside,
    get_kept Arm64Program.___kprog_a64_orn_wmask id _ _ outside2 inside,
    get_kept Arm64Program._t'139 id _ _ outside1 inside,
    get_kept Arm64Program._t'139 id _ _ outside1 inside,
    get_kept Arm64Program._t'139 id _ _ outside1 inside,
    get_kept Arm64Program.___kprog_a64_orn_width id _ _ outside0 inside]

private theorem prepared_kept (le : CC.TempEnv) (id : CC.Ident) (inside : id ∈ retained) :
    (preparedTemps le).get id = le.get id := by
  unfold preparedTemps
  rw [get_kept Arm64Program.___kprog_a64_orn_wmask id _ _ outside2 inside,
    get_kept Arm64Program._t'139 id _ _ outside1 inside,
    get_kept Arm64Program._t'139 id _ _ outside1 inside,
    get_kept Arm64Program._t'139 id _ _ outside1 inside,
    get_kept Arm64Program.___kprog_a64_orn_width id _ _ outside0 inside]

private theorem initialized_kept (le : CC.TempEnv) (id : CC.Ident) (inside : id ∈ retained) :
    ((preparedTemps le).set Arm64Program.___kprog_a64_orn_result (.Vlong (0#64))).get id =
      le.get id :=
  (get_kept _ id _ _ outside3 inside).trans (prepared_kept le id inside)


private def resultSet : CC.Stmt := .Sset Arm64Program.___kprog_a64_orn_result
  (.Ebinop .Oand (.Ebinop .Oor (.Etempvar Arm64Program.___kprog_a64_orn_lhs CC.tulong)
    (.Eunop .Onotint (.Etempvar Arm64Program.___kprog_a64_orn_rhs CC.tulong) CC.tulong) CC.tulong)
    (.Etempvar Arm64Program.___kprog_a64_orn_wmask CC.tulong) CC.tulong)

private structure SwitchPieces where
  selector : CC.Expr
  labels : CC.LStmts
  action : CC.Stmt
  fallthrough : CC.Stmt

private def switchPieces : SwitchPieces := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(choose)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "actual ORN switch changed"
    let labels := actual.getAppArgs[1]!
    let selected ← Lean.Meta.mkAppM ``CC.selectSwitch #[(← Lean.Elab.Term.elabTerm (← `((53 : Int))) none),labels]
    let selected ← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement #[selected]
    let selected ← Lean.Meta.withTransparency .all (Lean.Meta.whnf selected)
    unless selected.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual ORN case53 changed"
    Lean.Elab.Tactic.closeMainGoal `actual_orn_case53 (← Lean.Meta.mkAppM ``SwitchPieces.mk
      #[actual.getAppArgs[0]!,labels,selected.getAppArgs[0]!,selected.getAppArgs[1]!])

private def selector : CC.Expr := by run_tac cachePart (← `(switchPieces.selector))
private def labels : CC.LStmts := by run_tac cachePart (← `(switchPieces.labels))
private def case53 : CC.Stmt := by run_tac cachePart (← `(switchPieces.action))
private def fallthrough : CC.Stmt := by run_tac cachePart (← `(switchPieces.fallthrough))
private theorem choose_source : choose = .Sswitch selector labels := rfl
private theorem chosen_source : CC.seqOfLabeledStatement (CC.selectSwitch 53 labels) =
    .Ssequence case53 fallthrough := rfl
private theorem selector_source : selector = .Etempvar Arm64Program.___kprog_a64_orn_op CC.tulong := rfl
private theorem case_source : case53 = .Ssequence resultSet .Sbreak := rfl

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (op : le.get Arm64Program.___kprog_a64_orn_op = some (.Vlong (53#64))) :
    CC.Step2 world (.State Arm64Nop.handler choose k e le m) CC.E0
      (.State Arm64Nop.handler (.Ssequence case53 fallthrough) (.Kswitch k) e le m) := by
  rw [choose_source]
  apply CC.doStep_sound
  simp only [CC.doStep,selector_source,CC.doEvalExpr,op,CC.Cop.semSwitchArg,
    CC.Cop.classifySwitch,CC.tulong,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,chosen_source]
  rfl

private theorem result_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (lhs rhs : BitVec 64)
    (left : le.get Arm64Program.___kprog_a64_orn_lhs = some (.Vlong lhs))
    (right : le.get Arm64Program.___kprog_a64_orn_rhs = some (.Vlong rhs))
    (mask : le.get Arm64Program.___kprog_a64_orn_wmask = some (.Vlong (4294967295#64))) :
    CC.Step2 world (.State Arm64Nop.handler resultSet k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e
        (le.set Arm64Program.___kprog_a64_orn_result (.Vlong ((lhs ||| ~~~rhs) &&& (4294967295#64)))) m) := by
  apply CC.doStep_sound
  simp only [resultSet,CC.doStep,CC.doEvalExpr,left,right,mask,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semOr,CC.Cop.semUnaryOperation,CC.Cop.semNotint,
    CC.Cop.classifyNotint,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,
    CC.removeAttributes,CC.tattr,CC.tulong,CC.Archi.ptr64,ite_true,
    CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.or,CC.Integers.MI.or,
    CC.Integers.Int64.not,CC.Integers.MI.not]

private theorem initialized_mask (le : CC.TempEnv) :
    ((preparedTemps le).set Arm64Program.___kprog_a64_orn_result (.Vlong (0#64))).get
      Arm64Program.___kprog_a64_orn_wmask = some (.Vlong (4294967295#64)) :=
  (CC.PTree.gso _ _ _ _ (by decide +kernel :
    Arm64Program.___kprog_a64_orn_result ≠ Arm64Program.___kprog_a64_orn_wmask)).trans (CC.PTree.gss _ _ _)

set_option hygiene false in
private def numericSteps (stop : Lean.Name) : Lean.Elab.Tactic.TacticM Unit :=
  Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:100] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf stop then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual ORN numeric transitions: {i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``choose then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply choose_step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact
          (initialized_kept le Arm64Program.___kprog_a64_orn_op (by decide +kernel)).trans op))
        continue
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``resultSet then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply result_step (lhs := lhs) (rhs := rhs)))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact
          (initialized_kept le Arm64Program.___kprog_a64_orn_lhs (by decide +kernel)).trans left))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact
          (initialized_kept le Arm64Program.___kprog_a64_orn_rhs (by decide +kernel)).trans right))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact initialized_mask le))
        continue
      if state.isAppOfArity ``CC.State.State 6 then
        if state.getAppArgs[1]!.isConstOf ``case53 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| rw [case_source]))
        else if let .const name _ := state.getAppArgs[1]! then
          if let .defnInfo _ ← Lean.getConstInfo name then
            let alias := Lean.mkIdent name
            Lean.Elab.Tactic.evalTactic (← `(tactic| unfold $alias:ident))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [
        CC.doStep,widthPrefix,preparedTemps,ReadEntry.innerCont,narrow,CC.PTree.gss,
        CC.doEvalExpr,CC.typeof,CC.setOpttemp,CC.Cop.semBinaryOperation,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,
        CC.tattr,CC.tuchar,CC.tuint,CC.tint,CC.tulong,
        CC.Cop.semSwitchArg,CC.Cop.classifySwitch,CC.selectSwitch,CC.selectSwitchCase,
        CC.selectSwitchDefault,CC.seqOfLabeledStatement,
        CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
        CC.Integers.Int64.cmpu,CC.Integers.Int.eq,CC.Integers.Int64.eq,CC.Integers.MI.eq,
        CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
        CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.unsigned,
        CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,
        CC.Integers.Int.zero,CC.Integers.Int.one,CC.Integers.MI.zero,CC.Integers.MI.one,
        BitVec.ofBool_false,BitVec.ofBool_true,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false,eq_self,
        Bool.false_eq_true,Bool.true_eq_false] <;> try rfl))
    unless finished do throwError "ORN numeric path has further transitions before the original writer"

set_option hygiene false in
private theorem prepare (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (narrow : le.get Arm64Program.___a64_l_width = some (.Vint (4#32))) :
    ∃ count, InternalRun world count
      (.State Arm64Nop.handler RhsCall.tail (ReadEntry.innerCont k) e le m)
      (.State Arm64Nop.handler rest (ReadEntry.innerCont k) e (preparedTemps le) m) := by
  rw [source]
  refine ⟨?count,?execution⟩
  case execution => run_tac numericSteps ``rest

set_option hygiene false in
/-- Execute actual ORN32 width/mask, case53, result copy and inner-loop exit. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (lhs rhs : BitVec 64)
    (op : le.get Arm64Program.___kprog_a64_orn_op = some (.Vlong (53#64)))
    (left : le.get Arm64Program.___kprog_a64_orn_lhs = some (.Vlong lhs))
    (right : le.get Arm64Program.___kprog_a64_orn_rhs = some (.Vlong rhs))
    (narrow : le.get Arm64Program.___a64_l_width = some (.Vint (4#32))) :
    ∃ count le', InternalRun world count
      (.State Arm64Nop.handler RhsCall.tail (ReadEntry.innerCont k) e le m)
      (.State Arm64Nop.handler ReadEntry.writer k e le' m) ∧
      le'.get Arm64Program.___a64_l_result__7 = some (.Vlong ((lhs ||| ~~~rhs) &&& (4294967295#64))) ∧
      ∀ id ∈ retained, le'.get id = le.get id := by
  obtain ⟨first,preparation⟩ := prepare world e le m k narrow
  have computation : ∃ count le', InternalRun world count
      (.State Arm64Nop.handler rest (ReadEntry.innerCont k) e (preparedTemps le) m)
      (.State Arm64Nop.handler ReadEntry.writer k e le' m) ∧
      le'.get Arm64Program.___a64_l_result__7 = some (.Vlong ((lhs ||| ~~~rhs) &&& (4294967295#64))) ∧
      ∀ id ∈ retained, le'.get id = le.get id := by
    refine ⟨?count,?temps,?execution,?word,?kept⟩
    case execution => run_tac numericSteps ``ReadEntry.writer
    case word => exact CC.PTree.gss _ _ _
    case kept =>
      intro id inside
      change (finalTemps le ((lhs ||| ~~~rhs) &&& (4294967295#64))).get id = le.get id
      exact final_kept le _ id inside
  obtain ⟨second,le',run,word,kept⟩ := computation
  exact ⟨first+second,le',preparation.trans run,word,kept⟩

end KProgFormal.ClightRefinement.Arm64Orn.Numeric
