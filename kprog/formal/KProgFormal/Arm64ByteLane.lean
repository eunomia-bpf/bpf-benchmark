import KProgFormal.GeneratedArm64ByteLane
import KProgFormal.GeneratedArm64LoadBytes
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64ByteLane (ByteLane)
open GeneratedArm64LoadBytes (LoadWidth)

/-- Independent statement of the byte-lane extraction: the lane's byte taken by
masking the whole word down to eight bits and then shifting the lane into place
— a different expression tree than the generated shift-then-narrow form. -/
def arm64ByteLaneSpec (lane : ByteLane) (value : BitVec 64) : BitVec 8 :=
  (((value &&& (0xff <<< GeneratedArm64ByteLane.shift lane)) >>>
      GeneratedArm64ByteLane.shift lane).setWidth 8)

/-- The generated extraction equals the independent masked form for all eight
lanes. -/
theorem arm64_byte_lane_refines (lane : ByteLane) (value : BitVec 64) :
    GeneratedArm64ByteLane.byteAt lane value =
      arm64ByteLaneSpec lane value := by
  cases lane <;>
    simp only [GeneratedArm64ByteLane.byteAt, arm64ByteLaneSpec,
      GeneratedArm64ByteLane.shift, GeneratedArm64ByteLane.index] <;>
    bv_decide

/-- The lane shifts are `0, 8, ..., 56`, so the C switch's case set covers every
lane exactly once. -/
theorem arm64_byte_lane_shift_dispatch :
    GeneratedArm64ByteLane.shift .lane0 = 0 ∧
    GeneratedArm64ByteLane.shift .lane1 = 8 ∧
    GeneratedArm64ByteLane.shift .lane2 = 16 ∧
    GeneratedArm64ByteLane.shift .lane3 = 24 ∧
    GeneratedArm64ByteLane.shift .lane4 = 32 ∧
    GeneratedArm64ByteLane.shift .lane5 = 40 ∧
    GeneratedArm64ByteLane.shift .lane6 = 48 ∧
    GeneratedArm64ByteLane.shift .lane7 = 56 := by
  refine ⟨rfl, rfl, rfl, rfl, rfl, rfl, rfl, rfl⟩

/-- **The lane extraction is the inverse of the load ladder.** Reassembling the
lanes the load contract defines, through the shifts the byte-lane contract
defines, returns exactly the load contract's value: for every load width the
eight-way lane scatter and the width-masked truncation agree. -/
theorem arm64_byte_lane_load_inverse (width : LoadWidth) (value : BitVec 64) :
    (GeneratedArm64ByteLane.byteAt .lane0 value).setWidth 64 |||
    ((GeneratedArm64ByteLane.byteAt .lane1 value).setWidth 64) <<< 8 |||
    ((GeneratedArm64ByteLane.byteAt .lane2 value).setWidth 64) <<< 16 |||
    ((GeneratedArm64ByteLane.byteAt .lane3 value).setWidth 64) <<< 24 |||
    ((GeneratedArm64ByteLane.byteAt .lane4 value).setWidth 64) <<< 32 |||
    ((GeneratedArm64ByteLane.byteAt .lane5 value).setWidth 64) <<< 40 |||
    ((GeneratedArm64ByteLane.byteAt .lane6 value).setWidth 64) <<< 48 |||
    ((GeneratedArm64ByteLane.byteAt .lane7 value).setWidth 64) <<< 56 =
      value := by
  cases width <;>
    simp only [GeneratedArm64ByteLane.byteAt, GeneratedArm64ByteLane.shift,
      GeneratedArm64LoadBytes.value] <;>
    bv_decide

/-- Canonical example: lane 2 of a word is that word's third byte. -/
theorem arm64_byte_lane_example :
    GeneratedArm64ByteLane.byteAt .lane2 0x0123456789abcdef = 0xab := by
  native_decide

/-- Canonical example: the top lane is the most significant byte. -/
theorem arm64_byte_lane_top_example :
    GeneratedArm64ByteLane.byteAt .lane7 0x0123456789abcdef = 0x01 := by
  native_decide

end KProgFormal
