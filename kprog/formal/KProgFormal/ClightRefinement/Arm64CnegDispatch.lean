import KProgFormal.ClightRefinement.Arm64CnegPath

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cneg.Dispatch

private structure Gate where
  test : Option CC.Stmt
  condition : CC.Expr
  branch : CC.Stmt
private structure Parts where
  widthCall : CC.Stmt
  widthSet : CC.Stmt
  gates : List Gate
  alternative : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original CNEG dispatch constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let width ← peel body[0]! ``CC.Stmt.Ssequence 2
    let mut rest := body[1]!
    let mut gates := #[]
    for _ in [:9] do
      let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      let test ← if node.isAppOfArity ``CC.Stmt.Ssequence 2 then do
        let seq := node.getAppArgs
        node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf seq[1]!)
        Lean.Meta.mkAppM ``Option.some #[seq[0]!]
      else pure (Lean.mkApp (Lean.mkConst ``Option.none [0]) (Lean.mkConst ``CC.Stmt))
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original CNEG dispatch gate changed"
      let args := node.getAppArgs
      gates := gates.push (← Lean.Meta.mkAppM ``Gate.mk #[test,args[0]!,args[1]!])
      rest := args[2]!
    let rows ← Lean.Meta.mkListLit (Lean.mkConst ``Gate) gates.toList
    Lean.Elab.Tactic.closeMainGoal `actual_cneg_dispatch
      (← Lean.Meta.mkAppM ``Parts.mk #[width[0]!,width[1]!,rows,rest])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cneg_dispatch_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def widthCall : CC.Stmt := by run_tac cachePart (← `(parts.widthCall))
