import KProgFormal.GeneratedX86RegRead
import KProgFormal.X86RegWrite

namespace KProgFormal

private def read8 (value : BitVec 64) (shift : Nat) : BitVec 64 :=
  ((value >>> shift).setWidth 8).setWidth 64

/-- Independent architectural operand observation. Byte reads select AL/AH
style lanes; wider register operands always observe their low width. -/
def x86RegReadAtSpec (value : BitVec 64) (width : X86Width)
    (lane : X86ByteLane) : BitVec 64 :=
  match width with
  | .w8 => read8 value (x86ByteShiftSpec lane)
  | .w16 => (value.setWidth 16).setWidth 64
  | .w32 => (value.setWidth 32).setWidth 64
  | .w64 => value

theorem x86_reg_read_at_refines (value : BitVec 64) (width : X86Width)
    (lane : X86ByteLane) :
    GeneratedX86RegRead.readAt value width lane =
      x86RegReadAtSpec value width lane := by
  cases width <;> cases lane <;>
    simp [GeneratedX86RegRead.readAt, x86RegReadAtSpec, read8,
      x86ByteShiftSpec] <;> bv_decide

theorem x86_reg_read_low8 (value : BitVec 64) :
    GeneratedX86RegRead.readAt value .w8 .low = BitVec.and value 0xff := by
  rfl

theorem x86_reg_read_high8 (value : BitVec 64) :
    GeneratedX86RegRead.readAt value .w8 .high =
      BitVec.and (value >>> 8) 0xff := by
  rfl

theorem x86_reg_read_high8_counterexample :
    GeneratedX86RegRead.readAt 0x112233445566aa88 .w8 .high = 0xaa := by
  native_decide

end KProgFormal
