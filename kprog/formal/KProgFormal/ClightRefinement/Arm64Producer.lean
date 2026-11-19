import Lean
import KProgFormal.ClightRefinement.Arm64LinkedProgram
import KProgFormal.ClightRefinement.Deallocation
import KProgFormal.ClightRefinement.StepEquations
import KProgFormal.ClightRefinement.InternalExecution

namespace KProgFormal.ClightRefinement.Arm64Producer

def ge : CC.CGenv := Binding.ge
def producer : CC.Function := Arm64Entry.f_kprog_arm64_entry_raw

def allocation (m : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables ge.genv_cenv CC.emptyEnv m producer.fn_vars

def initialTemps (ctx continuation : CC.Val) : CC.TempEnv :=
  ((CC.createUndefTemps producer.fn_temps).set Arm64Entry._ctx ctx).set
    Arm64Entry._continuation continuation

private theorem names :
    CC.listNorepet (CC.varNames producer.fn_vars) ∧
    CC.listNorepet (CC.varNames producer.fn_params) ∧
    CC.listDisjoint (CC.varNames producer.fn_params) (CC.varNames producer.fn_temps) := by
  decide +kernel

private theorem allocation_valid (m : CC.Mem) :
    CC.AllocVariables ge.genv_cenv CC.emptyEnv m producer.fn_vars
      (allocation m).1 (allocation m).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm

/-- Function entry depends on the real local layout, not an equality of
whole linked worlds. Keep the actual producer allocation and parameters. -/
theorem entry_valid_bound (world : CC.CGenv) (layout : world.genv_cenv = ge.genv_cenv)
    (m : CC.Mem) (ctx continuation : CC.Val) :
    CC.FunctionEntry2 world producer [ctx, continuation] m
      (allocation m).1 (initialTemps ctx continuation) (allocation m).2 :=
  .intro names.1 names.2.1 names.2.2 (by simpa only [layout] using allocation_valid m) rfl

/-- The actual raw producer enters with all its real local declarations,
for arbitrary caller memory, context and continuation values. -/
theorem entry_valid (m : CC.Mem) (ctx continuation : CC.Val) :
    CC.FunctionEntry2 ge producer [ctx, continuation] m
      (allocation m).1 (initialTemps ctx continuation) (allocation m).2 :=
  entry_valid_bound ge rfl m ctx continuation

theorem entry_internal_bound (world : CC.CGenv) (layout : world.genv_cenv = ge.genv_cenv)
    (m : CC.Mem) (ctx continuation : CC.Val) (k : CC.Cont) :
    InternalRun world 1 (.Callstate (.Internal producer) [ctx, continuation] k m)
      (.State producer producer.fn_body k (allocation m).1
        (initialTemps ctx continuation) (allocation m).2) :=
  .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid_bound world layout m ctx continuation)) (.refl _)

theorem entry_internal (m : CC.Mem) (ctx continuation : CC.Val) (k : CC.Cont) :
    InternalRun ge 1 (.Callstate (.Internal producer) [ctx, continuation] k m)
      (.State producer producer.fn_body k (allocation m).1
        (initialTemps ctx continuation) (allocation m).2) :=
  entry_internal_bound ge rfl m ctx continuation k

/-- Allocation retains every caller byte and both permission maps. -/
theorem entry_frame (m : CC.Mem) : FrameBelow m.nextblock m (allocation m).2 :=
  (FrameBelow.allocVariables (allocation_valid m) m.nextblock (Nat.le_refl _)).2

/-- Any actual declared local has a fresh owned block and its complete
Freeable range. This specializes the imported allocation facts to the real
producer without requiring a caller-supplied allocation outcome. -/
theorem local_storage (m : CC.Mem) (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ producer.fn_vars) :
    ∃ block, (allocation m).1.get id = some (block, ty) ∧
      m.nextblock.toNat ≤ block.toNat ∧ block.toNat < (allocation m).2.nextblock.toNat ∧
      CC.Mem.rangePerm (allocation m).2 block 0 (CC.sizeof ge.genv_cenv ty) .Cur .Freeable = true := by
  obtain ⟨block, bound⟩ := allocated_local_binding (allocation_valid m) names.1 present
  exact ⟨block, bound, (allocated_local_storage (allocation_valid m)).1 _ _ bound⟩

