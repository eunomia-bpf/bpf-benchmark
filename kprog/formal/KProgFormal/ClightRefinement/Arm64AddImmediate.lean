import KProgFormal.ClightRefinement.Arm64AddOperandReads

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate

/-- This is the existing RHS selection statement from the actual generic handler. -/
def rhsBody : CC.Stmt := Arm64Program.s_kprog_arm64_program_execute_15

def rhsLoop : CC.Stmt := .Sloop rhsBody Arm64Program.s_kprog_arm64_program_execute_16

/-- Follow the actual NOP/ADRP/MOV/MOVK/ALU constructors to the RHS loop.
This structural projection has no instruction-semantics implementation. -/
private def exportedRhs : Option CC.Stmt := do
  let .Sloop body _ := Arm64Nop.handler.fn_body | none
  let .Ssequence _ nop := body | none
  let .Sifthenelse _ _ adrp := nop | none
  let .Ssequence _ adrpGate := adrp | none
  let .Sifthenelse _ _ mov := adrpGate | none
  let .Ssequence _ movGate := mov | none
  let .Sifthenelse _ _ movkGate := movGate | none
  let .Sifthenelse _ _ alu := movkGate | none
  let .Ssequence _ aluGate := alu | none
  let .Sifthenelse _ aluLoop _ := aluGate | none
  let .Sloop aluBody _ := aluLoop | none
  let .Ssequence _ afterWidth := aluBody | none
  let .Ssequence _ afterLhs := afterWidth | none
  let .Ssequence rhs _ := afterLhs | none
  pure rhs

/-- Kernel-check that this exact fragment belongs to the original handler. -/
theorem rhs_from_handler : exportedRhs = some rhsLoop := rfl

private structure Pieces where
  call : CC.Stmt
  test : CC.Expr
  immediate : CC.Stmt
  register : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let root ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(rhsBody)) none))
    unless root.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual ALU RHS prefix changed"
    let branch ← Lean.Meta.withTransparency .all (Lean.Meta.whnf root.getAppArgs[1]!)
    unless branch.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "actual ALU RHS gate changed"
    Lean.Elab.Tactic.closeMainGoal `actual_rhs_parts (← Lean.Meta.mkAppM ``Pieces.mk
      #[root.getAppArgs[0]!, branch.getAppArgs[0]!, branch.getAppArgs[1]!, branch.getAppArgs[2]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_rhs_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def selectorCall : CC.Stmt := by run_tac cachePart (← `(pieces.call))
