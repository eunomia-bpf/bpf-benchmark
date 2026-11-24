import KProgFormal.ClightRefinement.X86ProducerPushExit
import KProgFormal.ClightRefinement.X86ProducerPushDeallocate

namespace KProgFormal.ClightRefinement.X86ProducerPushReturn
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)
open X86ProducerHeaderSource (producer)

def finalTemps {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (metadata : X86ProducerPushMetadataPrefix.Result rsp) : CC.TempEnv :=
  X86ProducerPushLossCheck.temps (X86ProducerPushCachePrefix.temps metadata) ready.gprs.block

/-- Real body free/fallthrough, wrapper resumption/loop break/empty-frame
return, producer resumption and true next source sequence all execute. -/
theorem resume {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (le : CC.TempEnv) (memory after : CC.Mem)
    (freed : CC.Mem.freeList memory (CC.blocksOfEnv ge.genv_cenv (allocation ready.after).1) = some after) :
    InternalRun ge 7 (.State handler .Sskip (X86ProducerPushPrefix.bodyCont ready) (allocation ready.after).1 le memory)
      (.State producer X86ProducerContextSource.followingCalls outer (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output after) := by
  have empty : CC.blocksOfEnv ge.genv_cenv CC.emptyEnv = [] := rfl
  have caller := X86ProducerPushDispatch.source_continuation ready.entry.block (X86ProducerPushPrefix.wrapperCont ready) ready.after
  dsimp only [X86ProducerPushPrefix.wrapperCont, X86ProducerPushCall.continuation, X86ProducerPushWidth.loopCont] at caller
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep,
    X86ProducerPushPrefix.bodyCont, X86ProducerPushBody.continuation, caller, X86ProducerPushWidth.loopCont,
    X86ProducerPushPrefix.wrapperCont, X86ProducerPushCall.continuation, CC.setOpttemp,
    freed, empty, CC.Mem.freeList, CC.E0, CC.Eapp, List.nil_append, true_and]

/-- SAME actual post-cache heap reaches original caller code through every
exit and genuine local deallocation. No successful-free/return premise is
added; the complete original allocation and actual access maps derive it. -/
theorem from_cache {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp} (result : X86ProducerPushCachePrefix.Result metadata) :
    ∃ after, InternalRun ge (14 + 2 * (X86ProducerPushExitSource.bodies ready.entry.block (X86ProducerPushPrefix.bodyCont ready) ready.after).length + 7)
      (.State handler .Sskip (X86ProducerPushCacheExecute.following rsp (X86ProducerPushCachePrefix.control ready) metadata.after)
        (allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) result.after)
      (.State producer X86ProducerContextSource.followingCalls outer (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output after) ∧
    CC.Mem.freeList result.after (CC.blocksOfEnv ge.genv_cenv (allocation ready.after).1) = some after ∧
    FrameBelow ready.after.nextblock result.after after ∧ after.contents = result.after.contents ∧ after.nextblock = result.after.nextblock ∧
    (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (allocation ready.after).1, ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
      ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  obtain ⟨after,freed,frame,contents,frontier,released⟩ := X86ProducerPushDeallocate.execute result
  exact ⟨after,(X86ProducerPushExit.from_cache result).trans (resume ready _ result.after after freed),freed,frame,contents,frontier,released⟩

end KProgFormal.ClightRefinement.X86ProducerPushReturn
