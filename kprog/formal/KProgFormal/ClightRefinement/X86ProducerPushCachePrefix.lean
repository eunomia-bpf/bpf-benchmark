import KProgFormal.ClightRefinement.X86ProducerPushCacheExecute
import KProgFormal.ClightRefinement.X86ProducerPushCacheCurrent

namespace KProgFormal.ClightRefinement.X86ProducerPushCachePrefix
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)
open X86ProducerPushBody (handler allocation)

def control {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) : CC.Cont :=
  X86ProducerPushStackSource.outerCont (X86ProducerPushMetadataPrefix.control ready)

def temps {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (metadata : X86ProducerPushMetadataPrefix.Result rsp) : CC.TempEnv :=
  (X86ProducerPushStorageSelect.secondCertificate rsp (control ready) metadata.after).output.set
    X86_program_profile_bpf._t'211 (.Vptr (ready.sources 1).block 0)

structure Result {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (metadata : X86ProducerPushMetadataPrefix.Result rsp) where
  after : CC.Mem
  run : CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
    (.State handler .Sskip (X86ProducerPushCacheExecute.following rsp (control ready) metadata.after)
      (allocation ready.after).1 (temps metadata) after)
  stored : CC.Mem.store .Mint64 metadata.after (ready.sources 1).block 40 (.Vlong (ready.values 3)) = some after
  word_read : CC.Mem.load .Mint64 after (ready.sources 1).block 40 = some (.Vlong (ready.values 3))
  disjoint : ∀ c b ofs, b ≠ (ready.sources 1).block ∨ ofs + CC.sizeChunk c ≤ 40 ∨ 48 ≤ ofs → CC.Mem.load c after b ofs = CC.Mem.load c metadata.after b ofs
  header : ∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c metadata.after ready.entry.block ofs
  gprs : ∀ c ofs, CC.Mem.load c after ready.gprs.block ofs = CC.Mem.load c metadata.after ready.gprs.block ofs
  cache_view : X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0
  ghost_view : X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources)
  tag_read : CC.Mem.load .Mint8unsigned after (ready.sources 12).block 0 = some (.Vint 0)
  pointer_read : CC.Mem.load CC.Mptr after (ready.sources 13).block 0 = some (.Vlong 0)
  cells_read : CC.Mem.load CC.Mptr after ready.entry.block 0 = some (.Vptr ready.gprs.block 0)
  rsp_read : CC.Mem.load CC.Mptr after ready.gprs.block 64 = some (.Vlong X86ProducerPushRspStore.nextRsp)
  rsp_tag : CC.Mem.load .Mint8unsigned after ready.gprs.block 72 = some (.Vint 0)
  post_provider_frame : FrameBelow before.nextblock ready.stackOutcome.supplied after
  caller_loads : ∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs
  access : after.access = metadata.after.access
  frontier : after.nextblock = metadata.after.nextblock

theorem from_metadata {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (metadata : X86ProducerPushMetadataPrefix.Result rsp) : Nonempty (Result metadata) := by
  obtain ⟨after,executed,stored,word,disjoint,caller,access,frontier⟩ := X86ProducerPushCacheExecute.from_metadata metadata (control ready)
  have current := X86ProducerPushCacheCurrent.preserve metadata stored
  have run := star_trans metadata.run executed.sound
  refine ⟨⟨after,?_,stored,word,disjoint,current.1,current.2.1,current.2.2.1,current.2.2.2.1,
    current.2.2.2.2.1,current.2.2.2.2.2.1,(current.1 _ _).trans metadata.cells_read,
    (current.2.1 _ _).trans metadata.rsp_read,(current.2.1 _ _).trans metadata.rsp_tag,
    current.2.2.2.2.2.2.1,current.2.2.2.2.2.2.2.1,current.2.2.2.2.2.2.2.2.1,current.2.2.2.2.2.2.2.2.2⟩⟩
  simpa only [control, temps, CC.E0, CC.Eapp, List.append_nil] using run

theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp, Nonempty (Result metadata) := by
  obtain ⟨ready,rsp,metadata⟩ := X86ProducerPushMetadataPrefix.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨metadata⟩ := metadata
  exact ⟨ready,rsp,metadata,from_metadata metadata⟩

theorem inputs {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (metadata : X86ProducerPushMetadataPrefix.Result rsp) :
    (temps metadata).get X86_program_profile_bpf.___x86_bind = some (.Vptr ready.entry.block 0) ∧
    (temps metadata).get X86_program_profile_bpf.___x86_loss_off = some (.Vlong X86ProducerPushRspStore.nextRsp) := ⟨rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushCachePrefix
