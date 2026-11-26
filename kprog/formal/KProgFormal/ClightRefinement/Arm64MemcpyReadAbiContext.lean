import KProgFormal.ClightRefinement.Arm64MemcpyReadContext

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadAbiContext

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  head : CC.Stmt
  stack : CC.Stmt
  branch : CC.Stmt
  root : CC.Stmt
  rest : CC.Stmt
  byte : CC.Stmt
  guard : CC.Stmt
  condition : CC.Expr
  yes : CC.Stmt
  no : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do
        throwError "original memcpy ABI source changed"
      pure actual.getAppArgs
    let route ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadContext.fallback)) none) ``CC.Stmt.Ssequence 2
    let branch ← peel route[1]! ``CC.Stmt.Sifthenelse 3
    let head ← peel route[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel head[1]! ``CC.Stmt.Ssequence 2
    let guard ← peel rest[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_abi_read
      (← Lean.Meta.mkAppM ``Parts.mk #[route[0]!,branch[2]!,route[1]!,head[0]!,head[1]!,rest[0]!,rest[1]!,guard[0]!,guard[1]!,guard[2]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_abi_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def head : CC.Stmt := by run_tac cachePart (← `(parts.head))
def stack : CC.Stmt := by run_tac cachePart (← `(parts.stack))
private def branch : CC.Stmt := by run_tac cachePart (← `(parts.branch))
private def root : CC.Stmt := by run_tac cachePart (← `(parts.root))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def byte : CC.Stmt := by run_tac cachePart (← `(parts.byte))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def condition : CC.Expr := by run_tac cachePart (← `(parts.condition))
private def yes : CC.Stmt := by run_tac cachePart (← `(parts.yes))
private def no : CC.Stmt := by run_tac cachePart (← `(parts.no))

theorem source : Arm64MemcpyReadContext.fallback = .Ssequence head branch := rfl
private theorem head_source : head = .Ssequence root rest := rfl
private theorem rest_source : rest = .Ssequence byte guard := rfl
private theorem guard_source : guard = .Sifthenelse condition yes no := rfl

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._abi_kind entryComposite.co_members = .OK (704,.Full) := by
  constructor <;> decide +kernel

private theorem root_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry abi : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 704 = some (.Vptr abi 0)) :
    CC.doStep world (.State reader root k e le m) =
      some (CC.E0,.State reader .Sskip k e (le.set Arm64Program._t'116 (.Vptr abi 0)) m) := by
  simp only [root,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 704).toNat) : Nat) : Int) = 704 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 704 = some (.Vptr abi 0) from read]

private theorem byte_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (abi : CC.Block) (kind : BitVec 8)
    (hptr : le.get Arm64Program._t'116 = some (.Vptr abi 0))
    (read : CC.Mem.load .Mint8unsigned m abi 0 = some (.Vint (kind.setWidth 32))) :
    CC.doStep world (.State reader byte k e le m) =
      some (CC.E0,.State reader .Sskip k e (le.set Arm64Program._t'117 (.Vint (kind.setWidth 32))) m) := by
  simp only [byte,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hptr,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tuchar,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint8unsigned m abi 0 with
    | some value => some (CC.E0,CC.State.State reader .Sskip k e (le.set Arm64Program._t'117 value) m)
    | none => none) = _
  rw [read]

private def readTemps (le : CC.TempEnv) (abi : CC.Block) (kind : BitVec 8) : CC.TempEnv :=
  (le.set Arm64Program._t'116 (.Vptr abi 0)).set Arm64Program._t'117 (.Vint (kind.setWidth 32))

def temps (le : CC.TempEnv) (abi : CC.Block) (kind : BitVec 8) : CC.TempEnv :=
  (readTemps le abi kind).set Arm64Program._t'62 (.Vint 0)

/-- These three actual setters retain every other caller temporary. -/
theorem kept (le : CC.TempEnv) (abi : CC.Block) (kind : BitVec 8) (key : CC.Ident)
    (conditionOther : Arm64Program._t'62 ≠ key)
    (byteOther : Arm64Program._t'117 ≠ key)
    (pointerOther : Arm64Program._t'116 ≠ key) :
    (temps le abi kind).get key = le.get key := by
  simp only [temps,readTemps,CC.PTree.gso _ _ _ _ conditionOther,
    CC.PTree.gso _ _ _ _ byteOther,CC.PTree.gso _ _ _ _ pointerOther]

private theorem read_prefix (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry abi : CC.Block) (kind : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (header : CC.Mem.load CC.Mptr m entry 704 = some (.Vptr abi 0))
    (value : CC.Mem.load .Mint8unsigned m abi 0 = some (.Vint (kind.setWidth 32))) :
    InternalRun world 7 (.State reader Arm64MemcpyReadContext.fallback k e le m)
      (.State reader guard (.Kseq branch k) e (readTemps le abi kind) m) := by
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [head_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (root_step e le m (.Kseq rest (.Kseq branch k)) entry abi hentry header)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [rest_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq guard (.Kseq branch k)) e (readTemps le abi kind) m)
    trivial (CC.doStep_sound _ _ _ _ (byte_step e (le.set Arm64Program._t'116 (.Vptr abi 0)) m
      (.Kseq guard (.Kseq branch k)) abi kind (by simp only [CC.PTree.gss]) value)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private theorem condition_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (abi : CC.Block) (kind : BitVec 8) :
    CC.doEvalExpr world e (readTemps le abi kind) m condition =
      some (CC.Val.ofBool (kind.setWidth 32 == (1#32))) := by
  simp only [condition,CC.doEvalExpr,readTemps,CC.PTree.gss,CC.Cop.semBinaryOperation,
    CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tuchar,CC.tuint,CC.tint,CC.Archi.ptr64,ite_true,ite_false,
    CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.eq,CC.Integers.MI.eq,
    CC.Integers.Int.repr,CC.Integers.MI.repr]
  rfl

/-- Execute the genuine ABI pointer and byte reads, both real ABI alternatives
and the original false context guard into the stack arm, for every ABI byte. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry abi : CC.Block) (kind : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (tagged : le.get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32)))
    (header : CC.Mem.load CC.Mptr m entry 704 = some (.Vptr abi 0))
    (value : CC.Mem.load .Mint8unsigned m abi 0 = some (.Vint (kind.setWidth 32))) :
    InternalRun world 11 (.State reader Arm64MemcpyReadContext.fallback k e le m)
      (.State reader stack k e (temps le abi kind) m) := by
  have carried : (readTemps le abi kind).get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32)) := by
    have byteOther : Arm64Program._t'117 ≠ Arm64Program.___a64_memory_tag := by decide +kernel
    have rootOther : Arm64Program._t'116 ≠ Arm64Program.___a64_memory_tag := by decide +kernel
    simpa only [readTemps,CC.PTree.gso _ _ _ _ byteOther,CC.PTree.gso _ _ _ _ rootOther] using tagged
  have finish : InternalRun world 4 (.State reader guard (.Kseq branch k) e (readTemps le abi kind) m)
      (.State reader stack k e (temps le abi kind) m) := by
    rw [guard_source]
    let selected := if kind.setWidth 32 == (1#32) then yes else no
    have safe : InternalState (.State reader selected (.Kseq branch k) e (readTemps le abi kind) m) := by
      unfold selected
      cases h : kind.setWidth 32 == (1#32) <;>
        simp only [h,Bool.false_eq_true,ite_false,ite_true,yes,no,InternalState]
      all_goals trivial
    refine .step (mid := .State reader selected (.Kseq branch k) e (readTemps le abi kind) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · have ty : CC.typeof condition = CC.tint := rfl
      simp only [CC.doStep,condition_eval,ty]
      cases h : kind.setWidth 32 == (1#32) <;>
        simp only [selected,h,Bool.false_eq_true,ite_false,ite_true]
      all_goals rfl
    refine .step (mid := .State reader .Sskip (.Kseq branch k) e (temps le abi kind) m)
      safe (CC.doStep_sound _ _ _ _ ?_) ?_
    · unfold selected
      cases h : kind.setWidth 32 == (1#32)
      · simp only [h,Bool.false_eq_true,ite_false]
        rfl
      · simp only [h,ite_true,yes,CC.doStep,CC.doEvalExpr,carried]
        rfl
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
    simp only [branch,CC.doStep,CC.doEvalExpr,temps,CC.PTree.gss]
    rfl
  exact (read_prefix e le m k entry abi kind hentry header value).trans finish


end KProgFormal.ClightRefinement.Arm64MemcpyReadAbiContext
