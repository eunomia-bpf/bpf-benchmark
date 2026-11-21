import KProgFormal.ClightRefinement.Arm64CompareDispatch
import KProgFormal.ClightRefinement.Arm64AddImmediateOperands

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Compare.Operands

private structure Pieces where
  lhsCall : CC.Stmt
  lhsSet : CC.Stmt
  rhs : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual CMP operand constructors changed"
      pure actual.getAppArgs
    let branch ← peel (← Lean.Elab.Term.elabTerm (← `(Dispatch.branch)) none)
    let lhs ← peel branch[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_operands (← Lean.Meta.mkAppM ``Pieces.mk
      #[lhs[0]!, lhs[1]!, branch[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cmp_operand_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def lhsCall : CC.Stmt := by run_tac cachePart (← `(pieces.lhsCall))
private def lhsSet : CC.Stmt := by run_tac cachePart (← `(pieces.lhsSet))
def rhs : CC.Stmt := by run_tac cachePart (← `(pieces.rhs))

/-- Preserve the real CMP LHS call/assignment and all untouched RHS/flag code. -/
theorem branch_source : Dispatch.branch = .Ssequence (.Ssequence lhsCall lhsSet) rhs := rfl

private def lhsCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'107) Arm64Nop.handler e le (.Kseq lhsSet (.Kseq rhs k))

def lhsTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((le.set Arm64Program._t'107 (.Vlong value)).set Arm64Program.___a64_l_lhs__4 (.Vlong value))

private theorem reader_type :
    CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_read) =
      .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default := rfl

private theorem lhs_call_source : lhsCall =
    .Scall (some Arm64Program._t'107)
      (.Evar Arm64Program._kprog_arm64_program_read
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._dst CC.tulong] := rfl

private theorem call_lhs (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._dst = some (.Vlong sourceWord)) :
    CC.Step2 world (.State Arm64Nop.handler lhsCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong sourceWord]
        (.Kcall (some Arm64Program._t'107) Arm64Nop.handler e le k) m) := by
  rw [lhs_call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    simp +decide [CC.doEvalExprlist, CC.doEvalExpr, entry, source, CC.typeof,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tptr, CC.tulong, CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · exact reader_type

set_option hygiene false in
private theorem enter_lhs (world : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (sourceWord : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._dst = some (.Vlong sourceWord)) :
    InternalRun world 3 (.State Arm64Nop.handler Dispatch.branch k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong sourceWord] (lhsCont k e le) m) := by
  run_tac do
    for _ in [:2] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep, branch_source] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic|
      exact InternalRun.step trivial
        (call_lhs world block b ofs e le m _ sourceWord binding unshadowed entry source) (InternalRun.refl _)))

set_option hygiene false in
private theorem after_lhs (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64) :
    InternalRun world 4 (.Returnstate (.Vlong value) (lhsCont k e le) m)
      (.State Arm64Nop.handler rhs k e (lhsTemps le value) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep, lhsCont, lhsTemps, lhsSet,
        CC.setOpttemp, CC.PTree.gss, CC.doEvalExpr, CC.typeof, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The actual CMP DST scalar read retains memory and reaches the untouched
RHS/flag suffix, with no extra native result or successful-read premise. -/
theorem lhs_scalar {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i : Fin 31) (value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 80
      (.State Arm64Nop.handler Dispatch.branch k e le memory)
      (.State Arm64Nop.handler rhs k e (lhsTemps le value) memory) := by
  have observed : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong value, .Vint ((0#8).setWidth 32)) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  have enter := enter_lhs Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 66)
    Arm64AddOperandReads.Linked.bindings.2.2 entry.block 0 e le memory k
    (BitVec.ofNat 64 i.val) readName entryRead source
  have read := Arm64RegisterReads.gpr_read_nonrelative_bound Arm64ProgramEntryLinked.ge
    Arm64MovKeep.Linked.reader_layout (fun _ => none) memory.nextblock entry.block 0 i memory
    (lhsCont k e le) (.Vlong value) value (0#8) observed rfl (by decide) (by decide)
  have finish := after_lhs Arm64ProgramEntryLinked.ge e le memory k value
  simpa only [CC.callCont, lhsCont] using (enter.trans read).trans finish

end KProgFormal.ClightRefinement.Arm64Compare.Operands
