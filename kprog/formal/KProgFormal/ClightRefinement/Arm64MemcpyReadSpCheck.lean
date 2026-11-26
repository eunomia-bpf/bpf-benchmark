import KProgFormal.ClightRefinement.Arm64MemcpyReadObserve

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadSpCheck

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  head : CC.Stmt
  result : CC.Stmt
  root : CC.Stmt
  rest : CC.Stmt
  read : CC.Stmt
  guard : CC.Stmt
  condition : CC.Expr

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original reader post-read SP source changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyReadIndex.postRead)) none) ``CC.Stmt.Ssequence 2
    let head ← peel root[0]! ``CC.Stmt.Ssequence 2
    let rest ← peel head[1]! ``CC.Stmt.Ssequence 2
    let guard ← peel rest[1]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_reader_post_read_sp
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,head[0]!,head[1]!,rest[0]!,rest[1]!,guard[0]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_reader_post_read_sp_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def head : CC.Stmt := by run_tac cachePart (← `(parts.head))
private def result : CC.Stmt := by run_tac cachePart (← `(parts.result))
private def root : CC.Stmt := by run_tac cachePart (← `(parts.root))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def read : CC.Stmt := by run_tac cachePart (← `(parts.read))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def condition : CC.Expr := by run_tac cachePart (← `(parts.condition))

theorem source : Arm64MemcpyReadIndex.postRead = .Ssequence head result ∧
    head = .Ssequence root rest ∧ rest = .Ssequence read guard ∧
    result = .Sset Arm64Program.___a64_mrd_value (.Etempvar Arm64Program.___a64_observed CC.tulong) := ⟨rfl,rfl,rfl,rfl⟩

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40,.Full) := by
  constructor <;> decide +kernel

private def pointerTemps (le : CC.TempEnv) (sp : CC.Block) : CC.TempEnv := le.set Arm64Program._t'82 (.Vptr sp 0)
private def readTemps (le : CC.TempEnv) (sp : CC.Block) : CC.TempEnv := (pointerTemps le sp).set Arm64Program._t'83 (.Vlong (-32#64))
def temps (le : CC.TempEnv) (sp : CC.Block) (value : BitVec 64) : CC.TempEnv :=
  (readTemps le sp).set Arm64Program.___a64_mrd_value (.Vlong value)

private theorem root_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry sp : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (observed : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0)) :
    CC.doStep world (.State reader root k e le m) =
      some (CC.E0,.State reader .Sskip k e (pointerTemps le sp) m) := by
  simp only [root,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,pointerTemps,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 40).toNat) : Nat) : Int) = 40 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 40 = some (.Vptr sp 0) from observed]

private theorem read_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sp : CC.Block)
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    CC.doStep world (.State reader read k e (pointerTemps le sp) m) =
      some (CC.E0,.State reader .Sskip k e (readTemps le sp) m) := by
  simp only [read,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,pointerTemps,CC.PTree.gss,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tlong,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint64 m sp 0 with
    | some value => some (CC.E0,CC.State.State reader .Sskip k e ((pointerTemps le sp).set Arm64Program._t'83 value) m)
    | none => none) = _
  rw [observed]
  rfl

private theorem below_sp_false : ∀ i : Fin 16,
    CC.Integers.Int64.cmp .Clt ((-32#64)+BitVec.ofNat 64 i.val) (-32#64) = false := by decide +kernel

private theorem condition_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (i : Fin 16)
    (base : le.get Arm64Program.___a64_mrd_base = some (.Vlong (-32#64)))
    (off : le.get Arm64Program.___a64_memory_off = some (.Vlong (BitVec.ofNat 64 i.val)))
    (sp : le.get Arm64Program._t'83 = some (.Vlong (-32#64))) :
    CC.doEvalExpr world e le m condition = some (.Vint 0) := by
  simp only [condition,CC.doEvalExpr,base,off,sp,CC.Cop.semBinaryOperation,
    CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
    CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tlong,CC.tint,CC.Archi.ptr64,
    CC.Integers.Int64.add,CC.Integers.MI.add,ite_true,ite_false,below_sp_false i]
  rfl

/-- The current base=-32, actual offset0..15 and actual SP=-32 take the
original false guard. Its original kind6 provider arm remains in the source. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry sp : CC.Block) (i : Fin 16) (value : BitVec 64)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (header : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0))
    (spRead : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64)))
    (base : le.get Arm64Program.___a64_mrd_base = some (.Vlong (-32#64)))
    (off : le.get Arm64Program.___a64_memory_off = some (.Vlong (BitVec.ofNat 64 i.val)))
    (loaded : le.get Arm64Program.___a64_observed = some (.Vlong value)) :
    InternalRun world 10 (.State reader Arm64MemcpyReadIndex.postRead k e le m)
      (.State reader .Sskip k e (temps le sp value) m) := by
  have kept (key : CC.Ident) (wordOther : Arm64Program._t'83 ≠ key)
      (pointerOther : Arm64Program._t'82 ≠ key) : (readTemps le sp).get key = le.get key := by
    simp only [readTemps,pointerTemps,CC.PTree.gso _ _ _ _ wordOther,CC.PTree.gso _ _ _ _ pointerOther]
  have actualBase := (kept _ (by decide +kernel) (by decide +kernel)).trans base
  have actualOff := (kept _ (by decide +kernel) (by decide +kernel)).trans off
  have actualLoaded := (kept _ (by decide +kernel) (by decide +kernel)).trans loaded
  rw [source.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (root_step e le m _ entry sp hentry header)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (read_step e le m _ sp spRead)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State reader .Sskip (.Kseq result k) e (readTemps le sp) m)
    trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · have selected := condition_eval e (readTemps le sp) m i actualBase actualOff (CC.PTree.gss _ _ _)
    simp only [condition] at selected
    simp only [guard,CC.doStep,selected]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2.2]
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [CC.doStep,CC.doEvalExpr,actualLoaded,temps]

theorem kept (le : CC.TempEnv) (sp : CC.Block) (value : BitVec 64) (key : CC.Ident)
    (resultOther : Arm64Program.___a64_mrd_value ≠ key)
    (wordOther : Arm64Program._t'83 ≠ key) (pointerOther : Arm64Program._t'82 ≠ key) :
    (temps le sp value).get key = le.get key := by
  simp only [temps,readTemps,pointerTemps,CC.PTree.gso _ _ _ _ resultOther,
    CC.PTree.gso _ _ _ _ wordOther,CC.PTree.gso _ _ _ _ pointerOther]

end KProgFormal.ClightRefinement.Arm64MemcpyReadSpCheck
