import KProgFormal.GeneratedArm64AluOperand
import KProgFormal.Arm64AluHandler
import KProgFormal.Arm64Mod

namespace KProgFormal

open GeneratedArm64AluOperand (Mode)
open GeneratedArm64AluDecode (Alu)
open GeneratedArm64ModDecode (Mod)
open GeneratedArm64Width (Width)

/-- Independent RHS selection: immediate form bypasses source modification;
register form applies the independently stated modifier semantics. -/
def arm64AluRhsSpec (mode : Mode) (immediate : BitVec 64)
    (mod : Mod) (register shift : BitVec 64) (width : Width) : BitVec 64 :=
  match mode with
  | .immediate => immediate
  | .register => arm64ModValueSpec mod register shift width

theorem arm64_alu_rhs_refines (mode : Mode) (immediate : BitVec 64)
    (mod : Mod) (register shift : BitVec 64) (width : Width) :
    GeneratedArm64AluOperand.rhs mode immediate mod register shift width =
      arm64AluRhsSpec mode immediate mod register shift width := by
  cases mode
  · rfl
  · simp only [GeneratedArm64AluOperand.rhs, arm64AluRhsSpec]
    rw [arm64_mod_refines]

/-- The real generic ALU handler composition after typed register values,
destination class, source tag, opcode, modifier and width have been selected.
This closes the previous free-RHS premise for both immediate and modified
register forms without claiming parser/register-number correctness. -/
def generatedArm64AluOperandHandler (state : Arm64AluHandlerState)
    (mode : Mode) (op : Alu) (dst : Arm64Destination) (lhs immediate : BitVec 64)
    (register : BitVec 64) (srcTag : Tag) (mod : Mod)
    (shift : BitVec 64) (width : Width) : Arm64AluHandlerState :=
  let rhs := GeneratedArm64AluOperand.rhs
    mode immediate mod register shift width
  generatedArm64AluHandler state dst { bits := lhs, tag := srcTag }
    rhs width op

def arm64AluOperandHandlerSpec (state : Arm64AluHandlerState)
    (mode : Mode) (op : Alu) (dst : Arm64Destination) (lhs immediate : BitVec 64)
    (register : BitVec 64) (srcTag : Tag) (mod : Mod)
    (shift : BitVec 64) (width : Width) : Arm64AluHandlerState :=
  let rhs := arm64AluRhsSpec mode immediate mod register shift width
  arm64AluHandlerSpec state dst { bits := lhs, tag := srcTag }
    rhs width op

theorem arm64_alu_operand_handler_refines (state : Arm64AluHandlerState)
    (mode : Mode) (op : Alu) (dst : Arm64Destination) (lhs immediate : BitVec 64)
    (register : BitVec 64) (srcTag : Tag) (mod : Mod)
    (shift : BitVec 64) (width : Width) :
    generatedArm64AluOperandHandler state mode op dst lhs immediate register
        srcTag mod shift width =
      arm64AluOperandHandlerSpec state mode op dst lhs immediate register
        srcTag mod shift width := by
  simp only [generatedArm64AluOperandHandler, arm64AluOperandHandlerSpec]
  rw [arm64_alu_rhs_refines, arm64_alu_handler_refines]

theorem arm64_alu_immediate_bypasses_modifier :
    GeneratedArm64AluOperand.rhs .immediate 5 .sxtb 0x80 63 .w64 = 5 := by
  native_decide

theorem arm64_alu_register_sxtb_feeds_pointer_add :
    generatedArm64AluOperandHandler
      { dst := { bits := 0x55, tag := .scalar }, sp := 0x80 }
      .register .add .gpr 0x100 0 0xff .packet .sxtb 0 .w64 =
      { dst := { bits := 0xff, tag := .packet }, sp := 0x80 } := by
  native_decide

theorem arm64_alu_register_lsl_w32_scalarizes_and_narrows :
    generatedArm64AluOperandHandler
      { dst := { bits := 0x55, tag := .packet }, sp := 0x80 }
      .register .orr .gpr 0 0 1 .mapValue .lsl 31 .w32 =
      { dst := { bits := 0x80000000, tag := .scalar }, sp := 0x80 } := by
  native_decide

theorem arm64_alu_immediate_sp_write_uses_selected_rhs :
    generatedArm64AluOperandHandler
      { dst := { bits := 0x55, tag := .packet }, sp := 0x100 }
      .immediate .sub .sp 0x100 8 0xffff .stack .ror 17 .w64 =
      { dst := { bits := 0x55, tag := .packet }, sp := 0xf8 } := by
  native_decide

end KProgFormal
