import KProgFormal.ClightRefinement.Arm64MulDispatch
import KProgFormal.ClightRefinement.Arm64AddImmediateOperands

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Mul.Operands

private structure Pieces where
  opSet : CC.Stmt
  lhsCall : CC.Stmt
  widthChoice : CC.Stmt
  maskChoice : CC.Stmt
  lhsSet : CC.Stmt
  rhs : CC.Stmt
  writer : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual MUL operand constructors changed"
      pure actual.getAppArgs
    let branch ← peel (← Lean.Elab.Term.elabTerm (← `(Dispatch.branch)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel branch[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel body[1]! ``CC.Stmt.Ssequence 2
    let lhs ← peel rest[0]! ``CC.Stmt.Ssequence 2
    let masked ← peel lhs[0]! ``CC.Stmt.Ssequence 2
    let pair ← peel masked[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_mul_operands (← Lean.Meta.mkAppM ``Pieces.mk
      #[body[0]!, pair[0]!, pair[1]!, masked[1]!, lhs[1]!, rest[1]!, branch[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_mul_operand_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def opSet : CC.Stmt := by run_tac cachePart (← `(pieces.opSet))
private def lhsCall : CC.Stmt := by run_tac cachePart (← `(pieces.lhsCall))
private def widthChoice : CC.Stmt := by run_tac cachePart (← `(pieces.widthChoice))
private def maskChoice : CC.Stmt := by run_tac cachePart (← `(pieces.maskChoice))
private def lhsSet : CC.Stmt := by run_tac cachePart (← `(pieces.lhsSet))
def rhs : CC.Stmt := by run_tac cachePart (← `(pieces.rhs))
def writer : CC.Stmt := by run_tac cachePart (← `(pieces.writer))
private def lhs : CC.Stmt := .Ssequence (.Ssequence (.Ssequence lhsCall widthChoice) maskChoice) lhsSet

def body : CC.Stmt := .Ssequence opSet (.Ssequence lhs rhs)

/-- Exact original multiply block, including its pending RHS/addend/tail and writer. -/
theorem branch_source : Dispatch.branch = .Ssequence (.Sloop body .Sbreak) writer := rfl

def tailCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq writer k)
private def lhsCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'40) Arm64Nop.handler e le
    (.Kseq widthChoice (.Kseq maskChoice (.Kseq lhsSet (.Kseq rhs (tailCont k)))))

