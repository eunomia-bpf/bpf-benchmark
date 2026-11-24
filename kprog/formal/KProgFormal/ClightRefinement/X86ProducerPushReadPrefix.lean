import KProgFormal.ClightRefinement.X86ProducerPushPrefix
import KProgFormal.ClightRefinement.X86ProducerPushReadReturn

namespace KProgFormal.ClightRefinement.X86ProducerPushReadPrefix
open X86ProducerHeaderSource (producer)
open X86ProducerLayout (ge)
open X86ProducerPushPrefix (bodyCont)

/-- The SAME full producer reaches the actual saved RBX PUSH operand,
including original entry, every input/setup/header statement, actual PUSH
wrapper/dispatch/allocation and every register-mode guard. This is a nested
reader return and operand assignment, not completion of PUSH or of the producer. -/
theorem from_ready {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) :
    CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] k before) ready.trace
      (.State X86ProducerPushBody.handler .Sskip
        (X86ProducerPushReadReturn.following ready.entry.block (bodyCont ready) ready.after)
        (X86ProducerPushBody.allocation ready.after).1
        (X86ProducerPushReadReturn.temps ready.entry.block (bodyCont ready) ready.after (ready.values 3))
        (X86ProducerPushBody.allocation ready.after).2) := by
  have read := X86ProducerPushReadReturn.from_body ready (bodyCont ready)
  simpa only [CC.E0, CC.Eapp, List.append_nil] using
    star_trans (X86ProducerPushPrefix.from_ready ready) read.sound

/-- Current resources accompany the SAME original traced source execution;
only the already explicit kind6/kind1 platform input premises remain. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (k : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k,
    CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] k before) ready.trace
      (.State X86ProducerPushBody.handler .Sskip
        (X86ProducerPushReadReturn.following ready.entry.block (bodyCont ready) ready.after)
        (X86ProducerPushBody.allocation ready.after).1
        (X86ProducerPushReadReturn.temps ready.entry.block (bodyCont ready) ready.after (ready.values 3))
        (X86ProducerPushBody.allocation ready.after).2) ∧
    FrameBelow ready.after.nextblock ready.after (X86ProducerPushBody.allocation ready.after).2 ∧
    X86ReleaseProvider.View (X86ProducerPushBody.allocation ready.after).2 ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View (X86ProducerPushBody.allocation ready.after).2 ready.entry.block
      (X86ProducerHeaderViews.ghosts ready.sources) := by
  obtain ⟨ready⟩ := X86ProducerEntryReady.from_call before ctxBlock ctxOffset k inputs6 inputs1
  have views := X86ProducerPushResources.views ready
  exact ⟨ready, from_ready ready, (X86ProducerPushBody.entry_frame ready.after).2, views.1, views.2.1⟩

end KProgFormal.ClightRefinement.X86ProducerPushReadPrefix
