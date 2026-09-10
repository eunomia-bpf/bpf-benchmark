import KProgFormal.X86AluWriteback
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

end KProgFormal
