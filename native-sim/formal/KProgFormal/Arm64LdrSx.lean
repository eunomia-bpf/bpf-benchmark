import KProgFormal.GeneratedArm64LdrSx
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64LdrSx (LdrSx loadWidth code mnemonic)
open GeneratedArm64Width (Width bits)

/-- Independent statement of the load width keyed on the *numeric* opcode code
rather than the constructor: the byte load reads a byte, the halfword load reads a
halfword, the word load reads a word. An out-of-family code is the doubleword
sentinel, which no arm reaches. -/
def arm64LdrSxWidthOfCode (c : Nat) : Width :=
  match c with
  | 54 => .w8
  | 57 => .w32
  | 63 => .w16
  | _ => .w64

/-- The generated LDRSB/LDRSW/LDRSH load-width contract agrees with the
independent code-keyed statement on every opcode. -/
theorem arm64_ldrsx_width_refines (op : LdrSx) :
    loadWidth op = arm64LdrSxWidthOfCode (code op) := by
  cases op <;> rfl

/-- The load width is determined by the opcode's numeric code alone: two opcodes
with the same code read the same width. -/
theorem arm64_ldrsx_width_code_determined (op₁ op₂ : LdrSx)
    (h : code op₁ = code op₂) : loadWidth op₁ = loadWidth op₂ := by
  cases op₁ <;> cases op₂ <;> simp_all [code]

/-- The three load widths are pairwise distinct, so a mislabeled load is
observable. -/
theorem arm64_ldrsx_widths_distinct :
    loadWidth .ldrSb ≠ loadWidth .ldrSw ∧
    loadWidth .ldrSb ≠ loadWidth .ldrSh ∧
    loadWidth .ldrSw ≠ loadWidth .ldrSh := by
  decide

/-- The load width's bit count equals the number of bytes the opcode must read:
one for LDRSB, two for LDRSH, four for LDRSW. -/
theorem arm64_ldrsx_bytes_match (op : LdrSx) :
    bits (loadWidth op) = 8 * (match op with
      | .ldrSb => 1
      | .ldrSh => 2
      | .ldrSw => 4) := by
  cases op <;> decide

/-- Every sign-extending load reads strictly fewer than 64 bits, so the shared
sign-extension step is always load-bearing. -/
theorem arm64_ldrsx_width_lt_64 (op : LdrSx) :
    bits (loadWidth op) < 64 := by
  cases op <;> decide

/-- The three opcodes are pinned to their numeric case-label codes. -/
theorem arm64_ldrsx_code_dispatch :
    code .ldrSb = 54 ∧ code .ldrSw = 57 ∧ code .ldrSh = 63 := by
  decide

/-- The LDRSB opcode lies inside the numeric case-label range used by the shared
C macro. -/
theorem arm64_ldrsx_sb_code_in_range :
    54 ≤ code .ldrSb ∧ code .ldrSb ≤ 63 := by
  decide

/-- The LDRSW opcode lies inside the numeric case-label range used by the shared
C macro. -/
theorem arm64_ldrsx_sw_code_in_range :
    54 ≤ code .ldrSw ∧ code .ldrSw ≤ 63 := by
  decide

/-- The LDRSH opcode lies inside the numeric case-label range used by the shared
C macro. -/
theorem arm64_ldrsx_sh_code_in_range :
    54 ≤ code .ldrSh ∧ code .ldrSh ≤ 63 := by
  decide

/-- The sign-extending loads write no NZCV. -/
theorem arm64_ldrsx_flags_unchanged (op : LdrSx) :
    GeneratedArm64LdrSx.flagsUnchanged op = true := by
  cases op <;> rfl

/-- Canonical example: the byte load reads a byte. -/
theorem arm64_ldrsx_sb_example :
    arm64LdrSxWidthOfCode 54 = .w8 := by
  decide

/-- Canonical example: the word load reads a word. -/
theorem arm64_ldrsx_sw_example :
    arm64LdrSxWidthOfCode 57 = .w32 := by
  decide

end KProgFormal
