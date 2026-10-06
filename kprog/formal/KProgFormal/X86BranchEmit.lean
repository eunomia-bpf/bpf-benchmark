import KProgFormal.GeneratedX86BranchEmit
import KProgFormal.X86ControlFlow
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86BranchEmit (Shape)

/-- Independent statement of the emitted shape in terms of the address ordering,
rather than the generated `if`/`else`. -/
def x86BranchEmitShapeSpec (current target : Nat) : Bool :=
  decide (target ≤ current)

/-- The generated shape agrees with the independent address-ordering predicate. -/
theorem x86_branch_emit_shape_refines (current target : Nat) :
    GeneratedX86BranchEmit.backward
        (GeneratedX86BranchEmit.shape current target) =
      x86BranchEmitShapeSpec current target := by
  unfold GeneratedX86BranchEmit.backward GeneratedX86BranchEmit.shape
    x86BranchEmitShapeSpec
  by_cases h : target ≤ current <;> simp [h]

/-- **The emission bridge.** For both emitted shapes, the next program counter the
generated code selects equals `branchPc`, the architectural next-PC model that the
condition and conditional-branch predicate refinements are stated over. Combined
with those refinements, this closes the chain from the flag predicate through the
emitted `goto`/label code to the architectural next PC, so the `X86_SIM_X86_JCC`
forward/backward split is machine-checked rather than asserted. -/
theorem x86_branch_emit_refines (current target : Nat) (taken : Bool)
    (fallthrough : Nat) :
    GeneratedX86BranchEmit.nextPc
        (GeneratedX86BranchEmit.shape current target) taken fallthrough target =
      branchPc taken fallthrough target := by
  unfold GeneratedX86BranchEmit.nextPc GeneratedX86BranchEmit.shape branchPc
  split <;> split <;> rfl

/-- The two shapes select the same next PC for every predicate value: the
direction only decides *how* the jump is written, never *whether* it is taken,
which is why the simulator's backward special case is behaviour-preserving. -/
theorem x86_branch_emit_shape_irrelevant (taken : Bool) (fallthrough target : Nat) :
    GeneratedX86BranchEmit.nextPc .forward taken fallthrough target =
      GeneratedX86BranchEmit.nextPc .backward taken fallthrough target := by
  unfold GeneratedX86BranchEmit.nextPc
  cases taken <;> rfl

/-- A taken branch always reaches the target, for either shape. -/
theorem x86_branch_emit_taken (s : Shape) (fallthrough target : Nat) :
    GeneratedX86BranchEmit.nextPc s true fallthrough target = target := by
  cases s <;> rfl

/-- A not-taken branch always falls through, for either shape. -/
theorem x86_branch_emit_not_taken (s : Shape) (fallthrough target : Nat) :
    GeneratedX86BranchEmit.nextPc s false fallthrough target = fallthrough := by
  cases s <;> rfl

end KProgFormal
