import KProgFormal.ClightRefinement.X86ProducerPushReturn
import KProgFormal.ClightRefinement.X86ProducerPushReturnResources

namespace KProgFormal.ClightRefinement.X86ProducerPushComplete
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)
open X86ProducerPushBody (allocation)

/-- Completion of the first actual producer PUSH call, with its true next
source statement and all current output resources. Canonical fetched-ISA,
native-memory/input-oracle/trace correspondence remain separate goals. -/
structure Result {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (cache : X86ProducerPushCachePrefix.Result metadata) where
  after : CC.Mem
  run : CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
    (.State producer X86ProducerContextSource.followingCalls outer (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output after)
  freed : CC.Mem.freeList cache.after (CC.blocksOfEnv ge.genv_cenv (allocation ready.after).1) = some after
  old_frame : FrameBelow ready.after.nextblock cache.after after
  contents : after.contents = cache.after.contents
  frontier : after.nextblock = cache.after.nextblock
  released : ∀ row ∈ CC.blocksOfEnv ge.genv_cenv (allocation ready.after).1, ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
    ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false
  word_read : CC.Mem.load .Mint64 after (ready.sources 1).block 40 = some (.Vlong (ready.values 3))
  rsp_read : CC.Mem.load CC.Mptr after ready.gprs.block 64 = some (.Vlong X86ProducerPushRspStore.nextRsp)
  rsp_tag : CC.Mem.load .Mint8unsigned after ready.gprs.block 72 = some (.Vint 0)
  tag_read : CC.Mem.load .Mint8unsigned after (ready.sources 12).block 0 = some (.Vint 0)
  pointer_read : CC.Mem.load CC.Mptr after (ready.sources 13).block 0 = some (.Vlong 0)
  cells_read : CC.Mem.load CC.Mptr after ready.entry.block 0 = some (.Vptr ready.gprs.block 0)
  cache_view : X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0
  ghost_view : X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources)
  post_provider_frame : FrameBelow before.nextblock ready.stackOutcome.supplied after
  caller_loads : ∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs

theorem from_cache {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (cache : X86ProducerPushCachePrefix.Result metadata) : Nonempty (Result cache) := by
  obtain ⟨after,returned,freed,frame,contents,frontier,released⟩ := X86ProducerPushReturn.from_cache cache
  obtain ⟨word,rspRead,rspTag,tagRead,pointerRead,cells,cacheView,ghostView,raw,caller⟩ :=
    X86ProducerPushReturnResources.preserve cache frame
  have run := star_trans cache.run returned.sound
  refine ⟨⟨after,?_,freed,frame,contents,frontier,released,word,rspRead,rspTag,tagRead,pointerRead,cells,cacheView,ghostView,raw,caller⟩⟩
  simpa only [CC.E0, CC.Eapp, List.append_nil] using run

/-- Only the original explicit kind6/kind1 platform input ABIs are premises.
Every source initializer/dispatch/selector/helper/store/loop/free/return of
the actual first PUSH is included, with the genuine provider trace retained. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, Nonempty (Result cache) := by
  obtain ⟨ready,rsp,metadata,cache⟩ := X86ProducerPushCachePrefix.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨cache⟩ := cache
  exact ⟨ready,rsp,metadata,cache,from_cache cache⟩

end KProgFormal.ClightRefinement.X86ProducerPushComplete
