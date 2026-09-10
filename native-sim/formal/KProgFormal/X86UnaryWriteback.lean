import KProgFormal.X86AluWriteback
import KProgFormal.X86IncDec
import KProgFormal.X86Not

namespace KProgFormal

/-- Register NOT after decoded lane selection. The result is written only to
the selected byte lane and all modeled flags are preserved. -/
def generatedX86NotLaneHandler (state : X86RegAluState) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let value := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let result := GeneratedX86Not.result value
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86NotFlags state.flags }

def x86NotLaneHandlerSpec (state : X86RegAluState) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let value := x86RegReadAtSpec state.dst.bits width dstLane
  let result := x86NotWidthResultSpec value width
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86NotFlagsSpec state.flags }

theorem x86_not_lane_handler_refines (state : X86RegAluState)
    (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86NotLaneHandler state width dstLane =
      x86NotLaneHandlerSpec state width dstLane := by
  simp only [generatedX86NotLaneHandler, x86NotLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_not_flags_refine,
    x86_reg_write_at_refines, x86_reg_write_at_narrow_value]
  rw [← x86_narrow_refines, x86_not_narrowed_result_refines]

theorem x86_not_high8_preserves_other_bits_and_flags :
    generatedX86NotLaneHandler
      { dst := { bits := 0x112233445566aa01, tag := .packet },
        flags := { cf := true, zf := false, sf := true, of := false } }
      .w8 .high =
      { dst := { bits := 0x1122334455665501, tag := .scalar },
        flags := { cf := true, zf := false, sf := true, of := false } } := by
  native_decide

/-- Register INC after decoded lane selection. The selected lane is incremented,
the result is written back to that lane, and the incoming carry flag is
preserved while the remaining modeled arithmetic flags are replaced. -/
def generatedX86IncLaneHandler (state : X86RegAluState) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let value := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let result := GeneratedX86Adc.result value 1 false
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86IncFlags (GeneratedX86Width.narrow value width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) state.flags.cf }

def x86IncLaneHandlerSpec (state : X86RegAluState) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let value := x86RegReadAtSpec state.dst.bits width dstLane
  let result := x86IncResultSpec value
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86IncFlagsSpec (x86NarrowSpec value width)
      (x86NarrowSpec result width) (x86WidthSignMaskSpec width) state.flags.cf }

theorem x86_inc_lane_handler_refines (state : X86RegAluState)
    (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86IncLaneHandler state width dstLane =
      x86IncLaneHandlerSpec state width dstLane := by
  simp only [generatedX86IncLaneHandler, x86IncLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_inc_step_refines,
    x86_reg_write_at_refines, x86_inc_result_refines]

theorem x86_inc_high8_wraps_and_preserves_carry :
    generatedX86IncLaneHandler
      { dst := { bits := 0x112233445566ff01, tag := .packet },
        flags := { cf := true, zf := false, sf := true, of := true } }
      .w8 .high =
      { dst := { bits := 0x1122334455660001, tag := .scalar },
        flags := { cf := true, zf := true, sf := false, of := false } } := by
  native_decide

/-- Register DEC after decoded lane selection. The selected lane is decremented,
the result is written back to that lane, and the incoming carry flag is
preserved while the remaining modeled arithmetic flags are replaced. -/
def generatedX86DecLaneHandler (state : X86RegAluState) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let value := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let result := GeneratedX86SbbResult.result value 1 false
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86DecFlags (GeneratedX86Width.narrow value width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) state.flags.cf }

def x86DecLaneHandlerSpec (state : X86RegAluState) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let value := x86RegReadAtSpec state.dst.bits width dstLane
  let result := x86DecResultSpec value
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86DecFlagsSpec (x86NarrowSpec value width)
      (x86NarrowSpec result width) (x86WidthSignMaskSpec width) state.flags.cf }

theorem x86_dec_lane_handler_refines (state : X86RegAluState)
    (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86DecLaneHandler state width dstLane =
      x86DecLaneHandlerSpec state width dstLane := by
  simp only [generatedX86DecLaneHandler, x86DecLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_dec_step_refines,
    x86_reg_write_at_refines, x86_dec_result_refines]

theorem x86_dec_high8_overflow_and_preserves_carry :
    generatedX86DecLaneHandler
      { dst := { bits := 0x1122334455668001, tag := .packet },
        flags := { cf := true, zf := true, sf := true, of := false } }
      .w8 .high =
      { dst := { bits := 0x1122334455667f01, tag := .scalar },
        flags := { cf := true, zf := false, sf := false, of := true } } := by
  native_decide

end KProgFormal
