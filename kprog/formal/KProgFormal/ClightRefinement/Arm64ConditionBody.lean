import KProgFormal.ClightRefinement.Arm64ConditionEq

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ConditionAll

abbrev handler := Arm64Program.f_kprog_arm64_program_condition
def body : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none
    Lean.Elab.Tactic.closeMainGoal `actual_condition_body
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private theorem body_source : handler.fn_body = body := rfl
theorem return_type : handler.fn_return = CC.tint := rfl
theorem empty_elements : (CC.PTree.empty : CC.Env).elements = [] := rfl
theorem ptr_zero : ((0 : CC.Integers.Ptrofs).toNat : Int) = 0 := by decide +kernel

def arguments (condition : Nat) (blocks : Fin 4 → CC.Block) : List CC.Val :=
  [.Vlong (BitVec.ofNat 64 condition),.Vptr (blocks 0) 0,.Vptr (blocks 1) 0,
    .Vptr (blocks 2) 0,.Vptr (blocks 3) 0]
def temps (condition : Nat) (blocks : Fin 4 → CC.Block) : CC.TempEnv :=
  (((((CC.createUndefTemps handler.fn_temps).set Arm64Program._cond (.Vlong (BitVec.ofNat 64 condition))).set
    Arm64Program._n (.Vptr (blocks 0) 0)).set Arm64Program._z (.Vptr (blocks 1) 0)).set
    Arm64Program._c (.Vptr (blocks 2) 0)).set Arm64Program._v (.Vptr (blocks 3) 0)

theorem enter (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (condition : Nat) (blocks : Fin 4 → CC.Block) :
    InternalRun world 1 (.Callstate (.Internal handler) (arguments condition blocks) k m)
      (.State handler body k CC.emptyEnv (temps condition blocks) m) := by
  have entry : CC.FunctionEntry2 world handler (arguments condition blocks) m
      CC.emptyEnv (temps condition blocks) m :=
    .intro (by decide +kernel) (by decide +kernel) (by decide +kernel) (by exact .nil _ _) rfl
  rw [← body_source]
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entry) (.refl _)

theorem bit_cases : ∀ b : BitVec 1, b = (0#1) ∨ b = (1#1) := by decide +kernel

set_option hygiene false in
def executeBody : Lean.Elab.Tactic.TacticM Unit :=
  Lean.Meta.withAssignableSyntheticOpaque do
    let mut finished := false
    for i in [:120] do
      let goal ← Lean.Elab.Tactic.getMainTarget
      let state ← Lean.instantiateMVars goal.getAppArgs[2]!
      if state.isAppOfArity ``CC.State.Returnstate 3 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
        Lean.logInfo m!"actual condition body transitions: {i}"
        finished := true
        break
      if state.isAppOfArity ``CC.State.State 6 then
        if let .const name _ := state.getAppArgs[1]! then
          if let .defnInfo _ ← Lean.getConstInfo name then
            let alias := Lean.mkIdent name
            Lean.Elab.Tactic.evalTactic (← `(tactic| unfold $alias:ident))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,
        CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.Mem.loadv,CC.accessMode,CC.typeof,ptr_zero,BitVec.toNat_zero,
        temps,CC.PTree.gss,CC.PTree.gso,CC.setOpttemp,readN,readZ,readC,readV,
        CC.Cop.semUnaryOperation,CC.Cop.semNotbool,CC.Cop.semBinaryOperation,
        CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
        CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,
        CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.Archi.ptr64,
        CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
        CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,
        CC.Integers.Int.cmp,CC.Integers.MI.cmp,CC.Integers.Int.cmpu,CC.Integers.Int64.cmpu,CC.Integers.MI.cmpu,
        CC.Integers.Int.eq,CC.Integers.Int64.eq,CC.Integers.MI.eq,
        CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
        CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int64.repr,
        CC.Integers.Int.unsigned,CC.Integers.Int64.unsigned,
        CC.Integers.Int.zero,CC.Integers.Int.one,CC.Integers.MI.zero,CC.Integers.MI.one,
        CC.blocksOfEnv,CC.emptyEnv,CC.Mem.freeList,empty_elements,return_type,
        ite_true,ite_false,eq_self,Bool.false_eq_true,Bool.true_eq_false,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
      let remaining ← Lean.Elab.Tactic.getMainTarget
      unless remaining.isAppOfArity ``InternalRun 4 do
        throwError m!"original condition step {i} remains unresolved: {remaining}"
    unless finished do throwError "actual original condition body did not return"

set_option hygiene false in
theorem body0 (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont)
    (blocks : Fin 4 → CC.Block) (s : Reference.AArch64.State) (n z c v : BitVec 1)
    (readN : CC.Mem.load .Mint8unsigned m (blocks 0) 0 = some (.Vint (n.setWidth 32)))
    (readZ : CC.Mem.load .Mint8unsigned m (blocks 1) 0 = some (.Vint (z.setWidth 32)))
    (readC : CC.Mem.load .Mint8unsigned m (blocks 2) 0 = some (.Vint (c.setWidth 32)))
    (readV : CC.Mem.load .Mint8unsigned m (blocks 3) 0 = some (.Vint (v.setWidth 32)))
    (nativeN : read_flag .N s.machine = n) (nativeZ : read_flag .Z s.machine = z)
    (nativeC : read_flag .C s.machine = c) (nativeV : read_flag .V s.machine = v) :
    ∃ count, InternalRun world count
      (.State handler body k CC.emptyEnv (temps 0 blocks) m)
      (.Returnstate (.Vint (if ConditionHolds (0#4) s.machine then 1#32 else 0#32)) (CC.callCont k) m) := by
  rcases bit_cases n with rfl|rfl <;> rcases bit_cases z with rfl|rfl <;>
    rcases bit_cases c with rfl|rfl <;> rcases bit_cases v with rfl|rfl
  all_goals
    simp +decide only [ConditionHolds,nativeN,nativeZ,nativeC,nativeV,ite_true,ite_false]
    refine ⟨?_,?_⟩
    run_tac do
      let goals ← Lean.Elab.Tactic.getGoals
      match goals with
      | count :: execution :: rest => Lean.Elab.Tactic.setGoals (execution :: count :: rest)
      | _ => throwError "condition execution requires its fresh count and run goals"
      executeBody


end KProgFormal.ClightRefinement.Arm64ConditionAll
