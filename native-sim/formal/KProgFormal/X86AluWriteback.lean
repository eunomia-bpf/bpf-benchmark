import KProgFormal.X86RegWrite
import KProgFormal.X86AddResult
import KProgFormal.X86SubResult
import KProgFormal.X86Adc
import KProgFormal.X86SbbFlags
import KProgFormal.X86RegRead
import KProgFormal.X86LogicFlags

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

end KProgFormal
