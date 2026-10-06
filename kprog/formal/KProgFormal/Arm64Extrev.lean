import KProgFormal.GeneratedArm64Extrev
import KProgFormal.GeneratedArm64Flags
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open KProgFormal.GeneratedArm64Extrev (Extrev value rev rev16 signExtend)
open KProgFormal.GeneratedArm64Width (Width bits mask narrow)

/-- Independent statement of the AArch64 EXTR value at a concrete bit width:
the low `nb` of the rotate-left of the `src : src2` concatenation, stated over
the 128-bit concatenation so it is structurally separate from the C shift pair.
The shift is the hardware-masked low `nb - 1` bits of the immediate. -/
def arm64ExtrevExtrSpec (src src2 shift : BitVec 64) (nb : Nat) : BitVec 64 :=
  let k := shift &&& BitVec.ofNat 64 (nb - 1)
  let concat : BitVec 128 := (src.setWidth 128 <<< nb) ||| src2.setWidth 128
  (concat >>> k.setWidth 128).setWidth 64 &&& BitVec.ofNat 64 (2^nb - 1)

/-- Independent statement of a four-byte reversal: one shift-and-or term per
architectural byte of the low word, most significant byte first. -/
def arm64ExtrevRev32Spec (v : BitVec 64) : BitVec 64 :=
  (((v &&& 0xff) <<< 24) ||| (((v >>> 8) &&& 0xff) <<< 16) |||
   (((v >>> 16) &&& 0xff) <<< 8) ||| ((v >>> 24) &&& 0xff))

/-- Independent statement of an eight-byte reversal: one shift-and-or term per
architectural byte, most significant byte first. -/
def arm64ExtrevRev64Spec (v : BitVec 64) : BitVec 64 :=
  (((v &&& 0xff) <<< 56) ||| (((v >>> 8) &&& 0xff) <<< 48) |||
   (((v >>> 16) &&& 0xff) <<< 40) ||| (((v >>> 24) &&& 0xff) <<< 32) |||
   (((v >>> 32) &&& 0xff) <<< 24) ||| (((v >>> 40) &&& 0xff) <<< 16) |||
   (((v >>> 48) &&& 0xff) <<< 8) ||| ((v >>> 56) &&& 0xff))

/-- Independent statement of a within-16-bit-unit byte swap over the low word:
swap the two bytes of each of the two units and keep the units in place. -/
def arm64ExtrevRev16W32Spec (v : BitVec 64) : BitVec 64 :=
  (((v &&& 0xff) <<< 8) ||| ((v >>> 8) &&& 0xff)) |||
  (((((v >>> 16) &&& 0xff) <<< 8) ||| ((v >>> 24) &&& 0xff)) <<< 16)

/-- Independent statement of a within-16-bit-unit byte swap over the whole
operand: swap the two bytes of each of the four units. -/
def arm64ExtrevRev16W64Spec (v : BitVec 64) : BitVec 64 :=
  (((v &&& 0xff) <<< 8) ||| ((v >>> 8) &&& 0xff)) |||
  (((((v >>> 16) &&& 0xff) <<< 8) ||| ((v >>> 24) &&& 0xff)) <<< 16) |||
  (((((v >>> 32) &&& 0xff) <<< 8) ||| ((v >>> 40) &&& 0xff)) <<< 32) |||
  (((((v >>> 48) &&& 0xff) <<< 8) ||| ((v >>> 56) &&& 0xff)) <<< 48)

/-- Independent statement of the AArch64 SXTB/SXTH/SXTW value: the library sign
extension of the low `nb` bits. -/
def arm64ExtrevSignExtSpec (v : BitVec 64) (nb : Nat) : BitVec 64 :=
  BitVec.signExtend 64 (v.setWidth nb)

/-- The generated REV arm at word width agrees with the independent four-byte
reversal. C's `width == ARM64_WIDTH_32` test is resolved before the bit-blaster
runs, so no `Width` value reaches the solver. -/
theorem arm64_extrev_rev_w32_refines (v : BitVec 64) :
    rev v .w32 = arm64ExtrevRev32Spec v := by
  unfold rev arm64ExtrevRev32Spec
  rw [if_pos rfl]

/-- The generated REV arm at doubleword width agrees with the independent
eight-byte reversal, which is also the arm every non-word width takes. -/
theorem arm64_extrev_rev_w64_refines (v : BitVec 64) :
    rev v .w64 = arm64ExtrevRev64Spec v := by
  unfold rev arm64ExtrevRev64Spec
  rw [if_neg (by decide : ¬ (Width.w64 = Width.w32))]

/-- The generated REV16 arm at word width agrees with the independent swap of
the two 16-bit units of the low word. -/
theorem arm64_extrev_rev16_w32_refines (v : BitVec 64) :
    rev16 v .w32 = arm64ExtrevRev16W32Spec v := by
  unfold rev16 arm64ExtrevRev16W32Spec
  rw [if_pos rfl]
  bv_decide

/-- The generated REV16 arm at doubleword width agrees with the independent
swap of the four 16-bit units, which is also the arm every non-word width
takes. -/
theorem arm64_extrev_rev16_w64_refines (v : BitVec 64) :
    rev16 v .w64 = arm64ExtrevRev16W64Spec v := by
  unfold rev16 arm64ExtrevRev16W64Spec
  rw [if_neg (by decide : ¬ (Width.w64 = Width.w32))]
  bv_decide

/-- The generated EXTR arm agrees with the independent concatenation statement
once the result is narrowed to the destination width, which is what the C
handler's register write does. The two operands are `nb`-wide, i.e. already
narrowed by their own register writes; this is the 8-bit case. -/
theorem arm64_extrev_extr_w8_refines (src src2 shift : BitVec 64)
    (hs : narrow src .w8 = src) (ht : narrow src2 .w8 = src2) :
    narrow (value .extr src src2 shift .w8) .w8 =
      arm64ExtrevExtrSpec src src2 shift 8 := by
  simp only [value, arm64ExtrevExtrSpec, narrow, bits, mask] <;> bv_decide

/-- The 16-bit case of `arm64_extrev_extr_w8_refines`. -/
theorem arm64_extrev_extr_w16_refines (src src2 shift : BitVec 64)
    (hs : narrow src .w16 = src) (ht : narrow src2 .w16 = src2) :
    narrow (value .extr src src2 shift .w16) .w16 =
      arm64ExtrevExtrSpec src src2 shift 16 := by
  simp only [value, arm64ExtrevExtrSpec, narrow, bits, mask] <;> bv_decide

/-- The 32-bit case of `arm64_extrev_extr_w8_refines`. -/
theorem arm64_extrev_extr_w32_refines (src src2 shift : BitVec 64)
    (hs : narrow src .w32 = src) (ht : narrow src2 .w32 = src2) :
    narrow (value .extr src src2 shift .w32) .w32 =
      arm64ExtrevExtrSpec src src2 shift 32 := by
  simp only [value, arm64ExtrevExtrSpec, narrow, bits, mask] <;> bv_decide

/-- The 64-bit case of `arm64_extrev_extr_w8_refines`; both operands already
fill the width, so no narrowing hypothesis is needed. -/
theorem arm64_extrev_extr_w64_refines (src src2 shift : BitVec 64) :
    narrow (value .extr src src2 shift .w64) .w64 =
      arm64ExtrevExtrSpec src src2 shift 64 := by
  simp only [value, arm64ExtrevExtrSpec, narrow, bits, mask] <;> bv_decide

/-- The generated SXTB arm agrees with the independent 8-bit sign extension. -/
theorem arm64_extrev_sxtb_refines (v : BitVec 64) :
    signExtend v 8 = arm64ExtrevSignExtSpec v 8 := by
  unfold signExtend arm64ExtrevSignExtSpec
  by_cases h : v &&& 0x80 = 0 <;> bv_decide

