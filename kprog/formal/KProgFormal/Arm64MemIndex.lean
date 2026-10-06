import KProgFormal.GeneratedArm64MemIndex
import KProgFormal.GeneratedArm64MemOffset
import KProgFormal.GeneratedArm64Aux
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64MemIndex (Arm arm absent present indexSentinel)
open GeneratedArm64MemOffset (value valueSpec)
open GeneratedArm64Aux (regNone)

/-- Independent statement of the index-arm selection from the `AUX` index lane:
the sentinel byte names the absent arm, every other byte the present arm,
written against the literal `0xff` rather than the generated `indexSentinel`. -/
def arm64MemIndexArmSpec (indexByte : BitVec 8) : Arm :=
  if indexByte = (0xff : BitVec 8) then .absent else .present

/-- Independent statement of index presence: an addressing mode carries an index
register exactly when its `AUX` index lane differs from the sentinel `0xff`. -/
def arm64MemIndexPresentSpec (indexByte : BitVec 8) : Bool :=
  decide (indexByte ≠ (0xff : BitVec 8))

/-- The generated arm selector equals the independent literal-sentinel table for
every index byte, including the sentinel boundary. -/
theorem arm64_mem_index_arm_refines (indexByte : BitVec 8) :
    arm indexByte = arm64MemIndexArmSpec indexByte := by
  unfold arm arm64MemIndexArmSpec indexSentinel
  by_cases h : indexByte = (0xff : BitVec 8) <;> simp [h]

/-- The generated presence predicate equals the independent literal-sentinel
inequality for every index byte. -/
theorem arm64_mem_index_present_refines (indexByte : BitVec 8) :
    present indexByte = arm64MemIndexPresentSpec indexByte := by
  unfold present arm arm64MemIndexPresentSpec indexSentinel
  by_cases h : indexByte = (0xff : BitVec 8) <;>
    simp_all [decide_eq_false_iff_not]

/-- The sentinel is the all-ones byte, pinned so the C
`KPROG_ARM64_MEM_INDEX_SENTINEL` value and the generated `indexSentinel` cannot
drift apart. -/
theorem arm64_mem_index_sentinel_is_0xff : indexSentinel = 0xff := rfl

/-- The sentinel byte names the absent arm, so a mode with no index register is
exactly the one whose `AUX` index lane is `0xff`. -/
theorem arm64_mem_index_sentinel_is_absent : arm indexSentinel = .absent := rfl

/-- The two index contracts share one sentinel: the memory-index sentinel is the
`ARM64_REG_NONE` lane value the AUX contract pins, so an index decoder and the
AUX layout cannot disagree about "no index register". -/
theorem arm64_mem_index_sentinel_is_aux_reg_none :
    indexSentinel.setWidth 32 = regNone := rfl

/-- The two arms are complementary and total: `absent` inverts `present`, so no
index byte is neither and none is both. -/
theorem arm64_mem_index_absent_complement (indexByte : BitVec 8) :
    absent (arm indexByte) = !present indexByte := by
  unfold present arm absent indexSentinel
  by_cases h : indexByte = (0xff : BitVec 8) <;> simp_all [arm, absent]

/-- The two presence cases are exactly the two `hasIndex` cases the offset
contract consumes: an index byte at the sentinel takes the displacement-only
`valueSpec false` arm, and a non-sentinel byte the indexed `valueSpec true`
arm. -/
theorem arm64_mem_index_consumes_has_index (prepost : Bool)
    (imm index : BitVec 64) :
    value prepost (present indexSentinel) imm index =
        valueSpec prepost false imm index ∧
      value prepost (present (0x01 : BitVec 8)) imm index =
        valueSpec prepost true imm index := by
  unfold present arm value valueSpec indexSentinel
  by_cases h : prepost <;> simp [h]

/-- Both arms are reachable: the sentinel byte selects the absent arm and its two
neighbours select the present arm, so neither arm of the contract is dead. -/
theorem arm64_mem_index_case_dispatch :
    present (0xff : BitVec 8) = false ∧
      present (0xfe : BitVec 8) = true ∧
      present (0x00 : BitVec 8) = true := by
  refine ⟨?_, ?_, ?_⟩ <;>
    unfold present arm indexSentinel <;> decide

/-- Canonical examples: the arm selector on the sentinel and on plain register
numbers (lane 0 is shared with the ALU opcode, so an index register names a
small number), pinning the boundary against concrete values. -/
theorem arm64_mem_index_examples :
    arm (0xff : BitVec 8) = .absent ∧ arm (0x00 : BitVec 8) = .present ∧
      arm (0x1f : BitVec 8) = .present ∧
      present (0xff : BitVec 8) = false ∧ present (0x1f : BitVec 8) = true := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> decide

end KProgFormal
