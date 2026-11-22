import KProgFormal.ClightRefinement.Arm64ProgramEntrySelectCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Cneg.ReadEntry

private structure Pieces where
  branch : CC.Stmt
  body : CC.Stmt
  opSet : CC.Stmt
  readCall : CC.Stmt
  valueSet : CC.Stmt
  tail : CC.Stmt
  writer : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "actual CNEG reader constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let outerBody ← peel root[0]! ``CC.Stmt.Ssequence 2
    let mut rest := outerBody[1]!
    for i in [:9] do
      let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      if node.isAppOfArity ``CC.Stmt.Ssequence 2 then
        node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "actual CNEG gate changed {i}"
      rest := node.getAppArgs[2]!
      if i == 8 then
        let actual := node.getAppArgs[1]!
        let branch ← peel actual ``CC.Stmt.Ssequence 2
        let loop ← peel branch[0]! ``CC.Stmt.Sloop 2
        let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
        let operand ← peel body[1]! ``CC.Stmt.Ssequence 2
        let read ← peel operand[0]! ``CC.Stmt.Ssequence 2
        Lean.Elab.Tactic.closeMainGoal `actual_cneg_reader
          (← Lean.Meta.mkAppM ``Pieces.mk
            #[actual,loop[0]!,body[0]!,read[0]!,read[1]!,operand[1]!,branch[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_cneg_read_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def branch : CC.Stmt := by run_tac cachePart (← `(pieces.branch))
def body : CC.Stmt := by run_tac cachePart (← `(pieces.body))
private def opSet : CC.Stmt := by run_tac cachePart (← `(pieces.opSet))
private def readCall : CC.Stmt := by run_tac cachePart (← `(pieces.readCall))
def valueSet : CC.Stmt := by run_tac cachePart (← `(pieces.valueSet))
def tail : CC.Stmt := by run_tac cachePart (← `(pieces.tail))
def writer : CC.Stmt := by run_tac cachePart (← `(pieces.writer))

/-- The original branch retains its condition/numeric suffix and scalar writer. -/
theorem branch_source : branch = .Ssequence (.Sloop body .Sbreak) writer := rfl

theorem body_source : body =
    .Ssequence opSet (.Ssequence (.Ssequence readCall valueSet) tail) := rfl

private theorem op_source : opSet = .Sset Arm64Program.___kprog_a64_cneg_op
    (.Ecast (.Etempvar Arm64Program._op CC.tuint) CC.tulong) := rfl

private theorem read_source : readCall =
    .Scall (some Arm64Program._t'54)
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
  le.set Arm64Program.___kprog_a64_cneg_op (.Vlong (65#64))

def tailCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq writer k)

def callCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'54) Arm64Nop.handler e (opTemps le)
    (.Kseq valueSet (.Kseq tail (tailCont k)))

private theorem read_step (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong sourceWord)) :
    CC.Step2 world (.State Arm64Nop.handler readCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr b ofs,.Vlong sourceWord]
        (.Kcall (some Arm64Program._t'54) Arm64Nop.handler e le k) m) := by
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
/-- Actual CNEG source prefix to the scalar reader call, preserving the complete
heap and its original pending value copy, condition, numeric body and writer.
sourceWord is the original register index, not an assumed read result. -/
theorem enter (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sourceWord : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_read))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (source : le.get Arm64Program._src = some (.Vlong sourceWord))
    (op : le.get Arm64Program._op = some (.Vint (65#32))) :
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
        op_source,opTemps,tailCont,callCont,CC.PTree.gss,CC.PTree.gso,op,CC.doEvalExpr,CC.typeof,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,CC.Cop.classifyBool,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tulong,
        CC.Integers.Int64.repr,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,CC.Integers.MI.repr,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
  exact .step trivial (read_step world block b ofs e (opTemps le) m
    (.Kseq valueSet (.Kseq tail (tailCont k))) sourceWord binding unshadowed entry' source') (.refl _)

end KProgFormal.ClightRefinement.Arm64Cneg.ReadEntry
