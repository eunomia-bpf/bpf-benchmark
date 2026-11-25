import KProgFormal.ClightRefinement.X86ProducerSubReadSite
import KProgFormal.ClightRefinement.X86ProducerSubAllocated

namespace KProgFormal.ClightRefinement.X86ProducerSubLhs
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
open X86ProducerSubReadSite (resultName)

def save : CC.Stmt := .Sset X86_program_profile_bpf.___x86_l_lhs (.Etempvar resultName CC.tulong)

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing real SUB reader return parameter"
      pure (Lean.mkFVar argument.fvarId)
    let cert ← Lean.Meta.mkAppM ``X86ProducerSubReadSite.certificate arguments
    let continuation ← Lean.Meta.mkAppM ``X86ProducerSubReadSite.Certificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf continuation)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original RSP reader return assignment missing"
    Lean.Elab.Tactic.closeMainGoal `original_sub_lhs_following node.getAppArgs[1]!

theorem source (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    (X86ProducerSubReadSite.certificate binding k memory).continuation = .Kseq save (following binding k memory) := rfl

def temps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (value : BitVec 64) : CC.TempEnv :=
  ((X86ProducerSubReadSite.certificate binding k memory).output.set resultName (.Vlong value)).set
    X86_program_profile_bpf.___x86_l_lhs (.Vlong value)

/-- Genuine nested reader return and original lhs assignment retain the
complete allocated heap and its exact source continuation. -/
theorem resume (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (value : BitVec 64) :
    InternalRun ge 3
      (.Returnstate (.Vlong value) (CC.callCont (X86ProducerSubReadSite.continuation binding k memory)) (allocation memory).2)
      (.State handler .Sskip (following binding k memory) (allocation memory).1
        (temps binding k memory value) (allocation memory).2) := by
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,X86ProducerSubReadSite.continuation,
    CC.callCont,source,save,temps,CC.setOpttemp,CC.doEvalExpr,CC.PTree.gss,CC.Eapp,CC.E0,List.nil_append,true_and]

theorem saved (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (value : BitVec 64) :
    (temps binding k memory value).get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong value) := CC.PTree.gss _ _ _

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

theorem from_body (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) (k : CC.Cont) :
    InternalRun ge ((X86ProducerSubSetup.certificate ready.entry.block k complete.after).count + 8 +
      (X86ProducerSubReadSite.certificate ready.entry.block k complete.after).count + 1 + X86RegisterReadRspCall.length .q + 3)
      (X86ProducerSubSetup.start ready.entry.block k complete.after)
      (.State handler .Sskip (following ready.entry.block k complete.after) (allocation complete.after).1
        (temps ready.entry.block k complete.after (ready.stackOutcome.value-(8#64))) (allocation complete.after).2) :=
  (X86ProducerSubReadSite.from_body complete header k).trans
    (resume ready.entry.block k complete.after (ready.stackOutcome.value-(8#64)))

def bodyCont (complete : X86ProducerPushComplete.Result cache) : CC.Cont :=
  X86ProducerSubBody.continuation ready.entry.block (X86ProducerSubAllocated.caller ready) complete.after

/-- SAME original first PUSH through actual SUB allocation/width/aux decode,
real RSP read and lhs save. The physical lhs is actual kind1base-minus8,
not raw offset-minus8; every source read and call is included. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    CC.Star (CC.Step2 ge)
      (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State handler .Sskip (following ready.entry.block (bodyCont complete) complete.after) (allocation complete.after).1
        (temps ready.entry.block (bodyCont complete) complete.after (ready.stackOutcome.value-(8#64))) (allocation complete.after).2) := by
  have actual := star_trans (X86ProducerSubAllocated.execute complete) (from_body complete header (bodyCont complete)).sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

/-- No saved-lhs/header/post-store source run is a premise: the original
kind6/kind1 inputs construct the SAME complete source execution and packet. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
      X86ProducerEntryReady.HeaderReads ready ∧
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler .Sskip (following ready.entry.block (bodyCont complete) complete.after) (allocation complete.after).1
          (temps ready.entry.block (bodyCont complete) complete.after (ready.stackOutcome.value-(8#64))) (allocation complete.after).2) := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  refine ⟨ready,rsp,metadata,cache,complete,header,?_⟩
  have actual := star_trans ready.run (execute complete header)
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubLhs
