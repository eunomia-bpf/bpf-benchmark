import KProgFormal.ClightRefinement.X86ProducerSubScalarResources

namespace KProgFormal.ClightRefinement.X86ProducerSubFlagStorage
open X86ProducerLayout (ge)
open X86ProducerSubBody (allocation)

private theorem flag_size : ∀ i : Fin 6,
    CC.sizeof ge.genv_cenv (X86ProducerHeaderSource.localType
      (X86ProducerScalarSource.row ⟨i.val,by omega⟩)) = 1 := by decide +kernel

/-- The original six producer flag objects have writable byte rights on the
actual current SUB heap, derived solely from real local allocation/frame
proofs rather than assumed successful stores or a new whole-map equation. -/
theorem writable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache) (i : Fin 6) :
    CC.Mem.validAccess (allocation complete.after).2 .Mint8unsigned
      (ready.scalars ⟨i.val,by omega⟩).block 0 .Writable = true := by
  have rights := X86ProducerSubScalarResources.rights complete (ready.scalars ⟨i.val,by omega⟩)
  rw [flag_size i] at rights
  have permission := CC.Mem.rangePerm_implies rights
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  simp only [CC.Mem.validAccess,Bool.and_eq_true]
  exact ⟨by simpa only [CC.sizeChunk,Int.zero_add] using permission,by decide +kernel⟩

/-- Construct a flag-byte write on the current heap using the permission map
preserved by preceding actual stores. Exact byte readback, all other-block
loads and the old-caller frame survive. Source expressions are proved at
their actual sites; this lemma does not assume a successful write. -/
theorem write_current {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache)
    (memory : CC.Mem) (access : memory.access = (allocation complete.after).2.access)
    (i : Fin 6) (value : Bool) :
    ∃ after, CC.Mem.store .Mint8unsigned memory
        (ready.scalars ⟨i.val,by omega⟩).block 0 (.Vint (if value then 1 else 0)) = some after ∧
      CC.Mem.load .Mint8unsigned after (ready.scalars ⟨i.val,by omega⟩).block 0 =
        some (.Vint (if value then 1 else 0)) ∧
      (∀ chunk block offset, block ≠ (ready.scalars ⟨i.val,by omega⟩).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk memory block offset) ∧
      FrameBelow before.nextblock memory after ∧
      after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  have same : CC.Mem.rangePerm memory (ready.scalars ⟨i.val,by omega⟩).block 0
      (0+CC.sizeChunk .Mint8unsigned) .Cur .Writable =
      CC.Mem.rangePerm (allocation complete.after).2 (ready.scalars ⟨i.val,by omega⟩).block 0
        (0+CC.sizeChunk .Mint8unsigned) .Cur .Writable := by
    apply CC.Mem.rangePerm_congr
    intro offset
    simp only [CC.Mem.perm,access]
  have allowed : CC.Mem.validAccess memory .Mint8unsigned (ready.scalars ⟨i.val,by omega⟩).block 0 .Writable = true := by
    simpa only [CC.Mem.validAccess,same] using writable complete i
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint8unsigned memory
      (ready.scalars ⟨i.val,by omega⟩).block 0 (.Vint (if value then 1 else 0)) = some after := by
    simp only [CC.Mem.store,allowed,ite_true]
    exact ⟨_,rfl⟩
  refine ⟨after,stored,?_,?_,FrameBelow.store (ready.scalars ⟨i.val,by omega⟩).fresh stored,
    CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  · have read := CC.Mem.load_store_same stored
    cases value <;> exact read
  · intro chunk block offset different
    exact CC.Mem.load_store_other stored chunk block offset (.inl different)


/-- Construct each genuine flag-byte memory write on the actual allocated
heap with exact byte readback and complete other-block/caller frames. The
instruction's source expression/cast/transition is proved at its real site. -/
theorem write {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache)
    (i : Fin 6) (value : Bool) :
    ∃ after, CC.Mem.store .Mint8unsigned (allocation complete.after).2
        (ready.scalars ⟨i.val,by omega⟩).block 0 (.Vint (if value then 1 else 0)) = some after ∧
      CC.Mem.load .Mint8unsigned after (ready.scalars ⟨i.val,by omega⟩).block 0 =
        some (.Vint (if value then 1 else 0)) ∧
      (∀ chunk block offset, block ≠ (ready.scalars ⟨i.val,by omega⟩).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock :=
  write_current complete (allocation complete.after).2 rfl i value

end KProgFormal.ClightRefinement.X86ProducerSubFlagStorage
