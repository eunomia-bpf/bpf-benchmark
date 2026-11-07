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


/-- Bind the move gate and the independent immediate-selection contract to
exactly the same operation numbers. Shift rows in that contract cannot enter
this move body. -/
def decodeOpcode (opcode : Nat) : Option GeneratedArm64Mov.Mov :=
  if opcode = GeneratedArm64Mov.code .movImm then some .movImm
  else if opcode = GeneratedArm64Mov.code .movReg then some .movReg else none

def operandOp : GeneratedArm64Mov.Mov → GeneratedArm64ImmOperand.ImmOp
  | .movImm => .movImm | .movReg => .movReg

theorem operand_code (op : GeneratedArm64Mov.Mov) :
    GeneratedArm64ImmOperand.code (operandOp op) = GeneratedArm64Mov.code op := by cases op <;> rfl

theorem operand_immediate (op : GeneratedArm64Mov.Mov) :
    GeneratedArm64ImmOperand.immediate (operandOp op) = (op == .movImm) := by cases op <;> rfl

/-- An immediate destination is a GPR/ZR field. Unlike register MOV, it cannot
silently reinterpret architectural field31 as SP. -/
def scalarDestination (dst : Register) : RegisterRef :=
  if h : dst.val < 31 then .general ⟨dst.val, h⟩ else .zero

theorem scalar_destination_write (s : Reference.AArch64.State) (dst : Register)
    (value : Word) (width : Width) :
    widthWrite s (scalarDestination dst) value width = Arm64Register.writeReg s dst value width := by
  unfold scalarDestination
  split
  · rfl
  · have equal : dst = 31 := Fin.ext (by have := dst.isLt; omega)
    subst dst
    rfl

/-- The production body tests provenance-preserving MOV_REG/X first. Its
numeric projection reads the incoming SP/GPR/ZR before any write; the scalar
arm alone consumes the generated immediate/register selector. Native address
materialization and provenance transport remain Entry/O4 obligations. -/
def rawStep (op : GeneratedArm64Mov.Mov) (width : Width) (dst src : RegisterRef)
    (immediate : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let state := if GeneratedArm64Mov.ptrTagPath op (Arm64Register.handlerWidth width) then
      widthWrite s dst (readData s src) .w64
    else
      let value := if GeneratedArm64ImmOperand.immediate (operandOp op) then immediate else readData s src
      widthWrite s dst value width
  ⟨{ state with pc := s.pc + 4 }, [], none⟩

theorem raw_immediate_refines (width : Width) (dst : Register) (src : RegisterRef)
    (immediate : Word) (s : Reference.AArch64.State) :
    rawStep .movImm width (scalarDestination dst) src immediate s =
      Reference.AArch64.step (.moveImmediate width dst immediate) s := by
  simp only [rawStep, GeneratedArm64Mov.ptrTagPath, Bool.false_eq_true, ↓reduceIte,
    operandOp, GeneratedArm64ImmOperand.immediate, scalar_destination_write]
  change immediateStep width dst immediate s = _
  exact immediate_step_refines width dst immediate s

theorem raw_register_refines (width : Width) (dst src : RegisterRef) (immediate : Word)
    (s : Reference.AArch64.State) :
    rawStep .movReg width dst src immediate s =
      Reference.AArch64.step (.moveRegister width dst src) s := by
  change registerStep width dst src s = _
  exact register_step_refines width dst src s

def dispatch (opcode : Nat) (width : Width) (dst src : RegisterRef) (immediate : Word)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  (decodeOpcode opcode).map (fun op => rawStep op width dst src immediate s)

theorem dispatch_immediate_refines (width : Width) (dst : Register) (src : RegisterRef)
    (immediate : Word) (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Mov.code .movImm) width (scalarDestination dst) src immediate s =
      some (Reference.AArch64.step (.moveImmediate width dst immediate) s) := by
  change some (rawStep .movImm width (scalarDestination dst) src immediate s) = _
  rw [raw_immediate_refines]

theorem dispatch_register_refines (width : Width) (dst src : RegisterRef) (immediate : Word)
    (s : Reference.AArch64.State) :
    dispatch (GeneratedArm64Mov.code .movReg) width dst src immediate s =
      some (Reference.AArch64.step (.moveRegister width dst src) s) := by
  change some (rawStep .movReg width dst src immediate s) = _
  rw [raw_register_refines]

theorem dispatch_other (opcode : Nat) (width : Width) (dst src : RegisterRef) (immediate : Word)
    (s : Reference.AArch64.State) (notImm : opcode ≠ GeneratedArm64Mov.code .movImm)
    (notReg : opcode ≠ GeneratedArm64Mov.code .movReg) :
    dispatch opcode width dst src immediate s = none := by simp [dispatch, decodeOpcode, notImm, notReg]

end KProgFormal.Refinement.Arm64Move
