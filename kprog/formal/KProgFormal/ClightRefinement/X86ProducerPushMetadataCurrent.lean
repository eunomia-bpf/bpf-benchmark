import KProgFormal.ClightRefinement.X86ProducerPushRspPrefix

namespace KProgFormal.ClightRefinement.X86ProducerPushMetadataCurrent
open X86ProducerLayout (ge)

theorem preserve {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (result : X86ProducerPushRspPrefix.Result ready) {middle after : CC.Mem}
    (tagStored : CC.Mem.store .Mint8unsigned result.after (ready.sources 12).block 0 (.Vint 0) = some middle)
    (pointerStored : CC.Mem.store CC.Mptr middle (ready.sources 13).block 0 (.Vlong 0) = some after) :
    (∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c result.after ready.entry.block ofs) ∧
    (∀ c ofs, CC.Mem.load c after ready.gprs.block ofs = CC.Mem.load c result.after ready.gprs.block ofs) ∧
    (∀ c ofs, CC.Mem.load c after (ready.sources 1).block ofs = CC.Mem.load c result.after (ready.sources 1).block ofs) ∧
    X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources) ∧
    FrameBelow before.nextblock ready.stackOutcome.supplied after ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs) ∧
    after.access = result.after.access ∧ after.nextblock = result.after.nextblock := by
  have safe := ready.separated.2.2 5
  have cache := ready.separated.2.1 5
  have gprTag : ready.gprs.block ≠ (ready.sources 12).block :=
    X86ProducerGprStage.local_separate before ready.gprs (ready.sources 12) (by decide +kernel)
  have gprPointer : ready.gprs.block ≠ (ready.sources 13).block :=
    X86ProducerGprStage.local_separate before ready.gprs (ready.sources 13) (by decide +kernel)
  have frame : ∀ c b ofs, b ≠ (ready.sources 12).block → b ≠ (ready.sources 13).block →
      CC.Mem.load c after b ofs = CC.Mem.load c result.after b ofs := by
    intro c b ofs differentTag differentPointer
    exact (CC.Mem.load_store_other pointerStored c b ofs (.inl differentPointer)).trans
      (CC.Mem.load_store_other tagStored c b ofs (.inl differentTag))
  have header : ∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c result.after ready.entry.block ofs :=
    fun c ofs => frame c ready.entry.block ofs (Ne.symm safe.1) (Ne.symm safe.2.1)
  have access := (CC.Mem.store_access pointerStored).trans (CC.Mem.store_access tagStored)
  have rights : ∀ c b ofs permission, CC.Mem.validAccess after c b ofs permission = CC.Mem.validAccess result.after c b ofs permission :=
    fun c b ofs permission => X86ReleaseProvider.access_rights _ _ access c b ofs permission
  have caller : FrameBelow before.nextblock result.after after :=
    (FrameBelow.store (ready.sources 12).fresh tagStored).trans (FrameBelow.store (ready.sources 13).fresh pointerStored)
  refine ⟨header, fun c ofs => frame c ready.gprs.block ofs gprTag gprPointer,
    fun c ofs => frame c (ready.sources 1).block ofs cache.1 cache.2, ?_, ?_,
    result.post_provider_frame.trans caller, ?_, access,
    (CC.Mem.store_nextblock pointerStored).trans (CC.Mem.store_nextblock tagStored)⟩
  · exact ⟨(header _ _).trans result.cache_view.header,
      fun slot lane => (rights _ _ _ _).trans (result.cache_view.bytes slot lane),
      fun slot => (rights _ _ _ _).trans (result.cache_view.words slot)⟩
  · exact ⟨fun slot => (header _ _).trans (result.ghost_view.tags slot),
      fun slot => (header _ _).trans (result.ghost_view.pointers slot),
      fun slot => (rights _ _ _ _).trans (result.ghost_view.tag_rights slot),
      fun slot => (rights _ _ _ _).trans (result.ghost_view.pointer_rights slot)⟩
  · intro c b ofs below
    exact (caller.load c b ofs below).trans (result.caller_loads c b ofs below)

end KProgFormal.ClightRefinement.X86ProducerPushMetadataCurrent
