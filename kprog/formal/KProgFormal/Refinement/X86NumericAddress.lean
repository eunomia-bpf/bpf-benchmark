import KProgFormal.Refinement.EntryEnvironment
import KProgFormal.X86RegWrite
import KProgFormal.Refinement.X86Scalar
import KProgFormal.Generated.GeneratedX86StackIndex
import KProgFormal.Generated.GeneratedPtrAdd

namespace KProgFormal.Refinement.X86NumericAddress
open Reference EntryEnvironment

abbrev NativeWord := Reference.Word

/-- Typed stack aliases address the private arena. Numeric observations replace
only its origin with the invocation's bound native entry-stack origin. -/
def projectAddress (env : Environment) (frame : Frame) (arena pointer : NativeWord) : NativeWord :=
  pointer - arena + base env frame .stack

theorem project_refines (env : Environment) (frame : Frame) (arena offset : NativeWord) :
    projectAddress env frame arena (arena + offset) =
      materialize env frame (.relative .stack offset) := by
  simp only [projectAddress, materialize]
  rw [BitVec.add_comm arena offset, BitVec.add_sub_cancel, BitVec.add_comm]

/-- Scalar RSP writes normalize native bits; typed-alias RSP writes normalize
the corresponding private pointer. Both preserve the actual architectural SP. -/
theorem scalar_stack_write_refines (env : Environment) (frame : Frame) (bits : NativeWord) :
    base env frame .stack + (bits - base env frame .stack) = bits := by
  rw [BitVec.add_comm, BitVec.sub_add_cancel]

theorem alias_stack_write_refines (env : Environment) (frame : Frame)
    (arena offset : NativeWord) :
    base env frame .stack + ((arena + offset) - arena) =
      materialize env frame (.relative .stack offset) := by
  simp only [materialize]
  rw [BitVec.add_comm arena offset, BitVec.add_sub_cancel]

/-- LEA RSP,[RSP+d] must normalize once, after adding to the native value;
normalizing an already relative value subtracts the native base twice. -/
theorem stack_lea_refines (env : Environment) (frame : Frame) (offset delta : NativeWord) :
    base env frame .stack + ((base env frame .stack + offset + delta) -
      base env frame .stack) = base env frame .stack + (offset + delta) := by
  rw [scalar_stack_write_refines, BitVec.add_assoc]

/-- Partial writes merge with native address bits before dropping the pointer
origin. The existing generated write theorem supplies every width and byte lane. -/
theorem partial_write_refines (env : Environment) (frame : Frame)
    (arena offset value : NativeWord) (tag : KProgFormal.Tag)
    (width : KProgFormal.X86Width) (lane : KProgFormal.X86ByteLane) :
    KProgFormal.generatedX86RegWriteAt
      { bits := projectAddress env frame arena (arena + offset), tag := tag } value width lane =
    KProgFormal.x86RegWriteAtSpec
      { bits := materialize env frame (.relative .stack offset), tag := tag } value width lane := by
  rw [project_refines, KProgFormal.x86_reg_write_at_refines]

/-- Guest stores contain native address bytes, never the arena pointer bytes. -/
theorem stored_alias_bytes (env : Environment) (frame : Frame)
    (arena offset : NativeWord) (bytes : Nat) :
    valueBytes (projectAddress env frame arena (arena + offset)) bytes =
      valueBytes (base env frame .stack + offset) bytes := by
  rw [project_refines]
  rfl


/-- Implementation register representation over the already observed native
memory/flags/PC frame. RSP stores an offset, other STACK cells store arena
pointers; other tags are native numeric values in this component. This does
not establish the initial ABI or private-memory relation. -/
structure RegisterState where
  raw : Reference.X86.State
  stack : Reference.X86.Register → Bool

/-- Actual STACK_PTR pointer formation retains all64 offset bits. Its origin
is the biased arena top, never the invocation's native stack origin. -/
theorem stack_pointer_origin (start capacity offset : NativeWord) :
    GeneratedPtrAdd.bits start (GeneratedX86StackIndex.index capacity offset) =
      GeneratedPtrAdd.bits start (GeneratedX86StackIndex.index capacity 0) + offset := by
  simp only [GeneratedPtrAdd.bits, GeneratedX86StackIndex.index, NativeWord, Reference.Word]
  bv_decide

def registerValue (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (reg : Reference.X86.Register) : NativeWord :=
  if reg = 4 then state.raw.gpr reg + base env frame .stack
  else if state.stack reg then projectAddress env frame arena (state.raw.gpr reg)
  else state.raw.gpr reg

def nativeRegisters (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) : Reference.X86.State :=
  { state.raw with gpr := registerValue env frame arena state }

def registerPc (state : RegisterState) (nextPc : NativeWord) : RegisterState :=
  { state with raw := { state.raw with pc := nextPc } }

theorem native_register_pc (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (nextPc : NativeWord) :
    nativeRegisters env frame arena (registerPc state nextPc) =
      { nativeRegisters env frame arena state with pc := nextPc } := rfl

/-- Only byte/word writes materialize the old destination before merging.
Dword/qword bodies ignore it. RSP is normalized back to an offset once. -/
def registerWriteValue (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (value : NativeWord) : NativeWord :=
  let old := match width with
    | .w8 | .w16 => registerValue env frame arena state dst.reg
    | _ => state.raw.gpr dst.reg
  (GeneratedX86RegWrite.writeAt old value (X86Scalar.handlerWidth width) (X86Scalar.lane dst)).bits

def writeRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (value : NativeWord) : RegisterState :=
  let result := registerWriteValue env frame arena state width dst value
  ⟨{ state.raw with gpr := fun r => if r = dst.reg then
      (if r = 4 then result - base env frame .stack else result) else state.raw.gpr r },
    fun r => if r = dst.reg then false else state.stack r⟩

theorem register_write_value (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (value : NativeWord) :
    registerWriteValue env frame arena state width dst value =
      Reference.X86.scalarWriteValue (registerValue env frame arena state dst.reg) value width dst := by
  rw [← X86Scalar.register_write_refines]
  cases width <;> rfl

theorem native_register_write (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (value : NativeWord) :
    nativeRegisters env frame arena (writeRegister env frame arena state width dst value) =
      { nativeRegisters env frame arena state with gpr := (fun r => if r = dst.reg then
          Reference.X86.scalarWriteValue (registerValue env frame arena state r) value width dst
          else registerValue env frame arena state r) } := by
  simp only [nativeRegisters, writeRegister, registerValue]
  congr 1
  funext r
  simp only [registerValue]
  by_cases same : r = dst.reg
  · subst r
    by_cases rsp : dst.reg = 4 <;>
      simp only [rsp, ↓reduceIte, Bool.false_eq_true, register_write_value, registerValue, BitVec.sub_add_cancel]
  · simp only [same, ↓reduceIte]

def readRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (src : Reference.X86.RegisterSlice) : NativeWord :=
  GeneratedX86RegRead.readAt (registerValue env frame arena state src.reg)
    (X86Scalar.handlerWidth width) (X86Scalar.lane src)

theorem native_register_read (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (src : Reference.X86.RegisterSlice) :
    readRegister env frame arena state width src =
      Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) width src :=
  X86Scalar.register_read_refines width src _

/-- Full MOV's destination-RSP arm uses the numeric writer. Other destinations
copy raw pointers/tags; source RSP is first rebound to the private arena. -/
def movePointer (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (dst src : Reference.X86.Register) : RegisterState :=
  if dst = 4 then writeRegister env frame arena state .w64 (.low dst)
      (registerValue env frame arena state src)
  else
    let pointer := if src = 4 then arena + state.raw.gpr src else state.raw.gpr src
    let tag := if src = 4 then true else state.stack src
    ⟨{ state.raw with gpr := fun r => if r = dst then pointer else state.raw.gpr r },
      fun r => if r = dst then tag else state.stack r⟩

theorem register_write64 (old value : NativeWord) (dst : Reference.X86.RegisterSlice) :
    Reference.X86.scalarWriteValue old value .w64 dst = value := by
  rw [← X86Scalar.register_write_refines]
  rfl

theorem native_pointer_move (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (dst src : Reference.X86.Register) :
    nativeRegisters env frame arena (movePointer env frame arena state dst src) =
      { nativeRegisters env frame arena state with gpr := (fun r => if r = dst then
          registerValue env frame arena state src else registerValue env frame arena state r) } := by
  unfold movePointer
  split
  next dstRsp =>
    rw [native_register_write]
    simp only [register_write64, Reference.X86.RegisterSlice.reg]
  next dstOther =>
    simp only [nativeRegisters, registerValue]
    congr 1
    funext r
    simp only [registerValue]
    by_cases same : r = dst
    · subst r
      by_cases srcRsp : src = 4 <;> by_cases tagged : state.stack src = true <;>
        simp [dstOther, srcRsp, tagged, projectAddress, BitVec.add_comm, BitVec.add_sub_cancel] <;>
        rw [BitVec.add_comm arena (state.raw.gpr 4), BitVec.add_sub_cancel]
    · simp only [same, ↓reduceIte]

/-- Sources are captured before writeback, including identical registers and
mixed high/low byte lanes. Only full width uses the pointer-preserving body. -/
def moveRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) : RegisterState :=
  registerPc (if width = .w64 then movePointer env frame arena state dst.reg src.reg
    else writeRegister env frame arena state width dst (readRegister env frame arena state width src)) nextPc

theorem move_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (moveRegister env frame arena state width dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.move width (.register dst) (.register src) nextPc)
        (nativeRegisters env frame arena state) := by
  simp only [moveRegister, native_register_pc, Reference.X86.step, Reference.X86.moveStep,
    Reference.X86.scalarRead, Reference.X86.scalarWrite, List.append_nil]
  by_cases full : width = .w64
  · subst width
    simp only [↓reduceIte, native_pointer_move]
    have read64 : Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w64 src =
        registerValue env frame arena state src.reg := by
      cases src <;> simp [Reference.X86.scalarRegisterValue, Reference.X86.RegisterSlice.shift,
        Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, nativeRegisters]
    rw [read64]
    congr 1
    congr 1
    funext r
    simp only [register_write64, nativeRegisters]
  · simp only [full, ↓reduceIte]
    rw [native_register_write, native_register_read]
    rfl

/-- MOV-immediate uses the same numeric writer for every destination, including
RSP and partial/high-byte cells; all other architectural fields are retained. -/
theorem move_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (value nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (registerPc (writeRegister env frame arena state width dst value) nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.move width (.register dst) (.immediate value) nextPc)
        (nativeRegisters env frame arena state) := by
  simp only [native_register_pc, native_register_write, Reference.X86.step,
    Reference.X86.moveStep, Reference.X86.scalarRead, Reference.X86.scalarWrite, List.append_nil]
  rfl

end KProgFormal.Refinement.X86NumericAddress
