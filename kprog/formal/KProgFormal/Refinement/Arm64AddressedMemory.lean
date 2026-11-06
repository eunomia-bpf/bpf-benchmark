import KProgFormal.Refinement.Arm64Memory
import KProgFormal.Refinement.Arm64PairMemory
import KProgFormal.Generated.GeneratedArm64Mod
import KProgFormal.Generated.GeneratedArm64MemPrepost
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.Arm64AddressedMemory
open Reference
open Reference.AArch64

def modifier : MemoryExtend → GeneratedArm64ModDecode.Mod
  | .uxtw => .uxtw | .sxtw => .sxtw | .lsl | .sxtx => .lsl

def indexValue (kind : MemoryExtend) (value : Word) (shift : Nat) : Word :=
  let extended : Word := match kind with
    | .uxtw => (value.setWidth 32).setWidth 64
    | .sxtw => (value.setWidth 32).signExtend 64
    | .lsl | .sxtx => value
  extended <<< shift

theorem index_refines (kind : MemoryExtend) (value : Word) (shift : Fin 5) :
    GeneratedArm64Mod.value (modifier kind) value (BitVec.ofNat 64 shift.val) .w64 =
      indexValue kind value shift.val := by
  have h : shift.val = 0 ∨ shift.val = 1 ∨ shift.val = 2 ∨ shift.val = 3 ∨ shift.val = 4 := by omega
  rcases h with h | h | h | h | h <;>
    cases kind <;>
    simp [modifier, GeneratedArm64Mod.value, GeneratedArm64Width.mask, indexValue, Reference.Word, h] <;>
    bv_decide

/-- Exact generated packed pre/post flags for the three native modes. -/
def flags : Writeback → BitVec 32
  | .none => 0 | .pre => 0x01000000 | .post => 0x02000000

theorem access_offset_refines (mode : Writeback) (delta : Word) :
    GeneratedArm64MemPrepost.preDelta (flags mode) delta +
      GeneratedArm64MemOffset.value (GeneratedArm64MemPrepost.suppressOffset (flags mode)) false delta 0 =
        if mode = .post then 0 else delta := by
  cases mode <;> simp [flags, GeneratedArm64MemPrepost.preDelta,
    GeneratedArm64MemPrepost.preWriteback, GeneratedArm64MemPrepost.postWriteback,
    GeneratedArm64MemPrepost.flags, GeneratedArm64MemPrepost.suppressOffset,
    GeneratedArm64MemOffset.value]

theorem base_delta_refines (mode : Writeback) (delta : Word) :
    GeneratedArm64MemPrepost.preDelta (flags mode) delta +
      GeneratedArm64MemPrepost.postDelta (flags mode) delta =
        if mode = .none then 0 else delta := by
  cases mode <;> simp [flags, GeneratedArm64MemPrepost.preDelta,
    GeneratedArm64MemPrepost.postDelta, GeneratedArm64MemPrepost.preWriteback,
    GeneratedArm64MemPrepost.postWriteback, GeneratedArm64MemPrepost.flags]

/-- Compose the existing full-state ordinary memory refinement at the computed
native address. Writeback is committed only on a successful transfer. -/
def handlerStep (i : AddressedMemoryInstruction) (s : AArch64.State) : Transition AArch64.State :=
  let offset := memoryOffset s i.width.scale i.offset
  let result := Arm64Memory.handlerStep ⟨i.width, i.transfer, i.base,
    if i.writeback = .post then 0 else offset⟩ s
  if result.fault.isSome || i.writeback = .none then result
  else { result with state := writeMemoryBase result.state i.base (memoryBase s i.base + offset) }

theorem step_refines (i : AddressedMemoryInstruction) (s : AArch64.State)
    (alignment : spAlignmentFault s i.base = none) :
    handlerStep i s = AArch64.step (.addressedMemory i) s := by
  have refined := Arm64Memory.step_refines
    (⟨i.width, i.transfer, i.base, if i.writeback = .post then 0 else memoryOffset s i.width.scale i.offset⟩ : MemoryInstruction)
    s alignment
  simp only [AArch64.step] at refined
  simp only [handlerStep, AArch64.step, addressedMemoryStep, refined]

def pairHandlerStep (i : AddressedPairMemoryInstruction) (s : AArch64.State) : Transition AArch64.State :=
  let transfer := if i.writeback = .post then { i.instruction with offset := 0 } else i.instruction
  let result := Arm64PairMemory.handlerStep transfer s
  if result.fault.isSome || i.writeback = .none then result
  else { result with state := writeMemoryBase result.state i.instruction.base (memoryBase s i.instruction.base + i.instruction.offset) }

theorem pair_step_refines (i : AddressedPairMemoryInstruction) (s : AArch64.State)
    (alignment : spAlignmentFault s i.instruction.base = none) :
    pairHandlerStep i s = AArch64.step (.addressedPairMemory i) s := by
  let transfer := if i.writeback = .post then { i.instruction with offset := 0 } else i.instruction
  have aligned : spAlignmentFault s transfer.base = none := by
    dsimp only [transfer]
    split <;> exact alignment
  have refined := Arm64PairMemory.step_refines transfer s aligned
  simp only [AArch64.step] at refined
  simp only [pairHandlerStep, AArch64.step, addressedPairMemoryStep]
  rw [refined]

end KProgFormal.Refinement.Arm64AddressedMemory
