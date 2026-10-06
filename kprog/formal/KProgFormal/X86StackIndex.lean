import KProgFormal.GeneratedX86StackIndex

namespace KProgFormal

open GeneratedX86StackIndex (index)

/-- Independent statement of the stack arena index: the low 32 bits of the
wrapping 64-bit frame-offset-plus-capacity sum, agreeing with the C macro
`((__u32)((__s64)(OFF) + (__s64)(CAPACITY)))`. -/
def x86StackIndexSpec (capacity off : BitVec 64) : BitVec 32 :=
  BitVec.setWidth 32 (off + capacity)

/-- The generated truncation equals the independent 32-bit-width statement for
every capacity and offset. -/
theorem x86_stack_index_refines (capacity off : BitVec 64) :
    index capacity off = x86StackIndexSpec capacity off := by
  unfold index x86StackIndexSpec BitVec.truncate
  bv_decide

/-- The frame base, offset `-capacity` (i.e. `0 - capacity`), lands at index 0:
the abstract frame base is the bottom of the arena. -/
theorem x86_stack_index_frame_base_is_zero (capacity : BitVec 64) :
    index capacity (-capacity) = 0 := by
  unfold index
  bv_decide

/-- An offset of zero (the arena top) lands at index `capacity` in the byte
arena. -/
theorem x86_stack_index_top_is_capacity (capacity : BitVec 64) :
    index capacity 0 = capacity.truncate 32 := by
  unfold index
  bv_decide

/-- Two frame offsets that differ by a multiple of `2^32` alias to the same
arena index: only the low 32 bits of the sum reach the arena. -/
theorem x86_stack_index_mod_2_32 (capacity off off' : BitVec 64)
    (high : BitVec 64) (h : off' = off + BitVec.shiftLeft high 32) :
    index capacity off' = index capacity off := by
  subst h
  unfold index
  bv_decide

/-- Concrete stack frame: capacity 64, an offset of `-56` (the first pushed
qword below the frame base) maps to byte index 8, and `-8` maps to 56. -/
theorem x86_stack_index_example :
    index 64 (-56) = 8 ∧ index 64 (-8) = 56 ∧ index 64 0 = 64 := by
  refine ⟨?_, ?_, ?_⟩ <;> decide

end KProgFormal
