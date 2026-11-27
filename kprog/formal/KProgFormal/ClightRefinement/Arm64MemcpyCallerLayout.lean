import KProgFormal.ClightRefinement.Arm64MemcpyLinkOrdinary
import KProgFormal.ClightRefinement.Arm64ProducerRegisterStorage

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemcpyCallerLayout
open Arm64Producer (HeaderLocal tableName tableType tableCellName)
open Arm64ProducerRegisterStorage (Storage)
open Arm64MemcpyLinkCall (Header slot)

/-- Actual producer pointer slots cannot all denote offsets in a single dense
block. Both word and tag cases follow from the original local allocation,
not a proposed cross-source memory equality. -/
theorem not_dense {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (tags : Bool)
    (base : CC.Block) (offsets : Fin 31 → CC.Integers.Ptrofs) :
    ¬ ∀ i : Fin 31, CC.Mem.load CC.Mptr memory
      (storage.tables tags).tableBlock (8 * (i.val : Int)) =
        some (.Vptr base (offsets i)) := by
  intro dense
  have cell (i : Fin 31) : (storage.tables tags).cellBlock i = base := by
    have values := Option.some.inj ((storage.slots tags i).symm.trans (dense i))
    exact CC.Val.Vptr.inj values |>.1
  exact storage.cells_distinct tags tags 0 1 (.inr (by decide))
    ((cell 0).trans (cell 1).symm)

/-- At the same pointer, offset8 is the borrowed tag-table root. It is not
the dense word-array root used by the separate Addressing source unit. -/
theorem header_registers {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (h : Header memory entry.block 0) :
    h.registers = (storage.tables true).tableBlock ∧ h.registerOffset = 0 := by
  have header : CC.Mem.load CC.Mptr memory entry.block 8 =
      some (.Vptr h.registers h.registerOffset) := h.registersRead
  have root : CC.Mem.load CC.Mptr memory entry.block 8 =
      some (.Vptr (storage.tables true).tableBlock 0) := storage.roots true
  exact CC.Val.Vptr.inj (Option.some.inj (header.symm.trans root))

private theorem cell_table_names : ∀ (tags : Bool) (i : Fin 31),
    tableCellName tags i ≠ tableName true := by decide +kernel

/-- The misinterpreted dense word target is a different allocated block from
EVERY actual producer word/tag cell, including X30. -/
theorem header_target_separate {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (h : Header memory entry.block 0)
    (tags : Bool) (i : Fin 31) :
    h.registers ≠ (storage.tables tags).cellBlock i := by
  rw [(header_registers storage h).1]
  exact (storage.separate_local tags i _ _ _
    (storage.tables true).binding (cell_table_names tags i)).symm

/-- A scalar store at that wrong dense word target preserves each original
cell's imported load. Its successful memory operation cannot establish a
write of the real producer X30. -/
theorem wrong_header_store_frame {initial memory after : CC.Mem}
    {entry : HeaderLocal initial} (storage : Storage initial memory entry)
    (h : Header memory entry.block 0) (address : BitVec 64)
    (stored : CC.Mem.store .Mint64 memory h.registers
      (slot h.registerOffset 240) (.Vlong address) = some after)
    (tags : Bool) (i : Fin 31) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after ((storage.tables tags).cellBlock i) offset =
      CC.Mem.load chunk memory ((storage.tables tags).cellBlock i) offset :=
  CC.Mem.load_store_other stored chunk _ _
    (.inl (header_target_separate storage h tags i).symm)

/-- Original allocation-bound locals also exclude ANY same-heap dense table
bridge, including a new temporary table constructed after the LINK call,
if it is identified with the producer's actual table roots. -/
theorem no_same_table {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial memory entry) (tags : Bool)
    (table base : CC.Block) (offsets : Fin 31 → CC.Integers.Ptrofs)
    (dense : ∀ i : Fin 31, CC.Mem.load CC.Mptr memory table
      (8 * (i.val : Int)) = some (.Vptr base (offsets i))) :
    table ≠ (storage.tables tags).tableBlock := by
  intro same
  subst table
  exact not_dense storage tags base offsets dense

end KProgFormal.ClightRefinement.Arm64MemcpyCallerLayout
