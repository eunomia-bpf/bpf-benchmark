import KProgFormal.ClightRefinement.X86AluDecode

namespace KProgFormal.ClightRefinement.X86AluReadSite

private structure Pieces where
  operationGate : CC.Stmt
  laneGate : CC.Stmt
  call : CC.Stmt
  assign : CC.Stmt
  rhs : CC.Stmt

private def pieces : Pieces :=
  match X86AluDecode.operandReads with
  | .Ssequence (.Ssequence (.Ssequence op lane)
      (.Sifthenelse _ (.Ssequence (.Ssequence call assign) rhs) _)) _ =>
      ⟨op, lane, call, assign, rhs⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_alu_read_site_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def operationGate : CC.Stmt := by run_tac cachePart (← `(pieces.operationGate))
private def laneGate : CC.Stmt := by run_tac cachePart (← `(pieces.laneGate))
private def readCall : CC.Stmt := by run_tac cachePart (← `(pieces.call))
private def assignLhs : CC.Stmt := by run_tac cachePart (← `(pieces.assign))
def rhsRead : CC.Stmt := by run_tac cachePart (← `(pieces.rhs))

def readStatements : CC.Stmt :=
  .Ssequence (.Ssequence readCall assignLhs) rhsRead

private def selectReads : CC.Stmt :=
  .Sifthenelse (.Eunop .Onotbool (.Etempvar X86_program_profile_bpf._t'5 CC.tint) CC.tint)
    readStatements .Sskip

/-- Both XOR shortcut gates, reads and arithmetic dispatcher are actual source. -/
theorem source : X86AluDecode.operandReads =
    .Ssequence (.Ssequence (.Ssequence operationGate laneGate) selectReads)
      X86ShiftLeftRoute.dispatch := rfl

def selectedTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'4 (.Vint 0)).set
    X86_program_profile_bpf._t'5 (.Vint 0)

/-- The real two XOR gates select the original operand-read statements in
ten silent transitions for every other operation, with the full heap retained. -/
theorem select_reads (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (operation : BitVec 8)
    (different : operation.setWidth 32 ≠ (2#32))
    (opRead : le.get X86_program_profile_bpf.___x86_l_alu =
      some (.Vint (operation.setWidth 32))) :
    InternalRun ge 10 (.State function X86AluDecode.operandReads k e le m)
      (.State function readStatements (.Kseq X86ShiftLeftRoute.dispatch k)
        e (selectedTemps le) m) := by
  have notXor : (operation.setWidth 32 == (2#32)) = false :=
    beq_eq_false_iff_ne.mpr different
  have compared : CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (.Vint (operation.setWidth 32)) (.Tint .I8 .Unsigned CC.noattr)
      (.Vint (2#32)) (.Tint .I32 .Unsigned CC.noattr) m =
        some (.Vint (0#32)) := by
    change some (CC.Val.ofBool (operation.setWidth 32 == (2#32))) = _
    rw [notXor]
    rfl
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep,
      operationGate, laneGate, selectReads, readStatements, selectedTemps, CC.doEvalExpr,
      compared, opRead, CC.PTree.gss, CC.typeof,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.Cop.semUnaryOperation, CC.Cop.semNotbool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tint, CC.tuint, CC.tuchar,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]

end KProgFormal.ClightRefinement.X86AluReadSite
