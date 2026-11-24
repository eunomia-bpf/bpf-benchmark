import KProgFormal.ClightRefinement.X86ProducerPushResources

namespace KProgFormal.ClightRefinement.X86ProducerPushPrefix
open X86ProducerHeaderSource (producer)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def wrapperCont {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) : CC.Cont :=
  X86ProducerPushCall.continuation (allocation ge.genv_cenv before).1 ready.output k

def bodyCont {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) : CC.Cont :=
  X86ProducerPushBody.continuation ready.entry.block (wrapperCont ready) ready.after

/-- The SAME whole initialized producer enters the original PUSH body through
real argument evaluation, wrapper entry, effective-width helper, every actual
dispatch guard, callee lookup and three-local allocation. Its actual prior
input trace is retained and all new transitions are internal. -/
theorem from_ready {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) :
    CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] k before) ready.trace
      (.State X86ProducerPushBody.handler X86ProducerPushBody.handler.fn_body (bodyCont ready)
        (X86ProducerPushBody.allocation ready.after).1 (X86ProducerPushBody.initialTemps ready.entry.block)
        (X86ProducerPushBody.allocation ready.after).2) := by
  have first := X86ProducerPushCall.call before ready.after ready.output k ready.entry
  have width := X86ProducerPushWidth.from_call ready.after (wrapperCont ready) ready.entry.block
  have selected := X86ProducerPushDispatch.executes ready.entry.block (wrapperCont ready) ready.after
  have called := X86ProducerPushBody.call ready.entry.block (wrapperCont ready) ready.after
  have entered := X86ProducerPushBody.entry ready.after (bodyCont ready) ready.entry.block
  have run := first.trans (width.trans (selected.trans (called.trans entered)))
  simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans ready.run run.sound

/-- Full actual entry supplies current body resources, with only the already
explicit kind6/kind1 platform premises; no source run, post-allocation View,
callee binding or independent permission premise is assumed. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (k : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k,
    CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] k before) ready.trace
      (.State X86ProducerPushBody.handler X86ProducerPushBody.handler.fn_body (bodyCont ready)
        (X86ProducerPushBody.allocation ready.after).1 (X86ProducerPushBody.initialTemps ready.entry.block)
        (X86ProducerPushBody.allocation ready.after).2) ∧
    FrameBelow ready.after.nextblock ready.after (X86ProducerPushBody.allocation ready.after).2 ∧
    X86ReleaseProvider.View (X86ProducerPushBody.allocation ready.after).2 ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View (X86ProducerPushBody.allocation ready.after).2 ready.entry.block
      (X86ProducerHeaderViews.ghosts ready.sources) := by
  obtain ⟨ready⟩ := X86ProducerEntryReady.from_call before ctxBlock ctxOffset k inputs6 inputs1
  have views := X86ProducerPushResources.views ready
  exact ⟨ready, from_ready ready, (X86ProducerPushBody.entry_frame ready.after).2, views.1, views.2.1⟩

end KProgFormal.ClightRefinement.X86ProducerPushPrefix
