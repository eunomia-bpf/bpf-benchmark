import KProgFormal.ClightRefinement.Arm64FmovVectorStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.VectorView

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView

/-- The complete actual GPR pointer walk keeps every value/tag observation. -/
theorem gpr {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value) (i : Fin 31) :
    Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) i.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) i.val := by
  rw [← effect.nextblock,Arm64RegisterWrite.storage_gpr (VectorStorage.storage old value effect),
    effect.nextblock,Arm64RegisterWrite.storage_gpr old]
  change (do let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock i) 0
             let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock i) 0
             pure (word,tag)) = _
  rw [VectorStorage.cell old value effect false i,VectorStorage.cell old value effect true i]

private theorem storage_sp {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial memory entry) :
    Arm64EntryMemory.borrowed memory.nextblock .Mint64 memory (.Vptr entry.block 0) Arm64Program._sp =
      some (.Vlong old.spValue) :=
  header_borrowed_readback memory entry.block 5 .Mint64 old.sp.block 0 _ old.spPointer old.spRead

theorem sp {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value) :
    Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0) Arm64Program._sp =
      Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0) Arm64Program._sp := by
  rw [← effect.nextblock,storage_sp (VectorStorage.storage old value effect),effect.nextblock,storage_sp old]
  rfl

private theorem flag {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value) (i : Fin 4) :
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) (headerField (flagIndex i)) =
      Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) (headerField (flagIndex i)) := by
  rw [← effect.nextblock,Arm64RegisterWrite.storage_flag (VectorStorage.storage old value effect),
    effect.nextblock,Arm64RegisterWrite.storage_flag old]
  exact VectorStorage.flag old value effect i _ _

theorem flags {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value) :
    Arm64EntryMemory.flags before.nextblock after (.Vptr entry.block 0) =
      Arm64EntryMemory.flags before.nextblock before (.Vptr entry.block 0) := by
  have n := flag old value effect 0
  have z := flag old value effect 1
  have c := flag old value effect 2
  have v := flag old value effect 3
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) Arm64Program._n =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) Arm64Program._n at n
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) Arm64Program._z =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) Arm64Program._z at z
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) Arm64Program._c =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) Arm64Program._c at c
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) Arm64Program._v =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) Arm64Program._v at v
  simp only [Arm64EntryMemory.flags,n,z,c,v]

/-- The actual vector3 pointer walk observes the two original assignments. -/
theorem selected {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value) :
    Arm64EntryMemory.vector before.nextblock after (.Vptr entry.block 0) 3 = some (.Vlong value,.Vlong 0) := by
  rw [← effect.nextblock,Arm64RegisterWrite.storage_vector (VectorStorage.storage old value effect)]
  change (do let lo ← CC.Mem.load .Mint64 after old.vectors.block 48
             let hi ← CC.Mem.load .Mint64 after old.vectors.block 56
             pure (lo,hi)) = _
  simp only [effect.low,effect.high,bind,Option.bind_some,pure]

/-- Both actual pointer slots and half-loads for every other vector retain
their exact observation, including failed or undefined reads. -/
theorem other {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value) (i : Fin 32) (different : i ≠ 3) :
    Arm64EntryMemory.vector before.nextblock after (.Vptr entry.block 0) i =
      Arm64EntryMemory.vector before.nextblock before (.Vptr entry.block 0) i := by
  rw [← effect.nextblock,Arm64RegisterWrite.storage_vector (VectorStorage.storage old value effect),
    effect.nextblock,Arm64RegisterWrite.storage_vector old]
  change (do let lo ← CC.Mem.load .Mint64 after old.vectors.block (vectorLoopSourceOffset false i).unsigned
             let hi ← CC.Mem.load .Mint64 after old.vectors.block (vectorLoopSourceOffset true i).unsigned
             pure (lo,hi)) = _
  have low := effect.other_half false i different
  have high := effect.other_half true i different
  simp only [Bool.false_eq_true,ite_false,ite_true] at low high
  simp only [(vector_loop_offsets false i).2,(vector_loop_offsets true i).2,
    Bool.false_eq_true,ite_false,ite_true,low,high]

end KProgFormal.ClightRefinement.Arm64Fmov.VectorView
