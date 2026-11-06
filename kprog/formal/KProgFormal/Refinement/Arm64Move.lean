import KProgFormal.Refinement.Arm64Register
import KProgFormal.Arm64Mov
import KProgFormal.Arm64ImmOperand

namespace KProgFormal.Refinement.Arm64Move

open Reference
open Reference.AArch64 (Width Register)

/-- MOV_IMM selects the decoded word through the generated operand table,
then the generated width and destination-cell write arms. Its scalar path is
proved separately below; no pointer-write assumption is made for MOV_REG/SP. -/
def immediateStep (width : Width) (dst : Register) (value : Reference.Word)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let source := if GeneratedArm64ImmOperand.immediate .movImm then value else 0
  ⟨{ Arm64Register.writeReg s dst source width with pc := s.pc + 4 }, [], none⟩

theorem immediate_step_refines (width : Width) (dst : Register) (value : Reference.Word)
    (s : Reference.AArch64.State) :
    immediateStep width dst value s = Reference.AArch64.step (.moveImmediate width dst value) s := by
  simp only [immediateStep, GeneratedArm64ImmOperand.immediate, ↓reduceIte,
    Arm64Register.write_refines, Reference.AArch64.step]

theorem immediate_handler_refines (width : Width) (dst : Register) (value : Reference.Word)
    (s : Reference.AArch64.State) :
    GeneratedArm64Mov.ptrTagPath .movImm (Arm64Register.handlerWidth width) = false ∧
    Reference.AArch64.Step (.moveImmediate width dst value) s (immediateStep width dst value s) :=
  ⟨arm64_mov_imm_never_ptr _, (immediate_step_refines width dst value s).symm⟩

end KProgFormal.Refinement.Arm64Move
