import KProgFormal.ClightRefinement.X86ProducerSubBody
import KProgFormal.ClightRefinement.X86ProducerHeaderReady

namespace KProgFormal.ClightRefinement.X86ProducerSubResources
open X86ProducerLayout (ge)
open X86ProducerHeaderLocals (Local)
open X86ProducerSubBody (allocation)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Genuine original PUSH stores/freeing retain their actual allocation
frontier. No arbitrary post-PUSH ownership fact is assumed. -/
theorem frontier (complete : X86ProducerPushComplete.Result cache) :
    ready.after.nextblock.toNat ≤ complete.after.nextblock.toNat := by
  rw [complete.frontier,cache.frontier,metadata.frontier,rsp.frontier]
  exact (X86ProducerPushBody.entry_frame ready.after).1

theorem old_local (complete : X86ProducerPushComplete.Result cache)
    {name : CC.Ident} {ty : CC.Ty} (object : Local ge.genv_cenv before name ty) :
    object.block.toNat < complete.after.nextblock.toNat := by
  have old : object.block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact object.owned
  have next := frontier complete
  omega

/-- Both old permission maps are retained by actual ALU_IMM local allocation. -/
theorem old_access (memory : CC.Mem) (block : CC.Block) (old : block.toNat < memory.nextblock.toNat)
    (chunk : CC.Chunk) (offset : Int) (permission : CC.Permission) :
    CC.Mem.validAccess (allocation memory).2 chunk block offset permission =
      CC.Mem.validAccess memory chunk block offset permission := by
  apply CC.Mem.validAccess_congr
  intro point
  simp only [CC.Mem.perm,((X86ProducerSubBody.entry_frame memory).2 block old).2]

/-- Every one of the SAME actual initialized header pointers survives both
complete PUSH and actual SUB local allocation, including header112. -/
theorem headers (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) : ∀ i : Fin 24,
    CC.Mem.load CC.Mptr (allocation complete.after).2 ready.entry.block (8*(i.val:Int)) =
      some (.Vptr (ready.sources i).block 0) := by
  intro i
  exact ((X86ProducerSubBody.entry_frame complete.after).2.load _ _ _ (old_local complete ready.entry)).trans
    (X86ProducerHeaderReady.preserve complete header i)

/-- Actual post-allocation inputs to the genuine RSP reader, with no new
header/load/native-base equality premise. -/
theorem current (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) :
    CC.Mem.load CC.Mptr (allocation complete.after).2 ready.entry.block 0 = some (.Vptr ready.gprs.block 0) ∧
    CC.Mem.load CC.Mptr (allocation complete.after).2 ready.entry.block 112 = some (.Vptr ready.base.block 0) ∧
    CC.Mem.load .Mint64 (allocation complete.after).2 ready.base.block 0 = some (.Vlong ready.stackOutcome.value) ∧
    CC.Mem.load CC.Mptr (allocation complete.after).2 ready.gprs.block 64 = some (.Vlong X86ProducerPushRspStore.nextRsp) := by
  obtain ⟨cells,base,native,current⟩ := X86ProducerHeaderReady.current complete header
  have frame := (X86ProducerSubBody.entry_frame complete.after).2
  exact ⟨(frame.load _ _ _ (old_local complete ready.entry)).trans cells,
    (frame.load _ _ _ (old_local complete ready.entry)).trans base,
    (frame.load _ _ _ (old_local complete ready.base)).trans native,
    (frame.load _ _ _ (old_local complete ready.gprs)).trans current⟩

/-- Current cache/ghost views derive the actual post-PUSH resources and true
allocator frame, retaining rights and every real pointer observation. -/
theorem views (complete : X86ProducerPushComplete.Result cache) :
    X86ReleaseProvider.View (allocation complete.after).2 ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View (allocation complete.after).2 ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources) := by
  have frame := (X86ProducerSubBody.entry_frame complete.after).2
  have next := frontier complete
  refine ⟨⟨(frame.load _ _ _ (old_local complete ready.entry)).trans complete.cache_view.header,?_,?_⟩,
    ⟨?_,?_,?_,?_⟩⟩
  · intro slot lane
    exact (old_access complete.after _ (old_local complete (ready.sources 1)) _ _ _).trans (complete.cache_view.bytes slot lane)
  · intro slot
    exact (old_access complete.after _ (old_local complete (ready.sources 1)) _ _ _).trans (complete.cache_view.words slot)
  · intro slot
    exact (frame.load _ _ _ (old_local complete ready.entry)).trans (complete.ghost_view.tags slot)
  · intro slot
    exact (frame.load _ _ _ (old_local complete ready.entry)).trans (complete.ghost_view.pointers slot)
  · intro slot
    have old := (ready.ghosts_live slot).1
    exact (old_access complete.after _ (by omega) _ _ _).trans (complete.ghost_view.tag_rights slot)
  · intro slot
    have old := (ready.ghosts_live slot).2
    exact (old_access complete.after _ (by omega) _ _ _).trans (complete.ghost_view.pointer_rights slot)

/-- Actual saved payload, rawRSP/tag0 and old caller typed/raw frames remain
current after allocating all original SUB locals. -/
theorem observations (complete : X86ProducerPushComplete.Result cache) :
    CC.Mem.load .Mint64 (allocation complete.after).2 (ready.sources 1).block 40 = some (.Vlong (ready.values 3)) ∧
    CC.Mem.load .Mint8unsigned (allocation complete.after).2 ready.gprs.block 72 = some (.Vint 0) ∧
    FrameBelow before.nextblock ready.stackOutcome.supplied (allocation complete.after).2 ∧
    (∀ chunk block offset, block.toNat < before.nextblock.toNat →
      CC.Mem.load chunk (allocation complete.after).2 block offset = CC.Mem.load chunk before block offset) := by
  have frame := (X86ProducerSubBody.entry_frame complete.after).2
  have lower : before.nextblock.toNat ≤ complete.after.nextblock.toNat := by
    have fresh := ready.gprs.fresh
    have old := old_local complete ready.gprs
    omega
  have caller : FrameBelow before.nextblock complete.after (allocation complete.after).2 :=
    fun block old => frame block (by omega)
  exact ⟨(frame.load _ _ _ (old_local complete (ready.sources 1))).trans complete.word_read,
    (frame.load _ _ _ (old_local complete ready.gprs)).trans complete.rsp_tag,
    complete.post_provider_frame.trans caller,
    fun chunk block offset old => (caller.load _ _ _ old).trans (complete.caller_loads _ _ _ old)⟩

end KProgFormal.ClightRefinement.X86ProducerSubResources
