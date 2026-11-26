import KProgFormal.ClightRefinement.Arm64MemsetReleaseComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetReleaseTagLoop

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper tags)

private structure Parts where
  init : CC.Stmt
  loop : CC.Stmt
  body : CC.Stmt
  increment : CC.Stmt
  guard : CC.Stmt
  work : CC.Stmt
  capacityRead : CC.Stmt
  guardIf : CC.Stmt
  guardTest : CC.Expr
  firstPart : CC.Stmt
  finalIf : CC.Stmt
  firstRead : CC.Stmt
  firstIf : CC.Stmt
  firstTest : CC.Expr
  zero : CC.Stmt
  selected : CC.Stmt
  secondRead : CC.Stmt
  secondSet : CC.Stmt
  secondTest : CC.Expr

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original release tag scan changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(tags)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel root[1]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let guard ← peel body[0]! ``CC.Stmt.Ssequence 2
    let test ← peel guard[1]! ``CC.Stmt.Sifthenelse 3
    let work ← peel body[1]! ``CC.Stmt.Ssequence 2
    let first ← peel work[0]! ``CC.Stmt.Ssequence 2
    let firstIf ← peel first[1]! ``CC.Stmt.Sifthenelse 3
    let finalIf ← peel work[1]! ``CC.Stmt.Sifthenelse 3
    let second ← peel firstIf[1]! ``CC.Stmt.Ssequence 2
    let secondSet ← peel second[1]! ``CC.Stmt.Sset 2
    let secondCast ← peel secondSet[1]! ``CC.Expr.Ecast 2
    Lean.Elab.Tactic.closeMainGoal `actual_tag_scan_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,loop[0]!,loop[1]!,body[0]!,body[1]!,guard[0]!,guard[1]!,test[0]!,
        work[0]!,work[1]!,first[0]!,first[1]!,firstIf[0]!,firstIf[2]!,finalIf[1]!,second[0]!,second[1]!,secondCast[0]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_tag_scan_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def init : CC.Stmt := by run_tac cachePart (← `(parts.init))
def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def increment : CC.Stmt := by run_tac cachePart (← `(parts.increment))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
def work : CC.Stmt := by run_tac cachePart (← `(parts.work))
private def capacityRead : CC.Stmt := by run_tac cachePart (← `(parts.capacityRead))
private def guardIf : CC.Stmt := by run_tac cachePart (← `(parts.guardIf))
private def guardTest : CC.Expr := by run_tac cachePart (← `(parts.guardTest))
private def firstPart : CC.Stmt := by run_tac cachePart (← `(parts.firstPart))
private def finalIf : CC.Stmt := by run_tac cachePart (← `(parts.finalIf))
private def firstRead : CC.Stmt := by run_tac cachePart (← `(parts.firstRead))
private def firstIf : CC.Stmt := by run_tac cachePart (← `(parts.firstIf))
private def firstTest : CC.Expr := by run_tac cachePart (← `(parts.firstTest))
private def zero : CC.Stmt := by run_tac cachePart (← `(parts.zero))
def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))
private def secondRead : CC.Stmt := by run_tac cachePart (← `(parts.secondRead))
private def secondSet : CC.Stmt := by run_tac cachePart (← `(parts.secondSet))
private def secondTest : CC.Expr := by run_tac cachePart (← `(parts.secondTest))

