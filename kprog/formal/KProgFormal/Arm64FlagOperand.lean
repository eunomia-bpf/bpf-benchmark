import KProgFormal.GeneratedArm64FlagOperand
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64FlagOperand (FlagOp immediate code)

/-- The six immediate-form flag opcodes, named independently of the generated
`immediate` match. -/
def arm64FlagImmOps : List FlagOp :=
  [.subsImm, .addsImm, .cmpImm, .tstImm, .andsImm, .ccmpImm]

/-- The six register-form flag opcodes. -/
def arm64FlagRegOps : List FlagOp :=
  [.subsReg, .addsReg, .cmpReg, .tstReg, .andsReg, .ccmpReg]

/-- Independent statement of the operand-source selection: an opcode selects the
decoded immediate exactly when it is one of the six immediate-form opcodes.
Structurally separate from the generated match: a membership test over a named
list rather than a case per constructor. -/
def arm64FlagOperandSpec (op : FlagOp) : Bool :=
  op ∈ arm64FlagImmOps

/-- The generated flag-operand selection table agrees with the independent list
membership statement on all twelve opcodes. -/
theorem arm64_flag_operand_refines (op : FlagOp) :
    immediate op = arm64FlagOperandSpec op := by
  cases op <;> decide

/-- An opcode selects the immediate exactly when it is one of the six
immediate-form opcodes. -/
theorem arm64_flag_operand_immediate_iff_mem (op : FlagOp) :
    immediate op = true ↔ op ∈ arm64FlagImmOps := by
  cases op <;> decide

/-- No register-form opcode ever selects the immediate. -/
theorem arm64_flag_operand_reg_never_immediate (op : FlagOp)
    (h : op ∈ arm64FlagRegOps) : immediate op = false := by
  cases op <;> simp_all [arm64FlagRegOps, immediate]

/-- The immediate and register opcode lists are disjoint: no opcode is both. -/
theorem arm64_flag_operand_lists_disjoint (op : FlagOp) :
    ¬ (op ∈ arm64FlagImmOps ∧ op ∈ arm64FlagRegOps) := by
  cases op <;> simp [arm64FlagImmOps, arm64FlagRegOps]

/-- Each of the six families has exactly one immediate-selecting member and one
register member. -/
theorem arm64_flag_operand_pairs_exclusive :
    (immediate .subsImm = true ∧ immediate .subsReg = false) ∧
    (immediate .addsImm = true ∧ immediate .addsReg = false) ∧
    (immediate .cmpImm = true ∧ immediate .cmpReg = false) ∧
    (immediate .tstImm = true ∧ immediate .tstReg = false) ∧
    (immediate .andsImm = true ∧ immediate .andsReg = false) ∧
    (immediate .ccmpImm = true ∧ immediate .ccmpReg = false) := by
  decide

/-- The generated code dispatch: the twelve mnemonics map onto the twelve
ARM64_OP_* opcode numbers the C macro switches on. -/
theorem arm64_flag_operand_code_dispatch :
    code .subsImm = 48 ∧ code .subsReg = 50 ∧
    code .addsImm = 49 ∧ code .addsReg = 66 ∧
    code .cmpImm = 22 ∧ code .cmpReg = 23 ∧
    code .tstImm = 24 ∧ code .tstReg = 25 ∧
    code .andsImm = 55 ∧ code .andsReg = 45 ∧
    code .ccmpImm = 26 ∧ code .ccmpReg = 27 := by
  decide

/-- Every flag-arm opcode lies inside the numeric case-label range the shared C
macro addresses. -/
theorem arm64_flag_operand_code_in_range (op : FlagOp) :
    code op ≤ 66 := by
  cases op <;> decide

/-- Canonical example: the SUBS immediate form selects the immediate. -/
theorem arm64_flag_operand_subs_imm_example :
    arm64FlagOperandSpec .subsImm = true := by
  decide

/-- Canonical example: the CCMP register form selects the register expression. -/
theorem arm64_flag_operand_ccmp_reg_example :
    arm64FlagOperandSpec .ccmpReg = false := by
  decide

/-- Canonical example: a register-form opcode outside the immediate list never
selects the immediate. -/
theorem arm64_flag_operand_ands_reg_example :
    arm64FlagOperandSpec .andsReg = false := by
  decide

end KProgFormal
