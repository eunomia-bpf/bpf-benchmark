import KProgFormal.ClightRefinement.X86ProducerSubFlagRoute

namespace KProgFormal.ClightRefinement.X86ProducerSubFlagWidth
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
open X86ProducerSubFlagRoute (certificate widthCall)

def continuation (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) : CC.Cont :=
  .Kcall (some X86ProducerSubFlagRoute.resultName) handler (allocation memory).1
    (certificate binding k memory lhs cfBlock word).output (certificate binding k memory lhs cfBlock word).continuation

def temps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) : CC.TempEnv :=
  (certificate binding k memory lhs cfBlock word).output.set X86ProducerSubFlagRoute.resultName (.Vint (8#32))

/-- Actual selected SUB flag-width call/complete original helper/real caller
return, retaining the current whole heap and all original source frames. -/
theorem invoke (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    InternalRun ge 8
      (.State handler widthCall (certificate binding k memory lhs cfBlock word).continuation (allocation memory).1
        (certificate binding k memory lhs cfBlock word).output (allocation memory).2)
      (.State handler .Sskip (certificate binding k memory lhs cfBlock word).continuation (allocation memory).1
        (temps binding k memory lhs cfBlock word) (allocation memory).2) := by
  have absent : (allocation memory).1.get X86_program_profile_bpf._x86_width_effective = none := rfl
  have function : CC.doEvalExpr ge (allocation memory).1 (certificate binding k memory lhs cfBlock word).output
      (allocation memory).2 X86ProducerSubFlagRoute.expression = some (.Vptr X86ProducerPushWidth.widthBlock 0) := by
    simp only [X86ProducerSubFlagRoute.expression,CC.doEvalExpr,CC.lvalOfVar,absent,
      X86ProducerPushWidth.width_binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  have called : InternalRun ge 1
      (.State handler widthCall (certificate binding k memory lhs cfBlock word).continuation (allocation memory).1
        (certificate binding k memory lhs cfBlock word).output (allocation memory).2)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)]
        (continuation binding k memory lhs cfBlock word) (allocation memory).2) := by
    rw [X86ProducerSubFlagRoute.source_call]
    refine .step trivial ?_ (.refl _)
    apply CC.Step.call (tyargs := [CC.tuchar]) (tyres := CC.tuchar) (cconv := CC.cc_default)
      (vf := .Vptr X86ProducerPushWidth.widthBlock 0)
    · rfl
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (X86ProducerSubFlagRoute.arguments binding k memory lhs cfBlock word)
    · have zero : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
      simpa only [CC.Genv.findFunct,zero,ite_true] using X86ProducerPushWidth.width_binding.2
    · rfl
  have helper : InternalRun ge 6
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)]
        (continuation binding k memory lhs cfBlock word) (allocation memory).2)
      (.Returnstate (.Vint (8#32)) (continuation binding k memory lhs cfBlock word) (allocation memory).2) :=
    X86Width.internal ge (8#8) (continuation binding k memory lhs cfBlock word) (allocation memory).2
  have returned : InternalRun ge 1
      (.Returnstate (.Vint (8#32)) (continuation binding k memory lhs cfBlock word) (allocation memory).2)
      (.State handler .Sskip (certificate binding k memory lhs cfBlock word).continuation (allocation memory).1
        (temps binding k memory lhs cfBlock word) (allocation memory).2) :=
    .step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  exact (called.trans helper).trans returned

theorem from_old_cf (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    InternalRun ge ((certificate binding k memory lhs cfBlock word).count+8)
      (X86ProducerSubFlagRoute.start binding k memory lhs cfBlock word)
      (.State handler .Sskip (certificate binding k memory lhs cfBlock word).continuation (allocation memory).1
        (temps binding k memory lhs cfBlock word) (allocation memory).2) :=
  (X86ProducerSubFlagRoute.executes binding k memory lhs cfBlock word).trans (invoke binding k memory lhs cfBlock word)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- SAME original provider/PUSH/SUB prefix now includes actual oldCF reads,
all reached flag-arm guards/switch/SUB loop and genuine width helper return.
The real width cast and later SUB flag stores remain unconsumed source. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    let selected := certificate ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0)
    CC.Star (CC.Step2 ge)
      (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State handler .Sskip selected.continuation (allocation complete.after).1
        (temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
          (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0)) (allocation complete.after).2) := by
  have actual := star_trans (X86ProducerSubCfPrefix.execute complete header)
    (from_old_cf ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0)).sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

/-- Unchanged original kind6/kind1 inputs construct the whole traced
prefix and derived packet at the real selected SUB width return. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
      X86ProducerEntryReady.HeaderReads ready ∧
      let selected := certificate ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
        (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0)
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler .Sskip selected.continuation (allocation complete.after).1
          (temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
            (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0)) (allocation complete.after).2) := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  refine ⟨ready,rsp,metadata,cache,complete,header,?_⟩
  have actual := star_trans ready.run (execute complete header)
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubFlagWidth
