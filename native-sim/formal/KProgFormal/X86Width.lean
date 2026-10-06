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
theorem x86_width_bits_refines (w:X86Width) : GeneratedX86Width.bits w=x86WidthBitsSpec w := by cases w <;> rfl
theorem x86_narrow_refines (v:X86Word) (w:X86Width) : GeneratedX86Width.narrow v w=x86NarrowSpec v w := by cases w <;> rfl
theorem x86_zero_refines (v:X86Word) (w:X86Width) : GeneratedX86Width.zero v w=x86ZeroSpec v w := by cases w <;> rfl
theorem x86_sign_refines (v:X86Word) (w:X86Width) : GeneratedX86Width.sign v w=x86SignSpec v w := by cases w <;> rfl
theorem x86_sign_mask_observes (v:X86Word) (w:X86Width) :
    (BitVec.and (x86NarrowSpec v w) (x86WidthSignMaskSpec w) != 0) =
      x86SignSpec v w := by
  cases w <;> simp [x86NarrowSpec, x86WidthSignMaskSpec, x86SignSpec,
    x86WidthMaskSpec, x86WidthBitsSpec] <;> bv_decide
/-- The decoded width code that means "absent", stated independently of the
generated contract: the code the simulator leaves in an unused width field. -/
def x86AbsentCodeSpec : Nat := 0
/-- The code an absent width field resolves to, stated independently: the
64-bit width's code. -/
def x86DefaultCodeSpec : Nat := 8
/-- The width code a body operates at: the decoded code itself, or the 64-bit
default when the decoded code is absent. This is the resolution the simulator
restated inline; it now shares this one kernel. -/
def x86EffectiveCodeSpec (c : Nat) : Nat :=
  if c = x86AbsentCodeSpec then x86DefaultCodeSpec else c
theorem x86_effective_refines (c : Nat) :
    GeneratedX86Width.effective c = x86EffectiveCodeSpec c := by rfl
theorem x86_effective_absent_is_default :
    x86EffectiveCodeSpec x86AbsentCodeSpec = x86DefaultCodeSpec := by rfl
/-- The absent code names no width, so the fallback only fires on a genuinely
unused field and every real code is used as decoded. -/
theorem x86_absent_code_names_no_width (w : X86Width) :
    x86WidthCodeSpec w != x86AbsentCodeSpec := by cases w <;> decide
/-- The absent field's fallback code is exactly the 64-bit width's code, pinned
against the generated `x86_width.h` decode so the default cannot drift. -/
theorem x86_default_code_is_w64 :
    x86WidthCodeSpec .w64 = x86DefaultCodeSpec := by rfl
/-- A decoded width code is its own effective code: the resolution is the
identity on every real width, and only rewrites the absent code. -/
theorem x86_effective_identity_on_width (w : X86Width) :
    x86EffectiveCodeSpec (x86WidthCodeSpec w) = x86WidthCodeSpec w := by
  cases w <;> rfl
end KProgFormal
