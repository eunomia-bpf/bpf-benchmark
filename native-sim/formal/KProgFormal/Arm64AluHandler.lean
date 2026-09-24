import KProgFormal.GeneratedArm64AluHandler
import KProgFormal.GeneratedPtrAdd
import KProgFormal.Arm64AluResult
import KProgFormal.TagErasure

namespace KProgFormal

open GeneratedArm64AluDecode (Alu)
open GeneratedArm64Width (Width)

/-- Destination classes distinguished by `ARM64_SIM_L_WRITE_REG_WIDTH` and
`ARM64_SIM_L_WRITE_REG_PTR_TAG` after instruction decoding has supplied a
register number. -/
inductive Arm64Destination
  | gpr
  | sp
  | zero
  | none
  deriving DecidableEq, Repr

structure Arm64RegValue where
  bits : BitVec 64
  tag : Tag
  deriving DecidableEq, Repr

/-- The selected general-purpose destination cell and the separately modeled
stack pointer are precisely the state touched by the generic ALU handler. -/
structure Arm64AluHandlerState where
  dst : Arm64RegValue
  sp : BitVec 64
  deriving DecidableEq, Repr

def arm64DestinationIsSp : Arm64Destination -> Bool
  | .sp => true
  | _ => false

def arm64TagIsScalar : Tag -> Bool
  | .scalar => true
  | _ => false

/-- Independent enumeration of the pointer-path condition.  It deliberately
does not reuse the generated conjunction. -/
def arm64AluUsePointerSpec (width : Width) (op : Alu)
    (dst : Arm64Destination) (srcTag : Tag) : Bool :=
  match width, op, dst, srcTag with
  | .w64, .add, .sp, _ => false
  | .w64, .add, _, .scalar => false
  | .w64, .add, _, _ => true
  | _, _, _, _ => false

theorem arm64_alu_handler_path_refines (width : Width) (op : Alu)
    (dst : Arm64Destination) (srcTag : Tag) :
    GeneratedArm64AluHandler.usePointer width op
        (arm64DestinationIsSp dst) (arm64TagIsScalar srcTag) =
      arm64AluUsePointerSpec width op dst srcTag := by
  cases width <;> cases op <;> cases dst <;> cases srcTag <;> decide

/-- Generated scalar writeback: ordinary GPR writes replace the selected
cell and scalarize its provenance; SP writes affect only SP; XZR and NONE
discard the write. -/
def generatedArm64ScalarWrite (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (value : BitVec 64) (width : Width) :
    Arm64AluHandlerState :=
  let value := GeneratedArm64Width.narrow value width
  match dst with
  | .gpr => { state with dst := { bits := value, tag := .scalar } }
  | .sp => { state with sp := value }
  | .zero | .none => state

def arm64ScalarWriteSpec (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (value : BitVec 64) (width : Width) :
    Arm64AluHandlerState :=
  let value := arm64NarrowSpec value width
  match dst with
  | .gpr => { state with dst := { bits := value, tag := .scalar } }
  | .sp => { state with sp := value }
  | .zero | .none => state

theorem arm64_scalar_write_refines (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (value : BitVec 64) (width : Width) :
    generatedArm64ScalarWrite state dst value width =
      arm64ScalarWriteSpec state dst value width := by
  cases dst <;> cases width <;> rfl

/-- Pointer writeback is reachable only when `dst` is not SP.  A real GPR
receives the pointer sum and copied provenance; XZR and NONE discard it. -/
def generatedArm64PointerWrite (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (src : Arm64RegValue) (rhs : BitVec 64) :
    Arm64AluHandlerState :=
  match dst with
  | .gpr => { state with dst := {
      bits := GeneratedPtrAdd.bits src.bits rhs,
      tag := GeneratedPtrAdd.tag src.tag } }
  | .sp | .zero | .none => state

def arm64PointerWriteSpec (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (src : Arm64RegValue) (rhs : BitVec 64) :
    Arm64AluHandlerState :=
  match dst with
  | .gpr => { state with dst := { bits := src.bits + rhs, tag := src.tag } }
  | .sp | .zero | .none => state

theorem arm64_pointer_write_refines (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (src : Arm64RegValue) (rhs : BitVec 64) :
    generatedArm64PointerWrite state dst src rhs =
      arm64PointerWriteSpec state dst src rhs := by
  cases dst <;> rfl

/-- Model of the generic immediate/register ALU handler after decoding and
source-modifier evaluation have supplied typed `op`, `width`, destination,
source value/tag, and right-hand operand. -/
def generatedArm64AluHandler (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (src : Arm64RegValue) (rhs : BitVec 64)
    (width : Width) (op : Alu) : Arm64AluHandlerState :=
  let result := GeneratedArm64AluResult.result op src.bits rhs
  if GeneratedArm64AluHandler.usePointer width op
      (arm64DestinationIsSp dst) (arm64TagIsScalar src.tag) then
    generatedArm64PointerWrite state dst src rhs
  else
    generatedArm64ScalarWrite state dst result width

/-- Independent handler statement.  The pointer path preserves source
provenance for 64-bit ADD; every other arithmetic path performs a width-sized
architectural operation and scalarizes a real GPR destination. -/
def arm64AluHandlerSpec (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (src : Arm64RegValue) (rhs : BitVec 64)
    (width : Width) (op : Alu) : Arm64AluHandlerState :=
  let result := arm64AluResultSpec op src.bits rhs
  if arm64AluUsePointerSpec width op dst src.tag then
    arm64PointerWriteSpec state dst src rhs
  else
    arm64ScalarWriteSpec state dst result width

theorem arm64_alu_handler_refines (state : Arm64AluHandlerState)
    (dst : Arm64Destination) (src : Arm64RegValue) (rhs : BitVec 64)
    (width : Width) (op : Alu) :
    generatedArm64AluHandler state dst src rhs width op =
      arm64AluHandlerSpec state dst src rhs width op := by
  simp only [generatedArm64AluHandler, arm64AluHandlerSpec]
  rw [arm64_alu_handler_path_refines, arm64_alu_result_refines]
  cases h : arm64AluUsePointerSpec width op dst src.tag <;>
    simp only [h, Bool.false_eq_true, ↓reduceIte]
  · exact arm64_scalar_write_refines state dst
      (arm64AluResultSpec op src.bits rhs) width
  · exact arm64_pointer_write_refines state dst src rhs

theorem arm64_tagged_add_uses_pointer_path :
    generatedArm64AluHandler
      { dst := { bits := 0x55, tag := .scalar }, sp := 0x80 }
      .gpr { bits := 0x1000, tag := .packet } 0x20 .w64 .add =
      { dst := { bits := 0x1020, tag := .packet }, sp := 0x80 } := by
  native_decide

theorem arm64_tagged_sub_scalarizes :
    generatedArm64AluHandler
      { dst := { bits := 0x55, tag := .packet }, sp := 0x80 }
      .gpr { bits := 0x1000, tag := .packet } 0x20 .w64 .sub =
      { dst := { bits := 0xfe0, tag := .scalar }, sp := 0x80 } := by
  native_decide

theorem arm64_sp_add_is_scalar_write :
    generatedArm64AluHandler
      { dst := { bits := 0x55, tag := .packet }, sp := 0x80 }
      .sp { bits := 0x1000, tag := .stack } 0x20 .w64 .add =
      { dst := { bits := 0x55, tag := .packet }, sp := 0x1020 } := by
  native_decide

theorem arm64_w32_add_zero_extends_and_scalarizes :
    generatedArm64AluHandler
      { dst := { bits := 0, tag := .packet }, sp := 0 }
      .gpr { bits := 0xffffffff, tag := .packet } 1 .w32 .add =
      { dst := { bits := 0, tag := .scalar }, sp := 0 } := by
  native_decide

end KProgFormal