def baseName (returns : Bool) : CC.Ident :=
  if returns then Arm64Entry.___a64_numeric_return else Arm64Entry.___a64_numeric_sp

def validName (returns : Bool) : CC.Ident :=
  if returns then Arm64Entry.___a64_numeric_return_valid else Arm64Entry.___a64_numeric_sp_valid

/-- Actual local storage for a selected cache. The header pointers have not
been initialized yet; this record proves allocation and permission facts only. -/
structure CacheLocals (returns : Bool) (m : CC.Mem) where
  entryBlock : CC.Block
  baseBlock : CC.Block
  validBlock : CC.Block
  entryBinding : (allocation m).1.get Arm64Entry._entry =
    some (entryBlock, .Tstruct Arm64Entry._kprog_arm64_entry CC.noattr)
  baseBinding : (allocation m).1.get (baseName returns) = some (baseBlock, CC.tulong)
  validBinding : (allocation m).1.get (validName returns) = some (validBlock, CC.tuchar)
  entryOwned : entryBlock.toNat < (allocation m).2.nextblock.toNat
  baseFresh : m.nextblock.toNat ≤ baseBlock.toNat
  validFresh : m.nextblock.toNat ≤ validBlock.toNat
  baseOwned : baseBlock.toNat < (allocation m).2.nextblock.toNat
  validOwned : validBlock.toNat < (allocation m).2.nextblock.toNat
  entryBase : entryBlock ≠ baseBlock
  entryValid : entryBlock ≠ validBlock
  separate : baseBlock ≠ validBlock
  baseWritable : CC.Mem.validAccess (allocation m).2 .Mint64 baseBlock 0 .Writable = true
  validWritable : CC.Mem.validAccess (allocation m).2 .Mint8unsigned validBlock 0 .Writable = true

/-- The actual declared cache locals always provide distinct owned writable
cells. No caller-supplied successful allocation, permission or alias premise. -/
theorem cache_locals (returns : Bool) (m : CC.Mem) : Nonempty (CacheLocals returns m) := by
  have baseMember : (baseName returns, CC.tulong) ∈ producer.fn_vars := by
    cases returns <;> decide +kernel
  have validMember : (validName returns, CC.tuchar) ∈ producer.fn_vars := by
    cases returns <;> decide +kernel
  have entryMember : (Arm64Entry._entry, CC.Ty.Tstruct Arm64Entry._kprog_arm64_entry CC.noattr) ∈
      producer.fn_vars := by decide +kernel
  obtain ⟨eb, entry⟩ := allocated_local_binding (allocation_valid m) names.1 entryMember
  obtain ⟨bb, base⟩ := allocated_local_binding (allocation_valid m) names.1 baseMember
  obtain ⟨vb, valid⟩ := allocated_local_binding (allocation_valid m) names.1 validMember
  obtain ⟨live, distinct⟩ := allocated_local_storage (allocation_valid m)
  have ebLive := live _ _ entry
  have bbLive := live _ _ base
  have vbLive := live _ _ valid
  have ebNeBase : Arm64Entry._entry ≠ baseName returns := by cases returns <;> decide +kernel
  have ebNeValid : Arm64Entry._entry ≠ validName returns := by cases returns <;> decide +kernel
  have baseNeValid : baseName returns ≠ validName returns := by cases returns <;> decide +kernel
  have basePerm := CC.Mem.rangePerm_implies bbLive.2.2 (by decide : CC.permOrder .Freeable .Writable = true)
  have validPerm := CC.Mem.rangePerm_implies vbLive.2.2 (by decide : CC.permOrder .Freeable .Writable = true)
  refine ⟨⟨eb, bb, vb, entry, base, valid, ebLive.2.1, bbLive.1, vbLive.1, bbLive.2.1, vbLive.2.1,
    distinct _ _ _ _ entry base ebNeBase, distinct _ _ _ _ entry valid ebNeValid,
    distinct _ _ _ _ base valid baseNeValid, ?_, ?_⟩⟩
  · simpa [CC.Mem.validAccess, CC.sizeof, CC.tulong, CC.sizeChunk, CC.alignChunk] using basePerm
  · simpa [CC.Mem.validAccess, CC.sizeof, CC.tuchar, CC.sizeChunk, CC.alignChunk] using validPerm

