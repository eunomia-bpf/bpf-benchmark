import KProgFormal.Refinement.Arm64Register
import KProgFormal.Generated.GeneratedArm64LoadBytes
import KProgFormal.Generated.GeneratedArm64StoreBytes
import KProgFormal.Generated.GeneratedArm64MemBaseSrc
import KProgFormal.Generated.GeneratedArm64MemOffset
import KProgFormal.Generated.GeneratedArm64Extrev
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.Arm64Memory

open Reference
open Reference.AArch64 (MemoryWidth MemoryInstruction MemoryTransfer Width Register)

def loadWidth : MemoryWidth → GeneratedArm64LoadBytes.LoadWidth
  | .byte => .w8 | .half => .w16 | .word => .w32 | .double => .w64

def storeWidth : MemoryWidth → GeneratedArm64StoreBytes.StoreWidth
  | .byte => .w8 | .half => .w16 | .word => .w32 | .double => .w64

/-- The full packed word is a ghost value, not an eight-byte guest read.
Only the selected byte count is read by the generated ladder and event. -/
theorem load_value (width : MemoryWidth) (m : Memory) (address : Reference.Word) :
    GeneratedArm64LoadBytes.value (loadWidth width) (wordAt m address 8) =
      wordAt m address width.bytes := by
  cases width <;>
    simp [loadWidth, MemoryWidth.bytes, GeneratedArm64LoadBytes.value,
      wordAt, bytesAt, littleEndian, List.range_succ] <;> bv_decide

theorem store_byte (width : MemoryWidth) (value : Reference.Word) (i : Nat) (h : i < width.bytes) :
    ((GeneratedArm64StoreBytes.image (storeWidth width) value) >>> (8 * i)).setWidth 8 =
      (value >>> (8 * i)).setWidth 8 := by
  have bound : i < 8 := by cases width <;> simp only [MemoryWidth.bytes] at h <;> omega
  have hi : i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 := by omega
  rcases hi with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;>
    cases width <;> simp only [MemoryWidth.bytes] at h <;>
    first | omega | (simp only [storeWidth, GeneratedArm64StoreBytes.image,
      Reference.Word, Nat.reduceMul] <;> bv_decide)

def baseValue (s : Reference.AArch64.State) (base : Register) : Reference.Word :=
  match GeneratedArm64MemBaseSrc.sourceOf (base.val == 31) with
  | .spRegister => s.sp
  | .gprBase => Arm64Register.readReg s base

theorem base_refines (s : Reference.AArch64.State) (base : Register) :
    baseValue s base = Reference.AArch64.memoryBase s base := by
  by_cases h : base.val < 31
  · simp [baseValue, GeneratedArm64MemBaseSrc.sourceOf, Arm64Register.read_refines,
      Reference.AArch64.readReg, Reference.AArch64.memoryBase, h, show base.val ≠ 31 by omega]
  · have equal : base.val = 31 := by omega
    simp [baseValue, GeneratedArm64MemBaseSrc.sourceOf, Reference.AArch64.memoryBase, h, equal]

def address (i : MemoryInstruction) (s : Reference.AArch64.State) : Reference.Word :=
  baseValue s i.base + GeneratedArm64MemOffset.value false false i.offset 0

theorem address_refines (i : MemoryInstruction) (s : Reference.AArch64.State) :
    address i s = Reference.AArch64.memoryBase s i.base + i.offset := by
  simp [address, base_refines, GeneratedArm64MemOffset.value]

def read (width : MemoryWidth) (m : Memory) (address : Reference.Word) :
    Except Fault (Reference.Word × Event) :=
  if permitted m.readable address width.bytes then
    .ok (GeneratedArm64LoadBytes.value (loadWidth width) (wordAt m address 8),
      .memory .read address (bytesAt m address width.bytes) (initializedAt m address width.bytes))
  else .error (.read address width.bytes)

theorem read_refines (width : MemoryWidth) (m : Memory) (address : Reference.Word) :
    read width m address = readMemory m address width.bytes := by
  simp only [read, readMemory, load_value]

def store (width : MemoryWidth) (m : Memory) (address value : Reference.Word) : Memory :=
  { m with
    value := fun a =>
      let offset := (a - address).toNat
      if offset < width.bytes then
        ((GeneratedArm64StoreBytes.image (storeWidth width) value) >>> (8 * offset)).setWidth 8
      else m.value a
    initialized := fun a => if (a - address).toNat < width.bytes then true else m.initialized a }

