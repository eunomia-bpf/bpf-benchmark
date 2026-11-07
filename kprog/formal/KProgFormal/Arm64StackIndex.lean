import KProgFormal.Generated.GeneratedArm64StackIndex
import Std.Tactic.BVDecide

namespace KProgFormal
open GeneratedArm64StackIndex (index ptrIndex)

/-- Native-address subtraction and arena bias retain every address bit. -/
def arm64StackIndexSpec (bias off : BitVec 64) : BitVec 64 :=
  off - (-bias)

theorem arm64_stack_index_refines (bias off : BitVec 64) :
    index bias off = arm64StackIndexSpec bias off := by
  unfold index arm64StackIndexSpec
  bv_decide

theorem arm64_stack_index_frame_base (bias : BitVec 64) :
    index bias (-bias) = 0 := by
  unfold index
  bv_decide

theorem arm64_stack_index_base_is_bias (bias : BitVec 64) :
    index bias 0 = bias := by
  unfold index
  bv_decide

theorem arm64_stack_index_step (bias off delta : BitVec 64) :
    index bias (off + delta) = index bias off + delta := by
  unfold index
  bv_decide

/-- Biasing cannot collapse distinct native addresses, including high32. -/
theorem arm64_stack_index_injective (bias off off' : BitVec 64) :
    index bias off' = index bias off ↔ off' = off := by
  unfold index
  bv_decide

theorem arm64_stack_index_ptr_equal (bias off : BitVec 64) :
    index bias off = ptrIndex bias off := by rfl

theorem arm64_stack_index_ptr_sum (bias off : BitVec 64) :
    ptrIndex bias off = bias + off := by rfl

theorem arm64_stack_index_example :
    index 96 (-96) = 0 ∧ index 96 0 = 96 ∧ index 96 8 = 104 ∧
      index 96 64 = 160 := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

theorem arm64_stack_index_wrap_example :
    index 96 (-97) = 0xffffffffffffffff ∧
      index 96 (-100) = 0xfffffffffffffffc := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Both directions of the old 4GiB alias remain outside the arena. -/
theorem arm64_stack_index_high32 :
    index 32 (0x100000000 - 32) = 0x100000000 ∧
      index 32 (-0x100000000 - 32) = 0xffffffff00000000 := by
  refine ⟨?_, ?_⟩ <;> native_decide
end KProgFormal
