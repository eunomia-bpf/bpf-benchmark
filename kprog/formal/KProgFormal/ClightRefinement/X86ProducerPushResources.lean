import KProgFormal.ClightRefinement.X86ProducerPushBody

namespace KProgFormal.ClightRefinement.X86ProducerPushResources
open X86ProducerLayout (ge)
open X86ProducerHeaderLocals (Local)

/-- Repeated witnesses of the SAME original typed local derive equal blocks
from their actual allocator binding; no header/cache/GPR identity is assumed. -/
theorem same_local {before : CC.Mem} {name : CC.Ident} {ty : CC.Ty}
    (left right : Local ge.genv_cenv before name ty) : left.block = right.block :=
  congrArg Prod.fst (Option.some.inj (left.binding.symm.trans right.binding))

/-- Actual PUSH local allocation preserves every old typed permission from
both original access maps, even though the overall access map changes. -/
theorem old_access (memory : CC.Mem) (b : CC.Block) (old : b.toNat < memory.nextblock.toNat)
    (c : CC.Chunk) (ofs : CC.Z) (permission : CC.Permission) :
    CC.Mem.validAccess (X86ProducerPushBody.allocation memory).2 c b ofs permission =
      CC.Mem.validAccess memory c b ofs permission := by
  apply CC.Mem.validAccess_congr
  intro point
  simp only [CC.Mem.perm, ((X86ProducerPushBody.entry_frame memory).2 b old).2]

/-- The SAME initialized header, cache and ghost resources are current after
the real PUSH body allocation; freshness and old rights derive from the
original entry result, with no post-allocation View/permission premise. -/
theorem views {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) :
    X86ReleaseProvider.View (X86ProducerPushBody.allocation ready.after).2 ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View (X86ProducerPushBody.allocation ready.after).2 ready.entry.block
      (X86ProducerHeaderViews.ghosts ready.sources) ∧
    CC.Mem.load CC.Mptr (X86ProducerPushBody.allocation ready.after).2 ready.entry.block 0 = some (.Vptr ready.gprs.block 0) ∧
    (ready.sources 1).block = ready.cache.block ∧ (ready.sources 14).block = ready.base.block ∧
    (ready.sources 1).block.toNat < (X86ProducerPushBody.allocation ready.after).2.nextblock.toNat ∧
    (∀ slot, (((X86ProducerHeaderViews.ghosts ready.sources).tag slot).1).toNat <
        (X86ProducerPushBody.allocation ready.after).2.nextblock.toNat ∧
      (((X86ProducerHeaderViews.ghosts ready.sources).pointer slot).1).toNat <
        (X86ProducerPushBody.allocation ready.after).2.nextblock.toNat) := by
  have frame := (X86ProducerPushBody.entry_frame ready.after).2
  have next := (X86ProducerPushBody.entry_frame ready.after).1
  have headerOld : ready.entry.block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact ready.entry.owned
  have cellsSame := same_local (ready.sources 0) ready.gprs
  have cacheSame := same_local (ready.sources 1) ready.cache
  have baseSame := same_local (ready.sources 14) ready.base
  refine ⟨?_, ?_, ?_, cacheSame, baseSame, by have h := ready.cache_live; omega, ?_⟩
  · refine ⟨(frame.load _ _ _ headerOld).trans ready.cache_view.header, ?_, ?_⟩
    · intro slot lane
      exact (old_access ready.after _ ready.cache_live _ _ _).trans (ready.cache_view.bytes slot lane)
    · intro slot
      exact (old_access ready.after _ ready.cache_live _ _ _).trans (ready.cache_view.words slot)
  · refine ⟨?_, ?_, ?_, ?_⟩
    · intro slot
      exact (frame.load _ _ _ headerOld).trans (ready.ghost_view.tags slot)
    · intro slot
      exact (frame.load _ _ _ headerOld).trans (ready.ghost_view.pointers slot)
    · intro slot
      exact (old_access ready.after _ (ready.ghosts_live slot).1 _ _ _).trans (ready.ghost_view.tag_rights slot)
    · intro slot
      exact (old_access ready.after _ (ready.ghosts_live slot).2 _ _ _).trans (ready.ghost_view.pointer_rights slot)
  · exact (frame.load _ _ _ headerOld).trans (by simpa only [cellsSame] using ready.cells_read)
  · intro slot
    have old := ready.ghosts_live slot
    constructor <;> omega

/-- GPR/tag observations, original context pointer, all initialized scalar,
base/return/ABI/ghost fields and old caller loads survive the actual local
allocation. Only rows at genuine RDI retain pointer/tag1 instead of scalar/tag0. -/
theorem observations {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) :
    (∀ i : Fin 16, i ≠ 7 →
      CC.Mem.load CC.Mptr (X86ProducerPushBody.allocation ready.after).2 ready.gprs.block (16 * (i.val : Int)) = some (.Vlong (ready.values i)) ∧
      CC.Mem.load .Mint8unsigned (X86ProducerPushBody.allocation ready.after).2 ready.gprs.block (16 * (i.val : Int) + 8) = some (.Vint 0)) ∧
    CC.Mem.load CC.Mptr (X86ProducerPushBody.allocation ready.after).2 ready.gprs.block 112 = some (.Vptr ctxBlock ctxOffset) ∧
    CC.Mem.load .Mint8unsigned (X86ProducerPushBody.allocation ready.after).2 ready.gprs.block 120 = some (.Vint (1#32)) ∧
    (∀ i, CC.Mem.load (X86ProducerScalarSource.chunk i) (X86ProducerPushBody.allocation ready.after).2 (ready.scalars i).block 0 =
      some (X86ProducerScalarValue.value i (ready.scalarValues i))) ∧
    CC.Mem.load .Mint64 (X86ProducerPushBody.allocation ready.after).2 ready.base.block 0 = some (.Vlong ready.stackOutcome.value) ∧
    CC.Mem.load .Mint64 (X86ProducerPushBody.allocation ready.after).2 ready.ret.block 0 = some (.Vlong 0) ∧
    (∀ i, CC.Mem.load (X86ProducerAbiSource.chunk i) (X86ProducerPushBody.allocation ready.after).2 ready.abi.block (X86ProducerAbiSource.offset i) = some (X86ProducerAbiSource.value i)) ∧
    (∀ i, CC.Mem.load (X86ProducerGhostSource.chunk i) (X86ProducerPushBody.allocation ready.after).2 (ready.ghosts i).block 0 = some (X86ProducerGhostSource.value i)) ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat →
      CC.Mem.load c (X86ProducerPushBody.allocation ready.after).2 b ofs = CC.Mem.load c before b ofs) := by
  have frame := (X86ProducerPushBody.entry_frame ready.after).2
  have old {name : CC.Ident} {ty : CC.Ty} (object : Local ge.genv_cenv before name ty) : object.block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact object.owned
  refine ⟨?_, (frame.load _ _ _ (old ready.gprs)).trans ready.rdi_pointer,
    (frame.load _ _ _ (old ready.gprs)).trans ready.rdi_tag, ?_,
    (frame.load _ _ _ (old ready.base)).trans ready.base_read,
    (frame.load _ _ _ (old ready.ret)).trans ready.ret_read, ?_, ?_, ?_⟩
  · intro i different
    exact ⟨(frame.load _ _ _ (old ready.gprs)).trans (ready.gpr_reads i different).1,
      (frame.load _ _ _ (old ready.gprs)).trans (ready.gpr_reads i different).2⟩
  · intro i
    exact (frame.load _ _ _ (old (ready.scalars i))).trans (ready.scalar_reads i)
  · intro i
    exact (frame.load _ _ _ (old ready.abi)).trans (ready.abi_reads i)
  · intro i
    exact (frame.load _ _ _ (old (ready.ghosts i))).trans (ready.ghost_reads i)
  · intro c b ofs below
    have next : before.nextblock.toNat ≤ ready.after.nextblock.toNat := by
      have h := (ready.gprs).fresh
      have owned := old ready.gprs
      omega
    exact (frame.load c b ofs (by omega)).trans (ready.caller_loads c b ofs below)

end KProgFormal.ClightRefinement.X86ProducerPushResources
