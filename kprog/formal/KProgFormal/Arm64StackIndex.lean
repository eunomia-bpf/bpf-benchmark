import KProgFormal.GeneratedArm64StackIndex
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64StackIndex (index ptrIndex)

/-- Independent statement of the arena byte index: the low 32 bits of the
wrapping 64-bit bias-plus-offset sum, agreeing with the C macro
`((__u32)((__s64)(BIAS) + (__s64)(OFF)))`. -/
def arm64StackIndexSpec (bias off : BitVec 64) : BitVec 32 :=
  BitVec.setWidth 32 (bias + off)

/-- The generated truncation equals the independent 32-bit-width statement for
every bias and offset. -/
theorem arm64_stack_index_refines (bias off : BitVec 64) :
    index bias off = arm64StackIndexSpec bias off := by
  unfold index arm64StackIndexSpec BitVec.truncate
  bv_decide

/-- The frame base sits below the biased window: an abstract frame offset of
`-bias` (the value `__a64_sp` resolves to at the frame base) lands at arena byte
index 0. -/
theorem arm64_stack_index_frame_base (bias : BitVec 64) :
    index bias (-bias) = 0 := by
  unfold index
  bv_decide

/-- An offset of zero (the abstract frame base) lands at index `bias` in the
byte arena: the bottom of the biased window. -/
theorem arm64_stack_index_base_is_bias (bias : BitVec 64) :
    index bias 0 = bias.truncate 32 := by
  unfold index
  bv_decide

/-- The index is the affine offset `bias + off`: advancing the frame offset by
`delta` advances the arena index by the low 32 bits of `delta`. -/
theorem arm64_stack_index_step (bias off delta : BitVec 64) :
    index bias (off + delta) = index bias off + delta.truncate 32 := by
  unfold index
  bv_decide

/-- Two frame offsets that differ by a multiple of `2^32` alias to the same
arena index: only the low 32 bits of the sum reach the arena. -/
theorem arm64_stack_index_mod_2_32 (bias off off' : BitVec 64)
    (high : BitVec 64) (h : off' = off + BitVec.shiftLeft high 32) :
    index bias off' = index bias off := by
  subst h
  unfold index
  bv_decide

/-- The stack-pointer helper's 64-bit biased offset is the index before
truncation: `index` is `ptrIndex` narrowed to the index type. -/
theorem arm64_stack_index_ptr_truncation (bias off : BitVec 64) :
    index bias off = (ptrIndex bias off).truncate 32 := by
  rfl

/-- The pointer offset is the plain 64-bit biased sum. -/
theorem arm64_stack_index_ptr_sum (bias off : BitVec 64) :
    ptrIndex bias off = bias + off := by
  rfl

/-- Concrete arena: bias 96. The frame base (offset `-96`) is index 0, offset 0
is byte 96, offset 8 is word slot 13, offset 64 is the top of the frame window
at byte 160. -/
theorem arm64_stack_index_example :
    index 96 (-96) = 0 ∧ index 96 0 = 96 ∧ index 96 8 = 104 ∧
      index 96 64 = 160 := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> decide

/-- Concrete arena: bias 96. A negative offset below the frame base wraps, as
the 32-bit index of the biased arena byte. -/
theorem arm64_stack_index_wrap_example :
    index 96 (-97) = 0xffffffff ∧ index 96 (-100) = 0xfffffffc := by
  refine ⟨?_, ?_⟩ <;> decide

end KProgFormal
