import KProgFormal.ClightRefinement.Arm64OrnPath

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Orn.Dispatch

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
      unless actual.isAppOfArity ctor arity do throwError "original ORN dispatch constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let width ← peel body[0]! ``CC.Stmt.Ssequence 2
    let mut rest := body[1]!
    let mut gates := #[]
    for _ in [:21] do
      let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      let test ← if node.isAppOfArity ``CC.Stmt.Ssequence 2 then do
        let seq := node.getAppArgs
        node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf seq[1]!)
        Lean.Meta.mkAppM ``Option.some #[seq[0]!]
      else pure (Lean.mkApp (Lean.mkConst ``Option.none [0]) (Lean.mkConst ``CC.Stmt))
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original ORN dispatch gate changed"
      let args := node.getAppArgs
      gates := gates.push (← Lean.Meta.mkAppM ``Gate.mk #[test,args[0]!,args[1]!])
      rest := args[2]!
    let rows ← Lean.Meta.mkListLit (Lean.mkConst ``Gate) gates.toList
    Lean.Elab.Tactic.closeMainGoal `actual_orn_dispatch
      (← Lean.Meta.mkAppM ``Parts.mk #[width[0]!,width[1]!,rows,rest])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_orn_dispatch_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

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
private def branch8 : CC.Stmt := by run_tac cachePart (← `((parts.gates[8]'(by decide +kernel)).branch))
private def test9 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[9]'(by decide +kernel)).test))
private def condition9 : CC.Expr := by run_tac cachePart (← `((parts.gates[9]'(by decide +kernel)).condition))
private def branch9 : CC.Stmt := by run_tac cachePart (← `((parts.gates[9]'(by decide +kernel)).branch))
private def test10 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[10]'(by decide +kernel)).test))
private def condition10 : CC.Expr := by run_tac cachePart (← `((parts.gates[10]'(by decide +kernel)).condition))
private def branch10 : CC.Stmt := by run_tac cachePart (← `((parts.gates[10]'(by decide +kernel)).branch))
private def test11 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[11]'(by decide +kernel)).test))
private def condition11 : CC.Expr := by run_tac cachePart (← `((parts.gates[11]'(by decide +kernel)).condition))
private def branch11 : CC.Stmt := by run_tac cachePart (← `((parts.gates[11]'(by decide +kernel)).branch))
private def test12 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[12]'(by decide +kernel)).test))
private def condition12 : CC.Expr := by run_tac cachePart (← `((parts.gates[12]'(by decide +kernel)).condition))
private def branch12 : CC.Stmt := by run_tac cachePart (← `((parts.gates[12]'(by decide +kernel)).branch))
private def test13 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[13]'(by decide +kernel)).test))
private def condition13 : CC.Expr := by run_tac cachePart (← `((parts.gates[13]'(by decide +kernel)).condition))
private def branch13 : CC.Stmt := by run_tac cachePart (← `((parts.gates[13]'(by decide +kernel)).branch))
private def test14 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[14]'(by decide +kernel)).test))
private def condition14 : CC.Expr := by run_tac cachePart (← `((parts.gates[14]'(by decide +kernel)).condition))
private def branch14 : CC.Stmt := by run_tac cachePart (← `((parts.gates[14]'(by decide +kernel)).branch))
private def test15 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[15]'(by decide +kernel)).test))
private def condition15 : CC.Expr := by run_tac cachePart (← `((parts.gates[15]'(by decide +kernel)).condition))
private def branch15 : CC.Stmt := by run_tac cachePart (← `((parts.gates[15]'(by decide +kernel)).branch))
private def test16 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[16]'(by decide +kernel)).test))
private def condition16 : CC.Expr := by run_tac cachePart (← `((parts.gates[16]'(by decide +kernel)).condition))
private def branch16 : CC.Stmt := by run_tac cachePart (← `((parts.gates[16]'(by decide +kernel)).branch))
private def test17 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[17]'(by decide +kernel)).test))
private def condition17 : CC.Expr := by run_tac cachePart (← `((parts.gates[17]'(by decide +kernel)).condition))
private def branch17 : CC.Stmt := by run_tac cachePart (← `((parts.gates[17]'(by decide +kernel)).branch))
private def test18 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[18]'(by decide +kernel)).test))
private def condition18 : CC.Expr := by run_tac cachePart (← `((parts.gates[18]'(by decide +kernel)).condition))
private def branch18 : CC.Stmt := by run_tac cachePart (← `((parts.gates[18]'(by decide +kernel)).branch))
private def test19 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[19]'(by decide +kernel)).test))
private def condition19 : CC.Expr := by run_tac cachePart (← `((parts.gates[19]'(by decide +kernel)).condition))
private def branch19 : CC.Stmt := by run_tac cachePart (← `((parts.gates[19]'(by decide +kernel)).branch))
private def test20 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[20]'(by decide +kernel)).test))
private def condition20 : CC.Expr := by run_tac cachePart (← `((parts.gates[20]'(by decide +kernel)).condition))

private def gate (test : Option CC.Stmt) (condition : CC.Expr) (branch alternative : CC.Stmt) : CC.Stmt :=
  match test with
  | none => .Sifthenelse condition branch alternative
  | some test => .Ssequence test (.Sifthenelse condition branch alternative)
private def gate20 : CC.Stmt := gate test20 condition20 ReadEntry.branch alternative
private def gate19 : CC.Stmt := gate test19 condition19 branch19 gate20
private def gate18 : CC.Stmt := gate test18 condition18 branch18 gate19
private def gate17 : CC.Stmt := gate test17 condition17 branch17 gate18
private def gate16 : CC.Stmt := gate test16 condition16 branch16 gate17
private def gate15 : CC.Stmt := gate test15 condition15 branch15 gate16
private def gate14 : CC.Stmt := gate test14 condition14 branch14 gate15
private def gate13 : CC.Stmt := gate test13 condition13 branch13 gate14
private def gate12 : CC.Stmt := gate test12 condition12 branch12 gate13
private def gate11 : CC.Stmt := gate test11 condition11 branch11 gate12
private def gate10 : CC.Stmt := gate test10 condition10 branch10 gate11
private def gate9 : CC.Stmt := gate test9 condition9 branch9 gate10
private def gate8 : CC.Stmt := gate test8 condition8 branch8 gate9
private def gate7 : CC.Stmt := gate test7 condition7 branch7 gate8
private def gate6 : CC.Stmt := gate test6 condition6 branch6 gate7
private def gate5 : CC.Stmt := gate test5 condition5 branch5 gate6
private def gate4 : CC.Stmt := gate test4 condition4 branch4 gate5
private def gate3 : CC.Stmt := gate test3 condition3 branch3 gate4
private def gate2 : CC.Stmt := gate test2 condition2 branch2 gate3
private def gate1 : CC.Stmt := gate test1 condition1 branch1 gate2
private def gate0 : CC.Stmt := gate test0 condition0 branch0 gate1

def body : CC.Stmt := .Ssequence (.Ssequence widthCall widthSet) gate0

/-- The original outer loop, with the first twenty-one gates and actual ORN branch. -/
theorem body_source : Arm64Nop.handler.fn_body = .Sloop body .Sbreak := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def widthCont (k : CC.Cont) : CC.Cont := .Kseq widthSet (.Kseq gate0 (continuation k))

private theorem enter_width (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (4#8))) :
    InternalRun Arm64ProgramEntryLinked.ge 4
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.Callstate (.Internal Arm64Program.f_arm64_width_effective) [Arm64Width.argument (4#8)]
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
    (op : le.get Arm64Program._op = some (.Vint (53#32))) :
    ∃ count le', InternalRun Arm64ProgramEntryLinked.ge count
      (.Returnstate (Arm64Width.result (4#8))
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m)
      (.State Arm64Nop.handler ReadEntry.branch (continuation k) e le' m) ∧
      le'.get Arm64Program.___a64_l_width = some (.Vint (4#32)) ∧
      ∀ id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
        Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op], le'.get id = le.get id := by
  refine ⟨?count,?temps,?execution,?width,?kept⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
      let mut finished := false
      for i in [:300] do
        let goal ← Lean.Elab.Tactic.getMainTarget
        let args := goal.getAppArgs
        let state ← Lean.instantiateMVars args[2]!
        if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``ReadEntry.branch then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual ORN dispatch after-width transitions: {i}"
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
          gate0, gate1, gate2, gate3, gate4, gate5, gate6, gate7, gate8, gate9, gate10, gate11, gate12, gate13, gate14, gate15, gate16, gate17, gate18, gate19, gate20, test0, condition0, test1, condition1, test2, condition2, test3, condition3, test4, condition4, test5, condition5, test6, condition6, test7, condition7, test8, condition8, test9, condition9, test10, condition10, test11, condition11, test12, condition12, test13, condition13, test14, condition14, test15, condition15, test16, condition16, test17, condition17, test18, condition18, test19, condition19, test20, condition20, Arm64Width.result, Arm64Width.argument, CC.PTree.gss,
          CC.PTree.gso, op, CC.doEvalExpr, CC.typeof, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
          CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
          CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
          CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool,
          CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq,
          CC.Integers.MI.eq, CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.unsigned,
          CC.Integers.MI.unsigned, CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one, CC.E0,
          CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
          Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
      unless finished do throwError "ORN dispatch did not reach its original branch"
  case width => simp +decide only [CC.PTree.gss,CC.PTree.gso]
  case kept =>
    intro id original
    simp at original
    rcases original with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals simp +decide only [CC.PTree.gso]

/-- The real linked width helper and the first twenty-one original dispatch gates reach ORN32;
only genuine dispatch temporaries change, and the full heap is unchanged. -/
theorem body_dispatch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (4#8)))
    (op : le.get Arm64Program._op = some (.Vint (53#32))) :
    ∃ count le', InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler ReadEntry.branch (continuation k) e le' m) ∧
      le'.get Arm64Program.___a64_l_width = some (.Vint (4#32)) ∧
      ∀ id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
        Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op], le'.get id = le.get id := by
  have enter := enter_width e le m k unshadowed flags
  have helper := Arm64Width.internal Arm64ProgramEntryLinked.ge (4#8)
    (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m
  obtain ⟨count,le',choose,width,kept⟩ := after_width e le m k op
  exact ⟨_,le',by simpa only [CC.callCont] using (enter.trans helper).trans choose,width,kept⟩

end KProgFormal.ClightRefinement.Arm64Orn.Dispatch
