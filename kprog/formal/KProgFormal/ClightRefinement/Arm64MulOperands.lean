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

private structure RhsPieces where
  call : CC.Stmt
  widthChoice : CC.Stmt
  maskChoice : CC.Stmt
  valueSet : CC.Stmt
  addend : CC.Stmt

private def rhsPieces : RhsPieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual MUL RHS constructors changed"
      pure actual.getAppArgs
    let suffix ← peel (← Lean.Elab.Term.elabTerm (← `(rhs)) none)
    let block ← peel suffix[0]!
    let masked ← peel block[0]!
    let pair ← peel masked[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_mul_rhs (← Lean.Meta.mkAppM ``RhsPieces.mk
      #[pair[0]!, pair[1]!, masked[1]!, block[1]!, suffix[1]!])

private def rhsCall : CC.Stmt := by run_tac cachePart (← `(rhsPieces.call))
private def rhsWidthChoice : CC.Stmt := by run_tac cachePart (← `(rhsPieces.widthChoice))
private def rhsMaskChoice : CC.Stmt := by run_tac cachePart (← `(rhsPieces.maskChoice))
private def rhsSet : CC.Stmt := by run_tac cachePart (← `(rhsPieces.valueSet))
def addend : CC.Stmt := by run_tac cachePart (← `(rhsPieces.addend))
private def rhsBlock : CC.Stmt := .Ssequence (.Ssequence (.Ssequence rhsCall rhsWidthChoice) rhsMaskChoice) rhsSet

/-- The actual RHS suffix with its original pending third read/product. -/
theorem rhs_source : rhs = .Ssequence rhsBlock addend := rfl

private def rhsCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'45) Arm64Nop.handler e le
    (.Kseq rhsWidthChoice (.Kseq rhsMaskChoice (.Kseq rhsSet (.Kseq addend (tailCont k)))))

def rhsTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((((((((le).set Arm64Program._t'45 (.Vlong value)).set Arm64Program._t'46 (.Vint (8#32))).set Arm64Program._t'48 (.Vint (8#32))).set Arm64Program._t'49 (.Vint (8#32))).set Arm64Program._t'47 (.Vlong (BitVec.ofInt 64 (-1)))).set Arm64Program._t'47 (.Vlong (BitVec.ofInt 64 (-1)))).set Arm64Program._t'47 (.Vlong (BitVec.ofInt 64 (-1)))).set Arm64Program.___kprog_a64_mul_rhs (.Vlong value)

private theorem rhs_call_source : rhsCall =
    .Scall (some Arm64Program._t'45)
      (.Evar Arm64Program._kprog_arm64_program_read
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._src2 CC.tulong] := rfl

private theorem call_rhs (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src2 = some (.Vlong sourceWord)) :
    CC.Step2 world (.State Arm64Nop.handler rhsCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong sourceWord]
        (.Kcall (some Arm64Program._t'45) Arm64Nop.handler e le k) m) := by
  rw [rhs_call_source]
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
private theorem enter_rhs (world : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (sourceWord : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src2 = some (.Vlong sourceWord))
    (op : le.get Arm64Program._op = some (.Vint (12#32))) :
    InternalRun world 5 (.State Arm64Nop.handler rhs (tailCont k) e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong sourceWord] (rhsCont k e le) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, rhs_source, rhsBlock,
        rhsCall, rhsCont, tailCont,
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
        (call_rhs world block b ofs e _ m _ sourceWord binding unshadowed entry source) (InternalRun.refl _)))

set_option hygiene false in
private theorem after_rhs (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (op : le.get Arm64Program._op = some (.Vint (12#32))) :
    InternalRun world 26
      (.Returnstate (.Vlong value) (rhsCont k e le) m)
      (.State Arm64Nop.handler addend (tailCont k) e (rhsTemps le value) m) := by
  run_tac do
    for _ in [:26] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,
        rhsCont, tailCont, rhsTemps, rhsWidthChoice, rhsMaskChoice, rhsSet, op,
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

/-- Actual scalar RHS/masks, preserving the reached heap and all incoming
LHS state, reaching the original third-read/product suffix. -/
theorem rhs_scalar {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i : Fin 31) (value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 i.val)))
    (op : le.get Arm64Program._op = some (.Vint (12#32)))
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 104
      (.State Arm64Nop.handler rhs (tailCont k) e le memory)
      (.State Arm64Nop.handler addend (tailCont k) e (rhsTemps le value) memory) := by
  have observed : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong value, .Vint ((0#8).setWidth 32)) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  have enter := enter_rhs Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 66)
    Arm64AddOperandReads.Linked.bindings.2.2 entry.block 0 e le memory k
    (BitVec.ofNat 64 i.val) readName entryRead source op
  have read := Arm64RegisterReads.gpr_read_nonrelative_bound Arm64ProgramEntryLinked.ge
    Arm64MovKeep.Linked.reader_layout (fun _ => none) memory.nextblock entry.block 0 i memory
    (rhsCont k e le) (.Vlong value) value (0#8) observed rfl (by decide) (by decide)
  have finish := after_rhs Arm64ProgramEntryLinked.ge e le memory k value op
  simpa only [CC.callCont, rhsCont] using (enter.trans read).trans finish

/-- The actual combined reader at255 returns zero without any storage,
layout, cache, external-input or successful-read premise. -/
theorem read_zero (world : CC.CGenv) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 55
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong (255#64)] k m)
      (.Returnstate (.Vlong 0) (CC.callCont k) m) := by
  repeat first
    | exact InternalRun.refl _
    | apply InternalRun.step
      · trivial
      · apply CC.doStep_sound
        simp +decide only [CC.doStep, CC.doFunctionEntry2, Arm64Program.f_kprog_arm64_program_read,
        CC.doAllocVariables, CC.bindParameterTemps, CC.createUndefTemps,
        CC.doEvalExpr, CC.doEvalExprlist, CC.doEvalLvalue, CC.setOpttemp,
        CC.PTree.gss, CC.PTree.gso, CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.boolVal, CC.Cop.classifyBool, CC.tuchar, CC.tuint, CC.tint, CC.tlong, CC.tulong, CC.tptr,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
        CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.Int64.ltu,
        CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.MI.cmpu, CC.Integers.MI.eq, CC.Integers.MI.ltu,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.Integers.Int.unsigned, CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
        CC.Integers.Int.zero, CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
        CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
        Bool.false_eq_true, Bool.true_eq_false] <;> try rfl


private structure AddendPieces where
  call : CC.Stmt
  valueSet : CC.Stmt
  product : CC.Stmt

private def addendPieces : AddendPieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual MUL addend constructors changed"
      pure actual.getAppArgs
    let suffix ← peel (← Lean.Elab.Term.elabTerm (← `(addend)) none)
    let pair ← peel suffix[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_mul_addend (← Lean.Meta.mkAppM ``AddendPieces.mk
      #[pair[0]!, pair[1]!, suffix[1]!])

private def addendCall : CC.Stmt := by run_tac cachePart (← `(addendPieces.call))
private def addendSet : CC.Stmt := by run_tac cachePart (← `(addendPieces.valueSet))
def product : CC.Stmt := by run_tac cachePart (← `(addendPieces.product))

theorem addend_source : addend = .Ssequence (.Ssequence addendCall addendSet) product := rfl

private def addendCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'50) Arm64Nop.handler e le
    (.Kseq addendSet (.Kseq product (tailCont k)))

def addendTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set Arm64Program._t'50 (.Vlong 0)).set Arm64Program.___kprog_a64_mul_addend (.Vlong 0)

private theorem addend_call_source : addendCall =
    .Scall (some Arm64Program._t'50)
      (.Evar Arm64Program._kprog_arm64_program_read
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._src3 CC.tulong] := rfl

private theorem call_addend (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src3 = some (.Vlong sourceWord)) :
    CC.Step2 world (.State Arm64Nop.handler addendCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong sourceWord]
        (.Kcall (some Arm64Program._t'50) Arm64Nop.handler e le k) m) := by
  rw [addend_call_source]
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
private theorem enter_addend (world : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (sourceWord : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src3 = some (.Vlong sourceWord)) :
    InternalRun world 3 (.State Arm64Nop.handler addend (tailCont k) e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong sourceWord] (addendCont k e le) m) := by
  run_tac do
    for _ in [:2] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep, addend_source] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic|
      exact InternalRun.step trivial
        (call_addend world block b ofs e le m _ sourceWord binding unshadowed entry source) (InternalRun.refl _)))

set_option hygiene false in
private theorem after_addend (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) :
    InternalRun world 4 (.Returnstate (.Vlong 0) (addendCont k e le) m)
      (.State Arm64Nop.handler product (tailCont k) e (addendTemps le) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep, addendCont, addendTemps, addendSet,
        CC.setOpttemp, CC.PTree.gss, CC.doEvalExpr, CC.typeof,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.typeconv, CC.removeAttributes, CC.tattr, CC.tulong] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The actual unused third operand is still read and assigned through the
original call/reader/return, on arbitrary memory with no provider premise. -/
theorem addend_zero (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src3 = some (.Vlong (255#64))) :
    InternalRun Arm64ProgramEntryLinked.ge 62
      (.State Arm64Nop.handler addend (tailCont k) e le m)
      (.State Arm64Nop.handler product (tailCont k) e (addendTemps le) m) := by
  have enter := enter_addend Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 66)
    Arm64AddOperandReads.Linked.bindings.2.2 b ofs e le m k (255#64) readName entryRead source
  have read := read_zero Arm64ProgramEntryLinked.ge b ofs m (addendCont k e le)
  have finish := after_addend Arm64ProgramEntryLinked.ge e le m k
  simpa only [CC.callCont, addendCont] using (enter.trans read).trans finish

end KProgFormal.ClightRefinement.Arm64Mul.Operands
