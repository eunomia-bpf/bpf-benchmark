import KProgFormal.Refinement.Arm64Move
import KProgFormal.Refinement.Arm64Atomic
import KProgFormal.Refinement.Arm64Reduction
import KProgFormal.Refinement.Arm64Exclusive
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

/-- The two immediate alias labels share the generic ALU immediate body for
every AUX value, width, register assignment, operand and incoming state. AUX
continues to identify the ALU operation in the common C body. -/
theorem immediate_alias_dispatch (alias : Nat) (isAlias : alias = 3 ∨ alias = 4)
    (aux : BitVec 32) (width : Width) (dst src src2 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    dispatch alias aux width dst src src2 value sourceScalar sourceStack s =
      dispatch 6 aux width dst src src2 value sourceScalar sourceStack s := by
  rcases isAlias with h | h <;> subst alias <;> rfl

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

/-- The two immediate alias labels refine canonical ADD/SUB for every state
and operand, using the same AUX operation binding as the common ALU body. -/
theorem arithmetic_immediate_alias_refines (subtract sourceScalar sourceStack : Bool)
    (width : Width) (dst src : RegisterRef) (src2 : Byte) (value : Word)
    (lane1 lane2 lane3 : Byte) (s : Reference.AArch64.State) :
    dispatch (if subtract then 4 else 3)
      (Arm64Arithmetic.AluDispatch.immediateAux subtract lane1 lane2 lane3) width
      (Arm64Move.Fields.encode dst) (Arm64Move.Fields.encode src) src2 value sourceScalar sourceStack s =
      some (Reference.AArch64.step (.arithmeticImmediate width subtract false dst src value) s) := by
  have isAlias : (if subtract then 4 else 3) = 3 ∨ (if subtract then 4 else 3) = 4 := by
    cases subtract <;> decide
  rw [immediate_alias_dispatch _ isAlias]
  exact arithmetic_immediate_refines subtract sourceScalar sourceStack width dst src src2 value lane1 lane2 lane3 s

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



/-- A native register index is present even when field31 reads ZR; only the
actual NONE255 byte suppresses the index. -/
theorem memory_index_present (index : Register) :
    GeneratedArm64MemIndex.present (Arm64Register.registerCode index) = true := by
  have different : Arm64Register.registerCode index ≠ GeneratedArm64MemIndex.indexSentinel := by
    intro equal
    have numbers := congrArg BitVec.toNat equal
    change index.val % 256 = 255 at numbers
    rw [Nat.mod_eq_of_lt (show index.val < 256 by omega)] at numbers
    have := index.isLt
    omega
  simp only [GeneratedArm64MemIndex.present, GeneratedArm64MemIndex.arm, different, ↓reduceIte]

/-- An omitted unscaled X modifier is the same native index as LSL0/SXTX0.
Only enum/amount identities are assumed, never an evaluated index equality. -/
theorem memory_index_modifier (width : Reference.AArch64.MemoryWidth) (kind : Reference.AArch64.MemoryExtend)
    (scaled : Bool) (mod : GeneratedArm64ModDecode.Mod) (value : Word)
    (encoded : mod = Arm64AddressedMemory.modifier kind ∨
      (mod = .none ∧ (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then width.scale else 0) = 0)) :
    GeneratedArm64Mod.value mod value (BitVec.ofNat 64 (if scaled then width.scale else 0)) .w64 =
      GeneratedArm64Mod.value (Arm64AddressedMemory.modifier kind) value
        (BitVec.ofNat 64 (if scaled then width.scale else 0)) .w64 := by
  rcases encoded with standard | ⟨omitted, kinds, zero⟩
  · rw [standard]
  · rw [omitted, zero]
    rcases kinds with rfl | rfl <;>
      simp [Arm64AddressedMemory.modifier, GeneratedArm64Mod.value, GeneratedArm64Width.mask, Reference.Word] <;> bv_decide

theorem memory_offset_indexed (width : Reference.AArch64.MemoryWidth) (aux : BitVec 32) (index : Register)
    (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (s : Reference.AArch64.State)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then width.scale else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then width.scale else 0)) :
    memoryOffsetBody aux (Arm64Register.registerCode index) 0 s =
      Arm64WritebackMemory.offsetValue width s (.register index kind scaled) := by
  have suppressed : GeneratedArm64MemPrepost.suppressOffset aux = false :=
    (memory_flag_fields aux .none 0 memoryFlags).2.2
  unfold memoryOffsetBody
  rw [memory_index_present]
  simp only [GeneratedArm64MemIndexValue.sourceOf, ↓reduceIte, Arm64Move.Fields.register_read, suppressed]
  rw [amount, memory_index_modifier width kind scaled _ _ mod]
  simp [GeneratedArm64MemOffset.value, Arm64WritebackMemory.offsetValue, Reference.Word]

theorem scalar_memory_body_indexed (load : Bool) (width : Reference.AArch64.MemoryWidth) (aux : BitVec 32)
    (data base index : Register) (kind : Reference.AArch64.MemoryExtend) (scaled tagIsScalar : Bool)
    (s : Reference.AArch64.State)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then width.scale else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then width.scale else 0)) :
    scalarMemoryBody load width aux (Arm64Register.registerCode data) (memoryBaseCode base)
      (Arm64Register.registerCode index) 0 tagIsScalar s =
      Arm64WritebackMemory.core width (if load then .load data none else .store data) .none base
        (Arm64WritebackMemory.offsetValue width s (.register index kind scaled)) s := by
  have pre : GeneratedArm64MemPrepost.preDelta aux 0 = 0 := by
    unfold GeneratedArm64MemPrepost.preDelta
    split <;> rfl
  have post : GeneratedArm64MemPrepost.postDelta aux 0 = 0 := by
    unfold GeneratedArm64MemPrepost.postDelta
    split <;> rfl
  simp only [scalarMemoryBody, pre, post, bumpMemoryBase, ↓reduceIte,
    memory_offset_indexed width aux index kind scaled s memoryFlags mod amount,
    memory_base_read, scalar_memory_success_typed]
  simp only [Arm64WritebackMemory.core, Arm64Memory.base_refines]
  rfl

/-- Raw FLAGS normalization for the certified W/X prefix. Other widths pass
onward to memory/vector families; None is this normalization boundary, not a
new C runtime rejection policy. Zero uses the same generated X default. -/
def decodeDataWidth (flags : Byte) : Option Width :=
  let effective := GeneratedArm64Width.effective flags.toNat
  if effective = GeneratedArm64Width.code .w32 then some .w32
  else if effective = GeneratedArm64Width.code .w64 then some .w64 else none

def decodeMemoryWidth (flags : Byte) : Option Reference.AArch64.MemoryWidth :=
  let effective := GeneratedArm64Width.effective flags.toNat
  if effective = 1 then some .byte else if effective = 2 then some .half
  else if effective = 4 then some .word else if effective = 8 then some .double else none

theorem decode_data_width (flags : Byte) (width : Width)
    (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth width)) :
    decodeDataWidth flags = some width := by
  simp only [decodeDataWidth, encoded]
  cases width <;> rfl

theorem decode_memory_width (flags : Byte) (width : Reference.AArch64.MemoryWidth)
    (encoded : GeneratedArm64Width.effective flags.toNat = width.bytes) :
    decodeMemoryWidth flags = some width := by
  simp only [decodeMemoryWidth, encoded]
  cases width <;> rfl

def dispatchEncodedPrefix (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  (decodeDataWidth flags).bind (fun width =>
    dispatchThroughSelect code aux width dst src src2 src3 value sourceScalar sourceStack s)

/-- The next actual LOAD gate consumes the same raw FLAGS byte, including
byte and halfword widths which are never coerced to integer W/X. -/
def dispatchThroughLoad (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchEncodedPrefix code flags aux dst src src2 src3 value sourceScalar sourceStack s with
  | some result => some result
  | none => if code = GeneratedArm64DispatchSingleton.code .load then
      (decodeMemoryWidth flags).map (fun width => scalarMemoryBody true width aux dst src src2 value tagIsScalar s)
    else none

theorem load_reached (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State) :
    dispatchThroughLoad (GeneratedArm64DispatchSingleton.code .load) flags aux dst src src2 src3 value
      sourceScalar sourceStack tagIsScalar s =
      (decodeMemoryWidth flags).map (fun width => scalarMemoryBody true width aux dst src src2 value tagIsScalar s) := by
  have before : dispatchEncodedPrefix (GeneratedArm64DispatchSingleton.code .load) flags aux dst src src2 src3 value
      sourceScalar sourceStack s = none := by
    unfold dispatchEncodedPrefix
    cases decoded : decodeDataWidth flags with
    | none => rfl
    | some width =>
        change dispatchThroughSelect (GeneratedArm64DispatchSingleton.code .load) aux width dst src src2 src3 value
          sourceScalar sourceStack s = none
        rfl
  unfold dispatchThroughLoad
  rw [before]
  rfl

theorem load_earlier_preserved (code : Nat) (flags : Byte) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack tagIsScalar : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth width))
    (binding : SelectBinding s.pc code aux width dst src src2 src3 value native) :
    dispatchThroughLoad code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step native s) := by
  have before : dispatchEncodedPrefix code flags aux dst src src2 src3 value sourceScalar sourceStack s =
      some (Reference.AArch64.step native s) := by
    unfold dispatchEncodedPrefix
    rw [decode_data_width flags width encoded]
    exact step_through_select_refines code aux width dst src src2 src3 value sourceScalar sourceStack native s binding
  unfold dispatchThroughLoad
  rw [before]

theorem load_immediate_refines (i : Reference.AArch64.AddressedMemoryInstruction) (data : Register)
    (flags : Byte) (aux : BitVec 32) (immediate : Word) (src3 : Byte)
    (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State)
    (transfer : i.transfer = .load data none) (offset : i.offset = .immediate immediate)
    (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback))
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else immediate)) i.width.bytes = true) :
    dispatchThroughLoad (GeneratedArm64DispatchSingleton.code .load) flags aux (Arm64Register.registerCode data)
      (memoryBaseCode i.base) GeneratedArm64MemIndex.indexSentinel src3 immediate sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step (.addressedMemory i) s) := by
  rw [load_reached, decode_memory_width flags i.width encoded]
  change some (scalarMemoryBody true i.width aux (Arm64Register.registerCode data) (memoryBaseCode i.base)
    GeneratedArm64MemIndex.indexSentinel immediate tagIsScalar s) = _
  exact congrArg some (scalar_memory_immediate_refines true i data aux immediate tagIsScalar s transfer offset
    memoryFlags alignment accessible)


theorem load_indexed_refines (i : Reference.AArch64.AddressedMemoryInstruction) (data index : Register)
    (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (flags : Byte) (aux : BitVec 32) (src3 : Byte)
    (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State)
    (transfer : i.transfer = .load data none) (offset : i.offset = .register index kind scaled)
    (noWriteback : i.writeback = .none) (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then i.width.scale else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then i.width.scale else 0))
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (Reference.AArch64.memoryBase s i.base + Arm64WritebackMemory.offsetValue i.width s i.offset) i.width.bytes = true) :
    dispatchThroughLoad (GeneratedArm64DispatchSingleton.code .load) flags aux (Arm64Register.registerCode data)
      (memoryBaseCode i.base) (Arm64Register.registerCode index) src3 0 sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step (.addressedMemory i) s) := by
  rw [load_reached, decode_memory_width flags i.width encoded]
  change some (scalarMemoryBody true i.width aux (Arm64Register.registerCode data) (memoryBaseCode i.base)
    (Arm64Register.registerCode index) 0 tagIsScalar s) = _
  rw [scalar_memory_body_indexed true i.width aux data i.base index kind scaled tagIsScalar s memoryFlags mod amount]
  have access : permitted (match i.transfer with | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
      (Reference.AArch64.memoryBase s i.base + Arm64WritebackMemory.offsetValue i.width s i.offset) i.width.bytes = true := by
    simpa only [transfer] using accessible
  have result := Arm64WritebackMemory.indexed_refines i s noWriteback alignment access
  rw [transfer, offset] at result
  exact congrArg some result

/-- Raw instruction-field identities only; access witnesses are deliberately
separate below, never a component-step equality hidden in a constructor. -/
inductive LoadBinding (pc : Word) : Nat → Byte → BitVec 32 → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (flags : Byte) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Byte)
      (value : Word) (native : Reference.AArch64.Instruction)
      (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth width))
      (binding : SelectBinding pc code aux width dst src src2 src3 value native) :
      LoadBinding pc code flags aux dst src src2 src3 value native
  | immediate (i : Reference.AArch64.AddressedMemoryInstruction) (data : Register) (flags : Byte)
      (aux : BitVec 32) (immediate : Word) (src3 : Byte) (transfer : i.transfer = .load data none)
      (offset : i.offset = .immediate immediate) (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback)) :
      LoadBinding pc (GeneratedArm64DispatchSingleton.code .load) flags aux (Arm64Register.registerCode data)
        (memoryBaseCode i.base) GeneratedArm64MemIndex.indexSentinel src3 immediate (.addressedMemory i)

  | indexed (i : Reference.AArch64.AddressedMemoryInstruction) (data index : Register)
      (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (flags : Byte) (aux : BitVec 32) (src3 : Byte)
      (transfer : i.transfer = .load data none) (offset : i.offset = .register index kind scaled)
      (noWriteback : i.writeback = .none) (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
      (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
        (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
          (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then i.width.scale else 0) = 0))
      (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then i.width.scale else 0)) :
      LoadBinding pc (GeneratedArm64DispatchSingleton.code .load) flags aux (Arm64Register.registerCode data)
        (memoryBaseCode i.base) (Arm64Register.registerCode index) src3 0 (.addressedMemory i)

/-- Original SP-alignment/read-permission assumptions required by the C
success core. They are not runtime guards, nor derived from tag/shadow values.
Kernel/Entry/O2/O4 still must establish them for an admitted artifact. -/
def scalarMemoryAccess (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State) : Prop :=
  match native with
  | .addressedMemory i =>
      Reference.AArch64.spAlignmentFault s i.base = none ∧
        permitted (match i.transfer with | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
          (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else
            Reference.AArch64.memoryOffset s i.width.scale i.offset)) i.width.bytes = true
  | .atomicAdd i | .atomicLogical _ i =>
      Reference.AArch64.spAlignmentFault s i.base = none ∧
      Reference.AArch64.atomicAlignmentFault s (Reference.AArch64.memoryBase s i.base) i.width.bytes = none ∧
      permitted s.memory.readable (Reference.AArch64.memoryBase s i.base) i.width.bytes = true ∧
      permitted s.memory.writable (Reference.AArch64.memoryBase s i.base) i.width.bytes = true
  | _ => True

theorem step_through_load_refines (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : LoadBinding s.pc code flags aux dst src src2 src3 value native)
    (access : scalarMemoryAccess native s) :
    dispatchThroughLoad code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier code flags aux width dst src src2 src3 value native encoded earlier =>
      exact load_earlier_preserved code flags aux width dst src src2 src3 value sourceScalar sourceStack tagIsScalar native s encoded earlier
  | immediate i data flags aux _ src3 transfer offset encoded memoryFlags =>
      rcases access with ⟨alignment, accessible⟩
      have readable : permitted s.memory.readable
          (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else value)) i.width.bytes = true := by
        simpa only [transfer, offset, Reference.AArch64.memoryOffset] using accessible
      exact load_immediate_refines i data flags aux value src3 sourceScalar sourceStack tagIsScalar s
        transfer offset encoded memoryFlags alignment readable
  | indexed i data index kind scaled flags aux src3 transfer offset noWriteback encoded memoryFlags mod amount =>
      rcases access with ⟨alignment, accessible⟩
      have readable : permitted s.memory.readable
          (Reference.AArch64.memoryBase s i.base + Arm64WritebackMemory.offsetValue i.width s i.offset) i.width.bytes = true := by
        rw [← Arm64WritebackMemory.offset_refines i.width s i.offset] at accessible
        simpa only [transfer, noWriteback, reduceCtorEq, ↓reduceIte] using accessible
      exact load_indexed_refines i data index kind scaled flags aux src3 sourceScalar sourceStack tagIsScalar s
        transfer offset noWriteback encoded memoryFlags mod amount alignment readable


/-- Signed loads choose memory width and sign operation from the opcode,
then apply the independent FLAGS-selected W/X destination write. -/
def signedMemorySuccess (op : GeneratedArm64LdrSx.LdrSx) (output : Width) (dst : Byte)
    (address : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let width := Arm64WritebackMemory.signedWidth op
  let loaded := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width) (wordAt s.memory address 8)
  let value := GeneratedArm64Extrev.value (Arm64WritebackMemory.signedExtend op) loaded 0 0
    (Arm64Register.handlerWidth output)
  ⟨{ Arm64Move.Fields.write s dst value output with pc := s.pc + 4 },
    [.memory .read address (bytesAt s.memory address width.bytes) (initializedAt s.memory address width.bytes)], none⟩

theorem signed_memory_success_typed (op : GeneratedArm64LdrSx.LdrSx) (output : Width) (dst : Register)
    (address : Word) (s : Reference.AArch64.State) :
    signedMemorySuccess op output (Arm64Register.registerCode dst) address s =
      Arm64WritebackMemory.signedSuccess op dst output address s := by
  simp only [signedMemorySuccess, Arm64WritebackMemory.signedSuccess, Arm64Move.Fields.register_write]

def signedMemoryBody (op : GeneratedArm64LdrSx.LdrSx) (output : Width) (aux : BitVec 32)
    (dst base index : Byte) (immediate : Word) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let before := bumpMemoryBase base (GeneratedArm64MemPrepost.preDelta aux immediate) s
  let address := Arm64Move.Fields.read before base + memoryOffsetBody aux index immediate before
  let transferred := signedMemorySuccess op output dst address before
  { transferred with state := bumpMemoryBase base (GeneratedArm64MemPrepost.postDelta aux immediate) transferred.state }

theorem signed_memory_body_immediate (op : GeneratedArm64LdrSx.LdrSx) (output : Width) (aux : BitVec 32)
    (dst base : Register) (mode : Reference.AArch64.Writeback) (immediate : Word) (s : Reference.AArch64.State)
    (flags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags mode)) :
    signedMemoryBody op output aux (Arm64Register.registerCode dst) (memoryBaseCode base)
      GeneratedArm64MemIndex.indexSentinel immediate s =
      Arm64WritebackMemory.signedCore op dst output mode base immediate s := by
  obtain ⟨pre, post, suppressed⟩ := memory_flag_fields aux mode immediate flags
  simp only [signedMemoryBody, Arm64WritebackMemory.signedCore, pre, post, suppressed,
    memory_offset_absent, memory_base_bump_typed, memory_base_read,
    signed_memory_success_typed, Arm64Memory.base_refines]

theorem signed_memory_body_indexed (op : GeneratedArm64LdrSx.LdrSx) (output : Width) (aux : BitVec 32)
    (dst base index : Register) (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (s : Reference.AArch64.State)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then (Arm64WritebackMemory.signedWidth op).scale else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 =
      BitVec.ofNat 64 (if scaled then (Arm64WritebackMemory.signedWidth op).scale else 0)) :
    signedMemoryBody op output aux (Arm64Register.registerCode dst) (memoryBaseCode base)
      (Arm64Register.registerCode index) 0 s = Arm64WritebackMemory.signedCore op dst output .none base
        (Arm64WritebackMemory.offsetValue (Arm64WritebackMemory.signedWidth op) s (.register index kind scaled)) s := by
  have pre : GeneratedArm64MemPrepost.preDelta aux 0 = 0 := by
    unfold GeneratedArm64MemPrepost.preDelta
    split <;> rfl
  have post : GeneratedArm64MemPrepost.postDelta aux 0 = 0 := by
    unfold GeneratedArm64MemPrepost.postDelta
    split <;> rfl
  simp only [signedMemoryBody, pre, post, bumpMemoryBase, ↓reduceIte,
    memory_offset_indexed (Arm64WritebackMemory.signedWidth op) aux index kind scaled s memoryFlags mod amount,
    memory_base_read, signed_memory_success_typed]
  simp only [Arm64WritebackMemory.signedCore, Arm64Memory.base_refines]
  rfl

/-- The canonical decoder reserves W-output word sign-loads. This is native
field validity, not a new C guard on the generated numeric body. -/
def signedNativeOutput (op : GeneratedArm64LdrSx.LdrSx) (output : Width) : Prop :=
  op = .ldrSw → output = .w64

def dispatchThroughSigned (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughLoad code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s with
  | some result => some result
  | none => (Arm64WritebackMemory.signedDecode code).bind (fun op =>
      (decodeDataWidth flags).map (fun output => signedMemoryBody op output aux dst src src2 value s))

theorem signed_reached (op : GeneratedArm64LdrSx.LdrSx) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State) :
    dispatchThroughSigned (GeneratedArm64LdrSx.code op) flags aux dst src src2 src3 value
      sourceScalar sourceStack tagIsScalar s =
      (decodeDataWidth flags).map (fun output => signedMemoryBody op output aux dst src src2 value s) := by
  have before : dispatchEncodedPrefix (GeneratedArm64LdrSx.code op) flags aux dst src src2 src3 value
      sourceScalar sourceStack s = none := by
    unfold dispatchEncodedPrefix
    cases decoded : decodeDataWidth flags with
    | none => rfl
    | some width =>
        change dispatchThroughSelect (GeneratedArm64LdrSx.code op) aux width dst src src2 src3 value
          sourceScalar sourceStack s = none
        cases op <;> rfl
  have notLoad : GeneratedArm64LdrSx.code op ≠ GeneratedArm64DispatchSingleton.code .load := by cases op <;> decide
  unfold dispatchThroughSigned dispatchThroughLoad
  rw [before, if_neg notLoad, Arm64WritebackMemory.signed_decode_code]
  rfl

theorem signed_immediate_refines (op : GeneratedArm64LdrSx.LdrSx) (output : Width)
    (i : Reference.AArch64.AddressedMemoryInstruction) (data : Register) (flags : Byte) (aux : BitVec 32)
    (immediate : Word) (src3 : Byte) (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State)
    (width : i.width = Arm64WritebackMemory.signedWidth op) (transfer : i.transfer = .load data (some output))
    (offset : i.offset = .immediate immediate)
    (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth output))
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback))
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else immediate)) i.width.bytes = true) :
    dispatchThroughSigned (GeneratedArm64LdrSx.code op) flags aux (Arm64Register.registerCode data)
      (memoryBaseCode i.base) GeneratedArm64MemIndex.indexSentinel src3 immediate sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step (.addressedMemory i) s) := by
  rw [signed_reached, decode_data_width flags output encoded]
  change some (signedMemoryBody op output aux (Arm64Register.registerCode data) (memoryBaseCode i.base)
    GeneratedArm64MemIndex.indexSentinel immediate s) = _
  rw [signed_memory_body_immediate op output aux data i.base i.writeback immediate s memoryFlags]
  exact congrArg some (Arm64WritebackMemory.signed_core_refines op i data output immediate s width transfer offset alignment accessible)

theorem signed_indexed_refines (op : GeneratedArm64LdrSx.LdrSx) (output : Width)
    (i : Reference.AArch64.AddressedMemoryInstruction) (data index : Register) (kind : Reference.AArch64.MemoryExtend)
    (scaled : Bool) (flags : Byte) (aux : BitVec 32) (src3 : Byte) (sourceScalar sourceStack tagIsScalar : Bool)
    (s : Reference.AArch64.State) (width : i.width = Arm64WritebackMemory.signedWidth op)
    (transfer : i.transfer = .load data (some output)) (offset : i.offset = .register index kind scaled)
    (noWriteback : i.writeback = .none)
    (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth output))
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then i.width.scale else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then i.width.scale else 0))
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.readable
      (Reference.AArch64.memoryBase s i.base + Arm64WritebackMemory.offsetValue i.width s i.offset) i.width.bytes = true) :
    dispatchThroughSigned (GeneratedArm64LdrSx.code op) flags aux (Arm64Register.registerCode data)
      (memoryBaseCode i.base) (Arm64Register.registerCode index) src3 0 sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step (.addressedMemory i) s) := by
  rw [signed_reached, decode_data_width flags output encoded]
  change some (signedMemoryBody op output aux (Arm64Register.registerCode data) (memoryBaseCode i.base)
    (Arm64Register.registerCode index) 0 s) = _
  rw [width] at mod amount
  rw [signed_memory_body_indexed op output aux data i.base index kind scaled s memoryFlags mod amount]
  have result := Arm64WritebackMemory.signed_indexed_refines op i data output s width transfer noWriteback alignment accessible
  rw [offset, width] at result
  exact congrArg some result

theorem signed_earlier_preserved (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : LoadBinding s.pc code flags aux dst src src2 src3 value native)
    (access : scalarMemoryAccess native s) :
    dispatchThroughSigned code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughSigned,
    step_through_load_refines code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar native s binding access]

inductive SignedBinding (pc : Word) : Nat → Byte → BitVec 32 → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : LoadBinding pc code flags aux dst src src2 src3 value native) :
      SignedBinding pc code flags aux dst src src2 src3 value native
  | immediate (op : GeneratedArm64LdrSx.LdrSx) (output : Width) (i : Reference.AArch64.AddressedMemoryInstruction)
      (data : Register) (flags : Byte) (aux : BitVec 32) (immediate : Word) (src3 : Byte)
      (width : i.width = Arm64WritebackMemory.signedWidth op) (transfer : i.transfer = .load data (some output))
      (offset : i.offset = .immediate immediate) (nativeOutput : signedNativeOutput op output)
      (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth output))
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback)) :
      SignedBinding pc (GeneratedArm64LdrSx.code op) flags aux (Arm64Register.registerCode data)
        (memoryBaseCode i.base) GeneratedArm64MemIndex.indexSentinel src3 immediate (.addressedMemory i)
  | indexed (op : GeneratedArm64LdrSx.LdrSx) (output : Width) (i : Reference.AArch64.AddressedMemoryInstruction)
      (data index : Register) (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (flags : Byte) (aux : BitVec 32) (src3 : Byte)
      (width : i.width = Arm64WritebackMemory.signedWidth op) (transfer : i.transfer = .load data (some output))
      (offset : i.offset = .register index kind scaled) (noWriteback : i.writeback = .none)
      (nativeOutput : signedNativeOutput op output)
      (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth output))
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
      (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
        (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
          (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then i.width.scale else 0) = 0))
      (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then i.width.scale else 0)) :
      SignedBinding pc (GeneratedArm64LdrSx.code op) flags aux (Arm64Register.registerCode data)
        (memoryBaseCode i.base) (Arm64Register.registerCode index) src3 0 (.addressedMemory i)

theorem step_through_signed_refines (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : SignedBinding s.pc code flags aux dst src src2 src3 value native)
    (access : scalarMemoryAccess native s) :
    dispatchThroughSigned code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier code flags aux dst src src2 src3 value native earlier =>
      exact signed_earlier_preserved code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar native s earlier access
  | immediate op output i data flags aux _ src3 width transfer offset nativeOutput encoded memoryFlags =>
      rcases access with ⟨alignment, accessible⟩
      have readable : permitted s.memory.readable
          (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else value)) i.width.bytes = true := by
        simpa only [transfer, offset, Reference.AArch64.memoryOffset] using accessible
      exact signed_immediate_refines op output i data flags aux value src3 sourceScalar sourceStack tagIsScalar s
        width transfer offset encoded memoryFlags alignment readable
  | indexed op output i data index kind scaled flags aux src3 width transfer offset noWriteback nativeOutput encoded memoryFlags mod amount =>
      rcases access with ⟨alignment, accessible⟩
      have readable : permitted s.memory.readable
          (Reference.AArch64.memoryBase s i.base + Arm64WritebackMemory.offsetValue i.width s i.offset) i.width.bytes = true := by
        rw [← Arm64WritebackMemory.offset_refines i.width s i.offset] at accessible
        simpa only [transfer, noWriteback, reduceCtorEq, ↓reduceIte] using accessible
      exact signed_indexed_refines op output i data index kind scaled flags aux src3 sourceScalar sourceStack tagIsScalar s
        width transfer offset noWriteback encoded memoryFlags mod amount alignment readable


/-- STORE follows signed loads and consumes DST as base, SRC as data and
SRC2 as index. The same raw FLAGS decode retains exact byte/half/word/double
stores; it does not use the preceding signed row's output width. -/
def dispatchThroughStore (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughSigned code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s with
  | some result => some result
  | none => if code = GeneratedArm64DispatchSingleton.code .store then
      (decodeMemoryWidth flags).map (fun width => scalarMemoryBody false width aux src dst src2 value tagIsScalar s)
    else none

theorem store_reached (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State) :
    dispatchThroughStore (GeneratedArm64DispatchSingleton.code .store) flags aux dst src src2 src3 value
      sourceScalar sourceStack tagIsScalar s =
      (decodeMemoryWidth flags).map (fun width => scalarMemoryBody false width aux src dst src2 value tagIsScalar s) := by
  have before : dispatchEncodedPrefix (GeneratedArm64DispatchSingleton.code .store) flags aux dst src src2 src3 value
      sourceScalar sourceStack s = none := by
    unfold dispatchEncodedPrefix
    cases decoded : decodeDataWidth flags with
    | none => rfl
    | some width =>
        change dispatchThroughSelect (GeneratedArm64DispatchSingleton.code .store) aux width dst src src2 src3 value
          sourceScalar sourceStack s = none
        rfl
  have separate : GeneratedArm64DispatchSingleton.code .store ≠ GeneratedArm64DispatchSingleton.code .load := by decide
  have noSigned : Arm64WritebackMemory.signedDecode (GeneratedArm64DispatchSingleton.code .store) = none := rfl
  unfold dispatchThroughStore dispatchThroughSigned dispatchThroughLoad
  rw [before, if_neg separate, noSigned]
  rfl

theorem store_immediate_refines (i : Reference.AArch64.AddressedMemoryInstruction) (data : Register)
    (flags : Byte) (aux : BitVec 32) (immediate : Word) (src3 : Byte)
    (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State)
    (transfer : i.transfer = .store data) (offset : i.offset = .immediate immediate)
    (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback))
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.writable
      (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else immediate)) i.width.bytes = true) :
    dispatchThroughStore (GeneratedArm64DispatchSingleton.code .store) flags aux (memoryBaseCode i.base)
      (Arm64Register.registerCode data) GeneratedArm64MemIndex.indexSentinel src3 immediate
      sourceScalar sourceStack tagIsScalar s = some (Reference.AArch64.step (.addressedMemory i) s) := by
  rw [store_reached, decode_memory_width flags i.width encoded]
  change some (scalarMemoryBody false i.width aux (Arm64Register.registerCode data) (memoryBaseCode i.base)
    GeneratedArm64MemIndex.indexSentinel immediate tagIsScalar s) = _
  exact congrArg some (scalar_memory_immediate_refines false i data aux immediate tagIsScalar s transfer offset
    memoryFlags alignment accessible)

theorem store_indexed_refines (i : Reference.AArch64.AddressedMemoryInstruction) (data index : Register)
    (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (flags : Byte) (aux : BitVec 32) (src3 : Byte)
    (sourceScalar sourceStack tagIsScalar : Bool) (s : Reference.AArch64.State)
    (transfer : i.transfer = .store data) (offset : i.offset = .register index kind scaled)
    (noWriteback : i.writeback = .none) (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then i.width.scale else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then i.width.scale else 0))
    (alignment : Reference.AArch64.spAlignmentFault s i.base = none)
    (accessible : permitted s.memory.writable
      (Reference.AArch64.memoryBase s i.base + Arm64WritebackMemory.offsetValue i.width s i.offset) i.width.bytes = true) :
    dispatchThroughStore (GeneratedArm64DispatchSingleton.code .store) flags aux (memoryBaseCode i.base)
      (Arm64Register.registerCode data) (Arm64Register.registerCode index) src3 0 sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step (.addressedMemory i) s) := by
  rw [store_reached, decode_memory_width flags i.width encoded]
  change some (scalarMemoryBody false i.width aux (Arm64Register.registerCode data) (memoryBaseCode i.base)
    (Arm64Register.registerCode index) 0 tagIsScalar s) = _
  rw [scalar_memory_body_indexed false i.width aux data i.base index kind scaled tagIsScalar s memoryFlags mod amount]
  have access : permitted (match i.transfer with | .load _ _ => s.memory.readable | .store _ => s.memory.writable)
      (Reference.AArch64.memoryBase s i.base + Arm64WritebackMemory.offsetValue i.width s i.offset) i.width.bytes = true := by
    simpa only [transfer] using accessible
  have result := Arm64WritebackMemory.indexed_refines i s noWriteback alignment access
  rw [transfer, offset] at result
  exact congrArg some result

theorem store_earlier_preserved (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : SignedBinding s.pc code flags aux dst src src2 src3 value native)
    (access : scalarMemoryAccess native s) :
    dispatchThroughStore code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step native s) := by
  simp only [dispatchThroughStore,
    step_through_signed_refines code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar native s binding access]

inductive StoreBinding (pc : Word) : Nat → Byte → BitVec 32 → Byte → Byte → Byte → Byte → Word →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : SignedBinding pc code flags aux dst src src2 src3 value native) :
      StoreBinding pc code flags aux dst src src2 src3 value native
  | immediate (i : Reference.AArch64.AddressedMemoryInstruction) (data : Register) (flags : Byte)
      (aux : BitVec 32) (immediate : Word) (src3 : Byte) (transfer : i.transfer = .store data)
      (offset : i.offset = .immediate immediate) (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback)) :
      StoreBinding pc (GeneratedArm64DispatchSingleton.code .store) flags aux (memoryBaseCode i.base)
        (Arm64Register.registerCode data) GeneratedArm64MemIndex.indexSentinel src3 immediate (.addressedMemory i)
  | indexed (i : Reference.AArch64.AddressedMemoryInstruction) (data index : Register)
      (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (flags : Byte) (aux : BitVec 32) (src3 : Byte)
      (transfer : i.transfer = .store data) (offset : i.offset = .register index kind scaled)
      (noWriteback : i.writeback = .none) (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
      (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
        (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
          (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then i.width.scale else 0) = 0))
      (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then i.width.scale else 0)) :
      StoreBinding pc (GeneratedArm64DispatchSingleton.code .store) flags aux (memoryBaseCode i.base)
        (Arm64Register.registerCode data) (Arm64Register.registerCode index) src3 0 (.addressedMemory i)

theorem step_through_store_refines (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : StoreBinding s.pc code flags aux dst src src2 src3 value native)
    (access : scalarMemoryAccess native s) :
    dispatchThroughStore code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier code flags aux dst src src2 src3 value native earlier =>
      exact store_earlier_preserved code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar native s earlier access
  | immediate i data flags aux _ src3 transfer offset encoded memoryFlags =>
      rcases access with ⟨alignment, accessible⟩
      have writable : permitted s.memory.writable
          (Reference.AArch64.memoryBase s i.base + (if i.writeback = .post then 0 else value)) i.width.bytes = true := by
        simpa only [transfer, offset, Reference.AArch64.memoryOffset] using accessible
      exact store_immediate_refines i data flags aux value src3 sourceScalar sourceStack tagIsScalar s
        transfer offset encoded memoryFlags alignment writable
  | indexed i data index kind scaled flags aux src3 transfer offset noWriteback encoded memoryFlags mod amount =>
      rcases access with ⟨alignment, accessible⟩
      have writable : permitted s.memory.writable
          (Reference.AArch64.memoryBase s i.base + Arm64WritebackMemory.offsetValue i.width s i.offset) i.width.bytes = true := by
        rw [← Arm64WritebackMemory.offset_refines i.width s i.offset] at accessible
        simpa only [transfer, noWriteback, reduceCtorEq, ↓reduceIte] using accessible
      exact store_indexed_refines i data index kind scaled flags aux src3 sourceScalar sourceStack tagIsScalar s
        transfer offset noWriteback encoded memoryFlags mod amount alignment writable


/-- The actual STLXR numeric body: SRC2 is the base, SRC is captured before
DST's fixed-W status write, and NONE plus zero displacement makes every AUX
byte irrelevant to the address. `failure` is the nonzero result of the
site-indexed environment call, not a nondeterministic replacement for C. -/
def exclusiveStoreBody (width : Width) (failure : Bool) (aux : BitVec 32)
    (status data base : Byte) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let address := Arm64Move.Fields.read s base + memoryOffsetBody aux GeneratedArm64MemIndex.indexSentinel 0 s
  let value := Arm64Move.Fields.read s data
  let stored := if failure then s else
    { s with memory := Arm64Memory.store (Arm64Exclusive.accessWidth width) s.memory address value }
  let result := Arm64Move.Fields.write stored status (GeneratedArm64Stlxr.value .stlxr .w32 failure) .w32
  ⟨{ result with pc := s.pc + 4 },
    if failure then [] else [.memory .write address (valueBytes value width.bytes) true], none⟩

theorem exclusive_zero_offset (aux : BitVec 32) (s : Reference.AArch64.State) :
    memoryOffsetBody aux GeneratedArm64MemIndex.indexSentinel 0 s = 0 := by
  rw [memory_offset_absent]
  cases GeneratedArm64MemPrepost.suppressOffset aux <;> rfl

/-- A proof observation, never a C instruction: attach the canonical monitor
and attempt/order event to an already computed numeric transition. Its input
must be tied to the original STXR/STLXR word and site by Entry/O2/O4. This
function alone supplies no atomicity, ordering or native-identity guarantee. -/
def observeExclusiveStore (width : Width) (release failure : Bool) (base : Byte)
    (s : Reference.AArch64.State) (result : Transition Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  { result with
    state := { result.state with exclusiveMonitor := (Arm64Exclusive.checkedState s).exclusiveMonitor }
    events := [.exclusive .attempt (Arm64Move.Fields.read s base) width.bytes false release (!failure)] ++ result.events }

theorem exclusive_body_observation (width : Width) (release failure : Bool) (aux : BitVec 32)
    (status data base : Register) (s : Reference.AArch64.State) :
    observeExclusiveStore width release failure (memoryBaseCode base) s
      (exclusiveStoreBody width failure aux (Arm64Register.registerCode status)
        (Arm64Register.registerCode data) (memoryBaseCode base) s) =
      Arm64Exclusive.storeCore width release failure status data base s := by
  simp only [exclusiveStoreBody, exclusive_zero_offset, BitVec.add_zero]
  cases failure <;> cases retained : s.exclusiveInputs.retainLocal <;>
    cases virtual : s.exclusiveInputs.virtualPass <;>
    simp [observeExclusiveStore, exclusiveStoreBody, exclusive_zero_offset,
      Arm64Move.Fields.register_read, Arm64Move.Fields.register_write, memory_base_read,
      Arm64Exclusive.storeCore, Arm64Exclusive.checkedState, retained, virtual,
      Arm64Memory.base_refines, Arm64Register.read_refines, Arm64Register.write_refines,
      Reference.AArch64.writeReg, Reference.AArch64.narrow, Reference.AArch64.Width.bits]

/-- Numeric dispatcher extension in production order. The supplied outcome
is obtained at IMM's environment site; no monitor or order event is added. -/
def dispatchThroughExclusive (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar failure : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughStore code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar s with
  | some result => some result
  | none => if code = GeneratedArm64Stlxr.code .stlxr then
      (decodeDataWidth flags).map (fun width => exclusiveStoreBody width failure aux dst src src2 s)
    else none

theorem exclusive_reached (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack tagIsScalar failure : Bool) (s : Reference.AArch64.State) :
    dispatchThroughExclusive (GeneratedArm64Stlxr.code .stlxr) flags aux dst src src2 src3 value
      sourceScalar sourceStack tagIsScalar failure s =
      (decodeDataWidth flags).map (fun width => exclusiveStoreBody width failure aux dst src src2 s) := by
  have before : dispatchEncodedPrefix (GeneratedArm64Stlxr.code .stlxr) flags aux dst src src2 src3 value
      sourceScalar sourceStack s = none := by
    unfold dispatchEncodedPrefix
    cases decoded : decodeDataWidth flags with
    | none => rfl
    | some width =>
        change dispatchThroughSelect (GeneratedArm64Stlxr.code .stlxr) aux width dst src src2 src3 value
          sourceScalar sourceStack s = none
        rfl
  unfold dispatchThroughExclusive dispatchThroughStore dispatchThroughSigned dispatchThroughLoad
  rw [before]
  rfl

/-- Only the exclusive row receives the explicit ghost observation. Earlier
rows retain their exact states/events. `release` comes from the original
native word, which is not recoverable from the shared STLXR opcode row. -/
def observeExclusiveDispatch (code : Nat) (flags : Byte) (release failure : Bool) (base : Byte)
    (s : Reference.AArch64.State) (result : Option (Transition Reference.AArch64.State)) :
    Option (Transition Reference.AArch64.State) :=
  if code = GeneratedArm64Stlxr.code .stlxr then
    match decodeDataWidth flags with
    | some width => result.map (observeExclusiveStore width release failure base s)
    | none => result
  else result

/-- Native environmental conditions remain separate from field binding.
Inaccessible memory can still be an architectural failed store when the
profile does not preflight it; success always needs native writable bytes. -/
def exclusiveStoreEnvironment (native : Reference.AArch64.Instruction) (failure : Bool)
    (s : Reference.AArch64.State) : Prop :=
  match native with
  | .exclusive (.store width _ _ _ base) =>
      failure = !Reference.AArch64.exclusiveStorePass s width.bytes ∧
      Reference.AArch64.spAlignmentFault s base = none ∧
      Reference.AArch64.exclusiveNaturalFault (Reference.AArch64.memoryBase s base) width.bytes = none ∧
      ((Reference.AArch64.exclusiveMonitorPass s width.bytes || s.exclusiveInputs.abortOnFailure) = true →
        permitted s.memory.writable (Reference.AArch64.memoryBase s base) width.bytes = true)
  | _ => True

inductive ExclusiveBinding (pc : Word) : Nat → Byte → BitVec 32 → Byte → Byte → Byte → Byte → Word → Bool →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (release : Bool) (native : Reference.AArch64.Instruction)
      (binding : StoreBinding pc code flags aux dst src src2 src3 value native) :
      ExclusiveBinding pc code flags aux dst src src2 src3 value release native
  | store (width : Width) (release : Bool) (status data base : Register) (flags : Byte)
      (aux : BitVec 32) (src3 : Byte) (site : Word)
      (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth width)) :
      ExclusiveBinding pc (GeneratedArm64Stlxr.code .stlxr) flags aux (Arm64Register.registerCode status)
        (Arm64Register.registerCode data) (memoryBaseCode base) src3 site release
        (.exclusive (.store width release status data base))

/-- A previously certified row cannot be the exclusive gate. This is derived
from the actual dispatcher, rather than made another caller premise. -/
theorem store_binding_not_exclusive (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar : Bool) (native : Reference.AArch64.Instruction)
    (s : Reference.AArch64.State) (binding : StoreBinding s.pc code flags aux dst src src2 src3 value native)
    (access : scalarMemoryAccess native s) : code ≠ GeneratedArm64Stlxr.code .stlxr := by
  intro equal
  have actual := step_through_store_refines code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar native s binding access
  rw [equal] at actual
  have before : dispatchThroughStore (GeneratedArm64Stlxr.code .stlxr) flags aux dst src src2 src3 value
      sourceScalar sourceStack tagIsScalar s = none := by
    unfold dispatchThroughStore dispatchThroughSigned dispatchThroughLoad dispatchEncodedPrefix
    cases decoded : decodeDataWidth flags with
    | none => rfl
    | some width => rfl
  rw [before] at actual
  contradiction

/-- One step for the prefix through STLXR under the explicit native ghost
observation and environment. This is not an unconditional claim about C
atomicity/order or an end-to-end certificate for the compiled body. -/
theorem step_through_exclusive_observed_refines (code : Nat) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack tagIsScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : ExclusiveBinding s.pc code flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s) :
    observeExclusiveDispatch code flags release failure src2 s
      (dispatchThroughExclusive code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar failure s) =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier code flags aux dst src src2 src3 value release native earlier =>
      have separate := store_binding_not_exclusive code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar native s earlier access
      simp only [observeExclusiveDispatch, separate, ↓reduceIte, dispatchThroughExclusive,
        step_through_store_refines code flags aux dst src src2 src3 value sourceScalar sourceStack tagIsScalar native s earlier access]
  | store width release status data base flags aux src3 site encoded =>
      rw [exclusive_reached]
      simp only [observeExclusiveDispatch, ↓reduceIte, decode_data_width flags width encoded, Option.map_some]
      change some (observeExclusiveStore width release failure (memoryBaseCode base) s
        (exclusiveStoreBody width failure aux (Arm64Register.registerCode status)
          (Arm64Register.registerCode data) (memoryBaseCode base) s)) = _
      rw [exclusive_body_observation]
      rcases environment with ⟨outcome, spAligned, aligned, preflight⟩
      exact congrArg some (Arm64Exclusive.store_core_refines width release failure status data base s
        outcome spAligned aligned preflight)


/-- NATIVE_LAB_EXCLUSIVE_FAILURE is queried at the physical IMM site. Its
64-bit result is Booleanized exactly once: every nonzero word is failure,
including values whose low 32 bits are zero. Native-site/layout binding is
still required of the trusted producer and bound environment. -/
def dispatchThroughExclusiveAt (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (site : Word) (sourceScalar sourceStack tagIsScalar : Bool) (outcomeAt : Word → Word)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  dispatchThroughExclusive code flags aux dst src src2 src3 site sourceScalar sourceStack tagIsScalar
    (outcomeAt site != 0) s

theorem step_through_exclusive_at_observed_refines (code : Nat) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (site : Word) (sourceScalar sourceStack tagIsScalar release : Bool)
    (outcomeAt : Word → Word) (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : ExclusiveBinding s.pc code flags aux dst src src2 src3 site release native)
    (access : scalarMemoryAccess native s)
    (environment : exclusiveStoreEnvironment native (outcomeAt site != 0) s) :
    observeExclusiveDispatch code flags release (outcomeAt site != 0) src2 s
      (dispatchThroughExclusiveAt code flags aux dst src src2 src3 site sourceScalar sourceStack tagIsScalar outcomeAt s) =
      some (Reference.AArch64.step native s) :=
  step_through_exclusive_observed_refines code flags aux dst src src2 src3 site sourceScalar sourceStack tagIsScalar
    release (outcomeAt site != 0) native s binding access environment


/-- Two native-width elements, with both tag-preserving LOAD branches. The
address is captured before either destination write, including base aliases;
the second element uses WIDTH as stride, not an unconditional eight bytes. -/
def pairByteSuccess (load : Bool) (width : Width) (first second : Byte) (address : Word)
    (firstScalar secondScalar : Bool) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let one := scalarMemorySuccess load (Arm64Exclusive.accessWidth width) first address firstScalar s
  let two := scalarMemorySuccess load (Arm64Exclusive.accessWidth width) second
    (address + BitVec.ofNat 64 (GeneratedArm64Width.code (Arm64Register.handlerWidth width))) secondScalar one.state
  { two with state := { two.state with pc := s.pc + 4 }, events := one.events ++ two.events }

theorem pair_byte_success_typed (i : Reference.AArch64.PairMemoryInstruction) (address : Word)
    (firstScalar secondScalar : Bool) (s : Reference.AArch64.State) :
    pairByteSuccess i.load i.width (Arm64Register.registerCode i.first) (Arm64Register.registerCode i.second)
      address firstScalar secondScalar s = Arm64WritebackMemory.pairSuccess i address s := by
  simp only [pairByteSuccess, scalar_memory_success_typed, Arm64WritebackMemory.pairSuccess,
    (Arm64PairMemory.fields_refine i s).2.2.2.1]
  rfl

/-- Actual pair pre/access/post sequence. SRC3 is the physical index byte;
AUX0 is not used as a substitute. Native LDP/STP have immediate addressing,
so their binding selects NONE while keeping AUX0/modifier bytes arbitrary. -/
def pairByteBody (load : Bool) (width : Width) (aux : BitVec 32) (first second base index : Byte)
    (immediate : Word) (firstScalar secondScalar : Bool) (s : Reference.AArch64.State) :
    Transition Reference.AArch64.State :=
  let before := bumpMemoryBase base (GeneratedArm64MemPrepost.preDelta aux immediate) s
  let address := Arm64Move.Fields.read before base + memoryOffsetBody aux index immediate before
  let transferred := pairByteSuccess load width first second address firstScalar secondScalar before
  { transferred with state := bumpMemoryBase base (GeneratedArm64MemPrepost.postDelta aux immediate) transferred.state }

theorem pair_byte_body_typed (i : Reference.AArch64.PairMemoryInstruction) (mode : Reference.AArch64.Writeback)
    (aux : BitVec 32) (firstScalar secondScalar : Bool) (s : Reference.AArch64.State)
    (flags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags mode)) :
    pairByteBody i.load i.width aux (Arm64Register.registerCode i.first) (Arm64Register.registerCode i.second)
      (memoryBaseCode i.base) GeneratedArm64MemIndex.indexSentinel i.offset firstScalar secondScalar s =
      Arm64WritebackMemory.pairCore i mode s := by
  obtain ⟨pre, post, suppressed⟩ := memory_flag_fields aux mode i.offset flags
  simp only [pairByteBody, Arm64WritebackMemory.pairCore, pre, post, suppressed,
    memory_offset_absent, memory_base_bump_typed, memory_base_read, pair_byte_success_typed,
    Arm64Memory.base_refines]

def pairCode (load : Bool) : Nat := GeneratedArm64DispatchSingleton.code (if load then .ldp else .stp)

/-- LDP routes DST/SRC as the two destinations, SRC2 as base and SRC3 as
index. STP routes SRC/SRC2 as data, DST as base and SRC3 as index. -/
def dispatchThroughPair (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughExclusive code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar failure s with
  | some result => some result
  | none => if code = pairCode true then
      (decodeDataWidth flags).map (fun width => pairByteBody true width aux dst src src2 src3 value firstScalar secondScalar s)
    else if code = pairCode false then
      (decodeDataWidth flags).map (fun width => pairByteBody false width aux src src2 dst src3 value firstScalar secondScalar s)
    else none

theorem pair_before_none (load : Bool) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack tagIsScalar failure : Bool) (s : Reference.AArch64.State) :
    dispatchThroughExclusive (pairCode load) flags aux dst src src2 src3 value
      sourceScalar sourceStack tagIsScalar failure s = none := by
  unfold dispatchThroughExclusive dispatchThroughStore dispatchThroughSigned dispatchThroughLoad dispatchEncodedPrefix
  cases decoded : decodeDataWidth flags with
  | none => cases load <;> rfl
  | some width => cases load <;> rfl

theorem pair_reached (load : Bool) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    dispatchThroughPair (pairCode load) flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s =
      (decodeDataWidth flags).map (fun width => pairByteBody load width aux
        (if load then dst else src) (if load then src else src2) (if load then src2 else dst) src3 value
        firstScalar secondScalar s) := by
  unfold dispatchThroughPair
  rw [pair_before_none]
  cases load <;> rfl

/-- Profile and access witnesses refer to the original native memory. Each
ordered element needs its own permission; no private tag/shadow permission
supplies it. The two-access profile is explicit rather than coalesced to LSE2. -/
def pairMemoryAccess (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State) : Prop :=
  match native with
  | .addressedPairMemory i =>
      Reference.AArch64.spAlignmentFault s i.instruction.base = none ∧ s.pairSingleAccess = false ∧
      permitted (if i.instruction.load then s.memory.readable else s.memory.writable)
        (Reference.AArch64.memoryBase s i.instruction.base + (if i.writeback = .post then 0 else i.instruction.offset))
        i.instruction.width.bytes = true ∧
      permitted (if i.instruction.load then s.memory.readable else s.memory.writable)
        (Reference.AArch64.memoryBase s i.instruction.base + (if i.writeback = .post then 0 else i.instruction.offset) +
          BitVec.ofNat 64 i.instruction.width.bytes) i.instruction.width.bytes = true
  | _ => True

inductive PairBinding (pc : Word) : Nat → Byte → BitVec 32 → Byte → Byte → Byte → Byte → Word → Bool →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (release : Bool) (native : Reference.AArch64.Instruction)
      (binding : ExclusiveBinding pc code flags aux dst src src2 src3 value release native) :
      PairBinding pc code flags aux dst src src2 src3 value release native
  | pair (i : Reference.AArch64.AddressedPairMemoryInstruction) (flags : Byte) (aux : BitVec 32) (release : Bool)
      (encoded : GeneratedArm64Width.effective flags.toNat =
        GeneratedArm64Width.code (Arm64Register.handlerWidth i.instruction.width))
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback)) :
      PairBinding pc (pairCode i.instruction.load) flags aux
        (if i.instruction.load then Arm64Register.registerCode i.instruction.first else memoryBaseCode i.instruction.base)
        (if i.instruction.load then Arm64Register.registerCode i.instruction.second else Arm64Register.registerCode i.instruction.first)
        (if i.instruction.load then memoryBaseCode i.instruction.base else Arm64Register.registerCode i.instruction.second)
        GeneratedArm64MemIndex.indexSentinel i.instruction.offset release (.addressedPairMemory i)

theorem pair_byte_refines (i : Reference.AArch64.AddressedPairMemoryInstruction) (flags : Byte) (aux : BitVec 32)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State)
    (encoded : GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth i.instruction.width))
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags i.writeback))
    (access : pairMemoryAccess (.addressedPairMemory i) s) :
    dispatchThroughPair (pairCode i.instruction.load) flags aux
      (if i.instruction.load then Arm64Register.registerCode i.instruction.first else memoryBaseCode i.instruction.base)
      (if i.instruction.load then Arm64Register.registerCode i.instruction.second else Arm64Register.registerCode i.instruction.first)
      (if i.instruction.load then memoryBaseCode i.instruction.base else Arm64Register.registerCode i.instruction.second)
      GeneratedArm64MemIndex.indexSentinel i.instruction.offset sourceScalar sourceStack firstScalar secondScalar failure s =
      some (Reference.AArch64.step (.addressedPairMemory i) s) := by
  rw [pair_reached, decode_data_width flags i.instruction.width encoded]
  have routing : ∀ (load : Bool) (first second base : Byte),
      (if load then (if load then first else base) else (if load then second else first)) = first ∧
      (if load then (if load then second else first) else (if load then base else second)) = second ∧
      (if load then (if load then base else second) else (if load then first else base)) = base := by
    intro load first second base; cases load <;> exact ⟨rfl, rfl, rfl⟩
  obtain ⟨first, second, base⟩ := routing i.instruction.load (Arm64Register.registerCode i.instruction.first)
    (Arm64Register.registerCode i.instruction.second) (memoryBaseCode i.instruction.base)
  change some (pairByteBody i.instruction.load i.instruction.width aux _ _ _ GeneratedArm64MemIndex.indexSentinel
    i.instruction.offset firstScalar secondScalar s) = _
  rw [first, second, base, pair_byte_body_typed i.instruction i.writeback aux firstScalar secondScalar s memoryFlags]
  rcases access with ⟨alignment, profile, one, two⟩
  exact congrArg some (Arm64WritebackMemory.pair_core_refines i s alignment profile one two)

theorem step_through_pair_observed_refines (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : PairBinding s.pc code flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) :
    observeExclusiveDispatch code flags release failure src2 s
      (dispatchThroughPair code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s) =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier code flags aux dst src src2 src3 value release native earlier =>
      have result := step_through_exclusive_observed_refines code flags aux dst src src2 src3 value sourceScalar
        sourceStack firstScalar release failure native s earlier access environment
      have numeric : ∃ prior, dispatchThroughExclusive code flags aux dst src src2 src3 value
          sourceScalar sourceStack firstScalar failure s = some prior := by
        cases raw : dispatchThroughExclusive code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar failure s with
        | none => simp [raw, observeExclusiveDispatch] at result; split at result <;> simp_all
        | some prior => exact ⟨prior, rfl⟩
      obtain ⟨prior, reached⟩ := numeric
      simpa only [dispatchThroughPair, reached] using result
  | pair i flags aux release encoded memoryFlags =>
      have separate : pairCode i.instruction.load ≠ GeneratedArm64Stlxr.code .stlxr := by
        cases i.instruction.load <;> decide
      simp only [observeExclusiveDispatch, separate, ↓reduceIte]
      exact pair_byte_refines i flags aux sourceScalar sourceStack firstScalar secondScalar failure s encoded memoryFlags pairAccess


/-- Actual D0 pre/access/post body using the already-derived eight-byte
transfer and generated upper-half clearing. FLAGS and the unused integer
operand bytes do not select its width or vector bank. -/
def dByteBody (load : Bool) (aux : BitVec 32) (base index : Byte) (immediate : Word)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let before := bumpMemoryBase base (GeneratedArm64MemPrepost.preDelta aux immediate) s
  let address := Arm64Move.Fields.read before base + memoryOffsetBody aux index immediate before
  let transferred := Arm64VectorMemory.dSuccess load address before
  { transferred with state := bumpMemoryBase base (GeneratedArm64MemPrepost.postDelta aux immediate) transferred.state }

theorem d_byte_body_immediate (load : Bool) (mode : Reference.AArch64.Writeback) (aux : BitVec 32)
    (base : Register) (immediate : Word) (s : Reference.AArch64.State)
    (flags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags mode)) :
    dByteBody load aux (memoryBaseCode base) GeneratedArm64MemIndex.indexSentinel immediate s =
      Arm64VectorMemory.dWritebackCore load mode base immediate s := by
  obtain ⟨pre, post, suppressed⟩ := memory_flag_fields aux mode immediate flags
  simp only [dByteBody, Arm64VectorMemory.dWritebackCore, pre, post, suppressed,
    memory_offset_absent, memory_base_bump_typed, memory_base_read, Arm64Memory.base_refines]

theorem d_byte_body_indexed (load : Bool) (aux : BitVec 32) (base index : Register)
    (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (s : Reference.AArch64.State)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then 3 else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then 3 else 0)) :
    dByteBody load aux (memoryBaseCode base) (Arm64Register.registerCode index) 0 s =
      Arm64VectorMemory.dWritebackCore load .none base (Arm64VectorMemory.dOffset s (.register index kind scaled)) s := by
  have pre : GeneratedArm64MemPrepost.preDelta aux 0 = 0 := by
    unfold GeneratedArm64MemPrepost.preDelta; split <;> rfl
  have post : GeneratedArm64MemPrepost.postDelta aux 0 = 0 := by
    unfold GeneratedArm64MemPrepost.postDelta; split <;> rfl
  simp only [dByteBody, pre, post, bumpMemoryBase, ↓reduceIte,
    memory_offset_indexed .double aux index kind scaled s memoryFlags mod amount, memory_base_read]
  simp only [Arm64VectorMemory.dWritebackCore, Arm64Memory.base_refines]
  rfl

def dCode (load : Bool) : Nat := GeneratedArm64DispatchSingleton.code (if load then .loadD0 else .storeD0)

/-- These gates ignore FLAGS: D0 is always eight bytes. LOAD uses SRC as
base, STORE uses DST, and both use physical SRC2 as index; SRC3 is unused. -/
def dispatchThroughD (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughPair code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s with
  | some result => some result
  | none => if code = dCode true then some (dByteBody true aux src src2 value s)
    else if code = dCode false then some (dByteBody false aux dst src2 value s) else none

theorem d_before_none (load : Bool) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    dispatchThroughPair (dCode load) flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s = none := by
  unfold dispatchThroughPair dispatchThroughExclusive dispatchThroughStore dispatchThroughSigned dispatchThroughLoad dispatchEncodedPrefix
  cases decoded : decodeDataWidth flags with
  | none => cases load <;> rfl
  | some width => cases load <;> rfl

theorem d_reached (load : Bool) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    dispatchThroughD (dCode load) flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s =
      some (dByteBody load aux (if load then src else dst) src2 value s) := by
  unfold dispatchThroughD
  rw [d_before_none]
  cases load <;> rfl

def vectorMemoryAccess (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State) : Prop :=
  match native with
  | .vectorMemory i =>
      Reference.AArch64.spAlignmentFault s i.base = none ∧
      permitted (if i.load then s.memory.readable else s.memory.writable)
        (Reference.AArch64.memoryBase s i.base +
          (if i.writeback = .post then 0 else Reference.AArch64.memoryOffset s i.width.scale i.offset)) i.width.bytes = true
  | _ => True

inductive DBinding (pc : Word) : Nat → Byte → BitVec 32 → Byte → Byte → Byte → Byte → Word → Bool →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (release : Bool) (native : Reference.AArch64.Instruction)
      (binding : PairBinding pc code flags aux dst src src2 src3 value release native) :
      DBinding pc code flags aux dst src src2 src3 value release native
  | immediate (load : Bool) (mode : Reference.AArch64.Writeback) (base : Register) (immediate : Word)
      (flags : Byte) (aux : BitVec 32) (unused src3 : Byte) (release : Bool)
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags mode)) :
      DBinding pc (dCode load) flags aux (if load then unused else memoryBaseCode base)
        (if load then memoryBaseCode base else unused) GeneratedArm64MemIndex.indexSentinel src3 immediate release
        (.vectorMemory ⟨.double, load, 0, base, .immediate immediate, mode⟩)
  | indexed (load : Bool) (base index : Register) (kind : Reference.AArch64.MemoryExtend) (scaled : Bool)
      (flags : Byte) (aux : BitVec 32) (unused src3 : Byte) (release : Bool)
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
      (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
        (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
          (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then 3 else 0) = 0))
      (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then 3 else 0)) :
      DBinding pc (dCode load) flags aux (if load then unused else memoryBaseCode base)
        (if load then memoryBaseCode base else unused) (Arm64Register.registerCode index) src3 0 release
        (.vectorMemory ⟨.double, load, 0, base, .register index kind scaled, .none⟩)

theorem step_through_d_observed_refines (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : DBinding s.pc code flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch code flags release failure src2 s
      (dispatchThroughD code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s) =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier code flags aux dst src src2 src3 value release native earlier =>
      have result := step_through_pair_observed_refines code flags aux dst src src2 src3 value sourceScalar
        sourceStack firstScalar secondScalar release failure native s earlier access environment pairAccess
      have numeric : ∃ prior, dispatchThroughPair code flags aux dst src src2 src3 value
          sourceScalar sourceStack firstScalar secondScalar failure s = some prior := by
        cases raw : dispatchThroughPair code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s with
        | none => simp [raw, observeExclusiveDispatch] at result; split at result <;> simp_all
        | some prior => exact ⟨prior, rfl⟩
      obtain ⟨prior, reached⟩ := numeric
      simpa only [dispatchThroughD, reached] using result
  | immediate load mode base immediate flags aux unused src3 release memoryFlags =>
      have separate : dCode load ≠ GeneratedArm64Stlxr.code .stlxr := by cases load <;> decide
      simp only [observeExclusiveDispatch, separate, ↓reduceIte]
      rw [d_reached]
      have route : (if load then (if load then memoryBaseCode base else unused) else
          (if load then unused else memoryBaseCode base)) = memoryBaseCode base := by cases load <;> rfl
      rw [route, d_byte_body_immediate load mode aux base value s memoryFlags]
      rcases vectorAccess with ⟨alignment, accessible⟩
      exact congrArg some (Arm64VectorMemory.d_writeback_refines load mode base value s alignment accessible)
  | indexed load base index kind scaled flags aux unused src3 release memoryFlags mod amount =>
      have separate : dCode load ≠ GeneratedArm64Stlxr.code .stlxr := by cases load <;> decide
      simp only [observeExclusiveDispatch, separate, ↓reduceIte]
      rw [d_reached]
      have route : (if load then (if load then memoryBaseCode base else unused) else
          (if load then unused else memoryBaseCode base)) = memoryBaseCode base := by cases load <;> rfl
      rw [route, d_byte_body_indexed load aux base index kind scaled s memoryFlags mod amount]
      rcases vectorAccess with ⟨alignment, accessible⟩
      have allowed : permitted (if load then s.memory.readable else s.memory.writable)
          (Reference.AArch64.memoryBase s base + Arm64VectorMemory.dOffset s (.register index kind scaled)) 8 = true := by
        rw [Arm64VectorMemory.d_offset_refines]
        simpa only [Reference.AArch64.VectorMemoryWidth.bytes, Reference.AArch64.VectorMemoryWidth.scale,
          reduceCtorEq, ↓reduceIte] using accessible
      have result := Arm64VectorMemory.d_writeback_refines load .none base
        (Arm64VectorMemory.dOffset s (.register index kind scaled)) s alignment allowed
      have same : Reference.AArch64.step (.vectorMemory ⟨.double, load, 0, base,
          .immediate (Arm64VectorMemory.dOffset s (.register index kind scaled)), .none⟩) s =
          Reference.AArch64.step (.vectorMemory ⟨.double, load, 0, base, .register index kind scaled, .none⟩) s := by
        simp only [Reference.AArch64.step, Reference.AArch64.vectorMemoryStep, Reference.AArch64.memoryOffset,
          Reference.AArch64.VectorMemoryWidth.scale, Arm64VectorMemory.d_offset_refines]
      exact congrArg some (result.trans same)


/-- Q0 uses the actual two-lane raw transfer between byte-field pre/post
base updates. The architectural event observation stays outside this body. -/
def qByteBody (load : Bool) (aux : BitVec 32) (base index : Byte) (immediate : Word)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let before := bumpMemoryBase base (GeneratedArm64MemPrepost.preDelta aux immediate) s
  let address := Arm64Move.Fields.read before base + memoryOffsetBody aux index immediate before
  let transferred := Arm64VectorMemory.qSuccess load address before
  { transferred with state := bumpMemoryBase base (GeneratedArm64MemPrepost.postDelta aux immediate) transferred.state }

theorem q_byte_body_immediate (load : Bool) (mode : Reference.AArch64.Writeback) (aux : BitVec 32)
    (base : Register) (immediate : Word) (s : Reference.AArch64.State)
    (flags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags mode)) :
    qByteBody load aux (memoryBaseCode base) GeneratedArm64MemIndex.indexSentinel immediate s =
      Arm64VectorMemory.qWritebackCore load mode base immediate s := by
  obtain ⟨pre, post, suppressed⟩ := memory_flag_fields aux mode immediate flags
  simp only [qByteBody, Arm64VectorMemory.qWritebackCore, pre, post, suppressed,
    memory_offset_absent, memory_base_bump_typed, memory_base_read, Arm64Memory.base_refines]

/-- Q index scaling is four, not the scalar-double scale three. The original
native index-value proof already includes all four extension kinds at scale4. -/
theorem q_memory_offset_indexed (aux : BitVec 32) (index : Register)
    (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (s : Reference.AArch64.State)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then 4 else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then 4 else 0)) :
    memoryOffsetBody aux (Arm64Register.registerCode index) 0 s =
      Reference.AArch64.memoryOffset s 4 (.register index kind scaled) := by
  have suppressed : GeneratedArm64MemPrepost.suppressOffset aux = false :=
    (memory_flag_fields aux .none 0 memoryFlags).2.2
  have modifier : ∀ value : Word,
      GeneratedArm64Mod.value (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
        value (BitVec.ofNat 64 (if scaled then 4 else 0)) .w64 =
      GeneratedArm64Mod.value (Arm64AddressedMemory.modifier kind) value (BitVec.ofNat 64 (if scaled then 4 else 0)) .w64 := by
    intro value
    rcases mod with standard | ⟨omitted, kinds, zero⟩
    · rw [standard]
    · rw [omitted, zero]
      exact memory_index_modifier .double kind false .none value (Or.inr ⟨rfl, kinds, rfl⟩)
  unfold memoryOffsetBody
  rw [memory_index_present]
  simp only [GeneratedArm64MemIndexValue.sourceOf, ↓reduceIte, Arm64Move.Fields.register_read,
    Arm64Register.read_refines, suppressed, amount, modifier]
  simp only [GeneratedArm64MemOffset.value, Bool.not_true, Bool.false_eq_true, ↓reduceIte, BitVec.add_zero]
  simpa [Reference.Word, Reference.AArch64.memoryOffset, Arm64AddressedMemory.indexValue] using
    Arm64AddressedMemory.index_refines kind (Reference.AArch64.readReg s index)
      ⟨if scaled then 4 else 0, by split <;> decide⟩

theorem q_byte_body_indexed (load : Bool) (aux : BitVec 32) (base index : Register)
    (kind : Reference.AArch64.MemoryExtend) (scaled : Bool) (s : Reference.AArch64.State)
    (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
    (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
        (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then 4 else 0) = 0))
    (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then 4 else 0)) :
    qByteBody load aux (memoryBaseCode base) (Arm64Register.registerCode index) 0 s =
      Arm64VectorMemory.qWritebackCore load .none base (Reference.AArch64.memoryOffset s 4 (.register index kind scaled)) s := by
  have pre : GeneratedArm64MemPrepost.preDelta aux 0 = 0 := by
    unfold GeneratedArm64MemPrepost.preDelta; split <;> rfl
  have post : GeneratedArm64MemPrepost.postDelta aux 0 = 0 := by
    unfold GeneratedArm64MemPrepost.postDelta; split <;> rfl
  simp only [qByteBody, pre, post, bumpMemoryBase, ↓reduceIte,
    q_memory_offset_indexed aux index kind scaled s memoryFlags mod amount, memory_base_read]
  simp only [Arm64VectorMemory.qWritebackCore, Arm64Memory.base_refines]
  rfl

def qCode (load : Bool) : Nat := GeneratedArm64DispatchSingleton.code (if load then .loadQ0 else .storeQ0)

def dispatchThroughQ (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughD code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s with
  | some result => some result
  | none => if code = qCode true then some (qByteBody true aux src src2 value s)
    else if code = qCode false then some (qByteBody false aux dst src2 value s) else none

def observeQDispatch (code : Nat) (result : Option (Transition Reference.AArch64.State)) :
    Option (Transition Reference.AArch64.State) :=
  if code = qCode true ∨ code = qCode false then result.map Arm64VectorMemory.observeQ else result

theorem q_before_none (load : Bool) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    dispatchThroughD (qCode load) flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s = none := by
  unfold dispatchThroughD dispatchThroughPair dispatchThroughExclusive dispatchThroughStore dispatchThroughSigned dispatchThroughLoad dispatchEncodedPrefix
  cases decoded : decodeDataWidth flags with
  | none => cases load <;> rfl
  | some width => cases load <;> rfl

theorem q_reached (load : Bool) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    dispatchThroughQ (qCode load) flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s =
      some (qByteBody load aux (if load then src else dst) src2 value s) := by
  unfold dispatchThroughQ
  rw [q_before_none]
  cases load <;> rfl

inductive QBinding (pc : Word) : Nat → Byte → BitVec 32 → Byte → Byte → Byte → Byte → Word → Bool →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (release : Bool) (native : Reference.AArch64.Instruction)
      (binding : DBinding pc code flags aux dst src src2 src3 value release native) :
      QBinding pc code flags aux dst src src2 src3 value release native
  | immediate (load : Bool) (mode : Reference.AArch64.Writeback) (base : Register) (immediate : Word)
      (flags : Byte) (aux : BitVec 32) (unused src3 : Byte) (release : Bool)
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags mode)) :
      QBinding pc (qCode load) flags aux (if load then unused else memoryBaseCode base)
        (if load then memoryBaseCode base else unused) GeneratedArm64MemIndex.indexSentinel src3 immediate release
        (.vectorMemory ⟨.quad, load, 0, base, .immediate immediate, mode⟩)
  | indexed (load : Bool) (base index : Register) (kind : Reference.AArch64.MemoryExtend) (scaled : Bool)
      (flags : Byte) (aux : BitVec 32) (unused src3 : Byte) (release : Bool)
      (memoryFlags : GeneratedArm64MemPrepost.flags aux = GeneratedArm64MemPrepost.flags (Arm64AddressedMemory.flags .none))
      (mod : Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = Arm64AddressedMemory.modifier kind ∨
        (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat = .none ∧
          (kind = .lsl ∨ kind = .sxtx) ∧ (if scaled then 4 else 0) = 0))
      (amount : (GeneratedArm64Aux.b2 aux).setWidth 64 = BitVec.ofNat 64 (if scaled then 4 else 0)) :
      QBinding pc (qCode load) flags aux (if load then unused else memoryBaseCode base)
        (if load then memoryBaseCode base else unused) (Arm64Register.registerCode index) src3 0 release
        (.vectorMemory ⟨.quad, load, 0, base, .register index kind scaled, .none⟩)

/-- One observed step through both Q0 gates. The two concrete observations
are explicit: Q's byte-preserving lane grouping and the earlier exclusive
monitor/order ghost. Neither is hidden in a caller's semantic premise. -/
theorem step_through_q_observed_refines (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : QBinding s.pc code flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch code flags release failure src2 s
      (observeQDispatch code (dispatchThroughQ code flags aux dst src src2 src3 value
        sourceScalar sourceStack firstScalar secondScalar failure s)) = some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier code flags aux dst src src2 src3 value release native earlier =>
      have result := step_through_d_observed_refines code flags aux dst src src2 src3 value sourceScalar
        sourceStack firstScalar secondScalar release failure native s earlier access environment pairAccess vectorAccess
      have numeric : ∃ prior, dispatchThroughD code flags aux dst src src2 src3 value
          sourceScalar sourceStack firstScalar secondScalar failure s = some prior := by
        cases raw : dispatchThroughD code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s with
        | none => simp [raw, observeExclusiveDispatch] at result; split at result <;> simp_all
        | some prior => exact ⟨prior, rfl⟩
      obtain ⟨prior, reached⟩ := numeric
      have separate (load : Bool) : code ≠ qCode load := by
        intro equal; rw [equal, q_before_none] at reached; contradiction
      simpa only [dispatchThroughQ, reached, observeQDispatch, separate true, separate false,
        or_self, ↓reduceIte] using result
  | immediate load mode base immediate flags aux unused src3 release memoryFlags =>
      have separate : qCode load ≠ GeneratedArm64Stlxr.code .stlxr := by cases load <;> decide
      have isQ : qCode load = qCode true ∨ qCode load = qCode false := by cases load <;> simp
      simp only [observeExclusiveDispatch, separate, ↓reduceIte, observeQDispatch, isQ]
      rw [q_reached]
      have route : (if load then (if load then memoryBaseCode base else unused) else
          (if load then unused else memoryBaseCode base)) = memoryBaseCode base := by cases load <;> rfl
      change some (Arm64VectorMemory.observeQ (qByteBody load aux _ GeneratedArm64MemIndex.indexSentinel value s)) = _
      rw [route, q_byte_body_immediate load mode aux base value s memoryFlags]
      rcases vectorAccess with ⟨alignment, accessible⟩
      exact congrArg some (Arm64VectorMemory.q_writeback_observed_refines load mode base value s alignment accessible)
  | indexed load base index kind scaled flags aux unused src3 release memoryFlags mod amount =>
      have separate : qCode load ≠ GeneratedArm64Stlxr.code .stlxr := by cases load <;> decide
      have isQ : qCode load = qCode true ∨ qCode load = qCode false := by cases load <;> simp
      simp only [observeExclusiveDispatch, separate, ↓reduceIte, observeQDispatch, isQ]
      rw [q_reached]
      have route : (if load then (if load then memoryBaseCode base else unused) else
          (if load then unused else memoryBaseCode base)) = memoryBaseCode base := by cases load <;> rfl
      change some (Arm64VectorMemory.observeQ (qByteBody load aux _ (Arm64Register.registerCode index) 0 s)) = _
      rw [route, q_byte_body_indexed load aux base index kind scaled s memoryFlags mod amount]
      rcases vectorAccess with ⟨alignment, accessible⟩
      have allowed : permitted (if load then s.memory.readable else s.memory.writable)
          (Reference.AArch64.memoryBase s base + Reference.AArch64.memoryOffset s 4 (.register index kind scaled)) 16 = true := by
        simpa only [Reference.AArch64.VectorMemoryWidth.bytes, Reference.AArch64.VectorMemoryWidth.scale,
          reduceCtorEq, ↓reduceIte] using accessible
      have result := Arm64VectorMemory.q_writeback_observed_refines load .none base
        (Reference.AArch64.memoryOffset s 4 (.register index kind scaled)) s alignment allowed
      have same : Reference.AArch64.step (.vectorMemory ⟨.quad, load, 0, base,
          .immediate (Reference.AArch64.memoryOffset s 4 (.register index kind scaled)), .none⟩) s =
          Reference.AArch64.step (.vectorMemory ⟨.quad, load, 0, base, .register index kind scaled, .none⟩) s := by
        rfl
      exact congrArg some (result.trans same)


/-- Real FMOV integer bytes and generated value/destination selection. The
inactive integer field may be any byte. S_FROM_W truncates low32, both vector
writes clear high64, and vector bank31 remains a real vector bank. -/
def fmovByteBody (bank : Register) (direction : GeneratedArm64Fmov.Fmov) (width : Width)
    (dst src : Byte) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let code := GeneratedArm64Fmov.code direction
  let value := GeneratedArm64Fmov.value direction
    ((Reference.AArch64.readVector s bank).setWidth 64) (Arm64Move.Fields.read s src)
  let result := if GeneratedArm64FmovDest.vectorDestination code then
      let low := if code = GeneratedArm64Fmov.code .s_from_w then (value.setWidth 32).setWidth 64 else value
      Reference.AArch64.writeVector s bank (low.setWidth 128)
    else Arm64Move.Fields.write s dst value width
  ⟨{ result with pc := s.pc + 4 }, [], none⟩

theorem fmov_byte_body_refines (bank : Register) (direction : GeneratedArm64Fmov.Fmov) (width : Width)
    (dst src : Register) (unusedDst unusedSrc : Byte) (s : Reference.AArch64.State)
    (widthMatches : GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) = true ∨
      width = Arm64Fmov.operandWidth direction) :
    fmovByteBody bank direction width
      (if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then unusedDst else Arm64Register.registerCode dst)
      (if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then Arm64Register.registerCode src else unusedSrc) s =
      Reference.AArch64.step (.fmovBank bank (Arm64Fmov.nativeMove direction dst src)) s := by
  cases direction <;> cases width <;>
    simp_all [fmovByteBody, GeneratedArm64Fmov.code, GeneratedArm64FmovDest.vectorDestination,
      GeneratedArm64Fmov.value, Arm64Fmov.operandWidth, Arm64Fmov.nativeMove,
      Arm64Move.Fields.register_read, Arm64Move.Fields.register_write,
      Arm64Register.read_refines, Arm64Register.write_refines, Reference.AArch64.step,
      Reference.AArch64.fmovBankStep, Reference.AArch64.narrow, Reference.AArch64.Width.bits]

/-- FLAGS is ignored for vector destinations; the generated FMOV value
already selects W/X input. Integer destinations retain the real FLAGS width. -/
def fmovByteWidth (direction : GeneratedArm64Fmov.Fmov) : Width :=
  if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then .w64 else Arm64Fmov.operandWidth direction

def decodeFmovWidth (direction : GeneratedArm64Fmov.Fmov) (flags : Byte) : Option Width :=
  if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then some .w64 else decodeDataWidth flags

theorem fmov_byte_width (direction : GeneratedArm64Fmov.Fmov) (flags : Byte)
    (encoded : GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) = true ∨
      GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth (Arm64Fmov.operandWidth direction))) :
    decodeFmovWidth direction flags = some (fmovByteWidth direction) := by
  by_cases vector : GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) = true
  · simp only [decodeFmovWidth, fmovByteWidth, vector, ↓reduceIte]
  · have integer := encoded.resolve_left vector
    simp only [decodeFmovWidth, fmovByteWidth, vector, Bool.false_eq_true, ↓reduceIte,
      decode_data_width flags (Arm64Fmov.operandWidth direction) integer]

/-- Public LDADD opcode0x46 and its direct atomic body. C's typed fetch-add
captures the incoming base and addend before its target write. The scalar
projection retains the complete numeric state and atomic old-byte event. -/
def atomicOpcode : Nat := 0x46

def logicalAtomicOpcode (set : Bool) : Nat := if set then 0x47 else 0x48

def atomicByteBodyWith (combine : Word → Word → Word) (width : Reference.AArch64.MemoryWidth) (dst src base : Byte)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  let address := Arm64Move.Fields.read s base
  let addend := Arm64Move.Fields.read s src
  let old := GeneratedArm64LoadBytes.value (Arm64Memory.loadWidth width)
    (wordAt s.memory address 8)
  let memory := Arm64Memory.store width s.memory address (combine old addend)
  let loaded := Arm64Memory.loadResult width none old
  ⟨{ Arm64Move.Fields.write s dst loaded (Arm64Atomic.destinationWidth width) with
      memory := memory, pc := s.pc + 4 },
    [.memory .atomic address (bytesAt s.memory address width.bytes)
      (initializedAt s.memory address width.bytes)], none⟩

def atomicByteBody (width : Reference.AArch64.MemoryWidth) (dst src base : Byte)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  atomicByteBodyWith (· + ·) width dst src base s

def logicalAtomicByteBody (set : Bool) (width : Reference.AArch64.MemoryWidth)
    (dst src base : Byte) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  atomicByteBodyWith (Reference.AArch64.atomicLogicalValue set) width dst src base s

theorem atomic_body_typed (width : Reference.AArch64.MemoryWidth) (dst src base : Register)
    (s : Reference.AArch64.State) :
    atomicByteBody width (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
      (memoryBaseCode base) s = Arm64Atomic.body width dst src base s := by
  simp only [atomicByteBody, atomicByteBodyWith, Arm64Atomic.body, Arm64Atomic.bodyWith, memory_base_read, Arm64Memory.base_refines,
    Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

theorem logical_atomic_body_typed (set : Bool) (width : Reference.AArch64.MemoryWidth)
    (dst src base : Register) (s : Reference.AArch64.State) :
    logicalAtomicByteBody set width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (memoryBaseCode base) s =
      Arm64Atomic.logicalBody set width dst src base s := by
  simp only [logicalAtomicByteBody, atomicByteBodyWith, Arm64Atomic.logicalBody,
    Arm64Atomic.bodyWith, memory_base_read, Arm64Memory.base_refines,
    Arm64Move.Fields.register_read, Arm64Move.Fields.register_write]

/-- Complete numeric L_EXEC dispatcher. Source fields, native memory,
provenance, control/ABI and compiler/platform relations retain their explicit
interfaces alongside the operation-body step laws. -/
def dispatchExec (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match dispatchThroughQ code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s with
  | some result => some result
  | none => if code = GeneratedArm64DispatchSingleton.code .fmov then
      (Arm64Fmov.decodeDirection aux.toNat).bind (fun direction =>
        (Arm64Fmov.vectorIndex src2.toNat).bind (fun bank =>
          (decodeFmovWidth direction flags).map (fun width => fmovByteBody bank direction width dst src s)))
    else if code = atomicOpcode then
      (decodeMemoryWidth flags).map (fun width => atomicByteBody width dst src src2 s)
    else if code = logicalAtomicOpcode true then
      (decodeMemoryWidth flags).map (fun width => logicalAtomicByteBody true width dst src src2 s)
    else if code = logicalAtomicOpcode false then
      (decodeMemoryWidth flags).map (fun width => logicalAtomicByteBody false width dst src src2 s)
    else Arm64Reduction.dispatch code aux.toNat s

theorem atomic_before_none (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughQ atomicOpcode flags aux dst src src2 src3 value sourceScalar sourceStack
      firstScalar secondScalar failure s = none := by
  unfold dispatchThroughQ dispatchThroughD dispatchThroughPair dispatchThroughExclusive
    dispatchThroughStore dispatchThroughSigned dispatchThroughLoad dispatchEncodedPrefix atomicOpcode
  cases decoded : decodeDataWidth flags <;> rfl

theorem atomic_reached (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool)
    (s : Reference.AArch64.State) :
    dispatchExec atomicOpcode flags aux dst src src2 src3 value sourceScalar sourceStack
      firstScalar secondScalar failure s =
      (decodeMemoryWidth flags).map (fun width => atomicByteBody width dst src src2 s) := by
  unfold dispatchExec
  rw [atomic_before_none]
  rfl

theorem exec_atomic_refines (i : Reference.AArch64.AtomicAddInstruction)
    (flags : Byte) (aux : BitVec 32) (src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State)
    (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
    (access : scalarMemoryAccess (.atomicAdd i) s) :
    dispatchExec atomicOpcode flags aux (Arm64Register.registerCode i.dst)
      (Arm64Register.registerCode i.src) (memoryBaseCode i.base) src3 value sourceScalar sourceStack
      firstScalar secondScalar failure s = some (Reference.AArch64.step (.atomicAdd i) s) := by
  rw [atomic_reached, decode_memory_width flags i.width encoded]
  change some (atomicByteBody i.width _ _ _ s) = _
  rw [atomic_body_typed]
  exact congrArg some (Arm64Atomic.body_refines i s access.1 access.2.1 access.2.2.1 access.2.2.2)

theorem logical_atomic_before_none (set : Bool) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool)
    (s : Reference.AArch64.State) :
    dispatchThroughQ (logicalAtomicOpcode set) flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s = none := by
  cases set <;>
    unfold dispatchThroughQ dispatchThroughD dispatchThroughPair dispatchThroughExclusive
      dispatchThroughStore dispatchThroughSigned dispatchThroughLoad dispatchEncodedPrefix
      logicalAtomicOpcode <;>
    cases decoded : decodeDataWidth flags <;> rfl

theorem logical_atomic_reached (set : Bool) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool)
    (s : Reference.AArch64.State) :
    dispatchExec (logicalAtomicOpcode set) flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s =
      (decodeMemoryWidth flags).map (fun width => logicalAtomicByteBody set width dst src src2 s) := by
  unfold dispatchExec
  rw [logical_atomic_before_none]
  cases set <;> rfl

theorem exec_logical_atomic_refines (set : Bool) (i : Reference.AArch64.AtomicAddInstruction)
    (flags : Byte) (aux : BitVec 32) (src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State)
    (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
    (access : scalarMemoryAccess (.atomicLogical set i) s) :
    dispatchExec (logicalAtomicOpcode set) flags aux (Arm64Register.registerCode i.dst)
      (Arm64Register.registerCode i.src) (memoryBaseCode i.base) src3 value sourceScalar sourceStack
      firstScalar secondScalar failure s = some (Reference.AArch64.step (.atomicLogical set i) s) := by
  rw [logical_atomic_reached, decode_memory_width flags i.width encoded]
  change some (logicalAtomicByteBody set i.width _ _ _ s) = _
  rw [logical_atomic_body_typed]
  exact congrArg some (Arm64Atomic.logical_body_refines set i s
    access.1 access.2.1 access.2.2.1 access.2.2.2)

theorem exec_tail_before_none (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State)
    (tailCode : code = GeneratedArm64DispatchSingleton.code .fmov ∨ code = GeneratedArm64Reduction.code .cnt ∨
      code = GeneratedArm64Reduction.code .uaddlv) :
    dispatchThroughQ code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s = none := by
  rcases tailCode with rfl | rfl | rfl <;>
    unfold dispatchThroughQ dispatchThroughD dispatchThroughPair dispatchThroughExclusive dispatchThroughStore dispatchThroughSigned dispatchThroughLoad dispatchEncodedPrefix <;>
    cases decoded : decodeDataWidth flags <;> rfl

theorem exec_fmov_refines (bank : Register) (direction : GeneratedArm64Fmov.Fmov) (dst src : Register)
    (unusedDst unusedSrc src2 src3 : Byte) (flags : Byte) (aux : BitVec 32) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State)
    (bankCode : Arm64Fmov.vectorIndex src2.toNat = some bank)
    (directionCode : aux.toNat = GeneratedArm64Fmov.code direction)
    (encoded : GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) = true ∨
      GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth (Arm64Fmov.operandWidth direction))) :
    dispatchExec (GeneratedArm64DispatchSingleton.code .fmov) flags aux
      (if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then unusedDst else Arm64Register.registerCode dst)
      (if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then Arm64Register.registerCode src else unusedSrc)
      src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s =
      some (Reference.AArch64.step (.fmovBank bank (Arm64Fmov.nativeMove direction dst src)) s) := by
  unfold dispatchExec
  rw [exec_tail_before_none _ _ _ _ _ _ _ _ _ _ _ _ _ s (Or.inl rfl)]
  simp only [↓reduceIte, directionCode, Arm64Fmov.decode_direction_code]
  change (Arm64Fmov.vectorIndex src2.toNat).bind (fun bank =>
    (decodeFmovWidth direction flags).map (fun width => fmovByteBody bank direction width _ _ s)) = _
  rw [bankCode]
  change (decodeFmovWidth direction flags).map (fun width => fmovByteBody bank direction width _ _ s) = _
  rw [fmov_byte_width direction flags encoded]
  change some (fmovByteBody bank direction (fmovByteWidth direction) _ _ s) = _
  have widthMatches : GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) = true ∨
      fmovByteWidth direction = Arm64Fmov.operandWidth direction := by
    by_cases vector : GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) = true
    · exact Or.inl vector
    · exact Or.inr (by simp [fmovByteWidth, vector])
  exact congrArg some (fmov_byte_body_refines bank direction (fmovByteWidth direction) dst src unusedDst unusedSrc s widthMatches)

theorem exec_reduction_refines (op : Reference.AArch64.ReductionOp) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack firstScalar secondScalar failure : Bool)
    (s : Reference.AArch64.State) :
    dispatchExec (GeneratedArm64Reduction.code (Arm64Reduction.operation op)) flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s =
      some (Reference.AArch64.step (.reduction op (aux.toNat == 16)) s) := by
  have tailCode : GeneratedArm64Reduction.code (Arm64Reduction.operation op) = GeneratedArm64DispatchSingleton.code .fmov ∨
      GeneratedArm64Reduction.code (Arm64Reduction.operation op) = GeneratedArm64Reduction.code .cnt ∨
      GeneratedArm64Reduction.code (Arm64Reduction.operation op) = GeneratedArm64Reduction.code .uaddlv := by
    cases op <;> simp [Arm64Reduction.operation]
  have separate : GeneratedArm64Reduction.code (Arm64Reduction.operation op) ≠ GeneratedArm64DispatchSingleton.code .fmov := by
    cases op <;> decide
  unfold dispatchExec
  have atomicSeparate : GeneratedArm64Reduction.code (Arm64Reduction.operation op) ≠ atomicOpcode := by
    cases op <;> decide
  rw [exec_tail_before_none _ _ _ _ _ _ _ _ _ _ _ _ _ s tailCode, if_neg separate, if_neg atomicSeparate]
  have setSeparate : GeneratedArm64Reduction.code (Arm64Reduction.operation op) ≠ logicalAtomicOpcode true := by
    cases op <;> decide
  have clearSeparate : GeneratedArm64Reduction.code (Arm64Reduction.operation op) ≠ logicalAtomicOpcode false := by
    cases op <;> decide
  rw [if_neg setSeparate,if_neg clearSeparate]
  exact Arm64Reduction.dispatch_refines op aux.toNat s

/-- The three generated DIRECT_BODY_4 tokens retain their literal opcode.
The AUX low byte selects ADD/SUB/AND/ORR/EOR/BIC in the shared ALU body. -/
inductive ImmediateToken where
  | add | sub | alu
  deriving DecidableEq

def immediateTokenSelector : ImmediateToken → GeneratedArm64AluOperandSelect.AluOperandSelectOp
  | .add => .addImm
  | .sub => .subImm
  | .alu => .aluImm

def immediateTokenOpcode (token : ImmediateToken) : Nat :=
  GeneratedArm64AluOperandSelect.code (immediateTokenSelector token)

/-- W/X numeric projection of the generated direct macro: normalize FLAGS,
decode AUX, and call EXEC_ALU with the literal immediate selector. The Option
boundary and provenance predicates retain the established numeric-frame scope. -/
def specializedImmediate (token : ImmediateToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  (decodeDataWidth flags).bind (fun width =>
    (decodeAlu (GeneratedArm64Aux.b0 aux).toNat).map
      (fun op => aluBody op (GeneratedArm64AluOperandSelect.immediate (immediateTokenSelector token))
        sourceScalar sourceStack aux width dst src src2 value s))

/-- The direct macro body and the complete L_EXEC dispatcher agree on every
field and incoming numeric frame, with their existing Option boundary. -/
theorem immediate_token_body_matches (token : ImmediateToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    specializedImmediate token flags aux dst src src2 value sourceScalar sourceStack s =
      dispatchExec (immediateTokenOpcode token) flags aux dst src src2 src3 value
        sourceScalar sourceStack firstScalar secondScalar failure s := by
  cases token <;>
    unfold specializedImmediate dispatchExec dispatchThroughQ dispatchThroughD dispatchThroughPair
      dispatchThroughExclusive dispatchThroughStore dispatchThroughSigned
      dispatchThroughLoad dispatchEncodedPrefix dispatchThroughSelect dispatchThroughCompare dispatchThroughOrn
      dispatchThroughFlagLogic dispatchThroughFlagArithmetic dispatchThroughBitfield dispatchThroughExtrev
      dispatchThroughUnary dispatchThroughMultiply dispatchThroughShift dispatch
  all_goals cases w : decodeDataWidth flags <;> cases op : decodeAlu (GeneratedArm64Aux.b0 aux).toNat <;>
    simp only [w, op, immediateTokenOpcode, immediateTokenSelector,
      GeneratedArm64AluOperandSelect.code, GeneratedArm64AluOperandSelect.immediate, Option.bind_none, Option.bind_some,
      Option.map_none, Option.map_some]
  all_goals rfl

/-- Both production immediate labels retain the complete numeric L_EXEC
result for arbitrary fields, provenance predicates and incoming state. -/
theorem exec_immediate_alias_dispatch (alias : Nat) (isAlias : alias = 3 ∨ alias = 4)
    (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    dispatchExec alias flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s =
      dispatchExec 6 flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s := by
  rcases isAlias with h | h <;> subst alias <;> rfl

/-- Q-vector and exclusive observations preserve the immediate-label identity
including every state component, event and fault. -/
theorem observed_immediate_alias_dispatch (alias : Nat) (isAlias : alias = 3 ∨ alias = 4)
    (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) (s : Reference.AArch64.State) :
    observeExclusiveDispatch alias flags release failure src2 s
      (observeQDispatch alias (dispatchExec alias flags aux dst src src2 src3 value
        sourceScalar sourceStack firstScalar secondScalar failure s)) =
      observeExclusiveDispatch 6 flags release failure src2 s
        (observeQDispatch 6 (dispatchExec 6 flags aux dst src src2 src3 value
          sourceScalar sourceStack firstScalar secondScalar failure s)) := by
  rw [exec_immediate_alias_dispatch alias isAlias]
  rcases isAlias with h | h <;> subst alias <;> rfl

/-- Carry the existing field-only Q binding through the final L_EXEC gates. -/
theorem q_exec_observed_refines (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : QBinding s.pc code flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch code flags release failure src2 s
      (observeQDispatch code (dispatchExec code flags aux dst src src2 src3 value
        sourceScalar sourceStack firstScalar secondScalar failure s)) = some (Reference.AArch64.step native s) := by
  have result := step_through_q_observed_refines code flags aux dst src src2 src3 value sourceScalar
    sourceStack firstScalar secondScalar release failure native s binding access environment pairAccess vectorAccess
  have numeric : ∃ prior, dispatchThroughQ code flags aux dst src src2 src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s = some prior := by
    cases raw : dispatchThroughQ code flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s with
    | none =>
        cases decoded : decodeDataWidth flags <;> simp [raw, decoded, observeExclusiveDispatch, observeQDispatch] at result
    | some prior => exact ⟨prior, rfl⟩
  obtain ⟨prior, reached⟩ := numeric
  simpa only [dispatchExec, reached] using result

inductive ExecBinding (pc : Word) : Nat → Byte → BitVec 32 → Byte → Byte → Byte → Byte → Word → Bool →
    Reference.AArch64.Instruction → Prop where
  | earlier (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (release : Bool) (native : Reference.AArch64.Instruction)
      (binding : QBinding pc code flags aux dst src src2 src3 value release native) :
      ExecBinding pc code flags aux dst src src2 src3 value release native
  | immediateAlias (alias : Nat) (isAlias : alias = 3 ∨ alias = 4)
      (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (release : Bool) (native : Reference.AArch64.Instruction)
      (binding : QBinding pc 6 flags aux dst src src2 src3 value release native) :
      ExecBinding pc alias flags aux dst src src2 src3 value release native
  | fmov (bank : Register) (direction : GeneratedArm64Fmov.Fmov) (dst src : Register)
      (unusedDst unusedSrc src2 src3 : Byte) (flags : Byte) (aux : BitVec 32) (value : Word) (release : Bool)
      (bankCode : Arm64Fmov.vectorIndex src2.toNat = some bank)
      (directionCode : aux.toNat = GeneratedArm64Fmov.code direction)
      (encoded : GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) = true ∨
        GeneratedArm64Width.effective flags.toNat = GeneratedArm64Width.code (Arm64Register.handlerWidth (Arm64Fmov.operandWidth direction))) :
      ExecBinding pc (GeneratedArm64DispatchSingleton.code .fmov) flags aux
        (if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then unusedDst else Arm64Register.registerCode dst)
        (if GeneratedArm64FmovDest.vectorDestination (GeneratedArm64Fmov.code direction) then Arm64Register.registerCode src else unusedSrc)
        src2 src3 value release (.fmovBank bank (Arm64Fmov.nativeMove direction dst src))
  | reduction (op : Reference.AArch64.ReductionOp) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
      (value : Word) (release : Bool) :
      ExecBinding pc (GeneratedArm64Reduction.code (Arm64Reduction.operation op)) flags aux dst src src2 src3 value release
        (.reduction op (aux.toNat == 16))

  | atomicAdd (i : Reference.AArch64.AtomicAddInstruction) (flags : Byte) (aux : BitVec 32)
      (src3 : Byte) (value : Word) (release : Bool)
      (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
      (acquireCode : i.acquire = (aux &&& 1 != 0))
      (releaseCode : i.release = (aux &&& 2 != 0)) :
      ExecBinding pc atomicOpcode flags aux (Arm64Register.registerCode i.dst)
        (Arm64Register.registerCode i.src) (memoryBaseCode i.base) src3 value release (.atomicAdd i)
  | atomicLogical (set : Bool) (i : Reference.AArch64.AtomicAddInstruction) (flags : Byte) (aux : BitVec 32)
      (src3 : Byte) (value : Word) (release : Bool)
      (encoded : GeneratedArm64Width.effective flags.toNat = i.width.bytes)
      (acquireCode : i.acquire = (aux &&& 1 != 0))
      (releaseCode : i.release = (aux &&& 2 != 0)) :
      ExecBinding pc (logicalAtomicOpcode set) flags aux (Arm64Register.registerCode i.dst)
        (Arm64Register.registerCode i.src) (memoryBaseCode i.base) src3 value release (.atomicLogical set i)

/-- One step through all actual L_EXEC branch families, with explicit Q-byte
observation and exclusive ghost/environment. Field bindings do not assume any
handler semantic equality. This is not the outside control/helper dispatcher
or compiled-artifact/ABI/platform transport theorem. -/
theorem exec_observed_step_refines (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte)
    (value : Word) (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : ExecBinding s.pc code flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch code flags release failure src2 s
      (observeQDispatch code (dispatchExec code flags aux dst src src2 src3 value
        sourceScalar sourceStack firstScalar secondScalar failure s)) = some (Reference.AArch64.step native s) := by
  cases binding with
  | earlier code flags aux dst src src2 src3 value release native earlier =>
      exact q_exec_observed_refines code flags aux dst src src2 src3 value sourceScalar sourceStack
        firstScalar secondScalar release failure native s earlier access environment pairAccess vectorAccess
  | immediateAlias alias isAlias flags aux dst src src2 src3 value release native earlier =>
      rw [observed_immediate_alias_dispatch _ isAlias]
      exact q_exec_observed_refines 6 flags aux dst src src2 src3 value sourceScalar sourceStack
        firstScalar secondScalar release failure native s earlier access environment pairAccess vectorAccess
  | fmov bank direction dst src unusedDst unusedSrc src2 src3 flags aux value release bankCode directionCode encoded =>
      have exclusiveSeparate : GeneratedArm64DispatchSingleton.code .fmov ≠ GeneratedArm64Stlxr.code .stlxr := by decide
      have qSeparate : ¬(GeneratedArm64DispatchSingleton.code .fmov = qCode true ∨
          GeneratedArm64DispatchSingleton.code .fmov = qCode false) := by decide
      simp only [observeExclusiveDispatch, exclusiveSeparate, ↓reduceIte, observeQDispatch, qSeparate]
      exact exec_fmov_refines bank direction dst src unusedDst unusedSrc src2 src3 flags aux value
        sourceScalar sourceStack firstScalar secondScalar failure s bankCode directionCode encoded
  | reduction op flags aux dst src src2 src3 value release =>
      have exclusiveSeparate : GeneratedArm64Reduction.code (Arm64Reduction.operation op) ≠ GeneratedArm64Stlxr.code .stlxr := by cases op <;> decide
      have qSeparate : ¬(GeneratedArm64Reduction.code (Arm64Reduction.operation op) = qCode true ∨
          GeneratedArm64Reduction.code (Arm64Reduction.operation op) = qCode false) := by cases op <;> decide
      simp only [observeExclusiveDispatch, exclusiveSeparate, ↓reduceIte, observeQDispatch, qSeparate]
      exact exec_reduction_refines op flags aux dst src src2 src3 value sourceScalar sourceStack firstScalar secondScalar failure s


  | atomicAdd i flags aux src3 value release encoded acquireCode releaseCode =>
      have exclusiveSeparate : atomicOpcode ≠ GeneratedArm64Stlxr.code .stlxr := by decide
      have qSeparate : ¬(atomicOpcode = qCode true ∨ atomicOpcode = qCode false) := by decide
      simp only [observeExclusiveDispatch, exclusiveSeparate, ↓reduceIte, observeQDispatch, qSeparate]
      exact exec_atomic_refines i flags aux src3 value sourceScalar sourceStack firstScalar
        secondScalar failure s encoded access

  | atomicLogical set i flags aux src3 value release encoded acquireCode releaseCode =>
      have exclusiveSeparate : logicalAtomicOpcode set ≠ GeneratedArm64Stlxr.code .stlxr := by
        cases set <;> decide
      have qSeparate : ¬(logicalAtomicOpcode set = qCode true ∨ logicalAtomicOpcode set = qCode false) := by
        cases set <;> decide
      simp only [observeExclusiveDispatch, exclusiveSeparate, ↓reduceIte, observeQDispatch, qSeparate]
      exact exec_logical_atomic_refines set i flags aux src3 value sourceScalar sourceStack firstScalar
        secondScalar failure s encoded access

/-- Once per generated immediate token: combine its direct-body identity with
the unified canonical step theorem under the same field and platform binding. -/
theorem immediate_token_step_refines (token : ImmediateToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : ExecBinding s.pc (immediateTokenOpcode token) flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch (immediateTokenOpcode token) flags release failure src2 s
      (observeQDispatch (immediateTokenOpcode token) (specializedImmediate token flags aux dst src src2 value
        sourceScalar sourceStack s)) = some (Reference.AArch64.step native s) := by
  rw [immediate_token_body_matches token flags aux dst src src2 src3 value sourceScalar sourceStack
    firstScalar secondScalar failure s]
  exact exec_observed_step_refines _ flags aux dst src src2 src3 value sourceScalar sourceStack
    firstScalar secondScalar release failure native s binding access environment pairAccess vectorAccess


/-- Producer-level emission alternatives, not another ISA decoder or numeric
opcode table. Direct branches are emitted as C macros outside L_EXEC. Their
source-label coordinates are deliberately distinct from native PC words. -/
inductive Emission where
  | exec (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
  | jump (current target : Word)
  | condition (code : Nat) (current fallthrough target : Word)
  | zero (width : Width) (nonzero : Bool) (src : Byte) (current fallthrough target : Word)
  | bit (nonzero : Bool) (src : Byte) (bit : Word) (current fallthrough target : Word)

/-- The generated backward/forward shape is chosen in SOURCE coordinates;
only the selected label is materialized through `nativeAddress`. -/
def mappedBranchStep (nativeAddress : Word → Word) (current fallthrough target : Word) (taken : Bool)
    (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ s with pc := (Arm64Branch.choosePc (GeneratedArm64BranchEmit.shape current.toNat target.toNat)
      taken (nativeAddress fallthrough) (nativeAddress target)) }, [], none⟩

theorem mapped_branch_refines (nativeAddress : Word → Word) (current fallthrough target : Word)
    (taken : Bool) (displacement : Word) (s : Reference.AArch64.State)
    (fallAddress : nativeAddress fallthrough = s.pc + 4)
    (targetAddress : nativeAddress target = s.pc + displacement) :
    mappedBranchStep nativeAddress current fallthrough target taken s =
      Reference.AArch64.branchStep taken displacement s := by
  simp only [mappedBranchStep, Arm64Branch.pc_refines, fallAddress, targetAddress]
  rfl

/-- TBZ/TBNZ consume exactly low6 of the physical bit argument, as the
production predicate does; upper bits never become a native bit number. -/
theorem branch_bit_argument (nonzero : Bool) (value rawBit : Word) :
    GeneratedArm64Branch.value (if nonzero then .tbnz else .tbz) value rawBit =
      GeneratedArm64Branch.value (if nonzero then .tbnz else .tbz) value ((rawBit.setWidth 6).setWidth 64) := by
  have masked : rawBit &&& 63 = ((rawBit.setWidth 6).setWidth 64 &&& 63) := by
    simp only [Reference.Word]; bv_decide
  cases nonzero <;> simp only [Bool.false_eq_true, ↓reduceIte, GeneratedArm64Branch.value] <;> rw [masked]

/-- Numeric generated step. L_EXEC's explicit observations remain visible;
branch macros neither modify data state nor invent guest memory effects. The
label map/field binding must be established from the bound native artifact. -/
def dispatchEmission (nativeAddress : Word → Word) (emission : Emission)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) (s : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  match emission with
  | .exec code flags aux dst src src2 src3 value =>
      observeExclusiveDispatch code flags release failure src2 s
        (observeQDispatch code (dispatchExec code flags aux dst src src2 src3 value
          sourceScalar sourceStack firstScalar secondScalar failure s))
  | .jump _ target => some ⟨{ s with pc := nativeAddress target }, [], none⟩
  | .condition code current fallthrough target =>
      (Arm64Condition.decode code).map (fun predicate => mappedBranchStep nativeAddress current fallthrough target
        (generatedArm64Cond (Arm64Condition.flags s.flags) predicate) s)
  | .zero width nonzero src current fallthrough target =>
      some (mappedBranchStep nativeAddress current fallthrough target
        (GeneratedArm64Branch.value (if nonzero then .cbnz else .cbz)
          (Arm64Branch.zeroSource width (Arm64Move.Fields.read s src)) 0) s)
  | .bit nonzero src bit current fallthrough target =>
      some (mappedBranchStep nativeAddress current fallthrough target
        (GeneratedArm64Branch.value (if nonzero then .tbnz else .tbz) (Arm64Move.Fields.read s src) bit) s)

/-- Source/native coordinate identities only. The current, lexical next and
selected target are each tied to the actual native PC; equality between the
source coordinate and native address is never assumed. Permissions/profile/
exclusive witnesses stay outside this binding, as for L_EXEC. -/
inductive EmissionBinding (nativeAddress : Word → Word) (pc : Word) (release : Bool) :
    Emission → Reference.AArch64.Instruction → Prop where
  | exec (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
      (native : Reference.AArch64.Instruction) (binding : ExecBinding pc code flags aux dst src src2 src3 value release native) :
      EmissionBinding nativeAddress pc release (.exec code flags aux dst src src2 src3 value) native
  | jump (current target displacement : Word) (currentAddress : nativeAddress current = pc)
      (targetAddress : nativeAddress target = pc + displacement) :
      EmissionBinding nativeAddress pc release (.jump current target) (.branch displacement)
  | condition (predicate : Arm64Cond) (current fallthrough target displacement : Word)
      (currentAddress : nativeAddress current = pc) (nextLabel : fallthrough = current + 4)
      (fallAddress : nativeAddress fallthrough = pc + 4) (targetAddress : nativeAddress target = pc + displacement) :
      EmissionBinding nativeAddress pc release (.condition (GeneratedArm64Cond.code predicate) current fallthrough target)
        (.branchConditional (Arm64Condition.nativeCode predicate) displacement)
  | nv (current fallthrough target displacement : Word)
      (currentAddress : nativeAddress current = pc) (nextLabel : fallthrough = current + 4)
      (fallAddress : nativeAddress fallthrough = pc + 4) (targetAddress : nativeAddress target = pc + displacement) :
      EmissionBinding nativeAddress pc release (.condition (GeneratedArm64CcDecode.code .nv) current fallthrough target)
        (.branchConditional 15 displacement)
  | zero (width : Width) (nonzero : Bool) (src : Register) (current fallthrough target displacement : Word)
      (currentAddress : nativeAddress current = pc) (nextLabel : fallthrough = current + 4)
      (fallAddress : nativeAddress fallthrough = pc + 4) (targetAddress : nativeAddress target = pc + displacement) :
      EmissionBinding nativeAddress pc release (.zero width nonzero (Arm64Register.registerCode src) current fallthrough target)
        (.branchZero width nonzero src displacement)
  | bit (nonzero : Bool) (src : Register) (bit : Word) (current fallthrough target displacement : Word)
      (currentAddress : nativeAddress current = pc) (nextLabel : fallthrough = current + 4)
      (fallAddress : nativeAddress fallthrough = pc + 4) (targetAddress : nativeAddress target = pc + displacement) :
      EmissionBinding nativeAddress pc release (.bit nonzero (Arm64Register.registerCode src) bit current fallthrough target)
        (.branchBit nonzero src (bit.setWidth 6) displacement)

/-- One generated-step theorem combines all numeric L_EXEC cases with B,
B.cond including normalized NV, W/X CBZ/CBNZ and masked TBZ/TBNZ, using the
actual source-selected branch shape and native label map. No component step
equality or branch-outcome premise is supplied by the caller. -/
theorem emission_step_refines (nativeAddress : Word → Word) (emission : Emission)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : EmissionBinding nativeAddress s.pc release emission native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    dispatchEmission nativeAddress emission sourceScalar sourceStack firstScalar secondScalar release failure s =
      some (Reference.AArch64.step native s) := by
  cases binding with
  | exec code flags aux dst src src2 src3 value native earlier =>
      exact exec_observed_step_refines code flags aux dst src src2 src3 value sourceScalar sourceStack
        firstScalar secondScalar release failure native s earlier access environment pairAccess vectorAccess
  | jump current target displacement currentAddress targetAddress =>
      simp only [dispatchEmission, targetAddress, Reference.AArch64.step]
      rfl
  | condition predicate current fallthrough target displacement currentAddress nextLabel fallAddress targetAddress =>
      simp only [dispatchEmission, Arm64Condition.decode_code]
      change some (mappedBranchStep nativeAddress current fallthrough target _ s) = _
      rw [mapped_branch_refines nativeAddress current fallthrough target _ displacement s fallAddress targetAddress,
        Arm64Condition.condition_refines]
      rfl
  | nv current fallthrough target displacement currentAddress nextLabel fallAddress targetAddress =>
      simp only [dispatchEmission, Arm64Condition.decode_normalized_nv]
      change some (mappedBranchStep nativeAddress current fallthrough target _ s) = _
      rw [mapped_branch_refines nativeAddress current fallthrough target _ displacement s fallAddress targetAddress]
      rfl
  | zero width nonzero src current fallthrough target displacement currentAddress nextLabel fallAddress targetAddress =>
      simp only [dispatchEmission, Arm64Move.Fields.register_read, Arm64Register.read_refines,
        Arm64Branch.zero_predicate_refines]
      rw [mapped_branch_refines nativeAddress current fallthrough target _ displacement s fallAddress targetAddress]
      rfl
  | bit nonzero src bit current fallthrough target displacement currentAddress nextLabel fallAddress targetAddress =>
      simp only [dispatchEmission, Arm64Move.Fields.register_read, Arm64Register.read_refines]
      rw [branch_bit_argument, Arm64Branch.bit_predicate_refines]
      rw [mapped_branch_refines nativeAddress current fallthrough target _ displacement s fallAddress targetAddress]
      rfl


/-- Implementation code-token layer over the existing numeric observation:
non-CODE fields already use the prior stack/return/data frame relation. CODE
payloads remain source tokens, exactly as LINK/ADR and the finite switches
store/read them. This is not another ISA state or decoder. -/
structure CodeState where
  bits : Reference.AArch64.State
  code : Reference.AArch64.Gpr → Bool

/-- The bound layout maps source tokens to native byte addresses. Numeric
READ_REG on CODE currently leaves tokens unchanged; this observation alone
therefore proves no code-pointer arithmetic/memory or compiled-body transport. -/
def nativeCodeView (nativeAddress : Word → Word) (state : CodeState) : Reference.AArch64.State :=
  { state.bits with
    gpr := fun r => if state.code r then nativeAddress (state.bits.gpr r) else state.bits.gpr r
    pc := nativeAddress state.bits.pc }

def codeSource (state : CodeState) (src : Register) : Bool :=
  if h : src.val < 31 then state.code ⟨src.val, h⟩ else false

def writeCodeToken (state : CodeState) (dst : Register) (token : Word) : CodeState :=
  ⟨Arm64Move.Fields.write state.bits (Arm64Register.registerCode dst) token .w64,
    fun r => if r.val = dst.val then true else state.code r⟩

def codePc (state : CodeState) (target : Word) : CodeState :=
  { state with bits := { state.bits with pc := target } }

def observeCodeTransition (nativeAddress : Word → Word) (result : Transition CodeState) :
    Transition Reference.AArch64.State := ⟨nativeCodeView nativeAddress result.state, result.events, result.fault⟩

theorem native_code_pc (nativeAddress : Word → Word) (state : CodeState) (target : Word) :
    nativeCodeView nativeAddress (codePc state target) =
      { nativeCodeView nativeAddress state with pc := nativeAddress target } := rfl

theorem native_code_read (nativeAddress : Word → Word) (state : CodeState) (src : Register) :
    Reference.AArch64.readReg (nativeCodeView nativeAddress state) src =
      if codeSource state src then nativeAddress (Reference.AArch64.readReg state.bits src)
      else Reference.AArch64.readReg state.bits src := by
  by_cases general : src.val < 31 <;>
    simp only [Reference.AArch64.readReg, nativeCodeView, codeSource, general, ↓reduceDIte, Bool.false_eq_true, ↓reduceIte]

theorem native_code_write (nativeAddress : Word → Word) (state : CodeState) (dst : Register) (token : Word) :
    nativeCodeView nativeAddress (writeCodeToken state dst token) =
      Reference.AArch64.writeReg (nativeCodeView nativeAddress state) dst (nativeAddress token) := by
  simp only [nativeCodeView, writeCodeToken, Arm64Move.Fields.register_write,
    Arm64Register.write_refines, Reference.AArch64.writeReg, Reference.AArch64.narrow,
    Reference.AArch64.Width.bits, BitVec.setWidth_eq]
  congr 1
  funext r
  by_cases same : r.val = dst.val <;> simp [same]

/-- LINK writes the source successor token and CODE tag before its goto;
X30 data and its tag are updated together. The target is captured separately. -/
def sourceCallStep (target successor : Word) (state : CodeState) : Transition CodeState :=
  ⟨codePc (writeCodeToken state 30 successor) target, [], none⟩

theorem source_call_observed_refines (nativeAddress : Word → Word) (target successor displacement : Word)
    (state : CodeState)
    (targetAddress : nativeAddress target = (nativeCodeView nativeAddress state).pc + displacement)
    (successorAddress : nativeAddress successor = (nativeCodeView nativeAddress state).pc + 4) :
    observeCodeTransition nativeAddress (sourceCallStep target successor state) =
      Reference.AArch64.step (.branchLink displacement) (nativeCodeView nativeAddress state) := by
  simp only [observeCodeTransition, sourceCallStep, native_code_pc, native_code_write,
    targetAddress, successorAddress, Reference.AArch64.step]

/-- ADR's code-address arm writes only a GPR/ZR cell and its CODE tag, then
falls through. Native SP is not a destination of this source ADR form. -/
def sourceAddressStep (dst : Register) (address fallthrough : Word) (state : CodeState) : Transition CodeState :=
  ⟨codePc (writeCodeToken state dst address) fallthrough, [], none⟩

theorem source_address_observed_refines (nativeAddress : Word → Word) (dst : Register)
    (address fallthrough displacement : Word) (state : CodeState)
    (addressValue : nativeAddress address = (nativeCodeView nativeAddress state).pc + displacement)
    (fallAddress : nativeAddress fallthrough = (nativeCodeView nativeAddress state).pc + 4) :
    observeCodeTransition nativeAddress (sourceAddressStep dst address fallthrough state) =
      Reference.AArch64.step (.pcAddress false dst displacement) (nativeCodeView nativeAddress state) := by
  simp only [observeCodeTransition, sourceAddressStep, native_code_pc, native_code_write,
    addressValue, fallAddress, Reference.AArch64.step]
  rfl

/-- Actual CODE-tag finite-target arm of BR/BLR/internal RET. The incoming
source target is captured before LINK, so BLR X30 does not branch to its newly
written successor. None passes to the separate helper/outer-return/failure
paths; those paths are not replaced with a successful no-op or newly rejected. -/
def dispatchCodeTarget (link : Bool) (src : Register) (targets : List Word) (successor : Word)
    (state : CodeState) : Option (Transition CodeState) :=
  let target := Arm64Move.Fields.read state.bits (Arm64Register.registerCode src)
  if codeSource state src && targets.contains target then
    if link then some (sourceCallStep target successor state)
    else some ⟨codePc state target, [], none⟩
  else none

theorem code_target_observed_refines (nativeAddress : Word → Word) (link : Bool) (src : Register)
    (targets : List Word) (successor : Word) (state : CodeState)
    (code : codeSource state src = true)
    (allowed : targets.contains (Arm64Move.Fields.read state.bits (Arm64Register.registerCode src)) = true)
    (successorAddress : link = true → nativeAddress successor = (nativeCodeView nativeAddress state).pc + 4) :
    (dispatchCodeTarget link src targets successor state).map (observeCodeTransition nativeAddress) =
      some (Reference.AArch64.step (.branchRegister link src) (nativeCodeView nativeAddress state)) := by
  have read : Reference.AArch64.readReg (nativeCodeView nativeAddress state) src =
      nativeAddress (Arm64Move.Fields.read state.bits (Arm64Register.registerCode src)) := by
    rw [native_code_read, code]
    simp only [↓reduceIte, Arm64Move.Fields.register_read, Arm64Register.read_refines]
  cases link with
  | false =>
      simp only [dispatchCodeTarget, code, allowed, Bool.true_and, ↓reduceIte]
      change some (observeCodeTransition nativeAddress ⟨codePc state _, [], none⟩) = _
      simp only [observeCodeTransition, native_code_pc, Reference.AArch64.step, Bool.false_eq_true, ↓reduceIte, read]
  | true =>
      have successorValue := successorAddress rfl
      simp only [dispatchCodeTarget, code, allowed, Bool.true_and, ↓reduceIte]
      change some (observeCodeTransition nativeAddress (sourceCallStep _ successor state)) = _
      simp only [observeCodeTransition, sourceCallStep, native_code_pc, native_code_write,
        successorValue, Reference.AArch64.step, ↓reduceIte, read]


/-- The existing emitted numeric/direct branch plus the actual source-token
LINK/ADR/CODE-target arms. This joins implementation emission families only;
helper/outer-return and compiled-frame transport remain outside this layer. -/
inductive SourceEmission where
  | numeric (emission : Emission)
  | call (target successor : Word)
  | address (dst : Register) (address fallthrough : Word)
  | register (link : Bool) (src : Register) (targets : List Word) (successor : Word)

def dispatchSourceEmission (nativeAddress : Word → Word) (emission : SourceEmission)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) (state : CodeState) :
    Option (Transition Reference.AArch64.State) :=
  match emission with
  | .numeric ordinary => dispatchEmission nativeAddress ordinary sourceScalar sourceStack firstScalar
      secondScalar release failure (nativeCodeView nativeAddress state)
  | .call target successor => some (observeCodeTransition nativeAddress (sourceCallStep target successor state))
  | .address dst address fallthrough => some (observeCodeTransition nativeAddress (sourceAddressStep dst address fallthrough state))
  | .register link src targets successor =>
      (dispatchCodeTarget link src targets successor state).map (observeCodeTransition nativeAddress)

/-- Layout and actual CODE-arm guards are concrete input relations, never
assumed handler-step equality. Existing numeric fields still need the
compiled-frame relation; this binding does not manufacture it. -/
inductive SourceBinding (nativeAddress : Word → Word) (state : CodeState) (release : Bool) :
    SourceEmission → Reference.AArch64.Instruction → Prop where
  | numeric (ordinary : Emission) (native : Reference.AArch64.Instruction)
      (binding : EmissionBinding nativeAddress (nativeCodeView nativeAddress state).pc release ordinary native) :
      SourceBinding nativeAddress state release (.numeric ordinary) native
  | call (target successor displacement : Word)
      (targetAddress : nativeAddress target = (nativeCodeView nativeAddress state).pc + displacement)
      (successorAddress : nativeAddress successor = (nativeCodeView nativeAddress state).pc + 4) :
      SourceBinding nativeAddress state release (.call target successor) (.branchLink displacement)
  | address (dst : Register) (address fallthrough displacement : Word)
      (addressValue : nativeAddress address = (nativeCodeView nativeAddress state).pc + displacement)
      (fallAddress : nativeAddress fallthrough = (nativeCodeView nativeAddress state).pc + 4) :
      SourceBinding nativeAddress state release (.address dst address fallthrough) (.pcAddress false dst displacement)
  | register (link : Bool) (src : Register) (targets : List Word) (successor : Word)
      (code : codeSource state src = true)
      (allowed : targets.contains (Arm64Move.Fields.read state.bits (Arm64Register.registerCode src)) = true)
      (successorAddress : link = true → nativeAddress successor = (nativeCodeView nativeAddress state).pc + 4) :
      SourceBinding nativeAddress state release (.register link src targets successor) (.branchRegister link src)

/-- Lift the generic immediate field binding into either literal alias through
the complete numeric/source-emission chain. The input is a field binding. -/
theorem source_immediate_alias_binding (nativeAddress : Word → Word) (state : CodeState)
    (release : Bool) (alias : Nat) (isAlias : alias = 3 ∨ alias = 4)
    (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (value : Word)
    (native : Reference.AArch64.Instruction)
    (binding : QBinding (nativeCodeView nativeAddress state).pc 6 flags aux dst src src2 src3 value release native) :
    SourceBinding nativeAddress state release
      (.numeric (.exec alias flags aux dst src src2 src3 value)) native := by
  exact .numeric _ _ (.exec _ _ _ _ _ _ _ _ _ (.immediateAlias alias isAlias flags aux dst src src2 src3 value release native binding))

/-- One observed source-emission step theorem for L_EXEC, all direct branches,
internal BL/ADR and CODE-tag BR/BLR/internal RET. Original memory/profile/
exclusive premises stay explicit. Helper/outer-return tags, actual code-word
arithmetic/memory and compiled/native-layout/ABI transport are not discharged
by composing these proved primitives. -/
theorem source_emission_step_refines (nativeAddress : Word → Word) (emission : SourceEmission)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (state : CodeState)
    (binding : SourceBinding nativeAddress state release emission native)
    (access : scalarMemoryAccess native (nativeCodeView nativeAddress state))
    (environment : exclusiveStoreEnvironment native failure (nativeCodeView nativeAddress state))
    (pairAccess : pairMemoryAccess native (nativeCodeView nativeAddress state))
    (vectorAccess : vectorMemoryAccess native (nativeCodeView nativeAddress state)) :
    dispatchSourceEmission nativeAddress emission sourceScalar sourceStack firstScalar secondScalar release failure state =
      some (Reference.AArch64.step native (nativeCodeView nativeAddress state)) := by
  cases binding with
  | numeric ordinary native binding =>
      exact emission_step_refines nativeAddress ordinary sourceScalar sourceStack firstScalar secondScalar release failure
        native (nativeCodeView nativeAddress state) binding access environment pairAccess vectorAccess
  | call target successor displacement targetAddress successorAddress =>
      exact congrArg some (source_call_observed_refines nativeAddress target successor displacement state targetAddress successorAddress)
  | address dst address fallthrough displacement addressValue fallAddress =>
      exact congrArg some (source_address_observed_refines nativeAddress dst address fallthrough displacement state addressValue fallAddress)
  | register link src targets successor code allowed successorAddress =>
      exact code_target_observed_refines nativeAddress link src targets successor state code allowed successorAddress


/-- Raw tag bytes of the production cells. ZR has no tag cell. Non-CODE/
RETURN cells are already in the prior numeric stack/data observation. -/
def returnTag (tags : Reference.AArch64.Gpr → Byte) (src : Register) : Byte :=
  if h : src.val < 31 then tags ⟨src.val, h⟩ else 0

/-- RETURN carries an offset from this invocation's authenticated outer LR;
CODE still carries a source token. Applying this frame before the existing
code view keeps the two address spaces and tag classes distinct. -/
def returnCodeState (outerReturn : Word) (tags : Reference.AArch64.Gpr → Byte)
    (raw : Reference.AArch64.State) : CodeState :=
  ⟨{ raw with gpr := fun r => if tags r = 10 then outerReturn + raw.gpr r else raw.gpr r },
    fun r => tags r == 9⟩

theorem return_frame_read (outerReturn : Word) (tags : Reference.AArch64.Gpr → Byte)
    (raw : Reference.AArch64.State) (src : Register) :
    Reference.AArch64.readReg (returnCodeState outerReturn tags raw).bits src =
      if returnTag tags src = 10 then outerReturn + Reference.AArch64.readReg raw src
      else Reference.AArch64.readReg raw src := by
  by_cases general : src.val < 31 <;>
    simp [Reference.AArch64.readReg, returnCodeState, returnTag, general]

theorem return_frame_code (outerReturn : Word) (tags : Reference.AArch64.Gpr → Byte)
    (raw : Reference.AArch64.State) (src : Register) :
    codeSource (returnCodeState outerReturn tags raw) src = (returnTag tags src == 9) := by
  by_cases general : src.val < 31 <;> simp [codeSource, returnCodeState, returnTag, general]

/-- This is RET_TO's actual classification, including its raw-zero RETURN
check and finite CODE switch. Rejected control does not acquire an ISA
success transition. The u32 result and SKB context copy belong to the
separate invocation exit interface, not to a native RET instruction. -/
inductive ReturnRoute where
  | outer
  | internal (target : Word)
  deriving DecidableEq

def returnRoute (tags : Reference.AArch64.Gpr → Byte) (src : Register)
    (targets : List Word) (raw : Reference.AArch64.State) : Option ReturnRoute :=
  let target := Arm64Move.Fields.read raw (Arm64Register.registerCode src)
  if target = 0 ∧ returnTag tags src = 10 then some .outer
  else if returnTag tags src = 9 ∧ targets.contains target = true then some (.internal target)
  else none

/-- The source macro terminates in the outer arm. Its native-PC observation
uses the same-invocation LR witness, not an invented zero return sentinel.
SKB cb synchronization and the physical compiled continuation remain O2/O4. -/
def observeReturnRoute (nativeAddress : Word → Word) (outerReturn : Word)
    (state : CodeState) (route : ReturnRoute) : Transition Reference.AArch64.State :=
  match route with
  | .outer => ⟨{ nativeCodeView nativeAddress state with pc := outerReturn }, [], none⟩
  | .internal target => observeCodeTransition nativeAddress ⟨codePc state target, [], none⟩

/-- All successful RET_TO routes refine the SAME canonical register branch.
The sole route premise is the concrete macro guard; register target values
and whole-state preservation are derived, including non-X30 RET operands. -/
theorem return_route_observed_refines (nativeAddress : Word → Word) (outerReturn : Word)
    (tags : Reference.AArch64.Gpr → Byte) (src : Register) (targets : List Word)
    (raw : Reference.AArch64.State) (route : ReturnRoute)
    (reached : returnRoute tags src targets raw = some route) :
    observeReturnRoute nativeAddress outerReturn (returnCodeState outerReturn tags raw) route =
      Reference.AArch64.step (.branchRegister false src)
        (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)) := by
  unfold returnRoute at reached
  dsimp only at reached
  split at reached
  next outer =>
    obtain ⟨zero, tag⟩ := outer
    have rawRead : Reference.AArch64.readReg raw src = 0 := by
      simpa only [Arm64Move.Fields.register_read, Arm64Register.read_refines] using zero
    have target : Reference.AArch64.readReg
        (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)) src = outerReturn := by
      rw [native_code_read, return_frame_code, tag]
      simp only [show ((10 : Byte) == 9) = false from rfl, Bool.false_eq_true, ↓reduceIte,
        return_frame_read, tag, ↓reduceIte, rawRead]
      exact BitVec.add_zero _
    cases reached
    simp only [observeReturnRoute, Reference.AArch64.step, Bool.false_eq_true, ↓reduceIte, target]
  next notOuter =>
    split at reached
    next internal =>
      obtain ⟨tag, allowed⟩ := internal
      have target : Reference.AArch64.readReg
          (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)) src =
          nativeAddress (Arm64Move.Fields.read raw (Arm64Register.registerCode src)) := by
        rw [native_code_read, return_frame_code, tag]
        simp only [show ((9 : Byte) == 9) = true from rfl, ↓reduceIte, return_frame_read, tag,
          show (9 : Byte) ≠ 10 from by decide, ↓reduceIte,
          Arm64Move.Fields.register_read, Arm64Register.read_refines]
      cases reached
      simp only [observeReturnRoute, observeCodeTransition, native_code_pc,
        Reference.AArch64.step, Bool.false_eq_true, ↓reduceIte, target]
    next rejected => contradiction

/-- ARM64_SIM_RET returns the low32 materialized X0 bits. Ordinary CODE data
still needs its actual transport; the result equation explicitly excludes
that unproved case instead of assuming source tokens equal native words. -/
theorem outer_return_value (nativeAddress : Word → Word) (outerReturn : Word)
    (tags : Reference.AArch64.Gpr → Byte) (raw : Reference.AArch64.State)
    (notCode : returnTag tags 0 ≠ 9) :
    (Reference.AArch64.readReg (returnCodeState outerReturn tags raw).bits 0).setWidth 32 =
      (Reference.AArch64.readReg
        (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)) 0).setWidth 32 := by
  rw [native_code_read, return_frame_code]
  simp only [beq_iff_eq]
  rw [if_neg notCode]


/-- The ordinary source-emission interface and RET_TO share exactly one
RETURN/CODE frame. The right-hand sum carries the actual return operand and
per-site finite goto table; helper/ABI exit effects remain separate. -/
def dispatchInvocationEmission (nativeAddress : Word → Word) (outerReturn : Word)
    (tags : Reference.AArch64.Gpr → Byte) (emission : SourceEmission ⊕ (Register × List Word))
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) (raw : Reference.AArch64.State) :
    Option (Transition Reference.AArch64.State) :=
  let state := returnCodeState outerReturn tags raw
  match emission with
  | .inl ordinary => dispatchSourceEmission nativeAddress ordinary sourceScalar sourceStack
      firstScalar secondScalar release failure state
  | .inr (src, targets) => (returnRoute tags src targets raw).map (observeReturnRoute nativeAddress outerReturn state)

/-- Native layout/field relations and the literal RET_TO guards only. No
handler transition is a premise. Native access/profile/exclusive witnesses
stay separate, as in the preceding numeric/control compositions. -/
inductive InvocationBinding (nativeAddress : Word → Word) (outerReturn : Word)
    (tags : Reference.AArch64.Gpr → Byte) (raw : Reference.AArch64.State) (release : Bool) :
    SourceEmission ⊕ (Register × List Word) → Reference.AArch64.Instruction → Prop where
  | source (ordinary : SourceEmission) (native : Reference.AArch64.Instruction)
      (binding : SourceBinding nativeAddress (returnCodeState outerReturn tags raw) release ordinary native) :
      InvocationBinding nativeAddress outerReturn tags raw release (.inl ordinary) native
  | outer (src : Register) (targets : List Word)
      (zero : Arm64Move.Fields.read raw (Arm64Register.registerCode src) = 0)
      (tag : returnTag tags src = 10) :
      InvocationBinding nativeAddress outerReturn tags raw release (.inr (src, targets)) (.branchRegister false src)
  | internal (src : Register) (targets : List Word) (tag : returnTag tags src = 9)
      (allowed : targets.contains (Arm64Move.Fields.read raw (Arm64Register.registerCode src)) = true) :
      InvocationBinding nativeAddress outerReturn tags raw release (.inr (src, targets)) (.branchRegister false src)

/-- One observed invocation-emission step combines all preceding modeled
numeric/direct/CODE arms with outer RETURN and finite CODE returns. This is
not the physical compiled invocation/return, helper or arbitrary CODE-data
transport theorem. Those boundaries cannot be obtained by case composition. -/
theorem invocation_emission_step_refines (nativeAddress : Word → Word) (outerReturn : Word)
    (tags : Reference.AArch64.Gpr → Byte) (emission : SourceEmission ⊕ (Register × List Word))
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (raw : Reference.AArch64.State)
    (binding : InvocationBinding nativeAddress outerReturn tags raw release emission native)
    (access : scalarMemoryAccess native (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)))
    (environment : exclusiveStoreEnvironment native failure (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)))
    (pairAccess : pairMemoryAccess native (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)))
    (vectorAccess : vectorMemoryAccess native (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw))) :
    dispatchInvocationEmission nativeAddress outerReturn tags emission sourceScalar sourceStack
        firstScalar secondScalar release failure raw =
      some (Reference.AArch64.step native (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw))) := by
  cases binding with
  | source ordinary native earlier =>
      exact source_emission_step_refines nativeAddress ordinary sourceScalar sourceStack firstScalar
        secondScalar release failure native (returnCodeState outerReturn tags raw) earlier access environment pairAccess vectorAccess
  | outer src targets zero tag =>
      have reached : returnRoute tags src targets raw = some .outer := by
        unfold returnRoute
        dsimp only
        rw [if_pos ⟨zero, tag⟩]
      simp only [dispatchInvocationEmission, reached, Option.map_some]
      exact congrArg some (return_route_observed_refines nativeAddress outerReturn tags src targets raw .outer reached)
  | internal src targets tag allowed =>
      have notOuter : ¬(Arm64Move.Fields.read raw (Arm64Register.registerCode src) = 0 ∧ returnTag tags src = 10) := by
        intro h
        exact (by decide : (9 : Byte) ≠ 10) (tag.symm.trans h.2)
      have reached : returnRoute tags src targets raw = some (.internal (Arm64Move.Fields.read raw (Arm64Register.registerCode src))) := by
        unfold returnRoute
        dsimp only
        rw [if_neg notOuter, if_pos ⟨tag, allowed⟩]
      simp only [dispatchInvocationEmission, reached, Option.map_some]
      exact congrArg some (return_route_observed_refines nativeAddress outerReturn tags src targets raw _ reached)


/-- Generated direct memory bodies23--26. Signed load selectors retain their
source byte width and W/X output independently. -/
inductive MemoryToken where
  | load | store | signed (op : GeneratedArm64LdrSx.LdrSx) | exclusive | atomicAdd | atomicLogical (set : Bool)

def memoryTokenOpcode : MemoryToken → Nat
  | .load => GeneratedArm64DispatchSingleton.code .load
  | .store => GeneratedArm64DispatchSingleton.code .store
  | .signed op => GeneratedArm64LdrSx.code op
  | .exclusive => GeneratedArm64Stlxr.code .stlxr
  | .atomicAdd => atomicOpcode
  | .atomicLogical set => logicalAtomicOpcode set

/-- Numeric projection of each selected direct body, preserving pre/read/write/
post order, signed source width, source capture and the fresh exclusive result.
Pointer provenance and native memory observations retain the shared frame. -/
def specializedMemory (token : MemoryToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 : Byte) (value : Word) (tagIsScalar failure : Bool)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  match token with
  | .load => (decodeMemoryWidth flags).map
      (fun width => scalarMemoryBody true width aux dst src src2 value tagIsScalar s)
  | .store => (decodeMemoryWidth flags).map
      (fun width => scalarMemoryBody false width aux src dst src2 value tagIsScalar s)
  | .signed op => (decodeDataWidth flags).map
      (fun width => signedMemoryBody op width aux dst src src2 value s)
  | .exclusive => (decodeDataWidth flags).map
      (fun width => exclusiveStoreBody width failure aux dst src src2 s)
  | .atomicAdd => (decodeMemoryWidth flags).map
      (fun width => atomicByteBody width dst src src2 s)
  | .atomicLogical set => (decodeMemoryWidth flags).map
      (fun width => logicalAtomicByteBody set width dst src src2 s)

/-- Every direct memory body equals its complete numeric L_EXEC arm for all
fields and incoming states, including the established width domain. -/
theorem memory_token_body_matches (token : MemoryToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    specializedMemory token flags aux dst src src2 value firstScalar failure s =
      dispatchExec (memoryTokenOpcode token) flags aux dst src src2 src3 value
        sourceScalar sourceStack firstScalar secondScalar failure s := by
  cases token with
  | load =>
      unfold memoryTokenOpcode specializedMemory dispatchExec dispatchThroughQ dispatchThroughD
        dispatchThroughPair dispatchThroughExclusive dispatchThroughStore dispatchThroughSigned
      rw [load_reached]
      cases decoded : decodeMemoryWidth flags <;> rfl
  | store =>
      unfold memoryTokenOpcode specializedMemory dispatchExec dispatchThroughQ dispatchThroughD
        dispatchThroughPair dispatchThroughExclusive
      rw [store_reached]
      cases decoded : decodeMemoryWidth flags <;> rfl
  | signed op =>
      unfold memoryTokenOpcode specializedMemory dispatchExec dispatchThroughQ dispatchThroughD
        dispatchThroughPair dispatchThroughExclusive dispatchThroughStore
      rw [signed_reached]
      cases decoded : decodeDataWidth flags <;> cases op <;> rfl
  | exclusive =>
      unfold memoryTokenOpcode specializedMemory dispatchExec dispatchThroughQ dispatchThroughD
        dispatchThroughPair
      rw [exclusive_reached]
      cases decoded : decodeDataWidth flags <;> rfl

  | atomicAdd =>
      unfold memoryTokenOpcode specializedMemory
      rw [atomic_reached]

  | atomicLogical set =>
      unfold memoryTokenOpcode specializedMemory
      rw [logical_atomic_reached]

/-- Once per memory token, compose direct-body equality with the canonical
observed dispatcher step, retaining access, exclusive and ABI premises. -/
theorem memory_token_step_refines (token : MemoryToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : ExecBinding s.pc (memoryTokenOpcode token) flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch (memoryTokenOpcode token) flags release failure src2 s
      (observeQDispatch (memoryTokenOpcode token) (specializedMemory token flags aux dst src src2 value
        firstScalar failure s)) = some (Reference.AArch64.step native s) := by
  rw [memory_token_body_matches token flags aux dst src src2 src3 value sourceScalar sourceStack
    firstScalar secondScalar failure s]
  exact exec_observed_step_refines _ flags aux dst src src2 src3 value sourceScalar sourceStack
    firstScalar secondScalar release failure native s binding access environment pairAccess vectorAccess

/-- The environment supplies a fresh word at the same IMM site on this visit.
Every nonzero word takes the failure arm; zero takes the store arm. -/
def specializedMemoryAt (outcomeAt : Word → Word) (token : MemoryToken)
    (flags : Byte) (aux : BitVec 32) (dst src src2 : Byte) (site : Word)
    (tagIsScalar : Bool) (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  specializedMemory token flags aux dst src src2 site tagIsScalar (outcomeAt site != 0) s

theorem memory_token_at_body_matches (outcomeAt : Word → Word) (token : MemoryToken)
    (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (site : Word)
    (sourceScalar sourceStack firstScalar secondScalar : Bool) (s : Reference.AArch64.State) :
    specializedMemoryAt outcomeAt token flags aux dst src src2 site firstScalar s =
      dispatchExec (memoryTokenOpcode token) flags aux dst src src2 src3 site
        sourceScalar sourceStack firstScalar secondScalar (outcomeAt site != 0) s :=
  memory_token_body_matches token flags aux dst src src2 src3 site sourceScalar sourceStack
    firstScalar secondScalar (outcomeAt site != 0) s

theorem memory_token_at_step_refines (outcomeAt : Word → Word) (token : MemoryToken)
    (flags : Byte) (aux : BitVec 32) (dst src src2 src3 : Byte) (site : Word)
    (sourceScalar sourceStack firstScalar secondScalar release : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : ExecBinding s.pc (memoryTokenOpcode token) flags aux dst src src2 src3 site release native)
    (access : scalarMemoryAccess native s)
    (environment : exclusiveStoreEnvironment native (outcomeAt site != 0) s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch (memoryTokenOpcode token) flags release (outcomeAt site != 0) src2 s
      (observeQDispatch (memoryTokenOpcode token) (specializedMemoryAt outcomeAt token flags aux dst src src2
        site firstScalar s)) = some (Reference.AArch64.step native s) :=
  memory_token_step_refines token flags aux dst src src2 src3 site sourceScalar sourceStack
    firstScalar secondScalar release (outcomeAt site != 0) native s binding access environment pairAccess vectorAccess


/-- Generated scalar-body selectors. The logical flag family carries the
native register-only field condition for inverted operands. -/
inductive ScalarToken where
  | nop | address (op : GeneratedArm64Adrp.Op) | move (op : GeneratedArm64Mov.Mov) | keep
  | aluRegister | shift (immediate : Bool) | multiply (op : GeneratedArm64Mul.Mul)
  | unary (op : GeneratedArm64Unary.Unary) | conditionalNegate
  | extrev (op : GeneratedArm64Extrev.Extrev) | bitfield
  | flagArithmetic (subtract writeback immediate : Bool)
  | flagLogic (invert writeback immediate : Bool) (valid : invert = true → immediate = false)
  | orn | compare (immediate : Bool) | select (op : GeneratedArm64Csel.Csel)

def scalarTokenOpcode : ScalarToken → Nat
  | .nop => GeneratedArm64DispatchSingleton.code .nop
  | .address op => GeneratedArm64Adrp.code op
  | .move op => GeneratedArm64Mov.code op
  | .keep => GeneratedArm64DispatchSingleton.code .movk
  | .aluRegister => aluCode false
  | .shift immediate => shiftOpcode immediate
  | .multiply op => GeneratedArm64Mul.code op
  | .unary op => GeneratedArm64Unary.code op
  | .conditionalNegate => GeneratedArm64Cneg.code .cneg
  | .extrev op => GeneratedArm64Extrev.code op
  | .bitfield => GeneratedArm64DispatchSingleton.code .bitfield
  | .flagArithmetic sub wb imm => Arm64Arithmetic.FlagArithmetic.operationCode sub wb imm
  | .flagLogic inv wb imm _ => Arm64Logic.FlagDispatch.operationCode inv wb imm
  | .orn => GeneratedArm64Orn.code .orn_reg
  | .compare imm => GeneratedArm64DispatchFamily.code (if imm then .ccmpImm else .ccmpReg)
  | .select op => GeneratedArm64Csel.code op

/-- Independent numeric projection of each selected direct scalar body. The
shared FLAGS normalization precedes its exact AUX/source/result/writeback path. -/
def specializedScalar (token : ScalarToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  (decodeDataWidth flags).bind (fun width =>
    match token with
    | .nop => some (Arm64Branch.nopStep s)
    | .address _ => some (addressBody dst value s)
    | .move op => some (moveBody op width dst src value s)
    | .keep => (Arm64Movk.decodeShift (GeneratedArm64Aux.b2 aux).toNat).map
        (fun column => keepBody column width dst value s)
    | .aluRegister => (decodeAlu (GeneratedArm64Aux.b0 aux).toNat).map
        (fun op => aluBody op false sourceScalar sourceStack aux width dst src src2 value s)
    | .shift imm => (Arm64Shift.decodeKind (GeneratedArm64Aux.b0 aux).toNat).map
        (fun kind => shiftBody (if imm then .shiftImm else .shiftReg) kind width dst src src2 value s)
    | .multiply op => some (multiplyBody op width dst src src2 src3 s)
    | .unary op => some (unaryBody op aux width dst src s)
    | .conditionalNegate => (Arm64Condition.decode aux.toNat).map
        (fun predicate => conditionalNegateBody predicate width dst src s)
    | .extrev op => some (extrevBody op width dst src src2 value s)
    | .bitfield => (Arm64Bitfield.decodeKind (GeneratedArm64Aux.b0 aux).toNat).map
        (fun kind => bitfieldBody kind aux width dst src s)
    | .flagArithmetic sub wb imm => some (flagArithmeticBody sub wb imm aux width dst src src2 value s)
    | .flagLogic inv wb imm _ => some (flagLogicBody inv wb imm aux width dst src src2 value s)
    | .orn => some (ornBody aux width dst src src2 s)
    | .compare imm => (Arm64Condition.decode (GeneratedArm64CcmpDecode.ccmpCond aux).toNat).map
        (fun predicate => compareBody (if imm then .ccmpImm else .ccmpReg) predicate
          ((GeneratedArm64CcmpDecode.ccmpNzcv aux).setWidth 8) width dst src value s)
    | .select op => (Arm64Condition.decode aux.toNat).map
        (fun predicate => selectBody op predicate width dst src src2 s))

/-- Every selected scalar direct body equals the complete L_EXEC numeric
transition, retaining all input fields and its established width/AUX domain. -/
theorem scalar_token_body_matches (token : ScalarToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    specializedScalar token flags aux dst src src2 src3 value sourceScalar sourceStack s =
      dispatchExec (scalarTokenOpcode token) flags aux dst src src2 src3 value
        sourceScalar sourceStack firstScalar secondScalar failure s := by
  unfold specializedScalar dispatchExec dispatchThroughQ dispatchThroughD dispatchThroughPair
    dispatchThroughExclusive dispatchThroughStore dispatchThroughSigned dispatchThroughLoad dispatchEncodedPrefix
    dispatchThroughSelect dispatchThroughCompare dispatchThroughOrn dispatchThroughFlagLogic
    dispatchThroughFlagArithmetic dispatchThroughBitfield dispatchThroughExtrev dispatchThroughUnary
    dispatchThroughMultiply dispatchThroughShift dispatch dispatchPrefix
  cases token with
  | nop => cases w : (decodeDataWidth flags) <;> rfl
  | address op => cases op <;> cases w : (decodeDataWidth flags) <;> rfl
  | move op => cases op <;> cases w : (decodeDataWidth flags) <;> rfl
  | keep => cases w : (decodeDataWidth flags) <;>
      cases column : Arm64Movk.decodeShift (GeneratedArm64Aux.b2 aux).toNat <;> rfl
  | aluRegister => cases w : (decodeDataWidth flags) <;>
      cases op : decodeAlu (GeneratedArm64Aux.b0 aux).toNat <;> rfl
  | shift imm => cases imm <;> cases w : (decodeDataWidth flags) <;>
      cases kind : Arm64Shift.decodeKind (GeneratedArm64Aux.b0 aux).toNat <;> rfl
  | multiply op => cases op <;> cases w : (decodeDataWidth flags) <;> rfl
  | unary op => cases op <;> cases w : (decodeDataWidth flags) <;> rfl
  | conditionalNegate => cases w : (decodeDataWidth flags) <;>
      cases predicate : Arm64Condition.decode aux.toNat <;> rfl
  | extrev op => cases op <;> cases w : (decodeDataWidth flags) <;> rfl
  | bitfield => cases w : (decodeDataWidth flags) <;>
      cases kind : Arm64Bitfield.decodeKind (GeneratedArm64Aux.b0 aux).toNat <;> rfl
  | flagArithmetic sub wb imm => cases sub <;> cases wb <;> cases imm <;>
      cases w : (decodeDataWidth flags) <;> rfl
  | flagLogic inv wb imm valid =>
      cases inv <;> cases wb <;> cases imm
      all_goals try { cases (valid rfl) }
      all_goals cases w : (decodeDataWidth flags) <;> rfl
  | orn => cases w : (decodeDataWidth flags) <;> rfl
  | compare imm => cases imm <;> cases w : (decodeDataWidth flags) <;>
      cases predicate : Arm64Condition.decode (GeneratedArm64CcmpDecode.ccmpCond aux).toNat <;> rfl
  | select op => cases op <;> cases w : (decodeDataWidth flags) <;>
      cases predicate : Arm64Condition.decode aux.toNat <;> rfl

/-- Per scalar token, specialize the existing complete canonical observed step
under the same source-field, native memory, monitor and platform relations. -/
theorem scalar_token_step_refines (token : ScalarToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : ExecBinding s.pc (scalarTokenOpcode token) flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch (scalarTokenOpcode token) flags release failure src2 s
      (observeQDispatch (scalarTokenOpcode token) (specializedScalar token flags aux dst src src2 src3 value
        sourceScalar sourceStack s)) = some (Reference.AArch64.step native s) := by
  rw [scalar_token_body_matches token flags aux dst src src2 src3 value sourceScalar sourceStack
    firstScalar secondScalar failure s]
  exact exec_observed_step_refines _ flags aux dst src src2 src3 value sourceScalar sourceStack
    firstScalar secondScalar release failure native s binding access environment pairAccess vectorAccess


/-- Direct pair/vector/move/reduction selectors preserve their own width and
bank domains. D/Q and reductions consume their fixed widths independently of FLAGS. -/
inductive VectorToken where
  | pair (load : Bool) | d (load : Bool) | q (load : Bool) | move
  | reduction (op : Reference.AArch64.ReductionOp)

def vectorTokenOpcode : VectorToken → Nat
  | .pair load => pairCode load
  | .d load => dCode load
  | .q load => qCode load
  | .move => GeneratedArm64DispatchSingleton.code .fmov
  | .reduction op => GeneratedArm64Reduction.code (Arm64Reduction.operation op)

def specializedVector (token : VectorToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word) (firstScalar secondScalar : Bool)
    (s : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  match token with
  | .pair load => (decodeDataWidth flags).map (fun width => pairByteBody load width aux
      (if load then dst else src) (if load then src else src2) (if load then src2 else dst)
      src3 value firstScalar secondScalar s)
  | .d load => some (dByteBody load aux (if load then src else dst) src2 value s)
  | .q load => some (qByteBody load aux (if load then src else dst) src2 value s)
  | .move => (Arm64Fmov.decodeDirection aux.toNat).bind (fun direction =>
      (Arm64Fmov.vectorIndex src2.toNat).bind (fun bank =>
        (decodeFmovWidth direction flags).map (fun width => fmovByteBody bank direction width dst src s)))
  | .reduction op => some (Arm64Reduction.handlerStep op (aux.toNat == 16) s)

/-- The selected direct body equals the complete L_EXEC transition for each
pair/vector token, including bank31, default bank, fixed widths and AUX branches. -/
theorem vector_token_body_matches (token : VectorToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool) (s : Reference.AArch64.State) :
    specializedVector token flags aux dst src src2 src3 value firstScalar secondScalar s =
      dispatchExec (vectorTokenOpcode token) flags aux dst src src2 src3 value
        sourceScalar sourceStack firstScalar secondScalar failure s := by
  cases token with
  | pair load =>
      unfold specializedVector vectorTokenOpcode dispatchExec dispatchThroughQ dispatchThroughD
      rw [pair_reached]
      cases load <;> cases w : (decodeDataWidth flags) <;> rfl
  | d load =>
      unfold specializedVector vectorTokenOpcode dispatchExec dispatchThroughQ
      rw [d_reached]
  | q load =>
      unfold specializedVector vectorTokenOpcode dispatchExec
      rw [q_reached]
  | move =>
      unfold specializedVector vectorTokenOpcode dispatchExec
      rw [exec_tail_before_none _ _ _ _ _ _ _ _ _ _ _ _ _ s (Or.inl rfl)]
      rfl
  | reduction op =>
      have tailCode : vectorTokenOpcode (.reduction op) = GeneratedArm64DispatchSingleton.code .fmov ∨
          vectorTokenOpcode (.reduction op) = GeneratedArm64Reduction.code .cnt ∨
          vectorTokenOpcode (.reduction op) = GeneratedArm64Reduction.code .uaddlv := by
        cases op <;> simp [vectorTokenOpcode, Arm64Reduction.operation]
      unfold specializedVector dispatchExec
      rw [exec_tail_before_none _ _ _ _ _ _ _ _ _ _ _ _ _ s tailCode]
      cases op <;> rfl

/-- Pair access, D/Q observations and FMOV bank/width binding compose the direct
body identity with the existing full canonical step under the shared premises. -/
theorem vector_token_step_refines (token : VectorToken) (flags : Byte) (aux : BitVec 32)
    (dst src src2 src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (s : Reference.AArch64.State)
    (binding : ExecBinding s.pc (vectorTokenOpcode token) flags aux dst src src2 src3 value release native)
    (access : scalarMemoryAccess native s) (environment : exclusiveStoreEnvironment native failure s)
    (pairAccess : pairMemoryAccess native s) (vectorAccess : vectorMemoryAccess native s) :
    observeExclusiveDispatch (vectorTokenOpcode token) flags release failure src2 s
      (observeQDispatch (vectorTokenOpcode token) (specializedVector token flags aux dst src src2 src3 value
        firstScalar secondScalar s)) = some (Reference.AArch64.step native s) := by
  rw [vector_token_body_matches token flags aux dst src src2 src3 value sourceScalar sourceStack
    firstScalar secondScalar failure s]
  exact exec_observed_step_refines _ flags aux dst src src2 src3 value sourceScalar sourceStack
    firstScalar secondScalar release failure native s binding access environment pairAccess vectorAccess


/-- A literal C switch scans the finite source-label cases. Its selected
route retains the incoming target word. -/
def specializedReturnSwitch (target : Word) : List Word → Option ReturnRoute
  | [] => none
  | label :: rest => if target = label then some (.internal target)
      else specializedReturnSwitch target rest

theorem return_switch_matches (target : Word) (targets : List Word) :
    specializedReturnSwitch target targets =
      if targets.contains target then some (.internal target) else none := by
  induction targets with
  | nil => rfl
  | cons label rest ih =>
      by_cases hit : target = label
      · simp [specializedReturnSwitch, hit]
      · have apart : label ≠ target := Ne.symm hit
        simp [specializedReturnSwitch, hit, List.contains_cons, beq_iff_eq, apart, ih]

/-- RET_TO first captures raw Rn into its private LR scratch, takes the
nonzero/tag guard, and then chooses its finite CODE switch or outer return.
Architectural register cells retain their values; the scratch is private. -/
def specializedReturnRoute (tags : Reference.AArch64.Gpr → Byte) (src : Register)
    (targets : List Word) (raw : Reference.AArch64.State) : Option ReturnRoute :=
  let target := Arm64Move.Fields.read raw (Arm64Register.registerCode src)
  if target != 0 || returnTag tags src != 10 then
    if returnTag tags src == 9 then specializedReturnSwitch target targets else none
  else some .outer

theorem return_token_route_matches (tags : Reference.AArch64.Gpr → Byte) (src : Register)
    (targets : List Word) (raw : Reference.AArch64.State) :
    specializedReturnRoute tags src targets raw = returnRoute tags src targets raw := by
  by_cases zero : Arm64Move.Fields.read raw (Arm64Register.registerCode src) = 0 <;>
    by_cases ret : returnTag tags src = 10 <;>
    by_cases code : returnTag tags src = 9 <;>
    simp_all [specializedReturnRoute, returnRoute, return_switch_matches]

/-- The emitted RET token applies the existing RETURN/CODE observation to
its independently selected C route. Invocation exit memory and physical ABI
transport retain their explicit platform relation. -/
def specializedReturn (nativeAddress : Word → Word) (outerReturn : Word)
    (tags : Reference.AArch64.Gpr → Byte) (src : Register) (targets : List Word)
    (raw : Reference.AArch64.State) : Option (Transition Reference.AArch64.State) :=
  (specializedReturnRoute tags src targets raw).map
    (observeReturnRoute nativeAddress outerReturn (returnCodeState outerReturn tags raw))

theorem return_token_body_matches (nativeAddress : Word → Word) (outerReturn : Word)
    (tags : Reference.AArch64.Gpr → Byte) (src : Register) (targets : List Word)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) (raw : Reference.AArch64.State) :
    specializedReturn nativeAddress outerReturn tags src targets raw =
      dispatchInvocationEmission nativeAddress outerReturn tags (.inr (src, targets))
        sourceScalar sourceStack firstScalar secondScalar release failure raw := by
  simp only [specializedReturn, return_token_route_matches, dispatchInvocationEmission]

/-- Once for the emitted RET token, compose the route/body equality with the
canonical branch step under the shared source-label and same-invocation LR frame. -/
theorem return_token_step_refines (nativeAddress : Word → Word) (outerReturn : Word)
    (tags : Reference.AArch64.Gpr → Byte) (src : Register) (targets : List Word)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool)
    (native : Reference.AArch64.Instruction) (raw : Reference.AArch64.State)
    (binding : InvocationBinding nativeAddress outerReturn tags raw release (.inr (src, targets)) native)
    (access : scalarMemoryAccess native (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)))
    (environment : exclusiveStoreEnvironment native failure (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)))
    (pairAccess : pairMemoryAccess native (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw)))
    (vectorAccess : vectorMemoryAccess native (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw))) :
    specializedReturn nativeAddress outerReturn tags src targets raw =
      some (Reference.AArch64.step native (nativeCodeView nativeAddress (returnCodeState outerReturn tags raw))) := by
  rw [return_token_body_matches nativeAddress outerReturn tags src targets sourceScalar sourceStack
    firstScalar secondScalar release failure raw]
  exact invocation_emission_step_refines nativeAddress outerReturn tags (.inr (src, targets))
    sourceScalar sourceStack firstScalar secondScalar release failure native raw binding access environment pairAccess vectorAccess

/-- The unified byte LDADD dispatcher selects the typed-kfunc C body.
Its primitive/ABI ordering relation remains the platform interface. -/
theorem exec_atomic_byte_kfunc (dst src base : Register) (flags : Byte)
    (aux : BitVec 32) (src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool)
    (s : Reference.AArch64.State)
    (encoded : GeneratedArm64Width.effective flags.toNat = 1) :
    dispatchExec atomicOpcode flags aux (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (memoryBaseCode base) src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s =
      some (Arm64Atomic.byteKfuncBody 0 false dst src base s) := by
  rw [atomic_reached, decode_memory_width flags .byte encoded]
  change some (atomicByteBody .byte _ _ _ s) = _
  rw [atomic_body_typed]
  exact congrArg some (Arm64Atomic.byte_kfunc_add_body dst src base s).symm

/-- The same binding covers LDSET/STSET and LDCLR/STCLR, including ZR/SP
aliases through the existing byte-field decoder and register maps. -/
theorem exec_logical_atomic_byte_kfunc (set : Bool) (dst src base : Register)
    (flags : Byte) (aux : BitVec 32) (src3 : Byte) (value : Word)
    (sourceScalar sourceStack firstScalar secondScalar failure : Bool)
    (s : Reference.AArch64.State)
    (encoded : GeneratedArm64Width.effective flags.toNat = 1) :
    dispatchExec (logicalAtomicOpcode set) flags aux (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (memoryBaseCode base) src3 value
      sourceScalar sourceStack firstScalar secondScalar failure s =
      some (Arm64Atomic.byteKfuncBody (if set then 1 else 2) (!set) dst src base s) := by
  rw [logical_atomic_reached, decode_memory_width flags .byte encoded]
  change some (logicalAtomicByteBody set .byte _ _ _ s) = _
  rw [logical_atomic_body_typed]
  exact congrArg some (Arm64Atomic.byte_kfunc_logical_body set dst src base s).symm

end KProgFormal.Refinement.Arm64Dispatcher

#print axioms KProgFormal.Refinement.Arm64Dispatcher.exec_logical_atomic_refines
#print axioms KProgFormal.Refinement.Arm64Dispatcher.logical_atomic_body_typed

#print axioms KProgFormal.Refinement.Arm64Dispatcher.exec_atomic_byte_kfunc
#print axioms KProgFormal.Refinement.Arm64Dispatcher.exec_logical_atomic_byte_kfunc
