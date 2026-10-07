import KProgFormal.GeneratedArm64Reduction
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Reduction (Reduction)

/-- Independent statement of the two AArch64 byte-lane reductions. The CNT arm
keeps each byte's result in its own byte but states the per-byte popcount as a
bit walk over the byte shifted down to the low eight bits (a different
extraction than the generated `extractLsb'`); the UADDLV arm stacks the byte
sums as a right-associated fold of the bytes after masking. -/
def arm64ReductionSpec (op : Reduction) (value : BitVec 64) : BitVec 64 :=
  let bytePop (b : Nat) : BitVec 64 :=
    -- walk the eight bits of byte `b` without extractLsb': mask, then shift.
    ((value >>> (8 * b)) &&& 0x1) + (((value >>> (8 * b + 1)) &&& 0x1)) +
    (((value >>> (8 * b + 2)) &&& 0x1)) + (((value >>> (8 * b + 3)) &&& 0x1)) +
    (((value >>> (8 * b + 4)) &&& 0x1)) + (((value >>> (8 * b + 5)) &&& 0x1)) +
    (((value >>> (8 * b + 6)) &&& 0x1)) + (((value >>> (8 * b + 7)) &&& 0x1))
  match op with
  | .cnt =>
      (bytePop 0) ||| ((bytePop 1) <<< 8) ||| ((bytePop 2) <<< 16) |||
      ((bytePop 3) <<< 24) ||| ((bytePop 4) <<< 32) |||
      ((bytePop 5) <<< 40) ||| ((bytePop 6) <<< 48) |||
      ((bytePop 7) <<< 56)
  | .uaddlv =>
      let b0 := (value >>> 0) &&& 0xff
      let b1 := ((value >>> 8) &&& 0xff)
      let b2 := ((value >>> 16) &&& 0xff)
      let b3 := ((value >>> 24) &&& 0xff)
      let b4 := ((value >>> 32) &&& 0xff)
      let b5 := ((value >>> 40) &&& 0xff)
      let b6 := ((value >>> 48) &&& 0xff)
      let b7 := ((value >>> 56) &&& 0xff)
      b0 + (b1 + (b2 + (b3 + (b4 + (b5 + (b6 + b7))))))

/-- The generated reduction contract agrees with the independent statement for
both reductions. -/
theorem arm64_reduction_refines (op : Reduction) (value : BitVec 64) :
    GeneratedArm64Reduction.value op value =
      arm64ReductionSpec op value := by
  cases op <;>
    simp only [GeneratedArm64Reduction.value, arm64ReductionSpec,
      GeneratedArm64Reduction.popCountBits] <;>
    bv_decide

/-- Both reductions are inside the numeric case-label range `36..37` used by the
shared C macro. -/
theorem arm64_reduction_code_in_range (op : Reduction) :
    36 ≤ GeneratedArm64Reduction.code op ∧
      GeneratedArm64Reduction.code op ≤ 37 := by
  cases op <;> decide

/-- Every byte lane of a CNT result is at most eight, so the replicated
popcounts never carry into a neighbouring byte. -/
theorem arm64_reduction_cnt_lane_bound (value : BitVec 64) :
    (GeneratedArm64Reduction.value .cnt value) >>> 8 &&& 0xff ≤ 8 ∧
    (GeneratedArm64Reduction.value .cnt value) &&& 0xff ≤ 8 := by
  simp only [GeneratedArm64Reduction.value,
    GeneratedArm64Reduction.popCountBits]
  refine ⟨?_, ?_⟩ <;> bv_decide

/-- UADDLV sums eight bytes, so its result fits in ten bits (at most 8*255). -/
theorem arm64_reduction_uaddlv_bound (value : BitVec 64) :
    (GeneratedArm64Reduction.value .uaddlv value) < 2048 := by
  simp only [GeneratedArm64Reduction.value]
  bv_decide

/-- Canonical example: CNT of a byte with one bit set in each lane. -/
theorem arm64_reduction_cnt_example :
    arm64ReductionSpec .cnt 0x8040201008040201 = 0x0101010101010101 := by
  native_decide

/-- Canonical example: CNT of all-ones bytes fills each lane with 8. -/
theorem arm64_reduction_cnt_full_example :
    arm64ReductionSpec .cnt 0xffffffffffffffff = 0x0808080808080808 := by
  native_decide

/-- Canonical example: UADDLV of eight 0xff bytes is 8*255. -/
theorem arm64_reduction_uaddlv_example :
    arm64ReductionSpec .uaddlv 0xffffffffffffffff = 2040 := by
  native_decide

/-- Canonical example: UADDLV of the low byte only. -/
theorem arm64_reduction_uaddlv_low_example :
    arm64ReductionSpec .uaddlv 0xff = 255 := by
  native_decide

end KProgFormal
