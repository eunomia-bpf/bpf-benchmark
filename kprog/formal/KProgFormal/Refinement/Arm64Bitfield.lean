import KProgFormal.Refinement.Arm64Register
import KProgFormal.Arm64Bitfield
import KProgFormal.Arm64Aux
import KProgFormal.Generated.GeneratedArm64DispatchSingleton

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

/-- Actual AUX layout: kind, LSB, count, and an unused high byte. The native
instruction supplies the typed LSB/count validity already used above. -/
def packedAux (kind : Bitfield) (lsb count high : Byte) : BitVec 32 :=
  GeneratedArm64Aux.pack (BitVec.ofNat 32 (GeneratedArm64BitfieldDecode.code kind))
    (lsb.setWidth 32) (count.setWidth 32) (high.setWidth 32)

def decodeKind (code : Nat) : Option Bitfield :=
  if code = GeneratedArm64BitfieldDecode.code .ubfx then some .ubfx
  else if code = GeneratedArm64BitfieldDecode.code .sbfx then some .sbfx
  else if code = GeneratedArm64BitfieldDecode.code .ubfiz then some .ubfiz
  else if code = GeneratedArm64BitfieldDecode.code .bfxil then some .bfxil
  else if code = GeneratedArm64BitfieldDecode.code .bfi then some .bfi
  else none

theorem byte_lane (value : Byte) :
    ((value.setWidth 32) &&& (0xff : BitVec 32)).setWidth 8 = value := by
  bv_decide

/-- All three active AUX bytes round-trip independently of the unused high
byte; in particular an LSB/count field never changes the selected operation. -/
theorem packed_fields (kind : Bitfield) (lsb count high : Byte) :
    decodeKind (GeneratedArm64Aux.b0 (packedAux kind lsb count high)).toNat = some kind ∧
    (GeneratedArm64Aux.b1 (packedAux kind lsb count high)).setWidth 8 = lsb ∧
    (GeneratedArm64Aux.b2 (packedAux kind lsb count high)).setWidth 8 = count := by
  refine ⟨?_, ?_, ?_⟩
  · simp only [packedAux, arm64_aux_b0_roundtrip]
    cases kind <;> rfl
  · simpa only [packedAux, arm64_aux_b1_roundtrip] using byte_lane lsb
  · simpa only [packedAux, arm64_aux_b2_roundtrip] using byte_lane count


/-- Actual numeric body: low-byte kind selection is separate from the byte1
LSB and byte2 count extractors, then the generated primitive and register write
consume those fields. There is no invented runtime bounds guard. -/
def rawStep (kind : Bitfield) (width : Reference.AArch64.Width)
    (dst src : Reference.AArch64.Register) (aux : BitVec 32) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let value := GeneratedArm64Bitfield.value kind (Arm64Register.readReg s src)
    (Arm64Register.readReg s dst) ((GeneratedArm64Aux.b1 aux).setWidth 8)
    ((GeneratedArm64Aux.b2 aux).setWidth 8)
  ⟨{ Arm64Register.writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

theorem raw_step_eq (kind : Bitfield) (i : BitfieldInstruction) (high : Byte)
    (s : Reference.AArch64.State) :
    rawStep kind i.width i.dst i.src (packedAux kind i.lsbByte i.countByte high) s =
      handlerStep kind i s := by
  have fields := packed_fields kind i.lsbByte i.countByte high
  simp only [rawStep, fields.2.1, fields.2.2, handlerStep]

def dispatch (opcode : Nat) (aux : BitVec 32) (width : Reference.AArch64.Width)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  if opcode = GeneratedArm64DispatchSingleton.code .bitfield then
    (decodeKind (GeneratedArm64Aux.b0 aux).toNat).map (fun kind => rawStep kind width dst src aux s)
  else none

theorem dispatch_refines (kind : Bitfield) (i : BitfieldInstruction) (high : Byte)
    (s : Reference.AArch64.State) (matching : canonicalKind kind = i.kind) :
    dispatch (GeneratedArm64DispatchSingleton.code .bitfield)
      (packedAux kind i.lsbByte i.countByte high) i.width i.dst i.src s =
      some (Reference.AArch64.step (.bitfield i) s) := by
  simp only [dispatch, ↓reduceIte, (packed_fields kind i.lsbByte i.countByte high).1]
  change some (rawStep kind i.width i.dst i.src (packedAux kind i.lsbByte i.countByte high) s) = _
  rw [raw_step_eq, step_refines kind i s matching]

theorem dispatch_bad_kind (opcode : Nat) (aux : BitVec 32) (width : Reference.AArch64.Width)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State)
    (outside : 4 < (GeneratedArm64Aux.b0 aux).toNat) :
    dispatch opcode aux width dst src s = none := by
  have invalid : decodeKind (GeneratedArm64Aux.b0 aux).toNat = none := by
    simp [decodeKind, GeneratedArm64BitfieldDecode.code, show (GeneratedArm64Aux.b0 aux).toNat ≠ 0 by omega,
      show (GeneratedArm64Aux.b0 aux).toNat ≠ 1 by omega,
      show (GeneratedArm64Aux.b0 aux).toNat ≠ 2 by omega,
      show (GeneratedArm64Aux.b0 aux).toNat ≠ 3 by omega,
      show (GeneratedArm64Aux.b0 aux).toNat ≠ 4 by omega]
  simp [dispatch, invalid]

theorem dispatch_other (opcode : Nat) (aux : BitVec 32) (width : Reference.AArch64.Width)
    (dst src : Reference.AArch64.Register) (s : Reference.AArch64.State)
    (other : opcode ≠ GeneratedArm64DispatchSingleton.code .bitfield) :
    dispatch opcode aux width dst src s = none := by simp [dispatch, other]

end KProgFormal.Refinement.Arm64Bitfield
