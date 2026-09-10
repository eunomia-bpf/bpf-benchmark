import KProgFormal.GeneratedX86RegWrite
import KProgFormal.TagErasure
import KProgFormal.X86Width

namespace KProgFormal

structure X86RegValue where
  bits : BitVec 64
  tag : Tag
  deriving DecidableEq, Repr

abbrev X86ByteLane := GeneratedX86RegWrite.ByteLane

def x86ByteShiftSpec : X86ByteLane -> Nat
  | .low => 0
  | .high => 8

theorem x86_byte_shift_refines (lane : X86ByteLane) :
    GeneratedX86RegWrite.byteShift lane = x86ByteShiftSpec lane := by
  cases lane <;> rfl

/-- Independent architectural statement of an explicitly selected byte lane
or a wider register write. The lane is ignored for non-byte widths. -/
def x86RegWriteBitsAtSpec (old value : BitVec 64) (width : X86Width)
    (lane : X86ByteLane) : BitVec 64 :=
  match width with
  | .w8 =>
      let shift := x86ByteShiftSpec lane
      let mask := BitVec.shiftLeft (0xff : BitVec 64) shift
      BitVec.xor old (BitVec.and (BitVec.xor old
        (BitVec.shiftLeft (BitVec.and value 0xff) shift)) mask)
  | .w16 => BitVec.xor old (BitVec.and (BitVec.xor old value) 0xffff)
  | .w32 => BitVec.and value 0xffffffff
  | .w64 => value

/-- Independent architectural statement of low-lane partial-register
writeback. The 8- and 16-bit cases preserve the old upper bits, while 32-bit
writes zero the upper half and 64-bit writes replace the complete register. -/
def x86RegWriteBitsSpec (old value : BitVec 64) : X86Width -> BitVec 64
  | .w8 => BitVec.xor old (BitVec.and (BitVec.xor old value) 0xff)
  | .w16 => BitVec.xor old (BitVec.and (BitVec.xor old value) 0xffff)
  | .w32 => BitVec.and value 0xffffffff
  | .w64 => value

def generatedX86RegWriteAt (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) (lane : X86ByteLane) : X86RegValue :=
  let generated := GeneratedX86RegWrite.writeAt old.bits value width lane
  { bits := generated.bits
    tag := if generated.scalarizes then .scalar else old.tag }

def x86RegWriteAtSpec (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) (lane : X86ByteLane) : X86RegValue :=
  { bits := x86RegWriteBitsAtSpec old.bits value width lane, tag := .scalar }

theorem x86_reg_write_at_refines (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) (lane : X86ByteLane) :
    generatedX86RegWriteAt old value width lane =
      x86RegWriteAtSpec old value width lane := by
  cases old with
  | mk oldBits oldTag =>
      cases width <;> cases lane <;>
        simp [generatedX86RegWriteAt, GeneratedX86RegWrite.writeAt,
          GeneratedX86RegWrite.bitsAt, x86RegWriteAtSpec,
          x86RegWriteBitsAtSpec, x86ByteShiftSpec] <;> bv_decide

def generatedX86RegWrite (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) : X86RegValue :=
  let generated := GeneratedX86RegWrite.write old.bits value width
  { bits := generated.bits
    tag := if generated.scalarizes then .scalar else old.tag }

def x86RegWriteSpec (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) : X86RegValue :=
  { bits := x86RegWriteBitsSpec old.bits value width, tag := .scalar }

theorem x86_reg_write_low_compatible (old : X86RegValue)
    (value : BitVec 64) (width : X86Width) :
    generatedX86RegWriteAt old value width .low =
      generatedX86RegWrite old value width := by
  cases old
  cases width <;> rfl

theorem x86_reg_write_refines (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) :
    generatedX86RegWrite old value width = x86RegWriteSpec old value width := by
  cases old with
  | mk oldBits oldTag =>
      cases width <;>
        simp [generatedX86RegWrite, GeneratedX86RegWrite.write,
          GeneratedX86RegWrite.bits, x86RegWriteSpec,
          x86RegWriteBitsSpec] <;> bv_decide

theorem x86_reg_write8_preserves_upper (old : X86RegValue)
    (value : BitVec 64) :
    BitVec.and (generatedX86RegWrite old value .w8).bits 0xffffffffffffff00 =
      BitVec.and old.bits 0xffffffffffffff00 := by
  cases old
  simp [generatedX86RegWrite, GeneratedX86RegWrite.write,
    GeneratedX86RegWrite.bits]
  bv_decide

theorem x86_reg_write16_preserves_upper (old : X86RegValue)
    (value : BitVec 64) :
    BitVec.and (generatedX86RegWrite old value .w16).bits 0xffffffffffff0000 =
      BitVec.and old.bits 0xffffffffffff0000 := by
  cases old
  simp [generatedX86RegWrite, GeneratedX86RegWrite.write,
    GeneratedX86RegWrite.bits]
  bv_decide

theorem x86_reg_write_high8_updates_only_ah_lane (old : X86RegValue)
    (value : BitVec 64) :
    (generatedX86RegWriteAt old value .w8 .high).bits =
      BitVec.or (BitVec.and old.bits 0xffffffffffff00ff)
        (BitVec.shiftLeft (BitVec.and value 0xff) 8) := by
  cases old
  rfl

theorem x86_reg_write_high8_counterexample_fixed :
    (generatedX86RegWriteAt { bits := 0x1122334455667788, tag := .scalar }
      0xaa .w8 .high).bits = 0x112233445566aa88 := by
  native_decide

theorem x86_reg_write32_zero_extends (old : X86RegValue)
    (value : BitVec 64) :
    BitVec.and (generatedX86RegWrite old value .w32).bits 0xffffffff00000000 =
      0 := by
  cases old
  simp [generatedX86RegWrite, GeneratedX86RegWrite.write,
    GeneratedX86RegWrite.bits]
  bv_decide

theorem x86_reg_write64_replaces (old : X86RegValue)
    (value : BitVec 64) :
    (generatedX86RegWrite old value .w64).bits = value := by
  cases old
  rfl

theorem x86_reg_write_scalarizes (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) :
    (generatedX86RegWrite old value width).tag = .scalar := by
  cases old
  cases width <;> rfl

end KProgFormal
