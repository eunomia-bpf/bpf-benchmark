import KProgFormal.ClightRefinement.X86ProducerSubZfStore
import KProgFormal.ClightRefinement.X86ProducerScalarSeparation
import KProgFormal.ClightRefinement.X86ProducerSubFlagStorage
import KProgFormal.ClightRefinement.X86SubFlagValues

namespace KProgFormal.ClightRefinement.X86ProducerSubSfStore
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
def statement : CC.Stmt := X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_IMM_66

def pointerTemp : CC.Ident := X86_program_profile_bpf._t'234

def pointerExpr : CC.Expr := .Efield
  (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType))
    X86ProducerHeaderSource.headerType) X86_program_profile_bpf._sf (CC.tptr CC.tuchar)
def targetExpr : CC.Expr := .Ederef (.Etempvar pointerTemp (CC.tptr CC.tuchar)) CC.tuchar
def valueExpr : CC.Expr := .Ebinop .One
  (.Ebinop .Oand (.Etempvar X86_program_profile_bpf.___x86_sub_r__1 CC.tulong)
    (.Etempvar X86_program_profile_bpf.___x86_sub_sign__1 CC.tulong) CC.tulong)
  (.Econst_int (0#32) CC.tint) CC.tint

theorem source_body : statement = .Ssequence (.Sset pointerTemp pointerExpr) (.Sassign targetExpr valueExpr) := rfl

def inputTemps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock : CC.Block) : CC.TempEnv :=
  (X86ProducerSubZfSource.certificate binding k memory lhs cfBlock word middle).output.set
    X86ProducerSubZfSource.pointerTemp (.Vptr zfBlock 0)

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory,`lhs,`cfBlock,`word,`middle].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing original SF parameter"
      pure (Lean.mkFVar argument.fvarId)
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubZfStore.following arguments
    let allocated ← Lean.Meta.mkAppM ``allocation #[arguments[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let le ← Lean.Meta.mkAppM ``inputTemps (arguments.push (← Lean.Elab.Term.elabTerm (← `(CC.Positive.xH)) none))
    let mut current ← Lean.Meta.mkAppM ``CC.State.State #[← Lean.Elab.Term.elabTerm (← `(handler)) none,
      ← Lean.Elab.Term.elabTerm (← `(CC.Stmt.Sskip)) none,cont,env,le,arguments[2]!]
    let target ← Lean.Elab.Term.elabTerm (← `(statement)) none
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless node.isAppOfArity ``CC.State.State 6 do throwError "original SF route left its statement state"
      if ← Lean.Meta.isDefEq node.getAppArgs[1]! target then
        Lean.Elab.Tactic.closeMainGoal `actual_sub_sf_continuation node.getAppArgs[2]!
        return
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless result.isAppOfArity ``Option.some 2 do throwError "original SF route has no pure successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf result.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

structure Route (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock : CC.Block) (current : CC.Mem) where
  count : Nat
  run : InternalRun ge count
    (.State handler .Sskip (X86ProducerSubZfStore.following binding k memory lhs cfBlock word middle)
      (allocation memory).1 (inputTemps binding k memory lhs cfBlock word middle zfBlock) current)
    (.State handler statement (following binding k memory lhs cfBlock word middle)
      (allocation memory).1 (inputTemps binding k memory lhs cfBlock word middle zfBlock) current)

/-- Every intervening original skip/sequence transition is checked by the
existing Clight step relation, with current heap and temporaries retained. -/
def source_route (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock : CC.Block) (current : CC.Mem) :
    Route binding k memory lhs cfBlock word middle zfBlock current := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let args ← #[`binding,`k,`memory,`lhs,`cfBlock,`word,`middle,`zfBlock,`current].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing original SF route input"
      pure (Lean.mkFVar argument.fvarId)
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(statement)) none
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubZfStore.following args[:7].toArray
    let allocated ← Lean.Meta.mkAppM ``allocation #[args[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let le ← Lean.Meta.mkAppM ``inputTemps args[:8].toArray
    let initial ← Lean.Meta.mkAppM ``CC.State.State #[original,← Lean.Elab.Term.elabTerm (← `(CC.Stmt.Sskip)) none,cont,env,le,args[8]!]
    let built ← InternalPrefixBuilder.buildTo world initial original target env args[8]!
    Lean.Elab.Tactic.closeMainGoal `actual_sub_sf_route
      (← Lean.Meta.mkAppM ``Route.mk #[Lean.mkNatLit built.count,built.proof])

theorem observations (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock : CC.Block) :
    let le := inputTemps binding k memory lhs cfBlock word middle zfBlock
    le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) ∧
    le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong (lhs-(32#64))) ∧
    le.get X86_program_profile_bpf.___x86_sub_sign__1 = some (.Vlong (0x8000000000000000#64)) := by
  have bindingRead := X86ProducerSubZfSource.binding binding k memory lhs cfBlock word middle
  have operands := X86ProducerSubZfSource.operands binding k memory lhs cfBlock word middle
  simp +decide [inputTemps,X86ProducerSubZfSource.pointerTemp,CC.PTree.gso,bindingRead,operands.2.2.1,operands.2.2.2]

private theorem sf_address (world : CC.CGenv)
    (bindingsLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (block : CC.Block) :
    CC.lvalOfField world X86ProducerHeaderSource.headerType X86_program_profile_bpf._sf (.Vptr block 0) = some (block,136,.Full) := by
  change CC.lvalOfField world (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) _ _ = _
  simp only [CC.lvalOfField,bindingsLayout,X86ShiftFlagSF.sf_offset world.genv_cenv valueLayout]
  rfl

private theorem evaluate_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (value signValue : BitVec 64)
    (result : le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong value))
    (sign : le.get X86_program_profile_bpf.___x86_sub_sign__1 = some (.Vlong signValue)) :
    CC.doEvalExpr ge e le memory valueExpr = some (X86ShiftFlagSF.bit value signValue) := by
  have signedZero64 : BitVec.ofInt 64 (CC.Integers.Int.signed (0#32)) = (0 : BitVec 64) := rfl
  by_cases zero : value &&& signValue = 0
  all_goals simp +decide [valueExpr,CC.doEvalExpr,CC.typeof,result,sign,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Integers.Int64.and,CC.Integers.MI.and,
    CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
    CC.tulong,CC.tint,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Integers.Int64.cmpu,
    CC.Integers.MI.cmpu,CC.Integers.MI.eq,CC.Integers.Int.repr,CC.Integers.Int64.repr,
    CC.Integers.MI.repr,CC.Integers.MI.zero,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
    CC.Integers.Int.zero,CC.Integers.Int.one,CC.Integers.MI.one,signedZero64,
    X86ShiftFlagSF.bit,zero,apply_ite]

/-- Exact original pointer read, comparison, uchar cast and byte assignment.
The compositional caller below constructs the store from current ownership. -/
theorem at_site (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory after : CC.Mem)
    (bindingBlock sfBlock : CC.Block) (value signValue : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (left : le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong value))
    (right : le.get X86_program_profile_bpf.___x86_sub_sign__1 = some (.Vlong signValue))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 136 = some (.Vptr sfBlock 0))
    (stored : CC.Mem.store .Mint8unsigned memory sfBlock 0 (X86ShiftFlagSF.bit value signValue) = some after) :
    InternalRun ge 4 (.State handler statement k e le memory)
      (.State handler .Sskip k e (le.set pointerTemp (.Vptr sfBlock 0)) after) := by
  have address := sf_address ge X86ProducerLayout.layouts.1 X86ProducerLayout.layouts.2.1 bindingBlock
  have structAccess : CC.accessMode X86ProducerHeaderSource.headerType = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have unsigned136 : CC.Integers.Ptrofs.unsigned (136 : CC.Integers.Ptrofs) = 136 := rfl
  have evaluated : CC.doEvalExpr ge e le memory pointerExpr = some (.Vptr sfBlock 0) := by
    simp only [pointerExpr,CC.doEvalExpr,CC.doDerefLoc,CC.typeof,CC.tptr,
      structAccess,ptrAccess,CC.Mem.loadv,binding,address,unsigned136,header]
  have target : CC.doEvalLvalue ge e (le.set pointerTemp (.Vptr sfBlock 0)) memory targetExpr =
      some (sfBlock,0,.Full) := by
    simp only [targetExpr,CC.doEvalLvalue,CC.doEvalExpr,CC.PTree.gss]
  have keptLeft : (le.set pointerTemp (.Vptr sfBlock 0)).get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong value) := by
    simp +decide [pointerTemp,CC.PTree.gso,left]
  have keptRight : (le.set pointerTemp (.Vptr sfBlock 0)).get X86_program_profile_bpf.___x86_sub_sign__1 = some (.Vlong signValue) := by
    simp +decide [pointerTemp,CC.PTree.gso,right]
  have comparison := evaluate_value e (le.set pointerTemp (.Vptr sfBlock 0)) memory value signValue keptLeft keptRight
  have valueType : CC.typeof valueExpr = CC.tint := rfl
  have targetType : CC.typeof targetExpr = CC.tuchar := rfl
  have cast : CC.Cop.semCast (X86ShiftFlagSF.bit value signValue) CC.tint CC.tuchar memory = some (X86ShiftFlagSF.bit value signValue) := by
    unfold X86ShiftFlagSF.bit
    split <;> rfl
  have assigned : CC.doAssignLoc ge.genv_cenv CC.tuchar memory sfBlock 0 .Full (X86ShiftFlagSF.bit value signValue) = some after := by
    simp only [CC.doAssignLoc,charAccess,CC.Mem.storev]
    exact stored
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,source_body,evaluated,target,valueType,targetType,comparison,cast,assigned,CC.E0,CC.Eapp,List.nil_append,true_and]

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The original SF body follows the SAME CF/ZF writes. Current rights construct
the actual source store, and derived allocation separation protects both
earlier bytes. All three external flag projections and caller frames remain. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    let k := X86ProducerSubLhs.bodyCont complete
    let lhs := ready.stackOutcome.value-(8#64)
    ∃ middle after,
      let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block
      CC.Star (CC.Step2 ge)
        (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
          (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
        (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
          (allocation complete.after).1 (le.set pointerTemp (.Vptr (ready.scalars 2).block 0)) after) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).cf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 1).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).zf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 2).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).sf then 1 else 0))) ∧
      (∀ chunk block offset, block ≠ (ready.scalars 0).block → block ≠ (ready.scalars 1).block → block ≠ (ready.scalars 2).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  dsimp only
  let k := X86ProducerSubLhs.bodyCont complete
  let lhs := ready.stackOutcome.value-(8#64)
  obtain ⟨middle,current,run,readCF,readZF,other,frame,access,next⟩ := X86ProducerSubZfStore.execute complete header
  let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block
  have headerCF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 0) ready.entry (ready.scalars 0)).symm
  have headerZF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 1) ready.entry (ready.scalars 1)).symm
  have headerRead : CC.Mem.load CC.Mptr current ready.entry.block 136 = some (.Vptr (ready.scalars 2).block 0) := by
    rw [other CC.Mptr ready.entry.block 136 headerCF headerZF]
    exact X86ProducerSubScalarResources.headers complete header 2
  obtain ⟨after,stored,readSF,otherSF,frameSF,accessSF,nextSF⟩ := X86ProducerSubFlagStorage.write_current complete current access 2
    (X86.Flags.sub .q lhs (32#64) {}).sf
  rw [← X86SubFlagValues.sf_source lhs (32#64) {}] at stored readSF
  have values := observations ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block
  have entered := (source_route ready.entry.block k complete.after lhs (ready.scalars 0).block
    (ready.scalarValues 0) middle (ready.scalars 1).block current).run
  have written := at_site (allocation complete.after).1 le
    (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
    current after ready.entry.block (ready.scalars 2).block (lhs-(32#64)) (0x8000000000000000#64)
    values.1 values.2.1 values.2.2 headerRead stored
  refine ⟨middle,after,?_,?_,?_,?_,?_,frame.trans frameSF,accessSF.trans access,nextSF.trans next⟩
  · have result := star_trans run (entered.trans written).sound
    simpa only [CC.E0,CC.Eapp,List.nil_append,le,inputTemps] using result
  · intro flags
    rw [otherSF .Mint8unsigned (ready.scalars 0).block 0
      (X86ProducerScalarSeparation.separate ready 0 2 (by decide +kernel))]
    exact readCF flags
  · intro flags
    rw [otherSF .Mint8unsigned (ready.scalars 1).block 0
      (X86ProducerScalarSeparation.separate ready 1 2 (by decide +kernel))]
    exact readZF flags
  · intro flags
    calc
      CC.Mem.load .Mint8unsigned after (ready.scalars 2).block 0 =
          some (X86ShiftFlagSF.bit (lhs-(32#64)) (0x8000000000000000#64)) := readSF
      _ = _ := congrArg some (X86SubFlagValues.sf_source lhs (32#64) flags)
  · intro chunk block offset differentCF differentZF differentSF
    exact (otherSF chunk block offset differentSF).trans (other chunk block offset differentCF differentZF)

/-- The unchanged original provider ABIs construct one trace through the three
actual CF/ZF/SF stores, preserving all preceding arithmetic projections. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
    ∃ middle after, X86ProducerEntryReady.HeaderReads ready ∧
      let k := X86ProducerSubLhs.bodyCont complete
      let lhs := ready.stackOutcome.value-(8#64)
      let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
          (allocation complete.after).1 (le.set pointerTemp (.Vptr (ready.scalars 2).block 0)) after) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).cf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 1).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).zf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 2).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).sf then 1 else 0))) ∧
      (∀ chunk block offset, block ≠ (ready.scalars 0).block → block ≠ (ready.scalars 1).block → block ≠ (ready.scalars 2).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨middle,after,run,readCF,readZF,readSF,other,frame,access,next⟩ := execute complete header
  refine ⟨ready,rsp,metadata,cache,complete,middle,after,header,?_,readCF,readZF,readSF,other,frame,access,next⟩
  have actual := star_trans ready.run run
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubSfStore
