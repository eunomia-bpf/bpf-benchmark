import KProgFormal.ClightRefinement.X86ProducerSubOldCf

namespace KProgFormal.ClightRefinement.X86ProducerSubCfPrefix
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)

/-- Actual oldCF save preserves both operands and the physical SUB result. -/
theorem observations (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    let current := X86ProducerSubOldCf.temps binding k memory lhs cfBlock (X86ProducerScalarValue.value 0 word)
    current.get X86_program_profile_bpf.___x86_l_old_cf = some (X86ProducerScalarValue.value 0 word) ∧
    current.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs) ∧
    current.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong (32#64)) ∧
    current.get X86_program_profile_bpf.___x86_l_result = some (.Vlong (lhs-(32#64))) := by
  constructor
  · exact CC.PTree.gss _ _ _
  · constructor
    · rfl
    · constructor <;> rfl

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- SAME original provider/PUSH/SUB prefix now includes the unconditional
oldCF header/byte read, intermediate temporary, real cast and save before
flag selection. Whole current heap/trace/source continuations are retained. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    CC.Star (CC.Step2 ge)
      (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State handler .Sskip
        (X86ProducerSubOldCf.following ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64)))
        (allocation complete.after).1
        (X86ProducerSubOldCf.temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
          (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (X86ProducerScalarValue.value 0 (ready.scalarValues 0)))
        (allocation complete.after).2) := by
  have actual := star_trans (X86ProducerSubResult.execute complete header)
    (X86ProducerSubOldCf.from_result complete header (X86ProducerSubLhs.bodyCont complete)).sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
      X86ProducerEntryReady.HeaderReads ready ∧
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler .Sskip
          (X86ProducerSubOldCf.following ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64)))
          (allocation complete.after).1
          (X86ProducerSubOldCf.temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
            (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (X86ProducerScalarValue.value 0 (ready.scalarValues 0)))
          (allocation complete.after).2) := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  refine ⟨ready,rsp,metadata,cache,complete,header,?_⟩
  have actual := star_trans ready.run (execute complete header)
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubCfPrefix
