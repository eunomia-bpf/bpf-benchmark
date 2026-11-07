import KProgFormal.X86Xmm0Handler
import KProgFormal.Refinement.X86Scalar

namespace KProgFormal.Refinement.X86Xmm0
open Reference

/-- Both generated64-bit loads form the native128-bit value, in lane order. -/
def load (m : Memory) (address : Reference.Word) : BitVec 128 :=
  let byte := fun i => m.value (address + BitVec.ofNat 64 i)
  let lo := GeneratedX86MemAccess.load byte .w64
  let hi := GeneratedX86MemAccess.load (fun i => byte (i + 8)) .w64
  lo.setWidth 128 ||| (hi.setWidth 128 <<< 64)

theorem load_refines (m : Memory) (address : Reference.Word) :
    load m address = littleEndian 128 (bytesAt m address 16) := by
  simp [load, GeneratedX86MemAccess.load, GeneratedX86MemAccess.assemble,
    GeneratedX86Width.mask, bytesAt, littleEndian, List.range_succ,
    Reference.Word, BitVec.add_assoc]
  bv_decide

/-- The scalar-lane reads cover precisely the one architectural byte list.
Initialization summaries combine by conjunction, including address wraparound. -/
theorem read_bytes (m : Memory) (address : Reference.Word) :
    bytesAt m address 8 ++ bytesAt m (address + 8) 8 = bytesAt m address 16 := by
  simp [bytesAt, List.range_succ, BitVec.add_assoc]

theorem permissions (permission : Reference.Word → Bool) (address : Reference.Word) :
    permitted permission address 16 =
      (permitted permission address 8 && permitted permission (address + 8) 8) := by
  simp [permitted, List.range_succ, BitVec.add_assoc, Bool.and_assoc]

theorem store_bytes (value : BitVec 128) :
    valueBytes (value.setWidth 64) 8 ++ valueBytes ((value >>> 64).setWidth 64) 8 =
      Reference.X86.xmm0Bytes value := by
  simp [valueBytes, Reference.X86.xmm0Bytes, List.range_succ, Reference.Word]
  bv_decide

/-- Store the actual generated pair-byte contract into the materialized guest
memory. This is its byte projection; permissions/faults are separate obligations. -/
def store (m : Memory) (address : Reference.Word) (value : BitVec 128) : Memory :=
  let pair : X86Xmm0Pair := ⟨value.setWidth 64, (value >>> 64).setWidth 64⟩
  { m with
    value := fun a => x86Xmm0StoreBytes (fun _ => m.value a) pair (a - address).toNat
    initialized := fun a => if (a - address).toNat < 16 then true else m.initialized a }

theorem store_byte_refines (value : BitVec 128) (i : Nat) (h : i < 16) :
    x86Xmm0StoreBytes (fun _ => 0) ⟨value.setWidth 64, (value >>> 64).setWidth 64⟩ i =
      (value >>> (8 * i)).setWidth 8 := by
  have hi : i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨
      i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 ∨ i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15 := by omega
  rcases hi with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;>
    simp [x86Xmm0StoreBytes, GeneratedX86MemAccess.byteCount,
      GeneratedX86MemAccess.storeByte, GeneratedX86Width.mask] <;> bv_decide

theorem store_refines (m : Memory) (address : Reference.Word) (value : BitVec 128) :
    store m address value = Reference.X86.xmm0Store m address value := by
  unfold store Reference.X86.xmm0Store
  dsimp only
  congr 1
  funext a
  dsimp only
  by_cases h : (a - address).toNat < 16
  · have eq := store_byte_refines value (a - address).toNat h
    simpa only [x86Xmm0StoreBytes, GeneratedX86MemAccess.byteCount, Nat.reduceMul, if_pos h] using eq
  · simp only [x86Xmm0StoreBytes, GeneratedX86MemAccess.byteCount]
    have h8 : ¬ (a - address).toNat < 8 := by omega
    simp only [Nat.reduceMul, if_neg h, if_neg h8]

/-- Successful access after the platform/address certificate establishes all
16 bytes accessible and, for MOVAPS, aligned. The single guest event summarizes
the two scalar lanes; this theorem does not invent C alignment/fault checks. -/
def success (isStore : Bool) (address nextPc : Reference.Word) (s : Reference.X86.State) :
    Transition Reference.X86.State :=
  if isStore then
    ⟨{ s with memory := store s.memory address s.xmm0, pc := nextPc },
      [.memory .write address (Reference.X86.xmm0Bytes s.xmm0) true], none⟩
  else
    ⟨{ s with xmm0 := load s.memory address, pc := nextPc },
      [.memory .read address (bytesAt s.memory address 16) (initializedAt s.memory address 16)], none⟩

theorem success_refines (isStore aligned : Bool) (address nextPc : Reference.Word)
    (s : Reference.X86.State) (ha : (aligned && address &&& 15 != 0) = false)
    (hp : permitted (if isStore then s.memory.writable else s.memory.readable) address 16 = true) :
    success isStore address nextPc s = Reference.X86.step (.xmm0Move isStore aligned address nextPc) s := by
  cases aligned <;> cases isStore <;>
    simp_all [success, Reference.X86.step, Reference.X86.xmm0Step, load_refines, store_refines]

theorem success_handler_refines (isStore aligned : Bool) (address nextPc : Reference.Word)
    (s : Reference.X86.State) (ha : (aligned && address &&& 15 != 0) = false)
    (hp : permitted (if isStore then s.memory.writable else s.memory.readable) address 16 = true) :
    Reference.X86.Step (.xmm0Move isStore aligned address nextPc) s
      (success isStore address nextPc s) := by
  rw [success_refines isStore aligned address nextPc s ha hp]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Xmm0