def opTemps (le : CC.TempEnv) : CC.TempEnv :=
  le.set Arm64Program.___kprog_a64_mul_op (.Vlong (12#64))

/-- Exact temporaries, retaining the three original full-mask casts. -/
def lhsTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((((((((opTemps le).set Arm64Program._t'40 (.Vlong value)).set Arm64Program._t'41 (.Vint (8#32))).set Arm64Program._t'43 (.Vint (8#32))).set Arm64Program._t'44 (.Vint (8#32))).set Arm64Program._t'42 (.Vlong (BitVec.ofInt 64 (-1)))).set Arm64Program._t'42 (.Vlong (BitVec.ofInt 64 (-1)))).set Arm64Program._t'42 (.Vlong (BitVec.ofInt 64 (-1)))).set Arm64Program.___kprog_a64_mul_lhs (.Vlong value)

private theorem reader_type :
    CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_read) =
      .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default := rfl

private theorem lhs_call_source : lhsCall =
    .Scall (some Arm64Program._t'40)
      (.Evar Arm64Program._kprog_arm64_program_read
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._src CC.tulong] := rfl

private theorem call_lhs (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong sourceWord)) :
    CC.Step2 world (.State Arm64Nop.handler lhsCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong sourceWord]
        (.Kcall (some Arm64Program._t'40) Arm64Nop.handler e le k) m) := by
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

private theorem full_mask (x : BitVec 64) : x &&& BitVec.ofInt 64 (-1) = x := by
  have mask : BitVec.ofInt 64 (-1) = BitVec.allOnes 64 := by decide +kernel
  rw [mask]
  exact BitVec.and_allOnes

set_option hygiene false in
private theorem enter_lhs (world : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (sourceWord : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong sourceWord))
    (op : le.get Arm64Program._op = some (.Vint (12#32))) :
    InternalRun world 10 (.State Arm64Nop.handler Dispatch.branch k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong sourceWord] (lhsCont k e (opTemps le)) m) := by
  have entry' : (opTemps le).get Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide only [opTemps, CC.PTree.gso, entry]
  have source' : (opTemps le).get Arm64Program._src = some (.Vlong sourceWord) := by
    simp +decide only [opTemps, CC.PTree.gso, source]
  run_tac do
    for _ in [:9] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, branch_source, body, lhs, opSet,
        lhsCall, lhsCont, tailCont, opTemps,
        CC.PTree.gss, CC.PTree.gso, entry, source, op, CC.doEvalExpr, CC.doEvalExprlist,
        CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.typeof, CC.accessMode, CC.Cop.classifyFun,
        CC.Genv.findFunct, unshadowed, binding.1, binding.2, reader_type, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong, CC.typeconv, CC.removeAttributes, CC.tattr,
        CC.tuchar, CC.tuint, CC.tulong, CC.tptr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int64.repr, CC.Integers.MI.repr,
        CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil, ite_true, ite_false, eq_self, Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic|
      exact InternalRun.step trivial
        (call_lhs world block b ofs e _ m _ sourceWord binding unshadowed entry' source') (InternalRun.refl _)))

set_option hygiene false in
private theorem after_lhs (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (op : le.get Arm64Program._op = some (.Vint (12#32))) :
    InternalRun world 26
      (.Returnstate (.Vlong value) (lhsCont k e (opTemps le)) m)
      (.State Arm64Nop.handler rhs (tailCont k) e (lhsTemps le value) m) := by
  run_tac do
    for _ in [:26] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,
        lhsCont, tailCont, lhsTemps, opTemps, widthChoice, maskChoice, lhsSet, op,
        CC.setOpttemp, CC.PTree.gss, CC.PTree.gso, CC.doEvalExpr, CC.typeof,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semAnd,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
        CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tbool, CC.Val.and,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
        CC.Integers.Int64.and, CC.Integers.MI.and, full_mask,
        CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.eq, CC.Integers.MI.eq,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.unsigned,
        CC.Integers.MI.unsigned, CC.Integers.Int.zero, CC.Integers.Int.one,
        CC.Integers.MI.zero, CC.Integers.MI.one, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
        Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Actual scalar LHS and its original full-width mask, on the same reached
memory, ending at the untouched RHS/addend/product suffix. -/
theorem lhs_scalar {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i : Fin 31) (value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (op : le.get Arm64Program._op = some (.Vint (12#32)))
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 109
      (.State Arm64Nop.handler Dispatch.branch k e le memory)
      (.State Arm64Nop.handler rhs (tailCont k) e (lhsTemps le value) memory) := by
  have observed : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong value, .Vint ((0#8).setWidth 32)) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  have enter := enter_lhs Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 66)
    Arm64AddOperandReads.Linked.bindings.2.2 entry.block 0 e le memory k
    (BitVec.ofNat 64 i.val) readName entryRead source op
  have read := Arm64RegisterReads.gpr_read_nonrelative_bound Arm64ProgramEntryLinked.ge
    Arm64MovKeep.Linked.reader_layout (fun _ => none) memory.nextblock entry.block 0 i memory
    (lhsCont k e (opTemps le)) (.Vlong value) value (0#8) observed rfl (by decide) (by decide)
  have finish := after_lhs Arm64ProgramEntryLinked.ge e le memory k value op
  simpa only [CC.callCont, lhsCont] using (enter.trans read).trans finish

end KProgFormal.ClightRefinement.Arm64Mul.Operands
