import KProgFormal.ClightRefinement.Arm64CntPath

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Dispatch

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
      unless actual.isAppOfArity ctor arity do throwError "original CNT dispatch constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let width ← peel body[0]! ``CC.Stmt.Ssequence 2
    let mut rest := body[1]!
    let mut gates := #[]
    for _ in [:38] do
      let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      let test ← if node.isAppOfArity ``CC.Stmt.Ssequence 2 then do
        let seq := node.getAppArgs
        node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf seq[1]!)
        Lean.Meta.mkAppM ``Option.some #[seq[0]!]
      else pure (Lean.mkApp (Lean.mkConst ``Option.none [0]) (Lean.mkConst ``CC.Stmt))
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original CNT dispatch gate changed"
      let args := node.getAppArgs
      gates := gates.push (← Lean.Meta.mkAppM ``Gate.mk #[test,args[0]!,args[1]!])
      rest := args[2]!
    let rows ← Lean.Meta.mkListLit (Lean.mkConst ``Gate) gates.toList
    Lean.Elab.Tactic.closeMainGoal `actual_cnt_dispatch
      (← Lean.Meta.mkAppM ``Parts.mk #[width[0]!,width[1]!,rows,rest])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cnt_dispatch_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

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
private def branch20 : CC.Stmt := by run_tac cachePart (← `((parts.gates[20]'(by decide +kernel)).branch))
private def test21 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[21]'(by decide +kernel)).test))
private def condition21 : CC.Expr := by run_tac cachePart (← `((parts.gates[21]'(by decide +kernel)).condition))
private def branch21 : CC.Stmt := by run_tac cachePart (← `((parts.gates[21]'(by decide +kernel)).branch))
private def test22 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[22]'(by decide +kernel)).test))
private def condition22 : CC.Expr := by run_tac cachePart (← `((parts.gates[22]'(by decide +kernel)).condition))
private def branch22 : CC.Stmt := by run_tac cachePart (← `((parts.gates[22]'(by decide +kernel)).branch))
private def test23 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[23]'(by decide +kernel)).test))
private def condition23 : CC.Expr := by run_tac cachePart (← `((parts.gates[23]'(by decide +kernel)).condition))
private def branch23 : CC.Stmt := by run_tac cachePart (← `((parts.gates[23]'(by decide +kernel)).branch))
private def test24 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[24]'(by decide +kernel)).test))
private def condition24 : CC.Expr := by run_tac cachePart (← `((parts.gates[24]'(by decide +kernel)).condition))
private def branch24 : CC.Stmt := by run_tac cachePart (← `((parts.gates[24]'(by decide +kernel)).branch))
private def test25 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[25]'(by decide +kernel)).test))
private def condition25 : CC.Expr := by run_tac cachePart (← `((parts.gates[25]'(by decide +kernel)).condition))
private def branch25 : CC.Stmt := by run_tac cachePart (← `((parts.gates[25]'(by decide +kernel)).branch))
private def test26 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[26]'(by decide +kernel)).test))
private def condition26 : CC.Expr := by run_tac cachePart (← `((parts.gates[26]'(by decide +kernel)).condition))
private def branch26 : CC.Stmt := by run_tac cachePart (← `((parts.gates[26]'(by decide +kernel)).branch))
private def test27 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[27]'(by decide +kernel)).test))
private def condition27 : CC.Expr := by run_tac cachePart (← `((parts.gates[27]'(by decide +kernel)).condition))
private def branch27 : CC.Stmt := by run_tac cachePart (← `((parts.gates[27]'(by decide +kernel)).branch))
private def test28 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[28]'(by decide +kernel)).test))
private def condition28 : CC.Expr := by run_tac cachePart (← `((parts.gates[28]'(by decide +kernel)).condition))
private def branch28 : CC.Stmt := by run_tac cachePart (← `((parts.gates[28]'(by decide +kernel)).branch))
private def test29 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[29]'(by decide +kernel)).test))
private def condition29 : CC.Expr := by run_tac cachePart (← `((parts.gates[29]'(by decide +kernel)).condition))
private def branch29 : CC.Stmt := by run_tac cachePart (← `((parts.gates[29]'(by decide +kernel)).branch))
private def test30 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[30]'(by decide +kernel)).test))
private def condition30 : CC.Expr := by run_tac cachePart (← `((parts.gates[30]'(by decide +kernel)).condition))
private def branch30 : CC.Stmt := by run_tac cachePart (← `((parts.gates[30]'(by decide +kernel)).branch))
private def test31 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[31]'(by decide +kernel)).test))
private def condition31 : CC.Expr := by run_tac cachePart (← `((parts.gates[31]'(by decide +kernel)).condition))
private def branch31 : CC.Stmt := by run_tac cachePart (← `((parts.gates[31]'(by decide +kernel)).branch))
private def test32 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[32]'(by decide +kernel)).test))
private def condition32 : CC.Expr := by run_tac cachePart (← `((parts.gates[32]'(by decide +kernel)).condition))
private def branch32 : CC.Stmt := by run_tac cachePart (← `((parts.gates[32]'(by decide +kernel)).branch))
private def test33 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[33]'(by decide +kernel)).test))
private def condition33 : CC.Expr := by run_tac cachePart (← `((parts.gates[33]'(by decide +kernel)).condition))
private def branch33 : CC.Stmt := by run_tac cachePart (← `((parts.gates[33]'(by decide +kernel)).branch))
private def test34 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[34]'(by decide +kernel)).test))
private def condition34 : CC.Expr := by run_tac cachePart (← `((parts.gates[34]'(by decide +kernel)).condition))
private def branch34 : CC.Stmt := by run_tac cachePart (← `((parts.gates[34]'(by decide +kernel)).branch))
private def test35 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[35]'(by decide +kernel)).test))
private def condition35 : CC.Expr := by run_tac cachePart (← `((parts.gates[35]'(by decide +kernel)).condition))
private def branch35 : CC.Stmt := by run_tac cachePart (← `((parts.gates[35]'(by decide +kernel)).branch))
private def test36 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[36]'(by decide +kernel)).test))
private def condition36 : CC.Expr := by run_tac cachePart (← `((parts.gates[36]'(by decide +kernel)).condition))

private def branch36 : CC.Stmt := by run_tac cachePart (← `((parts.gates[36]'(by decide +kernel)).branch))
private def test37 : Option CC.Stmt := by run_tac cachePart (← `((parts.gates[37]'(by decide +kernel)).test))
private def condition37 : CC.Expr := by run_tac cachePart (← `((parts.gates[37]'(by decide +kernel)).condition))

private def gate (test : Option CC.Stmt) (condition : CC.Expr) (branch alternative : CC.Stmt) : CC.Stmt :=
  match test with
  | none => .Sifthenelse condition branch alternative
  | some test => .Ssequence test (.Sifthenelse condition branch alternative)
private def gate37 : CC.Stmt := gate test37 condition37 Path.statement alternative
private def gate36 : CC.Stmt := gate test36 condition36 branch36 gate37
private def gate35 : CC.Stmt := gate test35 condition35 branch35 gate36
private def gate34 : CC.Stmt := gate test34 condition34 branch34 gate35
private def gate33 : CC.Stmt := gate test33 condition33 branch33 gate34
private def gate32 : CC.Stmt := gate test32 condition32 branch32 gate33
private def gate31 : CC.Stmt := gate test31 condition31 branch31 gate32
private def gate30 : CC.Stmt := gate test30 condition30 branch30 gate31
private def gate29 : CC.Stmt := gate test29 condition29 branch29 gate30
private def gate28 : CC.Stmt := gate test28 condition28 branch28 gate29
private def gate27 : CC.Stmt := gate test27 condition27 branch27 gate28
private def gate26 : CC.Stmt := gate test26 condition26 branch26 gate27
private def gate25 : CC.Stmt := gate test25 condition25 branch25 gate26
private def gate24 : CC.Stmt := gate test24 condition24 branch24 gate25
private def gate23 : CC.Stmt := gate test23 condition23 branch23 gate24
private def gate22 : CC.Stmt := gate test22 condition22 branch22 gate23
private def gate21 : CC.Stmt := gate test21 condition21 branch21 gate22
private def gate20 : CC.Stmt := gate test20 condition20 branch20 gate21
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

/-- The original outer loop, with the first thirty-eight gates and actual CNT branch. -/
theorem body_source : Arm64Nop.handler.fn_body = .Sloop body .Sbreak := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def widthCont (k : CC.Cont) : CC.Cont := .Kseq widthSet (.Kseq gate0 (continuation k))

private theorem width_binding :
    CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._arm64_width_effective = some (CC.Positive.ofNat 97) ∧
    CC.Genv.findFunctPtr Arm64ProgramEntryLinked.ge.genv_genv (CC.Positive.ofNat 97) =
      some (.Internal Arm64Program.f_arm64_width_effective) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem enter_width (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8))) :
    InternalRun Arm64ProgramEntryLinked.ge 4
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.Callstate (.Internal Arm64Program.f_arm64_width_effective) [Arm64Width.argument (8#8)]
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m) := by
  have binding := width_binding
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
    (op : le.get Arm64Program._op = some (.Vint (36#32))) :
    ∃ count le', InternalRun Arm64ProgramEntryLinked.ge count
      (.Returnstate (Arm64Width.result (8#8))
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m)
      (.State Arm64Nop.handler Path.statement (continuation k) e le' m) ∧
      le'.get Arm64Program.___a64_l_width = some (.Vint (8#32)) ∧
      ∀ id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
        Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,Arm64Program._imm], le'.get id = le.get id := by
  refine ⟨?count,?temps,?execution,?width,?kept⟩
  case execution => run_tac Lean.Meta.withAssignableSyntheticOpaque do
      let mut finished := false
      for i in [:300] do
        let goal ← Lean.Elab.Tactic.getMainTarget
        let args := goal.getAppArgs
        let state ← Lean.instantiateMVars args[2]!
        if state.isAppOfArity ``CC.State.State 6 && state.getAppArgs[1]!.isConstOf ``Path.statement then
          Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
          Lean.logInfo m!"actual CNT dispatch after-width transitions: {i}"
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
          gate0,gate1,gate2,gate3,gate4,gate5,gate6,gate7,gate8,gate9,gate10,gate11,gate12,gate13,gate14,gate15,gate16,gate17,gate18,gate19,gate20,gate21,gate22,gate23,gate24,gate25,gate26,gate27,gate28,gate29,gate30,gate31,gate32,gate33,gate34,gate35,gate36,gate37,test0,condition0,test1,condition1,test2,condition2,test3,condition3,test4,condition4,test5,condition5,test6,condition6,test7,condition7,test8,condition8,test9,condition9,test10,condition10,test11,condition11,test12,condition12,test13,condition13,test14,condition14,test15,condition15,test16,condition16,test17,condition17,test18,condition18,test19,condition19,test20,condition20,test21,condition21,test22,condition22,test23,condition23,test24,condition24,test25,condition25,test26,condition26,test27,condition27,test28,condition28,test29,condition29,test30,condition30,test31,condition31,test32,condition32,test33,condition33,test34,condition34,test35,condition35,test36,condition36,test37,condition37, Arm64Width.result, Arm64Width.argument, CC.PTree.gss,
          CC.PTree.gso, op, CC.doEvalExpr, CC.typeof, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
          CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
          CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
          CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool,
          CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq,
          CC.Integers.MI.eq, CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.unsigned,
          CC.Integers.MI.unsigned, CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one, CC.E0,
          CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
          Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
      unless finished do throwError "CNT dispatch did not reach its original branch"
  case width => simp +decide only [CC.PTree.gss,CC.PTree.gso]
  case kept =>
    intro id original
    simp at original
    rcases original with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals simp +decide only [CC.PTree.gso]

/-- The real linked width helper and the first thirty-eight original dispatch gates reach CNT128;
only genuine dispatch temporaries change, and the full heap is unchanged. -/
theorem body_dispatch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (op : le.get Arm64Program._op = some (.Vint (36#32))) :
    ∃ count le', InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler Path.statement (continuation k) e le' m) ∧
      le'.get Arm64Program.___a64_l_width = some (.Vint (8#32)) ∧
      ∀ id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
        Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,Arm64Program._imm], le'.get id = le.get id := by
  have enter := enter_width e le m k unshadowed flags
  have helper := Arm64Width.internal Arm64ProgramEntryLinked.ge (8#8)
    (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m
  obtain ⟨count,le',choose,width,kept⟩ := after_width e le m k op
  exact ⟨_,le',by simpa only [CC.callCont] using (enter.trans helper).trans choose,width,kept⟩

end KProgFormal.ClightRefinement.Arm64Cnt.Dispatch