private def test : CC.Expr := by run_tac cachePart (← `(pieces.test))
private def immediate : CC.Stmt := by run_tac cachePart (← `(pieces.immediate))
private def register : CC.Stmt := by run_tac cachePart (← `(pieces.register))
private theorem rhs_source : rhsBody = .Ssequence selectorCall (.Sifthenelse test immediate register) := rfl

private theorem selector_executes (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont) :
    steps world 20 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source) [.Vlong (3#64)] k m) =
      some (CC.E0, .Returnstate (.Vint (1#32)) (CC.callCont k) m) ∧
    InternalPath world 20 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source) [.Vlong (3#64)] k m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  simp +decide [steps, InternalPath, InternalState, CC.doStep, CC.doFunctionEntry2,
    Arm64Numeric.f_kprog_arm64_alu_source, CC.doAllocVariables, CC.bindParameterTemps,
    CC.createUndefTemps, CC.PTree.gso, CC.doEvalExpr, CC.doEvalLvalue, CC.selectSwitch, CC.selectSwitchCase, CC.selectSwitchDefault, CC.seqOfLabeledStatement, CC.Cop.semSwitchArg, CC.Cop.classifySwitch, CC.Integers.Int64.unsigned, CC.typeof, CC.typeconv,
    CC.removeAttributes, CC.tattr,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
    CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.tuchar, CC.tptr, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp, empty]


/-- The actual Numeric C selector chooses the immediate for opcode3. -/
theorem selector (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 20
      (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source) [.Vlong (3#64)] k m)
      (.Returnstate (.Vint (1#32)) (CC.callCont k) m) := by
  have run := selector_executes world m k
  exact internalRun_of_steps run.2 run.1

private def callCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'13) Arm64Nop.handler e le
    (.Kseq (.Sifthenelse test immediate register)
      (.Kloop1 rhsBody Arm64Program.s_kprog_arm64_program_execute_16 k))

def rhsTemps (le : CC.TempEnv) (imm : BitVec 64) : CC.TempEnv :=
  (le.set Arm64Program._t'13 (.Vint (1#32))).set Arm64Program.___a64_alu_rhs (.Vlong imm)

set_option hygiene false in
private theorem enter_rhs (world : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_alu_source = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Numeric.f_kprog_arm64_alu_source))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_alu_source = none)
    (op : le.get Arm64Program._op = some (.Vint (3#32))) :
    InternalRun world 3 (.State Arm64Nop.handler rhsLoop k e le m)
      (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source) [.Vlong (3#64)] (callCont k e le) m) := by
  run_tac do
    for _ in [:3] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [rhsLoop, rhs_source, selectorCall, callCont,
        CC.doStep, CC.doEvalExprlist, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc,
        CC.typeof, CC.accessMode, unshadowed, binding.1, binding.2, CC.Genv.findFunct,
        CC.typeOfFundef, CC.typeOfFunction, CC.typeOfParams, Arm64Numeric.f_kprog_arm64_alu_source,
        op, CC.Cop.classifyFun, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntLong,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tulong,
        CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int64.repr, CC.Integers.MI.repr,
        CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

set_option hygiene false in
private theorem after_selector (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (imm : BitVec 64) (read : le.get Arm64Program._imm = some (.Vlong imm)) :
    InternalRun world 6
      (.Returnstate (.Vint (1#32)) (callCont k e le) m)
      (.State Arm64Nop.handler .Sskip k e (rhsTemps le imm) m) := by
  run_tac do
    for _ in [:6] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, callCont, rhsTemps, test, immediate,
        Arm64Program.s_kprog_arm64_program_execute_16, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
        CC.doEvalExpr, CC.typeof, read, CC.Cop.boolVal, CC.Cop.classifyBool, CC.Cop.semCast,
        CC.Cop.classifyCast, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tulong,
        CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Actual conditional RHS evaluation: opcode3 takes IMM and skips the SRC2
reader and modification branch. No SRC2 value, entry validity or heap premise. -/
theorem rhs_bound (world : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_alu_source = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Numeric.f_kprog_arm64_alu_source))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (imm : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_alu_source = none)
    (op : le.get Arm64Program._op = some (.Vint (3#32)))
    (read : le.get Arm64Program._imm = some (.Vlong imm)) :
    InternalRun world 29 (.State Arm64Nop.handler rhsLoop k e le m)
      (.State Arm64Nop.handler .Sskip k e (rhsTemps le imm) m) := by
  have enter := enter_rhs world block binding e le m k unshadowed op
  have choose := selector world m (callCont k e le)
  have finish := after_selector world e le m k imm read
  simpa only [CC.callCont] using (enter.trans choose).trans finish

namespace Linked
open Arm64ProgramEntryLinked (ge sourceEquality)

theorem selector_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._kprog_arm64_alu_source = some (CC.Positive.ofNat 100) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 100) = some (.Internal Arm64Numeric.f_kprog_arm64_alu_source) := by
  constructor <;> run_tac sourceEquality

theorem rhs (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (imm : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_alu_source = none)
    (op : le.get Arm64Program._op = some (.Vint (3#32)))
    (read : le.get Arm64Program._imm = some (.Vlong imm)) :
    InternalRun ge 29 (.State Arm64Nop.handler rhsLoop k e le m)
      (.State Arm64Nop.handler .Sskip k e (rhsTemps le imm) m) :=
  rhs_bound ge (CC.Positive.ofNat 100) selector_binding e le m k imm unshadowed op read

end Linked
end KProgFormal.ClightRefinement.Arm64AddImmediate
