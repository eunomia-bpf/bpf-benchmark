import KProgFormal.GeneratedArm64BranchEmit
import KProgFormal.Arm64ControlFlow
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64BranchEmit (Shape)

/-- Independent statement of the emitted shape in terms of the address ordering,
rather than the generated `if`/`else`. -/
def arm64BranchEmitShapeSpec (current target : Nat) : Bool :=
  decide (target ≤ current)

/-- The generated shape agrees with the independent address-ordering predicate. -/
theorem arm64_branch_emit_shape_refines (current target : Nat) :
    GeneratedArm64BranchEmit.backward
        (GeneratedArm64BranchEmit.shape current target) =
      arm64BranchEmitShapeSpec current target := by
  unfold GeneratedArm64BranchEmit.backward GeneratedArm64BranchEmit.shape
    arm64BranchEmitShapeSpec
  by_cases h : target ≤ current <;> simp [h]

/-- **The emission bridge.** For both emitted shapes, the next program counter the
generated code selects equals `branchPc`, the architectural next-PC model that the
condition and compare-and-branch predicate refinements are stated over. Combined
with those refinements, this closes the chain from the flag/value predicate
through the emitted `goto`/label code to the architectural next PC. -/
theorem arm64_branch_emit_refines (current target : Nat) (taken : Bool)
    (fallthrough : Nat) :
    GeneratedArm64BranchEmit.nextPc
        (GeneratedArm64BranchEmit.shape current target) taken fallthrough target =
      branchPc taken fallthrough target := by
  unfold GeneratedArm64BranchEmit.nextPc GeneratedArm64BranchEmit.shape branchPc
  split <;> split <;> rfl

/-- The two shapes select the same next PC for every predicate value: the
direction only decides *how* the jump is written, never *whether* it is taken. -/
theorem arm64_branch_emit_shape_irrelevant (taken : Bool) (fallthrough target : Nat) :
    GeneratedArm64BranchEmit.nextPc .forward taken fallthrough target =
      GeneratedArm64BranchEmit.nextPc .backward taken fallthrough target := by
  unfold GeneratedArm64BranchEmit.nextPc
  cases taken <;> rfl

/-- A taken branch always reaches the target, for either shape. -/
theorem arm64_branch_emit_taken (s : Shape) (fallthrough target : Nat) :
    GeneratedArm64BranchEmit.nextPc s true fallthrough target = target := by
  cases s <;> rfl

/-- A not-taken branch always falls through, for either shape. -/
theorem arm64_branch_emit_not_taken (s : Shape) (fallthrough target : Nat) :
    GeneratedArm64BranchEmit.nextPc s false fallthrough target = fallthrough := by
  cases s <;> rfl

end KProgFormal
