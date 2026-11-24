import KProgFormal.ClightRefinement.X86ProducerPushResources

namespace KProgFormal.ClightRefinement.X86ProducerPushRspStore
open X86ProducerLayout (ge)
open X86ProducerPushBody (allocation)

def nextRsp : BitVec 64 := -(8#64)

/-- The original GPR allocation and its actual preserved rights construct the
RSP store after real PUSH local allocation. Other rows, other blocks and old
caller data are framed by actual byte disjointness and source freshness. -/
theorem write {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) :
    ∃ after, CC.Mem.store CC.Mptr (allocation ready.after).2 ready.gprs.block 64 (.Vlong nextRsp) = some after ∧
    CC.Mem.load CC.Mptr after ready.gprs.block 64 = some (.Vlong nextRsp) ∧
    (∀ row : Fin 32, row ≠ 8 → CC.Mem.load (X86ProducerGprStore.chunk row) after ready.gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) (allocation ready.after).2 ready.gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ ready.gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c (allocation ready.after).2 b ofs) ∧
    FrameBelow before.nextblock (allocation ready.after).2 after ∧
    after.access = (allocation ready.after).2.access ∧ after.nextblock = (allocation ready.after).2.nextblock := by
  have size : CC.sizeof ge.genv_cenv (X86ProducerHeaderSource.localType (0 : Fin 24)) = 256 := by
    change CC.sizeof ge.genv_cenv X86ProducerGprAddress.registersType = 256
    simpa only [X86ProducerGprAddress.registersType, CC.sizeof, X86ProducerLayout.layouts.2.2.2]
      using X86ProducerLayout.registers_layout.1
  have rangeWritable := CC.Mem.rangePerm_implies ready.gprs.range
    (show CC.permOrder .Freeable .Writable = true by decide +kernel)
  have oldGprs : ready.gprs.block.toNat < ready.after.nextblock.toNat := by
    rw [ready.frontier]
    exact ready.gprs.owned
  have writableReady : CC.Mem.validAccess ready.after CC.Mptr ready.gprs.block 64 .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro point lower upper
      have permission := CC.Mem.rangePerm_perm (X86ProducerCacheAllocation.allocation ge.genv_cenv before).2 ready.gprs.block 0
        (CC.sizeof ge.genv_cenv (X86ProducerHeaderSource.localType (0 : Fin 24))) .Cur .Writable rangeWritable point
          (by omega) (by rw [size]; change point < 256; change point < 64 + 8 at upper; omega)
      simpa only [CC.Mem.perm, ready.access] using permission
    · rfl
  have writable : CC.Mem.validAccess (allocation ready.after).2 CC.Mptr ready.gprs.block 64 .Writable = true :=
    (X86ProducerPushResources.old_access ready.after _ oldGprs _ _ _).trans writableReady
  obtain ⟨after, stored⟩ : ∃ after, CC.Mem.store CC.Mptr (allocation ready.after).2 ready.gprs.block 64 (.Vlong nextRsp) = some after := by
    simp only [CC.Mem.store, writable, ite_true]
    exact ⟨_, rfl⟩
  have disjoint : ∀ row : Fin 32, row ≠ 8 →
      X86ProducerGprStore.offset row + CC.sizeChunk (X86ProducerGprStore.chunk row) ≤ 64 ∨
      64 + CC.sizeChunk CC.Mptr ≤ X86ProducerGprStore.offset row := by decide +kernel
  refine ⟨after, stored, ?_, ?_, ?_, FrameBelow.store ready.gprs.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · exact CC.Mem.load_store_same stored
  · intro row different
    exact CC.Mem.load_store_other stored _ _ _ (.inr (disjoint row different))
  · intro c b ofs different
    exact CC.Mem.load_store_other stored c b ofs (.inl different)

end KProgFormal.ClightRefinement.X86ProducerPushRspStore
