import KProgFormal.ClightRefinement.Arm64MemcpyTransferSetup

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTransferLoop

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  body : CC.Stmt
  increment : CC.Stmt
  test : CC.Expr
  work : CC.Stmt
  atSet : CC.Stmt
  selected : CC.Stmt
  selector : CC.Stmt
  storeGuard : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy transfer loop changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyTransferSetup.loop)) none) ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let guard ← peel body[0]! ``CC.Stmt.Sifthenelse 3
    let work ← peel body[1]! ``CC.Stmt.Ssequence 2
    let selected ← peel work[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_transfer_loop
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,loop[1]!,guard[0]!,body[1]!,work[0]!,work[1]!,selected[0]!,selected[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_transfer_loop_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def increment : CC.Stmt := by run_tac cachePart (← `(parts.increment))
private def test : CC.Expr := by run_tac cachePart (← `(parts.test))
def work : CC.Stmt := by run_tac cachePart (← `(parts.work))
private def atSet : CC.Stmt := by run_tac cachePart (← `(parts.atSet))
private def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))
private def selector : CC.Stmt := by run_tac cachePart (← `(parts.selector))
private def storeGuard : CC.Stmt := by run_tac cachePart (← `(parts.storeGuard))
private theorem loop_source : Arm64MemcpyTransferSetup.loop = .Sloop body increment := rfl
private theorem body_source : body = .Ssequence (.Sifthenelse test .Sskip .Sbreak) work := rfl
private theorem work_source : work = .Ssequence atSet selected := rfl
private theorem selected_source : selected = .Ssequence selector storeGuard := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body increment k
def active (i : Fin 16) : Bool := i.val == 0 || i.val == 8
def position (i : Fin 16) : BitVec 64 := (80#64)+BitVec.ofNat 64 i.val
def temps (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv :=
  (le.set Arm64Program.___a64_mt_at (.Vlong (position i))).set Arm64Program._t'86 (.Vint (if active i then 1 else 0))
theorem active_positions : ∀ i : Fin 16, active i = true ↔ i.val = 0 ∨ i.val = 8 := by decide +kernel

private theorem test_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i length : BitVec 64)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong i))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong length)) :
    CC.doEvalExpr world e le m test = some (CC.Val.ofBool (i.ult length)) := by
  simp only [test,CC.doEvalExpr,hi,hlen,CC.Cop.semBinaryOperation,CC.typeof,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.tulong,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Archi.ptr64,
    CC.Integers.Int64.cmpu,CC.Integers.MI.cmpu,CC.Integers.MI.ltu,ite_true,ite_false]

theorem guard_true (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i length : BitVec 64)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong i))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong length)) (less : i.ult length = true) :
    InternalRun world 4 (.State handler Arm64MemcpyTransferSetup.loop k e le m)
      (.State handler work (continuation k) e le m) := by
  have eval := test_eval e le m i length hi hlen
  rw [less] at eval
  rw [loop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq work (continuation k)) e le m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep]
    rw [eval]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private def atTemps (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv := le.set Arm64Program.___a64_mt_at (.Vlong (position i))
private theorem at_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hdst : le.get Arm64Program.___a64_mt_dst = some (.Vlong 80)) :
    CC.doStep world (.State handler atSet k e le m) =
      some (CC.E0,.State handler .Sskip k e (atTemps le i) m) := by
  simp only [CC.doStep,atSet,CC.doEvalExpr,hi,hdst,atTemps,position,CC.Cop.semBinaryOperation,
    CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,
    CC.Integers.Int64.add,CC.Integers.MI.add]
  rfl

private def firstTest : CC.Expr := .Eunop .Onotbool (.Etempvar Arm64Program.___a64_mt_i CC.tulong) CC.tint
private def firstSet : CC.Stmt := .Sset Arm64Program._t'86 (.Econst_int (CC.Integers.Int.repr 1) CC.tint)
private def alignedTest : CC.Expr := .Eunop .Onotbool (.Ebinop .Oand
  (.Etempvar Arm64Program.___a64_mt_at CC.tulong) (.Econst_int (CC.Integers.Int.repr 7) CC.tuint) CC.tulong) CC.tint
