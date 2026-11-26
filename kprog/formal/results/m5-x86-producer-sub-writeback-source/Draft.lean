import KProgFormal.ClightRefinement.X86ProducerSubAfStore

namespace KProgFormal.ClightRefinement.X86ProducerSubWritebackSource
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)

/-- Retain the original post-CF heap and all six actual flag-pointer results.
The separate current heap is the result of the six real source stores. -/
def inputTemps (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem)
    (zfBlock sfBlock ofBlock pfBlock afBlock : CC.Block) : CC.TempEnv :=
  (X86ProducerSubAfStore.inputTemps binding k memory lhs cfBlock word middle
    zfBlock sfBlock ofBlock pfBlock).set X86ProducerSubAfStore.pointerTemp (.Vptr afBlock 0)

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem)
    (zfBlock sfBlock ofBlock pfBlock afBlock : CC.Block) (current : CC.Mem) : CC.State :=
  .State handler .Sskip (X86ProducerSubAfStore.following binding k memory lhs cfBlock word middle)
    (allocation memory).1
    (inputTemps binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock) current

/-- Select the next original header-to-GPR-table read. This extraction only
locates a statement; certificate checks its generic source path separately. -/
def pointerLoad : CC.Stmt := by
  run_tac do
    let mut current ← Lean.Elab.Term.elabTerm (← `(start CC.Positive.xH .Kstop CC.Mem.empty (0#64)
      CC.Positive.xH (0#64) CC.Mem.empty CC.Positive.xH CC.Positive.xH CC.Positive.xH CC.Positive.xH CC.Positive.xH CC.Mem.empty)) none
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    while true do
      let state ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless state.isAppOfArity ``CC.State.State 6 do throwError "original SUB writeback left statement state"
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf state.getAppArgs[1]!)
      if stmt.isAppOfArity ``CC.Stmt.Sset 2 then
        let rhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
        if rhs.isAppOfArity ``CC.Expr.Efield 3 && rhs.getAppArgs[1]!.isConstOf ``X86_program_profile_bpf._cells then
          Lean.Elab.Tactic.closeMainGoal `original_sub_writeback_cells_read stmt
          return
      if stmt.isAppOfArity ``CC.Stmt.Scall 3 then throwError "original SUB writeback encountered an earlier call"
      let step ← Lean.Meta.mkAppM ``CC.doStep #[world,current]
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf step)
      unless result.isAppOfArity ``Option.some 2 do throwError "original SUB writeback has no pure successor before cells read"
      let pair ← Lean.Meta.withTransparency .all (Lean.Meta.whnf result.getAppArgs[1]!)
      current := pair.getAppArgs[3]!

def pointerTemp : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(pointerLoad)) none))
    Lean.Elab.Tactic.closeMainGoal `original_sub_writeback_cells_temp stmt.getAppArgs[0]!

def pointerExpr : CC.Expr := .Efield
  (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType))
    X86ProducerHeaderSource.headerType) X86_program_profile_bpf._cells
  (CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_gpr_cell CC.noattr))

theorem source_pointer : pointerLoad = .Sset pointerTemp pointerExpr := rfl

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem)
    (zfBlock sfBlock ofBlock pfBlock afBlock : CC.Block) (current : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count
    (start binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock current)
    (.State handler pointerLoad continuation (allocation memory).1 output current)

/-- Every real control transition from post-AF to the RSP writeback read is
checked by the existing Clight relation for arbitrary operands and heaps.
No table read, raw RSP update, release decision or native step is assumed. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem)
    (zfBlock sfBlock ofBlock pfBlock afBlock : CC.Block) (current : CC.Mem) :
    Certificate binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock current := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``start parameters
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(pointerLoad)) none
    let built ← InternalPrefixBuilder.buildTo world initial original target env parameters[12]!
    Lean.Elab.Tactic.closeMainGoal `original_sub_writeback_prefix
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem)
    (zfBlock sfBlock ofBlock pfBlock afBlock : CC.Block) (current : CC.Mem) :
    InternalRun ge (certificate binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock current).count
      (start binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock current)
      (.State handler pointerLoad
        (certificate binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock current).continuation
        (allocation memory).1
        (certificate binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock current).output current) :=
  (certificate binding k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock current).run

theorem binding (block : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64)
    (cfBlock : CC.Block) (word : BitVec 64) (middle : CC.Mem)
    (zfBlock sfBlock ofBlock pfBlock afBlock : CC.Block) (current : CC.Mem) :
    (certificate block k memory lhs cfBlock word middle zfBlock sfBlock ofBlock pfBlock afBlock current).output.get
      X86_program_profile_bpf.___x86_bind = some (.Vptr block 0) := by rfl

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The SAME six-flag execution continues to the genuine GPR-table read. All flag values and memory frames are retained. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    let k := X86ProducerSubLhs.bodyCont complete
    let lhs := ready.stackOutcome.value-(8#64)
    ∃ middle after,
      CC.Star (CC.Step2 ge)
        (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
          (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
        (.State handler pointerLoad
          (certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block (ready.scalars 5).block after).continuation (allocation complete.after).1
          (certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block (ready.scalars 5).block after).output after) ∧
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
  obtain ⟨middle,after,run,readCF,readZF,readSF,readOF,readPF,readAF,other,frame,access,next⟩ :=
    X86ProducerSubAfStore.execute complete header
  refine ⟨middle,after,?_,readCF,readZF,readSF,readOF,readPF,readAF,other,frame,access,next⟩
  have actual := star_trans run
    (executes ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64)) (ready.scalars 0).block (ready.scalarValues 0) middle
      (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block
      (ready.scalars 5).block after).sound
  simpa only [CC.E0,CC.Eapp,List.nil_append,start,inputTemps] using actual

/-- The unchanged provider inputs construct the complete source prefix, without a post-store/run/read premise. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
    ∃ middle after, X86ProducerEntryReady.HeaderReads ready ∧
      let k := X86ProducerSubLhs.bodyCont complete
      let lhs := ready.stackOutcome.value-(8#64)
      CC.Star (CC.Step2 ge)
        (.Callstate (.Internal X86ProducerHeaderSource.producer) [.Vptr ctxBlock ctxOffset] outer before) ready.trace
        (.State handler pointerLoad
          (certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block (ready.scalars 5).block after).continuation (allocation complete.after).1
          (certificate ready.entry.block k complete.after lhs (ready.scalars 0).block (ready.scalarValues 0) middle (ready.scalars 1).block (ready.scalars 2).block (ready.scalars 3).block (ready.scalars 4).block (ready.scalars 5).block after).output after) ∧
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
  obtain ⟨ready,rsp,metadata,cache,complete,header,_⟩ :=
    X86ProducerHeaderReady.from_call before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨middle,after,run,readCF,readZF,readSF,readOF,readPF,readAF,other,frame,access,next⟩ := execute complete header
  refine ⟨ready,rsp,metadata,cache,complete,middle,after,header,?_,readCF,readZF,readSF,readOF,readPF,readAF,other,frame,access,next⟩
  have actual := star_trans ready.run run
  simpa only [CC.E0,CC.Eapp,List.append_nil] using actual

end KProgFormal.ClightRefinement.X86ProducerSubWritebackSource
