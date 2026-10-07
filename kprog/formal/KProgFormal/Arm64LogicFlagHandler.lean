import KProgFormal.GeneratedArm64LogicFlagHandler
import KProgFormal.Arm64FlagHandler

namespace KProgFormal

open GeneratedArm64LogicFlagHandler (Family Mode)
open GeneratedArm64Width (Width)

/-- Independent AND/BIC result-plus-NZCV statement. The logical flag policy is
restated through `arm64LogicNzc`, rather than by reusing the generated handler
step. -/
def arm64LogicFlagStepSpec (family : Family) (lhs rhs : BitVec 64)
    (width : Width) : GeneratedArm64LogicFlagHandler.Step :=
  let value := match family with
    | .and => arm64AluResultSpec .and lhs rhs
    | .bic => arm64AluResultSpec .bic lhs rhs
  { value := value,
    flags := { n := (arm64LogicNzc value width).n,
               z := (arm64LogicNzc value width).z,
               c := (arm64LogicNzc value width).c,
               v := (arm64LogicNzc value width).v } }

theorem arm64_logic_flag_step_refines (family : Family)
    (lhs rhs : BitVec 64) (width : Width) :
    GeneratedArm64LogicFlagHandler.apply family lhs rhs width =
      arm64LogicFlagStepSpec family lhs rhs width := by
  cases family <;>
    simp only [GeneratedArm64LogicFlagHandler.apply,
      GeneratedArm64LogicFlagHandler.alu, arm64LogicFlagStepSpec]
  · rw [arm64_alu_result_refines, arm64_logic_flags_refines]
  · rw [arm64_alu_result_refines, arm64_logic_flags_refines]

/-- Handler state after typed operands and the width have been supplied.
ANDS/BICS use `writeback`; TST/TST-BIC use `test`, which preserves the entire
modeled register/SP state while replacing NZCV. -/
def generatedArm64LogicFlagHandler (state : Arm64FlagHandlerState)
    (mode : Mode) (family : Family) (dst : Arm64Destination)
    (lhs rhs : BitVec 64) (width : Width) : Arm64FlagHandlerState :=
  let step := GeneratedArm64LogicFlagHandler.apply family lhs rhs width
  let regs := match mode with
    | .writeback => generatedArm64ScalarWrite state.regs dst step.value width
    | .test => state.regs
  { regs := regs, flags := step.flags }

def arm64LogicFlagHandlerSpec (state : Arm64FlagHandlerState)
    (mode : Mode) (family : Family) (dst : Arm64Destination)
    (lhs rhs : BitVec 64) (width : Width) : Arm64FlagHandlerState :=
  let step := arm64LogicFlagStepSpec family lhs rhs width
  let regs := match mode with
    | .writeback => arm64ScalarWriteSpec state.regs dst step.value width
    | .test => state.regs
  { regs := regs, flags := step.flags }

theorem arm64_logic_flag_handler_refines (state : Arm64FlagHandlerState)
    (mode : Mode) (family : Family) (dst : Arm64Destination)
    (lhs rhs : BitVec 64) (width : Width) :
    generatedArm64LogicFlagHandler state mode family dst lhs rhs width =
      arm64LogicFlagHandlerSpec state mode family dst lhs rhs width := by
  cases mode <;>
    simp only [generatedArm64LogicFlagHandler, arm64LogicFlagHandlerSpec]
  · rw [arm64_logic_flag_step_refines, arm64_scalar_write_refines]
  · rw [arm64_logic_flag_step_refines]

theorem arm64_ands_w32_writes_scalar_and_sets_negative :
    generatedArm64LogicFlagHandler
      { regs := { dst := { bits := 0x55, tag := .packet }, sp := 0x80 },
        flags := { n := false, z := true, c := true, v := true } }
      .writeback .and .gpr 0xffffffff80000000 0xffffffff .w32 =
      { regs := { dst := { bits := 0x80000000, tag := .scalar }, sp := 0x80 },
        flags := { n := true, z := false, c := false, v := false } } := by
  native_decide

theorem arm64_bics_xzr_discards_result_but_sets_zero :
    generatedArm64LogicFlagHandler
      { regs := { dst := { bits := 0x55, tag := .mapValue }, sp := 0x80 },
        flags := { n := true, z := false, c := true, v := true } }
      .writeback .bic .zero 0xff 0xff .w64 =
      { regs := { dst := { bits := 0x55, tag := .mapValue }, sp := 0x80 },
        flags := { n := false, z := true, c := false, v := false } } := by
  native_decide

theorem arm64_tst_preserves_register_and_sp_state :
    (generatedArm64LogicFlagHandler
      { regs := { dst := { bits := 0xfeed, tag := .packetEnd }, sp := 0x80 },
        flags := { n := true, z := false, c := true, v := true } }
      .test .and .gpr 0xf0 0x0f .w64).regs =
      { dst := { bits := 0xfeed, tag := .packetEnd }, sp := 0x80 } := by
  native_decide

theorem arm64_tst_bic_sets_flags_without_writeback :
    generatedArm64LogicFlagHandler
      { regs := { dst := { bits := 0xfeed, tag := .stack }, sp := 0x80 },
        flags := { n := true, z := false, c := true, v := true } }
      .test .bic .gpr 0xff 0x0f .w8 =
      { regs := { dst := { bits := 0xfeed, tag := .stack }, sp := 0x80 },
        flags := { n := true, z := false, c := false, v := false } } := by
  native_decide

end KProgFormal
