import KProgFormal.GeneratedArm64PairMem
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64PairMem (Op Access)

/-- Independent statement of the two AArch64 pair-move transfers: the ordered
list of byte offsets each opcode touches. It is written directly as the slot
plan (`[0, 8]` for both), never as the generated index arithmetic, so the two
agree on which slots a body touches and how many. -/
def arm64PairMemSlotPlanSpec : Op -> List Nat
  | .ldp => [0, 8]
  | .stp => [0, 8]

/-- The ordered slot offsets the generated contract produces: the slot count's
many slot indices, each mapped through the generated slot offset. -/
def arm64PairMemSlotList (op : Op) : List Nat :=
  (List.range (GeneratedArm64PairMem.slotCount op)).map
    (GeneratedArm64PairMem.slotOffset op)

/-- The generated pair plan equals the independent plan for every opcode: the
same two slots, in the same order, with the same offsets. -/
theorem arm64_pair_mem_refines (op : Op) :
    arm64PairMemSlotList op = arm64PairMemSlotPlanSpec op := by
  cases op <;> rfl

/-- The generated slot count equals the length of the independent plan for every
opcode. -/
theorem arm64_pair_mem_slot_count_refines (op : Op) :
    GeneratedArm64PairMem.slotCount op =
      (arm64PairMemSlotPlanSpec op).length := by
  cases op <;> rfl

/-- **The access direction is a per-opcode fact**: `LDP` loads a register pair
from memory, `STP` stores one to memory. -/
theorem arm64_pair_mem_access_dispatch :
    GeneratedArm64PairMem.access .ldp = Access.load ∧
    GeneratedArm64PairMem.access .stp = Access.store := by
  refine ⟨rfl, rfl⟩

/-- **The pair plan is a per-opcode fact**: both opcodes move exactly two 64-bit
slots, the low slot at offset 0 and the high slot one slot stride higher. This
is the property the two C bodies rely on. -/
theorem arm64_pair_mem_slot_plan :
    arm64PairMemSlotPlanSpec .ldp = [0, 8] ∧
    arm64PairMemSlotPlanSpec .stp = [0, 8] := by
  refine ⟨rfl, rfl⟩

/-- Both pair moves transfer exactly two slots: the count is opcode-independent,
as a pair move always names a register pair. -/
theorem arm64_pair_mem_slot_count :
    (arm64PairMemSlotPlanSpec .ldp).length = 2 ∧
    (arm64PairMemSlotPlanSpec .stp).length = 2 := by
  refine ⟨rfl, rfl⟩

/-- A pair move always transfers two *distinct* slots: the high slot is eight
bytes above the low slot, so a body that wrote the low slot twice would not
satisfy the plan. -/
theorem arm64_pair_mem_moves_distinct_slots :
    arm64PairMemSlotPlanSpec .ldp = [0, 8] ∧
    arm64PairMemSlotPlanSpec .stp = [0, 8] ∧
    (arm64PairMemSlotPlanSpec .ldp).get ⟨0, by decide⟩ ≠
      (arm64PairMemSlotPlanSpec .ldp).get ⟨1, by decide⟩ := by
  refine ⟨rfl, rfl, ?_⟩
  decide

/-- The generated slot stride is the 64-bit slot width: the second slot of a
pair move is 8 bytes above the first, for every opcode. -/
theorem arm64_pair_mem_slot_stride (op : Op) :
    GeneratedArm64PairMem.slotOffset op 1 = 8 := by
  cases op <;> rfl

/-- The generated dispatch indices are `0, 1`, so the two-way C chain
`LDP / STP` covers each opcode exactly once, in the order the arm index
names. -/
theorem arm64_pair_mem_arm_index_dispatch :
    GeneratedArm64PairMem.armIndex .ldp = 0 ∧
    GeneratedArm64PairMem.armIndex .stp = 1 := by
  refine ⟨rfl, rfl⟩

/-- Canonical example: the low slot of a pair move is read/written at the base
offset itself, for both opcodes. -/
theorem arm64_pair_mem_low_slot_example :
    GeneratedArm64PairMem.slotOffset .ldp 0 = 0 ∧
    GeneratedArm64PairMem.slotOffset .stp 0 = 0 := by
  refine ⟨rfl, rfl⟩

/-- Canonical example: the high slot of a pair move sits eight bytes above the
low slot, so the two together span the full 16-byte register pair. -/
theorem arm64_pair_mem_high_slot_example :
    GeneratedArm64PairMem.slotOffset .ldp 1 = 8 ∧
    GeneratedArm64PairMem.slotOffset .stp 1 = 8 := by
  refine ⟨rfl, rfl⟩

end KProgFormal
