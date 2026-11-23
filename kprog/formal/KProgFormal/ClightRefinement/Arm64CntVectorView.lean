import KProgFormal.ClightRefinement.Arm64CntVectorStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.VectorView

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView

theorem gpr {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high) (i : Fin 31) :
    Arm64EntryMemory.gpr before.nextblock after (.Vptr entry.block 0) i.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) i.val := by
  rw [← effect.nextblock,Arm64RegisterWrite.storage_gpr (VectorStorage.storage old low high effect),
    effect.nextblock,Arm64RegisterWrite.storage_gpr old]
  change (do let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock i) 0
             let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock i) 0
             pure (word,tag)) = _
  rw [VectorStorage.cell old low high effect false i,VectorStorage.cell old low high effect true i]

private theorem storage_sp {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial memory entry) :
    Arm64EntryMemory.borrowed memory.nextblock .Mint64 memory (.Vptr entry.block 0) Arm64Program._sp =
      some (.Vlong old.spValue) :=
  header_borrowed_readback memory entry.block 5 .Mint64 old.sp.block 0 _ old.spPointer old.spRead

theorem sp {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high) :
    Arm64EntryMemory.borrowed before.nextblock .Mint64 after (.Vptr entry.block 0) Arm64Program._sp =
      Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0) Arm64Program._sp := by
  rw [← effect.nextblock,storage_sp (VectorStorage.storage old low high effect),effect.nextblock,storage_sp old]
  rfl

private theorem flag {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high) (i : Fin 4) :
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) (headerField (flagIndex i)) =
      Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) (headerField (flagIndex i)) := by
  rw [← effect.nextblock,Arm64RegisterWrite.storage_flag (VectorStorage.storage old low high effect),
    effect.nextblock,Arm64RegisterWrite.storage_flag old]
  exact VectorStorage.flag old low high effect i _ _

theorem flags {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high) :
    Arm64EntryMemory.flags before.nextblock after (.Vptr entry.block 0) =
      Arm64EntryMemory.flags before.nextblock before (.Vptr entry.block 0) := by
  have n := flag old low high effect 0
  have z := flag old low high effect 1
  have c := flag old low high effect 2
  have v := flag old low high effect 3
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) Arm64Program._n =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) Arm64Program._n at n
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) Arm64Program._z =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) Arm64Program._z at z
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) Arm64Program._c =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) Arm64Program._c at c
  change Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned after (.Vptr entry.block 0) Arm64Program._v =
    Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0) Arm64Program._v at v
  simp only [Arm64EntryMemory.flags,n,z,c,v]

/-- The original vector0 pointer walk reads both actual stored count words. -/
theorem selected {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high) :
    Arm64EntryMemory.vector before.nextblock after (.Vptr entry.block 0) 0 = some (.Vlong low,.Vlong high) := by
  rw [← effect.nextblock,Arm64RegisterWrite.storage_vector (VectorStorage.storage old low high effect)]
  change (do let lo ← CC.Mem.load .Mint64 after old.vectors.block 0
             let hi ← CC.Mem.load .Mint64 after old.vectors.block 8
             pure (lo,hi)) = _
  simp only [effect.low,effect.high,bind,Option.bind_some,pure]

theorem other {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high) (i : Fin 32) (different : i ≠ 0) :
    Arm64EntryMemory.vector before.nextblock after (.Vptr entry.block 0) i =
      Arm64EntryMemory.vector before.nextblock before (.Vptr entry.block 0) i := by
  rw [← effect.nextblock,Arm64RegisterWrite.storage_vector (VectorStorage.storage old low high effect),
    effect.nextblock,Arm64RegisterWrite.storage_vector old]
  change (do let lo ← CC.Mem.load .Mint64 after old.vectors.block (vectorLoopSourceOffset false i).unsigned
             let hi ← CC.Mem.load .Mint64 after old.vectors.block (vectorLoopSourceOffset true i).unsigned
             pure (lo,hi)) = _
  have lowRead := effect.other_half false i different
  have highRead := effect.other_half true i different
  simp only [Bool.false_eq_true,ite_false,ite_true] at lowRead highRead
  simp only [(vector_loop_offsets false i).2,(vector_loop_offsets true i).2,
    Bool.false_eq_true,ite_false,ite_true,lowRead,highRead]

end KProgFormal.ClightRefinement.Arm64Cnt.VectorView
