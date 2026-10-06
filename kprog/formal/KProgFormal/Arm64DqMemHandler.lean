import KProgFormal.GeneratedArm64DqMem
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64DqMem (Op Access Lanes)

/-- Independent statement of the four AArch64 vector memory transfers: the
ordered list of byte offsets each opcode moves. It is written directly as the
lane plan (`[0]` for `.D0`, `[0, 8]` for `.Q0`), never as the generated index
arithmetic, so the two agree on which lanes a body touches and how many. -/
def arm64DqMemPlanSpec : Op -> List Nat
  | .loadD0 => [0]
  | .loadQ0 => [0, 8]
  | .storeD0 => [0]
  | .storeQ0 => [0, 8]

/-- The ordered lane offsets the generated contract produces: the lane count's
many lane indices, each mapped through the generated transfer offset. -/
def arm64DqMemTransferList (op : Op) : List Nat :=
  (List.range (GeneratedArm64DqMem.laneCount
      (GeneratedArm64DqMem.lanes op))).map (GeneratedArm64DqMem.transfer op)

/-- The generated lane plan equals the independent plan for every opcode: the
same lanes, in the same order, with the same offsets. -/
theorem arm64_dq_mem_refines (op : Op) :
    arm64DqMemTransferList op = arm64DqMemPlanSpec op := by
  cases op <;> rfl

/-- The generated lane count equals the length of the independent plan for every
opcode. -/
theorem arm64_dq_mem_lane_count_refines (op : Op) :
    GeneratedArm64DqMem.laneCount (GeneratedArm64DqMem.lanes op) =
      (arm64DqMemPlanSpec op).length := by
  cases op <;> rfl

/-- **The access direction is a per-opcode fact**: the two `LOAD` opcodes move
memory into the SIMD register, the two `STORE` opcodes move it out. -/
theorem arm64_dq_mem_access_dispatch :
    GeneratedArm64DqMem.access .loadD0 = Access.load ∧
    GeneratedArm64DqMem.access .loadQ0 = Access.load ∧
    GeneratedArm64DqMem.access .storeD0 = Access.store ∧
    GeneratedArm64DqMem.access .storeQ0 = Access.store := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- **The lane plan is a per-opcode fact**: `.D0` moves exactly the low lane at
offset 0, `.Q0` moves the low lane at 0 and then the high lane one 64-bit lane
stride higher. This is the property the four C bodies rely on. -/
theorem arm64_dq_mem_lane_plan :
    arm64DqMemPlanSpec .loadD0 = [0] ∧
    arm64DqMemPlanSpec .loadQ0 = [0, 8] ∧
    arm64DqMemPlanSpec .storeD0 = [0] ∧
    arm64DqMemPlanSpec .storeQ0 = [0, 8] := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- The generated lane stride is the 64-bit lane width: the second lane of a
`.Q0` transfer is 8 bytes above the first, for every opcode that has one. -/
theorem arm64_dq_mem_lane_stride (op : Op) :
    GeneratedArm64DqMem.transfer op 1 = 8 := by
  cases op <;> rfl

/-- A `.Q0` plan moves two *distinct* lanes: the high lane is not a duplicate of
the low lane, so a body that re-reads lane 0 into the high lane's place would not
satisfy the plan. -/
theorem arm64_dq_mem_q0_moves_distinct_lanes :
    arm64DqMemPlanSpec .loadQ0 = [0, 8] ∧
    arm64DqMemPlanSpec .storeQ0 = [0, 8] ∧
    (arm64DqMemPlanSpec .loadQ0).get ⟨0, by decide⟩ ≠
      (arm64DqMemPlanSpec .loadQ0).get ⟨1, by decide⟩ := by
  refine ⟨rfl, rfl, ?_⟩
  decide

/-- The generated dispatch indices are `0, 1, 2, 3`, so the four-way C chain
`LOAD_D0 / LOAD_Q0 / STORE_D0 / STORE_Q0` covers each opcode exactly once, in the
order the arm index names. -/
theorem arm64_dq_mem_arm_index_dispatch :
    GeneratedArm64DqMem.armIndex .loadD0 = 0 ∧
    GeneratedArm64DqMem.armIndex .loadQ0 = 1 ∧
    GeneratedArm64DqMem.armIndex .storeD0 = 2 ∧
    GeneratedArm64DqMem.armIndex .storeQ0 = 3 := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- Canonical example: the low lane of a `.D0` load is read/written at the base
offset itself. -/
theorem arm64_dq_mem_low_lane_example :
    GeneratedArm64DqMem.transfer .loadD0 0 = 0 ∧
    GeneratedArm64DqMem.transfer .storeD0 0 = 0 := by
  refine ⟨rfl, rfl⟩

/-- Canonical example: the high lane of a `.Q0` transfer sits eight bytes above
the low lane, so the two together span the full 16-byte vector register. -/
theorem arm64_dq_mem_high_lane_example :
    GeneratedArm64DqMem.transfer .loadQ0 1 = 8 ∧
    GeneratedArm64DqMem.transfer .storeQ0 1 = 8 := by
  refine ⟨rfl, rfl⟩

end KProgFormal
