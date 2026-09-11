import KProgFormal.X86RegWrite
import KProgFormal.X86AddResult
import KProgFormal.X86SubResult
import KProgFormal.X86Adc
import KProgFormal.X86SbbFlags
import KProgFormal.X86RegRead
import KProgFormal.X86LogicFlags
import KProgFormal.X86Immediate
import KProgFormal.X86ShiftResult
import KProgFormal.X86ShiftFlags

namespace KProgFormal

/-- Register destination plus the four flags modeled by the accepted x86
subset. This is the state touched by register ADD/ADC/SUB/SBB handlers. -/
structure X86RegAluState where
  dst : X86RegValue
  flags : X86Flags
  deriving DecidableEq, Repr

def generatedX86AddHandler (state : X86RegAluState) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let result := GeneratedX86Adc.result lhs rhs false
  { dst := generatedX86RegWrite state.dst result width
    flags := generatedX86AddFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) }

def x86AddHandlerSpec (state : X86RegAluState) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let result := x86AddResultSpec lhs rhs
  { dst := x86RegWriteSpec state.dst result width
    flags := x86AddFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) }

theorem x86_add_handler_refines (state : X86RegAluState)
    (rhs : BitVec 64) (width : X86Width) :
    generatedX86AddHandler state rhs width =
      x86AddHandlerSpec state rhs width := by
  simp only [generatedX86AddHandler, x86AddHandlerSpec]
  rw [x86_add_step_refines, x86_reg_write_refines, x86_add_result_refines]

/-- The register-register ADD slice after decoded byte lanes select both
operands. For wider operands the lane parameters are architecturally ignored. -/
def generatedX86AddLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let result := GeneratedX86Adc.result lhs rhs false
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86AddFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) }

def x86AddLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let result := x86AddResultSpec lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86AddFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) }

theorem x86_add_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86AddLaneHandler state rawRhs width dstLane srcLane =
      x86AddLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86AddLaneHandler, x86AddLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_add_step_refines, x86_reg_write_at_refines,
    x86_add_result_refines]

theorem x86_add_high8_example :
    (generatedX86AddLaneHandler
      { dst := { bits := 0x1122334455667f01, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } }
      0x0000000000000102 .w8 .high .high).dst.bits =
      0x1122334455668001 := by
  native_decide

/-- Register-destination ADD-immediate after lane selection and decoding of the
raw artifact immediate. This is the value/flags/writeback slice used by the C
ALU-immediate handler once opcode, width, lane, and raw field are supplied. -/
def generatedX86AddImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let result := GeneratedX86Adc.result lhs rhs false
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86AddFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) }

def x86AddImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let result := x86AddResultSpec lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86AddFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) }

theorem x86_add_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86AddImmLaneHandler state rawImm width dstLane =
      x86AddImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86AddImmLaneHandler, x86AddImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_add_step_refines, x86_reg_write_at_refines,
    x86_add_result_refines]

theorem x86_add_imm64_sign_extension_example :
    generatedX86AddImmLaneHandler
      { dst := { bits := 1, tag := .packet },
        flags := { cf := false, zf := false, sf := true, of := true } }
      0xffffffff .w64 .low =
      { dst := { bits := 0, tag := .scalar },
        flags := { cf := true, zf := true, sf := false, of := false } } := by
  native_decide

def generatedX86AdcHandler (state : X86RegAluState) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let carry := state.flags.cf
  let result := GeneratedX86Adc.result lhs rhs carry
  { dst := generatedX86RegWrite state.dst result width
    flags := generatedX86AdcFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) carry }

def x86AdcHandlerSpec (state : X86RegAluState) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let carry := state.flags.cf
  let result := x86AdcResultSpec lhs rhs carry
  { dst := x86RegWriteSpec state.dst result width
    flags := x86AdcFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) carry }

theorem x86_adc_handler_refines (state : X86RegAluState)
    (rhs : BitVec 64) (width : X86Width) :
    generatedX86AdcHandler state rhs width =
      x86AdcHandlerSpec state rhs width := by
  simp only [generatedX86AdcHandler, x86AdcHandlerSpec]
  rw [x86_adc_step_refines, x86_reg_write_refines, x86_adc_result_refines]

/-- Register-register ADC after lane selection. The incoming carry is captured
from the pre-state before the result and replacement flags are computed. -/
def generatedX86AdcLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let carry := state.flags.cf
  let result := GeneratedX86Adc.result lhs rhs carry
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86AdcFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) carry }

def x86AdcLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let carry := state.flags.cf
  let result := x86AdcResultSpec lhs rhs carry
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86AdcFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) carry }

theorem x86_adc_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86AdcLaneHandler state rawRhs width dstLane srcLane =
      x86AdcLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86AdcLaneHandler, x86AdcLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_adc_step_refines, x86_reg_write_at_refines,
    x86_adc_result_refines]

theorem x86_adc_high8_consumes_incoming_carry :
    (generatedX86AdcLaneHandler
      { dst := { bits := 0x1122334455667f01, tag := .scalar },
        flags := { cf := true, zf := false, sf := false, of := false } }
      0x0000000000000102 .w8 .high .high).dst.bits =
      0x1122334455668101 := by
  native_decide

/-- Register-destination ADC-immediate after lane selection and raw immediate
decoding. The carry used by both result and flags is captured from the same
pre-state. -/
def generatedX86AdcImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let carry := state.flags.cf
  let result := GeneratedX86Adc.result lhs rhs carry
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86AdcFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) carry }

def x86AdcImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let carry := state.flags.cf
  let result := x86AdcResultSpec lhs rhs carry
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86AdcFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) carry }

theorem x86_adc_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86AdcImmLaneHandler state rawImm width dstLane =
      x86AdcImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86AdcImmLaneHandler, x86AdcImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_adc_step_refines, x86_reg_write_at_refines,
    x86_adc_result_refines]

theorem x86_adc_imm64_carry_boundary_example :
    generatedX86AdcImmLaneHandler
      { dst := { bits := 0, tag := .packet },
        flags := { cf := true, zf := false, sf := true, of := true } }
      0xffffffff .w64 .low =
      { dst := { bits := 0, tag := .scalar },
        flags := { cf := true, zf := true, sf := false, of := false } } := by
  native_decide

def generatedX86SubHandler (state : X86RegAluState) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let result := GeneratedX86SbbResult.result lhs rhs false
  { dst := generatedX86RegWrite state.dst result width
    flags := generatedX86SubFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) }

def x86SubHandlerSpec (state : X86RegAluState) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let result := x86SubResultSpec lhs rhs
  { dst := x86RegWriteSpec state.dst result width
    flags := x86SubFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) }

theorem x86_sub_handler_refines (state : X86RegAluState)
    (rhs : BitVec 64) (width : X86Width) :
    generatedX86SubHandler state rhs width =
      x86SubHandlerSpec state rhs width := by
  simp only [generatedX86SubHandler, x86SubHandlerSpec]
  rw [x86_sub_step_refines, x86_reg_write_refines, x86_sub_result_refines]

/-- Register-register SUB after lane selection. The result is produced by the
generated subtraction primitive rather than supplied as a theorem premise. -/
def generatedX86SubLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let result := GeneratedX86SbbResult.result lhs rhs false
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86SubFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) }

def x86SubLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let result := x86SubResultSpec lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86SubFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) }

theorem x86_sub_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86SubLaneHandler state rawRhs width dstLane srcLane =
      x86SubLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86SubLaneHandler, x86SubLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_sub_step_refines, x86_reg_write_at_refines,
    x86_sub_result_refines]

theorem x86_sub_high8_example :
    (generatedX86SubLaneHandler
      { dst := { bits := 0x1122334455660001, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } }
      0x0000000000000102 .w8 .high .high).dst.bits =
      0x112233445566ff01 := by
  native_decide

/-- Register-destination SUB-immediate after lane selection and decoding of the
raw artifact immediate. -/
def generatedX86SubImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let result := GeneratedX86SbbResult.result lhs rhs false
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86SubFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) }

def x86SubImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let result := x86SubResultSpec lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86SubFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) }

theorem x86_sub_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86SubImmLaneHandler state rawImm width dstLane =
      x86SubImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86SubImmLaneHandler, x86SubImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_sub_step_refines, x86_reg_write_at_refines,
    x86_sub_result_refines]

theorem x86_sub_imm64_sign_extension_example :
    generatedX86SubImmLaneHandler
      { dst := { bits := 0, tag := .packet },
        flags := { cf := false, zf := true, sf := true, of := true } }
      0xffffffff .w64 .low =
      { dst := { bits := 1, tag := .scalar },
        flags := { cf := true, zf := false, sf := false, of := false } } := by
  native_decide

def generatedX86SbbHandler (state : X86RegAluState) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let borrow := state.flags.cf
  let result := GeneratedX86SbbResult.result lhs rhs borrow
  { dst := generatedX86RegWrite state.dst result width
    flags := generatedX86SbbFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86SbbResult.subtrahend
        (GeneratedX86Width.narrow rhs width)
        (GeneratedX86Width.mask width) borrow)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) borrow }

def x86SbbHandlerSpec (state : X86RegAluState) (rhs : BitVec 64)
    (width : X86Width) : X86RegAluState :=
  let lhs := state.dst.bits
  let borrow := state.flags.cf
  let result := x86SbbResultSpec lhs rhs borrow
  { dst := x86RegWriteSpec state.dst result width
    flags := x86SbbFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width)
      (x86SbbSubtrahendSpec (x86NarrowSpec rhs width)
        (x86WidthMaskSpec width) borrow)
      (x86NarrowSpec result width) (x86WidthSignMaskSpec width) borrow }

theorem x86_sbb_handler_refines (state : X86RegAluState)
    (rhs : BitVec 64) (width : X86Width) :
    generatedX86SbbHandler state rhs width =
      x86SbbHandlerSpec state rhs width := by
  simp only [generatedX86SbbHandler, x86SbbHandlerSpec]
  rw [x86_sbb_step_refines, x86_reg_write_refines, x86_sbb_result_refines]

/-- Register-register SBB after lane selection. The incoming CF is the borrow
consumed by both the generated result and flag transition. -/
def generatedX86SbbLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let borrow := state.flags.cf
  let result := GeneratedX86SbbResult.result lhs rhs borrow
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86SbbFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86SbbResult.subtrahend
        (GeneratedX86Width.narrow rhs width)
        (GeneratedX86Width.mask width) borrow)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) borrow }

def x86SbbLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let borrow := state.flags.cf
  let result := x86SbbResultSpec lhs rhs borrow
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86SbbFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width)
      (x86SbbSubtrahendSpec (x86NarrowSpec rhs width)
        (x86WidthMaskSpec width) borrow)
      (x86NarrowSpec result width) (x86WidthSignMaskSpec width) borrow }

theorem x86_sbb_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86SbbLaneHandler state rawRhs width dstLane srcLane =
      x86SbbLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86SbbLaneHandler, x86SbbLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_sbb_step_refines, x86_reg_write_at_refines,
    x86_sbb_result_refines]

theorem x86_sbb_high8_consumes_incoming_borrow :
    (generatedX86SbbLaneHandler
      { dst := { bits := 0x1122334455660001, tag := .scalar },
        flags := { cf := true, zf := false, sf := false, of := false } }
      0x0000000000000102 .w8 .high .high).dst.bits =
      0x112233445566fe01 := by
  native_decide

/-- Register-destination SBB-immediate after lane selection and raw immediate
decoding. The borrow used by the result, subtrahend, and flags is captured from
one pre-state. -/
def generatedX86SbbImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let borrow := state.flags.cf
  let result := GeneratedX86SbbResult.result lhs rhs borrow
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86SbbFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86SbbResult.subtrahend
        (GeneratedX86Width.narrow rhs width)
        (GeneratedX86Width.mask width) borrow)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) borrow }

def x86SbbImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let borrow := state.flags.cf
  let result := x86SbbResultSpec lhs rhs borrow
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86SbbFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width)
      (x86SbbSubtrahendSpec (x86NarrowSpec rhs width)
        (x86WidthMaskSpec width) borrow)
      (x86NarrowSpec result width) (x86WidthSignMaskSpec width) borrow }

theorem x86_sbb_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86SbbImmLaneHandler state rawImm width dstLane =
      x86SbbImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86SbbImmLaneHandler, x86SbbImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_sbb_step_refines, x86_reg_write_at_refines,
    x86_sbb_result_refines]

theorem x86_sbb_imm64_borrow_boundary_example :
    generatedX86SbbImmLaneHandler
      { dst := { bits := 0, tag := .packet },
        flags := { cf := true, zf := false, sf := true, of := true } }
      0xffffffff .w64 .low =
      { dst := { bits := 0, tag := .scalar },
        flags := { cf := true, zf := true, sf := false, of := false } } := by
  native_decide

/-- CMP observes the selected register lanes and replaces flags with the
generated subtraction flags, while preserving the complete destination. -/
def generatedX86CmpLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let result := GeneratedX86SbbResult.result lhs rhs false
  { dst := state.dst
    flags := generatedX86SubFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) }

def x86CmpLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let result := x86SubResultSpec lhs rhs
  { dst := state.dst
    flags := x86SubFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) }

theorem x86_cmp_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86CmpLaneHandler state rawRhs width dstLane srcLane =
      x86CmpLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86CmpLaneHandler, x86CmpLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_sub_step_refines]

theorem x86_cmp_lane_preserves_destination (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    (generatedX86CmpLaneHandler state rawRhs width dstLane srcLane).dst =
      state.dst := by
  rfl

theorem x86_cmp_high8_observes_high_lanes :
    (generatedX86CmpLaneHandler
      { dst := { bits := 0x112233445566aa01, tag := .scalar },
        flags := { cf := true, zf := false, sf := true, of := true } }
      0x000000000000aa02 .w8 .high .high).flags.zf = true := by
  native_decide

/-- Register-destination CMP-immediate after lane selection and raw immediate
decoding. It replaces flags with the generated zero-borrow subtraction flags
and preserves the complete destination register value and tag. -/
def generatedX86CmpImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let result := GeneratedX86SbbResult.result lhs rhs false
  { dst := state.dst
    flags := generatedX86SubFlags (GeneratedX86Width.narrow lhs width)
      (GeneratedX86Width.narrow rhs width)
      (GeneratedX86Width.narrow result width)
      (GeneratedX86Width.signMask width) }

def x86CmpImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let result := x86SubResultSpec lhs rhs
  { dst := state.dst
    flags := x86SubFlagsSpec (x86NarrowSpec lhs width)
      (x86NarrowSpec rhs width) (x86NarrowSpec result width)
      (x86WidthSignMaskSpec width) }

theorem x86_cmp_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86CmpImmLaneHandler state rawImm width dstLane =
      x86CmpImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86CmpImmLaneHandler, x86CmpImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_sub_step_refines]

theorem x86_cmp_imm_lane_preserves_destination (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    (generatedX86CmpImmLaneHandler state rawImm width dstLane).dst =
      state.dst := by
  rfl

theorem x86_cmp_imm64_sign_extension_example :
    generatedX86CmpImmLaneHandler
      { dst := { bits := 0, tag := .packet },
        flags := { cf := false, zf := true, sf := true, of := true } }
      0xffffffff .w64 .low =
      { dst := { bits := 0, tag := .packet },
        flags := { cf := true, zf := false, sf := false, of := false } } := by
  native_decide

/-- TEST observes the selected register lanes, derives logic flags from their
bitwise conjunction, and preserves the complete destination register. -/
def generatedX86TestLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let result := GeneratedX86Width.narrow (BitVec.and lhs rhs) width
  { dst := state.dst
    flags := generatedX86LogicFlags (result == 0)
      (BitVec.and result (GeneratedX86Width.signMask width) != 0) }

def x86TestLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let result := x86NarrowSpec (BitVec.and lhs rhs) width
  { dst := state.dst
    flags := x86LogicFlagsSpec (result == 0)
      (BitVec.and result (x86WidthSignMaskSpec width) != 0) }

theorem x86_test_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86TestLaneHandler state rawRhs width dstLane srcLane =
      x86TestLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86TestLaneHandler, x86TestLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_narrow_refines, x86_width_sign_mask_refines]
  rw [x86_logic_flags_refine]

theorem x86_test_lane_preserves_destination (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    (generatedX86TestLaneHandler state rawRhs width dstLane srcLane).dst =
      state.dst := by
  rfl

theorem x86_test_high8_observes_high_lanes :
    let flags := (generatedX86TestLaneHandler
      { dst := { bits := 0x112233445566aa01, tag := .scalar },
        flags := { cf := true, zf := true, sf := false, of := true } }
      0x000000000000f002 .w8 .high .high).flags
    flags.zf = false /\ flags.sf = true := by
  native_decide

/-- Register-destination TEST-immediate after lane selection and raw immediate
decoding. It replaces flags from the width-local conjunction and preserves the
complete destination register value and tag. -/
def generatedX86TestImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let result := GeneratedX86Width.narrow (BitVec.and lhs rhs) width
  { dst := state.dst
    flags := generatedX86LogicFlags (result == 0)
      (BitVec.and result (GeneratedX86Width.signMask width) != 0) }

def x86TestImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let result := x86NarrowSpec (BitVec.and lhs rhs) width
  { dst := state.dst
    flags := x86LogicFlagsSpec (result == 0)
      (BitVec.and result (x86WidthSignMaskSpec width) != 0) }

theorem x86_test_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86TestImmLaneHandler state rawImm width dstLane =
      x86TestImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86TestImmLaneHandler, x86TestImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_narrow_refines, x86_width_sign_mask_refines]
  rw [x86_logic_flags_refine]

theorem x86_test_imm_lane_preserves_destination (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    (generatedX86TestImmLaneHandler state rawImm width dstLane).dst =
      state.dst := by
  rfl

theorem x86_test_imm_high8_example :
    generatedX86TestImmLaneHandler
      { dst := { bits := 0x1122334455668001, tag := .packet },
        flags := { cf := true, zf := true, sf := false, of := true } }
      0x80 .w8 .high =
      { dst := { bits := 0x1122334455668001, tag := .packet },
        flags := { cf := false, zf := false, sf := true, of := false } } := by
  native_decide

/-- Register-register AND after both selected lanes are observed. The C
`X86_SIM_L_EXEC_ALU_REG` generic branch computes the width-local logical result
from the two lane observations, replaces the destination lane, and takes
CF=OF=0 with ZF/SF from the width-narrowed result. The logical result of each
operation is the corresponding `BitVec` binary connective; the writeback and
flag contracts are the shared generated ones. -/
def generatedX86AndRegLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let result := BitVec.and lhs rhs
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86LogicFlags (GeneratedX86Width.zero result width)
      (GeneratedX86Width.sign result width) }

def x86AndRegLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let result := BitVec.and lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86LogicFlagsSpec (x86ZeroSpec result width)
      (x86SignSpec result width) }

theorem x86_and_reg_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86AndRegLaneHandler state rawRhs width dstLane srcLane =
      x86AndRegLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86AndRegLaneHandler, x86AndRegLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_zero_refines, x86_sign_refines,
    x86_logic_flags_refine, x86_reg_write_at_refines]

theorem x86_and_reg_high8_example :
    generatedX86AndRegLaneHandler
      { dst := { bits := 0x112233445566ff00, tag := .packet },
        flags := { cf := true, zf := true, sf := false, of := true } }
      0x0f00 .w8 .high .high =
      { dst := { bits := 0x1122334455660f00, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  native_decide

def generatedX86OrRegLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let result := BitVec.or lhs rhs
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86LogicFlags (GeneratedX86Width.zero result width)
      (GeneratedX86Width.sign result width) }

def x86OrRegLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let result := BitVec.or lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86LogicFlagsSpec (x86ZeroSpec result width)
      (x86SignSpec result width) }

theorem x86_or_reg_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86OrRegLaneHandler state rawRhs width dstLane srcLane =
      x86OrRegLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86OrRegLaneHandler, x86OrRegLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_zero_refines, x86_sign_refines,
    x86_logic_flags_refine, x86_reg_write_at_refines]

theorem x86_or_reg_high8_example :
    generatedX86OrRegLaneHandler
      { dst := { bits := 0x11223344556600ff, tag := .scalar },
        flags := { cf := false, zf := false, sf := true, of := true } }
      0x8000 .w8 .high .high =
      { dst := { bits := 0x11223344556680ff, tag := .scalar },
        flags := { cf := false, zf := false, sf := true, of := false } } := by
  native_decide

def generatedX86XorRegLaneHandler (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86RegRead.readAt rawRhs width srcLane
  let result := BitVec.xor lhs rhs
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86LogicFlags (GeneratedX86Width.zero result width)
      (GeneratedX86Width.sign result width) }

def x86XorRegLaneHandlerSpec (state : X86RegAluState) (rawRhs : BitVec 64)
    (width : X86Width) (dstLane srcLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86RegReadAtSpec rawRhs width srcLane
  let result := BitVec.xor lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86LogicFlagsSpec (x86ZeroSpec result width)
      (x86SignSpec result width) }

theorem x86_xor_reg_lane_handler_refines (state : X86RegAluState)
    (rawRhs : BitVec 64) (width : X86Width)
    (dstLane srcLane : X86ByteLane) :
    generatedX86XorRegLaneHandler state rawRhs width dstLane srcLane =
      x86XorRegLaneHandlerSpec state rawRhs width dstLane srcLane := by
  simp only [generatedX86XorRegLaneHandler, x86XorRegLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_reg_read_at_refines,
    x86_zero_refines, x86_sign_refines,
    x86_logic_flags_refine, x86_reg_write_at_refines]

theorem x86_xor_reg64_example :
    generatedX86XorRegLaneHandler
      { dst := { bits := 0x0000000000123456, tag := .scalar },
        flags := { cf := true, zf := true, sf := false, of := true } }
      0x0000000000765432 .w64 .low .low =
      { dst := { bits := 0x0000000000646064, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  native_decide
/-- Register-destination AND/OR/XOR-immediate after lane selection and raw
immediate decoding. The C handler computes the width-local logical result from
the selected-lane operand, replaces the destination lane, and takes the four
flags from the width-local zero/sign observation. The logical result of each
operation is the corresponding `BitVec` binary connective; the writeback and
flag contracts are the shared generated ones. -/
def generatedX86AndImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let result := BitVec.and lhs rhs
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86LogicFlags (GeneratedX86Width.zero result width)
      (GeneratedX86Width.sign result width) }

def x86AndImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let result := BitVec.and lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86LogicFlagsSpec (x86ZeroSpec result width)
      (x86SignSpec result width) }

theorem x86_and_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86AndImmLaneHandler state rawImm width dstLane =
      x86AndImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86AndImmLaneHandler, x86AndImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_zero_refines, x86_sign_refines,
    x86_logic_flags_refine, x86_reg_write_at_refines]

def generatedX86OrImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let result := BitVec.or lhs rhs
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86LogicFlags (GeneratedX86Width.zero result width)
      (GeneratedX86Width.sign result width) }

def x86OrImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let result := BitVec.or lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86LogicFlagsSpec (x86ZeroSpec result width)
      (x86SignSpec result width) }

theorem x86_or_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86OrImmLaneHandler state rawImm width dstLane =
      x86OrImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86OrImmLaneHandler, x86OrImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_zero_refines, x86_sign_refines,
    x86_logic_flags_refine, x86_reg_write_at_refines]

def generatedX86XorImmLaneHandler (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let rhs := GeneratedX86Immediate.value rawImm width
  let result := BitVec.xor lhs rhs
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86LogicFlags (GeneratedX86Width.zero result width)
      (GeneratedX86Width.sign result width) }

def x86XorImmLaneHandlerSpec (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width)
    (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let rhs := x86ImmediateValueSpec rawImm width
  let result := BitVec.xor lhs rhs
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := x86LogicFlagsSpec (x86ZeroSpec result width)
      (x86SignSpec result width) }

theorem x86_xor_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86XorImmLaneHandler state rawImm width dstLane =
      x86XorImmLaneHandlerSpec state rawImm width dstLane := by
  simp only [generatedX86XorImmLaneHandler, x86XorImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_immediate_value_refines,
    x86_zero_refines, x86_sign_refines,
    x86_logic_flags_refine, x86_reg_write_at_refines]

theorem x86_and_imm_high8_example :
    generatedX86AndImmLaneHandler
      { dst := { bits := 0x112233445566ff00, tag := .packet },
        flags := { cf := true, zf := true, sf := false, of := true } }
      0x0f .w8 .high =
      { dst := { bits := 0x1122334455660f00, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  native_decide

theorem x86_or_imm_high8_example :
    generatedX86OrImmLaneHandler
      { dst := { bits := 0x11223344556600ff, tag := .scalar },
        flags := { cf := false, zf := false, sf := true, of := true } }
      0x80 .w8 .high =
      { dst := { bits := 0x11223344556680ff, tag := .scalar },
        flags := { cf := false, zf := false, sf := true, of := false } } := by
  native_decide

theorem x86_xor_imm64_sign_extension_example :
    generatedX86XorImmLaneHandler
      { dst := { bits := 0x55555555, tag := .scalar },
        flags := { cf := true, zf := false, sf := false, of := true } }
      0xffffffff .w64 .low =
      { dst := { bits := 0xffffffffaaaaaaaa, tag := .scalar },
        flags := { cf := false, zf := false, sf := true, of := false } } := by
  native_decide

/-- Register-destination SHL/SHR/SAR/ROL-immediate after lane selection and
raw immediate decoding. The C handler computes the generated shift result
from the selected-lane operand and the raw count field, writes back the
selected lane, and replaces the flags through the generated shift-flag
transition seeded with the pre-state flags. Undefined CF/OF cases remain
architecturally unconstrained; the shared definedness contract proves the
generated transition satisfies the architectural choice whenever the case
is defined. -/
def generatedX86ShiftImmLaneHandler (op : X86ShiftOp)
    (state : X86RegAluState) (rawImm : BitVec 64)
    (width : X86Width) (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := GeneratedX86RegRead.readAt state.dst.bits width dstLane
  let result := match op with
    | .shl => GeneratedX86ShiftResult.shl lhs rawImm width
    | .shr => GeneratedX86ShiftResult.shr lhs rawImm width
    | .sar => GeneratedX86ShiftResult.sar lhs rawImm width
    | .rol => GeneratedX86ShiftResult.rol lhs rawImm width
  { dst := generatedX86RegWriteAt state.dst result width dstLane
    flags := generatedX86ShiftFlags op lhs rawImm result width state.flags }

def x86ShiftImmLaneHandlerSpec (op : X86ShiftOp)
    (state : X86RegAluState) (rawImm : BitVec 64)
    (width : X86Width) (dstLane : X86ByteLane) : X86RegAluState :=
  let lhs := x86RegReadAtSpec state.dst.bits width dstLane
  let result := match op with
    | .shl => x86ShlResultSpec lhs rawImm width
    | .shr => x86ShrResultSpec lhs rawImm width
    | .sar => x86SarResultSpec lhs rawImm width
    | .rol => x86RolResultSpec lhs rawImm width
  { dst := x86RegWriteAtSpec state.dst result width dstLane
    flags := generatedX86ShiftFlags op lhs rawImm result width state.flags }

theorem x86_shl_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86ShiftImmLaneHandler .shl state rawImm width dstLane =
      x86ShiftImmLaneHandlerSpec .shl state rawImm width dstLane := by
  simp only [generatedX86ShiftImmLaneHandler, x86ShiftImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_shl_result_refines,
    x86_reg_write_at_refines]

theorem x86_shr_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86ShiftImmLaneHandler .shr state rawImm width dstLane =
      x86ShiftImmLaneHandlerSpec .shr state rawImm width dstLane := by
  simp only [generatedX86ShiftImmLaneHandler, x86ShiftImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_shr_result_refines,
    x86_reg_write_at_refines]

theorem x86_sar_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86ShiftImmLaneHandler .sar state rawImm width dstLane =
      x86ShiftImmLaneHandlerSpec .sar state rawImm width dstLane := by
  simp only [generatedX86ShiftImmLaneHandler, x86ShiftImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_sar_result_refines,
    x86_reg_write_at_refines]

theorem x86_rol_imm_lane_handler_refines (state : X86RegAluState)
    (rawImm : BitVec 64) (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86ShiftImmLaneHandler .rol state rawImm width dstLane =
      x86ShiftImmLaneHandlerSpec .rol state rawImm width dstLane := by
  simp only [generatedX86ShiftImmLaneHandler, x86ShiftImmLaneHandlerSpec]
  rw [x86_reg_read_at_refines, x86_rol_result_refines,
    x86_reg_write_at_refines]

/-- For every shift opcode, the generated shift-flag transition used by the
immediate handler satisfies the architectural shift-flag definedness contract
for arbitrary operands, results, widths, and pre-state flags. This composes
the generated result with the generated flags at the handler level. -/
theorem x86_shift_imm_flags_defined (op : X86ShiftOp)
    (lhs rawImm result : BitVec 64) (width : X86Width)
    (old : X86Flags) :
    x86ShiftFlagsDefinedSpec op lhs rawImm result width old
      (generatedX86ShiftFlags op lhs rawImm result width old) = true := by
  cases op <;>
    (try exact x86_shl_flags_defined lhs rawImm width result old);
  (try exact x86_shr_flags_defined lhs rawImm width result old);
  (try exact x86_sar_flags_defined lhs rawImm width result old);
  (try exact x86_rol_flags_defined lhs rawImm width result old)

theorem x86_shl_imm64_wide_count_example :
    let s := { dst := { bits := 0x0000000000000001, tag := .scalar },
               flags := { cf := false, zf := false, sf := false, of := false } }
    (generatedX86ShiftImmLaneHandler .shl s 96 .w64 .low).dst.bits =
      0x100000000 := by
  native_decide

theorem x86_rol_imm_high8_example :
    generatedX86ShiftImmLaneHandler .rol
      { dst := { bits := 0x1122334455660100, tag := .scalar },
        flags := { cf := false, zf := true, sf := true, of := true } }
      2 .w8 .high =
      { dst := { bits := 0x1122334455660400, tag := .scalar },
        flags := { cf := false, zf := true, sf := true, of := true } } := by
  native_decide

end KProgFormal
