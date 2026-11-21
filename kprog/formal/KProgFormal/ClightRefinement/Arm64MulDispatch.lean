import KProgFormal.ClightRefinement.Arm64AddImmediateDispatch

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Mul.Dispatch

private structure Pieces where
  widthCall : CC.Stmt
  widthSet : CC.Stmt
  nopTest : CC.Expr
  adrpTest : CC.Stmt
  adrpCondition : CC.Expr
  adrpBranch : CC.Stmt
  movTest : CC.Stmt
  movCondition : CC.Expr
  movBranch : CC.Stmt
  movkTest : CC.Expr
  movkBranch : CC.Stmt
  aluTest : CC.Stmt
  aluCondition : CC.Expr
  aluBranch : CC.Stmt
  shiftTest : CC.Stmt
  shiftCondition : CC.Expr
  shiftBranch : CC.Stmt
  mulTest : CC.Stmt
  mulCondition : CC.Expr
  branch : CC.Stmt
  alternative : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual MUL dispatch constructors changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let width ← peel body[0]! ``CC.Stmt.Ssequence 2
    let nop ← peel body[1]! ``CC.Stmt.Sifthenelse 3
    let adrp ← peel nop[2]! ``CC.Stmt.Ssequence 2
    let adrpGate ← peel adrp[1]! ``CC.Stmt.Sifthenelse 3
    let mov ← peel adrpGate[2]! ``CC.Stmt.Ssequence 2
    let movGate ← peel mov[1]! ``CC.Stmt.Sifthenelse 3
    let movk ← peel movGate[2]! ``CC.Stmt.Sifthenelse 3
    let alu ← peel movk[2]! ``CC.Stmt.Ssequence 2
    let aluGate ← peel alu[1]! ``CC.Stmt.Sifthenelse 3
    let shift ← peel aluGate[2]! ``CC.Stmt.Ssequence 2
    let shiftGate ← peel shift[1]! ``CC.Stmt.Sifthenelse 3
    let mul ← peel shiftGate[2]! ``CC.Stmt.Ssequence 2
    let mulGate ← peel mul[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_mul_dispatch (← Lean.Meta.mkAppM ``Pieces.mk
      #[width[0]!, width[1]!, nop[0]!, adrp[0]!, adrpGate[0]!, adrpGate[1]!,
        mov[0]!, movGate[0]!, movGate[1]!, movk[0]!, movk[1]!,
        alu[0]!, aluGate[0]!, aluGate[1]!, shift[0]!, shiftGate[0]!, shiftGate[1]!,
        mul[0]!, mulGate[0]!, mulGate[1]!, mulGate[2]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_mul_dispatch_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def widthCall : CC.Stmt := by run_tac cachePart (← `(pieces.widthCall))
private def widthSet : CC.Stmt := by run_tac cachePart (← `(pieces.widthSet))
private def nopTest : CC.Expr := by run_tac cachePart (← `(pieces.nopTest))
private def adrpTest : CC.Stmt := by run_tac cachePart (← `(pieces.adrpTest))
private def adrpCondition : CC.Expr := by run_tac cachePart (← `(pieces.adrpCondition))
private def adrpBranch : CC.Stmt := by run_tac cachePart (← `(pieces.adrpBranch))
private def movTest : CC.Stmt := by run_tac cachePart (← `(pieces.movTest))
private def movCondition : CC.Expr := by run_tac cachePart (← `(pieces.movCondition))
private def movBranch : CC.Stmt := by run_tac cachePart (← `(pieces.movBranch))
private def movkTest : CC.Expr := by run_tac cachePart (← `(pieces.movkTest))
private def movkBranch : CC.Stmt := by run_tac cachePart (← `(pieces.movkBranch))
private def aluTest : CC.Stmt := by run_tac cachePart (← `(pieces.aluTest))
private def aluCondition : CC.Expr := by run_tac cachePart (← `(pieces.aluCondition))
private def aluBranch : CC.Stmt := by run_tac cachePart (← `(pieces.aluBranch))
private def shiftTest : CC.Stmt := by run_tac cachePart (← `(pieces.shiftTest))
private def shiftCondition : CC.Expr := by run_tac cachePart (← `(pieces.shiftCondition))
private def shiftBranch : CC.Stmt := by run_tac cachePart (← `(pieces.shiftBranch))
private def mulTest : CC.Stmt := by run_tac cachePart (← `(pieces.mulTest))
private def mulCondition : CC.Expr := by run_tac cachePart (← `(pieces.mulCondition))
def branch : CC.Stmt := by run_tac cachePart (← `(pieces.branch))
private def alternative : CC.Stmt := by run_tac cachePart (← `(pieces.alternative))

private def mulSequence : CC.Stmt := .Ssequence mulTest (.Sifthenelse mulCondition branch alternative)
private def shiftSequence : CC.Stmt := .Ssequence shiftTest (.Sifthenelse shiftCondition shiftBranch mulSequence)
private def aluSequence : CC.Stmt := .Ssequence aluTest (.Sifthenelse aluCondition aluBranch shiftSequence)
private def movkGate : CC.Stmt := .Sifthenelse movkTest movkBranch aluSequence
private def movSequence : CC.Stmt := .Ssequence movTest (.Sifthenelse movCondition movBranch movkGate)
private def adrpSequence : CC.Stmt := .Ssequence adrpTest (.Sifthenelse adrpCondition adrpBranch movSequence)
private def nopGate : CC.Stmt := .Sifthenelse nopTest .Sskip adrpSequence

def body : CC.Stmt := .Ssequence (.Ssequence widthCall widthSet) nopGate

/-- The dispatcher is an exact decomposition of the original generic body. -/
theorem body_source : Arm64Nop.handler.fn_body = .Sloop body .Sbreak := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def widthCont (k : CC.Cont) : CC.Cont := .Kseq widthSet (.Kseq nopGate (continuation k))

def flags (narrow : Bool) : BitVec 8 := if narrow then 4 else 8

/-- Exact actual short-circuit comparison temporaries for opcode12. -/
def temps (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  (((((((((((((Arm64Nop.resultEnv le (flags narrow)).set Arm64Program._t'2827 (.Vint 0)).set Arm64Program._t'2826 (.Vint 0)).set Arm64Program._t'2823 (.Vint 0)).set Arm64Program._t'2824 (.Vint 0)).set Arm64Program._t'2825 (.Vint 0)).set Arm64Program._t'2822 (.Vint 0)).set Arm64Program._t'2815 (.Vint 0)).set Arm64Program._t'2816 (.Vint 1)).set Arm64Program._t'2817 (.Vint 1)).set Arm64Program._t'2818 (.Vint 1)).set Arm64Program._t'2819 (.Vint 1)).set Arm64Program._t'2820 (.Vint 1)).set Arm64Program._t'2821 (.Vint 1)

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
    (k : CC.Cont) (narrow : Bool) (op : le.get Arm64Program._op = some (.Vint (12#32))) :
    InternalRun world 63
      (.Returnstate (Arm64Width.result (flags narrow))
        (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m)
      (.State Arm64Nop.handler branch (continuation k) e (temps le narrow) m) := by
  cases narrow <;>
    run_tac do
      for _ in [:63] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, CC.setOpttemp,
          widthCont, continuation, widthSet, nopGate, nopTest, adrpSequence, adrpTest, adrpCondition,
          movSequence, movTest, movCondition, movkGate, movkTest, aluSequence, aluTest, aluCondition,
          shiftSequence, shiftTest, shiftCondition, mulSequence, mulTest, mulCondition,
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

/-- Opcode12 reaches the original MUL branch for W and X widths, through the
actual width call and every preceding gate. Memory and all other inputs remain arbitrary. -/
theorem body_dispatch_bound (world : CC.CGenv) (widthBlock : CC.Block)
    (widthBinding : CC.Genv.findSymbol world.genv_genv Arm64Program._arm64_width_effective = some widthBlock ∧
      CC.Genv.findFunctPtr world.genv_genv widthBlock = some (.Internal Arm64Program.f_arm64_width_effective))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (narrow : Bool)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow)))
    (op : le.get Arm64Program._op = some (.Vint (12#32))) :
    InternalRun world 73 (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler branch (continuation k) e (temps le narrow) m) := by
  have enter := enter_width_bound world widthBlock widthBinding e le m k narrow unshadowed hflags
  have width := Arm64Width.internal world (flags narrow)
    (.Kcall (some Arm64Program._t'1) Arm64Nop.handler e le (widthCont k)) m
  have choose := after_width world e le m k narrow op
  simpa only [CC.callCont] using (enter.trans width).trans choose

namespace Linked
open Arm64ProgramEntryLinked (ge)

/-- Opcode12 in the actual caller-linked world, using the accepted width binding. -/
theorem body_dispatch (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (narrow : Bool)
    (unshadowed : e.get Arm64Program._arm64_width_effective = none)
    (hflags : le.get Arm64Program._flags = some (Arm64Width.argument (flags narrow)))
    (op : le.get Arm64Program._op = some (.Vint (12#32))) :
    InternalRun ge 73 (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
      (.State Arm64Nop.handler branch (continuation k) e (temps le narrow) m) :=
  body_dispatch_bound ge (CC.Positive.ofNat 97) Arm64AddImmediate.Dispatch.Linked.width_binding
    e le m k narrow unshadowed hflags op

end Linked
end KProgFormal.ClightRefinement.Arm64Mul.Dispatch
