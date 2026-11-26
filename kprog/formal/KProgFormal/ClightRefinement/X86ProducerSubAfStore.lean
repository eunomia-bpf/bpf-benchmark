import KProgFormal.ClightRefinement.X86ProducerSubPfStore
import KProgFormal.ClightRefinement.X86ProducerScalarSeparation
import KProgFormal.ClightRefinement.X86ProducerSubFlagStorage
import KProgFormal.ClightRefinement.X86SubFlagValues

namespace KProgFormal.ClightRefinement.X86ProducerSubAfStore
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
def inputTemps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock sfBlock ofBlock pfBlock : CC.Block) : CC.TempEnv :=
  (X86ProducerSubPfStore.inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock).set
    X86ProducerSubPfStore.pointerTemp (.Vptr pfBlock 0)

/-- Extract the next complete original AF store pair, stopping before its
header read. Generic source_route independently checks every real transition. -/
def statement : CC.Stmt := by
  run_tac do
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let cont ← Lean.Elab.Term.elabTerm (← `(X86ProducerSubPfStore.following CC.Positive.xH .Kstop CC.Mem.empty (0#64) CC.Positive.xH (0#64) CC.Mem.empty)) none
    let env ← Lean.Elab.Term.elabTerm (← `((allocation CC.Mem.empty).1)) none
    let le ← Lean.Elab.Term.elabTerm (← `(inputTemps CC.Positive.xH .Kstop CC.Mem.empty (0#64) CC.Positive.xH (0#64) CC.Mem.empty CC.Positive.xH CC.Positive.xH CC.Positive.xH CC.Positive.xH)) none
    let mut current ← Lean.Meta.mkAppM ``CC.State.State #[← Lean.Elab.Term.elabTerm (← `(handler)) none,
      ← Lean.Elab.Term.elabTerm (← `(CC.Stmt.Sskip)) none,cont,env,le,← Lean.Elab.Term.elabTerm (← `(CC.Mem.empty)) none]
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless node.isAppOfArity ``CC.State.State 6 do throwError "actual SUB PF route left statement state"
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      if stmt.isAppOfArity ``CC.Stmt.Ssequence 2 then
        let first ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[0]!)
        if first.isAppOfArity ``CC.Stmt.Sset 2 then
          let rhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf first.getAppArgs[1]!)
          if rhs.isAppOfArity ``CC.Expr.Efield 3 && rhs.getAppArgs[1]!.isConstOf ``X86_program_profile_bpf._af then
            Lean.Elab.Tactic.closeMainGoal `actual_sub_af_statement stmt
            return
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless result.isAppOfArity ``Option.some 2 do throwError "actual AF route has no pure successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf result.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

def pointerTemp : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(statement)) none))
    let first ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[0]!)
    Lean.Elab.Tactic.closeMainGoal `actual_sub_af_pointer_temp first.getAppArgs[0]!

def pointerExpr : CC.Expr := .Efield
  (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType))
    X86ProducerHeaderSource.headerType) X86_program_profile_bpf._af (CC.tptr CC.tuchar)
def targetExpr : CC.Expr := .Ederef (.Etempvar pointerTemp (CC.tptr CC.tuchar)) CC.tuchar
def valueExpr : CC.Expr := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(statement)) none))
    let second ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
    unless second.isAppOfArity ``CC.Stmt.Sassign 2 do throwError "actual AF assignment missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_af_value second.getAppArgs[1]!

theorem source_body : statement = .Ssequence (.Sset pointerTemp pointerExpr) (.Sassign targetExpr valueExpr) := rfl

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory,`lhs,`cfBlock,`word,`middle].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing original AF parameter"
      pure (Lean.mkFVar argument.fvarId)
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubPfStore.following arguments
    let allocated ← Lean.Meta.mkAppM ``allocation #[arguments[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let dummy ← Lean.Elab.Term.elabTerm (← `(CC.Positive.xH)) none
    let le ← Lean.Meta.mkAppM ``inputTemps ((((arguments.push dummy).push dummy).push dummy).push dummy)
    let mut current ← Lean.Meta.mkAppM ``CC.State.State #[← Lean.Elab.Term.elabTerm (← `(handler)) none,
      ← Lean.Elab.Term.elabTerm (← `(CC.Stmt.Sskip)) none,cont,env,le,arguments[2]!]
    let target ← Lean.Elab.Term.elabTerm (← `(statement)) none
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless node.isAppOfArity ``CC.State.State 6 do throwError "original AF route left its statement state"
      if ← Lean.Meta.isDefEq node.getAppArgs[1]! target then
        Lean.Elab.Tactic.closeMainGoal `actual_sub_af_continuation node.getAppArgs[2]!
        return
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless result.isAppOfArity ``Option.some 2 do throwError "original AF route has no pure successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf result.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

structure Route (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock sfBlock ofBlock pfBlock : CC.Block) (current : CC.Mem) where
  count : Nat
  run : InternalRun ge count
    (.State handler .Sskip (X86ProducerSubPfStore.following binding k memory lhs cfBlock word middle)
      (allocation memory).1 (inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock) current)
    (.State handler statement (following binding k memory lhs cfBlock word middle)
      (allocation memory).1 (inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock) current)

/-- Every intervening original skip/sequence transition is checked by the
existing Clight step relation, with current heap and temporaries retained. -/
def source_route (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock sfBlock ofBlock pfBlock : CC.Block) (current : CC.Mem) :
    Route binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock current := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let args ← #[`binding,`k,`memory,`lhs,`cfBlock,`word,`middle,`zfBlock,`sfBlock,`ofBlock,`pfBlock,`current].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing original AF route input"
      pure (Lean.mkFVar argument.fvarId)
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(statement)) none
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubPfStore.following args[:7].toArray
    let allocated ← Lean.Meta.mkAppM ``allocation #[args[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let le ← Lean.Meta.mkAppM ``inputTemps args[:11].toArray
    let initial ← Lean.Meta.mkAppM ``CC.State.State #[original,← Lean.Elab.Term.elabTerm (← `(CC.Stmt.Sskip)) none,cont,env,le,args[11]!]
    let built ← InternalPrefixBuilder.buildTo world initial original target env args[11]!
    Lean.Elab.Tactic.closeMainGoal `actual_sub_af_route
      (← Lean.Meta.mkAppM ``Route.mk #[Lean.mkNatLit built.count,built.proof])

theorem observations (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock sfBlock ofBlock pfBlock : CC.Block) :
    let le := inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock
    le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) ∧
    le.get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong lhs) ∧
    le.get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong (32#64)) ∧
    le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong (lhs-(32#64))) := by
  have a : (inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock).get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong (lhs &&& (-1#64))) := rfl
  have r : (inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock).get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong ((lhs-(32#64)) &&& (-1#64))) := rfl
  have allOnes : (-1#64) = BitVec.allOnes 64 := rfl
  rw [allOnes,BitVec.and_allOnes] at a r
  exact ⟨rfl,a,rfl,r⟩

private def members : List CC.Member := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(X86ShiftLeftCarry.bindingsRecord.co_members)) none
    Lean.Elab.Tactic.closeMainGoal `actual_sub_af_members (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private theorem af_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._af X86ShiftLeftCarry.bindingsRecord.co_members = .OK (160,.Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._af members = .OK (160,.Full)
  have size : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl
  have align : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl
  simp +decide [members,CC.fieldOffset,CC.fieldOffsetRec,CC.layoutField,CC.nextField,
    CC.bitalignof,CC.bitsizeof,CC.alignof,CC.sizeof,CC.alignAttr,CC.Ty.attr,
    CC.align,CC.zdiv,CC.tptr,CC.tarray,CC.noattr,valueLayout,size,align]

private theorem af_address (world : CC.CGenv)
    (bindingsLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (block : CC.Block) :
    CC.lvalOfField world X86ProducerHeaderSource.headerType X86_program_profile_bpf._af (.Vptr block 0) = some (block,160,.Full) := by
  change CC.lvalOfField world (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) _ _ = _
  simp only [CC.lvalOfField,bindingsLayout,af_offset world.genv_cenv valueLayout]
  rfl

private theorem mask_zero (value : BitVec 64) (i : Nat) (bound : i < 64) :
    value &&& ((1#64) <<< i) = 0 ↔ value.getLsbD i = false := by
  constructor
  · intro equal
    have observed := congrArg (fun v : BitVec 64 => v.getLsbD i) equal
    simpa [BitVec.getLsbD_and,BitVec.getLsbD_shiftLeft,bound] using observed
  · intro bitZero
    apply BitVec.eq_of_getLsbD_eq_iff.mpr
    intro j hj
    by_cases same : j = i
    · subst j
      simp [bound]
      simpa only [← BitVec.getLsbD_eq_getElem] using bitZero
    · by_cases lower : j < i
      · simp [BitVec.getLsbD_and,BitVec.getLsbD_shiftLeft,lower]
      · have difference : j-i ≠ 0 := by omega
        simp [BitVec.getLsbD_and,BitVec.getLsbD_shiftLeft,lower,difference]

/-- The original xor-and16 test is exactly the SAME external SUB AF bit. -/
theorem native_value (lhs rhs : BitVec 64) (flags : X86.Flags) :
    X86ShiftFlagSF.bit (lhs ^^^ rhs ^^^ (lhs-rhs)) (16#64) =
      .Vint (if (X86.Flags.sub .q lhs rhs flags).af then 1 else 0) := by
  rw [X86SubFlagValues.af]
  have criterion : (lhs ^^^ rhs ^^^ (lhs-rhs)) &&& (16#64) = 0 ↔
      (lhs ^^^ rhs ^^^ (lhs-rhs)).getLsbD 4 = false := mask_zero _ 4 (by decide +kernel)
  cases observed : (lhs ^^^ rhs ^^^ (lhs-rhs)).getLsbD 4 with
  | false => simp [X86ShiftFlagSF.bit,criterion.mpr observed]
  | true =>
      have nonzero : (lhs ^^^ rhs ^^^ (lhs-rhs)) &&& (16#64) ≠ (0#64) := by
        intro zero
        have impossible := criterion.mp zero
        rw [observed] at impossible
        cases impossible
      simp [X86ShiftFlagSF.bit,nonzero]

private theorem evaluate_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (a b result : BitVec 64)
    (left : le.get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong a))
    (right : le.get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong b))
    (value : le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong result)) :
    CC.doEvalExpr ge e le memory valueExpr = some (X86ShiftFlagSF.bit (a ^^^ b ^^^ result) (16#64)) := by
  have signedZero64 : BitVec.ofInt 64 (CC.Integers.Int.signed (0#32)) = (0 : BitVec 64) := rfl
  have unsigned16 : BitVec.ofInt 64 (CC.Integers.Int.unsigned (16#32)) = (16#64) := rfl
  by_cases zero : (a ^^^ b ^^^ result) &&& (16#64) = (0#64)
  all_goals simp +decide [valueExpr,CC.doEvalExpr,CC.typeof,left,right,value,
    CC.Cop.semBinaryOperation,CC.Cop.semAnd,CC.Integers.Int64.and,CC.Integers.MI.and,
    CC.Cop.semXor,CC.Integers.Int64.xor,CC.Integers.MI.xor,
    CC.Cop.semCmp,CC.Cop.classifyCmp,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
    CC.tulong,CC.tint,CC.tuint,CC.typeconv,CC.removeAttributes,CC.tattr,CC.Integers.Int64.cmpu,
    CC.Integers.MI.cmpu,CC.Integers.MI.eq,CC.Integers.Int.repr,CC.Integers.Int64.repr,
    CC.Integers.MI.repr,CC.Integers.MI.zero,CC.Val.ofBool,CC.Val.Vtrue,CC.Val.Vfalse,
    CC.Integers.Int.zero,CC.Integers.Int.one,CC.Integers.MI.one,signedZero64,
    X86ShiftFlagSF.bit,unsigned16,zero,apply_ite]

/-- Exact original pointer read, comparison, uchar cast and byte assignment.
The compositional caller below constructs the store from current ownership. -/
theorem at_site (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory after : CC.Mem)
    (bindingBlock afBlock : CC.Block) (a b result : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (left : le.get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong a))
    (right : le.get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong b))
    (value : le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong result))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 160 = some (.Vptr afBlock 0))
    (stored : CC.Mem.store .Mint8unsigned memory afBlock 0 (X86ShiftFlagSF.bit (a ^^^ b ^^^ result) (16#64)) = some after) :
    InternalRun ge 4 (.State handler statement k e le memory)
      (.State handler .Sskip k e (le.set pointerTemp (.Vptr afBlock 0)) after) := by
  have address := af_address ge X86ProducerLayout.layouts.1 X86ProducerLayout.layouts.2.1 bindingBlock
  have structAccess : CC.accessMode X86ProducerHeaderSource.headerType = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have unsigned160 : CC.Integers.Ptrofs.unsigned (160 : CC.Integers.Ptrofs) = 160 := rfl
  have evaluated : CC.doEvalExpr ge e le memory pointerExpr = some (.Vptr afBlock 0) := by
    simp only [pointerExpr,CC.doEvalExpr,CC.doDerefLoc,CC.typeof,CC.tptr,
      structAccess,ptrAccess,CC.Mem.loadv,binding,address,unsigned160,header]
  have target : CC.doEvalLvalue ge e (le.set pointerTemp (.Vptr afBlock 0)) memory targetExpr =
      some (afBlock,0,.Full) := by
    simp only [targetExpr,CC.doEvalLvalue,CC.doEvalExpr,CC.PTree.gss]
  have keptLeft : (le.set pointerTemp (.Vptr afBlock 0)).get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong a) := by
    simp +decide [pointerTemp,CC.PTree.gso,left]
  have keptRight : (le.set pointerTemp (.Vptr afBlock 0)).get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong b) := by
    simp +decide [pointerTemp,CC.PTree.gso,right]
  have keptValue : (le.set pointerTemp (.Vptr afBlock 0)).get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong result) := by
    simp +decide [pointerTemp,CC.PTree.gso,value]
  have comparison := evaluate_value e (le.set pointerTemp (.Vptr afBlock 0)) memory a b result keptLeft keptRight keptValue
  have valueType : CC.typeof valueExpr = CC.tint := rfl
  have targetType : CC.typeof targetExpr = CC.tuchar := rfl
  have cast : CC.Cop.semCast (X86ShiftFlagSF.bit (a ^^^ b ^^^ result) (16#64)) CC.tint CC.tuchar memory = some (X86ShiftFlagSF.bit (a ^^^ b ^^^ result) (16#64)) := by
    unfold X86ShiftFlagSF.bit
    split <;> rfl
  have assigned : CC.doAssignLoc ge.genv_cenv CC.tuchar memory afBlock 0 .Full (X86ShiftFlagSF.bit (a ^^^ b ^^^ result) (16#64)) = some after := by
    simp only [CC.doAssignLoc,charAccess,CC.Mem.storev]
    exact stored
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,source_body,evaluated,target,valueType,targetType,comparison,cast,assigned,CC.E0,CC.Eapp,List.nil_append,true_and]

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The original AF body follows the SAME CF/ZF/SF/OF/PF writes. Current rights construct
the actual source store, and derived allocation separation protects all three
earlier bytes. All six external flag projections and caller frames remain. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    let k := X86ProducerSubLhs.bodyCont complete
    let lhs := ready.stackOutcome.value-(8#64)
    ∃ middle after,
      let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block
      CC.Star (CC.Step2 ge)
        (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
          (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
        (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
          (allocation complete.after).1 (le.set pointerTemp (.Vptr (ready.scalars 5).block 0)) after) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).cf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 1).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).zf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 2).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).sf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 3).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).of then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 4).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).pf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 5).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).af then 1 else 0))) ∧
      (∀ chunk block offset, block ≠ (ready.scalars 0).block → block ≠ (ready.scalars 1).block → block ≠ (ready.scalars 2).block → block ≠ (ready.scalars 3).block → block ≠ (ready.scalars 4).block → block ≠ (ready.scalars 5).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  dsimp only
  let k := X86ProducerSubLhs.bodyCont complete
  let lhs := ready.stackOutcome.value-(8#64)
  obtain ⟨middle,current,run,readCF,readZF,readSF,readOF,readPF,other,frame,access,next⟩ := X86ProducerSubPfStore.execute complete header
  let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block
  have headerCF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 0) ready.entry (ready.scalars 0)).symm
  have headerZF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 1) ready.entry (ready.scalars 1)).symm
  have headerSF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 2) ready.entry (ready.scalars 2)).symm
  have headerOF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 3) ready.entry (ready.scalars 3)).symm
  have headerPF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 4) ready.entry (ready.scalars 4)).symm
  have headerRead : CC.Mem.load CC.Mptr current ready.entry.block 160 = some (.Vptr (ready.scalars 5).block 0) := by
    rw [other CC.Mptr ready.entry.block 160 headerCF headerZF headerSF headerOF headerPF]
    exact X86ProducerSubScalarResources.headers complete header 5
  obtain ⟨after,stored,readAF,otherAF,frameAF,accessAF,nextAF⟩ := X86ProducerSubFlagStorage.write_current complete current access 5
    (X86.Flags.sub .q lhs (32#64) {}).af
  rw [← native_value lhs (32#64) {}] at stored readAF
  have values := observations ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block
  have entered := (source_route ready.entry.block k complete.after lhs (ready.scalars 0).block
    (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block current).run
  have written := at_site (allocation complete.after).1 le
    (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
    current after ready.entry.block (ready.scalars 5).block lhs (32#64) (lhs-(32#64))
    values.1 values.2.1 values.2.2.1 values.2.2.2 headerRead stored
  refine ⟨middle,after,?_,?_,?_,?_,?_,?_,?_,?_,frame.trans frameAF,accessAF.trans access,nextAF.trans next⟩
  · have result := star_trans run (entered.trans written).sound
    simpa only [CC.E0,CC.Eapp,List.nil_append,le,inputTemps] using result
  · intro flags
    rw [otherAF .Mint8unsigned (ready.scalars 0).block 0
      (X86ProducerScalarSeparation.separate ready 0 5 (by decide +kernel))]
    exact readCF flags
  · intro flags
    rw [otherAF .Mint8unsigned (ready.scalars 1).block 0
      (X86ProducerScalarSeparation.separate ready 1 5 (by decide +kernel))]
    exact readZF flags
  · intro flags
    rw [otherAF .Mint8unsigned (ready.scalars 2).block 0
      (X86ProducerScalarSeparation.separate ready 2 5 (by decide +kernel))]
    exact readSF flags
  · intro flags
    rw [otherAF .Mint8unsigned (ready.scalars 3).block 0
      (X86ProducerScalarSeparation.separate ready 3 5 (by decide +kernel))]
    exact readOF flags
  · intro flags
    rw [otherAF .Mint8unsigned (ready.scalars 4).block 0
      (X86ProducerScalarSeparation.separate ready 4 5 (by decide +kernel))]
    exact readPF flags
  · intro flags
    calc
      CC.Mem.load .Mint8unsigned after (ready.scalars 5).block 0 =
          some (X86ShiftFlagSF.bit (lhs ^^^ (32#64) ^^^ (lhs-(32#64))) (16#64)) := readAF
      _ = _ := congrArg some (native_value lhs (32#64) flags)
  · intro chunk block offset differentCF differentZF differentSF differentOF differentPF differentAF
    exact (otherAF chunk block offset differentAF).trans (other chunk block offset differentCF differentZF differentSF differentOF differentPF)

/-- The unchanged original provider ABIs construct one trace through all six
actual CF/ZF/SF/OF/PF/AF stores, preserving all preceding arithmetic projections. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
    ∃ middle after, X86ProducerEntryReady.HeaderReads ready ∧
      let k := X86ProducerSubLhs.bodyCont complete
      let lhs := ready.stackOutcome.value-(8#64)
      let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
          (allocation complete.after).1 (le.set pointerTemp (.Vptr (ready.scalars 5).block 0)) after) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).cf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 1).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).zf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 2).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).sf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 3).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).of then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 4).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).pf then 1 else 0))) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 5).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).af then 1 else 0))) ∧
      (∀ chunk block offset, block ≠ (ready.scalars 0).block → block ≠ (ready.scalars 1).block → block ≠ (ready.scalars 2).block → block ≠ (ready.scalars 3).block → block ≠ (ready.scalars 4).block → block ≠ (ready.scalars 5).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨middle,after,run,readCF,readZF,readSF,readOF,readPF,readAF,other,frame,access,next⟩ := execute complete header
  refine ⟨ready,rsp,metadata,cache,complete,middle,after,header,?_,readCF,readZF,readSF,readOF,readPF,readAF,other,frame,access,next⟩
  have actual := star_trans ready.run run
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubAfStore
