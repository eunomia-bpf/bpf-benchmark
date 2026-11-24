import KProgFormal.ClightRefinement.X86ProducerPushResources
import KProgFormal.ClightRefinement.X86RegisterReadScalar

namespace KProgFormal.ClightRefinement.X86ProducerPushReadValue
open X86ProducerLayout (ge)

theorem layout : X86RegisterReadValue.Layout ge :=
  ⟨X86ProducerLayout.layouts.1, X86ProducerGprLayout.source_layouts.2.1,
    X86ProducerGprLayout.source_layouts.2.2⟩

/-- The actual initialized RBX scalar is returned by the complete original
reader after the true PUSH local allocation. Its header, word and tag loads
all derive from the SAME producer entry result, not independent premises. -/
theorem call {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) :
    InternalRun ge (X86RegisterReadScalar.length .q)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        [.Vptr ready.entry.block 0, .Vlong (3#64), .Vlong (8#64), .Vlong 0] k
        (X86ProducerPushBody.allocation ready.after).2)
      (.Returnstate (.Vlong (ready.values 3)) (CC.callCont k)
        (X86ProducerPushBody.allocation ready.after).2) := by
  have current := (X86ProducerPushResources.observations ready).1 3 (by decide +kernel)
  have cells := (X86ProducerPushResources.views ready).2.2.1
  have read := X86RegisterReadScalar.call ge layout (X86ProducerPushBody.allocation ready.after).2 k
    3 8 0 0 .q (ready.values 3) X86ProducerPushWidth.widthBlock ready.entry.block ready.gprs.block 0 0
    (by decide +kernel) (by decide +kernel) (by decide +kernel) (by rfl)
    X86ProducerPushWidth.width_binding cells current.1 current.2
  have args : X86AluReadSite.arguments (.Vptr ready.entry.block 0)
      (X86RegisterReadValue.registerByte 3) 8 0 =
      [.Vptr ready.entry.block 0, .Vlong (3#64), .Vlong (8#64), .Vlong 0] := rfl
  rw [args] at read
  simpa [X86RegisterReadLanes.result, X86.Value.trunc_q] using read

end KProgFormal.ClightRefinement.X86ProducerPushReadValue
