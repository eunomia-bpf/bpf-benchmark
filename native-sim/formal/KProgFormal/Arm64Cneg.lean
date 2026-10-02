import KProgFormal.GeneratedArm64Cneg
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Cneg (Cneg value)
open GeneratedArm64Width (Width narrow)

/-- Independent statement of the AArch64 condition-gated negation at a concrete
width. On a taken condition the source is negated through the
invert-and-add-one two's-complement identity (not the subtraction operator);
otherwise the source passes through unchanged. -/
def arm64CnegSpec (op : Cneg) (taken : Bool) (src : BitVec 64)
    (width : Width) : BitVec 64 :=
  match op with
  | .cneg => narrow (if taken then ~~~src + 1 else src) width

/-- The generated CNEG contract agrees with the independent statement over both
condition outcomes and all four destination widths. -/
theorem arm64_cneg_refines (op : Cneg) (taken : Bool) (src : BitVec 64)
    (width : Width) :
    value op taken src width = arm64CnegSpec op taken src width := by
  cases op <;> cases taken <;> cases width <;>
    simp only [value, arm64CnegSpec, narrow, GeneratedArm64Width.mask] <;>
    bv_decide

/-- The CNEG opcode lies inside the numeric case-label range used by the shared
C macro. -/
theorem arm64_cneg_code_in_range (op : Cneg) :
    65 ≤ GeneratedArm64Cneg.code op ∧
      GeneratedArm64Cneg.code op ≤ 65 := by
  cases op <;> decide

/-- The generated code dispatch maps the CNEG mnemonic onto the ARM64_OP_CNEG
opcode number the C macro switches on. -/
theorem arm64_cneg_code_dispatch :
    GeneratedArm64Cneg.code .cneg = 65 := by
  decide

/-- The CNEG handler leaves NZCV untouched, so the C macro's flag state threads
through unchanged. -/
theorem arm64_cneg_flags_unchanged (op : Cneg) :
    GeneratedArm64Cneg.flagsUnchanged op = true := by
  cases op <;> rfl

/-- On a taken condition the negation cancels its source at doubleword width. -/
theorem arm64_cneg_taken_cancel (src : BitVec 64) :
    src + arm64CnegSpec .cneg true src .w64 = 0 := by
  simp only [arm64CnegSpec, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- On an untaken condition the source passes through unchanged at doubleword
width. -/
theorem arm64_cneg_untaken_identity (src : BitVec 64) :
    arm64CnegSpec .cneg false src .w64 = src := by
  simp only [arm64CnegSpec, narrow, GeneratedArm64Width.mask]
  bv_decide

/-- A word-width result carries no bits above bit 31, for either condition
outcome. -/
theorem arm64_cneg_w32_bound (taken : Bool) (src : BitVec 64) :
    value .cneg taken src .w32 >>> 32 = 0 := by
  cases taken <;>
    simp only [value, narrow, GeneratedArm64Width.mask] <;>
    bv_decide

/-- Canonical example: CNEG of one on a taken condition is the all-ones word. -/
theorem arm64_cneg_taken_one_example :
    arm64CnegSpec .cneg true 1 .w64 = 0xffffffffffffffff := by
  native_decide

/-- Canonical example: CNEG of one on an untaken condition is one. -/
theorem arm64_cneg_untaken_one_example :
    arm64CnegSpec .cneg false 1 .w64 = 1 := by
  native_decide

/-- Canonical example: a word-width taken CNEG truncates to 32 bits. -/
theorem arm64_cneg_taken_w32_example :
    arm64CnegSpec .cneg true 1 .w32 = 0xffffffff := by
  native_decide

/-- Canonical example: a word-width untaken CNEG keeps only the low 32 bits of
the source. -/
theorem arm64_cneg_untaken_w32_example :
    arm64CnegSpec .cneg false 0x1_0000_0001 .w32 = 1 := by
  native_decide

end KProgFormal
