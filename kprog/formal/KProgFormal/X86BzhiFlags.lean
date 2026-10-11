import KProgFormal.GeneratedX86BzhiFlags
import KProgFormal.X86Width
import KProgFormal.X86Opcode
import KProgFormal.X86ControlFlow

namespace KProgFormal

open GeneratedX86BzhiFlags (opcodeBzhi opcodeBzhiMem opcodeBits cfSource zfSource
  eval Flags)

/-- Independent statement of the `X86_OP_BZHI` opcode, in the order
`kprog/x86/x86_sim.h` defines it. -/
def x86BzhiSetFlagsOpcodeSpec : Nat := 52

/-- Independent statement of the `X86_OP_BZHI_MEM` opcode, the decoder used by
the memory-valued body. -/
def x86BzhiSetFlagsOpcodeMemSpec : Nat := 53

/-- Independent statement of the number of bits each opcode is selected on. -/
def x86BzhiSetFlagsOpcodeBitsSpec : Nat := 8

/-- Independent statement of the source the `CF` input is read from: the
byte-masked count reaching the resolved width's *bit count* (an unsigned
`>=`), stated against the width contract's own bit count. -/
def x86BzhiSetCfSpec (count : BitVec 64) (width : X86Width) : Bool :=
  BitVec.ule (BitVec.ofNat 64 (x86WidthBitsSpec width)) count

/-- Independent statement of the source the `ZF` input is read from: the
cleared *result* being zero. -/
def x86BzhiSetZfSpec (result : BitVec 64) : Bool :=
  result == 0

/-- Independent statement of the flags after an x86 `BZHI`/`BZHI_MEM`: `SF` and
`OF` are cleared; `CF` is set exactly when the byte-masked count reaches the
resolved width's bit count; `ZF` is set exactly when the cleared result is zero.
Unlike the logical shape, `SF` is *not* the sign of the result and `CF` is *not*
a borrow -- it is derived from the count and the width, not from the value
written. -/
def x86BzhiSetFlagsSpec (count result : BitVec 64) (width : X86Width) : X86Flags :=
  { cf := x86BzhiSetCfSpec count width,
    zf := x86BzhiSetZfSpec result,
    sf := false,
    of := false }

/-- The generated transition, lifted into the shared `X86Flags` record the other
flag contracts use. The two inputs are the spec's count-versus-width comparison
and result-zero predicate. -/
def generatedX86BzhiSetFlags (count result : BitVec 64) (width : X86Width) :
    X86Flags :=
  let f := eval (x86BzhiSetCfSpec count width) (x86BzhiSetZfSpec result)
  { cf := f.cf, zf := f.zf, sf := f.sf, of := f.of }

/-- The generated transition equals the independent `BZHI` flag statement: the
`CF` input lands in `CF`, the `ZF` input lands in `ZF`, and `SF`/`OF` are the
generated clears. -/
theorem x86_bzhi_set_flags_refines (count result : BitVec 64) (width : X86Width) :
    generatedX86BzhiSetFlags count result width = x86BzhiSetFlagsSpec count result width := by
  simp only [generatedX86BzhiSetFlags, x86BzhiSetFlagsSpec, eval]

/-- The generated `BZHI` opcode equals the independent literal, so the opcode
the header's `_Static_assert` pins cannot drift from the simulator's decode. -/
theorem x86_bzhi_set_flags_opcode_refines :
    opcodeBzhi = x86BzhiSetFlagsOpcodeSpec := rfl

/-- The generated `BZHI_MEM` opcode equals the independent literal. -/
theorem x86_bzhi_set_flags_opcode_mem_refines :
    opcodeBzhiMem = x86BzhiSetFlagsOpcodeMemSpec := rfl

/-- The generated opcode width equals the independent literal, pinned so the C
opcode's `__u8` selection width and the generated `opcodeBits` cannot drift. -/
theorem x86_bzhi_set_flags_opcode_bits_refines :
    opcodeBits = x86BzhiSetFlagsOpcodeBitsSpec := rfl

/-- The independent `BZHI` opcode literal is the code `x86OpcodeSpec` names, so
the contract is keyed on the simulator's own decode. -/
theorem x86_bzhi_set_flags_opcode_spec_bound :
    x86OpcodeSpec.lookup "X86_OP_BZHI" = some x86BzhiSetFlagsOpcodeSpec := by
  unfold x86BzhiSetFlagsOpcodeSpec
  native_decide

/-- The independent `BZHI_MEM` opcode literal is the code `x86OpcodeSpec` names. -/
theorem x86_bzhi_set_flags_opcode_mem_spec_bound :
    x86OpcodeSpec.lookup "X86_OP_BZHI_MEM" = some x86BzhiSetFlagsOpcodeMemSpec := by
  unfold x86BzhiSetFlagsOpcodeMemSpec
  native_decide

/-- The generated source selector names the count-versus-width comparison, so
the `CF` input the header feeds cannot drift from the width contract's bits. -/
theorem x86_bzhi_set_flags_cf_source_refines :
    cfSource = "masked_count_at_least_width_bits" := rfl

/-- The generated source selector names the result-zero predicate, so the `ZF`
input the header feeds cannot drift from the result. -/
theorem x86_bzhi_set_flags_zf_source_refines :
    zfSource = "result_is_zero" := rfl

/-- `BZHI` clears `SF` and `OF` outright, whatever the count, result, and
width -- `SF` is *not* the sign of the result, unlike the shared logic-flag
production. -/
theorem x86_bzhi_set_flags_clears_sf_of (count result : BitVec 64) (width : X86Width) :
    (x86BzhiSetFlagsSpec count result width).sf = false ∧
      (x86BzhiSetFlagsSpec count result width).of = false := by
  exact ⟨rfl, rfl⟩

/-- `CF` is the byte-masked count reaching the *width's* bit count, not any
property of the result: an 8-bit BZHI reports `CF` at count 8, while a 64-bit
one does not. Same count, same result, different width - a different carry. -/
theorem x86_bzhi_set_flags_cf_is_count_versus_width (result : BitVec 64) :
    (x86BzhiSetFlagsSpec 8 result .w8).cf = true ∧
      (x86BzhiSetFlagsSpec 8 result .w64).cf = false := by
  refine ⟨?_, ?_⟩ <;>
    simp only [x86BzhiSetFlagsSpec, x86BzhiSetCfSpec, x86WidthBitsSpec] <;> decide

/-- `CF` does not depend on the result at all: for a fixed count and width, two
different results yield the same carry. -/
theorem x86_bzhi_set_flags_cf_independent_of_result (width : X86Width) :
    (x86BzhiSetFlagsSpec 4 0 width).cf = (x86BzhiSetFlagsSpec 4 0xffff width).cf := by
  cases width <;>
    simp only [x86BzhiSetFlagsSpec, x86BzhiSetCfSpec, x86WidthBitsSpec] <;> decide

/-- A count below the width's bit count clears `CF` at every width, so `CF` is
not a constant. -/
theorem x86_bzhi_set_flags_count_below_width_clears_cf (width : X86Width) :
    (x86BzhiSetFlagsSpec 1 0xff width).cf = false := by
  cases width <;>
    simp only [x86BzhiSetFlagsSpec, x86BzhiSetCfSpec, x86WidthBitsSpec] <;> decide

/-- The narrowest 8-bit BZHI reports `CF` exactly when the count reaches 8: count
7 clears it, count 8 sets it. -/
theorem x86_bzhi_set_flags_w8_cf_threshold :
    (x86BzhiSetFlagsSpec 7 0 .w8).cf = false ∧
      (x86BzhiSetFlagsSpec 8 0 .w8).cf = true := by
  refine ⟨?_, ?_⟩ <;>
    simp only [x86BzhiSetFlagsSpec, x86BzhiSetCfSpec, x86WidthBitsSpec] <;> decide

/-- `ZF` is the real zero test of the cleared result; `SF` stays false even when
the result's top bit is set, so the two disagree. -/
theorem x86_bzhi_set_flags_zf_real_sf_cleared :
    (x86BzhiSetFlagsSpec 4 0 .w8).zf = true ∧
      (x86BzhiSetFlagsSpec 4 0x80 .w8).zf = false ∧
      (x86BzhiSetFlagsSpec 4 0x80 .w8).sf = false ∧
      x86SignSpec 0x80 .w8 = true := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;>
    simp only [x86BzhiSetFlagsSpec, x86BzhiSetZfSpec, x86SignSpec, x86NarrowSpec,
      x86WidthMaskSpec, x86WidthBitsSpec] <;> decide

/-- A zero result sets `ZF` and leaves `SF`/`OF` cleared; a nonzero result
clears `ZF`. Same count and width. -/
theorem x86_bzhi_set_flags_zf_is_result_zero (width : X86Width) :
    (x86BzhiSetFlagsSpec 4 0 width).zf = true ∧
      (x86BzhiSetFlagsSpec 4 1 width).zf = false ∧
      (x86BzhiSetFlagsSpec 4 0 width).sf = false ∧
      (x86BzhiSetFlagsSpec 4 0 width).of = false := by
  cases width <;>
    simp only [x86BzhiSetFlagsSpec, x86BzhiSetZfSpec] <;> decide

/-- The contract is faithful to the simulator step at the 64-bit width: the
count reaches `CF` only at 64, and `ZF` tracks the result. -/
theorem x86_bzhi_set_flags_w64_cf_threshold :
    (x86BzhiSetFlagsSpec 63 0 .w64).cf = false ∧
      (x86BzhiSetFlagsSpec 64 0 .w64).cf = true := by
  refine ⟨?_, ?_⟩ <;>
    simp only [x86BzhiSetFlagsSpec, x86BzhiSetCfSpec, x86WidthBitsSpec] <;> decide

end KProgFormal
