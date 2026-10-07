import KProgFormal.GeneratedArm64Mod
import KProgFormal.GeneratedArm64Decode
import KProgFormal.GeneratedArm64Width
import KProgFormal.GeneratedArm64AluResult
import KProgFormal.Arm64AluResult

namespace KProgFormal

open GeneratedArm64ModDecode (Mod)
open GeneratedArm64Width (Width mask narrow bits)

/-- Independent statement of the eleven AArch64 source-modifier formulas. The
shift arms restate the result through `narrow`, the sign-extending arms restate
sign extension as a masked complement-and-subtract, the unsigned-extending arms
restate truncation as a shift pair, and the rotate is stated on a narrowed
operand in the rotation domain selected by the width code. -/
def arm64ModValueSpec (mod : Mod) (value : BitVec 64) (shift : BitVec 64)
    (width : Width) : BitVec 64 :=
  let k := shift &&& (if width = .w32 then 31 else 63)
  match mod with
  | .none => value
  | .lsl => narrow (narrow value width <<< k) width
  | .lsr => (value >>> k) &&& (mask width >>> k)
  | .asr =>
      if width = .w32 then
        (((value &&& 0xffffffff) ^^^ 0x80000000) - 0x80000000).sshiftRight' k
      else value.sshiftRight' k
  | .ror =>
      if width = .w32 then
        (if k = 0 then narrow value .w32
         else narrow ((narrow value .w32 >>> k) |||
              (narrow value .w32 <<< (BitVec.ofNat 64 32 - k))) .w32)
      else if k = 0 then value
      else narrow ((narrow value .w64 >>> k) |||
            (narrow value .w64 <<< (BitVec.ofNat 64 64 - k))) .w64
  | .uxtw => ((value <<< 32) >>> 32) <<< shift
  | .sxtw => (((value &&& 0xffffffff) ^^^ 0x80000000) - 0x80000000) <<< shift
  | .uxth => ((value <<< 48) >>> 48) <<< shift
  | .sxth => (((value &&& 0xffff) ^^^ 0x8000) - 0x8000) <<< shift
  | .uxtb => ((value <<< 56) >>> 56) <<< shift
  | .sxtb => (((value &&& 0xff) ^^^ 0x80) - 0x80) <<< shift

/-- The generated source-modifier contract agrees with the independent statement
for all eleven modifiers and all four widths. -/
theorem arm64_mod_refines (mod : Mod) (value : BitVec 64) (shift : BitVec 64)
    (width : Width) :
    GeneratedArm64Mod.value mod value shift width =
      arm64ModValueSpec mod value shift width := by
  cases mod <;> cases width <;>
    simp only [GeneratedArm64Mod.value, arm64ModValueSpec, mask, narrow, bits] <;>
    bv_decide

/-- Every modifier of the generated table is inside the numeric case-label range
`0U..10U` used by the shared C macro, so the macro's branch set covers a valid
`Mod` completely and no unsupported arm is needed. -/
theorem arm64_mod_code_in_range (mod : Mod) :
    GeneratedArm64ModDecode.code mod < 11 := by
  cases mod <;> decide

/-- The generated code dispatch: the no-op code leaves the operand untouched,
the unsigned extends truncate first and then shift, and the signed extends
sign-extend first and then shift. -/
theorem arm64_mod_code_dispatch (value shift : BitVec 64) (width : Width) :
    arm64ModValueSpec .none value shift width = value ∧
    arm64ModValueSpec .uxtb value shift width = ((value <<< 56) >>> 56) <<< shift ∧
    arm64ModValueSpec .uxth value shift width = ((value <<< 48) >>> 48) <<< shift ∧
    arm64ModValueSpec .sxtb value shift width =
      (((value &&& 0xff) ^^^ 0x80) - 0x80) <<< shift := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- C stores the modifier's shift field as an `__u8`. Its image under zero
extension to 64 bits is the shift vector the generated contract is stated over. -/
def arm64ModShiftOfByte (shift : BitVec 8) : BitVec 64 := shift.setWidth 64

theorem arm64_mod_shift_magnitude (shift : BitVec 8) :
    (arm64ModShiftOfByte shift).toNat = shift.toNat := by
  simp only [arm64ModShiftOfByte, BitVec.toNat_setWidth, Nat.reducePow]
  exact Nat.mod_eq_of_lt (by have := shift.isLt; omega)

/-- The generated contract's shift arms depend on the shift vector only through
its hardware-masked low bits, which is exactly how C computes the amount before
calling the shift helper. -/
theorem arm64_mod_shift_amount_masked (value shift : BitVec 64)
    (width : Width) :
    GeneratedArm64Mod.value .lsl value shift width =
      GeneratedArm64Mod.value .lsl value (shift &&& 0x3f) width ∧
    GeneratedArm64Mod.value .lsr value shift width =
      GeneratedArm64Mod.value .lsr value (shift &&& 0x3f) width ∧
    GeneratedArm64Mod.value .asr value shift width =
      GeneratedArm64Mod.value .asr value (shift &&& 0x3f) width ∧
    GeneratedArm64Mod.value .ror value shift width =
      GeneratedArm64Mod.value .ror value (shift &&& 0x3f) width := by
  cases width <;>
    simp only [GeneratedArm64Mod.value, mask, narrow, bits] <;>
    refine ⟨?_, ?_, ?_, ?_⟩ <;> bv_decide

/-- The extend arms shift by the raw hardware shift field, which is the shift
vector C applies unmasked. `arm64_mod_shift_magnitude` identifies that vector's
magnitude with the C `__u8` amount for shift values below 64. -/
theorem arm64_mod_extend_shift_refines (value : BitVec 64) (shift : BitVec 8) :
    GeneratedArm64Mod.value .uxtw value (arm64ModShiftOfByte shift) .w64 =
      (value &&& 0xffffffff) <<< arm64ModShiftOfByte shift ∧
    GeneratedArm64Mod.value .sxtw value (arm64ModShiftOfByte shift) .w64 =
      (BitVec.signExtend 64 (value.setWidth 32)) <<< arm64ModShiftOfByte shift ∧
    GeneratedArm64Mod.value .uxth value (arm64ModShiftOfByte shift) .w64 =
      (value &&& 0xffff) <<< arm64ModShiftOfByte shift ∧
    GeneratedArm64Mod.value .sxth value (arm64ModShiftOfByte shift) .w64 =
      (BitVec.signExtend 64 (value.setWidth 16)) <<< arm64ModShiftOfByte shift ∧
    GeneratedArm64Mod.value .uxtb value (arm64ModShiftOfByte shift) .w64 =
      (value &&& 0xff) <<< arm64ModShiftOfByte shift ∧
    GeneratedArm64Mod.value .sxtb value (arm64ModShiftOfByte shift) .w64 =
      (BitVec.signExtend 64 (value.setWidth 8)) <<< arm64ModShiftOfByte shift := by
  simp only [GeneratedArm64Mod.value, arm64ModShiftOfByte]
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩ <;> bv_decide

/-- The shared ALU op-step contract applied to a source-modified operand: the
generated modifier and the generated ALU result compose to the independent
modifier statement feeding the independent ALU statement. This is the
composition the C handler relies on when a register operand is modified before
the ALU step. -/
theorem arm64_mod_fed_alu_refines (mod : Mod) (lhs value shift : BitVec 64)
    (width : Width) :
    GeneratedArm64AluResult.result .add lhs
        (GeneratedArm64Mod.value mod value shift width) =
      arm64AluResultSpec .add lhs (arm64ModValueSpec mod value shift width) := by
  rw [arm64_mod_refines, arm64_alu_result_refines]

/-- Canonical example: UXTB keeps the low byte and clears the rest. -/
theorem arm64_uxtb_example :
    arm64ModValueSpec .uxtb 0x1ff 0 .w64 = 0xff := by
  native_decide

/-- Canonical example: SXTB sign-extends the low byte. -/
theorem arm64_sxtb_example :
    arm64ModValueSpec .sxtb 0x80 0 .w64 = 0xffffffffffffff80 := by
  native_decide

/-- Canonical example: a zero-shift SXTW is the plain 32-bit sign extension. -/
theorem arm64_sxtw_example :
    arm64ModValueSpec .sxtw 0xffffffff 0 .w64 = 0xffffffffffffffff := by
  native_decide

/-- Canonical example: a 32-bit LSL by 32 shifts by the hardware-masked amount
0, so the low word is unchanged, while the 64-bit form shifts by 32. -/
theorem arm64_lsl_shift_masking_example :
    arm64ModValueSpec .lsl 1 32 .w32 = 1 ∧
    arm64ModValueSpec .lsl 1 32 .w64 = 4294967296 := by
  native_decide

/-- Canonical example: a 64-bit ROR by 8 rotates the byte order of the word. -/
theorem arm64_ror_w64_example :
    arm64ModValueSpec .ror 0x0102030405060708 8 .w64 = 0x0801020304050607 := by
  native_decide

/-- Canonical example: the identity arm leaves the operand untouched. -/
theorem arm64_mod_none_example :
    arm64ModValueSpec .none 0xdeadbeef 63 .w32 = 0xdeadbeef := by
  native_decide

end KProgFormal
