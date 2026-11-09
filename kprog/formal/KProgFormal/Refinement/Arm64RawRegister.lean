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