private def sequenceTail : Nat → CC.Stmt → Option CC.Stmt
  | 0, s => some s
  | n + 1, .Ssequence _ rest => sequenceTail n rest
  | _, _ => none

/-- The actual four cache initializers, followed by the actual remaining
producer body. Reaching this stage from function entry is still separate. -/
def cacheStage : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm
      (← `((sequenceTail 3 Arm64Entry.s_kprog_arm64_entry_raw_66).get (by decide +kernel)))
      (some (← Lean.Elab.Tactic.getMainTarget))
    let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    Lean.Elab.Tactic.closeMainGoal `cache_stage value

def afterCacheStage : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm
      (← `((sequenceTail 4 cacheStage).get (by decide +kernel)))
      (some (← Lean.Elab.Tactic.getMainTarget))
    let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    Lean.Elab.Tactic.closeMainGoal `after_cache_stage value

theorem cache_stage_exported :
    sequenceTail 3 Arm64Entry.s_kprog_arm64_entry_raw_66 = some cacheStage ∧
    sequenceTail 4 cacheStage = some afterCacheStage := by constructor <;> rfl

/-- The four exported cache assignments, independent of their successor. -/
def cacheAssignments : List CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(cacheStage)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:4] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "cache initializer no longer has four assignments"
      rows := rows.push body.getAppArgs[0]!
      body := body.getAppArgs[1]!
    let result ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    Lean.Elab.Tactic.closeMainGoal `cache_assignments result

theorem cache_stage_source : cacheStage =
    cacheAssignments.foldr CC.Stmt.Ssequence afterCacheStage := by rfl

private theorem initialize_exec (world : CC.CGenv) (f : CC.Function) (rest : CC.Stmt) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (sb rb sv rv : CC.Block) (before m1 m2 m3 after : CC.Mem)
    (stackBase : e.get Arm64Entry.___a64_numeric_sp = some (sb, CC.tulong))
    (returnBase : e.get Arm64Entry.___a64_numeric_return = some (rb, CC.tulong))
    (stackValid : e.get Arm64Entry.___a64_numeric_sp_valid = some (sv, CC.tuchar))
    (returnValid : e.get Arm64Entry.___a64_numeric_return_valid = some (rv, CC.tuchar))
    (s0 : CC.Mem.storev .Mint64 before (.Vptr sb 0) (.Vlong 0) = some m1)
    (s1 : CC.Mem.storev .Mint64 m1 (.Vptr rb 0) (.Vlong 0) = some m2)
    (s2 : CC.Mem.storev .Mint8unsigned m2 (.Vptr sv 0) (.Vint 0) = some m3)
    (s3 : CC.Mem.storev .Mint8unsigned m3 (.Vptr rv 0) (.Vint 0) = some after) :
    steps world 12 (.State f (cacheAssignments.foldr CC.Stmt.Ssequence rest) k e le before) =
      some (CC.E0, .State f rest k e le after) ∧
    InternalPath world 12 (.State f (cacheAssignments.foldr CC.Stmt.Ssequence rest) k e le before) := by
  change CC.Mem.storev .Mint64 before (.Vptr sb (0#64)) (.Vlong (0#64)) = some m1 at s0
  change CC.Mem.storev .Mint64 m1 (.Vptr rb (0#64)) (.Vlong (0#64)) = some m2 at s1
  change CC.Mem.storev .Mint8unsigned m2 (.Vptr sv (0#64)) (.Vint (0#32)) = some m3 at s2
  change CC.Mem.storev .Mint8unsigned m3 (.Vptr rv (0#64)) (.Vint (0#32)) = some after at s3
  simp +decide [steps, InternalPath, InternalState, cacheAssignments, List.foldr,
    step_seq, step_skip_seq, CC.doStep, CC.doEvalLvalue, CC.lvalOfVar,
    CC.doEvalExpr, CC.typeof, CC.doAssignLoc, CC.accessMode,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntLong, CC.Cop.castIntInt,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.signed, CC.Integers.MI.signed,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int64.repr,
    CC.Integers.Int64.zero, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
    CC.tulong, CC.tint, CC.tuchar, CC.E0, CC.Eapp,
    stackBase, returnBase, stackValid, returnValid, s0, s1, s2, s3]

/-- The four actual initializer stores exist from the allocated producer's
permissions. Any preceding stores may change contents while preserving access.
The result initializes both cache words and validity bytes to zero, preserves
all caller blocks, and changes no permissions or allocation identity. -/
theorem initialize_caches_body (world : CC.CGenv) (f : CC.Function)
    (rest : CC.Stmt) (m before : CC.Mem) (e : CC.Env) (k : CC.Cont) (le : CC.TempEnv)
    (bases : ∀ returns, e.get (baseName returns) = (allocation m).1.get (baseName returns))
    (valids : ∀ returns, e.get (validName returns) = (allocation m).1.get (validName returns))
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 12
        (.State f (cacheAssignments.foldr CC.Stmt.Ssequence rest) k e le before)
        (.State f rest k e le after) ∧
      (∀ returns, ∃ locals : CacheLocals returns m,
        CC.Mem.loadv .Mint64 after (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow m.nextblock before after ∧
      after.access = before.access ∧ after.nextblock = before.nextblock := by
  obtain ⟨stack⟩ := cache_locals false m
  obtain ⟨ret⟩ := cache_locals true m
  have allDistinct := (allocated_local_storage (allocation_valid m)).2
  have sr : stack.baseBlock ≠ ret.baseBlock :=
    allDistinct _ _ _ _ stack.baseBinding ret.baseBinding (by decide +kernel)
  have sbRv : stack.baseBlock ≠ ret.validBlock :=
    allDistinct _ _ _ _ stack.baseBinding ret.validBinding (by decide +kernel)
  have rbSv : ret.baseBlock ≠ stack.validBlock :=
    allDistinct _ _ _ _ ret.baseBinding stack.validBinding (by decide +kernel)
  have vv : stack.validBlock ≠ ret.validBlock :=
    allDistinct _ _ _ _ stack.validBinding ret.validBinding (by decide +kernel)
  have create : ∀ (memory : CC.Mem) (chunk : CC.Chunk) block value,
      memory.access = (allocation m).2.access →
      CC.Mem.validAccess (allocation m).2 chunk block 0 .Writable = true →
      ∃ next, CC.Mem.store chunk memory block 0 value = some next ∧
        next.access = (allocation m).2.access := by
    intro memory chunk block value same writable
    have actual := (CC.Mem.validAccess_congr (m1 := memory) (m2 := (allocation m).2)
      (chunk := chunk) (b := block) (ofs := 0) (p := .Writable)
      (fun o => by simp only [CC.Mem.perm, same])).trans writable
    have stored : ∃ next, CC.Mem.store chunk memory block 0 value = some next := by
      unfold CC.Mem.store
      rw [actual]
      exact ⟨_, rfl⟩
    obtain ⟨next, store⟩ := stored
    exact ⟨next, store, (CC.Mem.store_access store).trans same⟩
  obtain ⟨m1, s0, a1⟩ := create before .Mint64 stack.baseBlock (.Vlong 0) access stack.baseWritable
  obtain ⟨m2, s1, a2⟩ := create m1 .Mint64 ret.baseBlock (.Vlong 0) a1 ret.baseWritable
  obtain ⟨m3, s2, a3⟩ := create m2 .Mint8unsigned stack.validBlock (.Vint 0) a2 stack.validWritable
  obtain ⟨after, s3, a4⟩ := create m3 .Mint8unsigned ret.validBlock (.Vint 0) a3 ret.validWritable
  have exec := initialize_exec world f rest e le k _ _ _ _ before m1 m2 m3 after
    ((bases false).trans stack.baseBinding) ((bases true).trans ret.baseBinding)
    ((valids false).trans stack.validBinding) ((valids true).trans ret.validBinding) s0 s1 s2 s3
  have baseStack : CC.Mem.loadv .Mint64 after (.Vptr stack.baseBlock 0) = some (.Vlong 0) := by
    have h3 := CC.Mem.load_store_other s3 .Mint64 stack.baseBlock 0 (.inl sbRv)
    have h2 := CC.Mem.load_store_other s2 .Mint64 stack.baseBlock 0 (.inl stack.separate)
    have h1 := CC.Mem.load_store_other s1 .Mint64 stack.baseBlock 0 (.inl sr)
    exact h3.trans (h2.trans (h1.trans (CC.Mem.load_store_same s0)))
  have baseReturn : CC.Mem.loadv .Mint64 after (.Vptr ret.baseBlock 0) = some (.Vlong 0) := by
    have h3 := CC.Mem.load_store_other s3 .Mint64 ret.baseBlock 0 (.inl ret.separate)
    have h2 := CC.Mem.load_store_other s2 .Mint64 ret.baseBlock 0 (.inl rbSv)
    exact h3.trans (h2.trans (CC.Mem.load_store_same s1))
  have validStack : CC.Mem.loadv .Mint8unsigned after (.Vptr stack.validBlock 0) = some (.Vint 0) := by
    have same := (CC.Mem.load_store_other s3 .Mint8unsigned stack.validBlock 0 (.inl vv)).trans
      (CC.Mem.load_store_same s2)
    simpa [CC.Mem.loadv, CC.Val.loadResult, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned] using same
  have validReturn : CC.Mem.loadv .Mint8unsigned after (.Vptr ret.validBlock 0) = some (.Vint 0) := by
    simpa [CC.Mem.loadv, CC.Val.loadResult, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned] using
      CC.Mem.load_store_same s3
  refine ⟨after, internalRun_of_steps exec.2 exec.1, ?_, ?_, a4.trans access.symm, ?_⟩
  · intro returns
    cases returns
    · exact ⟨stack, baseStack, validStack⟩
    · exact ⟨ret, baseReturn, validReturn⟩
  · exact ((FrameBelow.store stack.baseFresh s0).trans (FrameBelow.store ret.baseFresh s1)).trans
      ((FrameBelow.store stack.validFresh s2).trans (FrameBelow.store ret.validFresh s3))
  · exact (CC.Mem.store_nextblock s3).trans ((CC.Mem.store_nextblock s2).trans
      ((CC.Mem.store_nextblock s1).trans (CC.Mem.store_nextblock s0)))

/-- Source producer specialization of the shared cache store construction. -/
theorem initialize_caches_bound (world : CC.CGenv) (m before : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 12
        (.State producer cacheStage k (allocation m).1 le before)
        (.State producer afterCacheStage k (allocation m).1 le after) ∧
      (∀ returns, ∃ locals : CacheLocals returns m,
        CC.Mem.loadv .Mint64 after (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow m.nextblock before after ∧
      after.access = before.access ∧ after.nextblock = before.nextblock := by
  rw [cache_stage_source]
  exact initialize_caches_body world producer afterCacheStage m before (allocation m).1 k le
    (fun _ => rfl) (fun _ => rfl) access

theorem initialize_caches (m before : CC.Mem) (k : CC.Cont) (le : CC.TempEnv)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun ge 12
        (.State producer cacheStage k (allocation m).1 le before)
        (.State producer afterCacheStage k (allocation m).1 le after) ∧
      (∀ returns, ∃ locals : CacheLocals returns m,
        CC.Mem.loadv .Mint64 after (.Vptr locals.baseBlock 0) = some (.Vlong 0) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr locals.validBlock 0) = some (.Vint 0)) ∧
      FrameBelow m.nextblock before after ∧
      after.access = before.access ∧ after.nextblock = before.nextblock :=
  initialize_caches_bound ge m before k le access

end KProgFormal.ClightRefinement.Arm64Producer
