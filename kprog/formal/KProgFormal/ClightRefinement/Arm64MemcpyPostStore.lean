import KProgFormal.ClightRefinement.Arm64MemcpyStoreIndex
import KProgFormal.ClightRefinement.Arm64MemcpyReadCaller

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyPostStore

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  root : CC.Stmt
  rest : CC.Stmt
  read : CC.Stmt
  guard : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memcpy post-store source changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpyStoreIndex.post)) none)
    let rest ← peel root[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_post_store
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,rest[0]!,rest[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_post_store_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def root : CC.Stmt := by run_tac cachePart (← `(parts.root))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def read : CC.Stmt := by run_tac cachePart (← `(parts.read))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
theorem source : Arm64MemcpyStoreIndex.post = .Ssequence root rest ∧ rest = .Ssequence read guard := ⟨rfl,rfl⟩
def temps (le : CC.TempEnv) (sp : CC.Block) : CC.TempEnv :=
  (le.set Arm64Program._t'105 (.Vptr sp 0)).set Arm64Program._t'106 (.Vlong (-32#64))
private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40,.Full) := by
  constructor <;> decide +kernel
private theorem root_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry sp : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0)) :
    CC.doStep world (.State handler root k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'105 (.Vptr sp 0)) m) := by
  simp only [root,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.typeconv,CC.removeAttributes,CC.tattr,CC.doDerefLoc,CC.accessMode,
    CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs)+CC.Integers.Ptrofs.repr 40).toNat) : Nat) : Int) = 40 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 40 = some (.Vptr sp 0) from pointer]
private theorem read_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (sp : CC.Block)
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    CC.doStep world (.State handler read k e (le.set Arm64Program._t'105 (.Vptr sp 0)) m) =
      some (CC.E0,.State handler .Sskip k e (temps le sp) m) := by
  simp only [read,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.PTree.gss,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tlong,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,temps]
  change (match CC.Mem.load .Mint64 m sp 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e
        ((le.set Arm64Program._t'105 (CC.Val.Vptr sp 0)).set Arm64Program._t'106 value) m)
    | none => none) = _
  rw [observed]
private theorem above_sp : ∀ i : Fin 16,
    CC.Integers.MI.lt ((-16#64)+BitVec.ofNat 64 i.val) (-32#64) = false := by decide +kernel

/-- Actual header40 and SP reads supply the original signed comparison.
All16 destination offsets take the real false loss guard on SP=-32. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry sp : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0))
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    InternalRun world 7 (.State handler Arm64MemcpyStoreIndex.post k e le m)
      (.State handler .Sskip k e (temps le sp) m) := by
  rw [source.1,source.2]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (root_step e le m _ entry sp hentry pointer)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (read_step e le m _ sp observed)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  have compare := above_sp i
  have minus16 : (-16#64) = (18446744073709551600#64) := by decide +kernel
  have minus32 : (-32#64) = (18446744073709551584#64) := by decide +kernel
  rw [minus16,minus32] at compare
  simp +decide [guard,temps,CC.doStep,CC.doEvalExpr,CC.PTree.gss,CC.PTree.gso,hoff,
    CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,
    CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
    CC.Cop.boolVal,CC.Cop.classifyBool,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.typeof,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tlong,CC.tint,CC.Archi.ptr64,
    CC.Integers.Int64.cmp,CC.Integers.MI.cmp,compare,CC.E0,CC.Eapp]
  all_goals rfl

/-- Genuine inner-store exits and all three original loss/write wrappers
restore the saved body continuation after the actual false SP guard. -/
theorem after_write (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry sp : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0))
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong (-32#64))) :
    InternalRun world 16
      (.State handler .Sskip (Arm64MemcpyStoreIndex.continuation (Arm64MemcpyReadCaller.continuation k)) e le m)
      (.State handler .Sskip k e (temps le sp) m) := by
  have leaveStore : InternalRun world 3
      (.State handler .Sskip (Arm64MemcpyStoreIndex.continuation (Arm64MemcpyReadCaller.continuation k)) e le m)
      (.State handler Arm64MemcpyStoreIndex.post (Arm64MemcpyReadCaller.continuation k) e le m) := by
    apply internalRun_of_steps
    · simp [InternalPath,InternalState,steps,CC.doStep,Arm64MemcpyStoreIndex.continuation]
    · rfl
  have wrappers : InternalRun world 6
      (.State handler .Sskip (Arm64MemcpyReadCaller.continuation k) e (temps le sp) m)
      (.State handler .Sskip k e (temps le sp) m) := by
    apply internalRun_of_steps
    · simp [InternalPath,InternalState,steps,CC.doStep,Arm64MemcpyReadCaller.continuation,
        Arm64MemcpyDestinationTag.continuation,Arm64MemcpyStackSetup.continuation]
    · rfl
  exact (leaveStore.trans (execute e le m (Arm64MemcpyReadCaller.continuation k) entry sp i hentry hoff pointer observed)).trans wrappers

theorem kept (le : CC.TempEnv) (sp : CC.Block) (id : CC.Ident)
    (readOther : Arm64Program._t'106 ≠ id) (pointerOther : Arm64Program._t'105 ≠ id) :
    (temps le sp).get id = le.get id := by
  simp only [temps,CC.PTree.gso _ _ _ _ readOther,CC.PTree.gso _ _ _ _ pointerOther]

end KProgFormal.ClightRefinement.Arm64MemcpyPostStore
