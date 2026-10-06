import KProgFormal.X86RegWrite
import KProgFormal.X86Signed
import Std.Tactic.BVDecide

namespace KProgFormal

/-- Destination register state of the x86 zero-extending and sign-extending
register MOV handlers (`X86_SIM_L_EXEC_MOVX_REG`, the single body shared by
`X86_OP_MOVZX_REG` and `X86_OP_MOVSX_REG`). Those opcodes define no flags, so
only the destination register is written. -/
structure X86MovxState where
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- The two opcodes the shared register-source narrow/wide MOV body implements.
`movzx` zero-extends the source lane, `movsx` sign-extends it; `cdqe` and
`movsxd` both decode to `movsx` with a primary-width destination and a 32-bit
source width. -/
inductive X86MovxOp
  | movzx
  | movsx
  deriving DecidableEq, Repr

/-- Composition used by the x86 register-source MOVZX/MOVSX handler after the
opcode, the source register's raw 64-bit value, and the two width codes have
been decoded. The simulator reads the source with `X86_SIM_L_READ_REG`, i.e. the
full 64-bit register with no byte lane, then narrows (`movzx`) or sign-extends
(`movsx`) it at the *source* width; the *destination* width — `FLAGS` with the
64-bit fallback — confines the writeback, whose lane shift is zero. -/
def generatedX86MovxRegStep (state : X86MovxState) (src : BitVec 64)
    (op : X86MovxOp) (srcWidth dstWidth : X86Width) : X86MovxState :=
  let widened :=
    match op with
    | .movzx => GeneratedX86Width.narrow src srcWidth
    | .movsx => GeneratedX86Signed.signExtend src srcWidth
  { dst := generatedX86RegWrite state.dst widened dstWidth }

/-- Independent statement of the same handler: the two opcodes differ only in
whether the source lane is zero-extended or sign-extended, and the widened value
then goes through the plain partial-register writeback at the destination
width. -/
def x86MovxRegStepSpec (state : X86MovxState) (src : BitVec 64)
    (op : X86MovxOp) (srcWidth dstWidth : X86Width) : X86MovxState :=
  let widened :=
    match op with
    | .movzx => x86NarrowSpec src srcWidth
    | .movsx => x86SignExtendSpec src srcWidth
  { dst := x86RegWriteSpec state.dst widened dstWidth }

/-- The register-source MOVZX/MOVSX handler composition refines the independent
narrow/sign-extend/writeback statement for arbitrary destination state, raw
source register value, opcode, source width, and destination width. -/
theorem x86_movx_reg_step_refines (state : X86MovxState) (src : BitVec 64)
    (op : X86MovxOp) (srcWidth dstWidth : X86Width) :
    generatedX86MovxRegStep state src op srcWidth dstWidth =
      x86MovxRegStepSpec state src op srcWidth dstWidth := by
  cases op <;>
    simp only [generatedX86MovxRegStep, x86MovxRegStepSpec,
      x86_narrow_refines, x86_sign_extend_refines, x86_reg_write_refines]

/-- The zero-extending arm is exactly the width narrowing followed by the
writeback: MOVZX never consults the sign bit of the source lane. -/
theorem x86_movzx_is_narrow (state : X86MovxState) (src : BitVec 64)
    (srcWidth dstWidth : X86Width) :
    x86MovxRegStepSpec state src .movzx srcWidth dstWidth =
      { dst := x86RegWriteSpec state.dst
          (x86NarrowSpec src srcWidth) dstWidth } := by
  rfl

/-- The sign-extending arm is exactly the generated sign extension followed by
the writeback, so `cdqe` and `movsxd` are the `srcWidth = .w32` instance — with
`dstWidth = .w64` for `cdqe`, and with the narrower destination widths that
`movsx r16/r32, r/m8` encodes. -/
theorem x86_movsx_is_sign_extend (state : X86MovxState) (src : BitVec 64)
    (srcWidth dstWidth : X86Width) :
    x86MovxRegStepSpec state src .movsx srcWidth dstWidth =
      { dst := x86RegWriteSpec state.dst
          (x86SignExtendSpec src srcWidth) dstWidth } := by
  rfl

/-- `cdqe` is the `movsx` arm at a 32-bit source width and a 64-bit destination
width: the low 32 bits of RAX are sign-extended across the whole register. This
is the decoding the micro-program generator emits for the bare `cdqe` opcode
(`X86_OP_MOVSX_REG` with `flags = X86_WIDTH_64`, `aux = X86_WIDTH_32`). -/
theorem x86_cdqe_is_movsx_w32_w64 (state : X86MovxState) (src : BitVec 64) :
    x86MovxRegStepSpec state src .movsx .w32 .w64 =
      { dst := { bits := x86SignExtendSpec src .w32, tag := .scalar } } := by
  rfl

/-- Narrowing is idempotent, so a MOVZX whose source and destination widths
coincide re-narrows an already-narrow value without changing it: the case that
would otherwise be a silent double truncation is the identity. -/
theorem x86_movzx_same_width_idempotent (src : BitVec 64) (width : X86Width) :
    x86NarrowSpec (x86NarrowSpec src width) width = x86NarrowSpec src width := by
  cases width <;>
    simp only [x86NarrowSpec, x86WidthMaskSpec] <;> bv_decide

/-- A MOVZX from a width no wider than the destination width leaves the widened
value equal to the source's narrowed lane, so no information above the source
lane reaches the destination. -/
theorem x86_movzx_ignores_upper_source_bits (src src' : BitVec 64)
    (width : X86Width)
    (sameLane : x86NarrowSpec src width = x86NarrowSpec src' width) :
    x86MovxRegStepSpec { dst := { bits := 0, tag := .scalar } } src
        .movzx width width =
      x86MovxRegStepSpec { dst := { bits := 0, tag := .scalar } } src'
        .movzx width width := by
  simp only [x86MovxRegStepSpec, x86RegWriteSpec]
  rw [sameLane]

/-- Every MOVZX/MOVSX writeback scalarizes the destination's provenance,
regardless of the incoming tag: the family never produces a pointer. -/
theorem x86_movx_reg_tag_scalar (state : X86MovxState) (src : BitVec 64)
    (op : X86MovxOp) (srcWidth dstWidth : X86Width) :
    (x86MovxRegStepSpec state src op srcWidth dstWidth).dst.tag = .scalar := by
  cases op <;> rfl

/-- A sub-64-bit MOVZX/MOVSX preserves the destination's bytes above the
destination width, because the writeback is a partial-register write. -/
theorem x86_movx_reg_narrow_preserves_upper (state : X86MovxState)
    (src : BitVec 64) (op : X86MovxOp) (srcWidth : X86Width) :
    BitVec.and
        (x86MovxRegStepSpec state src op srcWidth .w16).dst.bits
        0xffffffffffff0000 =
      BitVec.and state.dst.bits 0xffffffffffff0000 := by
  cases state with
  | mk dst =>
      cases dst with
      | mk oldBits oldTag =>
          cases op <;>
            cases srcWidth <;>
              simp only [x86MovxRegStepSpec, x86RegWriteSpec,
                x86RegWriteBitsSpec, x86NarrowSpec, x86SignExtendSpec,
                x86WidthMaskSpec] <;>
              bv_decide

/-- Canonical example: `cdqe` sign-extends a negative 32-bit RAX value across
the full 64-bit register (source and destination are the same register, so the
incoming value is the low half). -/
theorem x86_cdqe_example :
    generatedX86MovxRegStep
      { dst := { bits := 0x1122334480000001, tag := .mapValue } }
      0x1122334480000001 .movsx .w32 .w64 =
      { dst := { bits := 0xffffffff80000001, tag := .scalar } } := by
  decide

/-- Canonical example: `movsxd rax, eax` of a positive 32-bit value leaves the
upper half zero and scalarizes the provenance. -/
theorem x86_movsxd_positive_example :
    generatedX86MovxRegStep
      { dst := { bits := 0xffffffffffffffff, tag := .packet } }
      0x000000007fffffff .movsx .w32 .w64 =
      { dst := { bits := 0x000000007fffffff, tag := .scalar } } := by
  decide

/-- Canonical example: a `movzx r32, r8`-shaped zero extension of the low byte
`0xff` yields `0x000000ff` and discards the source's upper bits. -/
theorem x86_movzx_w8_w32_example :
    generatedX86MovxRegStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .stack } }
      0x11223344556688ff .movzx .w8 .w32 =
      { dst := { bits := 0x00000000000000ff, tag := .scalar } } := by
  decide

/-- Canonical example: `movsx r32, r8` of the low byte `0x80` produces the
sign-extended `-128`, because the source width — not the destination width —
selects the sign bit. -/
theorem x86_movsx_w8_w32_example :
    generatedX86MovxRegStep
      { dst := { bits := 0xffffffffffffffff, tag := .scalar } }
      0x0000000000000080 .movsx .w8 .w32 =
      { dst := { bits := 0x00000000ffffff80, tag := .scalar } } := by
  decide

/-- Canonical example: a 16-bit MOVZX whose source and destination widths agree
merges the narrowed source into the destination's low half and keeps the
destination's six upper bytes, unlike the 32-bit form that zeroes them. -/
theorem x86_movzx_w16_identity_example :
    generatedX86MovxRegStep
      { dst := { bits := 0xdeadbeefdead0000, tag := .stack } }
      0xffffffffffffaa88 .movzx .w16 .w16 =
      { dst := { bits := 0xdeadbeefdeadaa88, tag := .scalar } } := by
  decide

end KProgFormal
