import KProgFormal.GeneratedArm64StackTag
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64StackTag (Case)

/-- The generated classification is total: every (isW64, isAligned) pair maps to
one of the four cases. This is the property the C predicate relies on when it
decides whether to read the slot tag array. -/
theorem arm64_stack_tag_classify_total (isW64 isAligned : Bool) :
    GeneratedArm64StackTag.classify isW64 isAligned = .qword ∨
      GeneratedArm64StackTag.classify isW64 isAligned = .sub_qword_aligned ∨
      GeneratedArm64StackTag.classify isW64 isAligned = .qword_unaligned ∨
      GeneratedArm64StackTag.classify isW64 isAligned =
        .sub_qword_unaligned := by
  cases isW64 <;> cases isAligned <;> simp [GeneratedArm64StackTag.classify]

/-- The selection is exactly the conjunction: a stack slot carries a tag iff the
access is 64-bit and qword-aligned. -/
theorem arm64_stack_tag_refines (isW64 isAligned : Bool) :
    GeneratedArm64StackTag.tagged
        (GeneratedArm64StackTag.classify isW64 isAligned) =
      (isW64 && isAligned) := by
  cases isW64 <;> cases isAligned <;> decide

/-- Only the qword-aligned 64-bit case is tagged; the other three are scalar. -/
theorem arm64_stack_tag_dispatch :
    GeneratedArm64StackTag.tagged .qword = true ∧
    GeneratedArm64StackTag.tagged .sub_qword_aligned = false ∧
    GeneratedArm64StackTag.tagged .qword_unaligned = false ∧
    GeneratedArm64StackTag.tagged .sub_qword_unaligned = false := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- An unaligned 64-bit access is never tagged, however wide it is: the slot is
shared with neighbouring values. -/
theorem arm64_stack_tag_unaligned_never (isW64 : Bool) :
    GeneratedArm64StackTag.tagged
        (GeneratedArm64StackTag.classify isW64 false) = false := by
  cases isW64 <;> simp only [GeneratedArm64StackTag.classify,
    GeneratedArm64StackTag.tagged]

end KProgFormal