theorem store_refines (width : MemoryWidth) (m : Memory) (address value : Reference.Word) :
    store width m address value = storeMemory m address value width.bytes := by
  unfold store storeMemory
  congr 1
  funext a
  dsimp only
  split <;> rename_i h
  · exact store_byte width value _ h
  · rfl

def write (width : MemoryWidth) (m : Memory) (address value : Reference.Word) :
    Except Fault (Memory × Event) :=
  if permitted m.writable address width.bytes then
    .ok (store width m address value, .memory .write address (valueBytes value width.bytes) true)
  else .error (.write address width.bytes)

theorem write_refines (width : MemoryWidth) (m : Memory) (address value : Reference.Word) :
    write width m address value = writeMemory m address value width.bytes := by
  simp only [write, writeMemory, store_refines]

/-- Byte/halfword unsigned writes take the full GPR arm after load narrowing;
word loads take the W arm, and signed loads use their encoded W/X destination. -/
def destinationWidth (width : MemoryWidth) : Option Width → Width
  | some output => output
  | none => match width with | .word => .w32 | _ => .w64

def valueWidth : MemoryWidth → GeneratedArm64Width.Width
  | .byte => .w8 | .half => .w16 | .word => .w32 | .double => .w64

def loadResult (width : MemoryWidth) (signedTo : Option Width) (value : Reference.Word) : Reference.Word :=
  match signedTo with
  | none => GeneratedArm64Width.narrow value (valueWidth width)
  | some _ => GeneratedArm64Extrev.signExtend value width.bits

theorem load_result_refines (width : MemoryWidth) (signedTo : Option Width) (value : Reference.Word) :
    Reference.AArch64.narrow (loadResult width signedTo value) (destinationWidth width signedTo) =
      Reference.AArch64.memoryLoadValue width signedTo value := by
  cases signedTo with
  | none =>
      cases width <;>
        simp only [loadResult, valueWidth, GeneratedArm64Width.narrow, GeneratedArm64Width.mask, destinationWidth,
          Reference.AArch64.memoryLoadValue, Reference.AArch64.narrow, MemoryWidth.bits,
          MemoryWidth.bytes, Width.bits, Reference.Word, Nat.reduceMul] <;> bv_decide
  | some output =>
      cases width <;> cases output <;>
        simp only [loadResult, GeneratedArm64Extrev.signExtend, destinationWidth,
          Reference.AArch64.memoryLoadValue, Reference.AArch64.narrow, MemoryWidth.bits,
          MemoryWidth.bytes, Width.bits, Reference.Word, Nat.reduceMul] <;> bv_decide

/-- This is the generated ordinary LOAD/STORE/LDRSX byte/value/writeback path
on materialized architectural addresses. Admission must establish SP alignment;
the production handler has no hidden runtime SP-alignment guard. -/
def handlerStep (i : MemoryInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let address := address i s
  match i.transfer with
  | .load dst signedTo =>
      match read i.width s.memory address with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (value, event) =>
          ⟨{ Arm64Register.writeReg s dst (loadResult i.width signedTo value)
            (destinationWidth i.width signedTo) with pc := s.pc + 4 }, [event], none⟩
  | .store src =>
      match write i.width s.memory address (Arm64Register.readReg s src) with
      | .error fault => ⟨s, [.fault fault], some fault⟩
      | .ok (memory, event) => ⟨{ s with memory := memory, pc := s.pc + 4 }, [event], none⟩

theorem step_refines (i : MemoryInstruction) (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none) :
    handlerStep i s = Reference.AArch64.step (.memory i) s := by
  simp only [handlerStep, Reference.AArch64.step, Reference.AArch64.memoryStep, alignment,
    address_refines, read_refines, write_refines, Arm64Register.read_refines]
  cases i.transfer with
  | load dst signedTo =>
      cases readMemory s.memory (Reference.AArch64.memoryBase s i.base + i.offset) i.width.bytes with
      | error fault => rfl
      | ok pair =>
          rcases pair with ⟨value, event⟩
          simp only [Arm64Register.write_refines, load_result_refines]
  | store src => rfl

theorem handler_refines (i : MemoryInstruction) (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none) :
    Reference.AArch64.Step (.memory i) s (handlerStep i s) := (step_refines i s alignment).symm

end KProgFormal.Refinement.Arm64Memory
