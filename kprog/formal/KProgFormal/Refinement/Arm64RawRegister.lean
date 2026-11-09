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
