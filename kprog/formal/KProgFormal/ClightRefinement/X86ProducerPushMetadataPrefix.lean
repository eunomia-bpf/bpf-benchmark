import KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute

namespace KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)
open X86ProducerPushBody (handler allocation)

def control {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) : CC.Cont :=
  X86ProducerPushRspSource.control ready.entry.block (X86ProducerPushPrefix.bodyCont ready) ready.after

structure Result {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) where
  middle : CC.Mem
  after : CC.Mem
  run : CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
    (.State handler X86ProducerPushStackSource.storage (X86ProducerPushStackSource.outerCont (control ready))
      (allocation ready.after).1 (X86ProducerPushMetadataExecute.temps ready (control ready) rsp.after) after)
  tag_stored : CC.Mem.store .Mint8unsigned rsp.after (ready.sources 12).block 0 (.Vint 0) = some middle
  pointer_stored : CC.Mem.store CC.Mptr middle (ready.sources 13).block 0 (.Vlong 0) = some after
  tag_read : CC.Mem.load .Mint8unsigned after (ready.sources 12).block 0 = some (.Vint 0)
  pointer_read : CC.Mem.load CC.Mptr after (ready.sources 13).block 0 = some (.Vlong 0)
  header : ∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c rsp.after ready.entry.block ofs
  gprs : ∀ c ofs, CC.Mem.load c after ready.gprs.block ofs = CC.Mem.load c rsp.after ready.gprs.block ofs
  cache : ∀ c ofs, CC.Mem.load c after (ready.sources 1).block ofs = CC.Mem.load c rsp.after (ready.sources 1).block ofs
  cache_view : X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0
  ghost_view : X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources)
  cells_read : CC.Mem.load CC.Mptr after ready.entry.block 0 = some (.Vptr ready.gprs.block 0)
  rsp_read : CC.Mem.load CC.Mptr after ready.gprs.block 64 = some (.Vlong X86ProducerPushRspStore.nextRsp)
  rsp_tag : CC.Mem.load .Mint8unsigned after ready.gprs.block 72 = some (.Vint 0)
  post_provider_frame : FrameBelow before.nextblock ready.stackOutcome.supplied after
  caller_loads : ∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs
  access : after.access = rsp.after.access
  frontier : after.nextblock = rsp.after.nextblock

/-- The SAME whole producer executes its real stack preparation/width call,
every overlap guard and both selected metadata stores, reaching the original
storage loop with current resources and the actual unchanged input trace. -/
theorem from_rsp {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) : Nonempty (Result rsp) := by
  obtain ⟨middle,after,tagStored,pointerStored,executed,tagBack,pointerBack,header,gprs,cache,cacheView,ghostView,raw,caller,access,frontier⟩ :=
    X86ProducerPushMetadataExecute.from_rsp rsp (control ready)
  have run := star_trans rsp.run executed.sound
  refine ⟨⟨middle,after,?_,tagStored,pointerStored,tagBack,pointerBack,header,gprs,cache,cacheView,ghostView,
    (header _ _).trans rsp.cells_read,(gprs _ _).trans rsp.rsp_read,(gprs _ _).trans rsp.rsp_tag,
    raw,caller,access,frontier⟩⟩
  simpa only [control, CC.E0, CC.Eapp, List.append_nil] using run

theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, Nonempty (Result rsp) := by
  obtain ⟨ready⟩ := X86ProducerEntryReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨rsp⟩ := X86ProducerPushRspPrefix.from_ready ready
  exact ⟨ready,rsp,from_rsp rsp⟩

end KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix
