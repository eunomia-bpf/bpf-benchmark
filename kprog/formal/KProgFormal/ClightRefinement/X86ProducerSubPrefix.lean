import KProgFormal.ClightRefinement.X86ProducerSubEntry
import KProgFormal.ClightRefinement.X86ProducerSubDispatch

namespace KProgFormal.ClightRefinement.X86ProducerSubPrefix
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)
open X86ProducerCacheAllocation (allocation)

/-- SAME complete first PUSH followed by original next-call sequencing,
real SUB wrapper entry/effective-width helper/return and every reached
original dispatcher guard. The ALU_IMM handler call is the genuine endpoint,
with its real continuation, current complete heap and all source temporaries.
Actual handler allocation/arithmetic/writeback remain separate work. -/
theorem execute {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache) :
    let caller := X86ProducerSubCall.continuation (allocation ge.genv_cenv before).1 ready.output outer
    let selected := X86ProducerSubDispatch.certificate ready.entry.block caller complete.after
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State X86ProducerSubCall.handler X86ProducerSubDispatch.targetCall selected.continuation
        CC.emptyEnv selected.output complete.after) := by
  dsimp only
  let caller := X86ProducerSubCall.continuation (allocation ge.genv_cenv before).1 ready.output outer
  have called := X86ProducerSubEntry.call before complete.after ready.output outer ready.entry
  have width := X86ProducerSubWidth.from_call complete.after caller ready.entry.block
  have selected := X86ProducerSubDispatch.executes ready.entry.block caller complete.after
  have traversed := (called.trans width).trans selected
  have actual := star_trans (X86ProducerPushLocal.silent complete) traversed.sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

end KProgFormal.ClightRefinement.X86ProducerSubPrefix
