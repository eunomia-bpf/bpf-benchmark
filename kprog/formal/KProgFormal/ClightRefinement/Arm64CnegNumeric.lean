import KProgFormal.ClightRefinement.Arm64CnegCondition

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Cneg.Numeric

private theorem full_mask (word : BitVec 64) : word &&& BitVec.ofInt 64 (-1) = word := by
  have mask : BitVec.ofInt 64 (-1) = BitVec.allOnes 64 := by decide +kernel
  rw [mask]
  exact BitVec.and_allOnes

/-- Original caller inputs and the materialized operand survive the numeric suffix. -/
def retained : List CC.Ident :=
  [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
    Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,
    Arm64Program.___a64_l_width,Arm64Program.___kprog_a64_cneg_op,
    Arm64Program.___kprog_a64_cneg_value,Arm64Program.___kprog_a64_cneg_taken]

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
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual CNEG numeric sequence changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Condition.after)) none)
    let suffix ← peel root[1]!
    let mask ← peel suffix[0]!
    let result ← peel suffix[1]!
    let switch ← peel result[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_cneg_numeric
      (← Lean.Meta.mkAppM ``Pieces.mk #[root[0]!,mask[0]!,mask[1]!,result[0]!,switch[0]!,switch[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cneg_numeric_part
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
theorem source : Condition.after = widthPrefix := rfl

private def preparedTemps (le : CC.TempEnv) : CC.TempEnv :=
  (((((le.set Arm64Program.___kprog_a64_cneg_width (.Vlong (8#64))).set
    Arm64Program._t'57 (.Vlong (BitVec.ofInt 64 (-1)))).set
    Arm64Program._t'57 (.Vlong (BitVec.ofInt 64 (-1)))).set
    Arm64Program._t'57 (.Vlong (BitVec.ofInt 64 (-1)))).set
    Arm64Program.___kprog_a64_cneg_wmask (.Vlong (BitVec.ofInt 64 (-1))))

private theorem outside0 : Arm64Program.___kprog_a64_cneg_width ∉ retained := by decide +kernel
private theorem outside1 : Arm64Program._t'57 ∉ retained := by decide +kernel
private theorem outside2 : Arm64Program.___kprog_a64_cneg_wmask ∉ retained := by decide +kernel
private theorem outside3 : Arm64Program.___kprog_a64_cneg_result ∉ retained := by decide +kernel
private theorem outside4 : Arm64Program._t'58 ∉ retained := by decide +kernel
private theorem outside5 : Arm64Program.___a64_l_result__3 ∉ retained := by decide +kernel

private theorem get_kept (key id : CC.Ident) (value : CC.Val) (le : CC.TempEnv)
    (outside : key ∉ retained) (inside : id ∈ retained) :
    (le.set key value).get id = le.get id := by
  apply CC.PTree.gso
  intro equal
  exact outside (equal.symm ▸ inside)

private def finalTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((((preparedTemps le).set Arm64Program.___kprog_a64_cneg_result (.Vlong 0)).set
    Arm64Program._t'58 (.Vlong value)).set Arm64Program.___kprog_a64_cneg_result (.Vlong value)).set
    Arm64Program.___a64_l_result__3 (.Vlong value)

private theorem final_kept (le : CC.TempEnv) (value : BitVec 64) (id : CC.Ident)
    (inside : id ∈ retained) : (finalTemps le value).get id = le.get id := by
  unfold finalTemps preparedTemps
  rw [get_kept Arm64Program.___a64_l_result__3 id _ _ outside5 inside,
    get_kept Arm64Program.___kprog_a64_cneg_result id _ _ outside3 inside,
    get_kept Arm64Program._t'58 id _ _ outside4 inside,
    get_kept Arm64Program.___kprog_a64_cneg_result id _ _ outside3 inside,
    get_kept Arm64Program.___kprog_a64_cneg_wmask id _ _ outside2 inside,
    get_kept Arm64Program._t'57 id _ _ outside1 inside,
    get_kept Arm64Program._t'57 id _ _ outside1 inside,
    get_kept Arm64Program._t'57 id _ _ outside1 inside,
    get_kept Arm64Program.___kprog_a64_cneg_width id _ _ outside0 inside]

private theorem prepared_kept (le : CC.TempEnv) (id : CC.Ident) (inside : id ∈ retained) :
    (preparedTemps le).get id = le.get id := by
  unfold preparedTemps
  rw [get_kept Arm64Program.___kprog_a64_cneg_wmask id _ _ outside2 inside,
    get_kept Arm64Program._t'57 id _ _ outside1 inside,
    get_kept Arm64Program._t'57 id _ _ outside1 inside,
    get_kept Arm64Program._t'57 id _ _ outside1 inside,
    get_kept Arm64Program.___kprog_a64_cneg_width id _ _ outside0 inside]

private theorem initialized_kept (le : CC.TempEnv) (id : CC.Ident) (inside : id ∈ retained) :
    ((preparedTemps le).set Arm64Program.___kprog_a64_cneg_result (.Vlong (0#64))).get id =
      le.get id :=
  (get_kept _ id _ _ outside3 inside).trans (prepared_kept le id inside)

private theorem initialized_mask (le : CC.TempEnv) (value : CC.Val) :
    (((preparedTemps le).set Arm64Program.___kprog_a64_cneg_result (.Vlong (0#64))).set
      Arm64Program._t'58 value).get Arm64Program.___kprog_a64_cneg_wmask =
      some (.Vlong (BitVec.ofInt 64 (-1))) :=
  (CC.PTree.gso _ _ _ _ (by decide +kernel : Arm64Program._t'58 ≠ Arm64Program.___kprog_a64_cneg_wmask)).trans
    ((CC.PTree.gso _ _ _ _ (by decide +kernel :
      Arm64Program.___kprog_a64_cneg_result ≠ Arm64Program.___kprog_a64_cneg_wmask)).trans (CC.PTree.gss _ _ _))

private def negativeSet : CC.Stmt := .Sset Arm64Program._t'58
  (.Ecast (.Ecast (.Ebinop .Osub (.Econst_long (0#64) CC.tulong)
    (.Etempvar Arm64Program.___kprog_a64_cneg_value CC.tulong) CC.tulong) CC.tulong) CC.tulong)
private def positiveSet : CC.Stmt := .Sset Arm64Program._t'58
  (.Ecast (.Etempvar Arm64Program.___kprog_a64_cneg_value CC.tulong) CC.tulong)
private theorem value_source : Arm64Program.s_kprog_arm64_program_execute_35 =
    .Sifthenelse (.Etempvar Arm64Program.___kprog_a64_cneg_taken CC.tint) negativeSet positiveSet := rfl

private theorem flag_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (taken : Bool)
    (observed : le.get Arm64Program.___kprog_a64_cneg_taken =
      some (.Vint ((BitVec.ofBool taken).setWidth 32))) :
    CC.Step2 world (.State Arm64Nop.handler Arm64Program.s_kprog_arm64_program_execute_35 k e le m) CC.E0
      (.State Arm64Nop.handler (if taken then negativeSet else positiveSet) k e le m) := by
  rw [value_source]
  cases taken <;> apply CC.doStep_sound
  all_goals simp +decide only [CC.doStep,CC.doEvalExpr,observed,CC.Cop.boolVal,CC.Cop.classifyBool,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,CC.Integers.Int.eq,CC.Integers.MI.eq,
    CC.Integers.Int.zero,CC.Integers.MI.zero,BitVec.ofBool_false,BitVec.ofBool_true,
    ite_true,ite_false] <;> rfl

private theorem value_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64) (negative : Bool)
    (observed : le.get Arm64Program.___kprog_a64_cneg_value = some (.Vlong value)) :
    CC.Step2 world (.State Arm64Nop.handler (if negative then negativeSet else positiveSet) k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e
        (le.set Arm64Program._t'58 (.Vlong (if negative then -value else value))) m) := by
  cases negative <;> apply CC.doStep_sound
  all_goals simp only [negativeSet,positiveSet,CC.doStep,CC.doEvalExpr,observed,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semSub,CC.Cop.classifySub,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.Integers.Int64.sub,CC.Integers.MI.sub,
    BitVec.zero_sub,Bool.false_eq_true,ite_false,ite_true] <;> rfl

private structure SwitchPieces where
  selector : CC.Expr
  labels : CC.LStmts
  action : CC.Stmt
  fallthrough : CC.Stmt

private def switchPieces : SwitchPieces := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(choose)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "actual CNEG switch changed"
    let labels := actual.getAppArgs[1]!
    let selected ← Lean.Meta.mkAppM ``CC.selectSwitch #[(← Lean.Elab.Term.elabTerm (← `((65 : Int))) none),labels]
    let selected ← Lean.Meta.mkAppM ``CC.seqOfLabeledStatement #[selected]
    let selected ← Lean.Meta.withTransparency .all (Lean.Meta.whnf selected)
    unless selected.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual CNEG case65 changed"
    Lean.Elab.Tactic.closeMainGoal `actual_cneg_case65 (← Lean.Meta.mkAppM ``SwitchPieces.mk
      #[actual.getAppArgs[0]!,labels,selected.getAppArgs[0]!,selected.getAppArgs[1]!])

private def selector : CC.Expr := by run_tac cachePart (← `(switchPieces.selector))
private def labels : CC.LStmts := by run_tac cachePart (← `(switchPieces.labels))
private def case65 : CC.Stmt := by run_tac cachePart (← `(switchPieces.action))
private def fallthrough : CC.Stmt := by run_tac cachePart (← `(switchPieces.fallthrough))
private theorem choose_source : choose = .Sswitch selector labels := rfl
private theorem chosen_source : CC.seqOfLabeledStatement (CC.selectSwitch 65 labels) =
    .Ssequence case65 fallthrough := rfl
private theorem selector_source : selector = .Etempvar Arm64Program.___kprog_a64_cneg_op CC.tulong := rfl

private def andSet : CC.Stmt := .Sset Arm64Program.___kprog_a64_cneg_result
  (.Ebinop .Oand (.Etempvar Arm64Program._t'58 CC.tulong)
    (.Etempvar Arm64Program.___kprog_a64_cneg_wmask CC.tulong) CC.tulong)
private theorem case_source : case65 =
    .Ssequence (.Ssequence Arm64Program.s_kprog_arm64_program_execute_35 andSet) .Sbreak := rfl

private theorem and_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (word : le.get Arm64Program._t'58 = some (.Vlong value))
    (mask : le.get Arm64Program.___kprog_a64_cneg_wmask = some (.Vlong (BitVec.ofInt 64 (-1)))) :
    CC.Step2 world (.State Arm64Nop.handler andSet k e le m) CC.E0
      (.State Arm64Nop.handler .Sskip k e
        (le.set Arm64Program.___kprog_a64_cneg_result (.Vlong value)) m) := by
  apply CC.doStep_sound
  simp only [andSet,CC.doStep,CC.doEvalExpr,word,mask,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,
    CC.removeAttributes,CC.tattr,CC.tulong,CC.Archi.ptr64,ite_true,CC.Integers.Int64.and,CC.Integers.MI.and,full_mask]

private theorem choose_step (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (op : le.get Arm64Program.___kprog_a64_cneg_op = some (.Vlong (65#64))) :
    CC.Step2 world (.State Arm64Nop.handler choose k e le m) CC.E0
      (.State Arm64Nop.handler (.Ssequence case65 fallthrough) (.Kswitch k) e le m) := by
  rw [choose_source]
  apply CC.doStep_sound
  simp only [CC.doStep,selector_source,CC.doEvalExpr,op,CC.Cop.semSwitchArg,
    CC.Cop.classifySwitch,CC.tulong,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,chosen_source]
  rfl

set_option hygiene false in
private def numericSteps (stop : Lean.Name) (taken : Bool := false) : Lean.Elab.Tactic.TacticM Unit :=
  Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:100] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.State 6 &&
          state.getAppArgs[1]!.isConstOf stop then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual CNEG numeric transitions: {i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``choose then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply choose_step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact
          (initialized_kept le Arm64Program.___kprog_a64_cneg_op (by decide +kernel)).trans op))
        continue
      if state.isAppOfArity ``CC.State.State 6 &&
          state.getAppArgs[1]!.isConstOf ``Arm64Program.s_kprog_arm64_program_execute_35 then
        let choice ← if taken then `(true) else `(false)
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply flag_step (taken := $choice)))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact
          (initialized_kept le Arm64Program.___kprog_a64_cneg_taken (by decide +kernel)).trans flag))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [Bool.false_eq_true,ite_false,ite_true]))
        continue
      if state.isAppOfArity ``CC.State.State 6 &&
          (state.getAppArgs[1]!.isConstOf ``negativeSet || state.getAppArgs[1]!.isConstOf ``positiveSet) then
        let choice ← if taken then `(true) else `(false)
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply value_step (negative := $choice) (value := value)))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact
          (initialized_kept le Arm64Program.___kprog_a64_cneg_value (by decide +kernel)).trans readValue))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [Bool.false_eq_true,ite_false,ite_true]))
        continue
      if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``andSet then
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply and_step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact CC.PTree.gss _ _ _))
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact
          initialized_mask le _))
        continue
      if state.isAppOfArity ``CC.State.State 6 then
        if state.getAppArgs[1]!.isConstOf ``case65 then
          Lean.Elab.Tactic.evalTactic (← `(tactic| rw [case_source]))
        else if let .const name _ := state.getAppArgs[1]! then
          if let .defnInfo _ ← Lean.getConstInfo name then
            let alias := Lean.mkIdent name
            Lean.Elab.Tactic.evalTactic (← `(tactic| unfold $alias:ident))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [
        CC.doStep,widthPrefix,preparedTemps,ReadEntry.tailCont,wide,CC.PTree.gss,
        CC.doEvalExpr,CC.typeof,CC.setOpttemp,CC.Cop.semBinaryOperation,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,
        CC.tattr,CC.tuchar,CC.tuint,CC.tint,CC.tulong,
        CC.Cop.semSwitchArg,CC.Cop.classifySwitch,CC.selectSwitch,CC.selectSwitchCase,
        CC.selectSwitchDefault,CC.seqOfLabeledStatement,
        CC.Integers.Int64.sub,CC.Integers.MI.sub,CC.Integers.Int64.and,CC.Integers.MI.and,
        CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,
        CC.Integers.Int64.cmpu,CC.Integers.Int.eq,CC.Integers.Int64.eq,CC.Integers.MI.eq,
        CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
        CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.unsigned,
        CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,
        CC.Integers.Int.zero,CC.Integers.Int.one,CC.Integers.MI.zero,CC.Integers.MI.one,
        BitVec.ofBool_false,BitVec.ofBool_true,BitVec.zero_sub,full_mask,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false,eq_self,
        Bool.false_eq_true,Bool.true_eq_false] <;> try rfl))
    unless finished do throwError "CNEG numeric path has further transitions before the original writer"

set_option hygiene false in
private theorem prepare (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (wide : le.get Arm64Program.___a64_l_width = some (.Vint (8#32))) :
    ∃ count, InternalRun world count
      (.State Arm64Nop.handler Condition.after (ReadEntry.tailCont k) e le m)
      (.State Arm64Nop.handler rest (ReadEntry.tailCont k) e (preparedTemps le) m) := by
  rw [source]
  refine ⟨?count,?execution⟩
  case execution => run_tac numericSteps ``rest

set_option hygiene false in
private theorem compute_false (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (op : le.get Arm64Program.___kprog_a64_cneg_op = some (.Vlong (65#64)))
    (readValue : le.get Arm64Program.___kprog_a64_cneg_value = some (.Vlong value))
    (wide : le.get Arm64Program.___a64_l_width = some (.Vint (8#32)))
    (flag : le.get Arm64Program.___kprog_a64_cneg_taken =
      some (.Vint ((BitVec.ofBool false).setWidth 32))) :
    ∃ count le', InternalRun world count
      (.State Arm64Nop.handler rest (ReadEntry.tailCont k) e (preparedTemps le) m)
      (.State Arm64Nop.handler ReadEntry.writer k e le' m) ∧
      le'.get Arm64Program.___a64_l_result__3 = some (.Vlong (value)) ∧
      ∀ id ∈ retained, le'.get id = le.get id := by
  refine ⟨?count,?temps,?execution,?word,?kept⟩
  case execution => run_tac numericSteps ``ReadEntry.writer
  case word => simp only [CC.PTree.gss,CC.Integers.Int64.and,CC.Integers.MI.and,
      CC.Integers.Int64.sub,CC.Integers.MI.sub,full_mask,BitVec.zero_sub] <;> rfl
  case kept =>
    intro id inside
    change (finalTemps le (value)).get id = le.get id
    exact final_kept le (value) id inside

set_option hygiene false in
private theorem compute_true (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (op : le.get Arm64Program.___kprog_a64_cneg_op = some (.Vlong (65#64)))
    (readValue : le.get Arm64Program.___kprog_a64_cneg_value = some (.Vlong value))
    (wide : le.get Arm64Program.___a64_l_width = some (.Vint (8#32)))
    (flag : le.get Arm64Program.___kprog_a64_cneg_taken =
      some (.Vint ((BitVec.ofBool true).setWidth 32))) :
    ∃ count le', InternalRun world count
      (.State Arm64Nop.handler rest (ReadEntry.tailCont k) e (preparedTemps le) m)
      (.State Arm64Nop.handler ReadEntry.writer k e le' m) ∧
      le'.get Arm64Program.___a64_l_result__3 = some (.Vlong (-value)) ∧
      ∀ id ∈ retained, le'.get id = le.get id := by
  refine ⟨?count,?temps,?execution,?word,?kept⟩
  case execution => run_tac numericSteps ``ReadEntry.writer true
  case word => simp only [CC.PTree.gss,CC.Integers.Int64.and,CC.Integers.MI.and,
      CC.Integers.Int64.sub,CC.Integers.MI.sub,full_mask,BitVec.zero_sub] <;> rfl
  case kept =>
    intro id inside
    change (finalTemps le (-value)).get id = le.get id
    exact final_kept le (-value) id inside

/-- Execute the actual width-eight preparation and case65 arithmetic through
its result copy and inner-loop exit, retaining the original caller and heap. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (op : le.get Arm64Program.___kprog_a64_cneg_op = some (.Vlong (65#64)))
    (readValue : le.get Arm64Program.___kprog_a64_cneg_value = some (.Vlong value))
    (wide : le.get Arm64Program.___a64_l_width = some (.Vint (8#32))) (taken : Bool)
    (flag : le.get Arm64Program.___kprog_a64_cneg_taken =
      some (.Vint ((BitVec.ofBool taken).setWidth 32))) :
    ∃ count le', InternalRun world count
      (.State Arm64Nop.handler Condition.after (ReadEntry.tailCont k) e le m)
      (.State Arm64Nop.handler ReadEntry.writer k e le' m) ∧
      le'.get Arm64Program.___a64_l_result__3 = some (.Vlong (if taken then -value else value)) ∧
      ∀ id ∈ retained, le'.get id = le.get id := by
  obtain ⟨first,prepared⟩ := prepare world e le m k wide
  cases taken with
  | false =>
    obtain ⟨second,le',run,word,kept⟩ := compute_false world e le m k value op readValue wide flag
    exact ⟨first+second,le',prepared.trans run,word,kept⟩
  | true =>
    obtain ⟨second,le',run,word,kept⟩ := compute_true world e le m k value op readValue wide flag
    exact ⟨first+second,le',prepared.trans run,word,kept⟩

end KProgFormal.ClightRefinement.Arm64Cneg.Numeric
