import KProgFormal.ClightRefinement.X86ProducerHeaderInitialize

namespace KProgFormal.ClightRefinement.X86ProducerHeaderViews
open X86ProducerHeaderSource X86ProducerHeaderLocals
open X86ProducerCacheAllocation (allocation)

def tagRow (slot : Fin 6) : Fin 24 := ⟨2 + 2 * slot.val, by omega⟩
def pointerRow (slot : Fin 6) : Fin 24 := ⟨3 + 2 * slot.val, by omega⟩
def ghosts {ce : CC.CompositeEnv} {before : CC.Mem}
    (sources : (i : Fin 24) → SourceLocal ce before i) : X86CallFrameComplete.Places :=
  ⟨fun slot => ((sources (tagRow slot)).block, 0), fun slot => ((sources (pointerRow slot)).block, 0)⟩

private theorem row_types : ∀ slot : Fin 6,
    localType (tagRow slot) = CC.tuchar ∧ localType (pointerRow slot) = CC.tptr CC.tvoid := by decide +kernel
private theorem source_names : ∀ slot : Fin 6,
    localName (tagRow slot) ≠ localName (pointerRow slot) ∧
    localName (1 : Fin 24) ≠ localName (tagRow slot) ∧
    localName (1 : Fin 24) ≠ localName (pointerRow slot) := by decide +kernel
private theorem tag_offset : ∀ slot : Fin 6,
    CC.Integers.Ptrofs.unsigned (X86CallFrameClear.headerOffset slot) = 8 * ((tagRow slot).val : Int) := by decide +kernel
private theorem pointer_offset : ∀ slot : Fin 6,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add (X86CallFrameClear.headerOffset slot)
      (CC.Integers.Ptrofs.repr 8)) = 8 * ((pointerRow slot).val : Int) := by decide +kernel
private theorem byte_offset : ∀ (slot : Fin 6) (lane : Fin 8),
    CC.Integers.Ptrofs.unsigned (X86RegisterWriteRspReleaseByteCall.address 0 slot lane) =
      8 * (slot.val : Int) + lane.val := by decide +kernel
private theorem word_offset : ∀ slot : Fin 6,
    CC.Integers.Ptrofs.unsigned (X86RegisterWriteRspReleaseWord.address 0 slot) = 8 * (slot.val : Int) := by decide +kernel

private theorem current_range (ce : CC.CompositeEnv) (before memory : CC.Mem) (name : CC.Ident) (ty : CC.Ty)
    (source : Local ce before name ty) (access : memory.access = (allocation ce before).2.access) :
    CC.Mem.rangePerm memory source.block 0 (CC.sizeof ce ty) .Cur .Writable = true := by
  have range := CC.Mem.rangePerm_implies source.range
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  apply CC.Mem.rangePerm_intro
  intro offset lower upper
  have permission := CC.Mem.rangePerm_perm (allocation ce before).2 source.block 0
    (CC.sizeof ce ty) .Cur .Writable range offset lower upper
  simpa only [CC.Mem.perm, access] using permission

private theorem zero_writable (ce : CC.CompositeEnv) (before memory : CC.Mem) (name : CC.Ident) (ty : CC.Ty)
    (source : Local ce before name ty) (access : memory.access = (allocation ce before).2.access)
    (chunk : CC.Chunk) (size : CC.sizeof ce ty = CC.sizeChunk chunk) :
    CC.Mem.validAccess memory chunk source.block 0 .Writable = true := by
  simp only [CC.Mem.validAccess, Bool.and_eq_true]
  constructor
  · simpa only [size, Int.zero_add] using current_range ce before memory name ty source access
  · simp

private theorem block_live (memory : CC.Mem) (chunk : CC.Chunk) (block : CC.Block)
    (positive : (0 : Int) < CC.sizeChunk chunk)
    (writable : CC.Mem.validAccess memory chunk block 0 .Writable = true) :
    block.toNat < memory.nextblock.toNat := by
  change (CC.Mem.rangePerm memory block 0 (0 + CC.sizeChunk chunk) .Cur .Writable && _) = true at writable
  simp only [Bool.and_eq_true] at writable
  have range := writable.1
  have permission := CC.Mem.rangePerm_perm memory block 0 (0 + CC.sizeChunk chunk) .Cur .Writable range 0
    (Int.le_refl _) (by omega)
  exact (CC.Positive.lt_iff block memory.nextblock).mp (CC.Mem.perm_valid_block memory block 0 .Cur .Writable permission)

