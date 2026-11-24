import KProgFormal.ClightRefinement.X86ProducerPushExitSource
import KProgFormal.ClightRefinement.X86ProducerPushLossCheck

namespace KProgFormal.ClightRefinement.X86ProducerPushExit
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)

theorem following_source {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) :
    X86ProducerPushCacheExecute.following rsp k memory =
      .Kloop1 X86ProducerPushStorageSource.fastBody .Sbreak
        (.Kseq X86ProducerPushStorageSource.lossCheck (X86ProducerPushStorageSource.loopCont k)) := rfl

/-- The actual cached payload path exits its fast loop, reloads current RSP,
executes the genuine false signed-loss branch and exits the storage loop. -/
theorem leave_storage {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (result : X86ProducerPushCachePrefix.Result metadata) (k : CC.Cont) :
    InternalRun ge 12
      (.State handler .Sskip (X86ProducerPushCacheExecute.following rsp k metadata.after) (allocation ready.after).1
        (X86ProducerPushCachePrefix.temps metadata) result.after)
      (.State handler .Sskip k (allocation ready.after).1
        (X86ProducerPushLossCheck.temps (X86ProducerPushCachePrefix.temps metadata) ready.gprs.block) result.after) := by
  rw [following_source]
  have first := X86ProducerPushExitSource.finish_loop (allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) result.after
    X86ProducerPushStorageSource.fastBody (.Kseq X86ProducerPushStorageSource.lossCheck (X86ProducerPushStorageSource.loopCont k))
  have sequence : InternalRun ge 1
      (.State handler .Sskip (.Kseq X86ProducerPushStorageSource.lossCheck (X86ProducerPushStorageSource.loopCont k))
        (allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) result.after)
      (.State handler X86ProducerPushStorageSource.lossCheck (X86ProducerPushStorageSource.loopCont k)
        (allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) result.after) :=
    .step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  have checked := X86ProducerPushLossCheck.from_cache result (X86ProducerPushStorageSource.loopCont k)
  have finished := X86ProducerPushExitSource.finish_loop (allocation ready.after).1
    (X86ProducerPushLossCheck.temps (X86ProducerPushCachePrefix.temps metadata) ready.gprs.block) result.after X86ProducerPushStorageSource.body k
  exact ((first.trans sequence).trans checked).trans finished

/-- All remaining original PUSH loop exits reach the TRUE body Kcall before
any local deallocation. The entire complete post-store heap is identical. -/
theorem from_cache {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (result : X86ProducerPushCachePrefix.Result metadata) :
    InternalRun ge (14 + 2 * (X86ProducerPushExitSource.bodies ready.entry.block (X86ProducerPushPrefix.bodyCont ready) ready.after).length)
      (.State handler .Sskip (X86ProducerPushCacheExecute.following rsp (X86ProducerPushCachePrefix.control ready) metadata.after)
        (allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) result.after)
      (.State handler .Sskip (X86ProducerPushPrefix.bodyCont ready) (allocation ready.after).1
        (X86ProducerPushLossCheck.temps (X86ProducerPushCachePrefix.temps metadata) ready.gprs.block) result.after) := by
  have first := leave_storage result (X86ProducerPushCachePrefix.control ready)
  have stack := X86ProducerPushExitSource.finish_loop (allocation ready.after).1
    (X86ProducerPushLossCheck.temps (X86ProducerPushCachePrefix.temps metadata) ready.gprs.block) result.after
    X86ProducerPushStackSource.body (X86ProducerPushMetadataPrefix.control ready)
  have last := X86ProducerPushExitSource.finish (allocation ready.after).1
    (X86ProducerPushLossCheck.temps (X86ProducerPushCachePrefix.temps metadata) ready.gprs.block) result.after
    (X86ProducerPushExitSource.bodies ready.entry.block (X86ProducerPushPrefix.bodyCont ready) ready.after) (X86ProducerPushPrefix.bodyCont ready)
  rw [← X86ProducerPushExitSource.source] at last
  exact (first.trans stack).trans last

end KProgFormal.ClightRefinement.X86ProducerPushExit
