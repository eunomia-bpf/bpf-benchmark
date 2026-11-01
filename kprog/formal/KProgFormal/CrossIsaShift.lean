import KProgFormal.GeneratedArm64Shift
import KProgFormal.GeneratedX86ShiftCount
import KProgFormal.GeneratedX86ShiftResult

/-!
The two architectures mask a shift amount differently.

AArch64 takes the amount modulo 32 at 32-bit width and modulo 64 at 64-bit
width. x86-64 takes it modulo 64 at 64-bit width and modulo 32 otherwise,
because it only has 64- and 32-bit shifts: an 8- or 16-bit shift is performed
at 32 bits and truncated.

At the two widths AArch64 actually encodes -- W and X, i.e. 32 and 64 -- the
two rules coincide exactly, so a shift of the same value by the same amount
produces the same result on both. At 8 and 16 bits they do not coincide, and
the divergence is real rather than representational: with `v = 1` and an
amount of 32, AArch64's rule masks to `0` and x86-64's to `32`, giving `0`
against `1`. That pair is unreachable from AArch64, which never encodes an
8- or 16-bit shift, so the disagreement is a property of the two contracts
rather than of any program either simulator runs. Recording it as a theorem is
what keeps that distinction explicit: a later change that starts emitting
narrow shifts would turn a proved agreement into a live difference, and this
module is where it shows up.

The result agreement for add/shift at the reachable widths follows from the
count agreement plus equal masking, which `GeneratedArm64Shift` and
`GeneratedX86ShiftResult` already state.
-/

namespace KProgFormal.CrossIsaShift

open KProgFormal

/-- The AArch64 amount mask, as the generated contract defines it. -/
def arm64CountMask (w : GeneratedArm64Width.Width) : BitVec 64 :=
  if w = .w32 then 31 else 63

/-- At 32-bit width the two rules agree. -/
theorem count_mask_w32 :
    arm64CountMask .w32 = GeneratedX86ShiftCount.mask .w32 := by rfl

/-- At 64-bit width they agree. -/
theorem count_mask_w64 :
    arm64CountMask .w64 = GeneratedX86ShiftCount.mask .w64 := by rfl

/-- At the narrower widths they disagree, and here is the concrete case: an
amount of 32 masks to 0 under AArch64's rule and to 32 under x86-64's, so
shifting `1` left by it gives `0` against `1`. -/
theorem count_mask_differs_at_w8 :
    arm64CountMask .w8 ≠ GeneratedX86ShiftCount.mask .w8 ∧
      ((32 : BitVec 64) &&& arm64CountMask .w8 = 32) ∧
      ((32 : BitVec 64) &&& GeneratedX86ShiftCount.mask .w8 = 0) ∧
      (GeneratedArm64Shift.value .lsl 1 32 .w8 = 0) ∧
      (GeneratedX86ShiftResult.shl 1 32 .w8 = 1) := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> decide

/-- The two widths AArch64 encodes are exactly the two at which the rules
agree, so the agreement holds on the whole reachable set rather than by luck
at one width. -/
theorem agrees_at_every_encoded_width (w : GeneratedArm64Width.Width)
    (h : w = .w32 ∨ w = .w64) :
    arm64CountMask w = GeneratedX86ShiftCount.mask
      (match w with
       | .w32 => .w32
       | .w64 => .w64
       | .w8 => .w8
       | .w16 => .w16) := by
  rcases h with rfl | rfl
  · exact count_mask_w32
  · exact count_mask_w64

end KProgFormal.CrossIsaShift