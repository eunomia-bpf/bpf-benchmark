import KProgFormal.GeneratedX86MemAccess
import KProgFormal.X86Width

namespace KProgFormal

abbrev X86MemByte := BitVec 8

/-- Independent statement of the little-endian byte assembly: the width's
bytes summed as `Σ byte i <<< (8*i)`, narrowed to 64 bits. -/
def x86MemAssembleSpec (byte : Nat -> X86MemByte) (width : X86Width) :
    BitVec 64 :=
  match width with
  | .w8 => BitVec.setWidth 64 (byte 0)
  | .w16 =>
      BitVec.or (BitVec.setWidth 64 (byte 0))
        (BitVec.shiftLeft (BitVec.setWidth 64 (byte 1)) 8)
  | .w32 =>
      BitVec.or
        (BitVec.or (BitVec.setWidth 64 (byte 0))
          (BitVec.shiftLeft (BitVec.setWidth 64 (byte 1)) 8))
        (BitVec.or (BitVec.shiftLeft (BitVec.setWidth 64 (byte 2)) 16)
          (BitVec.shiftLeft (BitVec.setWidth 64 (byte 3)) 24))
  | .w64 =>
      BitVec.or
        (BitVec.or
          (BitVec.or (BitVec.setWidth 64 (byte 0))
            (BitVec.shiftLeft (BitVec.setWidth 64 (byte 1)) 8))
          (BitVec.or (BitVec.shiftLeft (BitVec.setWidth 64 (byte 2)) 16)
            (BitVec.shiftLeft (BitVec.setWidth 64 (byte 3)) 24)))
        (BitVec.or
          (BitVec.or (BitVec.shiftLeft (BitVec.setWidth 64 (byte 4)) 32)
            (BitVec.shiftLeft (BitVec.setWidth 64 (byte 5)) 40))
          (BitVec.or (BitVec.shiftLeft (BitVec.setWidth 64 (byte 6)) 48)
            (BitVec.shiftLeft (BitVec.setWidth 64 (byte 7)) 56)))

/-- Independent statement of the load: assemble then narrow to the access
width mask. -/
def x86MemLoadSpec (byte : Nat -> X86MemByte) (width : X86Width) : BitVec 64 :=
  BitVec.and (x86MemAssembleSpec byte width) (x86WidthMaskSpec width)

/-- Independent statement of the store byte: the width-masked value's bits
`8*i .. 8*i+8`. -/
def x86MemStoreByteSpec (value : BitVec 64) (width : X86Width)
    (i : Nat) : X86MemByte :=
  BitVec.setWidth 8
    (BitVec.ushiftRight (BitVec.and value (x86WidthMaskSpec width)) (8 * i))

/-- The generated assembly satisfies the independent little-endian statement. -/
theorem x86_mem_assemble_refines (byte : Nat -> X86MemByte) (width : X86Width) :
    GeneratedX86MemAccess.assemble byte width = x86MemAssembleSpec byte width := by
  cases width <;>
    simp only [GeneratedX86MemAccess.assemble, x86MemAssembleSpec,
      GeneratedX86MemAccess.byteCount] <;>
    simp [BitVec.or_assoc]

/-- The generated load satisfies the independent load statement. -/
theorem x86_mem_load_refines (byte : Nat -> X86MemByte) (width : X86Width) :
    GeneratedX86MemAccess.load byte width = x86MemLoadSpec byte width := by
  simp only [GeneratedX86MemAccess.load, x86MemLoadSpec]
  rw [x86_mem_assemble_refines, x86_width_mask_refines]

/-- The generated store byte satisfies the independent store statement. -/
theorem x86_mem_store_byte_refines (value : BitVec 64) (width : X86Width)
    (i : Nat) :
    GeneratedX86MemAccess.storeByte value width i =
      x86MemStoreByteSpec value width i := by
  cases width <;>
    simp only [GeneratedX86MemAccess.storeByte, x86MemStoreByteSpec,
      GeneratedX86MemAccess.store, x86WidthMaskSpec,
      GeneratedX86Width.mask]

/-- Byte count agrees with the width's byte length. -/
theorem x86_mem_byte_count (width : X86Width) :
    GeneratedX86MemAccess.byteCount width = x86WidthBitsSpec width / 8 := by
  cases width <;> rfl

/-- Concrete load: the bytes `[0x78, 0x56, 0x34, 0x12]` assemble to
`0x12345678` at 32-bit width under little-endian order. -/
theorem x86_mem_load_w32_example :
    x86MemLoadSpec
      (fun i => match i with
        | 0 => 0x78 | 1 => 0x56 | 2 => 0x34 | 3 => 0x12 | _ => 0)
      .w32 = 0x12345678 := by
  native_decide

/-- Concrete store: a 16-bit masked value decomposes into its two low bytes. -/
theorem x86_mem_store_w16_example :
    x86MemStoreByteSpec 0xaabb .w16 0 = 0xbb ∧
      x86MemStoreByteSpec 0xaabb .w16 1 = 0xaa := by
  native_decide

end KProgFormal
