import KProgFormal.GeneratedArm64Unary
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Unary (Unary value)
open GeneratedArm64Width (Width narrow)

/-- Independent statement of the two AArch64 unary values at a concrete width.
The two arms are stated through named identities that are structurally separate
from the generated forms: MVN as an exclusive-or with the all-ones word (not
the complement operator), and NEG as the invert-and-add-one two's-complement
identity (not a subtraction from zero). -/
def arm64UnarySpec (op : Unary) (src : BitVec 64) (width : Width) : BitVec 64 :=
  match op with
  | .mvn => narrow (src ^^^ 0xffffffffffffffff) width
  | .neg => narrow (~~~src + 1) width

/-- The generated unary contract agrees with the independent statement over both
operations and all four destination widths. -/
theorem arm64_unary_refines (op : Unary) (src : BitVec 64) (width : Width) :
    value op src width = arm64UnarySpec op src width := by
  cases op <;> cases width <;>
    simp only [value, arm64UnarySpec, narrow, GeneratedArm64Width.mask] <;>
    bv_decide

/-- Both unary opcodes are inside the numeric case-label range `15..16` used by
the shared C macro. -/
theorem arm64_unary_code_in_range (op : Unary) :
    15 ≤ GeneratedArm64Unary.code op ∧
      GeneratedArm64Unary.code op ≤ 16 := by
  cases op <;> decide

/-- The generated code dispatch: the two mnemonics map onto the two ARM64_OP_*
opcode numbers the C macro switches on. -/
theorem arm64_unary_code_dispatch :
    GeneratedArm64Unary.code .mvn = 15 ∧
    GeneratedArm64Unary.code .neg = 16 := by
  decide

/-- Every unary op leaves NZCV untouched, so the C macro's flag state threads
through unchanged. -/
theorem arm64_unary_flags_unchanged (op : Unary) :
    GeneratedArm64Unary.flagsUnchanged op = true := by
  cases op <;> rfl

/-- MVN is its own inverse at doubleword width: complementing twice restores the
source. -/
theorem arm64_unary_mvn_self_inverse (src : BitVec 64) :
    arm64UnarySpec .mvn (arm64UnarySpec .mvn src .w64) .w64 = src := by
  simp only [arm64UnarySpec, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- The negation identity at doubleword width: a NEG result added to its source
wraps to zero. -/
theorem arm64_unary_neg_add_cancel (src : BitVec 64) :
    src + arm64UnarySpec .neg src .w64 = 0 := by
  simp only [arm64UnarySpec, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- A word-width result carries no bits above bit 31, for either operation. -/
theorem arm64_unary_w32_bound (op : Unary) (src : BitVec 64) :
    value op src .w32 >>> 32 = 0 := by
  cases op <;>
    simp only [value, narrow, GeneratedArm64Width.mask] <;>
    bv_decide

/-- A byte-width MVN result fits in the low byte. -/
theorem arm64_unary_mvn_w8_bound (src : BitVec 64) :
    value .mvn src .w8 >>> 8 = 0 := by
  simp only [value, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- Canonical example: MVN of zero is the all-ones word. -/
theorem arm64_unary_mvn_zero_example :
    arm64UnarySpec .mvn 0 .w64 = 0xffffffffffffffff := by
  native_decide

/-- Canonical example: NEG of one is the all-ones word. -/
theorem arm64_unary_neg_one_example :
    arm64UnarySpec .neg 1 .w64 = 0xffffffffffffffff := by
  native_decide

/-- Canonical example: NEG of zero is zero. -/
theorem arm64_unary_neg_zero_example :
    arm64UnarySpec .neg 0 .w64 = 0 := by
  native_decide

/-- Canonical example: a word-width NEG truncates to 32 bits rather than
producing the full 64-bit negation. -/
theorem arm64_unary_neg_w32_example :
    arm64UnarySpec .neg 1 .w32 = 0xffffffff := by
  native_decide

/-- Canonical example: a byte-width MVN keeps only the low byte. -/
theorem arm64_unary_mvn_w8_example :
    arm64UnarySpec .mvn 0 .w8 = 0xff := by
  native_decide

end KProgFormal
