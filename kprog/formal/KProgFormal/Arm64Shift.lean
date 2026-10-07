import KProgFormal.GeneratedArm64Shift
import KProgFormal.GeneratedArm64Decode
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64ShiftDecode (Shift)
open GeneratedArm64Width (Width mask narrow bits)

/-- Independent statement of the four AArch64 shifts the simulator's
`ARM64_OP_SHIFT_IMM`/`ARM64_OP_SHIFT_REG` handler applies. `k` is the
hardware-masked amount. The arms are stated structurally differently from the
generated ones: LSL masks the operand before shifting (the mask commutes out),
LSR masks the shifted operand by the shifted mask, ASR sign-corrects the operand
before an arithmetic shift, and ROR is stated as a left-complement rotation on
the narrowed operand. -/
def arm64ShiftValueSpec (kind : Shift) (value amount : BitVec 64)
    (width : Width) : BitVec 64 :=
  let k := amount &&& (if width = .w32 then 31 else 63)
  match kind with
  | .lsl => ((value &&& mask width) <<< k) &&& mask width
  | .lsr => (value >>> k) &&& (mask width >>> k)
  | .asr =>
      if width = .w32 then
        (((value &&& mask .w32) ^^^ 0x80000000) - 0x80000000).sshiftRight'
          (k &&& 31)
      else
        (((value &&& mask .w64) ^^^ 0x8000000000000000) - 0x8000000000000000).sshiftRight'
          (k &&& 63)
  | .ror =>
      if width = .w32 then
        (let u := value.setWidth 32
         let j := (amount &&& 31).setWidth 32
         if j = 0 then BitVec.setWidth 64 u
         else BitVec.setWidth 64
           ((u <<< (BitVec.ofNat 32 32 - j)) ||| (u >>> j)))
      else
        (let j := amount &&& 63
         if j = 0 then value
         else (value <<< (64 - j)) ||| (value >>> j))

/-- The generated shift contract agrees with the independent statement for all
four shift kinds and both possible destination widths (the handler only emits
32- and 64-bit shifts). -/
theorem arm64_shift_refines (kind : Shift) (value amount : BitVec 64)
    (width : Width) :
    GeneratedArm64Shift.value kind value amount width =
      arm64ShiftValueSpec kind value amount width := by
  cases kind <;> cases width <;>
    simp only [GeneratedArm64Shift.value, arm64ShiftValueSpec, mask,
      narrow, reduceCtorEq, reduceIte] <;>
    bv_decide

/-- The shift contract does not depend on the amount's high bits: the handler
masks the amount to the width's bit count, so only the low bits matter. -/
theorem arm64_shift_amount_masked (kind : Shift) (value amount : BitVec 64)
    (width : Width) :
    GeneratedArm64Shift.value kind value amount width =
      GeneratedArm64Shift.value kind value
        (amount &&& (if width = .w32 then 31 else 63)) width := by
  cases kind <;> cases width <;>
    simp only [GeneratedArm64Shift.value, mask, narrow, reduceCtorEq,
      reduceIte] <;>
    bv_decide

/-- Every shift kind of the generated table maps onto a numeric code in
`0..3`, so the C macro's `switch` covers the complete `Shift`. -/
theorem arm64_shift_code_in_range (kind : Shift) :
    GeneratedArm64Shift.code kind < 4 := by
  cases kind <;> decide

/-- The generated code dispatch: the four shift kinds carry the decode table's
codes and the four mnemonics. -/
theorem arm64_shift_code_dispatch :
    GeneratedArm64Shift.code .lsl = GeneratedArm64ShiftDecode.code .lsl ∧
    GeneratedArm64Shift.code .lsr = GeneratedArm64ShiftDecode.code .lsr ∧
    GeneratedArm64Shift.code .asr = GeneratedArm64ShiftDecode.code .asr ∧
    GeneratedArm64Shift.code .ror = GeneratedArm64ShiftDecode.code .ror ∧
    GeneratedArm64Shift.mnemonic .lsl = "LSL" ∧
    GeneratedArm64Shift.mnemonic .lsr = "LSR" ∧
    GeneratedArm64Shift.mnemonic .asr = "ASR" ∧
    GeneratedArm64Shift.mnemonic .ror = "ROR" := by
  refine ⟨rfl, rfl, rfl, rfl, rfl, rfl, rfl, rfl⟩

/-- Canonical example: a 64-bit LSL by 4. -/
theorem arm64_shift_lsl_example :
    arm64ShiftValueSpec .lsl 1 4 .w64 = 16 := by
  native_decide

/-- Canonical example: a 32-bit LSR masks the operand to the word first. -/
theorem arm64_shift_lsr_w32_example :
    arm64ShiftValueSpec .lsr 0x1_0000_0000 4 .w32 = 0 := by
  native_decide

/-- Canonical example: a 32-bit ASR of a negative word sign-extends. -/
theorem arm64_shift_asr_w32_example :
    arm64ShiftValueSpec .asr 0x80000000 4 .w32 = 0xfffffffff8000000 := by
  native_decide

/-- Canonical example: a 64-bit ROR by 8 rotates the byte order. -/
theorem arm64_shift_ror_w64_example :
    arm64ShiftValueSpec .ror 0x0102030405060708 8 .w64 =
      0x0801020304050607 := by
  native_decide

/-- Canonical example: the 32-bit amount is hardware-masked to 5 bits, so a
32-bit LSL by 36 shifts by 4. -/
theorem arm64_shift_w32_amount_masked_example :
    arm64ShiftValueSpec .lsl 3 36 .w32 = 48 := by
  native_decide

/-- Canonical example: a 64-bit ASR of the most negative value saturates. -/
theorem arm64_shift_asr_w64_example :
    arm64ShiftValueSpec .asr 0x8000000000000000 4 .w64 =
      0xf800000000000000 := by
  native_decide

end KProgFormal
