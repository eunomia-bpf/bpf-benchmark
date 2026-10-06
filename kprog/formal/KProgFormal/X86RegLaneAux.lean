import KProgFormal.GeneratedX86RegLaneAux
import KProgFormal.X86RegWrite

namespace KProgFormal

open GeneratedX86RegLaneAux (pack)

/-- Independent statement of the x86 register-lane AUX layout, written as an
explicit little-endian byte concatenation rather than the generated masked-or
expression: the payload (ALU code or source byte) occupies bits 0-7, the
destination byte lane bits 8-15, and the source byte lane bits 16-23, with the
top byte unused. -/
def x86RegLaneAuxSpec (payloadByte dstShift srcShift : BitVec 32) : BitVec 32 :=
  0#8 ++ srcShift.setWidth 8 ++ dstShift.setWidth 8 ++ payloadByte.setWidth 8

/-- The generated C-shaped packer equals the independent byte concatenation for
all three field values. -/
theorem x86_reg_lane_aux_pack_refines (payloadByte dstShift srcShift :
    BitVec 32) :
    pack payloadByte dstShift srcShift =
      x86RegLaneAuxSpec payloadByte dstShift srcShift := by
  unfold pack x86RegLaneAuxSpec
  bv_decide

/-- The payload decoder recovers the low byte regardless of the two lane
bytes. -/
theorem x86_reg_lane_aux_payload_roundtrip (payload dstShift srcShift : BitVec 32) :
    GeneratedX86RegLaneAux.payload (pack payload dstShift srcShift) =
      BitVec.and payload 0xff := by
  unfold pack GeneratedX86RegLaneAux.payload
  bv_decide

/-- The destination-lane decoder recovers the byte at bits 8-15 regardless of
the payload and source lane. -/
theorem x86_reg_lane_aux_dst_roundtrip (payload dstShift srcShift : BitVec 32) :
    GeneratedX86RegLaneAux.dstShift (pack payload dstShift srcShift) =
      BitVec.and dstShift 0xff := by
  unfold pack GeneratedX86RegLaneAux.dstShift
  bv_decide

/-- The source-lane decoder recovers the byte at bits 16-23 regardless of the
payload and destination lane. -/
theorem x86_reg_lane_aux_src_roundtrip (payload dstShift srcShift : BitVec 32) :
    GeneratedX86RegLaneAux.srcShift (pack payload dstShift srcShift) =
      BitVec.and srcShift 0xff := by
  unfold pack GeneratedX86RegLaneAux.srcShift
  bv_decide

/-- The three fields are pairwise non-interfering: each decoder's result is a
function of its own argument only, so no field's byte overwrites another's. -/
theorem x86_reg_lane_aux_fields_non_interfering
    (payload dstShift srcShift : BitVec 32) :
    GeneratedX86RegLaneAux.payload (pack payload dstShift srcShift) =
        BitVec.and payload 0xff ∧
      GeneratedX86RegLaneAux.dstShift (pack payload dstShift srcShift) =
        BitVec.and dstShift 0xff ∧
      GeneratedX86RegLaneAux.srcShift (pack payload dstShift srcShift) =
        BitVec.and srcShift 0xff := by
  refine ⟨?_, ?_, ?_⟩
  · unfold pack GeneratedX86RegLaneAux.payload; bv_decide
  · unfold pack GeneratedX86RegLaneAux.dstShift; bv_decide
  · unfold pack GeneratedX86RegLaneAux.srcShift; bv_decide

/-- Canonical layout example: a payload byte `2` with destination lane `8` and
source lane `0` packs to `0x0802`, pinning the byte order against a concrete
value. -/
theorem x86_reg_lane_aux_example : pack 2 8 0 = 0x0802 := by
  decide

/-- Typed-lane roundtrip: for the two valid byte lanes, packing their concrete
byte shifts and decoding them back recovers the shifts. -/
theorem x86_reg_lane_aux_typed_lanes_roundtrip (payload : BitVec 32)
    (dst src : X86ByteLane) :
    let aux := pack payload
      (BitVec.ofNat 32 (x86ByteShiftSpec dst))
      (BitVec.ofNat 32 (x86ByteShiftSpec src))
    GeneratedX86RegLaneAux.dstShift aux =
        BitVec.ofNat 32 (x86ByteShiftSpec dst) /\
      GeneratedX86RegLaneAux.srcShift aux =
        BitVec.ofNat 32 (x86ByteShiftSpec src) := by
  cases dst <;> cases src <;>
    simp [pack, GeneratedX86RegLaneAux.dstShift, GeneratedX86RegLaneAux.srcShift,
      x86ByteShiftSpec] <;> bv_decide

end KProgFormal
