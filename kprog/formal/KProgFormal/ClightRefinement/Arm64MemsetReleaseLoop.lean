import KProgFormal.ClightRefinement.Arm64MemsetClobberEntry

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetReleaseLoop

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper loop)

private structure Parts where
  body : CC.Stmt
  increment : CC.Stmt
  guard : CC.Stmt
  work : CC.Stmt
  capacityRead : CC.Stmt
  guardIf : CC.Stmt
  guardTest : CC.Expr
  offsetSetup : CC.Stmt
  choices : CC.Stmt
  biasRead : CC.Stmt
  offsetSet : CC.Stmt
  lowerIf : CC.Stmt
  upperIf : CC.Stmt
  lowerTest : CC.Expr
  upperSet : CC.Stmt
  upperTest : CC.Expr
  selected : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original clobber byte loop changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(loop)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let guard ← peel body[0]! ``CC.Stmt.Ssequence 2
    let guardIf ← peel guard[1]! ``CC.Stmt.Sifthenelse 3
    let work ← peel body[1]! ``CC.Stmt.Ssequence 2
    let offset ← peel work[0]! ``CC.Stmt.Ssequence 2
    let choices ← peel work[1]! ``CC.Stmt.Ssequence 2
    let lower ← peel choices[0]! ``CC.Stmt.Sifthenelse 3
    let upperSet ← peel lower[1]! ``CC.Stmt.Sset 2
    let upperCast ← peel upperSet[1]! ``CC.Expr.Ecast 2
    let upper ← peel choices[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_release_loop_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,body[0]!,body[1]!,guard[0]!,guard[1]!,guardIf[0]!,
        work[0]!,work[1]!,offset[0]!,offset[1]!,choices[0]!,choices[1]!,lower[0]!,lower[1]!,upperCast[0]!,upper[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_release_loop_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def increment : CC.Stmt := by run_tac cachePart (← `(parts.increment))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
def work : CC.Stmt := by run_tac cachePart (← `(parts.work))
private def capacityRead : CC.Stmt := by run_tac cachePart (← `(parts.capacityRead))
private def guardIf : CC.Stmt := by run_tac cachePart (← `(parts.guardIf))
private def guardTest : CC.Expr := by run_tac cachePart (← `(parts.guardTest))
private def offsetSetup : CC.Stmt := by run_tac cachePart (← `(parts.offsetSetup))
private def choices : CC.Stmt := by run_tac cachePart (← `(parts.choices))
private def biasRead : CC.Stmt := by run_tac cachePart (← `(parts.biasRead))
private def offsetSet : CC.Stmt := by run_tac cachePart (← `(parts.offsetSet))
private def lowerIf : CC.Stmt := by run_tac cachePart (← `(parts.lowerIf))
private def upperIf : CC.Stmt := by run_tac cachePart (← `(parts.upperIf))
private def lowerTest : CC.Expr := by run_tac cachePart (← `(parts.lowerTest))
private def upperSet : CC.Stmt := by run_tac cachePart (← `(parts.upperSet))
private def upperTest : CC.Expr := by run_tac cachePart (← `(parts.upperTest))
def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))

