import KProgFormal.GeneratedArm64CcmpDecode
import KProgFormal.GeneratedArm64Aux
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Aux (pack b0 b1 regNone)
open KProgFormal.GeneratedArm64CcmpDecode

/-- Independent statement of the two CCMP byte selectors, written as direct
`setWidth`-truncations of the packed word rather than the generated
shift-and-mask: the condition byte is bits 0-7, the NZCV fallback byte bits
8-15. -/
def arm64CcmpDecodeSpec (aux : BitVec 32) : BitVec 8 × BitVec 8 :=
  (aux.setWidth 8, (aux >>> 8).setWidth 8)

/-- The generated condition selector equals the independent byte extraction:
`(aux >>> 0) & 0xff` is the low byte for every packed word. -/
theorem arm64_ccmp_decode_cond_refines (aux : BitVec 32) :
    ((ccmpCond aux).setWidth 8) = (arm64CcmpDecodeSpec aux).1 := by
  unfold ccmpCond arm64CcmpDecodeSpec
  bv_decide

/-- The generated NZCV selector equals the independent byte extraction:
`(aux >>> 8) & 0xff`, so the condition byte cannot lean into it. -/
theorem arm64_ccmp_decode_nzcv_refines (aux : BitVec 32) :
    ((ccmpNzcv aux).setWidth 8) = (arm64CcmpDecodeSpec aux).2 := by
  unfold ccmpNzcv arm64CcmpDecodeSpec
  bv_decide

/-- Packing two bytes with the CCMP packer and decoding both lanes back
re-derives them exactly, so the packer and the selectors agree bit for bit. -/
theorem arm64_ccmp_decode_pack_roundtrip (cond nzcv : BitVec 32) :
    ccmpCond (pack cond nzcv 0 0) = BitVec.and cond 0xff ∧
      ccmpNzcv (pack cond nzcv 0 0) = BitVec.and nzcv 0xff := by
  unfold pack ccmpCond ccmpNzcv
  bv_decide

/-- The CCMP condition byte is the shared AUX lane 0 byte (`b0`), and the CCMP
NZCV byte is the shared AUX lane 1 byte (`b1`) that `simCcmpNzcv` and the
modifier/LSB lanes also name: the CCMP selectors decode the same two lanes the
rest of the simulator uses, not a private layout. -/
theorem arm64_ccmp_decode_lanes (aux : BitVec 32) :
    ccmpCond aux = b0 aux ∧ ccmpNzcv aux = b1 aux := by
  unfold ccmpCond ccmpNzcv b0 b1
  bv_decide

/-- The decoder is unaffected by noise in the two unused lanes: a CCMP operand
packed with lane-2/3 garbage decodes to the same condition and NZCV bytes as
the same operand packed with zero lanes. -/
theorem arm64_ccmp_decode_noise_free (cond nzcv shift flags : BitVec 32) :
    ccmpCond (pack cond nzcv shift flags) = ccmpCond (pack cond nzcv 0 0) ∧
      ccmpNzcv (pack cond nzcv shift flags) = ccmpNzcv (pack cond nzcv 0 0) := by
  unfold pack ccmpCond ccmpNzcv
  bv_decide

/-- The low four bits of the condition byte are the condition selector the
handler evaluates: they survive both truncation steps unchanged. -/
theorem arm64_ccmp_decode_cond_low_bits (cond nzcv : BitVec 32) :
    (BitVec.and (ccmpCond (pack cond nzcv 0 0)) 0xf) =
      BitVec.and cond 0xf := by
  unfold pack ccmpCond
  bv_decide

/-- The NZCV fallback byte feeds the handler's bit 3..0 extraction
(`arm64CcmpFallbackSpec`), so the byte the packer stores in lane 1 is the byte
the fallback reads: shown by concrete roundtrips on packer outputs. -/
example :
    ccmpNzcv (pack 0 0x96 0 0) = 0x96 ∧ ccmpCond (pack 0x0d 0 0 0) = 0x0d := by
  native_decide

end KProgFormal
