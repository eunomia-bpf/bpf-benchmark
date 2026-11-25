import KProgFormal.ClightRefinement.X86ProducerSubResultSite
import KProgFormal.ClightRefinement.X86ProducerSubOperands

namespace KProgFormal.ClightRefinement.X86ProducerSubResult
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
open X86ProducerSubResultSite (resultName)

def save : CC.Stmt := .Sset X86_program_profile_bpf.___x86_l_result (.Etempvar resultName CC.tulong)

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory,`lhs].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing actual result return parameter"
      pure (Lean.mkFVar argument.fvarId)
    let cert ← Lean.Meta.mkAppM ``X86ProducerSubResultSite.certificate arguments
    let continuation ← Lean.Meta.mkAppM ``X86ProducerSubResultSite.Certificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf continuation)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "actual result assignment missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_result_following node.getAppArgs[1]!

theorem source (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    (X86ProducerSubResultSite.certificate binding k memory lhs).continuation = .Kseq save (following binding k memory lhs) := rfl

def temps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : CC.TempEnv :=
  ((X86ProducerSubResultSite.certificate binding k memory lhs).output.set resultName (.Vlong (lhs-(32#64)))).set
    X86_program_profile_bpf.___x86_l_result (.Vlong (lhs-(32#64)))

/-- Actual arithmetic helper return and original result assignment retain the
same full source heap and materialized left operand. -/
theorem resume (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    InternalRun ge 3
      (.Returnstate (.Vlong (lhs-(32#64))) (CC.callCont (X86ProducerSubResultSite.continuation binding k memory lhs)) (allocation memory).2)
      (.State handler .Sskip (following binding k memory lhs) (allocation memory).1
        (temps binding k memory lhs) (allocation memory).2) := by
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,X86ProducerSubResultSite.continuation,
    CC.callCont,source,save,temps,CC.setOpttemp,CC.doEvalExpr,CC.PTree.gss,CC.Eapp,CC.E0,List.nil_append,true_and]

/-- Both actual operands derive original temporaries, without a lhs/rhs
result equality premise or a substitution of raw-offset arithmetic. -/
theorem inputs (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    (temps binding k memory lhs).get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs) ∧
    (temps binding k memory lhs).get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong (32#64)) := by
  constructor <;> rfl

/-- Actual wrapping arithmetic result is saved in its original temporary. -/
theorem saved (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    (temps binding k memory lhs).get X86_program_profile_bpf.___x86_l_result = some (.Vlong (lhs-(32#64))) := CC.PTree.gss _ _ _

theorem from_operands (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    InternalRun ge ((X86ProducerSubResultSite.certificate binding k memory lhs).count+1+20+3)
      (X86ProducerSubResultSite.start binding k memory lhs)
      (.State handler .Sskip (following binding k memory lhs) (allocation memory).1
        (temps binding k memory lhs) (allocation memory).2) :=
  (X86ProducerSubResultSite.from_operands binding k memory lhs).trans (resume binding k memory lhs)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- SAME original provider/PUSH/SUB trace now includes the actual ordinary SUB
selector, arithmetic helper call, return and actual result save after materialized RSP lhs. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    CC.Star (CC.Step2 ge)
      (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State handler .Sskip
        (following ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64)))
        (allocation complete.after).1
        (temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64)))
        (allocation complete.after).2) := by
  have actual := star_trans (X86ProducerSubOperands.execute complete header)
    (from_operands ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64))).sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
      X86ProducerEntryReady.HeaderReads ready ∧
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler .Sskip
          (following ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64)))
          (allocation complete.after).1
          (temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64)))
          (allocation complete.after).2) := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  refine ⟨ready,rsp,metadata,cache,complete,header,?_⟩
  have actual := star_trans ready.run (execute complete header)
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubResult
