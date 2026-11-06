import KProgFormal.Generated.GeneratedX86DoubleShift
import Std.Tactic.BVDecide
import KProgFormal.Reference.X86

namespace KProgFormal

/-- The sole ISA reference states double-shift values by concatenation. -/
def x86ShldSpec (dst src shiftv : BitVec 64) (widthCode : Nat) : BitVec 64 :=
  Reference.X86.doubleShiftValue true dst src shiftv (8 * widthCode)

def x86ShrdSpec (dst src shiftv : BitVec 64) (widthCode : Nat) : BitVec 64 :=
  Reference.X86.doubleShiftValue false dst src shiftv (8 * widthCode)

/-- The generated SHLD equals the independent doubled-word statement for all four
width codes. -/
theorem x86_shld_refines (dst src shiftv : BitVec 64) (widthCode : Nat)
    (h : widthCode = 1 ∨ widthCode = 2 ∨ widthCode = 4 ∨ widthCode = 8) :
    GeneratedX86DoubleShift.shld dst src shiftv widthCode =
      x86ShldSpec dst src shiftv widthCode := by
  rcases h with rfl | rfl | rfl | rfl <;>
    simp only [GeneratedX86DoubleShift.shld, GeneratedX86DoubleShift.widthMask,
      GeneratedX86DoubleShift.countMask, x86ShldSpec, Reference.X86.doubleShiftValue,
      Reference.X86.doubleShiftCount, Reference.Word, Bool.true_eq_false, ↓reduceIte] <;>
    bv_decide

/-- The generated SHRD equals the independent doubled-word statement for all four
width codes. -/
theorem x86_shrd_refines (dst src shiftv : BitVec 64) (widthCode : Nat)
    (h : widthCode = 1 ∨ widthCode = 2 ∨ widthCode = 4 ∨ widthCode = 8) :
    GeneratedX86DoubleShift.shrd dst src shiftv widthCode =
      x86ShrdSpec dst src shiftv widthCode := by
  rcases h with rfl | rfl | rfl | rfl <;>
    simp only [GeneratedX86DoubleShift.shrd, GeneratedX86DoubleShift.widthMask,
      GeneratedX86DoubleShift.countMask, x86ShrdSpec, Reference.X86.doubleShiftValue,
      Reference.X86.doubleShiftCount, Reference.Word, Bool.false_eq_true, ↓reduceIte] <;>
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
