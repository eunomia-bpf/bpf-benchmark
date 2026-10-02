import KProgFormal.GeneratedArm64Vreg
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Vreg (Op Access Half Halves)

/-- Independent statement of the four AArch64 vector-register half plans: the
ordered list of vector-register halves each opcode touches. It is written
directly as the plan (`[.low]` for `.D0`, `[.low, .high]` for `.Q0`), never as
the generated half-count-and-select arithmetic, so the two agree on which state
field a transfer touches and in which order. -/
def arm64VregPlanSpec : Op -> List Half
  | .loadD0 => [.low]
  | .loadQ0 => [.low, .high]
  | .storeD0 => [.low]
  | .storeQ0 => [.low, .high]

/-- The ordered half offsets the generated contract produces: the half count's
many plan positions, each mapped through the generated half plan and half
offset. -/
def arm64VregTransferList (op : Op) : List Nat :=
  (GeneratedArm64Vreg.plan op).map GeneratedArm64Vreg.halfOffset

/-- The generated half plan equals the independent plan for every opcode: the
same halves, in the same order. -/
theorem arm64_vreg_refines (op : Op) :
    GeneratedArm64Vreg.plan op = arm64VregPlanSpec op := by
  cases op <;> rfl

/-- The generated half count equals the length of the independent plan for every
opcode. -/
theorem arm64_vreg_half_count_refines (op : Op) :
    GeneratedArm64Vreg.halfCount (GeneratedArm64Vreg.halves op) =
      (arm64VregPlanSpec op).length := by
  cases op <;> rfl

/-- **The access direction is a per-opcode fact**: the two `LOAD` opcodes move
memory into the vector register file, the two `STORE` opcodes move it out. -/
theorem arm64_vreg_access_dispatch :
    GeneratedArm64Vreg.access .loadD0 = Access.load ∧
    GeneratedArm64Vreg.access .loadQ0 = Access.load ∧
    GeneratedArm64Vreg.access .storeD0 = Access.store ∧
    GeneratedArm64Vreg.access .storeQ0 = Access.store := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- **The half plan is a per-opcode fact**: `.D0` touches exactly the low half,
`.Q0` touches the low half and then the high half. This is the property the four
C bodies rely on. -/
theorem arm64_vreg_half_plan :
    arm64VregPlanSpec .loadD0 = [.low] ∧
    arm64VregPlanSpec .loadQ0 = [.low, .high] ∧
    arm64VregPlanSpec .storeD0 = [.low] ∧
    arm64VregPlanSpec .storeQ0 = [.low, .high] := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- The two halves map to *distinct* state-field slots: the low half is slot 0,
the high half slot 8, so a transfer that aliased the halves would not satisfy
the plan. -/
theorem arm64_vreg_halves_distinct :
    GeneratedArm64Vreg.halfOffset .low = 0 ∧
    GeneratedArm64Vreg.halfOffset .high = 8 ∧
    GeneratedArm64Vreg.halfOffset .low ≠ GeneratedArm64Vreg.halfOffset .high := by
  refine ⟨rfl, rfl, by decide⟩

/-- A `.Q0` plan touches two *distinct* halves: the high half is not a duplicate
of the low half, so a body that re-read the low half into the high lane's place
would not satisfy the plan. -/
theorem arm64_vreg_q0_touches_distinct_halves :
    arm64VregPlanSpec .loadQ0 = [.low, .high] ∧
    arm64VregPlanSpec .storeQ0 = [.low, .high] ∧
    (arm64VregPlanSpec .loadQ0).get ⟨0, by decide⟩ ≠
      (arm64VregPlanSpec .loadQ0).get ⟨1, by decide⟩ := by
  refine ⟨rfl, rfl, ?_⟩
  decide

/-- The generated dispatch indices are `0, 1, 2, 3`, so the four-way C chain
`LOAD_D0 / LOAD_Q0 / STORE_D0 / STORE_Q0` covers each opcode exactly once, in the
order the arm index names. -/
theorem arm64_vreg_arm_index_dispatch :
    GeneratedArm64Vreg.armIndex .loadD0 = 0 ∧
    GeneratedArm64Vreg.armIndex .loadQ0 = 1 ∧
    GeneratedArm64Vreg.armIndex .storeD0 = 2 ∧
    GeneratedArm64Vreg.armIndex .storeQ0 = 3 := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- Canonical example: a `.D0` transfer touches the low half at slot offset 0,
the same field the state declares first. -/
theorem arm64_vreg_low_half_example :
    GeneratedArm64Vreg.halfOffset .low = 0 ∧
    (GeneratedArm64Vreg.plan .loadD0).map GeneratedArm64Vreg.halfOffset = [0] ∧
    (GeneratedArm64Vreg.plan .storeD0).map GeneratedArm64Vreg.halfOffset = [0] := by
  refine ⟨rfl, rfl, rfl⟩

/-- Canonical example: a `.Q0` transfer touches the low half at offset 0 and
then the high half at offset 8, so the two together span the full 16-byte vector
register, low half first. -/
theorem arm64_vreg_high_half_example :
    (GeneratedArm64Vreg.plan .loadQ0).map GeneratedArm64Vreg.halfOffset = [0, 8] ∧
    (GeneratedArm64Vreg.plan .storeQ0).map GeneratedArm64Vreg.halfOffset = [0, 8] ∧
    arm64VregTransferList .loadQ0 = [0, 8] := by
  refine ⟨rfl, rfl, rfl⟩

end KProgFormal
