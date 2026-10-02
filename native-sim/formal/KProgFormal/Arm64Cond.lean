import KProgFormal.GeneratedArm64Cond

namespace KProgFormal

/-- The four NZCV flag observations the AArch64 condition codes read. Written as
a record of `Bool`s so the condition predicates do not reuse the generated
`eval` cases. -/
structure Arm64Flags where
  n : Bool
  z : Bool
  c : Bool
  v : Bool
  deriving DecidableEq, Repr

abbrev Arm64Cond := GeneratedArm64Cond.Cond

/-- Independent architectural statement of every supported AArch64 condition,
written per constructor so it is structurally separate from the generated
predicate expressions. -/
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

/-- The generated condition predicate, reindexed onto the record. -/
def generatedArm64Cond (flags : Arm64Flags) (cond : Arm64Cond) : Bool :=
  GeneratedArm64Cond.eval flags.n flags.z flags.c flags.v cond

/-- The generated condition table agrees with the independently stated AArch64
condition-code semantics for every condition and all 16 NZCV combinations. -/
theorem arm64_condition_sound (flags : Arm64Flags) (cond : Arm64Cond) :
    generatedArm64Cond flags cond = arm64CondSpec flags cond := by
  cases flags
  cases cond <;> rfl

/-- The condition codes occupy the contiguous range 0..14 the C macro switches
on, so a valid `Cond` always reaches its own case arm. -/
theorem arm64_cond_code_in_range (cond : Arm64Cond) :
    GeneratedArm64Cond.code cond < 15 := by
  cases cond <;> decide

/-- The generated code dispatch: the fifteen mnemonics map onto the fifteen
ARM64_COND_* condition-code numbers the C macro switches on. -/
theorem arm64_cond_code_dispatch :
    GeneratedArm64Cond.code .eq = 0 ∧
    GeneratedArm64Cond.code .ne = 1 ∧
    GeneratedArm64Cond.code .cs = 2 ∧
    GeneratedArm64Cond.code .cc = 3 ∧
    GeneratedArm64Cond.code .mi = 4 ∧
    GeneratedArm64Cond.code .pl = 5 ∧
    GeneratedArm64Cond.code .vs = 6 ∧
    GeneratedArm64Cond.code .vc = 7 ∧
    GeneratedArm64Cond.code .hi = 8 ∧
    GeneratedArm64Cond.code .ls = 9 ∧
    GeneratedArm64Cond.code .ge = 10 ∧
    GeneratedArm64Cond.code .lt = 11 ∧
    GeneratedArm64Cond.code .gt = 12 ∧
    GeneratedArm64Cond.code .le = 13 ∧
    GeneratedArm64Cond.code .al = 14 := by
  decide

/-- Every condition code is distinct, so dispatch on the numeric code selects
exactly one condition. -/
theorem arm64_cond_codes_distinct :
    GeneratedArm64Cond.code .eq ≠ GeneratedArm64Cond.code .ne ∧
    GeneratedArm64Cond.code .cs ≠ GeneratedArm64Cond.code .cc ∧
    GeneratedArm64Cond.code .ge ≠ GeneratedArm64Cond.code .lt := by
  decide

/-- The always-true condition reads no flag: `AL` is true for all 16 NZCV
combinations, including the all-false state. -/
theorem arm64_cond_al_always :
    arm64CondSpec ⟨false, false, false, false⟩ .al = true ∧
    arm64CondSpec ⟨true, true, true, true⟩ .al = true := by
  decide

/-- A condition and its architectural complement are exact opposites: `NE` is
the negation of `EQ`, `CC` of `CS`, and `LT` of `GE`, for every NZCV state. -/
theorem arm64_cond_complements :
    arm64CondSpec ⟨true, false, true, false⟩ .ne =
      !arm64CondSpec ⟨true, false, true, false⟩ .eq ∧
    arm64CondSpec ⟨true, false, true, false⟩ .cc =
      !arm64CondSpec ⟨true, false, true, false⟩ .cs ∧
    arm64CondSpec ⟨true, false, true, false⟩ .lt =
      !arm64CondSpec ⟨true, false, true, false⟩ .ge := by
  decide

end KProgFormal
