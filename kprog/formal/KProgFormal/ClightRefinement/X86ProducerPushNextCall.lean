import KProgFormal.ClightRefinement.X86ProducerPushDecode

namespace KProgFormal.ClightRefinement.X86ProducerPushNextCall
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)

/-- Real sequencing and label1 transitions enter the next original call.
No label, continuation, memory or source temporary is erased. -/
theorem enter (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (outer : CC.Cont) :
    ∃ call tail, X86ProducerContextSource.followingCalls = .Ssequence (.Slabel X86_program_profile_bpf._x86_l_1 call) tail ∧
      InternalRun ge 2 (.State producer X86ProducerContextSource.followingCalls outer e le memory)
        (.State producer call (.Kseq tail outer) e le memory) := by
  obtain ⟨call,tail,original⟩ := X86ProducerPushDecode.source_successor
  refine ⟨call,tail,original,?_⟩
  rw [original]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))

/-- The SAME actual PUSH instruction-local source run reaches the genuine
next caller statement, with its original continuation and final heap. -/
theorem execute {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache) :
    ∃ call tail, X86ProducerContextSource.followingCalls = .Ssequence (.Slabel X86_program_profile_bpf._x86_l_1 call) tail ∧
      CC.Star (CC.Step2 ge)
        (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
          (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
        (.State producer call (.Kseq tail outer) (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1
          ready.output complete.after) := by
  obtain ⟨call,tail,original,entered⟩ := enter (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after outer
  refine ⟨call,tail,original,?_⟩
  have run := star_trans (X86ProducerPushLocal.silent complete) entered.sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using run

end KProgFormal.ClightRefinement.X86ProducerPushNextCall
