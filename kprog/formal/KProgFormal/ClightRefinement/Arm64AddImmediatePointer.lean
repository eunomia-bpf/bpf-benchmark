import KProgFormal.ClightRefinement.Arm64AddImmediateTail

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.Pointer

private structure Pieces where
  spGate : CC.Stmt
  spTest : CC.Expr
  spBranch : CC.Stmt
  orGate : CC.Stmt
  orTest : CC.Expr
  orBranch : CC.Stmt
  subGate : CC.Stmt
  subTest : CC.Expr
  subBranch : CC.Stmt
  addGate : CC.Stmt
  addTest : CC.Expr
  readCall : CC.Stmt
  writeCall : CC.Stmt
  scalar : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "actual ADD pointer selection changed"
      pure actual.getAppArgs
    let mut rest ← Lean.Elab.Term.elabTerm (← `(Tail.selection)) none
    let mut fields := #[]
    for _ in [:3] do
      let seq ← peel rest ``CC.Stmt.Ssequence 2
      let test ← peel seq[1]! ``CC.Stmt.Sifthenelse 3
      fields := fields ++ #[seq[0]!, test[0]!, test[1]!]
      rest := test[2]!
    let seq ← peel rest ``CC.Stmt.Ssequence 2
    let test ← peel seq[1]! ``CC.Stmt.Sifthenelse 3
    let selected ← peel test[1]! ``CC.Stmt.Ssequence 2
    fields := fields ++ #[seq[0]!, test[0]!, selected[0]!, selected[1]!, test[2]!]
    Lean.Elab.Tactic.closeMainGoal `actual_pointer_parts (← Lean.Meta.mkAppM ``Pieces.mk fields)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_pointer_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def spGate : CC.Stmt := by run_tac cachePart (← `(pieces.spGate))

private def spTest : CC.Expr := by run_tac cachePart (← `(pieces.spTest))

private def spBranch : CC.Stmt := by run_tac cachePart (← `(pieces.spBranch))

private def orGate : CC.Stmt := by run_tac cachePart (← `(pieces.orGate))

private def orTest : CC.Expr := by run_tac cachePart (← `(pieces.orTest))

private def orBranch : CC.Stmt := by run_tac cachePart (← `(pieces.orBranch))

private def subGate : CC.Stmt := by run_tac cachePart (← `(pieces.subGate))

private def subTest : CC.Expr := by run_tac cachePart (← `(pieces.subTest))

private def subBranch : CC.Stmt := by run_tac cachePart (← `(pieces.subBranch))

private def addGate : CC.Stmt := by run_tac cachePart (← `(pieces.addGate))

private def addTest : CC.Expr := by run_tac cachePart (← `(pieces.addTest))

def readCall : CC.Stmt := by run_tac cachePart (← `(pieces.readCall))

def writeCall : CC.Stmt := by run_tac cachePart (← `(pieces.writeCall))

def scalar : CC.Stmt := by run_tac cachePart (← `(pieces.scalar))

private def addSequence : CC.Stmt := .Ssequence addGate
  (.Sifthenelse addTest (.Ssequence readCall writeCall) scalar)
private def subSequence : CC.Stmt := .Ssequence subGate (.Sifthenelse subTest subBranch addSequence)
private def orSequence : CC.Stmt := .Ssequence orGate (.Sifthenelse orTest orBranch subSequence)

/-- Every selection gate and the selected reader/writer are original source. -/
theorem source : Tail.selection = .Ssequence spGate (.Sifthenelse spTest spBranch orSequence) := rfl

def selectedTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((((((((((le.set Arm64Program._t'30 (.Vint 0)).set Arm64Program._t'31 (.Vint 0)).set Arm64Program._t'32 (.Vint 0)).set Arm64Program._t'27 (.Vint 0)).set Arm64Program._t'28 (.Vint 0)).set Arm64Program._t'29 (.Vint 0)).set Arm64Program._t'24 (.Vint 0)).set Arm64Program._t'25 (.Vint 0)).set Arm64Program._t'26 (.Vint 0)).set Arm64Program._t'21 (.Vint 1)).set Arm64Program._t'22 (.Vint 1)).set Arm64Program._t'23 (.Vint 1))

def readCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'20) Arm64Nop.handler e (selectedTemps le) (.Kseq writeCall k)

private theorem literal32 : BitVec.ofInt 64 (↑(BitVec.ofInt 32 32).toNat : Int) = (32#64) := rfl

set_option hygiene false in
/-- The original gates select the tagged ADD branch for a non-SP destination,
retaining the computed candidate and all source temporaries. -/
theorem select (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (dst : BitVec 64) (notSP : dst ≠ 32#64)
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32)))
    (destination : le.get Arm64Program._dst = some (.Vlong dst))
    (op : le.get Arm64Program.___a64_alu_op = some (.Vint (0#32)))
    (tag : le.get Arm64Program.___a64_alu_src_tag = some (.Vint (4#32))) :
    InternalRun world 53 (.State Arm64Nop.handler Tail.selection k e le m)
      (.State Arm64Nop.handler readCall (.Kseq writeCall k) e (selectedTemps le) m) := by
  run_tac do
    for _ in [:53] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, source, spGate, spTest,
        orSequence, orGate, orTest, subSequence, subGate, subTest, addSequence, addGate, addTest,
        selectedTemps, CC.PTree.gss, CC.PTree.gso, CC.doEvalExpr, CC.typeof,
        width, destination, op, tag, notSP, literal32,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
        CC.Cop.semUnaryOperation, CC.Cop.semNotbool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool,
        CC.Integers.Int.cmpu, CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
        CC.Integers.Int.eq, CC.Integers.Int64.eq, CC.Integers.MI.eq,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int64.repr,
        CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil,
        ite_true, ite_false, eq_self, beq_iff_eq, decide_false, decide_true, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

def scalarTemps (le : CC.TempEnv) : CC.TempEnv :=
  ((((((((((((le.set Arm64Program._t'30 (.Vint 0)).set Arm64Program._t'31 (.Vint 0)).set Arm64Program._t'32 (.Vint 0)).set Arm64Program._t'27 (.Vint 0)).set Arm64Program._t'28 (.Vint 0)).set Arm64Program._t'29 (.Vint 0)).set Arm64Program._t'24 (.Vint 0)).set Arm64Program._t'25 (.Vint 0)).set Arm64Program._t'26 (.Vint 0)).set Arm64Program._t'21 (.Vint 1)).set Arm64Program._t'22 (.Vint 1)).set Arm64Program._t'23 (.Vint 0))

set_option hygiene false in
/-- The original gates select the real scalar call for a non-SP destination,
retaining the computed candidate and all source temporaries. -/
theorem select_scalar (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (dst : BitVec 64) (notSP : dst ≠ 32#64)
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32)))
    (destination : le.get Arm64Program._dst = some (.Vlong dst))
    (op : le.get Arm64Program.___a64_alu_op = some (.Vint (0#32)))
    (tag : le.get Arm64Program.___a64_alu_src_tag = some (.Vint (0#32))) :
    InternalRun world 52 (.State Arm64Nop.handler Tail.selection k e le m)
      (.State Arm64Nop.handler scalar k e (scalarTemps le) m) := by
  run_tac do
    for _ in [:52] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, source, spGate, spTest,
        orSequence, orGate, orTest, subSequence, subGate, subTest, addSequence, addGate, addTest,
        scalarTemps, CC.PTree.gss, CC.PTree.gso, CC.doEvalExpr, CC.typeof,
        width, destination, op, tag, notSP, literal32,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
        CC.Cop.semUnaryOperation, CC.Cop.semNotbool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool,
        CC.Integers.Int.cmpu, CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
        CC.Integers.Int.eq, CC.Integers.Int64.eq, CC.Integers.MI.eq,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int64.repr,
        CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil,
        ite_true, ite_false, eq_self, beq_iff_eq, decide_false, decide_true, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64AddImmediate.Pointer
