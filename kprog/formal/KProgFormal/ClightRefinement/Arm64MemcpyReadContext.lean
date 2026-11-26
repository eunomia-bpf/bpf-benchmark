import KProgFormal.ClightRefinement.Arm64MemcpyReadSelect

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadContext

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  guarded : CC.Stmt
  result : CC.Stmt
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
    let whole ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadSelect.afterSelect)) none) ``CC.Stmt.Ssequence 2
    let route ← peel whole[0]! ``CC.Stmt.Ssequence 2
    let branch ← peel route[1]! ``CC.Stmt.Sifthenelse 3
    let head ← peel route[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel head[1]! ``CC.Stmt.Ssequence 2
    let guard ← peel rest[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_xdp_read
      (← Lean.Meta.mkAppM ``Parts.mk #[whole[0]!,whole[1]!,route[0]!,branch[2]!,route[1]!,head[0]!,head[1]!,rest[0]!,rest[1]!,guard[0]!,guard[1]!,guard[2]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_xdp_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def guarded : CC.Stmt := by run_tac cachePart (← `(parts.guarded))
def result : CC.Stmt := by run_tac cachePart (← `(parts.result))
private def head : CC.Stmt := by run_tac cachePart (← `(parts.head))
def fallback : CC.Stmt := by run_tac cachePart (← `(parts.stack))
private def branch : CC.Stmt := by run_tac cachePart (← `(parts.branch))
private def root : CC.Stmt := by run_tac cachePart (← `(parts.root))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def byte : CC.Stmt := by run_tac cachePart (← `(parts.byte))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def condition : CC.Expr := by run_tac cachePart (← `(parts.condition))
private def yes : CC.Stmt := by run_tac cachePart (← `(parts.yes))
private def no : CC.Stmt := by run_tac cachePart (← `(parts.no))

theorem source : Arm64MemcpyReadSelect.afterSelect = .Ssequence guarded result := rfl
private theorem guarded_source : guarded = .Ssequence head branch := rfl
private theorem head_source : head = .Ssequence root rest := rfl
private theorem rest_source : rest = .Ssequence byte guard := rfl
private theorem guard_source : guard = .Sifthenelse condition yes no := rfl

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._is_xdp entryComposite.co_members = .OK (696,.Full) := by
  constructor <;> decide +kernel

private theorem root_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry flag : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 696 = some (.Vptr flag 0)) :
    CC.doStep world (.State reader root k e le m) =
      some (CC.E0,.State reader .Sskip k e (le.set Arm64Program._t'129 (.Vptr flag 0)) m) := by
  simp only [root,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 696).toNat) : Nat) : Int) = 696 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 696 = some (.Vptr flag 0) from read]

private theorem byte_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (flag : CC.Block) (kind : BitVec 8)
    (hptr : le.get Arm64Program._t'129 = some (.Vptr flag 0))
    (read : CC.Mem.load .Mint8unsigned m flag 0 = some (.Vint (kind.setWidth 32))) :
    CC.doStep world (.State reader byte k e le m) =
      some (CC.E0,.State reader .Sskip k e (le.set Arm64Program._t'130 (.Vint (kind.setWidth 32))) m) := by
  simp only [byte,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hptr,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tuchar,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint8unsigned m flag 0 with
    | some value => some (CC.E0,CC.State.State reader .Sskip k e (le.set Arm64Program._t'130 value) m)
    | none => none) = _
  rw [read]

private def readTemps (le : CC.TempEnv) (flag : CC.Block) (kind : BitVec 8) : CC.TempEnv :=
  (le.set Arm64Program._t'129 (.Vptr flag 0)).set Arm64Program._t'130 (.Vint (kind.setWidth 32))

def temps (le : CC.TempEnv) (flag : CC.Block) (kind : BitVec 8) : CC.TempEnv :=
  (readTemps le flag kind).set Arm64Program._t'63 (.Vint 0)

/-- These three actual setters retain every other caller temporary. -/
theorem kept (le : CC.TempEnv) (flag : CC.Block) (kind : BitVec 8) (key : CC.Ident)
    (conditionOther : Arm64Program._t'63 ≠ key)
    (byteOther : Arm64Program._t'130 ≠ key)
    (pointerOther : Arm64Program._t'129 ≠ key) :
    (temps le flag kind).get key = le.get key := by
  simp only [temps,readTemps,CC.PTree.gso _ _ _ _ conditionOther,
    CC.PTree.gso _ _ _ _ byteOther,CC.PTree.gso _ _ _ _ pointerOther]

private theorem read_prefix (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry flag : CC.Block) (kind : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (header : CC.Mem.load CC.Mptr m entry 696 = some (.Vptr flag 0))
    (value : CC.Mem.load .Mint8unsigned m flag 0 = some (.Vint (kind.setWidth 32))) :
    InternalRun world 8 (.State reader Arm64MemcpyReadSelect.afterSelect k e le m)
      (.State reader guard (.Kseq branch (.Kseq result k)) e (readTemps le flag kind) m) := by
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [guarded_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [head_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (root_step e le m (.Kseq rest (.Kseq branch (.Kseq result k))) entry flag hentry header)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [rest_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq guard (.Kseq branch (.Kseq result k))) e (readTemps le flag kind) m)
    trivial (CC.doStep_sound _ _ _ _ (byte_step e (le.set Arm64Program._t'129 (.Vptr flag 0)) m
      (.Kseq guard (.Kseq branch (.Kseq result k))) flag kind (by simp only [CC.PTree.gss]) value)) ?_
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

/-- Both original is_xdp alternatives execute their real assignment. Tag4
makes the original tag==1 conjunct false for every actually loaded flag byte. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry flag : CC.Block) (kind : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (tagged : le.get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32)))
    (header : CC.Mem.load CC.Mptr m entry 696 = some (.Vptr flag 0))
    (value : CC.Mem.load .Mint8unsigned m flag 0 = some (.Vint (kind.setWidth 32))) :
    InternalRun world 12 (.State reader Arm64MemcpyReadSelect.afterSelect k e le m)
      (.State reader fallback (.Kseq result k) e (temps le flag kind) m) := by
  have carried : (readTemps le flag kind).get Arm64Program.___a64_memory_tag = some (.Vint ((4#8).setWidth 32)) := by
    have byteOther : Arm64Program._t'130 ≠ Arm64Program.___a64_memory_tag := by decide +kernel
    have rootOther : Arm64Program._t'129 ≠ Arm64Program.___a64_memory_tag := by decide +kernel
    simpa only [readTemps,CC.PTree.gso _ _ _ _ byteOther,CC.PTree.gso _ _ _ _ rootOther] using tagged
  have finish : InternalRun world 4
      (.State reader guard (.Kseq branch (.Kseq result k)) e (readTemps le flag kind) m)
      (.State reader fallback (.Kseq result k) e (temps le flag kind) m) := by
    rw [guard_source]
    let selected := if kind.setWidth 32 == (0#32) then no else yes
    have safe : InternalState (.State reader selected (.Kseq branch (.Kseq result k)) e (readTemps le flag kind) m) := by
      unfold selected
      cases h : kind.setWidth 32 == (0#32) <;>
        simp only [h,Bool.false_eq_true,ite_false,ite_true,yes,no,InternalState]
      all_goals trivial
    refine .step (mid := .State reader selected (.Kseq branch (.Kseq result k)) e (readTemps le flag kind) m)
      trivial (CC.doStep_sound _ _ _ _ ?_) ?_
    · simp only [condition,CC.doStep,CC.doEvalExpr,readTemps,CC.PTree.gss,CC.typeof,
        CC.Cop.boolVal,CC.Cop.classifyBool,CC.tuchar,CC.Integers.Int.eq,CC.Integers.MI.eq,
        CC.Integers.Int.zero,CC.Integers.MI.zero]
      cases h : kind.setWidth 32 == (0#32) <;>
        simp only [selected,h,Bool.false_eq_true,ite_false,ite_true]
      all_goals rfl
    refine .step (mid := .State reader .Sskip (.Kseq branch (.Kseq result k)) e (temps le flag kind) m)
      safe (CC.doStep_sound _ _ _ _ ?_) ?_
    · unfold selected
      cases h : kind.setWidth 32 == (0#32)
      · simp only [h,Bool.false_eq_true,ite_false,yes,CC.doStep,CC.doEvalExpr,carried]
        rfl
      · simp only [h,ite_true,no,CC.doStep,CC.doEvalExpr]
        rfl
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
    simp only [branch,CC.doStep,CC.doEvalExpr,temps,CC.PTree.gss]
    rfl
  exact (read_prefix e le m k entry flag kind hentry header value).trans finish

end KProgFormal.ClightRefinement.Arm64MemcpyReadContext
