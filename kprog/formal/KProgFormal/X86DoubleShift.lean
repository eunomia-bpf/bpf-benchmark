import KProgFormal.GeneratedX86DoubleShift
import Std.Tactic.BVDecide

namespace KProgFormal

/-- Independent width mask for an x86 width code, built from the `2^(8*code)`
exponent rather than the generated match table. -/
def x86DoubleShiftMask (widthCode : Nat) : BitVec 64 :=
  BitVec.ofNat 64 (2 ^ (8 * widthCode)) - 1

/-- Independent statement of the hardware count: masked to 63 for a 64-bit base
and 31 otherwise, stated over the code. -/
def x86DoubleShiftCount (widthCode : Nat) (shiftv : BitVec 64) : BitVec 64 :=
  shiftv &&& (if widthCode = 8 then 63 else 31)

/-- The 2b-bit word `(dst : src)` for a width code: destination high, source low,
each masked to the code's width. -/
private def pairDS (dst src : BitVec 64) (widthCode : Nat) : BitVec 128 :=
  (((dst &&& x86DoubleShiftMask widthCode).setWidth 128) <<< (8 * widthCode)) |||
  ((src &&& x86DoubleShiftMask widthCode).setWidth 128)

/-- The 2b-bit word `(src : dst)` for a width code. -/
private def pairSD (dst src : BitVec 64) (widthCode : Nat) : BitVec 128 :=
  (((src &&& x86DoubleShiftMask widthCode).setWidth 128) <<< (8 * widthCode)) |||
  ((dst &&& x86DoubleShiftMask widthCode).setWidth 128)

/-- Independent statement of SHLD: shift the `(dst : src)` doubled word left by
the hardware-masked count and take its high half, the architectural definition,
which shares no expression with the generated OR-of-two-shifts form. -/
def x86ShldSpec (dst src shiftv : BitVec 64) (widthCode : Nat) : BitVec 64 :=
  let b := 8 * widthCode
  let k := (x86DoubleShiftCount widthCode shiftv).setWidth 128
  (pairDS dst src widthCode <<< k >>> (BitVec.ofNat 128 b)).setWidth b |>.setWidth 64

/-- Independent statement of SHRD: shift the `(src : dst)` doubled word right by
the hardware-masked count and take its low half. -/
def x86ShrdSpec (dst src shiftv : BitVec 64) (widthCode : Nat) : BitVec 64 :=
  let b := 8 * widthCode
  let k := (x86DoubleShiftCount widthCode shiftv).setWidth 128
  (pairSD dst src widthCode >>> k).setWidth b |>.setWidth 64

/-- The generated SHLD equals the independent doubled-word statement for all four
width codes. -/
theorem x86_shld_refines (dst src shiftv : BitVec 64) (widthCode : Nat)
    (h : widthCode = 1 ∨ widthCode = 2 ∨ widthCode = 4 ∨ widthCode = 8) :
    GeneratedX86DoubleShift.shld dst src shiftv widthCode =
      x86ShldSpec dst src shiftv widthCode := by
  rcases h with rfl | rfl | rfl | rfl <;>
    simp only [GeneratedX86DoubleShift.shld, GeneratedX86DoubleShift.widthMask,
      GeneratedX86DoubleShift.countMask, x86ShldSpec, x86DoubleShiftMask,
      x86DoubleShiftCount, pairDS] <;>
    bv_decide

/-- The generated SHRD equals the independent doubled-word statement for all four
width codes. -/
theorem x86_shrd_refines (dst src shiftv : BitVec 64) (widthCode : Nat)
    (h : widthCode = 1 ∨ widthCode = 2 ∨ widthCode = 4 ∨ widthCode = 8) :
    GeneratedX86DoubleShift.shrd dst src shiftv widthCode =
      x86ShrdSpec dst src shiftv widthCode := by
  rcases h with rfl | rfl | rfl | rfl <;>
    simp only [GeneratedX86DoubleShift.shrd, GeneratedX86DoubleShift.widthMask,
      GeneratedX86DoubleShift.countMask, x86ShrdSpec, x86DoubleShiftMask,
      x86DoubleShiftCount, pairSD] <;>
    bv_decide

/-- A zero count leaves the destination untouched: both double shifts are no-ops
at count zero. -/
theorem x86_doubleshift_zero_count (dst src : BitVec 64) :
    GeneratedX86DoubleShift.shld dst src 0 1 = dst &&& 0xff ∧
    GeneratedX86DoubleShift.shrd dst src 0 1 = dst &&& 0xff ∧
    GeneratedX86DoubleShift.shld dst src 0 8 = dst ∧
    GeneratedX86DoubleShift.shrd dst src 0 8 = dst := by
  simp only [GeneratedX86DoubleShift.shld, GeneratedX86DoubleShift.shrd,
    GeneratedX86DoubleShift.countMask]
  refine ⟨?_, ?_, ?_, ?_⟩ <;> simp

/-- Canonical example: a 64-bit SHLD by 4 moves the top nibble of `src` in. -/
theorem x86_shld_w64_example :
    GeneratedX86DoubleShift.shld 0xf0 0x0f 4 8 = 0xf00 := by native_decide

/-- Canonical example: an 8-bit SHRD by 4 fills from the top of `src`. -/
theorem x86_shrd_w8_example :
    GeneratedX86DoubleShift.shrd 0xf0 0x0f 4 1 = 0xff := by native_decide

end KProgFormal
