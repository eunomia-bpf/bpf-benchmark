import KProgFormal.GeneratedX86RegLaneAux
import KProgFormal.X86RegWrite

namespace KProgFormal

theorem x86_reg_lane_aux_payload_roundtrip (payload dstShift srcShift : BitVec 32) :
    GeneratedX86RegLaneAux.payload
      (GeneratedX86RegLaneAux.pack payload dstShift srcShift) =
      BitVec.and payload 0xff := by
  simp [GeneratedX86RegLaneAux.payload, GeneratedX86RegLaneAux.pack]
  bv_decide

theorem x86_reg_lane_aux_dst_roundtrip (payload dstShift srcShift : BitVec 32) :
    GeneratedX86RegLaneAux.dstShift
      (GeneratedX86RegLaneAux.pack payload dstShift srcShift) =
      BitVec.and dstShift 0xff := by
  simp [GeneratedX86RegLaneAux.dstShift, GeneratedX86RegLaneAux.pack]
  bv_decide

theorem x86_reg_lane_aux_src_roundtrip (payload dstShift srcShift : BitVec 32) :
    GeneratedX86RegLaneAux.srcShift
      (GeneratedX86RegLaneAux.pack payload dstShift srcShift) =
      BitVec.and srcShift 0xff := by
  simp [GeneratedX86RegLaneAux.srcShift, GeneratedX86RegLaneAux.pack]
  bv_decide

theorem x86_reg_lane_aux_typed_lanes_roundtrip (payload : BitVec 32)
    (dst src : X86ByteLane) :
    let aux := GeneratedX86RegLaneAux.pack payload
      (BitVec.ofNat 32 (x86ByteShiftSpec dst))
      (BitVec.ofNat 32 (x86ByteShiftSpec src))
    GeneratedX86RegLaneAux.dstShift aux =
        BitVec.ofNat 32 (x86ByteShiftSpec dst) /\
      GeneratedX86RegLaneAux.srcShift aux =
        BitVec.ofNat 32 (x86ByteShiftSpec src) := by
  cases dst <;> cases src <;>
    simp [GeneratedX86RegLaneAux.pack, GeneratedX86RegLaneAux.dstShift,
      GeneratedX86RegLaneAux.srcShift, x86ByteShiftSpec] <;> bv_decide

end KProgFormal
