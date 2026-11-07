import KProgFormal.Refinement.Arm64Move
import KProgFormal.Refinement.Arm64Movk
import KProgFormal.Refinement.Arm64Branch
import KProgFormal.Generated.GeneratedArm64Adrp

namespace KProgFormal.Refinement.Arm64Dispatcher

open Reference
open Reference.AArch64 (Width Register RegisterRef KeepInstruction)

/-- Numeric projection of the two MOV bodies, with actual register-byte
selection and the production pointer-first MOV_REG/X branch. Materialized
pointer values and provenance remain the shared Entry/O4 relation. -/
def moveBody (op : GeneratedArm64Mov.Mov) (width : Width) (dst src : Byte) (immediate : Word)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let state := if GeneratedArm64Mov.ptrTagPath op (Arm64Register.handlerWidth width) then
      Arm64Move.Fields.write s dst (Arm64Move.Fields.read s src) .w64
    else
      let value := if GeneratedArm64ImmOperand.immediate (Arm64Move.operandOp op)
        then immediate else Arm64Move.Fields.read s src
      Arm64Move.Fields.write s dst value width
  ⟨{ state with pc := s.pc + 4 }, [], none⟩

theorem move_body_refines (op : GeneratedArm64Mov.Mov) (width : Width) (dst src : Byte) (immediate : Word)
    (s : Reference.AArch64.State) :
    moveBody op width dst src immediate s =
      Arm64Move.rawStep op width (Arm64Move.Fields.decode dst) (Arm64Move.Fields.decode src) immediate s := by
  simp only [moveBody, Arm64Move.rawStep, Arm64Move.Fields.read_refines,
    Arm64Move.Fields.write_refines, Arm64Move.read_data_refines, Arm64Move.width_write_refines]

def addressBody (dst : Byte) (immediate : Word) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  ⟨{ Arm64Move.Fields.write s dst immediate .w64 with pc := s.pc + 4 }, [], none⟩

def keepBody (column : GeneratedArm64Movk.MovkShift) (width : Width) (dst : Byte)
    (immediate : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Movk.value column (Arm64Move.Fields.read s dst) immediate
  ⟨{ Arm64Move.Fields.write s dst value width with pc := s.pc + 4 }, [], none⟩

/-- The actual first four branch gates, in production order. None passes to
the remaining dispatcher: it is not an unsupported-operation policy. The
canonical ISA remains Reference/AArch64.lean; these are implementation bodies. -/
def dispatchPrefix (code : Nat) (aux : BitVec 32) (width : Width) (dst src : Byte) (immediate : Word)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  if code = GeneratedArm64DispatchSingleton.code .nop then some (Arm64Branch.nopStep s)
  else if code = GeneratedArm64Adrp.code .got ∨ code = GeneratedArm64Adrp.code .rodata then
    some (addressBody dst immediate s)
  else match Arm64Move.decodeOpcode code with
    | some op => some (moveBody op width dst src immediate s)
    | none => if code = GeneratedArm64DispatchSingleton.code .movk then
        (Arm64Movk.decodeShift (GeneratedArm64Aux.b2 aux).toNat).map (fun shift => keepBody shift width dst immediate s)
      else none

theorem nop_refines (aux : BitVec 32) (width : Width) (dst src : Byte) (immediate : Word)
    (s : Reference.AArch64.State) :
    dispatchPrefix (GeneratedArm64DispatchSingleton.code .nop) aux width dst src immediate s =
      some (Reference.AArch64.step .nop s) := rfl

/-- Both relocation kinds reach the same native address value. The linker
must bind IMM to this exact PC-relative/page-relative address; tags retain
the separate GOT/rodata distinction of the generated table. -/
theorem address_refines (op : GeneratedArm64Adrp.Op) (page : Bool) (dst : Register)
    (displacement : Word) (aux : BitVec 32) (width : Width) (src : Byte) (s : Reference.AArch64.State) :
    dispatchPrefix (GeneratedArm64Adrp.code op) aux width (Arm64Register.registerCode dst) src
      (Arm64Branch.pcAddress page s.pc displacement) s =
      some (Reference.AArch64.step (.pcAddress page dst displacement) s) := by
  have reached : dispatchPrefix (GeneratedArm64Adrp.code op) aux width (Arm64Register.registerCode dst) src
      (Arm64Branch.pcAddress page s.pc displacement) s =
      some (addressBody (Arm64Register.registerCode dst) (Arm64Branch.pcAddress page s.pc displacement) s) := by
    cases op <;> rfl
  rw [reached]
  simp only [addressBody, Arm64Move.Fields.register_write]
  exact congrArg some (Arm64Branch.pc_address_step_refines page dst displacement s)

theorem move_reached (op : GeneratedArm64Mov.Mov) (aux : BitVec 32) (width : Width)
    (dst src : Byte) (immediate : Word) (s : Reference.AArch64.State) :
    dispatchPrefix (GeneratedArm64Mov.code op) aux width dst src immediate s =
      some (moveBody op width dst src immediate s) := by cases op <;> rfl

theorem move_register_refines (aux : BitVec 32) (width : Width) (dst src : RegisterRef)
    (immediate : Word) (s : Reference.AArch64.State) :
    dispatchPrefix (GeneratedArm64Mov.code .movReg) aux width
      (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) immediate s =
      some (Reference.AArch64.step (.moveRegister width dst src) s) := by
  rw [move_reached, move_body_refines, Arm64Move.Fields.decode_encode,
    Arm64Move.Fields.decode_encode, Arm64Move.raw_register_refines]

theorem move_immediate_refines (aux : BitVec 32) (width : Width) (dst : Register) (src : Byte)
    (immediate : Word) (s : Reference.AArch64.State) :
    dispatchPrefix (GeneratedArm64Mov.code .movImm) aux width
      (Arm64Move.Fields.encode (Arm64Move.scalarDestination dst)) src immediate s =
      some (Reference.AArch64.step (.moveImmediate width dst immediate) s) := by
  rw [move_reached, move_body_refines, Arm64Move.Fields.decode_encode, Arm64Move.raw_immediate_refines]

theorem move_bitmask_refines (aux : BitVec 32) (width : Width) (dst : RegisterRef) (src : Byte)
    (immediate : Word) (s : Reference.AArch64.State) :
    dispatchPrefix (GeneratedArm64Mov.code .movImm) aux width (Arm64Move.Fields.encode dst) src immediate s =
      some (Reference.AArch64.step (.logicImmediate width (.disjunction false) dst 31 immediate) s) := by
  rw [move_reached, move_body_refines, Arm64Move.Fields.decode_encode, Arm64Move.immediate_bitmask_refines]

theorem keep_reached (aux : BitVec 32) (width : Width) (dst src : Byte)
    (immediate : Word) (s : Reference.AArch64.State) :
    dispatchPrefix (GeneratedArm64DispatchSingleton.code .movk) aux width dst src immediate s =
      (Arm64Movk.decodeShift (GeneratedArm64Aux.b2 aux).toNat).map (fun shift => keepBody shift width dst immediate s) := rfl

theorem keep_refines (i : KeepInstruction) (lane0 lane1 lane3 src : Byte) (s : Reference.AArch64.State) :
    dispatchPrefix (GeneratedArm64DispatchSingleton.code .movk)
      (Arm64Movk.packedAux (BitVec.ofNat 32 (16*i.column.val)) lane0 lane1 lane3)
      i.width (Arm64Register.registerCode i.dst) src (i.immediate.setWidth 64) s =
      some (Reference.AArch64.step (.keep i) s) := by
  rw [keep_reached, Arm64Movk.packed_column]
  change some (keepBody (Arm64Movk.column i.column.val) i.width (Arm64Register.registerCode i.dst)
    (i.immediate.setWidth 64) s) = _
  simp only [keepBody, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]
  exact congrArg some (Arm64Movk.step_refines i s)

theorem other (code : Nat) (aux : BitVec 32) (width : Width) (dst src : Byte) (immediate : Word)
    (s : Reference.AArch64.State) (notNop : code ≠ GeneratedArm64DispatchSingleton.code .nop)
    (notGot : code ≠ GeneratedArm64Adrp.code .got) (notRodata : code ≠ GeneratedArm64Adrp.code .rodata)
    (notImm : code ≠ GeneratedArm64Mov.code .movImm) (notReg : code ≠ GeneratedArm64Mov.code .movReg)
    (notKeep : code ≠ GeneratedArm64DispatchSingleton.code .movk) :
    dispatchPrefix code aux width dst src immediate s = none := by
  have moveNone : Arm64Move.decodeOpcode code = none := by simp [Arm64Move.decodeOpcode, notImm, notReg]
  simp [dispatchPrefix, notNop, notGot, notRodata, notKeep, moveNone]

/-- Operand normalization for the covered production gates. Constructors
contain only field/code/address identities, never a handler-refinement or
step-equality premise. Native decoding/relocation validity must supply these
identities; the relation itself is not a native-byte decoder certificate. -/
inductive Binding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | nop (aux : BitVec 32) (width : Width) (dst src : Byte) (immediate : Word) :
      Binding pc (GeneratedArm64DispatchSingleton.code .nop) aux width dst src immediate .nop
  | address (op : GeneratedArm64Adrp.Op) (page : Bool) (dst : Register) (displacement : Word)
      (aux : BitVec 32) (width : Width) (src : Byte) :
      Binding pc (GeneratedArm64Adrp.code op) aux width (Arm64Register.registerCode dst) src
        (Arm64Branch.pcAddress page pc displacement) (.pcAddress page dst displacement)
  | moveImmediate (aux : BitVec 32) (width : Width) (dst : Register) (src : Byte) (immediate : Word) :
      Binding pc (GeneratedArm64Mov.code .movImm) aux width
        (Arm64Move.Fields.encode (Arm64Move.scalarDestination dst)) src immediate (.moveImmediate width dst immediate)
  | moveRegister (aux : BitVec 32) (width : Width) (dst src : RegisterRef) (immediate : Word) :
      Binding pc (GeneratedArm64Mov.code .movReg) aux width
        (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) immediate (.moveRegister width dst src)
  | moveBitmask (aux : BitVec 32) (width : Width) (dst : RegisterRef) (src : Byte) (immediate : Word) :
      Binding pc (GeneratedArm64Mov.code .movImm) aux width (Arm64Move.Fields.encode dst) src immediate
        (.logicImmediate width (.disjunction false) dst 31 immediate)
  | keep (i : KeepInstruction) (lane0 lane1 lane3 src : Byte) :
      Binding pc (GeneratedArm64DispatchSingleton.code .movk)
        (Arm64Movk.packedAux (BitVec.ofNat 32 (16*i.column.val)) lane0 lane1 lane3)
        i.width (Arm64Register.registerCode i.dst) src (i.immediate.setWidth 64) (.keep i)

/-- One concrete dispatcher-prefix step theorem for every normalization
constructor, including SP and bitmask aliases. It composes the actual gates
and generated bodies without assuming the component refinement statements. -/
theorem step_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src : Byte) (immediate : Word)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : Binding s.pc code aux width dst src immediate native) :
    dispatchPrefix code aux width dst src immediate s = some (Reference.AArch64.step native s) := by
  cases binding with
  | nop => apply nop_refines
  | address => apply address_refines
  | moveImmediate => apply move_immediate_refines
  | moveRegister => apply move_register_refines
  | moveBitmask => apply move_bitmask_refines
  | keep => apply keep_refines

end KProgFormal.Refinement.Arm64Dispatcher
