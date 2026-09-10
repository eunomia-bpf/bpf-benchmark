import KProgFormal.GeneratedX86RegWrite
import KProgFormal.TagErasure
import KProgFormal.X86Width

namespace KProgFormal

structure X86RegValue where
  bits : BitVec 64
  tag : Tag
  deriving DecidableEq, Repr

/-- Independent architectural statement of low-lane partial-register
writeback. The 8- and 16-bit cases preserve the old upper bits, while 32-bit
writes zero the upper half and 64-bit writes replace the complete register. -/
def x86RegWriteBitsSpec (old value : BitVec 64) : X86Width -> BitVec 64
  | .w8 => BitVec.xor old (BitVec.and (BitVec.xor old value) 0xff)
  | .w16 => BitVec.xor old (BitVec.and (BitVec.xor old value) 0xffff)
  | .w32 => BitVec.and value 0xffffffff
  | .w64 => value

def generatedX86RegWrite (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) : X86RegValue :=
  let generated := GeneratedX86RegWrite.write old.bits value width
  { bits := generated.bits
    tag := if generated.scalarizes then .scalar else old.tag }

def x86RegWriteSpec (old : X86RegValue) (value : BitVec 64)
    (width : X86Width) : X86RegValue :=
  { bits := x86RegWriteBitsSpec old.bits value width, tag := .scalar }

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
