import KProgFormal.ClightRefinement.Arm64CntLanes

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Packing

private theorem reverse_or (a b c d e f g h : BitVec 64) :
    ((((((a ||| b) ||| c) ||| d) ||| e) ||| f) ||| g) ||| h =
      ((((((h ||| g) ||| f) ||| e) ||| d) ||| c) ||| b) ||| a := by ac_rfl

private theorem bytes (b0 b1 b2 b3 b4 b5 b6 b7 : BitVec 8) :
    ((((((((0#64 ||| (b0.setWidth 64 <<< 0)) |||
      (b1.setWidth 64 <<< 8)) ||| (b2.setWidth 64 <<< 16)) |||
      (b3.setWidth 64 <<< 24)) ||| (b4.setWidth 64 <<< 32)) |||
      (b5.setWidth 64 <<< 40)) ||| (b6.setWidth 64 <<< 48)) |||
      (b7.setWidth 64 <<< 56)) =
        (((((((b7 ++ b6) ++ b5) ++ b4) ++ b3) ++ b2) ++ b1) ++ b0) := by
  change _ = (((((((b7 ++ b6) ++ b5) ++ b4) ++ b3) ++ b2) ++ b1) ++ b0).setWidth 64
  conv =>
    rhs
    rw [BitVec.setWidth_append_eq_shiftLeft_setWidth_or,
      BitVec.setWidth_append_eq_shiftLeft_setWidth_or,
      BitVec.setWidth_append_eq_shiftLeft_setWidth_or,
      BitVec.setWidth_append_eq_shiftLeft_setWidth_or,
      BitVec.setWidth_append_eq_shiftLeft_setWidth_or,
      BitVec.setWidth_append_eq_shiftLeft_setWidth_or,
      BitVec.setWidth_append_eq_shiftLeft_setWidth_or]
    simp only [BitVec.shiftLeft_or_distrib,← BitVec.shiftLeft_add]
  rw [BitVec.zero_or,BitVec.shiftLeft_zero]
  exact reverse_or _ _ _ _ _ _ _ _

/-- The original C accumulator order packs the full imported 64-bit count. -/
theorem word (value : BitVec 64) :
    ((((((((0#64 ||| ((Lanes.byte value 0).setWidth 64 <<< 0)) |||
      ((Lanes.byte value 1).setWidth 64 <<< 8)) ||| ((Lanes.byte value 2).setWidth 64 <<< 16)) |||
      ((Lanes.byte value 3).setWidth 64 <<< 24)) ||| ((Lanes.byte value 4).setWidth 64 <<< 32)) |||
      ((Lanes.byte value 5).setWidth 64 <<< 40)) ||| ((Lanes.byte value 6).setWidth 64 <<< 48)) |||
      ((Lanes.byte value 7).setWidth 64 <<< 56)) = DPSFP.simd_count_bytes value := by
  rw [Lanes.bytes64]
  exact bytes _ _ _ _ _ _ _ _

end KProgFormal.ClightRefinement.Arm64Cnt.Packing
