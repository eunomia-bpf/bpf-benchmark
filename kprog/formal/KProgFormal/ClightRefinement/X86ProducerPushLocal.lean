import KProgFormal.ClightRefinement.X86ProducerPushComplete

namespace KProgFormal.ClightRefinement.X86ProducerPushLocal
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)
open X86ProducerHeaderSource (producer)

/-- Functional original stores identify the SAME accepted RSP heap, rather
than constructing a second independent execution/result memory. -/
theorem rsp_run {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} (rsp : X86ProducerPushRspPrefix.Result ready) :
    InternalRun ge 13
      (.State handler .Sskip (X86ProducerPushReadReturn.following ready.entry.block (X86ProducerPushPrefix.bodyCont ready) ready.after)
        (allocation ready.after).1 (X86ProducerPushReadReturn.temps ready.entry.block (X86ProducerPushPrefix.bodyCont ready) ready.after (ready.values 3)) (allocation ready.after).2)
      (.State handler X86ProducerPushRspSource.stackLoop (X86ProducerPushMetadataPrefix.control ready)
        (allocation ready.after).1 (X86ProducerPushRspPrefix.temps ready) rsp.after) := by
  obtain ⟨after,run,stored,rest⟩ := X86ProducerPushRspExecute.from_ready ready (X86ProducerPushPrefix.bodyCont ready)
  have same : after = rsp.after := Option.some.inj (stored.symm.trans rsp.stored)
  subst after
  exact run

theorem metadata_run {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (metadata : X86ProducerPushMetadataPrefix.Result rsp) :
    ∃ n, InternalRun ge n
      (.State handler X86ProducerPushRspSource.stackLoop (X86ProducerPushMetadataPrefix.control ready)
        (allocation ready.after).1 (X86ProducerPushRspPrefix.temps ready) rsp.after)
      (.State handler X86ProducerPushStackSource.storage (X86ProducerPushCachePrefix.control ready)
        (allocation ready.after).1 (X86ProducerPushStorageSetup.initialTemps rsp) metadata.after) := by
  obtain ⟨middle,after,tagStored,pointerStored,run,rest⟩ := X86ProducerPushMetadataExecute.from_rsp rsp (X86ProducerPushMetadataPrefix.control ready)
  have sameMiddle : middle = metadata.middle := Option.some.inj (tagStored.symm.trans metadata.tag_stored)
  subst middle
  have same : after = metadata.after := Option.some.inj (pointerStored.symm.trans metadata.pointer_stored)
  subst after
  exact ⟨_,run⟩

theorem cache_run {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (cache : X86ProducerPushCachePrefix.Result metadata) :
    ∃ n, InternalRun ge n
      (.State handler X86ProducerPushStackSource.storage (X86ProducerPushCachePrefix.control ready)
        (allocation ready.after).1 (X86ProducerPushStorageSetup.initialTemps rsp) metadata.after)
      (.State handler .Sskip (X86ProducerPushCacheExecute.following rsp (X86ProducerPushCachePrefix.control ready) metadata.after)
        (allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) cache.after) := by
  obtain ⟨after,run,stored,rest⟩ := X86ProducerPushCacheExecute.from_metadata metadata (X86ProducerPushCachePrefix.control ready)
  have same : after = cache.after := Option.some.inj (stored.symm.trans cache.stored)
  subst after
  exact ⟨_,run⟩

/-- A true instruction-local silent path from the actual PUSH Scall through
its original wrapper/dispatcher/body and genuine stores/free/return, without
replaying initialization/input events or assuming a source execution. -/
theorem execute {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} {cache : X86ProducerPushCachePrefix.Result metadata}
    (complete : X86ProducerPushComplete.Result cache) :
    ∃ n, InternalRun ge n
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after)
      (.State producer X86ProducerContextSource.followingCalls outer (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after) := by
  have called := X86ProducerPushCall.call before ready.after ready.output outer ready.entry
  have width := X86ProducerPushWidth.from_call ready.after (X86ProducerPushPrefix.wrapperCont ready) ready.entry.block
  have selected := X86ProducerPushDispatch.executes ready.entry.block (X86ProducerPushPrefix.wrapperCont ready) ready.after
  have body := X86ProducerPushBody.call ready.entry.block (X86ProducerPushPrefix.wrapperCont ready) ready.after
  have entered := X86ProducerPushBody.entry ready.after (X86ProducerPushPrefix.bodyCont ready) ready.entry.block
  have read := X86ProducerPushReadReturn.from_body ready (X86ProducerPushPrefix.bodyCont ready)
  have sp := rsp_run rsp
  obtain ⟨nm,metaRun⟩ := metadata_run metadata
  obtain ⟨nc,cacheRun⟩ := cache_run cache
  obtain ⟨after,returned,freed,rest⟩ := X86ProducerPushReturn.from_cache cache
  have same : after = complete.after := Option.some.inj (freed.symm.trans complete.freed)
  subst after
  have dispatched := ((called.trans width).trans selected).trans body
  have loaded := (dispatched.trans entered).trans read
  have updated := (loaded.trans sp).trans metaRun
  exact ⟨_,(updated.trans cacheRun).trans returned⟩

theorem silent {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} {cache : X86ProducerPushCachePrefix.Result metadata}
    (complete : X86ProducerPushComplete.Result cache) :
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State producer X86ProducerContextSource.followingCalls outer (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after) := by
  obtain ⟨n,run⟩ := execute complete
  exact run.sound

end KProgFormal.ClightRefinement.X86ProducerPushLocal
