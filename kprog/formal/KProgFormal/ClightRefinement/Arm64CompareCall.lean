import KProgFormal.ClightRefinement.Arm64CompareBody
import KProgFormal.ClightRefinement.Arm64ProgramEntryCompareCall
import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Stores
open Arm64Producer Arm64ProducerRegisterStorage

/-- The same allocation-bound register/header storage survives the flag stores;
only actual flag-byte contents change. -/
def Effect.storage {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs result sign : BitVec 64}
    (effect : Effect storage lhs rhs result sign after) : Storage initial after entry := by
  have headerOther : ∀ i : Fin 4,
      headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ Arm64Entry._entry := by decide +kernel
  have tableOther : ∀ (tags : Bool) (i : Fin 4),
      headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ tableName tags := by decide +kernel
  have spOther : ∀ i : Fin 4,
      headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ headerSourceName 5 := by decide +kernel
  have keepHeader := effect.local_load _ _ _ entry.binding headerOther
  refine {storage with
    roots := fun tags => (keepHeader CC.Mptr _).trans (storage.roots tags)
    slots := fun tags i => (effect.local_load _ _ _ (storage.tables tags).binding (tableOther tags) CC.Mptr _).trans (storage.slots tags i)
    vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
      (fun offset => by simp only [CC.Mem.perm,effect.access])).trans storage.vectorWritable
    writable := ?_
    spPointer := (keepHeader CC.Mptr _).trans storage.spPointer
    spRead := (effect.local_load _ _ _ storage.sp.binding spOther .Mint64 _).trans storage.spRead
    flagPointers := fun i => (keepHeader CC.Mptr _).trans (storage.flagPointers i)
    flagWritable := fun i =>
      (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
        (chunk := .Mint8unsigned) (b := (storage.flags i).block) (ofs := 0) (p := .Writable)
        (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans (storage.flagWritable i)
    vectorPointers := fun high i => (keepHeader CC.Mptr _).trans (storage.vectorPointers high i)}
  intro tags i
  exact (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (chunk := cellChunk tags) (b := (storage.tables tags).cellBlock i) (ofs := 0) (p := .Writable)
    (fun o => by simp only [CC.Mem.perm,effect.access])).trans (storage.writable tags i)

end KProgFormal.ClightRefinement.Arm64Compare.Stores

namespace KProgFormal.ClightRefinement.Arm64Compare.Call
open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage (Storage)
open Arm64RegisterStorageFrontier
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryCompareCall (arguments initialTemps entry_valid)

/-- Actual generic function allocation, retaining the same producer storage. -/
def allocatedStorage {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) : Storage initial (Arm64Nop.allocation world before).2 entry :=
  storage.frame (Arm64Nop.entry_frame world before)

def flagValue (lhs rhs : BitVec 64) (i : Fin 4) : CC.Val :=
  Stores.value (Math.left lhs false) (Math.right (Body.rhsValue rhs false) false)
    (Math.result lhs (Body.rhsValue rhs false) false) (Math.sign false) i

/-- Actual live-body effect, real release and return, source observations and
permissions. This record does not assert a native post-state. -/
structure Result {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (lhs rhs : BitVec 64) (k : CC.Cont)
    (written after : CC.Mem) (finalStorage : Storage initial after entry) : Prop where
  effect : Stores.Effect (allocatedStorage storage) (Math.left lhs false)
    (Math.right (Body.rhsValue rhs false) false) (Math.result lhs (Body.rhsValue rhs false) false) (Math.sign false) written
  run : InternalRun world 413 (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
    (.Returnstate .Vundef k after)
  free : CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after
  freeFrame : FrameBelow before.nextblock written after
  contents : after.contents = written.contents
  nextblock : after.nextblock = written.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
    ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
      ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false
  bytes : ∀ i, CC.Mem.load .Mint8unsigned after (finalStorage.flags (Stores.flagIndex i)).block 0 = some (flagValue lhs rhs i)
  writable : Stores.Writable finalStorage
  caller : FrameBelow initial.nextblock before after
  locals : ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
    (∀ i : Fin 4, Arm64Producer.headerSourceName (Arm64ProducerEntryView.flagIndex (Stores.flagIndex i)) ≠ id) →
    ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs
  bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat

private theorem unshadowed (before : CC.Mem) (name : CC.Positive)
    (notLocal : name ∉ CC.varNames Arm64Nop.handler.fn_vars) :
    (Arm64Nop.allocation world before).1.get name = none := by
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64MovImmediate.allocated_bound world before) notLocal
private theorem width_not_local : Arm64Program._arm64_width_effective ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel
private theorem read_not_local : Arm64Program._kprog_arm64_program_read ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel
private theorem modified_not_local : Arm64Program._kprog_arm64_program_modified ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

/-- The real sixth generic call, including original argument binding, callee
allocation, complete body, live-frame release and return. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (writable : Stores.Writable storage)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 4) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 4) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      Result storage lhs rhs k written after finalStorage := by
  have allocationFrame := Arm64Nop.entry_frame world before
  let carried := allocatedStorage storage
  have allocatedWritable := writable.frame carried before.nextblock bound allocationFrame
  have cell (tags : Bool) (i : Fin 31) (chunk : CC.Chunk) :
      CC.Mem.load chunk (Arm64Nop.allocation world before).2 ((carried.tables tags).cellBlock i) 0 =
        CC.Mem.load chunk before ((storage.tables tags).cellBlock i) 0 :=
    allocationFrame.load chunk _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables tags).cellBinding i)) bound)
  let le := initialTemps entry.block
  have data :
      le.get Arm64Program._entry = some (.Vptr entry.block 0) ∧
      le.get Arm64Program._dst = some (.Vlong (4#64)) ∧
      le.get Arm64Program._src = some (.Vlong (1#64)) ∧
      le.get Arm64Program._aux = some (.Vint (256#32)) ∧
      le.get Arm64Program._flags = some (.Vint (8#32)) ∧
      le.get Arm64Program._op = some (.Vint (23#32)) := by
    simp +decide only [le,initialTemps,CC.PTree.gss,CC.PTree.gso,and_self]
  obtain ⟨written,effect,bodyRun⟩ := Body.execute carried allocatedWritable 4 1 lhs rhs
    (Arm64Nop.allocation world before).1 le k false
    (unshadowed before _ width_not_local) (unshadowed before _ read_not_local)
    (unshadowed before _ modified_not_local)
    data.1 data.2.1 data.2.2.1 data.2.2.2.1 data.2.2.2.2.1 data.2.2.2.2.2
    ((cell false 4 .Mint64).trans lhsWord) ((cell true 4 .Mint8unsigned).trans lhsTag)
    ((cell false 1 .Mint64).trans rhsWord) ((cell true 1 .Mint8unsigned).trans rhsTag)
  have owned : ∀ id v, (Arm64Nop.allocation world before).1.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof world.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage (Arm64MovImmediate.allocated_bound world before)).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation world before).2)
      (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans live
  obtain ⟨after,freed,freeFrame,contents,next,released⟩ :=
    deallocate_live_locals (Arm64MovImmediate.allocated_bound world before) owned
  let finalStorage := storage_frame effect.storage before.nextblock bound freeFrame
  have bytes (i : Fin 4) : CC.Mem.load .Mint8unsigned after
      (finalStorage.flags (Stores.flagIndex i)).block 0 = some (flagValue lhs rhs i) := by
    change CC.Mem.load .Mint8unsigned after (storage.flags (Stores.flagIndex i)).block 0 = _
    exact (freeFrame.load .Mint8unsigned _ 0
      (Nat.lt_of_lt_of_le (storage.flags (Stores.flagIndex i)).owned bound)).trans (effect.bytes i)
  have writtenWritable := allocatedWritable.access effect.storage effect.access
  have finalWritable := writtenWritable.frame finalStorage before.nextblock bound freeFrame
  have initialBound := Nat.le_trans ((FrameBelow.allocVariables
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)
    initial.nextblock (Nat.le_refl _)).1) bound
  have callerAlloc : FrameBelow initial.nextblock before (Arm64Nop.allocation world before).2 :=
    fun b owned => allocationFrame b (Nat.lt_of_lt_of_le owned initialBound)
  have callerFree : FrameBelow initial.nextblock written after :=
    fun b owned => freeFrame b (Nat.lt_of_lt_of_le owned initialBound)
  have locals : ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
      (∀ i : Fin 4, Arm64Producer.headerSourceName (Arm64ProducerEntryView.flagIndex (Stores.flagIndex i)) ≠ id) →
      ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs := by
    intro id ty block binding different chunk ofs
    have owned := Nat.lt_of_lt_of_le (local_owned initial id ty block binding) bound
    exact ((freeFrame.load chunk block ofs owned).trans
      (effect.local_load id ty block binding different chunk ofs)).trans (allocationFrame.load chunk block ofs owned)
  have entered : InternalRun world 1
      (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k (Arm64Nop.allocation world before).1 le
        (Arm64Nop.allocation world before).2) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid before entry.block)) (.refl _)
  have left : InternalRun world 1
      (.State Arm64Nop.handler .Sskip k (Arm64Nop.allocation world before).1
        (Body.finalTemps le lhs rhs false (fun i => (carried.flags (Stores.flagIndex i)).block)) written)
      (.Returnstate .Vundef k after) :=
    .step trivial (.skip_call _ _ _ _ _ _ valid freed) (.refl _)
  have finalNext := next.trans effect.nextblock
  have finalBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat :=
    Eq.mpr (congrArg (fun frontier : CC.Block => (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
      finalNext) (Nat.le_trans bound (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound world before)
        before.nextblock (Nat.le_refl _)).1)
  exact ⟨written,after,finalStorage,⟨effect,(entered.trans bodyRun).trans left,freed,freeFrame,contents,next,
    released,bytes,finalWritable,(callerAlloc.trans effect.caller).trans callerFree,locals,finalBound⟩⟩

/-- All raw GPR and tag-cell observations survive the true call and free,
for every register/chunk/offset, via their original allocation bindings. -/
theorem Result.gpr_load {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs : BitVec 64} {k : CC.Cont}
    {finalStorage : Storage initial after entry} (result : Result storage lhs rhs k written after finalStorage)
    (tags : Bool) (r : Fin 31) (chunk : CC.Chunk) (ofs : CC.Z) :
    CC.Mem.load chunk after ((finalStorage.tables tags).cellBlock r) ofs =
      CC.Mem.load chunk before ((storage.tables tags).cellBlock r) ofs := by
  have different : ∀ (tags : Bool) (r : Fin 31) (i : Fin 4),
      Arm64Producer.headerSourceName (Arm64ProducerEntryView.flagIndex (Stores.flagIndex i)) ≠
        Arm64Producer.tableCellName tags r := by decide +kernel
  have same : (finalStorage.tables tags).cellBlock r = (storage.tables tags).cellBlock r :=
    congrArg Prod.fst (Option.some.inj (((finalStorage.tables tags).cellBinding r).symm.trans
      ((storage.tables tags).cellBinding r)))
  rw [same]
  exact result.locals _ _ _ ((storage.tables tags).cellBinding r) (different tags r) chunk ofs

/-- All relational executions are silent prefixes of the same real returned,
freed-frame state. Stuck endpoints coincide and infinite executions are excluded. -/
theorem Result.all_behaviors {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs : BitVec 64}
    {finalStorage : Storage initial after entry} (result : Result storage lhs rhs .Kstop written after finalStorage) :
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun world remaining other (.Returnstate .Vundef .Kstop after)) ∧
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before) t other →
      (∀ u next, ¬ CC.Step2 world other u next) → t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before ∧
      ∀ j, ∃ t, CC.Step2 world (states j) t (states (j+1))) := by
  have stuck : ∀ t next, ¬ CC.Step2 world (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => result.run.finish_prefix stuck observed,
    fun _ _ observed endpoint => result.run.endpoint_unique stuck observed endpoint,
    result.run.no_infinite stuck⟩

/-- The actual original sixth call at afterMul resumes afterCompare, including
all source argument casts and actual caller restoration. -/
theorem execute_caller {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (writable : Stores.Writable storage)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 4) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 4) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      Result storage lhs rhs (Arm64ProgramEntryCompareCall.callCont initial le k) written after finalStorage ∧
      InternalRun world 417
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMulCall.afterMul k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) := by
  have entered := Arm64ProgramEntryCompareCall.enter entry le k before
  obtain ⟨written,after,finalStorage,result⟩ := execute storage writable bound lhs rhs
    lhsWord lhsTag rhsWord rhsTag (Arm64ProgramEntryCompareCall.callCont initial le k) rfl
  have left := Arm64ProgramEntryCompareCall.leave initial le k after
  exact ⟨written,after,finalStorage,result,(entered.trans result.run).trans left⟩


/-- The same actual execution with flag permissions derived from the source
storage allocation/frame history, not supplied as another input. -/
theorem execute_from_storage {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 4) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 4) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      Result storage lhs rhs k written after finalStorage :=
  execute storage (Stores.writable_of_storage storage) bound lhs rhs lhsWord lhsTag rhsWord rhsTag k valid

/-- The same actual execution with flag permissions derived from the source
storage allocation/frame history, not supplied as another input. -/
theorem execute_caller_from_storage {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 4) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 4) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      Result storage lhs rhs (Arm64ProgramEntryCompareCall.callCont initial le k) written after finalStorage ∧
      InternalRun world 417
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMulCall.afterMul k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) :=
  execute_caller storage (Stores.writable_of_storage storage) bound lhs rhs lhsWord lhsTag rhsWord rhsTag le k

end KProgFormal.ClightRefinement.Arm64Compare.Call
