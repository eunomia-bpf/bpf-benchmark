import KProgFormal.GeneratedArm64Stlxr
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Stlxr (Stlxr value)
open GeneratedArm64Width (Width narrow mask bits)

/-- Independent statement of the STLXR exclusive-store status at a concrete
width: the success code is the destination-width mask with itself subtracted (the
exclusive-monitor success encoding, `0`), narrowed to the width. -/
def arm64StlxrSpec (op : Stlxr) (width : Width) : BitVec 64 :=
  match op with
  | .stlxr => narrow (mask width - mask width) width

/-- The generated STLXR status contract agrees with the independent
subtraction-of-the-mask statement over all four destination widths. -/
theorem arm64_stlxr_refines (op : Stlxr) (width : Width) :
    value op width = arm64StlxrSpec op width := by
  cases op <;> cases width <;>
    simp only [value, arm64StlxrSpec, narrow, mask] <;> bv_decide

/-- The exclusive-store success status is the zero code at every width. -/
theorem arm64_stlxr_success_zero (op : Stlxr) (width : Width) :
    value op width = 0 := by
  cases op <;> cases width <;>
    simp only [value, narrow, mask] <;> bv_decide

/-- The STLXR opcode lies inside the numeric case-label range used by the shared
C macro. -/
theorem arm64_stlxr_code_in_range (op : Stlxr) :
    56 ≤ GeneratedArm64Stlxr.code op ∧ GeneratedArm64Stlxr.code op ≤ 56 := by
  cases op <;> decide

/-- The generated code dispatch maps the STLXR mnemonic onto the ARM64_OP_STLXR
opcode number the C macro switches on. -/
theorem arm64_stlxr_code_dispatch :
    GeneratedArm64Stlxr.code .stlxr = 56 := by
  decide

/-- The STLXR handler leaves NZCV untouched, so the C macro's flag state threads
through unchanged. -/
theorem arm64_stlxr_flags_unchanged (op : Stlxr) :
    GeneratedArm64Stlxr.flagsUnchanged op = true := by
  cases op <;> rfl

/-- A word-width success status carries no bits above bit 31. -/
theorem arm64_stlxr_w32_bound (op : Stlxr) :
    value op .w32 >>> 32 = 0 := by
  cases op <;> simp only [value, narrow, mask] <;> bv_decide

/-- Canonical example: the success status is zero at doubleword width. -/
theorem arm64_stlxr_example :
    arm64StlxrSpec .stlxr .w64 = 0 := by
  native_decide

/-- Canonical example: the success status is zero at word width. -/
theorem arm64_stlxr_w32_example :
    arm64StlxrSpec .stlxr .w32 = 0 := by
  native_decide

end KProgFormal
