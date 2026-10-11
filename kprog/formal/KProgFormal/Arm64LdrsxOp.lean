import KProgFormal.GeneratedArm64LdrsxOp
import KProgFormal.GeneratedArm64LdrSx
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64LdrsxOp (LdrSxLoad code sxCode signBits)
open GeneratedArm64LdrSx (LdrSx loadWidth)
open GeneratedArm64Width (Width bits)

/-- Independent statement of the sign-extending-opcode selection keyed on the
*numeric* load code rather than the constructor: a byte load selects SXTB (60),
a word load selects SXTW (47), a halfword load selects SXTH (21). An
out-of-family code selects 0, which is not a sign-extend opcode. -/
def arm64LdrsxOpSxOfCode (c : Nat) : Nat :=
  match c with
  | 54 => 60
  | 57 => 47
  | 63 => 21
  | _ => 0

/-- The three sign-extending opcodes a load may select, named independently of
the generated `sxCode` match. -/
def arm64LdrsxOpSignOps : List Nat :=
  [60, 47, 21]

/-- The three load opcodes the family covers, named independently. -/
def arm64LdrsxOpLoadCodes : List Nat :=
  [54, 57, 63]

/-- Independent statement of the selection: a load selects a sign-extending
opcode exactly when its derived code is a member of the sign-opcode table.
Structurally separate from the generated match: a membership test over a named
list rather than a case per constructor. -/
def arm64LdrsxOpSpec (op : LdrSxLoad) : Bool :=
  sxCode op ∈ arm64LdrsxOpSignOps

/-- The generated sign-extending-opcode contract agrees with the independent
code-keyed statement on every load opcode. -/
theorem arm64_ldrsx_op_refines (op : LdrSxLoad) :
    sxCode op = arm64LdrsxOpSxOfCode (code op) := by
  cases op <;> rfl

/-- The derived sign-extending opcode is determined by the load opcode's numeric
code alone: two loads with the same code select the same sign opcode. -/
theorem arm64_ldrsx_op_code_determined (op₁ op₂ : LdrSxLoad)
    (h : code op₁ = code op₂) : sxCode op₁ = sxCode op₂ := by
  cases op₁ <;> cases op₂ <;> simp_all [code]

/-- Every load's derived opcode is a member of the independent sign-opcode
table, so the refines statement always selects a real sign-extend opcode. -/
theorem arm64_ldrsx_op_selects_member (op : LdrSxLoad) :
    arm64LdrsxOpSpec op = true := by
  cases op <;> decide

/-- The three load opcodes are pairwise distinct, so a mislabeled load is
observable. -/
theorem arm64_ldrsx_op_load_codes_distinct :
    code .ldrSb ≠ code .ldrSw ∧
    code .ldrSb ≠ code .ldrSh ∧
    code .ldrSw ≠ code .ldrSh := by
  decide

/-- The three derived sign-extending opcodes are pairwise distinct, so a load
that picked the wrong sign width is observable. -/
theorem arm64_ldrsx_op_sx_codes_distinct :
    sxCode .ldrSb ≠ sxCode .ldrSw ∧
    sxCode .ldrSb ≠ sxCode .ldrSh ∧
    sxCode .ldrSw ≠ sxCode .ldrSh := by
  decide

/-- No derived sign-extending opcode equals a load opcode: the family crosses no
boundary into its own opcodes. -/
theorem arm64_ldrsx_op_sx_not_load (op : LdrSxLoad) :
    sxCode op ∉ arm64LdrsxOpLoadCodes := by
  cases op <;> decide

/-- The number of bits the load sign-extends from equals the bit count of the
load width: 8 for LDRSB, 32 for LDRSW, 16 for LDRSH. This pins the derived sign
width to the well-tested load-width contract. -/
theorem arm64_ldrsx_op_signbits_match_width (op : LdrSxLoad) :
    signBits op = bits (loadWidth (match op with
      | .ldrSb => .ldrSb
      | .ldrSw => .ldrSw
      | .ldrSh => .ldrSh)) := by
  cases op <;> decide

/-- The generated code dispatch: the three load mnemonics map onto the three
ARM64_OP_LDRS* opcode numbers the C macro switches on. -/
theorem arm64_ldrsx_op_code_dispatch :
    code .ldrSb = 54 ∧ code .ldrSw = 57 ∧ code .ldrSh = 63 := by
  decide

/-- The generated sign dispatch: the loads map onto the three ARM64_OP_SX*
opcode numbers the extract/reverse/extend contract keys on. -/
theorem arm64_ldrsx_op_sx_dispatch :
    sxCode .ldrSb = 60 ∧ sxCode .ldrSw = 47 ∧ sxCode .ldrSh = 21 := by
  decide

/-- Every load opcode lies inside the numeric case-label range the shared C
macro addresses. -/
theorem arm64_ldrsx_op_code_in_range (op : LdrSxLoad) :
    54 ≤ code op ∧ code op ≤ 63 := by
  cases op <;> decide

/-- Canonical example: the byte load selects sign-extend-byte. -/
theorem arm64_ldrsx_op_ldrsb_example :
    arm64LdrsxOpSxOfCode 54 = 60 := by
  decide

/-- Canonical example: the word load selects sign-extend-word. -/
theorem arm64_ldrsx_op_ldrsw_example :
    arm64LdrsxOpSxOfCode 57 = 47 := by
  decide

/-- Canonical example: out of the load family, no sign opcode is selected. -/
theorem arm64_ldrsx_op_out_of_family_example :
    arm64LdrsxOpSxOfCode 0 = 0 := by
  decide
