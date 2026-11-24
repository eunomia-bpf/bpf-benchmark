import KProgFormal.ClightRefinement.Arm64MemsetStoreExecution

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetStoreBackedge

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
  lossBody : CC.Stmt
  root : CC.Stmt
  rest : CC.Stmt
  read : CC.Stmt
  guard : CC.Stmt
  selected : CC.Stmt
  init : CC.Stmt
  loop : CC.Stmt
  body : CC.Stmt
  increment : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memset post-store control changed"
      pure actual.getAppArgs
    let loss ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetPointerRoute.loss)) none) ``CC.Stmt.Sloop 2
    let store ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetLossSetup.afterStore)) none) ``CC.Stmt.Ssequence 2
    let rest ← peel store[1]! ``CC.Stmt.Ssequence 2
    let guard ← peel rest[1]! ``CC.Stmt.Sifthenelse 3
    let selected ← peel guard[1]! ``CC.Stmt.Ssequence 2
    let loop ← peel selected[1]! ``CC.Stmt.Sloop 2
    Lean.Elab.Tactic.closeMainGoal `actual_memset_post_store
      (← Lean.Meta.mkAppM ``Parts.mk #[loss[0]!,store[0]!,store[1]!,rest[0]!,rest[1]!,guard[1]!,selected[0]!,selected[1]!,loop[0]!,loop[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_post_store_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def lossBody : CC.Stmt := by run_tac cachePart (← `(parts.lossBody))
