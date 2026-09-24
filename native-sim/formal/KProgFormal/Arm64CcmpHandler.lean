import KProgFormal.GeneratedArm64CcmpHandler
import KProgFormal.Arm64FlagHandler
import KProgFormal.Arm64ControlFlow

namespace KProgFormal

open GeneratedArm64Width (Width)

def arm64CcmpControlFlags (flags : GeneratedArm64Flags.Flags) : Arm64Flags :=
  { n := flags.n, z := flags.z, c := flags.c, v := flags.v }

/-- Independent interpretation of the architectural fallback immediate. Bits
above NZCV[3:0] are intentionally ignored, matching the real C extraction. -/
def arm64CcmpFallbackSpec (nzcv : BitVec 8) : GeneratedArm64Flags.Flags :=
  { n := nzcv.getLsbD 3,
    z := nzcv.getLsbD 2,
    c := nzcv.getLsbD 1,
    v := nzcv.getLsbD 0 }

theorem arm64_ccmp_fallback_refines (nzcv : BitVec 8) :
    GeneratedArm64CcmpHandler.fallbackFlags nzcv =
      arm64CcmpFallbackSpec nzcv := by
  simp [GeneratedArm64CcmpHandler.fallbackFlags, arm64CcmpFallbackSpec]
  bv_decide

theorem arm64_ccmp_condition_refines (incoming : GeneratedArm64Flags.Flags)
    (cond : Arm64Cond) :
    GeneratedArm64Cond.eval incoming.n incoming.z incoming.c incoming.v cond =
      arm64CondSpec (arm64CcmpControlFlags incoming) cond := by
  change generatedArm64Cond (arm64CcmpControlFlags incoming) cond =
    arm64CondSpec (arm64CcmpControlFlags incoming) cond
  exact arm64_condition_sound (arm64CcmpControlFlags incoming) cond

/-- Independent CCMP step: if the incoming NZCV satisfies the condition,
compute SUB flags from the operands; otherwise load NZCV from the fallback
immediate. -/
def arm64CcmpStepSpec (incoming : GeneratedArm64Flags.Flags)
    (cond : Arm64Cond) (lhs rhs : BitVec 64) (width : Width)
    (fallback : BitVec 8) : GeneratedArm64CcmpHandler.Step :=
  if arm64CondSpec (arm64CcmpControlFlags incoming) cond then
    { flags := { n := (arm64SubNzc lhs rhs width).n,
                 z := (arm64SubNzc lhs rhs width).z,
                 c := (arm64SubNzc lhs rhs width).c,
                 v := (arm64SubNzc lhs rhs width).v } }
  else
    { flags := arm64CcmpFallbackSpec fallback }

theorem arm64_ccmp_step_refines (incoming : GeneratedArm64Flags.Flags)
    (cond : Arm64Cond) (lhs rhs : BitVec 64) (width : Width)
    (fallback : BitVec 8) :
    GeneratedArm64CcmpHandler.apply incoming cond lhs rhs width fallback =
      arm64CcmpStepSpec incoming cond lhs rhs width fallback := by
  simp only [GeneratedArm64CcmpHandler.apply, arm64CcmpStepSpec]
  rw [arm64_ccmp_condition_refines]
  split
  · rw [arm64_sub_flags_refines]
  · rw [arm64_ccmp_fallback_refines]

/-- CCMP never writes a GPR or SP. The state theorem composes the conditional
flag step with preservation of the complete modeled register/SP state. -/
def generatedArm64CcmpHandler (state : Arm64FlagHandlerState)
    (cond : Arm64Cond) (lhs rhs : BitVec 64) (width : Width)
    (fallback : BitVec 8) : Arm64FlagHandlerState :=
  let step := GeneratedArm64CcmpHandler.apply
    state.flags cond lhs rhs width fallback
  { regs := state.regs, flags := step.flags }

def arm64CcmpHandlerSpec (state : Arm64FlagHandlerState)
    (cond : Arm64Cond) (lhs rhs : BitVec 64) (width : Width)
    (fallback : BitVec 8) : Arm64FlagHandlerState :=
  let step := arm64CcmpStepSpec state.flags cond lhs rhs width fallback
  { regs := state.regs, flags := step.flags }

theorem arm64_ccmp_handler_refines (state : Arm64FlagHandlerState)
    (cond : Arm64Cond) (lhs rhs : BitVec 64) (width : Width)
    (fallback : BitVec 8) :
    generatedArm64CcmpHandler state cond lhs rhs width fallback =
      arm64CcmpHandlerSpec state cond lhs rhs width fallback := by
  simp only [generatedArm64CcmpHandler, arm64CcmpHandlerSpec]
  rw [arm64_ccmp_step_refines]

theorem arm64_ccmp_true_path_uses_sub_flags_and_preserves_regs :
    generatedArm64CcmpHandler
      { regs := { dst := { bits := 0xfeed, tag := .packet }, sp := 0x80 },
        flags := { n := false, z := true, c := true, v := false } }
      .eq 1 2 .w64 0x6 =
      { regs := { dst := { bits := 0xfeed, tag := .packet }, sp := 0x80 },
        flags := { n := true, z := false, c := false, v := false } } := by
  native_decide

theorem arm64_ccmp_false_path_uses_fallback_and_preserves_regs :
    generatedArm64CcmpHandler
      { regs := { dst := { bits := 0xfeed, tag := .mapValue }, sp := 0x80 },
        flags := { n := false, z := false, c := true, v := false } }
      .eq 1 2 .w64 0x6 =
      { regs := { dst := { bits := 0xfeed, tag := .mapValue }, sp := 0x80 },
        flags := { n := false, z := true, c := true, v := false } } := by
  native_decide

theorem arm64_ccmp_w32_true_path_sets_sub_overflow :
    (generatedArm64CcmpHandler
      { regs := { dst := { bits := 0, tag := .scalar }, sp := 0 },
        flags := { n := false, z := false, c := true, v := false } }
      .cs 0x80000000 1 .w32 0).flags =
      { n := false, z := false, c := true, v := true } := by
  native_decide

theorem arm64_ccmp_fallback_ignores_high_nibble :
    GeneratedArm64CcmpHandler.fallbackFlags 0xf5 =
      { n := false, z := true, c := false, v := true } := by
  native_decide

end KProgFormal
