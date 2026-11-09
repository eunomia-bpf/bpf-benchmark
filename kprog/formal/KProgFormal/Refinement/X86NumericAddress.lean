import KProgFormal.Refinement.X86Call
import KProgFormal.Refinement.X86RepMovs
import KProgFormal.Refinement.X86Xmm0
import KProgFormal.Refinement.X86Push
import KProgFormal.Refinement.X86Divide
import KProgFormal.Refinement.X86Lea
import KProgFormal.Refinement.X86DoubleShift
import KProgFormal.Refinement.X86Mulx
import KProgFormal.Refinement.X86Movx
import KProgFormal.Refinement.X86RotateRight
import KProgFormal.Refinement.X86LegacyShift
import KProgFormal.Refinement.X86Multiply
import KProgFormal.Refinement.X86Unary
import KProgFormal.Refinement.X86Arithmetic
import KProgFormal.X86Immediate
import KProgFormal.Refinement.X86Logic
import KProgFormal.Refinement.X86Endian
import KProgFormal.Refinement.X86Popcount
import KProgFormal.Refinement.X86Condition
import KProgFormal.Refinement.EntryEnvironment
import KProgFormal.X86RegWrite
import KProgFormal.Refinement.X86Scalar
import KProgFormal.Refinement.X86Cmov
import KProgFormal.Refinement.X86Exchange
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


/-- Actual register CMOV body: full-width true copies the pointer through
MOV's RSP-aware arm; false32 still writes/zero-extends the old native value.
False16/64 preserve the raw representation and its STACK predicate. -/
def conditionalMove (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (cc : X86Cond)
    (dst src : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let taken := generatedX86Cond (X86Cmov.handlerFlags state.raw.rflags) cc
  let result := if taken then
    match width with
    | .w64 => movePointer env frame arena state dst src
    | .w32 => writeRegister env frame arena state .w32 (.low dst) (registerValue env frame arena state src)
    | .w16 => writeRegister env frame arena state .w16 (.low dst) (registerValue env frame arena state src)
  else match width with
    | .w32 => writeRegister env frame arena state .w32 (.low dst) (registerValue env frame arena state dst)
    | _ => state
  registerPc result nextPc

/-- The condition is derived from the same complete native RFLAGS. Both
outcomes, every legal CMOV width, STACK-tagged aliases and destination/source
RSP are covered without an assumed branch result or numeric state equality. -/
theorem conditional_move_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (cc : X86Cond)
    (dst src : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (conditionalMove env frame arena state width cc dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.cmov width (X86Cmov.nativeCondition cc) dst (.register src) nextPc)
        (nativeRegisters env frame arena state) := by
  have condition : generatedX86Cond (X86Cmov.handlerFlags state.raw.rflags) cc =
      Reference.X86.condition (nativeRegisters env frame arena state).rflags (X86Cmov.nativeCondition cc) :=
    X86Cmov.condition_refines _ cc
  unfold conditionalMove
  rw [native_register_pc]
  simp only [Reference.X86.step, Reference.X86.readSource]
  rw [← condition]
  cases width <;> cases taken : generatedX86Cond (X86Cmov.handlerFlags state.raw.rflags) cc <;>
    simp only [taken, Bool.false_eq_true, ↓reduceIte]
  all_goals first | rw [native_pointer_move] | rw [native_register_write] | skip
  all_goals simp only [Reference.X86.cmovValue, nativeRegisters]
  all_goals congr 1
  all_goals congr 1
  all_goals funext r
  all_goals by_cases same : r = dst
  all_goals simp only [same, ↓reduceIte, Reference.X86.RegisterSlice.reg,
    Reference.X86.scalarWriteValue, Reference.X86.RegisterSlice.shift,
    Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes]
  all_goals simp only [NativeWord, Reference.Word] at *
  all_goals bv_decide


/-- XCHG captures both operands before either assignment. The snapshot owns
raw pointer/tag/numeric sources; the current state owns the destination and
all other fields. RSP writeback consumes the captured native bits once. -/
def writeCapturedPointer (env : Environment) (frame : Frame) (arena : NativeWord)
    (snapshot current : RegisterState) (dst src : Reference.X86.Register) : RegisterState :=
  if dst = 4 then writeRegister env frame arena current .w64 (.low dst)
      (registerValue env frame arena snapshot src)
  else
    let pointer := if src = 4 then arena + snapshot.raw.gpr src else snapshot.raw.gpr src
    let tag := if src = 4 then true else snapshot.stack src
    ⟨{ current.raw with gpr := fun r => if r = dst then pointer else current.raw.gpr r },
      fun r => if r = dst then tag else current.stack r⟩

theorem native_captured_pointer_write (env : Environment) (frame : Frame) (arena : NativeWord)
    (snapshot current : RegisterState) (dst src : Reference.X86.Register) :
    nativeRegisters env frame arena (writeCapturedPointer env frame arena snapshot current dst src) =
      { nativeRegisters env frame arena current with gpr := (fun r => if r = dst then
          registerValue env frame arena snapshot src else registerValue env frame arena current r) } := by
  unfold writeCapturedPointer
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
      by_cases srcRsp : src = 4 <;> by_cases tagged : snapshot.stack src = true <;>
        simp [dstOther, srcRsp, tagged, projectAddress, BitVec.add_comm, BitVec.add_sub_cancel] <;>
        rw [BitVec.add_comm arena (snapshot.raw.gpr 4), BitVec.add_sub_cancel]
    · simp only [same, ↓reduceIte]

theorem exchange_numeric_write (width : Reference.X86.ScalarWidth) (reg : Reference.X86.Register)
    (old value : NativeWord) :
    Reference.X86.scalarWriteValue old value width (.low reg) = X86Exchange.write width old value := by
  rw [← X86Scalar.register_write_refines]
  cases width <;> rfl

/-- The generated width selector chooses the actual pointer/tag snapshot
body or the two numeric writes. Both source values stay tied to the incoming
state; the second destination merge uses the state after the first write. -/
def exchangeRegisters (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (left right : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let result := match GeneratedX86Xchg.armOf width.bytes with
    | .pointerSwap =>
        let first := writeCapturedPointer env frame arena state state left right
        writeCapturedPointer env frame arena state first right left
    | .subwordSwap =>
        let first := writeRegister env frame arena state width (.low left) (registerValue env frame arena state right)
        writeRegister env frame arena first width (.low right) (registerValue env frame arena state left)
  registerPc result nextPc

/-- Actual register XCHG refines the same canonical exchange step through the
raw RSP/STACK frame for all widths, registers and aliases, including RSP/RSP.
No captured-value equality or disjoint-register premise is supplied. -/
theorem exchange_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (left right : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (exchangeRegisters env frame arena state width left right nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.exchange width (.low left) (.low right) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Exchange.step_refines]
  have values (current : RegisterState) (reg : Reference.X86.Register) :
      registerValue env frame arena current reg = (nativeRegisters env frame arena current).gpr reg := rfl
  cases width <;>
    dsimp only [exchangeRegisters, GeneratedX86Xchg.armOf, GeneratedX86Xchg.fullWidthCode,
      Reference.X86.ScalarWidth.bytes]
  all_goals try simp only [show (1 : Nat) ≠ 8 from by decide, show (2 : Nat) ≠ 8 from by decide,
    show (4 : Nat) ≠ 8 from by decide, ↓reduceIte]
  all_goals rw [native_register_pc]
  all_goals simp only [native_captured_pointer_write, native_register_write, values,
    Reference.X86.RegisterSlice.reg, exchange_numeric_write, X86Exchange.handlerStep]
  all_goals try simp only [show ∀ old value, X86Exchange.write .w64 old value = value from fun _ _ => rfl]
  all_goals rfl


/-- The actual CMOV register arm evaluates the entire AUX word, including
parity conditions, through the generated full-condition table. Unsupported
words take its false default; no AUX truncation or new runtime guard occurs. -/
def conditionalMoveWord (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (aux : BitVec 32)
    (dst src : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let taken := (GeneratedX86FullCondition.eval aux
    (state.raw.rflags.getLsbD 0) (state.raw.rflags.getLsbD 6)
    (state.raw.rflags.getLsbD 7) (state.raw.rflags.getLsbD 11)
    (state.raw.rflags.getLsbD 2)).getD false
  let result := if taken then
    match width with
    | .w64 => movePointer env frame arena state dst src
    | .w32 => writeRegister env frame arena state .w32 (.low dst) (registerValue env frame arena state src)
    | .w16 => writeRegister env frame arena state .w16 (.low dst) (registerValue env frame arena state src)
  else match width with
    | .w32 => writeRegister env frame arena state .w32 (.low dst) (registerValue env frame arena state dst)
    | _ => state
  registerPc result nextPc

/-- All sixteen native conditions through the same raw RSP/STACK frame.
AUX identity is an encoded field fact, not an assumed condition result.
All widths, aliases and incoming flag bits remain arbitrary. -/
theorem conditional_move_word_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (code : Fin 16)
    (dst src : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena
        (conditionalMoveWord env frame arena state width (BitVec.ofNat 32 code.val) dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.cmov width code dst (.register src) nextPc)
        (nativeRegisters env frame arena state) := by
  have condition := X86Condition.condition_refines code state.raw.rflags
  unfold X86Condition.evaluate at condition
  unfold conditionalMoveWord
  rw [condition]
  simp only [Option.getD_some]
  rw [native_register_pc]
  simp only [Reference.X86.step, Reference.X86.readSource]
  have flags : (nativeRegisters env frame arena state).rflags = state.raw.rflags := rfl
  cases width <;> cases taken : Reference.X86.condition state.raw.rflags code <;>
    simp only [flags, taken, Bool.false_eq_true, ↓reduceIte]
  all_goals first | rw [native_pointer_move] | rw [native_register_write] | skip
  all_goals simp only [Reference.X86.cmovValue, nativeRegisters]
  all_goals congr 1
  all_goals congr 1
  all_goals funext r
  all_goals by_cases same : r = dst
  all_goals simp only [same, ↓reduceIte, Reference.X86.RegisterSlice.reg,
    Reference.X86.scalarWriteValue, Reference.X86.RegisterSlice.shift,
    Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes]
  all_goals simp only [NativeWord, Reference.Word] at *
  all_goals bv_decide


/-- Raw flag-cell assignment leaves the RSP/STACK address projection intact. -/
def registerFlags (state : RegisterState) (flags : NativeWord) : RegisterState :=
  { state with raw := { state.raw with rflags := flags } }

theorem native_register_flags (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (flags : NativeWord) :
    nativeRegisters env frame arena (registerFlags state flags) =
      { nativeRegisters env frame arena state with rflags := flags } := rfl

/-- Production BSWAP reads the materialized native value, reverses its bytes
with the generated ladder, then scalarizes the destination (including RSP). -/
def byteSwapRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let value := GeneratedX86Bswap.value (registerValue env frame arena state dst)
    (X86Bzhi.handlerWidth width)
  let scalar := match width with | .w32 => Reference.X86.ScalarWidth.w32 | .w64 => .w64
  registerPc (writeRegister env frame arena state scalar (.low dst) value) nextPc

theorem byte_swap_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (byteSwapRegister env frame arena state width dst nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.byteSwap width dst nextPc) (nativeRegisters env frame arena state) := by
  rw [← X86Endian.swap_step_refines width dst nextPc (nativeRegisters env frame arena state) .scalar]
  unfold byteSwapRegister
  rw [native_register_pc, native_register_write]
  simp only [X86Endian.swapStep, nativeRegisters]
  congr 1
  congr 1
  funext r
  by_cases same : r = dst
  · subst r
    simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
    rw [← X86Scalar.register_write_refines]
    cases width <;> rfl
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]

/-- POPCNT captures the materialized source before destination writeback.
Its generated count and six flag outputs use that same input snapshot. -/
def populationCountRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (dst src : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let source := registerValue env frame arena state src
  let value := X86Popcount.value width source
  let scalar := match width with
    | .w16 => Reference.X86.ScalarWidth.w16 | .w32 => .w32 | .w64 => .w64
  let written := writeRegister env frame arena state scalar (.low dst) value
  registerPc (registerFlags written (X86Popcount.flags width source state.raw.rflags)) nextPc

theorem population_count_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (dst src : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena
        (populationCountRegister env frame arena state width dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.popcount width dst (.register src) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Popcount.step_refines width dst src nextPc (nativeRegisters env frame arena state)]
  unfold populationCountRegister
  rw [native_register_pc, native_register_flags, native_register_write]
  simp only [X86Popcount.handlerStep, nativeRegisters]
  congr 1
  congr 1
  funext r
  by_cases same : r = dst
  · subst r
    simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
    rw [X86Cmov.value_refines]
    cases width <;> simp only [Reference.X86.scalarWriteValue, Reference.X86.cmovValue,
      Reference.X86.RegisterSlice.shift, Reference.X86.ScalarWidth.bits,
      Reference.X86.ScalarWidth.bytes] <;> bv_decide
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]


/-- The generated XOR result on identical source lanes is the same result
as its zero-operand specialization, independently of the pointer encoding. -/
theorem self_xor_value (width : Reference.X86.ScalarWidth) (value : NativeWord) :
    X86Logic.value width .xor value value = X86Logic.value width .xor 0 0 := by
  simp [X86Logic.value_refines, Reference.X86.logicalValue]

/-- Logic flags depend on that result and the same incoming flags; no old
pointer bits or selected condition outcome is an assumption. -/
theorem self_xor_flags (width : Reference.X86.ScalarWidth) (value old : NativeWord) :
    X86Logic.flags width .xor value value old = X86Logic.flags width .xor 0 0 old := by
  simp only [X86Logic.flags, self_xor_value]

/-- C's same-register/same-lane XOR specialization uses its existing generated
ALU, flag and write primitives with literal zero operands. The destination
write still preserves untouched byte/word lanes and normalizes RSP once. -/
def selfXorRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (nextPc : NativeWord) : RegisterState :=
  let value := X86Logic.value width .xor 0 0
  let written := writeRegister env frame arena state width dst value
  registerPc (registerFlags written (X86Logic.flags width .xor 0 0 state.raw.rflags)) nextPc

/-- Whole raw-frame refinement of the actual zero-operand body for a single
native register slice used as both operands. Cross-lane AH/AL forms are not
same-slice inputs. This does not prove a compiler or raw producer gate. -/
theorem self_xor_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (selfXorRegister env frame arena state width dst nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.logic width .xor (.register dst) (.register dst) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Logic.step_refines]
  unfold selfXorRegister
  rw [native_register_pc, native_register_flags, native_register_write]
  simp only [X86Logic.handlerStep, X86Scalar.read_refines, Reference.X86.ScalarDestination.source,
    Reference.X86.scalarRead, Except.bind, Bind.bind, Except.pure, Pure.pure,
    self_xor_value, self_xor_flags, reduceCtorEq, ↓reduceIte,
    X86Scalar.write_refines, Reference.X86.scalarWrite, List.nil_append, List.append_nil]
  rfl


/-- Actual materialized register-logic core. Both lane reads are captured
before flags/writeback; TEST retains the raw register representation, while
AND/OR/XOR scalarize through the same partial/full-width destination writer. -/
def logicRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) : RegisterState :=
  let left := readRegister env frame arena state width dst
  let right := readRegister env frame arena state width src
  let value := X86Logic.value width kind left right
  let written := if kind = .test then state else writeRegister env frame arena state width dst value
  registerPc (registerFlags written (X86Logic.flags width kind left right state.raw.rflags)) nextPc

/-- Whole native-frame lift for all four logical kinds, every width/lane,
all aliases and arbitrary input flags. The two register reads and all flag
outputs are derived, without a scalar-state or result equality premise. -/
theorem logic_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (logicRegister env frame arena state width kind dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.logic width kind (.register dst) (.register src) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Logic.step_refines]
  simp only [logicRegister, native_register_pc, native_register_flags, native_register_read,
    X86Logic.handlerStep, X86Scalar.read_refines, Reference.X86.ScalarDestination.source,
    Reference.X86.scalarRead, X86Scalar.write_refines, Reference.X86.scalarWrite,
    List.nil_append, List.append_nil]
  by_cases test : kind = .test
  · subst kind
    rfl
  · simp only [test, ↓reduceIte, native_register_write]
    rfl


/-- Native immediate identity at the operand width: narrow instructions
ignore higher bits; qword arithmetic consumes a sign-extended low imm32. -/
def ImmediateBinding (width : Reference.X86.ScalarWidth) (raw native : NativeWord) : Prop :=
  native.setWidth width.bits =
    (x86ImmediateValueSpec raw (X86Scalar.handlerWidth width)).setWidth width.bits

theorem logic_value_operand_bits (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (left right native : NativeWord) (bits : right.setWidth width.bits = native.setWidth width.bits) :
    X86Logic.value width kind left right = X86Logic.value width kind left native := by
  simp only [X86Logic.value_refines, Reference.X86.logicalValue, bits]

theorem logic_flags_operand_bits (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (left right native old : NativeWord) (bits : right.setWidth width.bits = native.setWidth width.bits) :
    X86Logic.flags width kind left right old = X86Logic.flags width kind left native old := by
  simp only [X86Logic.flags, logic_value_operand_bits width kind left right native bits]

/-- The immediate logical body consumes the actual generated low-imm32/
sign-extension primitive, then the same materialized lane read/flags/write.
TEST has no data write and retains the incoming raw provenance. -/
def logicImmediate (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (dst : Reference.X86.RegisterSlice) (raw nextPc : NativeWord) : RegisterState :=
  let left := readRegister env frame arena state width dst
  let right := GeneratedX86Immediate.value raw (X86Scalar.handlerWidth width)
  let value := X86Logic.value width kind left right
  let written := if kind = .test then state else writeRegister env frame arena state width dst value
  registerPc (registerFlags written (X86Logic.flags width kind left right state.raw.rflags)) nextPc

/-- The encoded immediate is related only by its operand bits. Its upper
unused bits need not equal an implementation-chosen whole-word value.
All native state and flag outputs are derived from this field identity. -/
theorem logic_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (dst : Reference.X86.RegisterSlice) (raw native nextPc : NativeWord)
    (field : ImmediateBinding width raw native) :
    (⟨nativeRegisters env frame arena (logicImmediate env frame arena state width kind dst raw nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.logic width kind (.register dst) (.immediate native) nextPc)
        (nativeRegisters env frame arena state) := by
  have bits : (GeneratedX86Immediate.value raw (X86Scalar.handlerWidth width)).setWidth width.bits =
      native.setWidth width.bits := by
    rw [x86_immediate_value_refines]
    exact field.symm
  have values (left : NativeWord) := logic_value_operand_bits width kind left _ native bits
  have flags (left old : NativeWord) := logic_flags_operand_bits width kind left _ native old bits
  rw [← X86Logic.step_refines]
  simp only [logicImmediate, native_register_pc, native_register_flags, native_register_read,
    X86Logic.handlerStep, X86Scalar.read_refines, Reference.X86.ScalarDestination.source,
    Reference.X86.scalarRead, X86Scalar.write_refines, Reference.X86.scalarWrite,
    List.nil_append, List.append_nil, values, flags]
  by_cases test : kind = .test
  · subst kind
    rfl
  · simp only [test, ↓reduceIte, native_register_write, values]
    rfl


/-- Generated narrowing depends only on the native operand-width bits. -/
theorem arithmetic_narrow_operand_bits (width : Reference.X86.ScalarWidth)
    (right native : NativeWord) (bits : right.setWidth width.bits = native.setWidth width.bits) :
    X86Arithmetic.narrow width right = X86Arithmetic.narrow width native := by
  cases width <;> simp_all only [X86Arithmetic.narrow, X86Scalar.handlerWidth,
    GeneratedX86Width.narrow, GeneratedX86Width.mask, Reference.X86.ScalarWidth.bits,
    Reference.X86.ScalarWidth.bytes, Nat.reduceMul, Reference.Word] <;> bv_decide

/-- All arithmetic flag helpers first narrow both operands; high unused
immediate bits cannot affect carry, parity, auxiliary carry or other flags. -/
theorem arithmetic_flags_operand_bits (width : Reference.X86.ScalarWidth)
    (kind : Reference.X86.ArithmeticKind) (left right native old : NativeWord)
    (bits : right.setWidth width.bits = native.setWidth width.bits) :
    X86Arithmetic.flags width kind left right old = X86Arithmetic.flags width kind left native old := by
  simp only [X86Arithmetic.flags, X86Arithmetic.value,
    arithmetic_narrow_operand_bits width right native bits]

/-- CMP takes both materialized lane operands before replacing flags. Raw
registers, tags, stack and memory remain exactly as they entered the handler. -/
def compareRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) : RegisterState :=
  let left := readRegister env frame arena state width dst
  let right := readRegister env frame arena state width src
  registerPc (registerFlags state (X86Arithmetic.compareFlags width left right state.raw.rflags)) nextPc

theorem compare_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (compareRegister env frame arena state width dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.arithmetic width .compare (.register dst) (.register src) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Arithmetic.step_refines]
  simp only [compareRegister, X86Arithmetic.compare_flags_eq, native_register_pc, native_register_flags, native_register_read,
    X86Arithmetic.handlerStep, X86Scalar.read_refines, Reference.X86.ScalarDestination.source,
    Reference.X86.scalarRead, List.nil_append, List.append_nil]
  rfl

/-- CMP_IMM uses the same generated low-imm32/sign-extension helper as the
production body, without scalarizing or rewriting its raw destination. -/
def compareImmediate (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (raw nextPc : NativeWord) : RegisterState :=
  let left := readRegister env frame arena state width dst
  let right := GeneratedX86Immediate.value raw (X86Scalar.handlerWidth width)
  registerPc (registerFlags state (X86Arithmetic.compareFlags width left right state.raw.rflags)) nextPc

theorem compare_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (raw native nextPc : NativeWord)
    (field : ImmediateBinding width raw native) :
    (⟨nativeRegisters env frame arena (compareImmediate env frame arena state width dst raw nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.arithmetic width .compare (.register dst) (.immediate native) nextPc)
        (nativeRegisters env frame arena state) := by
  have bits : (GeneratedX86Immediate.value raw (X86Scalar.handlerWidth width)).setWidth width.bits =
      native.setWidth width.bits := by
    rw [x86_immediate_value_refines]
    exact field.symm
  have flags (left old : NativeWord) := arithmetic_flags_operand_bits width .compare left _ native old bits
  rw [← X86Arithmetic.step_refines]
  simp only [compareImmediate, X86Arithmetic.compare_flags_eq, native_register_pc, native_register_flags, native_register_read,
    X86Arithmetic.handlerStep, X86Scalar.read_refines, Reference.X86.ScalarDestination.source,
    Reference.X86.scalarRead, List.nil_append, List.append_nil, flags]
  rfl


/-- The arithmetic result consumes only operand-width immediate bits. -/
theorem arithmetic_value_operand_bits (width : Reference.X86.ScalarWidth) (subtract carry : Bool)
    (left right native : NativeWord) (bits : right.setWidth width.bits = native.setWidth width.bits) :
    X86Arithmetic.value width subtract carry left right = X86Arithmetic.value width subtract carry left native := by
  simp only [X86Arithmetic.value, arithmetic_narrow_operand_bits width right native bits]

/-- ADD/SUB/ADC/SBB read both materialized lanes and the original carry before
flags or destination writeback. The existing scalar writer normalizes RSP
and clears a written STACK alias only after the operands have been captured. -/
def arithmeticRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) : RegisterState :=
  let left := readRegister env frame arena state width dst
  let right := readRegister env frame arena state width src
  let carry := kind.carry state.raw.rflags
  let written := writeRegister env frame arena state width dst
    (X86Arithmetic.value width kind.subtract carry left right)
  registerPc (registerFlags written (X86Arithmetic.flags width kind left right state.raw.rflags)) nextPc

theorem arithmetic_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) (writing : kind ≠ .compare) :
    (⟨nativeRegisters env frame arena (arithmeticRegister env frame arena state width kind dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.arithmetic width kind (.register dst) (.register src) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Arithmetic.step_refines]
  simp only [arithmeticRegister, native_register_pc, native_register_flags, native_register_write,
    native_register_read, X86Arithmetic.handlerStep, X86Scalar.read_refines,
    Reference.X86.ScalarDestination.source, Reference.X86.scalarRead, X86Scalar.write_refines,
    Reference.X86.scalarWrite, List.nil_append, List.append_nil, writing, ↓reduceIte]
  rfl

/-- The immediate arithmetic body uses generated low-imm32/sign-extension
production and samples carry from the same incoming raw flag word. -/
def arithmeticImmediate (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (dst : Reference.X86.RegisterSlice) (raw nextPc : NativeWord) : RegisterState :=
  let left := readRegister env frame arena state width dst
  let right := GeneratedX86Immediate.value raw (X86Scalar.handlerWidth width)
  let carry := kind.carry state.raw.rflags
  let written := writeRegister env frame arena state width dst
    (X86Arithmetic.value width kind.subtract carry left right)
  registerPc (registerFlags written (X86Arithmetic.flags width kind left right state.raw.rflags)) nextPc

theorem arithmetic_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (dst : Reference.X86.RegisterSlice) (raw native nextPc : NativeWord)
    (writing : kind ≠ .compare) (field : ImmediateBinding width raw native) :
    (⟨nativeRegisters env frame arena (arithmeticImmediate env frame arena state width kind dst raw nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.arithmetic width kind (.register dst) (.immediate native) nextPc)
        (nativeRegisters env frame arena state) := by
  have bits : (GeneratedX86Immediate.value raw (X86Scalar.handlerWidth width)).setWidth width.bits =
      native.setWidth width.bits := by
    rw [x86_immediate_value_refines]
    exact field.symm
  have values (left : NativeWord) (carry : Bool) := arithmetic_value_operand_bits width kind.subtract carry left _ native bits
  have flags (left old : NativeWord) := arithmetic_flags_operand_bits width kind left _ native old bits
  rw [← X86Arithmetic.step_refines]
  simp only [arithmeticImmediate, native_register_pc, native_register_flags, native_register_write,
    native_register_read, X86Arithmetic.handlerStep, X86Scalar.read_refines,
    Reference.X86.ScalarDestination.source, Reference.X86.scalarRead, X86Scalar.write_refines,
    Reference.X86.scalarWrite, List.nil_append, List.append_nil, writing, ↓reduceIte, values, flags]
  rfl


/-- INC/DEC/NEG/NOT capture the materialized destination lane before flags
and width-aware writeback. INC/DEC retain incoming CF; NOT retains all flags. -/
def unaryRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.UnaryKind)
    (dst : Reference.X86.RegisterSlice) (nextPc : NativeWord) : RegisterState :=
  let source := readRegister env frame arena state width dst
  let written := writeRegister env frame arena state width dst (X86Unary.value width kind source)
  registerPc (registerFlags written (X86Unary.flags width kind source state.raw.rflags)) nextPc

theorem unary_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.UnaryKind)
    (dst : Reference.X86.RegisterSlice) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (unaryRegister env frame arena state width kind dst nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.unary width kind (.register dst) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Unary.step_refines]
  simp only [unaryRegister, native_register_pc, native_register_flags, native_register_write,
    native_register_read, X86Unary.handlerStep, X86Scalar.read_refines,
    Reference.X86.ScalarDestination.source, Reference.X86.scalarRead, X86Scalar.write_refines,
    Reference.X86.scalarWrite, List.nil_append, List.append_nil]
  rfl


/-- The scalar read/write width for the legal two-operand IMUL forms. -/
def multiplyScalarWidth : Reference.X86.CmovWidth → Reference.X86.ScalarWidth
  | .w16 => .w16 | .w32 => .w32 | .w64 => .w64

/-- Early production lane narrowing retains every bit observed by IMUL. -/
theorem multiply_read_bits (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (reg : Reference.X86.Register) :
    (readRegister env frame arena state (multiplyScalarWidth width) (.low reg)).setWidth width.bits =
      (registerValue env frame arena state reg).setWidth width.bits := by
  cases width <;> simp only [readRegister, multiplyScalarWidth, X86Scalar.handlerWidth, X86Scalar.lane,
    GeneratedX86RegRead.readAt, Reference.X86.RegisterSlice.reg,
    Reference.X86.CmovWidth.bits, Reference.X86.CmovWidth.bytes, Nat.reduceMul] <;> bv_decide

theorem multiply_value_operand_bits (width : Reference.X86.CmovWidth)
    (left right nativeLeft nativeRight : NativeWord)
    (leftBits : left.setWidth width.bits = nativeLeft.setWidth width.bits)
    (rightBits : right.setWidth width.bits = nativeRight.setWidth width.bits) :
    X86Multiply.value width left right = Reference.X86.multiplyValue width nativeLeft nativeRight := by
  simp only [X86Multiply.value_refines, Reference.X86.multiplyValue, leftBits, rightBits]

theorem multiply_flags_operand_bits (width : Reference.X86.CmovWidth)
    (left right nativeLeft nativeRight old : NativeWord)
    (leftBits : left.setWidth width.bits = nativeLeft.setWidth width.bits)
    (rightBits : right.setWidth width.bits = nativeRight.setWidth width.bits) :
    X86Multiply.flags width left right old = Reference.X86.multiplyFlags width nativeLeft nativeRight old := by
  have mixed : Reference.X86.multiplyMixedSign width left right =
      Reference.X86.multiplyMixedSign width nativeLeft nativeRight := by
    cases width <;> simp_all only [Reference.X86.multiplyMixedSign,
      Reference.X86.CmovWidth.bits, Reference.X86.CmovWidth.bytes, Nat.reduceMul] <;> bv_decide
  simp only [X86Multiply.flags_refine, Reference.X86.multiplyFlags, Reference.X86.multiplyOverflow,
    Reference.X86.multiplyMagnitude, mixed, leftBits, rightBits]

theorem multiply_scalar_write (width : Reference.X86.CmovWidth) (reg : Reference.X86.Register)
    (old value : NativeWord) :
    Reference.X86.scalarWriteValue old value (multiplyScalarWidth width) (.low reg) =
      Reference.X86.writeValue width old value := by
  cases width <;> simp only [multiplyScalarWidth, Reference.X86.scalarWriteValue,
    Reference.X86.RegisterSlice.shift, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
    Reference.X86.writeValue, Nat.reduceMul] <;> bv_decide

/-- Two materialized width reads precede product/CF/OF and the scalarizing
write. Source aliases, native RSP and private STACK aliases remain explicit. -/
def multiplyRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (dst src : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let left := readRegister env frame arena state (multiplyScalarWidth width) (.low dst)
  let right := readRegister env frame arena state (multiplyScalarWidth width) (.low src)
  let written := writeRegister env frame arena state (multiplyScalarWidth width) (.low dst)
    (X86Multiply.value width left right)
  registerPc (registerFlags written (X86Multiply.flags width left right state.raw.rflags)) nextPc

theorem multiply_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (dst src : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (multiplyRegister env frame arena state width dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.multiply width dst (.register src) none nextPc)
        (nativeRegisters env frame arena state) := by
  have leftBits := multiply_read_bits env frame arena state width dst
  have rightBits := multiply_read_bits env frame arena state width src
  have value := multiply_value_operand_bits width _ _ _ _ leftBits rightBits
  have flags := multiply_flags_operand_bits width _ _ _ _ state.raw.rflags leftBits rightBits
  simp only [multiplyRegister, native_register_pc, native_register_flags, native_register_write,
    value, flags, multiply_scalar_write, Reference.X86.step, Reference.X86.multiplyStep,
    Reference.X86.readSource]
  congr 1
  congr 1
  funext reg
  by_cases same : reg = dst
  · subst reg
    rfl
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]
    rfl


/-- IMUL_IMM carries a sign-decoded simulator field. Only operand-width bits
must match the immediate encoded by the native instruction. -/
def MultiplyImmediateBinding (width : Reference.X86.CmovWidth) (raw : NativeWord)
    (encoded : BitVec 32) : Prop :=
  (GeneratedX86Signed.signExtend raw (X86Cmov.handlerWidth width)).setWidth width.bits =
    (Reference.X86.multiplyImmediate width encoded).setWidth width.bits

/-- Dedicated three-operand IMUL reads SRC, not the previous destination. -/
def multiplyImmediate (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (dst src : Reference.X86.Register) (raw nextPc : NativeWord) : RegisterState :=
  let left := registerValue env frame arena state src
  let right := GeneratedX86Signed.signExtend raw (X86Cmov.handlerWidth width)
  let written := writeRegister env frame arena state (multiplyScalarWidth width) (.low dst)
    (X86Multiply.value width left right)
  registerPc (registerFlags written (X86Multiply.flags width left right state.raw.rflags)) nextPc

theorem multiply_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (dst src : Reference.X86.Register) (raw : NativeWord) (encoded : BitVec 32) (nextPc : NativeWord)
    (field : MultiplyImmediateBinding width raw encoded) :
    (⟨nativeRegisters env frame arena (multiplyImmediate env frame arena state width dst src raw nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.multiply width dst (.register src) (some encoded) nextPc)
        (nativeRegisters env frame arena state) := by
  have value := multiply_value_operand_bits width (registerValue env frame arena state src) _ _ _ rfl field
  have flags := multiply_flags_operand_bits width (registerValue env frame arena state src) _ _ _ state.raw.rflags rfl field
  simp only [multiplyImmediate, native_register_pc, native_register_flags, native_register_write,
    value, flags, multiply_scalar_write, Reference.X86.step, Reference.X86.multiplyStep,
    Reference.X86.readSource]
  congr 1
  congr 1
  funext reg
  by_cases same : reg = dst
  · subst reg
    rfl
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]
    rfl

/-- The ALU-immediate route's generated helper has exactly the native IMUL
immediate bits, including16-bit narrowing and64-bit imm32 sign extension. -/
theorem multiply_alu_immediate_bits (width : Reference.X86.CmovWidth) (raw : NativeWord) :
    (GeneratedX86Immediate.value raw (X86Scalar.handlerWidth (multiplyScalarWidth width))).setWidth width.bits =
      (Reference.X86.multiplyImmediate width (raw.setWidth 32)).setWidth width.bits := by
  rw [x86_immediate_value_refines]
  cases width <;> simp only [multiplyScalarWidth, X86Scalar.handlerWidth, x86ImmediateValueSpec,
    Reference.X86.multiplyImmediate, Reference.X86.CmovWidth.bits, Reference.X86.CmovWidth.bytes,
    Nat.reduceMul, reduceCtorEq, ↓reduceIte] <;> bv_decide

def multiplyAluImmediate (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (dst : Reference.X86.Register) (raw nextPc : NativeWord) : RegisterState :=
  let left := readRegister env frame arena state (multiplyScalarWidth width) (.low dst)
  let right := GeneratedX86Immediate.value raw (X86Scalar.handlerWidth (multiplyScalarWidth width))
  let written := writeRegister env frame arena state (multiplyScalarWidth width) (.low dst)
    (X86Multiply.value width left right)
  registerPc (registerFlags written (X86Multiply.flags width left right state.raw.rflags)) nextPc

theorem multiply_alu_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (dst : Reference.X86.Register) (raw nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (multiplyAluImmediate env frame arena state width dst raw nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.multiply width dst (.register dst) (some (raw.setWidth 32)) nextPc)
        (nativeRegisters env frame arena state) := by
  have leftBits := multiply_read_bits env frame arena state width dst
  have rightBits := multiply_alu_immediate_bits width raw
  have value := multiply_value_operand_bits width _ _ _ _ leftBits rightBits
  have flags := multiply_flags_operand_bits width _ _ _ _ state.raw.rflags leftBits rightBits
  simp only [multiplyAluImmediate, native_register_pc, native_register_flags, native_register_write,
    value, flags, multiply_scalar_write, Reference.X86.step, Reference.X86.multiplyStep,
    Reference.X86.readSource]
  congr 1
  congr 1
  funext reg
  by_cases same : reg = dst
  · subst reg
    rfl
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]
    rfl


/-- Architectural shifts consume only their width-selected5/6 count bits. -/
def ShiftCountBinding (width : Reference.X86.ScalarWidth) (raw native : NativeWord) : Prop :=
  Reference.X86.legacyCount width raw = Reference.X86.legacyCount width native

theorem shift_value_count (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LegacyShift)
    (source raw native : NativeWord) (field : ShiftCountBinding width raw native) :
    X86LegacyShift.value width kind source raw = X86LegacyShift.value width kind source native := by
  unfold ShiftCountBinding at field
  simp only [X86LegacyShift.value_refines, Reference.X86.legacyShiftValue, field]

theorem shift_flags_count (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LegacyShift)
    (source raw native old : NativeWord) (field : ShiftCountBinding width raw native) :
    X86LegacyShift.flags width kind source raw old = X86LegacyShift.flags width kind source native old := by
  unfold ShiftCountBinding at field
  simp only [X86LegacyShift.flags_refine, Reference.X86.legacyShiftFlags,
    Reference.X86.legacyShiftValue, field]

/-- The real width-aware lane read precedes count/result/flags and the same
numeric writer. All aliases and count-zero partial writes remain observable. -/
def shiftRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LegacyShift)
    (dst : Reference.X86.RegisterSlice) (rawCount nextPc : NativeWord) : RegisterState :=
  let source := readRegister env frame arena state width dst
  let written := writeRegister env frame arena state width dst (X86LegacyShift.value width kind source rawCount)
  registerPc (registerFlags written (X86LegacyShift.flags width kind source rawCount state.raw.rflags)) nextPc

theorem shift_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LegacyShift)
    (dst : Reference.X86.RegisterSlice) (rawCount nativeCount nextPc : NativeWord)
    (field : ShiftCountBinding width rawCount nativeCount) :
    (⟨nativeRegisters env frame arena (shiftRegister env frame arena state width kind dst rawCount nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.legacyShift width kind (.register dst) nativeCount nextPc)
        (nativeRegisters env frame arena state) := by
  have values (source : NativeWord) := shift_value_count width kind source rawCount nativeCount field
  have flags (source old : NativeWord) := shift_flags_count width kind source rawCount nativeCount old field
  rw [← X86LegacyShift.step_refines]
  simp only [shiftRegister, native_register_pc, native_register_flags, native_register_write,
    native_register_read, X86LegacyShift.handlerStep, X86Scalar.read_refines,
    Reference.X86.ScalarDestination.source, Reference.X86.scalarRead, X86Scalar.write_refines,
    Reference.X86.scalarWrite, List.nil_append, List.append_nil, values, flags]
  rfl

theorem shift_immediate_count (width : Reference.X86.ScalarWidth) (raw : NativeWord) :
    ShiftCountBinding width (GeneratedX86Immediate.value raw (X86Scalar.handlerWidth width))
      ((raw.setWidth 8).setWidth 64) := by
  rw [x86_immediate_value_refines]
  cases width <;> simp only [ShiftCountBinding, Reference.X86.legacyCount,
    X86Scalar.handlerWidth, x86ImmediateValueSpec, reduceCtorEq, ↓reduceIte] <;> bv_decide

/-- CL's native count is derived from the SAME pre-state, including when RCX
carries a private STACK alias. No count value or alignment is assumed. -/
theorem shift_register_count (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (reg : Reference.X86.Register) :
    ShiftCountBinding width (readRegister env frame arena state width (.low reg))
      (Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w8 (.low reg)) := by
  rw [native_register_read]
  cases width <;> simp only [ShiftCountBinding, Reference.X86.legacyCount,
    Reference.X86.scalarRegisterValue, Reference.X86.RegisterSlice.shift,
    Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, Nat.reduceMul,
    reduceCtorEq, ↓reduceIte] <;> bv_decide

/-- Classic ROR uses the full already-evaluated IMM operand, not the ALU
immediate decoder. The encoder supplies either imm8 or a pre-write CL read. -/
def rotateRightRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (rawCount nextPc : NativeWord) : RegisterState :=
  let source := readRegister env frame arena state width dst
  let result := X86RotateRight.value width source rawCount
  let written := writeRegister env frame arena state width dst result
  registerPc (registerFlags written (X86RotateRight.flags width result rawCount state.raw.rflags)) nextPc

theorem rotate_right_value_count (width : Reference.X86.ScalarWidth)
    (source raw native : NativeWord) (field : ShiftCountBinding width raw native) :
    X86RotateRight.value width source raw = X86RotateRight.value width source native := by
  unfold ShiftCountBinding at field
  simp only [X86RotateRight.value, X86BmiShift.legacy_ror_value_refines,
    Reference.X86.rotateRightValue, field]

theorem rotate_right_flags_count (width : Reference.X86.ScalarWidth)
    (result raw native old : NativeWord) (field : ShiftCountBinding width raw native) :
    X86RotateRight.flags width result raw old = X86RotateRight.flags width result native old := by
  unfold ShiftCountBinding at field
  simp only [X86RotateRight.flags, X86LegacyShift.count_refines, field]

theorem rotate_right_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst : Reference.X86.RegisterSlice) (rawCount nativeCount nextPc : NativeWord)
    (field : ShiftCountBinding width rawCount nativeCount) :
    (⟨nativeRegisters env frame arena (rotateRightRegister env frame arena state width dst rawCount nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.rotateRight width (.register dst) nativeCount nextPc)
        (nativeRegisters env frame arena state) := by
  have values (source : NativeWord) := rotate_right_value_count width source rawCount nativeCount field
  have flags (source old : NativeWord) := rotate_right_flags_count width source rawCount nativeCount old field
  rw [← X86RotateRight.step_refines]
  simp only [rotateRightRegister, native_register_pc, native_register_flags, native_register_write,
    native_register_read, X86RotateRight.handlerStep, X86Scalar.read_refines,
    Reference.X86.ScalarDestination.source, Reference.X86.scalarRead, X86Scalar.write_refines,
    Reference.X86.scalarWrite, List.nil_append, List.append_nil, flags, values]
  rfl

/-- This is the encoder's actual CL expression. It is sampled before the
ROR writer, including RCX/CH destination aliases and private STACK inputs. -/
theorem rotate_right_cl_operand (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) :
    readRegister env frame arena state .w8 (.low 1) =
      Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w8 (.low 1) :=
  native_register_read env frame arena state .w8 (.low 1)

/-- Full-register reads used by BMI2 preserve neither private arena origins
nor the RSP offset representation: both are materialized before arithmetic. -/
def bmiRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
    (dst src : Reference.X86.Register) (count nextPc : NativeWord) : RegisterState :=
  let source := registerValue env frame arena state src
  let scalar := match width with | .w32 => Reference.X86.ScalarWidth.w32 | .w64 => .w64
  registerPc (writeRegister env frame arena state scalar (.low dst)
    (X86BmiShift.value width kind source count)) nextPc

theorem bmi_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
    (dst src : Reference.X86.Register) (count : Reference.X86.ShiftCount) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (bmiRegister env frame arena state width kind dst src
        (Reference.X86.countValue (nativeRegisters env frame arena state) count) nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.bmiShift width kind dst (.register src) count nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86BmiShift.step_refines width kind dst (.register src) count nextPc
    (nativeRegisters env frame arena state) .scalar]
  unfold bmiRegister
  rw [native_register_pc, native_register_write]
  simp only [X86BmiShift.handlerStep, X86Bt.readOperand, nativeRegisters]
  congr 1
  congr 1
  funext r
  by_cases same : r = dst
  · subst r
    simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
    rw [← X86Scalar.register_write_refines]
    cases width <;> rfl
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]

/-- The production SHIFTX gate samples source and count in the same input
state; all destination/source/count aliases are retained. No flags change. -/
def bmiShiftRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
    (dst src count : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  bmiRegister env frame arena state width kind dst src
    (registerValue env frame arena state count) nextPc

theorem bmi_shift_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
    (dst src count : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (bmiShiftRegister env frame arena state width kind dst src count nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.bmiShift width kind dst (.register src) (.register count) nextPc)
        (nativeRegisters env frame arena state) :=
  bmi_register_frame_refines env frame arena state width kind dst src (.register count) nextPc

/-- ANDN's shared logic intermediate supplies a deterministic representative.
FreshAux below composes both production fresh flag assignments. -/
def andnFlags (width : Reference.X86.BzhiWidth) (result old : NativeWord) : NativeWord :=
  Reference.X86.setFlag (X86Bzhi.liftFlags old (generatedX86AndnFlags result (X86Bzhi.handlerWidth width)))
    2 (GeneratedX86AuxFlags.parity result)

private theorem andn_parity_mask (flags : NativeWord) (pf : Bool) :
    Reference.X86.setFlag flags 2 pf &&& 0xffffffffffffffeb = flags &&& 0xffffffffffffffeb := by
  simp only [Reference.X86.setFlag, NativeWord, Reference.Word]
  bv_decide

theorem andn_flags_observed (width : Reference.X86.BzhiWidth) (result old : NativeWord) :
    andnFlags width result old &&& 0xffffffffffffffeb =
      X86Bzhi.liftFlags old (generatedX86AndnFlags result (X86Bzhi.handlerWidth width)) &&& 0xffffffffffffffeb :=
  andn_parity_mask _ _

def andnRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst first second : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let result := generatedX86AndnResult (registerValue env frame arena state first)
    (registerValue env frame arena state second)
  let scalar := match width with | .w32 => Reference.X86.ScalarWidth.w32 | .w64 => .w64
  registerPc (registerFlags (writeRegister env frame arena state scalar (.low dst) result)
    (andnFlags width result state.raw.rflags)) nextPc

/-- Exact intermediate writeback for the deterministic representative.
The defined-output relation composes with FreshAux production choices below. -/
theorem andn_register_frame_matches (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst first second : Reference.X86.Register) (nextPc : NativeWord) :
    let expected := X86Andn.handlerStep width dst first (.register second) nextPc
      (nativeRegisters env frame arena state) .scalar;
    (⟨nativeRegisters env frame arena (andnRegister env frame arena state width dst first second nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      { expected with state := { expected.state with rflags := (andnFlags width
        (generatedX86AndnResult (registerValue env frame arena state first)
          (registerValue env frame arena state second)) state.raw.rflags) } } := by
  unfold andnRegister
  rw [native_register_pc, native_register_flags, native_register_write]
  simp only [X86Andn.handlerStep, X86Bt.readOperand, nativeRegisters]
  congr 1
  congr 1
  funext r
  by_cases same : r = dst
  · subst r
    simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
    rw [← X86Scalar.register_write_refines]
    cases width <;> rfl
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]

theorem andn_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst first second : Reference.X86.Register) (nextPc : NativeWord) :
    Reference.X86.Step (.andn width dst first (.register second) nextPc) (nativeRegisters env frame arena state)
      ⟨nativeRegisters env frame arena (andnRegister env frame arena state width dst first second nextPc), [], none⟩ := by
  rw [andn_register_frame_matches]
  unfold Reference.X86.Step
  rw [← X86Andn.step_refines width dst first (.register second) nextPc
    (nativeRegisters env frame arena state) .scalar]
  simp only [Reference.X86.matchesTransition, X86Andn.handlerStep, X86Bt.readOperand,
    Reference.X86.definedFlags, Reference.X86.observedRegisters, Option.isSome_none, Bool.false_eq_true,
    ↓reduceIte]
  refine ⟨trivial, trivial, ?_⟩
  congr 1
  exact (andn_flags_observed width _ _).symm

/-- BZHI samples its low count byte before writeback. The deterministic
representative composes with both fresh PF/AF assignments in FreshAux. -/
def bzhiRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst src count : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let source := registerValue env frame arena state src
  let amount := registerValue env frame arena state count &&& 0xff
  let result := generatedX86BzhiResult source amount (X86Bzhi.handlerWidth width)
  let flags := generatedX86BzhiFlags amount result (X86Bzhi.handlerWidth width)
  let scalar := match width with | .w32 => Reference.X86.ScalarWidth.w32 | .w64 => .w64
  registerPc (registerFlags (writeRegister env frame arena state scalar (.low dst) result)
    (X86Bzhi.liftFlags state.raw.rflags flags)) nextPc

theorem bzhi_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst src count : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (bzhiRegister env frame arena state width dst src count nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.bzhi width dst (.register src) count nextPc) (nativeRegisters env frame arena state) := by
  rw [← X86Bzhi.step_refines width dst (.register src) count nextPc (nativeRegisters env frame arena state) .scalar]
  unfold bzhiRegister
  rw [native_register_pc, native_register_flags, native_register_write]
  simp only [X86Bzhi.handlerStep, X86Bt.readOperand, nativeRegisters]
  congr 1
  congr 1
  funext r
  by_cases same : r = dst
  · subst r
    simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
    rw [← X86Scalar.register_write_refines]
    cases width <;> rfl
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]

/-- BT changes only CF: neither register values/tags nor memory are written. -/
def bitTestRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (base : Reference.X86.Register) (index nextPc : NativeWord) : RegisterState :=
  let cf := generatedX86BtCf (registerValue env frame arena state base) index (X86Cmov.handlerWidth width)
  registerPc (registerFlags state (Reference.X86.setFlag state.raw.rflags 0 cf)) nextPc

theorem bit_test_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (base index : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (bitTestRegister env frame arena state width base
        (registerValue env frame arena state index) nextPc), [], none⟩ : Transition Reference.X86.State) =
      Reference.X86.step (.bt width (.register base) (.register index) nextPc) (nativeRegisters env frame arena state) := by
  change _ = Reference.X86.step (X86Bt.instruction width (.registers base index) nextPc) _
  rw [← X86Bt.step_refines]
  rfl

theorem bit_test_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (base : Reference.X86.Register) (index : Byte) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (bitTestRegister env frame arena state width base
        (index.setWidth 64) nextPc), [], none⟩ : Transition Reference.X86.State) =
      Reference.X86.step (.bt width (.register base) (.immediate index) nextPc) (nativeRegisters env frame arena state) := by
  change _ = Reference.X86.step (X86Bt.instruction width (.immediate base index) nextPc) _
  rw [← X86Bt.step_refines]
  rfl

/-- The actual SETCC register macro decodes the low AUX payload byte through
FULL_CONDITION_MATCHED and writes only the selected byte; FLAGS is unused. -/
def setConditionRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (payload : BitVec 32) (dst : Reference.X86.RegisterSlice)
    (nextPc : NativeWord) : RegisterState :=
  let matched := GeneratedX86FullCondition.matched (payload.setWidth 8)
  let taken := (GeneratedX86FullCondition.eval (matched.setWidth 32)
    (state.raw.rflags.getLsbD 0) (state.raw.rflags.getLsbD 6) (state.raw.rflags.getLsbD 7)
    (state.raw.rflags.getLsbD 11) (state.raw.rflags.getLsbD 2)).getD false
  registerPc (writeRegister env frame arena state .w8 dst (if taken then 1 else 0)) nextPc

theorem set_condition_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (code : Fin 16) (dst : Reference.X86.RegisterSlice) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (setConditionRegister env frame arena state
        (BitVec.ofNat 32 code.val) dst nextPc), [], none⟩ : Transition Reference.X86.State) =
      Reference.X86.step (.setcc code (.register dst) nextPc) (nativeRegisters env frame arena state) := by
  have low : (BitVec.ofNat 32 code.val).setWidth 8 = BitVec.ofNat 8 code.val := by simp
  have fits : (BitVec.ofNat 16 code.val).setWidth 32 = BitVec.ofNat 32 code.val := by
    apply BitVec.eq_of_toNat_eq
    simp [BitVec.toNat_setWidth, Nat.mod_eq_of_lt (show code.val < 65536 by omega),
      Nat.mod_eq_of_lt (show code.val < 4294967296 by omega)]
  have condition := X86Condition.condition_refines code state.raw.rflags
  unfold X86Condition.evaluate at condition
  simp only [setConditionRegister, low, X86Condition.matched_code, fits, condition, Option.getD_some]
  rw [native_register_pc, native_register_write]
  simp only [Reference.X86.step, Reference.X86.scalarWrite]
  rfl

/-- MOVX captures its encoded source lane before the numeric destination
writer. The complete raw frame includes RSP offsets and STACK aliases. -/
def extendRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (sourceWidth targetWidth : Reference.X86.ScalarWidth)
    (signed : Bool) (dst : Reference.X86.Register) (source : Reference.X86.RegisterSlice)
    (nextPc : NativeWord) : RegisterState :=
  let operand := readRegister env frame arena state sourceWidth source
  let result := X86Movx.value sourceWidth signed operand
  registerPc (writeRegister env frame arena state targetWidth (.low dst) result) nextPc

/-- Extension preserves flags, memory, ordered effects and every other
register for arbitrary source/destination aliases and projected stack values. -/
theorem extend_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (sourceWidth targetWidth : Reference.X86.ScalarWidth)
    (signed : Bool) (dst : Reference.X86.Register) (source : Reference.X86.RegisterSlice)
    (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena
      (extendRegister env frame arena state sourceWidth targetWidth signed dst source nextPc), [], none⟩ :
        Transition Reference.X86.State) =
      Reference.X86.step (.extend sourceWidth targetWidth signed dst (.register source) nextPc)
        (nativeRegisters env frame arena state) := by
  unfold extendRegister
  rw [native_register_pc, native_register_write, native_register_read, X86Movx.value_refines]
  simp only [Reference.X86.step, Reference.X86.scalarRead,
    Reference.X86.RegisterSlice.reg, nativeRegisters]
  congr 2
  funext r
  by_cases same : r = dst <;> simp [same]

def mulxScalarWidth : Reference.X86.BzhiWidth → Reference.X86.ScalarWidth
  | .w32 => .w32 | .w64 => .w64

theorem mulx_scalar_write (width : Reference.X86.BzhiWidth) (dst : Reference.X86.Register)
    (old value : NativeWord) :
    Reference.X86.scalarWriteValue old value (mulxScalarWidth width) (.low dst) =
      X86Mulx.write width old value := by
  rw [← X86Scalar.register_write_refines]
  cases width <;> rfl

/-- Each product half already occupies its full architectural output width.
The raw writer scalarizes its destination and projects RSP back to its offset. -/
theorem native_mulx_half_write (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst : Reference.X86.Register) (left right : NativeWord) (upper : Bool) :
    nativeRegisters env frame arena (writeRegister env frame arena state (mulxScalarWidth width)
      (.low dst) (if upper then (Reference.X86.mulxParts width left right).2
        else (Reference.X86.mulxParts width left right).1)) =
      { nativeRegisters env frame arena state with gpr := fun r => if r = dst then
          (if upper then (Reference.X86.mulxParts width left right).2
            else (Reference.X86.mulxParts width left right).1)
          else (nativeRegisters env frame arena state).gpr r } := by
  rw [native_register_write]
  simp only [Reference.X86.RegisterSlice.reg, nativeRegisters]
  congr 1
  funext r
  by_cases same : r = dst
  · subst r
    simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte, mulx_scalar_write]
    cases upper
    · exact (X86Mulx.writes_parts width _ left right).1
    · exact (X86Mulx.writes_parts width _ left right).2
  · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]

theorem native_mulx_low_write (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst : Reference.X86.Register) (left right : NativeWord) :
    nativeRegisters env frame arena (writeRegister env frame arena state (mulxScalarWidth width)
      (.low dst) (Reference.X86.mulxParts width left right).1) =
      { nativeRegisters env frame arena state with gpr := fun r => if r = dst then
          (Reference.X86.mulxParts width left right).1
          else (nativeRegisters env frame arena state).gpr r } := by
  simpa only [Bool.true_eq, Bool.false_eq_true, ↓reduceIte] using
    native_mulx_half_write env frame arena state width dst left right false

theorem native_mulx_high_write (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst : Reference.X86.Register) (left right : NativeWord) :
    nativeRegisters env frame arena (writeRegister env frame arena state (mulxScalarWidth width)
      (.low dst) (Reference.X86.mulxParts width left right).2) =
      { nativeRegisters env frame arena state with gpr := fun r => if r = dst then
          (Reference.X86.mulxParts width left right).2
          else (nativeRegisters env frame arena state).gpr r } := by
  simpa only [Bool.true_eq, Bool.false_eq_true, ↓reduceIte] using
    native_mulx_half_write env frame arena state width dst left right true

/-- The C limb/product arms capture both operands before the low assignment.
The high assignment uses the updated destination state; high=low retains high. -/
def mulxRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (high low source : Reference.X86.Register) (nextPc : NativeWord) : RegisterState :=
  let product := X86Mulx.parts width (registerValue env frame arena state 2)
    (registerValue env frame arena state source)
  let first := writeRegister env frame arena state (mulxScalarWidth width) (.low low) product.1
  let second := writeRegister env frame arena first (mulxScalarWidth width) (.low high) product.2
  registerPc second nextPc

theorem mulx_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (high low source : Reference.X86.Register) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (mulxRegister env frame arena state width high low source nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.mulx width high low (.register source) nextPc)
        (nativeRegisters env frame arena state) := by
  unfold mulxRegister
  rw [X86Mulx.parts_refine, native_register_pc]
  rw [native_mulx_high_write, native_mulx_low_write]
  rfl

theorem double_shift_step_count_byte (width : Reference.X86.CmovWidth) (left : Bool)
    (dst source : Reference.X86.Register) (count nextPc : NativeWord) (state : Reference.X86.State) :
    Reference.X86.step (.doubleShift width left dst source count nextPc) state =
      Reference.X86.step (.doubleShift width left dst source ((count.setWidth 8).setWidth 64) nextPc) state := by
  have amount : Reference.X86.doubleShiftCount count width.bits =
      Reference.X86.doubleShiftCount ((count.setWidth 8).setWidth 64) width.bits := by
    cases width <;> simp only [Reference.X86.doubleShiftCount, Reference.X86.CmovWidth.bits,
      Reference.X86.CmovWidth.bytes, Nat.reduceMul, Reference.Word] <;> bv_decide
  simp only [Reference.X86.step, Reference.X86.doubleShiftStep, Reference.X86.doubleShiftFlags,
    Reference.X86.doubleShiftValue, amount]

theorem double_shift_zero_write (width : Reference.X86.CmovWidth) (left : Bool)
    (old source count : NativeWord) (zero : Reference.X86.doubleShiftCount count width.bits = 0) :
    Reference.X86.writeValue width old
      (Reference.X86.doubleShiftValue left old source count width.bits) =
      if width = .w32 then (old.setWidth 32).setWidth 64 else old := by
  simp only [Reference.X86.doubleShiftValue, zero]
  cases width <;> cases left <;>
    simp only [Reference.X86.writeValue, Reference.X86.CmovWidth.bits,
      Reference.X86.CmovWidth.bytes, Nat.reduceMul, reduceCtorEq, ↓reduceIte, Reference.Word] <;> bv_decide

/-- Zero count preserves the physical representation at16/64 bits and uses
only the architectural zero-extending numeric write at32 bits. -/
def doubleShiftRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (left : Bool)
    (dst source : Reference.X86.Register) (count nextPc : NativeWord) : RegisterState :=
  let old := registerValue env frame arena state dst
  let rhs := registerValue env frame arena state source
  let amount := GeneratedX86ShiftCount.count count (X86Cmov.handlerWidth width)
  if amount.toNat = 0 then
    registerPc (if width = .w32 then writeRegister env frame arena state .w32 (.low dst) old
      else state) nextPc
  else
    let result := X86DoubleShift.value width left old rhs count
    let written := writeRegister env frame arena state (multiplyScalarWidth width) (.low dst) result
    registerPc (registerFlags written (X86DoubleShift.flags width left old result count state.raw.rflags)) nextPc

theorem double_shift_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (left : Bool)
    (dst source : Reference.X86.Register) (count nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena
      (doubleShiftRegister env frame arena state width left dst source count nextPc), [], none⟩ :
        Transition Reference.X86.State) =
      Reference.X86.step (.doubleShift width left dst source ((count.setWidth 8).setWidth 64) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← double_shift_step_count_byte]
  by_cases zero : (GeneratedX86ShiftCount.count count (X86Cmov.handlerWidth width)).toNat = 0
  · have zeroWord : Reference.X86.doubleShiftCount count width.bits = 0 := by
      rw [← X86DoubleShift.count_refines]
      apply BitVec.eq_of_toNat_eq
      simpa using zero
    have flagsZero (old a b : NativeWord) : Reference.X86.doubleShiftFlags width left a b count old = old := by
      simp [Reference.X86.doubleShiftFlags, zeroWord]
    simp only [doubleShiftRegister, zero, ↓reduceIte]
    cases width with
    | w16 =>
        simp only [reduceCtorEq, ↓reduceIte, native_register_pc, Reference.X86.step,
          Reference.X86.doubleShiftStep, flagsZero, double_shift_zero_write _ _ _ _ _ zeroWord]
        simp only [nativeRegisters]
        congr 2
        funext r
        by_cases same : r = dst
        · subst r
          simp only [↓reduceIte]
          simpa only [reduceCtorEq, ↓reduceIte] using
            (double_shift_zero_write _ left (registerValue env frame arena state dst)
              (registerValue env frame arena state source) count zeroWord).symm
        · simp [same]
    | w32 =>
        simp only [↓reduceIte]
        rw [native_register_pc, native_register_write]
        simp only [Reference.X86.step, Reference.X86.doubleShiftStep, flagsZero,
          double_shift_zero_write _ _ _ _ _ zeroWord, nativeRegisters]
        congr 2
        funext r
        by_cases same : r = dst
        · subst r
          simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
          rw [double_shift_zero_write _ left (registerValue env frame arena state dst)
            (registerValue env frame arena state source) count zeroWord]
          simp only [↓reduceIte]
          rw [← X86Scalar.register_write_refines]
          simp only [X86Scalar.handlerWidth, X86Scalar.lane, GeneratedX86RegWrite.writeAt,
            GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits, Reference.Word]
          bv_decide
        · simp [Reference.X86.RegisterSlice.reg, same]
    | w64 =>
        simp only [reduceCtorEq, ↓reduceIte, native_register_pc, Reference.X86.step,
          Reference.X86.doubleShiftStep, flagsZero, double_shift_zero_write _ _ _ _ _ zeroWord]
        simp only [nativeRegisters]
        congr 2
        funext r
        by_cases same : r = dst
        · subst r
          simp only [↓reduceIte]
          simpa only [reduceCtorEq, ↓reduceIte] using
            (double_shift_zero_write _ left (registerValue env frame arena state dst)
              (registerValue env frame arena state source) count zeroWord).symm
        · simp [same]
  · simp only [doubleShiftRegister, zero, ↓reduceIte]
    rw [native_register_pc, native_register_flags, native_register_write]
    simp only [multiply_scalar_write, X86DoubleShift.value_refines, X86DoubleShift.flags_refine,
      Reference.X86.step, Reference.X86.doubleShiftStep, Reference.X86.RegisterSlice.reg, nativeRegisters]

def leaBaseValue (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (source : Option Reference.X86.Register) : NativeWord :=
  (source.map (registerValue env frame arena state)).getD 0

/-- Full-width LEA preserves the source pointer origin, rebinds an RSP source
through the arena, and normalizes an RSP destination through the numeric writer. -/
def leaPointer (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (dst : Reference.X86.Register)
    (source : Option Reference.X86.Register) (offset : NativeWord) : RegisterState :=
  if dst = 4 then writeRegister env frame arena state .w64 (.low dst)
    (leaBaseValue env frame arena state source + offset)
  else
    let rawBase := (source.map state.raw.gpr).getD 0
    let stackReference := decide (source = some 4)
    let pointer := if stackReference then arena + (rawBase + offset) else rawBase + offset
    let tag := if stackReference then true else (source.map state.stack).getD false
    ⟨{ state.raw with gpr := fun r => if r = dst then pointer else state.raw.gpr r },
      fun r => if r = dst then tag else state.stack r⟩

theorem native_lea_pointer (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (dst : Reference.X86.Register)
    (source : Option Reference.X86.Register) (offset : NativeWord) :
    nativeRegisters env frame arena (leaPointer env frame arena state dst source offset) =
      { nativeRegisters env frame arena state with gpr := fun r =>
          if r = dst then (leaBaseValue env frame arena state source + offset)
          else (nativeRegisters env frame arena state).gpr r } := by
  unfold leaPointer
  split
  next dstRsp =>
    rw [native_register_write]
    simp only [Reference.X86.RegisterSlice.reg, register_write64]
    rfl
  next dstOther =>
    simp only [nativeRegisters]
    congr 1
    funext r
    by_cases same : r = dst
    · subst r
      cases source with
      | none => simp [leaBaseValue, registerValue, dstOther]
      | some src =>
          by_cases srcRsp : src = 4
          · subst src
            simp [leaBaseValue, registerValue, dstOther, projectAddress]
            simp only [NativeWord, Reference.Word]
            bv_decide
          · by_cases tagged : state.stack src = true <;>
              simp [leaBaseValue, registerValue, dstOther, srcRsp, tagged, projectAddress] <;>
              simp only [NativeWord, Reference.Word] <;> bv_decide
    · simp [registerValue, same]

/-- Address operands and their index contribution are captured before either
pointer/tag transfer or the narrow numeric write. Flags and memory are retained. -/
def leaRegister (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (dst : Reference.X86.Register)
    (source : Option Reference.X86.Register) (offset nextPc : NativeWord) : RegisterState :=
  registerPc (if width = .w64 then leaPointer env frame arena state dst source offset
    else writeRegister env frame arena state (multiplyScalarWidth width) (.low dst)
      (leaBaseValue env frame arena state source + offset)) nextPc

theorem lea_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (dst : Reference.X86.Register)
    (source : Option Reference.X86.Register) (offset nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (leaRegister env frame arena state width dst source offset nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.lea width dst (leaBaseValue env frame arena state source + offset) nextPc)
        (nativeRegisters env frame arena state) := by
  unfold leaRegister
  cases width <;> simp only [reduceCtorEq, ↓reduceIte]
  all_goals rw [native_register_pc]
  all_goals first | rw [native_lea_pointer] | rw [native_register_write]
  all_goals simp only [multiply_scalar_write, Reference.X86.step, Reference.X86.RegisterSlice.reg, nativeRegisters]
  all_goals congr 2
  all_goals funext r
  all_goals by_cases same : r = dst
  all_goals simp [same, Reference.X86.writeValue, Reference.Word]

/-- The existing32-bit LEA writer implements address-size32 followed by a
64-bit destination write, retaining the canonical zero-extended address. -/
theorem lea_address32_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (dst : Reference.X86.Register)
    (source : Option Reference.X86.Register) (offset nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (leaRegister env frame arena state .w32 dst source offset nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.lea .w64 dst
        (((leaBaseValue env frame arena state source + offset).setWidth 32).setWidth 64) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [lea_register_frame_refines]
  simp [Reference.X86.step, Reference.X86.writeValue]

/-- DIV captures its divisor and both implicit accumulator halves before
writeback. Narrow cases and the zero-high qword fast path use native division;
the remaining qword path uses the verified restoring long-division loop. -/
def divideResult (width : Reference.X86.ScalarWidth) (high low divisor : Nat) : Nat × Nat :=
  if width = .w64 ∧ high ≠ 0 then X86Divide.longDivide width.bits high low divisor
  else ((high * X86Divide.base width + low) / divisor,
        (high * X86Divide.base width + low) % divisor)

theorem divide_result_refines (width : Reference.X86.ScalarWidth) (high low divisor : Nat)
    (highBound : high < divisor) (lowBound : low < X86Divide.base width) :
    divideResult width high low divisor = X86Divide.longDivide width.bits high low divisor := by
  unfold divideResult
  split
  · rfl
  · have result := X86Divide.longDivide_quot_rem width.bits high low divisor highBound lowBound
    exact Prod.ext result.1.symm result.2.symm

/-- The divisor is narrowed by its actual operand width. Zero divisors and
high-half overflow return the unchanged frame with the canonical divide fault.
Successful byte DIV packs AH:AL; wider cases write RAX and then RDX. -/
def divideWord (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (operand nextPc : NativeWord) : Transition Reference.X86.State :=
  let native := nativeRegisters env frame arena state
  let divisor := operand.toNat % X86Divide.base width
  let high := X86Divide.high width native
  let low := X86Divide.low width native
  if divisor = 0 ∨ divisor ≤ high then ⟨native, [.fault .divide], some .divide⟩
  else
    let result := divideResult width high low divisor
    let written := if width = .w8 then
      writeRegister env frame arena state .w16 (.low 0) (BitVec.ofNat 64 (256 * result.2 + result.1))
    else
      writeRegister env frame arena
        (writeRegister env frame arena state width (.low 0) (BitVec.ofNat 64 result.1))
        width (.low 2) (BitVec.ofNat 64 result.2)
    ⟨nativeRegisters env frame arena (registerPc written nextPc), [], none⟩

theorem divide_narrow_nat (width : Reference.X86.ScalarWidth) (operand : NativeWord) :
    (((operand.setWidth width.bits).setWidth 64).toNat % X86Divide.base width) =
      operand.toNat % X86Divide.base width := by
  cases width <;> simp [X86Divide.base, Reference.X86.ScalarWidth.bits,
    Reference.X86.ScalarWidth.bytes, BitVec.toNat_setWidth, Nat.mod_mod]

theorem divide_word_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (operand nextPc : NativeWord) :
    divideWord env frame arena state width operand nextPc =
      Reference.X86.step (.divide width (.immediate operand) nextPc)
        (nativeRegisters env frame arena state) := by
  have readWrite (current : RegisterState) (access : Reference.X86.ScalarWidth)
      (destination : Reference.X86.RegisterSlice) (value : NativeWord) (reg : Reference.X86.Register) :
      registerValue env frame arena (writeRegister env frame arena current access destination value) reg =
        if reg = destination.reg then Reference.X86.scalarWriteValue
          (registerValue env frame arena current reg) value access destination
        else registerValue env frame arena current reg :=
    congrArg (fun native => native.gpr reg) (native_register_write env frame arena current access destination value)
  rw [← X86Divide.step_refines]
  simp only [divideWord, X86Divide.handlerStep, X86Scalar.read_refines,
    Reference.X86.scalarRead, divide_narrow_nat]
  by_cases fault : operand.toNat % X86Divide.base width = 0 ∨
      operand.toNat % X86Divide.base width ≤ X86Divide.high width (nativeRegisters env frame arena state)
  · simp [fault]
  · have highBound : X86Divide.high width (nativeRegisters env frame arena state) <
        operand.toNat % X86Divide.base width := by omega
    rw [if_neg fault, if_neg fault,
      divide_result_refines width _ _ _ highBound (X86Divide.low_lt width _)]
    by_cases byte : width = .w8
    · simp only [byte, ↓reduceIte, native_register_pc, native_register_write, X86Divide.write_refines]
      rfl
    · simp only [byte, ↓reduceIte, native_register_pc, native_register_write, readWrite, X86Divide.write_refines]
      congr 2
      funext reg
      by_cases low : reg = 0 <;> by_cases high : reg = 2 <;>
        simp_all [Reference.X86.RegisterSlice.reg, Reference.X86.scalarWriteValue, Reference.X86.RegisterSlice.shift, nativeRegisters]

/-- Present DIV source cells are sampled from the same native input frame,
including RAX, RDX and RSP aliases, before either implicit result write. -/
theorem divide_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (source : Reference.X86.Register) (nextPc : NativeWord) :
    divideWord env frame arena state width (registerValue env frame arena state source) nextPc =
      Reference.X86.step (.divide width (.register (.low source)) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [divide_word_frame_refines]
  have divisor : (Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state)
      width (.low source)).toNat % X86Divide.base width =
      (registerValue env frame arena state source).toNat % X86Divide.base width := by
    simpa [Reference.X86.scalarRegisterValue, Reference.X86.RegisterSlice.shift,
      Reference.X86.RegisterSlice.reg, nativeRegisters] using
      divide_narrow_nat width (registerValue env frame arena state source)
  simp only [X86Divide.base] at divisor
  simp only [Reference.X86.step, Reference.X86.divideStep, Reference.X86.scalarRead, divisor]

/-- Captured register-lane operands retain the native read from the same
input state. This includes the producer's SRC_NONE/IMM high-byte encoding. -/
theorem divide_captured_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (source : Reference.X86.RegisterSlice) (nextPc : NativeWord) :
    divideWord env frame arena state width (readRegister env frame arena state width source) nextPc =
      Reference.X86.step (.divide width (.register source) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [divide_word_frame_refines, native_register_read]
  rfl

/-- Guest memory is already observed at native addresses in this component.
The arena-memory/permission relation is supplied by the invocation ABI layer. -/
def registerMemory (state : RegisterState) (memory : Memory) : RegisterState :=
  { state with raw := { state.raw with memory := memory } }

theorem native_register_memory (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (memory : Memory) :
    nativeRegisters env frame arena (registerMemory state memory) =
      { nativeRegisters env frame arena state with memory := memory } := rfl

/-- Stack adjustment operates on the complete wrapping offset, preserving
other cells and their pointer provenance. -/
def advanceStack (state : RegisterState) (delta : NativeWord) : RegisterState :=
  { state with raw := { state.raw with gpr := fun r =>
      if r = 4 then (state.raw.gpr r) + delta else state.raw.gpr r } }

theorem native_advance_stack (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (delta : NativeWord) :
    nativeRegisters env frame arena (advanceStack state delta) =
      { nativeRegisters env frame arena state with gpr := fun r =>
          if r = 4 then (nativeRegisters env frame arena state).gpr 4 + delta
          else (nativeRegisters env frame arena state).gpr r } := by
  simp only [nativeRegisters, advanceStack]
  congr 1
  funext reg
  by_cases rsp : reg = 4
  · subst reg
    simp only [registerValue, advanceStack, ↓reduceIte]
    simp only [NativeWord, Reference.Word]
    bv_decide
  · simp [registerValue, advanceStack, rsp]

theorem register_value_advance_stack (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (delta : NativeWord) (reg : Reference.X86.Register) :
    registerValue env frame arena (advanceStack state delta) reg =
      if reg = 4 then registerValue env frame arena state 4 + delta
      else registerValue env frame arena state reg :=
  congrArg (fun result => result.gpr reg) (native_advance_stack env frame arena state delta)

/-- PUSH captures its numeric source before decrementing the raw RSP offset.
The generated byte store preserves the rest of the observed guest memory. -/
def pushValueFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth)
    (value nextPc : NativeWord) : Transition Reference.X86.State :=
  let address := registerValue env frame arena state 4 - BitVec.ofNat 64 width.bytes
  if permitted state.raw.memory.writable address width.bytes then
    let memory := X86Push.store width state.raw.memory address value
    let advanced := advanceStack state (-BitVec.ofNat 64 width.bytes)
    ⟨nativeRegisters env frame arena (registerPc (registerMemory advanced memory) nextPc),
      [.memory .write address (valueBytes value width.bytes) true], none⟩
  else ⟨nativeRegisters env frame arena state,
    [.fault (.write address width.bytes)], some (.write address width.bytes)⟩

theorem push_value_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth) (value nextPc : NativeWord) :
    pushValueFrame env frame arena state width value nextPc =
      Reference.X86.pushTransfer width value [] nextPc (nativeRegisters env frame arena state) := by
  unfold pushValueFrame
  simp only [native_register_pc, native_register_memory, native_advance_stack,
    X86Push.store_refines, Reference.X86.pushTransfer, writeMemory]
  change (if permitted state.raw.memory.writable (registerValue env frame arena state 4 - BitVec.ofNat 64 width.bytes) width.bytes then _ else _) = _
  simp only [show (nativeRegisters env frame arena state).gpr 4 = registerValue env frame arena state 4 from rfl,
    show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl]
  split <;> rename_i allowed
  · simp only [allowed, ↓reduceIte, List.nil_append]
    have addr : registerValue env frame arena state 4 + -BitVec.ofNat 64 width.bytes =
        registerValue env frame arena state 4 - BitVec.ofNat 64 width.bytes := by
      simp only [nativeRegisters, NativeWord, Reference.Word]; bv_decide
    rw [addr]
  · simp only [allowed, Bool.false_eq_true, ↓reduceIte, List.nil_append]

theorem push_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth)
    (source : Reference.X86.Register) (nextPc : NativeWord) :
    pushValueFrame env frame arena state width (registerValue env frame arena state source) nextPc =
      Reference.X86.step (.push width source nextPc) (nativeRegisters env frame arena state) :=
  push_value_frame_refines env frame arena state width _ nextPc

theorem push_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth) (value nextPc : NativeWord) :
    pushValueFrame env frame arena state width value nextPc =
      Reference.X86.step (.pushImmediate width value nextPc) (nativeRegisters env frame arena state) :=
  push_value_frame_refines env frame arena state width value nextPc

/-- POP reads the incoming stack address, advances RSP, then applies the
ordinary numeric writer. Partial SP therefore merges with the advanced SP. -/
def popRegisterFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth)
    (destination : Reference.X86.Register) (nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Bt.readOperand width.registerWidth (.memory (registerValue env frame arena state 4))
      (nativeRegisters env frame arena state) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      let advanced := advanceStack state (BitVec.ofNat 64 width.bytes)
      let scalarWidth := match width with | .w16 => Reference.X86.ScalarWidth.w16 | .w64 => .w64
      ⟨nativeRegisters env frame arena
        (registerPc (writeRegister env frame arena advanced scalarWidth (.low destination) value) nextPc),
        reads, none⟩

theorem pop_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth)
    (destination : Reference.X86.Register) (nextPc : NativeWord) :
    popRegisterFrame env frame arena state width destination nextPc =
      Reference.X86.step (.pop width destination nextPc) (nativeRegisters env frame arena state) := by
  have bytes_eq : width.registerWidth.bytes = width.bytes := by cases width <;> rfl
  simp only [popRegisterFrame, X86Bt.read_refines, bytes_eq, Reference.X86.step]
  simp only [show (nativeRegisters env frame arena state).gpr 4 = registerValue env frame arena state 4 from rfl]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state)
      (.memory (registerValue env frame arena state 4)) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨value, reads⟩
      simp only [read, native_register_pc, native_register_write, native_advance_stack]
      change (⟨_, reads, none⟩ : Transition Reference.X86.State) = ⟨_, reads, none⟩
      congr 1
      congr 1
      funext reg
      cases width <;> simp only [Reference.X86.StackWidth.registerWidth,
        Reference.X86.StackWidth.bytes, Reference.X86.scalarWriteValue,
        Reference.X86.RegisterSlice.reg, Reference.X86.RegisterSlice.shift,
        Reference.X86.cmovValue, Reference.X86.CmovWidth.bits,
        Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes]
      all_goals simp only [register_value_advance_stack]
      all_goals by_cases same : reg = destination
      all_goals simp only [same, ↓reduceIte, reduceCtorEq]
      all_goals first | rfl | (subst reg; by_cases rsp : destination = 4 <;> simp only [nativeRegisters, rsp, ↓reduceIte, NativeWord, Reference.Word] <;> bv_decide)

/-- A memory PUSH reads the complete source before decrementing RSP. Both
source and stack write carry their original initialization/event metadata. -/
def pushMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth)
    (address nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Bt.readOperand width.registerWidth (.memory address) (nativeRegisters env frame arena state) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      let transfer := pushValueFrame env frame arena state width value nextPc
      ⟨transfer.state, reads ++ transfer.events, transfer.fault⟩

theorem push_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth) (address nextPc : NativeWord) :
    pushMemoryFrame env frame arena state width address nextPc =
      Reference.X86.step (.pushMemory width address nextPc) (nativeRegisters env frame arena state) := by
  have bytes_eq : width.registerWidth.bytes = width.bytes := by cases width <;> rfl
  simp only [pushMemoryFrame, X86Bt.read_refines, bytes_eq, Reference.X86.step]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨value, reads⟩
      simp only [push_value_frame_refines, Reference.X86.pushTransfer, writeMemory]
      split <;> simp only [List.nil_append]

/-- Memory POP uses the incoming stack read and an address formed after the
stack advance. Destination permission is checked before committing the frame. -/
def popMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth)
    (address nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Bt.readOperand width.registerWidth (.memory (registerValue env frame arena state 4))
      (nativeRegisters env frame arena state) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      if permitted state.raw.memory.writable address width.bytes then
        let memory := X86Push.store width state.raw.memory address value
        let advanced := advanceStack state (BitVec.ofNat 64 width.bytes)
        ⟨nativeRegisters env frame arena (registerPc (registerMemory advanced memory) nextPc),
          reads ++ [.memory .write address (valueBytes value width.bytes) true], none⟩
      else ⟨nativeRegisters env frame arena state,
        reads ++ [.fault (.write address width.bytes)], some (.write address width.bytes)⟩

theorem pop_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.StackWidth) (address nextPc : NativeWord) :
    popMemoryFrame env frame arena state width address nextPc =
      Reference.X86.step (.popMemory width address nextPc) (nativeRegisters env frame arena state) := by
  have bytes_eq : width.registerWidth.bytes = width.bytes := by cases width <;> rfl
  simp only [popMemoryFrame, X86Bt.read_refines, bytes_eq, Reference.X86.step,
    show (nativeRegisters env frame arena state).gpr 4 = registerValue env frame arena state 4 from rfl]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state)
      (.memory (registerValue env frame arena state 4)) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨value, reads⟩
      simp only [native_register_pc, native_register_memory, native_advance_stack,
        X86Push.store_refines, writeMemory,
        show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl]
      split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte] <;> rfl

/-- MOVBE captures its generated byte-ladder read before the raw destination
writer normalizes an RSP offset or a former STACK alias. -/
def endianLoadFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (destination : Reference.X86.Register) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Bt.readOperand width (.memory address) (nativeRegisters env frame arena state) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      let result := GeneratedX86Bswap.value value (X86Cmov.handlerWidth width)
      ⟨nativeRegisters env frame arena
        (registerPc (writeRegister env frame arena state (multiplyScalarWidth width) (.low destination) result) nextPc),
        reads, none⟩

theorem endian_load_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (destination : Reference.X86.Register) (address nextPc : NativeWord) :
    endianLoadFrame env frame arena state width destination address nextPc =
      Reference.X86.step (.movbeLoad width destination address nextPc) (nativeRegisters env frame arena state) := by
  simp only [endianLoadFrame, X86Bt.read_refines, Reference.X86.step, Reference.X86.movbeLoadStep]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨value, reads⟩
      simp only [native_register_pc, native_register_write, multiply_scalar_write, X86Endian.reversal_refines]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = destination <;> simp [same, nativeRegisters, Reference.X86.RegisterSlice.reg]

/-- MOVBE stores native numeric source bytes with generated reversal and byte
stores. Guest permissions and all untouched raw cells retain the incoming frame. -/
def endianStoreFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (source : Reference.X86.Register) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  let value := GeneratedX86Bswap.value (registerValue env frame arena state source) (X86Cmov.handlerWidth width)
  if permitted state.raw.memory.writable address width.bytes then
    let memory := X86Endian.store width state.raw.memory address value
    ⟨nativeRegisters env frame arena (registerPc (registerMemory state memory) nextPc),
      [.memory .write address (valueBytes value width.bytes) true], none⟩
  else ⟨nativeRegisters env frame arena state,
    [.fault (.write address width.bytes)], some (.write address width.bytes)⟩

theorem endian_store_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (source : Reference.X86.Register) (address nextPc : NativeWord) :
    endianStoreFrame env frame arena state width source address nextPc =
      Reference.X86.step (.movbeStore width source address nextPc) (nativeRegisters env frame arena state) := by
  simp only [endianStoreFrame, X86Endian.reversal_refines, native_register_pc, native_register_memory,
    X86Endian.store_refines, Reference.X86.step, Reference.X86.movbeStoreStep, writeMemory,
    show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl,
    show (nativeRegisters env frame arena state).gpr source = registerValue env frame arena state source from rfl]
  split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte]

/-- SETCC memory observes all five condition flags and writes exactly one
byte through the generated scalar store, retaining the remaining frame. -/
def setConditionMemory (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (payload : BitVec 32) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  let taken := (GeneratedX86FullCondition.eval payload
    (state.raw.rflags.getLsbD 0) (state.raw.rflags.getLsbD 6) (state.raw.rflags.getLsbD 7)
    (state.raw.rflags.getLsbD 11) (state.raw.rflags.getLsbD 2)).getD false
  let value : NativeWord := if taken then 1 else 0
  if permitted state.raw.memory.writable address 1 then
    let memory := X86Scalar.store state.raw.memory .w8 address value
    ⟨nativeRegisters env frame arena (registerPc (registerMemory state memory) nextPc),
      [.memory .write address (valueBytes value 1) true], none⟩
  else ⟨nativeRegisters env frame arena state, [.fault (.write address 1)], some (.write address 1)⟩

theorem set_condition_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (cc : Fin 16) (address nextPc : NativeWord) :
    setConditionMemory env frame arena state (BitVec.ofNat 32 cc.val) address nextPc =
      Reference.X86.step (.setcc cc (.memory address) nextPc) (nativeRegisters env frame arena state) := by
  have condition := X86Condition.condition_refines cc state.raw.rflags
  unfold X86Condition.evaluate at condition
  simp only [setConditionMemory, condition, Option.getD_some, native_register_pc, native_register_memory,
    X86Scalar.store_refines, Reference.X86.step, Reference.X86.scalarWrite, writeMemory,
    Reference.X86.ScalarWidth.bytes,
    show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl,
    show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl]
  split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte]

/-- CMOV reads memory eagerly, before evaluating the condition. Its true arm
writes a numeric captured value; false32 zero-extends the old native destination. -/
def conditionalMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (payload : BitVec 32)
    (destination : Reference.X86.Register) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Bt.readOperand width (.memory address) (nativeRegisters env frame arena state) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      let taken := (GeneratedX86FullCondition.eval payload
        (state.raw.rflags.getLsbD 0) (state.raw.rflags.getLsbD 6) (state.raw.rflags.getLsbD 7)
        (state.raw.rflags.getLsbD 11) (state.raw.rflags.getLsbD 2)).getD false
      let result := if taken then
          writeRegister env frame arena state (multiplyScalarWidth width) (.low destination) value
        else if width = .w32 then
          writeRegister env frame arena state .w32 (.low destination) (registerValue env frame arena state destination)
        else state
      ⟨nativeRegisters env frame arena (registerPc result nextPc), reads, none⟩

theorem conditional_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (cc : Fin 16)
    (destination : Reference.X86.Register) (address nextPc : NativeWord) :
    conditionalMemoryFrame env frame arena state width (BitVec.ofNat 32 cc.val) destination address nextPc =
      Reference.X86.step (.cmov width cc destination (.memory address) nextPc) (nativeRegisters env frame arena state) := by
  have condition := X86Condition.condition_refines cc state.raw.rflags
  unfold X86Condition.evaluate at condition
  simp only [conditionalMemoryFrame, X86Bt.read_refines, Reference.X86.step]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨value, reads⟩
      simp only [condition, Option.getD_some]
      have flags : (nativeRegisters env frame arena state).rflags = state.raw.rflags := rfl
      cases width <;> cases taken : Reference.X86.condition state.raw.rflags cc <;>
        simp only [multiplyScalarWidth, flags, taken, Bool.false_eq_true, ↓reduceIte, reduceCtorEq,
          native_register_pc, native_register_write]
      all_goals simp only [Reference.X86.cmovValue, nativeRegisters]
      all_goals congr 1
      all_goals congr 1
      all_goals funext reg
      all_goals by_cases same : reg = destination
      all_goals simp only [same, ↓reduceIte, Reference.X86.RegisterSlice.reg,
        Reference.X86.scalarWriteValue, Reference.X86.RegisterSlice.shift,
        Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, NativeWord, Reference.Word]
      all_goals bv_decide


/-- Ordinary stores sample the numeric source and address from the input
frame. The generated width store changes only guest bytes and initialization. -/
def storeValueFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (value address nextPc : NativeWord) : Transition Reference.X86.State :=
  if permitted state.raw.memory.writable address width.bytes then
    let memory := X86Scalar.store state.raw.memory width address value
    ⟨nativeRegisters env frame arena (registerPc (registerMemory state memory) nextPc),
      [.memory .write address (valueBytes value width.bytes) true], none⟩
  else ⟨nativeRegisters env frame arena state,
    [.fault (.write address width.bytes)], some (.write address width.bytes)⟩

theorem store_value_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (value address nextPc : NativeWord) :
    storeValueFrame env frame arena state width value address nextPc =
      Reference.X86.step (.move width (.memory address) (.immediate value) nextPc)
        (nativeRegisters env frame arena state) := by
  simp only [storeValueFrame, native_register_pc, native_register_memory, X86Scalar.store_refines,
    Reference.X86.step, Reference.X86.moveStep, Reference.X86.scalarRead, Reference.X86.scalarWrite,
    writeMemory, List.nil_append,
    show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl]
  split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte]

/-- A full-width source read followed by the native lane shift and byte
store observes exactly the same low bytes as the generated narrow lane read. -/
theorem store_register_byte (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (source : Reference.X86.RegisterSlice) (i : Nat) (inside : i < width.bytes) :
    (((registerValue env frame arena state source.reg >>> source.shift width) >>> (8 * i)).setWidth 8) =
      ((readRegister env frame arena state width source >>> (8 * i)).setWidth 8) := by
  rw [native_register_read]
  simp only [Reference.X86.scalarRegisterValue, nativeRegisters]
  cases width <;> cases source <;>
    simp only [Reference.X86.RegisterSlice.shift, Reference.X86.ScalarWidth.bytes, Reference.X86.ScalarWidth.bits] at *
  all_goals have options : i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 := by omega
  all_goals rcases options with hi | hi | hi | hi | hi | hi | hi | hi
  all_goals subst i
  all_goals first | omega | (simp only [NativeWord, Reference.Word, Reference.X86.RegisterSlice.reg, reduceCtorEq, ↓reduceIte]; bv_decide)

private theorem store_frame_bytes_congr (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (left right address nextPc : NativeWord)
    (same : ∀ i, i < width.bytes → (left >>> (8 * i)).setWidth 8 = (right >>> (8 * i)).setWidth 8) :
    storeValueFrame env frame arena state width left address nextPc =
      storeValueFrame env frame arena state width right address nextPc := by
  have bytes : valueBytes left width.bytes = valueBytes right width.bytes := by
    unfold valueBytes
    apply List.map_congr_left
    intro i member
    exact same i (List.mem_range.mp member)
  have memory : storeMemory state.raw.memory address left width.bytes =
      storeMemory state.raw.memory address right width.bytes := by
    unfold storeMemory
    congr 1
    funext a
    dsimp only
    split <;> rename_i inside
    · exact same _ inside
    · rfl
  simp only [storeValueFrame, X86Scalar.store_refines, bytes, memory]

def storeRegisterFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (source : Reference.X86.RegisterSlice) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  storeValueFrame env frame arena state width
    (registerValue env frame arena state source.reg >>> source.shift width) address nextPc

theorem store_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (source : Reference.X86.RegisterSlice) (address nextPc : NativeWord) :
    storeRegisterFrame env frame arena state width source address nextPc =
      Reference.X86.step (.move width (.memory address) (.register source) nextPc)
        (nativeRegisters env frame arena state) := by
  unfold storeRegisterFrame
  rw [store_frame_bytes_congr env frame arena state width _ (readRegister env frame arena state width source)
    address nextPc (store_register_byte env frame arena state width source)]
  rw [store_value_frame_refines, native_register_read]
  simp only [Reference.X86.step, Reference.X86.moveStep, Reference.X86.scalarRead]

/-- Immediate stores use the width-aware low32 value rule; the independent
instruction binding supplies the signed-high32 effective displacement. -/
def storeImmediateFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (artifact address nextPc : NativeWord) : Transition Reference.X86.State :=
  storeValueFrame env frame arena state width
    (GeneratedX86Immediate.value artifact (X86Scalar.handlerWidth width)) address nextPc

theorem store_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (artifact address nextPc : NativeWord) :
    storeImmediateFrame env frame arena state width artifact address nextPc =
      Reference.X86.step (.move width (.memory address)
        (.immediate (KProgFormal.x86ImmediateValueSpec artifact (X86Scalar.handlerWidth width))) nextPc)
        (nativeRegisters env frame arena state) := by
  simp only [storeImmediateFrame, KProgFormal.x86_immediate_value_refines, store_value_frame_refines]


/-- Observed memory read/modify/write over one incoming numeric frame. A read
fault retains the frame; a write fault also retains its completed read event. -/
def modifyMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (value : NativeWord → NativeWord) (flags : NativeWord → NativeWord → NativeWord → NativeWord)
    (address nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Scalar.read (nativeRegisters env frame arena state) width (.memory address) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (source, reads) =>
      let result := value source
      if permitted state.raw.memory.writable address width.bytes then
        let memory := X86Scalar.store state.raw.memory width address result
        let written := registerMemory state memory
        ⟨nativeRegisters env frame arena
          (registerPc (registerFlags written (flags source result state.raw.rflags)) nextPc),
          reads ++ [.memory .write address (valueBytes result width.bytes) true], none⟩
      else ⟨nativeRegisters env frame arena state,
        reads ++ [.fault (.write address width.bytes)], some (.write address width.bytes)⟩

def unaryMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.UnaryKind)
    (address nextPc : NativeWord) : Transition Reference.X86.State :=
  modifyMemoryFrame env frame arena state width
    (fun source => X86Arithmetic.narrow width (GeneratedX86AluResult.result (X86Unary.alu kind)
      (X86Arithmetic.narrow width source) 1 (X86Scalar.handlerWidth width)))
    (fun source _ old => X86Unary.flags width kind source old) address nextPc

theorem unary_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.UnaryKind)
    (address nextPc : NativeWord) :
    unaryMemoryFrame env frame arena state width kind address nextPc =
      Reference.X86.step (.unary width kind (.memory address) nextPc)
        (nativeRegisters env frame arena state) := by
  have result (source : NativeWord) :
      X86Arithmetic.narrow width (GeneratedX86AluResult.result (X86Unary.alu kind)
        (X86Arithmetic.narrow width source) 1 (X86Scalar.handlerWidth width)) = X86Unary.value width kind source := by
    cases kind <;> rfl
  rw [← X86Unary.step_refines]
  simp only [unaryMemoryFrame, modifyMemoryFrame, X86Unary.handlerStep,
    Reference.X86.ScalarDestination.source, result]
  cases read : X86Scalar.read (nativeRegisters env frame arena state) width (.memory address) with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [X86Scalar.write, native_register_pc, native_register_flags, native_register_memory,
        show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl]
      split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte] <;> rfl

def rotateMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (count address nextPc : NativeWord) : Transition Reference.X86.State :=
  modifyMemoryFrame env frame arena state width (fun source => X86RotateRight.value width source count)
    (fun _ result old => X86RotateRight.flags width result count old) address nextPc

theorem rotate_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (count address nextPc : NativeWord) :
    rotateMemoryFrame env frame arena state width count address nextPc =
      Reference.X86.step (.rotateRight width (.memory address) count nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86RotateRight.step_refines]
  simp only [rotateMemoryFrame, modifyMemoryFrame, X86RotateRight.handlerStep,
    Reference.X86.ScalarDestination.source]
  cases read : X86Scalar.read (nativeRegisters env frame arena state) width (.memory address) with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [X86Scalar.write, native_register_pc, native_register_flags, native_register_memory,
        show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl]
      split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte] <;> rfl


/-- Memory comparisons sample one guest read and update only flags and PC.
Permissions and initialization remain in the original ordered read event. -/
def flagsMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (flags : NativeWord → NativeWord → NativeWord) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Scalar.read (nativeRegisters env frame arena state) width (.memory address) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (source, reads) =>
      ⟨nativeRegisters env frame arena (registerPc (registerFlags state (flags source state.raw.rflags)) nextPc), reads, none⟩

theorem compare_memory_value_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (right address nextPc : NativeWord) :
    flagsMemoryFrame env frame arena state width (fun source old => X86Arithmetic.compareFlags width source right old)
      address nextPc = Reference.X86.step (.arithmetic width .compare (.memory address) (.immediate right) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Arithmetic.step_refines]
  simp only [flagsMemoryFrame, X86Arithmetic.handlerStep, Reference.X86.ScalarDestination.source,
    X86Scalar.read_refines, Reference.X86.scalarRead, X86Arithmetic.compare_flags_eq]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, Reference.X86.scalarRead,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl, List.append_nil, ↓reduceIte]

theorem test_memory_value_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (right address nextPc : NativeWord) :
    flagsMemoryFrame env frame arena state width (fun source old => X86Logic.flags width .test source right old)
      address nextPc = Reference.X86.step (.logic width .test (.memory address) (.immediate right) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Logic.step_refines]
  simp only [flagsMemoryFrame, X86Logic.handlerStep, Reference.X86.ScalarDestination.source,
    X86Scalar.read_refines, Reference.X86.scalarRead]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, Reference.X86.scalarRead,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl, List.append_nil, ↓reduceIte]

/-- Numeric full-cell reads and native low-lane reads have the same operand
bits, including RSP offsets and STACK-tagged aliases. -/
theorem register_low_operand_bits (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (reg : Reference.X86.Register) :
    (registerValue env frame arena state reg).setWidth width.bits =
      (readRegister env frame arena state width (.low reg)).setWidth width.bits := by
  cases width <;> simp only [readRegister, X86Scalar.handlerWidth, X86Scalar.lane,
    Reference.X86.RegisterSlice.reg, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
    GeneratedX86RegRead.readAt, Nat.reduceMul, NativeWord, Reference.Word] <;> bv_decide

theorem compare_memory_register_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (right : Reference.X86.Register)
    (address nextPc : NativeWord) :
    flagsMemoryFrame env frame arena state width
      (fun source old => X86Arithmetic.compareFlags width source (registerValue env frame arena state right) old)
      address nextPc = Reference.X86.step (.arithmetic width .compare (.memory address) (.register (.low right)) nextPc)
        (nativeRegisters env frame arena state) := by
  have flags (source old : NativeWord) :
      X86Arithmetic.compareFlags width source (registerValue env frame arena state right) old =
        X86Arithmetic.compareFlags width source (readRegister env frame arena state width (.low right)) old := by
    simp only [X86Arithmetic.compare_flags_eq]
    exact arithmetic_flags_operand_bits width .compare source _ _ old (register_low_operand_bits env frame arena state width right)
  simp only [flagsMemoryFrame, flags]
  change flagsMemoryFrame env frame arena state width
    (fun source old => X86Arithmetic.compareFlags width source (readRegister env frame arena state width (.low right)) old)
      address nextPc = _
  rw [compare_memory_value_refines, native_register_read]
  rfl

theorem test_memory_register_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (right : Reference.X86.Register)
    (address nextPc : NativeWord) :
    flagsMemoryFrame env frame arena state width
      (fun source old => X86Logic.flags width .test source (registerValue env frame arena state right) old)
      address nextPc = Reference.X86.step (.logic width .test (.memory address) (.register (.low right)) nextPc)
        (nativeRegisters env frame arena state) := by
  have flags (source old : NativeWord) := logic_flags_operand_bits width .test source
    (registerValue env frame arena state right) (readRegister env frame arena state width (.low right)) old
    (register_low_operand_bits env frame arena state width right)
  simp only [flagsMemoryFrame, flags]
  change flagsMemoryFrame env frame arena state width
    (fun source old => X86Logic.flags width .test source (readRegister env frame arena state width (.low right)) old)
      address nextPc = _
  rw [test_memory_value_refines, native_register_read]
  rfl

theorem compare_register_memory_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (left : Reference.X86.Register)
    (address nextPc : NativeWord) :
    flagsMemoryFrame env frame arena state width
      (fun source old => X86Arithmetic.flags width .compare (registerValue env frame arena state left) source old)
      address nextPc = Reference.X86.step (.arithmetic width .compare (.register (.low left)) (.memory address) nextPc)
        (nativeRegisters env frame arena state) := by
  have flags (source old : NativeWord) :
      X86Arithmetic.flags width .compare (registerValue env frame arena state left) source old =
        X86Arithmetic.flags width .compare (readRegister env frame arena state width (.low left)) source old := by
    simp only [X86Arithmetic.flags, X86Arithmetic.value,
      arithmetic_narrow_operand_bits width _ _ (register_low_operand_bits env frame arena state width left)]
  rw [← X86Arithmetic.step_refines]
  simp only [flagsMemoryFrame, flags, X86Arithmetic.handlerStep, Reference.X86.ScalarDestination.source,
    X86Scalar.read_refines, Reference.X86.scalarRead, ← native_register_read]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, Reference.X86.scalarRead,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl,
        List.nil_append, List.append_nil, ↓reduceIte]


/-- A memory-destination arithmetic body captures its original carry and RHS
before replacing flags and exactly the selected bytes. -/
def arithmeticMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (right address nextPc : NativeWord) : Transition Reference.X86.State :=
  modifyMemoryFrame env frame arena state width
    (fun left => X86Arithmetic.value width kind.subtract (kind.carry state.raw.rflags) left right)
    (fun left _ old => X86Arithmetic.flags width kind left right old) address nextPc

theorem arithmetic_memory_value_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (right address nextPc : NativeWord) (writing : kind ≠ .compare) :
    arithmeticMemoryFrame env frame arena state width kind right address nextPc =
      Reference.X86.step (.arithmetic width kind (.memory address) (.immediate right) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Arithmetic.step_refines]
  simp only [arithmeticMemoryFrame, modifyMemoryFrame, X86Arithmetic.handlerStep,
    Reference.X86.ScalarDestination.source]
  cases read : X86Scalar.read (nativeRegisters env frame arena state) width (.memory address) with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨left, reads⟩
      simp only [X86Scalar.read, Reference.X86.scalarRead, writing, ↓reduceIte, X86Scalar.write,
        native_register_pc, native_register_flags, native_register_memory, List.append_nil,
        show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl]
      split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte] <;> rfl

def logicMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (right address nextPc : NativeWord) : Transition Reference.X86.State :=
  modifyMemoryFrame env frame arena state width (fun left => X86Logic.value width kind left right)
    (fun left _ old => X86Logic.flags width kind left right old) address nextPc

theorem logic_memory_value_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (right address nextPc : NativeWord) (writing : kind ≠ .test) :
    logicMemoryFrame env frame arena state width kind right address nextPc =
      Reference.X86.step (.logic width kind (.memory address) (.immediate right) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Logic.step_refines]
  simp only [logicMemoryFrame, modifyMemoryFrame, X86Logic.handlerStep,
    Reference.X86.ScalarDestination.source]
  cases read : X86Scalar.read (nativeRegisters env frame arena state) width (.memory address) with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨left, reads⟩
      simp only [X86Scalar.read, Reference.X86.scalarRead, writing, ↓reduceIte, X86Scalar.write,
        native_register_pc, native_register_flags, native_register_memory, List.append_nil,
        show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl]
      split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte] <;> rfl

def shiftMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LegacyShift)
    (count address nextPc : NativeWord) : Transition Reference.X86.State :=
  modifyMemoryFrame env frame arena state width (fun left => X86LegacyShift.value width kind left count)
    (fun left _ old => X86LegacyShift.flags width kind left count old) address nextPc

theorem shift_memory_value_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LegacyShift)
    (count address nextPc : NativeWord) :
    shiftMemoryFrame env frame arena state width kind count address nextPc =
      Reference.X86.step (.legacyShift width kind (.memory address) count nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86LegacyShift.step_refines]
  simp only [shiftMemoryFrame, modifyMemoryFrame, X86LegacyShift.handlerStep,
    Reference.X86.ScalarDestination.source]
  cases read : X86Scalar.read (nativeRegisters env frame arena state) width (.memory address) with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨left, reads⟩
      simp only [X86Scalar.write, native_register_pc, native_register_flags, native_register_memory,
        show (nativeRegisters env frame arena state).memory = state.raw.memory from rfl,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl]
      split <;> rename_i allowed <;> simp only [allowed, ↓reduceIte] <;> rfl

theorem arithmetic_memory_register_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (right : Reference.X86.Register) (address nextPc : NativeWord) (writing : kind ≠ .compare) :
    arithmeticMemoryFrame env frame arena state width kind (registerValue env frame arena state right) address nextPc =
      Reference.X86.step (.arithmetic width kind (.memory address) (.register (.low right)) nextPc)
        (nativeRegisters env frame arena state) := by
  have bits := register_low_operand_bits env frame arena state width right
  have values (left : NativeWord) := arithmetic_value_operand_bits width kind.subtract
    (kind.carry state.raw.rflags) left _ _ bits
  have flags (left old : NativeWord) := arithmetic_flags_operand_bits width kind left _ _ old bits
  simp only [arithmeticMemoryFrame, values, flags]
  change arithmeticMemoryFrame env frame arena state width kind
    (readRegister env frame arena state width (.low right)) address nextPc = _
  rw [arithmetic_memory_value_refines env frame arena state width kind _ address nextPc writing,
    native_register_read]
  rfl

theorem logic_memory_register_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (right : Reference.X86.Register) (address nextPc : NativeWord) (writing : kind ≠ .test) :
    logicMemoryFrame env frame arena state width kind (registerValue env frame arena state right) address nextPc =
      Reference.X86.step (.logic width kind (.memory address) (.register (.low right)) nextPc)
        (nativeRegisters env frame arena state) := by
  have bits := register_low_operand_bits env frame arena state width right
  have values (left : NativeWord) := logic_value_operand_bits width kind left _ _ bits
  have flags (left old : NativeWord) := logic_flags_operand_bits width kind left _ _ old bits
  simp only [logicMemoryFrame, values, flags]
  change logicMemoryFrame env frame arena state width kind
    (readRegister env frame arena state width (.low right)) address nextPc = _
  rw [logic_memory_value_refines env frame arena state width kind _ address nextPc writing,
    native_register_read]
  rfl


/-- CL count masking consumes the same low byte as the native decoder. -/
theorem shift_memory_register_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LegacyShift)
    (right : Reference.X86.Register) (address nextPc : NativeWord) :
    shiftMemoryFrame env frame arena state width kind (registerValue env frame arena state right) address nextPc =
      Reference.X86.step (.legacyShift width kind (.memory address)
        (((nativeRegisters env frame arena state).gpr right).setWidth 8 |>.setWidth 64) nextPc)
        (nativeRegisters env frame arena state) := by
  let count := registerValue env frame arena state right
  have masked : Reference.X86.legacyCount width count =
      Reference.X86.legacyCount width ((count.setWidth 8).setWidth 64) := by
    cases width <;> simp only [Reference.X86.legacyCount, reduceCtorEq, ↓reduceIte]
      <;> bv_decide
  have values (left : NativeWord) : X86LegacyShift.value width kind left count =
      X86LegacyShift.value width kind left ((count.setWidth 8).setWidth 64) := by
    simp only [X86LegacyShift.value_refines, Reference.X86.legacyShiftValue, masked]
  have flags (left old : NativeWord) : X86LegacyShift.flags width kind left count old =
      X86LegacyShift.flags width kind left ((count.setWidth 8).setWidth 64) old := by
    simp only [X86LegacyShift.flags_refine, Reference.X86.legacyShiftFlags,
      Reference.X86.legacyShiftValue, masked]
  change shiftMemoryFrame env frame arena state width kind count address nextPc = _
  simp only [shiftMemoryFrame, values, flags]
  change shiftMemoryFrame env frame arena state width kind ((count.setWidth 8).setWidth 64) address nextPc = _
  exact shift_memory_value_refines env frame arena state width kind _ address nextPc

/-- A captured memory source precedes the numeric destination write and flags.
The read fault retains the incoming complete architectural frame. -/
def aluSourceFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (dst : Reference.X86.Register)
    (value : NativeWord → NativeWord) (flags : NativeWord → NativeWord)
    (address nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Scalar.read (nativeRegisters env frame arena state) width (.memory address) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (right, reads) =>
      ⟨nativeRegisters env frame arena
        (registerPc (registerFlags (writeRegister env frame arena state width (.low dst) (value right))
          (flags right)) nextPc), reads, none⟩

def arithmeticSourceFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (dst : Reference.X86.Register) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  aluSourceFrame env frame arena state width dst
    (fun right => X86Arithmetic.value width kind.subtract (kind.carry state.raw.rflags)
      (registerValue env frame arena state dst) right)
    (fun right => X86Arithmetic.flags width kind (registerValue env frame arena state dst) right state.raw.rflags)
    address nextPc

theorem arithmetic_source_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (dst : Reference.X86.Register) (address nextPc : NativeWord) (writing : kind ≠ .compare) :
    arithmeticSourceFrame env frame arena state width kind dst address nextPc =
      Reference.X86.step (.arithmetic width kind (.register (.low dst)) (.memory address) nextPc)
        (nativeRegisters env frame arena state) := by
  have narrow := arithmetic_narrow_operand_bits width _ _ (register_low_operand_bits env frame arena state width dst)
  rw [← X86Arithmetic.step_refines]
  simp only [arithmeticSourceFrame, aluSourceFrame, X86Arithmetic.value, X86Arithmetic.flags, narrow,
    X86Arithmetic.handlerStep, Reference.X86.ScalarDestination.source, X86Scalar.read_refines,
    Reference.X86.scalarRead, ← native_register_read]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨right, reads⟩
      simp only [native_register_pc, native_register_flags, native_register_write, X86Scalar.write_refines,
        Reference.X86.scalarWrite, writing, ↓reduceIte,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl,
        List.nil_append, List.append_nil]
      rfl

def logicSourceFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (dst : Reference.X86.Register) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  aluSourceFrame env frame arena state width dst
    (fun right => X86Logic.value width kind (registerValue env frame arena state dst) right)
    (fun right => X86Logic.flags width kind (registerValue env frame arena state dst) right state.raw.rflags)
    address nextPc

theorem logic_source_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (kind : Reference.X86.LogicKind)
    (dst : Reference.X86.Register) (address nextPc : NativeWord) (writing : kind ≠ .test) :
    logicSourceFrame env frame arena state width kind dst address nextPc =
      Reference.X86.step (.logic width kind (.register (.low dst)) (.memory address) nextPc)
        (nativeRegisters env frame arena state) := by
  have narrow := arithmetic_narrow_operand_bits width _ _ (register_low_operand_bits env frame arena state width dst)
  rw [← X86Logic.step_refines]
  simp only [logicSourceFrame, aluSourceFrame, X86Logic.flags, X86Logic.value, narrow,
    X86Logic.handlerStep, Reference.X86.ScalarDestination.source, X86Scalar.read_refines,
    Reference.X86.scalarRead, ← native_register_read]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨right, reads⟩
      simp only [native_register_pc, native_register_flags, native_register_write, X86Scalar.write_refines,
        Reference.X86.scalarWrite, writing, ↓reduceIte,
        show (nativeRegisters env frame arena state).rflags = state.raw.rflags from rfl,
        List.nil_append, List.append_nil]
      rfl

def multiplySourceFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (dst : Reference.X86.Register)
    (address nextPc : NativeWord) : Transition Reference.X86.State :=
  aluSourceFrame env frame arena state (multiplyScalarWidth width) dst
    (fun right => X86Multiply.value width (registerValue env frame arena state dst) right)
    (fun right => X86Multiply.flags width (registerValue env frame arena state dst) right state.raw.rflags)
    address nextPc

theorem multiply_source_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (dst : Reference.X86.Register)
    (address nextPc : NativeWord) :
    multiplySourceFrame env frame arena state width dst address nextPc =
      Reference.X86.step (.multiply width dst (.memory address) none nextPc)
        (nativeRegisters env frame arena state) := by
  simp only [multiplySourceFrame, aluSourceFrame, X86Scalar.read_refines, Reference.X86.scalarRead,
    Reference.X86.step, Reference.X86.multiplyStep]
  have bytes : (multiplyScalarWidth width).bytes = width.bytes := by cases width <;> rfl
  rw [bytes]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨right, reads⟩
      simp only [native_register_pc, native_register_flags, native_register_write, multiply_scalar_write,
        X86Multiply.value_refines, X86Multiply.flags_refine]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = dst <;> simp [same, nativeRegisters, Reference.X86.RegisterSlice.reg]

/-- The packed low32 immediate is extended at the selected product width.
Its operand bits coincide with the native IMUL immediate at that width. -/
theorem multiply_memory_immediate_bits (width : Reference.X86.CmovWidth) (raw : NativeWord) :
    (GeneratedX86Signed.signExtend
      (GeneratedX86Immediate.value raw (X86Scalar.handlerWidth (multiplyScalarWidth width)))
      (X86Cmov.handlerWidth width)).setWidth width.bits =
      (Reference.X86.multiplyImmediate width (raw.setWidth 32)).setWidth width.bits := by
  rw [X86Multiply.signed_lane_refines]
  exact multiply_alu_immediate_bits width raw

/-- IMUL's memory source and packed immediate are captured before the
scalarizing destination write; CF/OF use the same original operands. -/
def multiplyMemoryImmediateFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (dst : Reference.X86.Register)
    (raw address nextPc : NativeWord) : Transition Reference.X86.State :=
  let right := GeneratedX86Signed.signExtend
    (GeneratedX86Immediate.value raw (X86Scalar.handlerWidth (multiplyScalarWidth width))) (X86Cmov.handlerWidth width)
  aluSourceFrame env frame arena state (multiplyScalarWidth width) dst
    (fun source => X86Multiply.value width (GeneratedX86Signed.signExtend source (X86Cmov.handlerWidth width)) right)
    (fun source => X86Multiply.flags width source right state.raw.rflags) address nextPc

theorem multiply_memory_immediate_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (dst : Reference.X86.Register)
    (raw address nextPc : NativeWord) :
    multiplyMemoryImmediateFrame env frame arena state width dst raw address nextPc =
      Reference.X86.step (.multiply width dst (.memory address) (some (raw.setWidth 32)) nextPc)
        (nativeRegisters env frame arena state) := by
  have bits := multiply_memory_immediate_bits width raw
  have values (source : NativeWord) := multiply_value_operand_bits width _ _ source
    (Reference.X86.multiplyImmediate width (raw.setWidth 32)) (X86Multiply.signed_lane_refines width source) bits
  have flags (source : NativeWord) := multiply_flags_operand_bits width source _ source
    (Reference.X86.multiplyImmediate width (raw.setWidth 32)) state.raw.rflags rfl bits
  simp only [multiplyMemoryImmediateFrame, aluSourceFrame, X86Scalar.read_refines, Reference.X86.scalarRead,
    Reference.X86.step, Reference.X86.multiplyStep]
  have bytes : (multiplyScalarWidth width).bytes = width.bytes := by cases width <;> rfl
  rw [bytes]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, native_register_write, multiply_scalar_write, values, flags]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = dst <;> simp [same, nativeRegisters, Reference.X86.RegisterSlice.reg]

/-- A load captures its common-input address and memory value before the
numeric destination write; flags and every other architectural cell persist. -/
def loadMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (sourceWidth targetWidth : Reference.X86.ScalarWidth)
    (signed : Bool) (destination : Reference.X86.Register) (address nextPc : NativeWord) :
    Transition Reference.X86.State :=
  match X86Scalar.read (nativeRegisters env frame arena state) sourceWidth (.memory address) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (source, reads) =>
      ⟨nativeRegisters env frame arena
        (registerPc (writeRegister env frame arena state targetWidth (.low destination)
          (X86Movx.value sourceWidth signed source)) nextPc), reads, none⟩

theorem load_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (sourceWidth targetWidth : Reference.X86.ScalarWidth)
    (signed : Bool) (destination : Reference.X86.Register) (address nextPc : NativeWord) :
    loadMemoryFrame env frame arena state sourceWidth targetWidth signed destination address nextPc =
      Reference.X86.step (.extend sourceWidth targetWidth signed destination (.memory address) nextPc)
        (nativeRegisters env frame arena state) := by
  simp only [loadMemoryFrame, X86Scalar.read_refines, Reference.X86.step, Reference.X86.scalarRead]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) sourceWidth.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_write, X86Movx.value_refines]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = destination <;> simp [same, nativeRegisters, Reference.X86.RegisterSlice.reg]

/-- The extra zero-narrowing of an ordinary load retains exactly its native
write lane, including byte/word merges and32-bit zero-extension. -/
theorem load_narrow_write (width : Reference.X86.ScalarWidth) (destination : Reference.X86.Register)
    (old value : NativeWord) :
    Reference.X86.scalarWriteValue old (Reference.X86.extendValue width false value) width (.low destination) =
      Reference.X86.scalarWriteValue old value width (.low destination) := by
  cases width <;> simp only [Reference.X86.scalarWriteValue, Reference.X86.extendValue,
    Reference.X86.RegisterSlice.shift, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
    Nat.reduceMul, Bool.false_eq_true, ↓reduceIte] <;> bv_decide

theorem load_memory_move_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (destination : Reference.X86.Register)
    (address nextPc : NativeWord) :
    loadMemoryFrame env frame arena state width width false destination address nextPc =
      Reference.X86.step (.move width (.register (.low destination)) (.memory address) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [load_memory_frame_refines]
  simp only [Reference.X86.step, Reference.X86.moveStep, Reference.X86.scalarRead]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [Reference.X86.scalarWrite, load_narrow_write, List.append_nil]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = destination <;> simp [same, Reference.X86.RegisterSlice.reg]


/-- BMI memory operands capture the source and count in the incoming frame.
The numeric writer retains RSP offsets, destination aliases and every flag. -/
def bmiMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
    (dst : Reference.X86.Register) (count address nextPc : NativeWord) : Transition Reference.X86.State :=
  aluSourceFrame env frame arena state (multiplyScalarWidth (X86Bzhi.readWidth width)) dst
    (fun source => X86BmiShift.value width kind source count)
    (fun _ => state.raw.rflags) address nextPc

theorem bmi_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
    (dst : Reference.X86.Register) (count : Reference.X86.ShiftCount) (address nextPc : NativeWord) :
    bmiMemoryFrame env frame arena state width kind dst
        (Reference.X86.countValue (nativeRegisters env frame arena state) count) address nextPc =
      Reference.X86.step (.bmiShift width kind dst (.memory address) count nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86BmiShift.step_refines width kind dst (.memory address) count nextPc
    (nativeRegisters env frame arena state) .scalar]
  simp only [bmiMemoryFrame, aluSourceFrame, X86BmiShift.handlerStep,
    X86Scalar.read_refines, X86Bt.read_refines, Reference.X86.scalarRead]
  have bytes : (multiplyScalarWidth (X86Bzhi.readWidth width)).bytes = width.bytes := by cases width <;> rfl
  have readBytes : (X86Bzhi.readWidth width).bytes = width.bytes := by cases width <;> rfl
  rw [bytes, readBytes]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, native_register_write]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = dst
      · subst reg
        simp only [nativeRegisters, Reference.X86.RegisterSlice.reg, ↓reduceIte]
        rw [← X86Scalar.register_write_refines]
        cases width <;> rfl
      · simp only [nativeRegisters, Reference.X86.RegisterSlice.reg, same, ↓reduceIte]


/-- Memory BZHI captures the low count byte from the incoming numeric frame.
Its generated flags and numeric destination writer share the captured source. -/
def bzhiMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst count : Reference.X86.Register) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  let amount := registerValue env frame arena state count &&& 0xff
  aluSourceFrame env frame arena state (multiplyScalarWidth (X86Bzhi.readWidth width)) dst
    (fun source => generatedX86BzhiResult source amount (X86Bzhi.handlerWidth width))
    (fun source => X86Bzhi.liftFlags state.raw.rflags
      (generatedX86BzhiFlags amount (generatedX86BzhiResult source amount (X86Bzhi.handlerWidth width))
        (X86Bzhi.handlerWidth width))) address nextPc

theorem bzhi_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst count : Reference.X86.Register) (address nextPc : NativeWord) :
    bzhiMemoryFrame env frame arena state width dst count address nextPc =
      Reference.X86.step (.bzhi width dst (.memory address) count nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Bzhi.step_refines width dst (.memory address) count nextPc
    (nativeRegisters env frame arena state) .scalar]
  simp only [bzhiMemoryFrame, aluSourceFrame, X86Bzhi.handlerStep,
    X86Scalar.read_refines, X86Bt.read_refines, Reference.X86.scalarRead]
  have bytes : (multiplyScalarWidth (X86Bzhi.readWidth width)).bytes = width.bytes := by cases width <;> rfl
  have readBytes : (X86Bzhi.readWidth width).bytes = width.bytes := by cases width <;> rfl
  rw [bytes, readBytes]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, native_register_write]
      simp only [nativeRegisters]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = dst
      · subst reg
        simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
        rw [← X86Scalar.register_write_refines]
        cases width <;> rfl
      · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]

/-- POPCNT's memory read, generated population count and six flags precede
one numeric destination write with its full register and control frame. -/
def populationCountMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (dst : Reference.X86.Register)
    (address nextPc : NativeWord) : Transition Reference.X86.State :=
  aluSourceFrame env frame arena state (multiplyScalarWidth width) dst
    (X86Popcount.value width) (fun source => X86Popcount.flags width source state.raw.rflags) address nextPc

theorem population_count_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (dst : Reference.X86.Register)
    (address nextPc : NativeWord) :
    populationCountMemoryFrame env frame arena state width dst address nextPc =
      Reference.X86.step (.popcount width dst (.memory address) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Popcount.memory_step_refines]
  simp only [populationCountMemoryFrame, aluSourceFrame, X86Popcount.memoryHandlerStep,
    X86Scalar.read_refines, X86Bt.read_refines, Reference.X86.scalarRead]
  have bytes : (multiplyScalarWidth width).bytes = width.bytes := by cases width <;> rfl
  rw [bytes]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, native_register_write]
      simp only [nativeRegisters]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = dst
      · subst reg
        simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
        rw [← X86Scalar.register_write_refines]
        cases width <;> first | rfl | (simp [X86Cmov.handlerValue, X86Cmov.handlerWidth, ↓reduceIte, generatedX86MovPointerWrite, GeneratedPtrAdd.bits, BitVec.add_zero, generatedX86RegWrite,
          GeneratedX86RegWrite.write, GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt,
          GeneratedX86RegWrite.bits, X86Scalar.handlerWidth, X86Scalar.lane, multiplyScalarWidth])
      · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]


/-- BT's packed immediate supplies its selected bit while the memory source
retains the complete numeric frame, ordered read and precise fault state. -/
def bitTestMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth)
    (raw address nextPc : NativeWord) : Transition Reference.X86.State :=
  flagsMemoryFrame env frame arena state (multiplyScalarWidth width)
    (fun source old => Reference.X86.setFlag old 0
      (generatedX86BtCf source (generatedX86BtIndex .btMemImm 0 raw) (X86Cmov.handlerWidth width))) address nextPc

theorem bit_test_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.CmovWidth) (raw address nextPc : NativeWord) :
    bitTestMemoryFrame env frame arena state width raw address nextPc =
      Reference.X86.step (.bt width (.memory address) (.immediate (raw.setWidth 8)) nextPc)
        (nativeRegisters env frame arena state) := by
  simp only [bitTestMemoryFrame, flagsMemoryFrame, Reference.X86.step,
    Reference.X86.bitBaseSource, Reference.X86.bitIndexValue,
    X86Scalar.read_refines, Reference.X86.scalarRead]
  have bytes : (multiplyScalarWidth width).bytes = width.bytes := by cases width <;> rfl
  rw [bytes]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, X86Bt.carry_refines,
        reduceCtorEq, ↓reduceIte]
      rfl

/-- ANDN retains its shared logic intermediate and independent memory width.
FreshAux composes the production PF/AF choices after a successful read. -/
def andnMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (sourceWidth : Reference.X86.ScalarWidth) (width : Reference.X86.BzhiWidth)
    (dst first : Reference.X86.Register) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  match X86Scalar.read (nativeRegisters env frame arena state) sourceWidth (.memory address) with
  | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
  | .ok (second, reads) =>
      let result := generatedX86AndnResult (registerValue env frame arena state first) second
      ⟨nativeRegisters env frame arena
        (registerPc (registerFlags (writeRegister env frame arena state
          (multiplyScalarWidth (X86Bzhi.readWidth width)) (.low dst) result)
          (andnFlags width result state.raw.rflags)) nextPc), reads, none⟩

theorem andn_memory_frame_matches (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst first : Reference.X86.Register) (address nextPc : NativeWord) :
    andnMemoryFrame env frame arena state (multiplyScalarWidth (X86Bzhi.readWidth width)) width dst first address nextPc =
      match Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
      | .error fault => ⟨nativeRegisters env frame arena state, [.fault fault], some fault⟩
      | .ok (second, _) =>
          let expected := X86Andn.handlerStep width dst first (.memory address) nextPc
            (nativeRegisters env frame arena state) .scalar
          { expected with state := { expected.state with rflags := (andnFlags width
            (generatedX86AndnResult (registerValue env frame arena state first) second) state.raw.rflags) } } := by
  simp only [andnMemoryFrame, X86Scalar.read_refines, Reference.X86.scalarRead,
    X86Andn.handlerStep, X86Bt.read_refines]
  have bytes : (multiplyScalarWidth (X86Bzhi.readWidth width)).bytes = width.bytes := by cases width <;> rfl
  have readBytes : (X86Bzhi.readWidth width).bytes = width.bytes := by cases width <;> rfl
  rw [bytes, readBytes]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [native_register_pc, native_register_flags, native_register_write]
      simp only [nativeRegisters]
      congr 1
      congr 1
      funext reg
      by_cases same : reg = dst
      · subst reg
        simp only [Reference.X86.RegisterSlice.reg, ↓reduceIte]
        rw [← X86Scalar.register_write_refines]
        cases width <;> rfl
      · simp only [Reference.X86.RegisterSlice.reg, same, ↓reduceIte]

theorem andn_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.BzhiWidth)
    (dst first : Reference.X86.Register) (address nextPc : NativeWord) :
    Reference.X86.Step (.andn width dst first (.memory address) nextPc) (nativeRegisters env frame arena state)
      (andnMemoryFrame env frame arena state (multiplyScalarWidth (X86Bzhi.readWidth width)) width dst first address nextPc) := by
  rw [andn_memory_frame_matches]
  unfold Reference.X86.Step
  rw [← X86Andn.step_refines width dst first (.memory address) nextPc
    (nativeRegisters env frame arena state) .scalar]
  simp only [X86Andn.handlerStep, X86Bt.read_refines]
  have readBytes : (X86Bzhi.readWidth width).bytes = width.bytes := by cases width <;> rfl
  rw [readBytes]
  cases read : Reference.X86.readSource (nativeRegisters env frame arena state) (.memory address) width.bytes with
  | error fault => exact ⟨rfl, rfl, rfl⟩
  | ok pair =>
      rcases pair with ⟨source, reads⟩
      simp only [Reference.X86.matchesTransition, Reference.X86.definedFlags,
        Reference.X86.observedRegisters, Option.isSome_none, Bool.false_eq_true, ↓reduceIte]
      refine ⟨trivial, trivial, ?_⟩
      congr 1
      exact (andn_flags_observed width _ _).symm


/-- The XMM0 pair update leaves every numeric GPR materialization intact. -/
def registerVector (state : RegisterState) (value : BitVec 128) : RegisterState :=
  { state with raw := { state.raw with xmm0 := value } }

theorem native_register_vector (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (value : BitVec 128) :
    nativeRegisters env frame arena (registerVector state value) =
      { nativeRegisters env frame arena state with xmm0 := value } := rfl

/-- Both actual lanes share the established native-memory observation. Complete
16-byte permission and MOVAPS alignment are the surrounding access witnesses. -/
def xmmMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (store : Bool) (address nextPc : NativeWord) : Transition Reference.X86.State :=
  if store then
    ⟨nativeRegisters env frame arena (registerPc
      (registerMemory state (X86Xmm0.store state.raw.memory address state.raw.xmm0)) nextPc),
      [.memory .write address (Reference.X86.xmm0Bytes state.raw.xmm0) true], none⟩
  else
    ⟨nativeRegisters env frame arena (registerPc
      (registerVector state (X86Xmm0.load state.raw.memory address)) nextPc),
      [.memory .read address (bytesAt state.raw.memory address 16) (initializedAt state.raw.memory address 16)], none⟩

theorem xmm_memory_frame_success (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (store : Bool) (address nextPc : NativeWord) :
    xmmMemoryFrame env frame arena state store address nextPc =
      X86Xmm0.success store address nextPc (nativeRegisters env frame arena state) := by
  cases store <;> simp only [xmmMemoryFrame, Bool.false_eq_true, ↓reduceIte,
    X86Xmm0.success, native_register_pc, native_register_memory, native_register_vector] <;> rfl

theorem xmm_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (store aligned : Bool) (address nextPc : NativeWord)
    (alignment : (aligned && address &&& 15 != 0) = false)
    (permission : permitted (if store then state.raw.memory.writable else state.raw.memory.readable) address 16 = true) :
    xmmMemoryFrame env frame arena state store address nextPc =
      Reference.X86.step (.xmm0Move store aligned address nextPc) (nativeRegisters env frame arena state) := by
  rw [xmm_memory_frame_success]
  exact X86Xmm0.success_refines store aligned address nextPc _ alignment permission

theorem xmm_memory_frame_step_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (store aligned : Bool) (address nextPc : NativeWord)
    (alignment : (aligned && address &&& 15 != 0) = false)
    (permission : permitted (if store then state.raw.memory.writable else state.raw.memory.readable) address 16 = true) :
    Reference.X86.Step (.xmm0Move store aligned address nextPc) (nativeRegisters env frame arena state)
      (xmmMemoryFrame env frame arena state store address nextPc) := by
  rw [xmm_memory_frame_refines env frame arena state store aligned address nextPc alignment permission]
  exact ⟨rfl, rfl, rfl⟩

/-- The production absolute-base argument includes its resolved index. The
existing base-form primitive then selects that complete address directly. -/
theorem xmm_load_absolute_index (immediate indexOffset ignored : NativeWord) :
    generatedX86Xmm0OrdinaryAddr .loadXmm0 true (immediate + indexOffset) ignored ignored =
      immediate + indexOffset := by
  simp [generatedX86Xmm0OrdinaryAddr, generatedX86Xmm0BasePtr, generatedX86Xmm0AddsOffset,
    GeneratedX86Xmm0.baseForm, x86Xmm0ToOp]

/-- REP commits its two original-tag pointer advances and scalar RCX zero
from the captured initial cells. The stride retains all64 wrapping bits. -/
def repFinish (state : RegisterState) (width : Reference.X86.ScalarWidth) (count : Nat) : RegisterState :=
  { raw := { state.raw with gpr := fun r => if r = 1 then 0 else if r = 6 ∨ r = 7 then
      generatedX86RepMovsAdvance (state.raw.gpr r) count (X86Scalar.handlerWidth width) else state.raw.gpr r },
    stack := fun r => if r = 1 then false else state.stack r }

theorem project_address_advance (env : Environment) (frame : Frame) (arena pointer delta : NativeWord) :
    projectAddress env frame arena (pointer + delta) = projectAddress env frame arena pointer + delta := by
  unfold projectAddress
  generalize base env frame .stack = origin
  clear env frame
  rw [BitVec.add_sub_comm, BitVec.add_assoc, BitVec.add_comm delta origin, ← BitVec.add_assoc]

theorem native_rep_finish (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (count : Nat) :
    nativeRegisters env frame arena (repFinish state width count) =
      { nativeRegisters env frame arena state with gpr := X86RepMovs.emittedRegisters width count (nativeRegisters env frame arena state) } := by
  simp only [nativeRegisters, repFinish]
  congr 1
  funext r
  by_cases counter : r = 1
  · subst r
    simp [registerValue, X86RepMovs.emittedRegisters, generatedX86RepMovsRcx,
      generatedX86RegWrite, GeneratedX86RegWrite.write, GeneratedX86RegWrite.writeAt,
      GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits]
  · by_cases pointer : r = 6 ∨ r = 7
    · have stackPointer : r ≠ 4 := by rcases pointer with h | h <;> subst r <;> decide
      simp only [registerValue, if_neg counter, if_pos pointer, if_neg stackPointer,
        X86RepMovs.emittedRegisters, generatedX86RepMovsAdvance]
      split <;> simp only [project_address_advance]
    · simp only [registerValue, if_neg counter, if_neg pointer, X86RepMovs.emittedRegisters]

/-- The observed scalar-copy loop supplies its complete sequential memory
image. The actual handler commits only RSI/RDI/RCX and its next control label. -/
def repMemoryFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (count : Nat) (nextPc : NativeWord) :
    Transition Reference.X86.State :=
  let copied := X86RepMovs.loop width nextPc (generatedX86RepMovsElementCount count)
    (nativeRegisters env frame arena state)
  ⟨nativeRegisters env frame arena (registerPc
    (registerMemory (repFinish state width count) copied.state.memory) nextPc), copied.events, none⟩

theorem rep_memory_frame_matches_handler (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (count : Nat) (nextPc : NativeWord)
    (bound : count ≤ 64)
    (successful : (X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state)).fault = none) :
    repMemoryFrame env frame arena state width count nextPc =
      X86RepMovs.handlerStep width count nextPc (nativeRegisters env frame arena state) := by
  obtain ⟨flags, vector, fs, gs, addressWidth⟩ :=
    X86RepMovs.loop_fields width nextPc count (nativeRegisters env frame arena state)
  have pc := X86RepMovs.loop_success_pc width nextPc count (nativeRegisters env frame arena state) successful
  unfold repMemoryFrame X86RepMovs.handlerStep
  rw [X86RepMovs.bounded_count_exact count bound]
  cases result : X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state) with
  | mk final events fault =>
      have finished : fault = none := by simpa only [result] using successful
      have preserved : { final with gpr := X86RepMovs.emittedRegisters width count (nativeRegisters env frame arena state) } =
          { nativeRegisters env frame arena state with
            gpr := X86RepMovs.emittedRegisters width count (nativeRegisters env frame arena state),
            memory := final.memory, pc := nextPc } := by
        simp only [result] at flags vector fs gs addressWidth pc
        cases final
        simp_all only
      simp only [finished, Option.isSome_none, Bool.false_eq_true, ↓reduceIte,
        native_register_pc, native_register_memory, native_rep_finish]
      rw [preserved]

/-- Complete raw pointer and count writeback refines the canonical forward
copy under its captured count, direction and successful-access witnesses. -/
theorem rep_memory_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (count : Nat) (nextPc : NativeWord)
    (bound : count ≤ 64) (counter : registerValue env frame arena state 1 = BitVec.ofNat 64 count)
    (direction : state.raw.rflags.getLsbD 10 = false)
    (successful : (X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state)).fault = none) :
    repMemoryFrame env frame arena state width count nextPc =
      Reference.X86.step (.repMovs width false 0 nextPc) (nativeRegisters env frame arena state) := by
  rw [rep_memory_frame_matches_handler env frame arena state width count nextPc bound successful]
  exact X86RepMovs.handler_refines width count nextPc _ bound counter direction successful

theorem rep_memory_frame_step_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (count : Nat) (nextPc : NativeWord)
    (bound : count ≤ 64) (counter : registerValue env frame arena state 1 = BitVec.ofNat 64 count)
    (direction : state.raw.rflags.getLsbD 10 = false)
    (successful : (X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state)).fault = none) :
    Reference.X86.Step (.repMovs width false 0 nextPc) (nativeRegisters env frame arena state)
      (repMemoryFrame env frame arena state width count nextPc) := by
  rw [rep_memory_frame_refines env frame arena state width count nextPc bound counter direction successful]
  exact ⟨rfl, rfl, rfl⟩

/-- The emitted internal CALL decrements the raw stack offset, stores its
saved return word and selects its linked target label. -/
def callLabelFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (target savedReturn : NativeWord) : Transition Reference.X86.State :=
  let address := registerValue env frame arena state 4 - 8
  let advanced := advanceStack state (-8)
  let memory := X86Push.store .w64 state.raw.memory address savedReturn
  ⟨nativeRegisters env frame arena (registerPc (registerMemory advanced memory) target),
    [.memory .write address (valueBytes savedReturn 8) true], none⟩

theorem call_label_frame_success (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (target savedReturn : NativeWord) :
    callLabelFrame env frame arena state target savedReturn =
      X86Call.callSuccess target savedReturn [] (nativeRegisters env frame arena state) := by
  simp only [callLabelFrame, X86Call.callSuccess, native_register_pc, native_register_memory, native_advance_stack]
  have advanced : registerValue env frame arena state 4 + (-8) = registerValue env frame arena state 4 - 8 := by
    generalize registerValue env frame arena state 4 = value
    clear env frame arena state target savedReturn
    bv_decide
  change (⟨{ nativeRegisters env frame arena state with
      gpr := fun r => if r = 4 then registerValue env frame arena state 4 + (-8) else registerValue env frame arena state r,
      memory := X86Push.store .w64 state.raw.memory (registerValue env frame arena state 4 - 8) savedReturn,
      pc := target }, [.memory .write (registerValue env frame arena state 4 - 8) (valueBytes savedReturn 8) true], none⟩ :
      Transition Reference.X86.State) = _
  rw [advanced]
  rfl

/-- Linked-label and saved-return words use the same code coordinate as the
reference call. Step(e)'s link relation supplies their materialized addresses. -/
theorem call_label_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (target savedReturn : NativeWord)
    (canonical : Reference.X86.canonicalTarget state.raw.addressWidth target = true)
    (writable : permitted state.raw.memory.writable (registerValue env frame arena state 4 - 8) 8 = true) :
    callLabelFrame env frame arena state target savedReturn =
      Reference.X86.step (.call (.immediate target) savedReturn) (nativeRegisters env frame arena state) := by
  rw [call_label_frame_success]
  exact X86Call.call_success_refines (.immediate target) target savedReturn [] _ rfl canonical writable

theorem call_label_frame_step_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (target savedReturn : NativeWord)
    (canonical : Reference.X86.canonicalTarget state.raw.addressWidth target = true)
    (writable : permitted state.raw.memory.writable (registerValue env frame arena state 4 - 8) 8 = true) :
    Reference.X86.Step (.call (.immediate target) savedReturn) (nativeRegisters env frame arena state)
      (callLabelFrame env frame arena state target savedReturn) := by
  rw [call_label_frame_refines env frame arena state target savedReturn canonical writable]
  exact ⟨rfl, rfl, rfl⟩

/-- SUB_RET samples the full saved word at the old stack offset before
advancing RSP and entering the emitted return-label dispatcher. -/
def returnStackWord (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) : NativeWord :=
  GeneratedX86MemAccess.load
    (fun i => state.raw.memory.value (registerValue env frame arena state 4 + BitVec.ofNat 64 i)) .w64

def returnStackReads (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) : List Event :=
  [.memory .read (registerValue env frame arena state 4)
    (bytesAt state.raw.memory (registerValue env frame arena state 4) 8)
    (initializedAt state.raw.memory (registerValue env frame arena state 4) 8)]

def returnLabelFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) : Transition Reference.X86.State :=
  ⟨nativeRegisters env frame arena
    (registerPc (advanceStack state 8) (returnStackWord env frame arena state)),
    returnStackReads env frame arena state, none⟩

theorem return_label_frame_success (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) :
    returnLabelFrame env frame arena state =
      X86Call.returnSuccess (returnStackWord env frame arena state)
        (returnStackReads env frame arena state) (nativeRegisters env frame arena state) := by
  simp only [returnLabelFrame, X86Call.returnSuccess, native_register_pc, native_advance_stack]
  rfl

/-- Readability and canonicality are ISA/profile premises. The emitted C
body is the direct load/advance/goto sequence. -/
theorem return_label_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (nextPc : NativeWord)
    (readable : permitted state.raw.memory.readable (registerValue env frame arena state 4) 8 = true)
    (canonical : Reference.X86.canonicalTarget state.raw.addressWidth (returnStackWord env frame arena state) = true) :
    returnLabelFrame env frame arena state =
      Reference.X86.step (.returnNear 0 nextPc) (nativeRegisters env frame arena state) := by
  rw [return_label_frame_success]
  apply X86Call.return_success_refines
  · simp only [X86Scalar.read, Reference.X86.ScalarWidth.bytes, nativeRegisters,
      readable, ↓reduceIte, X86Scalar.handlerWidth, returnStackWord, returnStackReads]
  · exact canonical

theorem return_label_frame_step_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (nextPc : NativeWord)
    (readable : permitted state.raw.memory.readable (registerValue env frame arena state 4) 8 = true)
    (canonical : Reference.X86.canonicalTarget state.raw.addressWidth (returnStackWord env frame arena state) = true) :
    Reference.X86.Step (.returnNear 0 nextPc) (nativeRegisters env frame arena state)
      (returnLabelFrame env frame arena state) := by
  rw [return_label_frame_refines env frame arena state nextPc readable canonical]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86NumericAddress

namespace KProgFormal.Refinement.X86NumericAddress.FreshAux
open Reference

def flags (pf af : Bool) (old : Reference.Word) : Reference.Word :=
  X86.setFlag (X86.setFlag old 2 pf) 4 af

theorem flags_mask (pf af : Bool) (old : Reference.Word) :
    flags pf af old &&& 0xffffffffffffffeb = old &&& 0xffffffffffffffeb := by
  unfold flags X86.setFlag Reference.Word
  bv_decide

theorem flags_realize (old target : Reference.Word)
    (same : old &&& 0xffffffffffffffeb = target &&& 0xffffffffffffffeb) :
    flags (target.getLsbD 2) (target.getLsbD 4) old = target := by
  unfold flags X86.setFlag Reference.Word at *
  bv_decide

/-- Each successful production ANDN/BZHI body reads fresh PF then fresh AF.
Faulting memory access retains its complete preceding state and effects. -/
def apply (pf af : Bool) (effect : Transition X86.State) : Transition X86.State :=
  if effect.fault.isSome then effect
  else { effect with state := { effect.state with rflags := flags pf af effect.state.rflags } }

theorem matches_preserved (instruction : X86.Instruction)
    (mask : X86.definedFlags instruction = 0xffffffffffffffeb)
    (expected actual : Transition X86.State)
    (matching : X86.matchesTransition instruction expected actual) (pf af : Bool) :
    X86.matchesTransition instruction expected (apply pf af actual) := by
  rcases matching with ⟨events, fault, state⟩
  unfold apply
  cases present : actual.fault with
  | some error =>
    simp only [present, Option.isSome_some, ↓reduceIte]
    exact ⟨events, fault, state⟩
  | none =>
    have expectedFault : expected.fault = none := fault.trans present
    unfold X86.matchesTransition
    simp only [present, Option.isSome_none, Bool.false_eq_true, ↓reduceIte]
    refine ⟨events, expectedFault, ?_⟩
    dsimp only at state
    simpa only [expectedFault, Option.isSome_none, Bool.false_eq_true, ↓reduceIte,
      mask, flags_mask] using state

/-- Every complete state with the same defined outputs is realized by the two
independent production choices. This supplies a local output-transport law. -/
theorem realizes (instruction : X86.Instruction)
    (mask : X86.definedFlags instruction = 0xffffffffffffffeb)
    (registers : ∀ state, X86.observedRegisters instruction state = state.gpr)
    (expected representative target : Transition X86.State)
    (first : X86.matchesTransition instruction expected representative)
    (second : X86.matchesTransition instruction expected target) :
    apply (target.state.rflags.getLsbD 2) (target.state.rflags.getLsbD 4) representative = target := by
  rcases first with ⟨events1, fault1, state1⟩
  rcases second with ⟨events2, fault2, state2⟩
  have events : representative.events = target.events := events1.symm.trans events2
  have fault : representative.fault = target.fault := fault1.symm.trans fault2
  cases expectedFault : expected.fault with
  | some error =>
    have repFault := fault1.symm.trans expectedFault
    have ones : (0xffffffffffffffff : Reference.Word) = BitVec.allOnes 64 := by decide
    simp only [expectedFault, Option.isSome_some, ↓reduceIte, ones, BitVec.and_allOnes] at state1 state2
    have states : representative.state = target.state := state1.symm.trans state2
    simp only [apply, repFault, Option.isSome_some, ↓reduceIte]
    cases representative; cases target
    simp_all
  | none =>
    have repFault := fault1.symm.trans expectedFault
    simp only [expectedFault, Option.isSome_none, Bool.false_eq_true, ↓reduceIte, mask, registers] at state1 state2
    have observed := state1.symm.trans state2
    have same := congrArg X86.State.rflags observed
    have bits := flags_realize representative.state.rflags target.state.rflags same
    have states := congrArg (fun s : X86.State => { s with rflags := target.state.rflags }) observed
    change { representative.state with rflags := target.state.rflags } = target.state at states
    simp only [apply, repFault, Option.isSome_none, Bool.false_eq_true, ↓reduceIte, bits]
    cases representative; cases target
    simp_all


def word (bit : Bool) : Reference.Word := if bit then 1 else 0
@[simp] theorem word_bit (bit : Bool) : (word bit).getLsbD 0 = bit := by cases bit <;> rfl

def inputFlags (choices : Nat → Reference.Word) (visit : Nat) (effect : Transition X86.State) :=
  apply ((choices visit).getLsbD 0) ((choices (visit+1)).getLsbD 0) effect

def choose (original : Nat → Reference.Word) (visit : Nat) (pf af : Bool) : Nat → Reference.Word :=
  fun n => if n = visit then word pf else if n = visit+1 then word af else original n

theorem realizes_stream (instruction : X86.Instruction)
    (mask : X86.definedFlags instruction = 0xffffffffffffffeb)
    (registers : ∀ state, X86.observedRegisters instruction state = state.gpr)
    (expected representative target : Transition X86.State)
    (first : X86.matchesTransition instruction expected representative)
    (second : X86.matchesTransition instruction expected target)
    (original : Nat → Reference.Word) (visit : Nat) :
    ∃ choices : Nat → Reference.Word,
      (∀ n, n ≠ visit → n ≠ visit+1 → choices n = original n) ∧
      inputFlags choices visit representative = target := by
  refine ⟨choose original visit (target.state.rflags.getLsbD 2) (target.state.rflags.getLsbD 4), ?_, ?_⟩
  · intro n first second
    simp only [choose, first, second, ↓reduceIte]
  · have distinct : visit+1 ≠ visit := by omega
    simp only [inputFlags, choose, ↓reduceIte, distinct, word_bit]
    exact realizes instruction mask registers expected representative target first second

def andnRegisterBody (pf af : Bool) (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst first second : X86.Register) (nextPc : NativeWord) : Transition X86.State :=
  apply pf af (⟨nativeRegisters env frame arena (X86NumericAddress.andnRegister env frame arena state width dst first second nextPc), [], none⟩)

theorem andn_register_body_refines (pf af : Bool) (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst first second : X86.Register) (nextPc : NativeWord) :
    X86.Step (.andn width dst first (.register second) nextPc) (nativeRegisters env frame arena state) (andnRegisterBody pf af env frame arena state width dst first second nextPc) := by
  exact matches_preserved _ rfl _ _ (andn_register_frame_refines env frame arena state width dst first second nextPc) pf af

theorem andn_register_body_realizes (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst first second : X86.Register) (nextPc : NativeWord)
    (target : Transition X86.State) (admitted : X86.Step (.andn width dst first (.register second) nextPc) (nativeRegisters env frame arena state) target) :
    ∃ pf af, andnRegisterBody pf af env frame arena state width dst first second nextPc = target := by
  refine ⟨target.state.rflags.getLsbD 2, target.state.rflags.getLsbD 4, ?_⟩
  exact realizes _ rfl (fun _ => rfl) _ _ target (andn_register_frame_refines env frame arena state width dst first second nextPc) admitted

def bzhiRegisterBody (pf af : Bool) (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst src count : X86.Register) (nextPc : NativeWord) : Transition X86.State :=
  apply pf af (⟨nativeRegisters env frame arena (X86NumericAddress.bzhiRegister env frame arena state width dst src count nextPc), [], none⟩)

theorem bzhi_register_body_refines (pf af : Bool) (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst src count : X86.Register) (nextPc : NativeWord) :
    X86.Step (.bzhi width dst (.register src) count nextPc) (nativeRegisters env frame arena state) (bzhiRegisterBody pf af env frame arena state width dst src count nextPc) := by
  exact matches_preserved _ rfl _ _ (by
      rw [bzhi_register_frame_refines]
      exact ⟨rfl, rfl, rfl⟩) pf af

theorem bzhi_register_body_realizes (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst src count : X86.Register) (nextPc : NativeWord)
    (target : Transition X86.State) (admitted : X86.Step (.bzhi width dst (.register src) count nextPc) (nativeRegisters env frame arena state) target) :
    ∃ pf af, bzhiRegisterBody pf af env frame arena state width dst src count nextPc = target := by
  refine ⟨target.state.rflags.getLsbD 2, target.state.rflags.getLsbD 4, ?_⟩
  exact realizes _ rfl (fun _ => rfl) _ _ target (by
      rw [bzhi_register_frame_refines]
      exact ⟨rfl, rfl, rfl⟩) admitted

def andnMemoryBody (pf af : Bool) (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst first : X86.Register) (address nextPc : NativeWord) : Transition X86.State :=
  apply pf af (andnMemoryFrame env frame arena state (multiplyScalarWidth (X86Bzhi.readWidth width)) width dst first address nextPc)

theorem andn_memory_body_refines (pf af : Bool) (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst first : X86.Register) (address nextPc : NativeWord) :
    X86.Step (.andn width dst first (.memory address) nextPc) (nativeRegisters env frame arena state) (andnMemoryBody pf af env frame arena state width dst first address nextPc) := by
  exact matches_preserved _ rfl _ _ (andn_memory_frame_refines env frame arena state width dst first address nextPc) pf af

theorem andn_memory_body_realizes (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst first : X86.Register) (address nextPc : NativeWord)
    (target : Transition X86.State) (admitted : X86.Step (.andn width dst first (.memory address) nextPc) (nativeRegisters env frame arena state) target) :
    ∃ pf af, andnMemoryBody pf af env frame arena state width dst first address nextPc = target := by
  refine ⟨target.state.rflags.getLsbD 2, target.state.rflags.getLsbD 4, ?_⟩
  exact realizes _ rfl (fun _ => rfl) _ _ target (andn_memory_frame_refines env frame arena state width dst first address nextPc) admitted

def bzhiMemoryBody (pf af : Bool) (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst count : X86.Register) (address nextPc : NativeWord) : Transition X86.State :=
  apply pf af (bzhiMemoryFrame env frame arena state width dst count address nextPc)

theorem bzhi_memory_body_refines (pf af : Bool) (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst count : X86.Register) (address nextPc : NativeWord) :
    X86.Step (.bzhi width dst (.memory address) count nextPc) (nativeRegisters env frame arena state) (bzhiMemoryBody pf af env frame arena state width dst count address nextPc) := by
  exact matches_preserved _ rfl _ _ (by
      rw [bzhi_memory_frame_refines]
      exact ⟨rfl, rfl, rfl⟩) pf af

theorem bzhi_memory_body_realizes (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame) (arena : NativeWord)
    (state : RegisterState) (width : X86.BzhiWidth)
    (dst count : X86.Register) (address nextPc : NativeWord)
    (target : Transition X86.State) (admitted : X86.Step (.bzhi width dst (.memory address) count nextPc) (nativeRegisters env frame arena state) target) :
    ∃ pf af, bzhiMemoryBody pf af env frame arena state width dst count address nextPc = target := by
  refine ⟨target.state.rflags.getLsbD 2, target.state.rflags.getLsbD 4, ?_⟩
  exact realizes _ rfl (fun _ => rfl) _ _ target (by
      rw [bzhi_memory_frame_refines]
      exact ⟨rfl, rfl, rfl⟩) admitted

end KProgFormal.Refinement.X86NumericAddress.FreshAux
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.flags_realize
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.matches_preserved
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.realizes
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.realizes_stream
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.andn_register_body_refines
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.andn_register_body_realizes
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.bzhi_register_body_refines
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.bzhi_register_body_realizes
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.andn_memory_body_refines
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.andn_memory_body_realizes
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.bzhi_memory_body_refines
#print axioms KProgFormal.Refinement.X86NumericAddress.FreshAux.bzhi_memory_body_realizes

namespace KProgFormal.Refinement.X86NumericAddress
open Reference EntryEnvironment

/-- Current REP uses the observed numeric RCX, never the legacy IMM count.
Only the successful loop image/events and final progress are projected here. -/
def repFullCountFrame (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (nextPc : NativeWord) :
    Transition Reference.X86.State :=
  let count := (registerValue env frame arena state 1).toNat
  let copied := X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state)
  ⟨nativeRegisters env frame arena (registerPc
    (registerMemory (repFinish state width count) copied.state.memory) nextPc), copied.events, none⟩

theorem rep_full_count_frame_matches_handler (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (nextPc : NativeWord)
    (successful : (X86RepMovs.loop width nextPc (registerValue env frame arena state 1).toNat
      (nativeRegisters env frame arena state)).fault = none) :
    repFullCountFrame env frame arena state width nextPc =
      X86RepMovs.fullCountHandlerStep width nextPc (nativeRegisters env frame arena state) := by
  let count := (registerValue env frame arena state 1).toNat
  change (X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state)).fault = none at successful
  obtain ⟨flags, vector, fs, gs, addressWidth⟩ :=
    X86RepMovs.loop_fields width nextPc count (nativeRegisters env frame arena state)
  have pc := X86RepMovs.loop_success_pc width nextPc count (nativeRegisters env frame arena state) successful
  unfold repFullCountFrame X86RepMovs.fullCountHandlerStep
  change (⟨nativeRegisters env frame arena (registerPc
    (registerMemory (repFinish state width count)
      (X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state)).state.memory) nextPc),
    (X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state)).events, none⟩ : Transition Reference.X86.State) =
      (let copied := X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state)
       if copied.fault.isSome then copied else
         ⟨{ copied.state with gpr := X86RepMovs.emittedRegisters width count (nativeRegisters env frame arena state) }, copied.events, none⟩)
  cases result : X86RepMovs.loop width nextPc count (nativeRegisters env frame arena state) with
  | mk final events fault =>
      have finished : fault = none := by simpa only [result] using successful
      have preserved : { final with gpr := X86RepMovs.emittedRegisters width count (nativeRegisters env frame arena state) } =
          { nativeRegisters env frame arena state with
            gpr := X86RepMovs.emittedRegisters width count (nativeRegisters env frame arena state),
            memory := final.memory, pc := nextPc } := by
        simp only [result] at flags vector fs gs addressWidth pc
        cases final
        simp_all only
      simp only [finished, Option.isSome_none, Bool.false_eq_true, ↓reduceIte,
        native_register_pc, native_register_memory, native_rep_finish]
      rw [preserved]

theorem rep_full_count_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (nextPc : NativeWord)
    (direction : state.raw.rflags.getLsbD 10 = false)
    (successful : (X86RepMovs.loop width nextPc (registerValue env frame arena state 1).toNat
      (nativeRegisters env frame arena state)).fault = none) :
    repFullCountFrame env frame arena state width nextPc =
      Reference.X86.step (.repMovs width false 0 nextPc) (nativeRegisters env frame arena state) := by
  rw [rep_full_count_frame_matches_handler env frame arena state width nextPc successful]
  exact X86RepMovs.full_count_handler_refines width nextPc _ direction successful

theorem rep_full_count_frame_step_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (nextPc : NativeWord)
    (direction : state.raw.rflags.getLsbD 10 = false)
    (successful : (X86RepMovs.loop width nextPc (registerValue env frame arena state 1).toNat
      (nativeRegisters env frame arena state)).fault = none) :
    Reference.X86.Step (.repMovs width false 0 nextPc) (nativeRegisters env frame arena state)
      (repFullCountFrame env frame arena state width nextPc) := by
  rw [rep_full_count_frame_refines env frame arena state width nextPc direction successful]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86NumericAddress

namespace KProgFormal.Refinement.X86NumericAddress
open Reference EntryEnvironment

/-- Relate the once-captured C pointers/index loop and final original-tag
writeback to the progress projection. Actual access/recovery primitives and
physical arena representation retain their explicitly stated interface. -/
theorem rep_full_count_frame_matches_indexed (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth) (nextPc : NativeWord)
    (successful : (X86RepMovs.Indexed.loop width nextPc 0 (registerValue env frame arena state 1).toNat
      (nativeRegisters env frame arena state)).fault = none) :
    repFullCountFrame env frame arena state width nextPc =
      X86RepMovs.Indexed.handlerStep width nextPc (nativeRegisters env frame arena state) := by
  have faults := X86RepMovs.Indexed.loop_fault_matches width nextPc
    (registerValue env frame arena state 1).toNat 0 (nativeRegisters env frame arena state)
  rw [X86RepMovs.Indexed.project_zero] at faults
  have progressOk : (X86RepMovs.loop width nextPc (registerValue env frame arena state 1).toNat
      (nativeRegisters env frame arena state)).fault = none := by
    rw [← faults]
    exact successful
  rw [rep_full_count_frame_matches_handler env frame arena state width nextPc progressOk]
  exact (X86RepMovs.Indexed.handler_matches_progress width nextPc _ successful).symm

end KProgFormal.Refinement.X86NumericAddress
