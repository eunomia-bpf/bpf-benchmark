import KProgFormal.Generated.GeneratedX86StackIndex
namespace KProgFormal
open GeneratedX86StackIndex (index)
/-- Native addresses wrap only at 64 bits, independently stated with commuted operands. -/
def x86StackIndexSpec (capacity off : BitVec 64) : BitVec 64 := off + capacity
theorem x86_stack_index_refines (capacity off : BitVec 64) :
    index capacity off = x86StackIndexSpec capacity off := by
  unfold index x86StackIndexSpec
  bv_decide
theorem x86_stack_index_frame_base_is_zero (capacity : BitVec 64) :
    index capacity (-capacity) = 0 := by
  unfold index
  bv_decide
theorem x86_stack_index_top_is_capacity (capacity : BitVec 64) :
    index capacity 0 = capacity := by
  unfold index
  bv_decide
/-- Adding a nonzero high word cannot alias a distinct native address. -/
theorem x86_stack_index_high_bits_distinct (capacity off delta : BitVec 64)
    (h : delta ≠ 0) : index capacity (off + delta) ≠ index capacity off := by
  unfold index
  bv_decide
/-- The old high32 alias input remains, with its corrected native64 result. -/
theorem x86_stack_index_example :
    index 64 (-56) = 8 ∧ index 64 (-8) = 56 ∧ index 64 0 = 64 ∧
    index 64 ((-56) + 0x100000000) = 0x100000008 := by
  decide
end KProgFormal
