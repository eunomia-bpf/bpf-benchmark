import KProgFormal.GeneratedX86ShiftResult
import KProgFormal.X86ShiftCount

namespace KProgFormal

private def narrow8 (value : BitVec 64) : BitVec 8 := value.setWidth 8
private def narrow16 (value : BitVec 64) : BitVec 16 := value.setWidth 16
private def narrow32 (value : BitVec 64) : BitVec 32 := value.setWidth 32

def x86ShlResultSpec (value rhs : BitVec 64) : X86Width -> BitVec 64
  | .w8 => ((narrow8 value) <<< GeneratedX86ShiftCount.count rhs .w8).setWidth 64
  | .w16 => ((narrow16 value) <<< GeneratedX86ShiftCount.count rhs .w16).setWidth 64
  | .w32 => ((narrow32 value) <<< GeneratedX86ShiftCount.count rhs .w32).setWidth 64
  | .w64 => value <<< GeneratedX86ShiftCount.count rhs .w64

def x86ShrResultSpec (value rhs : BitVec 64) : X86Width -> BitVec 64
  | .w8 => ((narrow8 value) >>> GeneratedX86ShiftCount.count rhs .w8).setWidth 64
  | .w16 => ((narrow16 value) >>> GeneratedX86ShiftCount.count rhs .w16).setWidth 64
  | .w32 => ((narrow32 value) >>> GeneratedX86ShiftCount.count rhs .w32).setWidth 64
  | .w64 => value >>> GeneratedX86ShiftCount.count rhs .w64

def x86SarResultSpec (value rhs : BitVec 64) : X86Width -> BitVec 64
  | .w8 => ((narrow8 value).sshiftRight' (GeneratedX86ShiftCount.count rhs .w8)).setWidth 64
  | .w16 => ((narrow16 value).sshiftRight' (GeneratedX86ShiftCount.count rhs .w16)).setWidth 64
  | .w32 => ((narrow32 value).sshiftRight' (GeneratedX86ShiftCount.count rhs .w32)).setWidth 64
  | .w64 => value.sshiftRight' (GeneratedX86ShiftCount.count rhs .w64)

private def rol8 (value : BitVec 8) (count : BitVec 64) : BitVec 8 :=
  if count = 0 then value else value <<< count ||| value >>> ((8 : BitVec 64) - count)
private def rol16 (value : BitVec 16) (count : BitVec 64) : BitVec 16 :=
  if count = 0 then value else value <<< count ||| value >>> ((16 : BitVec 64) - count)
private def rol32 (value : BitVec 32) (count : BitVec 64) : BitVec 32 :=
  if count = 0 then value else value <<< count ||| value >>> ((32 : BitVec 64) - count)
private def rol64 (value : BitVec 64) (count : BitVec 64) : BitVec 64 :=
  if count = 0 then value else value <<< count ||| value >>> ((64 : BitVec 64) - count)

def x86RolResultSpec (value rhs : BitVec 64) : X86Width -> BitVec 64
  | .w8 => (rol8 (narrow8 value)
      (BitVec.and (GeneratedX86ShiftCount.count rhs .w8) 7)).setWidth 64
  | .w16 => (rol16 (narrow16 value)
      (BitVec.and (GeneratedX86ShiftCount.count rhs .w16) 15)).setWidth 64
  | .w32 => (rol32 (narrow32 value)
      (BitVec.and (GeneratedX86ShiftCount.count rhs .w32) 31)).setWidth 64
  | .w64 => rol64 value
      (BitVec.and (GeneratedX86ShiftCount.count rhs .w64) 63)

theorem x86_shl_result_refines (value rhs : BitVec 64) (width : X86Width) :
    GeneratedX86ShiftResult.shl value rhs width =
      x86ShlResultSpec value rhs width := by
  cases width <;> simp only [GeneratedX86ShiftResult.shl,
    GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask,
    GeneratedX86Width.narrow, GeneratedX86Width.mask, x86ShlResultSpec,
    narrow8, narrow16, narrow32] <;> bv_decide

theorem x86_shr_result_refines (value rhs : BitVec 64) (width : X86Width) :
    GeneratedX86ShiftResult.shr value rhs width =
      x86ShrResultSpec value rhs width := by
  cases width <;> simp only [GeneratedX86ShiftResult.shr,
    GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask,
    GeneratedX86Width.narrow, GeneratedX86Width.mask, x86ShrResultSpec,
    narrow8, narrow16, narrow32] <;> bv_decide

theorem x86_sar_result_refines (value rhs : BitVec 64) (width : X86Width) :
    GeneratedX86ShiftResult.sar value rhs width =
      x86SarResultSpec value rhs width := by
  cases width <;> simp only [GeneratedX86ShiftResult.sar,
    GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask,
    GeneratedX86Width.narrow, GeneratedX86Width.mask,
    GeneratedX86Width.signMask, x86SarResultSpec,
    narrow8, narrow16, narrow32] <;> bv_decide

theorem x86_rol_result_refines (value rhs : BitVec 64) (width : X86Width) :
    GeneratedX86ShiftResult.rol value rhs width =
      x86RolResultSpec value rhs width := by
  cases width <;> simp only [GeneratedX86ShiftResult.rol,
    GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask,
    GeneratedX86Width.narrow, GeneratedX86Width.mask,
    GeneratedX86Width.bits, x86RolResultSpec,
    narrow8, narrow16, narrow32, rol8, rol16, rol32, rol64] <;> bv_decide

/-- Independent statement of the x86 ROR result: rotating right by `k` is
rotating left by the complementary count `bits - k`, so the spec reaches the
result *through the already-generated `rol`* rather than mirroring its shift
pair. This is the property an x86 right-rotate has that a plain mirrored
implementation does not state. -/
def x86RorResultSpec (value rhs : BitVec 64) : X86Width -> BitVec 64
  | .w8 => GeneratedX86ShiftResult.rol value
      ((8 : BitVec 64) - GeneratedX86ShiftCount.count rhs .w8) .w8
  | .w16 => GeneratedX86ShiftResult.rol value
      ((16 : BitVec 64) - GeneratedX86ShiftCount.count rhs .w16) .w16
  | .w32 => GeneratedX86ShiftResult.rol value
      ((32 : BitVec 64) - GeneratedX86ShiftCount.count rhs .w32) .w32
  | .w64 => GeneratedX86ShiftResult.rol value
      ((64 : BitVec 64) - GeneratedX86ShiftCount.count rhs .w64) .w64

/-- The generated ROR equals the independent complementary-count form for all
four widths. -/
theorem x86_ror_result_refines (value rhs : BitVec 64) (width : X86Width) :
    GeneratedX86ShiftResult.ror value rhs width =
      x86RorResultSpec value rhs width := by
  cases width <;> simp only [GeneratedX86ShiftResult.ror,
    GeneratedX86ShiftResult.rol, GeneratedX86ShiftCount.count,
    GeneratedX86ShiftCount.mask, GeneratedX86Width.narrow,
    GeneratedX86Width.mask, GeneratedX86Width.bits, x86RorResultSpec] <;>
    bv_decide

/-- Canonical example: an 8-bit right rotate by one moves the low bit to the top
and the rest down. -/
theorem x86_ror_w8_example :
    GeneratedX86ShiftResult.ror 0x81 1 .w8 = 0xc0 := by native_decide

/-- Canonical example: a 32-bit right rotate by 8 rotates the byte order of the
low word and clears the high word. -/
theorem x86_ror_w32_example :
    GeneratedX86ShiftResult.ror 0x01020304 8 .w32 = 0x04010203 := by
  native_decide

/-- Canonical example: a 64-bit right rotate by 0 is the identity. -/
theorem x86_ror_w64_zero_example :
    GeneratedX86ShiftResult.ror 0x0123456789abcdef 0 .w64 =
      0x0123456789abcdef := by native_decide

theorem x86_shr_w8_discards_high_bits :
    GeneratedX86ShiftResult.shr 0x100 1 .w8 = 0 := by native_decide

theorem x86_shr_w32_discards_high_bits :
    GeneratedX86ShiftResult.shr 0x100000000 1 .w32 = 0 := by native_decide

theorem x86_sar_w8_sign_fills :
    GeneratedX86ShiftResult.sar 0x80 1 .w8 = 0xc0 := by native_decide

theorem x86_sar_w8_saturates :
    GeneratedX86ShiftResult.sar 0x80 8 .w8 = 0xff := by native_decide

end KProgFormal
