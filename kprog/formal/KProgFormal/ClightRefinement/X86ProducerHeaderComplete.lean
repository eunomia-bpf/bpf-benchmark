import KProgFormal.ClightRefinement.X86ProducerContextInitialize
import KProgFormal.ClightRefinement.X86ProducerBindLoop

namespace KProgFormal.ClightRefinement.X86ProducerHeaderComplete
open X86ProducerContextSource (Typed tempName afterContext followingCalls)
open X86ProducerBindLoop (firstCall)
open X86ProducerHeaderSource (producer headerStart)
open X86ProducerHeaderLocals
open X86ProducerHeaderViews (ghosts)
open X86ProducerCacheAllocation (allocation)

private theorem tag_end : ∀ slot : Fin 6,
    CC.Integers.Ptrofs.unsigned (X86CallFrameClear.headerOffset slot) + CC.sizeChunk CC.Mptr ≤ 192 := by decide +kernel
private theorem pointer_end : ∀ slot : Fin 6,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add (X86CallFrameClear.headerOffset slot)
      (CC.Integers.Ptrofs.repr 8)) + CC.sizeChunk CC.Mptr ≤ 192 := by decide +kernel

/-- The original complete header initializer, context stores, genuine bind loop
and first label execute in94 internal transitions. The same run constructs
current cache/ghost views and all context readbacks at the actual first PUSH
call. The preceding setup/provider prefix and the PUSH execution remain open. -/
theorem to_first_call (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (registers : CC.Composite)
    (registersLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells = some registers)
    (cellsOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._gpr_cells registers.co_members = .OK (0, .Full))
    (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 5 → CC.Val) (typed : Typed values)
    (inputs : ∀ i, le.get (tempName i) = some (values i))
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ entry : HeaderLocal ge.genv_cenv before,
    ∃ sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i, ∃ after,
    InternalRun ge 94 (.State producer headerStart k (allocation ge.genv_cenv before).1 le memory)
      (.State producer firstCall (.Kseq followingCalls k) (allocation ge.genv_cenv before).1 le after) ∧
    X86ReleaseProvider.View after entry.block (sources 1).block 0 ∧
    X86CallFrameComplete.View after entry.block (ghosts sources) ∧
    CC.Mem.load CC.Mptr after entry.block 0 = some (.Vptr (sources 0).block 0) ∧
    (∀ i, CC.Mem.load (X86ProducerContextSource.chunk i) after entry.block (X86ProducerContextSource.offset i) = some (values i)) ∧
    entry.block ≠ (sources 1).block ∧ X86CallFrameComplete.Outside (ghosts sources) (sources 1).block ∧
    X86CallFrameComplete.Separated entry.block (ghosts sources) ∧
    (sources 1).block.toNat < after.nextblock.toNat ∧
    (∀ slot, ((ghosts sources).tag slot).1.toNat < after.nextblock.toNat ∧
      ((ghosts sources).pointer slot).1.toNat < after.nextblock.toNat) ∧
    (∀ c b ofs, b ≠ entry.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨entry, sources, middle, prefixRun, cacheView, ghostView, cells,
    bindingCache, outsideGhosts, separated, cacheLive, ghostsLive, prefixOutside, prefixFrame, prefixAccess, prefixNext⟩ :=
    X86ProducerHeaderViews.initialized_views ge bindingsLayout valueLayout stackLayout registers registersLayout cellsOffset
      before memory le k access
  obtain ⟨after, contextRun, contextReads, header, outside, frame, finalAccess, frontier⟩ :=
    X86ProducerContextInitialize.context_initialized ge bindingsLayout valueLayout before middle le k values typed inputs
      entry (prefixAccess.trans access)
  have afterCache : X86ReleaseProvider.View after entry.block (sources 1).block 0 := by
    refine ⟨(header CC.Mptr 8 (by decide +kernel)).trans cacheView.header, ?_, ?_⟩
    · intro slot lane
      exact (X86ReleaseProvider.access_rights middle after finalAccess _ _ _ _).trans (cacheView.bytes slot lane)
    · intro slot
      exact (X86ReleaseProvider.access_rights middle after finalAccess _ _ _ _).trans (cacheView.words slot)
  have afterGhosts : X86CallFrameComplete.View after entry.block (ghosts sources) := by
    constructor
    · intro slot
      exact (header CC.Mptr _ (tag_end slot)).trans (ghostView.tags slot)
    · intro slot
      exact (header CC.Mptr _ (pointer_end slot)).trans (ghostView.pointers slot)
    · intro slot
      exact (X86ReleaseProvider.access_rights middle after finalAccess _ _ _ _).trans (ghostView.tag_rights slot)
    · intro slot
      exact (X86ReleaseProvider.access_rights middle after finalAccess _ _ _ _).trans (ghostView.pointer_rights slot)
  refine ⟨entry, sources, after, ?_, afterCache, afterGhosts,
    (header CC.Mptr 0 (by decide +kernel)).trans cells, contextReads, bindingCache, outsideGhosts, separated,
    ?_, ?_, ?_, prefixFrame.trans frame, finalAccess.trans prefixAccess, frontier.trans prefixNext⟩
  · exact (prefixRun.trans contextRun).trans
      (X86ProducerBindLoop.to_call ge (allocation ge.genv_cenv before).1 le after k)
  · simpa only [frontier] using cacheLive
  · simpa only [frontier] using ghostsLive
  · intro c b ofs different
    exact (outside c b ofs different).trans (prefixOutside c b ofs different)

end KProgFormal.ClightRefinement.X86ProducerHeaderComplete
