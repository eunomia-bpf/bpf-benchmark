import KProgFormal.Arm64Mul
import KProgFormal.Refinement.Arm64Register

namespace KProgFormal.Refinement.Arm64Mul

open Reference
open Reference.AArch64 (Width MulInstruction)
open Arm64Register (handlerWidth readReg writeReg)

theorem input_width_refines (value : Reference.Word) (width : Width) :
    GeneratedArm64Width.narrow value (handlerWidth width) =
      Reference.AArch64.narrow value width := by
  cases width <;>
    simp only [handlerWidth, GeneratedArm64Width.narrow, GeneratedArm64Width.mask,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits, Reference.Word] <;> bv_decide

theorem narrow_full (value : Reference.Word) :
    Reference.AArch64.narrow value .w64 = value := by rfl

/-- Arm X[n,datasize] narrows all three MADD/MSUB inputs. The generated
handler may defer that narrowing to its write without changing the result. -/
theorem multiply_width_refines (width : Width) (subtract : Bool)
    (lhs rhs addend : Reference.Word) :
    let op := if subtract then Reference.AArch64.MulOp.msub else .madd
    Reference.AArch64.narrow (Reference.AArch64.mulValue op lhs rhs addend) width =
      Reference.AArch64.narrow (Reference.AArch64.mulValue op
        (Reference.AArch64.narrow lhs width) (Reference.AArch64.narrow rhs width)
        (Reference.AArch64.narrow addend width)) width := by
  cases width <;> cases subtract <;>
    simp only [Reference.AArch64.narrow, Reference.AArch64.Width.bits,
      Reference.AArch64.mulValue, Bool.false_eq_true, ↓reduceIte, Reference.Word] <;> bv_decide

/-- The generated multiply-family expressions feed the real generated width
and GPR write selectors. UDIV narrows both inputs before division, unlike the
multiply arms whose final narrowing suffices. NZCV/vector/SP/memory are retained. -/
def handlerState (i : MulInstruction) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  match i with
  | .multiply width subtract dst lhs rhs addend =>
      let op := if subtract then GeneratedArm64Mul.Mul.msub else .madd
      let value := GeneratedArm64Mul.value op (readReg s lhs) (readReg s rhs) (readReg s addend)
      writeReg s dst value width
  | .longMultiply signed dst lhs rhs addend =>
      let op := if signed then GeneratedArm64Mul.Mul.smaddl else .umaddl
      let value := GeneratedArm64Mul.value op (readReg s lhs) (readReg s rhs) (readReg s addend)
      writeReg s dst value .w64
  | .unsignedHigh dst lhs rhs =>
      writeReg s dst (GeneratedArm64Mul.value .umulh (readReg s lhs) (readReg s rhs) 0) .w64
  | .unsignedDivide width dst lhs rhs =>
      let lhs := GeneratedArm64Width.narrow (readReg s lhs) (handlerWidth width)
      let rhs := GeneratedArm64Width.narrow (readReg s rhs) (handlerWidth width)
      writeReg s dst (GeneratedArm64Mul.value .udiv lhs rhs 0) width

def handlerStep (i : MulInstruction) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ handlerState i s with pc := s.pc + 4 }, [], none⟩

/-- Exact full-state equality for all multiply/divide register encodings,
including aliased operands, ZR sources/discarded destinations and 32-bit writes. -/
theorem step_refines (i : MulInstruction) (s : Reference.AArch64.State) :
    handlerStep i s = Reference.AArch64.step (.mul i) s := by
  cases i with
  | multiply width subtract dst lhs rhs addend =>
      have h := multiply_width_refines width subtract
        (Reference.AArch64.readReg s lhs) (Reference.AArch64.readReg s rhs)
        (Reference.AArch64.readReg s addend)
      cases subtract <;>
        simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.mulStep, Reference.AArch64.mulResult,
          Arm64Register.read_refines, Arm64Register.write_refines, arm64_mul_refines,
          arm64MulValueSpec, arm64MulToReference, Bool.false_eq_true, ↓reduceIte] at h ⊢
      all_goals rw [h]
  | longMultiply signed dst lhs rhs addend =>
      cases signed <;>
        simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.mulStep, Reference.AArch64.mulResult,
          Arm64Register.read_refines, Arm64Register.write_refines, arm64_mul_refines,
          arm64MulValueSpec, arm64MulToReference, Bool.false_eq_true, ↓reduceIte, narrow_full]
  | unsignedHigh dst lhs rhs =>
      simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.mulStep, Reference.AArch64.mulResult,
        Arm64Register.read_refines, Arm64Register.write_refines, arm64_mul_refines,
        arm64MulValueSpec, arm64MulToReference, narrow_full]
  | unsignedDivide width dst lhs rhs =>
      simp only [handlerStep, handlerState, Reference.AArch64.step, Reference.AArch64.mulStep, Reference.AArch64.mulResult,
        Arm64Register.read_refines, Arm64Register.write_refines, input_width_refines,
        arm64_mul_refines, arm64MulValueSpec, arm64MulToReference]

theorem handler_refines (i : MulInstruction) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.mul i) s (handlerStep i s) := (step_refines i s).symm

/-- MUL/UMULL select their own production opcode, while their native encodings
are MADD/UMADDL with Ra=ZR. The extra argument read by the C macro is unused. -/
def aliasStep (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs : Reference.AArch64.Register) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let value := GeneratedArm64Mul.value op (readReg s lhs) (readReg s rhs) 0
  ⟨{ writeReg s dst value width with pc := s.pc + 4 }, [], none⟩

theorem mul_refines (width : Width) (dst lhs rhs : Reference.AArch64.Register)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.mul (.multiply width false dst lhs rhs 31)) s
      (aliasStep .mul width dst lhs rhs s) := by
  unfold Reference.AArch64.Step
  rw [← step_refines]
  simp only [handlerStep, handlerState, aliasStep, Bool.false_eq_true, ↓reduceIte,
    GeneratedArm64Mul.value]
  have hz : readReg s 31 = 0 := by rw [Arm64Register.read_refines]; rfl
  have hadd (v : Reference.Word) : v + 0 = v := by
    simp only [Reference.Word]; bv_decide
  simp only [hz, hadd]

theorem umull_refines (dst lhs rhs : Reference.AArch64.Register)
    (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.mul (.longMultiply false dst lhs rhs 31)) s
      (aliasStep .umull .w64 dst lhs rhs s) := by
  unfold Reference.AArch64.Step
  rw [← step_refines]
  simp only [handlerStep, handlerState, aliasStep, Bool.false_eq_true, ↓reduceIte,
    GeneratedArm64Mul.value]
  have hz : readReg s 31 = 0 := by rw [Arm64Register.read_refines]; rfl
  have hadd (v : Reference.Word) : v + 0 = v := by
    simp only [Reference.Word]; bv_decide
  simp only [hz, hadd]

end KProgFormal.Refinement.Arm64Mul
