import KProgFormal.ClightRefinement.Arm64VectorWritable

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.VectorMemory

/-- The original CNT branch assigns vector0's low half, then its high half. -/
def Effect (before after : CC.Mem) (block : CC.Block) (low high : BitVec 64) : Prop :=
  ∃ middle, CC.Mem.store .Mint64 before block 0 (.Vlong low) = some middle ∧
    CC.Mem.store .Mint64 middle block 8 (.Vlong high) = some after

private theorem exists_store (m : CC.Mem) (block : CC.Block) (offset : Int) (value : BitVec 64)
    (writable : CC.Mem.validAccess m .Mint64 block offset .Writable = true) :
    ∃ after, CC.Mem.store .Mint64 m block offset (.Vlong value) = some after := by
  simp only [CC.Mem.store,writable,ite_true]
  exact ⟨_,rfl⟩

/-- Original allocation permissions supply both real stores, including the
second permission transported through the first actual assignment. -/
theorem write {initial before : CC.Mem} (vectors : Arm64Producer.VectorLocal initial)
    (writable : Arm64VectorWritable.Writable vectors before) (low high : BitVec 64) :
    ∃ after, Effect before after vectors.block low high ∧ Arm64VectorWritable.Writable vectors after := by
  obtain ⟨middle,lowStore⟩ := exists_store before vectors.block 0 low
    (Arm64VectorWritable.half vectors writable false 0)
  have middleWritable := Arm64VectorWritable.store vectors writable _ _ _ _ lowStore
  obtain ⟨after,highStore⟩ := exists_store middle vectors.block 8 high
    (Arm64VectorWritable.half vectors middleWritable true 0)
  exact ⟨after,⟨middle,lowStore,highStore⟩,
    Arm64VectorWritable.store vectors middleWritable _ _ _ _ highStore⟩

theorem Effect.low {before after : CC.Mem} {block : CC.Block} {low high : BitVec 64}
    (effect : Effect before after block low high) : CC.Mem.load .Mint64 after block 0 = some (.Vlong low) := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  rw [CC.Mem.load_store_other highStore .Mint64 block 0 (.inr (.inl (by decide +kernel)))]
  exact CC.Mem.load_store_same lowStore

theorem Effect.high {before after : CC.Mem} {block : CC.Block} {low high : BitVec 64}
    (effect : Effect before after block low high) : CC.Mem.load .Mint64 after block 8 = some (.Vlong high) := by
  obtain ⟨middle,_,highStore⟩ := effect
  exact CC.Mem.load_store_same highStore

/-- Every chunk on another block retains its complete successful or refused load. -/
theorem Effect.other {before after : CC.Mem} {block : CC.Block} {low high : BitVec 64}
    (effect : Effect before after block low high) (chunk : CC.Chunk) (other : CC.Block) (offset : Int)
    (different : other ≠ block) : CC.Mem.load chunk after other offset = CC.Mem.load chunk before other offset := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.load_store_other highStore chunk other offset (.inl different)).trans
    (CC.Mem.load_store_other lowStore chunk other offset (.inl different))

private theorem disjoint_halves : ∀ (high : Bool) (i : Fin 32), i ≠ 0 →
    (0 + 8 ≤ 16 * (i.val : Int) + (if high then 8 else 0)) ∧
    (8 + 8 ≤ 16 * (i.val : Int) + (if high then 8 else 0)) := by decide +kernel

/-- Both halves of all 31 other vectors retain their original raw load. -/
theorem Effect.other_half {before after : CC.Mem} {block : CC.Block} {low high : BitVec 64}
    (effect : Effect before after block low high) (upper : Bool) (i : Fin 32) (different : i ≠ 0) :
    CC.Mem.load .Mint64 after block (16 * (i.val : Int) + (if upper then 8 else 0)) =
      CC.Mem.load .Mint64 before block (16 * (i.val : Int) + (if upper then 8 else 0)) := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.load_store_other highStore .Mint64 block _ (.inr (.inr (disjoint_halves upper i different).2))).trans
    (CC.Mem.load_store_other lowStore .Mint64 block _ (.inr (.inr (disjoint_halves upper i different).1)))

theorem Effect.access {before after : CC.Mem} {block : CC.Block} {low high : BitVec 64}
    (effect : Effect before after block low high) : after.access = before.access := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.store_access highStore).trans (CC.Mem.store_access lowStore)

theorem Effect.nextblock {before after : CC.Mem} {block : CC.Block} {low high : BitVec 64}
    (effect : Effect before after block low high) : after.nextblock = before.nextblock := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.store_nextblock highStore).trans (CC.Mem.store_nextblock lowStore)

end KProgFormal.ClightRefinement.Arm64Cnt.VectorMemory
