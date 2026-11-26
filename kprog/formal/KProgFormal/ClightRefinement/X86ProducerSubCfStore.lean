import KProgFormal.ClightRefinement.X86ProducerSubCfSource
import KProgFormal.ClightRefinement.X86ProducerSubFlagStorage
import KProgFormal.ClightRefinement.X86SubFlagValues

namespace KProgFormal.ClightRefinement.X86ProducerSubCfStore
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
open X86ProducerSubCfSource (pointerLoad pointerTemp pointerExpr certificate)

def assignment : CC.Stmt := by
  run_tac do
    let cert ← Lean.Elab.Term.elabTerm (← `(certificate CC.Positive.xH .Kstop CC.Mem.empty (0#64) CC.Positive.xH (0#64))) none
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubCfSource.Certificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf cont)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "actual SUB CF store missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_cf_assignment node.getAppArgs[0]!

def targetExpr : CC.Expr := .Ederef (.Etempvar pointerTemp (CC.tptr CC.tuchar)) CC.tuchar
def valueExpr : CC.Expr := .Ebinop .Olt
  (.Etempvar X86_program_profile_bpf.___x86_sub_a__1 CC.tulong)
  (.Etempvar X86_program_profile_bpf.___x86_sub_b__1 CC.tulong) CC.tint

theorem source_store : assignment = .Sassign targetExpr valueExpr := rfl

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory,`lhs,`cfBlock,`word].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing actual CF parameter"
      pure (Lean.mkFVar argument.fvarId)
    let cert ← Lean.Meta.mkAppM ``certificate arguments
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubCfSource.Certificate.continuation #[cert]
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf cont)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "actual SUB CF continuation missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_cf_following node.getAppArgs[1]!

theorem source_following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    (certificate binding k memory lhs cfBlock word).continuation =
      .Kseq assignment (following binding k memory lhs cfBlock word) := rfl

def bit (lhs rhs : BitVec 64) : CC.Val := .Vint (if decide (lhs.toNat < rhs.toNat) then 1 else 0)

private theorem cf_address (world : CC.CGenv)
    (bindingsLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (block : CC.Block) :
    CC.lvalOfField world X86ProducerHeaderSource.headerType X86_program_profile_bpf._cf (.Vptr block 0) = some (block,120,.Full) := by
  change CC.lvalOfField world (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) _ _ = _
  simp only [CC.lvalOfField,bindingsLayout,X86ShiftLeftCarry.cf_offset world.genv_cenv valueLayout]
  rfl

private theorem evaluate_comparison (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (lhs rhs : BitVec 64)
    (left : le.get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong rhs)) :
    CC.doEvalExpr ge e le memory valueExpr = some (bit lhs rhs) := by
    by_cases less : lhs.toNat < rhs.toNat
    all_goals simp +decide [valueExpr,CC.doEvalExpr,CC.typeof,left,right,
      CC.Cop.semBinaryOperation,CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,
      CC.Cop.classifyBinarith,CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tint,
      CC.Integers.Int64.cmpu,CC.Integers.MI.cmpu,CC.Integers.Int64.ltu,CC.Integers.MI.ltu,
      BitVec.ult,BitVec.lt_def,
      CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,CC.Integers.Int.one,CC.Integers.Int.zero,
      CC.Integers.MI.one,CC.Integers.MI.zero,bit,less,apply_ite]

/-- Exact original pointer read, comparison, uchar cast and byte assignment.
The compositional caller below constructs the store from current ownership. -/
theorem at_site (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory after : CC.Mem)
    (bindingBlock cfBlock : CC.Block) (lhs rhs : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (left : le.get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong rhs))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 120 = some (.Vptr cfBlock 0))
    (stored : CC.Mem.store .Mint8unsigned memory cfBlock 0 (bit lhs rhs) = some after) :
    InternalRun ge 3 (.State handler pointerLoad (.Kseq assignment k) e le memory)
      (.State handler .Sskip k e (le.set pointerTemp (.Vptr cfBlock 0)) after) := by
  have address := cf_address ge X86ProducerLayout.layouts.1 X86ProducerLayout.layouts.2.1 bindingBlock
  have structAccess : CC.accessMode X86ProducerHeaderSource.headerType = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have unsigned120 : CC.Integers.Ptrofs.unsigned (120 : CC.Integers.Ptrofs) = 120 := rfl
  have evaluated : CC.doEvalExpr ge e le memory pointerExpr = some (.Vptr cfBlock 0) := by
    simp only [pointerExpr,CC.doEvalExpr,CC.doDerefLoc,CC.typeof,CC.tptr,
      structAccess,ptrAccess,CC.Mem.loadv,binding,address,unsigned120,header]
  have target : CC.doEvalLvalue ge e (le.set pointerTemp (.Vptr cfBlock 0)) memory targetExpr =
      some (cfBlock,0,.Full) := by
    simp only [targetExpr,CC.doEvalLvalue,CC.doEvalExpr,CC.PTree.gss]
  have keptLeft : (le.set pointerTemp (.Vptr cfBlock 0)).get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong lhs) := by
    simp +decide [pointerTemp,CC.PTree.gso,left]
  have keptRight : (le.set pointerTemp (.Vptr cfBlock 0)).get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong rhs) := by
    simp +decide [pointerTemp,CC.PTree.gso,right]
  have comparison := evaluate_comparison e (le.set pointerTemp (.Vptr cfBlock 0)) memory lhs rhs keptLeft keptRight
  have valueType : CC.typeof valueExpr = CC.tint := rfl
  have targetType : CC.typeof targetExpr = CC.tuchar := rfl
  have cast : CC.Cop.semCast (bit lhs rhs) CC.tint CC.tuchar memory = some (bit lhs rhs) := by
    unfold bit
    split <;> rfl
  have assigned : CC.doAssignLoc ge.genv_cenv CC.tuchar memory cfBlock 0 .Full (bit lhs rhs) = some after := by
    simp only [CC.doAssignLoc,charAccess,CC.Mem.storev]
    exact stored
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,X86ProducerSubCfSource.source_pointer,
    source_store,evaluated,target,valueType,targetType,comparison,cast,assigned,CC.E0,CC.Eapp,List.nil_append,true_and]

