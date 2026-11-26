import KProgFormal.ClightRefinement.X86ProducerSubOfStore
import KProgFormal.ClightRefinement.X86ProducerScalarSeparation
import KProgFormal.ClightRefinement.X86ProducerSubFlagStorage
import KProgFormal.ClightRefinement.X86SubFlagValues

namespace KProgFormal.ClightRefinement.X86ProducerSubPfStore
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
def inputTemps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock sfBlock ofBlock : CC.Block) : CC.TempEnv :=
  (X86ProducerSubOfStore.inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock).set
    X86ProducerSubOfStore.pointerTemp (.Vptr ofBlock 0)

/-- Extract the next complete original PF store pair, stopping before its
header read. Generic source_route independently checks every real transition. -/
def statement : CC.Stmt := by
  run_tac do
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let cont ← Lean.Elab.Term.elabTerm (← `(X86ProducerSubOfStore.following CC.Positive.xH .Kstop CC.Mem.empty (0#64) CC.Positive.xH (0#64) CC.Mem.empty)) none
    let env ← Lean.Elab.Term.elabTerm (← `((allocation CC.Mem.empty).1)) none
    let le ← Lean.Elab.Term.elabTerm (← `(inputTemps CC.Positive.xH .Kstop CC.Mem.empty (0#64) CC.Positive.xH (0#64) CC.Mem.empty CC.Positive.xH CC.Positive.xH CC.Positive.xH)) none
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
          if rhs.isAppOfArity ``CC.Expr.Efield 3 && rhs.getAppArgs[1]!.isConstOf ``X86_program_profile_bpf._pf then
            Lean.Elab.Tactic.closeMainGoal `actual_sub_pf_statement stmt
            return
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless result.isAppOfArity ``Option.some 2 do throwError "actual PF route has no pure successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf result.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

def pointerTemp : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(statement)) none))
    let first ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[0]!)
    Lean.Elab.Tactic.closeMainGoal `actual_sub_pf_pointer_temp first.getAppArgs[0]!

def pointerExpr : CC.Expr := .Efield
  (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType))
    X86ProducerHeaderSource.headerType) X86_program_profile_bpf._pf (CC.tptr CC.tuchar)
def targetExpr : CC.Expr := .Ederef (.Etempvar pointerTemp (CC.tptr CC.tuchar)) CC.tuchar
def valueExpr : CC.Expr := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(statement)) none))
    let second ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
    unless second.isAppOfArity ``CC.Stmt.Sassign 2 do throwError "actual PF assignment missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_pf_value second.getAppArgs[1]!

theorem source_body : statement = .Ssequence (.Sset pointerTemp pointerExpr) (.Sassign targetExpr valueExpr) := rfl

def following (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) : CC.Cont := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let arguments ← #[`binding,`k,`memory,`lhs,`cfBlock,`word,`middle].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing original PF parameter"
      pure (Lean.mkFVar argument.fvarId)
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubOfStore.following arguments
    let allocated ← Lean.Meta.mkAppM ``allocation #[arguments[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let dummy ← Lean.Elab.Term.elabTerm (← `(CC.Positive.xH)) none
    let le ← Lean.Meta.mkAppM ``inputTemps (((arguments.push dummy).push dummy).push dummy)
    let mut current ← Lean.Meta.mkAppM ``CC.State.State #[← Lean.Elab.Term.elabTerm (← `(handler)) none,
      ← Lean.Elab.Term.elabTerm (← `(CC.Stmt.Sskip)) none,cont,env,le,arguments[2]!]
    let target ← Lean.Elab.Term.elabTerm (← `(statement)) none
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless node.isAppOfArity ``CC.State.State 6 do throwError "original PF route left its statement state"
      if ← Lean.Meta.isDefEq node.getAppArgs[1]! target then
        Lean.Elab.Tactic.closeMainGoal `actual_sub_pf_continuation node.getAppArgs[2]!
        return
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless result.isAppOfArity ``Option.some 2 do throwError "original PF route has no pure successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf result.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

structure Route (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock sfBlock ofBlock : CC.Block) (current : CC.Mem) where
  count : Nat
  run : InternalRun ge count
    (.State handler .Sskip (X86ProducerSubOfStore.following binding k memory lhs cfBlock word middle)
      (allocation memory).1 (inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock) current)
    (.State handler statement (following binding k memory lhs cfBlock word middle)
      (allocation memory).1 (inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock) current)

/-- Every intervening original skip/sequence transition is checked by the
existing Clight step relation, with current heap and temporaries retained. -/
def source_route (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock sfBlock ofBlock : CC.Block) (current : CC.Mem) :
    Route binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock current := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let context ← Lean.getLCtx
    let args ← #[`binding,`k,`memory,`lhs,`cfBlock,`word,`middle,`zfBlock,`sfBlock,`ofBlock,`current].mapM fun name => do
      let some argument := context.findFromUserName? name | throwError "missing original PF route input"
      pure (Lean.mkFVar argument.fvarId)
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(statement)) none
    let cont ← Lean.Meta.mkAppM ``X86ProducerSubOfStore.following args[:7].toArray
    let allocated ← Lean.Meta.mkAppM ``allocation #[args[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let le ← Lean.Meta.mkAppM ``inputTemps args[:10].toArray
    let initial ← Lean.Meta.mkAppM ``CC.State.State #[original,← Lean.Elab.Term.elabTerm (← `(CC.Stmt.Sskip)) none,cont,env,le,args[10]!]
    let built ← InternalPrefixBuilder.buildTo world initial original target env args[10]!
    Lean.Elab.Tactic.closeMainGoal `actual_sub_pf_route
      (← Lean.Meta.mkAppM ``Route.mk #[Lean.mkNatLit built.count,built.proof])

theorem observations (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem) (zfBlock sfBlock ofBlock : CC.Block) :
    let le := inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock
    le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0) ∧
    le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong (lhs-(32#64))) := by
  have r : (inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock).get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong ((lhs-(32#64)) &&& (-1#64))) := rfl
  have allOnes : (-1#64) = BitVec.allOnes 64 := rfl
  rw [allOnes,BitVec.and_allOnes] at r
  exact ⟨rfl,r⟩

private theorem pf_address (world : CC.CGenv)
    (bindingsLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : world.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (block : CC.Block) :
    CC.lvalOfField world X86ProducerHeaderSource.headerType X86_program_profile_bpf._pf (.Vptr block 0) = some (block,152,.Full) := by
  change CC.lvalOfField world (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) _ _ = _
  simp only [CC.lvalOfField,bindingsLayout,X86ShiftFlagPF.pf_offset world.genv_cenv valueLayout]
  rfl

private theorem evaluate_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (value : BitVec 64)
    (result : le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong value)) :
    CC.doEvalExpr ge e le memory valueExpr = some (X86ShiftFlagPF.bit value) := by
  have bound : (X86ShiftFlagPF.index value).toNat < 16 := by
    unfold X86ShiftFlagPF.index
    rw [BitVec.toNat_and]
    have bounded := Nat.and_le_right (n := (value ^^^ (value >>> 4)).toNat) (m := (15#64).toNat)
    change _ ≤ 15 at bounded
    omega
  have lowNat : (CC.Integers.Int64.loword (X86ShiftFlagPF.index value)).toNat = (X86ShiftFlagPF.index value).toNat := by
    change ((X86ShiftFlagPF.index value).setWidth 32).toNat = _
    simp only [BitVec.toNat_setWidth]
    exact Nat.mod_eq_of_lt (by omega)
  have shiftBound : (X86ShiftFlagPF.index value).toNat < 32 := by omega
  dsimp only [X86ShiftFlagPF.index] at shiftBound lowNat
  have shiftNat : (value.toNat ^^^ (value.toNat >>> 4)) &&& 15 < 32 := by simpa using shiftBound
  simp +decide [valueExpr,CC.doEvalExpr,CC.typeof,result,
    CC.Cop.semBinaryOperation,CC.Cop.semBinarith,CC.Cop.classifyBinarith,
    CC.Cop.binarithType,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntLong,
    CC.Cop.semShr,CC.Cop.semShift,CC.Cop.classifyShift,CC.Cop.semAnd,CC.Cop.semXor,
    CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.tuint,
    CC.Integers.Int64.shru,CC.Integers.Int.shru,CC.Integers.MI.shru,
    CC.Integers.Int64.xor,CC.Integers.Int64.and,CC.Integers.Int.and,
    CC.Integers.MI.xor,CC.Integers.MI.and,CC.Integers.Int.repr,CC.Integers.Int64.repr,
    CC.Integers.MI.repr,CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,
    CC.Integers.Int64.ltu,CC.Integers.MI.ltu,BitVec.ult,
    X86ShiftFlagPF.bit,X86ShiftFlagPF.index,shiftNat,lowNat]

/-- Exact original pointer read, comparison, uchar cast and byte assignment.
The compositional caller below constructs the store from current ownership. -/
theorem at_site (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory after : CC.Mem)
    (bindingBlock pfBlock : CC.Block) (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong value))
    (header : CC.Mem.load CC.Mptr memory bindingBlock 152 = some (.Vptr pfBlock 0))
    (stored : CC.Mem.store .Mint8unsigned memory pfBlock 0 (X86ShiftFlagPF.bit value) = some after) :
    InternalRun ge 4 (.State handler statement k e le memory)
      (.State handler .Sskip k e (le.set pointerTemp (.Vptr pfBlock 0)) after) := by
  have address := pf_address ge X86ProducerLayout.layouts.1 X86ProducerLayout.layouts.2.1 bindingBlock
  have structAccess : CC.accessMode X86ProducerHeaderSource.headerType = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have unsigned152 : CC.Integers.Ptrofs.unsigned (152 : CC.Integers.Ptrofs) = 152 := rfl
  have evaluated : CC.doEvalExpr ge e le memory pointerExpr = some (.Vptr pfBlock 0) := by
    simp only [pointerExpr,CC.doEvalExpr,CC.doDerefLoc,CC.typeof,CC.tptr,
      structAccess,ptrAccess,CC.Mem.loadv,binding,address,unsigned152,header]
  have target : CC.doEvalLvalue ge e (le.set pointerTemp (.Vptr pfBlock 0)) memory targetExpr =
      some (pfBlock,0,.Full) := by
    simp only [targetExpr,CC.doEvalLvalue,CC.doEvalExpr,CC.PTree.gss]
  have keptValue : (le.set pointerTemp (.Vptr pfBlock 0)).get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong value) := by
    simp +decide [pointerTemp,CC.PTree.gso,result]
  have comparison := evaluate_value e (le.set pointerTemp (.Vptr pfBlock 0)) memory value keptValue
  have valueType : CC.typeof valueExpr = CC.tuint := rfl
  have targetType : CC.typeof targetExpr = CC.tuchar := rfl
  have cast : CC.Cop.semCast (X86ShiftFlagPF.bit value) CC.tuint CC.tuchar memory = some (X86ShiftFlagPF.bit value) := by
    rw [X86ShiftFlagPF.parity]
    cases X86.Value.parity8 value <;> rfl
  have assigned : CC.doAssignLoc ge.genv_cenv CC.tuchar memory pfBlock 0 .Full (X86ShiftFlagPF.bit value) = some after := by
    simp only [CC.doAssignLoc,charAccess,CC.Mem.storev]
    exact stored
  apply internalRun_of_steps
  all_goals simp only [steps,InternalPath,InternalState,CC.doStep,source_body,evaluated,target,valueType,targetType,comparison,cast,assigned,CC.E0,CC.Eapp,List.nil_append,true_and]

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The original PF body follows the SAME CF/ZF/SF/OF writes. Current rights construct
the actual source store, and derived allocation separation protects all three
earlier bytes. All five external flag projections and caller frames remain. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    let k := X86ProducerSubLhs.bodyCont complete
    let lhs := ready.stackOutcome.value-(8#64)
    ∃ middle after,
      let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block
      CC.Star (CC.Step2 ge)
        (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
          (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
        (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
          (allocation complete.after).1 (le.set pointerTemp (.Vptr (ready.scalars 4).block 0)) after) ∧
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
      (∀ chunk block offset, block ≠ (ready.scalars 0).block → block ≠ (ready.scalars 1).block → block ≠ (ready.scalars 2).block → block ≠ (ready.scalars 3).block → block ≠ (ready.scalars 4).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  dsimp only
  let k := X86ProducerSubLhs.bodyCont complete
  let lhs := ready.stackOutcome.value-(8#64)
  obtain ⟨middle,current,run,readCF,readZF,readSF,readOF,other,frame,access,next⟩ := X86ProducerSubOfStore.execute complete header
  let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block
  have headerCF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 0) ready.entry (ready.scalars 0)).symm
  have headerZF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 1) ready.entry (ready.scalars 1)).symm
  have headerSF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 2) ready.entry (ready.scalars 2)).symm
  have headerOF := (X86ProducerHeaderLocals.source_separate ge.genv_cenv before (X86ProducerScalarSource.row 3) ready.entry (ready.scalars 3)).symm
  have headerRead : CC.Mem.load CC.Mptr current ready.entry.block 152 = some (.Vptr (ready.scalars 4).block 0) := by
    rw [other CC.Mptr ready.entry.block 152 headerCF headerZF headerSF headerOF]
    exact X86ProducerSubScalarResources.headers complete header 4
  obtain ⟨after,stored,readPF,otherPF,framePF,accessPF,nextPF⟩ := X86ProducerSubFlagStorage.write_current complete current access 4
    (X86.Flags.sub .q lhs (32#64) {}).pf
  rw [← X86SubFlagValues.pf_source lhs (32#64) {}] at stored readPF
  have values := observations ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block
  have entered := (source_route ready.entry.block k complete.after lhs (ready.scalars 0).block
    (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block current).run
  have written := at_site (allocation complete.after).1 le
    (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
    current after ready.entry.block (ready.scalars 4).block (lhs-(32#64))
    values.1 values.2 headerRead stored
  refine ⟨middle,after,?_,?_,?_,?_,?_,?_,?_,frame.trans framePF,accessPF.trans access,nextPF.trans next⟩
  · have result := star_trans run (entered.trans written).sound
    simpa only [CC.E0,CC.Eapp,List.nil_append,le,inputTemps] using result
  · intro flags
    rw [otherPF .Mint8unsigned (ready.scalars 0).block 0
      (X86ProducerScalarSeparation.separate ready 0 4 (by decide +kernel))]
    exact readCF flags
  · intro flags
    rw [otherPF .Mint8unsigned (ready.scalars 1).block 0
      (X86ProducerScalarSeparation.separate ready 1 4 (by decide +kernel))]
    exact readZF flags
  · intro flags
    rw [otherPF .Mint8unsigned (ready.scalars 2).block 0
      (X86ProducerScalarSeparation.separate ready 2 4 (by decide +kernel))]
    exact readSF flags
  · intro flags
    rw [otherPF .Mint8unsigned (ready.scalars 3).block 0
      (X86ProducerScalarSeparation.separate ready 3 4 (by decide +kernel))]
    exact readOF flags
  · intro flags
    calc
      CC.Mem.load .Mint8unsigned after (ready.scalars 4).block 0 = some (X86ShiftFlagPF.bit (lhs-(32#64))) := readPF
      _ = _ := congrArg some (X86SubFlagValues.pf_source lhs (32#64) flags)
  · intro chunk block offset differentCF differentZF differentSF differentOF differentPF
    exact (otherPF chunk block offset differentPF).trans (other chunk block offset differentCF differentZF differentSF differentOF)

/-- The unchanged original provider ABIs construct one trace through the five
actual CF/ZF/SF/OF/PF stores, preserving all preceding arithmetic projections. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
    ∃ middle after, X86ProducerEntryReady.HeaderReads ready ∧
      let k := X86ProducerSubLhs.bodyCont complete
      let lhs := ready.stackOutcome.value-(8#64)
      let le := inputTemps ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler .Sskip (following ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle)
          (allocation complete.after).1 (le.set pointerTemp (.Vptr (ready.scalars 4).block 0)) after) ∧
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
      (∀ chunk block offset, block ≠ (ready.scalars 0).block → block ≠ (ready.scalars 1).block → block ≠ (ready.scalars 2).block → block ≠ (ready.scalars 3).block → block ≠ (ready.scalars 4).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨middle,after,run,readCF,readZF,readSF,readOF,readPF,other,frame,access,next⟩ := execute complete header
  refine ⟨ready,rsp,metadata,cache,complete,middle,after,header,?_,readCF,readZF,readSF,readOF,readPF,other,frame,access,next⟩
  have actual := star_trans ready.run run
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubPfStore
