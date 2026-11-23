import KProgFormal.ClightRefinement.Arm64ProgramEntryOrnCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Orn.ReadEntry

private structure Pieces where
  branch : CC.Stmt
  body : CC.Stmt
  opSet : CC.Stmt
  readCall : CC.Stmt
  lhsSet : CC.Stmt
  rhs : CC.Stmt
  writer : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "actual ORN reader constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let outerBody ← peel root[0]! ``CC.Stmt.Ssequence 2
    let mut rest := outerBody[1]!
    for i in [:21] do
      let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      if node.isAppOfArity ``CC.Stmt.Ssequence 2 then
        node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "actual ORN gate changed {i}"
      rest := node.getAppArgs[2]!
      if i == 20 then
        let actual := node.getAppArgs[1]!
        let branch ← peel actual ``CC.Stmt.Ssequence 2
        let loop ← peel branch[0]! ``CC.Stmt.Sloop 2
        let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
        let operand ← peel body[1]! ``CC.Stmt.Ssequence 2
        let read ← peel operand[0]! ``CC.Stmt.Ssequence 2
        Lean.Elab.Tactic.closeMainGoal `actual_orn_reader
          (← Lean.Meta.mkAppM ``Pieces.mk
            #[actual,loop[0]!,body[0]!,read[0]!,read[1]!,operand[1]!,branch[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_orn_read_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def branch : CC.Stmt := by run_tac cachePart (← `(pieces.branch))
def body : CC.Stmt := by run_tac cachePart (← `(pieces.body))
private def opSet : CC.Stmt := by run_tac cachePart (← `(pieces.opSet))
private def readCall : CC.Stmt := by run_tac cachePart (← `(pieces.readCall))
def lhsSet : CC.Stmt := by run_tac cachePart (← `(pieces.lhsSet))
def rhs : CC.Stmt := by run_tac cachePart (← `(pieces.rhs))
def writer : CC.Stmt := by run_tac cachePart (← `(pieces.writer))

/-- The original branch retains its RHS/numeric suffix and scalar writer. -/
theorem branch_source : branch = .Ssequence (.Sloop body .Sbreak) writer := rfl

theorem body_source : body =
    .Ssequence opSet (.Ssequence (.Ssequence readCall lhsSet) rhs) := rfl

private theorem op_source : opSet = .Sset Arm64Program.___kprog_a64_orn_op
    (.Ecast (.Etempvar Arm64Program._op CC.tuint) CC.tulong) := rfl

private theorem read_source : readCall =
    .Scall (some Arm64Program._t'137)
      (.Evar Arm64Program._kprog_arm64_program_read
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong]
          CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._src CC.tulong] := rfl

private theorem reader_type :
    CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_read) =
      .Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong]
        CC.tulong CC.cc_default := rfl

def opTemps (le : CC.TempEnv) : CC.TempEnv :=
  le.set Arm64Program.___kprog_a64_orn_op (.Vlong (53#64))

def innerCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq writer k)

def callCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'137) Arm64Nop.handler e (opTemps le)
    (.Kseq lhsSet (.Kseq rhs (innerCont k)))

private theorem read_step (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong sourceWord)) :
    CC.Step2 world (.State Arm64Nop.handler readCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs,.Vlong sourceWord]
        (.Kcall (some Arm64Program._t'137) Arm64Nop.handler e le k) m) := by
  rw [read_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,CC.doDerefLoc,CC.accessMode,
      CC.typeof,unshadowed,binding.1,CC.Integers.Ptrofs.zero,CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    simp +decide [CC.doEvalExprlist,CC.doEvalExpr,entry,source,CC.typeof,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,
      CC.tattr,CC.tptr,CC.tulong,CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · exact reader_type

set_option hygiene false in
/-- Actual ORN source prefix to the scalar reader call, preserving the complete
heap and its original pending value copy, condition, numeric body and writer.
sourceWord is the original register index, not an assumed read result. -/
theorem enter (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong sourceWord))
    (op : le.get Arm64Program._op = some (.Vint (53#32))) :
    InternalRun world 8 (.State Arm64Nop.handler branch k e le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr b ofs,.Vlong sourceWord] (callCont k e le) m) := by
  have entry' : (opTemps le).get Arm64Program._entry = some (.Vptr b ofs) := by
    simp +decide only [opTemps,CC.PTree.gso,entry]
  have source' : (opTemps le).get Arm64Program._src = some (.Vlong sourceWord) := by
    simp +decide only [opTemps,CC.PTree.gso,source]
  run_tac do
    for _ in [:7] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,branch_source,body_source,
        op_source,opTemps,innerCont,callCont,CC.PTree.gss,CC.PTree.gso,op,CC.doEvalExpr,CC.typeof,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.Cop.classifyBool,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tulong,
        CC.Integers.Int64.repr,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Integers.MI.repr,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
  exact .step trivial (read_step world block b ofs e (opTemps le) m
    (.Kseq lhsSet (.Kseq rhs (innerCont k))) sourceWord binding unshadowed entry' source') (.refl _)

private theorem lhs_source : lhsSet = .Sset Arm64Program.___kprog_a64_orn_lhs
    (.Etempvar Arm64Program._t'137 CC.tulong) := rfl

def lhsTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((opTemps le).set Arm64Program._t'137 (.Vlong value)).set
    Arm64Program.___kprog_a64_orn_lhs (.Vlong value)

set_option hygiene false in
/-- The actual reader return is copied into the original ORN operand before
resuming the untouched RHS and numeric suffix. Full memory is unchanged. -/
theorem returned (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64) :
    InternalRun world 4
      (.Returnstate (.Vlong value) (callCont k e le) m)
      (.State Arm64Nop.handler rhs (innerCont k) e (lhsTemps le value) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,callCont,innerCont,
        lhs_source,lhsTemps,CC.setOpttemp,CC.PTree.gss,CC.doEvalExpr,CC.typeof,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Run the actual scalar or warm-stack reader between its real ORN entry
and return. The observations are pre-memory loads; no read result or updated
heap is supplied. Relative pointers use the existing M3 materialization. -/
theorem scalar (origins : Reference.Provenance.AArch64.Origins)
    (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 31)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (raw : BitVec 64) (tag : BitVec 8)
    (tags : tag = 0 ∨ tag = 4)
    (observed : Arm64EntryMemory.gpr frontier m (.Vptr b ofs) i.val =
      some (.Vlong raw,.Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false frontier m (.Vptr b ofs) origins.stack)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (op : le.get Arm64Program._op = some (.Vint (53#32))) :
    InternalRun Arm64ProgramEntryLinked.ge (if tag = 4 then 103 else 85)
      (.State Arm64Nop.handler branch k e le m)
      (.State Arm64Nop.handler rhs (innerCont k) e
        (lhsTemps le (Reference.Provenance.AArch64.materialize origins raw tag)) m) := by
  have start := enter Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 66) b ofs e le m k
    (BitVec.ofNat 64 i.val) Arm64AddOperandReads.Linked.bindings.2.2 unshadowed entry source op
  rcases tags with rfl|rfl
  · have read := Arm64RegisterReads.gpr_read_nonrelative_bound Arm64ProgramEntryLinked.ge
      Arm64MovKeep.Linked.reader_layout (fun _ => none) frontier b ofs i m
      (callCont k e le) (.Vlong raw) raw (0#8) observed rfl (by decide) (by decide)
    have finish := returned Arm64ProgramEntryLinked.ge e le m k raw
    simpa +decide only [CC.callCont,callCont,Reference.Provenance.AArch64.materialize,ite_false,ite_true]
      using (start.trans read).trans finish
  · have read := Arm64RegisterReads.gpr_read_stack_bound Arm64ProgramEntryLinked.ge
      Arm64MovKeep.Linked.reader_layout Arm64ProgramEntryColdRead.stack_layout frontier b ofs i m
      (callCont k e le) raw origins.stack observed (cache rfl)
    have finish := returned Arm64ProgramEntryLinked.ge e le m k (raw + origins.stack)
    simpa +decide only [CC.callCont,callCont,Reference.Provenance.AArch64.materialize,ite_true]
      using (start.trans read).trans finish

/-- The next real RHS/numeric suffix reads the actual materialized word;
all original input temporaries and the computed width survive this prefix. -/
theorem ready (le : CC.TempEnv) (value : BitVec 64) :
    (lhsTemps le value).get Arm64Program.___kprog_a64_orn_lhs = some (.Vlong value) ∧
    ∀ id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
      Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,
      Arm64Program.___a64_l_width], (lhsTemps le value).get id = le.get id := by
  constructor
  · simp only [lhsTemps,CC.PTree.gss]
  · intro id original
    simp at original
    rcases original with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals simp +decide only [lhsTemps,opTemps,CC.PTree.gso]

end KProgFormal.ClightRefinement.Arm64Orn.ReadEntry
