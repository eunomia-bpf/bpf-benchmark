import KProgFormal.X86RegWrite
import KProgFormal.X86AddResult
import KProgFormal.X86SubResult
import KProgFormal.X86Adc
import KProgFormal.X86SbbFlags

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

end KProgFormal
