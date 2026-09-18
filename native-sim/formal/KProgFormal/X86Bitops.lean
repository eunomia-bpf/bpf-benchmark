import KProgFormal.GeneratedX86Bitops
import Std.Tactic.BVDecide

namespace KProgFormal

/-- Independent width mask for an x86 width code (1/2/4/8 bytes), built from the
2^(8*code) exponent rather than the generated match table. -/
def x86BitopsMaskCode (widthCode : Nat) : BitVec 64 :=
  BitVec.ofNat 64 (2 ^ (8 * widthCode)) - 1

/-- Independent statement of `bt`'s carry result: test the indexed bit through a
single-bit mask (a different expression tree than the generated
shift-and-extract), with the index masked to the simulator's hardware `63 : 31`
pair. -/
def x86BtSpec (base index : BitVec 64) (widthCode : Nat) : Bool :=
  let bit := index &&& (if widthCode = 8 then 63 else 31)
  let oneBit := (BitVec.ofNat 64 1 <<< bit) &&& x86BitopsMaskCode widthCode
  (base &&& oneBit) != 0

/-- The generated `bt` equals the independent single-bit-mask test for all four
width codes. -/
theorem x86_bt_refines (base index : BitVec 64) (widthCode : Nat)
    (h : widthCode = 1 ∨ widthCode = 2 ∨ widthCode = 4 ∨ widthCode = 8) :
    GeneratedX86Bitops.bt base index widthCode = x86BtSpec base index widthCode := by
  rcases h with rfl | rfl | rfl | rfl <;>
    simp only [GeneratedX86Bitops.bt, GeneratedX86Bitops.widthMask, x86BtSpec,
      x86BitopsMaskCode] <;>
    bv_decide

/-- Independent statement of `bzhi`: keep the low `count` bits through the
exponent-built mask rather than the generated `widthMask` table. -/
def x86BzhiSpec (src count : BitVec 64) (widthCode : Nat) : BitVec 64 :=
  let b := widthCode * 8
  let c := count &&& 0xff
  let kept := if BitVec.ult c (BitVec.ofNat 64 b)
              then (BitVec.ofNat 64 1 <<< c) - 1
              else x86BitopsMaskCode widthCode
  src &&& kept &&& x86BitopsMaskCode widthCode

/-- The generated `bzhi` equals the independent kept-mask statement for all four
width codes. -/
theorem x86_bzhi_refines (src count : BitVec 64) (widthCode : Nat)
    (h : widthCode = 1 ∨ widthCode = 2 ∨ widthCode = 4 ∨ widthCode = 8) :
    GeneratedX86Bitops.bzhi src count widthCode =
      x86BzhiSpec src count widthCode := by
  rcases h with rfl | rfl | rfl | rfl <;>
    simp only [GeneratedX86Bitops.bzhi, GeneratedX86Bitops.widthMask, x86BzhiSpec,
      x86BitopsMaskCode] <;>
    bv_decide

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

/-- Canonical example: an 8-bit `bt` with an offset at or above the width tests a
bit the byte does not have, and always yields false. -/
theorem x86_bt_wide_index_false :
    GeneratedX86Bitops.bt 0xff 8 1 = false ∧
    GeneratedX86Bitops.bt 0xff 31 1 = false := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- Canonical example: `bzhi` keeps the low `count` bits. -/
theorem x86_bzhi_example :
    GeneratedX86Bitops.bzhi 0xffff 4 8 = 0xf := by native_decide

end KProgFormal
