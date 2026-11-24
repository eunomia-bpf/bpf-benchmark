import KProgFormal.ClightRefinement.Arm64MemsetSource

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetLoop

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  initializer : CC.Stmt
  loop : CC.Stmt
  body : CC.Stmt
  increment : CC.Stmt
  test : CC.Expr
  write : CC.Stmt
  effects : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do
        throwError "original memset write-loop control changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetSource.afterReads)) none) ``CC.Stmt.Ssequence 2
    let first ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let loop ← peel first[1]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let guard ← peel body[0]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memset_write_loop
      (← Lean.Meta.mkAppM ``Parts.mk #[first[0]!,first[1]!,loop[0]!,loop[1]!,guard[0]!,body[1]!,outer[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_loop_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def initializer : CC.Stmt := by run_tac cachePart (← `(parts.initializer))
def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def increment : CC.Stmt := by run_tac cachePart (← `(parts.increment))
private def test : CC.Expr := by run_tac cachePart (← `(parts.test))
def write : CC.Stmt := by run_tac cachePart (← `(parts.write))
def effects : CC.Stmt := by run_tac cachePart (← `(parts.effects))
def writeCont (k : CC.Cont) : CC.Cont := .Kloop1 body increment k

theorem source : Arm64MemsetSource.afterReads = .Ssequence (.Ssequence initializer loop) effects := rfl
private theorem loop_source : loop = .Sloop body increment := rfl
private theorem body_source : body = .Ssequence (.Sifthenelse test .Sskip .Sbreak) write := rfl

def initializedTemps (entry : CC.Block) (value length : BitVec 64) : CC.TempEnv :=
  (Arm64MemsetSource.readTemps entry value length).set Arm64Program.___a64_lib_i (.Vlong 0)

/-- The real for-loop initializer leaves the original memory/tag/clobber
continuation intact and sets the actual unsigned64 loop variable to0. -/
theorem start (e : CC.Env) (m : CC.Mem) (entry : CC.Block) (value length : BitVec 64) (k : CC.Cont) :
    InternalRun world 4
      (.State handler Arm64MemsetSource.afterReads k e (Arm64MemsetSource.readTemps entry value length) m)
      (.State handler loop (.Kseq effects k) e (initializedTemps entry value length) m) := by
  rw [source]
  apply internalRun_of_steps
  · simp only [steps,InternalPath,InternalState,CC.doStep,initializer,CC.doEvalExpr,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.tint,CC.tulong,CC.Cop.castIntLong,
      CC.Integers.Int.signed,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.MI.signed]
    decide
  · simp only [steps,CC.doStep,initializer,initializedTemps,CC.doEvalExpr,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.tint,CC.tulong,CC.Cop.castIntLong,
      CC.Integers.Int.signed,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.MI.signed,CC.Eapp,CC.E0,List.nil_append]
    rfl

private theorem test_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i length : BitVec 64)
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong i))
    (hlength : le.get Arm64Program.___a64_lib_len = some (.Vlong length)) :
    CC.doEvalExpr world e le m test = some (CC.Val.ofBool (i.ult length)) := by
  simp only [test,CC.doEvalExpr,hi,hlength,CC.Cop.semBinaryOperation,CC.typeof,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.tulong,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Archi.ptr64,
    CC.Integers.Int64.cmpu,CC.Integers.MI.cmpu,CC.Integers.MI.ltu,ite_true,ite_false]

/-- A true actual unsigned loop guard reaches precisely the original byte
write body, retaining its increment and complete surrounding continuation. -/
theorem guard_true (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i length : BitVec 64)
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong i))
    (hlength : le.get Arm64Program.___a64_lib_len = some (.Vlong length))
    (less : i.ult length = true) :
    InternalRun world 4 (.State handler loop k e le m)
      (.State handler write (.Kloop1 body increment k) e le m) := by
  have eval := test_eval e le m i length hi hlength
  rw [less] at eval
  rw [loop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq write (.Kloop1 body increment k)) e le m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep]
    rw [eval]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- The false original guard exits the write loop into the retained tag and
clobber continuation; the endpoint includes the real break transitions. -/
theorem guard_false (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i length : BitVec 64)
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong i))
    (hlength : le.get Arm64Program.___a64_lib_len = some (.Vlong length))
    (less : i.ult length = false) :
    InternalRun world 5 (.State handler loop k e le m) (.State handler .Sskip k e le m) := by
  have eval := test_eval e le m i length hi hlength
  rw [less] at eval
  rw [loop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sbreak (.Kseq write (.Kloop1 body increment k)) e le m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep]
    rw [eval]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- After the original byte body, execute its real unsigned64 increment and
loop-back transitions. No write effect or memory observation is replaced. -/
theorem advance (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : BitVec 64)
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong i)) :
    InternalRun world 3
      (.State handler .Sskip (.Kloop1 body increment k) e le m)
      (.State handler loop k e (le.set Arm64Program.___a64_lib_i (.Vlong (i + (1#64)))) m) := by
  rw [loop_source]
  apply internalRun_of_steps
  · simp only [steps,InternalPath,InternalState,CC.doStep,increment,CC.doEvalExpr,hi,CC.typeof,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntLong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Archi.ptr64,
      CC.tint,CC.tulong,CC.Integers.Int.signed,CC.Integers.MI.signed,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,ite_true,ite_false]
    decide
  · simp only [steps,CC.doStep,increment,CC.doEvalExpr,hi,CC.typeof,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntLong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Archi.ptr64,
      CC.tint,CC.tulong,CC.Integers.Int.signed,CC.Integers.MI.signed,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int64.add,CC.Integers.MI.add,CC.Eapp,CC.E0,List.nil_append,ite_true,ite_false]
    rfl

end KProgFormal.ClightRefinement.Arm64MemsetLoop
