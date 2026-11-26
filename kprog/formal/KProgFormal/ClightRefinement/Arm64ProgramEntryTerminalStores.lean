import KProgFormal.ClightRefinement.Arm64ProgramEntryContinuationByte

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalStores
open Arm64Producer (HeaderLocal HeaderSourceLocal tableCellName tableCellType)
open Arm64ProducerRegisterStorage (Storage)
open Arm64ProgramEntryAllocation (world allocation)

private structure Parts where
  word : CC.Stmt
  afterWord : CC.Stmt
  tag : CC.Stmt
  afterTag : CC.Stmt
  sp : CC.Stmt
  tail : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original terminal stores changed"
      pure actual.getAppArgs
    let first ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryReturnTarget.afterContinuation)) none)
    let second ← peel first[1]!
    let third ← peel second[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_terminal_store_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[first[0]!,first[1]!,second[0]!,second[1]!,third[0]!,third[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_terminal_store_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def word : CC.Stmt := by run_tac cachePart (← `(parts.word))
def afterWord : CC.Stmt := by run_tac cachePart (← `(parts.afterWord))
def tag : CC.Stmt := by run_tac cachePart (← `(parts.tag))
def afterTag : CC.Stmt := by run_tac cachePart (← `(parts.afterTag))
def sp : CC.Stmt := by run_tac cachePart (← `(parts.sp))
def tail : CC.Stmt := by run_tac cachePart (← `(parts.tail))
theorem source : Arm64ProgramEntryReturnTarget.afterContinuation = .Ssequence word afterWord := rfl
theorem after_word_source : afterWord = .Ssequence tag afterTag := rfl
theorem after_tag_source : afterTag = .Ssequence sp tail := rfl
theorem word_source : word = .Sassign
    (.Efield (.Evar Arm64ProgramFixture.___a64_x0 (.Tunion Arm64ProgramFixture._arm64_sim_gpr CC.noattr))
      Arm64ProgramFixture._x CC.tulong) (.Etempvar Arm64ProgramFixture._result CC.tulong) := rfl
theorem tag_source : tag = .Sassign (.Evar Arm64ProgramFixture.___a64_x0_tag CC.tuchar) (.Econst_int (0#32) CC.tuint) := rfl
theorem sp_source : sp = .Sassign (.Evar Arm64ProgramFixture.___a64_sp CC.tlong) (.Econst_int (0#32) CC.tint) := rfl

/-- Actual SP zero store, all other source locals and caller/access frame. -/
structure SpEffect {initial : CC.Mem} (cell : HeaderSourceLocal initial 5) (before after : CC.Mem) : Prop where
  stored : CC.Mem.store .Mint64 before cell.block 0 (.Vlong 0) = some after
  local_load : ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
    id ≠ Arm64Entry.___a64_sp → ∀ chunk ofs,
      CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs
  caller : FrameBelow initial.nextblock before after
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock

/-- Both actual X0 stores followed by the actual SP store. -/
structure Effect {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (value : BitVec 64) (after : CC.Mem) where
  registersWritten : CC.Mem
  registers : Arm64PointerWrite.Result storage 0 value (0#8) registersWritten
  sp : SpEffect storage.sp registersWritten after

theorem sp_binding {initial : CC.Mem} (cell : HeaderSourceLocal initial 5) :
    (allocation initial).1.get Arm64ProgramFixture.___a64_sp = some (cell.block,CC.tlong) :=
  Arm64ProgramEntryAllocation.local_binding initial _ _ _ cell.binding

/-- Source-derived Freeable rights survive the first two real stores and
supply the last SP write. -/
theorem write {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (resources : Arm64ProgramEntryResources.Resources initial before entry)
    (value : BitVec 64) : ∃ after, Nonempty (Effect storage value after) := by
  obtain ⟨written,registers⟩ := Arm64PointerWrite.write storage 0 value (0#8)
  have range := resources.freeable _ _ (sp_binding storage.sp)
  change CC.Mem.rangePerm before storage.sp.block 0 8 .Cur .Freeable = true at range
  have writableRange := CC.Mem.rangePerm_implies range (by decide : CC.permOrder .Freeable .Writable = true)
  have original : CC.Mem.validAccess before .Mint64 storage.sp.block 0 .Writable = true := by
    change (CC.Mem.rangePerm before storage.sp.block 0 8 .Cur .Writable && true) = true
    rw [writableRange]
    rfl
  have writable : CC.Mem.validAccess written .Mint64 storage.sp.block 0 .Writable = true :=
    (CC.Mem.validAccess_congr (m1 := written) (m2 := before)
      (fun ofs => by simp only [CC.Mem.perm,registers.access])).trans original
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint64 written storage.sp.block 0 (.Vlong 0) = some after := by
    simp only [CC.Mem.store,writable,ite_true]
    exact ⟨_,rfl⟩
  have bound : (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_sp = some (storage.sp.block,CC.tlong) := storage.sp.binding
  obtain ⟨block,binding,fresh,_⟩ := Arm64Producer.scalar_local initial Arm64Entry.___a64_sp CC.tlong .Mint64
    (by decide +kernel) rfl (by decide)
  have same : block = storage.sp.block := congrArg Prod.fst (Option.some.inj (binding.symm.trans bound))
  subst block
  refine ⟨after,⟨⟨written,registers,⟨stored,?_,FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩⟩⟩
  intro id ty target localBound different chunk ofs
  have separate := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)).2
    _ _ _ _ bound localBound (Ne.symm different)
  exact CC.Mem.load_store_other stored chunk target ofs (.inl (Ne.symm separate))

private def composite : CC.Composite :=
  (world.genv_cenv.get Arm64ProgramFixture._arm64_sim_gpr).get (by decide +kernel)
private theorem layout : world.genv_cenv.get Arm64ProgramFixture._arm64_sim_gpr = some composite ∧
    CC.unionFieldOffset world.genv_cenv Arm64ProgramFixture._x composite.co_members = .OK (0,.Full) := by
  constructor <;> decide +kernel

theorem word_step {initial before middle : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64ProgramFixture._result = some (.Vlong value))
    (stored : CC.Mem.store .Mint64 before ((storage.tables false).cellBlock 0) 0 (.Vlong value) = some middle) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile word k (allocation initial).1 le before) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le middle) := by
  have binding : (allocation initial).1.get Arm64ProgramFixture.___a64_x0 =
      some ((storage.tables false).cellBlock 0,.Tunion Arm64ProgramFixture._arm64_sim_gpr CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ ((storage.tables false).cellBinding 0)
  have target : CC.doEvalLvalue world (allocation initial).1 le before
      (.Efield (.Evar Arm64ProgramFixture.___a64_x0 (.Tunion Arm64ProgramFixture._arm64_sim_gpr CC.noattr))
        Arm64ProgramFixture._x CC.tulong) = some (((storage.tables false).cellBlock 0),0,.Full) := by
    simp only [CC.doEvalLvalue,CC.lvalOfVar,binding,CC.lvalOfField,CC.typeof,CC.doEvalExpr,CC.doDerefLoc,CC.accessMode,layout.1,layout.2]
    rfl
  have cast : CC.Cop.semCast (.Vlong value) CC.tulong CC.tulong before = some (.Vlong value) := rfl
  have assigned : CC.doAssignLoc world.genv_cenv CC.tulong before ((storage.tables false).cellBlock 0) 0 .Full (.Vlong value) = some middle := stored
  apply CC.doStep_sound
  rw [word_source,CC.doStep,target]
  simp only [CC.doEvalExpr,read,CC.typeof,cast,assigned]

theorem tag_step {initial before middle written : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (le : CC.TempEnv) (k : CC.Cont)
    (stored : CC.Mem.store .Mint8unsigned middle ((storage.tables true).cellBlock 0) 0 (.Vint 0) = some written) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile tag k (allocation initial).1 le middle) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le written) := by
  have binding : (allocation initial).1.get Arm64ProgramFixture.___a64_x0_tag = some ((storage.tables true).cellBlock 0,CC.tuchar) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ ((storage.tables true).cellBinding 0)
  have target : CC.doEvalLvalue world (allocation initial).1 le middle
      (.Evar Arm64ProgramFixture.___a64_x0_tag CC.tuchar) = some (((storage.tables true).cellBlock 0),0,.Full) := by
    simp only [CC.doEvalLvalue,CC.lvalOfVar,binding]
    rfl
  have cast : CC.Cop.semCast (.Vint (0#32)) CC.tuint CC.tuchar middle = some (.Vint 0) := rfl
  have assigned : CC.doAssignLoc world.genv_cenv CC.tuchar middle ((storage.tables true).cellBlock 0) 0 .Full (.Vint 0) = some written := stored
  apply CC.doStep_sound
  rw [tag_source,CC.doStep,target]
  simp only [CC.doEvalExpr,CC.typeof,cast,assigned]

theorem sp_step {initial before after : CC.Mem} (cell : HeaderSourceLocal initial 5)
    (le : CC.TempEnv) (k : CC.Cont) (effect : SpEffect cell before after) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile sp k (allocation initial).1 le before) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) := by
  have target : CC.doEvalLvalue world (allocation initial).1 le before
      (.Evar Arm64ProgramFixture.___a64_sp CC.tlong) = some (cell.block,0,.Full) := by
    simp only [CC.doEvalLvalue,CC.lvalOfVar,sp_binding cell]
    rfl
  have cast : CC.Cop.semCast (.Vint (0#32)) CC.tint CC.tlong before = some (.Vlong 0) := rfl
  have assigned : CC.doAssignLoc world.genv_cenv CC.tlong before cell.block 0 .Full (.Vlong 0) = some after := effect.stored
  apply CC.doStep_sound
  rw [sp_source,CC.doStep,target]
  simp only [CC.doEvalExpr,CC.typeof,cast,assigned]

set_option hygiene false in
/-- Execute all THREE actual direct assignments and real sequence resumes. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (resources : Arm64ProgramEntryResources.Resources initial before entry)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (read : le.get Arm64ProgramFixture._result = some (.Vlong value)) :
    ∃ after, ∃ effect : Effect storage value after, InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.afterContinuation k (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile tail k (allocation initial).1 le after) := by
  obtain ⟨after,⟨effect⟩⟩ := write storage resources value
  obtain ⟨middle,wordStore,tagStore⟩ := effect.registers.stores
  refine ⟨after,effect,?_⟩
  run_tac do
    for i in [:9] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 1 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact word_step storage le _ value read wordStore))
      else if i == 4 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact tag_step storage le _ tagStore))
      else if i == 7 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact sp_step storage.sp le _ effect.sp))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,source,after_word_source,after_tag_source] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

end KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalStores
