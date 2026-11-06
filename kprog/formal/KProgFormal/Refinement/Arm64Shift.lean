import KProgFormal.Refinement.Arm64Register
import KProgFormal.Arm64Mod
import KProgFormal.Arm64Unary
import KProgFormal.Arm64Shift

namespace KProgFormal.Refinement.Arm64Shift

open Reference
open Reference.AArch64 (Width ShiftKind ShiftInstruction)
open Arm64Register (handlerWidth readReg writeReg)

def shiftCode : ShiftKind → GeneratedArm64ShiftDecode.Shift
  | .lsl => .lsl | .lsr => .lsr | .asr => .asr | .ror => .ror

def modifier : ShiftKind → GeneratedArm64ModDecode.Mod
  | .lsl => .lsl | .lsr => .lsr | .asr => .asr | .ror => .ror

theorem shift_value_refines (width : Width) (kind : ShiftKind) (value amount : Reference.Word) :
    Reference.AArch64.narrow
      (GeneratedArm64Shift.value (shiftCode kind) value amount (handlerWidth width)) width =
      Reference.AArch64.shiftValue width kind value amount := by
  cases width <;> cases kind <;>
    simp only [GeneratedArm64Shift.value, shiftCode, handlerWidth,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.shiftValue, Reference.AArch64.extractValue,
      Reference.AArch64.extractRawWindow, Reference.Word] <;> bv_decide

/-- Generated MVN/NEG consume the modifier before the unary operation. ASR may
sign-extend in the temporary, but only architectural low bits reach writeback. -/
theorem unary_value_refines (width : Width) (kind : ShiftKind) (value amount : Reference.Word) :
    GeneratedArm64Unary.value .mvn
        (GeneratedArm64Mod.value (modifier kind) value amount (handlerWidth width)) (handlerWidth width) =
      Reference.AArch64.narrow (~~~(Reference.AArch64.shiftValue width kind value amount)) width ∧
    GeneratedArm64Unary.value .neg
        (GeneratedArm64Mod.value (modifier kind) value amount (handlerWidth width)) (handlerWidth width) =
      Reference.AArch64.narrow (-(Reference.AArch64.shiftValue width kind value amount)) width := by
  cases width <;> cases kind <;>
    simp only [GeneratedArm64Mod.value, GeneratedArm64Unary.value, modifier, handlerWidth,
      GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.shiftValue, Reference.AArch64.extractValue,
      Reference.AArch64.extractRawWindow, Reference.Word] <;>
    constructor <;> bv_decide

theorem narrow_idempotent (width : Width) (value : Reference.Word) :
    Reference.AArch64.narrow (Reference.AArch64.narrow value width) width =
      Reference.AArch64.narrow value width := by
  cases width <;>
    simp only [Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.Word] <;> bv_decide

def handlerState (i : ShiftInstruction) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  match i with
  | .register width kind dst src count =>
      writeReg s dst (GeneratedArm64Shift.value (shiftCode kind)
        (readReg s src) (readReg s count) (handlerWidth width)) width
  | .immediate width kind amount dst src =>
      writeReg s dst (GeneratedArm64Shift.value (shiftCode kind)
        (readReg s src) (BitVec.ofNat 64 amount.val) (handlerWidth width)) width
  | .invert width kind amount dst src =>
      let source := GeneratedArm64Mod.value (modifier kind) (readReg s src)
        (BitVec.ofNat 64 amount.val) (handlerWidth width)
      writeReg s dst (GeneratedArm64Unary.value .mvn source (handlerWidth width)) width
  | .negate width kind amount dst src =>
      let source := GeneratedArm64Mod.value (modifier (Reference.AArch64.arithmeticShift kind))
        (readReg s src) (BitVec.ofNat 64 amount.val) (handlerWidth width)
      writeReg s dst (GeneratedArm64Unary.value .neg source (handlerWidth width)) width

def handlerStep (i : ShiftInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ handlerState i s with pc := s.pc + 4 }, [], none⟩

theorem step_refines (i : ShiftInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.shift i) s := by
  cases i <;>
    simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.shiftStep,
      Reference.AArch64.shiftResult, Arm64Register.read_refines, Arm64Register.write_refines,
      shift_value_refines, (unary_value_refines _ _ _ _).1, (unary_value_refines _ _ _ _).2,
      narrow_idempotent]

theorem handler_refines (i : ShiftInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.shift i) s (handlerStep i s) := (step_refines i s).symm

end KProgFormal.Refinement.Arm64Shift
