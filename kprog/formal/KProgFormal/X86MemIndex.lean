import KProgFormal.GeneratedX86MemIndex
import KProgFormal.GeneratedX86MemOffset
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86MemIndex (Arm arm absent present indexSentinel)
open GeneratedX86MemOffset (value valueSpec)

/-- Independent statement of the index-arm selection from the `AUX` index byte:
the sentinel byte names the absent arm, every other byte the present arm,
written against the literal `0xff` rather than the generated `indexSentinel`. -/
def x86MemIndexArmSpec (indexByte : BitVec 8) : Arm :=
  if indexByte = (0xff : BitVec 8) then .absent else .present

/-- Independent statement of index presence: an addressing mode carries an index
register exactly when its `AUX` index byte differs from the sentinel `0xff`. -/
def x86MemIndexPresentSpec (indexByte : BitVec 8) : Bool :=
  decide (indexByte ≠ (0xff : BitVec 8))

/-- The generated arm selector equals the independent literal-sentinel table for
every index byte, including the sentinel boundary. -/
theorem x86_mem_index_arm_refines (indexByte : BitVec 8) :
    arm indexByte = x86MemIndexArmSpec indexByte := by
  unfold arm x86MemIndexArmSpec indexSentinel
  by_cases h : indexByte = (0xff : BitVec 8) <;> simp [h]

/-- The generated presence predicate equals the independent literal-sentinel
inequality for every index byte. -/
theorem x86_mem_index_present_refines (indexByte : BitVec 8) :
    present indexByte = x86MemIndexPresentSpec indexByte := by
  unfold present arm x86MemIndexPresentSpec indexSentinel
  by_cases h : indexByte = (0xff : BitVec 8) <;>
    simp_all [decide_eq_false_iff_not]

/-- The sentinel is the all-ones byte, pinned so the C
`KPROG_X86_MEM_INDEX_SENTINEL` value and the generated `indexSentinel` cannot
drift apart. -/
theorem x86_mem_index_sentinel_is_0xff : indexSentinel = 0xff := rfl

/-- The sentinel byte names the absent arm, so a mode with no index register is
exactly the one whose `AUX` index byte is `0xff`. -/
theorem x86_mem_index_sentinel_is_absent : arm indexSentinel = .absent := rfl

/-- The two arms are complementary and total: `absent` inverts `present`, so no
index byte is neither and none is both. -/
theorem x86_mem_index_absent_complement (indexByte : BitVec 8) :
    absent (arm indexByte) = !present indexByte := by
  unfold present arm absent indexSentinel
  by_cases h : indexByte = (0xff : BitVec 8) <;> simp_all [arm, absent]

/-- The two presence cases are exactly the two `hasIndex` cases the offset
contract consumes: an index byte at the sentinel takes the displacement-only
`valueSpec false` arm, and a non-sentinel byte the indexed `valueSpec true`
arm. -/
theorem x86_mem_index_consumes_has_index (scale disp index : BitVec 64) :
    value (present indexSentinel) scale disp index =
        valueSpec false scale disp index ∧
      value (present (0x01 : BitVec 8)) scale disp index =
        valueSpec true scale disp index := by
  unfold present arm value valueSpec indexSentinel
  simp

/-- Both arms are reachable: the sentinel byte selects the absent arm and its two
neighbours select the present arm, so neither arm of the contract is dead. -/
theorem x86_mem_index_case_dispatch :
    present (0xff : BitVec 8) = false ∧
      present (0xfe : BitVec 8) = true ∧
      present (0x00 : BitVec 8) = true := by
  refine ⟨?_, ?_, ?_⟩ <;>
    unfold present arm indexSentinel <;> native_decide

/-- Canonical examples: the arm selector on the sentinel and on plain register
numbers, pinning the boundary against concrete values. -/
theorem x86_mem_index_examples :
    arm (0xff : BitVec 8) = .absent ∧ arm (0x00 : BitVec 8) = .present ∧
      arm (0x07 : BitVec 8) = .present ∧
      present (0xff : BitVec 8) = false ∧ present (0x07 : BitVec 8) = true := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

end KProgFormal
