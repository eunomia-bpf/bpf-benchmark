import KProgFormal.GeneratedArm64Orn
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Orn (Orn value)
open GeneratedArm64Width (Width narrow)

/-- Independent statement of the AArch64 complemented logical OR at a concrete
width. The arm is stated in its De Morgan complement form, the complement of the
AND of the complemented first source with the second source (rather than the OR
with a complemented operand the generated arm uses). -/
def arm64OrnSpec (op : Orn) (lhs rhs : BitVec 64) (width : Width) : BitVec 64 :=
  match op with
  | .orn_reg => narrow (~~~((~~~lhs) &&& rhs)) width

/-- The generated ORN contract agrees with the independent De Morgan statement
over all four destination widths. -/
theorem arm64_orn_refines (op : Orn) (lhs rhs : BitVec 64) (width : Width) :
    value op lhs rhs width = arm64OrnSpec op lhs rhs width := by
  cases op <;> cases width <;>
    simp only [value, arm64OrnSpec, narrow, GeneratedArm64Width.mask] <;>
    bv_decide

/-- The independent De Morgan statement equals the direct OR-with-complement
form: ORN is `lhs | ~rhs` and, dually, `~(~lhs & rhs)`. -/
theorem arm64_orn_de_morgan (lhs rhs : BitVec 64) :
    arm64OrnSpec .orn_reg lhs rhs .w64 = (lhs ||| ~~~rhs) := by
  simp only [arm64OrnSpec, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- The ORN opcode lies inside the numeric case-label range used by the shared
C macro. -/
theorem arm64_orn_code_in_range (op : Orn) :
    53 ≤ GeneratedArm64Orn.code op ∧ GeneratedArm64Orn.code op ≤ 53 := by
  cases op <;> decide

/-- The generated code dispatch maps the ORN mnemonic onto the ARM64_OP_ORN_REG
opcode number the C macro switches on. -/
theorem arm64_orn_code_dispatch :
    GeneratedArm64Orn.code .orn_reg = 53 := by
  decide

/-- The ORN handler leaves NZCV untouched, so the C macro's flag state threads
through unchanged. -/
theorem arm64_orn_flags_unchanged (op : Orn) :
    GeneratedArm64Orn.flagsUnchanged op = true := by
  cases op <;> rfl

/-- A complemented OR with a zero second source is all ones at doubleword
width, matching `~0`. -/
theorem arm64_orn_zero_rhs_all_ones (lhs : BitVec 64) :
    arm64OrnSpec .orn_reg lhs 0 .w64 = ~~~(0 : BitVec 64) := by
  simp only [arm64OrnSpec, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- A complemented OR with a zero first source is the complement of the second
source at doubleword width. -/
theorem arm64_orn_zero_lhs_complement (rhs : BitVec 64) :
    arm64OrnSpec .orn_reg 0 rhs .w64 = ~~~rhs := by
  simp only [arm64OrnSpec, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- A word-width result carries no bits above bit 31. -/
theorem arm64_orn_w32_bound (lhs rhs : BitVec 64) :
    value .orn_reg lhs rhs .w32 >>> 32 = 0 := by
  simp only [value, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- Canonical example: ORN of `0xf0` with `0x0f` sets the complemented bits of
the second source only. -/
theorem arm64_orn_example :
    arm64OrnSpec .orn_reg 0xf0 0x0f .w64 = 0xfffffffffffffff0 := by
  decide

/-- Canonical example: a word-width ORN truncates to 32 bits. -/
theorem arm64_orn_w32_example :
    arm64OrnSpec .orn_reg 0 0x1_0000_0000 .w32 = 0xffffffff := by
  decide

end KProgFormal
