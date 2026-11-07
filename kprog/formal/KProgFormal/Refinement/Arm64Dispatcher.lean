import KProgFormal.Refinement.Arm64Move
import KProgFormal.Refinement.Arm64Arithmetic
import KProgFormal.Refinement.Arm64Mul
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

end KProgFormal.Refinement.Arm64Dispatcher
