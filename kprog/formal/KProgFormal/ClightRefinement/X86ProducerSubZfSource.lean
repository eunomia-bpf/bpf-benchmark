import KProgFormal.ClightRefinement.X86ProducerSubCfStore
import KProgFormal.ClightRefinement.X86WidthShape

namespace KProgFormal.ClightRefinement.X86ProducerSubZfSource
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (current : CC.Mem) : CC.State :=
  .State handler .Sskip (X86ProducerSubCfStore.following binding k memory lhs cfBlock word)
    (allocation memory).1 ((X86ProducerSubCfSource.certificate binding k memory lhs cfBlock word).output.set
      X86ProducerSubCfSource.pointerTemp (.Vptr cfBlock 0)) current

/-- Locate the next genuine SUB ZF header-pointer load using EXISTING Clight doStep. The
certificate below independently checks the generic actual path in the kernel;
this extraction adds no interpreter or trusted numerical semantics. -/
def pointerLoad : CC.Stmt := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(start CC.Positive.xH .Kstop CC.Mem.empty (0#64) CC.Positive.xH (0#64) CC.Mem.empty)) none
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    while true do
      let state ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless state.isAppOfArity ``CC.State.State 6 do throwError "actual ZF source left statement state"
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf state.getAppArgs[1]!)
      if stmt.isAppOfArity ``CC.Stmt.Sset 2 then
        let rhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
        if rhs.isAppOfArity ``CC.Expr.Efield 3 && rhs.getAppArgs[1]!.isConstOf ``X86_program_profile_bpf._zf then
          Lean.Elab.Tactic.closeMainGoal `actual_sub_zf_pointer_load stmt
          return
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let next ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless next.isAppOfArity ``Option.some 2 do throwError "actual ZF source has no pure successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf next.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

def pointerTemp : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(pointerLoad)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_sub_zf_pointer_temp stmt.getAppArgs[0]!

def pointerExpr : CC.Expr := .Efield
  (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType))
    X86ProducerHeaderSource.headerType) X86_program_profile_bpf._zf (CC.tptr CC.tuchar)

theorem source_pointer : pointerLoad = .Sset pointerTemp pointerExpr := by rfl

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (current : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory lhs cfBlock word current)
    (.State handler pointerLoad continuation (allocation memory).1 output current)

/-- The original post-CF skip/sequence rules execute to the real ZF header
load on the actual current heap. No pointer read or successful ZF store is
assumed; all source temporaries and the entire current heap are retained. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (current : CC.Mem) : Certificate binding k memory lhs cfBlock word current := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``start parameters
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let memory := parameters[6]!
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(pointerLoad)) none
    let built ← InternalPrefixBuilder.buildTo world initial original target env memory
    Lean.Elab.Tactic.closeMainGoal `actual_sub_flag_route
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (current : CC.Mem) :
    InternalRun ge (certificate binding k memory lhs cfBlock word current).count (start binding k memory lhs cfBlock word current)
      (.State handler pointerLoad (certificate binding k memory lhs cfBlock word current).continuation (allocation memory).1
        (certificate binding k memory lhs cfBlock word current).output current) :=
  (certificate binding k memory lhs cfBlock word current).run

theorem binding (block : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (current : CC.Mem) :
    (certificate block k memory lhs cfBlock word current).output.get X86_program_profile_bpf.___x86_bind = some (.Vptr block 0) := by rfl

/-- Actual source qword masks retain physical a/b/r and the original sign
constant; this does not assume their values as incoming source observations. -/
theorem operands (block : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (current : CC.Mem) :
    let output := (certificate block k memory lhs cfBlock word current).output
    output.get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong lhs) ∧
    output.get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong (32#64)) ∧
    output.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong (lhs-(32#64))) ∧
    output.get X86_program_profile_bpf.___x86_sub_sign__1 = some (.Vlong (0x8000000000000000#64)) := by
  dsimp only
  have a : (certificate block k memory lhs cfBlock word current).output.get X86_program_profile_bpf.___x86_sub_a__1 =
      some (.Vlong (lhs &&& (-1#64))) := by rfl
  have r : (certificate block k memory lhs cfBlock word current).output.get X86_program_profile_bpf.___x86_sub_r__1 =
      some (.Vlong ((lhs-(32#64)) &&& (-1#64))) := by rfl
  have allOnes : (-1#64) = BitVec.allOnes 64 := rfl
  rw [allOnes,BitVec.and_allOnes] at a r
  exact ⟨a,rfl,r,rfl⟩


variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The SAME provider/PUSH/SUB execution continues after the actual CF store
through the real skip/sequence rules to the next ZF header-pointer load.
All CF readback and current memory rights/frames are retained. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    let k := X86ProducerSubLhs.bodyCont complete
    let lhs := ready.stackOutcome.value-(8#64)
    ∃ after, CC.Star (CC.Step2 ge)
      (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State handler pointerLoad
        (certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) after).continuation
        (allocation complete.after).1
        (certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) after).output after) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).cf then 1 else 0))) ∧
      (∀ chunk block offset, block ≠ (ready.scalars 0).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  dsimp only
  obtain ⟨after,run,read,other,frame,access,next⟩ := X86ProducerSubCfStore.execute complete header
  refine ⟨after,?_,read,other,frame,access,next⟩
  have actual := star_trans run
    (executes ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0) after).sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

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
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler pointerLoad
          (certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) after).continuation
          (allocation complete.after).1
          (certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) after).output after) ∧
      (∀ flags : X86.Flags, CC.Mem.load .Mint8unsigned after (ready.scalars 0).block 0 =
        some (.Vint (if (X86.Flags.sub .q lhs (32#64) flags).cf then 1 else 0))) ∧
      (∀ chunk block offset, block ≠ (ready.scalars 0).block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk (allocation complete.after).2 block offset) ∧
      FrameBelow before.nextblock (allocation complete.after).2 after ∧
      after.access = (allocation complete.after).2.access ∧ after.nextblock = (allocation complete.after).2.nextblock := by
  obtain ⟨ready,rsp,metadata,cache,complete,after,header,run,read,other,frame,access,next⟩ :=
    X86ProducerSubCfStore.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  refine ⟨ready,rsp,metadata,cache,complete,after,header,?_,read,other,frame,access,next⟩
  have actual := star_trans run
    (executes ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0) after).sound
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubZfSource
