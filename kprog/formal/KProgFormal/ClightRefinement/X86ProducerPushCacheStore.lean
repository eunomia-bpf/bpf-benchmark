import KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix

namespace KProgFormal.ClightRefinement.X86ProducerPushCacheStore
open X86ProducerLayout (ge)

/-- The actual current48-byte cache view constructs the aligned qword store
at byte40 from the SAME saved RBX value. All disjoint typed ranges, old
caller bytes and permission/frontier maps are retained. -/
theorem write {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (result : X86ProducerPushMetadataPrefix.Result rsp) :
    ∃ after, CC.Mem.store .Mint64 result.after (ready.sources 1).block 40 (.Vlong (ready.values 3)) = some after ∧
    CC.Mem.load .Mint64 after (ready.sources 1).block 40 = some (.Vlong (ready.values 3)) ∧
    (∀ c b ofs, b ≠ (ready.sources 1).block ∨ ofs + CC.sizeChunk c ≤ 40 ∨ 48 ≤ ofs →
      CC.Mem.load c after b ofs = CC.Mem.load c result.after b ofs) ∧
    FrameBelow before.nextblock result.after after ∧
    after.access = result.after.access ∧ after.nextblock = result.after.nextblock := by
  have writable : CC.Mem.validAccess result.after .Mint64 (ready.sources 1).block 40 .Writable = true := result.cache_view.words 5
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint64 result.after (ready.sources 1).block 40 (.Vlong (ready.values 3)) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_,rfl⟩
  refine ⟨after,stored,CC.Mem.load_store_same stored,?_,FrameBelow.store (ready.sources 1).fresh stored,
    CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  intro c b ofs disjoint
  rcases disjoint with other | below | above
  · exact CC.Mem.load_store_other stored c b ofs (.inl other)
  · exact CC.Mem.load_store_other stored c b ofs (.inr (.inl below))
  · exact CC.Mem.load_store_other stored c b ofs (.inr (.inr above))

end KProgFormal.ClightRefinement.X86ProducerPushCacheStore
