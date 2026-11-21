import KProgFormal.ClightRefinement.Arm64AddImmediateDispatch

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.Operands

private structure Pieces where
  widthSet : CC.Stmt
  lhsCall : CC.Stmt
  lhsSet : CC.Stmt
  tail : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual ALU operand constructors changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Dispatch.branch)) none) ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel body[1]! ``CC.Stmt.Ssequence 2
    let lhs ← peel rest[0]! ``CC.Stmt.Ssequence 2
    let rhs ← peel rest[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_alu_operands (← Lean.Meta.mkAppM ``Pieces.mk
      #[body[0]!, lhs[0]!, lhs[1]!, rhs[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_operand_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def widthSet : CC.Stmt := by run_tac cachePart (← `(pieces.widthSet))
private def lhsCall : CC.Stmt := by run_tac cachePart (← `(pieces.lhsCall))
private def lhsSet : CC.Stmt := by run_tac cachePart (← `(pieces.lhsSet))
def tail : CC.Stmt := by run_tac cachePart (← `(pieces.tail))

def body : CC.Stmt := .Ssequence widthSet
  (.Ssequence (.Ssequence lhsCall lhsSet) (.Ssequence rhsLoop tail))

/-- Bind operand evaluation and the following tail to the original ALU branch. -/
theorem branch_source : Dispatch.branch = .Sloop body .Sbreak := rfl

theorem tail_source : tail = Arm64Program.s_kprog_arm64_program_execute_17 := rfl

def tailCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
private def rhsCont (k : CC.Cont) : CC.Cont := .Kseq tail (tailCont k)
private def lhsCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'7) Arm64Nop.handler e le
    (.Kseq lhsSet (.Kseq (.Ssequence rhsLoop tail) (tailCont k)))

def width (narrow : Bool) : CC.Val := Arm64Width.argument (Dispatch.flags narrow)
private def widthTemps (le : CC.TempEnv) (narrow : Bool) : CC.TempEnv :=
  le.set Arm64Program.___a64_alu_width (width narrow)

def lhsTemps (le : CC.TempEnv) (narrow : Bool) (lhs : BitVec 64) : CC.TempEnv :=
  ((widthTemps le narrow).set Arm64Program._t'7 (.Vlong lhs)).set
    Arm64Program.___a64_alu_lhs (.Vlong lhs)

def tailTemps (le : CC.TempEnv) (narrow : Bool) (lhs imm : BitVec 64) : CC.TempEnv :=
  rhsTemps (lhsTemps le narrow lhs) imm

private theorem reader_type :
    CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_read) =
      .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default := rfl

private theorem lhs_call_source : lhsCall =
    .Scall (some Arm64Program._t'7)
      (.Evar Arm64Program._kprog_arm64_program_read
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._src CC.tulong] := rfl

private theorem call_lhs (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong (32#64))) :
    CC.Step2 world (.State Arm64Nop.handler lhsCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong (32#64)]
        (.Kcall (some Arm64Program._t'7) Arm64Nop.handler e le k) m) := by
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
    (k : CC.Cont) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong (32#64)))
    (effective : le.get Arm64Program.___a64_l_width = some (width narrow)) :
    InternalRun world 7 (.State Arm64Nop.handler Dispatch.branch k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong (32#64)] (lhsCont k e (widthTemps le narrow)) m) := by
  have entry' : (widthTemps le narrow).get Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide only [widthTemps, CC.PTree.gso, entry]
  have source' : (widthTemps le narrow).get Arm64Program._src = some (.Vlong (32#64)) := by
    simp +decide only [widthTemps, CC.PTree.gso, source]
  cases narrow <;>
    run_tac do
      for _ in [:6] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, branch_source, body, widthSet,
          lhsCall, lhsCont, rhsCont, tailCont, widthTemps, width, Dispatch.flags, Arm64Width.argument,
          CC.PTree.gss, CC.PTree.gso, entry, source, effective, CC.doEvalExpr, CC.doEvalExprlist,
          CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.typeof, CC.accessMode, CC.Cop.classifyFun,
          CC.Genv.findFunct, unshadowed, binding.1, binding.2, reader_type, CC.Cop.semCast, CC.Cop.classifyCast,
          CC.Cop.castIntInt, CC.Cop.castIntLong, CC.typeconv, CC.removeAttributes, CC.tattr,
          CC.tuchar, CC.tuint, CC.tulong, CC.tptr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
          CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int64.repr, CC.Integers.MI.repr,
          CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.E0, CC.Eapp,
          List.nil_append, List.append_nil, ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
      Lean.Elab.Tactic.evalTactic (← `(tactic|
        exact InternalRun.step trivial
          (call_lhs world block b ofs e _ m _ binding unshadowed entry' source') (InternalRun.refl _)))

set_option hygiene false in
private theorem after_lhs (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (narrow : Bool) (lhs : BitVec 64) :
    InternalRun world 5
      (.Returnstate (.Vlong lhs) (lhsCont k e (widthTemps le narrow)) m)
      (.State Arm64Nop.handler rhsLoop (rhsCont k) e (lhsTemps le narrow lhs) m) := by
  run_tac do
    for _ in [:5] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, lhsCont, rhsCont, tailCont,
        lhsTemps, lhsSet, CC.setOpttemp, CC.PTree.gss, CC.doEvalExpr, CC.typeof,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tulong,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Read the represented SP using its reached warm cache, then run the actual
conditional immediate RHS and reach the original tag/arithmetic tail. No new
provider choice or heap/post-memory premise is added; both widths retain the same memory. -/
theorem evaluate (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (m : CC.Mem) (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier m (.Vptr b ofs) native)
    (cache : Arm64RegisterReads.WarmEntryCache false frontier m (.Vptr b ofs) origins.stack)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (narrow : Bool) (imm : BitVec 64)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (selectorName : e.get Arm64Program._kprog_arm64_alu_source = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong (32#64)))
    (effective : le.get Arm64Program.___a64_l_width = some (width narrow))
    (op : le.get Arm64Program._op = some (.Vint (3#32)))
    (immediate : le.get Arm64Program._imm = some (.Vlong imm)) :
    InternalRun Arm64ProgramEntryLinked.ge 113
      (.State Arm64Nop.handler Dispatch.branch k e le m)
      (.State Arm64Nop.handler tail (tailCont k) e
        (tailTemps le narrow (Reference.AArch64.sp native) imm) m) := by
  have enter := enter_lhs Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 66)
    Arm64AddOperandReads.Linked.bindings.2.2 b ofs e le m k narrow readName entry source effective
  have read := Arm64ProgramEntryWarmRead.read addresses origins frontier b ofs m
    (lhsCont k e (widthTemps le narrow)) native represented cache
  have finishRead := after_lhs Arm64ProgramEntryLinked.ge e le m k narrow (Reference.AArch64.sp native)
  have op' : (lhsTemps le narrow (Reference.AArch64.sp native)).get Arm64Program._op = some (.Vint (3#32)) := by
    simp +decide only [lhsTemps, widthTemps, CC.PTree.gso, op]
  have imm' : (lhsTemps le narrow (Reference.AArch64.sp native)).get Arm64Program._imm = some (.Vlong imm) := by
    simp +decide only [lhsTemps, widthTemps, CC.PTree.gso, immediate]
  have rhs := Linked.rhs e (lhsTemps le narrow (Reference.AArch64.sp native)) m (rhsCont k) imm selectorName op' imm'
  have leave : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler .Sskip (rhsCont k) e
        (tailTemps le narrow (Reference.AArch64.sp native) imm) m)
      (.State Arm64Nop.handler tail (tailCont k) e
        (tailTemps le narrow (Reference.AArch64.sp native) imm) m) :=
    .step trivial (.skip_seq _ _ _ _ _ _) (.refl _)
  simpa only [CC.callCont, tailTemps] using (((enter.trans read).trans finishRead).trans rhs).trans leave

end KProgFormal.ClightRefinement.Arm64AddImmediate.Operands
