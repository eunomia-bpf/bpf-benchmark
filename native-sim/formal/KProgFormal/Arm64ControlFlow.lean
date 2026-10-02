import KProgFormal.Arm64Cond

namespace KProgFormal

def branchPc (take : Bool) (fallthrough target : Nat) : Nat :=
  if take then target else fallthrough

/-- Therefore the generated predicate selects the same next program counter
as the architectural condition semantics, for forward and backward edges. -/
theorem arm64_conditional_branch_refines
    (flags : Arm64Flags) (cond : Arm64Cond) (fallthrough target : Nat) :
    branchPc (generatedArm64Cond flags cond) fallthrough target =
      branchPc (arm64CondSpec flags cond) fallthrough target := by
  rw [arm64_condition_sound]

end KProgFormal
