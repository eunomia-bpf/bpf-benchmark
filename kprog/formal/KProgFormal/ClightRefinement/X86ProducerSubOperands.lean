import KProgFormal.ClightRefinement.X86ProducerSubRhsSite

namespace KProgFormal.ClightRefinement.X86ProducerSubOperands
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
open X86ProducerSubRhsSite (resultName)

def save : CC.Stmt := .Sset X86_program_profile_bpf.___x86_l_rhs (.Etempvar resultName CC.tulong)

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory,`lhs].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing actual rhs return parameter"
      pure (Lean.mkFVar argument.fvarId)
    let cert ← Lean.Meta.mkAppM ``X86ProducerSubRhsSite.certificate arguments
    let continuation ← Lean.Meta.mkAppM ``X86ProducerSubRhsSite.Certificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf continuation)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "actual rhs assignment missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_rhs_following node.getAppArgs[1]!

theorem source (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    (X86ProducerSubRhsSite.certificate binding k memory lhs).continuation = .Kseq save (following binding k memory lhs) := rfl

def temps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : CC.TempEnv :=
  ((X86ProducerSubRhsSite.certificate binding k memory lhs).output.set resultName (.Vlong (32#64))).set
    X86_program_profile_bpf.___x86_l_rhs (.Vlong (32#64))

/-- Actual immediate helper return and original rhs assignment retain the
same full source heap and materialized left operand. -/
theorem resume (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    InternalRun ge 3
      (.Returnstate (.Vlong (32#64)) (CC.callCont (X86ProducerSubRhsSite.continuation binding k memory lhs)) (allocation memory).2)
      (.State handler .Sskip (following binding k memory lhs) (allocation memory).1
        (temps binding k memory lhs) (allocation memory).2) := by
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,X86ProducerSubRhsSite.continuation,
    CC.callCont,source,save,temps,CC.setOpttemp,CC.doEvalExpr,CC.PTree.gss,CC.Eapp,CC.E0,List.nil_append,true_and]

/-- Both actual operands derive original temporaries, without a lhs/rhs
result equality premise or a substitution of raw-offset arithmetic. -/
theorem operands (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    (temps binding k memory lhs).get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs) ∧
    (temps binding k memory lhs).get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong (32#64)) := by
  constructor <;> rfl

theorem from_lhs (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    InternalRun ge ((X86ProducerSubRhsSite.certificate binding k memory lhs).count+1+10+3)
      (X86ProducerSubRhsSite.start binding k memory lhs)
      (.State handler .Sskip (following binding k memory lhs) (allocation memory).1
        (temps binding k memory lhs) (allocation memory).2) :=
  (X86ProducerSubRhsSite.from_lhs binding k memory lhs).trans (resume binding k memory lhs)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- SAME original provider/PUSH/SUB trace now includes the actual immediate
helper call, sign-bit branch, return and rhs save after materialized RSP lhs. -/
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
  have actual := star_trans (X86ProducerSubLhs.execute complete header)
    (from_lhs ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64))).sound
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

end KProgFormal.ClightRefinement.X86ProducerSubOperands
