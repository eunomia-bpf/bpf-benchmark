import KProgFormal.ClightRefinement.Arm64AddImmediateDispatch

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddRegisterOperands

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
    steps world 17 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source) [.Vlong (7#64)] k m) =
      some (CC.E0, .Returnstate (.Vint (0#32)) (CC.callCont k) m) ∧
    InternalPath world 17 (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source) [.Vlong (7#64)] k m) := by
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


/-- The actual Numeric C selector chooses the register branch for opcode7. -/
theorem selector (world : CC.CGenv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 17
      (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source) [.Vlong (7#64)] k m)
      (.Returnstate (.Vint (0#32)) (CC.callCont k) m) := by
  have run := selector_executes world m k
  exact internalRun_of_steps run.2 run.1

def selectorCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'13) Arm64Nop.handler e le
    (.Kseq (.Sifthenelse test immediate register)
      (.Kloop1 rhsBody Arm64Program.s_kprog_arm64_program_execute_16 k))

set_option hygiene false in
private theorem enter_rhs (world : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_alu_source = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Numeric.f_kprog_arm64_alu_source))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_alu_source = none)
    (op : le.get Arm64Program._op = some (.Vint (7#32))) :
    InternalRun world 3 (.State Arm64Nop.handler rhsLoop k e le m)
      (.Callstate (.Internal Arm64Numeric.f_kprog_arm64_alu_source) [.Vlong (7#64)] (selectorCont k e le) m) := by
  run_tac do
    for _ in [:3] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [rhsLoop, rhs_source, selectorCall, selectorCont,
        CC.doStep, CC.doEvalExprlist, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc,
        CC.typeof, CC.accessMode, unshadowed, binding.1, binding.2, CC.Genv.findFunct,
        CC.typeOfFundef, CC.typeOfFunction, CC.typeOfParams, Arm64Numeric.f_kprog_arm64_alu_source,
        op, CC.Cop.classifyFun, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntLong,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tulong,
        CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int64.repr, CC.Integers.MI.repr,
        CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))


private structure RegisterParts where
  body : CC.Stmt
  readCall : CC.Stmt
  valueSet : CC.Stmt
  modify : CC.Stmt

private def registerParts : RegisterParts := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual register RHS changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(register)) none) ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let read ← peel body[0]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_register_rhs (← Lean.Meta.mkAppM ``RegisterParts.mk
      #[loop[0]!, read[0]!, read[1]!, body[1]!])

private def registerBody : CC.Stmt := by run_tac cachePart (← `(registerParts.body))
private def readCall : CC.Stmt := by run_tac cachePart (← `(registerParts.readCall))
def valueSet : CC.Stmt := by run_tac cachePart (← `(registerParts.valueSet))
def modify : CC.Stmt := by run_tac cachePart (← `(registerParts.modify))

private theorem register_source : register = .Sloop registerBody .Sbreak := rfl
private theorem body_source : registerBody = .Ssequence (.Ssequence readCall valueSet) modify := rfl

def selectedTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'13 (.Vint (0#32))

def readerCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'8) Arm64Nop.handler e (selectedTemps le)
    (.Kseq valueSet (.Kseq modify
      (.Kloop1 registerBody .Sbreak (.Kloop1 rhsBody Arm64Program.s_kprog_arm64_program_execute_16 k))))

private theorem reader_type :
    CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_read) =
      .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default := rfl

private theorem read_source : readCall =
    .Scall (some Arm64Program._t'8)
      (.Evar Arm64Program._kprog_arm64_program_read
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong] CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._src2 CC.tulong] := rfl

private theorem call_reader (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (sourceWord : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src2 = some (.Vlong sourceWord)) :
    CC.Step2 world (.State Arm64Nop.handler readCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs, .Vlong sourceWord]
        (.Kcall (some Arm64Program._t'8) Arm64Nop.handler e le k) m) := by
  rw [read_source]
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
private theorem after_selector (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src2 = some (.Vlong sourceWord)) :
    InternalRun world 7
      (.Returnstate (.Vint (0#32)) (selectorCont k e le) m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong sourceWord] (readerCont k e le) m) := by
  have entry' : (selectedTemps le).get Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide only [selectedTemps, CC.PTree.gso, entry]
  have source' : (selectedTemps le).get Arm64Program._src2 = some (.Vlong sourceWord) := by
    simp +decide only [selectedTemps, CC.PTree.gso, source]
  run_tac do
    for _ in [:6] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, selectorCont, readerCont,
        selectedTemps, test, register_source, body_source, CC.setOpttemp, CC.PTree.gss,
        CC.doEvalExpr, CC.typeof, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self] <;> try rfl))
  exact InternalRun.step trivial
    (call_reader world block b ofs sourceWord e _ m _ binding unshadowed entry' source') (.refl _)

/-- Opcode7 reaches the actual SRC2 reader. The immediate path is skipped,
all casts and continuations are retained, and no memory validity is assumed. -/
theorem enter_reader (world : CC.CGenv) (selectorBlock readBlock b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (selectorBinding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_alu_source = some selectorBlock ∧
      CC.Genv.findFunctPtr world.genv_genv selectorBlock = some (.Internal Arm64Numeric.f_kprog_arm64_alu_source))
    (readerBinding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some readBlock ∧
      CC.Genv.findFunctPtr world.genv_genv readBlock = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (selectorName : e.get Arm64Program._kprog_arm64_alu_source = none)
    (readerName : e.get Arm64Program._kprog_arm64_program_read = none)
    (op : le.get Arm64Program._op = some (.Vint (7#32)))
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src2 = some (.Vlong sourceWord)) :
    InternalRun world 27 (.State Arm64Nop.handler rhsLoop k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong sourceWord] (readerCont k e le) m) := by
  have enter := enter_rhs world selectorBlock selectorBinding e le m k selectorName op
  have choose := selector world m (selectorCont k e le)
  have finish := after_selector world readBlock b ofs readerBinding e le m k sourceWord readerName entry source
  simpa only [CC.callCont] using (enter.trans choose).trans finish


namespace Linked
open Arm64ProgramEntryLinked (ge)

/-- The actual caller world's selector and SRC2 reader identities. -/
theorem enter_reader (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (selectorName : e.get Arm64Program._kprog_arm64_alu_source = none)
    (readerName : e.get Arm64Program._kprog_arm64_program_read = none)
    (op : le.get Arm64Program._op = some (.Vint (7#32)))
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src2 = some (.Vlong sourceWord)) :
    InternalRun ge 27 (.State Arm64Nop.handler rhsLoop k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs, .Vlong sourceWord] (readerCont k e le) m) :=
  Arm64AddRegisterOperands.enter_reader ge (CC.Positive.ofNat 100) (CC.Positive.ofNat 66) b ofs
    Arm64AddImmediate.Linked.selector_binding Arm64AddOperandReads.Linked.bindings.2.2
    e le m k sourceWord selectorName readerName op entry source

/-- Read the actual retained STACK-tag cell via the reached warm invocation
cache. The raw coordinate and its origin are materialized exactly once. -/
theorem read_stack {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i : Fin 31) (raw base : BitVec 64) (k : CC.Cont)
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong raw))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint (4#32)))
    (cache : Arm64RegisterReads.WarmEntryCache false memory.nextblock memory (.Vptr entry.block 0) base) :
    InternalRun ge 91
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0, .Vlong (BitVec.ofNat 64 i.val)] k memory)
      (.Returnstate (.Vlong (raw + base)) (CC.callCont k) memory) := by
  have observed : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong raw, .Vint ((4#8).setWidth 32)) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  exact Arm64RegisterReads.gpr_read_stack_bound ge Arm64MovKeep.Linked.reader_layout
    Arm64ProgramEntryColdRead.stack_layout memory.nextblock entry.block 0 i memory k raw base observed cache

/-- Real register selection and the warm SRC2 read share this same memory,
with no replayed provider or fresh post-read heap. -/
theorem rhs_stack {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i : Fin 31) (raw base : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (selectorName : e.get Arm64Program._kprog_arm64_alu_source = none)
    (readerName : e.get Arm64Program._kprog_arm64_program_read = none)
    (op : le.get Arm64Program._op = some (.Vint (7#32)))
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 i.val)))
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong raw))
    (tag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint (4#32)))
    (cache : Arm64RegisterReads.WarmEntryCache false memory.nextblock memory (.Vptr entry.block 0) base) :
    InternalRun ge 118 (.State Arm64Nop.handler rhsLoop k e le memory)
      (.Returnstate (.Vlong (raw + base)) (readerCont k e le) memory) := by
  have enter := enter_reader entry.block 0 e le memory k (BitVec.ofNat 64 i.val)
    selectorName readerName op entryRead source
  have read := read_stack storage i raw base (readerCont k e le) word tag cache
  simpa only [CC.callCont, readerCont] using enter.trans read

end Linked
end KProgFormal.ClightRefinement.Arm64AddRegisterOperands
