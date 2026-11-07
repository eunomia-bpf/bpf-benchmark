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
  registerPc (registerFlags state (X86Arithmetic.flags width .compare left right state.raw.rflags)) nextPc

theorem compare_register_frame_refines (env : Environment) (frame : Frame) (arena : NativeWord)
    (state : RegisterState) (width : Reference.X86.ScalarWidth)
    (dst src : Reference.X86.RegisterSlice) (nextPc : NativeWord) :
    (⟨nativeRegisters env frame arena (compareRegister env frame arena state width dst src nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.arithmetic width .compare (.register dst) (.register src) nextPc)
        (nativeRegisters env frame arena state) := by
  rw [← X86Arithmetic.step_refines]
  simp only [compareRegister, native_register_pc, native_register_flags, native_register_read,
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
  registerPc (registerFlags state (X86Arithmetic.flags width .compare left right state.raw.rflags)) nextPc

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
  simp only [compareImmediate, native_register_pc, native_register_flags, native_register_read,
    X86Arithmetic.handlerStep, X86Scalar.read_refines, Reference.X86.ScalarDestination.source,
    Reference.X86.scalarRead, List.nil_append, List.append_nil, flags]
  rfl

end KProgFormal.Refinement.X86NumericAddress
