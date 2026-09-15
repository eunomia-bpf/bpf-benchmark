import KProgFormal.GeneratedArm64Bitfield
import KProgFormal.GeneratedArm64Decode

namespace KProgFormal

open GeneratedArm64BitfieldDecode (Bitfield)

/-- C stores the bitfield's `lsb` and `bits` fields as `__u8`. Their image under
zero extension to 64 bits is the vector the independent bitfield statement is
stated over. -/
def arm64BitfieldFieldOfByte (field : BitVec 8) : BitVec 64 := field.setWidth 64

/-- Independent statement of the AArch64 bitfield mask. The mask is the
complement of the bits held above the field width, so a field width of 64 or
more is the full mask and no zero-width guard is needed. -/
def arm64BitfieldMaskSpec (bits : BitVec 64) : BitVec 64 :=
  if (64 : BitVec 64) ≤ bits then 0xffffffffffffffff
  else ~~~((0xffffffffffffffff : BitVec 64) <<< bits)

/-- Independent statement of the five AArch64 bitfield compositions. The field
is the right-justified extraction of `src[lsb + bits .. lsb]`, stated as a shift
pair; SBFX is that pair's arithmetic shift right; UBFIZ shifts the masked source
up by `lsb`; BFXIL splices the field into the complement-held destination half;
and BFI splices the field into the destination at `lsb`. -/
def arm64BitfieldValueSpec (kind : Bitfield) (src dst lsb bits : BitVec 64) :
    BitVec 64 :=
  let m := arm64BitfieldMaskSpec bits
  let field := (src <<< ((64 : BitVec 64) - lsb - bits)) >>>
    ((64 : BitVec 64) - bits)
  match kind with
  | .ubfx => field
  | .sbfx =>
      (src <<< ((64 : BitVec 64) - lsb - bits)).sshiftRight'
        ((64 : BitVec 64) - bits)
  | .ubfiz => (src &&& m) <<< lsb
  | .bfxil => (dst &&& ~~~m) ||| field
  | .bfi => (dst &&& ~~~(m <<< lsb)) ||| ((src &&& m) <<< lsb)

set_option maxHeartbeats 4000000 in
/-- The generated bitfield contract agrees with the independent statement for
all five kinds over the architectural domain: a field of one to 64 bits that
starts inside the 64-bit register. The contract is stated over the zero-extended
field bytes, which is how the independent statement reads C's `__u8` operands. -/
theorem arm64_bitfield_refines (kind : Bitfield) (src dst : BitVec 64)
    (lsb bits : BitVec 8) (hb : (1 : BitVec 8) ≤ bits)
    (h64 : bits ≤ (64 : BitVec 8))
    (hlsb : lsb ≤ (64 : BitVec 8) - bits) :
    GeneratedArm64Bitfield.value kind src dst lsb bits =
      arm64BitfieldValueSpec kind src dst (arm64BitfieldFieldOfByte lsb)
        (arm64BitfieldFieldOfByte bits) := by
  cases kind <;>
    simp only [GeneratedArm64Bitfield.value, arm64BitfieldValueSpec,
      GeneratedArm64Bitfield.mask, GeneratedArm64Bitfield.signExtend,
      arm64BitfieldMaskSpec, arm64BitfieldFieldOfByte] <;>
    bv_decide

/-- The generated mask agrees with the independent complement-form mask. -/
theorem arm64_bitfield_mask_refines (bits : BitVec 8)
    (hb : (1 : BitVec 8) ≤ bits) :
    GeneratedArm64Bitfield.mask bits =
      arm64BitfieldMaskSpec (arm64BitfieldFieldOfByte bits) := by
  simp only [GeneratedArm64Bitfield.mask, arm64BitfieldMaskSpec,
    arm64BitfieldFieldOfByte]
  split <;> bv_decide

/-- Under the contract's domain the field position is below 64, so the C
handler's `lsb >= 64` guards never fire: the guarded left/right shifts and field
placement are the bare ones the generated arms use. -/
theorem arm64_bitfield_lsb_below_width (lsb bits : BitVec 8)
    (hb : (1 : BitVec 8) ≤ bits) (h64 : bits ≤ (64 : BitVec 8))
    (hlsb : lsb ≤ (64 : BitVec 8) - bits) : lsb < (64 : BitVec 8) := by
  bv_omega

/-- Every bitfield of the generated table is inside the numeric case-label range
`0U..4U` used by the shared C macro, so the macro's branch set covers a valid
`Bitfield` and only a code outside the table reaches the unsupported arm. -/
theorem arm64_bitfield_code_in_range (kind : Bitfield) :
    GeneratedArm64BitfieldDecode.code kind < 5 := by
  cases kind <;> decide

/-- The generated code dispatch: the five bitfield mnemonics map onto the five
numeric case labels in table order. -/
theorem arm64_bitfield_code_dispatch :
    GeneratedArm64BitfieldDecode.code .ubfx = 0 ∧
    GeneratedArm64BitfieldDecode.code .sbfx = 1 ∧
    GeneratedArm64BitfieldDecode.code .ubfiz = 2 ∧
    GeneratedArm64BitfieldDecode.code .bfxil = 3 ∧
    GeneratedArm64BitfieldDecode.code .bfi = 4 := by
  decide

/-- C's `__u8` field byte carries its magnitude into the 64-bit contract. -/
theorem arm64_bitfield_field_magnitude (field : BitVec 8) :
    (arm64BitfieldFieldOfByte field).toNat = field.toNat := by
  simp only [arm64BitfieldFieldOfByte, BitVec.toNat_setWidth, Nat.reducePow]
  exact Nat.mod_eq_of_lt (by have := field.isLt; omega)

/-- Canonical example: UBFX of a mid-register field extracts the 16 bits at
`lsb = 8`. -/
theorem arm64_ubfx_example :
    arm64BitfieldValueSpec .ubfx 0x0000000000abcdef01 0 8 16 = 0xcdef := by
  native_decide

/-- Canonical example: SBFX propagates the sign of a four-bit field, so the
field `1111` becomes all ones. -/
theorem arm64_sbfx_example :
    arm64BitfieldValueSpec .sbfx 0xf 0 0 4 = 0xffffffffffffffff := by
  native_decide

/-- Canonical example: UBFIZ places the masked source at the field position and
clears everything else. -/
theorem arm64_ubfiz_example :
    arm64BitfieldValueSpec .ubfiz 0xff 0 8 8 = 0xff00 := by
  native_decide

/-- Canonical example: BFXIL keeps the destination's complement half and drops
the extracted field into the low bits. -/
theorem arm64_bfxil_example :
    arm64BitfieldValueSpec .bfxil 0xaa 0xffffffffffff0000 0 8 =
      0xffffffffffff00aa := by
  native_decide

/-- Canonical example: BFI drops the masked source into a field that starts
above bit zero. -/
theorem arm64_bfi_example :
    arm64BitfieldValueSpec .bfi 0xb 0x0 4 4 = 0xb0 := by
  native_decide

/-- Canonical example: a 64-bit field consumes the whole source. -/
theorem arm64_ubfx_width64_example :
    arm64BitfieldValueSpec .ubfx 0x0123456789abcdef 0 0 64 =
      0x0123456789abcdef := by
  native_decide

end KProgFormal
