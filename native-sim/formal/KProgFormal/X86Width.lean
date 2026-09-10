import KProgFormal.GeneratedX86Width
namespace KProgFormal
abbrev X86Width := GeneratedX86Width.Width
abbrev X86Word := BitVec 64
def x86WidthCodeSpec : X86Width -> Nat | .w8 => 1 | .w16 => 2 | .w32 => 4 | .w64 => 8
def x86WidthMaskSpec : X86Width -> X86Word
  | .w8 => BitVec.ofNat 64 0xff
  | .w16 => BitVec.ofNat 64 0xffff
  | .w32 => BitVec.ofNat 64 0xffffffff
  | .w64 => BitVec.ofNat 64 0xffffffffffffffff
def x86WidthSignMaskSpec : X86Width -> X86Word
  | .w8 => BitVec.ofNat 64 0x80
  | .w16 => BitVec.ofNat 64 0x8000
  | .w32 => BitVec.ofNat 64 0x80000000
  | .w64 => BitVec.ofNat 64 0x8000000000000000
def x86WidthBitsSpec : X86Width -> Nat | .w8 => 8 | .w16 => 16 | .w32 => 32 | .w64 => 64
def x86NarrowSpec (v:X86Word) (w:X86Width) := BitVec.and v (x86WidthMaskSpec w)
def x86ZeroSpec (v:X86Word) (w:X86Width) : Bool := x86NarrowSpec v w == 0
def x86SignSpec (v:X86Word) (w:X86Width) : Bool := (x86NarrowSpec v w).getLsbD (x86WidthBitsSpec w-1)
theorem x86_width_mask_refines (w:X86Width) : GeneratedX86Width.mask w=x86WidthMaskSpec w := by cases w <;> rfl
theorem x86_width_sign_mask_refines (w:X86Width) : GeneratedX86Width.signMask w=x86WidthSignMaskSpec w := by cases w <;> rfl
theorem x86_width_code_refines (w:X86Width) : GeneratedX86Width.code w=x86WidthCodeSpec w := by cases w <;> rfl
theorem x86_narrow_refines (v:X86Word) (w:X86Width) : GeneratedX86Width.narrow v w=x86NarrowSpec v w := by cases w <;> rfl
theorem x86_zero_refines (v:X86Word) (w:X86Width) : GeneratedX86Width.zero v w=x86ZeroSpec v w := by cases w <;> rfl
theorem x86_sign_refines (v:X86Word) (w:X86Width) : GeneratedX86Width.sign v w=x86SignSpec v w := by cases w <;> rfl
theorem x86_sign_mask_observes (v:X86Word) (w:X86Width) :
    (BitVec.and (x86NarrowSpec v w) (x86WidthSignMaskSpec w) != 0) =
      x86SignSpec v w := by
  cases w <;> simp [x86NarrowSpec, x86WidthSignMaskSpec, x86SignSpec,
    x86WidthMaskSpec, x86WidthBitsSpec] <;> bv_decide
end KProgFormal
