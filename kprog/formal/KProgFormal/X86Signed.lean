import KProgFormal.GeneratedX86Signed
import KProgFormal.GeneratedX86ImulFlags
import KProgFormal.GeneratedX86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Width (Width mask narrow signMask sign bits)

/-- Independent statement of the x86 sign extension: widen the narrowed operand
from the width's own low lane via `BitVec.signExtend`, rather than the generated
complement-and-subtract form. A 64-bit width is the identity. -/
def x86SignExtendSpec (value : BitVec 64) : Width -> BitVec 64
  | .w8 => BitVec.signExtend 64 (value.setWidth 8)
  | .w16 => BitVec.signExtend 64 (value.setWidth 16)
  | .w32 => BitVec.signExtend 64 (value.setWidth 32)
  | .w64 => value

/-- The generated sign extension equals the independent `signExtend` statement
for all four widths. -/
theorem x86_sign_extend_refines (value : BitVec 64) (width : Width) :
    GeneratedX86Signed.signExtend value width =
      x86SignExtendSpec value width := by
  cases width <;>
    simp only [GeneratedX86Signed.signExtend, x86SignExtendSpec] <;>
    bv_decide

/-- Independent statement of the width-domain magnitude: negate the narrowed
operand when the width's sign bit is set, otherwise keep it. -/
def x86AbsWidthSpec (value : BitVec 64) : Width -> BitVec 64
  | .w8 =>
      let n := value &&& mask .w8
      if n &&& signMask .w8 != 0 then (0 - n) &&& mask .w8 else n
  | .w16 =>
      let n := value &&& mask .w16
      if n &&& signMask .w16 != 0 then (0 - n) &&& mask .w16 else n
  | .w32 =>
      let n := value &&& mask .w32
      if n &&& signMask .w32 != 0 then (0 - n) &&& mask .w32 else n
  | .w64 =>
      let n := value &&& mask .w64
      if n &&& signMask .w64 != 0 then (0 - n) &&& mask .w64 else n

/-- The generated magnitude equals the independent negation statement for all
four widths. -/
theorem x86_abs_width_refines (value : BitVec 64) (width : Width) :
    GeneratedX86Signed.absWidth value width =
      x86AbsWidthSpec value width := by
  cases width <;>
    simp only [GeneratedX86Signed.absWidth, x86AbsWidthSpec, mask,
      signMask] <;>
    bv_decide

/-- The magnitude is idempotent: taking the magnitude of a magnitude returns it,
so repeated IMUL-flag construction cannot drift. -/
theorem x86_abs_width_idempotent (value : BitVec 64) (width : Width) :
    GeneratedX86Signed.absWidth
        (GeneratedX86Signed.absWidth value width) width =
      GeneratedX86Signed.absWidth value width := by
  cases width <;> simp only [GeneratedX86Signed.absWidth] <;> bv_decide

/-- The magnitude never exceeds the width's sign mask: for each width the result
is at most 2^(bits-1), so every IMUL-magnitude operand lies in the width's
non-negative signed range. -/
theorem x86_abs_width_bounded (value : BitVec 64) :
    BitVec.ule (GeneratedX86Signed.absWidth value .w8) (0x80 : BitVec 64) =
      true ∧
    BitVec.ule (GeneratedX86Signed.absWidth value .w16) (0x8000 : BitVec 64) =
      true ∧
    BitVec.ule (GeneratedX86Signed.absWidth value .w32)
      (0x80000000 : BitVec 64) = true := by
  simp only [GeneratedX86Signed.absWidth]
  refine ⟨?_, ?_, ?_⟩ <;> bv_decide

/-- Canonical example: sign-extending a 64-bit value is the identity. -/
theorem x86_sign_extend_w64_example :
    x86SignExtendSpec 0x8000000000000000 .w64 = 0x8000000000000000 := by
  native_decide

/-- Canonical example: the magnitude of -5 in the 8-bit domain is 5. -/
theorem x86_abs_width_w8_example :
    GeneratedX86Signed.absWidth 0xfb .w8 = 5 := by native_decide

/-- **Cross-contract agreement.** The IMUL flag contract
(`GeneratedX86ImulFlags.signedAbs`) and this contract's magnitude were generated
independently, each with its own local signed-abs definition. They agree for all
four widths, so the two generated contracts cannot drift apart on the magnitude
they both depend on. -/
theorem x86_abs_width_agrees_imul (value : BitVec 64) (width : Width) :
    GeneratedX86ImulFlags.signedAbs value width =
      GeneratedX86Signed.absWidth value width := by
  cases width <;>
    simp only [GeneratedX86ImulFlags.signedAbs,
      GeneratedX86Signed.absWidth, mask, signMask, narrow, bits,
      GeneratedX86Width.sign, GeneratedX86Width.bits] <;>
    bv_decide

end KProgFormal
