import KProgFormal.GeneratedArm64Cond

namespace KProgFormal

structure Arm64Flags where
  n : Bool
  z : Bool
  c : Bool
  v : Bool
  deriving DecidableEq, Repr

abbrev Arm64Cond := GeneratedArm64Cond.Cond

/-- Independent architectural statement of every supported AArch64 condition. -/
def arm64CondSpec (flags : Arm64Flags) : Arm64Cond -> Bool
  | .eq => flags.z
  | .ne => !flags.z
  | .cs => flags.c
  | .cc => !flags.c
  | .mi => flags.n
  | .pl => !flags.n
  | .vs => flags.v
  | .vc => !flags.v
  | .hi => flags.c && !flags.z
  | .ls => !flags.c || flags.z
  | .ge => flags.n == flags.v
  | .lt => flags.n != flags.v
  | .gt => !flags.z && (flags.n == flags.v)
  | .le => flags.z || (flags.n != flags.v)
  | .al => true

def generatedArm64Cond (flags : Arm64Flags) (cond : Arm64Cond) : Bool :=
  GeneratedArm64Cond.eval flags.n flags.z flags.c flags.v cond

/-- The condition predicate used by both the generated C handler and Lean
agrees with the independently stated AArch64 condition-code semantics. -/
theorem arm64_condition_sound (flags : Arm64Flags) (cond : Arm64Cond) :
    generatedArm64Cond flags cond = arm64CondSpec flags cond := by
  cases flags
  cases cond <;> rfl

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
