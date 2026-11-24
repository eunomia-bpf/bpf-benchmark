import KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix

namespace KProgFormal.ClightRefinement.X86ProducerPushCacheCurrent
open X86ProducerLayout (ge)

theorem preserve {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (result : X86ProducerPushMetadataPrefix.Result rsp) {after : CC.Mem}
    (stored : CC.Mem.store .Mint64 result.after (ready.sources 1).block 40 (.Vlong (ready.values 3)) = some after) :
    (∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c result.after ready.entry.block ofs) ∧
    (∀ c ofs, CC.Mem.load c after ready.gprs.block ofs = CC.Mem.load c result.after ready.gprs.block ofs) ∧
    X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources) ∧
    CC.Mem.load .Mint8unsigned after (ready.sources 12).block 0 = some (.Vint 0) ∧
    CC.Mem.load CC.Mptr after (ready.sources 13).block 0 = some (.Vlong 0) ∧
    FrameBelow before.nextblock ready.stackOutcome.supplied after ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs) ∧
    after.access = result.after.access ∧ after.nextblock = result.after.nextblock := by
  have gprsDifferent := X86ProducerGprStage.local_separate before ready.gprs (ready.sources 1) (by decide +kernel)
  have header : ∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c result.after ready.entry.block ofs :=
    fun c ofs => CC.Mem.load_store_other stored c ready.entry.block ofs (.inl ready.separated.1)
  have access := CC.Mem.store_access stored
  have rights : ∀ c b ofs permission, CC.Mem.validAccess after c b ofs permission = CC.Mem.validAccess result.after c b ofs permission :=
    fun c b ofs permission => X86ReleaseProvider.access_rights _ _ access c b ofs permission
  have caller := FrameBelow.store (ready.sources 1).fresh stored
  have ghosts := ready.separated.2.1 5
  refine ⟨header, fun c ofs => CC.Mem.load_store_other stored c ready.gprs.block ofs (.inl gprsDifferent), ?_, ?_,
    (CC.Mem.load_store_other stored .Mint8unsigned (ready.sources 12).block 0 (.inl (Ne.symm ghosts.1))).trans result.tag_read,
    (CC.Mem.load_store_other stored CC.Mptr (ready.sources 13).block 0 (.inl (Ne.symm ghosts.2))).trans result.pointer_read,
    result.post_provider_frame.trans caller, ?_, access, CC.Mem.store_nextblock stored⟩
  · exact ⟨(header _ _).trans result.cache_view.header,
      fun slot lane => (rights _ _ _ _).trans (result.cache_view.bytes slot lane),
      fun slot => (rights _ _ _ _).trans (result.cache_view.words slot)⟩
  · exact ⟨fun slot => (header _ _).trans (result.ghost_view.tags slot),
      fun slot => (header _ _).trans (result.ghost_view.pointers slot),
      fun slot => (rights _ _ _ _).trans (result.ghost_view.tag_rights slot),
      fun slot => (rights _ _ _ _).trans (result.ghost_view.pointer_rights slot)⟩
  · intro c b ofs below
    exact (caller.load c b ofs below).trans (result.caller_loads c b ofs below)

end KProgFormal.ClightRefinement.X86ProducerPushCacheCurrent
