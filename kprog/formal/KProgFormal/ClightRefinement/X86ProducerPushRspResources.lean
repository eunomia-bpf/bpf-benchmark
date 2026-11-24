import KProgFormal.ClightRefinement.X86ProducerPushRspStore

namespace KProgFormal.ClightRefinement.X86ProducerPushRspResources
open X86ProducerLayout (ge)
open X86ProducerPushBody (allocation)

/-- The actual RSP store leaves the original header, cache and ghost views
current, together with the cell pointer and RSP scalar tag. Store disjointness
and unchanged access derive every field; no post-store View is assumed. -/
theorem views {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) {after : CC.Mem}
    (stored : CC.Mem.store CC.Mptr (allocation ready.after).2 ready.gprs.block 64
      (.Vlong X86ProducerPushRspStore.nextRsp) = some after) :
    (∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c (allocation ready.after).2 ready.entry.block ofs) ∧
    X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources) ∧
    CC.Mem.load CC.Mptr after ready.entry.block 0 = some (.Vptr ready.gprs.block 0) ∧
    CC.Mem.load .Mint8unsigned after ready.gprs.block 72 = some (.Vint 0) := by
  have different : ready.entry.block ≠ ready.gprs.block :=
    (X86ProducerHeaderLocals.source_separate ge.genv_cenv before 0 ready.entry ready.gprs).symm
  have header : ∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c (allocation ready.after).2 ready.entry.block ofs :=
    fun c ofs => CC.Mem.load_store_other stored c ready.entry.block ofs (.inl different)
  have access := CC.Mem.store_access stored
  have original := X86ProducerPushResources.views ready
  refine ⟨header, ?_, ?_, (header _ _).trans original.2.2.1, ?_⟩
  · exact ⟨(header _ _).trans original.1.header,
      fun slot lane => (X86ReleaseProvider.access_rights _ _ access _ _ _ _).trans (original.1.bytes slot lane),
      fun slot => (X86ReleaseProvider.access_rights _ _ access _ _ _ _).trans (original.1.words slot)⟩
  · exact ⟨fun slot => (header _ _).trans (original.2.1.tags slot),
      fun slot => (header _ _).trans (original.2.1.pointers slot),
      fun slot => (X86ReleaseProvider.access_rights _ _ access _ _ _ _).trans (original.2.1.tag_rights slot),
      fun slot => (X86ReleaseProvider.access_rights _ _ access _ _ _ _).trans (original.2.1.pointer_rights slot)⟩
  · have frame := CC.Mem.load_store_other stored .Mint8unsigned ready.gprs.block 72
      (.inr (.inr (show 64 + CC.sizeChunk CC.Mptr ≤ 72 by decide +kernel)))
    exact frame.trans ((X86ProducerPushResources.observations ready).1 4 (by decide +kernel)).2

end KProgFormal.ClightRefinement.X86ProducerPushRspResources