private def widthSet : CC.Stmt := by run_tac cachePart (← `(parts.widthSet))
private def alternative : CC.Stmt := by run_tac cachePart (← `(parts.alternative))
private def test0 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[0]'(by decide +kernel)).test))
private def condition0 : CC.Expr := by run_tac cachePart (← `((parts.gates[0]'(by decide +kernel)).condition))
private def branch0 : CC.Stmt := by run_tac cachePart (← `((parts.gates[0]'(by decide +kernel)).branch))
private def test1 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[1]'(by decide +kernel)).test))
private def condition1 : CC.Expr := by run_tac cachePart (← `((parts.gates[1]'(by decide +kernel)).condition))
private def branch1 : CC.Stmt := by run_tac cachePart (← `((parts.gates[1]'(by decide +kernel)).branch))
private def test2 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[2]'(by decide +kernel)).test))
private def condition2 : CC.Expr := by run_tac cachePart (← `((parts.gates[2]'(by decide +kernel)).condition))
private def branch2 : CC.Stmt := by run_tac cachePart (← `((parts.gates[2]'(by decide +kernel)).branch))
private def test3 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[3]'(by decide +kernel)).test))
private def condition3 : CC.Expr := by run_tac cachePart (← `((parts.gates[3]'(by decide +kernel)).condition))
private def branch3 : CC.Stmt := by run_tac cachePart (← `((parts.gates[3]'(by decide +kernel)).branch))
private def test4 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[4]'(by decide +kernel)).test))
private def condition4 : CC.Expr := by run_tac cachePart (← `((parts.gates[4]'(by decide +kernel)).condition))
private def branch4 : CC.Stmt := by run_tac cachePart (← `((parts.gates[4]'(by decide +kernel)).branch))
private def test5 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[5]'(by decide +kernel)).test))
private def condition5 : CC.Expr := by run_tac cachePart (← `((parts.gates[5]'(by decide +kernel)).condition))
private def branch5 : CC.Stmt := by run_tac cachePart (← `((parts.gates[5]'(by decide +kernel)).branch))
private def test6 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[6]'(by decide +kernel)).test))
private def condition6 : CC.Expr := by run_tac cachePart (← `((parts.gates[6]'(by decide +kernel)).condition))
private def branch6 : CC.Stmt := by run_tac cachePart (← `((parts.gates[6]'(by decide +kernel)).branch))
private def test7 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[7]'(by decide +kernel)).test))
private def condition7 : CC.Expr := by run_tac cachePart (← `((parts.gates[7]'(by decide +kernel)).condition))
private def branch7 : CC.Stmt := by run_tac cachePart (← `((parts.gates[7]'(by decide +kernel)).branch))
private def test8 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[8]'(by decide +kernel)).test))
private def condition8 : CC.Expr := by run_tac cachePart (← `((parts.gates[8]'(by decide +kernel)).condition))

private def gate (test : Option CC.Stmt) (condition : CC.Expr) (branch alternative : CC.Stmt) : CC.Stmt :=
  match test with
  | none => .Sifthenelse condition branch alternative
  | some test => .Ssequence test (.Sifthenelse condition branch alternative)
private def gate8 : CC.Stmt := gate test8 condition8 ReadEntry.branch alternative
private def gate7 : CC.Stmt := gate test7 condition7 branch7 gate8
private def gate6 : CC.Stmt := gate test6 condition6 branch6 gate7
private def gate5 : CC.Stmt := gate test5 condition5 branch5 gate6
private def gate4 : CC.Stmt := gate test4 condition4 branch4 gate5
private def gate3 : CC.Stmt := gate test3 condition3 branch3 gate4
private def gate2 : CC.Stmt := gate test2 condition2 branch2 gate3
private def gate1 : CC.Stmt := gate test1 condition1 branch1 gate2
private def gate0 : CC.Stmt := gate test0 condition0 branch0 gate1

def body : CC.Stmt := .Ssequence (.Ssequence widthCall widthSet) gate0

/-- The original outer loop, with the first nine gates and actual CNEG branch. -/
theorem body_source : Arm64Nop.handler.fn_body = .Sloop body .Sbreak := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def widthCont (k : CC.Cont) : CC.Cont := .Kseq widthSet (.Kseq gate0 (continuation k))

private theorem enter_width (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8))) :
    InternalRun Arm64ProgramEntryLinked.ge 4
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.Callstate (.Internal Arm64Program.f_arm64_width_effective) [Arm64Width.argument (8#8)]
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m) := by
  have binding := Arm64AddImmediate.Dispatch.Linked.width_binding
  apply internalRun_of_steps
  · simp [InternalPath,InternalState,CC.doStep,body_source,body,widthCall,widthCont,continuation,
      flags,unshadowed,binding.1,binding.2,Arm64Width.cast_argument,
      CC.doEvalExpr,CC.doEvalExprlist,CC.Cop.classifyFun,CC.typeof,CC.lvalOfVar,CC.doDerefLoc,
      CC.accessMode,CC.Genv.findFunct,CC.typeOfFundef,CC.typeOfFunction,CC.typeOfParams,
      Arm64Program.f_arm64_width_effective,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero]
  · simp [steps,CC.doStep,body_source,body,widthCall,widthCont,continuation,
      flags,unshadowed,binding.1,binding.2,Arm64Width.cast_argument,
      CC.doEvalExpr,CC.doEvalExprlist,CC.Cop.classifyFun,CC.typeof,CC.lvalOfVar,CC.doDerefLoc,
      CC.accessMode,CC.Genv.findFunct,CC.typeOfFundef,CC.typeOfFunction,CC.typeOfParams,
      Arm64Program.f_arm64_width_effective,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero,CC.E0,CC.Eapp]

set_option hygiene false in
private theorem after_width (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (op : le.get Arm64Program._op = some (.Vint (65#32))) :
    ∃ count le', InternalRun Arm64ProgramEntryLinked.ge count
      (.Returnstate (Arm64Width.result (8#8))
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m)
      (.State Arm64Nop.handler ReadEntry.branch (continuation k) e le' m) ∧
      le'.get Arm64Program.___a64_l_width = some (.Vint (8#32)) ∧
      ∀ id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
        Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op], le'.get id = le.get id := by
  refine ⟨?count,?temps,?execution,?width,?kept⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
      let mut finished := false
      for i in [:120] do
        let goal ← Lean.Elab.Tactic.getMainTarget
        let args := goal.getAppArgs
        let state ← Lean.instantiateMVars args[2]!
        if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``ReadEntry.branch then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual CNEG dispatch after-width transitions: {i}"
          finished := true
          break
        if state.isAppOfArity ``CC.State.State 6 then
          let stmt := state.getAppArgs[1]!
          if let .const name _ := stmt then
            if let .defnInfo _ ← Lean.getConstInfo name then
              let alias := Lean.mkIdent name
              Lean.Elab.Tactic.evalTactic (← `(tactic| unfold $alias:ident))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [
          CC.doStep, CC.setOpttemp, widthCont, continuation, widthSet, gate,
          gate0, gate1, gate2, gate3, gate4, gate5, gate6, gate7, gate8, test0, condition0, test1, condition1, test2, condition2, test3, condition3, test4, condition4, test5, condition5, test6, condition6, test7, condition7, test8, condition8, Arm64Width.result, Arm64Width.argument, CC.PTree.gss,
          CC.PTree.gso, op, CC.doEvalExpr, CC.typeof, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
          CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
          CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
          CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool,
          CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq,
          CC.Integers.MI.eq, CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.unsigned,
          CC.Integers.MI.unsigned, CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one, CC.E0,
          CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
          Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
      unless finished do throwError "CNEG dispatch did not reach its original branch"
  case width => simp +decide only [CC.PTree.gss,CC.PTree.gso]
  case kept =>
    intro id original
    simp at original
    rcases original with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals simp +decide only [CC.PTree.gso]

/-- The real linked width helper and the first nine original dispatch gates reach CNEG64;
only genuine dispatch temporaries change, and the full heap is unchanged. -/
theorem body_dispatch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (op : le.get Arm64Program._op = some (.Vint (65#32))) :
    ∃ count le', InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler ReadEntry.branch (continuation k) e le' m) ∧
      le'.get Arm64Program.___a64_l_width = some (.Vint (8#32)) ∧
      ∀ id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
        Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op], le'.get id = le.get id := by
  have enter := enter_width e le m k unshadowed flags
  have helper := Arm64Width.internal Arm64ProgramEntryLinked.ge (8#8)
    (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m
  obtain ⟨count,le',choose,width,kept⟩ := after_width e le m k op
  exact ⟨_,le',by simpa only [CC.callCont] using (enter.trans helper).trans choose,width,kept⟩

end KProgFormal.ClightRefinement.Arm64Cneg.Dispatch
