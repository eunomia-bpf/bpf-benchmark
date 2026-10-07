import KProgFormal.GeneratedX86Popcount
import Std.Tactic.BVDecide

namespace KProgFormal

private def laneByte (x : BitVec 64) (i : Nat) : BitVec 8 :=
  ((x >>> (8 * i)) &&& 0xff).setWidth 8

/-- Independent per-byte population count: an explicit eight-bit walk, sharing no
constant with the generated SWAR reduction. -/
private def bytePop (b : BitVec 8) : BitVec 8 :=
  (b.extractLsb' 0 1).setWidth 8 + (b.extractLsb' 1 1).setWidth 8 +
  (b.extractLsb' 2 1).setWidth 8 + (b.extractLsb' 3 1).setWidth 8 +
  (b.extractLsb' 4 1).setWidth 8 + (b.extractLsb' 5 1).setWidth 8 +
  (b.extractLsb' 6 1).setWidth 8 + (b.extractLsb' 7 1).setWidth 8

/-- Independent statement of the 64-bit population count: the sum of the eight
byte lanes' bit walks, each lane narrowed before counting. -/
def x86PopcountSpec (x : BitVec 64) : BitVec 64 :=
  (bytePop (laneByte x 0)).setWidth 64 + (bytePop (laneByte x 1)).setWidth 64 +
  (bytePop (laneByte x 2)).setWidth 64 + (bytePop (laneByte x 3)).setWidth 64 +
  (bytePop (laneByte x 4)).setWidth 64 + (bytePop (laneByte x 5)).setWidth 64 +
  (bytePop (laneByte x 6)).setWidth 64 + (bytePop (laneByte x 7)).setWidth 64

/-- The generated SWAR reduction equals the independent lane-grouped bit walk. -/
theorem x86_popcount_refines (x : BitVec 64) :
    GeneratedX86Popcount.value x = x86PopcountSpec x := by
  unfold GeneratedX86Popcount.value x86PopcountSpec laneByte bytePop
  bv_decide (config := { timeout := 120 })

/-- The population count never exceeds 64: at most every bit is set. -/
theorem x86_popcount_bounded (x : BitVec 64) :
    BitVec.ule (GeneratedX86Popcount.value x) (64 : BitVec 64) = true := by
  unfold GeneratedX86Popcount.value
  bv_decide

/-- The population count of zero is zero. -/
theorem x86_popcount_zero :
    GeneratedX86Popcount.value 0 = 0 := by native_decide

/-- Canonical example: one bit set. -/
theorem x86_popcount_one :
    GeneratedX86Popcount.value 0x8000000000000000 = 1 := by native_decide

/-- Canonical example: all bits set. -/
theorem x86_popcount_full :
    GeneratedX86Popcount.value 0xffffffffffffffff = 64 := by native_decide

/-- Canonical example: an alternating pattern. -/
theorem x86_popcount_alternating :
    GeneratedX86Popcount.value 0x5555555555555555 = 32 := by native_decide

end KProgFormal
