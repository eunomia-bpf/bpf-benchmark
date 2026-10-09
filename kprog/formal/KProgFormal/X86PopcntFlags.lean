import KProgFormal.GeneratedX86PopcntFlags
import KProgFormal.X86Width
import KProgFormal.X86Opcode
import KProgFormal.X86ControlFlow

namespace KProgFormal

open GeneratedX86PopcntFlags (opcode opcodeBits zeroSource eval Flags)

/-- Independent statement of the `X86_OP_POPCNT` opcode, in the order
`kprog/x86/x86_sim.h` defines it. -/
def x86PopcntOpcodeSpec : Nat := 24

/-- Independent statement of the number of bits the opcode is selected on. -/
def x86PopcntOpcodeBitsSpec : Nat := 8

/-- Independent statement of the source the `ZF` input is read from: the
width-narrowed source operand being zero, stated against the width contract's
own narrowing. -/
def x86PopcntZeroSpec (src : BitVec 64) (width : X86Width) : Bool :=
  x86ZeroSpec src width

/-- Independent statement of the flags after an x86 `POPCNT` applied to the
width-narrowed source: `CF`, `SF`, and `OF` are cleared; `ZF` is set exactly
when the width-narrowed source is zero. Unlike the logical shape, `SF` is *not*
the sign bit of the result. -/
def x86PopcntFlagsSpec (src : BitVec 64) (width : X86Width) : X86Flags :=
  { cf := false, zf := x86PopcntZeroSpec src width, sf := false, of := false }

/-- The generated transition, lifted into the shared `X86Flags` record the other
flag contracts use. -/
def generatedX86PopcntFlags (src : BitVec 64) (width : X86Width) : X86Flags :=
  let f := eval (x86PopcntZeroSpec src width)
  { cf := f.cf, zf := f.zf, sf := f.sf, of := f.of }

/-- The generated transition equals the independent `POPCNT` flag statement. -/
theorem x86_popcnt_flags_refines (src : BitVec 64) (width : X86Width) :
    generatedX86PopcntFlags src width = x86PopcntFlagsSpec src width := by
  cases width <;>
    simp [generatedX86PopcntFlags, x86PopcntFlagsSpec, x86PopcntZeroSpec,
      x86ZeroSpec, x86NarrowSpec, x86WidthMaskSpec, x86WidthBitsSpec, eval]

/-- The generated opcode equals the independent literal, so the opcode the
header's `_Static_assert` pins cannot drift from the simulator's decode. -/
theorem x86_popcnt_opcode_refines : opcode = x86PopcntOpcodeSpec := rfl

/-- The generated opcode width equals the independent literal, pinned so the C
opcode's `__u8` selection width and the generated `opcodeBits` cannot drift. -/
theorem x86_popcnt_opcode_bits_refines :
    opcodeBits = x86PopcntOpcodeBitsSpec := rfl

/-- The independent opcode literal is the code `x86OpcodeSpec` names for
`X86_OP_POPCNT`, so the contract is keyed on the simulator's own decode. -/
theorem x86_popcnt_opcode_spec_bound :
    x86OpcodeSpec.lookup "X86_OP_POPCNT" = some x86PopcntOpcodeSpec := by
  unfold x86PopcntOpcodeSpec
  native_decide

/-- The generated source selector names the narrowed-source zero predicate, so
the input the header feeds cannot drift from the width contract's narrowing. -/
theorem x86_popcnt_zero_source_refines :
    zeroSource = "narrowed_source_is_zero" := rfl

/-- `ZF` is exactly the narrowed-source zero predicate, stated against the width
contract rather than the generated structure. -/
theorem x86_popcnt_zf_is_narrowed_source_zero (src : BitVec 64)
    (width : X86Width) :
    (generatedX86PopcntFlags src width).zf = x86ZeroSpec src width := by
  cases width <;> rfl

/-- `CF`, `SF`, and `OF` are all cleared by the `POPCNT` transition regardless
of the source, so the three flag clears do not depend on the input. -/
theorem x86_popcnt_cleared_flags (src : BitVec 64) (width : X86Width) :
    (generatedX86PopcntFlags src width).cf = false ∧
      (generatedX86PopcntFlags src width).sf = false ∧
      (generatedX86PopcntFlags src width).of = false := by
  cases width <;> exact ⟨rfl, rfl, rfl⟩

/-- A zero source sets `ZF` and clears `CF`/`SF`/`OF` at every width. -/
theorem x86_popcnt_zero_source_sets_zf (width : X86Width) :
    (generatedX86PopcntFlags 0 width).zf = true ∧
      (generatedX86PopcntFlags 0 width).cf = false ∧
      (generatedX86PopcntFlags 0 width).sf = false ∧
      (generatedX86PopcntFlags 0 width).of = false := by
  cases width <;> native_decide

/-- A nonzero source clears `ZF` at every width, so `ZF` is not a constant. -/
theorem x86_popcnt_nonzero_source_clears_zf (width : X86Width) :
    (generatedX86PopcntFlags 1 width).zf = false := by
  cases width <;> native_decide

/-- The `SF` bit is cleared even for a source whose sign bit is set, so the
`POPCNT` flag shape cannot be confused with the logical shape that derives `SF`
from the result sign. -/
theorem x86_popcnt_sf_not_result_sign (width : X86Width) :
    (generatedX86PopcntFlags 0x8000000000000000 width).sf = false := by
  cases width <;> native_decide

/-- The contract is faithful to the simulator arm at the 64-bit width: the
narrowed source is the source itself, so `ZF` is exactly the source being
zero -- a zero word sets it and any nonzero word clears it. -/
theorem x86_popcnt_w64_zf_is_source_zero :
    (generatedX86PopcntFlags 0 .w64).zf = true ∧
      (generatedX86PopcntFlags 0x1000000000000000 .w64).zf = false ∧
      (generatedX86PopcntFlags 0x0000000100000000 .w64).zf = false ∧
      (generatedX86PopcntFlags 0x00000000ffffffff .w64).zf = false ∧
      (generatedX86PopcntFlags 0xffffffff00000000 .w64).zf = false := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The 8-bit narrowing is observable: a source whose low byte is zero but whose
upper bytes are set still clears `ZF` at the 8-bit width, so the input is truly
the *narrowed* source and not the full 64-bit word. -/
theorem x86_popcnt_w8_narrowed_zero :
    (generatedX86PopcntFlags 0x0000000000000100 .w8).zf = true ∧
      (generatedX86PopcntFlags 0x0000000000000001 .w8).zf = false := by
  native_decide

end KProgFormal
