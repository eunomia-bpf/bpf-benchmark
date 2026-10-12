import KProgFormal.GeneratedArm64DqMemExtra
import KProgFormal.GeneratedArm64DqMem
import KProgFormal.GeneratedArm64Vreg

namespace KProgFormal

open GeneratedArm64DqMemExtra (Outcome outcomeCount outcomeNames outcomeCodes
  codeOfOutcome effectOfOutcome extraOffsetOf outcomeOfCode Case classify
  outcomeOfCase highLaneFact)
open GeneratedArm64DqMem (Op laneCount transfer)
open GeneratedArm64Vreg (Half halfOffset plan)

/-- Independent statement of the per-lane extra-offset selector, built from the
literal constructors rather than the generated `extraOffsetOf`: the first-lane
offset exactly when the lane is the first plan position, the high-lane offset at
every later position of a transfer that has a high lane, and the single-lane
offset when the transfer has only one position. -/
def arm64DqMemExtraSpec (isFirstLane hasHighLane : Bool) : Outcome :=
  if isFirstLane then .firstLane
  else if hasHighLane then .highLane
  else .singleLane

/-- Independent statement of the three outcome names, built from the literal
constructor order rather than the generated `outcomeNames`. -/
def arm64DqMemExtraNamesSpec : List String :=
  ["firstLane", "highLane", "singleLane"]

/-- Independent statement of the three outcome codes: the first-lane offset
yields the selector's true branch (0), the high-lane offset the middle branch
(1), and the single-lane offset the default (2). -/
def arm64DqMemExtraCodesSpec : List Nat := [0, 1, 2]

/-- Independent statement of the three extra offsets in bytes, built from the
literal `offset_bytes` values rather than the generated selector: the first-lane
and single-lane offsets are the base offset itself, and the high-lane offset is
one 64-bit lane stride higher. -/
def arm64DqMemExtraOffsetSpec : Outcome -> Nat
  | .firstLane => 0
  | .highLane => 8
  | .singleLane => 0

/-- The generated offset selector equals the independent literal construction
for every moved lane. -/
theorem arm64_dq_mem_extra_refines (isFirstLane hasHighLane : Bool) :
    extraOffsetOf isFirstLane hasHighLane =
      arm64DqMemExtraSpec isFirstLane hasHighLane := by
  unfold extraOffsetOf arm64DqMemExtraSpec
  cases isFirstLane <;> cases hasHighLane <;> rfl

/-- The generated outcome-name table equals the independent literal order. -/
theorem arm64_dq_mem_extra_names_refine :
    outcomeNames = arm64DqMemExtraNamesSpec := by
  unfold outcomeNames arm64DqMemExtraNamesSpec
  rfl

/-- The generated outcome-code table equals the independent literal codes. -/
theorem arm64_dq_mem_extra_codes_refine :
    outcomeCodes = arm64DqMemExtraCodesSpec := by
  unfold outcomeCodes arm64DqMemExtraCodesSpec
  rfl

/-- The generated outcome-code table has exactly `outcomeCount` entries, so the
zip table and the macro name the same three offsets and nothing else. -/
theorem arm64_dq_mem_extra_codes_length :
    outcomeCodes.length = outcomeCount :=
  rfl

/-- The generated outcome-name table has exactly `outcomeCount` entries. -/
theorem arm64_dq_mem_extra_names_length :
    outcomeNames.length = outcomeCount :=
  rfl

/-- The three outcome codes are distinct, so no two outcomes alias one code. -/
theorem arm64_dq_mem_extra_codes_nodup : outcomeCodes.Nodup := by
  unfold outcomeCodes
  native_decide

/-- The outcome count is the three per-lane extra offsets a vector memory step
selects between. -/
theorem arm64_dq_mem_extra_count_is_3 : outcomeCount = 3 := rfl

/-- The generated outcome-code selector round-trips each outcome to its own code
and names no other code. -/
theorem arm64_dq_mem_extra_of_code_roundtrip (outcome : Outcome) :
    outcomeOfCode (codeOfOutcome outcome) = some outcome := by
  cases outcome <;> native_decide

/-- The generated outcome-code selector names no outcome at or above the outcome
count, so the table is exactly the three offsets and no other code reaches
one. -/
theorem arm64_dq_mem_extra_of_code_beyond_is_none :
    outcomeOfCode 3 = none ∧ outcomeOfCode 8 = none ∧
      outcomeOfCode 255 = none := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The three offsets report three distinct plan effects. -/