/-- The generated SXTH arm agrees with the independent 16-bit sign extension. -/
theorem arm64_extrev_sxth_refines (v : BitVec 64) :
    signExtend v 16 = arm64ExtrevSignExtSpec v 16 := by
  unfold signExtend arm64ExtrevSignExtSpec
  by_cases h : v &&& 0x8000 = 0 <;> bv_decide

/-- The generated SXTW arm agrees with the independent 32-bit sign extension. -/
theorem arm64_extrev_sxtw_refines (v : BitVec 64) :
    signExtend v 32 = arm64ExtrevSignExtSpec v 32 := by
  unfold signExtend arm64ExtrevSignExtSpec
  by_cases h : v &&& 0x80000000 = 0 <;> bv_decide

/-- The family-level refinement: each generated arm equals the corresponding
independent statement. The four EXTR conjuncts are at the narrowed result and
carry the two operand-narrowing hypotheses; the REV and REV16 conjuncts cover
the word and doubleword arms the shared C macro selects; the SXT conjuncts are
the three sign extensions. -/
theorem arm64_extrev_family_refines (src src2 shift : BitVec 64)
    (h8 : narrow src .w8 = src ∧ narrow src2 .w8 = src2)
    (h16 : narrow src .w16 = src ∧ narrow src2 .w16 = src2)
    (h32 : narrow src .w32 = src ∧ narrow src2 .w32 = src2) :
    narrow (value .extr src src2 shift .w8) .w8 =
        arm64ExtrevExtrSpec src src2 shift 8 ∧
    narrow (value .extr src src2 shift .w16) .w16 =
        arm64ExtrevExtrSpec src src2 shift 16 ∧
    narrow (value .extr src src2 shift .w32) .w32 =
        arm64ExtrevExtrSpec src src2 shift 32 ∧
    narrow (value .extr src src2 shift .w64) .w64 =
        arm64ExtrevExtrSpec src src2 shift 64 ∧
    rev src .w32 = arm64ExtrevRev32Spec src ∧
    rev src .w64 = arm64ExtrevRev64Spec src ∧
    rev16 src .w32 = arm64ExtrevRev16W32Spec src ∧
    rev16 src .w64 = arm64ExtrevRev16W64Spec src ∧
    signExtend src 8 = arm64ExtrevSignExtSpec src 8 ∧
    signExtend src 16 = arm64ExtrevSignExtSpec src 16 ∧
    signExtend src 32 = arm64ExtrevSignExtSpec src 32 := by
  exact ⟨arm64_extrev_extr_w8_refines src src2 shift h8.1 h8.2,
    arm64_extrev_extr_w16_refines src src2 shift h16.1 h16.2,
    arm64_extrev_extr_w32_refines src src2 shift h32.1 h32.2,
    arm64_extrev_extr_w64_refines src src2 shift,
    arm64_extrev_rev_w32_refines src,
    arm64_extrev_rev_w64_refines src,
    arm64_extrev_rev16_w32_refines src,
    arm64_extrev_rev16_w64_refines src,
    arm64_extrev_sxtb_refines src,
    arm64_extrev_sxth_refines src,
    arm64_extrev_sxtw_refines src⟩

/-- The NZCV transition of an extract/reverse/extend op: the identity. The
generated flag contract models only the ADD/SUB/logical families, so the six
extract/reverse/extend handlers write no flag register and thread the incoming
flag state through unchanged. -/
def arm64ExtrevFlagsSpec (op : Extrev) (_v _shift : BitVec 64) (_width : Width)
    (nzcv : GeneratedArm64Flags.Flags) : GeneratedArm64Flags.Flags :=
  match op with
  | .extr => nzcv
  | .rev => nzcv
  | .rev16 => nzcv
  | .sxth => nzcv
  | .sxtw => nzcv
  | .sxtb => nzcv

/-- Every extract/reverse/extend op leaves NZCV untouched. -/
theorem arm64_extrev_flags_unchanged (op : Extrev) (v shift : BitVec 64)
    (width : Width) (nzcv : GeneratedArm64Flags.Flags) :
    arm64ExtrevFlagsSpec op v shift width nzcv = nzcv := by
  cases op <;> rfl

/-- Every extract/reverse/extend opcode of the generated table is inside the
numeric label range spanned by the shared C macro: the six opcodes are all at or
below `60U`, so a valid `Extrev` always reaches its own case arm and only a code
outside the table reaches the unsupported arm. -/
theorem arm64_extrev_code_in_range (op : Extrev) :
    GeneratedArm64Extrev.code op < 61 := by
  cases op <;> decide

/-- The generated code dispatch: the six mnemonics map onto the six ARM64_OP_*
opcode numbers the C macro switches on. -/
theorem arm64_extrev_code_dispatch :
    GeneratedArm64Extrev.code .extr = 17 ∧
    GeneratedArm64Extrev.code .rev = 19 ∧
    GeneratedArm64Extrev.code .rev16 = 20 ∧
    GeneratedArm64Extrev.code .sxth = 21 ∧
    GeneratedArm64Extrev.code .sxtw = 47 ∧
    GeneratedArm64Extrev.code .sxtb = 60 := by
  decide

/-- Canonical example: a 64-bit EXTR by eight bits splices the high byte of
`src2` onto the low seven bytes of `src`. -/
theorem arm64_ext_rev_extr_w64_example :
    arm64ExtrevExtrSpec 0x0123456789abcdef 0xfedcba9876543210 8 64 =
      0xeffedcba98765432 := by
  native_decide

/-- Canonical example: a 32-bit EXTR narrows to the low word, so the result has
no bits above bit 31. -/
theorem arm64_ext_rev_extr_w32_example :
    arm64ExtrevExtrSpec 0x11223344 0x55667788 4 32 = 0x45566778 := by
  native_decide

/-- Canonical example: a 64-bit REV reverses all eight bytes. -/
theorem arm64_ext_rev_rev_w64_example :
    arm64ExtrevRev64Spec 0x0102030405060708 = 0x0807060504030201 := by
  native_decide

/-- Canonical example: a 32-bit REV reverses only the low four bytes. -/
theorem arm64_ext_rev_rev_w32_example :
    arm64ExtrevRev32Spec 0x11223344 = 0x44332211 := by
  native_decide

/-- Canonical example: a 64-bit REV16 swaps the bytes within each 16-bit unit
but leaves the units in place. -/
theorem arm64_ext_rev_rev16_w64_example :
    arm64ExtrevRev16W64Spec 0x0102030405060708 = 0x0201040306050807 := by
  native_decide

/-- Canonical example: a 32-bit REV16 swaps the bytes of the two low halves. -/
theorem arm64_ext_rev_rev16_w32_example :
    arm64ExtrevRev16W32Spec 0x11223344 = 0x22114433 := by
  native_decide

/-- Canonical example: SXTB propagates the sign of a set low byte. -/
theorem arm64_ext_rev_sxtb_example :
    arm64ExtrevSignExtSpec 0x80 8 = 0xffffffffffffff80 := by
  native_decide

/-- Canonical example: SXTH propagates the sign of a set low halfword. -/
theorem arm64_ext_rev_sxth_example :
    arm64ExtrevSignExtSpec 0x8000 16 = 0xffffffffffff8000 := by
  native_decide

/-- Canonical example: SXTW propagates the sign of a set low word. -/
theorem arm64_ext_rev_sxtw_example :
    arm64ExtrevSignExtSpec 0x80000000 32 = 0xffffffff80000000 := by
  native_decide

end KProgFormal
