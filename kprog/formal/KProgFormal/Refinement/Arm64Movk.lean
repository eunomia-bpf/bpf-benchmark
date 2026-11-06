import KProgFormal.Refinement.Arm64Register
import KProgFormal.Arm64Movk

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

end KProgFormal.Refinement.Arm64Movk
