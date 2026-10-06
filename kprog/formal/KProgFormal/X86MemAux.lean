import KProgFormal.GeneratedX86MemAux
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86MemAux (pack index scaleLog2 memWidth op indexNone)

/-- Independent statement of the packed x86 AUX layout, written as an explicit
little-endian byte concatenation rather than the generated masked-or
expression: each field dominates only its own byte, the opcode/tag byte is most
significant, then the memory width, then the scale exponent, then the index
register byte least significant, so field `k` occupies bits `8k`-`8k+7`. -/
def x86MemAuxSpec (indexReg scaleExp memWidthCode opTag : BitVec 32) :
    BitVec 32 :=
  opTag.setWidth 8 ++ memWidthCode.setWidth 8 ++
    scaleExp.setWidth 8 ++ indexReg.setWidth 8

/-- The generated C-shaped packer equals the independent byte concatenation for
all four field values: a masked-or of shifted bytes and a little-endian
concatenation of each field's low byte produce the same 32-bit word. -/
theorem x86_mem_aux_pack_refines (indexReg scaleExp memWidthCode opTag :
    BitVec 32) :
    pack indexReg scaleExp memWidthCode opTag =
      x86MemAuxSpec indexReg scaleExp memWidthCode opTag := by
  unfold pack x86MemAuxSpec
  bv_decide

/-- The index decoder recovers the low byte: the index field's roundtrip, and
the fact that it depends only on the index argument (no other field bleeds into
bits 0-7). -/
theorem x86_mem_aux_index_roundtrip (indexReg scaleExp memWidthCode opTag :
    BitVec 32) :
    index (pack indexReg scaleExp memWidthCode opTag) =
      BitVec.and indexReg 0xff := by
  unfold pack index
  bv_decide

/-- The scale-exponent decoder recovers the byte at bits 8-15 regardless of the
other three fields. -/
theorem x86_mem_aux_scale_roundtrip (indexReg scaleExp memWidthCode opTag :
    BitVec 32) :
    scaleLog2 (pack indexReg scaleExp memWidthCode opTag) =
      BitVec.and scaleExp 0xff := by
  unfold pack scaleLog2
  bv_decide

/-- The memory-width decoder recovers the byte at bits 16-23 regardless of the
other three fields. -/
theorem x86_mem_aux_mem_width_roundtrip (indexReg scaleExp memWidthCode opTag :
    BitVec 32) :
    memWidth (pack indexReg scaleExp memWidthCode opTag) =
      BitVec.and memWidthCode 0xff := by
  unfold pack memWidth
  bv_decide

/-- The opcode/tag decoder recovers the high byte at bits 24-31 regardless of
the other three fields. -/
theorem x86_mem_aux_op_roundtrip (indexReg scaleExp memWidthCode opTag :
    BitVec 32) :
    op (pack indexReg scaleExp memWidthCode opTag) =
      BitVec.and opTag 0xff := by
  unfold pack op
  bv_decide

/-- The four fields are pairwise non-interfering: each decoder's result is a
function of its own argument only, so no field's byte overwrites another's.
This is the conjunction of the four roundtrips stated as independence. -/
theorem x86_mem_aux_fields_non_interfering
    (indexReg scaleExp memWidthCode opTag : BitVec 32) :
    index (pack indexReg scaleExp memWidthCode opTag) =
        BitVec.and indexReg 0xff ∧
      scaleLog2 (pack indexReg scaleExp memWidthCode opTag) =
        BitVec.and scaleExp 0xff ∧
      memWidth (pack indexReg scaleExp memWidthCode opTag) =
        BitVec.and memWidthCode 0xff ∧
      op (pack indexReg scaleExp memWidthCode opTag) =
        BitVec.and opTag 0xff := by
  refine ⟨?_, ?_, ?_, ?_⟩
  · unfold pack index; bv_decide
  · unfold pack scaleLog2; bv_decide
  · unfold pack memWidth; bv_decide
  · unfold pack op; bv_decide

/-- The `X86_REG_NONE` sentinel survives a pack/unpack cycle: an addressing
mode with no index register packs its `0xff` index byte and the index decoder
reads `0xff` back, at any scale, width, and opcode byte. -/
theorem x86_mem_aux_index_none_roundtrip (scaleExp memWidthCode opTag :
    BitVec 32) :
    index (pack indexNone scaleExp memWidthCode opTag) = indexNone := by
  unfold pack index indexNone
  bv_decide

/-- The sentinel is the all-ones byte, pinned so the C `X86_REG_NONE` value and
the generated `indexNone` cannot drift apart. -/
theorem x86_mem_aux_index_none_is_0xff : indexNone = 0xff := rfl

/-- Canonical layout example: index `1`, scale exponent `2`, memory-width code
`3`, opcode byte `4` pack to the little-endian word `0x04030201`, pinning the
byte order against a concrete value. -/
theorem x86_mem_aux_example :
    pack 1 2 3 4 = 0x04030201 := by
  decide

/-- Canonical example: the memory-width field carries a register source byte
lane (`8`) in bits 16-23 while the source-shift byte lives in bits 24-31, so a
store AUX of `X86_MEM_AUX(dst, scale) | X86_REG_AUX_SRC_SHIFT(8)` decodes back
to lane 8 and shift byte 8. -/
theorem x86_mem_aux_src_lane_example :
    memWidth (pack 0 0 8 8) = 8 ∧ op (pack 0 0 8 8) = 8 := by
  decide

end KProgFormal
