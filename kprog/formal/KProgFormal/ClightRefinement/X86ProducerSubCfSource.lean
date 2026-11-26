import KProgFormal.ClightRefinement.X86ProducerSubSignCall
import KProgFormal.ClightRefinement.X86WidthShape

namespace KProgFormal.ClightRefinement.X86ProducerSubCfSource
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) : CC.State :=
  .State handler .Sskip (X86ProducerSubSignSetup.certificate binding k memory lhs cfBlock word).continuation
    (allocation memory).1 (X86ProducerSubSignCall.temps binding k memory lhs cfBlock word) (allocation memory).2

/-- Locate the next genuine SUB CF header-pointer load using EXISTING Clight doStep. The
certificate below independently checks the generic actual path in the kernel;
this extraction adds no interpreter or trusted numerical semantics. -/
def pointerLoad : CC.Stmt := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(start CC.Positive.xH .Kstop CC.Mem.empty (0#64) CC.Positive.xH (0#64))) none
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    while true do
      let state ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless state.isAppOfArity ``CC.State.State 6 do throwError "actual CF source left statement state"
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf state.getAppArgs[1]!)
      if stmt.isAppOfArity ``CC.Stmt.Sset 2 then
        let rhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
        if rhs.isAppOfArity ``CC.Expr.Efield 3 && rhs.getAppArgs[1]!.isConstOf ``X86_program_profile_bpf._cf then
          Lean.Elab.Tactic.closeMainGoal `actual_sub_cf_pointer_load stmt
          return
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let next ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless next.isAppOfArity ``Option.some 2 do throwError "actual CF source has no pure successor"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf next.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

def pointerTemp : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(pointerLoad)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_sub_cf_pointer_temp stmt.getAppArgs[0]!

def pointerExpr : CC.Expr := .Efield
  (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType))
    X86ProducerHeaderSource.headerType) X86_program_profile_bpf._cf (CC.tptr CC.tuchar)

theorem source_pointer : pointerLoad = .Sset pointerTemp pointerExpr := by rfl

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory lhs cfBlock word)
    (.State handler pointerLoad continuation (allocation memory).1 output (allocation memory).2)

/-- Original SUB sign-helper return/cast/save and loop entry
execute to the actual CF pointer load with all source state retained. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) : Certificate binding k memory lhs cfBlock word := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``start parameters
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let memory ← Lean.Meta.mkAppM ``Prod.snd #[allocated]
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(pointerLoad)) none
    let built ← InternalPrefixBuilder.buildTo world initial original target env memory
    Lean.Elab.Tactic.closeMainGoal `actual_sub_flag_route
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    InternalRun ge (certificate binding k memory lhs cfBlock word).count (start binding k memory lhs cfBlock word)
      (.State handler pointerLoad (certificate binding k memory lhs cfBlock word).continuation (allocation memory).1
        (certificate binding k memory lhs cfBlock word).output (allocation memory).2) :=
  (certificate binding k memory lhs cfBlock word).run

theorem binding (block : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    (certificate block k memory lhs cfBlock word).output.get X86_program_profile_bpf.___x86_bind = some (.Vptr block 0) := by rfl

/-- Actual source qword masks retain physical a/b/r and the original sign
constant; this does not assume their values as incoming source observations. -/
theorem operands (block : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) :
    let output := (certificate block k memory lhs cfBlock word).output
    output.get X86_program_profile_bpf.___x86_sub_a__1 = some (.Vlong lhs) ∧
    output.get X86_program_profile_bpf.___x86_sub_b__1 = some (.Vlong (32#64)) ∧
    output.get X86_program_profile_bpf.___x86_sub_r__1 = some (.Vlong (lhs-(32#64))) ∧
    output.get X86_program_profile_bpf.___x86_sub_sign__1 = some (.Vlong (0x8000000000000000#64)) := by
  dsimp only
  have a : (certificate block k memory lhs cfBlock word).output.get X86_program_profile_bpf.___x86_sub_a__1 =
      some (.Vlong (lhs &&& (-1#64))) := by rfl
  have r : (certificate block k memory lhs cfBlock word).output.get X86_program_profile_bpf.___x86_sub_r__1 =
      some (.Vlong ((lhs-(32#64)) &&& (-1#64))) := by rfl
  have allOnes : (-1#64) = BitVec.allOnes 64 := rfl
  rw [allOnes,BitVec.and_allOnes] at a r
  exact ⟨a,rfl,r,rfl⟩


variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- SAME original provider/PUSH/SUB prefix includes actual sign-mask
assignment and loop entry up to the genuine CF pointer load. The header read
and flag stores are the next source statements, not incoming observations. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    let selected := certificate ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0)
    CC.Star (CC.Step2 ge)
      (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State handler pointerLoad selected.continuation (allocation complete.after).1
        selected.output (allocation complete.after).2) := by
  have actual := star_trans (X86ProducerSubSignCall.execute complete header)
    (executes ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0)).sound
  simpa only [CC.E0,CC.Eapp,List.nil_append] using actual

/-- Unchanged original kind6/kind1 inputs construct the whole traced
prefix and derived packet at the real selected SUB CF pointer load. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
      X86ProducerEntryReady.HeaderReads ready ∧
      let selected := certificate ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
        (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0)
      CC.Star (CC.Step2 ge) (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler pointerLoad selected.continuation (allocation complete.after).1
          selected.output (allocation complete.after).2) := by
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ := X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  refine ⟨ready,rsp,metadata,cache,complete,header,?_⟩
  have actual := star_trans ready.run (execute complete header)
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubCfSource
