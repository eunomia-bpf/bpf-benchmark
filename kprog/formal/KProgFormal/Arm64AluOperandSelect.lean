import KProgFormal.GeneratedArm64AluOperandSelect
import KProgFormal.GeneratedArm64AluOperand
import KProgFormal.Arm64AluOperandHandler
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64AluOperandSelect (AluOperandSelectOp immediate code)
open GeneratedArm64AluOperand (Mode)
open GeneratedArm64AluDecode (Alu)
open GeneratedArm64ModDecode (Mod)
open GeneratedArm64Width (Width)

/-- The one immediate-form operand-source opcode of the generic ALU arm (the
ALU immediate), named independently of the generated `immediate` match. -/
def arm64AluOperandSelectImmOps : List AluOperandSelectOp :=
  [.aluImm]

/-- The one register-form operand-source opcode of the generic ALU arm (the ALU
register). -/
def arm64AluOperandSelectRegOps : List AluOperandSelectOp :=
  [.aluReg]

/-- Independent statement of the operand-source selection: an opcode selects the
decoded immediate exactly when it is the immediate-form opcode. Structurally
separate from the generated match: a membership test over a named list rather
than a case per constructor. -/
def arm64AluOperandSelectSpec (op : AluOperandSelectOp) : Bool :=
  op ∈ arm64AluOperandSelectImmOps

/-- The generated operand-source selection table agrees with the independent
list membership statement on both opcodes. -/
theorem arm64_alu_operand_select_refines (op : AluOperandSelectOp) :
    immediate op = arm64AluOperandSelectSpec op := by
  cases op <;> decide

/-- An opcode selects the immediate exactly when it is the immediate-form
opcode. -/
theorem arm64_alu_operand_select_immediate_iff_mem (op : AluOperandSelectOp) :
    immediate op = true ↔ op ∈ arm64AluOperandSelectImmOps := by
  cases op <;> decide

/-- No register-form opcode ever selects the immediate. -/
theorem arm64_alu_operand_select_reg_never_immediate (op : AluOperandSelectOp)
    (h : op ∈ arm64AluOperandSelectRegOps) : immediate op = false := by
  cases op <;> simp_all [arm64AluOperandSelectRegOps, immediate]

/-- The immediate and register opcode lists are disjoint: no opcode is both. -/
theorem arm64_alu_operand_select_lists_disjoint (op : AluOperandSelectOp) :
    ¬ (op ∈ arm64AluOperandSelectImmOps ∧
       op ∈ arm64AluOperandSelectRegOps) := by
  cases op <;> simp [arm64AluOperandSelectImmOps, arm64AluOperandSelectRegOps]

/-- The generated code dispatch: the two mnemonics map onto the two ARM64_OP_*
opcode numbers the C macro switches on. -/
theorem arm64_alu_operand_select_code_dispatch :
    code .aluImm = 6 ∧ code .aluReg = 7 := by
  decide

/-- Every operand-source opcode lies inside the numeric case-label range the
shared C macro addresses. -/
theorem arm64_alu_operand_select_code_in_range (op : AluOperandSelectOp) :
    code op ≤ 7 := by
  cases op <;> decide

/-- The 0/1 selector decision translated to the operand-value `Mode` of the
existing `KPROG_ARM64_ALU_RHS` contract: the immediate-form opcode selects the
decoded immediate, the register-form opcode the (modifier-rewritten) register
read. -/
def aluOperandSelectMode : AluOperandSelectOp -> Mode
  | .aluImm => .immediate
  | .aluReg => .register

/-- The mode bridge agrees with the generated selector: the mode is the immediate
form exactly when the selector returns 1. -/
theorem arm64_alu_operand_select_mode_immediate_iff (op : AluOperandSelectOp) :
    aluOperandSelectMode op = .immediate ↔ immediate op = true := by
  cases op <;> decide

/-- The selector-1 case is exactly the named immediate-form list membership: the
composed decision never disagrees with the independent statement. -/
theorem arm64_alu_operand_select_mode_immediate_iff_mem
    (op : AluOperandSelectOp) :
    aluOperandSelectMode op = .immediate ↔
      op ∈ arm64AluOperandSelectImmOps := by
  cases op <;> decide

/-- The selector's opcode-6 case is the only one that feeds the immediate mode. -/
theorem arm64_alu_operand_select_code_six_is_immediate
    (op : AluOperandSelectOp) :
    code op = 6 ↔ aluOperandSelectMode op = .immediate := by
  cases op <;> decide

/-- Composition with the existing ALU operand contract: feeding the ALU-arm
operand handler the mode the selector chooses for `op` refines the independent
ALU operand handler statement, for every opcode of the pair. -/
theorem arm64_alu_operand_select_composes (state : Arm64AluHandlerState)
    (op : AluOperandSelectOp) (aluOp : Alu) (dst : Arm64Destination)
    (lhs immediate : BitVec 64) (register : BitVec 64) (srcTag : Tag)
    (mod : Mod) (shift : BitVec 64) (width : Width) :
    generatedArm64AluOperandHandler state (aluOperandSelectMode op) aluOp dst
        lhs immediate register srcTag mod shift width =
      arm64AluOperandHandlerSpec state (aluOperandSelectMode op) aluOp dst
        lhs immediate register srcTag mod shift width :=
  arm64_alu_operand_handler_refines state _ _ _ _ _ _ _ _ _ _

/-- Canonical example: the immediate-form opcode selects the immediate. -/
theorem arm64_alu_operand_select_imm_example :
    arm64AluOperandSelectSpec .aluImm = true := by
  decide

/-- Canonical example: the register-form opcode selects the register expression. -/
theorem arm64_alu_operand_select_reg_example :
    arm64AluOperandSelectSpec .aluReg = false := by
  decide

/-- Canonical example: the register-form opcode bypasses the immediate and applies
the source modifier (SXTB of 0x80), while the immediate-form opcode takes the
immediate unchanged. -/
theorem arm64_alu_operand_select_examples :
    GeneratedArm64AluOperand.rhs (aluOperandSelectMode .aluImm) 5 .sxtb 0x80 0
        .w64 = 5 ∧
    GeneratedArm64AluOperand.rhs (aluOperandSelectMode .aluReg) 5 .sxtb 0x80 0
        .w64 = 0xffffffffffffff80 := by
  native_decide

end KProgFormal
