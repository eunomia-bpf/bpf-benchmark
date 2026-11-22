import KProgFormal.ClightRefinement.Arm64ModifiedCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Rhs

private structure Pieces where
  selector : CC.Expr
  cases : CC.LStmts
  output : CC.Stmt
private def pieces : Pieces := by
  run_tac do
    let tail ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(RhsCall.tail)) none))
    unless tail.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual CMP RHS tail changed"
    let sw ← Lean.Meta.withTransparency .all (Lean.Meta.whnf tail.getAppArgs[0]!)
    unless sw.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "actual flag RHS selector changed"
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_rhs_tail (← Lean.Meta.mkAppM ``Pieces.mk
      #[sw.getAppArgs[0]!, sw.getAppArgs[1]!, tail.getAppArgs[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cmp_rhs_tail_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def selector : CC.Expr := by run_tac cachePart (← `(pieces.selector))
private def cases : CC.LStmts := by run_tac cachePart (← `(pieces.cases))
private def output : CC.Stmt := by run_tac cachePart (← `(pieces.output))

/-- Keep the original opcode switch and final RHS assignment. -/
theorem tail_source : RhsCall.tail = .Ssequence (.Sswitch selector cases) output := rfl
private theorem select_source : CC.seqOfLabeledStatement (CC.selectSwitch 23 cases) =
    .Ssequence .Sbreak .Sskip := rfl

def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((le.set Arm64Program._t'108 (.Vlong value)).set
    Arm64Program.___kprog_a64_fo_rhs__2 (.Vlong value)).set Arm64Program.___a64_l_rhs__4 (.Vlong value)

set_option hygiene false in
/-- Real caller restore, source selector/default arm and loop exit. -/
theorem resume_bound (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (op : le.get Arm64Program._op = some (.Vint (23#32))) :
    InternalRun world 14 (.Returnstate (.Vlong value) (RhsCall.callCont k e le) m)
      (.State Arm64Nop.handler RhsCall.flags k e (temps le value) m) := by
  run_tac do
    for _ in [:14] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, RhsCall.callCont,
        RhsCall.tailCont, RhsCall.body, RhsCall.readSet, tail_source, selector, output, select_source,
        temps, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso, op, CC.doEvalExpr, CC.typeof,
        CC.Cop.semSwitchArg, CC.Cop.classifySwitch, CC.Integers.Int.unsigned,
        CC.Integers.MI.unsigned, CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.tuint, CC.tint, CC.tulong, BitVec.toNat_ofNat, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
        Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The actual linked helper call/return and original selector derive the RHS
from real scalar table loads and reach the untouched flag loop. -/
theorem execute (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) (narrow : Bool)
    (value : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (RhsCall.width narrow))
    (op : le.get Arm64Program._op = some (.Vint (23#32)))
    (cells : CC.Mem.loadv CC.Mptr m (.Vptr b ofs) = some (.Vptr cb co))
    (cellSlot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (tags : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 8))) = some (.Vptr tb to))
    (tagSlot : CC.Mem.loadv CC.Mptr m (.Vptr tb (CC.Integers.Ptrofs.add to
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr kb ko))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value))
    (kind : CC.Mem.loadv .Mint8unsigned m (.Vptr kb ko) = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 138
      (.State Arm64Nop.handler Operands.rhs k e le m)
      (.State Arm64Nop.handler RhsCall.flags k e
        (temps le (Arm64Modified.Modifier.result value narrow)) m) := by
  have entered := RhsCall.Linked.enter b ofs e le m k (BitVec.ofNat 64 i.val) narrow
    unshadowed entry src aux effective
  have helper := Arm64Modified.Call.execute Arm64ProgramEntryLinked.ge Arm64MovKeep.Linked.reader_layout
    i b cb vb tb kb ofs co vo to ko m (RhsCall.callCont k e le) narrow value
    cells cellSlot tags tagSlot cell kind
  have resumed := resume_bound Arm64ProgramEntryLinked.ge e le m k
    (Arm64Modified.Modifier.result value narrow) op
  exact (entered.trans helper).trans resumed

end KProgFormal.ClightRefinement.Arm64Compare.Rhs
