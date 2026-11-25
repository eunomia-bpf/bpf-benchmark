import KProgFormal.ClightRefinement.X86ProducerSubPrefix
import KProgFormal.ClightRefinement.X86ProducerSubResources

namespace KProgFormal.ClightRefinement.X86ProducerSubAllocated
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)

def caller {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) : CC.Cont :=
  X86ProducerSubCall.continuation (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output outer

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- SAME complete original PUSH, real SUB wrapper and dispatch call compose
through genuine ALU_IMM entry and all its actual local allocations. -/
theorem execute (complete : X86ProducerPushComplete.Result cache) :
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State X86ProducerSubBody.handler X86ProducerSubBody.handler.fn_body
        (X86ProducerSubBody.continuation ready.entry.block (caller ready) complete.after)
        (X86ProducerSubBody.allocation complete.after).1 (X86ProducerSubBody.initialTemps ready.entry.block)
        (X86ProducerSubBody.allocation complete.after).2) := by
  have selected := X86ProducerSubPrefix.execute complete
  have entered := (X86ProducerSubBody.call ready.entry.block (caller ready) complete.after).trans
    (X86ProducerSubBody.entry complete.after _ ready.entry.block)
  have actual := star_trans selected entered.sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

/-- Original input ABIs construct every prior prefix and genuine current
SUB allocation. The header packet is derived, not a new input premise. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
      X86ProducerEntryReady.HeaderReads ready ∧
      CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State X86ProducerSubBody.handler X86ProducerSubBody.handler.fn_body
          (X86ProducerSubBody.continuation ready.entry.block (caller ready) complete.after)
          (X86ProducerSubBody.allocation complete.after).1 (X86ProducerSubBody.initialTemps ready.entry.block)
          (X86ProducerSubBody.allocation complete.after).2) := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  refine ⟨ready,rsp,metadata,cache,complete,header,?_⟩
  have actual := star_trans ready.run (execute complete)
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubAllocated
