import KProgFormal.Refinement.Arm64Register
import KProgFormal.Arm64Mov
import KProgFormal.Arm64ImmOperand

namespace KProgFormal.Refinement.Arm64Move

open Reference
open Reference.AArch64 (Width Register RegisterRef)

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


def arithmeticRegister (r : Reference.AArch64.Gpr) : Reference.AArch64.Register := ⟨r.val, by omega⟩

/-- After the SP-special-case selector, these are the actual generated GPR
cell reads. ZR routes through the generated absent-cell result. -/
def readData (s : Reference.AArch64.State) : RegisterRef → Reference.Word
  | .general r => Arm64Register.readReg s (arithmeticRegister r)
  | .zero => Arm64Register.readReg s 31
  | .stack => s.sp

theorem read_data_refines (s : Reference.AArch64.State) (src : RegisterRef) :
    readData s src = Reference.AArch64.readData s src := by
  cases src with
  | general r =>
    simp only [readData, Arm64Register.read_refines, Reference.AArch64.readData,
      Reference.AArch64.readReg, arithmeticRegister, r.isLt, ↓reduceDIte]
  | zero => rw [readData, Arm64Register.read_refines]; rfl
  | stack => rfl

/-- Width writes already have a separate SP branch. The pointer route added
by ceed44baf has that same SP branch and a full-width GPR store. -/
def widthWrite (s : Reference.AArch64.State) (dst : RegisterRef) (value : Reference.Word)
    (width : Width) : Reference.AArch64.State :=
  match dst with
  | .general r => Arm64Register.writeReg s (arithmeticRegister r) value width
  | .zero => Arm64Register.writeReg s 31 value width
  | .stack => { s with sp := Arm64Register.writeValue width value }

theorem width_write_refines (s : Reference.AArch64.State) (dst : RegisterRef)
    (value : Reference.Word) (width : Width) :
    widthWrite s dst value width = Reference.AArch64.writeData s dst value width := by
  cases dst with
  | general r =>
    simp only [widthWrite, Arm64Register.write_refines, Reference.AArch64.writeData,
      Reference.AArch64.writeReg, arithmeticRegister]
  | stack => simp only [widthWrite, Arm64Register.write_value_refines, Reference.AArch64.writeData]
  | zero =>
    simp only [widthWrite, Arm64Register.write_refines, Reference.AArch64.writeData, Reference.AArch64.writeReg]
    congr 1
    funext i
    change (if i.val = 31 then Reference.AArch64.narrow value width else s.gpr i) = s.gpr i
    rw [if_neg (show i.val ≠ 31 by omega)]

def registerStep (width : Width) (dst src : RegisterRef) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let value := readData s src
  let state := if GeneratedArm64Mov.ptrTagPath .movReg (Arm64Register.handlerWidth width)
    then widthWrite s dst value .w64 else widthWrite s dst value width
  ⟨{ state with pc := s.pc + 4 }, [], none⟩

theorem register_step_refines (width : Width) (dst src : RegisterRef) (s : Reference.AArch64.State) :
    registerStep width dst src s = Reference.AArch64.step (.moveRegister width dst src) s := by
  cases width <;>
    simp only [registerStep, Reference.AArch64.step, Reference.AArch64.moveRegStep, GeneratedArm64Mov.ptrTagPath,
      Arm64Register.handlerWidth, width_write_refines, read_data_refines,
      Bool.false_eq_true, ↓reduceIte]

theorem register_handler_refines (width : Width) (dst src : RegisterRef) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.moveRegister width dst src) s (registerStep width dst src s) :=
  (register_step_refines width dst src s).symm

end KProgFormal.Refinement.Arm64Move