private theorem loop_source : loop = .Sloop body increment := rfl
private theorem body_source : body = .Ssequence guard work := rfl
private theorem guard_source : guard = .Ssequence capacityRead guardIf := rfl
private theorem guard_if_source : guardIf = .Sifthenelse guardTest .Sskip .Sbreak := rfl
private theorem work_source : work = .Ssequence offsetSetup choices := rfl
private theorem offset_source : offsetSetup = .Ssequence biasRead offsetSet := rfl
private theorem choices_source : choices = .Ssequence lowerIf upperIf := rfl
private theorem lower_source : lowerIf = .Sifthenelse lowerTest upperSet
    (.Sset Arm64Program._t'2 (.Econst_int (CC.Integers.Int.repr 0) CC.tint)) := rfl
private theorem upper_set_source : upperSet = .Sset Arm64Program._t'2 (.Ecast upperTest CC.tbool) := rfl
private theorem upper_source : upperIf = .Sifthenelse (.Etempvar Arm64Program._t'2 CC.tint) selected .Sskip := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body increment k
def active (i : Fin 160) : Bool := decide (i.val < 64)
def index (i : Fin 160) : BitVec 32 := BitVec.ofNat 32 i.val
def offset (i : Fin 160) : BitVec 64 := BitVec.ofNat 64 i.val - (96#64)
private def guardTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'237 (.Vint 160)
private def offsetTemps (le : CC.TempEnv) (i : Fin 160) : CC.TempEnv :=
  (le.set Arm64Program._t'236 (.Vlong 96)).set Arm64Program.___a64_release_off (.Vlong (offset i))
def temps (le : CC.TempEnv) (i : Fin 160) : CC.TempEnv :=
  (offsetTemps (guardTemps le) i).set Arm64Program._t'2 (.Vint (if active i then 1 else 0))

theorem active_positions (i : Fin 160) : active i = true ↔ i.val < 64 := by simp only [active,decide_eq_true_eq]
private theorem index_less : ∀ i : Fin 160, (index i).ult (160#32) = true := by decide +kernel
private theorem cast_index : ∀ i : Fin 160,
    CC.Integers.Int64.repr (CC.Integers.Int.unsigned (index i)) = BitVec.ofNat 64 i.val := by decide +kernel
private theorem lower_data : ∀ i : Fin 160, CC.Integers.MI.lt (offset i) (-96#64) = false := by decide +kernel
private theorem upper_data : ∀ i : Fin 160, CC.Integers.MI.lt (offset i) (-32#64) = active i := by decide +kernel

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._capacity entryComposite.co_members = .OK (656,.Full) ∧
    CC.fieldOffset world.genv_cenv Arm64Program._bias entryComposite.co_members = .OK (672,.Full) := by
  constructor
  · decide +kernel
  constructor <;> decide +kernel

private theorem capacity_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (capacity : CC.Mem.load .Mint32 m entry 656 = some (.Vint 160)) :
    CC.doStep world (.State helper capacityRead k e le m) =
      some (CC.E0,.State helper .Sskip k e (guardTemps le) m) := by
  simp only [capacityRead,guardTemps,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,
    CC.lvalOfField,layout.1,layout.2.1,CC.typeof,CC.tuint,CC.tattr,CC.typeconv,
    CC.removeAttributes,CC.doDerefLoc,CC.accessMode,CC.Archi.ptr64,CC.Integers.Ptrofs.add,
    CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have fieldOffset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 656).toNat) : Nat) : Int) = 656 := by decide +kernel
  rw [fieldOffset,capacity]

private theorem bias_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doStep world (.State helper biasRead k e le m) =
      some (CC.E0,.State helper .Sskip k e (le.set Arm64Program._t'236 (.Vlong 96)) m) := by
  simp only [biasRead,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,
    CC.lvalOfField,layout.1,layout.2.2,CC.typeof,CC.tlong,CC.tattr,CC.typeconv,
    CC.removeAttributes,CC.doDerefLoc,CC.accessMode,CC.Archi.ptr64,CC.Integers.Ptrofs.add,
    CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have fieldOffset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
  rw [fieldOffset,bias]

private theorem guard_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (n : BitVec 32)
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint n)) :
    CC.doEvalExpr world e (guardTemps le) m guardTest = some (CC.Val.ofBool (n.ult (160#32))) := by
  have hi : (guardTemps le).get Arm64Program.___a64_release_i = some (.Vint n) := by
    simpa +decide only [guardTemps,CC.PTree.gso] using counter
  simp only [guardTest,CC.doEvalExpr]
  rw [hi]
  simp only [guardTemps,CC.PTree.gss,CC.Cop.semBinaryOperation,
    CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tuint,CC.tattr,CC.Archi.ptr64,
    CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.MI.ltu,ite_true,ite_false]
  rfl

/-- The actual capacity load, true unsigned guard and original wrappers. -/
theorem guard_true (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 160)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint (index i)))
    (capacity : CC.Mem.load .Mint32 m entry 656 = some (.Vint 160)) :
    InternalRun world 7 (.State helper loop k e le m)
      (.State helper work (continuation k) e (guardTemps le) m) := by
  have eval := guard_eval e le m (index i) counter
  rw [index_less] at eval
  rw [loop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [guard_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (capacity_step e le m _ entry hentry capacity)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [guard_if_source]
  refine .step (mid := .State helper .Sskip (.Kseq work (continuation k)) e (guardTemps le) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep]
    rw [eval]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private theorem offset_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 160)
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint (index i))) :
    CC.doStep world (.State helper offsetSet k e (le.set Arm64Program._t'236 (.Vlong 96)) m) =
      some (CC.E0,.State helper .Sskip k e (offsetTemps le i) m) := by
  have hi : (le.set Arm64Program._t'236 (.Vlong 96)).get Arm64Program.___a64_release_i = some (.Vint (index i)) := by
    simpa +decide only [CC.PTree.gso] using counter
  simp only [offsetSet,offsetTemps,CC.doStep,CC.doEvalExpr,hi,CC.PTree.gss,CC.Cop.semBinaryOperation,
    CC.Cop.semSub,CC.Cop.classifySub,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tuint,CC.tlong,CC.tattr,CC.Archi.ptr64,
    cast_index,CC.Integers.Int64.sub,CC.Integers.MI.sub,offset]
  rfl

private theorem lower_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 160)
    (off : le.get Arm64Program.___a64_release_off = some (.Vlong (offset i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64))) :
    CC.doEvalExpr world e le m lowerTest = some (.Vint 1) := by
  simp only [lowerTest,CC.doEvalExpr,off,old,CC.Cop.semBinaryOperation,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tlong,CC.tattr,CC.Archi.ptr64,ite_true,ite_false,CC.Integers.Int64.cmp,CC.Integers.MI.cmp,lower_data]
  rfl

private theorem upper_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 160)
    (off : le.get Arm64Program.___a64_release_off = some (.Vlong (offset i)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64))) :
    CC.doEvalExpr world e le m upperTest = some (.Vint (if active i then 1 else 0)) := by
  simp only [upperTest,CC.doEvalExpr,off,new,CC.Cop.semBinaryOperation,CC.Cop.semCmp,
    CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tlong,CC.tattr,CC.Archi.ptr64,ite_true,ite_false,CC.Integers.Int64.cmp,CC.Integers.MI.cmp,upper_data]
  cases active i <;> rfl

private theorem lower_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 160)
    (off : le.get Arm64Program.___a64_release_off = some (.Vlong (offset i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64))) :
    CC.doStep world (.State helper lowerIf k e le m) = some (CC.E0,.State helper upperSet k e le m) := by
  rw [lower_source]
  simp only [CC.doStep]
  rw [lower_eval e le m i off old]
  rfl

private theorem upper_set_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 160)
    (off : le.get Arm64Program.___a64_release_off = some (.Vlong (offset i)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64))) :
    CC.doStep world (.State helper upperSet k e le m) = some (CC.E0,.State helper .Sskip k e
      (le.set Arm64Program._t'2 (.Vint (if active i then 1 else 0))) m) := by
  rw [upper_set_source]
  simp only [CC.doStep,CC.doEvalExpr]
  rw [upper_eval e le m i off new]
  cases active i <;> rfl

private theorem select_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 160) :
    CC.doStep world (.State helper upperIf k e (le.set Arm64Program._t'2 (.Vint (if active i then 1 else 0))) m) =
      some (CC.E0,.State helper (if active i then selected else .Sskip) k e
        (le.set Arm64Program._t'2 (.Vint (if active i then 1 else 0))) m) := by
  rw [upper_source]
  simp only [CC.doStep,CC.doEvalExpr,CC.PTree.gss]
  cases active i <;> rfl

/-- Actual signed offset and both original predicates select the real store
body for the first64 indices and the genuine skip for the other96. -/
theorem prepare (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 160)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint (index i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64)))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 11 (.State helper work k e le m)
      (.State helper (if active i then selected else .Sskip) k e
        ((offsetTemps le i).set Arm64Program._t'2 (.Vint (if active i then 1 else 0))) m) := by
  have off : (offsetTemps le i).get Arm64Program.___a64_release_off = some (.Vlong (offset i)) := CC.PTree.gss ..
  have old1 : (offsetTemps le i).get Arm64Program.___a64_release_old = some (.Vlong (-96#64)) := by
    simpa +decide only [offsetTemps,CC.PTree.gso] using old
  have new1 : (offsetTemps le i).get Arm64Program.___a64_release_new = some (.Vlong (-32#64)) := by
    simpa +decide only [offsetTemps,CC.PTree.gso] using new
  rw [work_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [offset_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (bias_step e le m _ entry hentry bias)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (offset_step e le m _ i counter)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [choices_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (lower_step e _ m _ i off old1)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (upper_set_step e _ m _ i off new1)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ (select_step e _ m k i)) (.refl _)

private theorem preserved (le : CC.TempEnv) (i : Fin 160) (id : CC.Ident)
    (n2 : Arm64Program._t'2 ≠ id) (noff : Arm64Program.___a64_release_off ≠ id)
    (n236 : Arm64Program._t'236 ≠ id) (n237 : Arm64Program._t'237 ≠ id) :
    (temps le i).get id = le.get id := by
  simp only [temps,offsetTemps,guardTemps,CC.PTree.gso _ _ _ _ n2,
    CC.PTree.gso _ _ _ _ noff,CC.PTree.gso _ _ _ _ n236,CC.PTree.gso _ _ _ _ n237]

theorem observations (le : CC.TempEnv) (i : Fin 160) :
    (temps le i).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le i).get Arm64Program.___a64_release_i = le.get Arm64Program.___a64_release_i ∧
    (temps le i).get Arm64Program.___a64_release_old = le.get Arm64Program.___a64_release_old ∧
    (temps le i).get Arm64Program.___a64_release_new = le.get Arm64Program.___a64_release_new ∧
    (temps le i).get Arm64Program.___a64_release_off = some (.Vlong (offset i)) := by
  refine ⟨?_,?_,?_,?_,?_⟩
  · apply preserved <;> decide +kernel
  · apply preserved <;> decide +kernel
  · apply preserved <;> decide +kernel
  · apply preserved <;> decide +kernel
  · have n2 : Arm64Program._t'2 ≠ Arm64Program.___a64_release_off := by decide +kernel
    simp only [temps,offsetTemps,CC.PTree.gso _ _ _ _ n2,CC.PTree.gss]

/-- Execute actual capacity load and all signed selection control. -/
theorem setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 160)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint (index i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64)))
    (capacity : CC.Mem.load .Mint32 m entry 656 = some (.Vint 160))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 18 (.State helper loop k e le m)
      (.State helper (if active i then selected else .Sskip) (continuation k) e (temps le i) m) := by
  have run := guard_true e le m k entry i hentry counter capacity
  have workRun := prepare e (guardTemps le) m (continuation k) entry i
    (by simpa +decide only [guardTemps,CC.PTree.gso] using hentry)
    (by simpa +decide only [guardTemps,CC.PTree.gso] using counter)
    (by simpa +decide only [guardTemps,CC.PTree.gso] using old)
    (by simpa +decide only [guardTemps,CC.PTree.gso] using new) bias
  exact run.trans workRun

/-- The actual unsigned32 counter store and loop backedge. -/
theorem advance (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (n : BitVec 32)
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint n)) :
    InternalRun world 3 (.State helper .Sskip (continuation k) e le m)
      (.State helper loop k e (le.set Arm64Program.___a64_release_i (.Vint (n + (1#32)))) m) := by
  rw [loop_source]
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,continuation,increment,CC.doEvalExpr,counter,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tint,CC.tuint,CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.MI.repr,
    CC.Integers.Int.add,CC.Integers.MI.add,CC.Eapp,CC.E0,List.nil_append,ite_true,ite_false]
  all_goals first | rfl | decide

theorem inactive (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 160)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint (index i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64)))
    (capacity : CC.Mem.load .Mint32 m entry 656 = some (.Vint 160))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) (inactive : active i = false) :
    InternalRun world 21 (.State helper loop k e le m)
      (.State helper loop k e ((temps le i).set Arm64Program.___a64_release_i (.Vint (index i + (1#32)))) m) := by
  have run := setup e le m k entry i hentry counter old new capacity bias
  rw [inactive] at run
  exact run.trans (advance e (temps le i) m k (index i) ((observations le i).2.1.trans counter))

/-- The actual counter160 guard load/false branch and break wrappers. -/
theorem finish (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint 160))
    (capacity : CC.Mem.load .Mint32 m entry 656 = some (.Vint 160)) :
    InternalRun world 8 (.State helper loop k e le m)
      (.State helper .Sskip k e (guardTemps le) m) := by
  have eval := guard_eval e le m (160#32) counter
  change CC.doEvalExpr world e (guardTemps le) m guardTest = some (.Vint 0) at eval
  rw [loop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [guard_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (capacity_step e le m _ entry hentry capacity)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [guard_if_source]
  refine .step (mid := .State helper .Sbreak (.Kseq work (continuation k)) e (guardTemps le) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep]
    rw [eval]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

end KProgFormal.ClightRefinement.Arm64MemsetReleaseLoop
