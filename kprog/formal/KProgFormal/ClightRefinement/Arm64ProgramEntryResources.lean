import KProgFormal.ClightRefinement.Arm64ProgramEntryLoop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryResources

open Arm64ProgramEntryAllocation (world)
open Arm64Producer

/-- Freeable ranges for every actual local, with its actual declared type and
world size. Only the access map, not the contents or frontier, is needed. -/
theorem locals_freeable (initial memory : CC.Mem)
    (access : memory.access = (allocation initial).2.access) :
    ∀ id value, (Arm64ProgramEntryAllocation.allocation initial).1.get id = some value →
      CC.Mem.rangePerm memory value.1 0 (CC.sizeof world.genv_cenv value.2)
        .Cur .Freeable = true := by
  have actualAccess : memory.access = (Arm64ProgramEntryAllocation.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1)
  intro id value binding
  have allocated := ((allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _
      (Prod.eta (Arm64ProgramEntryAllocation.allocation initial)).symm)).1 id value binding).2.2
  apply CC.Mem.rangePerm_intro
  intro offset lower upper
  have perm := CC.Mem.rangePerm_perm (Arm64ProgramEntryAllocation.allocation initial).2
    value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable allocated offset lower upper
  simpa only [CC.Mem.perm, actualAccess] using perm

/-- The existing borrowed cache-storage contract uses the same actual header
block and the actual allocation frontier. No cold flag/value is assumed. -/
theorem cache_storage (returns : Bool) (initial memory : CC.Mem) (entry : HeaderLocal initial)
    (cells : (i : Fin 12) → HeaderSourceLocal initial i)
    (access : memory.access = (allocation initial).2.access)
    (reads : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (cells i).block 0)) :
    Nonempty (Arm64RegisterReads.BorrowedCacheStorage returns
      (Arm64ProgramEntryAllocation.allocation initial).2.nextblock entry.block 0 memory) := by
  obtain ⟨cache, storage⟩ := header_cache_storage returns initial memory entry cells access reads
  have same : cache.entryBlock = entry.block :=
    congrArg Prod.fst (Option.some.inj (cache.entryBinding.symm.trans entry.binding))
  rw [same, (Arm64ProgramEntryAllocation.allocation_corresponds initial).1] at storage
  exact storage

/-- Exactly the resources derived from arbitrary-content header construction.
The cache bound is the allocation frontier, not an asserted native frontier.
Initialized table/SP values and cold-cache contents are separate obligations. -/
structure Resources (initial memory : CC.Mem) (entry : HeaderLocal initial) : Prop where
  freeable : ∀ id value, (Arm64ProgramEntryAllocation.allocation initial).1.get id = some value →
    CC.Mem.rangePerm memory value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable = true
  caches : ∀ returns, Nonempty (Arm64RegisterReads.BorrowedCacheStorage returns
    (Arm64ProgramEntryAllocation.allocation initial).2.nextblock entry.block 0 memory)

/-- Derive both actual cache resources and all actual local ranges from the
same readbacks/access map, without running any initialization again. -/
theorem resources (initial memory : CC.Mem) (entry : HeaderLocal initial)
    (cells : (i : Fin 12) → HeaderSourceLocal initial i)
    (access : memory.access = (allocation initial).2.access)
    (reads : ∀ i, CC.Mem.load CC.Mptr memory entry.block (8 * (i.val : Int)) =
      some (.Vptr (cells i).block 0)) : Resources initial memory entry :=
  ⟨locals_freeable initial memory access,
    fun returns => cache_storage returns initial memory entry cells access reads⟩

private theorem ctx_not_index : Arm64Entry._ctx ≠ Arm64Entry._i := by decide +kernel

/-- The actual reached-body interface retains the entire 638-step result and
adds derived permission/cache resources and the original context temporary.
Its frontier equality only preserves the starting frontier. -/
theorem reached_body (initial before : CC.Mem) (temps : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation initial).2.access) :
    ∃ entry : HeaderLocal initial, ∃ cells : (i : Fin 12) → HeaderSourceLocal initial i,
    ∃ sources : (i : Fin 9) → TailLocal initial i, ∃ vectors : VectorLocal initial,
    ∃ after finalTemps,
      InternalRun world 638
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryAssignments.beforeHeader
          k (Arm64ProgramEntryAllocation.allocation initial).1 temps before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntrySource.body
          k (Arm64ProgramEntryAllocation.allocation initial).1 finalTemps after) ∧
      finalTemps.get Arm64Entry._i = some (.Vint 32) ∧
      (∀ id, id ≠ Arm64Entry._i → finalTemps.get id = temps.get id) ∧
      finalTemps.get Arm64Entry._ctx = temps.get Arm64Entry._ctx ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ (high : Bool) (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr vectors.block (vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) =
        some (Arm64ProgramEntryTail.actualValue sources i)) ∧
      (∀ id ty block, (allocation initial).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk offset, CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) ∧
      Resources initial after entry ∧ FrameBelow initial.nextblock before after ∧
      after.access = before.access ∧ after.nextblock = before.nextblock := by
  obtain ⟨entry, cells, sources, vectors, after, finalTemps, run, index, otherTemps,
    scalarReads, vectorReads, tailReads, locals, frame, finalAccess, next⟩ :=
    Arm64ProgramEntryLoop.header_initialized_before_body initial before temps k access
  rw [Arm64ProgramEntryLoop.actual_body] at run
  exact ⟨entry, cells, sources, vectors, after, finalTemps, run, index, otherTemps,
    otherTemps Arm64Entry._ctx ctx_not_index, scalarReads, vectorReads, tailReads,
    locals, resources initial after entry cells (finalAccess.trans access) scalarReads,
    frame, finalAccess, next⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryResources
