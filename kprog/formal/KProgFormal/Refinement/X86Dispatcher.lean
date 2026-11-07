import KProgFormal.Refinement.X86NumericAddress
import KProgFormal.Generated.GeneratedX86RegDispatch
import KProgFormal.Generated.GeneratedX86RegLaneAux
import KProgFormal.Generated.GeneratedX86Opcode
import KProgFormal.Generated.GeneratedX86DispatchSingleton

namespace KProgFormal.Refinement.X86Dispatcher
open Reference
open Reference.X86 (ScalarWidth Register RegisterSlice)
open X86NumericAddress

/-- Implementation register-byte selection, matching the generated cell
contract including all absent bytes16..255. This is not an ISA decoder. -/
def registerOf (code : Byte) : Option Register :=
  if h : code.toNat < 16 then some ⟨code.toNat, h⟩ else none

def registerByte (reg : Register) : Byte := BitVec.ofNat 8 reg.val

theorem register_cell_contract (code : Byte) :
    (registerOf code).map (fun r => r.val) = GeneratedX86RegDispatch.cellOf code := by
  unfold registerOf GeneratedX86RegDispatch.cellOf GeneratedX86RegDispatch.gprCount
  split <;> rfl

theorem register_of_byte (reg : Register) : registerOf (registerByte reg) = some reg := by
  have bound : reg.val < 256 := by have := reg.isLt; omega
  simp [registerOf, registerByte, BitVec.toNat_ofNat, Nat.mod_eq_of_lt bound, reg.isLt]

/-- Legal operand-width fields use the actual absent0->8 resolution. None
marks fields outside this proved interface, not a new C rejection. -/
def widthOf (flags : Byte) : Option ScalarWidth :=
  match GeneratedX86Width.effective flags.toNat with
  | 1 => some .w8 | 2 => some .w16 | 4 => some .w32 | 8 => some .w64 | _ => none

def WidthBinding (flags : Byte) (width : ScalarWidth) : Prop :=
  flags.toNat = width.bytes ∨ (flags.toNat = 0 ∧ width = .w64)

theorem width_binding_decodes (flags : Byte) (width : ScalarWidth) (binding : WidthBinding flags width) :
    widthOf flags = some width := by
  rcases binding with exactWidth | ⟨absent, rfl⟩
  · cases width <;> simp [widthOf, GeneratedX86Width.effective, GeneratedX86Width.absentCode,
      GeneratedX86Width.defaultCode, exactWidth, Reference.X86.ScalarWidth.bytes]
  · simp [widthOf, GeneratedX86Width.effective, GeneratedX86Width.absentCode,
      GeneratedX86Width.defaultCode, absent]

/-- AUX shifts matter only at byte width. Native high-byte operands can
name only the first four GPRs; other widths consume every unused AUX byte. -/
def sliceOf (width : ScalarWidth) (code : Byte) (shift : BitVec 32) : Option RegisterSlice := do
  let reg ← registerOf code
  if width = .w8 then
    if shift = 0 then pure (.low reg)
    else if shift = 8 then
      if h : reg.val < 4 then pure (.high ⟨reg.val, h⟩) else none
    else none
  else pure (.low reg)

def SliceBinding (width : ScalarWidth) (code : Byte) (shift : BitVec 32) (slice : RegisterSlice) : Prop :=
  code = registerByte slice.reg ∧
    match width, slice with
    | .w8, .low _ => shift = 0
    | .w8, .high _ => shift = 8
    | _, .low _ => True
    | _, .high _ => False

theorem slice_binding_decodes (width : ScalarWidth) (code : Byte) (shift : BitVec 32)
    (slice : RegisterSlice) (binding : SliceBinding width code shift slice) :
    sliceOf width code shift = some slice := by
  rcases binding with ⟨rfl, lane⟩
  cases slice with
  | low reg =>
      by_cases byte : width = .w8
      · subst width
        change shift = 0 at lane
        subst shift
        simp [sliceOf, register_of_byte, Reference.X86.RegisterSlice.reg]
      · simp [sliceOf, register_of_byte, byte, Reference.X86.RegisterSlice.reg]
  | high reg =>
      cases width <;> simp only at lane
      · change shift = 8 at lane
        subst shift
        simp [sliceOf, register_of_byte, Reference.X86.RegisterSlice.reg, reg.isLt]
      all_goals contradiction

/-- These production prefix gates precede MOV. Their bodies are not yet
lifted here; reaching one stays outside this interface. The generated opcode
table supplies their identities and preserves the actual gate order. -/
def beforeMove (code : Nat) : Bool :=
  ([.movLoadMapPtr, .movLoadHelperId, .callMemcpy, .callMemset,
      .callMemcpyReg, .callMemsetReg, .callReg].map GeneratedX86Opcode.code).contains code

/-- Covered portion of the actual L_EXEC prefix. NOP ignores all fields;
MOV selects raw width, GPR bytes and AUX lanes, then uses the proved raw
stack-frame body. None means unproved/out-of-binding, never runtime success
or a claim that C added a guard for malformed fields or other opcodes. -/
def dispatchThroughMove (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86DispatchSingleton.code .nop then
    some ⟨nativeRegisters env frame arena (registerPc state nextPc), [], none⟩
  else if beforeMove code then none
  else if code = GeneratedX86DispatchSingleton.code .movImm then do
    let width ← widthOf flags
    let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
    pure ⟨nativeRegisters env frame arena (registerPc (writeRegister env frame arena state width destination value) nextPc), [], none⟩
  else if code = GeneratedX86DispatchSingleton.code .movReg then do
    let width ← widthOf flags
    let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
    let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
    pure ⟨nativeRegisters env frame arena (moveRegister env frame arena state width destination source nextPc), [], none⟩
  else none

/-- Field identities only: nextPc/value remain the same supplied native
fields. Artifact decoding/layout/initial ABI still must establish them. -/
inductive MoveBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word) :
    Nat → Reference.X86.Instruction → Prop where
  | nop : MoveBinding flags aux dst src value nextPc (GeneratedX86DispatchSingleton.code .nop) (.nop nextPc)
  | immediate (width : ScalarWidth) (destination : RegisterSlice)
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination) :
      MoveBinding flags aux dst src value nextPc (GeneratedX86DispatchSingleton.code .movImm)
        (.move width (.register destination) (.immediate value) nextPc)
  | register (width : ScalarWidth) (destination source : RegisterSlice)
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (srcField : SliceBinding width src (GeneratedX86RegLaneAux.srcShift aux) source) :
      MoveBinding flags aux dst src value nextPc (GeneratedX86DispatchSingleton.code .movReg)
        (.move width (.register destination) (.register source) nextPc)

/-- One raw-field prefix step theorem against the SAME canonical ISA.
Neither a handler equation nor a state/value equality is a premise. This is
NOP and MOV, not all77 operations or compiled/native invocation transport. -/
theorem step_through_move_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : MoveBinding flags aux dst src value nextPc code native) :
    dispatchThroughMove env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | nop => rfl
  | immediate width destination widthField dstField =>
      have widthDecoded := width_binding_decodes flags width widthField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      simpa [dispatchThroughMove, beforeMove, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, widthDecoded, dstDecoded] using
        congrArg some (move_immediate_frame_refines env frame arena state width destination value nextPc)
  | register width destination source widthField dstField srcField =>
      have widthDecoded := width_binding_decodes flags width widthField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      have srcDecoded := slice_binding_decodes width src _ source srcField
      simpa [dispatchThroughMove, beforeMove, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, widthDecoded, dstDecoded, srcDecoded] using
        congrArg some (move_register_frame_refines env frame arena state width destination source nextPc)

end KProgFormal.Refinement.X86Dispatcher
