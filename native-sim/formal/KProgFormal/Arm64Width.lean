import KProgFormal.GeneratedArm64Width
namespace KProgFormal
abbrev Arm64Width := GeneratedArm64Width.Width
abbrev Arm64Word := BitVec 64
def arm64WidthCodeSpec : Arm64Width -> Nat | .w8 => 1 | .w16 => 2 | .w32 => 4 | .w64 => 8
def arm64WidthMaskSpec : Arm64Width -> Arm64Word
  | .w8 => BitVec.ofNat 64 0xff
  | .w16 => BitVec.ofNat 64 0xffff
  | .w32 => BitVec.ofNat 64 0xffffffff
  | .w64 => BitVec.ofNat 64 0xffffffffffffffff
def arm64WidthSignMaskSpec : Arm64Width -> Arm64Word
  | .w8 => BitVec.ofNat 64 0x80
  | .w16 => BitVec.ofNat 64 0x8000
  | .w32 => BitVec.ofNat 64 0x80000000
  | .w64 => BitVec.ofNat 64 0x8000000000000000
def arm64WidthBitsSpec : Arm64Width -> Nat | .w8 => 8 | .w16 => 16 | .w32 => 32 | .w64 => 64
def arm64NarrowSpec (v : Arm64Word) (w : Arm64Width) := BitVec.and v (arm64WidthMaskSpec w)
def arm64ZeroSpec (v : Arm64Word) (w : Arm64Width) : Bool := arm64NarrowSpec v w == 0
def arm64SignSpec (v : Arm64Word) (w : Arm64Width) : Bool :=
  (arm64NarrowSpec v w).getLsbD (arm64WidthBitsSpec w - 1)
theorem arm64_width_code_refines (w : Arm64Width) :
    GeneratedArm64Width.code w = arm64WidthCodeSpec w := by cases w <;> rfl
theorem arm64_width_mask_refines (w : Arm64Width) :
    GeneratedArm64Width.mask w = arm64WidthMaskSpec w := by cases w <;> rfl
theorem arm64_width_sign_mask_refines (w : Arm64Width) :
    GeneratedArm64Width.signMask w = arm64WidthSignMaskSpec w := by cases w <;> rfl
theorem arm64_width_bits_refines (w : Arm64Width) :
    GeneratedArm64Width.bits w = arm64WidthBitsSpec w := by cases w <;> rfl
theorem arm64_narrow_refines (v : Arm64Word) (w : Arm64Width) :
    GeneratedArm64Width.narrow v w = arm64NarrowSpec v w := by cases w <;> rfl
theorem arm64_zero_refines (v : Arm64Word) (w : Arm64Width) :
    GeneratedArm64Width.zero v w = arm64ZeroSpec v w := by cases w <;> rfl
theorem arm64_sign_refines (v : Arm64Word) (w : Arm64Width) :
    GeneratedArm64Width.sign v w = arm64SignSpec v w := by cases w <;> rfl
/-- Testing the sign bit through the width sign mask agrees with the shift-based
sign observation, so the C `KPROG_ARM64_WIDTH_SIGN_MASK` test and the generated
`sign` definition pick the same bit. -/
theorem arm64_sign_mask_observes (v : Arm64Word) (w : Arm64Width) :
    (BitVec.and (arm64NarrowSpec v w) (arm64WidthSignMaskSpec w) != 0) =
      arm64SignSpec v w := by
  cases w <;> simp [arm64NarrowSpec, arm64WidthSignMaskSpec, arm64SignSpec,
    arm64WidthMaskSpec, arm64WidthBitsSpec] <;> bv_decide
end KProgFormal
