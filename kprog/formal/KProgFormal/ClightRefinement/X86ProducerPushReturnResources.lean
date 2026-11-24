import KProgFormal.ClightRefinement.X86ProducerPushDeallocate

namespace KProgFormal.ClightRefinement.X86ProducerPushReturnResources
open X86ProducerLayout (ge)

theorem preserve {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (result : X86ProducerPushCachePrefix.Result metadata)
    {after : CC.Mem} (frame : FrameBelow ready.after.nextblock result.after after) :
    CC.Mem.load .Mint64 after (ready.sources 1).block 40 = some (.Vlong (ready.values 3)) ∧
    CC.Mem.load CC.Mptr after ready.gprs.block 64 = some (.Vlong X86ProducerPushRspStore.nextRsp) ∧
    CC.Mem.load .Mint8unsigned after ready.gprs.block 72 = some (.Vint 0) ∧
    CC.Mem.load .Mint8unsigned after (ready.sources 12).block 0 = some (.Vint 0) ∧
    CC.Mem.load CC.Mptr after (ready.sources 13).block 0 = some (.Vlong 0) ∧
    CC.Mem.load CC.Mptr after ready.entry.block 0 = some (.Vptr ready.gprs.block 0) ∧
    X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources) ∧
    FrameBelow before.nextblock ready.stackOutcome.supplied after ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs) := by
  have old (i : Fin 24) : (ready.sources i).block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact (ready.sources i).owned
  have headerOld : ready.entry.block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact ready.entry.owned
  have gprsOld : ready.gprs.block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact ready.gprs.owned
  have rights {b : CC.Block} (below : b.toNat < ready.after.nextblock.toNat) (c : CC.Chunk) (ofs : Int) (permission : CC.Permission) :
      CC.Mem.validAccess after c b ofs permission = CC.Mem.validAccess result.after c b ofs permission := by
    apply CC.Mem.validAccess_congr
    intro point
    simp only [CC.Mem.perm,(frame b below).2]
  have beforeBound : before.nextblock.toNat ≤ ready.after.nextblock.toNat := by
    have fresh := ready.gprs.fresh
    omega
  have oldCaller : FrameBelow before.nextblock result.after after := fun b below => frame b (by omega)
  refine ⟨(frame.load _ _ _ (old 1)).trans result.word_read,(frame.load _ _ _ gprsOld).trans result.rsp_read,
    (frame.load _ _ _ gprsOld).trans result.rsp_tag,(frame.load _ _ _ (old 12)).trans result.tag_read,
    (frame.load _ _ _ (old 13)).trans result.pointer_read,(frame.load _ _ _ headerOld).trans result.cells_read,
    ?_,?_,result.post_provider_frame.trans oldCaller,?_⟩
  · exact ⟨(frame.load _ _ _ headerOld).trans result.cache_view.header,
      fun slot lane => (rights (old 1) _ _ _).trans (result.cache_view.bytes slot lane),
      fun slot => (rights (old 1) _ _ _).trans (result.cache_view.words slot)⟩
  · exact ⟨fun slot => (frame.load _ _ _ headerOld).trans (result.ghost_view.tags slot),
      fun slot => (frame.load _ _ _ headerOld).trans (result.ghost_view.pointers slot),
      fun slot => (rights (ready.ghosts_live slot).1 _ _ _).trans (result.ghost_view.tag_rights slot),
      fun slot => (rights (ready.ghosts_live slot).2 _ _ _).trans (result.ghost_view.pointer_rights slot)⟩
  · intro c b ofs below
    exact (oldCaller.load c b ofs below).trans (result.caller_loads c b ofs below)

end KProgFormal.ClightRefinement.X86ProducerPushReturnResources
