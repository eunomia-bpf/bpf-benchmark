import KProgFormal.X86MemAccess
import KProgFormal.X86AluWriteback
import KProgFormal.X86Signed
import KProgFormal.X86Immediate

namespace KProgFormal

/-- Composition used by the x86 `IMUL reg, [mem], imm` handler after
address-space selection has supplied the little-endian bytes at a valid
effective address. The memory operand is read at its *own* width `memWidth`
(the auxiliary operand carries the encoded access size); the destination
register's width `width` governs the immediate sign extension, the IMUL flag
computation, and the writeback confinement. The loaded value is sign-extended
from `memWidth` before the multiply, so a narrow memory read lands in the
product as a signed quantity, while the flag operands stay the raw loaded and
senior-extended immediate values exactly as `X86_SIM_L_SET_IMUL_FLAGS` receives
them. The `if (!memWidth) memWidth = width` default resolution in
`X86_SIM_L_EXEC_IMUL_MEM_IMM` is an auxiliary-decode concern shared with the
other memory-source handlers and is applied before this bounded step. -/
def generatedX86MemImulStep (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (rawImm : BitVec 64) (width memWidth : X86Width) : X86RegAluState :=
  let lhs := GeneratedX86MemAccess.load byte memWidth
  let rhs := GeneratedX86Signed.signExtend
    (GeneratedX86Immediate.value rawImm width) width
  let result := GeneratedX86Signed.signExtend lhs memWidth * rhs
  { dst := generatedX86RegWrite state.dst result width
    flags := generatedX86ImulFlags lhs rhs width state.flags }

/-- Independent statement of the same handler: load through the byte-sum memory
specification at the memory operand's width, apply the independently stated
sign extension to both operands, multiply in the 64-bit wrap-around arithmetic,
and confine the writeback to the destination width. -/
def x86MemImulStepSpec (state : X86RegAluState) (byte : Nat -> X86MemByte)
    (rawImm : BitVec 64) (width memWidth : X86Width) : X86RegAluState :=
  let lhs := x86MemLoadSpec byte memWidth
  let rhs := x86SignExtendSpec (x86ImmediateValueSpec rawImm width) width
  let result := x86SignExtendSpec lhs memWidth * rhs
  { dst := x86RegWriteSpec state.dst result width
    flags := x86ImulFlagsApplied lhs rhs width state.flags }

/-- The memory-source IMUL-immediate handler composition refines the
independent load/sign-extend/multiply/flags/writeback statement for arbitrary
memory bytes, register state, incoming flags, decoded immediate, destination
width, and memory-operand width. -/
theorem x86_mem_imul_step_refines (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (rawImm : BitVec 64)
    (width memWidth : X86Width) :
    generatedX86MemImulStep state byte rawImm width memWidth =
      x86MemImulStepSpec state byte rawImm width memWidth := by
  simp only [generatedX86MemImulStep, x86MemImulStepSpec,
    x86_mem_load_refines, x86_immediate_value_refines,
    x86_sign_extend_refines, x86_reg_write_refines,
    x86_imul_flags_apply_refines]

/-- IMUL defines only CF and OF: the incoming ZF and SF survive the handler. -/
theorem x86_mem_imul_preserves_zf_sf (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (rawImm : BitVec 64)
    (width memWidth : X86Width) :
    (x86MemImulStepSpec state byte rawImm width memWidth).flags.zf =
        state.flags.zf ∧
      (x86MemImulStepSpec state byte rawImm width memWidth).flags.sf =
        state.flags.sf := by
  exact ⟨rfl, rfl⟩

/-- IMUL sets CF and OF together: they report the same overflow condition. -/
theorem x86_mem_imul_cf_eq_of (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (rawImm : BitVec 64)
    (width memWidth : X86Width) :
    (x86MemImulStepSpec state byte rawImm width memWidth).flags.cf =
      (x86MemImulStepSpec state byte rawImm width memWidth).flags.of := by
  rfl

/-- The writeback scalarizes the destination's provenance regardless of the
incoming tag. -/
theorem x86_mem_imul_tag_scalar (state : X86RegAluState)
    (byte : Nat -> X86MemByte) (rawImm : BitVec 64)
    (width memWidth : X86Width) :
    (x86MemImulStepSpec state byte rawImm width memWidth).dst.tag = .scalar := by
  rfl

/-- The memory read is confined to the operand width: two byte functions that
agree below `memWidth`'s byte count yield the same handler state. This is the
architectural property that lets a narrow `IMUL [mem8], imm` ignore the
neighbouring memory the wider destination width would otherwise have consumed. -/
theorem x86_mem_imul_bytes_congruent (state : X86RegAluState)
    (left right : Nat -> X86MemByte) (rawImm : BitVec 64)
    (width memWidth : X86Width)
    (h : ∀ i, i < x86WidthBitsSpec memWidth / 8 -> left i = right i) :
    x86MemImulStepSpec state left rawImm width memWidth =
      x86MemImulStepSpec state right rawImm width memWidth := by
  have hload : x86MemLoadSpec left memWidth = x86MemLoadSpec right memWidth := by
    cases memWidth
    · simp only [x86MemLoadSpec, x86MemAssembleSpec, x86WidthMaskSpec,
        x86WidthBitsSpec, h 0 (by decide)]
    · simp only [x86MemLoadSpec, x86MemAssembleSpec, x86WidthMaskSpec,
        x86WidthBitsSpec, h 0 (by decide), h 1 (by decide)]
    · simp only [x86MemLoadSpec, x86MemAssembleSpec, x86WidthMaskSpec,
        x86WidthBitsSpec, h 0 (by decide), h 1 (by decide), h 2 (by decide),
        h 3 (by decide)]
    · simp only [x86MemLoadSpec, x86MemAssembleSpec, x86WidthMaskSpec,
        x86WidthBitsSpec, h 0 (by decide), h 1 (by decide), h 2 (by decide),
        h 3 (by decide), h 4 (by decide), h 5 (by decide), h 6 (by decide),
        h 7 (by decide)]
  simp only [x86MemImulStepSpec, hload]

/-- For the narrow operand widths the arithmetic-immediate rule reaches the same
signed immediate as reading the low `width` bits directly, because the
sign-extension source is masked to the width before extension. The 64-bit case
differs and sign-extends bit 31 instead. -/
theorem x86_mem_imul_rhs_narrow_reads_low_bits (raw : BitVec 64) :
    x86SignExtendSpec (x86ImmediateValueSpec raw .w8) .w8 =
        x86SignExtendSpec raw .w8 ∧
      x86SignExtendSpec (x86ImmediateValueSpec raw .w16) .w16 =
        x86SignExtendSpec raw .w16 ∧
      x86SignExtendSpec (x86ImmediateValueSpec raw .w32) .w32 =
        x86SignExtendSpec raw .w32 := by
  refine ⟨?_, ?_, ?_⟩ <;>
    simp only [x86SignExtendSpec, x86ImmediateValueSpec] <;> bv_decide

/-- A 16-bit `IMUL` reads `0x7fff` from memory and multiplies it by the
immediate two: the width-narrowed signed product overflows, so CF and OF are
set together, the low 16 bits `0xfffe` are written back, and the incoming
ZF/SF survive. -/
theorem x86_mem_imul_w16_overflow_example :
    generatedX86MemImulStep
      { dst := { bits := 0x0000000000007fff, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } }
      (fun i => if i = 0 then 0xff else if i = 1 then 0x7f else 0xa5)
      2 .w16 .w16 =
      { dst := { bits := 0x000000000000fffe, tag := .scalar },
        flags := { cf := true, zf := false, sf := false, of := true } } := by
  decide

/-- An 8-bit memory operand inside a 64-bit `IMUL` is sign-extended before the
multiply: the loaded `0xff` becomes all ones, so the product is `-3` and the
full 64-bit destination receives `0xfffffffffffffffd`. The *flags* still see the
raw loaded byte, whose 64-bit signed product with three fits, so no overflow is
reported. -/
theorem x86_mem_imul_narrow_mem_sign_extends_example :
    generatedX86MemImulStep
      { dst := { bits := 0xffffffffffffffff, tag := .packet },
        flags := { cf := true, zf := true, sf := true, of := true } }
      (fun i => if i = 0 then 0xff else 0xa5)
      3 .w64 .w8 =
      { dst := { bits := 0xfffffffffffffffd, tag := .scalar },
        flags := { cf := false, zf := true, sf := true, of := false } } := by
  decide

/-- An 8-bit `IMUL` whose operands have opposite signs gets one extra bit of
headroom: `-128 * 2` still overflows the 8-bit signed range, so CF/OF are set
and the low byte of the destination is cleared while its upper seven bytes
survive. -/
theorem x86_mem_imul_w8_mixed_sign_overflow_example :
    generatedX86MemImulStep
      { dst := { bits := 0x1122334455660000, tag := .mapValue },
        flags := { cf := false, zf := true, sf := true, of := false } }
      (fun i => if i = 0 then 0x80 else 0xa5)
      2 .w8 .w8 =
      { dst := { bits := 0x1122334455660000, tag := .scalar },
        flags := { cf := true, zf := true, sf := true, of := true } } := by
  decide

/-- An in-range 8-bit `IMUL` with an all-zero flag word stays entirely clear and
merges the product into the destination's low byte. -/
theorem x86_mem_imul_w8_in_range_example :
    generatedX86MemImulStep
      { dst := { bits := 0x1122334455660000, tag := .mapValue },
        flags := { cf := false, zf := false, sf := false, of := false } }
      (fun i => if i = 0 then 0x10 else 0xa5)
      2 .w8 .w8 =
      { dst := { bits := 0x1122334455660020, tag := .scalar },
        flags := { cf := false, zf := false, sf := false, of := false } } := by
  decide

end KProgFormal
