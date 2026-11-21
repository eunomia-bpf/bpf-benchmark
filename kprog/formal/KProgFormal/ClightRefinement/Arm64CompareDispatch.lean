import KProgFormal.ClightRefinement.Arm64MulDispatch

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Dispatch

private structure Pieces where
  widthCall : CC.Stmt
  widthSet : CC.Stmt
  nopCondition : CC.Expr
  nopBranch : CC.Stmt
  adrpTest : CC.Stmt
  adrpCondition : CC.Expr
  adrpBranch : CC.Stmt
  movTest : CC.Stmt
  movCondition : CC.Expr
  movBranch : CC.Stmt
  movkCondition : CC.Expr
  movkBranch : CC.Stmt
  aluTest : CC.Stmt
  aluCondition : CC.Expr
  aluBranch : CC.Stmt
  shiftTest : CC.Stmt
  shiftCondition : CC.Expr
  shiftBranch : CC.Stmt
  mulTest : CC.Stmt
  mulCondition : CC.Expr
  mulBranch : CC.Stmt
  unaryTest : CC.Stmt
  unaryCondition : CC.Expr
  unaryBranch : CC.Stmt
  cnegCondition : CC.Expr
  cnegBranch : CC.Stmt
  extrevTest : CC.Stmt
  extrevCondition : CC.Expr
  extrevBranch : CC.Stmt
  bitfieldCondition : CC.Expr
  bitfieldBranch : CC.Stmt
  subsTest : CC.Stmt
  subsCondition : CC.Expr
  subsBranch : CC.Stmt
  addsTest : CC.Stmt
  addsCondition : CC.Expr
  addsBranch : CC.Stmt
  cmnImmCondition : CC.Expr
  cmnImmBranch : CC.Stmt
  cmnRegCondition : CC.Expr
  cmnRegBranch : CC.Stmt
  cmpTest : CC.Stmt
  cmpCondition : CC.Expr
  branch : CC.Stmt
  alternative : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual CMP dispatch constructors changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let width ← peel body[0]! ``CC.Stmt.Ssequence 2
    let mut args := #[width[0]!, width[1]!]
    let mut rest := body[1]!
    for hasTest in #[false, true, true, false, true, true, true, true, false, true, false, true, true, false, false, true] do
      let gate ← if hasTest then do
        let node ← peel rest ``CC.Stmt.Ssequence 2
        args := args.push node[0]!
        peel node[1]! ``CC.Stmt.Sifthenelse 3
      else peel rest ``CC.Stmt.Sifthenelse 3
      args := (args.push gate[0]!).push gate[1]!
      rest := gate[2]!
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_dispatch
      (← Lean.Meta.mkAppM ``Pieces.mk (args.push rest))

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cmp_dispatch_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def widthCall : CC.Stmt := by run_tac cachePart (← `(pieces.widthCall))
private def widthSet : CC.Stmt := by run_tac cachePart (← `(pieces.widthSet))
private def nopCondition : CC.Expr := by run_tac cachePart (← `(pieces.nopCondition))
private def nopBranch : CC.Stmt := by run_tac cachePart (← `(pieces.nopBranch))
private def adrpTest : CC.Stmt := by run_tac cachePart (← `(pieces.adrpTest))
private def adrpCondition : CC.Expr := by run_tac cachePart (← `(pieces.adrpCondition))
private def adrpBranch : CC.Stmt := by run_tac cachePart (← `(pieces.adrpBranch))
private def movTest : CC.Stmt := by run_tac cachePart (← `(pieces.movTest))
private def movCondition : CC.Expr := by run_tac cachePart (← `(pieces.movCondition))
private def movBranch : CC.Stmt := by run_tac cachePart (← `(pieces.movBranch))
private def movkCondition : CC.Expr := by run_tac cachePart (← `(pieces.movkCondition))
private def movkBranch : CC.Stmt := by run_tac cachePart (← `(pieces.movkBranch))
private def aluTest : CC.Stmt := by run_tac cachePart (← `(pieces.aluTest))
private def aluCondition : CC.Expr := by run_tac cachePart (← `(pieces.aluCondition))
private def aluBranch : CC.Stmt := by run_tac cachePart (← `(pieces.aluBranch))
private def shiftTest : CC.Stmt := by run_tac cachePart (← `(pieces.shiftTest))
private def shiftCondition : CC.Expr := by run_tac cachePart (← `(pieces.shiftCondition))
private def shiftBranch : CC.Stmt := by run_tac cachePart (← `(pieces.shiftBranch))
private def mulTest : CC.Stmt := by run_tac cachePart (← `(pieces.mulTest))
private def mulCondition : CC.Expr := by run_tac cachePart (← `(pieces.mulCondition))
private def mulBranch : CC.Stmt := by run_tac cachePart (← `(pieces.mulBranch))
private def unaryTest : CC.Stmt := by run_tac cachePart (← `(pieces.unaryTest))
private def unaryCondition : CC.Expr := by run_tac cachePart (← `(pieces.unaryCondition))
private def unaryBranch : CC.Stmt := by run_tac cachePart (← `(pieces.unaryBranch))
private def cnegCondition : CC.Expr := by run_tac cachePart (← `(pieces.cnegCondition))
private def cnegBranch : CC.Stmt := by run_tac cachePart (← `(pieces.cnegBranch))
private def extrevTest : CC.Stmt := by run_tac cachePart (← `(pieces.extrevTest))
private def extrevCondition : CC.Expr := by run_tac cachePart (← `(pieces.extrevCondition))
private def extrevBranch : CC.Stmt := by run_tac cachePart (← `(pieces.extrevBranch))
private def bitfieldCondition : CC.Expr := by run_tac cachePart (← `(pieces.bitfieldCondition))
private def bitfieldBranch : CC.Stmt := by run_tac cachePart (← `(pieces.bitfieldBranch))
private def subsTest : CC.Stmt := by run_tac cachePart (← `(pieces.subsTest))
private def subsCondition : CC.Expr := by run_tac cachePart (← `(pieces.subsCondition))
private def subsBranch : CC.Stmt := by run_tac cachePart (← `(pieces.subsBranch))
private def addsTest : CC.Stmt := by run_tac cachePart (← `(pieces.addsTest))
private def addsCondition : CC.Expr := by run_tac cachePart (← `(pieces.addsCondition))
private def addsBranch : CC.Stmt := by run_tac cachePart (← `(pieces.addsBranch))
private def cmnImmCondition : CC.Expr := by run_tac cachePart (← `(pieces.cmnImmCondition))
private def cmnImmBranch : CC.Stmt := by run_tac cachePart (← `(pieces.cmnImmBranch))
private def cmnRegCondition : CC.Expr := by run_tac cachePart (← `(pieces.cmnRegCondition))
private def cmnRegBranch : CC.Stmt := by run_tac cachePart (← `(pieces.cmnRegBranch))
private def cmpTest : CC.Stmt := by run_tac cachePart (← `(pieces.cmpTest))
private def cmpCondition : CC.Expr := by run_tac cachePart (← `(pieces.cmpCondition))
def branch : CC.Stmt := by run_tac cachePart (← `(pieces.branch))
private def alternative : CC.Stmt := by run_tac cachePart (← `(pieces.alternative))
private def cmpGate : CC.Stmt := .Ssequence cmpTest (.Sifthenelse cmpCondition branch alternative)
private def cmnRegGate : CC.Stmt := .Sifthenelse cmnRegCondition cmnRegBranch cmpGate
private def cmnImmGate : CC.Stmt := .Sifthenelse cmnImmCondition cmnImmBranch cmnRegGate
private def addsGate : CC.Stmt := .Ssequence addsTest (.Sifthenelse addsCondition addsBranch cmnImmGate)
private def subsGate : CC.Stmt := .Ssequence subsTest (.Sifthenelse subsCondition subsBranch addsGate)
private def bitfieldGate : CC.Stmt := .Sifthenelse bitfieldCondition bitfieldBranch subsGate
private def extrevGate : CC.Stmt := .Ssequence extrevTest (.Sifthenelse extrevCondition extrevBranch bitfieldGate)
private def cnegGate : CC.Stmt := .Sifthenelse cnegCondition cnegBranch extrevGate
private def unaryGate : CC.Stmt := .Ssequence unaryTest (.Sifthenelse unaryCondition unaryBranch cnegGate)
private def mulGate : CC.Stmt := .Ssequence mulTest (.Sifthenelse mulCondition mulBranch unaryGate)
private def shiftGate : CC.Stmt := .Ssequence shiftTest (.Sifthenelse shiftCondition shiftBranch mulGate)
private def aluGate : CC.Stmt := .Ssequence aluTest (.Sifthenelse aluCondition aluBranch shiftGate)
private def movkGate : CC.Stmt := .Sifthenelse movkCondition movkBranch aluGate
private def movGate : CC.Stmt := .Ssequence movTest (.Sifthenelse movCondition movBranch movkGate)
private def adrpGate : CC.Stmt := .Ssequence adrpTest (.Sifthenelse adrpCondition adrpBranch movGate)
private def nopGate : CC.Stmt := .Sifthenelse nopCondition nopBranch adrpGate

def body : CC.Stmt := .Ssequence (.Ssequence widthCall widthSet) nopGate

/-- Exact decomposition through all original dispatch gates to CMP. -/
theorem body_source : Arm64Nop.handler.fn_body = .Sloop body .Sbreak := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def widthCont (k : CC.Cont) : CC.Cont := .Kseq widthSet (.Kseq nopGate (continuation k))
def flags (narrow : Bool) : BitVec 8 := if narrow then 4 else 8

/-- Exact source comparison writes for opcode23; no operand or memory access. -/
def temps (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  ((((((((((((((((((((((Arm64Nop.resultEnv le (flags narrow)).set Arm64Program._t'2827 (.Vint 0)).set Arm64Program._t'2826 (.Vint 0)).set Arm64Program._t'2823 (.Vint 0)).set Arm64Program._t'2824 (.Vint 0)).set Arm64Program._t'2825 (.Vint 0)).set Arm64Program._t'2822 (.Vint 0)).set Arm64Program._t'2815 (.Vint 0)).set Arm64Program._t'2816 (.Vint 0)).set Arm64Program._t'2817 (.Vint 0)).set Arm64Program._t'2818 (.Vint 0)).set Arm64Program._t'2819 (.Vint 0)).set Arm64Program._t'2820 (.Vint 0)).set Arm64Program._t'2821 (.Vint 0)).set Arm64Program._t'2814 (.Vint 0)).set Arm64Program._t'2809 (.Vint 0)).set Arm64Program._t'2810 (.Vint 0)).set Arm64Program._t'2811 (.Vint 0)).set Arm64Program._t'2812 (.Vint 0)).set Arm64Program._t'2813 (.Vint 0)).set Arm64Program._t'2808 (.Vint 0)).set Arm64Program._t'2807 (.Vint 0)).set Arm64Program._t'2806 (.Vint 1)

private theorem enter_width_bound (world : CC.CGenv) (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol world.genv_genv Arm64Program._arm64_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr world.genv_genv widthBlock = some (.Internal Arm64Program.f_arm64_width_effective))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (narrow : Bool)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow))) :
    InternalRun world 4 (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.Callstate (.Internal Arm64Program.f_arm64_width_effective) [Arm64Width.argument (flags narrow)]
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m) := by
  have execution : steps world 4 (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m) =
      some (CC.E0, .Callstate (.Internal Arm64Program.f_arm64_width_effective)
        [Arm64Width.argument (flags narrow)]
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m) ∧
      InternalPath world 4 (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m) := by
    simp [body_source, body, widthCall, widthCont, continuation, steps, InternalPath, InternalState,
      CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.Cop.classifyFun, CC.typeof,
      CC.lvalOfVar, unshadowed, widthBinding.1, CC.doDerefLoc,
      CC.accessMode, CC.Genv.findFunct, widthBinding.2, hflags,
      Arm64Width.cast_argument, CC.typeOfFundef, CC.typeOfFunction, CC.typeOfParams,
      CC.Integers.MI.zero, Arm64Program.f_arm64_width_effective, CC.E0, CC.Eapp,
      CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq]
  exact internalRun_of_steps execution.2 execution.1

set_option hygiene false in
private theorem after_width (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (narrow : Bool) (op : le.get Arm64Program._op = some (.Vint (23#32))) :
    InternalRun world 108
      (.Returnstate (Arm64Width.result (flags narrow))
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m)
      (.State Arm64Nop.handler branch (continuation k) e (temps le narrow) m) := by
  cases narrow <;>
    run_tac do
      for _ in [:108] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, CC.setOpttemp,
          widthCont, continuation, widthSet, nopGate, adrpGate, movGate, movkGate, aluGate, shiftGate, mulGate, unaryGate, cnegGate, extrevGate, bitfieldGate, subsGate, addsGate, cmnImmGate, cmnRegGate, cmpGate, nopCondition, adrpTest, adrpCondition, movTest, movCondition, movkCondition, aluTest, aluCondition, shiftTest, shiftCondition, mulTest, mulCondition, unaryTest, unaryCondition, cnegCondition, extrevTest, extrevCondition, bitfieldCondition, subsTest, subsCondition, addsTest, addsCondition, cmnImmCondition, cmnRegCondition, cmpTest, cmpCondition,
          Arm64Program.s_kprog_arm64_program_execute_27, Arm64Program.s_kprog_arm64_program_execute_28,
          flags, temps, Arm64Nop.resultEnv, Arm64Width.result, Arm64Width.argument,
          CC.PTree.gss, CC.PTree.gso, op, CC.doEvalExpr, CC.typeof,
          CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
          CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
          CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
          CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool,
          CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
          CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.repr, CC.Integers.MI.repr,
          CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.unsigned,
          CC.Integers.MI.unsigned, CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero,
          CC.Integers.MI.one, CC.E0, CC.Eapp, List.nil_append, List.append_nil,
          ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Opcode23 reaches the original CMP branch for W and X widths, through the
actual width call and every preceding gate. Memory and all other inputs remain arbitrary. -/
theorem body_dispatch_bound (world : CC.CGenv) (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol world.genv_genv Arm64Program._arm64_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr world.genv_genv widthBlock = some (.Internal Arm64Program.f_arm64_width_effective))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (narrow : Bool)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow)))
    (op : le.get Arm64Program._op = some (.Vint (23#32))) :
    InternalRun world 118 (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler branch (continuation k) e (temps le narrow) m) := by
  have enter := enter_width_bound world widthBlock widthBinding e le m k narrow unshadowed hflags
  have width := Arm64Width.internal world (flags narrow)
    (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m
  have choose := after_width world e le m k narrow op
  simpa only [CC.callCont] using (enter.trans width).trans choose

namespace Linked
open Arm64ProgramEntryLinked (ge)

/-- Opcode23 in the actual caller-linked world, using the accepted width binding. -/
theorem body_dispatch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (narrow : Bool)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow)))
    (op : le.get Arm64Program._op = some (.Vint (23#32))) :
    InternalRun ge 118 (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler branch (continuation k) e (temps le narrow) m) :=
  body_dispatch_bound ge (CC.Positive.ofNat 97) Arm64AddImmediate.Dispatch.Linked.width_binding
    e le m k narrow unshadowed hflags op

end Linked
end KProgFormal.ClightRefinement.Arm64Compare.Dispatch
