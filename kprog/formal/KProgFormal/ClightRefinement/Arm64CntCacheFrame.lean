import KProgFormal.ClightRefinement.Arm64CntCaller

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Call

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView

variable {initial before written after : CC.Mem} {entry : HeaderLocal initial}
  {old : Storage initial before entry}
  {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
  {native : Reference.AArch64.State} {k : CC.Cont} {count : Nat}
  {finalStorage : Storage initial after entry}

private theorem source_other : ∀ j : Fin 12, headerSourceName j ≠ Arm64Entry.___a64_vectors := by decide +kernel

/-- The real CNT effect changes the vector array; every actual header
pointer slot remains available to the following original instructions. -/
theorem Result.pointers (result : Result old addresses origins native k count written after finalStorage)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) :
    ∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0) := by
  intro j
  exact (result.locals _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (pointers j)

theorem Result.borrowed (result : Result old addresses origins native k count written after finalStorage)
    (frontier : CC.Block) (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (j : Fin 12) (chunk : CC.Chunk) :
    Arm64EntryMemory.borrowed frontier chunk after (.Vptr entry.block 0) (headerField j) =
      Arm64EntryMemory.borrowed frontier chunk before (.Vptr entry.block 0) (headerField j) := by
  rw [Arm64CacheLocalFrame.borrowed_load frontier entry header bound (result.pointers header pointers),
    Arm64CacheLocalFrame.borrowed_load frontier entry header bound pointers]
  exact result.locals _ _ _ (header j).binding (source_other j) chunk 0

/-- The actual base/valid local loads preserve the existing warm-cache
predicate, while permitting the two real vector-data assignments. -/
theorem Result.warm (result : Result old addresses origins native k count written after finalStorage)
    (frontier : CC.Block) (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (returns : Bool) (base : BitVec 64)
    (warm : Arm64RegisterReads.WarmEntryCache returns frontier before (.Vptr entry.block 0) base) :
    Arm64RegisterReads.WarmEntryCache returns frontier after (.Vptr entry.block 0) base := by
  obtain ⟨valid,nonzero,validRead,baseRead⟩ := warm
  have v := result.borrowed frontier header bound pointers (if returns then 7 else 6) .Mint8unsigned
  have b := result.borrowed frontier header bound pointers (if returns then 3 else 2) .Mint64
  have validField : headerField (if returns then 7 else 6) =
      (if returns then Arm64Program._return_valid else Arm64Program._sp_valid) := by cases returns <;> rfl
  have baseField : headerField (if returns then 3 else 2) =
      (if returns then Arm64Program._return_base else Arm64Program._sp_base) := by cases returns <;> rfl
  rw [validField] at v
  rw [baseField] at b
  exact ⟨valid,nonzero,v.trans validRead,b.trans baseRead⟩

end KProgFormal.ClightRefinement.Arm64Cnt.Call
