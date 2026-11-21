import KProgFormal.ClightRefinement.Arm64RegisterStorageFrontier

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CacheLocalFrame

open Arm64Producer Arm64ProducerEntryView Arm64RegisterStorageFrontier

/-- Exact local observations outside the two selected GPR cells. Undefined
values, pointers and refused loads remain imported Mem observations. -/
def Kept (initial before after : CC.Mem) (i : Fin 31) : Prop :=
  ∀ id ty block, (allocation initial).1.get id = some (block, ty) →
    tableCellName false i ≠ id → tableCellName true i ≠ id →
    ∀ chunk offset, CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset

private theorem header_other : ∀ tags (i : Fin 31), tableCellName tags i ≠ Arm64Entry._entry := by decide +kernel
private theorem source_other : ∀ tags (i : Fin 31) (j : Fin 12),
    tableCellName tags i ≠ headerSourceName j := by decide +kernel

/-- Compose observations around actual allocation, writing and frame free. -/
theorem Kept.trans {initial before middle after : CC.Mem} {i : Fin 31}
    (first : Kept initial before middle i) (second : Kept initial middle after i) :
    Kept initial before after i := by
  intro id ty block binding word tag chunk offset
  exact (second id ty block binding word tag chunk offset).trans (first id ty block binding word tag chunk offset)

theorem of_frame {initial before after : CC.Mem} (frontier : CC.Block) (i : Fin 31)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier before after) : Kept initial before after i := by
  intro id ty block binding _ _ chunk offset
  exact frame.load chunk block offset (Nat.lt_of_lt_of_le (local_owned initial id ty block binding) bound)

/-- A real local cell outside the selected destination retains every raw load.
Both storage witnesses identify the same block through the original allocation;
no successful-load premise or replacement readback is introduced. -/
theorem Kept.cell_load {initial before after : CC.Mem} {i : Fin 31} {entry : HeaderLocal initial}
    (kept : Kept initial before after i)
    (beforeStorage : Arm64ProducerRegisterStorage.Storage initial before entry)
    (afterStorage : Arm64ProducerRegisterStorage.Storage initial after entry)
    (tags : Bool) (j : Fin 31) (different : i ≠ j) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after ((afterStorage.tables tags).cellBlock j) offset =
      CC.Mem.load chunk before ((beforeStorage.tables tags).cellBlock j) offset := by
  have outside (selected : Bool) : tableCellName selected i ≠ tableCellName tags j := by
    intro same
    have bindings := (beforeStorage.tables selected).cellBinding i
    rw [same] at bindings
    have blocks := congrArg Prod.fst (Option.some.inj
      (bindings.symm.trans ((beforeStorage.tables tags).cellBinding j)))
    exact beforeStorage.cells_distinct selected tags i j (Or.inr different) blocks
  have sameBlock : (afterStorage.tables tags).cellBlock j = (beforeStorage.tables tags).cellBlock j :=
    congrArg Prod.fst (Option.some.inj
    (((afterStorage.tables tags).cellBinding j).symm.trans
      ((beforeStorage.tables tags).cellBinding j)))
  rw [sameBlock]
  exact kept _ _ _ ((beforeStorage.tables tags).cellBinding j) (outside false) (outside true) chunk offset

/-- Every actual header pointer survives the selected GPR writes. -/
theorem Kept.pointers {initial before after : CC.Mem} {i : Fin 31} {entry : HeaderLocal initial}
    (kept : Kept initial before after i) (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) :
    ∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0) := by
  intro j
  exact (kept _ _ _ entry.binding (header_other false i) (header_other true i) CC.Mptr _).trans (pointers j)

/-- A typed canonical header/pointee walk collapses to its actual raw load,
including failed observations, at any owned frontier. -/
theorem borrowed_load {initial memory : CC.Mem} (frontier : CC.Block) (entry : HeaderLocal initial)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (pointers : ∀ j, CC.Mem.load CC.Mptr memory entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (j : Fin 12) (chunk : CC.Chunk) :
    Arm64EntryMemory.borrowed frontier chunk memory (.Vptr entry.block 0) (headerField j) =
      CC.Mem.load chunk memory (header j).block 0 := by
  rw [Arm64EntryMemory.borrowed,
    field_eq memory frontier entry.block (Nat.lt_of_lt_of_le entry.owned bound) 0 CC.Mptr _,
    header_field_readback memory entry.block j _ (pointers j)]
  simp only [bind, Option.bind_some, load_eq memory frontier (header j).block
    (Nat.lt_of_lt_of_le (header j).owned bound) chunk 0, Arm64RegisterWrite.checked_load_eq]
  rfl

theorem Kept.borrowed {initial before after : CC.Mem} {i : Fin 31} {entry : HeaderLocal initial}
    (kept : Kept initial before after i) (frontier : CC.Block)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (j : Fin 12) (chunk : CC.Chunk) :
    Arm64EntryMemory.borrowed frontier chunk after (.Vptr entry.block 0) (headerField j) =
      Arm64EntryMemory.borrowed frontier chunk before (.Vptr entry.block 0) (headerField j) := by
  rw [borrowed_load frontier entry header bound (kept.pointers header pointers), borrowed_load frontier entry header bound pointers]
  exact kept _ _ _ (header j).binding (source_other false i j) (source_other true i j) chunk 0

private theorem valid_field (returns : Bool) :
    headerField (if returns then 7 else 6) =
      (if returns then Arm64Program._return_valid else Arm64Program._sp_valid) := by cases returns <;> rfl
private theorem base_field (returns : Bool) :
    headerField (if returns then 3 else 2) =
      (if returns then Arm64Program._return_base else Arm64Program._sp_base) := by cases returns <;> rfl

/-- Preserve the existing warm-cache predicate; no new cache semantics. -/
theorem Kept.warm {initial before after : CC.Mem} {i : Fin 31} {entry : HeaderLocal initial}
    (kept : Kept initial before after i) (frontier : CC.Block)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (returns : Bool) (base : BitVec 64)
    (warm : Arm64RegisterReads.WarmEntryCache returns frontier before (.Vptr entry.block 0) base) :
    Arm64RegisterReads.WarmEntryCache returns frontier after (.Vptr entry.block 0) base := by
  obtain ⟨valid, nonzero, validRead, baseRead⟩ := warm
  have v := kept.borrowed frontier header bound pointers (if returns then 7 else 6) .Mint8unsigned
  have b := kept.borrowed frontier header bound pointers (if returns then 3 else 2) .Mint64
  rw [valid_field] at v
  rw [base_field] at b
  exact ⟨valid, nonzero, v.trans validRead, b.trans baseRead⟩

/-- Transport the same cache between an owned frontier and the real memory
frontier. This changes no read success or cache-validity premise. -/
theorem warm_iff {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (frontier : CC.Block) (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (pointers : ∀ j, CC.Mem.load CC.Mptr memory entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (returns : Bool) (base : BitVec 64) :
    Arm64RegisterReads.WarmEntryCache returns frontier memory (.Vptr entry.block 0) base ↔
      Arm64RegisterReads.WarmEntryCache returns memory.nextblock memory (.Vptr entry.block 0) base := by
  have v := borrowed_eq memory frontier entry.block (Nat.lt_of_lt_of_le entry.owned bound)
    (if returns then 7 else 6) _ 0 (Nat.lt_of_lt_of_le (header _).owned bound) .Mint8unsigned (pointers _)
  have b := borrowed_eq memory frontier entry.block (Nat.lt_of_lt_of_le entry.owned bound)
    (if returns then 3 else 2) _ 0 (Nat.lt_of_lt_of_le (header _).owned bound) .Mint64 (pointers _)
  rw [valid_field] at v
  rw [base_field] at b
  constructor
  · rintro ⟨valid, nonzero, vr, br⟩
    exact ⟨valid, nonzero, v.symm.trans vr, b.symm.trans br⟩
  · rintro ⟨valid, nonzero, vr, br⟩
    exact ⟨valid, nonzero, v.trans vr, b.trans br⟩

end KProgFormal.ClightRefinement.Arm64CacheLocalFrame