/-- The actual initializer constructs the same cache/ghost header views used
by release proofs. Current rights and lifetime follow actual allocation and
stores; no initialized view or post-execution frame is assumed. The preceding
provider/setup prefix and later context-header tail remain separate. -/
theorem initialized_views_with_reads (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (registers : CC.Composite)
    (registersLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells = some registers)
    (cellsOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._gpr_cells registers.co_members = .OK (0, .Full))
    (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ entry : HeaderLocal ge.genv_cenv before,
    ∃ sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i, ∃ after,
    InternalRun ge 72 (.State producer headerStart k (allocation ge.genv_cenv before).1 le memory)
      (.State producer afterHeader k (allocation ge.genv_cenv before).1 le after) ∧
    X86ReleaseProvider.View after entry.block (sources 1).block 0 ∧
    X86CallFrameComplete.View after entry.block (ghosts sources) ∧
    CC.Mem.load CC.Mptr after entry.block 0 = some (.Vptr (sources 0).block 0) ∧
    entry.block ≠ (sources 1).block ∧ X86CallFrameComplete.Outside (ghosts sources) (sources 1).block ∧
    X86CallFrameComplete.Separated entry.block (ghosts sources) ∧
    (sources 1).block.toNat < after.nextblock.toNat ∧
    (∀ slot, ((ghosts sources).tag slot).1.toNat < after.nextblock.toNat ∧
      ((ghosts sources).pointer slot).1.toNat < after.nextblock.toNat) ∧
    (∀ chunk block offset, block ≠ entry.block → CC.Mem.load chunk after block offset = CC.Mem.load chunk memory block offset) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock ∧
    (∀ i : Fin 24, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (sources i).block 0)) := by
  obtain ⟨entry, sources, after, run, reads, outside, frame, finalAccess, frontier⟩ :=
    X86ProducerHeaderInitialize.header_initialized ge bindingsLayout valueLayout registers registersLayout cellsOffset
      before memory le k access
  have sameAccess := finalAccess.trans access
  have allocated : CC.AllocVariables ge.genv_cenv CC.emptyEnv before producer.fn_vars
      (allocation ge.genv_cenv before).1 (allocation ge.genv_cenv before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  have distinct := (allocated_local_storage allocated).2
  have cacheSize : CC.sizeof ge.genv_cenv (localType (1 : Fin 24)) = 48 := by
    change CC.sizeof ge.genv_cenv (.Tunion X86_program_profile_bpf._x86_sim_stack_mem CC.noattr) = 48
    simp only [CC.sizeof, stackLayout]
    rfl
  have cacheRange := current_range ge.genv_cenv before after _ _ (sources 1) sameAccess
  rw [cacheSize] at cacheRange
  have cacheView : X86ReleaseProvider.View after entry.block (sources 1).block 0 := by
    refine ⟨reads 1, ?_, ?_⟩
    · intro slot lane
      rw [byte_offset]
      simp only [CC.Mem.validAccess, Bool.and_eq_true]
      constructor
      · apply CC.Mem.rangePerm_intro
        intro offset lower upper
        have hs := slot.isLt
        have hl := lane.isLt
        change (8 * (slot.val : Int) + (lane.val : Int)) ≤ offset at lower
        change offset < (8 * (slot.val : Int) + (lane.val : Int)) + 1 at upper
        have laneNonnegative : (0 : Int) ≤ (lane.val : Int) := Int.natCast_nonneg _
        exact CC.Mem.rangePerm_perm after (sources 1).block 0 48 .Cur .Writable cacheRange offset (by omega) (by omega)
      · simp [CC.alignChunk]
    · intro slot
      rw [word_offset]
      simp only [CC.Mem.validAccess, Bool.and_eq_true]
      constructor
      · apply CC.Mem.rangePerm_intro
        intro offset lower upper
        have hs := slot.isLt
        change offset < 8 * (slot.val : Int) + 8 at upper
        exact CC.Mem.rangePerm_perm after (sources 1).block 0 48 .Cur .Writable cacheRange offset (by omega) (by omega)
      · change ((8 * (slot.val : Int)) % 8 == 0) = true
        simp
  have ghostView : X86CallFrameComplete.View after entry.block (ghosts sources) := by
    constructor
    · intro slot
      simpa only [ghosts, tag_offset] using reads (tagRow slot)
    · intro slot
      simpa only [ghosts, pointer_offset] using reads (pointerRow slot)
    · intro slot
      have size : CC.sizeof ge.genv_cenv (localType (tagRow slot)) = CC.sizeChunk .Mint8unsigned := by
        rw [(row_types slot).1]
        rfl
      exact zero_writable ge.genv_cenv before after _ _ (sources (tagRow slot)) sameAccess .Mint8unsigned size
    · intro slot
      have size : CC.sizeof ge.genv_cenv (localType (pointerRow slot)) = CC.sizeChunk CC.Mptr := by
        rw [(row_types slot).2]
        rfl
      exact zero_writable ge.genv_cenv before after _ _ (sources (pointerRow slot)) sameAccess CC.Mptr size
  have cacheZero : CC.Mem.validAccess after .Mint64 (sources 1).block 0 .Writable = true := by
    have writable := cacheView.words (0 : Fin 6)
    change CC.Mem.validAccess after .Mint64 (sources 1).block 0 .Writable = true at writable
    exact writable
  refine ⟨entry, sources, after, run, cacheView, ghostView, reads 0,
    (source_separate ge.genv_cenv before 1 entry (sources 1)).symm, ?_, ?_,
    block_live after .Mint64 (sources 1).block (by decide +kernel) cacheZero, ?_, outside, frame, finalAccess, frontier, reads⟩
  · intro slot
    exact ⟨distinct _ _ _ _ (sources 1).binding (sources (tagRow slot)).binding (source_names slot).2.1,
      distinct _ _ _ _ (sources 1).binding (sources (pointerRow slot)).binding (source_names slot).2.2⟩
  · intro slot
    exact ⟨source_separate ge.genv_cenv before (tagRow slot) entry (sources (tagRow slot)),
      source_separate ge.genv_cenv before (pointerRow slot) entry (sources (pointerRow slot)),
      distinct _ _ _ _ (sources (tagRow slot)).binding (sources (pointerRow slot)).binding (source_names slot).1⟩
  · intro slot
    exact ⟨block_live after .Mint8unsigned _ (by decide +kernel) (ghostView.tag_rights slot),
      block_live after CC.Mptr _ (by decide +kernel) (ghostView.pointer_rights slot)⟩

/-- Compatibility interface: all original premises and conclusions are retained. -/
theorem initialized_views (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some X86ShiftLeftCarry.valueRecord)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some X86RegisterWriteRspReleaseWord.stackRecord)
    (registers : CC.Composite)
    (registersLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_register_cells = some registers)
    (cellsOffset : CC.unionFieldOffset ge.genv_cenv X86_program_profile_bpf._gpr_cells registers.co_members = .OK (0, .Full))
    (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ entry : HeaderLocal ge.genv_cenv before,
    ∃ sources : (i : Fin 24) → SourceLocal ge.genv_cenv before i, ∃ after,
    InternalRun ge 72 (.State producer headerStart k (allocation ge.genv_cenv before).1 le memory)
      (.State producer afterHeader k (allocation ge.genv_cenv before).1 le after) ∧
    X86ReleaseProvider.View after entry.block (sources 1).block 0 ∧
    X86CallFrameComplete.View after entry.block (ghosts sources) ∧
    CC.Mem.load CC.Mptr after entry.block 0 = some (.Vptr (sources 0).block 0) ∧
    entry.block ≠ (sources 1).block ∧ X86CallFrameComplete.Outside (ghosts sources) (sources 1).block ∧
    X86CallFrameComplete.Separated entry.block (ghosts sources) ∧
    (sources 1).block.toNat < after.nextblock.toNat ∧
    (∀ slot, ((ghosts sources).tag slot).1.toNat < after.nextblock.toNat ∧
      ((ghosts sources).pointer slot).1.toNat < after.nextblock.toNat) ∧
    (∀ chunk block offset, block ≠ entry.block → CC.Mem.load chunk after block offset = CC.Mem.load chunk memory block offset) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨entry, sources, after, run, cacheView, ghostView, cells, bindingCache, outsideGhosts, separated, cacheLive, ghostsLive, outside, frame, finalAccess, frontier, headerReads⟩ :=
    initialized_views_with_reads ge bindingsLayout valueLayout stackLayout registers registersLayout cellsOffset before memory le k access
  exact ⟨entry, sources, after, run, cacheView, ghostView, cells, bindingCache, outsideGhosts, separated, cacheLive, ghostsLive, outside, frame, finalAccess, frontier⟩

end KProgFormal.ClightRefinement.X86ProducerHeaderViews
