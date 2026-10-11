import KProgFormal.GeneratedArm64ImmOperand
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64ImmOperand (ImmOp immediate code)

/-- The two immediate-form operand opcodes (the move immediate and the shift
immediate), named independently of the generated `immediate` match. -/
def arm64ImmOperandImmOps : List ImmOp :=
  [.movImm, .shiftImm]

/-- The two register-form operand opcodes (the move register and the shift
register). -/
def arm64ImmOperandRegOps : List ImmOp :=
  [.movReg, .shiftReg]

/-- Independent statement of the operand-source selection: an opcode selects the
decoded immediate exactly when it is one of the two immediate-form opcodes.
Structurally separate from the generated match: a membership test over a named
list rather than a case per constructor. -/
def arm64ImmOperandSpec (op : ImmOp) : Bool :=
  op ∈ arm64ImmOperandImmOps

/-- The generated operand-source selection table agrees with the independent list
membership statement on all four opcodes. -/
theorem arm64_imm_operand_refines (op : ImmOp) :
    immediate op = arm64ImmOperandSpec op := by
  cases op <;> decide

/-- An opcode selects the immediate exactly when it is one of the two
immediate-form opcodes. -/
theorem arm64_imm_operand_immediate_iff_mem (op : ImmOp) :
    immediate op = true ↔ op ∈ arm64ImmOperandImmOps := by
  cases op <;> decide

/-- No register-form opcode ever selects the immediate. -/
theorem arm64_imm_operand_reg_never_immediate (op : ImmOp)
    (h : op ∈ arm64ImmOperandRegOps) : immediate op = false := by
  cases op <;> simp_all [arm64ImmOperandRegOps, immediate]

/-- The immediate and register opcode lists are disjoint: no opcode is both. -/
theorem arm64_imm_operand_lists_disjoint (op : ImmOp) :
    ¬ (op ∈ arm64ImmOperandImmOps ∧ op ∈ arm64ImmOperandRegOps) := by
  cases op <;> simp [arm64ImmOperandImmOps, arm64ImmOperandRegOps]

/-- Each of the two selector families has exactly one immediate-selecting member
and one register member. -/
theorem arm64_imm_operand_pairs_exclusive :
    (immediate .movImm = true ∧ immediate .movReg = false) ∧
    (immediate .shiftImm = true ∧ immediate .shiftReg = false) := by
  decide

/-- The generated code dispatch: the four mnemonics map onto the four
ARM64_OP_* opcode numbers the C macro switches on. -/
theorem arm64_imm_operand_code_dispatch :
    code .movImm = 1 ∧ code .movReg = 2 ∧
    code .shiftImm = 8 ∧ code .shiftReg = 9 := by
  decide

/-- Every operand-source opcode lies inside the numeric case-label range the
shared C macro addresses. -/
theorem arm64_imm_operand_code_in_range (op : ImmOp) :
    code op ≤ 9 := by
  cases op <;> decide

/-- Canonical example: the move immediate form selects the immediate. -/
theorem arm64_imm_operand_mov_imm_example :
    arm64ImmOperandSpec .movImm = true := by
  decide

/-- Canonical example: the move register form selects the register expression. -/
theorem arm64_imm_operand_mov_reg_example :
    arm64ImmOperandSpec .movReg = false := by
  decide

/-- Canonical example: the shift immediate form selects the immediate. -/
theorem arm64_imm_operand_shift_imm_example :
    arm64ImmOperandSpec .shiftImm = true := by
  decide

/-- Canonical example: a register-form opcode outside the immediate list never
selects the immediate. -/
theorem arm64_imm_operand_shift_reg_example :
    arm64ImmOperandSpec .shiftReg = false := by
  decide

end KProgFormal
