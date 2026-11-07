import KProgFormal.Refinement.Arm64AddressedMemory
import KProgFormal.Generated.GeneratedArm64DispatchSingleton
import KProgFormal.Generated.GeneratedArm64DqMem
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.Arm64VectorMemory
open Reference

/-- The actual D-load lane transfer plus the generated upper-half action. -/
def dLoad (old : BitVec 128) (low : Word) : BitVec 128 :=
  let high : Word := if GeneratedArm64DqMem.clearHigh .loadD0 then 0 else (old >>> 64).setWidth 64
  low.setWidth 128 ||| (high.setWidth 128 <<< 64)

theorem d_load_refines (old : BitVec 128) (m : Memory) (address : Word) :
    dLoad old (wordAt m address 8) = littleEndian 128 (bytesAt m address 8) := by
  simp [dLoad, GeneratedArm64DqMem.clearHigh, if_true, wordAt,
    bytesAt, littleEndian, List.range_succ, Reference.Word, BitVec.add_assoc]
  bv_decide

/-- Both transferred Q lanes form the one 128-bit architectural value. -/
def qLoad (low high : Word) : BitVec 128 :=
  low.setWidth 128 ||| (high.setWidth 128 <<< 64)

theorem q_load_refines (m : Memory) (address : Word) :
    qLoad (wordAt m address 8) (wordAt m (address + 8) 8) =
      littleEndian 128 (bytesAt m address 16) := by
  simp [qLoad, wordAt, bytesAt, littleEndian, List.range_succ, Reference.Word, BitVec.add_assoc]
  bv_decide

/-- Each low D lane store emits exactly eight source bytes. Truncating the
vector to the generated memory word does not change any of those bytes. -/
theorem d_store_bytes (value : BitVec 128) :
    (List.range 8).map (fun n => (value >>> (8 * n)).setWidth 8) =
      valueBytes (value.setWidth 64) 8 := by
  unfold valueBytes
  apply List.map_congr_left
  intro n member
  have nBound : n < 8 := List.mem_range.mp member
  apply BitVec.eq_of_getLsbD_eq
  intro bit bitBound
  have lowBound : 8 * n + bit < 64 := by omega
  simp only [BitVec.getLsbD_setWidth, BitVec.getLsbD_ushiftRight]
  simp [bitBound, lowBound]

open Reference.AArch64 (Register)

/-- The no-writeback D0 instruction corresponding to the two production
singletons. Other vector banks and Q-width effects are not substituted here. -/
def dInstruction (load : Bool) (base : Register) (offset : Word) :
    Reference.AArch64.Instruction :=
  .vectorMemory ⟨.double, load, 0, base, .immediate offset, .none⟩

/-- Compose the actual DQ direction/high-clear selectors with the generated
native-eight-byte memory primitives. Permission/fault branches are the checked
memory model, not new runtime guards inserted into the C macro. -/
def dStep (load : Bool) (base : Register) (offset : Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let op := if load then GeneratedArm64DqMem.Op.loadD0 else .storeD0
  let address := Arm64Memory.baseValue s base +
    GeneratedArm64MemOffset.value false false offset 0
  if GeneratedArm64DqMem.access op = .load then
    match Arm64Memory.read .double s.memory address with
    | .error fault => ⟨s, [.fault fault], some fault⟩
    | .ok (value, event) => ⟨{ s with vector0 := dLoad s.vector0 value, pc := s.pc + 4 }, [event], none⟩
  else
    match Arm64Memory.write .double s.memory address (s.vector0.setWidth 64) with
    | .error fault => ⟨s, [.fault fault], some fault⟩
    | .ok (memory, event) => ⟨{ s with memory := memory, pc := s.pc + 4 }, [event], none⟩

theorem d_step_refines (load : Bool) (base : Register) (offset : Word)
    (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s base = none) :
    dStep load base offset s = Reference.AArch64.step (dInstruction load base offset) s := by
  cases load <;>
    simp only [dStep, dInstruction, Reference.AArch64.step,
      Reference.AArch64.vectorMemoryStep, alignment, Reference.AArch64.memoryOffset,
      Arm64Memory.base_refines, GeneratedArm64MemOffset.value, GeneratedArm64DqMem.access,
      Arm64Memory.read_refines, Arm64Memory.write_refines,
      Reference.AArch64.VectorMemoryWidth.bytes, Reference.AArch64.VectorMemoryWidth.scale,
      Reference.AArch64.MemoryWidth.bytes, readMemory, writeMemory,
      Bool.false_eq_true, reduceCtorEq, ↓reduceIte, Nat.reducePow,
      Reference.AArch64.readVector_zero, Reference.AArch64.writeVector_zero]
  · by_cases permittedWrite : permitted s.memory.writable (Reference.AArch64.memoryBase s base + offset) 8 = true <;>
      simp [permittedWrite, d_store_bytes]
  · by_cases permittedRead : permitted s.memory.readable (Reference.AArch64.memoryBase s base + offset) 8 = true <;>
      simp [permittedRead, d_load_refines]

/-- Generated index modifiers feed the same D-width address, including W
zero/sign extension, the native X index, scaling by eight and ZR indexes. -/
def dOffset (s : Reference.AArch64.State) : Reference.AArch64.MemoryOffset → Word
  | .immediate value => value
  | .register index kind scaled =>
      GeneratedArm64Mod.value (Arm64AddressedMemory.modifier kind)
        (Arm64Register.readReg s index) (BitVec.ofNat 64 (if scaled then 3 else 0)) .w64

theorem d_offset_refines (s : Reference.AArch64.State) (offset : Reference.AArch64.MemoryOffset) :
    dOffset s offset = Reference.AArch64.memoryOffset s 3 offset := by
  cases offset with
  | immediate value => rfl
  | register index kind scaled =>
      simpa only [dOffset, Arm64Register.read_refines, Reference.AArch64.memoryOffset,
        Arm64AddressedMemory.indexValue] using
        Arm64AddressedMemory.index_refines kind (Reference.AArch64.readReg s index)
          ⟨if scaled then 3 else 0, by split <;> decide⟩

def dIndexedStep (load : Bool) (base : Register) (offset : Reference.AArch64.MemoryOffset)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  dStep load base (dOffset s offset) s

theorem d_indexed_refines (load : Bool) (base : Register) (offset : Reference.AArch64.MemoryOffset)
    (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s base = none) :
    dIndexedStep load base offset s = Reference.AArch64.step
      (.vectorMemory ⟨.double, load, 0, base, offset, .none⟩) s := by
  rw [dIndexedStep, d_step_refines load base (dOffset s offset) s alignment]
  simp only [dInstruction, Reference.AArch64.step, Reference.AArch64.vectorMemoryStep,
    alignment, Reference.AArch64.VectorMemoryWidth.scale, Reference.AArch64.memoryOffset,
    d_offset_refines]

/-- This two-arm dispatcher uses the production singleton predicates. Its
result is absent for every other opcode, retaining the rest of the chain. -/
def dispatchD (op : GeneratedArm64DispatchSingleton.SingletonOp) (base : Register)
    (offset : Word) (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  if GeneratedArm64DispatchSingleton.loadD0Handled op then some (dStep true base offset s)
  else if GeneratedArm64DispatchSingleton.storeD0Handled op then some (dStep false base offset s)
  else none

theorem dispatch_d_load_refines (base : Register) (offset : Word) (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s base = none) :
    dispatchD .loadD0 base offset s = some (Reference.AArch64.step (dInstruction true base offset) s) := by
  change some (dStep true base offset s) = _
  rw [d_step_refines true base offset s alignment]

theorem dispatch_d_store_refines (base : Register) (offset : Word) (s : Reference.AArch64.State)
    (alignment : Reference.AArch64.spAlignmentFault s base = none) :
    dispatchD .storeD0 base offset s = some (Reference.AArch64.step (dInstruction false base offset) s) := by
  change some (dStep false base offset s) = _
  rw [d_step_refines false base offset s alignment]

theorem dispatch_d_other (op : GeneratedArm64DispatchSingleton.SingletonOp)
    (base : Register) (offset : Word) (s : Reference.AArch64.State)
    (notLoad : op ≠ .loadD0) (notStore : op ≠ .storeD0) :
    dispatchD op base offset s = none := by
  simp [dispatchD, GeneratedArm64DispatchSingleton.loadD0Handled,
    GeneratedArm64DispatchSingleton.storeD0Handled, notLoad, notStore]

end KProgFormal.Refinement.Arm64VectorMemory
