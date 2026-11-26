import KProgFormal.ClightRefinement.Arm64MemcpyProgramEntry

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLoop

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  body : CC.Stmt
  increment : CC.Stmt
  test : CC.Expr
  write : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy loop control changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyCopyEntry.loop)) none) ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let test ← peel body[0]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_loop_control
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,loop[1]!,test[0]!,body[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_loop_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def increment : CC.Stmt := by run_tac cachePart (← `(parts.increment))
private def test : CC.Expr := by run_tac cachePart (← `(parts.test))
def write : CC.Stmt := by run_tac cachePart (← `(parts.write))
abbrev loop := Arm64MemcpyCopyEntry.loop
def writeCont (k : CC.Cont) : CC.Cont := .Kloop1 body increment k

theorem source : loop = .Sloop body increment ∧
    body = .Ssequence (.Sifthenelse test .Sskip .Sbreak) write := ⟨rfl,rfl⟩
private theorem loop_source : loop = .Sloop body increment := source.1
private theorem body_source : body = .Ssequence (.Sifthenelse test .Sskip .Sbreak) write := source.2

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

private theorem counter_less : ∀ i : Fin 16, (BitVec.ofNat 64 i.val).ult (16#64) = true := by decide +kernel
private theorem counter_next : ∀ i : Fin 16, BitVec.ofNat 64 i.val + (1#64) = BitVec.ofNat 64 (i.val+1) := by decide +kernel

section Current
variable {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}

/-- Each original copy-loop guard at the actual counter enters its genuine
body with the exact original increment continuation and unchanged heap. -/
theorem enter_current (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m le) :
    InternalRun world 4 (.State handler loop k e le m) (.State handler write (writeCont k) e le m) :=
  guard_true e le m k (BitVec.ofNat 64 i.val) (16#64) current.counter current.length (counter_less i)

/-- After an actual body output supplies the next copied byte, the real C
increment/backedge extends the same current packet and copied progress. -/
theorem advance_current (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val m le)
    (copied : CC.Mem.load .Mint8unsigned m base.stack.block (80 + (i.val : Int)) = some (.Vint (byte.setWidth 32))) :
    ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore (i.val+1) m
        (le.set Arm64Program.___a64_lib_i (.Vlong (BitVec.ofNat 64 (i.val+1)))),
      InternalRun world 3 (.State handler .Sskip (writeCont k) e le m)
        (.State handler loop k e (le.set Arm64Program.___a64_lib_i (.Vlong (BitVec.ofNat 64 (i.val+1)))) m) := by
  refine ⟨{
    packet := current.packet
    callee := current.callee
    entryRead := ?_
    length := ?_
    counter := by simp only [CC.PTree.gss]
    sourceTag := ?_
    copied := ?_ },?_⟩
  · simpa +decide only [CC.PTree.gso] using current.entryRead
  · simpa +decide only [CC.PTree.gso] using current.length
  · simpa +decide only [CC.PTree.gso] using current.sourceTag
  · intro j bound
    by_cases earlier : j.val < i.val
    · exact current.copied j earlier
    · have same : j = i := Fin.ext (by omega)
      subst j
      exact copied
  · simpa only [counter_next,writeCont] using advance e le m k (BitVec.ofNat 64 i.val) current.counter

/-- Counter16 takes the actual final false guard and real break/sequence
transitions to the source tag-transfer continuation, retaining all memory. -/
theorem exit_current (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le) :
    InternalRun world 6 (.State handler loop (Arm64MemcpyCopyEntry.continuation k) e le m)
      (.State handler Arm64MemcpyCopyEntry.afterCopy k e le m) := by
  have exit := guard_false e le m (Arm64MemcpyCopyEntry.continuation k) (16#64) (16#64)
    current.counter current.length (by decide)
  exact exit.trans (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

end Current
end KProgFormal.ClightRefinement.Arm64MemcpyLoop