private theorem source : tags = .Ssequence init loop := rfl
private theorem loop_source : loop = .Sloop body increment := rfl
private theorem body_source : body = .Ssequence guard work := rfl
private theorem guard_source : guard = .Ssequence capacityRead guardIf := rfl
private theorem guard_if_source : guardIf = .Sifthenelse guardTest .Sskip .Sbreak := rfl
private theorem work_source : work = .Ssequence firstPart finalIf := rfl
private theorem first_source : firstPart = .Ssequence firstRead firstIf := rfl
private theorem first_if_source : firstIf = .Sifthenelse firstTest Arm64Program.s_kprog_arm64_program_clobbers_0 zero := rfl
private theorem second_source : Arm64Program.s_kprog_arm64_program_clobbers_0 = .Ssequence secondRead secondSet := rfl
private theorem second_set_source : secondSet = .Sset Arm64Program._t'4 (.Ecast secondTest CC.tbool) := rfl
private theorem final_source : finalIf = .Sifthenelse (.Etempvar Arm64Program._t'4 CC.tint) selected .Sskip := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body increment k
def active (i : Fin 20) : Bool := decide (i.val < 8)
def index (i : Fin 20) : BitVec 32 := BitVec.ofNat 32 i.val
private def low (i : Fin 20) : BitVec 64 :=
  CC.Integers.Int64.repr (CC.Integers.Int.unsigned (index i * (8#32))) - (96#64)
private def high (i : Fin 20) : BitVec 64 :=
  CC.Integers.Int64.repr (CC.Integers.Int.unsigned (index i * (8#32) + (8#32))) - (96#64)
private def guardTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'234 (.Vint 160)
private def firstTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'232 (.Vlong 96)
private def choiceTemps (le : CC.TempEnv) (i : Fin 20) : CC.TempEnv :=
  if active i then (le.set Arm64Program._t'233 (.Vlong 96)).set Arm64Program._t'4 (.Vint 1)
  else le.set Arm64Program._t'4 (.Vint 0)
def temps (le : CC.TempEnv) (i : Fin 20) : CC.TempEnv := choiceTemps (firstTemps (guardTemps le)) i

theorem active_positions (i : Fin 20) : active i = true ↔ i.val < 8 := by simp only [active,decide_eq_true_eq]
private theorem index_less : ∀ i : Fin 20, (index i).ult (20#32) = true := by decide +kernel
private theorem first_data : ∀ i : Fin 20, CC.Integers.MI.lt (low i) (-32#64) = active i := by decide +kernel
private theorem second_data : ∀ i : Fin 20, CC.Integers.MI.lt (-96#64) (high i) = true := by decide +kernel

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
    CC.lvalOfField,layout.1,layout.2.1,CC.typeof,CC.tuint,CC.tattr,CC.typeconv,CC.removeAttributes,
    CC.doDerefLoc,CC.accessMode,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  have fieldOffset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 656).toNat) : Nat) : Int) = 656 := by decide +kernel
  rw [fieldOffset,capacity]

private theorem bias_step (second : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    CC.doStep world (.State helper (if second then secondRead else firstRead) k e le m) =
      some (CC.E0,.State helper .Sskip k e
        (le.set (if second then Arm64Program._t'233 else Arm64Program._t'232) (.Vlong 96)) m) := by
  cases second <;> simp only [firstRead,secondRead,Bool.false_eq_true,ite_false,ite_true,
    CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2.2,
    CC.typeof,CC.tlong,CC.tattr,CC.typeconv,CC.removeAttributes,CC.doDerefLoc,CC.accessMode,
    CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv]
  all_goals
    have fieldOffset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 672).toNat) : Nat) : Int) = 672 := by decide +kernel
    rw [fieldOffset,bias]

private theorem guard_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (n : BitVec 32)
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint n)) :
    CC.doEvalExpr world e (guardTemps le) m guardTest = some (CC.Val.ofBool (n.ult (20#32))) := by
  have hi : (guardTemps le).get Arm64Program.___a64_release_w = some (.Vint n) := by
    simpa +decide only [guardTemps,CC.PTree.gso] using counter
  simp only [guardTest,CC.doEvalExpr]
  rw [hi]
  simp +decide only [guardTemps,CC.PTree.gss,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,
    CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semDiv,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tuint,CC.tattr,CC.Archi.ptr64,
    CC.Integers.Int.add,CC.Integers.MI.add,CC.Integers.Int.divu,CC.Integers.MI.divu,
    CC.Integers.Int.eq,CC.Integers.MI.eq,CC.Integers.Int.zero,CC.Integers.MI.zero,
    CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.MI.ltu,
    CC.Integers.Int.repr,CC.Integers.MI.repr,ite_true,ite_false]
  rfl

theorem enter (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3 (.State helper tags k e le m)
      (.State helper loop k e (le.set Arm64Program.___a64_release_w (.Vint 0)) m) := by
  rw [source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

theorem guard_true (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 20)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (index i)))
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
  refine .step (mid := .State helper .Sskip (.Kseq work (continuation k)) e (guardTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep]
    rw [eval]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private theorem first_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 20)
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (index i)))
    (bias : le.get Arm64Program._t'232 = some (.Vlong 96))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64))) :
    CC.doEvalExpr world e le m firstTest = some (.Vint (if active i then 1 else 0)) := by
  simp only [firstTest,CC.doEvalExpr,counter,bias,new,CC.Cop.semBinaryOperation,
    CC.Cop.semMul,CC.Cop.semSub,CC.Cop.classifySub,CC.Cop.semCmp,CC.Cop.classifyCmp,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tuint,CC.tlong,CC.tattr,CC.Archi.ptr64,CC.Integers.Int.mul,CC.Integers.MI.mul,
    CC.Integers.Int64.sub,CC.Integers.MI.sub,CC.Integers.Int64.cmp,CC.Integers.MI.cmp,
    CC.Integers.Int.repr,CC.Integers.MI.repr,ite_true,ite_false]
  change some (CC.Val.ofBool (CC.Integers.MI.lt (low i) (-32#64))) = _
  rw [first_data]
  cases active i <;> rfl

private theorem second_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 20)
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (index i)))
    (bias : le.get Arm64Program._t'233 = some (.Vlong 96))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64))) :
    CC.doEvalExpr world e le m secondTest = some (.Vint 1) := by
  simp only [secondTest,CC.doEvalExpr,counter,bias,old,CC.Cop.semBinaryOperation,
    CC.Cop.semMul,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semSub,CC.Cop.classifySub,CC.Cop.semCmp,CC.Cop.classifyCmp,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.Cop.castIntInt,CC.Cop.castIntLong,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tuint,CC.tlong,CC.tattr,CC.Archi.ptr64,CC.Integers.Int.mul,CC.Integers.MI.mul,
    CC.Integers.Int.add,CC.Integers.MI.add,CC.Integers.Int64.sub,CC.Integers.MI.sub,
    CC.Integers.Int64.cmp,CC.Integers.MI.cmp,CC.Integers.Int.repr,CC.Integers.MI.repr,ite_true,ite_false]
  change some (CC.Val.ofBool (CC.Integers.MI.lt (-96#64) (high i))) = _
  rw [second_data]
  rfl

private theorem select_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (flag : Bool) :
    CC.doStep world (.State helper finalIf k e (le.set Arm64Program._t'4 (.Vint (if flag then 1 else 0))) m) =
      some (CC.E0,.State helper (if flag then selected else .Sskip) k e
        (le.set Arm64Program._t'4 (.Vint (if flag then 1 else 0))) m) := by
  rw [final_source]
  simp only [CC.doStep,CC.doEvalExpr,CC.PTree.gss]
  cases flag <;> rfl

private theorem first_run (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 20)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (index i)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64)))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 5 (.State helper work k e le m)
      (.State helper (if active i then Arm64Program.s_kprog_arm64_program_clobbers_0 else zero)
        (.Kseq finalIf k) e (firstTemps le) m) := by
  have hi : (firstTemps le).get Arm64Program.___a64_release_w = some (.Vint (index i)) := by
    simpa +decide only [firstTemps,CC.PTree.gso] using counter
  have hn : (firstTemps le).get Arm64Program.___a64_release_new = some (.Vlong (-32#64)) := by
    simpa +decide only [firstTemps,CC.PTree.gso] using new
  rw [work_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [first_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State helper .Sskip (.Kseq firstIf (.Kseq finalIf k)) e (firstTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simpa only [firstTemps,Bool.false_eq_true,ite_false] using bias_step false e le m _ entry hentry bias
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [first_if_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [CC.doStep]
  rw [first_eval e _ m i hi (CC.PTree.gss ..) hn]
  cases active i <;> rfl

private theorem second_run (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 20)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (index i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64)))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world 6
      (.State helper Arm64Program.s_kprog_arm64_program_clobbers_0 (.Kseq finalIf k) e le m)
      (.State helper selected k e ((le.set Arm64Program._t'233 (.Vlong 96)).set Arm64Program._t'4 (.Vint 1)) m) := by
  let le1 := le.set Arm64Program._t'233 (.Vlong 96)
  have hi : le1.get Arm64Program.___a64_release_w = some (.Vint (index i)) := by
    simpa +decide only [le1,CC.PTree.gso] using counter
  have ho : le1.get Arm64Program.___a64_release_old = some (.Vlong (-96#64)) := by
    simpa +decide only [le1,CC.PTree.gso] using old
  rw [second_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State helper .Sskip (.Kseq secondSet (.Kseq finalIf k)) e le1 m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simpa only [le1,ite_true] using bias_step true e le m _ entry hentry bias
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [second_set_source]
  refine .step (mid := .State helper .Sskip (.Kseq finalIf k) e (le1.set Arm64Program._t'4 (.Vint 1)) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep,CC.doEvalExpr]
    rw [second_eval e le1 m i hi (CC.PTree.gss ..) ho]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ (select_step e le1 m k true)) (.refl _)

theorem prepare (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 20)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (index i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64)))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world (if active i then 11 else 8) (.State helper work k e le m)
      (.State helper (if active i then selected else .Sskip) k e (choiceTemps (firstTemps le) i) m) := by
  have first := first_run e le m k entry i hentry counter new bias
  by_cases yes : active i = true
  · simp only [yes,ite_true] at first ⊢
    have last := second_run e (firstTemps le) m k entry i
      (by simpa +decide only [firstTemps,CC.PTree.gso] using hentry)
      (by simpa +decide only [firstTemps,CC.PTree.gso] using counter)
      (by simpa +decide only [firstTemps,CC.PTree.gso] using old) bias
    simpa only [choiceTemps,yes,ite_true] using first.trans last
  · have no : active i = false := Bool.eq_false_iff.mpr yes
    simp only [no,Bool.false_eq_true,ite_false] at first ⊢
    have last : InternalRun world 3 (.State helper zero (.Kseq finalIf k) e (firstTemps le) m)
        (.State helper .Sskip k e ((firstTemps le).set Arm64Program._t'4 (.Vint 0)) m) := by
      refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
      refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
      exact .step trivial (CC.doStep_sound _ _ _ _ (select_step e (firstTemps le) m k false)) (.refl _)
    simpa only [choiceTemps,no,Bool.false_eq_true,ite_false] using first.trans last

private theorem preserved (le : CC.TempEnv) (i : Fin 20) (id : CC.Ident)
    (n4 : Arm64Program._t'4 ≠ id) (n233 : Arm64Program._t'233 ≠ id)
    (n232 : Arm64Program._t'232 ≠ id) (n234 : Arm64Program._t'234 ≠ id) :
    (temps le i).get id = le.get id := by
  unfold temps choiceTemps
  split <;> simp only [firstTemps,guardTemps,CC.PTree.gso _ _ _ _ n4,
    CC.PTree.gso _ _ _ _ n233,CC.PTree.gso _ _ _ _ n232,CC.PTree.gso _ _ _ _ n234]

theorem observations (le : CC.TempEnv) (i : Fin 20) :
    (temps le i).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le i).get Arm64Program.___a64_release_w = le.get Arm64Program.___a64_release_w ∧
    (temps le i).get Arm64Program.___a64_release_old = le.get Arm64Program.___a64_release_old ∧
    (temps le i).get Arm64Program.___a64_release_new = le.get Arm64Program.___a64_release_new ∧
    (temps le i).get Arm64Program.___a64_release_i = le.get Arm64Program.___a64_release_i := by
  refine ⟨?_,?_,?_,?_,?_⟩ <;> apply preserved <;> decide +kernel

theorem setup (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 20)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (index i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64)))
    (capacity : CC.Mem.load .Mint32 m entry 656 = some (.Vint 160))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) :
    InternalRun world (if active i then 18 else 15) (.State helper loop k e le m)
      (.State helper (if active i then selected else .Sskip) (continuation k) e (temps le i) m) := by
  have first := guard_true e le m k entry i hentry counter capacity
  have last := prepare e (guardTemps le) m (continuation k) entry i
    (by simpa +decide only [guardTemps,CC.PTree.gso] using hentry)
    (by simpa +decide only [guardTemps,CC.PTree.gso] using counter)
    (by simpa +decide only [guardTemps,CC.PTree.gso] using old)
    (by simpa +decide only [guardTemps,CC.PTree.gso] using new) bias
  cases flag : active i <;> simpa only [flag,temps,Bool.false_eq_true,ite_false,ite_true] using first.trans last

theorem advance (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (n : BitVec 32)
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint n)) :
    InternalRun world 3 (.State helper .Sskip (continuation k) e le m)
      (.State helper loop k e (le.set Arm64Program.___a64_release_w (.Vint (n + (1#32)))) m) := by
  rw [loop_source]
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,continuation,increment,CC.doEvalExpr,counter,CC.typeof,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeconv,CC.removeAttributes,
    CC.tattr,CC.tint,CC.tuint,CC.Archi.ptr64,CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.add,CC.Integers.MI.add,
    CC.Eapp,CC.E0,List.nil_append,ite_true,ite_false]
  all_goals first | rfl | decide

theorem inactive (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 20)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint (index i)))
    (old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64)))
    (new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64)))
    (capacity : CC.Mem.load .Mint32 m entry 656 = some (.Vint 160))
    (bias : CC.Mem.load .Mint64 m entry 672 = some (.Vlong 96)) (inactive : active i = false) :
    InternalRun world 18 (.State helper loop k e le m)
      (.State helper loop k e ((temps le i).set Arm64Program.___a64_release_w (.Vint (index i + (1#32)))) m) := by
  have run := setup e le m k entry i hentry counter old new capacity bias
  simp only [inactive,Bool.false_eq_true,ite_false] at run
  exact run.trans (advance e (temps le i) m k (index i) ((observations le i).2.1.trans counter))

theorem finish (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_w = some (.Vint 20))
    (capacity : CC.Mem.load .Mint32 m entry 656 = some (.Vint 160)) :
    InternalRun world 8 (.State helper loop k e le m)
      (.State helper .Sskip k e (guardTemps le) m) := by
  have eval := guard_eval e le m (20#32) counter
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
  refine .step (mid := .State helper .Sbreak (.Kseq work (continuation k)) e (guardTemps le) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [CC.doStep]
    rw [eval]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

private def restTail : CC.Cont → CC.Cont := by
  run_tac do
    let result ← Lean.Meta.withLocalDeclD `savedContinuation (Lean.mkConst ``CC.Cont) fun k => do
      let term ← Lean.Meta.mkAppM ``Arm64MemsetReleaseComplete.tagCont #[k]
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Cont.Kloop1 3 do throwError "actual release outer loop changed"
      let tail ← Lean.Meta.withTransparency .all (Lean.Meta.whnf actual.getAppArgs[2]!)
      unless tail.isAppOfArity ``CC.Cont.Kseq 2 do throwError "actual clobber rest continuation changed"
      Lean.Meta.mkLambdaFVars #[k] tail.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_clobber_rest_cont result
def restCont (k : CC.Cont) : CC.Cont := restTail k

/-- Execute the genuine release do/while break and sequence exit. -/
theorem outer_exit (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3 (.State helper .Sskip (Arm64MemsetReleaseComplete.tagCont k) e le m)
      (.State helper Arm64MemsetClobberEntry.rest (restCont k) e le m) := by
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

end KProgFormal.ClightRefinement.Arm64MemsetReleaseTagLoop
