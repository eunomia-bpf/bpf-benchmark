import KProgFormal.Generated.GeneratedX86Bitops
import KProgFormal.X86Width
import KProgFormal.Reference.X86
import Std.Tactic.BVDecide

namespace KProgFormal

/-- Independent width mask for an x86 width code (1/2/4/8 bytes), built from the
2^(8*code) exponent rather than the generated match table. -/
def x86BitopsMaskCode (widthCode : Nat) : BitVec 64 :=
  BitVec.ofNat 64 (2 ^ (8 * widthCode)) - 1

/-- The sole ISA reference supplies the bit-selection rule. -/
def x86BtSpec (base index : BitVec 64) (widthCode : Nat) : Bool :=
  Reference.X86.bitTest base index (widthCode * 8)

/-- The generated `bt` equals the independent single-bit-mask test for all four
width codes. -/
theorem x86_bt_refines (base index : BitVec 64) (widthCode : Nat)
    (h : widthCode = 1 ∨ widthCode = 2 ∨ widthCode = 4 ∨ widthCode = 8) :
    GeneratedX86Bitops.bt base index widthCode = x86BtSpec base index widthCode := by
  rcases h with rfl | rfl | rfl | rfl <;>
    simp only [GeneratedX86Bitops.bt, GeneratedX86Bitops.widthMask, x86BtSpec,
      x86BitopsMaskCode, Reference.X86.bitTest, Reference.Word] <;>
    bv_decide

/-- The sole ISA reference supplies the zero-high-bits rule. -/
def x86BzhiSpec (src count : BitVec 64) (widthCode : Nat) : BitVec 64 :=
  Reference.X86.zeroHighBits src count (widthCode * 8)

/-- The generated `bzhi` equals the independent kept-mask statement for all four
width codes. -/
theorem x86_bzhi_refines (src count : BitVec 64) (widthCode : Nat)
    (h : widthCode = 1 ∨ widthCode = 2 ∨ widthCode = 4 ∨ widthCode = 8) :
    GeneratedX86Bitops.bzhi src count widthCode =
      x86BzhiSpec src count widthCode := by
  rcases h with rfl | rfl | rfl | rfl <;>
    simp only [GeneratedX86Bitops.bzhi, GeneratedX86Bitops.widthMask, x86BzhiSpec,
      x86BitopsMaskCode, Reference.X86.zeroHighBits, Reference.Word] <;>
    bv_decide

/-- The four legal x86 width codes, as the closed set `bt`/`bzhi` are defined
on. -/
theorem x86_width_code_spec_cases (w : X86Width) :
    x86WidthCodeSpec w = 1 ∨ x86WidthCodeSpec w = 2 ∨
      x86WidthCodeSpec w = 4 ∨ x86WidthCodeSpec w = 8 := by
  cases w <;> simp [x86WidthCodeSpec]

/-- Width-indexed bridge: the generated `bt` at the generated width code
refines the independent `bt` statement at the independent width code. -/
theorem x86_bt_refines_width (base index : BitVec 64) (width : X86Width) :
    GeneratedX86Bitops.bt base index (GeneratedX86Width.code width) =
      x86BtSpec base index (x86WidthCodeSpec width) := by
  rw [x86_width_code_refines]
  exact x86_bt_refines base index (x86WidthCodeSpec width)
    (x86_width_code_spec_cases width)

/-- Width-indexed bridge: the generated `bzhi` at the generated width code
refines the independent `bzhi` statement at the independent width code. -/
theorem x86_bzhi_refines_width (src count : BitVec 64) (width : X86Width) :
    GeneratedX86Bitops.bzhi src count (GeneratedX86Width.code width) =
      x86BzhiSpec src count (x86WidthCodeSpec width) := by
  rw [x86_width_code_refines]
  exact x86_bzhi_refines src count (x86WidthCodeSpec width)
    (x86_width_code_spec_cases width)

/-- `bzhi` never sets a bit above its width: the result is always within the
width mask. -/
theorem x86_bzhi_within_width (src count : BitVec 64) :
    BitVec.ule (GeneratedX86Bitops.bzhi src count 1) (0xff : BitVec 64) = true ∧
    BitVec.ule (GeneratedX86Bitops.bzhi src count 2) (0xffff : BitVec 64) =
      true ∧
    BitVec.ule (GeneratedX86Bitops.bzhi src count 4) (0xffffffff : BitVec 64) =
      true := by
  simp only [GeneratedX86Bitops.bzhi, GeneratedX86Bitops.widthMask]
  refine ⟨?_, ?_, ?_⟩ <;> bv_decide

/-- A `bzhi` whose index reaches the width keeps the whole narrowed base: no bits
are cleared. -/
theorem x86_bzhi_max_index_keeps (src : BitVec 64) :
    GeneratedX86Bitops.bzhi src 0xff 1 = src &&& 0xff := by
  simp only [GeneratedX86Bitops.bzhi, GeneratedX86Bitops.widthMask]
  bv_decide

/-- Canonical example: `bt` of bit 3 of a 64-bit base is set. -/
theorem x86_bt_example :
    GeneratedX86Bitops.bt 0x8 3 8 = true ∧
    GeneratedX86Bitops.bt 0x8 2 8 = false := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Bits above the operand width cannot leak into CF when the index wraps. -/
theorem x86_bt_wide_index_false :
    GeneratedX86Bitops.bt 0x100 8 1 = false ∧
    GeneratedX86Bitops.bt 0x100 31 1 = false := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Regression: index 16 wraps to bit zero at operand size 16; index 31
selects bit 15, not a nonexistent bit in the narrowed value. -/
theorem x86_bt_w16_index_wraps :
    GeneratedX86Bitops.bt 1 16 2 = true ∧
    GeneratedX86Bitops.bt 0x8000 31 2 = true := by decide

/-- Canonical example: `bzhi` keeps the low `count` bits. -/
theorem x86_bzhi_example :
    GeneratedX86Bitops.bzhi 0xffff 4 8 = 0xf := by native_decide

end KProgFormal