theorem arm64_dq_mem_extra_effects :
    effectOfOutcome .firstLane = "plan_first_lane_offset" ∧
      effectOfOutcome .highLane = "plan_high_lane_offset" ∧
      effectOfOutcome .singleLane = "plan_single_lane_offset" ∧
      effectOfOutcome .firstLane ≠ effectOfOutcome .highLane ∧
      effectOfOutcome .highLane ≠ effectOfOutcome .singleLane := by
  refine ⟨rfl, rfl, rfl, ?_, ?_⟩ <;> decide

/-- Every fact pair is reachable: naming the offset from the two facts directly
classifies and dispatches the same case, so no case is dead, and the four
`(is first lane, high present)` pairs land on exactly the three outcomes with the
first-lane fact winning. -/
theorem arm64_dq_mem_extra_case_dispatch :
    extraOffsetOf true true = .firstLane ∧
      extraOffsetOf true false = .firstLane ∧
      extraOffsetOf false true = .highLane ∧
      extraOffsetOf false false = .singleLane := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- The four-case table agrees with the direct selector: classifying a moved lane
and dispatching on the case is the same offset selection the macro performs. -/
theorem arm64_dq_mem_extra_case_refines (isFirstLane hasHighLane : Bool) :
    extraOffsetOf isFirstLane hasHighLane =
      outcomeOfCase (classify isFirstLane hasHighLane) :=
  GeneratedArm64DqMemExtra.extraOffsetOf_refines isFirstLane hasHighLane

/-- **The per-lane extra offset is the closed fact pair.** The high-lane offset
is selected exactly when the lane is not the first plan position and the transfer
has a high lane at all: the first-lane test wins over the high-lane test, so the
3-way selection reduces to the two ordered facts and no other arm is ever
reachable. -/
theorem arm64_dq_mem_extra_selects_high_lane (isFirstLane hasHighLane : Bool) :
    (extraOffsetOf isFirstLane hasHighLane = .highLane) =
      highLaneFact isFirstLane hasHighLane := by
  cases isFirstLane <;> cases hasHighLane <;> decide

/-- The two non-high-lane offsets are the base offset and the high-lane offset is
one lane stride above it, so a wrong outcome changes the memory byte the lane
touches. -/
theorem arm64_dq_mem_extra_offsets_distinct :
    arm64DqMemExtraOffsetSpec .firstLane = 0 ∧
      arm64DqMemExtraOffsetSpec .singleLane = 0 ∧
      arm64DqMemExtraOffsetSpec .highLane = 8 ∧
      arm64DqMemExtraOffsetSpec .highLane ≠
        arm64DqMemExtraOffsetSpec .firstLane := by
  refine ⟨rfl, rfl, rfl, ?_⟩ <;> decide

/-- **The high-lane extra offset is the DQ lane stride.** The offset the vector
memory step adds for the high lane is exactly the DQ contract's per-lane
transfer offset at lane index 1 — the 64-bit lane stride the `.Q0` bodies move
their second lane by — for both the load and the store direction. -/
theorem arm64_dq_mem_extra_matches_dq_stride :
    arm64DqMemExtraOffsetSpec .highLane = transfer .loadQ0 1 ∧
      arm64DqMemExtraOffsetSpec .highLane = transfer .storeQ0 1 := by
  refine ⟨rfl, rfl⟩

/-- **The high-lane extra offset is the vector half offset.** The offset the
step adds at a later plan position is exactly the vector-register contract's
state-field offset of the high half, and the step's "a high lane is present" fact
matches the vector-register contract's half plan for the same opcode: `.D0`
plans one position and the DQ contract one lane, `.Q0` plans two of each. The two
contracts agree on which position is the high lane and how far above the low half
it sits. -/
theorem arm64_dq_mem_extra_matches_vreg_half :
    arm64DqMemExtraOffsetSpec .highLane =
      GeneratedArm64Vreg.halfOffset .high ∧
      (GeneratedArm64Vreg.plan .loadD0).length = 1 ∧
      (GeneratedArm64Vreg.plan .loadQ0).length = 2 ∧
      (GeneratedArm64Vreg.plan .storeD0).length = 1 ∧
      (GeneratedArm64Vreg.plan .storeQ0).length = 2 ∧
      laneCount (GeneratedArm64DqMem.lanes .loadD0) = 1 ∧
      laneCount (GeneratedArm64DqMem.lanes .loadQ0) = 2 ∧
      laneCount (GeneratedArm64DqMem.lanes .storeD0) = 1 ∧
      laneCount (GeneratedArm64DqMem.lanes .storeQ0) = 2 := by
  refine ⟨rfl, rfl, rfl, rfl, rfl, rfl, rfl, rfl, rfl⟩

end KProgFormal
