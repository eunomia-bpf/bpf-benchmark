import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkCall
open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProgramEntryAllocation (world allocation)

private structure Parts where
  body : CC.Stmt
  innerBody : CC.Stmt
  storeLR : CC.Stmt
  afterStore : CC.Stmt
  readLR : CC.Stmt
  writeCall : CC.Stmt
  jump : CC.Stmt
private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original CALL source changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCmpLabels.takenBody)) none) ``CC.Stmt.Sloop 2
    let body ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let inner ← peel body[0]! ``CC.Stmt.Sloop 2
    let setup ← peel inner[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel setup[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_link_call_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[0]!,inner[0]!,setup[0]!,setup[1]!,tail[0]!,tail[1]!,body[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_link_call_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
def innerBody : CC.Stmt := by run_tac cachePart (← `(parts.innerBody))
def storeLR : CC.Stmt := by run_tac cachePart (← `(parts.storeLR))
def afterStore : CC.Stmt := by run_tac cachePart (← `(parts.afterStore))
def readLR : CC.Stmt := by run_tac cachePart (← `(parts.readLR))
def writeCall : CC.Stmt := by run_tac cachePart (← `(parts.writeCall))
def jump : CC.Stmt := by run_tac cachePart (← `(parts.jump))
theorem source : Arm64ProgramEntryCmpLabels.takenBody = .Sloop body .Sbreak := rfl
theorem body_source : body = .Ssequence (.Sloop innerBody .Sbreak) jump := rfl
theorem inner_source : innerBody = .Ssequence storeLR afterStore := rfl
theorem after_source : afterStore = .Ssequence readLR writeCall := rfl
theorem store_source : storeLR = .Sassign (.Evar Arm64ProgramFixture.___a64_lr CC.tulong)
    (.Econst_int (64#32) CC.tint) := rfl
theorem read_source : readLR = .Sset Arm64ProgramFixture._t'159
    (.Evar Arm64ProgramFixture.___a64_lr CC.tulong) := rfl
theorem jump_source : jump = .Sgoto Arm64ProgramFixture._callee := rfl

def outerCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k)
def innerCont (k : CC.Cont) : CC.Cont := .Kloop1 innerBody .Sbreak (.Kseq jump (outerCont k))
def storeCont (k : CC.Cont) : CC.Cont := .Kseq afterStore (innerCont k)
def temps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64ProgramFixture._t'159 (.Vlong 64)

theorem local_binding {initial : CC.Mem} (lr : HeaderSourceLocal initial 4) :
    (allocation initial).1.get Arm64ProgramFixture.___a64_lr = some (lr.block,CC.tulong) :=
  Arm64ProgramEntryAllocation.local_binding initial _ _ _ lr.binding

/-- The true LR store retains its imported memory event, every other allocated
local and the original caller frame. -/
structure Effect {initial : CC.Mem} (lr : HeaderSourceLocal initial 4) (before after : CC.Mem) : Prop where
  stored : CC.Mem.store .Mint64 before lr.block 0 (.Vlong 64) = some after
  local_load : ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
    id ≠ Arm64Entry.___a64_lr → ∀ chunk ofs,
    CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs
  caller : FrameBelow initial.nextblock before after
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock

/-- Current real Freeable ranges derive the eight-byte LR store; its success
and observed value are outputs of this original source memory operation. -/
theorem write {initial before : CC.Mem} {entry : HeaderLocal initial}
    (resources : Arm64ProgramEntryResources.Resources initial before entry) (lr : HeaderSourceLocal initial 4) :
    ∃ after, Effect lr before after := by
  have range := resources.freeable _ _ (local_binding lr)
  change CC.Mem.rangePerm before lr.block 0 8 .Cur .Freeable = true at range
  have writableRange := CC.Mem.rangePerm_implies range (by decide : CC.permOrder .Freeable .Writable = true)
  have writable : CC.Mem.validAccess before .Mint64 lr.block 0 .Writable = true := by
    change (CC.Mem.rangePerm before lr.block 0 8 .Cur .Writable && true) = true
    rw [writableRange]
    rfl
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint64 before lr.block 0 (.Vlong 64) = some after := by
    simp only [CC.Mem.store,writable,ite_true]
    exact ⟨_,rfl⟩
  have lrBinding : (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_lr = some (lr.block,CC.tulong) := lr.binding
  obtain ⟨block,binding,fresh,_⟩ := Arm64Producer.scalar_local initial Arm64Entry.___a64_lr CC.tulong .Mint64
    (by decide +kernel) rfl (by decide)
  have same : block = lr.block := congrArg Prod.fst (Option.some.inj (binding.symm.trans lrBinding))
  subst block
  refine ⟨after,⟨stored,?_,FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩
  intro id ty block bound different chunk ofs
  have separate := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)).2
    _ _ _ _ lrBinding bound (Ne.symm different)
  exact CC.Mem.load_store_other stored chunk block ofs (.inl (Ne.symm separate))

theorem store_step {initial before after : CC.Mem} (lr : HeaderSourceLocal initial 4)
    (le : CC.TempEnv) (k : CC.Cont) (effect : Effect lr before after) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile storeLR k (allocation initial).1 le before) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) := by
  have target : CC.doEvalLvalue world (allocation initial).1 le before
      (.Evar Arm64ProgramFixture.___a64_lr CC.tulong) = some (lr.block,0,.Full) := by
    simp only [CC.doEvalLvalue,CC.lvalOfVar,local_binding lr]
    rfl
  have cast : CC.Cop.semCast (.Vint (64#32)) CC.tint CC.tulong before = some (.Vlong 64) := rfl
  have assigned : CC.doAssignLoc world.genv_cenv CC.tulong before lr.block 0 .Full (.Vlong 64) = some after := by
    change CC.Mem.store .Mint64 before lr.block 0 (.Vlong 64) = some after
    exact effect.stored
  apply CC.doStep_sound
  rw [store_source,CC.doStep,target]
  simp only [CC.doEvalExpr,CC.typeof,cast,assigned]

/-- Actual Evar load observes the value from the real LR store. -/
theorem read_step {initial before after : CC.Mem} (lr : HeaderSourceLocal initial 4)
    (le : CC.TempEnv) (k : CC.Cont) (effect : Effect lr before after) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile readLR k (allocation initial).1 le after) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le) after) := by
  have read : CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong 64) := CC.Mem.load_store_same effect.stored
  have evaluated : CC.doEvalExpr world (allocation initial).1 le after
      (.Evar Arm64ProgramFixture.___a64_lr CC.tulong) = some (.Vlong 64) := by
    simp only [CC.doEvalExpr,CC.lvalOfVar,local_binding lr]
    change CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong 64)
    exact read
  rw [read_source]
  exact CC.Step.set _ _ _ _ _ _ _ _ (CC.doEvalExpr_sound _ _ _ _ _ _ evaluated)

set_option hygiene false in
private theorem enter {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 4
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
        (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile storeLR (storeCont k) (allocation initial).1 le m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,source,body_source,inner_source,
        outerCont,innerCont,storeCont] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

set_option hygiene false in
private theorem resume {initial before after : CC.Mem} (lr : HeaderSourceLocal initial 4)
    (le : CC.TempEnv) (k : CC.Cont) (effect : Effect lr before after) :
    InternalRun world 4
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (storeCont k) (allocation initial).1 le after)
      (.State Arm64ProgramFixture.f_arm64_execute_compile writeCall (innerCont k) (allocation initial).1 (temps le) after) := by
  run_tac do
    for i in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 2 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact read_step lr le _ effect))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,storeCont,after_source] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Original CALL setup performs its actual LR write/read before reaching the
actual pointer-writer call, with the real changed heap and captured t159. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (resources : Arm64ProgramEntryResources.Resources initial before entry) (lr : HeaderSourceLocal initial 4)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after, Effect lr before after ∧ InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
        (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile writeCall (innerCont k) (allocation initial).1 (temps le) after) := by
  obtain ⟨after,effect⟩ := write resources lr
  have store : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile storeLR (storeCont k) (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (storeCont k) (allocation initial).1 le after) :=
    .step (by rw [store_source]; trivial) (store_step lr le (storeCont k) effect) (.refl _)
  exact ⟨after,effect,((enter le before k).trans store).trans (resume lr le k effect)⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkCall
