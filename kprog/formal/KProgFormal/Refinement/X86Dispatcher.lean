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


/-- CMOV has no byte operand form. The width field retains the production
zero-to64 fallback through the same raw-width decoder. -/
def cmovWidthOf (flags : Byte) : Option Reference.X86.CmovWidth := do
  match ← widthOf flags with
  | .w16 => some .w16 | .w32 => some .w32 | .w64 => some .w64 | .w8 => none

def cmovScalarWidth : Reference.X86.CmovWidth → ScalarWidth
  | .w16 => .w16 | .w32 => .w32 | .w64 => .w64

theorem cmov_width_binding_decodes (flags : Byte) (width : Reference.X86.CmovWidth)
    (binding : WidthBinding flags (cmovScalarWidth width)) :
    cmovWidthOf flags = some width := by
  have decoded := width_binding_decodes flags (cmovScalarWidth width) binding
  cases width <;> simp [cmovWidthOf, decoded, cmovScalarWidth] at *

/-- BSWAP selects only its native32/64-bit forms; absent FLAGS still uses
production64-bit fallback, with no new runtime guard. -/
def bswapWidthOf (flags : Byte) : Option Reference.X86.BzhiWidth := do
  match ← widthOf flags with
  | .w32 => some .w32 | .w64 => some .w64 | _ => none

def bswapScalarWidth : Reference.X86.BzhiWidth → ScalarWidth
  | .w32 => .w32 | .w64 => .w64

theorem bswap_width_binding_decodes (flags : Byte) (width : Reference.X86.BzhiWidth)
    (binding : WidthBinding flags (bswapScalarWidth width)) :
    bswapWidthOf flags = some width := by
  have decoded := width_binding_decodes flags (bswapScalarWidth width) binding
  cases width <;> simp [bswapWidthOf, decoded, bswapScalarWidth] at *

/-- Partial register-handler dispatcher. Existing NOP/MOV steps retain their
prefix selection; the later singleton CMOV/BSWAP/POPCNT/XCHG gates consume their actual
raw opcode, width and GPR fields. Every intervening unproved opcode remains
None. Distinct generated opcode identities prevent an intervening handler
from taking these gates; None never means production success/rejection. -/
def dispatchRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchThroughMove env frame arena code flags aux dst src value nextPc state with
  | some result => some result
  | none =>
      if code = GeneratedX86DispatchSingleton.code .cmov then do
        let width ← cmovWidthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (conditionalMoveWord env frame arena state width aux destination source nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .bswap then do
        let width ← bswapWidthOf flags
        let destination ← registerOf dst
        pure ⟨nativeRegisters env frame arena
          (byteSwapRegister env frame arena state width destination nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .popcnt then do
        let width ← cmovWidthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (populationCountRegister env frame arena state width destination source nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .xchg then do
        let width ← widthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (exchangeRegisters env frame arena state width destination source nextPc), [], none⟩
      else none

/-- Field/operand identities only. CMOV consumes the entire condition AUX;
XCHG ignores AUX and immediate, matching the production low-slice encoder.
The native instruction is the single canonical ISA's existing constructor. -/
inductive RegisterBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Word) :
    Nat → Reference.X86.Instruction → Prop where
  | move (code : Nat) (native : Reference.X86.Instruction)
      (fields : MoveBinding flags aux dst src value nextPc code native) :
      RegisterBinding flags aux dst src value nextPc code native
  | cmov (width : Reference.X86.CmovWidth) (cc : Fin 16) (destination source : Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source)
      (conditionField : aux = BitVec.ofNat 32 cc.val) :
      RegisterBinding flags aux dst src value nextPc (GeneratedX86DispatchSingleton.code .cmov)
        (.cmov width cc destination (.register source) nextPc)
  | byteSwap (width : Reference.X86.BzhiWidth) (destination : Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (dstField : dst = registerByte destination) :
      RegisterBinding flags aux dst src value nextPc (GeneratedX86DispatchSingleton.code .bswap)
        (.byteSwap width destination nextPc)
  | populationCount (width : Reference.X86.CmovWidth) (destination source : Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source) :
      RegisterBinding flags aux dst src value nextPc (GeneratedX86DispatchSingleton.code .popcnt)
        (.popcount width destination (.register source) nextPc)
  | exchange (width : ScalarWidth) (destination source : Register)
      (widthField : WidthBinding flags width)
      (dstField : dst = registerByte destination) (srcField : src = registerByte source) :
      RegisterBinding flags aux dst src value nextPc (GeneratedX86DispatchSingleton.code .xchg)
        (.exchange width (.low destination) (.low source) nextPc)

/-- One complete raw-frame step for the currently lifted register opcodes:
NOP/MOV immediate/MOV register/CMOV(all16)/BSWAP/POPCNT/XCHG. Neither component handler
semantics nor a chosen condition/value/state equation is assumed. This is a
partial dispatcher theorem, not all77 operations or a compiled-body claim. -/
theorem register_dispatch_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : RegisterBinding flags aux dst src value nextPc code native) :
    dispatchRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | move code native fields =>
      simp only [dispatchRegisters, step_through_move_refines env frame arena code flags aux dst src value nextPc state native fields]
  | cmov width cc destination source widthField dstField srcField conditionField =>
      subst dst; subst src; subst aux
      have decoded := cmov_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, decoded, register_of_byte] using
        congrArg some (conditional_move_word_frame_refines env frame arena state width cc destination source nextPc)
  | byteSwap width destination widthField dstField =>
      subst dst
      have decoded := bswap_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, decoded, register_of_byte] using
        congrArg some (byte_swap_register_frame_refines env frame arena state width destination nextPc)
  | populationCount width destination source widthField dstField srcField =>
      subst dst; subst src
      have decoded := cmov_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, decoded, register_of_byte] using
        congrArg some (population_count_register_frame_refines env frame arena state width destination source nextPc)
  | exchange width destination source widthField dstField srcField =>
      subst dst; subst src
      have decoded := width_binding_decodes flags width widthField
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, decoded, register_of_byte] using
        congrArg some (exchange_register_frame_refines env frame arena state width destination source nextPc)

end KProgFormal.Refinement.X86Dispatcher