private def alignedSet : CC.Stmt := .Sset Arm64Program._t'86 (.Ecast alignedTest CC.tbool)
private theorem selector_source : selector = .Sifthenelse firstTest firstSet alignedSet := rfl
private def picked (i : Fin 16) : CC.Stmt := if i.val == 0 then firstSet else alignedSet
private theorem first_data : ∀ i : Fin 16, (BitVec.ofNat 64 i.val == (0#64)) = (i.val == 0) := by decide +kernel
private theorem aligned_data : ∀ i : Fin 16, (position i &&& (7#64) == (0#64)) = active i := by decide +kernel
private theorem first_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.doEvalExpr world e le m firstTest = some (.Vint (if i.val == 0 then 1 else 0)) := by
  simp only [firstTest,CC.doEvalExpr,hi,CC.Cop.semUnaryOperation,CC.Cop.semNotbool,
    CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,
    CC.Integers.Int64.eq,CC.Integers.MI.eq,CC.Integers.Int64.zero,CC.Integers.MI.zero]
  change some (CC.Val.ofBool (!( !(BitVec.ofNat 64 i.val == (0#64))))) = _
  rw [Bool.not_not,first_data]
  cases i.val == 0 <;> rfl
private theorem aligned_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 16)
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position i))) :
    CC.doEvalExpr world e le m alignedTest = some (.Vint (if active i then 1 else 0)) := by
  simp only [alignedTest,CC.doEvalExpr,hat,CC.Cop.semUnaryOperation,CC.Cop.semNotbool,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
    CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tulong,CC.tuint,CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
    CC.Integers.Int64.and,CC.Integers.MI.and,CC.Integers.Int64.eq,CC.Integers.MI.eq,
    CC.Integers.Int64.zero,CC.Integers.MI.zero,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned]
  change some (CC.Val.ofBool (!( !(position i &&& (7#64) == (0#64))))) = _
  rw [Bool.not_not,aligned_data]
  cases active i <;> rfl

private theorem selector_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val))) :
    CC.doStep world (.State handler selector k e le m) = some (CC.E0,.State handler (picked i) k e le m) := by
  rw [selector_source]
  simp only [CC.doStep]
  rw [first_eval e le m i hi]
  cases first : i.val == 0 <;> simp only [picked,first,firstTest,CC.typeof] <;> rfl
private theorem picked_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position i))) :
    CC.doStep world (.State handler (picked i) k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'86 (.Vint (if active i then 1 else 0))) m) := by
  by_cases first : (i.val == 0) = true
  · have selected : active i = true := by simp only [active,first,Bool.true_or]
    simp only [picked,first,ite_true,firstSet,CC.doStep,CC.doEvalExpr,selected]
    rfl
  · have zero : (i.val == 0) = false := Bool.eq_false_iff.mpr first
    simp only [picked,zero,Bool.false_eq_true,ite_false,alignedSet,CC.doStep,CC.doEvalExpr]
    rw [aligned_eval e le m i hat]
    cases active i <;> rfl
private theorem selector_run (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hat : le.get Arm64Program.___a64_mt_at = some (.Vlong (position i))) :
    InternalRun world 2 (.State handler selector k e le m)
      (.State handler .Sskip k e (le.set Arm64Program._t'86 (.Vint (if active i then 1 else 0))) m) := by
  have safe : InternalState (.State handler (picked i) k e le m) := by
    unfold picked
    split <;> trivial
  exact .step trivial (CC.doStep_sound _ _ _ _ (selector_step e le m k i hi))
    (.step safe (CC.doStep_sound _ _ _ _ (picked_step e le m k i hat)) (.refl _))
private def storeTest : CC.Expr := .Etempvar Arm64Program._t'86 CC.tint
private theorem store_guard_source : storeGuard = .Sifthenelse storeTest
    Arm64Program.s_kprog_arm64_program_memcpy_110 .Sskip := rfl
private theorem store_guard_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16) :
    CC.doStep world (.State handler storeGuard k e (le.set Arm64Program._t'86 (.Vint (if active i then 1 else 0))) m) =
      some (CC.E0,.State handler (if active i then Arm64Program.s_kprog_arm64_program_memcpy_110 else .Sskip) k e
        (le.set Arm64Program._t'86 (.Vint (if active i then 1 else 0))) m) := by
  rw [store_guard_source]
  simp only [CC.doStep,storeTest,CC.doEvalExpr,CC.PTree.gss]
  cases active i <;> rfl

/-- The actual address assignment and first/alignment selectors choose the
real copy-tag body at counters0 and8, retaining every original branch. -/
theorem prepare (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hdst : le.get Arm64Program.___a64_mt_dst = some (.Vlong 80)) :
    InternalRun world 8 (.State handler work k e le m)
      (.State handler (if active i then Arm64Program.s_kprog_arm64_program_memcpy_110 else .Sskip) k e (temps le i) m) := by
  have hi1 : (atTemps le i).get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simpa +decide only [atTemps,CC.PTree.gso] using hi
  have hat : (atTemps le i).get Arm64Program.___a64_mt_at = some (.Vlong (position i)) := CC.PTree.gss _ _ _
  have finish : InternalRun world 2
      (.State handler .Sskip (.Kseq storeGuard k) e (temps le i) m)
      (.State handler (if active i then Arm64Program.s_kprog_arm64_program_memcpy_110 else .Sskip) k e (temps le i) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ (store_guard_step e (atTemps le i) m k i)) (.refl _))
  rw [work_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (at_step e le m _ i hi hdst)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [selected_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact (selector_run e (atTemps le i) m (.Kseq storeGuard k) i hi1 hat).trans finish

/-- The actual unsigned increment restores the real original loop. -/
theorem advance (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : BitVec 64)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong i)) :
    InternalRun world 3 (.State handler .Sskip (continuation k) e le m)
      (.State handler Arm64MemcpyTransferSetup.loop k e (le.set Arm64Program.___a64_mt_i (.Vlong (i+(1#64)))) m) := by
  rw [loop_source]
  apply internalRun_of_steps
  · simp only [steps,InternalPath,InternalState,CC.doStep,continuation,increment,CC.doEvalExpr,hi,CC.typeof,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntLong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Archi.ptr64,
      CC.tint,CC.tuint,CC.tulong,CC.Integers.Int.signed,CC.Integers.MI.signed,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,ite_true,ite_false]
    decide
  · simp only [steps,CC.doStep,continuation,increment,CC.doEvalExpr,hi,CC.typeof,
      CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntLong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Archi.ptr64,
      CC.tint,CC.tuint,CC.tulong,CC.Integers.Int.signed,CC.Integers.MI.signed,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
      CC.Integers.Int.repr,CC.Integers.Int64.repr,CC.Integers.MI.repr,
      CC.Integers.Int64.add,CC.Integers.MI.add,CC.Eapp,CC.E0,List.nil_append,ite_true,ite_false]
    rfl

theorem guard_false (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i length : BitVec 64)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong i))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong length)) (less : i.ult length = false) :
    InternalRun world 5 (.State handler Arm64MemcpyTransferSetup.loop k e le m) (.State handler .Sskip k e le m) := by
  have eval := test_eval e le m i length hi hlen
  rw [less] at eval
  rw [loop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sbreak (.Kseq work (continuation k)) e le m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep]
    rw [eval]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

theorem observations (le : CC.TempEnv) (i : Fin 16) :
    (temps le i).get Arm64Program.___a64_mt_i = le.get Arm64Program.___a64_mt_i ∧
    (temps le i).get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst ∧
    (temps le i).get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len ∧
    (temps le i).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le i).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (temps le i).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (temps le i).get Arm64Program.___a64_lib_src_tag = le.get Arm64Program.___a64_lib_src_tag ∧
    (temps le i).get Arm64Program.___a64_mt_at = some (.Vlong (position i)) := by
  refine ⟨?_,?_,?_,?_,?_,?_,?_,?_⟩ <;> simp +decide only [temps,CC.PTree.gso,CC.PTree.gss]

/-- Compose the real guard and selectors at the actual sixteen counters. -/
theorem setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16))
    (hdst : le.get Arm64Program.___a64_mt_dst = some (.Vlong 80)) :
    InternalRun world 12 (.State handler Arm64MemcpyTransferSetup.loop k e le m)
      (.State handler (if active i then Arm64Program.s_kprog_arm64_program_memcpy_110 else .Sskip)
        (continuation k) e (temps le i) m) := by
  have less : ∀ j : Fin 16, (BitVec.ofNat 64 j.val).ult (16#64) = true := by decide +kernel
  exact (guard_true e le m k (BitVec.ofNat 64 i.val) (16#64) hi hlen (less i)).trans
    (prepare e le m (continuation k) i hi hdst)

/-- Each of the fourteen inactive positions takes its original guard and
counter backedge on the same actual memory. -/
theorem inactive (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16))
    (hdst : le.get Arm64Program.___a64_mt_dst = some (.Vlong 80)) (notActive : active i = false) :
    InternalRun world 15 (.State handler Arm64MemcpyTransferSetup.loop k e le m)
      (.State handler Arm64MemcpyTransferSetup.loop k e
        ((temps le i).set Arm64Program.___a64_mt_i (.Vlong (BitVec.ofNat 64 i.val+(1#64)))) m) := by
  have selected := setup e le m k i hi hlen hdst
  rw [notActive] at selected
  exact selected.trans (advance e (temps le i) m k (BitVec.ofNat 64 i.val) ((observations le i).1.trans hi))

/-- Counter16 executes the real false guard and outer transfer exits into
the original shared clobber call with its actual memcpy continuation. -/
theorem finish (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (hi : le.get Arm64Program.___a64_mt_i = some (.Vlong 16))
    (hlen : le.get Arm64Program.___a64_mt_len = some (.Vlong 16)) :
    InternalRun world 8
      (.State handler Arm64MemcpyTransferSetup.loop (Arm64MemcpyTransferSetup.continuation k) e le m)
      (.State handler Arm64MemcpyTransferSource.clobbers k e le m) :=
  (guard_false e le m (Arm64MemcpyTransferSetup.continuation k) (16#64) (16#64) hi hlen (by decide +kernel)).trans
    (Arm64MemcpyTransferSource.leave e le m k)

end KProgFormal.ClightRefinement.Arm64MemcpyTransferLoop