private def root : CC.Stmt := by run_tac cachePart (← `(parts.root))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def read : CC.Stmt := by run_tac cachePart (← `(parts.read))
private def guard : CC.Stmt := by run_tac cachePart (← `(parts.guard))
private def selected : CC.Stmt := by run_tac cachePart (← `(parts.selected))
private def init : CC.Stmt := by run_tac cachePart (← `(parts.init))
private def loop : CC.Stmt := by run_tac cachePart (← `(parts.loop))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def increment : CC.Stmt := by run_tac cachePart (← `(parts.increment))

private theorem store_source : Arm64MemsetLossSetup.afterStore = .Ssequence root rest := rfl
private theorem rest_source : rest = .Ssequence read guard := rfl
private theorem selected_source : selected = .Ssequence init loop := rfl
private theorem loop_source : loop = .Sloop body increment := rfl
private theorem body_source : body = .Ssequence Arm64Program.s_kprog_arm64_program_memset_78
  Arm64Program.s_kprog_arm64_program_memset_101 := rfl

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body increment (.Kloop1 lossBody .Sbreak k)
def temps (le : CC.TempEnv) (sp : CC.Block) : CC.TempEnv :=
  (((le.set Arm64Program._t'98 (.Vptr sp 0)).set Arm64Program._t'99 (.Vlong 0)).set
    Arm64Program.___a64_loss_i (.Vint 0))

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40,.Full) := by
  constructor <;> decide +kernel

/-- Exit the actual inner store do/while and retain the real post-store SP
and loss-tag work as the continuation. -/
theorem store_exit (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3
      (.State handler .Sskip (Arm64MemsetStoreRoute.continuation (Arm64MemsetLossSetup.continuation k)) e le m)
      (.State handler Arm64MemsetLossSetup.afterStore (.Kloop1 lossBody .Sbreak k) e le m) := by
  apply internalRun_of_steps
  · simp [InternalPath,InternalState,steps,CC.doStep,Arm64MemsetStoreRoute.continuation,Arm64MemsetLossSetup.continuation]
  · rfl

private theorem root_step (m : CC.Mem) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (entry sp : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0)) :
    CC.doStep world (.State handler root k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'98 (.Vptr sp 0)) m) := by
  simp only [root,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.typeconv,CC.removeAttributes,CC.tattr,CC.doDerefLoc,CC.accessMode,
    CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 40).toNat) : Nat) : Int) = 40 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 40 = some (.Vptr sp 0) from pointer]

private theorem read_step (m : CC.Mem) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (sp : CC.Block) (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong 0)) :
    CC.doStep world (.State handler read k e (le.set Arm64Program._t'98 (.Vptr sp 0)) m) =
      some (CC.E0,.State handler .Sskip k e
        ((le.set Arm64Program._t'98 (.Vptr sp 0)).set Arm64Program._t'99 (.Vlong 0)) m) := by
  simp only [read,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.PTree.gss,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tlong,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint64 m sp 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e
        ((le.set Arm64Program._t'98 (CC.Val.Vptr sp 0)).set Arm64Program._t'99 value) m)
    | none => none) = _
  rw [observed]

private theorem negative : ∀ i : Fin 16,
    CC.Integers.MI.lt (Arm64MemsetStoreRoute.lossOffset i) 0 = true := by decide +kernel

private theorem select_loss (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 16)
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)))
    (hsp : le.get Arm64Program._t'99 = some (.Vlong 0)) :
    InternalRun world 8 (.State handler guard (.Kloop1 lossBody .Sbreak k) e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_101 (continuation k) e
        (le.set Arm64Program.___a64_loss_i (.Vint 0)) m) := by
  have neg : CC.Integers.MI.lt (Arm64MemsetStoreRoute.lossOffset i) (0#64) = true := negative i
  apply internalRun_of_steps
  all_goals simp +decide [InternalPath,InternalState,steps,guard,selected_source,loop_source,body_source,init,increment,
    Arm64Program.s_kprog_arm64_program_memset_78,continuation,CC.doStep,CC.doEvalExpr,hoff,hsp,
    CC.PTree.gss,CC.PTree.gso,CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,
    CC.Cop.semBinarith,CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.boolVal,CC.Cop.classifyBool,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tlong,CC.tulong,CC.tuchar,CC.tuint,CC.tint,CC.tattr,CC.Archi.ptr64,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
    neg,negative,CC.Integers.Int64.cmp,CC.Integers.MI.cmp,CC.Integers.Int64.signed,CC.Integers.MI.signed,
    CC.Integers.Int.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.one,CC.Integers.Int.zero,CC.Integers.MI.one,CC.Integers.MI.zero,CC.Integers.Int.eq,CC.Integers.MI.eq,CC.E0,CC.Eapp]

/-- All16 real negative loss offsets take the genuine post-store tag loop.
The header and cell loads are actual current-memory observations; both inner
loop exits, source index initialization and gate78 execute on that same heap. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry sp : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)))
    (pointer : CC.Mem.load CC.Mptr m entry 40 = some (.Vptr sp 0))
    (observed : CC.Mem.load .Mint64 m sp 0 = some (.Vlong 0)) :
    InternalRun world 17
      (.State handler .Sskip (Arm64MemsetStoreRoute.continuation (Arm64MemsetLossSetup.continuation k)) e le m)
      (.State handler Arm64Program.s_kprog_arm64_program_memset_101 (continuation k) e (temps le sp) m) := by
  have spRun : InternalRun world 6
      (.State handler Arm64MemsetLossSetup.afterStore (.Kloop1 lossBody .Sbreak k) e le m)
      (.State handler guard (.Kloop1 lossBody .Sbreak k) e
        ((le.set Arm64Program._t'98 (.Vptr sp 0)).set Arm64Program._t'99 (.Vlong 0)) m) := by
    rw [store_source,rest_source]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (root_step m e le _ entry sp hentry pointer)) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (read_step m e le _ sp observed)) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have off : (((le.set Arm64Program._t'98 (.Vptr sp 0)).set Arm64Program._t'99 (.Vlong 0))).get
      Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)) := by
    simpa +decide only [CC.PTree.gso] using hoff
  exact ((store_exit e le m k).trans spRun).trans
    (select_loss e _ m k i off (CC.PTree.gss ..))

/-- The exact input observations survive every real store-route/tag/byte
setter, so the post-store branch consumes the same invocation's temporaries. -/
theorem stored_inputs {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (le : CC.TempEnv) (i : Fin 16) (byte : BitVec 8) :
    (Arm64MemsetStoreExecution.temps view le i byte).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (Arm64MemsetStoreExecution.temps view le i byte).get Arm64Program.___a64_loss_off = le.get Arm64Program.___a64_loss_off := by
  have saved := Arm64MemsetStackWrite.temps_inputs (Arm64MemsetStoreRoute.temps le i byte)
    (Arm64MemsetStoreExecution.index i) view.tags.block view.stack.block 0 byte
  have route := Arm64MemsetStoreRoute.temps_inputs le i byte
  exact ⟨saved.1.trans route.1,saved.2.trans route.2⟩

/-- Construct both actual stores and then execute the original17-transition
post-store SP/negative-offset/tag-loop route, retaining all effects and frame.
The current SP value is identified explicitly; original-entry linkage derives
this equality from its own represented native SP. -/
theorem with_stores {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (spZero : storage.spValue = 0)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (byte : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0)) :
    ∃ tagged after,
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetLossSetup.store (Arm64MemsetLossSetup.continuation k) e le m) CC.E0
        (.State handler Arm64Program.s_kprog_arm64_program_memset_101 (continuation k) e
          (temps (Arm64MemsetStoreExecution.temps view le i byte) storage.sp.block) after) ∧
      CC.Mem.store .Mint64 m view.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged view.stack.block ((Arm64MemsetStoreExecution.index i).val : Int)
        (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after view.stack.block ((Arm64MemsetStoreExecution.index i).val : Int) = some (.Vint (byte.setWidth 32)) ∧
      CC.Mem.load .Mint64 after view.tags.block 8 = some (.Vlong 0) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block → block ≠ view.stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) ∧
      Nonempty (Arm64MemsetHeaderView.View initial after entry) := by
  obtain ⟨tagged,after,run,tagStore,byteStore,byteRead,tagRead,frame,access,next,outside,afterView⟩ :=
    Arm64MemsetStoreExecution.execute view resources e le (Arm64MemsetLossSetup.continuation k) i byte
      hentry hoff hwidth hvalue tagBytes
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have entryTag : entry.block ≠ view.tags.block := separate _ _ _ _ entry.binding view.tags.binding (by decide +kernel)
  have entryStack : entry.block ≠ view.stack.block := separate _ _ _ _ entry.binding view.stack.binding (by decide +kernel)
  have spTag : storage.sp.block ≠ view.tags.block := separate _ _ _ _ storage.sp.binding view.tags.binding (by decide +kernel)
  have spStack : storage.sp.block ≠ view.stack.block := separate _ _ _ _ storage.sp.binding view.stack.binding (by decide +kernel)
  have pointer := (outside CC.Mptr entry.block 40 entryTag entryStack).trans storage.spPointer
  have observed : CC.Mem.load .Mint64 after storage.sp.block 0 = some (.Vlong 0) := by
    rw [outside .Mint64 storage.sp.block 0 spTag spStack,storage.spRead,spZero]
  have inputs := stored_inputs view le i byte
  have back := execute e _ after k entry.block storage.sp.block i (inputs.1.trans hentry)
    (inputs.2.trans hoff) pointer observed
  refine ⟨tagged,after,?_,tagStore,byteStore,byteRead,tagRead,frame,access,next,outside,afterView⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans run back.sound

end KProgFormal.ClightRefinement.Arm64MemsetStoreBackedge
