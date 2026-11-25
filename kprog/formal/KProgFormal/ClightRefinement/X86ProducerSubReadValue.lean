import KProgFormal.ClightRefinement.X86ProducerSubResources
import KProgFormal.ClightRefinement.X86RegisterReadRspCall

namespace KProgFormal.ClightRefinement.X86ProducerSubReadValue
open X86ProducerLayout (ge)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Read the actual materialized native RSP after genuine SUB local allocation.
Both header pointers, raw offset and native base are derived from the SAME
initializer and genuine source frames. The helper leaves the full heap alone. -/
theorem call (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) (k : CC.Cont) :
    InternalRun ge (X86RegisterReadRspCall.length .q)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        [.Vptr ready.entry.block 0,.Vlong (4#64),.Vlong (8#64),.Vlong 0] k (X86ProducerSubBody.allocation complete.after).2)
      (.Returnstate (.Vlong (ready.stackOutcome.value - (8#64))) (CC.callCont k) (X86ProducerSubBody.allocation complete.after).2) := by
  obtain ⟨cells,base,native,current⟩ := X86ProducerSubResources.current complete header
  have read := X86RegisterReadRspCall.call ge X86ProducerPushReadValue.layout
    X86ProducerLayout.layouts.2.1 (X86ProducerSubBody.allocation complete.after).2 k 8 0 .q
    X86ProducerPushRspStore.nextRsp ready.stackOutcome.value
    X86ProducerPushWidth.widthBlock ready.entry.block ready.gprs.block ready.base.block 0 0
    (by decide +kernel) rfl X86ProducerPushWidth.width_binding cells current base native
  have materialized : X86ProducerPushRspStore.nextRsp + ready.stackOutcome.value =
      ready.stackOutcome.value - (8#64) := by
    change -(8#64) + ready.stackOutcome.value = _
    rw [BitVec.add_comm,BitVec.sub_eq_add_neg]
  have args : X86AluReadSite.arguments (.Vptr ready.entry.block 0) (4#8) 8 0 =
      [.Vptr ready.entry.block 0,.Vlong (4#64),.Vlong (8#64),.Vlong 0] := rfl
  rw [args] at read
  simpa [X86RegisterReadLanes.result,X86.Value.trunc_q,materialized] using read

end KProgFormal.ClightRefinement.X86ProducerSubReadValue
