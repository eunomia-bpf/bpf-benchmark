import KProgFormal.ClightRefinement.X86ProducerPushCachePrefix

namespace KProgFormal.ClightRefinement.X86ProducerPushDeallocate
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)

/-- Every original PUSH body local still has its actual allocated Freeable
range after all genuine GPR/metadata/cache stores. Real free-list success,
old caller raw frame, contents/frontier and revoked local rights follow. -/
theorem execute {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (result : X86ProducerPushCachePrefix.Result metadata) :
    ∃ after, CC.Mem.freeList result.after (CC.blocksOfEnv ge.genv_cenv (allocation ready.after).1) = some after ∧
    FrameBelow ready.after.nextblock result.after after ∧ after.contents = result.after.contents ∧
    after.nextblock = result.after.nextblock ∧
    (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (allocation ready.after).1, ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
      ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  have access := result.access.trans (metadata.access.trans rsp.access)
  have allocated := X86ProducerPushBody.allocation_valid ready.after
  apply deallocate_live_locals allocated
  intro name value binding
  have range := ((allocated_local_storage allocated).1 name value binding).2.2
  apply CC.Mem.rangePerm_intro
  intro ofs lower upper
  have permission := CC.Mem.rangePerm_perm (allocation ready.after).2 value.1 0 (CC.sizeof ge.genv_cenv value.2)
    .Cur .Freeable range ofs lower upper
  simpa only [CC.Mem.perm, access] using permission

end KProgFormal.ClightRefinement.X86ProducerPushDeallocate
