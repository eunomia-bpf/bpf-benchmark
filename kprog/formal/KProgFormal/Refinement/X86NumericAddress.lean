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

/-- ANDN's actual shared logic macro writes PF as well as CF/ZF/SF/OF.
The ISA leaves PF undefined; the raw model must still retain the real write. -/
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

/-- Exact raw writeback, with the production PF assignment explicitly retained.
The following refinement uses the canonical defined-output mask, not equality
with a selected value of an architecturally undefined flag. -/
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

/-- BZHI samples the low count byte before the destination writer and writes
exactly CF/ZF/SF/OF; unlike the shared ANDN macro it leaves PF untouched. -/
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

end KProgFormal.Refinement.X86NumericAddress
