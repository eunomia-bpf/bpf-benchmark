import KProgFormal.GeneratedArm64FlagHandler
import KProgFormal.Arm64AluHandler
import KProgFormal.Arm64Flags

namespace KProgFormal

open GeneratedArm64FlagHandler (Family Mode)
open GeneratedArm64Width (Width)

/-- The register/SP state and NZCV state touched by ADDS/SUBS. CMP/CMN touch
only `flags`; their operand register has already been selected when this model
begins. -/
structure Arm64FlagHandlerState where
  regs : Arm64AluHandlerState
  flags : GeneratedArm64Flags.Flags
  deriving DecidableEq, Repr

/-- Independent ADD/SUB step statement used by both writeback and comparison
handlers. -/
def arm64FlagStepSpec (family : Family) (lhs rhs : BitVec 64)
    (width : Width) : GeneratedArm64FlagHandler.Step :=
  match family with
  | .add =>
      { value := arm64AluResultSpec .add lhs rhs,
        flags := { n := (arm64AddNzc lhs rhs width).n,
                   z := (arm64AddNzc lhs rhs width).z,
                   c := (arm64AddNzc lhs rhs width).c,
                   v := (arm64AddNzc lhs rhs width).v } }
  | .sub =>
      { value := arm64AluResultSpec .sub lhs rhs,
        flags := { n := (arm64SubNzc lhs rhs width).n,
                   z := (arm64SubNzc lhs rhs width).z,
                   c := (arm64SubNzc lhs rhs width).c,
                   v := (arm64SubNzc lhs rhs width).v } }

theorem arm64_flag_step_refines (family : Family) (lhs rhs : BitVec 64)
    (width : Width) :
    GeneratedArm64FlagHandler.apply family lhs rhs width =
      arm64FlagStepSpec family lhs rhs width := by
  cases family <;>
    simp only [GeneratedArm64FlagHandler.apply,
      GeneratedArm64FlagHandler.result, GeneratedArm64FlagHandler.flags,
      arm64FlagStepSpec]
  · rw [arm64_alu_result_refines, arm64_add_flags_refines]
  · rw [arm64_alu_result_refines, arm64_sub_flags_refines]

/-- Generated handler composition after typed operands are supplied. In
writeback mode (ADDS/SUBS), result and flags come from one shared step and the
destination write scalarizes. In compare mode (CMN/CMP), register/SP state is
preserved and only NZCV is replaced. -/
def generatedArm64FlagHandler (state : Arm64FlagHandlerState)
    (mode : Mode) (family : Family) (dst : Arm64Destination)
    (lhs rhs : BitVec 64) (width : Width) : Arm64FlagHandlerState :=
  let step := GeneratedArm64FlagHandler.apply family lhs rhs width
  let regs := match mode with
    | .writeback => generatedArm64ScalarWrite state.regs dst step.value width
    | .compare => state.regs
  { regs := regs, flags := step.flags }

def arm64FlagHandlerSpec (state : Arm64FlagHandlerState)
    (mode : Mode) (family : Family) (dst : Arm64Destination)
    (lhs rhs : BitVec 64) (width : Width) : Arm64FlagHandlerState :=
  let step := arm64FlagStepSpec family lhs rhs width
  let regs := match mode with
    | .writeback => arm64ScalarWriteSpec state.regs dst step.value width
    | .compare => state.regs
  { regs := regs, flags := step.flags }

theorem arm64_flag_handler_refines (state : Arm64FlagHandlerState)
    (mode : Mode) (family : Family) (dst : Arm64Destination)
    (lhs rhs : BitVec 64) (width : Width) :
    generatedArm64FlagHandler state mode family dst lhs rhs width =
      arm64FlagHandlerSpec state mode family dst lhs rhs width := by
  cases mode <;> simp only [generatedArm64FlagHandler, arm64FlagHandlerSpec]
  · rw [arm64_flag_step_refines, arm64_scalar_write_refines]
  · rw [arm64_flag_step_refines]

theorem arm64_adds_w32_overflow_writeback :
    generatedArm64FlagHandler
      { regs := { dst := { bits := 0x55, tag := .packet }, sp := 0x80 },
        flags := { n := false, z := true, c := true, v := false } }
      .writeback .add .gpr 0x7fffffff 1 .w32 =
      { regs := { dst := { bits := 0x80000000, tag := .scalar }, sp := 0x80 },
        flags := { n := true, z := false, c := false, v := true } } := by
  native_decide

theorem arm64_subs_xzr_discards_result_but_sets_flags :
    generatedArm64FlagHandler
      { regs := { dst := { bits := 0x55, tag := .packet }, sp := 0x80 },
        flags := { n := false, z := true, c := true, v := true } }
      .writeback .sub .zero 1 2 .w64 =
      { regs := { dst := { bits := 0x55, tag := .packet }, sp := 0x80 },
        flags := { n := true, z := false, c := false, v := false } } := by
  native_decide

theorem arm64_cmp_preserves_register_and_sp_state :
    (generatedArm64FlagHandler
      { regs := { dst := { bits := 0xfeed, tag := .mapValue }, sp := 0x80 },
        flags := { n := true, z := false, c := false, v := true } }
      .compare .sub .gpr 7 7 .w64).regs =
      { dst := { bits := 0xfeed, tag := .mapValue }, sp := 0x80 } := by
  native_decide

theorem arm64_cmn_sets_carry_without_writeback :
    generatedArm64FlagHandler
      { regs := { dst := { bits := 0xfeed, tag := .packet }, sp := 0x80 },
        flags := { n := true, z := false, c := false, v := true } }
      .compare .add .gpr 0xffffffffffffffff 1 .w64 =
      { regs := { dst := { bits := 0xfeed, tag := .packet }, sp := 0x80 },
        flags := { n := false, z := true, c := true, v := false } } := by
  native_decide

end KProgFormal
