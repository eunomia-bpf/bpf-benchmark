import KProgFormal.Refinement.Arm64Move
import KProgFormal.Refinement.Arm64Arithmetic
import KProgFormal.Refinement.Arm64Mul
import KProgFormal.Refinement.Arm64Select
import KProgFormal.Refinement.Arm64Bitfield
import KProgFormal.Refinement.Arm64VectorMemory
import KProgFormal.Refinement.Arm64WritebackMemory
import KProgFormal.Generated.GeneratedArm64MemIndexValue
import KProgFormal.Generated.GeneratedArm64LoadTag
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

/-- The six implementation ALU selectors, not a second ISA decoder. -/
def decodeAlu (code : Nat) : Option GeneratedArm64AluDecode.Alu :=
  if code = GeneratedArm64AluDecode.code .add then some .add
  else if code = GeneratedArm64AluDecode.code .sub then some .sub
  else if code = GeneratedArm64AluDecode.code .and then some .and
  else if code = GeneratedArm64AluDecode.code .bic then some .bic
  else if code = GeneratedArm64AluDecode.code .eor then some .eor
  else if code = GeneratedArm64AluDecode.code .orr then some .orr else none

theorem decode_alu_code (op : GeneratedArm64AluDecode.Alu) :
    decodeAlu (GeneratedArm64AluDecode.code op) = some op := by cases op <;> rfl

def aluCode (immediate : Bool) : Nat :=
  GeneratedArm64AluOperandSelect.code (if immediate then .aluImm else .aluReg)

theorem encoded_stack (r : RegisterRef) :
    decide ((Arm64Move.Fields.encode r).toNat = GeneratedArm64RegDispatch.stackNumber) =
      decide (r = .stack) := by
  cases r with
  | general r =>
    have small : r.val < 256 := by omega
    have different : r.val ≠ 32 := by omega
    simp [Arm64Move.Fields.encode, GeneratedArm64RegDispatch.stackNumber,
      Nat.mod_eq_of_lt small, different]
  | zero => rfl
  | stack => rfl

def aluRhs (immediate : Bool) (aux : BitVec 32) (width : Width) (src2 : Byte) (value : Word)
    (s : Reference.AArch64.State) : Word :=
  GeneratedArm64AluOperand.rhs
    (if GeneratedArm64AluOperandSelect.immediate (if immediate then .aluImm else .aluReg)
      then .immediate else .register)
    value (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
    (Arm64Move.Fields.read s src2) ((GeneratedArm64Aux.b2 aux).setWidth 64) (Arm64Register.handlerWidth width)

/-- Actual uniform-byte ALU body, retaining every production pointer branch
in order. Native pointer reads must materialize the same words; sourceScalar
and sourceStack are the projected incoming provenance predicates. No source
is forced scalar and no SP32 byte is silently treated as ZR31. -/
def aluBody (op : GeneratedArm64AluDecode.Alu) (immediate sourceScalar sourceStack : Bool)
    (aux : BitVec 32) (width : Width) (dst src src2 : Byte) (value : Word)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let lhs := Arm64Move.Fields.read s src
  let rhs := aluRhs immediate aux width src2 value s
  let result := GeneratedArm64AluResult.result op lhs rhs
  let state := if width = .w64 ∧ op = .orr ∧ sourceStack ∧ rhs < 16 then
      Arm64Move.Fields.write s dst (GeneratedPtrAdd.bits lhs (rhs &&& ~~~lhs)) .w64
    else if GeneratedArm64AluHandler.useStackSub (Arm64Register.handlerWidth width) op
      (decide (dst.toNat = GeneratedArm64RegDispatch.stackNumber)) sourceStack then
      Arm64Move.Fields.write s dst (GeneratedPtrAdd.bits lhs (-rhs)) .w64
    else if GeneratedArm64AluHandler.usePointer (Arm64Register.handlerWidth width) op
      (decide (dst.toNat = GeneratedArm64RegDispatch.stackNumber)) sourceScalar then
      Arm64Move.Fields.write s dst (GeneratedPtrAdd.bits lhs rhs) .w64
    else Arm64Move.Fields.write s dst result width
  ⟨{ state with pc := s.pc + 4 }, [], none⟩

theorem alu_immediate_ignores_src2 (op : GeneratedArm64AluDecode.Alu) (sourceScalar sourceStack : Bool)
    (aux : BitVec 32) (width : Width) (dst src src2 other : Byte) (value : Word)
    (s : Reference.AArch64.State) :
    aluBody op true sourceScalar sourceStack aux width dst src src2 value s =
      aluBody op true sourceScalar sourceStack aux width dst src other value s := rfl

theorem alu_arithmetic_body (subtract immediate sourceScalar sourceStack : Bool) (aux : BitVec 32)
    (width : Width) (dst src : RegisterRef) (rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    aluBody (Arm64Arithmetic.AluDispatch.arithmetic subtract) immediate sourceScalar sourceStack aux width
      (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) (Arm64Register.registerCode rhs) value s =
      Arm64Arithmetic.AluDispatch.rawStep subtract immediate sourceScalar sourceStack aux width dst src rhs value s := by
  simp only [aluBody, aluRhs, Arm64Arithmetic.AluDispatch.rawStep, Arm64Move.Fields.typed_read,
    Arm64Move.Fields.typed_write, Arm64Move.Fields.register_read, encoded_stack]

theorem alu_logic_body (op : Arm64Logic.ImmediateDispatch.Logical) (immediate sourceScalar sourceStack : Bool)
    (aux : BitVec 32) (width : Width) (dst : RegisterRef) (src : Register) (src2 : Byte)
    (value : Word) (s : Reference.AArch64.State) :
    aluBody (Arm64Logic.ImmediateDispatch.alu op) immediate sourceScalar sourceStack aux width
      (Arm64Move.Fields.encode dst) (Arm64Register.registerCode src) src2 value s =
      Arm64Logic.ImmediateDispatch.rawStep op width sourceStack dst src (aluRhs immediate aux width src2 value s) s := by
  have paths := Arm64Logic.ImmediateDispatch.no_arithmetic_pointer_branch op width
    (decide (dst = .stack)) sourceScalar sourceStack
  simp only [aluBody, Arm64Logic.ImmediateDispatch.rawStep, Arm64Move.Fields.register_read,
    Arm64Move.Fields.typed_write, encoded_stack, paths.1, paths.2,
    GeneratedArm64AluOperandSelect.immediate, GeneratedArm64AluOperand.rhs, Bool.false_eq_true, ↓reduceIte]

/-- The concrete next ALU gate follows the established prefix. None leaves
later families to the surrounding dispatcher, not a new rejection rule. -/
def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  match dispatchPrefix code aux width dst src value s with
  | some result => some result
  | none => (Arm64Arithmetic.AluDispatch.decodeOpcode code).bind (fun immediate =>
      (decodeAlu (GeneratedArm64Aux.b0 aux).toNat).map
        (fun op => aluBody op immediate sourceScalar sourceStack aux width dst src src2 value s))

theorem alu_reached (immediate : Bool) (aux : BitVec 32) (width : Width) (dst src src2 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatch (aluCode immediate) aux width dst src src2 value sourceScalar sourceStack s =
      (decodeAlu (GeneratedArm64Aux.b0 aux).toNat).map
        (fun op => aluBody op immediate sourceScalar sourceStack aux width dst src src2 value s) := by
  have before : dispatchPrefix (aluCode immediate) aux width dst src value s = none := by
    apply other <;> cases immediate <;> decide
  unfold dispatch
  rw [before]
  have decoded : Arm64Arithmetic.AluDispatch.decodeOpcode (aluCode immediate) = some immediate :=
    Arm64Arithmetic.AluDispatch.decode_code immediate
  rw [decoded]
  rfl

theorem prefix_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : Binding s.pc code aux width dst src value native) :
    dispatch code aux width dst src src2 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatch, step_refines code aux width dst src value native s binding]

theorem dispatch_immediate_ignores_src2 (aux : BitVec 32) (width : Width) (dst src src2 other : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatch (aluCode true) aux width dst src src2 value sourceScalar sourceStack s =
      dispatch (aluCode true) aux width dst src other value sourceScalar sourceStack s := by
  rw [alu_reached, alu_reached]
  rfl

/-- Equality with the independently established arithmetic pipeline, derived
from literal operation identities and the uniform byte body, not assumed. -/
theorem arithmetic_dispatch_eq (subtract immediate sourceScalar sourceStack : Bool) (aux : BitVec 32)
    (width : Width) (dst src : RegisterRef) (rhs : Register) (value : Word) (s : Reference.AArch64.State)
    (operation : (GeneratedArm64Aux.b0 aux).toNat =
      GeneratedArm64AluDecode.code (Arm64Arithmetic.AluDispatch.arithmetic subtract)) :
    dispatch (aluCode immediate) aux width (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src)
      (Arm64Register.registerCode rhs) value sourceScalar sourceStack s =
      Arm64Arithmetic.AluDispatch.dispatch (aluCode immediate) aux width sourceScalar sourceStack dst src rhs value s := by
  rw [alu_reached]
  simp only [operation, decode_alu_code, Arm64Arithmetic.AluDispatch.dispatch, aluCode,
    Arm64Arithmetic.AluDispatch.decode_code, Arm64Arithmetic.AluDispatch.decode_arithmetic]
  change some (aluBody (Arm64Arithmetic.AluDispatch.arithmetic subtract) immediate sourceScalar sourceStack
    aux width (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) (Arm64Register.registerCode rhs) value s) =
    some (Arm64Arithmetic.AluDispatch.rawStep subtract immediate sourceScalar sourceStack aux width dst src rhs value s)
  rw [alu_arithmetic_body]

theorem arithmetic_immediate_refines (subtract sourceScalar sourceStack : Bool) (width : Width)
    (dst src : RegisterRef) (src2 : Byte) (value : Word) (lane1 lane2 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (aluCode true) (Arm64Arithmetic.AluDispatch.immediateAux subtract lane1 lane2 lane3) width
      (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) src2 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.arithmeticImmediate width subtract false dst src value) s) := by
  rw [dispatch_immediate_ignores_src2 _ _ _ _ src2 (Arm64Register.registerCode 31)]
  rw [arithmetic_dispatch_eq subtract true sourceScalar sourceStack _ width dst src 31 value s
    (Arm64Arithmetic.AluDispatch.immediate_operation subtract lane1 lane2 lane3)]
  exact Arm64Arithmetic.AluDispatch.dispatch_immediate_refines subtract sourceScalar sourceStack width dst src 31 value
    lane1 lane2 lane3 s

theorem arithmetic_register_refines (subtract sourceScalar sourceStack : Bool) (width : Width)
    (dst src : RegisterRef) (rhs : Register) (kind : Fin 3) (amount : Fin width.bits) (value : Word)
    (lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (aluCode false)
      (Arm64Arithmetic.AluDispatch.packedAux subtract (Arm64Arithmetic.registerModifier width kind amount)
        (BitVec.ofNat 8 amount.val) lane3) width
      (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) (Arm64Register.registerCode rhs)
      value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.arithmeticRegister width subtract false dst src rhs kind amount) s) := by
  rw [arithmetic_dispatch_eq subtract false sourceScalar sourceStack _ width dst src rhs value s
    (Arm64Arithmetic.AluDispatch.packed_operation subtract _ _ _)]
  exact Arm64Arithmetic.AluDispatch.dispatch_register_refines subtract sourceScalar sourceStack width dst src rhs kind amount value lane3 s

theorem arithmetic_extended_refines (subtract sourceScalar sourceStack plainSource : Bool) (width : Width)
    (dst src : RegisterRef) (rhs : Register) (kind : Reference.AArch64.RegisterExtend) (amount : Fin 5)
    (value : Word) (lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (aluCode false)
      (Arm64Arithmetic.AluDispatch.packedAux subtract
        (Arm64Arithmetic.extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
        (BitVec.ofNat 8 amount.val) lane3) width
      (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) (Arm64Register.registerCode rhs)
      value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.arithmeticExtended width subtract false dst src rhs kind amount) s) := by
  rw [arithmetic_dispatch_eq subtract false sourceScalar sourceStack _ width dst src rhs value s
    (Arm64Arithmetic.AluDispatch.packed_operation subtract _ _ _)]
  exact Arm64Arithmetic.AluDispatch.dispatch_extended_refines subtract sourceScalar sourceStack plainSource width dst src rhs kind amount value lane3 s

theorem logic_immediate_refines (op : Arm64Logic.ImmediateDispatch.Logical) (sourceScalar sourceStack : Bool)
    (width : Width) (dst : RegisterRef) (src : Register) (src2 : Byte) (value : Word)
    (lane1 lane2 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (aluCode true) (Arm64Logic.ImmediateDispatch.packedAux op lane1 lane2 lane3) width
      (Arm64Move.Fields.encode dst) (Arm64Register.registerCode src) src2 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.logicImmediate width (Arm64Logic.ImmediateDispatch.operation op) dst src value) s) := by
  rw [alu_reached, Arm64Logic.ImmediateDispatch.packed_operation, decode_alu_code]
  change some (aluBody (Arm64Logic.ImmediateDispatch.alu op) true sourceScalar sourceStack _ width
    (Arm64Move.Fields.encode dst) (Arm64Register.registerCode src) src2 value s) = _
  rw [alu_logic_body]
  change some (Arm64Logic.ImmediateDispatch.rawStep op width sourceStack dst src value s) = _
  rw [Arm64Logic.ImmediateDispatch.raw_step_refines]

theorem rhs_register_packed (mod : GeneratedArm64ModDecode.Mod) (amount lane0 lane3 : Byte)
    (width : Width) (rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    aluRhs false (Arm64Arithmetic.FlagArithmetic.packedAux mod amount lane0 lane3) width
      (Arm64Register.registerCode rhs) value s =
      GeneratedArm64Mod.value mod (Arm64Register.readReg s rhs) (amount.setWidth 64) (Arm64Register.handlerWidth width) := by
  simp only [aluRhs, GeneratedArm64AluOperandSelect.immediate, GeneratedArm64AluOperand.rhs,
    Bool.false_eq_true, ↓reduceIte, Arm64Arithmetic.FlagArithmetic.packed_modifier,
    Arm64Arithmetic.FlagArithmetic.packed_amount, Arm64Move.Fields.register_read]

theorem logic_register_body (op : Arm64Logic.ImmediateDispatch.Logical) (sourceScalar sourceStack : Bool)
    (mod : GeneratedArm64ModDecode.Mod) (amount lane3 : Byte) (width : Width)
    (dst src rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    aluBody (Arm64Logic.ImmediateDispatch.alu op) false sourceScalar sourceStack
      (Arm64Logic.ImmediateDispatch.registerAux op mod amount lane3) width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) value s =
      Arm64Logic.ImmediateDispatch.registerRawStep op mod (amount.setWidth 64) width sourceStack dst src rhs value s := by
  rw [← Arm64Move.Fields.encode_scalar dst, alu_logic_body]
  change Arm64Logic.ImmediateDispatch.rawStep op width sourceStack (Arm64Move.scalarDestination dst) src
    (aluRhs false (Arm64Arithmetic.FlagArithmetic.packedAux mod amount
      (BitVec.ofNat 8 (GeneratedArm64AluDecode.code (Arm64Logic.ImmediateDispatch.alu op))) lane3)
      width (Arm64Register.registerCode rhs) value s) s = _
  rw [rhs_register_packed]
  rfl

theorem logic_register_refines (op : Arm64Logic.ImmediateDispatch.Logical) (sourceScalar sourceStack : Bool)
    (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits) (dst src rhs : Register)
    (value : Word) (lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (aluCode false)
      (Arm64Logic.ImmediateDispatch.registerAux op (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane3)
      width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs)
      value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.logic ⟨width, Arm64Logic.ImmediateDispatch.operation op, kind, amount, dst, src, rhs⟩) s) := by
  rw [alu_reached, Arm64Logic.ImmediateDispatch.register_aux_operation, decode_alu_code]
  change some (aluBody (Arm64Logic.ImmediateDispatch.alu op) false sourceScalar sourceStack _ width
    (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) value s) = _
  rw [logic_register_body, Arm64Shift.Unary.native_amount, Arm64Logic.ImmediateDispatch.register_raw_refines]

theorem logic_unmodified_refines (op : Arm64Logic.ImmediateDispatch.Logical) (sourceScalar sourceStack : Bool)
    (width : Width) (dst src rhs : Register) (value : Word) (amount lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (aluCode false) (Arm64Logic.ImmediateDispatch.registerAux op .none amount lane3)
      width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs)
      value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.logic ⟨width, Arm64Logic.ImmediateDispatch.operation op, .lsl,
        ⟨0, by cases width <;> decide⟩, dst, src, rhs⟩) s) := by
  rw [alu_reached, Arm64Logic.ImmediateDispatch.register_aux_operation, decode_alu_code]
  change some (aluBody (Arm64Logic.ImmediateDispatch.alu op) false sourceScalar sourceStack _ width
    (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) value s) = _
  rw [logic_register_body, Arm64Logic.ImmediateDispatch.register_identity]
  exact congrArg some (Arm64Logic.ImmediateDispatch.register_raw_refines op width sourceStack .lsl
    ⟨0, by cases width <;> decide⟩ dst src rhs value s)

/-- Extend the field-only normalization relation to the actual next gate.
No constructor assumes a component semantic/refinement theorem. -/
inductive DispatchBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : Binding pc code aux width dst src value native) :
      DispatchBinding pc code aux width dst src src2 value native
  | arithmeticImmediate (subtract : Bool) (width : Width) (dst src : RegisterRef) (src2 : Byte)
      (value : Word) (lane1 lane2 lane3 : Byte) :
      DispatchBinding pc (aluCode true) (Arm64Arithmetic.AluDispatch.immediateAux subtract lane1 lane2 lane3) width
        (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) src2 value
        (.arithmeticImmediate width subtract false dst src value)
  | arithmeticRegister (subtract : Bool) (width : Width) (dst src : RegisterRef) (rhs : Register)
      (kind : Fin 3) (amount : Fin width.bits) (value : Word) (lane3 : Byte) :
      DispatchBinding pc (aluCode false)
        (Arm64Arithmetic.AluDispatch.packedAux subtract (Arm64Arithmetic.registerModifier width kind amount)
          (BitVec.ofNat 8 amount.val) lane3) width (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src)
        (Arm64Register.registerCode rhs) value (.arithmeticRegister width subtract false dst src rhs kind amount)
  | arithmeticExtended (subtract plainSource : Bool) (width : Width) (dst src : RegisterRef) (rhs : Register)
      (kind : Reference.AArch64.RegisterExtend) (amount : Fin 5) (value : Word) (lane3 : Byte) :
      DispatchBinding pc (aluCode false)
        (Arm64Arithmetic.AluDispatch.packedAux subtract
          (Arm64Arithmetic.extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
          (BitVec.ofNat 8 amount.val) lane3) width (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src)
        (Arm64Register.registerCode rhs) value (.arithmeticExtended width subtract false dst src rhs kind amount)
  | logicImmediate (op : Arm64Logic.ImmediateDispatch.Logical) (width : Width) (dst : RegisterRef)
      (src : Register) (src2 : Byte) (value : Word) (lane1 lane2 lane3 : Byte) :
      DispatchBinding pc (aluCode true) (Arm64Logic.ImmediateDispatch.packedAux op lane1 lane2 lane3) width
        (Arm64Move.Fields.encode dst) (Arm64Register.registerCode src) src2 value
        (.logicImmediate width (Arm64Logic.ImmediateDispatch.operation op) dst src value)
  | logicRegister (op : Arm64Logic.ImmediateDispatch.Logical) (width : Width)
      (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits) (dst src rhs : Register)
      (value : Word) (lane3 : Byte) :
      DispatchBinding pc (aluCode false)
        (Arm64Logic.ImmediateDispatch.registerAux op (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane3)
        width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs)
        value (.logic ⟨width, Arm64Logic.ImmediateDispatch.operation op, kind, amount, dst, src, rhs⟩)
  | logicUnmodified (op : Arm64Logic.ImmediateDispatch.Logical) (width : Width) (dst src rhs : Register)
      (value : Word) (amount lane3 : Byte) :
      DispatchBinding pc (aluCode false) (Arm64Logic.ImmediateDispatch.registerAux op .none amount lane3)
        width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs)
        value (.logic ⟨width, Arm64Logic.ImmediateDispatch.operation op, .lsl,
          ⟨0, by cases width <;> decide⟩, dst, src, rhs⟩)

/-- One step theorem for the concrete leading prefix plus both ALU rows.
The quantified provenance predicates do not remove pointer branches. Full
native-byte/field binding and the remaining ISA families are separate work. -/
theorem dispatch_step_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : DispatchBinding s.pc code aux width dst src src2 value native) :
    dispatch code aux width dst src src2 value sourceScalar sourceStack s = some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ earlier => exact prefix_preserved _ _ _ _ _ _ _ _ _ _ s earlier
  | arithmeticImmediate => apply arithmetic_immediate_refines
  | arithmeticRegister => apply arithmetic_register_refines
  | arithmeticExtended => apply arithmetic_extended_refines
  | logicImmediate => apply logic_immediate_refines
  | logicRegister => apply logic_register_refines
  | logicUnmodified => apply logic_unmodified_refines

/-- The next production body uses its generated operand selector and actual
byte-field reads before the generated shift and width write. -/
def shiftBody (op : GeneratedArm64ImmOperand.ImmOp) (kind : Reference.AArch64.ShiftKind) (width : Width)
    (dst src count : Byte) (immediate : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let amount := if GeneratedArm64ImmOperand.immediate op then immediate else Arm64Move.Fields.read s count
  let value := GeneratedArm64Shift.value (Arm64Shift.shiftCode kind) (Arm64Move.Fields.read s src)
    amount (Arm64Register.handlerWidth width)
  ⟨{ Arm64Move.Fields.write s dst value width with pc := s.pc + 4 }, [], none⟩

theorem shift_body_typed (op : GeneratedArm64ImmOperand.ImmOp) (kind : Reference.AArch64.ShiftKind)
    (width : Width) (dst src count : Register) (immediate : Word) (s : Reference.AArch64.State) :
    shiftBody op kind width (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
      (Arm64Register.registerCode count) immediate s = Arm64Shift.rawStep op kind width dst src count immediate s := by
  simp only [shiftBody, Arm64Shift.rawStep, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

theorem shift_immediate_ignores_count (kind : Reference.AArch64.ShiftKind) (width : Width)
    (dst src count other : Byte) (immediate : Word) (s : Reference.AArch64.State) :
    shiftBody .shiftImm kind width dst src count immediate s =
      shiftBody .shiftImm kind width dst src other immediate s := rfl

def shiftOpcode (immediate : Bool) : Nat :=
  GeneratedArm64DispatchFamily.code (if immediate then .shiftImm else .shiftReg)

/-- The next actual gate is reached only after the earlier prefix/ALU.
Its counts and operands are still bytes; other families pass onward. -/
def dispatchThroughShift (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatch code aux width dst src src2 value sourceScalar sourceStack s with
  | some result => some result
  | none => (Arm64Shift.decodeOpcode code).bind (fun op =>
      (Arm64Shift.decodeKind (GeneratedArm64Aux.b0 aux).toNat).map
        (fun kind => shiftBody op kind width dst src src2 value s))

theorem before_shift (immediate : Bool) (aux : BitVec 32) (width : Width) (dst src src2 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatch (shiftOpcode immediate) aux width dst src src2 value sourceScalar sourceStack s = none := by
  have first : dispatchPrefix (shiftOpcode immediate) aux width dst src value s = none := by
    apply other <;> cases immediate <;> decide
  have noAlu : Arm64Arithmetic.AluDispatch.decodeOpcode (shiftOpcode immediate) = none := by
    cases immediate <;> rfl
  simp only [dispatch, first, noAlu]
  rfl

theorem shift_reached (immediate : Bool) (aux : BitVec 32) (width : Width) (dst src src2 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughShift (shiftOpcode immediate) aux width dst src src2 value sourceScalar sourceStack s =
      (Arm64Shift.decodeKind (GeneratedArm64Aux.b0 aux).toNat).map
        (fun kind => shiftBody (if immediate then .shiftImm else .shiftReg) kind width dst src src2 value s) := by
  have known : Arm64Shift.decodeOpcode (shiftOpcode immediate) =
      some (if immediate then .shiftImm else .shiftReg) := by cases immediate <;> rfl
  unfold dispatchThroughShift
  rw [before_shift, known]
  rfl

theorem shift_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : DispatchBinding s.pc code aux width dst src src2 value native) :
    dispatchThroughShift code aux width dst src src2 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughShift, dispatch_step_refines code aux width dst src src2 value sourceScalar sourceStack native s binding]

theorem shift_immediate_refines (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits)
    (dst src : Register) (count : Byte) (lane1 lane2 lane3 : Byte) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughShift (shiftOpcode true) (Arm64Shift.packedAux kind lane1 lane2 lane3) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) count (BitVec.ofNat 64 amount.val)
      sourceScalar sourceStack s = some (Reference.AArch64.step (.shift (.immediate width kind amount dst src)) s) := by
  rw [shift_reached, Arm64Shift.packed_kind]
  change some (shiftBody .shiftImm kind width (Arm64Register.registerCode dst)
    (Arm64Register.registerCode src) count (BitVec.ofNat 64 amount.val) s) = _
  rw [shift_immediate_ignores_count kind width _ _ count (Arm64Register.registerCode 31), shift_body_typed]
  change some (Arm64Shift.handlerStep (.immediate width kind amount dst src) s) = _
  rw [Arm64Shift.step_refines]

theorem shift_register_refines (width : Width) (kind : Reference.AArch64.ShiftKind)
    (dst src count : Register) (value : Word) (lane1 lane2 lane3 : Byte) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughShift (shiftOpcode false) (Arm64Shift.packedAux kind lane1 lane2 lane3) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode count) value
      sourceScalar sourceStack s = some (Reference.AArch64.step (.shift (.register width kind dst src count)) s) := by
  rw [shift_reached, Arm64Shift.packed_kind]
  change some (shiftBody .shiftReg kind width (Arm64Register.registerCode dst)
    (Arm64Register.registerCode src) (Arm64Register.registerCode count) value s) = _
  rw [shift_body_typed]
  change some (Arm64Shift.handlerStep (.register width kind dst src count) s) = _
  rw [Arm64Shift.step_refines]

/-- Field-only extension for the actual two SHIFT rows. -/
inductive ShiftBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : DispatchBinding pc code aux width dst src src2 value native) :
      ShiftBinding pc code aux width dst src src2 value native
  | immediate (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits)
      (dst src : Register) (count : Byte) (lane1 lane2 lane3 : Byte) :
      ShiftBinding pc (shiftOpcode true) (Arm64Shift.packedAux kind lane1 lane2 lane3) width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) count (BitVec.ofNat 64 amount.val)
        (.shift (.immediate width kind amount dst src))
  | register (width : Width) (kind : Reference.AArch64.ShiftKind) (dst src count : Register)
      (value : Word) (lane1 lane2 lane3 : Byte) :
      ShiftBinding pc (shiftOpcode false) (Arm64Shift.packedAux kind lane1 lane2 lane3) width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode count) value
        (.shift (.register width kind dst src count))

theorem step_through_shift_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : ShiftBinding s.pc code aux width dst src src2 value native) :
    dispatchThroughShift code aux width dst src src2 value sourceScalar sourceStack s = some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ earlier => exact shift_earlier_preserved _ _ _ _ _ _ _ _ _ _ s earlier
  | immediate => apply shift_immediate_refines
  | register => apply shift_register_refines


/-- The actual eight-row multiply body: only UDIV narrows its two inputs
before the generated value; every row uses the common width write. SRC3 is
an actual byte, including SP32 and NONE255, rather than an invented GPR. -/
def multiplyBody (op : GeneratedArm64Mul.Mul) (width : Width) (dst src src2 src3 : Byte)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let inputWidth := if GeneratedArm64Mul.code op = GeneratedArm64Mul.code .udiv
    then Arm64Register.handlerWidth width else .w64
  let lhs := GeneratedArm64Width.narrow (Arm64Move.Fields.read s src) inputWidth
  let rhs := GeneratedArm64Width.narrow (Arm64Move.Fields.read s src2) inputWidth
  let value := GeneratedArm64Mul.value op lhs rhs (Arm64Move.Fields.read s src3)
  ⟨{ Arm64Move.Fields.write s dst value width with pc := s.pc + 4 }, [], none⟩

theorem multiply_body_typed (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst src src2 src3 : Register) (s : Reference.AArch64.State) :
    multiplyBody op width (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
      (Arm64Register.registerCode src2) (Arm64Register.registerCode src3) s =
      Arm64Mul.rawStep op width dst src src2 src3 s := by
  simp only [multiplyBody, Arm64Mul.rawStep, Arm64Move.Fields.register_read,
    Arm64Move.Fields.register_write]

/-- These four numeric operations read SRC3 but do not use its value. No
encoding, presence or tag condition is imposed on that unused field. -/
theorem multiply_ignores_accumulator (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst src src2 src3 other : Byte) (s : Reference.AArch64.State)
    (unused : op = .mul ∨ op = .umull ∨ op = .udiv ∨ op = .umulh) :
    multiplyBody op width dst src src2 src3 s = multiplyBody op width dst src src2 other s := by
  rcases unused with rfl | rfl | rfl | rfl <;> rfl

/-- SRC3 first becomes live at this production gate. Earlier gates retain
all their unused-field freedom, including an arbitrary SRC3 byte. -/
def dispatchThroughMultiply (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughShift code aux width dst src src2 value sourceScalar sourceStack s with
  | some result => some result
  | none => (Arm64Mul.decodeOpcode code).map (fun op => multiplyBody op width dst src src2 src3 s)

theorem before_multiply (op : GeneratedArm64Mul.Mul) (aux : BitVec 32) (width : Width)
    (dst src src2 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughShift (GeneratedArm64Mul.code op) aux width dst src src2 value sourceScalar sourceStack s = none := by
  have leading : dispatchPrefix (GeneratedArm64Mul.code op) aux width dst src value s = none := by
    apply other <;> cases op <;> decide
  have noAlu : Arm64Arithmetic.AluDispatch.decodeOpcode (GeneratedArm64Mul.code op) = none := by
    cases op <;> rfl
  have noShift : Arm64Shift.decodeOpcode (GeneratedArm64Mul.code op) = none := by
    cases op <;> rfl
  simp only [dispatchThroughShift, dispatch, leading, noAlu, noShift]
  rfl

theorem multiply_reached (op : GeneratedArm64Mul.Mul) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughMultiply (GeneratedArm64Mul.code op) aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (multiplyBody op width dst src src2 src3 s) := by
  unfold dispatchThroughMultiply
  rw [before_multiply, Arm64Mul.decode_code]
  rfl

theorem multiply_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : ShiftBinding s.pc code aux width dst src src2 value native) :
    dispatchThroughMultiply code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughMultiply,
    step_through_shift_refines code aux width dst src src2 value sourceScalar sourceStack native s binding]

theorem multiply_refines (op : GeneratedArm64Mul.Mul) (width : Width) (aux : BitVec 32)
    (dst src src2 src3 : Register) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) (valid : Arm64Mul.nativeWidth op width) :
    dispatchThroughMultiply (GeneratedArm64Mul.code op) aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode src2) (Arm64Register.registerCode src3)
      value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.mul (Arm64Mul.instruction op width dst src src2 src3)) s) := by
  rw [multiply_reached, multiply_body_typed, Arm64Mul.raw_step_refines op width dst src src2 src3 s valid]

theorem multiply_unused_refines (op : GeneratedArm64Mul.Mul) (width : Width) (aux : BitVec 32)
    (dst src src2 : Register) (src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) (valid : Arm64Mul.nativeWidth op width)
    (unused : op = .mul ∨ op = .umull ∨ op = .udiv ∨ op = .umulh) :
    dispatchThroughMultiply (GeneratedArm64Mul.code op) aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode src2) src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.mul (Arm64Mul.instruction op width dst src src2 31)) s) := by
  rw [multiply_reached, multiply_ignores_accumulator op width _ _ _ src3 (Arm64Register.registerCode 31) s unused,
    multiply_body_typed, Arm64Mul.raw_step_refines op width dst src src2 31 s valid]

/-- Field/code/native-width normalization only. In particular no constructor
assumes the generated body or dispatcher already refines an ISA step. -/
inductive MultiplyBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : ShiftBinding pc code aux width dst src src2 value native) :
      MultiplyBinding pc code aux width dst src src2 src3 value native
  | multiply (op : GeneratedArm64Mul.Mul) (width : Width) (aux : BitVec 32)
      (dst src src2 src3 : Register) (value : Word) (valid : Arm64Mul.nativeWidth op width) :
      MultiplyBinding pc (GeneratedArm64Mul.code op) aux width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (Arm64Register.registerCode src2) (Arm64Register.registerCode src3) value
        (.mul (Arm64Mul.instruction op width dst src src2 src3))
  | unusedAccumulator (op : GeneratedArm64Mul.Mul) (width : Width) (aux : BitVec 32)
      (dst src src2 : Register) (src3 : Byte) (value : Word) (valid : Arm64Mul.nativeWidth op width)
      (unused : op = .mul ∨ op = .umull ∨ op = .udiv ∨ op = .umulh) :
      MultiplyBinding pc (GeneratedArm64Mul.code op) aux width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (Arm64Register.registerCode src2) src3 value
        (.mul (Arm64Mul.instruction op width dst src src2 31))

theorem step_through_multiply_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : MultiplyBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughMultiply code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact multiply_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | multiply => apply multiply_refines; assumption
  | unusedAccumulator => apply multiply_unused_refines <;> assumption


/-- The actual unary modifier switch retains all eleven selectors and the
unknown-byte identity behavior. Native MVN/NEG normalization below selects
only their architectural modifiers; the body adds no rejection policy. -/
def unaryBody (op : GeneratedArm64Unary.Unary) (aux : BitVec 32) (width : Width) (dst src : Byte)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let modified := GeneratedArm64Mod.value
    (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
    (Arm64Move.Fields.read s src) ((GeneratedArm64Aux.b2 aux).setWidth 64) (Arm64Register.handlerWidth width)
  let value := GeneratedArm64Unary.value op modified (Arm64Register.handlerWidth width)
  ⟨{ Arm64Move.Fields.write s dst value width with pc := s.pc + 4 }, [], none⟩

theorem unary_body_typed (op : GeneratedArm64Unary.Unary) (mod : GeneratedArm64ModDecode.Mod)
    (amount lane0 lane3 : Byte) (width : Width) (dst src : Register) (s : Reference.AArch64.State) :
    unaryBody op (Arm64Shift.Unary.packedAux mod amount lane0 lane3) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) s =
      Arm64Shift.Unary.rawStep op mod (amount.setWidth 64) width dst src s := by
  change unaryBody op (Arm64Arithmetic.FlagArithmetic.packedAux mod amount lane0 lane3) width
    (Arm64Register.registerCode dst) (Arm64Register.registerCode src) s = _
  simp only [unaryBody, Arm64Shift.Unary.rawStep, Arm64Arithmetic.FlagArithmetic.packed_modifier,
    Arm64Arithmetic.FlagArithmetic.packed_amount, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

def dispatchThroughUnary (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughMultiply code aux width dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => (Arm64Shift.Unary.decodeOpcode code).map (fun op => unaryBody op aux width dst src s)

theorem unary_reached (op : GeneratedArm64Unary.Unary) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughUnary (GeneratedArm64Unary.code op) aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (unaryBody op aux width dst src s) := by
  have leading : dispatchPrefix (GeneratedArm64Unary.code op) aux width dst src value s = none := by
    apply other <;> cases op <;> decide
  have noAlu : Arm64Arithmetic.AluDispatch.decodeOpcode (GeneratedArm64Unary.code op) = none := by cases op <;> rfl
  have noShift : Arm64Shift.decodeOpcode (GeneratedArm64Unary.code op) = none := by cases op <;> rfl
  have noMul : Arm64Mul.decodeOpcode (GeneratedArm64Unary.code op) = none := by cases op <;> rfl
  have known : Arm64Shift.Unary.decodeOpcode (GeneratedArm64Unary.code op) = some op := by cases op <;> rfl
  simp only [dispatchThroughUnary, dispatchThroughMultiply, dispatchThroughShift, dispatch,
    leading, noAlu, noShift, noMul, known]
  rfl

theorem unary_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : MultiplyBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughUnary code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughUnary,
    step_through_multiply_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding]

theorem unary_invert_refines (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits)
    (dst src : Register) (src2 src3 lane0 lane3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughUnary (GeneratedArm64Unary.code .mvn)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.shift (.invert width kind amount dst src)) s) := by
  rw [unary_reached, unary_body_typed, Arm64Shift.Unary.native_amount]
  change some (Arm64Shift.handlerStep (.invert width kind amount dst src) s) = _
  rw [Arm64Shift.step_refines]

theorem unary_negate_refines (width : Width) (kind : Fin 3) (amount : Fin width.bits)
    (dst src : Register) (src2 src3 lane0 lane3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughUnary (GeneratedArm64Unary.code .neg)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier (Reference.AArch64.arithmeticShift kind))
        (BitVec.ofNat 8 amount.val) lane0 lane3) width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.shift (.negate width kind amount dst src)) s) := by
  rw [unary_reached, unary_body_typed, Arm64Shift.Unary.native_amount]
  change some (Arm64Shift.handlerStep (.negate width kind amount dst src) s) = _
  rw [Arm64Shift.step_refines]

/-- Omitted modifiers ignore the entire amount byte. This includes values
outside the native shift-immediate bound; no fictitious amount guard is added. -/
theorem unary_unmodified_refines (op : GeneratedArm64Unary.Unary) (width : Width)
    (dst src : Register) (src2 src3 amount lane0 lane3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughUnary (GeneratedArm64Unary.code op) (Arm64Shift.Unary.packedAux .none amount lane0 lane3) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.shift (if op = .mvn then
        .invert width .lsl ⟨0, by cases width <;> decide⟩ dst src else
        .negate width 0 ⟨0, by cases width <;> decide⟩ dst src)) s) := by
  rw [unary_reached, unary_body_typed]
  simp only [Arm64Shift.Unary.rawStep, Arm64Shift.Unary.identity_value]
  cases op with
  | mvn =>
      simp only [if_pos rfl]
      change some (Arm64Shift.handlerStep (.invert width .lsl ⟨0, by cases width <;> decide⟩ dst src) s) = _
      rw [Arm64Shift.step_refines]
      rfl
  | neg =>
      simp only [if_neg (by decide : GeneratedArm64Unary.Unary.neg ≠ .mvn)]
      change some (Arm64Shift.handlerStep (.negate width 0 ⟨0, by cases width <;> decide⟩ dst src) s) = _
      rw [Arm64Shift.step_refines]

/-- Native field/modifier/amount identities for both unary rows. Unused
SRC2/SRC3/IMM/AUX0/AUX3 retain arbitrary values. NEG has no native ROR form. -/
inductive UnaryBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : MultiplyBinding pc code aux width dst src src2 src3 value native) :
      UnaryBinding pc code aux width dst src src2 src3 value native
  | invert (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits)
      (dst src : Register) (src2 src3 lane0 lane3 : Byte) (value : Word) :
      UnaryBinding pc (GeneratedArm64Unary.code .mvn)
        (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3) width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
        (.shift (.invert width kind amount dst src))
  | negate (width : Width) (kind : Fin 3) (amount : Fin width.bits)
      (dst src : Register) (src2 src3 lane0 lane3 : Byte) (value : Word) :
      UnaryBinding pc (GeneratedArm64Unary.code .neg)
        (Arm64Shift.Unary.packedAux (Arm64Shift.modifier (Reference.AArch64.arithmeticShift kind))
          (BitVec.ofNat 8 amount.val) lane0 lane3) width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
        (.shift (.negate width kind amount dst src))
  | unmodified (op : GeneratedArm64Unary.Unary) (width : Width)
      (dst src : Register) (src2 src3 amount lane0 lane3 : Byte) (value : Word) :
      UnaryBinding pc (GeneratedArm64Unary.code op) (Arm64Shift.Unary.packedAux .none amount lane0 lane3) width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
        (.shift (if op = .mvn then .invert width .lsl ⟨0, by cases width <;> decide⟩ dst src
          else .negate width 0 ⟨0, by cases width <;> decide⟩ dst src))

theorem step_through_unary_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : UnaryBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughUnary code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact unary_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | invert => apply unary_invert_refines
  | negate => apply unary_negate_refines
  | unmodified => apply unary_unmodified_refines


/-- CNEG consumes the whole AUX condition. Its scalar generated value and
actual byte read/write preserve all other architectural components. -/
def conditionalNegateBody (predicate : Arm64Cond) (width : Width) (dst src : Byte)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Cneg.value .cneg
    (generatedArm64Cond (Arm64Condition.flags s.flags) predicate)
    (Arm64Move.Fields.read s src) (Arm64Register.handlerWidth width)
  ⟨{ Arm64Move.Fields.write s dst value width with pc := s.pc + 4 }, [], none⟩

theorem conditional_negate_body_typed (predicate : Arm64Cond) (width : Width) (dst src : Register)
    (s : Reference.AArch64.State) :
    conditionalNegateBody predicate width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) s =
      Arm64Select.negateStep width dst src predicate s := by
  simp only [conditionalNegateBody, Arm64Select.negateStep,
    Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

/-- EXTR alone narrows the two input words before the generated value. The
other five rows retain full input reads and ignore SRC2 and IMM. -/
def extrevBody (op : GeneratedArm64Extrev.Extrev) (width : Width) (dst src src2 : Byte) (value : Word)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let inputWidth := if GeneratedArm64Extrev.code op = GeneratedArm64Extrev.code .extr
    then Arm64Register.handlerWidth width else .w64
  let lhs := GeneratedArm64Width.narrow (Arm64Move.Fields.read s src) inputWidth
  let rhs := GeneratedArm64Width.narrow (Arm64Move.Fields.read s src2) inputWidth
  let result := GeneratedArm64Extrev.value op lhs rhs value (Arm64Register.handlerWidth width)
  ⟨{ Arm64Move.Fields.write s dst result width with pc := s.pc + 4 }, [], none⟩

theorem extrev_body_typed (op : GeneratedArm64Extrev.Extrev) (width : Width) (dst src src2 : Register)
    (value : Word) (s : Reference.AArch64.State) :
    extrevBody op width (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
      (Arm64Register.registerCode src2) value s = Arm64Extrev.rawStep op width dst src src2 value s := by
  simp only [extrevBody, Arm64Extrev.rawStep, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

theorem extrev_unused_fields (op : GeneratedArm64Extrev.Extrev) (width : Width) (dst src src2 other : Byte)
    (value otherValue : Word) (s : Reference.AArch64.State) (unused : op ≠ .extr) :
    extrevBody op width dst src src2 value s = extrevBody op width dst src other otherValue s := by
  cases op with
  | extr => exact False.elim (unused rfl)
  | rev => rfl
  | rev16 => rfl
  | sxth => rfl
  | sxtw => rfl
  | sxtb => rfl

/-- The next two production gates in order. CNEG's entire AUX is decoded;
packed AUX fields do not replace that condition. EXTR/REV/SXT use IMM only
where their actual generated primitive consumes it. -/
def dispatchThroughExtrev (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughUnary code aux width dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => if code = GeneratedArm64Cneg.code .cneg then
      (Arm64Condition.decode aux.toNat).map (fun predicate => conditionalNegateBody predicate width dst src s)
    else (Arm64Extrev.decodeOpcode code).map (fun op => extrevBody op width dst src src2 value s)

theorem before_conditional_negate (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughUnary (GeneratedArm64Cneg.code .cneg) aux width dst src src2 src3 value sourceScalar sourceStack s = none := rfl

theorem conditional_negate_reached (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughExtrev (GeneratedArm64Cneg.code .cneg) aux width dst src src2 src3 value sourceScalar sourceStack s =
      (Arm64Condition.decode aux.toNat).map (fun predicate => conditionalNegateBody predicate width dst src s) := by
  unfold dispatchThroughExtrev
  rw [before_conditional_negate]
  rfl

theorem conditional_negate_refines (predicate : Arm64Cond) (width : Width) (dst src : Register)
    (src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State)
    (valid : predicate ≠ .al) :
    dispatchThroughExtrev (GeneratedArm64Cneg.code .cneg) (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.select width .negate dst src src
        (Arm64Condition.nativeCode (Arm64Select.inverse predicate))) s) := by
  have condition : Arm64Condition.decode (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)).toNat =
      some predicate := by cases predicate <;> rfl
  rw [conditional_negate_reached, condition]
  change some (conditionalNegateBody predicate width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) s) = _
  rw [conditional_negate_body_typed, Arm64Select.negate_step_refines width dst src predicate s valid]

theorem extrev_reached (op : GeneratedArm64Extrev.Extrev) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughExtrev (GeneratedArm64Extrev.code op) aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (extrevBody op width dst src src2 value s) := by
  have before : dispatchThroughUnary (GeneratedArm64Extrev.code op) aux width dst src src2 src3 value sourceScalar sourceStack s = none := by
    cases op <;> rfl
  have separate : GeneratedArm64Extrev.code op ≠ GeneratedArm64Cneg.code .cneg := by cases op <;> decide
  unfold dispatchThroughExtrev
  rw [before, if_neg separate, Arm64Extrev.decode_code]
  rfl

theorem extract_refines (width : Width) (amount : Fin width.bits) (dst src src2 : Register)
    (aux : BitVec 32) (src3 : Byte) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughExtrev (GeneratedArm64Extrev.code .extr) aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode src2) src3 (BitVec.ofNat 64 amount.val)
      sourceScalar sourceStack s = some (Reference.AArch64.step (.extrev (.extract width amount dst src src2)) s) := by
  rw [extrev_reached, extrev_body_typed, Arm64Extrev.raw_extract_refines]

theorem reverse_refines (width : Width) (halfwords : Bool) (dst src : Register) (aux : BitVec 32)
    (src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughExtrev (GeneratedArm64Extrev.code (if halfwords then .rev16 else .rev)) aux width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.extrev (.reverse width halfwords dst src)) s) := by
  rw [extrev_reached, extrev_unused_fields _ width _ _ src2 (Arm64Register.registerCode 31) value value s
      (by cases halfwords <;> decide), extrev_body_typed, Arm64Extrev.raw_reverse_refines]

theorem extend_refines (width : Width) (source : Reference.AArch64.ExtendBits) (dst src : Register)
    (aux : BitVec 32) (src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughExtrev (GeneratedArm64Extrev.code (Arm64Extrev.extendOpcode source)) aux width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.extrev (.extend width source dst src)) s) := by
  rw [extrev_reached, extrev_unused_fields _ width _ _ src2 (Arm64Register.registerCode 31) value value s
      (by cases source <;> decide), extrev_body_typed, Arm64Extrev.raw_extend_refines]

theorem extrev_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : UnaryBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughExtrev code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughExtrev,
    step_through_unary_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding]

inductive ExtrevBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : UnaryBinding pc code aux width dst src src2 src3 value native) :
      ExtrevBinding pc code aux width dst src src2 src3 value native
  | conditionalNegate (predicate : Arm64Cond) (width : Width) (dst src : Register)
      (src2 src3 : Byte) (value : Word) (valid : predicate ≠ .al) :
      ExtrevBinding pc (GeneratedArm64Cneg.code .cneg) (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
        (.select width .negate dst src src (Arm64Condition.nativeCode (Arm64Select.inverse predicate)))
  | extract (width : Width) (amount : Fin width.bits) (dst src src2 : Register) (aux : BitVec 32) (src3 : Byte) :
      ExtrevBinding pc (GeneratedArm64Extrev.code .extr) aux width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (Arm64Register.registerCode src2) src3 (BitVec.ofNat 64 amount.val)
        (.extrev (.extract width amount dst src src2))
  | reverse (width : Width) (halfwords : Bool) (dst src : Register) (aux : BitVec 32) (src2 src3 : Byte) (value : Word) :
      ExtrevBinding pc (GeneratedArm64Extrev.code (if halfwords then .rev16 else .rev)) aux width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
        (.extrev (.reverse width halfwords dst src))
  | extend (width : Width) (source : Reference.AArch64.ExtendBits) (dst src : Register)
      (aux : BitVec 32) (src2 src3 : Byte) (value : Word) :
      ExtrevBinding pc (GeneratedArm64Extrev.code (Arm64Extrev.extendOpcode source)) aux width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
        (.extrev (.extend width source dst src))

/-- One concrete step for all earlier gates, CNEG and six EXTR/REV/SXT rows;
normalization premises are field/code/condition/amount identities only. -/
theorem step_through_extrev_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : ExtrevBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughExtrev code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact extrev_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | conditionalNegate => apply conditional_negate_refines; assumption
  | extract => apply extract_refines
  | reverse => apply reverse_refines
  | extend => apply extend_refines


/-- BITFIELD reads the incoming destination as well as its source. Actual
AUX0/1/2 choose kind/LSB/count; there is no additional runtime bounds guard. -/
def bitfieldBody (kind : GeneratedArm64BitfieldDecode.Bitfield) (aux : BitVec 32) (width : Width)
    (dst src : Byte) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let value := GeneratedArm64Bitfield.value kind (Arm64Move.Fields.read s src) (Arm64Move.Fields.read s dst)
    ((GeneratedArm64Aux.b1 aux).setWidth 8) ((GeneratedArm64Aux.b2 aux).setWidth 8)
  ⟨{ Arm64Move.Fields.write s dst value width with pc := s.pc + 4 }, [], none⟩

theorem bitfield_body_typed (kind : GeneratedArm64BitfieldDecode.Bitfield) (aux : BitVec 32) (width : Width)
    (dst src : Register) (s : Reference.AArch64.State) :
    bitfieldBody kind aux width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) s =
      Arm64Bitfield.rawStep kind width dst src aux s := by
  simp only [bitfieldBody, Arm64Bitfield.rawStep, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

def dispatchThroughBitfield (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughExtrev code aux width dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => if code = GeneratedArm64DispatchSingleton.code .bitfield then
      (Arm64Bitfield.decodeKind (GeneratedArm64Aux.b0 aux).toNat).map
        (fun kind => bitfieldBody kind aux width dst src s)
    else none

theorem bitfield_reached (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughBitfield (GeneratedArm64DispatchSingleton.code .bitfield) aux width dst src src2 src3
      value sourceScalar sourceStack s = (Arm64Bitfield.decodeKind (GeneratedArm64Aux.b0 aux).toNat).map
        (fun kind => bitfieldBody kind aux width dst src s) := by
  have before : dispatchThroughExtrev (GeneratedArm64DispatchSingleton.code .bitfield) aux width dst src src2 src3
      value sourceScalar sourceStack s = none := rfl
  unfold dispatchThroughBitfield
  rw [before]
  rfl

theorem bitfield_refines (kind : GeneratedArm64BitfieldDecode.Bitfield) (i : Reference.AArch64.BitfieldInstruction)
    (high src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State)
    (matching : Arm64Bitfield.canonicalKind kind = i.kind) :
    dispatchThroughBitfield (GeneratedArm64DispatchSingleton.code .bitfield)
      (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width
      (Arm64Register.registerCode i.dst) (Arm64Register.registerCode i.src) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.bitfield i) s) := by
  rw [bitfield_reached, (Arm64Bitfield.packed_fields kind i.lsbByte i.countByte high).1]
  change some (bitfieldBody kind (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width
    (Arm64Register.registerCode i.dst) (Arm64Register.registerCode i.src) s) = _
  rw [bitfield_body_typed, Arm64Bitfield.raw_step_eq, Arm64Bitfield.step_refines kind i s matching]

theorem bitfield_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : ExtrevBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughBitfield code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughBitfield,
    step_through_extrev_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding]

inductive BitfieldBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : ExtrevBinding pc code aux width dst src src2 src3 value native) :
      BitfieldBinding pc code aux width dst src src2 src3 value native
  | bitfield (kind : GeneratedArm64BitfieldDecode.Bitfield) (i : Reference.AArch64.BitfieldInstruction)
      (high src2 src3 : Byte) (value : Word) (matching : Arm64Bitfield.canonicalKind kind = i.kind) :
      BitfieldBinding pc (GeneratedArm64DispatchSingleton.code .bitfield)
        (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width
        (Arm64Register.registerCode i.dst) (Arm64Register.registerCode i.src) src2 src3 value (.bitfield i)

theorem step_through_bitfield_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : BitfieldBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughBitfield code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact bitfield_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | bitfield => apply bitfield_refines; assumption


/-- Actual flag arithmetic field roles differ between writeback and compares:
ADDS/SUBS read SRC/SRC2 and write DST; CMP/CMN read DST/SRC and never write a
register. The independent generated operand selector is retained. -/
def flagArithmeticBody (subtract writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src src2 : Byte) (value : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let lhs := Arm64Move.Fields.read s (if writeback then src else dst)
  let useImmediate := if writeback then
      GeneratedArm64FlagOperand.immediate (if subtract then if immediate then .subsImm else .subsReg
        else if immediate then .addsImm else .addsReg)
    else if subtract then GeneratedArm64FlagOperand.immediate (if immediate then .cmpImm else .cmpReg)
    else immediate
  let rhs := if useImmediate then value else GeneratedArm64Mod.value
    (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
    (Arm64Move.Fields.read s (if writeback then src2 else src))
    ((GeneratedArm64Aux.b2 aux).setWidth 64) (Arm64Register.handlerWidth width)
  let result := GeneratedArm64FlagHandler.apply (if subtract then .sub else .add) lhs rhs
    (Arm64Register.handlerWidth width)
  let state := if writeback then Arm64Move.Fields.write s dst result.value width else s
  ⟨{ state with flags := Arm64Logic.flagsWord s.flags result.flags, pc := s.pc + 4 }, [], none⟩

/-- This equality derives the correspondence to the earlier typed pipeline;
its byte-field routing is explicit for both compare-only and writeback rows. -/
theorem flag_arithmetic_body_typed (subtract writeback immediate sourceScalar : Bool) (aux : BitVec 32)
    (width : Width) (dst lhs : RegisterRef) (rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    flagArithmeticBody subtract writeback immediate aux width
      (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
      (if writeback then Arm64Move.Fields.encode lhs else Arm64Register.registerCode rhs)
      (Arm64Register.registerCode rhs) value s =
      Arm64Arithmetic.FlagArithmetic.rawStep subtract writeback immediate sourceScalar aux width dst lhs rhs value s := by
  cases writeback <;> cases subtract <;> cases immediate <;>
    simp only [flagArithmeticBody, Arm64Arithmetic.FlagArithmetic.rawStep,
      Arm64Arithmetic.arithmeticHandlerStep, Arm64Arithmetic.compareArithmeticHandlerStep,
      Arm64Arithmetic.FlagArithmetic.registerValue, GeneratedArm64FlagHandler.apply,
      GeneratedArm64FlagHandler.result, GeneratedArm64FlagOperand.immediate,
      Arm64Move.Fields.typed_read, Arm64Move.Fields.typed_write, Arm64Move.Fields.register_read,
      Bool.false_eq_true, Bool.true_eq, Bool.not_true, Bool.false_and, ↓reduceIte]

def dispatchThroughFlagArithmetic (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughBitfield code aux width dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => (Arm64Arithmetic.FlagArithmetic.decodeOpcode code).map
      (fun choice => flagArithmeticBody choice.1 choice.2.1 choice.2.2 aux width dst src src2 value s)

theorem flag_arithmetic_reached (subtract writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughFlagArithmetic (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback immediate)
      aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (flagArithmeticBody subtract writeback immediate aux width dst src src2 value s) := by
  have before : dispatchThroughBitfield (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback immediate)
      aux width dst src src2 src3 value sourceScalar sourceStack s = none := by
    cases subtract <;> cases writeback <;> cases immediate <;> rfl
  unfold dispatchThroughFlagArithmetic
  rw [before, Arm64Arithmetic.FlagArithmetic.decode_code]
  rfl

/-- Immediate rows ignore their physical RHS bytes. In compare rows SRC is
unused, whereas writeback rows still need SRC for the left operand. -/
theorem flag_arithmetic_immediate_body (subtract writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst lhs : RegisterRef) (unusedSrc src2 : Byte) (value : Word) (s : Reference.AArch64.State) :
    flagArithmeticBody subtract writeback true aux width
      (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
      (if writeback then Arm64Move.Fields.encode lhs else unusedSrc) src2 value s =
    flagArithmeticBody subtract writeback true aux width
      (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
      (if writeback then Arm64Move.Fields.encode lhs else Arm64Register.registerCode 31)
      (Arm64Register.registerCode 31) value s := by
  cases writeback <;> cases subtract <;> rfl

/-- Compare rows ignore SRC2 for every byte, including SP32 and NONE255. -/
theorem flag_arithmetic_register_body (subtract writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst lhs : RegisterRef) (rhs : Register) (unusedSrc2 : Byte) (value : Word) (s : Reference.AArch64.State) :
    flagArithmeticBody subtract writeback false aux width
      (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
      (if writeback then Arm64Move.Fields.encode lhs else Arm64Register.registerCode rhs)
      (if writeback then Arm64Register.registerCode rhs else unusedSrc2) value s =
    flagArithmeticBody subtract writeback false aux width
      (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
      (if writeback then Arm64Move.Fields.encode lhs else Arm64Register.registerCode rhs)
      (Arm64Register.registerCode rhs) value s := by
  cases writeback <;> rfl

theorem flag_arithmetic_immediate_refines (subtract writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst lhs : RegisterRef) (unusedSrc src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughFlagArithmetic (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback true) aux width
      (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
      (if writeback then Arm64Move.Fields.encode lhs else unusedSrc) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.arithmeticImmediate width subtract true (if writeback then dst else .zero) lhs value) s) := by
  rw [flag_arithmetic_reached, flag_arithmetic_immediate_body,
    flag_arithmetic_body_typed subtract writeback true sourceScalar,
    Arm64Arithmetic.FlagArithmetic.raw_step_refines]
  rfl

theorem flag_arithmetic_register_refines (subtract writeback : Bool) (width : Width) (dst lhs : RegisterRef)
    (rhs : Register) (kind : Fin 3) (amount : Fin width.bits) (unusedSrc2 src3 lane0 lane3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughFlagArithmetic (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
      (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Arithmetic.registerModifier width kind amount)
        (BitVec.ofNat 8 amount.val) lane0 lane3) width
      (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
      (if writeback then Arm64Move.Fields.encode lhs else Arm64Register.registerCode rhs)
      (if writeback then Arm64Register.registerCode rhs else unusedSrc2) src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.arithmeticRegister width subtract true (if writeback then dst else .zero) lhs rhs kind amount) s) := by
  rw [flag_arithmetic_reached, flag_arithmetic_register_body,
    flag_arithmetic_body_typed subtract writeback false sourceScalar]
  have result := Arm64Arithmetic.FlagArithmetic.dispatch_register_refines subtract writeback sourceScalar width
    dst lhs rhs kind amount value lane0 lane3 s
  simp only [Arm64Arithmetic.FlagArithmetic.dispatch, Arm64Arithmetic.FlagArithmetic.decode_code] at result
  exact result

theorem flag_arithmetic_extended_refines (subtract writeback plainSource : Bool) (width : Width)
    (dst lhs : RegisterRef) (rhs : Register) (kind : Reference.AArch64.RegisterExtend) (amount : Fin 5)
    (unusedSrc2 src3 lane0 lane3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughFlagArithmetic (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
      (Arm64Arithmetic.FlagArithmetic.packedAux
        (Arm64Arithmetic.extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
        (BitVec.ofNat 8 amount.val) lane0 lane3) width
      (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
      (if writeback then Arm64Move.Fields.encode lhs else Arm64Register.registerCode rhs)
      (if writeback then Arm64Register.registerCode rhs else unusedSrc2) src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.arithmeticExtended width subtract true (if writeback then dst else .zero) lhs rhs kind amount) s) := by
  rw [flag_arithmetic_reached, flag_arithmetic_register_body,
    flag_arithmetic_body_typed subtract writeback false sourceScalar]
  have result := Arm64Arithmetic.FlagArithmetic.dispatch_extended_refines subtract writeback sourceScalar plainSource
    width dst lhs rhs kind amount value lane0 lane3 s
  simp only [Arm64Arithmetic.FlagArithmetic.dispatch, Arm64Arithmetic.FlagArithmetic.decode_code] at result
  exact result

theorem flag_arithmetic_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : BitfieldBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughFlagArithmetic code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughFlagArithmetic,
    step_through_bitfield_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding]

/-- Only numeric field routing, native modifier/amount and instruction
identities appear in this extension; no handler-refinement premise is used. -/
inductive FlagArithmeticBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : BitfieldBinding pc code aux width dst src src2 src3 value native) :
      FlagArithmeticBinding pc code aux width dst src src2 src3 value native
  | immediate (subtract writeback : Bool) (aux : BitVec 32) (width : Width) (dst lhs : RegisterRef)
      (unusedSrc src2 src3 : Byte) (value : Word) :
      FlagArithmeticBinding pc (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback true) aux width
        (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
        (if writeback then Arm64Move.Fields.encode lhs else unusedSrc) src2 src3 value
        (.arithmeticImmediate width subtract true (if writeback then dst else .zero) lhs value)
  | register (subtract writeback : Bool) (width : Width) (dst lhs : RegisterRef) (rhs : Register)
      (kind : Fin 3) (amount : Fin width.bits) (unusedSrc2 src3 lane0 lane3 : Byte) (value : Word) :
      FlagArithmeticBinding pc (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
        (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Arithmetic.registerModifier width kind amount)
          (BitVec.ofNat 8 amount.val) lane0 lane3) width
        (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
        (if writeback then Arm64Move.Fields.encode lhs else Arm64Register.registerCode rhs)
        (if writeback then Arm64Register.registerCode rhs else unusedSrc2) src3 value
        (.arithmeticRegister width subtract true (if writeback then dst else .zero) lhs rhs kind amount)
  | extended (subtract writeback plainSource : Bool) (width : Width) (dst lhs : RegisterRef) (rhs : Register)
      (kind : Reference.AArch64.RegisterExtend) (amount : Fin 5) (unusedSrc2 src3 lane0 lane3 : Byte) (value : Word) :
      FlagArithmeticBinding pc (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
        (Arm64Arithmetic.FlagArithmetic.packedAux
          (Arm64Arithmetic.extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
          (BitVec.ofNat 8 amount.val) lane0 lane3) width
        (if writeback then Arm64Move.Fields.encode dst else Arm64Move.Fields.encode lhs)
        (if writeback then Arm64Move.Fields.encode lhs else Arm64Register.registerCode rhs)
        (if writeback then Arm64Register.registerCode rhs else unusedSrc2) src3 value
        (.arithmeticExtended width subtract true (if writeback then dst else .zero) lhs rhs kind amount)

theorem step_through_flag_arithmetic_refines (code : Nat) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : FlagArithmeticBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughFlagArithmetic code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact flag_arithmetic_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | immediate => apply flag_arithmetic_immediate_refines
  | register => apply flag_arithmetic_register_refines
  | extended => apply flag_arithmetic_extended_refines


/-- Actual logical-flag body: test rows read DST/SRC, writeback rows read
SRC/SRC2. The runtime modifier switch retains extensions and unknown-byte
identity; native-form certification below does not add a rejection rule. -/
def flagLogicBody (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src src2 : Byte) (value : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let lhs := Arm64Move.Fields.read s (if writeback then src else dst)
  let rhs := if GeneratedArm64FlagOperand.immediate (Arm64Logic.FlagDispatch.operandOp writeback immediate)
    then value else GeneratedArm64Mod.value
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
      (Arm64Move.Fields.read s (if writeback then src2 else src))
      ((GeneratedArm64Aux.b2 aux).setWidth 64) (Arm64Register.handlerWidth width)
  let result := GeneratedArm64LogicFlagHandler.apply (if invert then .bic else .and) lhs rhs
    (Arm64Register.handlerWidth width)
  let state := if writeback then Arm64Move.Fields.write s dst result.value width else s
  ⟨{ state with flags := Arm64Logic.flagsWord s.flags result.flags, pc := s.pc + 4 }, [], none⟩

theorem flag_logic_body_typed (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs : Register) (value : Word) (s : Reference.AArch64.State) :
    flagLogicBody invert writeback immediate aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) value s =
      Arm64Logic.FlagDispatch.rawStep invert writeback immediate width dst src rhs value
        (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
        ((GeneratedArm64Aux.b2 aux).setWidth 64) s := by
  cases writeback <;> simp only [flagLogicBody, Arm64Logic.FlagDispatch.rawStep, Bool.false_eq_true,
    ↓reduceIte, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

def dispatchThroughFlagLogic (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughFlagArithmetic code aux width dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => (Arm64Logic.FlagDispatch.decodeOpcode code).map
      (fun choice => flagLogicBody choice.1 choice.2.1 choice.2.2 aux width dst src src2 value s)

theorem flag_logic_reached (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State)
    (native : invert = true → immediate = false) :
    dispatchThroughFlagLogic (Arm64Logic.FlagDispatch.operationCode invert writeback immediate)
      aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (flagLogicBody invert writeback immediate aux width dst src src2 value s) := by
  have before : dispatchThroughFlagArithmetic (Arm64Logic.FlagDispatch.operationCode invert writeback immediate)
      aux width dst src src2 src3 value sourceScalar sourceStack s = none := by
    cases invert <;> cases writeback <;> cases immediate <;> rfl
  unfold dispatchThroughFlagLogic
  rw [before, Arm64Logic.FlagDispatch.decode_code invert writeback immediate native]
  rfl

/-- Immediate TST ignores SRC as well as SRC2; ANDS still reads SRC. -/
theorem flag_logic_immediate_body (writeback : Bool) (aux : BitVec 32) (width : Width) (dst src : Register)
    (unusedSrc src2 : Byte) (value : Word) (s : Reference.AArch64.State) :
    flagLogicBody false writeback true aux width (Arm64Register.registerCode dst)
      (if writeback then Arm64Register.registerCode src else unusedSrc) src2 value s =
    flagLogicBody false writeback true aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode 31) value s := by
  cases writeback <;> rfl

theorem flag_logic_register_body (invert writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs : Register) (unusedSrc2 : Byte) (value : Word) (s : Reference.AArch64.State) :
    flagLogicBody invert writeback false aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (if writeback then Arm64Register.registerCode rhs else unusedSrc2) value s =
    flagLogicBody invert writeback false aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) value s := by
  cases writeback <;> rfl

theorem flag_logic_immediate_refines (writeback : Bool) (aux : BitVec 32) (width : Width) (dst src : Register)
    (unusedSrc src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughFlagLogic (Arm64Logic.FlagDispatch.operationCode false writeback true) aux width
      (Arm64Register.registerCode dst) (if writeback then Arm64Register.registerCode src else unusedSrc)
      src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.logicImmediate width (.conjunction false true)
        (Arm64Move.scalarDestination (if writeback then dst else 31)) (if writeback then src else dst) value) s) := by
  rw [flag_logic_reached false writeback true aux width _ _ _ _ value sourceScalar sourceStack s (by simp),
    flag_logic_immediate_body, flag_logic_body_typed]
  have result := Arm64Logic.FlagDispatch.dispatch_immediate_refines writeback aux width dst src 31 value s
  simp only [Arm64Logic.FlagDispatch.dispatch, Arm64Logic.FlagDispatch.decode_code false writeback true (by simp)] at result
  simpa only [Arm64Logic.FlagDispatch.rawStep, Arm64Logic.FlagDispatch.operand_immediate, ↓reduceIte] using result

theorem flag_logic_register_refines (invert writeback : Bool) (width : Width) (kind : Reference.AArch64.ShiftKind)
    (amount : Fin width.bits) (dst src rhs : Register) (unusedSrc2 src3 lane0 lane3 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughFlagLogic (Arm64Logic.FlagDispatch.operationCode invert writeback false)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
      (if writeback then Arm64Register.registerCode rhs else unusedSrc2) src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.logic (Arm64Logic.FlagDispatch.instruction invert writeback width kind amount dst src rhs)) s) := by
  rw [flag_logic_reached invert writeback false _ width _ _ _ _ value sourceScalar sourceStack s (by simp),
    flag_logic_register_body, flag_logic_body_typed]
  change some (Arm64Logic.FlagDispatch.rawStep invert writeback false width dst src rhs value
    (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1
      (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)).toNat)
    ((GeneratedArm64Aux.b2 (Arm64Arithmetic.FlagArithmetic.packedAux
      (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)).setWidth 64) s) = _
  rw [Arm64Arithmetic.FlagArithmetic.packed_modifier, Arm64Arithmetic.FlagArithmetic.packed_amount,
    Arm64Shift.Unary.native_amount, Arm64Logic.FlagDispatch.raw_register_refines]

theorem flag_logic_unmodified_refines (invert writeback : Bool) (width : Width) (dst src rhs : Register)
    (unusedSrc2 src3 amount lane0 lane3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughFlagLogic (Arm64Logic.FlagDispatch.operationCode invert writeback false)
      (Arm64Shift.Unary.packedAux .none amount lane0 lane3) width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (if writeback then Arm64Register.registerCode rhs else unusedSrc2)
      src3 value sourceScalar sourceStack s = some (Reference.AArch64.step
        (.logic (Arm64Logic.FlagDispatch.instruction invert writeback width .lsl
          ⟨0, by cases width <;> decide⟩ dst src rhs)) s) := by
  rw [flag_logic_reached invert writeback false _ width _ _ _ _ value sourceScalar sourceStack s (by simp),
    flag_logic_register_body, flag_logic_body_typed]
  change some (Arm64Logic.FlagDispatch.rawStep invert writeback false width dst src rhs value
    (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1
      (Arm64Arithmetic.FlagArithmetic.packedAux .none amount lane0 lane3)).toNat)
    ((GeneratedArm64Aux.b2 (Arm64Arithmetic.FlagArithmetic.packedAux .none amount lane0 lane3)).setWidth 64) s) = _
  rw [Arm64Arithmetic.FlagArithmetic.packed_modifier, Arm64Logic.FlagDispatch.raw_identity_refines]
  exact congrArg some (Arm64Logic.FlagDispatch.raw_register_refines invert writeback width .lsl
    ⟨0, by cases width <;> decide⟩ dst src rhs value s)

theorem flag_logic_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : FlagArithmeticBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughFlagLogic code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughFlagLogic,
    step_through_flag_arithmetic_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding]

inductive FlagLogicBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : FlagArithmeticBinding pc code aux width dst src src2 src3 value native) :
      FlagLogicBinding pc code aux width dst src src2 src3 value native
  | immediate (writeback : Bool) (aux : BitVec 32) (width : Width) (dst src : Register)
      (unusedSrc src2 src3 : Byte) (value : Word) :
      FlagLogicBinding pc (Arm64Logic.FlagDispatch.operationCode false writeback true) aux width
        (Arm64Register.registerCode dst) (if writeback then Arm64Register.registerCode src else unusedSrc) src2 src3 value
        (.logicImmediate width (.conjunction false true) (Arm64Move.scalarDestination (if writeback then dst else 31))
          (if writeback then src else dst) value)
  | register (invert writeback : Bool) (width : Width) (kind : Reference.AArch64.ShiftKind)
      (amount : Fin width.bits) (dst src rhs : Register) (unusedSrc2 src3 lane0 lane3 : Byte) (value : Word) :
      FlagLogicBinding pc (Arm64Logic.FlagDispatch.operationCode invert writeback false)
        (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3) width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
        (if writeback then Arm64Register.registerCode rhs else unusedSrc2) src3 value
        (.logic (Arm64Logic.FlagDispatch.instruction invert writeback width kind amount dst src rhs))
  | unmodified (invert writeback : Bool) (width : Width) (dst src rhs : Register)
      (unusedSrc2 src3 amount lane0 lane3 : Byte) (value : Word) :
      FlagLogicBinding pc (Arm64Logic.FlagDispatch.operationCode invert writeback false)
        (Arm64Shift.Unary.packedAux .none amount lane0 lane3) width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (if writeback then Arm64Register.registerCode rhs else unusedSrc2) src3 value
        (.logic (Arm64Logic.FlagDispatch.instruction invert writeback width .lsl
          ⟨0, by cases width <;> decide⟩ dst src rhs))

theorem step_through_flag_logic_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : FlagLogicBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughFlagLogic code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact flag_logic_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | immediate => apply flag_logic_immediate_refines
  | register => apply flag_logic_register_refines
  | unmodified => apply flag_logic_unmodified_refines


/-- ORN uses the full production modifier switch before its generated
complemented OR and byte-coded width write. It never changes NZCV. -/
def ornBody (aux : BitVec 32) (width : Width) (dst src src2 : Byte) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let rhs := GeneratedArm64Mod.value (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
    (Arm64Move.Fields.read s src2) ((GeneratedArm64Aux.b2 aux).setWidth 64) (Arm64Register.handlerWidth width)
  let value := GeneratedArm64Orn.value .orn_reg (Arm64Move.Fields.read s src) rhs (Arm64Register.handlerWidth width)
  ⟨{ Arm64Move.Fields.write s dst value width with pc := s.pc + 4 }, [], none⟩

def dispatchThroughOrn (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughFlagLogic code aux width dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => if code = GeneratedArm64Orn.code .orn_reg then some (ornBody aux width dst src src2 s) else none

theorem orn_reached (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughOrn (GeneratedArm64Orn.code .orn_reg) aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (ornBody aux width dst src src2 s) := by
  have before : dispatchThroughFlagLogic (GeneratedArm64Orn.code .orn_reg) aux width dst src src2 src3 value
      sourceScalar sourceStack s = none := rfl
  unfold dispatchThroughOrn
  rw [before]
  rfl

theorem orn_body_refines (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits)
    (dst src rhs : Register) (lane0 lane3 : Byte) (s : Reference.AArch64.State) :
    ornBody (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
      width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) s =
      Reference.AArch64.step (.logic ⟨width, .disjunction true, kind, amount, dst, src, rhs⟩) s := by
  simp only [ornBody, Arm64Arithmetic.FlagArithmetic.packed_modifier, Arm64Arithmetic.FlagArithmetic.packed_amount,
    Arm64Shift.Unary.native_amount, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]
  change Arm64Logic.handlerStep ⟨width, .disjunction true, kind, amount, dst, src, rhs⟩ s = _
  rw [Arm64Logic.step_refines]

theorem orn_unmodified_value (width : Width) (lhs rhs amount : Word) :
    GeneratedArm64Orn.value .orn_reg lhs (GeneratedArm64Mod.value .none rhs amount (Arm64Register.handlerWidth width))
      (Arm64Register.handlerWidth width) =
    GeneratedArm64Orn.value .orn_reg lhs (GeneratedArm64Mod.value .lsl rhs 0 (Arm64Register.handlerWidth width))
      (Arm64Register.handlerWidth width) := by
  cases width <;> simp only [GeneratedArm64Orn.value, GeneratedArm64Mod.value,
    Arm64Register.handlerWidth, GeneratedArm64Width.narrow, GeneratedArm64Width.mask] <;> bv_decide

theorem orn_body_unmodified (width : Width) (dst src src2 : Byte) (amount lane0 lane3 : Byte)
    (s : Reference.AArch64.State) :
    ornBody (Arm64Arithmetic.FlagArithmetic.packedAux .none amount lane0 lane3) width dst src src2 s =
      ornBody (Arm64Arithmetic.FlagArithmetic.packedAux .lsl 0 lane0 lane3) width dst src src2 s := by
  simp only [ornBody, Arm64Arithmetic.FlagArithmetic.packed_modifier,
    Arm64Arithmetic.FlagArithmetic.packed_amount, orn_unmodified_value]
  rfl

theorem orn_refines (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits)
    (dst src rhs : Register) (src3 lane0 lane3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughOrn (GeneratedArm64Orn.code .orn_reg)
      (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
      width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs)
      src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.logic ⟨width, .disjunction true, kind, amount, dst, src, rhs⟩) s) := by
  rw [orn_reached, orn_body_refines]

theorem orn_unmodified_refines (width : Width) (dst src rhs : Register) (src3 amount lane0 lane3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughOrn (GeneratedArm64Orn.code .orn_reg)
      (Arm64Arithmetic.FlagArithmetic.packedAux .none amount lane0 lane3) width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.logic ⟨width, .disjunction true, .lsl,
        ⟨0, by cases width <;> decide⟩, dst, src, rhs⟩) s) := by
  rw [orn_reached, orn_body_unmodified]
  exact congrArg some (orn_body_refines width .lsl ⟨0, by cases width <;> decide⟩ dst src rhs lane0 lane3 s)

theorem orn_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : FlagLogicBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughOrn code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughOrn,
    step_through_flag_logic_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding]

inductive OrnBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : FlagLogicBinding pc code aux width dst src src2 src3 value native) :
      OrnBinding pc code aux width dst src src2 src3 value native
  | shifted (width : Width) (kind : Reference.AArch64.ShiftKind) (amount : Fin width.bits)
      (dst src rhs : Register) (src3 lane0 lane3 : Byte) (value : Word) :
      OrnBinding pc (GeneratedArm64Orn.code .orn_reg)
        (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
        width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) src3 value
        (.logic ⟨width, .disjunction true, kind, amount, dst, src, rhs⟩)
  | unmodified (width : Width) (dst src rhs : Register) (src3 amount lane0 lane3 : Byte) (value : Word) :
      OrnBinding pc (GeneratedArm64Orn.code .orn_reg) (Arm64Arithmetic.FlagArithmetic.packedAux .none amount lane0 lane3)
        width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) src3 value
        (.logic ⟨width, .disjunction true, .lsl, ⟨0, by cases width <;> decide⟩, dst, src, rhs⟩)

theorem step_through_orn_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : OrnBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughOrn code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact orn_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | shifted => apply orn_refines
  | unmodified => apply orn_unmodified_refines


/-- CCMP reads its left operand from physical DST and its optional right
register from SRC. Its generated conditional flags retain both outcomes and
only the low four fallback bits, without any register write. -/
def compareBody (op : GeneratedArm64FlagOperand.FlagOp) (predicate : Arm64Cond) (fallback : Byte)
    (width : Width) (dst src : Byte) (value : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let rhs := if GeneratedArm64FlagOperand.immediate op then value else Arm64Move.Fields.read s src
  let result := GeneratedArm64CcmpHandler.apply (Arm64Arithmetic.incomingFlags s.flags) predicate
    (Arm64Move.Fields.read s dst) rhs (Arm64Register.handlerWidth width) fallback
  ⟨{ s with flags := Arm64Logic.flagsWord s.flags result.flags, pc := s.pc + 4 }, [], none⟩

theorem compare_body_typed (op : GeneratedArm64FlagOperand.FlagOp) (predicate : Arm64Cond) (fallback : Byte)
    (width : Width) (dst src : Register) (value : Word) (s : Reference.AArch64.State) :
    compareBody op predicate fallback width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) value s =
      Arm64Arithmetic.ConditionalCompare.rawStep op width dst src value predicate fallback s := by
  simp only [compareBody, Arm64Arithmetic.ConditionalCompare.rawStep, Arm64Move.Fields.register_read]

def dispatchThroughCompare (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughOrn code aux width dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => (Arm64Arithmetic.ConditionalCompare.decodeOpcode code).bind (fun op =>
      (Arm64Condition.decode (GeneratedArm64CcmpDecode.ccmpCond aux).toNat).map (fun predicate =>
        compareBody op predicate ((GeneratedArm64CcmpDecode.ccmpNzcv aux).setWidth 8) width dst src value s))

theorem compare_reached (immediate : Bool) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughCompare (GeneratedArm64DispatchFamily.code (if immediate then .ccmpImm else .ccmpReg))
      aux width dst src src2 src3 value sourceScalar sourceStack s =
      (Arm64Condition.decode (GeneratedArm64CcmpDecode.ccmpCond aux).toNat).map (fun predicate =>
        compareBody (if immediate then .ccmpImm else .ccmpReg) predicate
          ((GeneratedArm64CcmpDecode.ccmpNzcv aux).setWidth 8) width dst src value s) := by
  have before : dispatchThroughOrn (GeneratedArm64DispatchFamily.code (if immediate then .ccmpImm else .ccmpReg))
      aux width dst src src2 src3 value sourceScalar sourceStack s = none := by cases immediate <;> rfl
  have decoded : Arm64Arithmetic.ConditionalCompare.decodeOpcode
      (GeneratedArm64DispatchFamily.code (if immediate then .ccmpImm else .ccmpReg)) =
      some (if immediate then .ccmpImm else .ccmpReg) := by cases immediate <;> rfl
  unfold dispatchThroughCompare
  rw [before, decoded]
  rfl

theorem compare_immediate_refines (width : Width) (dst : Register) (src src2 src3 : Byte) (value : BitVec 5)
    (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughCompare (GeneratedArm64DispatchFamily.code .ccmpImm)
      (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3) width
      (Arm64Register.registerCode dst) src src2 src3 (value.setWidth 64) sourceScalar sourceStack s =
      some (Reference.AArch64.step (.compare width dst (.immediate value)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) s) := by
  have reached := compare_reached true (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
    width (Arm64Register.registerCode dst) src src2 src3 (value.setWidth 64) sourceScalar sourceStack s
  simp only [↓reduceIte] at reached
  rw [reached, Arm64Arithmetic.ConditionalCompare.packed_condition, Arm64Arithmetic.ConditionalCompare.packed_fallback]
  change some (compareBody .ccmpImm predicate fallback width (Arm64Register.registerCode dst) src (value.setWidth 64) s) = _
  have ignored : compareBody .ccmpImm predicate fallback width (Arm64Register.registerCode dst) src (value.setWidth 64) s =
      compareBody .ccmpImm predicate fallback width (Arm64Register.registerCode dst) (Arm64Register.registerCode 31)
        (value.setWidth 64) s := rfl
  rw [ignored, compare_body_typed, Arm64Arithmetic.ConditionalCompare.raw_immediate_refines]

theorem compare_register_refines (width : Width) (dst src : Register) (src2 src3 : Byte) (value : Word)
    (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughCompare (GeneratedArm64DispatchFamily.code .ccmpReg)
      (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3) width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.compare width dst (.register src)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) s) := by
  have reached := compare_reached false (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
    width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value sourceScalar sourceStack s
  simp only [Bool.false_eq_true, ↓reduceIte] at reached
  rw [reached, Arm64Arithmetic.ConditionalCompare.packed_condition, Arm64Arithmetic.ConditionalCompare.packed_fallback]
  change some (compareBody .ccmpReg predicate fallback width (Arm64Register.registerCode dst)
    (Arm64Register.registerCode src) value s) = _
  rw [compare_body_typed, Arm64Arithmetic.ConditionalCompare.raw_register_refines]

theorem compare_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : OrnBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughCompare code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughCompare,
    step_through_orn_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding]

inductive CompareBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : OrnBinding pc code aux width dst src src2 src3 value native) :
      CompareBinding pc code aux width dst src src2 src3 value native
  | immediate (width : Width) (dst : Register) (src src2 src3 : Byte) (value : BitVec 5)
      (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) :
      CompareBinding pc (GeneratedArm64DispatchFamily.code .ccmpImm)
        (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3) width
        (Arm64Register.registerCode dst) src src2 src3 (value.setWidth 64)
        (.compare width dst (.immediate value) (Arm64Condition.nativeCode predicate) (fallback.setWidth 4))
  | register (width : Width) (dst src : Register) (src2 src3 : Byte) (value : Word)
      (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) :
      CompareBinding pc (GeneratedArm64DispatchFamily.code .ccmpReg)
        (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3) width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
        (.compare width dst (.register src) (Arm64Condition.nativeCode predicate) (fallback.setWidth 4))

theorem step_through_compare_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : CompareBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughCompare code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact compare_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | immediate => apply compare_immediate_refines
  | register => apply compare_register_refines


/-- The production CSEL/X pointer-copy branch precedes the scalar generated
select. Numeric pointer values must be the materialized native values; tag
transport remains Entry/O4 rather than an invented scalar-source restriction. -/
def selectBody (op : GeneratedArm64Csel.Csel) (predicate : Arm64Cond) (width : Width)
    (dst src src2 : Byte) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let taken := generatedArm64Cond (Arm64Condition.flags s.flags) predicate
  let state := if GeneratedArm64CselPtr.ptrTagPath op (Arm64Register.handlerWidth width) then
      Arm64Move.Fields.write s dst (if taken then Arm64Move.Fields.read s src else Arm64Move.Fields.read s src2) .w64
    else Arm64Move.Fields.write s dst
      (GeneratedArm64Csel.value op taken (Arm64Move.Fields.read s src) (Arm64Move.Fields.read s src2)) width
  ⟨{ state with pc := s.pc + 4 }, [], none⟩

theorem select_body_typed (op : GeneratedArm64Csel.Csel) (predicate : Arm64Cond) (width : Width)
    (dst src rhs : Register) (s : Reference.AArch64.State) :
    selectBody op predicate width (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
      (Arm64Register.registerCode rhs) s = Arm64Select.rawStep op width dst src rhs predicate s := by
  simp only [selectBody, Arm64Select.rawStep, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

def dispatchThroughSelect (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughCompare code aux width dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => (Arm64Select.decodeOpcode code).bind (fun op =>
      (Arm64Condition.decode aux.toNat).map (fun predicate => selectBody op predicate width dst src src2 s))

theorem select_reached (op : GeneratedArm64Csel.Csel) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughSelect (GeneratedArm64Csel.code op) aux width dst src src2 src3 value sourceScalar sourceStack s =
      (Arm64Condition.decode aux.toNat).map (fun predicate => selectBody op predicate width dst src src2 s) := by
  have before : dispatchThroughCompare (GeneratedArm64Csel.code op) aux width dst src src2 src3 value
      sourceScalar sourceStack s = none := by cases op <;> rfl
  unfold dispatchThroughSelect
  rw [before, Arm64Select.decode_code]
  rfl

theorem select_condition_decode (predicate : Arm64Cond) :
    Arm64Condition.decode (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)).toNat = some predicate := by
  cases predicate <;> rfl

theorem select_refines (width : Width) (alternative : Reference.AArch64.SelectElse) (dst src rhs : Register)
    (predicate : Arm64Cond) (src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughSelect (GeneratedArm64Csel.code (Arm64Select.opcode alternative))
      (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.select width alternative dst src rhs (Arm64Condition.nativeCode predicate)) s) := by
  rw [select_reached, select_condition_decode]
  change some (selectBody (Arm64Select.opcode alternative) predicate width (Arm64Register.registerCode dst)
    (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) s) = _
  rw [select_body_typed, Arm64Select.raw_step_refines]

/-- Native NV15 is normalized to the existing producer AL14 condition. The
native instruction retains its original code15 in the canonical step. -/
theorem select_normalized_nv_refines (width : Width) (alternative : Reference.AArch64.SelectElse)
    (dst src rhs : Register) (src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatchThroughSelect (GeneratedArm64Csel.code (Arm64Select.opcode alternative))
      (BitVec.ofNat 32 (GeneratedArm64CcDecode.code .nv)) width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.select width alternative dst src rhs 15) s) :=
  select_refines width alternative dst src rhs .al src3 value sourceScalar sourceStack s

/-- CINC/CINV ignore the second source; CSET/CSETM ignore both. No encoding,
presence or provenance predicate is imposed on the ignored bytes. -/
theorem select_alias_unused (alias : Arm64Select.Alias) (predicate : Arm64Cond) (width : Width)
    (dst src : Register) (unusedSrc rhs : Byte) (s : Reference.AArch64.State) :
    selectBody (Arm64Select.aliasOpcode alias) predicate width (Arm64Register.registerCode dst)
      (match alias with | .increment | .invert => Arm64Register.registerCode src | .set | .mask => unusedSrc) rhs s =
    selectBody (Arm64Select.aliasOpcode alias) predicate width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode 31) s := by
  cases alias <;> cases width <;> rfl

theorem select_alias_refines (alias : Arm64Select.Alias) (width : Width) (dst src : Register)
    (predicate : Arm64Cond) (unusedSrc rhs src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) (valid : predicate ≠ .al) :
    dispatchThroughSelect (GeneratedArm64Csel.code (Arm64Select.aliasOpcode alias))
      (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width (Arm64Register.registerCode dst)
      (match alias with | .increment | .invert => Arm64Register.registerCode src | .set | .mask => unusedSrc)
      rhs src3 value sourceScalar sourceStack s = some (Reference.AArch64.step
        (.select width (Arm64Select.aliasAlternative alias) dst (Arm64Select.aliasSource alias src)
          (Arm64Select.aliasSource alias src) (Arm64Condition.nativeCode (Arm64Select.inverse predicate))) s) := by
  rw [select_reached, select_condition_decode]
  change some (selectBody (Arm64Select.aliasOpcode alias) predicate width (Arm64Register.registerCode dst)
    (match alias with | .increment | .invert => Arm64Register.registerCode src | .set | .mask => unusedSrc) rhs s) = _
  rw [select_alias_unused, select_body_typed, Arm64Select.raw_alias_refines width alias dst src 31 predicate s valid]

theorem select_bad_condition (op : GeneratedArm64Csel.Csel) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State)
    (bad : 15 ≤ aux.toNat) :
    dispatchThroughSelect (GeneratedArm64Csel.code op) aux width dst src src2 src3 value sourceScalar sourceStack s = none := by
  rw [select_reached, Arm64Condition.decode_bad aux.toNat bad]
  rfl

theorem select_earlier_preserved (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : CompareBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughSelect code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughSelect,
    step_through_compare_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding]

inductive SelectBinding (pc : Word) : Nat → BitVec 32 → Width → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : CompareBinding pc code aux width dst src src2 src3 value native) :
      SelectBinding pc code aux width dst src src2 src3 value native
  | select (width : Width) (alternative : Reference.AArch64.SelectElse) (dst src rhs : Register)
      (predicate : Arm64Cond) (src3 : Byte) (value : Word) :
      SelectBinding pc (GeneratedArm64Csel.code (Arm64Select.opcode alternative))
        (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) src3 value
        (.select width alternative dst src rhs (Arm64Condition.nativeCode predicate))
  | normalizedNv (width : Width) (alternative : Reference.AArch64.SelectElse) (dst src rhs : Register)
      (src3 : Byte) (value : Word) :
      SelectBinding pc (GeneratedArm64Csel.code (Arm64Select.opcode alternative))
        (BitVec.ofNat 32 (GeneratedArm64CcDecode.code .nv)) width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) src3 value (.select width alternative dst src rhs 15)
  | alias (alias : Arm64Select.Alias) (width : Width) (dst src : Register) (predicate : Arm64Cond)
      (unusedSrc rhs src3 : Byte) (value : Word) (valid : predicate ≠ .al) :
      SelectBinding pc (GeneratedArm64Csel.code (Arm64Select.aliasOpcode alias))
        (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width (Arm64Register.registerCode dst)
        (match alias with | .increment | .invert => Arm64Register.registerCode src | .set | .mask => unusedSrc)
        rhs src3 value (.select width (Arm64Select.aliasAlternative alias) dst (Arm64Select.aliasSource alias src)
          (Arm64Select.aliasSource alias src) (Arm64Condition.nativeCode (Arm64Select.inverse predicate)))

theorem step_through_select_refines (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : SelectBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughSelect code aux width dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier _ _ _ _ _ _ _ _ _ earlier => exact select_earlier_preserved _ _ _ _ _ _ _ _ _ _ _ s earlier
  | select => apply select_refines
  | normalizedNv => apply select_normalized_nv_refines
  | alias => apply select_alias_refines; assumption


/-- Native memory base field31 denotes SP, while a data field31 denotes ZR.
Its actual simulator byte therefore uses the separate SP32 code. -/
def memoryBaseCode (base : Register) : Byte :=
  Arm64Move.Fields.encode (if h : base.val < 31 then .general ⟨base.val, h⟩ else .stack)

theorem memory_base_read (s : Reference.AArch64.State) (base : Register) :
    Arm64Move.Fields.read s (memoryBaseCode base) = Reference.AArch64.memoryBase s base := by
  unfold memoryBaseCode
  rw [Arm64Move.Fields.typed_read, Arm64Move.read_data_refines]
  by_cases general : base.val < 31 <;>
    simp only [general, ↓reduceDIte, Reference.AArch64.readData, Reference.AArch64.memoryBase]
  all_goals rfl

theorem memory_base_write (s : Reference.AArch64.State) (base : Register) (value : Word) :
    Arm64Move.Fields.write s (memoryBaseCode base) value .w64 =
      Reference.AArch64.writeMemoryBase s base value := by
  unfold memoryBaseCode
  rw [Arm64Move.Fields.typed_write, Arm64Move.width_write_refines]
  by_cases general : base.val < 31
  · have notStack : base.val ≠ 31 := by omega
    simp [general, Reference.AArch64.writeMemoryBase, notStack, Reference.AArch64.writeData,
      Reference.AArch64.writeReg, Reference.AArch64.narrow, Reference.AArch64.Width.bits]
  · have stack : base.val = 31 := by have := base.isLt; omega
    simp [general, stack, Reference.AArch64.writeMemoryBase, Reference.AArch64.writeData,
      Reference.AArch64.narrow, Reference.AArch64.Width.bits]

/-- Numeric projection of MEM_PREPOST_STEP: zero delta leaves even the
private base cell untouched; nonzero pointer arithmetic must materialize the
same native word through Entry/O4. The actual SP32 read/write is retained. -/
def bumpMemoryBase (base : Byte) (delta : Word) (s : Reference.AArch64.State) : Reference.AArch64.State :=
  if delta = 0 then s else Arm64Move.Fields.write s base (Arm64Move.Fields.read s base + delta) .w64

theorem memory_base_bump_typed (base : Register) (delta : Word) (s : Reference.AArch64.State) :
    bumpMemoryBase (memoryBaseCode base) delta s = Arm64VectorMemory.bumpBase s base delta := by
  rw [Arm64VectorMemory.bump_refines]
  by_cases zero : delta = 0
  · simp only [bumpMemoryBase, zero, ↓reduceIte, BitVec.add_zero]
    simpa [Reference.Word] using (Arm64VectorMemory.write_base_read s base).symm
  · simp only [bumpMemoryBase, zero, ↓reduceIte, memory_base_read, memory_base_write]

/-- Only the base-update algebra is composed here. An intervening transfer,
its permissions/faults and ordering are still separate obligations. -/
theorem memory_base_prepost (mode : Reference.AArch64.Writeback) (base : Register) (delta : Word)
    (s : Reference.AArch64.State) :
    bumpMemoryBase (memoryBaseCode base)
      (GeneratedArm64MemPrepost.postDelta (Arm64AddressedMemory.flags mode) delta)
      (bumpMemoryBase (memoryBaseCode base)
        (GeneratedArm64MemPrepost.preDelta (Arm64AddressedMemory.flags mode) delta) s) =
      Reference.AArch64.writeMemoryBase s base
        (Reference.AArch64.memoryBase s base + (if mode = .none then 0 else delta)) := by
  rw [memory_base_bump_typed, memory_base_bump_typed]
  exact Arm64VectorMemory.writeback_base_refines mode s base delta

/-- Bind the raw FLAGS byte to each scalar-memory width. Zero is exactly the
production default doubleword, never byte/halfword/word or a 16-byte vector.
These are field identities, not an access-success or safety premise. -/
theorem scalar_memory_width_code (width : Reference.AArch64.MemoryWidth) :
    GeneratedArm64Width.code (Arm64Memory.valueWidth width) = width.bytes := by cases width <;> rfl

theorem scalar_memory_effective_width (flags : Byte) (width : Reference.AArch64.MemoryWidth)
    (encoded : flags.toNat = width.bytes ∨ (flags.toNat = 0 ∧ width = .double)) :
    GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Memory.valueWidth width) := by
  rw [scalar_memory_width_code]
  rcases encoded with explicit | ⟨absent, rfl⟩
  · rw [explicit]
    cases width <;> rfl
  · rw [absent]
    rfl


/-- MEM_BASE_OFF uses the physical index byte, not the duplicate AUX0 lane.
The independent presence/value selectors feed the full modifier switch at X
width before the generated immediate/index offset composition. -/
def memoryOffsetBody (aux : BitVec 32) (index : Byte) (immediate : Word) (s : Reference.AArch64.State) : Word :=
  let present := GeneratedArm64MemIndex.present index
  let value := match GeneratedArm64MemIndexValue.sourceOf present with
    | .zero => 0
    | .registerIndex => GeneratedArm64Mod.value
        (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
        (Arm64Move.Fields.read s index) ((GeneratedArm64Aux.b2 aux).setWidth 64) .w64
  GeneratedArm64MemOffset.value (GeneratedArm64MemPrepost.suppressOffset aux) present immediate value

theorem memory_offset_absent (aux : BitVec 32) (immediate : Word) (s : Reference.AArch64.State) :
    memoryOffsetBody aux GeneratedArm64MemIndex.indexSentinel immediate s =
      GeneratedArm64MemOffset.value (GeneratedArm64MemPrepost.suppressOffset aux) false immediate 0 := rfl

theorem memory_flag_fields (aux : BitVec 32) (mode : Reference.AArch64.Writeback) (immediate : Word)
    (flags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags mode)) :
    GeneratedArm64MemPrepost.preDelta aux immediate =
        GeneratedArm64MemPrepost.preDelta (Arm64AddressedMemory.flags mode) immediate ∧
      GeneratedArm64MemPrepost.postDelta aux immediate =
        GeneratedArm64MemPrepost.postDelta (Arm64AddressedMemory.flags mode) immediate ∧
      GeneratedArm64MemPrepost.suppressOffset aux =
        GeneratedArm64MemPrepost.suppressOffset (Arm64AddressedMemory.flags mode) := by
  simp only [GeneratedArm64MemPrepost.preDelta, GeneratedArm64MemPrepost.postDelta,
    GeneratedArm64MemPrepost.suppressOffset, GeneratedArm64MemPrepost.preWriteback,
    GeneratedArm64MemPrepost.postWriteback, flags, and_self]

/-- Successful scalar transfer through actual byte reads/writes. LOAD retains
the generated tag-preserving branch for every incoming tag predicate. The
packed eight-byte word is a ghost; its event and value ladder use only WIDTH
bytes. This body inserts no C permission/alignment guard. -/
def scalarMemorySuccess (load : Bool) (width : Reference.AArch64.MemoryWidth) (data : Byte)
    (address : Word) (tagIsScalar : Bool) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  if load then
    let loaded := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width) (wordAt s.memory address 8)
    let value := Arm64Memory.loadResult width none loaded
    let state := if GeneratedArm64LoadTag.preserve (Arm64Memory.valueWidth width) tagIsScalar then
        Arm64Move.Fields.write s data value .w64
      else Arm64Move.Fields.write s data value (Arm64Memory.destinationWidth width none)
    ⟨{ state with pc := s.pc + 4 }, [.memory .read address (bytesAt s.memory address width.bytes)
      (initializedAt s.memory address width.bytes)], none⟩
  else
    let value := Arm64Move.Fields.read s data
    ⟨{ s with memory := Arm64Memory.store width s.memory address value, pc := s.pc + 4 },
      [.memory .write address (valueBytes value width.bytes) true], none⟩

theorem scalar_memory_success_typed (load : Bool) (width : Reference.AArch64.MemoryWidth) (data : Register)
    (address : Word) (tagIsScalar : Bool) (s : Reference.AArch64.State) :
    scalarMemorySuccess load width (Arm64Register.registerCode data) address tagIsScalar s =
      Arm64WritebackMemory.success width (if load then .load data none else .store data) address s := by
  cases load <;> cases width <;> cases tagIsScalar <;>
    simp only [scalarMemorySuccess, Arm64WritebackMemory.success, Bool.false_eq_true, Bool.not_true,
      Bool.not_false, Bool.true_and, Bool.false_and, ↓reduceIte,
      GeneratedArm64LoadTag.preserve, Arm64Memory.valueWidth, Arm64Memory.destinationWidth,
      Arm64Move.Fields.register_read, Arm64Move.Fields.register_write, beq_self_eq_true, reduceCtorEq]
  all_goals rfl

/-- The actual numeric MEM_PRE/access/MEM_POST order. Materialized pointers,
shadow/payload conversion, provenance and accepted access permissions still
need their Entry/O2/O4 witnesses. Faulting pre/post is not rewritten as success. -/
def scalarMemoryBody (load : Bool) (width : Reference.AArch64.MemoryWidth) (aux : BitVec 32)
    (data base index : Byte) (immediate : Word) (tagIsScalar : Bool) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let before := bumpMemoryBase base (GeneratedArm64MemPrepost.preDelta aux immediate) s
  let address := Arm64Move.Fields.read before base + memoryOffsetBody aux index immediate before
  let transferred := scalarMemorySuccess load width data address tagIsScalar before
  { transferred with state := bumpMemoryBase base (GeneratedArm64MemPrepost.postDelta aux immediate) transferred.state }

theorem scalar_memory_body_immediate (load : Bool) (width : Reference.AArch64.MemoryWidth)
    (aux : BitVec 32) (data base : Register) (mode : Reference.AArch64.Writeback) (immediate : Word)
    (tagIsScalar : Bool) (s : Reference.AArch64.State)
    (flags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags mode)) :
    scalarMemoryBody load width aux (Arm64Register.registerCode data) (memoryBaseCode base)
      GeneratedArm64MemIndex.indexSentinel immediate tagIsScalar s =
      Arm64WritebackMemory.core width (if load then .load data none else .store data) mode base immediate s := by
  obtain ⟨pre, post, suppressed⟩ := memory_flag_fields aux mode immediate flags
  simp only [scalarMemoryBody, Arm64WritebackMemory.core, pre, post, suppressed,
    memory_offset_absent, memory_base_bump_typed, memory_base_read,
    scalar_memory_success_typed, Arm64Memory.base_refines]

theorem scalar_memory_immediate_refines (load : Bool) (i : Reference.AArch64.AddressedMemoryInstruction)
    (data : Register) (aux : BitVec 32) (immediate : Word) (tagIsScalar : Bool) (s : Reference.AArch64.State)
    (transfer : i.transfer = if load then .load data none else .store data)
    (offset : i.offset = .immediate immediate)
    (flags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback))
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none)
    (accessible : permitted (if load then s.memory.readable else s.memory.writable)
      (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else immediate)) i.width.bytes = true) :
    scalarMemoryBody load i.width aux (Arm64Register.registerCode data) (memoryBaseCode i.base)
      GeneratedArm64MemIndex.indexSentinel immediate tagIsScalar s =
      Reference.AArch64.step (.addressedMemory i) s := by
  rw [scalar_memory_body_immediate load i.width aux data i.base i.writeback immediate tagIsScalar s flags]
  have access : permitted (match i.transfer with | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
      (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else immediate)) i.width.bytes = true := by
    cases load <;> simpa only [transfer, Bool.false_eq_true, ↓reduceIte] using accessible
  have result := Arm64WritebackMemory.core_refines i immediate s offset alignment access
  rw [transfer] at result
  exact result

end KProgFormal.Refinement.Arm64Dispatcher
