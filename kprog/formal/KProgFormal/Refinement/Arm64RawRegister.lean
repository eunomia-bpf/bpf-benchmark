import KProgFormal.Refinement.Arm64Dispatcher

namespace KProgFormal.Refinement.Arm64RawRegister
open Reference
open Reference.AArch64 (Register Gpr Width KeepInstruction)

/-- Numeric inputs for the two C materialization cases. Their entry/platform
identity is supplied independently of register-cell and stack storage layout. -/
structure Origins where
  stack : Word
  returnAddress : Word

/-- Raw architectural register words and the complete byte-tag domain.
All remaining architectural fields stay in the shared reference frame. -/
structure State where
  raw : Reference.AArch64.State
  tags : Gpr → Byte

def materialize (origins : Origins) (word : Word) (tag : Byte) : Word :=
  if tag = 4 then word + origins.stack
  else if tag = 10 then word + origins.returnAddress else word

def image (origins : Origins) (state : State) : Reference.AArch64.State :=
  { state.raw with
    gpr := fun r => materialize origins (state.raw.gpr r) (state.tags r)
    sp := state.raw.sp + origins.stack }

def readRegister (origins : Origins) (state : State) (src : Register) : Word :=
  match GeneratedArm64RegDispatch.cellOf (Arm64Register.registerCode src) with
  | some index =>
      let cell : Gpr := ⟨index % 31, Nat.mod_lt _ (by decide)⟩
      materialize origins (state.raw.gpr cell) (state.tags cell)
  | none => 0

theorem read_refines (origins : Origins) (state : State) (src : Register) :
    readRegister origins state src = Reference.AArch64.readReg (image origins state) src := by
  by_cases general : src.val < 31 <;>
    simp [readRegister, Arm64Register.cell_refines, Reference.AArch64.readReg,
      image, general, Nat.mod_eq_of_lt]

/-- The GPR/ZR destination arm of WRITE_REG_WIDTH. Native Register fields
range over0..31, so every invocation here keeps the distinct SP32 arm separate. -/
def writeRegister (state : State) (dst : Register) (value : Word) (width : Width) : State :=
  let selected := fun r : Gpr => GeneratedArm64RegPresence.writable (Arm64Register.registerCode dst) &&
    (GeneratedArm64RegDispatch.cellOf (Arm64Register.registerCode dst) == some r.val)
  { raw := { state.raw with
      gpr := fun r => if selected r then Arm64Register.writeValue width value else state.raw.gpr r }
    tags := fun r => if selected r then 0 else state.tags r }

theorem write_refines (origins : Origins) (state : State) (dst : Register)
    (value : Word) (width : Width) :
    image origins (writeRegister state dst value width) =
      Reference.AArch64.writeReg (image origins state) dst (Reference.AArch64.narrow value width) := by
  simp only [image, writeRegister, Arm64Register.write_selection,
    Arm64Register.write_value_refines, Reference.AArch64.writeReg]
  congr 1
  funext r
  by_cases same : r.val = dst.val
  · simp [same, materialize]
  · simp [same, materialize]

theorem write_zero_register (state : State) (value : Word) (width : Width) :
    writeRegister state 31 value width = state := by
  have outside (r : Gpr) : r.val ≠ (31 : Register).val := by
    change r.val ≠ 31
    exact Nat.ne_of_lt r.isLt
  cases state
  simp [writeRegister, Arm64Register.write_selection, outside]

theorem write_tag_frame (state : State) (dst : Register) (value : Word) (width : Width) (r : Gpr) :
    (writeRegister state dst value width).tags r =
      if r.val = dst.val then 0 else state.tags r := by
  simp [writeRegister, Arm64Register.write_selection]

def advance (state : State) : State :=
  { state with raw := { state.raw with pc := state.raw.pc + 4 } }

theorem advance_refines (origins : Origins) (state : State) :
    image origins (advance state) = { image origins state with pc := state.raw.pc + 4 } := rfl

def observe (origins : Origins) (result : Transition State) : Transition Reference.AArch64.State :=
  ⟨image origins result.state, result.events, result.fault⟩

def nop (state : State) : Transition State := ⟨advance state, [], none⟩

def immediate (width : Width) (dst : Register) (value : Word) (state : State) : Transition State :=
  let operand := if GeneratedArm64ImmOperand.immediate .movImm then value else 0
  ⟨advance (writeRegister state dst operand width), [], none⟩

def keep (shift : GeneratedArm64Movk.MovkShift) (width : Width) (dst : Register)
    (value : Word) (origins : Origins) (state : State) : Transition State :=
  let result := GeneratedArm64Movk.value shift (readRegister origins state dst) value
  ⟨advance (writeRegister state dst result width), [], none⟩

theorem nop_refines (origins : Origins) (state : State) :
    observe origins (nop state) = Reference.AArch64.step .nop (image origins state) := rfl

theorem immediate_refines (origins : Origins) (state : State) (width : Width)
    (dst : Register) (value : Word) :
    observe origins (immediate width dst value state) =
      Reference.AArch64.step (.moveImmediate width dst value) (image origins state) := by
  simp only [immediate, GeneratedArm64ImmOperand.immediate, ↓reduceIte, observe,
    advance_refines, write_refines, Reference.AArch64.step]
  rfl

theorem keep_refines (origins : Origins) (state : State) (i : KeepInstruction) :
    observe origins (keep (Arm64Movk.column i.column.val) i.width i.dst
      (i.immediate.setWidth 64) origins state) =
      Reference.AArch64.step (.keep i) (image origins state) := by
  have numeric := Arm64Movk.step_refines i (image origins state)
  simpa only [keep, observe, advance_refines, write_refines, read_refines,
    Arm64Movk.handlerStep, Arm64Register.read_refines, Arm64Register.write_refines] using numeric

/-- Actual prefix order is retained; GOT/rodata address gates pass to their
existing O4-address bodies. This component binds the three pure register gates. -/
def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst : Register) (value : Word)
    (origins : Origins) (state : State) : Option (Transition State) :=
  if code = GeneratedArm64DispatchSingleton.code .nop then some (nop state)
  else if code = GeneratedArm64Adrp.code .got ∨ code = GeneratedArm64Adrp.code .rodata then none
  else if code = GeneratedArm64Mov.code .movImm then some (immediate width dst value state)
  else if code = GeneratedArm64DispatchSingleton.code .movk then
    (Arm64Movk.decodeShift (GeneratedArm64Aux.b2 aux).toNat).map
      (fun shift => keep shift width dst value origins state)
  else none

theorem dispatch_nop (origins : Origins) (state : State) (aux : BitVec 32)
    (width : Width) (dst : Register) (value : Word) :
    (dispatch (GeneratedArm64DispatchSingleton.code .nop) aux width dst value origins state).map
      (observe origins) = some (Reference.AArch64.step .nop (image origins state)) := rfl

theorem dispatch_immediate (origins : Origins) (state : State) (aux : BitVec 32)
    (width : Width) (dst : Register) (value : Word) :
    (dispatch (GeneratedArm64Mov.code .movImm) aux width dst value origins state).map
      (observe origins) = some (Reference.AArch64.step (.moveImmediate width dst value) (image origins state)) := by
  change some (observe origins (immediate width dst value state)) = _
  rw [immediate_refines]

theorem dispatch_keep (origins : Origins) (state : State) (i : KeepInstruction)
    (lane0 lane1 lane3 : Byte) :
    (dispatch (GeneratedArm64DispatchSingleton.code .movk)
      (Arm64Movk.packedAux (BitVec.ofNat 32 (16 * i.column.val)) lane0 lane1 lane3)
      i.width i.dst (i.immediate.setWidth 64) origins state).map (observe origins) =
      some (Reference.AArch64.step (.keep i) (image origins state)) := by
  change ((Arm64Movk.decodeShift (GeneratedArm64Aux.b2
    (Arm64Movk.packedAux (BitVec.ofNat 32 (16 * i.column.val)) lane0 lane1 lane3)).toNat).map
    (fun shift => keep shift i.width i.dst (i.immediate.setWidth 64) origins state)).map
    (observe origins) = _
  rw [Arm64Movk.packed_column]
  exact congrArg some (keep_refines origins state i)

/-- Native GPR/ZR operands use the architectural five-bit destination domain. -/
theorem destination_separate_sp (dst : Register) :
    (Arm64Register.registerCode dst).toNat ≠ GeneratedArm64RegDispatch.stackNumber := by
  simp only [Arm64Register.registerCode, BitVec.toNat_ofNat]
  change dst.val % 256 ≠ 32
  rw [Nat.mod_eq_of_lt (by omega)]
  omega

/-- Normalization records opcode/field identities and architectural MOVK
column validity. Component handler equality is derived by the step theorem. -/
inductive Binding : Nat → BitVec 32 → Width → Register → Word → Reference.AArch64.Instruction → Prop where
  | nop (aux : BitVec 32) (width : Width) (dst : Register) (value : Word) :
      Binding (GeneratedArm64DispatchSingleton.code .nop) aux width dst value .nop
  | immediate (aux : BitVec 32) (width : Width) (dst : Register) (value : Word) :
      Binding (GeneratedArm64Mov.code .movImm) aux width dst value (.moveImmediate width dst value)
  | keep (i : KeepInstruction) (lane0 lane1 lane3 : Byte) :
      Binding (GeneratedArm64DispatchSingleton.code .movk)
        (Arm64Movk.packedAux (BitVec.ofNat 32 (16 * i.column.val)) lane0 lane1 lane3)
        i.width i.dst (i.immediate.setWidth 64) (.keep i)

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst value instruction) :
    (dispatch code aux width dst value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | nop => exact dispatch_nop origins state _ _ _ _
  | immediate => exact dispatch_immediate origins state _ _ _ _
  | keep i lane0 lane1 lane3 => exact dispatch_keep origins state i lane0 lane1 lane3

end KProgFormal.Refinement.Arm64RawRegister
#print axioms KProgFormal.Refinement.Arm64RawRegister.read_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.write_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.write_zero_register
#print axioms KProgFormal.Refinement.Arm64RawRegister.write_tag_frame
#print axioms KProgFormal.Refinement.Arm64RawRegister.advance_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.nop_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.immediate_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.keep_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.dispatch_nop
#print axioms KProgFormal.Refinement.Arm64RawRegister.dispatch_immediate
#print axioms KProgFormal.Refinement.Arm64RawRegister.dispatch_keep

#print axioms KProgFormal.Refinement.Arm64RawRegister.destination_separate_sp
#print axioms KProgFormal.Refinement.Arm64RawRegister.step_refines

namespace KProgFormal.Refinement.Arm64RawRegister.Multiply
open Reference
open Reference.AArch64 (Register Width)

/-- The C multiply macro narrows UDIV sources at WIDTH and retains the full
materialized word for every other operation. All operands precede writeback. -/
def body (op : GeneratedArm64Mul.Mul) (width : Width) (dst lhs rhs addend : Register)
    (origins : Origins) (state : State) : Transition State :=
  let inputWidth := if GeneratedArm64Mul.code op = GeneratedArm64Mul.code .udiv
    then Arm64Register.handlerWidth width else .w64
  let lhsValue := GeneratedArm64Width.narrow (readRegister origins state lhs) inputWidth
  let rhsValue := GeneratedArm64Width.narrow (readRegister origins state rhs) inputWidth
  let result := GeneratedArm64Mul.value op lhsValue rhsValue (readRegister origins state addend)
  ⟨advance (writeRegister state dst result width), [], none⟩

theorem body_projects (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs addend : Register) (origins : Origins) (state : State) :
    observe origins (body op width dst lhs rhs addend origins state) =
      Arm64Mul.rawStep op width dst lhs rhs addend (image origins state) := by
  simp only [body, observe, advance_refines, write_refines, read_refines,
    Arm64Mul.rawStep, Arm64Register.read_refines, Arm64Register.write_refines]
  rfl

theorem body_refines (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs addend : Register) (origins : Origins) (state : State)
    (valid : Arm64Mul.nativeWidth op width) :
    observe origins (body op width dst lhs rhs addend origins state) =
      Reference.AArch64.step (.mul (Arm64Mul.instruction op width dst lhs rhs addend))
        (image origins state) := by
  rw [body_projects, Arm64Mul.raw_step_refines op width dst lhs rhs addend _ valid]

/-- The raw-register leading and multiply selector keep their production order.
Additional ALU/shift gates retain the established numerical leading relation. -/
def dispatch (code : Nat) (aux : BitVec 32) (width : Width)
    (dst lhs rhs addend : Register) (value : Word) (origins : Origins) (state : State) :
    Option (Transition State) :=
  match Arm64RawRegister.dispatch code aux width dst value origins state with
  | some result => some result
  | none => (Arm64Mul.decodeOpcode code).map (fun op => body op width dst lhs rhs addend origins state)

theorem prefix_passes (op : GeneratedArm64Mul.Mul) (aux : BitVec 32) (width : Width)
    (dst : Register) (value : Word) (origins : Origins) (state : State) :
    Arm64RawRegister.dispatch (GeneratedArm64Mul.code op) aux width dst value origins state = none := by
  cases op <;> rfl

theorem reached (op : GeneratedArm64Mul.Mul) (aux : BitVec 32) (width : Width)
    (dst lhs rhs addend : Register) (value : Word) (origins : Origins) (state : State) :
    dispatch (GeneratedArm64Mul.code op) aux width dst lhs rhs addend value origins state =
      some (body op width dst lhs rhs addend origins state) := by
  simp only [dispatch, prefix_passes, Arm64Mul.decode_code]
  rfl

/-- Equality with the existing complete numerical dispatcher through its
multiply arm derives every earlier gate's fallthrough and every field codec. -/
theorem production_dispatch (op : GeneratedArm64Mul.Mul) (aux : BitVec 32) (width : Width)
    (dst lhs rhs addend : Register) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Mul.code op) aux width dst lhs rhs addend value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughMultiply (GeneratedArm64Mul.code op) aux width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode lhs)
      (Arm64Register.registerCode rhs) (Arm64Register.registerCode addend)
      value sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.multiply_reached, Arm64Dispatcher.multiply_body_typed]
  exact congrArg some (body_projects op width dst lhs rhs addend origins state)

theorem dispatch_refines (op : GeneratedArm64Mul.Mul) (aux : BitVec 32) (width : Width)
    (dst lhs rhs addend : Register) (value : Word) (origins : Origins) (state : State)
    (valid : Arm64Mul.nativeWidth op width) :
    (dispatch (GeneratedArm64Mul.code op) aux width dst lhs rhs addend value origins state).map
      (observe origins) = some (Reference.AArch64.step
        (.mul (Arm64Mul.instruction op width dst lhs rhs addend)) (image origins state)) := by
  rw [reached]
  exact congrArg some (body_refines op width dst lhs rhs addend origins state valid)

theorem earlier_step (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst lhs rhs addend : Register) (value : Word)
    (instruction : Reference.AArch64.Instruction)
    (binding : Arm64RawRegister.Binding code aux width dst value instruction) :
    (dispatch code aux width dst lhs rhs addend value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have result := Arm64RawRegister.step_refines origins state code aux width dst value instruction binding
  unfold dispatch
  cases leading : Arm64RawRegister.dispatch code aux width dst value origins state with
  | none => simp [leading] at result
  | some output => simpa only [leading] using result

/-- Width validity describes the native instruction domain, including X-only
long/high products. The constructors carry operand/opcode identities. -/
inductive Binding : Nat → BitVec 32 → Width → Register → Register → Register → Register →
    Word → Reference.AArch64.Instruction → Prop where
  | leading (code : Nat) (aux : BitVec 32) (width : Width) (dst lhs rhs addend : Register)
      (value : Word) (instruction : Reference.AArch64.Instruction)
      (binding : Arm64RawRegister.Binding code aux width dst value instruction) :
      Binding code aux width dst lhs rhs addend value instruction
  | multiply (op : GeneratedArm64Mul.Mul) (aux : BitVec 32) (width : Width)
      (dst lhs rhs addend : Register) (value : Word) (valid : Arm64Mul.nativeWidth op width) :
      Binding (GeneratedArm64Mul.code op) aux width dst lhs rhs addend value
        (.mul (Arm64Mul.instruction op width dst lhs rhs addend))

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst lhs rhs addend : Register) (value : Word)
    (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst lhs rhs addend value instruction) :
    (dispatch code aux width dst lhs rhs addend value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading code aux width dst lhs rhs addend value instruction bound =>
      exact earlier_step origins state code aux width dst lhs rhs addend value instruction bound
  | multiply op aux width dst lhs rhs addend value valid =>
      exact dispatch_refines op aux width dst lhs rhs addend value origins state valid

/-- MUL, UMULL, UDIV and UMULH retain freedom in the unused accumulator. -/
theorem unused_accumulator (op : GeneratedArm64Mul.Mul) (width : Width)
    (dst lhs rhs addend other : Register) (origins : Origins) (state : State)
    (unused : op = .mul ∨ op = .umull ∨ op = .udiv ∨ op = .umulh) :
    body op width dst lhs rhs addend origins state = body op width dst lhs rhs other origins state := by
  rcases unused with rfl | rfl | rfl | rfl <;> rfl

/-- The actual dispatcher accepts every unused SRC3 byte, including NONE255,
while the native instruction retains its architectural zero accumulator. -/
theorem production_unused_addend (op : GeneratedArm64Mul.Mul) (aux : BitVec 32) (width : Width)
    (dst lhs rhs addend : Register) (source3 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State)
    (unused : op = .mul ∨ op = .umull ∨ op = .udiv ∨ op = .umulh) :
    (dispatch (GeneratedArm64Mul.code op) aux width dst lhs rhs addend value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughMultiply (GeneratedArm64Mul.code op) aux width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode lhs)
      (Arm64Register.registerCode rhs) source3 value sourceScalar sourceStack (image origins state) := by
  rw [Arm64Dispatcher.multiply_reached]
  rw [Arm64Dispatcher.multiply_ignores_accumulator op width
    (Arm64Register.registerCode dst) (Arm64Register.registerCode lhs)
    (Arm64Register.registerCode rhs) source3 (Arm64Register.registerCode addend) (image origins state) unused]
  rw [Arm64Dispatcher.multiply_body_typed, reached]
  exact congrArg some (body_projects op width dst lhs rhs addend origins state)

end KProgFormal.Refinement.Arm64RawRegister.Multiply
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.body_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.body_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.prefix_passes
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.production_dispatch
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.dispatch_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.earlier_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.step_refines

#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.unused_accumulator
#print axioms KProgFormal.Refinement.Arm64RawRegister.Multiply.production_unused_addend
namespace KProgFormal.Refinement.Arm64RawRegister.ShiftUnary
open Reference
open Reference.AArch64 (Register Width ShiftKind)

/-- SHIFT consumes the complete AUX word in the C switch. -/
def kindAux (kind : ShiftKind) : BitVec 32 :=
  BitVec.ofNat 32 (GeneratedArm64ShiftDecode.code (Arm64Shift.shiftCode kind))

theorem whole_kind (kind : ShiftKind) :
    Arm64Shift.decodeKind (kindAux kind).toNat = some kind := by cases kind <;> rfl

theorem numeric_kind (kind : ShiftKind) :
    kindAux kind = Arm64Shift.nativeAux kind := by cases kind <;> rfl

def shiftBody (op : GeneratedArm64ImmOperand.ImmOp) (kind : ShiftKind) (width : Width)
    (dst src count : Register) (value : Word) (origins : Origins) (state : State) : Transition State :=
  let amount := if GeneratedArm64ImmOperand.immediate op then value else readRegister origins state count
  let result := GeneratedArm64Shift.value (Arm64Shift.shiftCode kind)
    (readRegister origins state src) amount (Arm64Register.handlerWidth width)
  ⟨advance (writeRegister state dst result width), [], none⟩

theorem shift_projects (op : GeneratedArm64ImmOperand.ImmOp) (kind : ShiftKind) (width : Width)
    (dst src count : Register) (value : Word) (origins : Origins) (state : State) :
    observe origins (shiftBody op kind width dst src count value origins state) =
      Arm64Shift.rawStep op kind width dst src count value (image origins state) := by
  simp only [shiftBody, observe, advance_refines, write_refines, read_refines,
    Arm64Shift.rawStep, Arm64Register.read_refines, Arm64Register.write_refines]
  rfl

/-- Source modifier byte1 and amount byte2 precede unary result/writeback. -/
def unaryBody (op : GeneratedArm64Unary.Unary) (aux : BitVec 32) (width : Width)
    (dst src : Register) (origins : Origins) (state : State) : Transition State :=
  let modified := GeneratedArm64Mod.value
    (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
    (readRegister origins state src) ((GeneratedArm64Aux.b2 aux).setWidth 64)
    (Arm64Register.handlerWidth width)
  let result := GeneratedArm64Unary.value op modified (Arm64Register.handlerWidth width)
  ⟨advance (writeRegister state dst result width), [], none⟩

theorem unary_projects (op : GeneratedArm64Unary.Unary) (aux : BitVec 32) (width : Width)
    (dst src : Register) (origins : Origins) (state : State) :
    observe origins (unaryBody op aux width dst src origins state) =
      Arm64Dispatcher.unaryBody op aux width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (image origins state) := by
  simp only [unaryBody, observe, advance_refines, write_refines, read_refines,
    Arm64Dispatcher.unaryBody, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write,
    Arm64Register.read_refines, Arm64Register.write_refines]
  rfl

/-- Covered disjoint opcode gates extend the preceding eleven-operation lift.
Production reachability is derived separately for each added opcode. -/
def dispatch (code : Nat) (aux : BitVec 32) (width : Width)
    (dst src count addend : Register) (value : Word) (origins : Origins) (state : State) :
    Option (Transition State) :=
  match Multiply.dispatch code aux width dst src count addend value origins state with
  | some result => some result
  | none => match Arm64Shift.decodeOpcode code with
    | some op => (Arm64Shift.decodeKind aux.toNat).map
        (fun kind => shiftBody op kind width dst src count value origins state)
    | none => (Arm64Shift.Unary.decodeOpcode code).map
        (fun op => unaryBody op aux width dst src origins state)

theorem before_shift (immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src count addend : Register) (value : Word) (origins : Origins) (state : State) :
    Multiply.dispatch (Arm64Dispatcher.shiftOpcode immediate) aux width dst src count addend value origins state = none := by
  cases immediate <;> rfl

theorem shift_reached (immediate : Bool) (kind : ShiftKind) (width : Width)
    (dst src count addend : Register) (value : Word) (origins : Origins) (state : State) :
    dispatch (Arm64Dispatcher.shiftOpcode immediate) (kindAux kind) width dst src count addend value origins state =
      some (shiftBody (if immediate then .shiftImm else .shiftReg) kind width dst src count value origins state) := by
  have decoded : Arm64Shift.decodeOpcode (Arm64Dispatcher.shiftOpcode immediate) =
      some (if immediate then .shiftImm else .shiftReg) := by cases immediate <;> rfl
  simp only [dispatch, before_shift, decoded, whole_kind, Option.map_some]
  rfl

theorem unary_reached (op : GeneratedArm64Unary.Unary) (aux : BitVec 32) (width : Width)
    (dst src count addend : Register) (value : Word) (origins : Origins) (state : State) :
    dispatch (GeneratedArm64Unary.code op) aux width dst src count addend value origins state =
      some (unaryBody op aux width dst src origins state) := by
  have leading : Multiply.dispatch (GeneratedArm64Unary.code op) aux width dst src count addend value origins state = none := by
    cases op <;> rfl
  have shift : Arm64Shift.decodeOpcode (GeneratedArm64Unary.code op) = none := by cases op <;> rfl
  have known : Arm64Shift.Unary.decodeOpcode (GeneratedArm64Unary.code op) = some op := by cases op <;> rfl
  simp only [dispatch, leading, shift, known, Option.map_some]
  rfl

/-- Actual ordered production gates, including arbitrary unused SRC3. -/
theorem production_shift (immediate : Bool) (kind : ShiftKind) (width : Width)
    (dst src count addend : Register) (src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) :
    (dispatch (Arm64Dispatcher.shiftOpcode immediate) (kindAux kind) width dst src count addend value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughUnary (Arm64Dispatcher.shiftOpcode immediate) (kindAux kind) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode count)
      src3 value sourceScalar sourceStack (image origins state) := by
  have reached := Arm64Dispatcher.shift_reached immediate (kindAux kind) width
    (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode count)
    value sourceScalar sourceStack (image origins state)
  rw [numeric_kind, Arm64Shift.native_kind] at reached
  simp only [Arm64Dispatcher.dispatchThroughUnary, Arm64Dispatcher.dispatchThroughMultiply,
    numeric_kind, reached, Arm64Dispatcher.shift_body_typed]
  rw [← numeric_kind, shift_reached]
  exact congrArg some (shift_projects _ kind width dst src count value origins state)

/-- Immediate SHIFT keeps every unused count byte, including NONE255. -/
theorem production_immediate_count (kind : ShiftKind) (width : Width)
    (dst src count addend : Register) (src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) :
    (dispatch (Arm64Dispatcher.shiftOpcode true) (kindAux kind) width dst src count addend value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughUnary (Arm64Dispatcher.shiftOpcode true) (kindAux kind) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
      sourceScalar sourceStack (image origins state) := by
  have reached := Arm64Dispatcher.shift_reached true (kindAux kind) width
    (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 value sourceScalar sourceStack (image origins state)
  rw [numeric_kind, Arm64Shift.native_kind] at reached
  simp only [Arm64Dispatcher.dispatchThroughUnary, Arm64Dispatcher.dispatchThroughMultiply, numeric_kind, reached, Option.map, ↓reduceIte]
  rw [Arm64Dispatcher.shift_immediate_ignores_count kind width _ _ src2 (Arm64Register.registerCode count),
    Arm64Dispatcher.shift_body_typed, ← numeric_kind, shift_reached]
  exact congrArg some (shift_projects .shiftImm kind width dst src count value origins state)

theorem production_unary (op : GeneratedArm64Unary.Unary) (aux : BitVec 32) (width : Width)
    (dst src count addend : Register) (src2 src3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Unary.code op) aux width dst src count addend value origins state).map (observe origins) =
    Arm64Dispatcher.dispatchThroughUnary (GeneratedArm64Unary.code op) aux width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) src2 src3 value
      sourceScalar sourceStack (image origins state) := by
  rw [unary_reached, Arm64Dispatcher.unary_reached]
  exact congrArg some (unary_projects op aux width dst src origins state)

theorem immediate_refines (width : Width) (kind : ShiftKind) (amount : Fin width.bits)
    (dst src count addend : Register) (origins : Origins) (state : State) :
    (dispatch (Arm64Dispatcher.shiftOpcode true) (kindAux kind) width dst src count addend
      (BitVec.ofNat 64 amount.val) origins state).map (observe origins) =
      some (Reference.AArch64.step (.shift (.immediate width kind amount dst src)) (image origins state)) := by
  rw [production_shift true kind width dst src count addend 255 _ false false origins state, numeric_kind]
  simp only [Arm64Dispatcher.dispatchThroughUnary, Arm64Dispatcher.dispatchThroughMultiply,
    Arm64Dispatcher.shift_immediate_refines]

theorem register_refines (width : Width) (kind : ShiftKind) (dst src count addend : Register)
    (value : Word) (origins : Origins) (state : State) :
    (dispatch (Arm64Dispatcher.shiftOpcode false) (kindAux kind) width dst src count addend value origins state).map
      (observe origins) = some (Reference.AArch64.step (.shift (.register width kind dst src count)) (image origins state)) := by
  rw [production_shift false kind width dst src count addend 255 _ false false origins state, numeric_kind]
  simp only [Arm64Dispatcher.dispatchThroughUnary, Arm64Dispatcher.dispatchThroughMultiply,
    Arm64Dispatcher.shift_register_refines]

theorem invert_refines (width : Width) (kind : ShiftKind) (amount : Fin width.bits)
    (dst src count addend : Register) (value : Word) (lane0 lane3 : Byte) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Unary.code .mvn)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
      width dst src count addend value origins state).map (observe origins) =
      some (Reference.AArch64.step (.shift (.invert width kind amount dst src)) (image origins state)) := by
  rw [production_unary .mvn _ width dst src count addend 255 255 value false false origins state]
  exact Arm64Dispatcher.unary_invert_refines width kind amount dst src 255 255 lane0 lane3 value false false _

theorem negate_refines (width : Width) (kind : Fin 3) (amount : Fin width.bits)
    (dst src count addend : Register) (value : Word) (lane0 lane3 : Byte) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Unary.code .neg)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier (Reference.AArch64.arithmeticShift kind))
        (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src count addend value origins state).map (observe origins) =
      some (Reference.AArch64.step (.shift (.negate width kind amount dst src)) (image origins state)) := by
  rw [production_unary .neg _ width dst src count addend 255 255 value false false origins state]
  exact Arm64Dispatcher.unary_negate_refines width kind amount dst src 255 255 lane0 lane3 value false false _

theorem unmodified_refines (op : GeneratedArm64Unary.Unary) (width : Width)
    (dst src count addend : Register) (value : Word) (amount lane0 lane3 : Byte) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Unary.code op) (Arm64Shift.Unary.packedAux .none amount lane0 lane3)
      width dst src count addend value origins state).map (observe origins) =
      some (Reference.AArch64.step (.shift (if op = .mvn then
        .invert width .lsl ⟨0, by cases width <;> decide⟩ dst src else
        .negate width 0 ⟨0, by cases width <;> decide⟩ dst src)) (image origins state)) := by
  rw [production_unary op _ width dst src count addend 255 255 value false false origins state]
  exact Arm64Dispatcher.unary_unmodified_refines op width dst src 255 255 amount lane0 lane3 value false false _

theorem earlier_step (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src count addend : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Multiply.Binding code aux width dst src count addend value instruction) :
    (dispatch code aux width dst src count addend value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have result := Multiply.step_refines origins state code aux width dst src count addend value instruction binding
  unfold dispatch
  cases leading : Multiply.dispatch code aux width dst src count addend value origins state with
  | none => simp [leading] at result
  | some output => simpa only [leading] using result

/-- Native opcode, operand, whole SHIFT AUX and unary modifier identities.
All shift amount bounds describe encoded native instruction fields. -/
inductive Binding : Nat → BitVec 32 → Width → Register → Register → Register → Register →
    Word → Reference.AArch64.Instruction → Prop where
  | leading (code : Nat) (aux : BitVec 32) (width : Width) (dst src count addend : Register)
      (value : Word) (instruction : Reference.AArch64.Instruction)
      (binding : Multiply.Binding code aux width dst src count addend value instruction) :
      Binding code aux width dst src count addend value instruction
  | immediate (width : Width) (kind : ShiftKind) (amount : Fin width.bits) (dst src count addend : Register) :
      Binding (Arm64Dispatcher.shiftOpcode true) (kindAux kind) width dst src count addend
        (BitVec.ofNat 64 amount.val) (.shift (.immediate width kind amount dst src))
  | register (width : Width) (kind : ShiftKind) (dst src count addend : Register) (value : Word) :
      Binding (Arm64Dispatcher.shiftOpcode false) (kindAux kind) width dst src count addend value
        (.shift (.register width kind dst src count))
  | invert (width : Width) (kind : ShiftKind) (amount : Fin width.bits) (dst src count addend : Register)
      (value : Word) (lane0 lane3 : Byte) :
      Binding (GeneratedArm64Unary.code .mvn)
        (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
        width dst src count addend value (.shift (.invert width kind amount dst src))
  | negate (width : Width) (kind : Fin 3) (amount : Fin width.bits) (dst src count addend : Register)
      (value : Word) (lane0 lane3 : Byte) :
      Binding (GeneratedArm64Unary.code .neg)
        (Arm64Shift.Unary.packedAux (Arm64Shift.modifier (Reference.AArch64.arithmeticShift kind))
          (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src count addend value
        (.shift (.negate width kind amount dst src))
  | unmodified (op : GeneratedArm64Unary.Unary) (width : Width) (dst src count addend : Register)
      (value : Word) (amount lane0 lane3 : Byte) :
      Binding (GeneratedArm64Unary.code op) (Arm64Shift.Unary.packedAux .none amount lane0 lane3)
        width dst src count addend value (.shift (if op = .mvn then
          .invert width .lsl ⟨0, by cases width <;> decide⟩ dst src else
          .negate width 0 ⟨0, by cases width <;> decide⟩ dst src))

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src count addend : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst src count addend value instruction) :
    (dispatch code aux width dst src count addend value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading code aux width dst src count addend value instruction bound =>
      exact earlier_step origins state code aux width dst src count addend value instruction bound
  | immediate width kind amount dst src count addend =>
      exact immediate_refines width kind amount dst src count addend origins state
  | register width kind dst src count addend value =>
      exact register_refines width kind dst src count addend value origins state
  | invert width kind amount dst src count addend value lane0 lane3 =>
      exact invert_refines width kind amount dst src count addend value lane0 lane3 origins state
  | negate width kind amount dst src count addend value lane0 lane3 =>
      exact negate_refines width kind amount dst src count addend value lane0 lane3 origins state
  | unmodified op width dst src count addend value amount lane0 lane3 =>
      exact unmodified_refines op width dst src count addend value amount lane0 lane3 origins state

end KProgFormal.Refinement.Arm64RawRegister.ShiftUnary

#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.whole_kind
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.numeric_kind
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.shift_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.unary_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.before_shift
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.shift_reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.unary_reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.production_shift
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.production_immediate_count
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.production_unary
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.immediate_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.register_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.invert_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.negate_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.unmodified_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.earlier_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.ShiftUnary.step_refines
namespace KProgFormal.Refinement.Arm64RawRegister.ExtractReverse
open Reference
open Reference.AArch64 (Register Width ExtendBits)

/-- EXTR narrows both incoming materialized operands at W/X width. REV/SXT
consume full64-bit words and retain their generated scalar writeback. -/
def body (op : GeneratedArm64Extrev.Extrev) (width : Width) (dst src src2 : Register)
    (value : Word) (origins : Origins) (state : State) : Transition State :=
  let inputWidth := if GeneratedArm64Extrev.code op = GeneratedArm64Extrev.code .extr
    then Arm64Register.handlerWidth width else .w64
  let lhs := GeneratedArm64Width.narrow (readRegister origins state src) inputWidth
  let rhs := GeneratedArm64Width.narrow (readRegister origins state src2) inputWidth
  let result := GeneratedArm64Extrev.value op lhs rhs value (Arm64Register.handlerWidth width)
  ⟨advance (writeRegister state dst result width), [], none⟩

theorem body_projects (op : GeneratedArm64Extrev.Extrev) (width : Width)
    (dst src src2 : Register) (value : Word) (origins : Origins) (state : State) :
    observe origins (body op width dst src src2 value origins state) =
      Arm64Extrev.rawStep op width dst src src2 value (image origins state) := by
  simp only [body, observe, advance_refines, write_refines, read_refines,
    Arm64Extrev.rawStep, Arm64Register.read_refines, Arm64Register.write_refines]
  rfl

/-- CNEG evaluates the incoming NZCV condition and captures SRC before writeback. -/
def conditionalBody (predicate : Arm64Cond) (width : Width) (dst src : Register)
    (origins : Origins) (state : State) : Transition State :=
  let result := GeneratedArm64Cneg.value .cneg
    (generatedArm64Cond (Arm64Condition.flags state.raw.flags) predicate)
    (readRegister origins state src) (Arm64Register.handlerWidth width)
  ⟨advance (writeRegister state dst result width), [], none⟩

theorem conditional_projects (predicate : Arm64Cond) (width : Width) (dst src : Register)
    (origins : Origins) (state : State) :
    observe origins (conditionalBody predicate width dst src origins state) =
      Arm64Dispatcher.conditionalNegateBody predicate width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (image origins state) := by
  simp only [conditionalBody, observe, advance_refines, write_refines, read_refines,
    Arm64Dispatcher.conditionalNegateBody, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write,
    Arm64Register.read_refines, Arm64Register.write_refines]
  rfl

/-- The CNEG and EXTR/REV/SXT production gates follow the preceding raw lift. -/
def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register)
    (value : Word) (origins : Origins) (state : State) : Option (Transition State) :=
  match ShiftUnary.dispatch code aux width dst src src2 src3 value origins state with
  | some result => some result
  | none => if code = GeneratedArm64Cneg.code .cneg then
      (Arm64Condition.decode aux.toNat).map (fun predicate => conditionalBody predicate width dst src origins state)
    else (Arm64Extrev.decodeOpcode code).map (fun op => body op width dst src src2 value origins state)

theorem before_extrev (op : GeneratedArm64Extrev.Extrev) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Register) (value : Word) (origins : Origins) (state : State) :
    ShiftUnary.dispatch (GeneratedArm64Extrev.code op) aux width dst src src2 src3 value origins state = none := by
  cases op <;> rfl

theorem reached (op : GeneratedArm64Extrev.Extrev) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Register) (value : Word) (origins : Origins) (state : State) :
    dispatch (GeneratedArm64Extrev.code op) aux width dst src src2 src3 value origins state =
      some (body op width dst src src2 value origins state) := by
  have separate : GeneratedArm64Extrev.code op ≠ GeneratedArm64Cneg.code .cneg := by cases op <;> decide
  simp only [dispatch, before_extrev, if_neg separate, Arm64Extrev.decode_code]
  rfl

theorem conditional_reached (predicate : Arm64Cond) (width : Width) (dst src src2 src3 : Register)
    (value : Word) (origins : Origins) (state : State) :
    dispatch (GeneratedArm64Cneg.code .cneg) (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate))
      width dst src src2 src3 value origins state = some (conditionalBody predicate width dst src origins state) := by
  have leading : ShiftUnary.dispatch (GeneratedArm64Cneg.code .cneg)
      (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width dst src src2 src3 value origins state = none := rfl
  have known : Arm64Condition.decode (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)).toNat = some predicate := by
    cases predicate <;> rfl
  simp only [dispatch, leading, if_pos rfl, known]
  rfl

/-- Actual numerical production dispatcher equality derives preceding gates,
concrete register codecs and full state projection. SRC3 retains every byte. -/
theorem production_extrev (op : GeneratedArm64Extrev.Extrev) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Register) (unused3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Extrev.code op) aux width dst src src2 src3 value origins state).map (observe origins) =
      Arm64Dispatcher.dispatchThroughExtrev (GeneratedArm64Extrev.code op) aux width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode src2)
        unused3 value sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.extrev_reached, Arm64Dispatcher.extrev_body_typed]
  exact congrArg some (body_projects op width dst src src2 value origins state)

/-- REV/REV16/SXT ignore all SRC2/SRC3/IMM values, including NONE255. -/
theorem production_unused_fields (op : GeneratedArm64Extrev.Extrev) (aux : BitVec 32) (width : Width)
    (dst src src2 src3 : Register) (unused2 unused3 : Byte) (value otherValue : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) (unused : op ≠ .extr) :
    (dispatch (GeneratedArm64Extrev.code op) aux width dst src src2 src3 value origins state).map (observe origins) =
      Arm64Dispatcher.dispatchThroughExtrev (GeneratedArm64Extrev.code op) aux width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) unused2 unused3 otherValue
        sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.extrev_reached,
    Arm64Dispatcher.extrev_unused_fields op width _ _ unused2 (Arm64Register.registerCode src2) otherValue value _ unused,
    Arm64Dispatcher.extrev_body_typed]
  exact congrArg some (body_projects op width dst src src2 value origins state)

theorem production_conditional (predicate : Arm64Cond) (width : Width) (dst src src2 src3 : Register)
    (unused2 unused3 : Byte) (value : Word) (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Cneg.code .cneg) (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate))
      width dst src src2 src3 value origins state).map (observe origins) =
    Arm64Dispatcher.dispatchThroughExtrev (GeneratedArm64Cneg.code .cneg)
      (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) unused2 unused3 value sourceScalar sourceStack (image origins state) := by
  have known : Arm64Condition.decode (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)).toNat = some predicate := by
    cases predicate <;> rfl
  rw [conditional_reached, Arm64Dispatcher.conditional_negate_reached, known]
  exact congrArg some (conditional_projects predicate width dst src origins state)

theorem extract_refines (width : Width) (amount : Fin width.bits) (dst src src2 src3 : Register)
    (aux : BitVec 32) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Extrev.code .extr) aux width dst src src2 src3 (BitVec.ofNat 64 amount.val)
      origins state).map (observe origins) =
      some (Reference.AArch64.step (.extrev (.extract width amount dst src src2)) (image origins state)) := by
  rw [reached]
  change some (observe origins (body .extr width dst src src2 (BitVec.ofNat 64 amount.val) origins state)) = _
  rw [body_projects, Arm64Extrev.raw_extract_refines]

theorem reverse_refines (width : Width) (halfwords : Bool) (dst src src2 src3 : Register)
    (aux : BitVec 32) (value : Word) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Extrev.code (if halfwords then .rev16 else .rev)) aux width dst src src2 src3
      value origins state).map (observe origins) =
      some (Reference.AArch64.step (.extrev (.reverse width halfwords dst src)) (image origins state)) := by
  rw [reached]
  change some (observe origins (body (if halfwords then .rev16 else .rev) width dst src src2 value origins state)) = _
  rw [body_projects, Arm64Extrev.raw_reverse_refines]

theorem extend_refines (width : Width) (source : ExtendBits) (dst src src2 src3 : Register)
    (aux : BitVec 32) (value : Word) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Extrev.code (Arm64Extrev.extendOpcode source)) aux width dst src src2 src3
      value origins state).map (observe origins) =
      some (Reference.AArch64.step (.extrev (.extend width source dst src)) (image origins state)) := by
  rw [reached]
  change some (observe origins (body (Arm64Extrev.extendOpcode source) width dst src src2 value origins state)) = _
  rw [body_projects, Arm64Extrev.raw_extend_refines]

theorem conditional_refines (predicate : Arm64Cond) (width : Width) (dst src src2 src3 : Register)
    (value : Word) (origins : Origins) (state : State) (valid : predicate ≠ .al) :
    (dispatch (GeneratedArm64Cneg.code .cneg) (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate))
      width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step (.select width .negate dst src src
        (Arm64Condition.nativeCode (Arm64Select.inverse predicate))) (image origins state)) := by
  rw [production_conditional predicate width dst src src2 src3 255 255 value false false origins state]
  exact Arm64Dispatcher.conditional_negate_refines predicate width dst src 255 255 value false false _ valid

theorem earlier_step (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src src2 src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : ShiftUnary.Binding code aux width dst src src2 src3 value instruction) :
    (dispatch code aux width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have result := ShiftUnary.step_refines origins state code aux width dst src src2 src3 value instruction binding
  unfold dispatch
  cases leading : ShiftUnary.dispatch code aux width dst src src2 src3 value origins state with
  | none => simp [leading] at result
  | some output => simpa only [leading] using result

/-- Native field and condition identities extend the prior fifteen operations.
EXTR uses its encoded immediate domain; CNEG keeps the native alias condition. -/
inductive Binding : Nat → BitVec 32 → Width → Register → Register → Register → Register →
    Word → Reference.AArch64.Instruction → Prop where
  | leading (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register)
      (value : Word) (instruction : Reference.AArch64.Instruction)
      (binding : ShiftUnary.Binding code aux width dst src src2 src3 value instruction) :
      Binding code aux width dst src src2 src3 value instruction
  | extract (width : Width) (amount : Fin width.bits) (dst src src2 src3 : Register) (aux : BitVec 32) :
      Binding (GeneratedArm64Extrev.code .extr) aux width dst src src2 src3 (BitVec.ofNat 64 amount.val)
        (.extrev (.extract width amount dst src src2))
  | reverse (width : Width) (halfwords : Bool) (dst src src2 src3 : Register) (aux : BitVec 32) (value : Word) :
      Binding (GeneratedArm64Extrev.code (if halfwords then .rev16 else .rev)) aux width dst src src2 src3 value
        (.extrev (.reverse width halfwords dst src))
  | extend (width : Width) (source : ExtendBits) (dst src src2 src3 : Register) (aux : BitVec 32) (value : Word) :
      Binding (GeneratedArm64Extrev.code (Arm64Extrev.extendOpcode source)) aux width dst src src2 src3 value
        (.extrev (.extend width source dst src))
  | conditional (predicate : Arm64Cond) (width : Width) (dst src src2 src3 : Register) (value : Word)
      (valid : predicate ≠ .al) :
      Binding (GeneratedArm64Cneg.code .cneg) (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate))
        width dst src src2 src3 value (.select width .negate dst src src
          (Arm64Condition.nativeCode (Arm64Select.inverse predicate)))

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src src2 src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst src src2 src3 value instruction) :
    (dispatch code aux width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading code aux width dst src src2 src3 value instruction bound =>
      exact earlier_step origins state code aux width dst src src2 src3 value instruction bound
  | extract width amount dst src src2 src3 aux => exact extract_refines width amount dst src src2 src3 aux origins state
  | reverse width halfwords dst src src2 src3 aux value => exact reverse_refines width halfwords dst src src2 src3 aux value origins state
  | extend width source dst src src2 src3 aux value => exact extend_refines width source dst src src2 src3 aux value origins state
  | conditional predicate width dst src src2 src3 value valid => exact conditional_refines predicate width dst src src2 src3 value origins state valid

end KProgFormal.Refinement.Arm64RawRegister.ExtractReverse

#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.body_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.conditional_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.before_extrev
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.conditional_reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.production_extrev
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.production_unused_fields
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.production_conditional
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.extract_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.reverse_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.extend_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.conditional_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.earlier_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.ExtractReverse.step_refines
namespace KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect
open Reference
open Reference.AArch64 (Register Gpr Width SelectElse)

/-- The GPR/ZR domain of READ_REG_PTR and REG_TAG captures the raw word and
its byte tag before any destination update. Native field31 supplies scalar0. -/
def readTagged (state : State) (src : Register) : Word × Byte :=
  match GeneratedArm64RegDispatch.cellOf (Arm64Register.registerCode src) with
  | some index =>
      let cell : Gpr := ⟨index % 31, Nat.mod_lt _ (by decide)⟩
      (state.raw.gpr cell, state.tags cell)
  | none => (0, 0)

theorem read_tagged_materializes (origins : Origins) (state : State) (src : Register) :
    materialize origins (readTagged state src).1 (readTagged state src).2 = readRegister origins state src := by
  cases cell : GeneratedArm64RegDispatch.cellOf (Arm64Register.registerCode src) <;>
    simp [readTagged, readRegister, cell, materialize]

/-- The native GPR/ZR arm of WRITE_REG_PTR_TAG retains the supplied raw word
and tag, using the concrete generated destination cell/writable selector. -/
def writeTagged (state : State) (dst : Register) (word : Word) (tag : Byte) : State :=
  let selected := fun r : Gpr => GeneratedArm64RegPresence.writable (Arm64Register.registerCode dst) &&
    (GeneratedArm64RegDispatch.cellOf (Arm64Register.registerCode dst) == some r.val)
  { raw := { state.raw with gpr := fun r => if selected r then word else state.raw.gpr r }
    tags := fun r => if selected r then tag else state.tags r }

theorem write_tagged_projects (origins : Origins) (state : State) (dst : Register) (word : Word) (tag : Byte) :
    image origins (writeTagged state dst word tag) =
      Reference.AArch64.writeReg (image origins state) dst (materialize origins word tag) := by
  simp only [image, writeTagged, Arm64Register.write_selection, Reference.AArch64.writeReg]
  congr 1
  funext r
  by_cases same : r.val = dst.val <;> simp [same, materialize]

def copyRegister (state : State) (dst src : Register) : State :=
  let captured := readTagged state src
  writeTagged state dst captured.1 captured.2

theorem copy_projects (origins : Origins) (state : State) (dst src : Register) :
    image origins (copyRegister state dst src) =
      Reference.AArch64.writeReg (image origins state) dst (Reference.AArch64.readReg (image origins state) src) := by
  simp only [copyRegister, write_tagged_projects, read_tagged_materializes, read_refines]

theorem copy_tag_frame (state : State) (dst src : Register) (r : Gpr) :
    (copyRegister state dst src).tags r = if r.val = dst.val then (readTagged state src).2 else state.tags r := by
  simp [copyRegister, writeTagged, Arm64Register.write_selection]

/-- CSEL/X copies the chosen incoming raw word/tag; the other rows use
materialized operands, generated scalar values and scalarizing width writes. -/
def body (op : GeneratedArm64Csel.Csel) (predicate : Arm64Cond) (width : Width)
    (dst lhs rhs : Register) (origins : Origins) (state : State) : Transition State :=
  let taken := generatedArm64Cond (Arm64Condition.flags state.raw.flags) predicate
  let next := if GeneratedArm64CselPtr.ptrTagPath op (Arm64Register.handlerWidth width) then
      copyRegister state dst (if taken then lhs else rhs)
    else writeRegister state dst (GeneratedArm64Csel.value op taken
      (readRegister origins state lhs) (readRegister origins state rhs)) width
  ⟨advance next, [], none⟩

theorem body_projects (op : GeneratedArm64Csel.Csel) (predicate : Arm64Cond) (width : Width)
    (dst lhs rhs : Register) (origins : Origins) (state : State) :
    observe origins (body op predicate width dst lhs rhs origins state) =
      Arm64Select.rawStep op width dst lhs rhs predicate (image origins state) := by
  have flag_image : (image origins state).flags = state.raw.flags := rfl
  cases op <;> cases width <;>
    simp only [body, observe, GeneratedArm64CselPtr.ptrTagPath, Arm64Register.handlerWidth,
      Bool.false_eq_true, ↓reduceIte, advance_refines, copy_projects, write_refines, read_refines,
      Arm64Select.rawStep, Arm64Register.read_refines, Arm64Register.write_refines, flag_image]
  all_goals first | rfl | (cases taken : generatedArm64Cond (Arm64Condition.flags state.raw.flags) predicate <;> simp only [taken, Bool.false_eq_true, ↓reduceIte] <;> rfl)

/-- Covered disjoint select opcodes extend the preceding22-operation lift. -/
def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst lhs rhs src3 : Register)
    (value : Word) (origins : Origins) (state : State) : Option (Transition State) :=
  match ExtractReverse.dispatch code aux width dst lhs rhs src3 value origins state with
  | some result => some result
  | none => (Arm64Select.decodeOpcode code).bind (fun op =>
      (Arm64Condition.decode aux.toNat).map (fun predicate => body op predicate width dst lhs rhs origins state))

theorem before_select (op : GeneratedArm64Csel.Csel) (aux : BitVec 32) (width : Width)
    (dst lhs rhs src3 : Register) (value : Word) (origins : Origins) (state : State) :
    ExtractReverse.dispatch (GeneratedArm64Csel.code op) aux width dst lhs rhs src3 value origins state = none := by
  cases op <;> rfl

theorem reached (op : GeneratedArm64Csel.Csel) (predicate : Arm64Cond) (width : Width)
    (dst lhs rhs src3 : Register) (value : Word) (origins : Origins) (state : State) :
    dispatch (GeneratedArm64Csel.code op) (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate))
      width dst lhs rhs src3 value origins state = some (body op predicate width dst lhs rhs origins state) := by
  simp only [dispatch, before_select, Arm64Select.decode_code, Option.bind_some,
    Arm64Dispatcher.select_condition_decode]
  rfl

theorem production (op : GeneratedArm64Csel.Csel) (predicate : Arm64Cond) (width : Width)
    (dst lhs rhs src3 : Register) (unused3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Csel.code op) (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate))
      width dst lhs rhs src3 value origins state).map (observe origins) =
      Arm64Dispatcher.dispatchThroughSelect (GeneratedArm64Csel.code op)
        (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode lhs) (Arm64Register.registerCode rhs) unused3 value
        sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.select_reached, Arm64Dispatcher.select_condition_decode]
  change some (observe origins (body op predicate width dst lhs rhs origins state)) = _
  simp only [Option.map]
  rw [Arm64Dispatcher.select_body_typed, body_projects]

theorem alias_unused (alias : Arm64Select.Alias) (predicate : Arm64Cond) (width : Width)
    (dst src rhs other : Register) (origins : Origins) (state : State) :
    body (Arm64Select.aliasOpcode alias) predicate width dst src rhs origins state =
      body (Arm64Select.aliasOpcode alias) predicate width dst src other origins state := by
  cases alias <;> cases width <;> rfl

/-- CINC/CINV ignore SRC2; CSET/CSETM ignore both source bytes. All these
rows retain every unused byte, including NONE255, through production routing. -/
theorem production_alias_unused (alias : Arm64Select.Alias) (predicate : Arm64Cond) (width : Width)
    (dst src rhs src3 : Register) (unusedSrc unused2 unused3 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Csel.code (Arm64Select.aliasOpcode alias))
      (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width dst src rhs src3 value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughSelect (GeneratedArm64Csel.code (Arm64Select.aliasOpcode alias))
      (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width (Arm64Register.registerCode dst)
      (match alias with | .increment | .invert => Arm64Register.registerCode src | .set | .mask => unusedSrc)
      unused2 unused3 value sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.select_reached, Arm64Dispatcher.select_condition_decode]
  change some (observe origins (body (Arm64Select.aliasOpcode alias) predicate width dst src rhs origins state)) = _
  simp only [Option.map]
  rw [alias_unused alias predicate width dst src rhs 31]
  apply congrArg some
  have ignored := Arm64Dispatcher.select_alias_unused alias predicate width dst src unusedSrc unused2 (image origins state)
  have typed := Arm64Dispatcher.select_body_typed (Arm64Select.aliasOpcode alias) predicate width dst src 31 (image origins state)
  exact (body_projects (Arm64Select.aliasOpcode alias) predicate width dst src 31 origins state).trans
    (typed.symm.trans ignored.symm)

theorem select_refines (width : Width) (alternative : SelectElse) (dst lhs rhs src3 : Register)
    (predicate : Arm64Cond) (value : Word) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Csel.code (Arm64Select.opcode alternative))
      (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width dst lhs rhs src3 value origins state).map
      (observe origins) = some (Reference.AArch64.step
        (.select width alternative dst lhs rhs (Arm64Condition.nativeCode predicate)) (image origins state)) := by
  rw [reached]
  change some (observe origins (body (Arm64Select.opcode alternative) predicate width dst lhs rhs origins state)) = _
  rw [body_projects, Arm64Select.raw_step_refines]

theorem alias_refines (alias : Arm64Select.Alias) (width : Width) (dst src rhs src3 : Register)
    (predicate : Arm64Cond) (value : Word) (origins : Origins) (state : State) (valid : predicate ≠ .al) :
    (dispatch (GeneratedArm64Csel.code (Arm64Select.aliasOpcode alias))
      (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width dst src rhs src3 value origins state).map
      (observe origins) = some (Reference.AArch64.step
        (.select width (Arm64Select.aliasAlternative alias) dst (Arm64Select.aliasSource alias src)
          (Arm64Select.aliasSource alias src) (Arm64Condition.nativeCode (Arm64Select.inverse predicate)))
        (image origins state)) := by
  rw [reached]
  change some (observe origins (body (Arm64Select.aliasOpcode alias) predicate width dst src rhs origins state)) = _
  rw [body_projects, Arm64Select.raw_alias_refines width alias dst src rhs predicate _ valid]

theorem normalized_nv_refines (width : Width) (alternative : SelectElse) (dst lhs rhs src3 : Register)
    (value : Word) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Csel.code (Arm64Select.opcode alternative))
      (BitVec.ofNat 32 (GeneratedArm64CcDecode.code .nv)) width dst lhs rhs src3 value origins state).map
      (observe origins) = some (Reference.AArch64.step (.select width alternative dst lhs rhs 15) (image origins state)) :=
  select_refines width alternative dst lhs rhs src3 .al value origins state

theorem earlier_step (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst lhs rhs src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : ExtractReverse.Binding code aux width dst lhs rhs src3 value instruction) :
    (dispatch code aux width dst lhs rhs src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have result := ExtractReverse.step_refines origins state code aux width dst lhs rhs src3 value instruction binding
  unfold dispatch
  cases leading : ExtractReverse.dispatch code aux width dst lhs rhs src3 value origins state with
  | none => simp [leading] at result
  | some output => simpa only [leading] using result

/-- Native fields, condition inversion and producer NV-to-AL normalization
extend the prior22 operations. Handler equality is derived by the step law. -/
inductive Binding : Nat → BitVec 32 → Width → Register → Register → Register → Register →
    Word → Reference.AArch64.Instruction → Prop where
  | leading (code : Nat) (aux : BitVec 32) (width : Width) (dst lhs rhs src3 : Register)
      (value : Word) (instruction : Reference.AArch64.Instruction)
      (binding : ExtractReverse.Binding code aux width dst lhs rhs src3 value instruction) :
      Binding code aux width dst lhs rhs src3 value instruction
  | select (width : Width) (alternative : SelectElse) (dst lhs rhs src3 : Register)
      (predicate : Arm64Cond) (value : Word) :
      Binding (GeneratedArm64Csel.code (Arm64Select.opcode alternative))
        (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width dst lhs rhs src3 value
        (.select width alternative dst lhs rhs (Arm64Condition.nativeCode predicate))
  | alias (alias : Arm64Select.Alias) (width : Width) (dst src rhs src3 : Register)
      (predicate : Arm64Cond) (value : Word) (valid : predicate ≠ .al) :
      Binding (GeneratedArm64Csel.code (Arm64Select.aliasOpcode alias))
        (BitVec.ofNat 32 (GeneratedArm64Cond.code predicate)) width dst src rhs src3 value
        (.select width (Arm64Select.aliasAlternative alias) dst (Arm64Select.aliasSource alias src)
          (Arm64Select.aliasSource alias src) (Arm64Condition.nativeCode (Arm64Select.inverse predicate)))
  | normalizedNv (width : Width) (alternative : SelectElse) (dst lhs rhs src3 : Register) (value : Word) :
      Binding (GeneratedArm64Csel.code (Arm64Select.opcode alternative))
        (BitVec.ofNat 32 (GeneratedArm64CcDecode.code .nv)) width dst lhs rhs src3 value
        (.select width alternative dst lhs rhs 15)

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst lhs rhs src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst lhs rhs src3 value instruction) :
    (dispatch code aux width dst lhs rhs src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading code aux width dst lhs rhs src3 value instruction bound =>
      exact earlier_step origins state code aux width dst lhs rhs src3 value instruction bound
  | select width alternative dst lhs rhs src3 predicate value =>
      exact select_refines width alternative dst lhs rhs src3 predicate value origins state
  | alias => apply alias_refines; assumption
  | normalizedNv width alternative dst lhs rhs src3 value =>
      exact normalized_nv_refines width alternative dst lhs rhs src3 value origins state

end KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect

#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.read_tagged_materializes
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.write_tagged_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.copy_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.copy_tag_frame
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.body_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.before_select
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.production
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.alias_unused
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.production_alias_unused
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.select_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.alias_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.normalized_nv_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.earlier_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.ConditionalSelect.step_refines
namespace KProgFormal.Refinement.Arm64RawRegister.Bitfield
open Reference
open Reference.AArch64 (Register Width BitfieldInstruction)

/-- The C bitfield body captures SRC and old DST from incoming tagged words,
then consumes kind byte0, LSB byte1 and count byte2 before scalar writeback. -/
def body (kind : GeneratedArm64BitfieldDecode.Bitfield) (aux : BitVec 32) (width : Width)
    (dst src : Register) (origins : Origins) (state : State) : Transition State :=
  let result := GeneratedArm64Bitfield.value kind (readRegister origins state src)
    (readRegister origins state dst) ((GeneratedArm64Aux.b1 aux).setWidth 8)
    ((GeneratedArm64Aux.b2 aux).setWidth 8)
  ⟨advance (writeRegister state dst result width), [], none⟩

theorem body_projects (kind : GeneratedArm64BitfieldDecode.Bitfield) (aux : BitVec 32) (width : Width)
    (dst src : Register) (origins : Origins) (state : State) :
    observe origins (body kind aux width dst src origins state) =
      Arm64Bitfield.rawStep kind width dst src aux (image origins state) := by
  simp only [body, observe, advance_refines, write_refines, read_refines,
    Arm64Bitfield.rawStep, Arm64Register.read_refines, Arm64Register.write_refines]
  rfl

theorem body_refines (kind : GeneratedArm64BitfieldDecode.Bitfield) (i : BitfieldInstruction)
    (high : Byte) (origins : Origins) (state : State) (matching : Arm64Bitfield.canonicalKind kind = i.kind) :
    observe origins (body kind (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high)
      i.width i.dst i.src origins state) = Reference.AArch64.step (.bitfield i) (image origins state) := by
  rw [body_projects, Arm64Bitfield.raw_step_eq, Arm64Bitfield.step_refines kind i _ matching]

/-- The covered bitfield opcode extends the preceding thirty disjoint gates. -/
def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register)
    (value : Word) (origins : Origins) (state : State) : Option (Transition State) :=
  match ConditionalSelect.dispatch code aux width dst src src2 src3 value origins state with
  | some result => some result
  | none => if code = GeneratedArm64DispatchSingleton.code .bitfield then
      (Arm64Bitfield.decodeKind (GeneratedArm64Aux.b0 aux).toNat).map
        (fun kind => body kind aux width dst src origins state)
    else none

theorem leading_passes (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register)
    (value : Word) (origins : Origins) (state : State) :
    ConditionalSelect.dispatch (GeneratedArm64DispatchSingleton.code .bitfield) aux width
      dst src src2 src3 value origins state = none := rfl

theorem reached (kind : GeneratedArm64BitfieldDecode.Bitfield) (i : BitfieldInstruction)
    (high : Byte) (src2 src3 : Register) (value : Word) (origins : Origins) (state : State) :
    dispatch (GeneratedArm64DispatchSingleton.code .bitfield)
      (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width i.dst i.src src2 src3 value origins state =
      some (body kind (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width i.dst i.src origins state) := by
  simp only [dispatch, leading_passes, if_pos rfl,
    (Arm64Bitfield.packed_fields kind i.lsbByte i.countByte high).1]
  rfl

/-- Actual production arm equality retains all unused SRC2/SRC3/IMM values
and the high AUX byte. All operands refer to the incoming state, including aliases. -/
theorem production (kind : GeneratedArm64BitfieldDecode.Bitfield) (i : BitfieldInstruction)
    (high : Byte) (src2 src3 : Register) (unused2 unused3 : Byte) (value otherValue : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64DispatchSingleton.code .bitfield)
      (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width i.dst i.src src2 src3 value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughBitfield (GeneratedArm64DispatchSingleton.code .bitfield)
      (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width (Arm64Register.registerCode i.dst)
      (Arm64Register.registerCode i.src) unused2 unused3 otherValue sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.bitfield_reached,
    (Arm64Bitfield.packed_fields kind i.lsbByte i.countByte high).1]
  simp only [Option.map]
  rw [Arm64Dispatcher.bitfield_body_typed]
  exact congrArg some (body_projects kind _ i.width i.dst i.src origins state)

theorem dispatch_refines (kind : GeneratedArm64BitfieldDecode.Bitfield) (i : BitfieldInstruction)
    (high : Byte) (src2 src3 : Register) (value : Word) (origins : Origins) (state : State)
    (matching : Arm64Bitfield.canonicalKind kind = i.kind) :
    (dispatch (GeneratedArm64DispatchSingleton.code .bitfield)
      (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width i.dst i.src src2 src3 value origins state).map
      (observe origins) = some (Reference.AArch64.step (.bitfield i) (image origins state)) := by
  rw [reached]
  exact congrArg some (body_refines kind i high origins state matching)

theorem earlier_step (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src src2 src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : ConditionalSelect.Binding code aux width dst src src2 src3 value instruction) :
    (dispatch code aux width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have result := ConditionalSelect.step_refines origins state code aux width dst src src2 src3 value instruction binding
  unfold dispatch
  cases leading : ConditionalSelect.dispatch code aux width dst src src2 src3 value origins state with
  | none => simp [leading] at result
  | some output => simpa only [leading] using result

/-- Typed native LSB/count fields and kind identity bind all five bitfield
forms. The field bounds are ISA premises supplied by the instruction type. -/
inductive Binding : Nat → BitVec 32 → Width → Register → Register → Register → Register →
    Word → Reference.AArch64.Instruction → Prop where
  | leading (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register)
      (value : Word) (instruction : Reference.AArch64.Instruction)
      (binding : ConditionalSelect.Binding code aux width dst src src2 src3 value instruction) :
      Binding code aux width dst src src2 src3 value instruction
  | bitfield (kind : GeneratedArm64BitfieldDecode.Bitfield) (i : BitfieldInstruction)
      (high : Byte) (src2 src3 : Register) (value : Word) (matching : Arm64Bitfield.canonicalKind kind = i.kind) :
      Binding (GeneratedArm64DispatchSingleton.code .bitfield)
        (Arm64Bitfield.packedAux kind i.lsbByte i.countByte high) i.width i.dst i.src src2 src3 value (.bitfield i)

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src src2 src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst src src2 src3 value instruction) :
    (dispatch code aux width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading code aux width dst src src2 src3 value instruction bound =>
      exact earlier_step origins state code aux width dst src src2 src3 value instruction bound
  | bitfield kind i high src2 src3 value matching =>
      exact dispatch_refines kind i high src2 src3 value origins state matching

end KProgFormal.Refinement.Arm64RawRegister.Bitfield

#print axioms KProgFormal.Refinement.Arm64RawRegister.Bitfield.body_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.Bitfield.body_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Bitfield.leading_passes
#print axioms KProgFormal.Refinement.Arm64RawRegister.Bitfield.reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.Bitfield.production
#print axioms KProgFormal.Refinement.Arm64RawRegister.Bitfield.dispatch_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Bitfield.earlier_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.Bitfield.step_refines
namespace KProgFormal.Refinement.Arm64RawRegister.Branch
open Reference
open Reference.AArch64 (Register Width)

def setPc (state : State) (pc : Word) : State :=
  { state with raw := { state.raw with pc := pc } }

theorem set_pc_projects (origins : Origins) (state : State) (pc : Word) :
    image origins (setPc state pc) = { image origins state with pc := pc } := rfl

theorem set_pc_tag_frame (state : State) (pc : Word) :
    (setPc state pc).tags = state.tags := rfl

/-- Raw operands select the actual source-level forward/backward branch shape;
the selected label's native address supplies the architectural PC. -/
def mappedBody (nativeAddress : Word → Word) (current fallthrough target : Word) (taken : Bool)
    (state : State) : Transition State :=
  ⟨setPc state (Arm64Branch.choosePc (GeneratedArm64BranchEmit.shape current.toNat target.toNat)
    taken (nativeAddress fallthrough) (nativeAddress target)), [], none⟩

theorem mapped_projects (nativeAddress : Word → Word) (current fallthrough target : Word) (taken : Bool)
    (origins : Origins) (state : State) :
    observe origins (mappedBody nativeAddress current fallthrough target taken state) =
      Arm64Dispatcher.mappedBranchStep nativeAddress current fallthrough target taken (image origins state) := rfl

theorem mapped_refines (nativeAddress : Word → Word) (current fallthrough target : Word) (taken : Bool)
    (displacement : Word) (origins : Origins) (state : State)
    (fallAddress : nativeAddress fallthrough = state.raw.pc + 4)
    (targetAddress : nativeAddress target = state.raw.pc + displacement) :
    observe origins (mappedBody nativeAddress current fallthrough target taken state) =
      Reference.AArch64.branchStep taken displacement (image origins state) := by
  rw [mapped_projects]
  exact Arm64Dispatcher.mapped_branch_refines nativeAddress current fallthrough target taken displacement
    (image origins state) fallAddress targetAddress

/-- Source emission alternatives extend the raw register dispatcher. They are
producer forms outside L_EXEC and retain source labels separately from native PC. -/
inductive Emission where
  | execute (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register) (value : Word)
  | jump (current target : Word)
  | condition (code : Nat) (current fallthrough target : Word)
  | zero (width : Width) (nonzero : Bool) (src : Register) (current fallthrough target : Word)
  | bit (nonzero : Bool) (src : Register) (bit : Word) (current fallthrough target : Word)

def dispatch (nativeAddress : Word → Word) (emission : Emission) (origins : Origins) (state : State) :
    Option (Transition State) :=
  match emission with
  | .execute code aux width dst src src2 src3 value => Bitfield.dispatch code aux width dst src src2 src3 value origins state
  | .jump _ target => some ⟨setPc state (nativeAddress target), [], none⟩
  | .condition code current fallthrough target => (Arm64Condition.decode code).map (fun predicate =>
      mappedBody nativeAddress current fallthrough target
        (generatedArm64Cond (Arm64Condition.flags state.raw.flags) predicate) state)
  | .zero width nonzero src current fallthrough target => some (mappedBody nativeAddress current fallthrough target
      (GeneratedArm64Branch.value (if nonzero then .cbnz else .cbz)
        (Arm64Branch.zeroSource width (readRegister origins state src)) 0) state)
  | .bit nonzero src bit current fallthrough target => some (mappedBody nativeAddress current fallthrough target
      (GeneratedArm64Branch.value (if nonzero then .tbnz else .tbz) (readRegister origins state src) bit) state)

theorem production_jump (nativeAddress : Word → Word) (current target : Word) (origins : Origins) (state : State)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) :
    (dispatch nativeAddress (.jump current target) origins state).map (observe origins) =
    Arm64Dispatcher.dispatchEmission nativeAddress (.jump current target) sourceScalar sourceStack
      firstScalar secondScalar release failure (image origins state) := rfl

theorem production_condition (nativeAddress : Word → Word) (code : Nat) (current fallthrough target : Word)
    (origins : Origins) (state : State) (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) :
    (dispatch nativeAddress (.condition code current fallthrough target) origins state).map (observe origins) =
    Arm64Dispatcher.dispatchEmission nativeAddress (.condition code current fallthrough target) sourceScalar sourceStack
      firstScalar secondScalar release failure (image origins state) := by
  simp only [dispatch, Arm64Dispatcher.dispatchEmission, Option.map_map]
  rfl

theorem production_zero (nativeAddress : Word → Word) (width : Width) (nonzero : Bool) (src : Register)
    (current fallthrough target : Word) (origins : Origins) (state : State)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) :
    (dispatch nativeAddress (.zero width nonzero src current fallthrough target) origins state).map (observe origins) =
    Arm64Dispatcher.dispatchEmission nativeAddress
      (.zero width nonzero (Arm64Register.registerCode src) current fallthrough target)
      sourceScalar sourceStack firstScalar secondScalar release failure (image origins state) := by
  simp only [dispatch, Arm64Dispatcher.dispatchEmission, Arm64Move.Fields.register_read,
    Arm64Register.read_refines, ← read_refines]
  rfl

theorem production_bit (nativeAddress : Word → Word) (nonzero : Bool) (src : Register) (bit : Word)
    (current fallthrough target : Word) (origins : Origins) (state : State)
    (sourceScalar sourceStack firstScalar secondScalar release failure : Bool) :
    (dispatch nativeAddress (.bit nonzero src bit current fallthrough target) origins state).map (observe origins) =
    Arm64Dispatcher.dispatchEmission nativeAddress
      (.bit nonzero (Arm64Register.registerCode src) bit current fallthrough target)
      sourceScalar sourceStack firstScalar secondScalar release failure (image origins state) := by
  simp only [dispatch, Arm64Dispatcher.dispatchEmission, Arm64Move.Fields.register_read,
    Arm64Register.read_refines, ← read_refines]
  rfl

theorem jump_refines (nativeAddress : Word → Word) (current target displacement : Word)
    (origins : Origins) (state : State) (targetAddress : nativeAddress target = state.raw.pc + displacement) :
    (dispatch nativeAddress (.jump current target) origins state).map (observe origins) =
      some (Reference.AArch64.step (.branch displacement) (image origins state)) := by
  change some (observe origins ⟨setPc state (nativeAddress target), [], none⟩) = _
  simp only [observe, set_pc_projects, targetAddress, Reference.AArch64.step]
  rfl

theorem condition_refines (nativeAddress : Word → Word) (predicate : Arm64Cond)
    (current fallthrough target displacement : Word) (origins : Origins) (state : State)
    (fallAddress : nativeAddress fallthrough = state.raw.pc + 4)
    (targetAddress : nativeAddress target = state.raw.pc + displacement) :
    (dispatch nativeAddress (.condition (GeneratedArm64Cond.code predicate) current fallthrough target) origins state).map
      (observe origins) = some (Reference.AArch64.step
        (.branchConditional (Arm64Condition.nativeCode predicate) displacement) (image origins state)) := by
  simp only [dispatch, Arm64Condition.decode_code]
  change some (observe origins (mappedBody nativeAddress current fallthrough target _ state)) = _
  rw [mapped_refines nativeAddress current fallthrough target _ displacement origins state fallAddress targetAddress,
    Arm64Condition.condition_refines]
  rfl

theorem normalized_nv_refines (nativeAddress : Word → Word) (current fallthrough target displacement : Word)
    (origins : Origins) (state : State) (fallAddress : nativeAddress fallthrough = state.raw.pc + 4)
    (targetAddress : nativeAddress target = state.raw.pc + displacement) :
    (dispatch nativeAddress (.condition (GeneratedArm64CcDecode.code .nv) current fallthrough target) origins state).map
      (observe origins) = some (Reference.AArch64.step (.branchConditional 15 displacement) (image origins state)) :=
  condition_refines nativeAddress .al current fallthrough target displacement origins state fallAddress targetAddress

theorem zero_refines (nativeAddress : Word → Word) (width : Width) (nonzero : Bool) (src : Register)
    (current fallthrough target displacement : Word) (origins : Origins) (state : State)
    (fallAddress : nativeAddress fallthrough = state.raw.pc + 4)
    (targetAddress : nativeAddress target = state.raw.pc + displacement) :
    (dispatch nativeAddress (.zero width nonzero src current fallthrough target) origins state).map (observe origins) =
      some (Reference.AArch64.step (.branchZero width nonzero src displacement) (image origins state)) := by
  change some (observe origins (mappedBody nativeAddress current fallthrough target _ state)) = _
  rw [mapped_refines nativeAddress current fallthrough target _ displacement origins state fallAddress targetAddress,
    read_refines, Arm64Branch.zero_predicate_refines]
  rfl

theorem bit_refines (nativeAddress : Word → Word) (nonzero : Bool) (src : Register) (bit : Word)
    (current fallthrough target displacement : Word) (origins : Origins) (state : State)
    (fallAddress : nativeAddress fallthrough = state.raw.pc + 4)
    (targetAddress : nativeAddress target = state.raw.pc + displacement) :
    (dispatch nativeAddress (.bit nonzero src bit current fallthrough target) origins state).map (observe origins) =
      some (Reference.AArch64.step (.branchBit nonzero src (bit.setWidth 6) displacement) (image origins state)) := by
  change some (observe origins (mappedBody nativeAddress current fallthrough target _ state)) = _
  rw [mapped_refines nativeAddress current fallthrough target _ displacement origins state fallAddress targetAddress,
    read_refines, Arm64Dispatcher.branch_bit_argument, Arm64Branch.bit_predicate_refines]
  rfl

/-- Every program uses the same source-label/native-address field identities.
Bounds and branch outcomes are derived by the handlers; only layout identities
bind the current, lexical successor and target to the architectural PC. -/
inductive Binding (nativeAddress : Word → Word) (pc : Word) : Emission → Reference.AArch64.Instruction → Prop where
  | execute (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register) (value : Word)
      (instruction : Reference.AArch64.Instruction)
      (binding : Bitfield.Binding code aux width dst src src2 src3 value instruction) :
      Binding nativeAddress pc (.execute code aux width dst src src2 src3 value) instruction
  | jump (current target displacement : Word) (currentAddress : nativeAddress current = pc)
      (targetAddress : nativeAddress target = pc + displacement) :
      Binding nativeAddress pc (.jump current target) (.branch displacement)
  | condition (predicate : Arm64Cond) (current fallthrough target displacement : Word)
      (currentAddress : nativeAddress current = pc) (nextLabel : fallthrough = current + 4)
      (fallAddress : nativeAddress fallthrough = pc + 4) (targetAddress : nativeAddress target = pc + displacement) :
      Binding nativeAddress pc (.condition (GeneratedArm64Cond.code predicate) current fallthrough target)
        (.branchConditional (Arm64Condition.nativeCode predicate) displacement)
  | normalizedNv (current fallthrough target displacement : Word)
      (currentAddress : nativeAddress current = pc) (nextLabel : fallthrough = current + 4)
      (fallAddress : nativeAddress fallthrough = pc + 4) (targetAddress : nativeAddress target = pc + displacement) :
      Binding nativeAddress pc (.condition (GeneratedArm64CcDecode.code .nv) current fallthrough target)
        (.branchConditional 15 displacement)
  | zero (width : Width) (nonzero : Bool) (src : Register) (current fallthrough target displacement : Word)
      (currentAddress : nativeAddress current = pc) (nextLabel : fallthrough = current + 4)
      (fallAddress : nativeAddress fallthrough = pc + 4) (targetAddress : nativeAddress target = pc + displacement) :
      Binding nativeAddress pc (.zero width nonzero src current fallthrough target) (.branchZero width nonzero src displacement)
  | bit (nonzero : Bool) (src : Register) (bit : Word) (current fallthrough target displacement : Word)
      (currentAddress : nativeAddress current = pc) (nextLabel : fallthrough = current + 4)
      (fallAddress : nativeAddress fallthrough = pc + 4) (targetAddress : nativeAddress target = pc + displacement) :
      Binding nativeAddress pc (.bit nonzero src bit current fallthrough target)
        (.branchBit nonzero src (bit.setWidth 6) displacement)

theorem step_refines (nativeAddress : Word → Word) (emission : Emission) (origins : Origins) (state : State)
    (instruction : Reference.AArch64.Instruction) (binding : Binding nativeAddress state.raw.pc emission instruction) :
    (dispatch nativeAddress emission origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | execute code aux width dst src src2 src3 value instruction bound =>
      exact Bitfield.step_refines origins state code aux width dst src src2 src3 value instruction bound
  | jump current target displacement currentAddress targetAddress =>
      exact jump_refines nativeAddress current target displacement origins state targetAddress
  | condition predicate current fallthrough target displacement currentAddress nextLabel fallAddress targetAddress =>
      exact condition_refines nativeAddress predicate current fallthrough target displacement origins state fallAddress targetAddress
  | normalizedNv current fallthrough target displacement currentAddress nextLabel fallAddress targetAddress =>
      exact normalized_nv_refines nativeAddress current fallthrough target displacement origins state fallAddress targetAddress
  | zero width nonzero src current fallthrough target displacement currentAddress nextLabel fallAddress targetAddress =>
      exact zero_refines nativeAddress width nonzero src current fallthrough target displacement origins state fallAddress targetAddress
  | bit nonzero src bit current fallthrough target displacement currentAddress nextLabel fallAddress targetAddress =>
      exact bit_refines nativeAddress nonzero src bit current fallthrough target displacement origins state fallAddress targetAddress

end KProgFormal.Refinement.Arm64RawRegister.Branch

#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.set_pc_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.set_pc_tag_frame
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.mapped_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.mapped_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.production_jump
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.production_condition
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.production_zero
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.production_bit
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.jump_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.condition_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.normalized_nv_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.zero_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.bit_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Branch.step_refines
namespace KProgFormal.Refinement.Arm64RawRegister.Orn
open Reference
open Reference.AArch64 (Register Width ShiftKind)

/-- Incoming tagged operands precede the actual byte1 modifier, byte2 amount,
generated ORN value and scalarizing width/tag writeback. -/
def body (aux : BitVec 32) (width : Width) (dst src rhs : Register)
    (origins : Origins) (state : State) : Transition State :=
  let modified := GeneratedArm64Mod.value
    (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
    (readRegister origins state rhs) ((GeneratedArm64Aux.b2 aux).setWidth 64)
    (Arm64Register.handlerWidth width)
  let result := GeneratedArm64Orn.value .orn_reg (readRegister origins state src) modified
    (Arm64Register.handlerWidth width)
  ⟨advance (writeRegister state dst result width), [], none⟩

theorem body_projects (aux : BitVec 32) (width : Width) (dst src rhs : Register)
    (origins : Origins) (state : State) :
    observe origins (body aux width dst src rhs origins state) =
      Arm64Dispatcher.ornBody aux width (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
        (Arm64Register.registerCode rhs) (image origins state) := by
  simp only [body, observe, advance_refines, write_refines, read_refines,
    Arm64Dispatcher.ornBody, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write,
    Arm64Register.read_refines, Arm64Register.write_refines]
  rfl

theorem body_refines (width : Width) (kind : ShiftKind) (amount : Fin width.bits)
    (dst src rhs : Register) (lane0 lane3 : Byte) (origins : Origins) (state : State) :
    observe origins (body (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Shift.modifier kind)
      (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src rhs origins state) =
      Reference.AArch64.step (.logic ⟨width, .disjunction true, kind, amount, dst, src, rhs⟩) (image origins state) := by
  rw [body_projects, Arm64Dispatcher.orn_body_refines]

theorem body_unmodified_refines (width : Width) (dst src rhs : Register)
    (amount lane0 lane3 : Byte) (origins : Origins) (state : State) :
    observe origins (body (Arm64Arithmetic.FlagArithmetic.packedAux .none amount lane0 lane3)
      width dst src rhs origins state) = Reference.AArch64.step
        (.logic ⟨width, .disjunction true, .lsl, ⟨0, by cases width <;> decide⟩, dst, src, rhs⟩) (image origins state) := by
  rw [body_projects, Arm64Dispatcher.orn_body_unmodified]
  exact Arm64Dispatcher.orn_body_refines width .lsl ⟨0, by cases width <;> decide⟩ dst src rhs lane0 lane3 _

def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register)
    (value : Word) (origins : Origins) (state : State) : Option (Transition State) :=
  match Bitfield.dispatch code aux width dst src rhs src3 value origins state with
  | some result => some result
  | none => if code = GeneratedArm64Orn.code .orn_reg then some (body aux width dst src rhs origins state) else none

theorem leading_passes (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register)
    (value : Word) (origins : Origins) (state : State) :
    Bitfield.dispatch (GeneratedArm64Orn.code .orn_reg) aux width dst src rhs src3 value origins state = none := rfl

theorem reached (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register)
    (value : Word) (origins : Origins) (state : State) :
    dispatch (GeneratedArm64Orn.code .orn_reg) aux width dst src rhs src3 value origins state =
      some (body aux width dst src rhs origins state) := by
  simp only [dispatch, leading_passes, if_pos rfl]
  rfl

theorem production (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register)
    (unused3 : Byte) (value otherValue : Word) (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Orn.code .orn_reg) aux width dst src rhs src3 value origins state).map (observe origins) =
      Arm64Dispatcher.dispatchThroughOrn (GeneratedArm64Orn.code .orn_reg) aux width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs)
        unused3 otherValue sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.orn_reached]
  exact congrArg some (body_projects aux width dst src rhs origins state)

theorem dispatch_refines (width : Width) (kind : ShiftKind) (amount : Fin width.bits)
    (dst src rhs src3 : Register) (lane0 lane3 : Byte) (value : Word) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Orn.code .orn_reg) (Arm64Arithmetic.FlagArithmetic.packedAux
      (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src rhs src3 value origins state).map
      (observe origins) = some (Reference.AArch64.step
        (.logic ⟨width, .disjunction true, kind, amount, dst, src, rhs⟩) (image origins state)) := by
  rw [reached]
  exact congrArg some (body_refines width kind amount dst src rhs lane0 lane3 origins state)

theorem dispatch_unmodified_refines (width : Width) (dst src rhs src3 : Register)
    (amount lane0 lane3 : Byte) (value : Word) (origins : Origins) (state : State) :
    (dispatch (GeneratedArm64Orn.code .orn_reg) (Arm64Arithmetic.FlagArithmetic.packedAux .none amount lane0 lane3)
      width dst src rhs src3 value origins state).map (observe origins) = some (Reference.AArch64.step
        (.logic ⟨width, .disjunction true, .lsl, ⟨0, by cases width <;> decide⟩, dst, src, rhs⟩) (image origins state)) := by
  rw [reached]
  exact congrArg some (body_unmodified_refines width dst src rhs amount lane0 lane3 origins state)

theorem earlier_step (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src rhs src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Bitfield.Binding code aux width dst src rhs src3 value instruction) :
    (dispatch code aux width dst src rhs src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have result := Bitfield.step_refines origins state code aux width dst src rhs src3 value instruction binding
  unfold dispatch
  cases leading : Bitfield.dispatch code aux width dst src rhs src3 value origins state with
  | none => simp [leading] at result
  | some output => simpa only [leading] using result

inductive Binding : Nat → BitVec 32 → Width → Register → Register → Register → Register →
    Word → Reference.AArch64.Instruction → Prop where
  | leading (code : Nat) (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register) (value : Word)
      (instruction : Reference.AArch64.Instruction) (binding : Bitfield.Binding code aux width dst src rhs src3 value instruction) :
      Binding code aux width dst src rhs src3 value instruction
  | shifted (width : Width) (kind : ShiftKind) (amount : Fin width.bits) (dst src rhs src3 : Register)
      (lane0 lane3 : Byte) (value : Word) :
      Binding (GeneratedArm64Orn.code .orn_reg) (Arm64Arithmetic.FlagArithmetic.packedAux
        (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src rhs src3 value
        (.logic ⟨width, .disjunction true, kind, amount, dst, src, rhs⟩)
  | unmodified (width : Width) (dst src rhs src3 : Register) (amount lane0 lane3 : Byte) (value : Word) :
      Binding (GeneratedArm64Orn.code .orn_reg) (Arm64Arithmetic.FlagArithmetic.packedAux .none amount lane0 lane3)
        width dst src rhs src3 value (.logic ⟨width, .disjunction true, .lsl, ⟨0, by cases width <;> decide⟩, dst, src, rhs⟩)

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src rhs src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst src rhs src3 value instruction) :
    (dispatch code aux width dst src rhs src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading code aux width dst src rhs src3 value instruction bound =>
      exact earlier_step origins state code aux width dst src rhs src3 value instruction bound
  | shifted => apply dispatch_refines
  | unmodified => apply dispatch_unmodified_refines

/-- Extend only the raw numeric execute arm; all source control forms keep
their established label map and exact data/tag-frame semantics. -/
def dispatchEmission (nativeAddress : Word → Word) (emission : Branch.Emission) (origins : Origins) (state : State) :
    Option (Transition State) :=
  match emission with
  | .execute code aux width dst src src2 src3 value => dispatch code aux width dst src src2 src3 value origins state
  | _ => Branch.dispatch nativeAddress emission origins state

theorem earlier_emission_step (nativeAddress : Word → Word) (emission : Branch.Emission)
    (origins : Origins) (state : State) (instruction : Reference.AArch64.Instruction)
    (binding : Branch.Binding nativeAddress state.raw.pc emission instruction) :
    (dispatchEmission nativeAddress emission origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases emission with
  | execute code aux width dst src rhs src3 value =>
      cases binding with
      | execute => apply earlier_step; assumption
  | jump current target => exact Branch.step_refines nativeAddress (.jump current target) origins state instruction binding
  | condition code current fallthrough target =>
      exact Branch.step_refines nativeAddress (.condition code current fallthrough target) origins state instruction binding
  | zero width nonzero src current fallthrough target =>
      exact Branch.step_refines nativeAddress (.zero width nonzero src current fallthrough target) origins state instruction binding
  | bit nonzero src bit current fallthrough target =>
      exact Branch.step_refines nativeAddress (.bit nonzero src bit current fallthrough target) origins state instruction binding

inductive EmissionBinding (nativeAddress : Word → Word) (pc : Word) : Branch.Emission → Reference.AArch64.Instruction → Prop where
  | leading (emission : Branch.Emission) (instruction : Reference.AArch64.Instruction)
      (binding : Branch.Binding nativeAddress pc emission instruction) :
      EmissionBinding nativeAddress pc emission instruction
  | execute (code : Nat) (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register) (value : Word)
      (instruction : Reference.AArch64.Instruction) (binding : Binding code aux width dst src rhs src3 value instruction) :
      EmissionBinding nativeAddress pc (.execute code aux width dst src rhs src3 value) instruction

theorem emission_step_refines (nativeAddress : Word → Word) (emission : Branch.Emission)
    (origins : Origins) (state : State) (instruction : Reference.AArch64.Instruction)
    (binding : EmissionBinding nativeAddress state.raw.pc emission instruction) :
    (dispatchEmission nativeAddress emission origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading emission instruction bound => exact earlier_emission_step nativeAddress emission origins state instruction bound
  | execute code aux width dst src rhs src3 value instruction bound =>
      exact step_refines origins state code aux width dst src rhs src3 value instruction bound

end KProgFormal.Refinement.Arm64RawRegister.Orn

#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.body_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.body_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.body_unmodified_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.leading_passes
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.production
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.dispatch_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.dispatch_unmodified_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.earlier_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.step_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.earlier_emission_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.Orn.emission_step_refines
namespace KProgFormal.Refinement.Arm64RawRegister.Compare
open Reference
open Reference.AArch64 (Register Width)

def setFlags (state : State) (flags : Word) : State :=
  { state with raw := { state.raw with flags := flags } }

theorem flags_projects (origins : Origins) (state : State) (flags : Word) :
    image origins (setFlags state flags) = { image origins state with flags := flags } := rfl

theorem flags_frame (state : State) (flags : Word) :
    (setFlags state flags).tags = state.tags ∧ (setFlags state flags).raw.gpr = state.raw.gpr := ⟨rfl, rfl⟩

/-- DST is the left source, SRC supplies only register RHS, and the generated
CCMP handler chooses compare NZCV or low4 fallback from the incoming flags. -/
def body (op : GeneratedArm64FlagOperand.FlagOp) (width : Width) (dst src : Register)
    (value : Word) (predicate : Arm64Cond) (fallback : Byte) (origins : Origins) (state : State) : Transition State :=
  let rhs := if GeneratedArm64FlagOperand.immediate op then value else readRegister origins state src
  let result := GeneratedArm64CcmpHandler.apply (Arm64Arithmetic.incomingFlags state.raw.flags) predicate
    (readRegister origins state dst) rhs (Arm64Register.handlerWidth width) fallback
  ⟨advance (setFlags state (Arm64Logic.flagsWord state.raw.flags result.flags)), [], none⟩

theorem body_projects (op : GeneratedArm64FlagOperand.FlagOp) (width : Width) (dst src : Register)
    (value : Word) (predicate : Arm64Cond) (fallback : Byte) (origins : Origins) (state : State) :
    observe origins (body op width dst src value predicate fallback origins state) =
      Arm64Arithmetic.ConditionalCompare.rawStep op width dst src value predicate fallback (image origins state) := by
  simp only [body, observe, advance_refines, flags_projects, read_refines,
    Arm64Arithmetic.ConditionalCompare.rawStep, Arm64Register.read_refines]
  rfl

theorem body_tag_frame (op : GeneratedArm64FlagOperand.FlagOp) (width : Width) (dst src : Register)
    (value : Word) (predicate : Arm64Cond) (fallback : Byte) (origins : Origins) (state : State) :
    (body op width dst src value predicate fallback origins state).state.tags = state.tags := rfl

theorem body_immediate_refines (width : Width) (dst src : Register) (value : BitVec 5)
    (predicate : Arm64Cond) (fallback : Byte) (origins : Origins) (state : State) :
    observe origins (body .ccmpImm width dst src (value.setWidth 64) predicate fallback origins state) =
      Reference.AArch64.step (.compare width dst (.immediate value)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) (image origins state) := by
  rw [body_projects, Arm64Arithmetic.ConditionalCompare.raw_immediate_refines]

theorem body_register_refines (width : Width) (dst src : Register) (value : Word)
    (predicate : Arm64Cond) (fallback : Byte) (origins : Origins) (state : State) :
    observe origins (body .ccmpReg width dst src value predicate fallback origins state) =
      Reference.AArch64.step (.compare width dst (.register src)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) (image origins state) := by
  rw [body_projects, Arm64Arithmetic.ConditionalCompare.raw_register_refines]

def opcode (immediate : Bool) : Nat :=
  GeneratedArm64DispatchFamily.code (if immediate then .ccmpImm else .ccmpReg)

def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register)
    (value : Word) (origins : Origins) (state : State) : Option (Transition State) :=
  match Orn.dispatch code aux width dst src src2 src3 value origins state with
  | some result => some result
  | none => (Arm64Arithmetic.ConditionalCompare.decodeOpcode code).bind (fun op =>
      (Arm64Condition.decode (GeneratedArm64CcmpDecode.ccmpCond aux).toNat).map (fun predicate =>
        body op width dst src value predicate ((GeneratedArm64CcmpDecode.ccmpNzcv aux).setWidth 8) origins state))

theorem leading_passes (immediate : Bool) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register)
    (value : Word) (origins : Origins) (state : State) :
    Orn.dispatch (opcode immediate) aux width dst src src2 src3 value origins state = none := by cases immediate <;> rfl

theorem reached (immediate : Bool) (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (width : Width)
    (dst src src2 src3 : Register) (value : Word) (origins : Origins) (state : State) :
    dispatch (opcode immediate) (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
      width dst src src2 src3 value origins state =
      some (body (if immediate then .ccmpImm else .ccmpReg) width dst src value predicate fallback origins state) := by
  have decoded : Arm64Arithmetic.ConditionalCompare.decodeOpcode (opcode immediate) =
      some (if immediate then .ccmpImm else .ccmpReg) := by cases immediate <;> rfl
  simp only [dispatch, leading_passes, decoded, Option.bind_some,
    Arm64Arithmetic.ConditionalCompare.packed_condition, Arm64Arithmetic.ConditionalCompare.packed_fallback]
  rfl

theorem production (immediate : Bool) (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (width : Width)
    (dst src src2 src3 : Register) (unused2 unused3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) :
    (dispatch (opcode immediate) (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
      width dst src src2 src3 value origins state).map (observe origins) =
    Arm64Dispatcher.dispatchThroughCompare (opcode immediate)
      (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) unused2 unused3 value
      sourceScalar sourceStack (image origins state) := by
  rw [reached]
  unfold opcode
  rw [Arm64Dispatcher.compare_reached immediate,
    Arm64Arithmetic.ConditionalCompare.packed_condition, Arm64Arithmetic.ConditionalCompare.packed_fallback]
  simp only [Option.map]
  rw [Arm64Dispatcher.compare_body_typed]
  exact congrArg some (body_projects _ width dst src value predicate fallback origins state)

/-- Immediate CCMP retains every unused SRC byte, including NONE255. -/
theorem production_immediate_unused (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (width : Width)
    (dst src src2 src3 : Register) (unusedSrc unused2 unused3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) :
    (dispatch (opcode true) (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
      width dst src src2 src3 value origins state).map (observe origins) =
    Arm64Dispatcher.dispatchThroughCompare (opcode true)
      (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3) width
      (Arm64Register.registerCode dst) unusedSrc unused2 unused3 value sourceScalar sourceStack (image origins state) := by
  rw [reached]
  unfold opcode
  rw [Arm64Dispatcher.compare_reached true,
    Arm64Arithmetic.ConditionalCompare.packed_condition, Arm64Arithmetic.ConditionalCompare.packed_fallback]
  simp only [Option.map, ↓reduceIte]
  have ignored : Arm64Dispatcher.compareBody .ccmpImm predicate fallback width
      (Arm64Register.registerCode dst) unusedSrc value (image origins state) =
      Arm64Dispatcher.compareBody .ccmpImm predicate fallback width
        (Arm64Register.registerCode dst) (Arm64Register.registerCode src) value (image origins state) := rfl
  rw [ignored, Arm64Dispatcher.compare_body_typed]
  exact congrArg some (body_projects .ccmpImm width dst src value predicate fallback origins state)

/-- Register CCMP retains the full unused IMM word. -/
theorem production_register_unused_value (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (width : Width)
    (dst src src2 src3 : Register) (unused2 unused3 : Byte) (value otherValue : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (opcode false) (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
      width dst src src2 src3 value origins state).map (observe origins) =
    Arm64Dispatcher.dispatchThroughCompare (opcode false)
      (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3) width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src) unused2 unused3 otherValue
      sourceScalar sourceStack (image origins state) := by
  rw [reached]
  unfold opcode
  rw [Arm64Dispatcher.compare_reached false,
    Arm64Arithmetic.ConditionalCompare.packed_condition, Arm64Arithmetic.ConditionalCompare.packed_fallback]
  simp only [Option.map, Bool.false_eq_true, ↓reduceIte]
  rw [Arm64Dispatcher.compare_body_typed]
  have ignored : Arm64Arithmetic.ConditionalCompare.rawStep .ccmpReg width dst src value predicate fallback (image origins state) =
      Arm64Arithmetic.ConditionalCompare.rawStep .ccmpReg width dst src otherValue predicate fallback (image origins state) := rfl
  exact congrArg some ((body_projects .ccmpReg width dst src value predicate fallback origins state).trans ignored)

theorem immediate_refines (width : Width) (dst src src2 src3 : Register) (value : BitVec 5)
    (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (origins : Origins) (state : State) :
    (dispatch (opcode true) (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
      width dst src src2 src3 (value.setWidth 64) origins state).map (observe origins) =
      some (Reference.AArch64.step (.compare width dst (.immediate value)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) (image origins state)) := by
  rw [reached]
  exact congrArg some (body_immediate_refines width dst src value predicate fallback origins state)

theorem register_refines (width : Width) (dst src src2 src3 : Register) (value : Word)
    (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) (origins : Origins) (state : State) :
    (dispatch (opcode false) (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
      width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step (.compare width dst (.register src)
        (Arm64Condition.nativeCode predicate) (fallback.setWidth 4)) (image origins state)) := by
  rw [reached]
  exact congrArg some (body_register_refines width dst src value predicate fallback origins state)

theorem immediate_nv_refines (width : Width) (dst src src2 src3 : Register) (value : BitVec 5)
    (fallback lane2 lane3 : Byte) (origins : Origins) (state : State) :
    (dispatch (opcode true) (Arm64Arithmetic.ConditionalCompare.packedAux .al fallback lane2 lane3)
      width dst src src2 src3 (value.setWidth 64) origins state).map (observe origins) =
      some (Reference.AArch64.step (.compare width dst (.immediate value) 15 (fallback.setWidth 4)) (image origins state)) :=
  immediate_refines width dst src src2 src3 value .al fallback lane2 lane3 origins state

theorem register_nv_refines (width : Width) (dst src src2 src3 : Register) (value : Word)
    (fallback lane2 lane3 : Byte) (origins : Origins) (state : State) :
    (dispatch (opcode false) (Arm64Arithmetic.ConditionalCompare.packedAux .al fallback lane2 lane3)
      width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step (.compare width dst (.register src) 15 (fallback.setWidth 4)) (image origins state)) :=
  register_refines width dst src src2 src3 value .al fallback lane2 lane3 origins state

theorem earlier_step (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src src2 src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Orn.Binding code aux width dst src src2 src3 value instruction) :
    (dispatch code aux width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have result := Orn.step_refines origins state code aux width dst src src2 src3 value instruction binding
  unfold dispatch
  cases leading : Orn.dispatch code aux width dst src src2 src3 value origins state with
  | none => simp [leading] at result
  | some output => simpa only [leading] using result

inductive Binding : Nat → BitVec 32 → Width → Register → Register → Register → Register →
    Word → Reference.AArch64.Instruction → Prop where
  | leading (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register) (value : Word)
      (instruction : Reference.AArch64.Instruction) (binding : Orn.Binding code aux width dst src src2 src3 value instruction) :
      Binding code aux width dst src src2 src3 value instruction
  | immediate (width : Width) (dst src src2 src3 : Register) (value : BitVec 5)
      (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) :
      Binding (opcode true) (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
        width dst src src2 src3 (value.setWidth 64)
        (.compare width dst (.immediate value) (Arm64Condition.nativeCode predicate) (fallback.setWidth 4))
  | register (width : Width) (dst src src2 src3 : Register) (value : Word)
      (predicate : Arm64Cond) (fallback lane2 lane3 : Byte) :
      Binding (opcode false) (Arm64Arithmetic.ConditionalCompare.packedAux predicate fallback lane2 lane3)
        width dst src src2 src3 value (.compare width dst (.register src) (Arm64Condition.nativeCode predicate) (fallback.setWidth 4))
  | immediateNv (width : Width) (dst src src2 src3 : Register) (value : BitVec 5) (fallback lane2 lane3 : Byte) :
      Binding (opcode true) (Arm64Arithmetic.ConditionalCompare.packedAux .al fallback lane2 lane3)
        width dst src src2 src3 (value.setWidth 64) (.compare width dst (.immediate value) 15 (fallback.setWidth 4))
  | registerNv (width : Width) (dst src src2 src3 : Register) (value : Word) (fallback lane2 lane3 : Byte) :
      Binding (opcode false) (Arm64Arithmetic.ConditionalCompare.packedAux .al fallback lane2 lane3)
        width dst src src2 src3 value (.compare width dst (.register src) 15 (fallback.setWidth 4))

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src src2 src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst src src2 src3 value instruction) :
    (dispatch code aux width dst src src2 src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading code aux width dst src src2 src3 value instruction bound =>
      exact earlier_step origins state code aux width dst src src2 src3 value instruction bound
  | immediate => apply immediate_refines
  | register => apply register_refines
  | immediateNv => apply immediate_nv_refines
  | registerNv => apply register_nv_refines

def dispatchEmission (nativeAddress : Word → Word) (emission : Branch.Emission) (origins : Origins) (state : State) :
    Option (Transition State) :=
  match emission with
  | .execute code aux width dst src src2 src3 value => dispatch code aux width dst src src2 src3 value origins state
  | _ => Orn.dispatchEmission nativeAddress emission origins state

theorem earlier_emission_step (nativeAddress : Word → Word) (emission : Branch.Emission)
    (origins : Origins) (state : State) (instruction : Reference.AArch64.Instruction)
    (binding : Orn.EmissionBinding nativeAddress state.raw.pc emission instruction) :
    (dispatchEmission nativeAddress emission origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have prior := Orn.emission_step_refines nativeAddress emission origins state instruction binding
  cases emission with
  | execute code aux width dst src src2 src3 value =>
      change (Orn.dispatch code aux width dst src src2 src3 value origins state).map (observe origins) = _ at prior
      change (dispatch code aux width dst src src2 src3 value origins state).map (observe origins) = _
      unfold dispatch
      cases leading : Orn.dispatch code aux width dst src src2 src3 value origins state with
      | none => simp [leading] at prior
      | some output => simpa only [leading] using prior
  | jump current target => exact prior
  | condition code current fallthrough target => exact prior
  | zero width nonzero src current fallthrough target => exact prior
  | bit nonzero src bit current fallthrough target => exact prior

inductive EmissionBinding (nativeAddress : Word → Word) (pc : Word) : Branch.Emission → Reference.AArch64.Instruction → Prop where
  | leading (emission : Branch.Emission) (instruction : Reference.AArch64.Instruction)
      (binding : Orn.EmissionBinding nativeAddress pc emission instruction) : EmissionBinding nativeAddress pc emission instruction
  | execute (code : Nat) (aux : BitVec 32) (width : Width) (dst src src2 src3 : Register) (value : Word)
      (instruction : Reference.AArch64.Instruction) (binding : Binding code aux width dst src src2 src3 value instruction) :
      EmissionBinding nativeAddress pc (.execute code aux width dst src src2 src3 value) instruction

theorem emission_step_refines (nativeAddress : Word → Word) (emission : Branch.Emission)
    (origins : Origins) (state : State) (instruction : Reference.AArch64.Instruction)
    (binding : EmissionBinding nativeAddress state.raw.pc emission instruction) :
    (dispatchEmission nativeAddress emission origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading emission instruction bound => exact earlier_emission_step nativeAddress emission origins state instruction bound
  | execute code aux width dst src src2 src3 value instruction bound =>
      exact step_refines origins state code aux width dst src src2 src3 value instruction bound

end KProgFormal.Refinement.Arm64RawRegister.Compare

#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.flags_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.flags_frame
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.body_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.body_tag_frame
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.body_immediate_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.body_register_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.leading_passes
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.production
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.production_immediate_unused
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.production_register_unused_value
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.immediate_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.register_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.immediate_nv_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.register_nv_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.earlier_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.step_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.earlier_emission_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.Compare.emission_step_refines
namespace KProgFormal.Refinement.Arm64RawRegister.FlagLogic
open Reference
open Reference.AArch64 (Register Gpr Width ShiftKind)

/-- ANDS/BICS write DST from SRC/SRC2; TST reads DST/SRC and retains all GPRs.
The generated operand row chooses an immediate or the actual source modifier. -/
def body (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width) (dst src rhs : Register)
    (value : Word) (origins : Origins) (state : State) : Transition State :=
  let lhs := readRegister origins state (if writeback then src else dst)
  let right := if GeneratedArm64FlagOperand.immediate (Arm64Logic.FlagDispatch.operandOp writeback immediate)
    then value else GeneratedArm64Mod.value
      (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
      (readRegister origins state (if writeback then rhs else src))
      ((GeneratedArm64Aux.b2 aux).setWidth 64) (Arm64Register.handlerWidth width)
  let result := GeneratedArm64LogicFlagHandler.apply (if invert then .bic else .and) lhs right
    (Arm64Register.handlerWidth width)
  let next := if writeback then writeRegister state dst result.value width else state
  ⟨advance (Compare.setFlags next (Arm64Logic.flagsWord state.raw.flags result.flags)), [], none⟩

theorem body_projects (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs : Register) (value : Word) (origins : Origins) (state : State) :
    observe origins (body invert writeback immediate aux width dst src rhs value origins state) =
      Arm64Dispatcher.flagLogicBody invert writeback immediate aux width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) value (image origins state) := by
  cases writeback <;> simp only [body, observe, Bool.false_eq_true, ↓reduceIte, advance_refines,
    Compare.flags_projects, write_refines, read_refines, Arm64Dispatcher.flagLogicBody,
    Arm64Move.Fields.register_read, Arm64Move.Fields.register_write, Arm64Register.read_refines,
    Arm64Register.write_refines] <;> rfl

theorem body_tag_frame (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs : Register) (value : Word) (origins : Origins) (state : State) (r : Gpr) :
    (body invert writeback immediate aux width dst src rhs value origins state).state.tags r =
      if writeback then (if r.val = dst.val then 0 else state.tags r) else state.tags r := by
  cases writeback <;> simp [body, Compare.setFlags, advance, write_tag_frame]

def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register)
    (value : Word) (origins : Origins) (state : State) : Option (Transition State) :=
  match Compare.dispatch code aux width dst src rhs src3 value origins state with
  | some result => some result
  | none => (Arm64Logic.FlagDispatch.decodeOpcode code).map
      (fun choice => body choice.1 choice.2.1 choice.2.2 aux width dst src rhs value origins state)

theorem leading_passes (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs src3 : Register) (value : Word) (origins : Origins) (state : State) :
    Compare.dispatch (Arm64Logic.FlagDispatch.operationCode invert writeback immediate) aux width
      dst src rhs src3 value origins state = none := by
  cases invert <;> cases writeback <;> cases immediate <;> rfl

theorem reached (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs src3 : Register) (value : Word) (origins : Origins) (state : State)
    (native : invert = true → immediate = false) :
    dispatch (Arm64Logic.FlagDispatch.operationCode invert writeback immediate) aux width dst src rhs src3 value origins state =
      some (body invert writeback immediate aux width dst src rhs value origins state) := by
  simp only [dispatch, leading_passes, Arm64Logic.FlagDispatch.decode_code invert writeback immediate native]
  rfl

theorem production (invert writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs src3 : Register) (unused3 : Byte) (value : Word) (sourceScalar sourceStack : Bool)
    (origins : Origins) (state : State) (native : invert = true → immediate = false) :
    (dispatch (Arm64Logic.FlagDispatch.operationCode invert writeback immediate) aux width
      dst src rhs src3 value origins state).map (observe origins) =
      Arm64Dispatcher.dispatchThroughFlagLogic (Arm64Logic.FlagDispatch.operationCode invert writeback immediate)
        aux width (Arm64Register.registerCode dst) (Arm64Register.registerCode src) (Arm64Register.registerCode rhs)
        unused3 value sourceScalar sourceStack (image origins state) := by
  rw [reached (native := native), Arm64Dispatcher.flag_logic_reached (native := native)]
  exact congrArg some (body_projects invert writeback immediate aux width dst src rhs value origins state)

theorem production_immediate_unused (writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs src3 : Register) (unusedSrc unused2 unused3 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (Arm64Logic.FlagDispatch.operationCode false writeback true) aux width dst src rhs src3 value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughFlagLogic (Arm64Logic.FlagDispatch.operationCode false writeback true) aux width
      (Arm64Register.registerCode dst) (if writeback then Arm64Register.registerCode src else unusedSrc)
      unused2 unused3 value sourceScalar sourceStack (image origins state) := by
  rw [reached (native := by simp), Arm64Dispatcher.flag_logic_reached (native := by simp)]
  apply congrArg some
  have fixed : Arm64Dispatcher.flagLogicBody false writeback true aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) value (image origins state) =
      Arm64Dispatcher.flagLogicBody false writeback true aux width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (Arm64Register.registerCode 31) value (image origins state) := by cases writeback <;> rfl
  have unused := Arm64Dispatcher.flag_logic_immediate_body writeback aux width dst src unusedSrc unused2 value (image origins state)
  exact (body_projects false writeback true aux width dst src rhs value origins state).trans (fixed.trans unused.symm)

theorem production_register_unused (invert writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst src rhs src3 : Register) (unused2 unused3 : Byte) (value otherValue : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (Arm64Logic.FlagDispatch.operationCode invert writeback false) aux width dst src rhs src3 value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughFlagLogic (Arm64Logic.FlagDispatch.operationCode invert writeback false) aux width
      (Arm64Register.registerCode dst) (Arm64Register.registerCode src)
      (if writeback then Arm64Register.registerCode rhs else unused2) unused3 otherValue
      sourceScalar sourceStack (image origins state) := by
  rw [reached (native := by simp), Arm64Dispatcher.flag_logic_reached (native := by simp)]
  apply congrArg some
  have ignored : Arm64Dispatcher.flagLogicBody invert writeback false aux width (Arm64Register.registerCode dst)
      (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) value (image origins state) =
      Arm64Dispatcher.flagLogicBody invert writeback false aux width (Arm64Register.registerCode dst)
        (Arm64Register.registerCode src) (Arm64Register.registerCode rhs) otherValue (image origins state) := by cases writeback <;> rfl
  have unused := Arm64Dispatcher.flag_logic_register_body invert writeback aux width dst src rhs unused2 otherValue (image origins state)
  exact (body_projects invert writeback false aux width dst src rhs value origins state).trans (ignored.trans unused.symm)

theorem immediate_refines (writeback : Bool) (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register)
    (value : Word) (origins : Origins) (state : State) :
    (dispatch (Arm64Logic.FlagDispatch.operationCode false writeback true) aux width dst src rhs src3 value origins state).map
      (observe origins) = some (Reference.AArch64.step
        (.logicImmediate width (.conjunction false true) (Arm64Move.scalarDestination (if writeback then dst else 31))
          (if writeback then src else dst) value) (image origins state)) := by
  rw [production_immediate_unused writeback aux width dst src rhs src3 255 255 255 value false false origins state]
  exact Arm64Dispatcher.flag_logic_immediate_refines writeback aux width dst src 255 255 255 value false false _

theorem register_refines (invert writeback : Bool) (width : Width) (kind : ShiftKind) (amount : Fin width.bits)
    (dst src rhs src3 : Register) (lane0 lane3 : Byte) (value : Word) (origins : Origins) (state : State) :
    (dispatch (Arm64Logic.FlagDispatch.operationCode invert writeback false)
      (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
      width dst src rhs src3 value origins state).map (observe origins) = some (Reference.AArch64.step
        (.logic (Arm64Logic.FlagDispatch.instruction invert writeback width kind amount dst src rhs)) (image origins state)) := by
  rw [production_register_unused invert writeback _ width dst src rhs src3 255 255 value value false false origins state]
  exact Arm64Dispatcher.flag_logic_register_refines invert writeback width kind amount dst src rhs 255 255 lane0 lane3 value false false _

theorem unmodified_refines (invert writeback : Bool) (width : Width) (dst src rhs src3 : Register)
    (amount lane0 lane3 : Byte) (value : Word) (origins : Origins) (state : State) :
    (dispatch (Arm64Logic.FlagDispatch.operationCode invert writeback false)
      (Arm64Shift.Unary.packedAux .none amount lane0 lane3) width dst src rhs src3 value origins state).map
      (observe origins) = some (Reference.AArch64.step (.logic
        (Arm64Logic.FlagDispatch.instruction invert writeback width .lsl ⟨0, by cases width <;> decide⟩ dst src rhs))
        (image origins state)) := by
  rw [production_register_unused invert writeback _ width dst src rhs src3 255 255 value value false false origins state]
  exact Arm64Dispatcher.flag_logic_unmodified_refines invert writeback width dst src rhs 255 255 amount lane0 lane3 value false false _

theorem earlier_step (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src rhs src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Compare.Binding code aux width dst src rhs src3 value instruction) :
    (dispatch code aux width dst src rhs src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have prior := Compare.step_refines origins state code aux width dst src rhs src3 value instruction binding
  unfold dispatch
  cases leading : Compare.dispatch code aux width dst src rhs src3 value origins state with
  | none => simp [leading] at prior
  | some output => simpa only [leading] using prior

inductive Binding : Nat → BitVec 32 → Width → Register → Register → Register → Register →
    Word → Reference.AArch64.Instruction → Prop where
  | leading (code : Nat) (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register) (value : Word)
      (instruction : Reference.AArch64.Instruction) (binding : Compare.Binding code aux width dst src rhs src3 value instruction) :
      Binding code aux width dst src rhs src3 value instruction
  | immediate (writeback : Bool) (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register) (value : Word) :
      Binding (Arm64Logic.FlagDispatch.operationCode false writeback true) aux width dst src rhs src3 value
        (.logicImmediate width (.conjunction false true) (Arm64Move.scalarDestination (if writeback then dst else 31))
          (if writeback then src else dst) value)
  | register (invert writeback : Bool) (width : Width) (kind : ShiftKind) (amount : Fin width.bits)
      (dst src rhs src3 : Register) (lane0 lane3 : Byte) (value : Word) :
      Binding (Arm64Logic.FlagDispatch.operationCode invert writeback false)
        (Arm64Shift.Unary.packedAux (Arm64Shift.modifier kind) (BitVec.ofNat 8 amount.val) lane0 lane3)
        width dst src rhs src3 value (.logic (Arm64Logic.FlagDispatch.instruction invert writeback width kind amount dst src rhs))
  | unmodified (invert writeback : Bool) (width : Width) (dst src rhs src3 : Register)
      (amount lane0 lane3 : Byte) (value : Word) :
      Binding (Arm64Logic.FlagDispatch.operationCode invert writeback false) (Arm64Shift.Unary.packedAux .none amount lane0 lane3)
        width dst src rhs src3 value (.logic (Arm64Logic.FlagDispatch.instruction invert writeback width .lsl
          ⟨0, by cases width <;> decide⟩ dst src rhs))

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32)
    (width : Width) (dst src rhs src3 : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst src rhs src3 value instruction) :
    (dispatch code aux width dst src rhs src3 value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading code aux width dst src rhs src3 value instruction bound =>
      exact earlier_step origins state code aux width dst src rhs src3 value instruction bound
  | immediate => apply immediate_refines
  | register => apply register_refines
  | unmodified => apply unmodified_refines

def dispatchEmission (nativeAddress : Word → Word) (emission : Branch.Emission) (origins : Origins) (state : State) :
    Option (Transition State) :=
  match emission with
  | .execute code aux width dst src rhs src3 value => dispatch code aux width dst src rhs src3 value origins state
  | _ => Compare.dispatchEmission nativeAddress emission origins state

theorem earlier_emission_step (nativeAddress : Word → Word) (emission : Branch.Emission)
    (origins : Origins) (state : State) (instruction : Reference.AArch64.Instruction)
    (binding : Compare.EmissionBinding nativeAddress state.raw.pc emission instruction) :
    (dispatchEmission nativeAddress emission origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  have prior := Compare.emission_step_refines nativeAddress emission origins state instruction binding
  cases emission with
  | execute code aux width dst src rhs src3 value =>
      change (Compare.dispatch code aux width dst src rhs src3 value origins state).map (observe origins) = _ at prior
      change (dispatch code aux width dst src rhs src3 value origins state).map (observe origins) = _
      unfold dispatch
      cases leading : Compare.dispatch code aux width dst src rhs src3 value origins state with
      | none => simp [leading] at prior
      | some output => simpa only [leading] using prior
  | jump current target => exact prior
  | condition code current fallthrough target => exact prior
  | zero width nonzero src current fallthrough target => exact prior
  | bit nonzero src bit current fallthrough target => exact prior

inductive EmissionBinding (nativeAddress : Word → Word) (pc : Word) : Branch.Emission → Reference.AArch64.Instruction → Prop where
  | leading (emission : Branch.Emission) (instruction : Reference.AArch64.Instruction)
      (binding : Compare.EmissionBinding nativeAddress pc emission instruction) : EmissionBinding nativeAddress pc emission instruction
  | execute (code : Nat) (aux : BitVec 32) (width : Width) (dst src rhs src3 : Register) (value : Word)
      (instruction : Reference.AArch64.Instruction) (binding : Binding code aux width dst src rhs src3 value instruction) :
      EmissionBinding nativeAddress pc (.execute code aux width dst src rhs src3 value) instruction

theorem emission_step_refines (nativeAddress : Word → Word) (emission : Branch.Emission)
    (origins : Origins) (state : State) (instruction : Reference.AArch64.Instruction)
    (binding : EmissionBinding nativeAddress state.raw.pc emission instruction) :
    (dispatchEmission nativeAddress emission origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading emission instruction bound => exact earlier_emission_step nativeAddress emission origins state instruction bound
  | execute code aux width dst src rhs src3 value instruction bound =>
      exact step_refines origins state code aux width dst src rhs src3 value instruction bound

end KProgFormal.Refinement.Arm64RawRegister.FlagLogic

#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.body_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.body_tag_frame
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.leading_passes
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.production
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.production_immediate_unused
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.production_register_unused
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.immediate_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.register_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.unmodified_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.earlier_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.step_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.earlier_emission_step
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagLogic.emission_step_refines


namespace KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic
open Reference
open Reference.AArch64 (Register Gpr RegisterRef Width RegisterExtend)

/-- READ_REG distinguishes SP32 from ZR31 before materializing the tagged word. -/
def readData (origins : Origins) (state : State) : RegisterRef → Word
  | .general r => readRegister origins state (Arm64Move.arithmeticRegister r)
  | .zero => readRegister origins state 31
  | .stack => materialize origins state.raw.sp 4

theorem read_data_refines (origins : Origins) (state : State) (src : RegisterRef) :
    readData origins state src = Arm64Move.readData (image origins state) src := by
  cases src <;> simp only [readData, read_refines, Arm64Move.readData, Arm64Register.read_refines, image, materialize, ↓reduceIte]

def body (subtract writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (value : Word) (origins : Origins) (state : State) :
    Transition State :=
  let lhs := readData origins state src
  let useImmediate := if writeback then
    GeneratedArm64FlagOperand.immediate (if subtract then if immediate then .subsImm else .subsReg
      else if immediate then .addsImm else .addsReg)
    else if subtract then GeneratedArm64FlagOperand.immediate (if immediate then .cmpImm else .cmpReg)
    else immediate
  let right := if useImmediate then value else GeneratedArm64Mod.value
    (Arm64Arithmetic.FlagArithmetic.modifierOf (GeneratedArm64Aux.b1 aux).toNat)
    (readRegister origins state rhs) ((GeneratedArm64Aux.b2 aux).setWidth 64) (Arm64Register.handlerWidth width)
  let result := GeneratedArm64FlagHandler.apply (if subtract then .sub else .add) lhs right
    (Arm64Register.handlerWidth width)
  let next := if writeback then writeRegister state dst result.value width else state
  ⟨advance (Compare.setFlags next (Arm64Logic.flagsWord state.raw.flags result.flags)), [], none⟩

theorem body_projects (subtract writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (value : Word) (origins : Origins) (state : State) :
    observe origins (body subtract writeback immediate aux width dst src rhs value origins state) =
    Arm64Dispatcher.flagArithmeticBody subtract writeback immediate aux width
      (if writeback then Arm64Register.registerCode dst else Arm64Move.Fields.encode src)
      (if writeback then Arm64Move.Fields.encode src else Arm64Register.registerCode rhs)
      (Arm64Register.registerCode rhs) value (image origins state) := by
  cases writeback <;> simp only [body, observe, Bool.false_eq_true, ↓reduceIte, advance_refines,
    Compare.flags_projects, write_refines, read_refines, read_data_refines, Arm64Dispatcher.flagArithmeticBody,
    Arm64Move.Fields.typed_read, Arm64Move.Fields.register_read, Arm64Move.Fields.register_write,
    Arm64Register.read_refines, Arm64Register.write_refines] <;> rfl

theorem body_tag_frame (subtract writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (value : Word) (origins : Origins) (state : State) (r : Gpr) :
    (body subtract writeback immediate aux width dst src rhs value origins state).state.tags r =
      if writeback then (if r.val = dst.val then 0 else state.tags r) else state.tags r := by
  cases writeback <;> simp [body, Compare.setFlags, advance, write_tag_frame]

def dispatch (code : Nat) (aux : BitVec 32) (width : Width) (dst : Register) (src : RegisterRef)
    (rhs : Register) (value : Word) (origins : Origins) (state : State) : Option (Transition State) :=
  (Arm64Arithmetic.FlagArithmetic.decodeOpcode code).map
    (fun choice => body choice.1 choice.2.1 choice.2.2 aux width dst src rhs value origins state)

theorem reached (subtract writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (value : Word) (origins : Origins) (state : State) :
    dispatch (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback immediate) aux width dst src rhs value origins state =
      some (body subtract writeback immediate aux width dst src rhs value origins state) := by
  simp only [dispatch, Arm64Arithmetic.FlagArithmetic.decode_code]; rfl

theorem production (subtract writeback immediate : Bool) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (unused3 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback immediate) aux width dst src rhs value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughFlagArithmetic (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback immediate)
      aux width (if writeback then Arm64Register.registerCode dst else Arm64Move.Fields.encode src)
      (if writeback then Arm64Move.Fields.encode src else Arm64Register.registerCode rhs)
      (Arm64Register.registerCode rhs) unused3 value sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.flag_arithmetic_reached]
  exact congrArg some (body_projects subtract writeback immediate aux width dst src rhs value origins state)

theorem production_immediate_unused (subtract writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (unusedSrc unused2 unused3 : Byte) (value : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback true) aux width dst src rhs value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughFlagArithmetic (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback true)
      aux width (if writeback then Arm64Register.registerCode dst else Arm64Move.Fields.encode src)
      (if writeback then Arm64Move.Fields.encode src else unusedSrc) unused2 unused3 value sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.flag_arithmetic_reached]
  apply congrArg some
  have fixed : Arm64Dispatcher.flagArithmeticBody subtract writeback true aux width
      (if writeback then Arm64Register.registerCode dst else Arm64Move.Fields.encode src)
      (if writeback then Arm64Move.Fields.encode src else Arm64Register.registerCode rhs)
      (Arm64Register.registerCode rhs) value (image origins state) =
    Arm64Dispatcher.flagArithmeticBody subtract writeback true aux width
      (if writeback then Arm64Register.registerCode dst else Arm64Move.Fields.encode src)
      (if writeback then Arm64Move.Fields.encode src else Arm64Register.registerCode 31)
      (Arm64Register.registerCode 31) value (image origins state) := by cases writeback <;> cases subtract <;> rfl
  have unused := Arm64Dispatcher.flag_arithmetic_immediate_body subtract writeback aux width
    (Arm64Move.scalarDestination dst) src unusedSrc unused2 value (image origins state)
  simp only [Arm64Move.Fields.encode_scalar] at unused
  exact (body_projects subtract writeback true aux width dst src rhs value origins state).trans (fixed.trans unused.symm)

theorem production_register_unused (subtract writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (unused2 unused3 : Byte) (value otherValue : Word)
    (sourceScalar sourceStack : Bool) (origins : Origins) (state : State) :
    (dispatch (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false) aux width dst src rhs value origins state).map
      (observe origins) =
    Arm64Dispatcher.dispatchThroughFlagArithmetic (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
      aux width (if writeback then Arm64Register.registerCode dst else Arm64Move.Fields.encode src)
      (if writeback then Arm64Move.Fields.encode src else Arm64Register.registerCode rhs)
      (if writeback then Arm64Register.registerCode rhs else unused2) unused3 otherValue
      sourceScalar sourceStack (image origins state) := by
  rw [reached, Arm64Dispatcher.flag_arithmetic_reached]
  apply congrArg some
  have ignored : Arm64Dispatcher.flagArithmeticBody subtract writeback false aux width
      (if writeback then Arm64Register.registerCode dst else Arm64Move.Fields.encode src)
      (if writeback then Arm64Move.Fields.encode src else Arm64Register.registerCode rhs)
      (Arm64Register.registerCode rhs) value (image origins state) =
    Arm64Dispatcher.flagArithmeticBody subtract writeback false aux width
      (if writeback then Arm64Register.registerCode dst else Arm64Move.Fields.encode src)
      (if writeback then Arm64Move.Fields.encode src else Arm64Register.registerCode rhs)
      (Arm64Register.registerCode rhs) otherValue (image origins state) := by cases writeback <;> cases subtract <;> rfl
  have unused := Arm64Dispatcher.flag_arithmetic_register_body subtract writeback aux width
    (Arm64Move.scalarDestination dst) src rhs unused2 otherValue (image origins state)
  simp only [Arm64Move.Fields.encode_scalar] at unused
  exact (body_projects subtract writeback false aux width dst src rhs value origins state).trans (ignored.trans unused.symm)

theorem immediate_refines (subtract writeback : Bool) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (value : Word) (origins : Origins) (state : State) :
    (dispatch (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback true) aux width dst src rhs value origins state).map
      (observe origins) = some (Reference.AArch64.step (.arithmeticImmediate width subtract true
        (if writeback then Arm64Move.scalarDestination dst else .zero) src value) (image origins state)) := by
  rw [production_immediate_unused subtract writeback aux width dst src rhs 255 255 255 value false false origins state]
  have result := Arm64Dispatcher.flag_arithmetic_immediate_refines subtract writeback aux width
    (Arm64Move.scalarDestination dst) src 255 255 255 value false false (image origins state)
  simpa only [Arm64Move.Fields.encode_scalar] using result

theorem register_refines (subtract writeback : Bool) (width : Width) (kind : Fin 3) (amount : Fin width.bits)
    (dst : Register) (src : RegisterRef) (rhs : Register) (lane0 lane3 : Byte) (value : Word) (origins : Origins) (state : State) :
    (dispatch (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
      (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Arithmetic.registerModifier width kind amount)
        (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src rhs value origins state).map (observe origins) =
      some (Reference.AArch64.step (.arithmeticRegister width subtract true
        (if writeback then Arm64Move.scalarDestination dst else .zero) src rhs kind amount) (image origins state)) := by
  rw [production_register_unused subtract writeback _ width dst src rhs 255 255 value value false false origins state]
  have result := Arm64Dispatcher.flag_arithmetic_register_refines subtract writeback width
    (Arm64Move.scalarDestination dst) src rhs kind amount 255 255 lane0 lane3 value false false (image origins state)
  simpa only [Arm64Move.Fields.encode_scalar] using result

theorem extended_refines (subtract writeback plainSource : Bool) (width : Width) (kind : RegisterExtend) (amount : Fin 5)
    (dst : Register) (src : RegisterRef) (rhs : Register) (lane0 lane3 : Byte) (value : Word) (origins : Origins) (state : State) :
    (dispatch (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
      (Arm64Arithmetic.FlagArithmetic.packedAux
        (Arm64Arithmetic.extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
        (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src rhs value origins state).map (observe origins) =
      some (Reference.AArch64.step (.arithmeticExtended width subtract true
        (if writeback then Arm64Move.scalarDestination dst else .zero) src rhs kind amount) (image origins state)) := by
  rw [production_register_unused subtract writeback _ width dst src rhs 255 255 value value false false origins state]
  have result := Arm64Dispatcher.flag_arithmetic_extended_refines subtract writeback plainSource width
    (Arm64Move.scalarDestination dst) src rhs kind amount 255 255 lane0 lane3 value false false (image origins state)
  simpa only [Arm64Move.Fields.encode_scalar] using result

inductive Binding : Nat → BitVec 32 → Width → Register → RegisterRef → Register → Word →
    Reference.AArch64.Instruction → Prop where
  | immediate (subtract writeback : Bool) (aux : BitVec 32) (width : Width)
      (dst : Register) (src : RegisterRef) (rhs : Register) (value : Word) :
      Binding (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback true) aux width dst src rhs value
        (.arithmeticImmediate width subtract true (if writeback then Arm64Move.scalarDestination dst else .zero) src value)
  | register (subtract writeback : Bool) (width : Width) (kind : Fin 3) (amount : Fin width.bits)
      (dst : Register) (src : RegisterRef) (rhs : Register) (lane0 lane3 : Byte) (value : Word) :
      Binding (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
        (Arm64Arithmetic.FlagArithmetic.packedAux (Arm64Arithmetic.registerModifier width kind amount)
          (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src rhs value
        (.arithmeticRegister width subtract true (if writeback then Arm64Move.scalarDestination dst else .zero) src rhs kind amount)
  | extended (subtract writeback plainSource : Bool) (width : Width) (kind : RegisterExtend) (amount : Fin 5)
      (dst : Register) (src : RegisterRef) (rhs : Register) (lane0 lane3 : Byte) (value : Word) :
      Binding (Arm64Arithmetic.FlagArithmetic.operationCode subtract writeback false)
        (Arm64Arithmetic.FlagArithmetic.packedAux
          (Arm64Arithmetic.extendedModifier width kind (BitVec.ofNat 64 amount.val) plainSource)
          (BitVec.ofNat 8 amount.val) lane0 lane3) width dst src rhs value
        (.arithmeticExtended width subtract true (if writeback then Arm64Move.scalarDestination dst else .zero) src rhs kind amount)

theorem step_refines (origins : Origins) (state : State) (code : Nat) (aux : BitVec 32) (width : Width)
    (dst : Register) (src : RegisterRef) (rhs : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
    (binding : Binding code aux width dst src rhs value instruction) :
    (dispatch code aux width dst src rhs value origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | immediate => apply immediate_refines
  | register => apply register_refines
  | extended => apply extended_refines

/-- Normalized emitted forms retain SP-capable arithmetic operands and the
previous source-label and numeric register forms in one transition relation. -/
inductive Emission where
  | leading (emission : Branch.Emission)
  | arithmetic (code : Nat) (aux : BitVec 32) (width : Width) (dst : Register)
      (src : RegisterRef) (rhs : Register) (value : Word)

def dispatchEmission (nativeAddress : Word → Word) (emission : Emission) (origins : Origins) (state : State) :
    Option (Transition State) :=
  match emission with
  | .leading emission => FlagLogic.dispatchEmission nativeAddress emission origins state
  | .arithmetic code aux width dst src rhs value => dispatch code aux width dst src rhs value origins state

inductive EmissionBinding (nativeAddress : Word → Word) (pc : Word) : Emission → Reference.AArch64.Instruction → Prop where
  | leading (emission : Branch.Emission) (instruction : Reference.AArch64.Instruction)
      (binding : FlagLogic.EmissionBinding nativeAddress pc emission instruction) :
      EmissionBinding nativeAddress pc (.leading emission) instruction
  | arithmetic (code : Nat) (aux : BitVec 32) (width : Width) (dst : Register) (src : RegisterRef)
      (rhs : Register) (value : Word) (instruction : Reference.AArch64.Instruction)
      (binding : Binding code aux width dst src rhs value instruction) :
      EmissionBinding nativeAddress pc (.arithmetic code aux width dst src rhs value) instruction

theorem emission_step_refines (nativeAddress : Word → Word) (emission : Emission) (origins : Origins) (state : State)
    (instruction : Reference.AArch64.Instruction) (binding : EmissionBinding nativeAddress state.raw.pc emission instruction) :
    (dispatchEmission nativeAddress emission origins state).map (observe origins) =
      some (Reference.AArch64.step instruction (image origins state)) := by
  cases binding with
  | leading emission instruction bound => exact FlagLogic.emission_step_refines nativeAddress emission origins state instruction bound
  | arithmetic code aux width dst src rhs value instruction bound =>
      exact step_refines origins state code aux width dst src rhs value instruction bound

end KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic

#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.read_data_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.body_projects
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.body_tag_frame
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.reached
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.production
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.production_immediate_unused
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.production_register_unused
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.immediate_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.register_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.extended_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.step_refines
#print axioms KProgFormal.Refinement.Arm64RawRegister.FlagArithmetic.emission_step_refines
