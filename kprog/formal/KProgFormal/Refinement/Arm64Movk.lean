import KProgFormal.Refinement.Arm64Register
import KProgFormal.Arm64Movk
import KProgFormal.Arm64Aux
import KProgFormal.Generated.GeneratedArm64DispatchSingleton

namespace KProgFormal.Refinement.Arm64Movk

open Reference
open Reference.AArch64 (KeepInstruction)
open Arm64Register (readReg writeReg)

def column (code : Nat) : GeneratedArm64Movk.MovkShift :=
  match code with | 0 => .col0 | 1 => .col16 | 2 => .col32 | _ => .col48

theorem value_refines (code : Nat) (h : code < 4) (dst immediate : Reference.Word) :
    GeneratedArm64Movk.value (column code) dst immediate =
      Reference.AArch64.moveKeepRaw (16 * code) dst immediate := by
  rw [arm64_movk_refines]
  have cases : code = 0 ∨ code = 1 ∨ code = 2 ∨ code = 3 := by omega
  rcases cases with h | h | h | h <;> subst code <;> rfl

def handlerStep (i : KeepInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let result := GeneratedArm64Movk.value (column i.column.val) (readReg s i.dst) (i.immediate.setWidth 64)
  ⟨{ writeReg s i.dst result i.width with pc := s.pc + 4 }, [], none⟩

theorem step_refines (i : KeepInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.keep i) s := by
  have h : i.column.val < 4 := by
    have bound : ∀ width : Reference.AArch64.Width, width.bits / 16 ≤ 4 := by
      intro width
      cases width <;> decide
    exact Nat.lt_of_lt_of_le i.column.isLt (bound i.width)
  simp only [handlerStep, Reference.AArch64.step, Reference.AArch64.keepStep, Arm64Register.read_refines,
    Arm64Register.write_refines, value_refines _ h]

theorem handler_refines (i : KeepInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.keep i) s (handlerStep i s) := (step_refines i s).symm

/-- Native W instructions admit columns0/1 and X instructions0..3.
This is source validity, not a new runtime guard in the simulator. -/
theorem native_column_bound (i : KeepInstruction) : i.column.val < 4 := by
  have bound : ∀ width : Reference.AArch64.Width, width.bits / 16 ≤ 4 := by
    intro width
    cases width <;> decide
  exact Nat.lt_of_lt_of_le i.column.isLt (bound i.width)

def packedAux (shift : BitVec 32) (lane0 lane1 lane3 : Byte) : BitVec 32 :=
  GeneratedArm64Aux.pack (lane0.setWidth 32) (lane1.setWidth 32) shift (lane3.setWidth 32)

/-- The C switch consumes actual bit columns, not the small column ordinal.
An out-of-set shift reaches the unsupported arm; it is never aliased to48. -/
def decodeShift (shift : Nat) : Option GeneratedArm64Movk.MovkShift :=
  if shift = 0 then some .col0 else if shift = 16 then some .col16
  else if shift = 32 then some .col32 else if shift = 48 then some .col48
  else none

theorem packed_column (i : KeepInstruction) (lane0 lane1 lane3 : Byte) :
    decodeShift (GeneratedArm64Aux.b2
      (packedAux (BitVec.ofNat 32 (16 * i.column.val)) lane0 lane1 lane3)).toNat =
      some (column i.column.val) := by
  simp only [packedAux, arm64_aux_b2_roundtrip]
  have bound := native_column_bound i
  have cases : i.column.val = 0 ∨ i.column.val = 1 ∨ i.column.val = 2 ∨ i.column.val = 3 := by omega
  rcases cases with h | h | h | h <;> simp only [h] <;> rfl

/-- Generated insertion body with the independently decoded shift column,
then the actual destination-width register write and one PC advance. -/
def rawStep (shift : GeneratedArm64Movk.MovkShift) (width : Reference.AArch64.Width)
    (dst : Reference.AArch64.Register) (immediate : Reference.Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let result := GeneratedArm64Movk.value shift (readReg s dst) immediate
  ⟨{ writeReg s dst result width with pc := s.pc + 4 }, [], none⟩

def dispatch (opcode : Nat) (aux : BitVec 32) (width : Reference.AArch64.Width)
    (dst : Reference.AArch64.Register) (immediate : Reference.Word) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  if opcode = GeneratedArm64DispatchSingleton.code .movk then
    (decodeShift (GeneratedArm64Aux.b2 aux).toNat).map (fun shift => rawStep shift width dst immediate s)
  else none

theorem dispatch_refines (i : KeepInstruction) (lane0 lane1 lane3 : Byte)
    (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64DispatchSingleton.code .movk)
      (packedAux (BitVec.ofNat 32 (16 * i.column.val)) lane0 lane1 lane3)
      i.width i.dst (i.immediate.setWidth 64) s = some (Reference.AArch64.step (.keep i) s) := by
  simp only [dispatch, ↓reduceIte, packed_column]
  change some (handlerStep i s) = _
  rw [step_refines]

theorem dispatch_bad_column (opcode : Nat) (aux : BitVec 32) (width : Reference.AArch64.Width)
    (dst : Reference.AArch64.Register) (immediate : Reference.Word) (s : Reference.AArch64.State)
    (not0 : (GeneratedArm64Aux.b2 aux).toNat ≠ 0) (not16 : (GeneratedArm64Aux.b2 aux).toNat ≠ 16)
    (not32 : (GeneratedArm64Aux.b2 aux).toNat ≠ 32) (not48 : (GeneratedArm64Aux.b2 aux).toNat ≠ 48) :
    dispatch opcode aux width dst immediate s = none := by
  simp [dispatch, decodeShift, not0, not16, not32, not48]

theorem dispatch_other (opcode : Nat) (aux : BitVec 32) (width : Reference.AArch64.Width)
    (dst : Reference.AArch64.Register) (immediate : Reference.Word) (s : Reference.AArch64.State)
    (other : opcode ≠ GeneratedArm64DispatchSingleton.code .movk) :
    dispatch opcode aux width dst immediate s = none := by simp [dispatch, other]

end KProgFormal.Refinement.Arm64Movk
