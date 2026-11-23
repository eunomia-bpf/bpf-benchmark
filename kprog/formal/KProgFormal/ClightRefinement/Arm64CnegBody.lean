import KProgFormal.ClightRefinement.Arm64CnegDispatch

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cneg.Body

/-- Original arguments retained across dispatch, CNEG execution and loop exit. -/
def inputs : List CC.Ident :=
  [Arm64Program._entry, Arm64Program._dst, Arm64Program._src, Arm64Program._src2,
    Arm64Program._src3, Arm64Program._flags, Arm64Program._aux, Arm64Program._op]

private theorem path_input (id : CC.Ident) (inside : id ∈ inputs) : id ∈ Path.inputs := by
  simp only [inputs, List.mem_cons, List.not_mem_nil, or_false] at inside
  rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
  all_goals simp [Path.inputs]

private theorem leave_loop (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun Arm64ProgramEntryLinked.ge 2
      (.State Arm64Nop.handler .Sskip (Dispatch.continuation k) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  apply InternalRun.step
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  exact .refl _

/-- The complete original CNEG64 GE handler body executes the linked width
helper, original dispatch, scalar read, GE call, arithmetic, write and loop
exit. Pre-memory observations determine all intermediate values and stores. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (represented : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) s)
    (src dst : Fin 31) (raw : BitVec 64) (tag : BitVec 8)
    (tags : tag = 0 ∨ tag = 4)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) src.val =
      some (.Vlong raw, .Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false m.nextblock m
      (.Vptr entry.block 0) origins.stack)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthFree : e.get Arm64Program._arm64_width_effective = none)
    (readerFree : e.get Arm64Program._kprog_arm64_program_read = none)
    (conditionFree : e.get Arm64Program._kprog_arm64_program_condition = none)
    (writerFree : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 src.val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (op : le.get Arm64Program._op = some (.Vint (65#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (10#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8))) :
    ∃ count after le',
      Arm64RegisterWrite.Result storage dst
        (let value := Reference.Provenance.AArch64.materialize origins raw tag
         if ConditionHolds (10#4) s.machine then -value else value) false after ∧
      InternalRun Arm64ProgramEntryLinked.ge count
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
        (.State Arm64Nop.handler .Sskip k e le' after) ∧
      ∀ id ∈ inputs, le'.get id = le.get id := by
  obtain ⟨dispatchCount, dispatched, dispatch, width, kept⟩ :=
    Dispatch.body_dispatch e le m k widthFree flags op
  obtain ⟨pathCount, after, le', written, path, pathKept⟩ := Path.execute storage origins s
    represented src dst raw tag tags observed cache e dispatched (Dispatch.continuation k)
    readerFree conditionFree writerFree
    ((kept _ (by simp)).trans entryRead)
    ((kept _ (by simp)).trans source)
    ((kept _ (by simp)).trans destination)
    ((kept _ (by simp)).trans op)
    ((kept _ (by simp)).trans aux) width
  refine ⟨_, after, le', written, (dispatch.trans path).trans (leave_loop e le' after k), ?_⟩
  intro id inside
  exact (pathKept id (path_input id inside)).trans (kept id inside)

end KProgFormal.ClightRefinement.Arm64Cneg.Body
