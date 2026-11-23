import KProgFormal.ClightRefinement.Arm64VectorWritable

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.VectorMemory

/-- The two actual Mint64 assignments to vector3, in source order. -/
def Effect (before after : CC.Mem) (block : CC.Block) (value : BitVec 64) : Prop :=
  ∃ middle, CC.Mem.store .Mint64 before block 48 (.Vlong value) = some middle ∧
    CC.Mem.store .Mint64 middle block 56 (.Vlong 0) = some after

private theorem exists_store (m : CC.Mem) (block : CC.Block) (offset : Int) (value : BitVec 64)
    (writable : CC.Mem.validAccess m .Mint64 block offset .Writable = true) :
    ∃ after, CC.Mem.store .Mint64 m block offset (.Vlong value) = some after := by
  simp only [CC.Mem.store,writable,ite_true]
  exact ⟨_,rfl⟩

/-- Genuine allocation permissions derive both successful stores and the
post-memory; the second permission follows through the first actual store. -/
theorem write {initial before : CC.Mem} (vectors : Arm64Producer.VectorLocal initial)
    (writable : Arm64VectorWritable.Writable vectors before) (value : BitVec 64) :
    ∃ after, Effect before after vectors.block value ∧ Arm64VectorWritable.Writable vectors after := by
  have lowWritable : CC.Mem.validAccess before .Mint64 vectors.block 48 .Writable = true :=
    Arm64VectorWritable.half vectors writable false 3
  obtain ⟨middle,low⟩ := exists_store before vectors.block 48 value lowWritable
  have middleWritable := Arm64VectorWritable.store vectors writable _ _ _ _ low
  have highWritable : CC.Mem.validAccess middle .Mint64 vectors.block 56 .Writable = true :=
    Arm64VectorWritable.half vectors middleWritable true 3
  obtain ⟨after,high⟩ := exists_store middle vectors.block 56 0 highWritable
  exact ⟨after,⟨middle,low,high⟩,Arm64VectorWritable.store vectors middleWritable _ _ _ _ high⟩

theorem Effect.low {before after : CC.Mem} {block : CC.Block} {value : BitVec 64}
    (effect : Effect before after block value) : CC.Mem.load .Mint64 after block 48 = some (.Vlong value) := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  rw [CC.Mem.load_store_other highStore .Mint64 block 48 (.inr (.inl (by decide +kernel)))]
  exact CC.Mem.load_store_same lowStore

theorem Effect.high {before after : CC.Mem} {block : CC.Block} {value : BitVec 64}
    (effect : Effect before after block value) : CC.Mem.load .Mint64 after block 56 = some (.Vlong 0) := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact CC.Mem.load_store_same highStore

/-- Every chunk on another block retains its exact load, including refused
loads and pointer values, through both actual vector assignments. -/
theorem Effect.other {before after : CC.Mem} {block : CC.Block} {value : BitVec 64}
    (effect : Effect before after block value) (chunk : CC.Chunk) (other : CC.Block) (offset : Int)
    (different : other ≠ block) : CC.Mem.load chunk after other offset = CC.Mem.load chunk before other offset := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.load_store_other highStore chunk other offset (.inl different)).trans
    (CC.Mem.load_store_other lowStore chunk other offset (.inl different))

private theorem disjoint_halves : ∀ (high : Bool) (i : Fin 32), i ≠ 3 →
    (16 * (i.val : Int) + (if high then 8 else 0) + 8 ≤ 48 ∨
      56 ≤ 16 * (i.val : Int) + (if high then 8 else 0)) ∧
    (16 * (i.val : Int) + (if high then 8 else 0) + 8 ≤ 56 ∨
      64 ≤ 16 * (i.val : Int) + (if high then 8 else 0)) := by decide +kernel

/-- Both halves of every other vector retain their original raw load. -/
theorem Effect.other_half {before after : CC.Mem} {block : CC.Block} {value : BitVec 64}
    (effect : Effect before after block value) (high : Bool) (i : Fin 32) (different : i ≠ 3) :
    CC.Mem.load .Mint64 after block (16 * (i.val : Int) + (if high then 8 else 0)) =
      CC.Mem.load .Mint64 before block (16 * (i.val : Int) + (if high then 8 else 0)) := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.load_store_other highStore .Mint64 block _ (.inr (disjoint_halves high i different).2)).trans
    (CC.Mem.load_store_other lowStore .Mint64 block _ (.inr (disjoint_halves high i different).1))

theorem Effect.access {before after : CC.Mem} {block : CC.Block} {value : BitVec 64}
    (effect : Effect before after block value) : after.access = before.access := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.store_access highStore).trans (CC.Mem.store_access lowStore)

theorem Effect.nextblock {before after : CC.Mem} {block : CC.Block} {value : BitVec 64}
    (effect : Effect before after block value) : after.nextblock = before.nextblock := by
  obtain ⟨middle,lowStore,highStore⟩ := effect
  exact (CC.Mem.store_nextblock highStore).trans (CC.Mem.store_nextblock lowStore)

end KProgFormal.ClightRefinement.Arm64Fmov.VectorMemory
