import KProgFormal.ClightRefinement.X86ProducerSubCall
import KProgFormal.ClightRefinement.X86ProducerPushLocal

namespace KProgFormal.ClightRefinement.X86ProducerSubEntry
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)
open X86ProducerCacheAllocation (allocation)
open X86ProducerSubCall (handler values followingCalls continuation initialTemps)

/-- Execute the original sequence, label1 and actual six-argument call,
retaining every unconsumed statement, local and temporary on the same heap. -/
theorem call (before memory : CC.Mem) (le : CC.TempEnv) (outer : CC.Cont)
    (entry : X86ProducerHeaderLocals.HeaderLocal ge.genv_cenv before) :
    InternalRun ge 3
      (.State producer X86ProducerContextSource.followingCalls outer (allocation ge.genv_cenv before).1 le memory)
      (.Callstate (.Internal handler) (values entry.block)
        (continuation (allocation ge.genv_cenv before).1 le outer) memory) := by
  have entered : InternalRun ge 2
      (.State producer X86ProducerContextSource.followingCalls outer (allocation ge.genv_cenv before).1 le memory)
      (.State producer X86ProducerSubCall.callStmt (.Kseq followingCalls outer) (allocation ge.genv_cenv before).1 le memory) := by
    rw [X86ProducerSubCall.source_site]
    exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))
  exact entered.trans (X86ProducerSubCall.call before memory le outer entry)

/-- SAME complete original PUSH executes into the actual next SUB wrapper
body. Its exact current heap and complete caller continuation are retained;
this theorem does not assume or claim SUB dispatch, arithmetic or writeback. -/
theorem execute {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache) :
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State handler handler.fn_body
        (continuation (allocation ge.genv_cenv before).1 ready.output outer)
        CC.emptyEnv (initialTemps ready.entry.block) complete.after) := by
  have next := call before complete.after ready.output outer ready.entry
  have body := next.trans (X86ProducerSubCall.entry complete.after _ ready.entry.block)
  have actual := star_trans (X86ProducerPushLocal.silent complete) body.sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

end KProgFormal.ClightRefinement.X86ProducerSubEntry
