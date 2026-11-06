import KProgFormal.Reference.X86
import KProgFormal.Generated.GeneratedX86RegRead
import KProgFormal.Generated.GeneratedX86MemAccess
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.X86Scalar

open Reference
open Reference.X86 (ScalarWidth RegisterSlice ScalarSource ScalarDestination)

def handlerWidth : ScalarWidth → GeneratedX86Width.Width
  | .w8 => .w8 | .w16 => .w16 | .w32 => .w32 | .w64 => .w64

def lane : RegisterSlice → GeneratedX86RegWrite.ByteLane
  | .low _ => .low | .high _ => .high

theorem register_read_refines (width : ScalarWidth) (slice : RegisterSlice) (value : Reference.Word) :
    GeneratedX86RegRead.readAt value (handlerWidth width) (lane slice) =
      ((value >>> slice.shift width).setWidth width.bits).setWidth 64 := by
  cases width <;> cases slice <;>
    simp only [handlerWidth, lane, GeneratedX86RegRead.readAt, Reference.X86.RegisterSlice.shift,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, reduceCtorEq, ↓reduceIte,
      Nat.reduceMul, Reference.Word] <;> bv_decide

theorem register_write_refines (width : ScalarWidth) (slice : RegisterSlice) (old value : Reference.Word) :
    (GeneratedX86RegWrite.writeAt old value (handlerWidth width) (lane slice)).bits =
      Reference.X86.scalarWriteValue old value width slice := by
  cases width <;> cases slice <;>
    simp only [handlerWidth, lane, GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt,
      Reference.X86.scalarWriteValue, Reference.X86.RegisterSlice.shift,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, reduceCtorEq, ↓reduceIte,
      Nat.reduceMul, Reference.Word] <;> bv_decide

theorem load_value_refines (width : ScalarWidth) (memory : Memory) (address : Reference.Word) :
    GeneratedX86MemAccess.load (fun i => memory.value (address + BitVec.ofNat 64 i))
      (handlerWidth width) = wordAt memory address width.bytes := by
  cases width <;>
    simp [handlerWidth, Reference.X86.ScalarWidth.bytes, GeneratedX86MemAccess.load,
      GeneratedX86MemAccess.assemble, GeneratedX86Width.mask, wordAt, bytesAt,
      littleEndian, List.range_succ] <;> bv_decide

theorem fixed_load_value_refines (width : ScalarWidth) (memory : Memory)
    (base : Reference.Word) (displacement : BitVec 16) :
    GeneratedX86MemAccess.loadFixed memory.value base displacement (handlerWidth width) =
      wordAt memory (base + displacement.signExtend 64) width.bytes := by
  exact load_value_refines width memory (base + displacement.signExtend 64)

theorem store_byte_refines (width : ScalarWidth) (value : Reference.Word) (i : Nat) (h : i < width.bytes) :
    GeneratedX86MemAccess.store value (handlerWidth width) i = (value >>> (8 * i)).setWidth 8 := by
  have bound : i < 8 := by cases width <;> simp only [Reference.X86.ScalarWidth.bytes] at h <;> omega
  have hi : i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 := by omega
  rcases hi with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;>
    cases width <;> simp only [Reference.X86.ScalarWidth.bytes] at h <;>
    first | omega | (simp only [handlerWidth, GeneratedX86MemAccess.store, GeneratedX86MemAccess.storeByte,
      GeneratedX86Width.mask, Reference.Word, Nat.reduceMul] <;> bv_decide)

/-- Shared generated scalar read, after the entry/address relation supplies
materialized native register values. Stack-relative encodings are not guessed. -/
def read (s : Reference.X86.State) (width : ScalarWidth) : ScalarSource → Except Fault (Reference.Word × List Event)
  | .register slice => .ok (GeneratedX86RegRead.readAt (s.gpr slice.reg) (handlerWidth width) (lane slice), [])
  | .immediate value => .ok (value, [])
  | .memory address =>
      if permitted s.memory.readable address width.bytes then
        .ok (GeneratedX86MemAccess.load (fun i => s.memory.value (address + BitVec.ofNat 64 i)) (handlerWidth width),
          [.memory .read address (bytesAt s.memory address width.bytes) (initializedAt s.memory address width.bytes)])
      else .error (.read address width.bytes)

theorem read_refines (s : Reference.X86.State) (width : ScalarWidth) (src : ScalarSource) :
    read s width src = Reference.X86.scalarRead s width src := by
  cases src <;>
    simp [read, Reference.X86.scalarRead, Reference.X86.scalarRegisterValue,
      Reference.X86.readSource, readMemory, register_read_refines, load_value_refines]
  split <;> simp_all

def readFixed (s : Reference.X86.State) (width : ScalarWidth) (base : Reference.Word)
    (displacement : BitVec 16) : Except Fault (Reference.Word × List Event) :=
  let address := GeneratedX86MemAccess.displacedAddress base displacement
  if permitted s.memory.readable address width.bytes then
    .ok (GeneratedX86MemAccess.loadFixed s.memory.value base displacement (handlerWidth width),
      [.memory .read address (bytesAt s.memory address width.bytes) (initializedAt s.memory address width.bytes)])
  else .error (.read address width.bytes)

/-- The fixed-offset encoding changes neither the effective address nor
permissions, initialization, ordered effects or faults of the scalar read. -/
theorem fixed_read_refines (s : Reference.X86.State) (width : ScalarWidth) (base : Reference.Word)
    (displacement : BitVec 16) :
    readFixed s width base displacement =
      Reference.X86.scalarRead s width (.memory (base + displacement.signExtend 64)) := by
  exact read_refines s width (.memory (base + displacement.signExtend 64))

def store (memory : Memory) (width : ScalarWidth) (address value : Reference.Word) : Memory :=
  { memory with
    value := fun a =>
      let offset := (a - address).toNat
      if offset < width.bytes then GeneratedX86MemAccess.store value (handlerWidth width) offset else memory.value a
    initialized := fun a => if (a - address).toNat < width.bytes then true else memory.initialized a }

theorem store_refines (memory : Memory) (width : ScalarWidth) (address value : Reference.Word) :
    store memory width address value = storeMemory memory address value width.bytes := by
  unfold store storeMemory
  congr 1
  funext a
  dsimp only
  split <;> rename_i h
  · exact store_byte_refines width value _ h
  · rfl

def write (s : Reference.X86.State) (width : ScalarWidth) (dst : ScalarDestination) (value : Reference.Word) :
    Except Fault (Reference.X86.State × List Event) :=
  match dst with
  | .register slice =>
      .ok ({ s with gpr := fun r => if r = slice.reg then
        (GeneratedX86RegWrite.writeAt (s.gpr r) value (handlerWidth width) (lane slice)).bits else s.gpr r }, [])
  | .memory address =>
      if permitted s.memory.writable address width.bytes then
        .ok ({ s with memory := store s.memory width address value },
          [.memory .write address (valueBytes value width.bytes) true])
      else .error (.write address width.bytes)

theorem write_refines (s : Reference.X86.State) (width : ScalarWidth) (dst : ScalarDestination) (value : Reference.Word) :
    write s width dst value = Reference.X86.scalarWrite s width dst value := by
  cases dst <;> simp [write, Reference.X86.scalarWrite, register_write_refines, writeMemory, store_refines]
  split <;> simp_all

def moveStep (width : ScalarWidth) (dst : ScalarDestination) (src : ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match read s width src with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      match write s width dst value with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (result, writes) => ⟨{ result with pc := nextPc }, reads ++ writes, none⟩

theorem move_step_refines (width : ScalarWidth) (dst : ScalarDestination) (src : ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    moveStep width dst src nextPc s = Reference.X86.step (.move width dst src nextPc) s := by
  simp only [moveStep, Reference.X86.step, Reference.X86.moveStep, read_refines, write_refines]
  rfl

theorem move_handler_refines (width : ScalarWidth) (dst : ScalarDestination) (src : ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.move width dst src nextPc) s (moveStep width dst src nextPc s) := by
  rw [move_step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Scalar
