import KProgFormal.ClightRefinement.X86ProducerContextSetup
import KProgFormal.ClightRefinement.X86ProducerStackBaseProvider
import KProgFormal.ClightRefinement.X86ProducerStackBasePrefix

namespace KProgFormal.ClightRefinement.X86ProducerEntryReady
open X86ProducerHeaderSource (producer localName)
open X86ProducerHeaderLocals (Local SourceLocal HeaderLocal)
open X86ProducerGhostStore (Locals)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

structure Result (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (k : CC.Cont) where
  abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi X86ProducerAbiSource.abiType
  ghosts : Locals before
  gprs : SourceLocal ge.genv_cenv before 0
  cache : SourceLocal ge.genv_cenv before 1
  base : SourceLocal ge.genv_cenv before 14
  ret : SourceLocal ge.genv_cenv before 23
  scalars : X86ProducerScalarStage.Locals before
  entry : HeaderLocal ge.genv_cenv before
  sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i
  values : Fin 16 → BitVec 64
  scalarValues : Fin 8 → BitVec 64
  stackBefore : CC.Mem
  stackOutcome : X86ProducerStackBaseProvider.Outcome cache.block stackBefore
  after : CC.Mem
  output : CC.TempEnv
  trace : CC.Trace
  run : CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] k before) trace
    (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls k)
      (allocation ge.genv_cenv before).1 output after)
  gpr_reads : ∀ i : Fin 16, i ≠ 7 →
    CC.Mem.load CC.Mptr after gprs.block (16 * (i.val : Int)) = some (.Vlong (values i)) ∧
    CC.Mem.load .Mint8unsigned after gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0)
  rsp_zero : values 4 = 0
  rdi_pointer : CC.Mem.load CC.Mptr after gprs.block 112 = some (.Vptr ctxBlock ctxOffset)
  rdi_tag : CC.Mem.load .Mint8unsigned after gprs.block 120 = some (.Vint (1#32))
  scalar_reads : ∀ i, CC.Mem.load (X86ProducerScalarSource.chunk i) after (scalars i).block 0 =
    some (X86ProducerScalarValue.value i (scalarValues i))
  base_read : CC.Mem.load .Mint64 after base.block 0 = some (.Vlong stackOutcome.value)
  ret_read : CC.Mem.load .Mint64 after ret.block 0 = some (.Vlong 0)
  abi_reads : ∀ i, CC.Mem.load (X86ProducerAbiSource.chunk i) after abi.block (X86ProducerAbiSource.offset i) = some (X86ProducerAbiSource.value i)
  ghost_reads : ∀ i, CC.Mem.load (X86ProducerGhostSource.chunk i) after (ghosts i).block 0 = some (X86ProducerGhostSource.value i)
  cache_view : X86ReleaseProvider.View after entry.block (sources 1).block 0
  ghost_view : X86CallFrameComplete.View after entry.block (X86ProducerHeaderViews.ghosts sources)
  cells_read : CC.Mem.load CC.Mptr after entry.block 0 = some (.Vptr (sources 0).block 0)
  context_reads : ∀ i, CC.Mem.load (X86ProducerContextSource.chunk i) after entry.block (X86ProducerContextSource.offset i) =
    some (X86ProducerContextSetup.contextValues ctxBlock ctxOffset i)
  separated : entry.block ≠ (sources 1).block ∧ X86CallFrameComplete.Outside (X86ProducerHeaderViews.ghosts sources) (sources 1).block ∧
    X86CallFrameComplete.Separated entry.block (X86ProducerHeaderViews.ghosts sources)
  cache_live : (sources 1).block.toNat < after.nextblock.toNat
  ghosts_live : ∀ slot, (((X86ProducerHeaderViews.ghosts sources).tag slot).1).toNat < after.nextblock.toNat ∧
    (((X86ProducerHeaderViews.ghosts sources).pointer slot).1).toNat < after.nextblock.toNat
  context : output.get X86_program_profile_bpf._ctx = some (.Vptr ctxBlock ctxOffset)
  caller_loads : ∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs
  post_provider_frame : FrameBelow before.nextblock stackOutcome.supplied after
  access : after.access = (allocation ge.genv_cenv before).2.access
  frontier : after.nextblock = (allocation ge.genv_cenv before).2.nextblock

/-- Derived original header observations, retained separately so the old
Result and every old theorem keep precisely their existing premises. -/
def HeaderReads {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : Result before ctxBlock ctxOffset k) : Prop := ∀ i : Fin 24,
  CC.Mem.load CC.Mptr ready.after ready.entry.block (8 * (i.val : Int)) = some (.Vptr (ready.sources i).block 0)

private theorem rows : ∀ i : Fin 16,
    X86ProducerGprStore.chunk (X86ProducerGprSites.valueRow i) = CC.Mptr ∧
    X86ProducerGprStore.offset (X86ProducerGprSites.valueRow i) = 16 * (i.val : Int) ∧
    X86ProducerGprStore.chunk (X86ProducerGprSites.tagRow i) = .Mint8unsigned ∧
    X86ProducerGprStore.offset (X86ProducerGprSites.tagRow i) = 16 * (i.val : Int) + 8 ∧
    (i ≠ 7 → X86ProducerGprSites.valueRow i ≠ 14 ∧ X86ProducerGprSites.valueRow i ≠ 15 ∧
      X86ProducerGprSites.tagRow i ≠ 14 ∧ X86ProducerGprSites.tagRow i ≠ 15) := by decide +kernel

/-- The SAME full original call reaches its actual first PUSH with all source
initialization readbacks and current header/cache/ghost resources. Kind6 and
kind1 platform ABIs remain separate explicit premises. No native-memory or
provider-oracle/trace correspondence is inferred from this source theorem. -/
theorem from_call_with_header (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (k : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : Result before ctxBlock ctxOffset k, HeaderReads ready := by
  obtain ⟨abi, ghosts, gprs, cache, memory, gpr, objects, base, scalar, ret, current,
    prefixRun, gprReads, rspZero, scalarReads, oldBaseRead, retRead, abiReads, ghostReads,
    typed, contextReads, ctxRead, callerReads, initialFrame, scalarFrame, access, frontier⟩ :=
    X86ProducerStackBasePrefix.from_call before (.Vptr ctxBlock ctxOffset) k inputs6
  obtain ⟨stack⟩ := X86ProducerStackBaseProvider.execute before current scalar.output k base cache inputs1 access frontier
  have names : X86ProducerStackBaseSource.resultName ≠ X86_program_profile_bpf._ctx ∧
      (∀ i : Fin 5, X86ProducerStackBaseSource.resultName ≠ X86ProducerContextSource.tempName i) := by decide +kernel
  have currentCtx : (X86ProducerStackBaseReturn.temps scalar.output stack.outcome.value).get X86_program_profile_bpf._ctx =
      some (.Vptr ctxBlock ctxOffset) := by
    unfold X86ProducerStackBaseReturn.temps
    rw [CC.PTree.gso _ _ _ _ names.1]
    exact ctxRead
  have currentInputs : ∀ i : Fin 5,
      (X86ProducerStackBaseReturn.temps scalar.output stack.outcome.value).get (X86ProducerContextSource.tempName i) =
        some (X86ProducerInitialPrefix.contextValues i) := by
    intro i
    unfold X86ProducerStackBaseReturn.temps
    rw [CC.PTree.gso _ _ _ _ (names.2 i)]
    exact contextReads i
  obtain ⟨entry, sources, after, readyRun, cacheView, ghostView, cellsRead, headerContexts,
    entryCache, cacheGhosts, ghostsSeparate, cacheLive, ghostsLive, rdiRead, rdiTag,
    otherRows, outside, readyFrame, readyAccess, readyNext, headerReads⟩ :=
    X86ProducerContextSetup.to_first_call_with_reads before stack.after
      (X86ProducerStackBaseReturn.temps scalar.output stack.outcome.value) k gprs ctxBlock ctxOffset
      currentCtx currentInputs (stack.access.trans access)
  have gprNames : localName (0 : Fin 24) ≠ localName (14 : Fin 24) ∧ localName (0 : Fin 24) ≠ localName (1 : Fin 24) := by decide +kernel
  have gprBase := X86ProducerGprStage.local_separate before gprs base gprNames.1
  have gprCache := X86ProducerGprStage.local_separate before gprs cache gprNames.2
  have combined : ∀ {name : CC.Ident} {ty : CC.Ty} (object : Local ge.genv_cenv before name ty),
      name ≠ X86_program_profile_bpf.___x86_inline_bindings → name ≠ localName (0 : Fin 24) →
      name ≠ localName (14 : Fin 24) → name ≠ localName (1 : Fin 24) →
      ∀ c ofs, CC.Mem.load c after object.block ofs = CC.Mem.load c current object.block ofs := by
    intro name ty object notHeader notGpr notBase notCache c ofs
    have headerSeparate := X86ProducerGprStage.local_separate before object entry notHeader
    have gprSeparate := X86ProducerGprStage.local_separate before object gprs notGpr
    have baseSeparate := X86ProducerGprStage.local_separate before object base notBase
    have cacheSeparate := X86ProducerGprStage.local_separate before object cache notCache
    exact (outside c object.block ofs headerSeparate gprSeparate).trans (stack.outside c object.block ofs baseSeparate cacheSeparate)
  have scalarNames : ∀ i : Fin 8,
      localName (X86ProducerScalarSource.row i) ≠ X86_program_profile_bpf.___x86_inline_bindings ∧
      localName (X86ProducerScalarSource.row i) ≠ localName (0 : Fin 24) ∧
      localName (X86ProducerScalarSource.row i) ≠ localName (14 : Fin 24) ∧
      localName (X86ProducerScalarSource.row i) ≠ localName (1 : Fin 24) := by decide +kernel
  have retNames : localName (23 : Fin 24) ≠ X86_program_profile_bpf.___x86_inline_bindings ∧
      localName (23 : Fin 24) ≠ localName (0 : Fin 24) ∧ localName (23 : Fin 24) ≠ localName (14 : Fin 24) ∧
      localName (23 : Fin 24) ≠ localName (1 : Fin 24) := by decide +kernel
  have abiNames : X86_program_profile_bpf.___x86_sim_abi ≠ X86_program_profile_bpf.___x86_inline_bindings ∧
      X86_program_profile_bpf.___x86_sim_abi ≠ localName (0 : Fin 24) ∧ X86_program_profile_bpf.___x86_sim_abi ≠ localName (14 : Fin 24) ∧
      X86_program_profile_bpf.___x86_sim_abi ≠ localName (1 : Fin 24) := by decide +kernel
  have ghostNames : ∀ i : Fin 12,
      localName (X86ProducerGhostSource.row i) ≠ X86_program_profile_bpf.___x86_inline_bindings ∧
      localName (X86ProducerGhostSource.row i) ≠ localName (0 : Fin 24) ∧
      localName (X86ProducerGhostSource.row i) ≠ localName (14 : Fin 24) ∧
      localName (X86ProducerGhostSource.row i) ≠ localName (1 : Fin 24) := by decide +kernel
  have baseHeader := X86ProducerHeaderLocals.source_separate ge.genv_cenv before 14 entry base
  have baseGpr := X86ProducerGprStage.local_separate before base gprs gprNames.1.symm
  refine ⟨{
    abi := abi, ghosts := ghosts, gprs := gprs, cache := cache, base := base, ret := ret,
    scalars := objects, entry := entry, sources := sources, values := gpr.values, scalarValues := scalar.values,
    stackBefore := current, stackOutcome := stack.outcome, after := after,
    output := X86ProducerContextSetup.temps (X86ProducerStackBaseReturn.temps scalar.output stack.outcome.value) ctxBlock ctxOffset,
    trace := CC.Eapp (CC.Eapp gpr.trace scalar.trace) stack.outcome.trace,
    run := ?_, gpr_reads := ?_, rsp_zero := rspZero, rdi_pointer := rdiRead, rdi_tag := rdiTag,
    scalar_reads := ?_, base_read := (outside _ _ _ baseHeader baseGpr).trans stack.read,
    ret_read := (combined ret retNames.1 retNames.2.1 retNames.2.2.1 retNames.2.2.2 _ _).trans retRead,
    abi_reads := ?_, ghost_reads := ?_, cache_view := cacheView, ghost_view := ghostView, cells_read := cellsRead,
    context_reads := headerContexts, separated := ⟨entryCache, cacheGhosts, ghostsSeparate⟩,
    cache_live := cacheLive, ghosts_live := ghostsLive,
    context := (X86ProducerContextSetup.context_preserved _ ctxBlock ctxOffset).trans currentCtx,
    caller_loads := ?_, post_provider_frame := stack.post_frame.trans readyFrame,
    access := readyAccess.trans (stack.access.trans access), frontier := readyNext.trans (stack.frontier.trans frontier) }, ?_⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans (star_trans prefixRun stack.run) readyRun.sound
  · intro i notRdi
    have apart := (rows i).2.2.2.2 notRdi
    have pointer := (otherRows (X86ProducerGprSites.valueRow i) apart.1 apart.2.1).trans
      (stack.outside _ gprs.block _ gprBase gprCache)
    have tag := (otherRows (X86ProducerGprSites.tagRow i) apart.2.2.1 apart.2.2.2).trans
      (stack.outside _ gprs.block _ gprBase gprCache)
    simp only [(rows i).1, (rows i).2.1] at pointer
    simp only [(rows i).2.2.1, (rows i).2.2.2.1] at tag
    exact ⟨pointer.trans (gprReads i).1, tag.trans (gprReads i).2⟩
  · intro i
    have n := scalarNames i
    exact (combined (objects i) n.1 n.2.1 n.2.2.1 n.2.2.2 _ _).trans (scalarReads i)
  · intro i
    exact (combined abi abiNames.1 abiNames.2.1 abiNames.2.2.1 abiNames.2.2.2 _ _).trans (abiReads i)
  · intro i
    have n := ghostNames i
    exact (combined (ghosts i) n.1 n.2.1 n.2.2.1 n.2.2.2 _ _).trans (ghostReads i)
  · intro c b ofs below
    have fresh {name : CC.Ident} {ty : CC.Ty} (object : Local ge.genv_cenv before name ty) : b ≠ object.block := by
      intro equal
      have allocated := object.fresh
      rw [equal] at below
      omega
    exact (outside c b ofs (fresh entry) (fresh gprs)).trans
      ((stack.outside c b ofs (fresh base) (fresh cache)).trans (callerReads c b ofs below))

  · exact headerReads

/-- Original entry interface: no added header or input premise. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (k : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    Nonempty (Result before ctxBlock ctxOffset k) := by
  obtain ⟨ready, _header⟩ := from_call_with_header before ctxBlock ctxOffset k inputs6 inputs1
  exact ⟨ready⟩

end KProgFormal.ClightRefinement.X86ProducerEntryReady
