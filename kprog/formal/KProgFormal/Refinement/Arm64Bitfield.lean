import KProgFormal.Refinement.Arm64Register
import KProgFormal.Arm64Bitfield

namespace KProgFormal.Refinement.Arm64Bitfield
open Reference
open Reference.AArch64 (BitfieldKind BitfieldInstruction)
open GeneratedArm64BitfieldDecode (Bitfield)

def canonicalKind : Bitfield → BitfieldKind
  | .ubfx => .ubfx | .sbfx => .sbfx | .ubfiz => .ubfiz | .bfxil => .bfxil | .bfi => .bfi

/-- Bounds come from the typed native field, not a simulator runtime check. -/
theorem byte_bounds (i : BitfieldInstruction) :
    (1 : BitVec 8) ≤ i.countByte ∧ i.countByte ≤ (64 : BitVec 8) ∧
    i.lsbByte ≤ (64 : BitVec 8) - i.countByte := by
  rcases i with ⟨width, kind, dst, src, lsb, size⟩
  have hl := lsb.isLt
  have hs := size.isLt
  cases width <;>
    simp only [BitfieldInstruction.countByte, BitfieldInstruction.lsbByte,
      Reference.AArch64.Width.bits] at * <;> bv_omega

theorem mask_spec (count : Byte) :
    arm64BitfieldMaskSpec (count.setWidth 64) =
      ~~~((0xffffffffffffffff : Word) <<< (count.setWidth 64)) := by
  simp only [arm64BitfieldMaskSpec]
  bv_decide

theorem value_refines (kind : Bitfield) (i : BitfieldInstruction) (src dst : Word) :
    GeneratedArm64Bitfield.value kind src dst i.lsbByte i.countByte =
      Reference.AArch64.bitfieldValue (canonicalKind kind) src dst i.lsbByte i.countByte := by
  obtain ⟨hb, h64, hlsb⟩ := byte_bounds i
  rw [arm64_bitfield_refines kind src dst i.lsbByte i.countByte hb h64 hlsb]
  cases kind <;>
    simp only [arm64BitfieldValueSpec, arm64BitfieldFieldOfByte,
      canonicalKind, Reference.AArch64.bitfieldValue, mask_spec]

def handlerStep (kind : Bitfield) (i : BitfieldInstruction)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Bitfield.value kind (Arm64Register.readReg s i.src)
    (Arm64Register.readReg s i.dst) i.lsbByte i.countByte
  ⟨{ Arm64Register.writeReg s i.dst value i.width with pc := s.pc + 4 }, [], none⟩

theorem step_refines (kind : Bitfield) (i : BitfieldInstruction)
    (s : Reference.AArch64.State) (hk : canonicalKind kind = i.kind) :
    handlerStep kind i s = Reference.AArch64.step (.bitfield i) s := by
  simp only [handlerStep, Reference.AArch64.step, Reference.AArch64.bitfieldStep,
    Arm64Register.read_refines, Arm64Register.write_refines, value_refines, hk]

end KProgFormal.Refinement.Arm64Bitfield