/-- The written source byte is the SAME external qword SUB borrow for every
incoming flag word; this invokes the shared reference definition. -/
theorem native_value (lhs rhs : BitVec 64) (flags : X86.Flags) :
    bit lhs rhs = .Vint (if (X86.Flags.sub .q lhs rhs flags).cf then 1 else 0) := by
  rw [X86SubFlagValues.cf]
  rfl


variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Current original producer ownership constructs the actual CF store; all
header/operand observations come from the same prefix. The stored byte equals
external SUB CF, and the old caller and all other blocks retain their loads. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    let k := X86ProducerSubLhs.bodyCont complete
    let lhs := ready.stackOutcome.value-(8#64)
    let selected := certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0)
    ∃ after, CC.Star (CC.Step2 ge)
      (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0))
        (allocation complete.after).1 (selected.output.set pointerTemp (.Vptr (ready.scalars 0).block 0)) after) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).cf then 1 else 0))) ∧
      (∀ chunk block offset, block ≠ (ready.scalars 0).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  dsimp only
  let k := X86ProducerSubLhs.bodyCont complete
  let lhs := ready.stackOutcome.value-(8#64)
  let selected := certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0)
  obtain ⟨after,stored,read,other,frame,access,next⟩ := X86ProducerSubFlagStorage.write complete 0 (decide (lhs.toNat < 32))
  change CC.Mem.store .Mint8unsigned (allocation complete.after).2 (ready.scalars 0).block 0 (bit lhs (32#64)) = some after at stored
  have values := X86ProducerSubCfSource.operands ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0)
  have written := at_site (allocation complete.after).1 selected.output
    (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0))
    (allocation complete.after).2 after ready.entry.block (ready.scalars 0).block lhs (32#64)
    (X86ProducerSubCfSource.binding _ _ _ _ _ _) values.1 values.2.1
    (X86ProducerSubScalarResources.headers complete header 0) stored
  have actual : InternalRun ge 3
      (.State handler pointerLoad selected.continuation (allocation complete.after).1 selected.output (allocation complete.after).2)
      (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0))
        (allocation complete.after).1 (selected.output.set pointerTemp (.Vptr (ready.scalars 0).block 0)) after) := by
    rw [show selected.continuation = .Kseq assignment (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0)) from source_following _ _ _ _ _ _]
    exact written
  refine ⟨after,?_,?_,other,frame,access,next⟩
  · have result := star_trans (X86ProducerSubCfSource.execute complete header) actual.sound
    simpa only [CC.E0,CC.Eapp,List.nil_append] using result
  · intro flags
    change CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 = some (bit lhs (32#64)) at read
    rw [read,native_value lhs (32#64) flags]


/-- The unchanged original kind6/kind1 provider ABIs construct the same
source execution through the first real SUB flag store and its external
borrow readback. No initialized flag value or successful store is assumed. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
    ∃ after, X86ProducerEntryReady.HeaderReads ready ∧
      let k := X86ProducerSubLhs.bodyCont complete
      let lhs := ready.stackOutcome.value-(8#64)
      let selected := certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0)
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0))
          (allocation complete.after).1 (selected.output.set pointerTemp (.Vptr (ready.scalars 0).block 0)) after) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).cf then 1 else 0))) ∧
      (∀ chunk block offset, block ≠ (ready.scalars 0).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨after,run,read,other,frame,access,next⟩ := execute complete header
  refine ⟨ready,rsp,metadata,cache,complete,after,header,?_,read,other,frame,access,next⟩
  have actual := star_trans ready.run run
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubCfStore
