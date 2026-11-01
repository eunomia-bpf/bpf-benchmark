import KProgFormal.GeneratedArm64Width
import KProgFormal.GeneratedX86Width

/-!
The two ISAs share one width vocabulary, and both generated width contracts
define it independently. Nothing forced them to agree: `arm64_width_spec.json`
and `x86_width_spec.json` are separate inputs to separate generators, and each
renders its own C header and Lean module. A drifted mask or bit count on one
side would make the two simulators disagree about what an 8-bit write means
while every per-ISA theorem continued to hold.

This module states the agreement as theorems over the generated definitions,
so a drift in either spec breaks the build here rather than surfacing as a
per-ISA inconsistency. It compares the contracts only; it does not duplicate
either one.
-/

namespace KProgFormal.CrossIsaWidth

open KProgFormal

/-- Map the shared width vocabulary across the two generated contracts. The
constructors are the same four on both sides, so this is a pure renaming. -/
def toX86 : GeneratedArm64Width.Width → GeneratedX86Width.Width
  | .w8 => .w8
  | .w16 => .w16
  | .w32 => .w32
  | .w64 => .w64

/-- The width codes agree: both ISAs name 8/16/32/64-bit widths 1/2/4/8. -/
theorem code_agrees (w : GeneratedArm64Width.Width) :
    GeneratedArm64Width.code w = GeneratedX86Width.code (toX86 w) := by
  cases w <;> rfl

/-- The width masks agree, so a narrow write keeps the same low bits on both
ISAs. -/
theorem mask_agrees (w : GeneratedArm64Width.Width) :
    GeneratedArm64Width.mask w = GeneratedX86Width.mask (toX86 w) := by
  cases w <;> rfl

/-- The sign masks agree, which is the bit each ISA's `sign` reads. -/
theorem signMask_agrees (w : GeneratedArm64Width.Width) :
    GeneratedArm64Width.signMask w = GeneratedX86Width.signMask (toX86 w) := by
  cases w <;> rfl

/-- The bit counts agree, so the sign-bit position is the same on both. -/
theorem bits_agrees (w : GeneratedArm64Width.Width) :
    GeneratedArm64Width.bits w = GeneratedX86Width.bits (toX86 w) := by
  cases w <;> rfl

/-- Truncating a value agrees, which is what makes a narrow result equal
across the two simulators. -/
theorem narrow_agrees (value : BitVec 64) (w : GeneratedArm64Width.Width) :
    GeneratedArm64Width.narrow value w =
      GeneratedX86Width.narrow value (toX86 w) := by
  cases w <;> rfl

/-- The zero test agrees, so a narrow compare-to-zero decides the same way. -/
theorem zero_agrees (value : BitVec 64) (w : GeneratedArm64Width.Width) :
    GeneratedArm64Width.zero value w = GeneratedX86Width.zero value (toX86 w) := by
  cases w <;> rfl

/-- The sign test agrees, so a narrow signed condition reads the same bit. -/
theorem sign_agrees (value : BitVec 64) (w : GeneratedArm64Width.Width) :
    GeneratedArm64Width.sign value w = GeneratedX86Width.sign value (toX86 w) := by
  cases w <;> rfl

/-- The absent-width code agrees: both ISAs spell "no width field" as 0. -/
theorem absentCode_agrees :
    GeneratedArm64Width.absentCode = GeneratedX86Width.absentCode := rfl

/-- The default code agrees: an absent field resolves to 8 (64-bit) on both. -/
theorem defaultCode_agrees :
    GeneratedArm64Width.defaultCode = GeneratedX86Width.defaultCode := rfl

/-- The absence rule agrees, so an empty width field resolves the same way on
both ISAs. -/
theorem effective_agrees (code : Nat) :
    GeneratedArm64Width.effective code = GeneratedX86Width.effective code := by
  simp only [GeneratedArm64Width.effective, GeneratedX86Width.effective,
    absentCode_agrees, defaultCode_agrees]

end KProgFormal.CrossIsaWidth