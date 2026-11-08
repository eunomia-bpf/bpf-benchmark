import KProgFormal.X86BranchEmit
import KProgFormal.Generated.GeneratedX86MemAux
import KProgFormal.Generated.GeneratedX86Specialization
import KProgFormal.Generated.GeneratedX86DispatchFamily
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
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
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
inductive MoveBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) :
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
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
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

/-- Both production immediate-ALU opcodes pass the AUX selector unchanged;
the ADD-named row does not force an addition payload. -/
def aluImmediateHandled (code : Nat) : Bool :=
  ([.aluImm, .addImm].map GeneratedX86DispatchFamily.code).contains code

theorem alu_immediate_family (op : GeneratedX86DispatchFamily.DispatchOp) :
    aluImmediateHandled (GeneratedX86DispatchFamily.code op) =
      GeneratedX86DispatchFamily.aluImmHandled op := by
  cases op <;> rfl

/-- The production ALU-register family gate, using generated opcode IDs.
All three rows pass the AUX word unchanged to the shared handler. -/
def aluRegisterHandled (code : Nat) : Bool :=
  ([.aluReg, .addReg, .xorReg].map GeneratedX86DispatchFamily.code).contains code

theorem alu_register_family (op : GeneratedX86DispatchFamily.DispatchOp) :
    aluRegisterHandled (GeneratedX86DispatchFamily.code op) =
      GeneratedX86DispatchFamily.aluRegHandled op := by
  cases op <;> rfl

/-- The actual low-byte AUX selector for the three scalar logical ALU kinds.
TEST belongs to the separate flag-only opcode and cannot use this writer. -/
def logicKindOf (payload : BitVec 32) : Option Reference.X86.LogicKind :=
  if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .and) then some .and
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .or) then some .or
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .xor) then some .xor
  else none

theorem logic_kind_binding_decodes (payload : BitVec 32) (kind : Reference.X86.LogicKind)
    (writing : kind ≠ .test)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Logic.alu kind))) :
    logicKindOf payload = some kind := by
  subst payload
  cases kind <;> simp [logicKindOf, GeneratedX86AluDecode.code, X86Logic.alu] at *

/-- Implementation arithmetic payloads. CMP has its separate flag-only
opcode; its SUB mapping is used only to state field identities uniformly. -/
def arithmeticAlu : Reference.X86.ArithmeticKind → GeneratedX86AluDecode.Alu
  | .add => .add | .adc => .adc | .sub => .sub | .sbb => .sbb | .compare => .sub

/-- Production carry-sensitive routing is tested before generic ADD/SUB.
Logical payloads remain separate and cannot select either carry handler. -/
def arithmeticKindOf (payload : BitVec 32) : Option Reference.X86.ArithmeticKind :=
  match GeneratedX86AluDecode.handlerForCode payload with
  | .sbb => some .sbb
  | .adc => some .adc
  | .generic =>
      if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .add) then some .add
      else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .sub) then some .sub
      else none

theorem arithmetic_kind_binding_decodes (payload : BitVec 32) (kind : Reference.X86.ArithmeticKind)
    (writing : kind ≠ .compare)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (arithmeticAlu kind))) :
    arithmeticKindOf payload = some kind := by
  subst payload
  cases kind <;> simp [arithmeticKindOf, arithmeticAlu, GeneratedX86AluDecode.code,
    GeneratedX86AluDecode.handlerForCode] at *

/-- Arithmetic fields cannot take either a logical branch or the raw XOR
zero-operand gate. No operand equality or carry value is a premise. -/
theorem arithmetic_payload_separate (payload : BitVec 32) (kind : Reference.X86.ArithmeticKind)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (arithmeticAlu kind))) :
    logicKindOf payload = none ∧ payload ≠ BitVec.ofNat 32 (GeneratedX86AluDecode.code .xor) := by
  subst payload
  cases kind <;> simp [logicKindOf, arithmeticAlu, GeneratedX86AluDecode.code]

/-- Unary payloads of the same actual ALU families. Their generated
result formulas ignore the right-hand operand, even for a register-family row. -/
def unaryKindOf (payload : BitVec 32) : Option Reference.X86.UnaryKind :=
  if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .inc) then some .inc
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .dec) then some .dec
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .neg) then some .neg
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .not) then some .not
  else none

theorem unary_kind_binding_decodes (payload : BitVec 32) (kind : Reference.X86.UnaryKind)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Unary.alu kind))) :
    unaryKindOf payload = some kind := by
  subst payload
  cases kind <;> rfl

theorem unary_payload_separate (payload : BitVec 32) (kind : Reference.X86.UnaryKind)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Unary.alu kind))) :
    logicKindOf payload = none ∧ arithmeticKindOf payload = none ∧
      payload ≠ BitVec.ofNat 32 (GeneratedX86AluDecode.code .xor) := by
  subst payload
  cases kind <;> simp [logicKindOf, arithmeticKindOf, X86Unary.alu,
    GeneratedX86AluDecode.code, GeneratedX86AluDecode.handlerForCode]

/-- This is the actual generated result contract, not an assumed operand
value: all four unary formulas discard arbitrary RHS bits. -/
theorem unary_result_ignores_rhs (kind : Reference.X86.UnaryKind) (left right : Reference.Word)
    (width : GeneratedX86Width.Width) :
    GeneratedX86AluResult.result (X86Unary.alu kind) left right width =
      GeneratedX86AluResult.result (X86Unary.alu kind) left 0 width := by
  cases kind <;> rfl

/-- The IMUL token cannot take any previously lifted ALU payload branch
or the zero-operand XOR gate; its carry route is the generic handler. -/
theorem multiply_payload_separate (payload : BitVec 32)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul)) :
    logicKindOf payload = none ∧ arithmeticKindOf payload = none ∧ unaryKindOf payload = none ∧
      GeneratedX86AluDecode.handlerForCode payload = .generic ∧
      payload ≠ BitVec.ofNat 32 (GeneratedX86AluDecode.code .xor) := by
  subst payload
  decide

def shiftAlu : Reference.X86.LegacyShift → GeneratedX86AluDecode.Alu
  | .left => .shl | .right => .shr | .arithmetic => .sar | .rotateLeft => .rol

def shiftKindOf (payload : BitVec 32) : Option Reference.X86.LegacyShift :=
  if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .shl) then some .left
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .shr) then some .right
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .sar) then some .arithmetic
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .rol) then some .rotateLeft
  else none

theorem shift_kind_binding_decodes (payload : BitVec 32) (kind : Reference.X86.LegacyShift)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (shiftAlu kind))) :
    shiftKindOf payload = some kind := by
  subst payload
  cases kind <;> rfl

theorem shift_payload_separate (payload : BitVec 32) (kind : Reference.X86.LegacyShift)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (shiftAlu kind))) :
    logicKindOf payload = none ∧ arithmeticKindOf payload = none ∧ unaryKindOf payload = none ∧
      payload ≠ BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul) ∧
      payload ≠ BitVec.ofNat 32 (GeneratedX86AluDecode.code .xor) ∧
      GeneratedX86AluDecode.handlerForCode payload = .generic := by
  subst payload
  cases kind <;> decide

/-- The actual generic ALU result arms invoke these same shift helpers. -/
theorem shift_alu_value (width : ScalarWidth) (kind : Reference.X86.LegacyShift)
    (source count : Reference.Word) :
    GeneratedX86AluResult.result (shiftAlu kind) source count (X86Scalar.handlerWidth width) =
      X86LegacyShift.value width kind source count := by
  cases kind <;> rfl

/-- SHIFTX's IMM is a32-bit ALU token, separate from the count GPR in AUX.
Its three legal BMI shifts preserve flags; RORX has its own opcode. -/
def bmiShiftKindOf (payload : BitVec 32) : Option Reference.X86.BmiShift :=
  if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .shl) then some .left
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .shr) then some .right
  else if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .sar) then some .arithmetic
  else none

def bmiShiftAlu : Reference.X86.BmiShift → GeneratedX86AluDecode.Alu
  | .left => .shl | .right => .shr | .arithmetic => .sar | .rotate => .rol

theorem bmi_shift_kind_decodes (kind : Reference.X86.BmiShift) (payload : BitVec 32)
    (ordinary : kind ≠ .rotate)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (bmiShiftAlu kind))) :
    bmiShiftKindOf payload = some kind := by
  subst payload
  cases kind <;> first | rfl | contradiction

/-- The actual x86_alu_result shift arms are the same generated primitives
as the BMI value model. The rotate arm is excluded from SHIFTX. -/
theorem bmi_shift_alu_value (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
    (source count : Reference.Word) (ordinary : kind ≠ .rotate) :
    GeneratedX86AluResult.result (bmiShiftAlu kind) source count (X86Bzhi.handlerWidth width) =
      X86BmiShift.value width kind source count := by
  cases kind <;> first | rfl | contradiction

/-- Every declared ALU token selects a proved payload family. This does not
claim arbitrary raw payload bytes or malformed native operand fields. -/
theorem alu_payload_cases (alu : GeneratedX86AluDecode.Alu) :
    let payload := BitVec.ofNat 32 (GeneratedX86AluDecode.code alu)
    logicKindOf payload ≠ none ∨ arithmeticKindOf payload ≠ none ∨ unaryKindOf payload ≠ none ∨
      payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul) ∨ shiftKindOf payload ≠ none := by
  cases alu <;> decide

/-- C's current same-register/same-lane XOR zero-operand selection, tested
on raw fields before either read. Partial writes still use the original cell. -/
def logicRegisterBody (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (kind : Reference.X86.LogicKind)
    (dstCode srcCode : Byte) (aux : BitVec 32) (destination source : RegisterSlice)
    (nextPc : Reference.Word) : RegisterState :=
  if GeneratedX86RegLaneAux.payload aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code .xor) ∧
      dstCode = srcCode ∧ GeneratedX86RegLaneAux.dstShift aux = GeneratedX86RegLaneAux.srcShift aux
  then selfXorRegister env frame arena state width destination nextPc
  else logicRegister env frame arena state width kind destination source nextPc

/-- Field identities derive both the selected native XOR kind and identical
native slices. No same-value or chosen branch-result premise is assumed. -/
theorem logic_register_body_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (kind : Reference.X86.LogicKind)
    (dstCode srcCode : Byte) (aux : BitVec 32) (destination source : RegisterSlice) (nextPc : Reference.Word)
    (kindField : GeneratedX86RegLaneAux.payload aux =
      BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Logic.alu kind)))
    (dstField : SliceBinding width dstCode (GeneratedX86RegLaneAux.dstShift aux) destination)
    (srcField : SliceBinding width srcCode (GeneratedX86RegLaneAux.srcShift aux) source) :
    (⟨nativeRegisters env frame arena
        (logicRegisterBody env frame arena state width kind dstCode srcCode aux destination source nextPc), [], none⟩ :
      Transition Reference.X86.State) =
      Reference.X86.step (.logic width kind (.register destination) (.register source) nextPc)
        (nativeRegisters env frame arena state) := by
  unfold logicRegisterBody
  split
  next selected =>
    have kindIsXor : kind = .xor := by
      cases kind <;> simp_all [X86Logic.alu, GeneratedX86AluDecode.code]
    have dstDecoded := slice_binding_decodes width dstCode _ destination dstField
    have srcDecoded := slice_binding_decodes width srcCode _ source srcField
    have sameSlices : destination = source := by
      have sameDecode : sliceOf width dstCode (GeneratedX86RegLaneAux.dstShift aux) =
          sliceOf width srcCode (GeneratedX86RegLaneAux.srcShift aux) := by
        rw [selected.2.1, selected.2.2]
      rw [dstDecoded, srcDecoded] at sameDecode
      exact Option.some.inj sameDecode
    subst kind
    subst source
    exact self_xor_register_frame_refines env frame arena state width destination nextPc
  next ordinary =>
    exact logic_register_frame_refines env frame arena state width kind destination source nextPc

/-- Shared semantic body of the production ALU-immediate macro. The direct
renderer and ordered interpreter pass the same AUX/width/lane/immediate fields. -/
def aluImmediateRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (flags : Byte) (aux : BitVec 32) (dst : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) := do
  let width ← widthOf flags
  let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
  match logicKindOf (GeneratedX86RegLaneAux.payload aux) with
  | some kind => pure ⟨nativeRegisters env frame arena
      (logicImmediate env frame arena state width kind destination value nextPc), [], none⟩
  | none =>
      match arithmeticKindOf (GeneratedX86RegLaneAux.payload aux) with
      | some kind => pure ⟨nativeRegisters env frame arena
          (arithmeticImmediate env frame arena state width kind destination value nextPc), [], none⟩
      | none =>
          match unaryKindOf (GeneratedX86RegLaneAux.payload aux) with
          | some kind => pure ⟨nativeRegisters env frame arena
              (unaryRegister env frame arena state width kind destination nextPc), [], none⟩
          | none =>
              if GeneratedX86RegLaneAux.payload aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul) then do
                let wide ← cmovWidthOf flags
                pure ⟨nativeRegisters env frame arena
                  (multiplyAluImmediate env frame arena state wide destination.reg value nextPc), [], none⟩
              else do
                let kind ← shiftKindOf (GeneratedX86RegLaneAux.payload aux)
                pure ⟨nativeRegisters env frame arena
                  (shiftRegister env frame arena state width kind destination
                    (GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)) nextPc), [], none⟩

/-- Shared semantic body of the ALU-register macro, including the actual
same-lane XOR fast path and pre-write source/count sampling. -/
def aluRegisterRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) := do
  let width ← widthOf flags
  let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
  match logicKindOf (GeneratedX86RegLaneAux.payload aux) with
  | some kind => do
      let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
      pure ⟨nativeRegisters env frame arena
        (logicRegisterBody env frame arena state width kind dst src aux destination source nextPc), [], none⟩
  | none =>
      match arithmeticKindOf (GeneratedX86RegLaneAux.payload aux) with
      | some kind => do
          let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
          pure ⟨nativeRegisters env frame arena
            (arithmeticRegister env frame arena state width kind destination source nextPc), [], none⟩
      | none =>
          match unaryKindOf (GeneratedX86RegLaneAux.payload aux) with
          | some kind => pure ⟨nativeRegisters env frame arena
              (unaryRegister env frame arena state width kind destination nextPc), [], none⟩
          | none =>
              if GeneratedX86RegLaneAux.payload aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul) then do
                let wide ← cmovWidthOf flags
                let source ← registerOf src
                pure ⟨nativeRegisters env frame arena
                  (multiplyRegister env frame arena state wide destination.reg source nextPc), [], none⟩
              else do
                let kind ← shiftKindOf (GeneratedX86RegLaneAux.payload aux)
                let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
                pure ⟨nativeRegisters env frame arena
                  (shiftRegister env frame arena state width kind destination
                    (readRegister env frame arena state width source) nextPc), [], none⟩

/-- The C macro narrows AUX to its low byte, then resolves its absent zero
code against the effective FLAGS width. Upper AUX bytes remain arbitrary. -/
def movxSourceWidthCode (flags : Byte) (aux : BitVec 32) : Byte :=
  BitVec.ofNat 8 (GeneratedX86MovxShape.srcWidth (aux.setWidth 8).toNat
    (GeneratedX86Width.effective flags.toNat))

def movxSourceRegister (source : Byte) : Byte :=
  BitVec.ofNat 8 (GeneratedX86MovxShape.sourceRegister source.toNat)

def movxSourceShift (source : Byte) : BitVec 32 :=
  BitVec.ofNat 32 (GeneratedX86MovxShape.sourceShift source.toNat)

/-- Native source-width fields determine the exact generated width code,
including the absent-width fallback. Higher AUX bytes stay arbitrary. -/
theorem movx_source_width_binding (flags : Byte) (aux : BitVec 32)
    (sourceWidth targetWidth : ScalarWidth)
    (targetField : WidthBinding flags targetWidth)
    (sourceField : (aux.setWidth 8).toNat = sourceWidth.bytes ∨
      ((aux.setWidth 8).toNat = 0 ∧ sourceWidth = targetWidth)) :
    WidthBinding (movxSourceWidthCode flags aux) sourceWidth := by
  rcases sourceField with explicit | ⟨absent, rfl⟩
  · cases sourceWidth <;> simp [WidthBinding, movxSourceWidthCode,
      GeneratedX86MovxShape.srcWidth, GeneratedX86MovxShape.srcWidthAbsentCode,
      explicit, Reference.X86.ScalarWidth.bytes]
  · rcases targetField with explicit | ⟨absentFlags, rfl⟩
    · cases sourceWidth <;> simp [WidthBinding, movxSourceWidthCode,
        GeneratedX86MovxShape.srcWidth, GeneratedX86MovxShape.srcWidthAbsentCode,
        GeneratedX86Width.effective, GeneratedX86Width.absentCode,
        GeneratedX86Width.defaultCode, absent, explicit, Reference.X86.ScalarWidth.bytes]
    · simp [WidthBinding, movxSourceWidthCode, GeneratedX86MovxShape.srcWidth,
        GeneratedX86MovxShape.srcWidthAbsentCode, GeneratedX86Width.effective,
        GeneratedX86Width.absentCode, GeneratedX86Width.defaultCode, absent,
        absentFlags, Reference.X86.ScalarWidth.bytes]

/-- The encoder's legacy low-register and128..131 high-byte source codes
establish the raw source selector for each legal architectural lane. -/
theorem movx_encoded_source_binding (width : ScalarWidth) (source : RegisterSlice)
    (legal : match source with | .low _ => True | .high _ => width = .w8) :
    SliceBinding width
      (movxSourceRegister (BitVec.ofNat 8 (X86Movx.sourceCode source)))
      (movxSourceShift (BitVec.ofNat 8 (X86Movx.sourceCode source))) source := by
  have fits := X86Movx.source_code_fits_byte source
  simp only [SliceBinding, movxSourceRegister, movxSourceShift,
    BitVec.toNat_ofNat, Nat.mod_eq_of_lt fits, X86Movx.source_register_refines]
  refine ⟨rfl, ?_⟩
  cases source with
  | low reg =>
      have lower : ¬128 ≤ reg.val := by have := reg.isLt; omega
      cases width <;> simp [X86Movx.sourceCode, GeneratedX86MovxShape.sourceShift,
        GeneratedX86MovxShape.sourceHigh, GeneratedX86MovxShape.sourceHighBase,
        GeneratedX86MovxShape.sourceHighCount, lower]
  | high reg =>
      change width = .w8 at legal
      subst width
      have bound : 128 ≤ 128 + reg.val ∧ 128 + reg.val < 132 := by have := reg.isLt; omega
      simp [X86Movx.sourceCode, GeneratedX86MovxShape.sourceShift,
        GeneratedX86MovxShape.sourceHigh, GeneratedX86MovxShape.sourceHighBase,
        GeneratedX86MovxShape.sourceHighCount, GeneratedX86MovxShape.sourceHighShift, bound]

/-- Shared MOVX register macro, with the actual source-width and high-byte
selectors followed by the RSP/STACK-aware numeric writeback. -/
def movxRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (signed : Bool) (flags : Byte) (aux : BitVec 32)
    (dst src : Byte) (nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) := do
  let targetWidth ← widthOf flags
  let sourceWidth ← widthOf (movxSourceWidthCode flags aux)
  let destination ← registerOf dst
  let source ← sliceOf sourceWidth (movxSourceRegister src) (movxSourceShift src)
  pure ⟨nativeRegisters env frame arena
    (extendRegister env frame arena state sourceWidth targetWidth signed destination source nextPc), [], none⟩

/-- Encoded absent operands use byte255; present operands select their
actual GPR cell. This interface retains the complete native source state. -/
def optionalRegisterByte (reg : Option Register) : Byte :=
  (reg.map registerByte).getD 255

def optionalRegisterOf (code : Byte) : Option (Option Register) :=
  if code = 255 then some none else (registerOf code).map some

theorem optional_register_of_byte (reg : Option Register) :
    optionalRegisterOf (optionalRegisterByte reg) = some reg := by
  cases reg with
  | none => rfl
  | some reg =>
      have distinct : registerByte reg ≠ (255 : Byte) := by
        intro equal
        have eq := congrArg BitVec.toNat equal
        have bound := reg.isLt
        change reg.val % 256 = 255 at eq
        omega
      change optionalRegisterOf (registerByte reg) = some (some reg)
      unfold optionalRegisterOf
      rw [if_neg distinct, register_of_byte]
      rfl

/-- Native effective-address operands, sampled before destination writeback.
The generated offset contract uses full64-bit displacement bits and the
actual AUX scale byte. Legal native scale encodings are0..3. -/
def leaAddress (state : Reference.X86.State) (base index : Option Register)
    (aux : BitVec 32) (displacement : Reference.Word) : Reference.Word :=
  (base.map state.gpr).getD 0 + GeneratedX86MemOffset.value index.isSome
    ((GeneratedX86MemAux.scaleLog2 aux).setWidth 64) displacement
    ((index.map state.gpr).getD 0)

/-- Shared LEA macro body, including its leading readonly-literal arm.
All address reads precede the existing RSP/STACK-aware writer. The wrapping
bitvector offset is the contract of the published unsigned-helper correction. -/
def leaRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) := do
  let width ← cmovWidthOf flags
  let destination ← registerOf dst
  if width = .w64 ∧ src = 255 ∧ aux = 1 then
    pure ⟨nativeRegisters env frame arena (registerPc
      (writeRegister env frame arena state .w64 (.low destination) value) nextPc), [], none⟩
  else
    let source ← optionalRegisterOf src
    let index ← optionalRegisterOf ((GeneratedX86MemAux.index aux).setWidth 8)
    let offset := GeneratedX86MemOffset.value index.isSome
      ((GeneratedX86MemAux.scaleLog2 aux).setWidth 64) value
      (leaBaseValue env frame arena state index)
    pure ⟨nativeRegisters env frame arena
      (leaRegister env frame arena state width destination source offset nextPc), [], none⟩

/-- DIV's raw SRC selector samples a full GPR or the already captured IMM
operand before RAX/RDX writeback. DST and AUX retain their unused values. -/
def divideRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (flags : Byte) (src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match widthOf flags with
  | none => none
  | some width =>
      if src = 255 then some (divideWord env frame arena state width value nextPc)
      else (registerOf src).map (fun source =>
        divideWord env frame arena state width (registerValue env frame arena state source) nextPc)

/-- Partial ordered register dispatcher. MOVX follows the existing NOP/MOV
prefix and precedes the ALU, compare and singleton register gates. Distinct
opcode identities preserve selection across the covered handler families.
Option-valued decoding records the scope of the legal-field interface. -/
def dispatchRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchThroughMove env frame arena code flags aux dst src value nextPc state with
  | some result => some result
  | none =>
      if code = GeneratedX86Opcode.code .movzxReg then
        movxRegisters env frame arena false flags aux dst src nextPc state
      else if code = GeneratedX86Opcode.code .movsxReg then
        movxRegisters env frame arena true flags aux dst src nextPc state
      else if code = GeneratedX86Opcode.code .lea then
        leaRegisters env frame arena flags aux dst src value nextPc state
      else if aluImmediateHandled code then
        aluImmediateRegisters env frame arena flags aux dst value nextPc state
      else if code = GeneratedX86DispatchFamily.code .cmpImm then do
        let width ← widthOf flags
        let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
        pure ⟨nativeRegisters env frame arena
          (compareImmediate env frame arena state width destination value nextPc), [], none⟩
      else if code = GeneratedX86DispatchFamily.code .testImm then do
        let width ← widthOf flags
        let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
        pure ⟨nativeRegisters env frame arena
          (logicImmediate env frame arena state width .test destination value nextPc), [], none⟩
      else if aluRegisterHandled code then
        aluRegisterRegisters env frame arena flags aux dst src nextPc state
      else if code = GeneratedX86DispatchFamily.code .cmpReg then do
        let width ← widthOf flags
        let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
        let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
        pure ⟨nativeRegisters env frame arena
          (compareRegister env frame arena state width destination source nextPc), [], none⟩
      else if code = GeneratedX86DispatchFamily.code .testReg then do
        let width ← widthOf flags
        let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
        let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
        pure ⟨nativeRegisters env frame arena
          (logicRegister env frame arena state width .test destination source nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .shiftx then do
        let width ← bswapWidthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        let count ← registerOf (aux.setWidth 8)
        let kind ← bmiShiftKindOf (value.setWidth 32)
        pure ⟨nativeRegisters env frame arena
          (bmiShiftRegister env frame arena state width kind destination source count nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .rorx then do
        let width ← bswapWidthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (bmiRegister env frame arena state width .rotate destination source value nextPc), [], none⟩
      else if code = GeneratedX86Opcode.code .ror then do
        let width ← widthOf flags
        let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
        pure ⟨nativeRegisters env frame arena
          (rotateRightRegister env frame arena state width destination value nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .andn then do
        let width ← bswapWidthOf flags
        let destination ← registerOf dst
        let first ← registerOf src
        let second ← registerOf (aux.setWidth 8)
        pure ⟨nativeRegisters env frame arena
          (andnRegister env frame arena state width destination first second nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .bzhi then do
        let width ← bswapWidthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        let count ← registerOf (aux.setWidth 8)
        pure ⟨nativeRegisters env frame arena
          (bzhiRegister env frame arena state width destination source count nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .bt then do
        let width ← cmovWidthOf flags
        let base ← registerOf dst
        let index ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (bitTestRegister env frame arena state width base (registerValue env frame arena state index) nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .btImm then do
        let width ← cmovWidthOf flags
        let base ← registerOf dst
        pure ⟨nativeRegisters env frame arena
          (bitTestRegister env frame arena state width base value nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .imulImm then do
        let width ← cmovWidthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (multiplyImmediate env frame arena state width destination source value nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .cmov then do
        let width ← cmovWidthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (conditionalMoveWord env frame arena state width aux destination source nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .setcc then do
        let destination ← sliceOf .w8 dst (GeneratedX86RegLaneAux.dstShift aux)
        pure ⟨nativeRegisters env frame arena
          (setConditionRegister env frame arena state (GeneratedX86RegLaneAux.payload aux) destination nextPc), [], none⟩
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
      else if code = GeneratedX86Opcode.code .shldImm || code = GeneratedX86Opcode.code .shrdImm then do
        let width ← cmovWidthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (doubleShiftRegister env frame arena state width (code == GeneratedX86Opcode.code .shldImm)
            destination source value nextPc), [], none⟩
      else if code = GeneratedX86Opcode.code .mulx then do
        let width ← bswapWidthOf flags
        let low ← registerOf dst
        let source ← registerOf src
        let high ← registerOf (aux.setWidth 8)
        pure ⟨nativeRegisters env frame arena
          (mulxRegister env frame arena state width high low source nextPc), [], none⟩
      else if code = GeneratedX86DispatchSingleton.code .xchg then do
        let width ← widthOf flags
        let destination ← registerOf dst
        let source ← registerOf src
        pure ⟨nativeRegisters env frame arena
          (exchangeRegisters env frame arena state width destination source nextPc), [], none⟩
      else if code = GeneratedX86Opcode.code .div then
        divideRegisters env frame arena flags src value nextPc state
      else none

/-- Field/operand identities only. CMOV consumes the entire condition AUX;
XCHG ignores AUX and immediate, matching the production low-slice encoder.
Immediate forms consume only the destination lane and low-imm32/width
operand binding; SRC, source-shift and unused AUX bytes are unconstrained.
The input-state parameter resolves CL from the same incoming native view;
all older constructors remain available for every input state. No output or
native-state equality is assumed. The native instruction is the single
canonical ISA's existing constructor. -/
inductive RegisterBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word)
    (nativeState : Reference.X86.State) :
    Nat → Reference.X86.Instruction → Prop where
  | move (code : Nat) (native : Reference.X86.Instruction)
      (fields : MoveBinding flags aux dst src value nextPc code native) :
      RegisterBinding flags aux dst src value nextPc nativeState code native
  | divide (width : ScalarWidth) (source : Register)
      (widthField : WidthBinding flags width) (sourceField : src = registerByte source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .div)
        (.divide width (.register (.low source)) nextPc)
  | divideCaptured (width : ScalarWidth) (source : RegisterSlice)
      (widthField : WidthBinding flags width) (sourceField : src = 255)
      (legal : match source with | .low _ => True | .high _ => width = .w8)
      (operandField : value = Reference.X86.scalarRegisterValue nativeState width source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .div)
        (.divide width (.register source) nextPc)
  | lea (width : Reference.X86.CmovWidth) (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index)
      (scaleField : index.isSome = true → (GeneratedX86MemAux.scaleLog2 aux).toNat < 4)
      (ordinary : width = .w64 → src = 255 → aux ≠ 1) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .lea)
        (.lea width destination (leaAddress nativeState base index aux value) nextPc)
  | leaAddress32 (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags .w32)
      (dstField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index)
      (scaleField : index.isSome = true → (GeneratedX86MemAux.scaleLog2 aux).toNat < 4) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .lea)
        (.lea .w64 destination (((leaAddress nativeState base index aux value).setWidth 32).setWidth 64) nextPc)
  | leaLiteral (destination : Register)
      (widthField : WidthBinding flags .w64) (dstField : dst = registerByte destination)
      (baseField : src = 255) (literalField : aux = 1) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .lea)
        (.lea .w64 destination value nextPc)
  | doubleShift (width : Reference.X86.CmovWidth) (left : Bool)
      (destination source : Register) (encoded : Byte)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source)
      (countField : value.setWidth 8 = encoded) :
      RegisterBinding flags aux dst src value nextPc nativeState
        (GeneratedX86Opcode.code (if left then .shldImm else .shrdImm))
        (.doubleShift width left destination source (encoded.setWidth 64) nextPc)
  | mulx (width : Reference.X86.BzhiWidth) (high low source : Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (lowField : dst = registerByte low) (srcField : src = registerByte source)
      (highField : aux = BitVec.ofNat 32 high.val) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .mulx)
        (.mulx width high low (.register source) nextPc)
  | extend (signed : Bool) (sourceWidth targetWidth : ScalarWidth)
      (destination : Register) (source : RegisterSlice)
      (targetWidthField : WidthBinding flags targetWidth)
      (sourceWidthField : WidthBinding (movxSourceWidthCode flags aux) sourceWidth)
      (dstField : dst = registerByte destination)
      (srcField : SliceBinding sourceWidth (movxSourceRegister src) (movxSourceShift src) source) :
      RegisterBinding flags aux dst src value nextPc nativeState
        (GeneratedX86Opcode.code (if signed then .movsxReg else .movzxReg))
        (.extend sourceWidth targetWidth signed destination (.register source) nextPc)
  | andn (width : Reference.X86.BzhiWidth) (destination first second : Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte first)
      (secondField : aux = BitVec.ofNat 32 second.val) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .andn)
        (.andn width destination first (.register second) nextPc)
  | bzhi (width : Reference.X86.BzhiWidth) (destination source count : Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source)
      (countField : aux = BitVec.ofNat 32 count.val) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .bzhi)
        (.bzhi width destination (.register source) count nextPc)
  | bitTest (width : Reference.X86.CmovWidth) (base index : Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte base) (srcField : src = registerByte index) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .bt)
        (.bt width (.register base) (.register index) nextPc)
  | bitTestImmediate (width : Reference.X86.CmovWidth) (base : Register) (encoded : Byte)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte base) (indexField : value = encoded.setWidth 64) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .btImm)
        (.bt width (.register base) (.immediate encoded) nextPc)
  | bmiShift (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
      (destination source count : Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source)
      (countField : aux = BitVec.ofNat 32 count.val)
      (ordinary : kind ≠ .rotate)
      (operationField : value.setWidth 32 = BitVec.ofNat 32 (GeneratedX86AluDecode.code (bmiShiftAlu kind))) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .shiftx)
        (.bmiShift width kind destination (.register source) (.register count) nextPc)
  | rorx (width : Reference.X86.BzhiWidth) (destination source : Register) (encoded : Byte)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source)
      (countField : value = encoded.setWidth 64) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .rorx)
        (.bmiShift width .rotate destination (.register source) (.immediate encoded) nextPc)
  | rotateImmediate (width : ScalarWidth) (destination : RegisterSlice) (encoded : Byte)
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (countField : value = encoded.setWidth 64) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .ror)
        (.rotateRight width (.register destination) (encoded.setWidth 64) nextPc)
  | rotateCl (width : ScalarWidth) (destination : RegisterSlice)
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (countField : value = Reference.X86.scalarRegisterValue nativeState .w8 (.low 1)) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .ror)
        (.rotateRight width (.register destination)
          (Reference.X86.scalarRegisterValue nativeState .w8 (.low 1)) nextPc)
  | shiftImmediate (op : GeneratedX86DispatchFamily.DispatchOp) (width : ScalarWidth)
      (kind : Reference.X86.LegacyShift) (destination : RegisterSlice)
      (familyField : GeneratedX86DispatchFamily.aluImmHandled op = true)
      (operationField : GeneratedX86RegLaneAux.payload aux =
        BitVec.ofNat 32 (GeneratedX86AluDecode.code (shiftAlu kind)))
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.legacyShift width kind (.register destination) ((value.setWidth 8).setWidth 64) nextPc)
  | shiftRegister (op : GeneratedX86DispatchFamily.DispatchOp) (width : ScalarWidth)
      (kind : Reference.X86.LegacyShift) (destination : RegisterSlice)
      (familyField : GeneratedX86DispatchFamily.aluRegHandled op = true)
      (operationField : GeneratedX86RegLaneAux.payload aux =
        BitVec.ofNat 32 (GeneratedX86AluDecode.code (shiftAlu kind)))
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (srcField : SliceBinding width src (GeneratedX86RegLaneAux.srcShift aux) (.low 1)) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.legacyShift width kind (.register destination)
          (Reference.X86.scalarRegisterValue nativeState .w8 (.low 1)) nextPc)
  | multiplyRegister (op : GeneratedX86DispatchFamily.DispatchOp) (width : Reference.X86.CmovWidth)
      (destination source : Register)
      (familyField : GeneratedX86DispatchFamily.aluRegHandled op = true)
      (operationField : GeneratedX86RegLaneAux.payload aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul))
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.multiply width destination (.register source) none nextPc)
  | multiplyAluImmediate (op : GeneratedX86DispatchFamily.DispatchOp) (width : Reference.X86.CmovWidth)
      (destination : Register)
      (familyField : GeneratedX86DispatchFamily.aluImmHandled op = true)
      (operationField : GeneratedX86RegLaneAux.payload aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul))
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.multiply width destination (.register destination) (some (value.setWidth 32)) nextPc)
  | multiplyImmediate (width : Reference.X86.CmovWidth) (destination source : Register) (encoded : BitVec 32)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source)
      (immediateField : MultiplyImmediateBinding width value encoded) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .imulImm)
        (.multiply width destination (.register source) (some encoded) nextPc)
  | unaryImmediate (op : GeneratedX86DispatchFamily.DispatchOp) (width : ScalarWidth)
      (kind : Reference.X86.UnaryKind) (destination : RegisterSlice)
      (familyField : GeneratedX86DispatchFamily.aluImmHandled op = true)
      (operationField : GeneratedX86RegLaneAux.payload aux =
        BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Unary.alu kind)))
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.unary width kind (.register destination) nextPc)
  | unaryRegister (op : GeneratedX86DispatchFamily.DispatchOp) (width : ScalarWidth)
      (kind : Reference.X86.UnaryKind) (destination : RegisterSlice)
      (familyField : GeneratedX86DispatchFamily.aluRegHandled op = true)
      (operationField : GeneratedX86RegLaneAux.payload aux =
        BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Unary.alu kind)))
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.unary width kind (.register destination) nextPc)
  | arithmeticImmediate (op : GeneratedX86DispatchFamily.DispatchOp) (width : ScalarWidth)
      (kind : Reference.X86.ArithmeticKind) (destination : RegisterSlice) (nativeValue : Reference.Word)
      (familyField : GeneratedX86DispatchFamily.aluImmHandled op = true)
      (writing : kind ≠ .compare)
      (operationField : GeneratedX86RegLaneAux.payload aux =
        BitVec.ofNat 32 (GeneratedX86AluDecode.code (arithmeticAlu kind)))
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (immediateField : ImmediateBinding width value nativeValue) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.arithmetic width kind (.register destination) (.immediate nativeValue) nextPc)
  | arithmeticRegister (op : GeneratedX86DispatchFamily.DispatchOp) (width : ScalarWidth)
      (kind : Reference.X86.ArithmeticKind) (destination source : RegisterSlice)
      (familyField : GeneratedX86DispatchFamily.aluRegHandled op = true)
      (writing : kind ≠ .compare)
      (operationField : GeneratedX86RegLaneAux.payload aux =
        BitVec.ofNat 32 (GeneratedX86AluDecode.code (arithmeticAlu kind)))
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (srcField : SliceBinding width src (GeneratedX86RegLaneAux.srcShift aux) source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.arithmetic width kind (.register destination) (.register source) nextPc)
  | logicImmediate (op : GeneratedX86DispatchFamily.DispatchOp) (width : ScalarWidth)
      (kind : Reference.X86.LogicKind) (destination : RegisterSlice) (nativeValue : Reference.Word)
      (familyField : GeneratedX86DispatchFamily.aluImmHandled op = true)
      (writing : kind ≠ .test)
      (operationField : GeneratedX86RegLaneAux.payload aux =
        BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Logic.alu kind)))
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (immediateField : ImmediateBinding width value nativeValue) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.logic width kind (.register destination) (.immediate nativeValue) nextPc)
  | compareImmediate (width : ScalarWidth) (destination : RegisterSlice) (nativeValue : Reference.Word)
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (immediateField : ImmediateBinding width value nativeValue) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code .cmpImm)
        (.arithmetic width .compare (.register destination) (.immediate nativeValue) nextPc)
  | testImmediate (width : ScalarWidth) (destination : RegisterSlice) (nativeValue : Reference.Word)
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (immediateField : ImmediateBinding width value nativeValue) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code .testImm)
        (.logic width .test (.register destination) (.immediate nativeValue) nextPc)
  | logicRegister (op : GeneratedX86DispatchFamily.DispatchOp) (width : ScalarWidth)
      (kind : Reference.X86.LogicKind) (destination source : RegisterSlice)
      (familyField : GeneratedX86DispatchFamily.aluRegHandled op = true)
      (writing : kind ≠ .test)
      (operationField : GeneratedX86RegLaneAux.payload aux =
        BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Logic.alu kind)))
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (srcField : SliceBinding width src (GeneratedX86RegLaneAux.srcShift aux) source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code op)
        (.logic width kind (.register destination) (.register source) nextPc)
  | compareRegister (width : ScalarWidth) (destination source : RegisterSlice)
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (srcField : SliceBinding width src (GeneratedX86RegLaneAux.srcShift aux) source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code .cmpReg)
        (.arithmetic width .compare (.register destination) (.register source) nextPc)
  | testRegister (width : ScalarWidth) (destination source : RegisterSlice)
      (widthField : WidthBinding flags width)
      (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (srcField : SliceBinding width src (GeneratedX86RegLaneAux.srcShift aux) source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchFamily.code .testReg)
        (.logic width .test (.register destination) (.register source) nextPc)
  | cmov (width : Reference.X86.CmovWidth) (cc : Fin 16) (destination source : Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source)
      (conditionField : aux = BitVec.ofNat 32 cc.val) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .cmov)
        (.cmov width cc destination (.register source) nextPc)
  | setCondition (cc : Fin 16) (destination : RegisterSlice)
      (dstField : SliceBinding .w8 dst (GeneratedX86RegLaneAux.dstShift aux) destination)
      (conditionField : GeneratedX86RegLaneAux.payload aux = BitVec.ofNat 32 cc.val) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .setcc)
        (.setcc cc (.register destination) nextPc)
  | byteSwap (width : Reference.X86.BzhiWidth) (destination : Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (dstField : dst = registerByte destination) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .bswap)
        (.byteSwap width destination nextPc)
  | populationCount (width : Reference.X86.CmovWidth) (destination source : Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (dstField : dst = registerByte destination) (srcField : src = registerByte source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .popcnt)
        (.popcount width destination (.register source) nextPc)
  | exchange (width : ScalarWidth) (destination source : Register)
      (widthField : WidthBinding flags width)
      (dstField : dst = registerByte destination) (srcField : src = registerByte source) :
      RegisterBinding flags aux dst src value nextPc nativeState (GeneratedX86DispatchSingleton.code .xchg)
        (.exchange width (.low destination) (.low source) nextPc)

/-- The corrected producer's RCX unit-index form uses RCX as its base.
The binding derives the original canonical effective address from that same
incoming RCX, including every wrapping displacement and destination alias. -/
theorem lea_unit_rcx_binding (state : Reference.X86.State) (flags : Byte)
    (destination : Register) (displacement nextPc : Reference.Word)
    (widthField : WidthBinding flags .w64) :
    RegisterBinding flags 255 (registerByte destination) (registerByte 1)
      displacement nextPc state (GeneratedX86Opcode.code .lea)
      (.lea .w64 destination (X86Lea.address 0 displacement true 0 (state.gpr 1)) nextPc) := by
  have binding : RegisterBinding flags 255 (registerByte destination) (registerByte 1)
      displacement nextPc state (GeneratedX86Opcode.code .lea)
      (.lea .w64 destination (leaAddress state (some 1) none 255 displacement) nextPc) :=
    .lea .w64 destination (some 1) none widthField rfl rfl rfl (by simp) (by decide)
  have address : leaAddress state (some 1) none 255 displacement =
      X86Lea.address 0 displacement true 0 (state.gpr 1) := by
    change state.gpr 1 + displacement = 0 + (displacement + (state.gpr 1 <<< (0 : Nat)))
    simp only [Reference.Word]
    bv_decide
  simpa only [address] using binding

/-- The high-byte DIV producer argument is the exact incoming native byte;
its SRC_NONE encoding therefore establishes the generic captured-lane binding. -/
theorem divide_high_byte_binding (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (flags : Byte) (aux : BitVec 32) (dst : Byte)
    (source : Fin 4) (nextPc : Reference.Word) (widthField : WidthBinding flags .w8) :
    RegisterBinding flags aux dst 255 (readRegister env frame arena state .w8 (.high source)) nextPc
      (nativeRegisters env frame arena state) (GeneratedX86Opcode.code .div)
      (.divide .w8 (.register (.high source)) nextPc) :=
  .divideCaptured .w8 (.high source) widthField rfl rfl
    (native_register_read env frame arena state .w8 (.high source))

/-- SHLD/SHRD CL reads the byte from the same incoming raw RCX frame.
Count capture precedes every destination assignment, including destination RCX. -/
theorem double_shift_cl_binding (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (nextPc : Reference.Word) (width : Reference.X86.CmovWidth) (left : Bool)
    (destination source : Register)
    (widthField : WidthBinding flags (cmovScalarWidth width))
    (dstField : dst = registerByte destination) (srcField : src = registerByte source) :
    RegisterBinding flags aux dst src (readRegister env frame arena state .w8 (.low 1)) nextPc
      (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code (if left then .shldImm else .shrdImm))
      (.doubleShift width left destination source
        (Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w8 (.low 1)) nextPc) := by
  have cl : (((readRegister env frame arena state .w8 (.low 1)).setWidth 8).setWidth 64) =
      Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w8 (.low 1) := by
    rw [native_register_read]
    simp only [Reference.X86.scalarRegisterValue, Reference.X86.RegisterSlice.shift,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, Nat.reduceMul, Reference.Word]
    bv_decide
  have bound : RegisterBinding flags aux dst src (readRegister env frame arena state .w8 (.low 1)) nextPc
      (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code (if left then .shldImm else .shrdImm))
      (.doubleShift width left destination source
        (((readRegister env frame arena state .w8 (.low 1)).setWidth 8).setWidth 64) nextPc) :=
    .doubleShift width left destination source
      ((readRegister env frame arena state .w8 (.low 1)).setWidth 8) widthField dstField srcField rfl
  simpa only [cl] using bound

/-- The dynamic IMM argument emitted for classic ROR CL is derived from
its real raw pre-state read. It is not a chosen count or result premise. -/
theorem rotate_cl_binding (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (nextPc : Reference.Word) (width : ScalarWidth) (destination : RegisterSlice)
    (widthField : WidthBinding flags width)
    (dstField : SliceBinding width dst (GeneratedX86RegLaneAux.dstShift aux) destination) :
    RegisterBinding flags aux dst src (readRegister env frame arena state .w8 (.low 1)) nextPc
      (nativeRegisters env frame arena state) (GeneratedX86Opcode.code .ror)
      (.rotateRight width (.register destination)
        (Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w8 (.low 1)) nextPc) :=
  .rotateCl width destination widthField dstField (rotate_right_cl_operand env frame arena state)

/-- Exact equality with the executable representative is sufficient for the
canonical relation. The raw dispatcher also admits actual defined-output
refinement when an implementation writes architecturally undefined flags. -/
private theorem exact_dispatch_refines {native : Reference.X86.Instruction} {before : Reference.X86.State}
    {dispatched : Option (Transition Reference.X86.State)}
    (same : dispatched = some (Reference.X86.step native before)) :
    ∃ actual, dispatched = some actual ∧ Reference.X86.Step native before actual :=
  ⟨Reference.X86.step native before, same, rfl, rfl, rfl⟩

set_option maxHeartbeats 800000 in
/-- One complete raw-frame step for the currently lifted register opcodes:
NOP/MOV/CMOV+SETCC(all16)/BSWAP/POPCNT/XCHG/ROR(imm8+CL)/SHIFTX/RORX/ANDN/BZHI/BT plus logical/arithmetic/unary/multiply/shift ALU-register
and immediate family payloads and CMP/TEST register/immediate forms. Neither component handler
semantics nor a chosen condition/value/state equation is assumed. This is a
partial dispatcher theorem, not all77 operations or a compiled-body claim.
It returns the actual transition and canonical Step relation, retaining real
ANDN parity writes without constraining architecturally undefined PF/AF. -/
theorem register_dispatch_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : RegisterBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchRegisters env frame arena code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | move code native fields =>
      apply exact_dispatch_refines
      simp only [dispatchRegisters, step_through_move_refines env frame arena code flags aux dst src value nextPc state native fields]
  | divide width source widthField sourceField =>
      apply exact_dispatch_refines
      subst src
      have decoded := width_binding_decodes flags width widthField
      have present : registerByte source ≠ (255 : Byte) := by
        intro equal
        have encoded := congrArg BitVec.toNat equal
        change source.val % 256 = 255 at encoded
        have bound := source.isLt
        omega
      change divideRegisters env frame arena flags (registerByte source) value nextPc state =
        some (Reference.X86.step (.divide width (.register (.low source)) nextPc)
          (nativeRegisters env frame arena state))
      simp only [divideRegisters, decoded]
      rw [if_neg present]
      simpa [register_of_byte] using
        congrArg some (divide_register_frame_refines env frame arena state width source nextPc)
  | divideCaptured width source widthField sourceField legal operandField =>
      apply exact_dispatch_refines
      have decoded := width_binding_decodes flags width widthField
      have captured : value = readRegister env frame arena state width source := by
        rw [native_register_read]; exact operandField
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        divideRegisters, decoded, sourceField, captured] using
        congrArg some (divide_captured_frame_refines env frame arena state width source nextPc)
  | lea width destination base index widthField dstField baseField indexField scaleField ordinary =>
      apply exact_dispatch_refines
      have widthDecoded := cmov_width_binding_decodes flags width widthField
      have normal : ¬(width = .w64 ∧ src = 255 ∧ aux = 1) := by
        intro h; exact ordinary h.1 h.2.1 h.2.2
      have body : leaRegisters env frame arena flags aux dst src value nextPc state =
          some (Reference.X86.step
            (.lea width destination (leaAddress (nativeRegisters env frame arena state) base index aux value) nextPc)
            (nativeRegisters env frame arena state)) := by
        simp only [leaRegisters, widthDecoded, dstField, register_of_byte, Option.bind_some]
        change (if width = .w64 ∧ src = 255 ∧ aux = 1 then _ else _) = _
        rw [if_neg normal]
        simpa [baseField, indexField, optional_register_of_byte, leaAddress, leaBaseValue, nativeRegisters] using
          congrArg some (lea_register_frame_refines env frame arena state width destination base
            (GeneratedX86MemOffset.value index.isSome
              ((GeneratedX86MemAux.scaleLog2 aux).setWidth 64) value
              (leaBaseValue env frame arena state index)) nextPc)
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove,
        GeneratedX86Opcode.code, GeneratedX86DispatchSingleton.code] using body
  | leaAddress32 destination base index widthField dstField baseField indexField scaleField =>
      apply exact_dispatch_refines
      have widthDecoded := cmov_width_binding_decodes flags .w32 widthField
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove, leaRegisters,
        GeneratedX86Opcode.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, dstField, register_of_byte, baseField, indexField,
        optional_register_of_byte, leaAddress, leaBaseValue, nativeRegisters] using
        congrArg some (lea_address32_frame_refines env frame arena state destination base
          (GeneratedX86MemOffset.value index.isSome
            ((GeneratedX86MemAux.scaleLog2 aux).setWidth 64) value
            (leaBaseValue env frame arena state index)) nextPc)
  | leaLiteral destination widthField dstField baseField literalField =>
      apply exact_dispatch_refines
      have widthDecoded := cmov_width_binding_decodes flags .w64 widthField
      have body : leaRegisters env frame arena flags aux dst src value nextPc state =
          some (Reference.X86.step (.lea .w64 destination value nextPc)
            (nativeRegisters env frame arena state)) := by
        simp only [leaRegisters, widthDecoded, dstField, register_of_byte, Option.bind_some,
          baseField, literalField, and_self, ↓reduceIte]
        change some (⟨nativeRegisters env frame arena (registerPc
          (writeRegister env frame arena state .w64 (.low destination) value) nextPc), [], none⟩ :
          Transition Reference.X86.State) = _
        rw [native_register_pc, native_register_write]
        simp only [register_write64, Reference.X86.RegisterSlice.reg, Reference.X86.step,
          Reference.X86.writeValue]
        rfl
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove,
        GeneratedX86Opcode.code, GeneratedX86DispatchSingleton.code] using body
  | doubleShift width left destination source encoded widthField dstField srcField countField =>
      apply exact_dispatch_refines
      subst dst; subst src
      have widthDecoded := cmov_width_binding_decodes flags width widthField
      cases left <;>
        simpa [dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
          GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
          widthDecoded, register_of_byte, countField] using
          congrArg some (double_shift_register_frame_refines env frame arena state width _ destination source value nextPc)
  | mulx width high low source widthField lowField srcField highField =>
      apply exact_dispatch_refines
      subst dst; subst src; subst aux
      have widthDecoded := bswap_width_binding_decodes flags width widthField
      have highDecoded : registerOf (BitVec.ofNat 8 high.val) = some high := register_of_byte high
      simpa [dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, register_of_byte, highDecoded] using
        congrArg some (mulx_register_frame_refines env frame arena state width high low source nextPc)
  | extend signed sourceWidth targetWidth destination source targetWidthField sourceWidthField dstField srcField =>
      apply exact_dispatch_refines
      subst dst
      have targetDecoded := width_binding_decodes flags targetWidth targetWidthField
      have sourceDecoded := width_binding_decodes (movxSourceWidthCode flags aux) sourceWidth sourceWidthField
      have laneDecoded := slice_binding_decodes sourceWidth (movxSourceRegister src) (movxSourceShift src) source srcField
      cases signed <;>
        simpa [dispatchRegisters, dispatchThroughMove, beforeMove, movxRegisters,
          GeneratedX86Opcode.code, GeneratedX86DispatchSingleton.code,
          targetDecoded, sourceDecoded, laneDecoded, register_of_byte] using
          congrArg some (extend_register_frame_refines env frame arena state sourceWidth targetWidth _ destination source nextPc)
  | andn width destination first second widthField dstField srcField secondField =>
      subst dst; subst src; subst aux
      have widthDecoded := bswap_width_binding_decodes flags width widthField
      have secondDecoded : registerOf (BitVec.ofNat 8 second.val) = some second := register_of_byte second
      refine ⟨⟨nativeRegisters env frame arena
        (andnRegister env frame arena state width destination first second nextPc), [], none⟩, ?_, ?_⟩
      · simp [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
          GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
          widthDecoded, register_of_byte, secondDecoded]
      · exact andn_register_frame_refines env frame arena state width destination first second nextPc
  | bzhi width destination source count widthField dstField srcField countField =>
      apply exact_dispatch_refines
      subst dst; subst src; subst aux
      have widthDecoded := bswap_width_binding_decodes flags width widthField
      have countDecoded : registerOf (BitVec.ofNat 8 count.val) = some count := register_of_byte count
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, register_of_byte, countDecoded] using
        congrArg some (bzhi_register_frame_refines env frame arena state width destination source count nextPc)
  | bitTest width base index widthField dstField srcField =>
      apply exact_dispatch_refines
      subst dst; subst src
      have widthDecoded := cmov_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, register_of_byte] using
        congrArg some (bit_test_register_frame_refines env frame arena state width base index nextPc)
  | bitTestImmediate width base encoded widthField dstField indexField =>
      apply exact_dispatch_refines
      subst dst
      have widthDecoded := cmov_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, register_of_byte, indexField] using
        congrArg some (bit_test_immediate_frame_refines env frame arena state width base encoded nextPc)
  | bmiShift width kind destination source count widthField dstField srcField countField ordinary operationField =>
      apply exact_dispatch_refines
      subst dst; subst src; subst aux
      have widthDecoded := bswap_width_binding_decodes flags width widthField
      have kindDecoded := bmi_shift_kind_decodes kind _ ordinary operationField
      have countDecoded : registerOf (BitVec.ofNat 8 count.val) = some count :=
        register_of_byte count
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, register_of_byte, countDecoded, kindDecoded] using
        congrArg some (bmi_shift_register_frame_refines env frame arena state width kind destination source count nextPc)
  | rorx width destination source encoded widthField dstField srcField countField =>
      apply exact_dispatch_refines
      subst dst; subst src
      have widthDecoded := bswap_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, register_of_byte, countField, Reference.X86.countValue] using
        congrArg some (bmi_register_frame_refines env frame arena state width .rotate destination source (.immediate encoded) nextPc)
  | rotateImmediate width destination encoded widthField dstField countField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, dstDecoded, countField] using
        congrArg some (rotate_right_register_frame_refines env frame arena state width destination
          (encoded.setWidth 64) (encoded.setWidth 64) nextPc rfl)
  | rotateCl width destination widthField dstField countField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, dstDecoded, countField] using
        congrArg some (rotate_right_register_frame_refines env frame arena state width destination
          (Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w8 (.low 1))
          (Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w8 (.low 1)) nextPc rfl)
  | shiftImmediate op width kind destination familyField operationField widthField dstField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have kindDecoded := shift_kind_binding_decodes _ kind operationField
      have separate := shift_payload_separate _ kind operationField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      cases op <;> simp [GeneratedX86DispatchFamily.aluImmHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, kindDecoded, separate.1, separate.2.1, separate.2.2.1, separate.2.2.2.1, dstDecoded] using
        congrArg some (shift_register_frame_refines env frame arena state width kind destination
          (GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)) ((value.setWidth 8).setWidth 64)
          nextPc (shift_immediate_count width value))
  | shiftRegister op width kind destination familyField operationField widthField dstField srcField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have kindDecoded := shift_kind_binding_decodes _ kind operationField
      have separate := shift_payload_separate _ kind operationField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      have srcDecoded := slice_binding_decodes width src _ (.low 1) srcField
      cases op <;> simp [GeneratedX86DispatchFamily.aluRegHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, kindDecoded, separate.1, separate.2.1, separate.2.2.1, separate.2.2.2.1, dstDecoded, srcDecoded] using
        congrArg some (shift_register_frame_refines env frame arena state width kind destination
          (readRegister env frame arena state width (.low 1))
          (Reference.X86.scalarRegisterValue (nativeRegisters env frame arena state) .w8 (.low 1))
          nextPc (shift_register_count env frame arena state width 1))
  | multiplyRegister op width destination source familyField operationField widthField dstField srcField =>
      apply exact_dispatch_refines
      subst dst; subst src
      have widthDecoded := width_binding_decodes flags (cmovScalarWidth width) widthField
      have wideDecoded := cmov_width_binding_decodes flags width widthField
      have separate := multiply_payload_separate (BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul)) rfl
      have dstDecoded : sliceOf (cmovScalarWidth width) (registerByte destination)
          (GeneratedX86RegLaneAux.dstShift aux) = some (.low destination) := by
        cases width <;> simp [sliceOf, cmovScalarWidth, register_of_byte]
      cases op <;> simp [GeneratedX86DispatchFamily.aluRegHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, wideDecoded, separate.1, separate.2.1, separate.2.2.1, operationField, dstDecoded,
        register_of_byte, Reference.X86.RegisterSlice.reg] using
        congrArg some (multiply_register_frame_refines env frame arena state width destination source nextPc)
  | multiplyAluImmediate op width destination familyField operationField widthField dstField =>
      apply exact_dispatch_refines
      subst dst
      have widthDecoded := width_binding_decodes flags (cmovScalarWidth width) widthField
      have wideDecoded := cmov_width_binding_decodes flags width widthField
      have separate := multiply_payload_separate (BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul)) rfl
      have dstDecoded : sliceOf (cmovScalarWidth width) (registerByte destination)
          (GeneratedX86RegLaneAux.dstShift aux) = some (.low destination) := by
        cases width <;> simp [sliceOf, cmovScalarWidth, register_of_byte]
      cases op <;> simp [GeneratedX86DispatchFamily.aluImmHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, wideDecoded, separate.1, separate.2.1, separate.2.2.1, operationField, dstDecoded,
        Reference.X86.RegisterSlice.reg] using
        congrArg some (multiply_alu_immediate_frame_refines env frame arena state width destination value nextPc)
  | multiplyImmediate width destination source encoded widthField dstField srcField immediateField =>
      apply exact_dispatch_refines
      subst dst; subst src
      have decoded := cmov_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        decoded, register_of_byte] using
        congrArg some (multiply_immediate_frame_refines env frame arena state width destination source value encoded nextPc immediateField)
  | unaryImmediate op width kind destination familyField operationField widthField dstField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have kindDecoded := unary_kind_binding_decodes _ kind operationField
      have separate := unary_payload_separate _ kind operationField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      cases op <;> simp [GeneratedX86DispatchFamily.aluImmHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, kindDecoded, separate.1, separate.2.1, dstDecoded] using
        congrArg some (unary_register_frame_refines env frame arena state width kind destination nextPc)
  | unaryRegister op width kind destination familyField operationField widthField dstField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have kindDecoded := unary_kind_binding_decodes _ kind operationField
      have separate := unary_payload_separate _ kind operationField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      cases op <;> simp [GeneratedX86DispatchFamily.aluRegHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, kindDecoded, separate.1, separate.2.1, dstDecoded] using
        congrArg some (unary_register_frame_refines env frame arena state width kind destination nextPc)
  | arithmeticImmediate op width kind destination nativeValue familyField writing operationField widthField dstField immediateField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have kindDecoded := arithmetic_kind_binding_decodes _ kind writing operationField
      have separate := arithmetic_payload_separate _ kind operationField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      cases op <;> simp [GeneratedX86DispatchFamily.aluImmHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, kindDecoded, separate.1, dstDecoded] using
        congrArg some (arithmetic_immediate_frame_refines env frame arena state width kind destination value nativeValue nextPc writing immediateField)
  | arithmeticRegister op width kind destination source familyField writing operationField widthField dstField srcField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have kindDecoded := arithmetic_kind_binding_decodes _ kind writing operationField
      have separate := arithmetic_payload_separate _ kind operationField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      have srcDecoded := slice_binding_decodes width src _ source srcField
      cases op <;> simp [GeneratedX86DispatchFamily.aluRegHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, kindDecoded, separate.1, dstDecoded, srcDecoded] using
        congrArg some (arithmetic_register_frame_refines env frame arena state width kind destination source nextPc writing)
  | logicImmediate op width kind destination nativeValue familyField writing operationField widthField dstField immediateField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have kindDecoded := logic_kind_binding_decodes _ kind writing operationField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      cases op <;> simp [GeneratedX86DispatchFamily.aluImmHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, kindDecoded, dstDecoded] using
        congrArg some (logic_immediate_frame_refines env frame arena state width kind destination value nativeValue nextPc immediateField)
  | compareImmediate width destination nativeValue widthField dstField immediateField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, dstDecoded] using
        congrArg some (compare_immediate_frame_refines env frame arena state width destination value nativeValue nextPc immediateField)
  | testImmediate width destination nativeValue widthField dstField immediateField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, dstDecoded] using
        congrArg some (logic_immediate_frame_refines env frame arena state width .test destination value nativeValue nextPc immediateField)
  | logicRegister op width kind destination source familyField writing operationField widthField dstField srcField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have kindDecoded := logic_kind_binding_decodes _ kind writing operationField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      have srcDecoded := slice_binding_decodes width src _ source srcField
      cases op <;> simp [GeneratedX86DispatchFamily.aluRegHandled] at familyField
      all_goals simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, kindDecoded, dstDecoded, srcDecoded] using
        congrArg some (logic_register_body_refines env frame arena state width kind dst src aux destination source nextPc operationField dstField srcField)
  | compareRegister width destination source widthField dstField srcField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      have srcDecoded := slice_binding_decodes width src _ source srcField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, dstDecoded, srcDecoded] using
        congrArg some (compare_register_frame_refines env frame arena state width destination source nextPc)
  | testRegister width destination source widthField dstField srcField =>
      apply exact_dispatch_refines
      have widthDecoded := width_binding_decodes flags width widthField
      have dstDecoded := slice_binding_decodes width dst _ destination dstField
      have srcDecoded := slice_binding_decodes width src _ source srcField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        widthDecoded, dstDecoded, srcDecoded] using
        congrArg some (logic_register_frame_refines env frame arena state width .test destination source nextPc)
  | cmov width cc destination source widthField dstField srcField conditionField =>
      apply exact_dispatch_refines
      subst dst; subst src; subst aux
      have decoded := cmov_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled, GeneratedX86DispatchFamily.code, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, decoded, register_of_byte] using
        congrArg some (conditional_move_word_frame_refines env frame arena state width cc destination source nextPc)
  | setCondition cc destination dstField conditionField =>
      apply exact_dispatch_refines
      have dstDecoded := slice_binding_decodes .w8 dst _ destination dstField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code,
        dstDecoded, conditionField] using
        congrArg some (set_condition_register_frame_refines env frame arena state cc destination nextPc)
  | byteSwap width destination widthField dstField =>
      apply exact_dispatch_refines
      subst dst
      have decoded := bswap_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled, GeneratedX86DispatchFamily.code, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, decoded, register_of_byte] using
        congrArg some (byte_swap_register_frame_refines env frame arena state width destination nextPc)
  | populationCount width destination source widthField dstField srcField =>
      apply exact_dispatch_refines
      subst dst; subst src
      have decoded := cmov_width_binding_decodes flags width widthField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled, GeneratedX86DispatchFamily.code, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, decoded, register_of_byte] using
        congrArg some (population_count_register_frame_refines env frame arena state width destination source nextPc)
  | exchange width destination source widthField dstField srcField =>
      apply exact_dispatch_refines
      subst dst; subst src
      have decoded := width_binding_decodes flags width widthField
      simpa [dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled, GeneratedX86DispatchFamily.code, GeneratedX86Opcode.code,
        GeneratedX86DispatchSingleton.code, decoded, register_of_byte] using
        congrArg some (exchange_register_frame_refines env frame arena state width destination source nextPc)

/-- Two allowed successors of the same reference instruction agree on its
observable outputs. Undefined output bits are masked by the canonical ISA,
not assigned a fabricated value by this bridge. -/
private theorem successors_match (native : Reference.X86.Instruction) (before : Reference.X86.State)
    (left right : Transition Reference.X86.State)
    (first : Reference.X86.Step native before left) (second : Reference.X86.Step native before right) :
    Reference.X86.matchesTransition native left right := by
  unfold Reference.X86.Step at first second
  unfold Reference.X86.matchesTransition at first second ⊢
  obtain ⟨firstEvents, firstFault, firstState⟩ := first
  obtain ⟨secondEvents, secondFault, secondState⟩ := second
  refine ⟨firstEvents.symm.trans secondEvents, firstFault.symm.trans secondFault, ?_⟩
  rw [← firstFault]
  exact firstState.symm.trans secondState

/-- Native-to-handler direction for ANY canonical successor and every covered
raw token. This is single-step observational matching, including real faults
and effects. Composing steps still needs the generic flag/register-definedness
invariant; equality of architecturally undefined bits is not claimed. -/
theorem register_dispatch_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : RegisterBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native)
    (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, dispatchRegisters env frame arena code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refines⟩ :=
    register_dispatch_step_refines env frame arena code flags aux dst src value nextPc state native binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refines⟩

/-- Direct macro tokens whose complete raw register bodies are lifted below.
The code comes from the full opcode contract; the specialization table's
independent token spellings and dispatch class are checked by the next lemma. -/
def directRegisterOpcode : GeneratedX86Specialization.Op → Option GeneratedX86Opcode.Op
  | .movImm => some .movImm | .movReg => some .movReg | .cmov => some .cmov
  | .setcc => some .setcc | .ror => some .ror | .rorx => some .rorx
  | .andn => some .andn | .bt => some .bt | .btImm => some .btImm
  | .imulImm => some .imulImm
  | .mulx => some .mulx | .lea => some .lea
  | .movzxReg => some .movzxReg | .movsxReg => some .movsxReg
  | .addImm => some .addImm | .aluImm => some .aluImm
  | .addReg => some .addReg | .xorReg => some .xorReg | .aluReg => some .aluReg
  | .cmpImm => some .cmpImm | .testImm => some .testImm
  | .cmpReg => some .cmpReg | .testReg => some .testReg | _ => none

theorem direct_register_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : directRegisterOpcode token = some opcode) :
    GeneratedX86Specialization.dispatch token = .directMacro ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

/-- Semantic C-macro bodies selected by the direct renderer, independently of
L_EXEC's ordered opcode gates. Raw fields, aliases, input flags and the full
frame remain parameters. None is an unproved/malformed modeled binding, not
an added runtime guard. This is C-model O2; compiler/actual-B preservation is
still a separate trusted or proved transformation law. -/
def specializedRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (token : GeneratedX86Specialization.Op) (flags : Byte) (aux : BitVec 32)
    (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  match token with
  | .movImm => do
      let width ← widthOf flags
      let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
      pure ⟨nativeRegisters env frame arena (registerPc
        (writeRegister env frame arena state width destination value) nextPc), [], none⟩
  | .movReg => do
      let width ← widthOf flags
      let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
      let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
      pure ⟨nativeRegisters env frame arena (moveRegister env frame arena state width destination source nextPc), [], none⟩
  | .lea => leaRegisters env frame arena flags aux dst src value nextPc state
  | .movzxReg => movxRegisters env frame arena false flags aux dst src nextPc state
  | .movsxReg => movxRegisters env frame arena true flags aux dst src nextPc state
  | .mulx => do
      let width ← bswapWidthOf flags
      let low ← registerOf dst
      let source ← registerOf src
      let high ← registerOf (aux.setWidth 8)
      pure ⟨nativeRegisters env frame arena (mulxRegister env frame arena state width high low source nextPc), [], none⟩
  | .cmov => do
      let width ← cmovWidthOf flags
      let destination ← registerOf dst
      let source ← registerOf src
      pure ⟨nativeRegisters env frame arena (conditionalMoveWord env frame arena state width aux destination source nextPc), [], none⟩
  | .setcc => do
      let destination ← sliceOf .w8 dst (GeneratedX86RegLaneAux.dstShift aux)
      pure ⟨nativeRegisters env frame arena (setConditionRegister env frame arena state
        (GeneratedX86RegLaneAux.payload aux) destination nextPc), [], none⟩
  | .ror => do
      let width ← widthOf flags
      let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
      pure ⟨nativeRegisters env frame arena (rotateRightRegister env frame arena state width destination value nextPc), [], none⟩
  | .rorx => do
      let width ← bswapWidthOf flags
      let destination ← registerOf dst
      let source ← registerOf src
      pure ⟨nativeRegisters env frame arena (bmiRegister env frame arena state width .rotate destination source value nextPc), [], none⟩
  | .andn => do
      let width ← bswapWidthOf flags
      let destination ← registerOf dst
      let first ← registerOf src
      let second ← registerOf (aux.setWidth 8)
      pure ⟨nativeRegisters env frame arena (andnRegister env frame arena state width destination first second nextPc), [], none⟩
  | .bt => do
      let width ← cmovWidthOf flags
      let base ← registerOf dst
      let index ← registerOf src
      pure ⟨nativeRegisters env frame arena (bitTestRegister env frame arena state width base
        (registerValue env frame arena state index) nextPc), [], none⟩
  | .btImm => do
      let width ← cmovWidthOf flags
      let base ← registerOf dst
      pure ⟨nativeRegisters env frame arena (bitTestRegister env frame arena state width base value nextPc), [], none⟩
  | .imulImm => do
      let width ← cmovWidthOf flags
      let destination ← registerOf dst
      let source ← registerOf src
      pure ⟨nativeRegisters env frame arena (multiplyImmediate env frame arena state width destination source value nextPc), [], none⟩
  | .addImm | .aluImm => aluImmediateRegisters env frame arena flags aux dst value nextPc state
  | .addReg | .xorReg | .aluReg => aluRegisterRegisters env frame arena flags aux dst src nextPc state
  | .cmpImm => do
      let width ← widthOf flags
      let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
      pure ⟨nativeRegisters env frame arena (compareImmediate env frame arena state width destination value nextPc), [], none⟩
  | .testImm => do
      let width ← widthOf flags
      let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
      pure ⟨nativeRegisters env frame arena (logicImmediate env frame arena state width .test destination value nextPc), [], none⟩
  | .cmpReg => do
      let width ← widthOf flags
      let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
      let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
      pure ⟨nativeRegisters env frame arena (compareRegister env frame arena state width destination source nextPc), [], none⟩
  | .testReg => do
      let width ← widthOf flags
      let destination ← sliceOf width dst (GeneratedX86RegLaneAux.dstShift aux)
      let source ← sliceOf width src (GeneratedX86RegLaneAux.srcShift aux)
      pure ⟨nativeRegisters env frame arena (logicRegister env frame arena state width .test destination source nextPc), [], none⟩
  | .div => dispatchRegisters env frame arena (GeneratedX86Opcode.code .div) flags aux dst src value nextPc state
  | .nop => dispatchRegisters env frame arena (GeneratedX86Opcode.code .nop) flags aux dst src value nextPc state
  | .bswap => dispatchRegisters env frame arena (GeneratedX86Opcode.code .bswap) flags aux dst src value nextPc state
  | .popcnt => dispatchRegisters env frame arena (GeneratedX86Opcode.code .popcnt) flags aux dst src value nextPc state
  | .xchg => dispatchRegisters env frame arena (GeneratedX86Opcode.code .xchg) flags aux dst src value nextPc state
  | .shiftx => dispatchRegisters env frame arena (GeneratedX86Opcode.code .shiftx) flags aux dst src value nextPc state
  | .bzhi => dispatchRegisters env frame arena (GeneratedX86Opcode.code .bzhi) flags aux dst src value nextPc state
  | .shldImm => dispatchRegisters env frame arena (GeneratedX86Opcode.code .shldImm) flags aux dst src value nextPc state
  | .shrdImm => dispatchRegisters env frame arena (GeneratedX86Opcode.code .shrdImm) flags aux dst src value nextPc state
  | _ => none

/-- O2 once per lifted direct token: specializing opcode dispatch retains the
entire raw body result for ALL fields, states and invocations. No ISA result,
condition, chosen state, program bytes or program certificate is a premise. -/
theorem specialized_register_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : directRegisterOpcode token = some opcode) :
    specializedRegisters env frame arena token flags aux dst src value nextPc state =
      dispatchRegisters env frame arena (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  cases token <;> simp only [directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals simp [specializedRegisters, dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters, dispatchThroughMove, beforeMove,
    aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
    GeneratedX86DispatchSingleton.code]
  all_goals symm
  all_goals split <;> symm <;> assumption

/-- The same O1 result holds for each specialized body through its O2 equality.
This supplies a program-independent per-token interface, not compiled-B or
whole-ISA coverage for tokens whose raw bodies are still being lifted. -/
theorem specialized_register_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word)
    (state : RegisterState) (native : Reference.X86.Instruction)
    (selected : directRegisterOpcode token = some opcode)
    (binding : RegisterBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedRegisters env frame arena token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [specialized_register_body_matches env frame arena token opcode flags aux dst src value nextPc state selected]
  exact register_dispatch_step_refines env frame arena _ flags aux dst src value nextPc state native binding

/-- Combine O1's native-successor observation with O2's per-token body
identity. All fields and invocations remain arbitrary. This common-input
single-step interface does not replace the generic definedness/ABI relation
needed to compose masked architectural states across instructions. -/
theorem specialized_register_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word)
    (state : RegisterState) (native : Reference.X86.Instruction)
    (selected : directRegisterOpcode token = some opcode)
    (binding : RegisterBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native)
    (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedRegisters env frame arena token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  rw [specialized_register_body_matches env frame arena token opcode flags aux dst src value nextPc state selected]
  exact register_dispatch_native_matches env frame arena _ flags aux dst src value nextPc state native binding nativeAfter nativeStep

/-- The uniform token interface includes direct bodies and unchanged generic
RUN_OP calls. The direct-only API above remains available for its direct-macro subset. -/
def registerTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  match token with
  | .div => some .div
  | .nop => some .nop | .bswap => some .bswap | .popcnt => some .popcnt
  | .xchg => some .xchg | .shiftx => some .shiftx | .bzhi => some .bzhi
  | .shldImm => some .shldImm | .shrdImm => some .shrdImm
  | _ => directRegisterOpcode token

theorem register_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : registerTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

/-- Uniform O2: every lifted token preserves the full raw step, whether the
renderer emits its shared macro directly or forwards all fields to RUN_OP. -/
theorem register_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : registerTokenOpcode token = some opcode) :
    specializedRegisters env frame arena token flags aux dst src value nextPc state =
      dispatchRegisters env frame arena (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals simp [specializedRegisters, dispatchRegisters, aluImmediateRegisters, aluRegisterRegisters,
    dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code,
    GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code]
  all_goals symm
  all_goals split <;> symm <;> assumption

theorem register_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word)
    (state : RegisterState) (native : Reference.X86.Instruction)
    (selected : registerTokenOpcode token = some opcode)
    (binding : RegisterBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedRegisters env frame arena token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [register_token_body_matches env frame arena token opcode flags aux dst src value nextPc state selected]
  exact register_dispatch_step_refines env frame arena _ flags aux dst src value nextPc state native binding

/-- Native-to-specialized observation for every covered direct or generic
token, any common architectural input and any permitted native successor.
Generic ABI/definedness and actual compiled-B preservation remain separate. -/
theorem register_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word)
    (state : RegisterState) (native : Reference.X86.Instruction)
    (selected : registerTokenOpcode token = some opcode)
    (binding : RegisterBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native)
    (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedRegisters env frame arena token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  rw [register_token_body_matches env frame arena token opcode flags aux dst src value nextPc state selected]
  exact register_dispatch_native_matches env frame arena _ flags aux dst src value nextPc state native binding nativeAfter nativeStep

/-- Raw PF-aware JCC condition and the actual forward/backward goto shape.
Logical label addresses select the architectural PC through the existing
branch-emission contract. Input registers, tags, memory and flags are retained. -/
def branchRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (aux : BitVec 32)
    (target nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match GeneratedX86FullCondition.eval aux
    (state.raw.rflags.getLsbD 0) (state.raw.rflags.getLsbD 6) (state.raw.rflags.getLsbD 7)
    (state.raw.rflags.getLsbD 11) (state.raw.rflags.getLsbD 2) with
  | none => none
  | some taken =>
      let selected := GeneratedX86BranchEmit.nextPc
        (GeneratedX86BranchEmit.shape current target.toNat) taken nextPc.toNat target.toNat
      some ⟨nativeRegisters env frame arena (registerPc state (BitVec.ofNat 64 selected)), [], none⟩

theorem branch_register_frame_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (cc : Fin 16)
    (target nextPc : Reference.Word) (state : RegisterState) :
    branchRegisters env frame arena current (BitVec.ofNat 32 cc.val) target nextPc state =
      some (Reference.X86.step (.branch (some cc) target nextPc) (nativeRegisters env frame arena state)) := by
  have condition := X86Condition.condition_refines cc state.raw.rflags
  unfold X86Condition.evaluate at condition
  simp only [branchRegisters, condition, Option.bind_some]
  rw [x86_branch_emit_refines]
  cases taken : Reference.X86.condition state.raw.rflags cc <;>
    simp [branchPc, taken, native_register_pc, Reference.X86.step, nativeRegisters, registerPc, registerValue]
  all_goals funext reg; rfl

/-- The unconditional JMP macro chooses its mapped target label directly. -/
def jumpRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (target : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  some ⟨nativeRegisters env frame arena (registerPc state target), [], none⟩

theorem jump_register_frame_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (target nextPc : Reference.Word) (state : RegisterState) :
    jumpRegisters env frame arena target state =
      some (Reference.X86.step (.branch none target nextPc) (nativeRegisters env frame arena state)) := rfl

/-- Architectural stack transfer widths retain the zero-to64 field default. -/
def stackWidthOf (flags : Byte) : Option Reference.X86.StackWidth :=
  match widthOf flags with
  | some .w16 => some .w16 | some .w64 => some .w64 | _ => none

def StackWidthBinding (flags : Byte) (width : Reference.X86.StackWidth) : Prop :=
  WidthBinding flags (match width with | .w16 => .w16 | .w64 => .w64)

theorem stack_width_binding_decodes (flags : Byte) (width : Reference.X86.StackWidth)
    (binding : StackWidthBinding flags width) : stackWidthOf flags = some width := by
  cases width <;> simp [stackWidthOf, width_binding_decodes flags _ binding]

/-- Raw memory fields select the same base/index numeric observations as LEA.
A private arena mapping supplies the corresponding guest-memory accesses. -/
def memoryAddressRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (baseField : Byte)
    (aux : BitVec 32) (displacement : Reference.Word) : Option Reference.Word := do
  let base ← optionalRegisterOf baseField
  let index ← optionalRegisterOf ((GeneratedX86MemAux.index aux).setWidth 8)
  pure (leaAddress (nativeRegisters env frame arena state) base index aux displacement)

theorem memory_address_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (baseField : Byte) (base index : Option Register)
    (aux : BitVec 32) (displacement : Reference.Word)
    (baseBinding : baseField = optionalRegisterByte base)
    (indexBinding : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
    memoryAddressRegisters env frame arena state baseField aux displacement =
      some (leaAddress (nativeRegisters env frame arena state) base index aux displacement) := by
  simp only [memoryAddressRegisters, baseBinding, indexBinding, optional_register_of_byte, Option.bind_some]
  rfl

/-- The shared PUSH_OP/POP_OP arms select register and immediate transfers
from the high AUX byte. Mode2 forms PUSH addresses before the transfer and
POP addresses after the raw stack advance. -/
def stackRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .push then do
    let width ← stackWidthOf flags
    if GeneratedX86MemAux.op aux = 1 then
      pure (pushValueFrame env frame arena state width value nextPc)
    else if GeneratedX86MemAux.op aux = 2 then do
      let address ← memoryAddressRegisters env frame arena state src aux value
      pure (pushMemoryFrame env frame arena state width address nextPc)
    else
      let source ← registerOf src
      pure (pushValueFrame env frame arena state width (registerValue env frame arena state source) nextPc)
  else if code = GeneratedX86Opcode.code .pop then do
    let width ← stackWidthOf flags
    if GeneratedX86MemAux.op aux = 2 then do
      let address ← memoryAddressRegisters env frame arena
        (advanceStack state (BitVec.ofNat 64 width.bytes)) dst aux value
      pure (popMemoryFrame env frame arena state width address nextPc)
    else
      let destination ← registerOf dst
      pure (popRegisterFrame env frame arena state width destination nextPc)
  else none

inductive StackBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) : Nat → Reference.X86.Instruction → Prop where
  | pushRegister (width : Reference.X86.StackWidth) (source : Register)
      (widthField : StackWidthBinding flags width) (sourceField : src = registerByte source)
      (modeField : GeneratedX86MemAux.op aux ≠ 1 ∧ GeneratedX86MemAux.op aux ≠ 2) :
      StackBinding flags aux dst src value nextPc (GeneratedX86Opcode.code .push) (.push width source nextPc)
  | pushImmediate (width : Reference.X86.StackWidth) (widthField : StackWidthBinding flags width)
      (modeField : GeneratedX86MemAux.op aux = 1) :
      StackBinding flags aux dst src value nextPc (GeneratedX86Opcode.code .push) (.pushImmediate width value nextPc)
  | popRegister (width : Reference.X86.StackWidth) (destination : Register)
      (widthField : StackWidthBinding flags width) (destinationField : dst = registerByte destination)
      (modeField : GeneratedX86MemAux.op aux ≠ 2) :
      StackBinding flags aux dst src value nextPc (GeneratedX86Opcode.code .pop) (.pop width destination nextPc)

theorem stack_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : StackBinding flags aux dst src value nextPc code native) :
    stackRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | pushRegister width source widthField sourceField modeField =>
      simp only [stackRegisters, if_pos rfl, stack_width_binding_decodes flags width widthField,
        Option.bind_some, modeField.1, modeField.2, ↓reduceIte, sourceField, register_of_byte]
      exact
        congrArg some (push_register_frame_refines env frame arena state width source nextPc)
  | pushImmediate width widthField modeField =>
      simpa [stackRegisters, stack_width_binding_decodes flags width widthField, modeField] using
        congrArg some (push_immediate_frame_refines env frame arena state width value nextPc)
  | popRegister width destination widthField destinationField modeField =>
      have separate : GeneratedX86Opcode.code .pop ≠ GeneratedX86Opcode.code .push := by decide
      simp only [stackRegisters, separate, ↓reduceIte, stack_width_binding_decodes flags width widthField,
        Option.bind_some, modeField, destinationField, register_of_byte]
      exact
        congrArg some (pop_register_frame_refines env frame arena state width destination nextPc)

/-- Input field bindings also derive memory POP's post-increment address.
The native instruction contains that computed address from the common input. -/
inductive StackMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) :
    Nat → Reference.X86.Instruction → Prop where
  | push (width : Reference.X86.StackWidth) (base index : Option Register)
      (widthField : StackWidthBinding flags width) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index)
      (modeField : GeneratedX86MemAux.op aux = 2) :
      StackMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .push)
        (.pushMemory width (leaAddress nativeState base index aux value) nextPc)
  | pop (width : Reference.X86.StackWidth) (base index : Option Register)
      (widthField : StackWidthBinding flags width) (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index)
      (modeField : GeneratedX86MemAux.op aux = 2) :
      StackMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .pop)
        (.popMemory width (leaAddress
          { nativeState with gpr := fun r => if r = 4 then nativeState.gpr 4 + BitVec.ofNat 64 width.bytes
            else nativeState.gpr r } base index aux value) nextPc)

theorem stack_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : StackMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    stackRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | push width base index widthField baseField indexField modeField =>
      have modeSeparate : GeneratedX86MemAux.op aux ≠ 1 := by rw [modeField]; decide
      simp only [stackRegisters, if_pos rfl, stack_width_binding_decodes flags width widthField,
        Option.bind_some, modeSeparate, modeField, ↓reduceIte,
        memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
      exact congrArg some (push_memory_frame_refines env frame arena state width _ nextPc)
  | pop width base index widthField baseField indexField modeField =>
      have separate : GeneratedX86Opcode.code .pop ≠ GeneratedX86Opcode.code .push := by decide
      simp only [stackRegisters, separate, if_pos rfl, ↓reduceIte,
        stack_width_binding_decodes flags width widthField, Option.bind_some, modeField]
      change (memoryAddressRegisters env frame arena (advanceStack state (BitVec.ofNat 64 width.bytes)) dst aux value >>=
        fun address => some (popMemoryFrame env frame arena state width address nextPc)) = _
      rw [memory_address_registers_refine env frame arena (advanceStack state (BitVec.ofNat 64 width.bytes))
        dst base index aux value baseField indexField]
      change some (popMemoryFrame env frame arena state width
        (leaAddress (nativeRegisters env frame arena (advanceStack state (BitVec.ofNat 64 width.bytes))) base index aux value) nextPc) = _
      rw [pop_memory_frame_refines, native_advance_stack]

/-- MOVBE's shared memory body resolves FLAGS, captures its address/source,
then applies generated reversal and the raw frame writer or byte store. -/
def endianRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .movbeLoad then do
    let width ← cmovWidthOf flags
    let destination ← registerOf dst
    let address ← memoryAddressRegisters env frame arena state src aux value
    pure (endianLoadFrame env frame arena state width destination address nextPc)
  else if code = GeneratedX86Opcode.code .movbeStore then do
    let width ← cmovWidthOf flags
    let source ← registerOf src
    let address ← memoryAddressRegisters env frame arena state dst aux value
    pure (endianStoreFrame env frame arena state width source address nextPc)
  else none

inductive EndianBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) :
    Nat → Reference.X86.Instruction → Prop where
  | load (width : Reference.X86.CmovWidth) (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags (cmovScalarWidth width)) (destinationField : dst = registerByte destination)
      (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      EndianBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .movbeLoad)
        (.movbeLoad width destination (leaAddress nativeState base index aux value) nextPc)
  | store (width : Reference.X86.CmovWidth) (source : Register) (base index : Option Register)
      (widthField : WidthBinding flags (cmovScalarWidth width)) (sourceField : src = registerByte source)
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      EndianBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .movbeStore)
        (.movbeStore width source (leaAddress nativeState base index aux value) nextPc)

theorem endian_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : EndianBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    endianRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | load width destination base index widthField destinationField baseField indexField =>
      simp only [endianRegisters, if_pos rfl, cmov_width_binding_decodes flags width widthField,
        destinationField, register_of_byte, Option.bind_some]
      change (memoryAddressRegisters env frame arena state src aux value >>=
        fun address => some (endianLoadFrame env frame arena state width destination address nextPc)) = _
      rw [memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
      exact congrArg some (endian_load_frame_refines env frame arena state width destination _ nextPc)
  | store width source base index widthField sourceField baseField indexField =>
      have separate : GeneratedX86Opcode.code .movbeStore ≠ GeneratedX86Opcode.code .movbeLoad := by decide
      simp only [endianRegisters, separate, if_pos rfl, ↓reduceIte,
        cmov_width_binding_decodes flags width widthField, sourceField, register_of_byte, Option.bind_some]
      change (memoryAddressRegisters env frame arena state dst aux value >>=
        fun address => some (endianStoreFrame env frame arena state width source address nextPc)) = _
      rw [memory_address_registers_refine env frame arena state dst base index aux value baseField indexField]
      exact congrArg some (endian_store_frame_refines env frame arena state width source _ nextPc)

/-- Memory conditions occupy AUX's high byte. CMOV's packed displacement
uses the signed high32 bits; SETCC consumes the complete displacement word. -/
def conditionMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .setccMem then do
    let address ← memoryAddressRegisters env frame arena state dst aux value
    pure (setConditionMemory env frame arena state (GeneratedX86MemAux.op aux) address nextPc)
  else if code = GeneratedX86Opcode.code .cmovMem then do
    let width ← cmovWidthOf flags
    if GeneratedX86MemAux.memWidth aux = 0 ∨ (GeneratedX86MemAux.memWidth aux).toNat = width.bytes then do
      let destination ← registerOf dst
      let address ← memoryAddressRegisters env frame arena state src aux
        (((value >>> 32).setWidth 32).signExtend 64)
      pure (conditionalMemoryFrame env frame arena state width (GeneratedX86MemAux.op aux) destination address nextPc)
    else none
  else none

inductive ConditionMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) :
    Nat → Reference.X86.Instruction → Prop where
  | set (cc : Fin 16) (base index : Option Register)
      (conditionField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 cc.val)
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      ConditionMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .setccMem)
        (.setcc cc (.memory (leaAddress nativeState base index aux value)) nextPc)
  | move (width : Reference.X86.CmovWidth) (cc : Fin 16) (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (memoryWidthField : GeneratedX86MemAux.memWidth aux = 0 ∨ (GeneratedX86MemAux.memWidth aux).toNat = width.bytes)
      (conditionField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 cc.val)
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      ConditionMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .cmovMem)
        (.cmov width cc destination
          (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64))) nextPc)

theorem condition_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ConditionMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    conditionMemoryRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | set cc base index conditionField baseField indexField =>
      simp only [conditionMemoryRegisters, if_pos rfl]
      rw [memory_address_registers_refine env frame arena state dst base index aux value baseField indexField]
      simp only [Option.bind_some, conditionField]
      exact congrArg some (set_condition_memory_frame_refines env frame arena state cc _ nextPc)
  | move width cc destination base index widthField memoryWidthField conditionField destinationField baseField indexField =>
      have separate : GeneratedX86Opcode.code .cmovMem ≠ GeneratedX86Opcode.code .setccMem := by decide
      simp only [conditionMemoryRegisters, separate, if_pos rfl, ↓reduceIte,
        cmov_width_binding_decodes flags width widthField, Option.bind_some]
      change (if GeneratedX86MemAux.memWidth aux = 0 ∨ (GeneratedX86MemAux.memWidth aux).toNat = width.bytes then _ else _) = _
      rw [if_pos memoryWidthField]
      simp only [destinationField, register_of_byte, Option.bind_some]
      change (memoryAddressRegisters env frame arena state src aux (((value >>> 32).setWidth 32).signExtend 64) >>=
        fun address => some (conditionalMemoryFrame env frame arena state width (GeneratedX86MemAux.op aux) destination address nextPc)) = _
      rw [memory_address_registers_refine env frame arena state src base index aux _ baseField indexField]
      simp only [Option.bind_some, conditionField]
      exact congrArg some (conditional_memory_frame_refines env frame arena state width cc destination _ nextPc)

/-- Ordinary store fields preserve the producer's two immediate slices.
Register-store lane validation describes native input fields; the C macro
itself accepts other defined shifts, retained by the existing host oracle. -/
def storeRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .movStoreImm then do
    let width ← widthOf flags
    let address ← memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64)
    pure (storeImmediateFrame env frame arena state width value address nextPc)
  else if code = GeneratedX86Opcode.code .movStoreReg then do
    let width ← widthOf flags
    let source ← sliceOf width src (GeneratedX86MemAux.op aux)
    if GeneratedX86MemAux.op aux = BitVec.ofNat 32 (source.shift width) then do
      let address ← memoryAddressRegisters env frame arena state dst aux value
      pure (storeRegisterFrame env frame arena state width source address nextPc)
    else none
  else none

inductive StoreBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) :
    Nat → Reference.X86.Instruction → Prop where
  | immediate (width : ScalarWidth) (base index : Option Register)
      (widthField : WidthBinding flags width) (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      StoreBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .movStoreImm)
        (.move width (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64)))
          (.immediate (KProgFormal.x86ImmediateValueSpec value (X86Scalar.handlerWidth width))) nextPc)
  | registers (width : ScalarWidth) (source : RegisterSlice) (base index : Option Register)
      (widthField : WidthBinding flags width)
      (sourceField : SliceBinding width src (GeneratedX86MemAux.op aux) source)
      (shiftField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 (source.shift width))
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      StoreBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .movStoreReg)
        (.move width (.memory (leaAddress nativeState base index aux value)) (.register source) nextPc)

theorem store_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : StoreBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    storeRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | immediate width base index widthField baseField indexField =>
      simp only [storeRegisters, if_pos rfl, width_binding_decodes flags width widthField, Option.bind_some]
      rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
      exact congrArg some (store_immediate_frame_refines env frame arena state width value _ nextPc)
  | registers width source base index widthField sourceField shiftField baseField indexField =>
      have separate : GeneratedX86Opcode.code .movStoreReg ≠ GeneratedX86Opcode.code .movStoreImm := by decide
      simp only [storeRegisters, separate, if_pos rfl, ↓reduceIte, width_binding_decodes flags width widthField]
      change (sliceOf width src (GeneratedX86MemAux.op aux) >>= fun lane =>
        if GeneratedX86MemAux.op aux = BitVec.ofNat 32 (lane.shift width) then
          (memoryAddressRegisters env frame arena state dst aux value >>= fun address =>
            some (storeRegisterFrame env frame arena state width lane address nextPc))
        else none) = _
      rw [slice_binding_decodes width src _ source sourceField]
      change (if GeneratedX86MemAux.op aux = BitVec.ofNat 32 (source.shift width) then _ else _) = _
      rw [if_pos shiftField]
      rw [memory_address_registers_refine env frame arena state dst base index aux value baseField indexField]
      exact congrArg some (store_register_frame_refines env frame arena state width source _ nextPc)

/-- Memory unary payloads and ROR's raw byte count share AUX's high byte;
their effective address uses the complete displacement word. -/
def modifyMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .aluMemUnary then do
    let width ← widthOf flags
    let kind ← unaryKindOf (GeneratedX86MemAux.op aux)
    let address ← memoryAddressRegisters env frame arena state dst aux value
    pure (unaryMemoryFrame env frame arena state width kind address nextPc)
  else if code = GeneratedX86Opcode.code .rorMem then do
    let width ← widthOf flags
    let address ← memoryAddressRegisters env frame arena state dst aux value
    pure (rotateMemoryFrame env frame arena state width ((GeneratedX86MemAux.op aux).setWidth 64) address nextPc)
  else none

inductive ModifyMemoryBinding (flags : Byte) (aux : BitVec 32) (dst : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) :
    Nat → Reference.X86.Instruction → Prop where
  | unary (width : ScalarWidth) (kind : Reference.X86.UnaryKind) (base index : Option Register)
      (widthField : WidthBinding flags width)
      (kindField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Unary.alu kind)))
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      ModifyMemoryBinding flags aux dst value nextPc nativeState (GeneratedX86Opcode.code .aluMemUnary)
        (.unary width kind (.memory (leaAddress nativeState base index aux value)) nextPc)
  | rotate (width : ScalarWidth) (base index : Option Register)
      (widthField : WidthBinding flags width) (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      ModifyMemoryBinding flags aux dst value nextPc nativeState (GeneratedX86Opcode.code .rorMem)
        (.rotateRight width (.memory (leaAddress nativeState base index aux value))
          ((GeneratedX86MemAux.op aux).setWidth 64) nextPc)

theorem modify_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ModifyMemoryBinding flags aux dst value nextPc (nativeRegisters env frame arena state) code native) :
    modifyMemoryRegisters env frame arena code flags aux dst value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | unary width kind base index widthField kindField baseField indexField =>
      simp only [modifyMemoryRegisters, if_pos rfl, width_binding_decodes flags width widthField,
        unary_kind_binding_decodes _ kind kindField, Option.bind_some]
      rw [memory_address_registers_refine env frame arena state dst base index aux value baseField indexField]
      exact congrArg some (unary_memory_frame_refines env frame arena state width kind _ nextPc)
  | rotate width base index widthField baseField indexField =>
      have separate : GeneratedX86Opcode.code .rorMem ≠ GeneratedX86Opcode.code .aluMemUnary := by decide
      simp only [modifyMemoryRegisters, separate, if_pos rfl, ↓reduceIte,
        width_binding_decodes flags width widthField, Option.bind_some]
      rw [memory_address_registers_refine env frame arena state dst base index aux value baseField indexField]
      exact congrArg some (rotate_memory_frame_refines env frame arena state width _ _ nextPc)

/-- Shared memory CMP/TEST selectors retain their different displacement
slices. Source cells are sampled from the same incoming numeric frame. -/
def compareMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) := do
  let width ← widthOf flags
  if code = GeneratedX86Opcode.code .cmpRegMem then do
    let left ← registerOf dst
    let address ← memoryAddressRegisters env frame arena state src aux value
    pure (flagsMemoryFrame env frame arena state width
      (fun source old => X86Arithmetic.flags width .compare (registerValue env frame arena state left) source old) address nextPc)
  else if code = GeneratedX86Opcode.code .cmpMemReg ∨ code = GeneratedX86Opcode.code .testMemReg then do
    let right ← registerOf src
    let displacement := if code = GeneratedX86Opcode.code .cmpMemReg then value
      else ((value >>> 32).setWidth 32).signExtend 64
    let address ← memoryAddressRegisters env frame arena state dst aux displacement
    pure (flagsMemoryFrame env frame arena state width
      (fun source old => if code = GeneratedX86Opcode.code .testMemReg
        then X86Logic.flags width .test source (registerValue env frame arena state right) old
        else X86Arithmetic.compareFlags width source (registerValue env frame arena state right) old) address nextPc)
  else if code = GeneratedX86Opcode.code .cmpMemImm ∨ code = GeneratedX86Opcode.code .testMemImm then do
    let address ← memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64)
    let right := GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)
    pure (flagsMemoryFrame env frame arena state width
      (fun source old => if code = GeneratedX86Opcode.code .testMemImm
        then X86Logic.flags width .test source right old else X86Arithmetic.compareFlags width source right old) address nextPc)
  else none

inductive CompareMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) :
    Nat → Reference.X86.Instruction → Prop where
  | immediate (test : Bool) (width : ScalarWidth) (base index : Option Register)
      (widthField : WidthBinding flags width) (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      CompareMemoryBinding flags aux dst src value nextPc nativeState
        (GeneratedX86Opcode.code (if test then .testMemImm else .cmpMemImm))
        (if test then .logic width .test (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64)))
          (.immediate (KProgFormal.x86ImmediateValueSpec value (X86Scalar.handlerWidth width))) nextPc
        else .arithmetic width .compare (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64)))
          (.immediate (KProgFormal.x86ImmediateValueSpec value (X86Scalar.handlerWidth width))) nextPc)
  | registers (test : Bool) (width : ScalarWidth) (right : Register) (base index : Option Register)
      (widthField : WidthBinding flags width) (rightField : src = registerByte right)
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      CompareMemoryBinding flags aux dst src value nextPc nativeState
        (GeneratedX86Opcode.code (if test then .testMemReg else .cmpMemReg))
        (if test then .logic width .test (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64)))
          (.register (.low right)) nextPc
        else .arithmetic width .compare (.memory (leaAddress nativeState base index aux value)) (.register (.low right)) nextPc)
  | reverse (width : ScalarWidth) (left : Register) (base index : Option Register)
      (widthField : WidthBinding flags width) (leftField : dst = registerByte left)
      (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      CompareMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .cmpRegMem)
        (.arithmetic width .compare (.register (.low left)) (.memory (leaAddress nativeState base index aux value)) nextPc)

theorem compare_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : CompareMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    compareMemoryRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | immediate test width base index widthField baseField indexField =>
      cases test <;> unfold compareMemoryRegisters <;> rw [width_binding_decodes flags width widthField]
      · change (memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64) >>=
          fun address => some (flagsMemoryFrame env frame arena state width
            (fun source old => X86Arithmetic.compareFlags width source (GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)) old) address nextPc)) = _
        rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
        simpa only [Option.bind_some, KProgFormal.x86_immediate_value_refines] using
          congrArg some (compare_memory_value_refines env frame arena state width _ _ nextPc)
      · change (memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64) >>=
          fun address => some (flagsMemoryFrame env frame arena state width
            (fun source old => X86Logic.flags width .test source (GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)) old) address nextPc)) = _
        rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
        simpa only [Option.bind_some, KProgFormal.x86_immediate_value_refines] using
          congrArg some (test_memory_value_refines env frame arena state width _ _ nextPc)
  | registers test width right base index widthField rightField baseField indexField =>
      cases test <;> unfold compareMemoryRegisters <;> rw [width_binding_decodes flags width widthField]
      · change (registerOf src >>= fun right =>
          memoryAddressRegisters env frame arena state dst aux value >>= fun address =>
            some (flagsMemoryFrame env frame arena state width
              (fun source old => X86Arithmetic.compareFlags width source (registerValue env frame arena state right) old) address nextPc)) = _
        rw [rightField, register_of_byte]
        change (memoryAddressRegisters env frame arena state dst aux value >>= fun address =>
          some (flagsMemoryFrame env frame arena state width
            (fun source old => X86Arithmetic.compareFlags width source (registerValue env frame arena state right) old) address nextPc)) = _
        rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
        exact congrArg some (compare_memory_register_refines env frame arena state width right _ nextPc)
      · change (registerOf src >>= fun right =>
          memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64) >>= fun address =>
            some (flagsMemoryFrame env frame arena state width
              (fun source old => X86Logic.flags width .test source (registerValue env frame arena state right) old) address nextPc)) = _
        rw [rightField, register_of_byte]
        change (memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64) >>= fun address =>
          some (flagsMemoryFrame env frame arena state width
            (fun source old => X86Logic.flags width .test source (registerValue env frame arena state right) old) address nextPc)) = _
        rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
        exact congrArg some (test_memory_register_refines env frame arena state width right _ nextPc)
  | reverse width left base index widthField leftField baseField indexField =>
      unfold compareMemoryRegisters
      rw [width_binding_decodes flags width widthField]
      change (registerOf dst >>= fun left => memoryAddressRegisters env frame arena state src aux value >>= fun address =>
        some (flagsMemoryFrame env frame arena state width
          (fun source old => X86Arithmetic.flags width .compare (registerValue env frame arena state left) source old) address nextPc)) = _
      rw [leftField, register_of_byte]
      change (memoryAddressRegisters env frame arena state src aux value >>= fun address =>
        some (flagsMemoryFrame env frame arena state width
          (fun source old => X86Arithmetic.flags width .compare (registerValue env frame arena state left) source old) address nextPc)) = _
      rw [memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
      exact congrArg some (compare_register_memory_refines env frame arena state width left _ nextPc)

/-- Unified partial simulator step: register execution and the producer's
separate JCC/JMP branch-handler class share one transition interface. Logical
label/PC and compiled-code correspondence retain their layout/ABI obligations. -/
def dispatchStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchRegisters env frame arena code flags aux dst src value nextPc state with
  | some result => some result
  | none =>
      if code = GeneratedX86Opcode.code .jcc then branchRegisters env frame arena current aux value nextPc state
      else if code = GeneratedX86Opcode.code .jmp then jumpRegisters env frame arena value state
      else if code = GeneratedX86Opcode.code .cmpMemImm ∨ code = GeneratedX86Opcode.code .testMemImm ∨
          code = GeneratedX86Opcode.code .cmpMemReg ∨ code = GeneratedX86Opcode.code .testMemReg ∨
          code = GeneratedX86Opcode.code .cmpRegMem then
        compareMemoryRegisters env frame arena code flags aux dst src value nextPc state
      else if code = GeneratedX86Opcode.code .aluMemUnary ∨ code = GeneratedX86Opcode.code .rorMem then
        modifyMemoryRegisters env frame arena code flags aux dst value nextPc state
      else if code = GeneratedX86Opcode.code .movStoreImm ∨ code = GeneratedX86Opcode.code .movStoreReg then
        storeRegisters env frame arena code flags aux dst src value nextPc state
      else if code = GeneratedX86Opcode.code .setccMem ∨ code = GeneratedX86Opcode.code .cmovMem then
        conditionMemoryRegisters env frame arena code flags aux dst src value nextPc state
      else if code = GeneratedX86Opcode.code .movbeLoad ∨ code = GeneratedX86Opcode.code .movbeStore then
        endianRegisters env frame arena code flags aux dst src value nextPc state
      else stackRegisters env frame arena code flags aux dst src value nextPc state

inductive StepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word)
    (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | registers (code : Nat) (native : Reference.X86.Instruction)
      (fields : RegisterBinding flags aux dst src value nextPc nativeState code native) :
      StepBinding flags aux dst src value nextPc nativeState code native
  | stack (code : Nat) (native : Reference.X86.Instruction)
      (fields : StackBinding flags aux dst src value nextPc code native) :
      StepBinding flags aux dst src value nextPc nativeState code native
  | stackMemory (code : Nat) (native : Reference.X86.Instruction)
      (fields : StackMemoryBinding flags aux dst src value nextPc nativeState code native) :
      StepBinding flags aux dst src value nextPc nativeState code native
  | endian (code : Nat) (native : Reference.X86.Instruction)
      (fields : EndianBinding flags aux dst src value nextPc nativeState code native) :
      StepBinding flags aux dst src value nextPc nativeState code native
  | compareMemory (code : Nat) (native : Reference.X86.Instruction)
      (fields : CompareMemoryBinding flags aux dst src value nextPc nativeState code native) :
      StepBinding flags aux dst src value nextPc nativeState code native
  | modifyMemory (code : Nat) (native : Reference.X86.Instruction)
      (fields : ModifyMemoryBinding flags aux dst value nextPc nativeState code native) :
      StepBinding flags aux dst src value nextPc nativeState code native
  | store (code : Nat) (native : Reference.X86.Instruction)
      (fields : StoreBinding flags aux dst src value nextPc nativeState code native) :
      StepBinding flags aux dst src value nextPc nativeState code native
  | conditionMemory (code : Nat) (native : Reference.X86.Instruction)
      (fields : ConditionMemoryBinding flags aux dst src value nextPc nativeState code native) :
      StepBinding flags aux dst src value nextPc nativeState code native
  | conditional (cc : Fin 16) (conditionField : aux = BitVec.ofNat 32 cc.val) :
      StepBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .jcc)
        (.branch (some cc) value nextPc)
  | jump : StepBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .jmp)
      (.branch none value nextPc)

theorem simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : StepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | registers code native fields =>
      obtain ⟨actual, dispatched, step⟩ :=
        register_dispatch_step_refines env frame arena code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchStep, dispatched], step⟩
  | stack code native fields =>
      apply exact_dispatch_refines
      have model := stack_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields <;>
        simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
          GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
  | stackMemory code native fields =>
      apply exact_dispatch_refines
      have model := stack_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields <;>
        simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
          GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
  | endian code native fields =>
      apply exact_dispatch_refines
      have model := endian_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields <;>
        simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
          GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
  | compareMemory code native fields =>
      apply exact_dispatch_refines
      have model := compare_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields with
      | immediate test width base index widthField baseField indexField =>
          cases test <;>
          simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
            GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
      | registers test width right base index widthField rightField baseField indexField =>
          cases test <;>
          simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
            GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
      | reverse width left base index widthField leftField baseField indexField =>
          simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
            GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
  | modifyMemory code native fields =>
      apply exact_dispatch_refines
      have model := modify_memory_registers_refine env frame arena code flags aux dst value nextPc state native fields
      cases fields <;>
        simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
          GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
  | store code native fields =>
      apply exact_dispatch_refines
      have model := store_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields <;>
        simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
          GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
  | conditionMemory code native fields =>
      apply exact_dispatch_refines
      have model := condition_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields <;>
        simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
          GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using model
  | conditional cc conditionField =>
      apply exact_dispatch_refines
      subst aux
      simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using
        branch_register_frame_refines env frame arena current cc value nextPc state
  | jump =>
      apply exact_dispatch_refines
      simpa [dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove, aluImmediateHandled, aluRegisterHandled,
        GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code, GeneratedX86DispatchSingleton.code] using
        jump_register_frame_refines env frame arena value nextPc state

/-- The branch renderer emits the same shared macro for every JCC/JMP token.
Other covered tokens retain their existing direct/generic body interface. -/
def specializedStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .jcc then branchRegisters env frame arena current aux value nextPc state
  else if token = .jmp then jumpRegisters env frame arena value state
  else if token = .push then stackRegisters env frame arena (GeneratedX86Opcode.code .push) flags aux dst src value nextPc state
  else if token = .pop then stackRegisters env frame arena (GeneratedX86Opcode.code .pop) flags aux dst src value nextPc state
  else if token = .movbeLoad then endianRegisters env frame arena (GeneratedX86Opcode.code .movbeLoad) flags aux dst src value nextPc state
  else if token = .movbeStore then endianRegisters env frame arena (GeneratedX86Opcode.code .movbeStore) flags aux dst src value nextPc state
  else if token = .setccMem then conditionMemoryRegisters env frame arena (GeneratedX86Opcode.code .setccMem) flags aux dst src value nextPc state
  else if token = .cmovMem then conditionMemoryRegisters env frame arena (GeneratedX86Opcode.code .cmovMem) flags aux dst src value nextPc state
  else if token = .movStoreImm then storeRegisters env frame arena (GeneratedX86Opcode.code .movStoreImm) flags aux dst src value nextPc state
  else if token = .movStoreReg then storeRegisters env frame arena (GeneratedX86Opcode.code .movStoreReg) flags aux dst src value nextPc state
  else if token = .aluMemUnary then modifyMemoryRegisters env frame arena (GeneratedX86Opcode.code .aluMemUnary) flags aux dst value nextPc state
  else if token = .rorMem then modifyMemoryRegisters env frame arena (GeneratedX86Opcode.code .rorMem) flags aux dst value nextPc state
  else if token = .cmpMemImm then compareMemoryRegisters env frame arena (GeneratedX86Opcode.code .cmpMemImm) flags aux dst src value nextPc state
  else if token = .testMemImm then compareMemoryRegisters env frame arena (GeneratedX86Opcode.code .testMemImm) flags aux dst src value nextPc state
  else if token = .cmpMemReg then compareMemoryRegisters env frame arena (GeneratedX86Opcode.code .cmpMemReg) flags aux dst src value nextPc state
  else if token = .testMemReg then compareMemoryRegisters env frame arena (GeneratedX86Opcode.code .testMemReg) flags aux dst src value nextPc state
  else if token = .cmpRegMem then compareMemoryRegisters env frame arena (GeneratedX86Opcode.code .cmpRegMem) flags aux dst src value nextPc state
  else specializedRegisters env frame arena token flags aux dst src value nextPc state

def stepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .jcc then some .jcc else if token = .jmp then some .jmp
  else if token = .push then some .push else if token = .pop then some .pop
  else if token = .movbeLoad then some .movbeLoad else if token = .movbeStore then some .movbeStore
  else if token = .setccMem then some .setccMem else if token = .cmovMem then some .cmovMem
  else if token = .movStoreImm then some .movStoreImm else if token = .movStoreReg then some .movStoreReg
  else if token = .aluMemUnary then some .aluMemUnary else if token = .rorMem then some .rorMem
  else if token = .cmpMemImm then some .cmpMemImm
  else if token = .testMemImm then some .testMemImm
  else if token = .cmpMemReg then some .cmpMemReg
  else if token = .testMemReg then some .testMemReg
  else if token = .cmpRegMem then some .cmpRegMem
  else registerTokenOpcode token

private theorem register_token_excludes_control (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : registerTokenOpcode token = some opcode) :
    token ≠ .jcc ∧ token ≠ .jmp ∧ GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .jcc ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .jmp := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem register_token_excludes_stack (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : registerTokenOpcode token = some opcode) :
    token ≠ .push ∧ token ≠ .pop ∧ GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .push ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .pop := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem register_token_excludes_endian (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : registerTokenOpcode token = some opcode) :
    token ≠ .movbeLoad ∧ token ≠ .movbeStore ∧ GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .movbeLoad ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .movbeStore := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem register_token_excludes_memory_condition (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : registerTokenOpcode token = some opcode) :
    token ≠ .setccMem ∧ token ≠ .cmovMem ∧ GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .setccMem ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .cmovMem := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem register_token_excludes_store (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : registerTokenOpcode token = some opcode) :
    token ≠ .movStoreImm ∧ token ≠ .movStoreReg ∧ GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .movStoreImm ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .movStoreReg := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem register_token_excludes_modify_memory (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : registerTokenOpcode token = some opcode) :
    token ≠ .aluMemUnary ∧ token ≠ .rorMem ∧ GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .aluMemUnary ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .rorMem := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem register_token_excludes_memory_compare (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : registerTokenOpcode token = some opcode) :
    token ≠ .cmpMemImm ∧ token ≠ .testMemImm ∧ token ≠ .cmpMemReg ∧ token ≠ .testMemReg ∧ token ≠ .cmpRegMem ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .cmpMemImm ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .testMemImm ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .cmpMemReg ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .testMemReg ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .cmpRegMem := by
  cases token <;> simp only [registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : stepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : stepTokenOpcode token = some opcode) :
    specializedStep env frame arena current token flags aux dst src value nextPc state =
      dispatchStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases conditional : token = .jcc
  · subst token
    simp only [stepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
      aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
      GeneratedX86DispatchSingleton.code]
  · by_cases jump : token = .jmp
    · subst token
      simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
      subst opcode
      simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
        aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
        GeneratedX86DispatchSingleton.code]
    · by_cases push : token = .push
      · subst token
        simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
        subst opcode
        simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
          aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
          GeneratedX86DispatchSingleton.code]
      · by_cases pop : token = .pop
        · subst token
          simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
          subst opcode
          simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
            aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
            GeneratedX86DispatchSingleton.code]
        · by_cases load : token = .movbeLoad
          · subst token
            simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
            subst opcode
            simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
              aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
              GeneratedX86DispatchSingleton.code]
          · by_cases store : token = .movbeStore
            · subst token
              simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
              subst opcode
              simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                GeneratedX86DispatchSingleton.code]
            · by_cases set : token = .setccMem
              · subst token
                simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                subst opcode
                simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                  aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                  GeneratedX86DispatchSingleton.code]
              · by_cases move : token = .cmovMem
                · subst token
                  simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                  subst opcode
                  simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                    aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                    GeneratedX86DispatchSingleton.code]
                · by_cases immediateStore : token = .movStoreImm
                  · subst token
                    simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                    subst opcode
                    simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                      aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                      GeneratedX86DispatchSingleton.code]
                  · by_cases registerStore : token = .movStoreReg
                    · subst token
                      simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                      subst opcode
                      simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                        aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                        GeneratedX86DispatchSingleton.code]
                    · by_cases memoryUnary : token = .aluMemUnary
                      · subst token
                        simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                        subst opcode
                        simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                          aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                          GeneratedX86DispatchSingleton.code]
                      · by_cases memoryRotate : token = .rorMem
                        · subst token
                          simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                          subst opcode
                          simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                            aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                            GeneratedX86DispatchSingleton.code]
                        · by_cases cmpMemoryImmediate : token = .cmpMemImm
                          · subst token
                            simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                            subst opcode
                            simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                              aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                              GeneratedX86DispatchSingleton.code]
                          · by_cases testMemoryImmediate : token = .testMemImm
                            · subst token
                              simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                              subst opcode
                              simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                                aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                                GeneratedX86DispatchSingleton.code]
                            · by_cases cmpMemoryRegister : token = .cmpMemReg
                              · subst token
                                simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                                subst opcode
                                simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                                  aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                                  GeneratedX86DispatchSingleton.code]
                              · by_cases testMemoryRegister : token = .testMemReg
                                · subst token
                                  simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                                  subst opcode
                                  simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                                    aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                                    GeneratedX86DispatchSingleton.code]
                                · by_cases cmpRegisterMemory : token = .cmpRegMem
                                  · subst token
                                    simp only [stepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
                                    subst opcode
                                    simp [specializedStep, dispatchStep, dispatchRegisters, dispatchThroughMove, beforeMove,
                                      aluImmediateHandled, aluRegisterHandled, GeneratedX86Opcode.code, GeneratedX86DispatchFamily.code,
                                      GeneratedX86DispatchSingleton.code]
                                  · have registerSelected : registerTokenOpcode token = some opcode := by
                                      simpa only [stepTokenOpcode, conditional, jump, push, pop, load, store, set, move, immediateStore, registerStore, memoryUnary, memoryRotate, cmpMemoryImmediate, testMemoryImmediate, cmpMemoryRegister, testMemoryRegister, cmpRegisterMemory, ↓reduceIte] using selected
                                    obtain ⟨_, _, notConditional, notJump⟩ := register_token_excludes_control token opcode registerSelected
                                    obtain ⟨_, _, notPush, notPop⟩ := register_token_excludes_stack token opcode registerSelected
                                    obtain ⟨_, _, notLoad, notStore⟩ := register_token_excludes_endian token opcode registerSelected
                                    obtain ⟨_, _, notSet, notMove⟩ := register_token_excludes_memory_condition token opcode registerSelected
                                    obtain ⟨_, _, notImmediateStore, notRegisterStore⟩ := register_token_excludes_store token opcode registerSelected
                                    obtain ⟨_, _, notMemoryUnary, notMemoryRotate⟩ := register_token_excludes_modify_memory token opcode registerSelected
                                    obtain ⟨_, _, _, _, _, notCmpMemImm, notTestMemImm, notCmpMemReg, notTestMemReg, notCmpRegMem⟩ :=
                                      register_token_excludes_memory_compare token opcode registerSelected
                                    simp only [specializedStep, conditional, jump, push, pop, load, store, set, move, immediateStore, registerStore, memoryUnary, memoryRotate, cmpMemoryImmediate, testMemoryImmediate, cmpMemoryRegister, testMemoryRegister, cmpRegisterMemory, ↓reduceIte]
                                    rw [register_token_body_matches env frame arena token opcode flags aux dst src value nextPc state registerSelected]
                                    unfold dispatchStep
                                    cases dispatched : dispatchRegisters env frame arena (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
                                      simp [dispatched, notConditional, notJump, notSet, notMove, notLoad, notStore, notImmediateStore, notRegisterStore, notMemoryUnary, notMemoryRotate, notCmpMemImm, notTestMemImm, notCmpMemReg, notTestMemReg, notCmpRegMem, stackRegisters, notPush, notPop]


theorem simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : stepTokenOpcode token = some opcode)
    (binding : StepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : stepTokenOpcode token = some opcode)
    (binding : StepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native)
    (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refines⟩ :=
    simulator_token_step_refines env frame arena current token opcode flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refines⟩


/-- The memory ALU consumes AUX's operation byte and captures RHS before
flags/store. Its scalar writing domain covers arithmetic, logic and shifts. -/
def aluMemoryBody (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (payload : BitVec 32)
    (right address nextPc : Reference.Word) : Option (Transition Reference.X86.State) :=
  match logicKindOf payload with
  | some kind => some (logicMemoryFrame env frame arena state width kind right address nextPc)
  | none => match arithmeticKindOf payload with
    | some kind => some (arithmeticMemoryFrame env frame arena state width kind right address nextPc)
    | none => (shiftKindOf payload).map (fun kind => shiftMemoryFrame env frame arena state width kind right address nextPc)

def aluMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .aluMemImm then do
    let width ← widthOf flags
    let address ← memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64)
    aluMemoryBody env frame arena state width (GeneratedX86MemAux.op aux)
      (GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)) address nextPc
  else if code = GeneratedX86Opcode.code .aluMemReg then do
    let width ← widthOf flags
    let right ← registerOf src
    let address ← memoryAddressRegisters env frame arena state dst aux value
    aluMemoryBody env frame arena state width (GeneratedX86MemAux.op aux)
      (registerValue env frame arena state right) address nextPc
  else none

theorem alu_memory_arithmetic_body (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (payload : BitVec 32)
    (kind : Reference.X86.ArithmeticKind) (right address nextPc : Reference.Word)
    (writing : kind ≠ .compare) (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (arithmeticAlu kind))) :
    aluMemoryBody env frame arena state width payload right address nextPc =
      some (arithmeticMemoryFrame env frame arena state width kind right address nextPc) := by
  simp only [aluMemoryBody, (arithmetic_payload_separate payload kind field).1,
    arithmetic_kind_binding_decodes payload kind writing field]

theorem alu_memory_logic_body (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (payload : BitVec 32)
    (kind : Reference.X86.LogicKind) (right address nextPc : Reference.Word)
    (writing : kind ≠ .test) (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Logic.alu kind))) :
    aluMemoryBody env frame arena state width payload right address nextPc =
      some (logicMemoryFrame env frame arena state width kind right address nextPc) := by
  rw [aluMemoryBody, logic_kind_binding_decodes payload kind writing field]

theorem alu_memory_shift_body (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (payload : BitVec 32)
    (kind : Reference.X86.LegacyShift) (right address nextPc : Reference.Word)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (shiftAlu kind))) :
    aluMemoryBody env frame arena state width payload right address nextPc =
      some (shiftMemoryFrame env frame arena state width kind right address nextPc) := by
  obtain ⟨logic, arithmetic, _⟩ := shift_payload_separate payload kind field
  simp only [aluMemoryBody, logic, arithmetic, shift_kind_binding_decodes payload kind field, Option.map_some]
  all_goals rfl

inductive AluMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) :
    Nat → Reference.X86.Instruction → Prop where
  | arithmetic (immediate : Bool) (width : ScalarWidth) (kind : Reference.X86.ArithmeticKind)
      (right : Register) (base index : Option Register) (writing : kind ≠ .compare)
      (widthField : WidthBinding flags width)
      (kindField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code (arithmeticAlu kind)))
      (rightField : immediate = false → src = registerByte right)
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      AluMemoryBinding flags aux dst src value nextPc nativeState
        (GeneratedX86Opcode.code (if immediate then .aluMemImm else .aluMemReg))
        (.arithmetic width kind
          (.memory (leaAddress nativeState base index aux
            (if immediate then ((value >>> 32).setWidth 32).signExtend 64 else value)))
          (if immediate then .immediate (KProgFormal.x86ImmediateValueSpec value (X86Scalar.handlerWidth width))
            else .register (.low right)) nextPc)
  | logic (immediate : Bool) (width : ScalarWidth) (kind : Reference.X86.LogicKind)
      (right : Register) (base index : Option Register) (writing : kind ≠ .test)
      (widthField : WidthBinding flags width)
      (kindField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Logic.alu kind)))
      (rightField : immediate = false → src = registerByte right)
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      AluMemoryBinding flags aux dst src value nextPc nativeState
        (GeneratedX86Opcode.code (if immediate then .aluMemImm else .aluMemReg))
        (.logic width kind
          (.memory (leaAddress nativeState base index aux
            (if immediate then ((value >>> 32).setWidth 32).signExtend 64 else value)))
          (if immediate then .immediate (KProgFormal.x86ImmediateValueSpec value (X86Scalar.handlerWidth width))
            else .register (.low right)) nextPc)
  | shift (immediate : Bool) (width : ScalarWidth) (kind : Reference.X86.LegacyShift)
      (base index : Option Register)
      (widthField : WidthBinding flags width)
      (kindField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code (shiftAlu kind)))
      (rightField : immediate = false → src = registerByte 1)
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      AluMemoryBinding flags aux dst src value nextPc nativeState
        (GeneratedX86Opcode.code (if immediate then .aluMemImm else .aluMemReg))
        (.legacyShift width kind
          (.memory (leaAddress nativeState base index aux
            (if immediate then ((value >>> 32).setWidth 32).signExtend 64 else value)))
          (if immediate then KProgFormal.x86ImmediateValueSpec value (X86Scalar.handlerWidth width)
            else ((nativeState.gpr 1).setWidth 8).setWidth 64) nextPc)

theorem alu_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : AluMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    aluMemoryRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | arithmetic immediate width kind right base index writing widthField kindField rightField baseField indexField =>
      cases immediate
      · change (widthOf flags >>= fun width => registerOf src >>= fun right =>
          memoryAddressRegisters env frame arena state dst aux value >>= fun address =>
            aluMemoryBody env frame arena state width (GeneratedX86MemAux.op aux)
              (registerValue env frame arena state right) address nextPc) = _
        rw [width_binding_decodes flags width widthField]
        rw [rightField rfl, register_of_byte]
        rw [memory_address_registers_refine env frame arena state dst base index aux value baseField indexField]
        simpa only [Option.bind_some, alu_memory_arithmetic_body _ _ _ _ _ _ kind _ _ _ writing kindField] using
          congrArg some (arithmetic_memory_register_refines env frame arena state width kind right _ nextPc writing)
      · change (widthOf flags >>= fun width =>
          memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64) >>= fun address =>
            aluMemoryBody env frame arena state width (GeneratedX86MemAux.op aux)
              (GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)) address nextPc) = _
        rw [width_binding_decodes flags width widthField]
        rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
        simpa only [Option.bind_some, alu_memory_arithmetic_body _ _ _ _ _ _ kind _ _ _ writing kindField,
          KProgFormal.x86_immediate_value_refines] using
          congrArg some (arithmetic_memory_value_refines env frame arena state width kind _ _ nextPc writing)
  | logic immediate width kind right base index writing widthField kindField rightField baseField indexField =>
      cases immediate
      · change (widthOf flags >>= fun width => registerOf src >>= fun right =>
          memoryAddressRegisters env frame arena state dst aux value >>= fun address =>
            aluMemoryBody env frame arena state width (GeneratedX86MemAux.op aux)
              (registerValue env frame arena state right) address nextPc) = _
        rw [width_binding_decodes flags width widthField]
        rw [rightField rfl, register_of_byte]
        rw [memory_address_registers_refine env frame arena state dst base index aux value baseField indexField]
        simpa only [Option.bind_some, alu_memory_logic_body _ _ _ _ _ _ kind _ _ _ writing kindField] using
          congrArg some (logic_memory_register_refines env frame arena state width kind right _ nextPc writing)
      · change (widthOf flags >>= fun width =>
          memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64) >>= fun address =>
            aluMemoryBody env frame arena state width (GeneratedX86MemAux.op aux)
              (GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)) address nextPc) = _
        rw [width_binding_decodes flags width widthField]
        rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
        simpa only [Option.bind_some, alu_memory_logic_body _ _ _ _ _ _ kind _ _ _ writing kindField,
          KProgFormal.x86_immediate_value_refines] using
          congrArg some (logic_memory_value_refines env frame arena state width kind _ _ nextPc writing)
  | shift immediate width kind base index widthField kindField rightField baseField indexField =>
      cases immediate
      · change (widthOf flags >>= fun width => registerOf src >>= fun right =>
          memoryAddressRegisters env frame arena state dst aux value >>= fun address =>
            aluMemoryBody env frame arena state width (GeneratedX86MemAux.op aux)
              (registerValue env frame arena state right) address nextPc) = _
        rw [width_binding_decodes flags width widthField]
        rw [rightField rfl, register_of_byte]
        rw [memory_address_registers_refine env frame arena state dst base index aux value baseField indexField]
        simpa only [Option.bind_some, alu_memory_shift_body _ _ _ _ _ _ kind _ _ _ kindField] using
          congrArg some (shift_memory_register_refines env frame arena state width kind 1 _ nextPc)
      · change (widthOf flags >>= fun width =>
          memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64) >>= fun address =>
            aluMemoryBody env frame arena state width (GeneratedX86MemAux.op aux)
              (GeneratedX86Immediate.value value (X86Scalar.handlerWidth width)) address nextPc) = _
        rw [width_binding_decodes flags width widthField]
        rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
        simpa only [Option.bind_some, alu_memory_shift_body _ _ _ _ _ _ kind _ _ _ kindField,
          KProgFormal.x86_immediate_value_refines] using
          congrArg some (shift_memory_value_refines env frame arena state width kind _ _ nextPc)


/-- Extend the existing unified model with the two memory-destination ALU
opcodes, preserving every previously composed register/control/memory arm. -/
def dispatchMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => aluMemoryRegisters env frame arena code flags aux dst src value nextPc state

theorem before_alu_memory_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (immediate : Bool) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchStep env frame arena current (GeneratedX86Opcode.code (if immediate then .aluMemImm else .aluMemReg))
      flags aux dst src value nextPc state = none := by
  cases immediate <;> rfl

theorem alu_memory_binding_before_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : AluMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    dispatchStep env frame arena current code flags aux dst src value nextPc state = none := by
  cases binding <;> apply before_alu_memory_none

inductive MemoryStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : StepBinding flags aux dst src value nextPc nativeState code native) :
      MemoryStepBinding flags aux dst src value nextPc nativeState code native
  | alu (code : Nat) (native : Reference.X86.Instruction)
      (fields : AluMemoryBinding flags aux dst src value nextPc nativeState code native) :
      MemoryStepBinding flags aux dst src value nextPc nativeState code native

/-- One composed step for all earlier model arms and the new memory ALU
fields. It retains native state, ordered effects, faults and defined flags. -/
theorem memory_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : MemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchMemoryStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchMemoryStep, dispatched], refined⟩
  | alu fields =>
      apply exact_dispatch_refines
      rw [dispatchMemoryStep, alu_memory_binding_before_none env frame arena current code flags aux dst src value nextPc state native fields]
      exact alu_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields

def specializedMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .aluMemImm then aluMemoryRegisters env frame arena (GeneratedX86Opcode.code .aluMemImm) flags aux dst src value nextPc state
  else if token = .aluMemReg then aluMemoryRegisters env frame arena (GeneratedX86Opcode.code .aluMemReg) flags aux dst src value nextPc state
  else specializedStep env frame arena current token flags aux dst src value nextPc state

def memoryStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .aluMemImm then some .aluMemImm else if token = .aluMemReg then some .aluMemReg
  else stepTokenOpcode token

theorem memory_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : memoryStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_alu_memory (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : stepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .aluMemImm ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .aluMemReg := by
  cases token <;> simp only [stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem memory_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : memoryStepTokenOpcode token = some opcode) :
    specializedMemoryStep env frame arena current token flags aux dst src value nextPc state =
      dispatchMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases immediate : token = .aluMemImm
  · subst token
    simp only [memoryStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    have skipped := before_alu_memory_none env frame arena current true flags aux dst src value nextPc state
    simp only [Bool.true_eq, Bool.false_eq_true, ↓reduceIte] at skipped
    rw [specializedMemoryStep, if_pos rfl, dispatchMemoryStep, skipped]
  · by_cases registers : token = .aluMemReg
    · subst token
      simp only [memoryStepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
      subst opcode
      have skipped := before_alu_memory_none env frame arena current false flags aux dst src value nextPc state
      simp only [Bool.true_eq, Bool.false_eq_true, ↓reduceIte] at skipped
      rw [specializedMemoryStep, if_neg (by decide), if_pos rfl, dispatchMemoryStep, skipped]
    · have earlier : stepTokenOpcode token = some opcode := by
        simpa only [memoryStepTokenOpcode, immediate, registers, ↓reduceIte] using selected
      obtain ⟨notImmediate, notRegisters⟩ := earlier_token_excludes_alu_memory token opcode earlier
      simp only [specializedMemoryStep, immediate, registers, ↓reduceIte]
      rw [step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
      unfold dispatchMemoryStep
      cases dispatched : dispatchStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
        simp [dispatched, aluMemoryRegisters, notImmediate, notRegisters]

theorem memory_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : memoryStepTokenOpcode token = some opcode)
    (binding : MemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact memory_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem memory_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : memoryStepTokenOpcode token = some opcode)
    (binding : MemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := memory_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩

def sourceMultiplyWidth : ScalarWidth → Option Reference.X86.CmovWidth
  | .w8 => none | .w16 => some .w16 | .w32 => some .w32 | .w64 => some .w64

def aluSourceBody (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (payload : BitVec 32)
    (destination : Register) (address nextPc : Reference.Word) : Option (Transition Reference.X86.State) :=
  match logicKindOf payload with
  | some kind => some (logicSourceFrame env frame arena state width kind destination address nextPc)
  | none => match arithmeticKindOf payload with
    | some kind => some (arithmeticSourceFrame env frame arena state width kind destination address nextPc)
    | none => if payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul) then
        (sourceMultiplyWidth width).map (fun wide => multiplySourceFrame env frame arena state wide destination address nextPc)
      else none

def aluSourceRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .aluMem then do
    let width ← widthOf flags
    let destination ← registerOf dst
    let address ← memoryAddressRegisters env frame arena state src aux value
    aluSourceBody env frame arena state width (GeneratedX86MemAux.op aux) destination address nextPc
  else none

theorem alu_source_arithmetic_body (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (kind : Reference.X86.ArithmeticKind)
    (payload : BitVec 32) (destination : Register) (address nextPc : Reference.Word)
    (writing : kind ≠ .compare) (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (arithmeticAlu kind))) :
    aluSourceBody env frame arena state width payload destination address nextPc =
      some (arithmeticSourceFrame env frame arena state width kind destination address nextPc) := by
  simp only [aluSourceBody, (arithmetic_payload_separate payload kind field).1,
    arithmetic_kind_binding_decodes payload kind writing field]

theorem alu_source_logic_body (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : ScalarWidth) (kind : Reference.X86.LogicKind)
    (payload : BitVec 32) (destination : Register) (address nextPc : Reference.Word)
    (writing : kind ≠ .test) (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Logic.alu kind))) :
    aluSourceBody env frame arena state width payload destination address nextPc =
      some (logicSourceFrame env frame arena state width kind destination address nextPc) := by
  rw [aluSourceBody, logic_kind_binding_decodes payload kind writing field]

theorem alu_source_multiply_body (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (width : Reference.X86.CmovWidth)
    (payload : BitVec 32) (destination : Register) (address nextPc : Reference.Word)
    (field : payload = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul)) :
    aluSourceBody env frame arena state (cmovScalarWidth width) payload destination address nextPc =
      some (multiplySourceFrame env frame arena state width destination address nextPc) := by
  obtain ⟨logic, arithmetic, _⟩ := multiply_payload_separate payload field
  simp only [aluSourceBody, logic, arithmetic, field, ↓reduceIte]
  cases width <;> rfl

inductive AluSourceBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | arithmetic (width : ScalarWidth) (kind : Reference.X86.ArithmeticKind) (destination : Register)
      (base index : Option Register) (writing : kind ≠ .compare)
      (widthField : WidthBinding flags width)
      (kindField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code (arithmeticAlu kind)))
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      AluSourceBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .aluMem)
        (.arithmetic width kind (.register (.low destination)) (.memory (leaAddress nativeState base index aux value)) nextPc)
  | logic (width : ScalarWidth) (kind : Reference.X86.LogicKind) (destination : Register)
      (base index : Option Register) (writing : kind ≠ .test)
      (widthField : WidthBinding flags width)
      (kindField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code (X86Logic.alu kind)))
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      AluSourceBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .aluMem)
        (.logic width kind (.register (.low destination)) (.memory (leaAddress nativeState base index aux value)) nextPc)
  | multiply (width : Reference.X86.CmovWidth) (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (kindField : GeneratedX86MemAux.op aux = BitVec.ofNat 32 (GeneratedX86AluDecode.code .imul))
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      AluSourceBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .aluMem)
        (.multiply width destination (.memory (leaAddress nativeState base index aux value)) none nextPc)

theorem alu_source_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : AluSourceBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    aluSourceRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | arithmetic width kind destination base index writing widthField kindField destinationField baseField indexField =>
      simp only [aluSourceRegisters, if_pos rfl, ↓reduceIte, width_binding_decodes flags width widthField, Option.bind_some]
      rw [destinationField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
      change aluSourceBody env frame arena state width (GeneratedX86MemAux.op aux) destination
        (leaAddress (nativeRegisters env frame arena state) base index aux value) nextPc = _
      rw [alu_source_arithmetic_body _ _ _ _ _ kind _ _ _ _ writing kindField]
      exact congrArg some (arithmetic_source_frame_refines env frame arena state width kind destination _ nextPc writing)
  | logic width kind destination base index writing widthField kindField destinationField baseField indexField =>
      simp only [aluSourceRegisters, if_pos rfl, ↓reduceIte, width_binding_decodes flags width widthField, Option.bind_some]
      rw [destinationField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
      change aluSourceBody env frame arena state width (GeneratedX86MemAux.op aux) destination
        (leaAddress (nativeRegisters env frame arena state) base index aux value) nextPc = _
      rw [alu_source_logic_body _ _ _ _ _ kind _ _ _ _ writing kindField]
      exact congrArg some (logic_source_frame_refines env frame arena state width kind destination _ nextPc writing)
  | multiply width destination base index widthField kindField destinationField baseField indexField =>
      simp only [aluSourceRegisters, if_pos rfl, ↓reduceIte, width_binding_decodes flags _ widthField, Option.bind_some]
      rw [destinationField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
      change aluSourceBody env frame arena state (cmovScalarWidth width) (GeneratedX86MemAux.op aux) destination
        (leaAddress (nativeRegisters env frame arena state) base index aux value) nextPc = _
      rw [alu_source_multiply_body _ _ _ _ width _ _ _ _ kindField]
      exact congrArg some (multiply_source_frame_refines env frame arena state width destination _ nextPc)

def dispatchSourceStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchMemoryStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => aluSourceRegisters env frame arena code flags aux dst src value nextPc state

theorem before_alu_source_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchMemoryStep env frame arena current (GeneratedX86Opcode.code .aluMem) flags aux dst src value nextPc state = none := by
  rfl

inductive SourceStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : MemoryStepBinding flags aux dst src value nextPc nativeState code native) :
      SourceStepBinding flags aux dst src value nextPc nativeState code native
  | source (native : Reference.X86.Instruction)
      (fields : AluSourceBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .aluMem) native) :
      SourceStepBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .aluMem) native

theorem source_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : SourceStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchSourceStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier code native fields =>
      obtain ⟨actual, dispatched, refined⟩ := memory_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchSourceStep, dispatched], refined⟩
  | source native fields =>
      apply exact_dispatch_refines
      rw [dispatchSourceStep, before_alu_source_none]
      exact alu_source_registers_refine env frame arena _ flags aux dst src value nextPc state native fields

def specializedSourceStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .aluMem then aluSourceRegisters env frame arena (GeneratedX86Opcode.code .aluMem) flags aux dst src value nextPc state
  else specializedMemoryStep env frame arena current token flags aux dst src value nextPc state

def sourceStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .aluMem then some .aluMem else memoryStepTokenOpcode token

theorem source_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : sourceStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_alu_source (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : memoryStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .aluMem := by
  cases token <;> simp only [memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem source_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : sourceStepTokenOpcode token = some opcode) :
    specializedSourceStep env frame arena current token flags aux dst src value nextPc state =
      dispatchSourceStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases source : token = .aluMem
  · subst token
    simp only [sourceStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    rw [specializedSourceStep, if_pos rfl, dispatchSourceStep, before_alu_source_none]
  · have earlier : memoryStepTokenOpcode token = some opcode := by
      simpa only [sourceStepTokenOpcode, source, ↓reduceIte] using selected
    have separate := earlier_token_excludes_alu_source token opcode earlier
    simp only [specializedSourceStep, source, ↓reduceIte]
    rw [memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
    unfold dispatchSourceStep
    cases dispatched : dispatchMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
      simp [dispatched, aluSourceRegisters, separate]

theorem source_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : sourceStepTokenOpcode token = some opcode)
    (binding : SourceStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedSourceStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [source_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact source_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem source_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : sourceStepTokenOpcode token = some opcode)
    (binding : SourceStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedSourceStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := source_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩

/-- The memory-width byte is absent or matches the native IMUL operand.
The packed high32 displacement and low32 immediate retain separate fields. -/
def imulMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .imulMemImm then do
    let width ← cmovWidthOf flags
    if GeneratedX86MemAux.memWidth aux = 0 ∨ GeneratedX86MemAux.memWidth aux = BitVec.ofNat 32 width.bytes then do
      let destination ← registerOf dst
      let address ← memoryAddressRegisters env frame arena state src aux (((value >>> 32).setWidth 32).signExtend 64)
      pure (multiplyMemoryImmediateFrame env frame arena state width destination value address nextPc)
    else none
  else none

inductive ImulMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | fields (width : Reference.X86.CmovWidth) (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (memoryField : GeneratedX86MemAux.memWidth aux = 0 ∨
        GeneratedX86MemAux.memWidth aux = BitVec.ofNat 32 width.bytes)
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      ImulMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .imulMemImm)
        (.multiply width destination
          (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64)))
          (some (value.setWidth 32)) nextPc)

theorem imul_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ImulMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    imulMemoryRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | fields width destination base index widthField memoryField destinationField baseField indexField =>
      simp only [imulMemoryRegisters, if_pos rfl, ↓reduceIte,
        cmov_width_binding_decodes flags width widthField, Option.bind_some]
      change (if GeneratedX86MemAux.memWidth aux = 0 ∨ GeneratedX86MemAux.memWidth aux = BitVec.ofNat 32 width.bytes
        then _ else _) = _
      rw [if_pos memoryField, destinationField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state src base index aux _ baseField indexField]
      change some (multiplyMemoryImmediateFrame env frame arena state width destination value
        (leaAddress (nativeRegisters env frame arena state) base index aux (((value >>> 32).setWidth 32).signExtend 64)) nextPc) = _
      exact congrArg some (multiply_memory_immediate_frame_refines env frame arena state width destination value _ nextPc)

def dispatchImulStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchSourceStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => imulMemoryRegisters env frame arena code flags aux dst src value nextPc state

theorem before_imul_memory_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchSourceStep env frame arena current (GeneratedX86Opcode.code .imulMemImm) flags aux dst src value nextPc state = none := by
  rfl

inductive ImulStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : SourceStepBinding flags aux dst src value nextPc nativeState code native) :
      ImulStepBinding flags aux dst src value nextPc nativeState code native
  | source (native : Reference.X86.Instruction)
      (fields : ImulMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .imulMemImm) native) :
      ImulStepBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .imulMemImm) native

theorem imul_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ImulStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchImulStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier code native fields =>
      obtain ⟨actual, dispatched, refined⟩ := source_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchImulStep, dispatched], refined⟩
  | source native fields =>
      apply exact_dispatch_refines
      rw [dispatchImulStep, before_imul_memory_none]
      exact imul_memory_registers_refine env frame arena _ flags aux dst src value nextPc state native fields

def specializedImulStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .imulMemImm then imulMemoryRegisters env frame arena (GeneratedX86Opcode.code .imulMemImm) flags aux dst src value nextPc state
  else specializedSourceStep env frame arena current token flags aux dst src value nextPc state

def imulStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .imulMemImm then some .imulMemImm else sourceStepTokenOpcode token

theorem imul_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : imulStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [imulStepTokenOpcode, sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_imul_memory (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : sourceStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .imulMemImm := by
  cases token <;> simp only [sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem imul_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : imulStepTokenOpcode token = some opcode) :
    specializedImulStep env frame arena current token flags aux dst src value nextPc state =
      dispatchImulStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases source : token = .imulMemImm
  · subst token
    simp only [imulStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    rw [specializedImulStep, if_pos rfl, dispatchImulStep, before_imul_memory_none]
  · have earlier : sourceStepTokenOpcode token = some opcode := by
      simpa only [imulStepTokenOpcode, source, ↓reduceIte] using selected
    have separate := earlier_token_excludes_imul_memory token opcode earlier
    simp only [specializedImulStep, source, ↓reduceIte]
    rw [source_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
    unfold dispatchImulStep
    cases dispatched : dispatchSourceStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
      simp [dispatched, imulMemoryRegisters, separate]

theorem imul_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : imulStepTokenOpcode token = some opcode)
    (binding : ImulStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedImulStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [imul_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact imul_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem imul_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : imulStepTokenOpcode token = some opcode)
    (binding : ImulStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedImulStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := imul_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩

inductive LoadKind where
  | ordinary | scalar | signed
  deriving DecidableEq

def loadOpcode : LoadKind → GeneratedX86Opcode.Op
  | .ordinary => .movLoad | .scalar => .movLoadScalar | .signed => .movsxLoad

def loadSigned : LoadKind → Bool
  | .ordinary | .scalar => false | .signed => true

/-- The memory width uses AUX's byte when present, otherwise the resolved
write width. Both fields retain their generated byte layout. -/
def loadSourceWidthOf (targetWidth : ScalarWidth) (aux : BitVec 32) : Option ScalarWidth :=
  if GeneratedX86MemAux.memWidth aux = 0 then some targetWidth
  else widthOf ((GeneratedX86MemAux.memWidth aux).setWidth 8)

def LoadMemoryWidthBinding (aux : BitVec 32) (sourceWidth targetWidth : ScalarWidth) : Prop :=
  (GeneratedX86MemAux.memWidth aux = 0 ∧ sourceWidth = targetWidth) ∨
    GeneratedX86MemAux.memWidth aux = BitVec.ofNat 32 sourceWidth.bytes

theorem load_source_width_decodes (aux : BitVec 32) (sourceWidth targetWidth : ScalarWidth)
    (binding : LoadMemoryWidthBinding aux sourceWidth targetWidth) :
    loadSourceWidthOf targetWidth aux = some sourceWidth := by
  rcases binding with ⟨absent, rfl⟩ | exactWidth
  · simp only [loadSourceWidthOf, absent, ↓reduceIte]
  · cases sourceWidth <;> simp [loadSourceWidthOf, exactWidth, widthOf, GeneratedX86Width.effective,
      GeneratedX86Width.absentCode, GeneratedX86Width.defaultCode, Reference.X86.ScalarWidth.bytes]

def loadBodyRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (signed : Bool) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) := do
  let targetWidth ← widthOf flags
  let sourceWidth ← loadSourceWidthOf targetWidth aux
  let destination ← registerOf dst
  let address ← memoryAddressRegisters env frame arena state src aux value
  pure (loadMemoryFrame env frame arena state sourceWidth targetWidth signed destination address nextPc)

def loadRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .movLoad then loadBodyRegisters env frame arena false flags aux dst src value nextPc state
  else if code = GeneratedX86Opcode.code .movLoadScalar then loadBodyRegisters env frame arena false flags aux dst src value nextPc state
  else if code = GeneratedX86Opcode.code .movsxLoad then loadBodyRegisters env frame arena true flags aux dst src value nextPc state
  else none

theorem load_kind_body (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (kind : LoadKind) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    loadRegisters env frame arena (GeneratedX86Opcode.code (loadOpcode kind)) flags aux dst src value nextPc state =
      loadBodyRegisters env frame arena (loadSigned kind) flags aux dst src value nextPc state := by
  cases kind <;> rfl

theorem load_body_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (sourceWidth targetWidth : ScalarWidth)
    (signed : Bool) (flags : Byte) (aux : BitVec 32) (dst src : Byte) (destination : Register)
    (base index : Option Register) (value nextPc : Reference.Word)
    (widthField : WidthBinding flags targetWidth) (memoryField : LoadMemoryWidthBinding aux sourceWidth targetWidth)
    (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
    (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
    loadBodyRegisters env frame arena signed flags aux dst src value nextPc state =
      some (loadMemoryFrame env frame arena state sourceWidth targetWidth signed destination
        (leaAddress (nativeRegisters env frame arena state) base index aux value) nextPc) := by
  simp only [loadBodyRegisters, width_binding_decodes flags targetWidth widthField, Option.bind_some]
  change (loadSourceWidthOf targetWidth aux >>= fun source => registerOf dst >>= fun destination =>
    memoryAddressRegisters env frame arena state src aux value >>= fun address =>
      some (loadMemoryFrame env frame arena state source targetWidth signed destination address nextPc)) = _
  rw [load_source_width_decodes aux sourceWidth targetWidth memoryField, destinationField, register_of_byte]
  rw [memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
  rfl

inductive LoadBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | extension (kind : LoadKind) (sourceWidth targetWidth : ScalarWidth) (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags targetWidth) (memoryField : LoadMemoryWidthBinding aux sourceWidth targetWidth)
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      LoadBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code (loadOpcode kind))
        (.extend sourceWidth targetWidth (loadSigned kind) destination (.memory (leaAddress nativeState base index aux value)) nextPc)
  | move (kind : LoadKind) (width : ScalarWidth) (destination : Register) (base index : Option Register)
      (ordinary : loadSigned kind = false) (widthField : WidthBinding flags width)
      (memoryField : LoadMemoryWidthBinding aux width width)
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      LoadBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code (loadOpcode kind))
        (.move width (.register (.low destination)) (.memory (leaAddress nativeState base index aux value)) nextPc)

theorem load_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : LoadBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    loadRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | extension kind sourceWidth targetWidth destination base index widthField memoryField destinationField baseField indexField =>
      rw [load_kind_body, load_body_registers_refine env frame arena state sourceWidth targetWidth _ flags aux dst src destination base index value nextPc widthField memoryField destinationField baseField indexField]
      exact congrArg some (load_memory_frame_refines env frame arena state sourceWidth targetWidth _ destination _ nextPc)
  | move kind width destination base index ordinary widthField memoryField destinationField baseField indexField =>
      rw [load_kind_body, ordinary, load_body_registers_refine env frame arena state width width false flags aux dst src destination base index value nextPc widthField memoryField destinationField baseField indexField]
      exact congrArg some (load_memory_move_refines env frame arena state width destination _ nextPc)

def dispatchLoadStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchImulStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => loadRegisters env frame arena code flags aux dst src value nextPc state

theorem before_load_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (kind : LoadKind) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchImulStep env frame arena current (GeneratedX86Opcode.code (loadOpcode kind)) flags aux dst src value nextPc state = none := by
  cases kind <;> rfl

theorem load_binding_before_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : LoadBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    dispatchImulStep env frame arena current code flags aux dst src value nextPc state = none := by
  cases binding <;> apply before_load_none

inductive LoadStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : ImulStepBinding flags aux dst src value nextPc nativeState code native) :
      LoadStepBinding flags aux dst src value nextPc nativeState code native
  | load (code : Nat) (native : Reference.X86.Instruction)
      (fields : LoadBinding flags aux dst src value nextPc nativeState code native) :
      LoadStepBinding flags aux dst src value nextPc nativeState code native

theorem load_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : LoadStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchLoadStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := imul_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchLoadStep, dispatched], refined⟩
  | load fields =>
      apply exact_dispatch_refines
      rw [dispatchLoadStep, load_binding_before_none env frame arena current code flags aux dst src value nextPc state native fields]
      exact load_registers_refine env frame arena code flags aux dst src value nextPc state native fields

def specializedLoadStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .movLoad then loadBodyRegisters env frame arena false flags aux dst src value nextPc state
  else if token = .movLoadScalar then loadBodyRegisters env frame arena false flags aux dst src value nextPc state
  else if token = .movsxLoad then loadBodyRegisters env frame arena true flags aux dst src value nextPc state
  else specializedImulStep env frame arena current token flags aux dst src value nextPc state

def loadStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .movLoad then some .movLoad else if token = .movLoadScalar then some .movLoadScalar
  else if token = .movsxLoad then some .movsxLoad else imulStepTokenOpcode token

theorem load_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : loadStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [loadStepTokenOpcode, imulStepTokenOpcode, sourceStepTokenOpcode, memoryStepTokenOpcode,
    stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_load (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : imulStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .movLoad ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .movLoadScalar ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .movsxLoad := by
  cases token <;> simp only [imulStepTokenOpcode, sourceStepTokenOpcode, memoryStepTokenOpcode,
    stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem load_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : loadStepTokenOpcode token = some opcode) :
    specializedLoadStep env frame arena current token flags aux dst src value nextPc state =
      dispatchLoadStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases ordinary : token = .movLoad
  · subst token
    simp only [loadStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    have skipped := before_load_none env frame arena current .ordinary flags aux dst src value nextPc state
    simp only [loadOpcode] at skipped
    rw [specializedLoadStep, if_pos rfl, dispatchLoadStep,
      skipped]
    rfl
  · by_cases scalar : token = .movLoadScalar
    · subst token
      simp only [loadStepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
      subst opcode
      have skipped := before_load_none env frame arena current .scalar flags aux dst src value nextPc state
      simp only [loadOpcode] at skipped
      rw [specializedLoadStep, if_neg (by decide), if_pos rfl, dispatchLoadStep,
        skipped]
      rfl
    · by_cases signed : token = .movsxLoad
      · subst token
        simp only [loadStepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
        subst opcode
        have skipped := before_load_none env frame arena current .signed flags aux dst src value nextPc state
        simp only [loadOpcode] at skipped
        rw [specializedLoadStep, if_neg (by decide), if_neg (by decide), if_pos rfl, dispatchLoadStep,
          skipped]
        rfl
      · have earlier : imulStepTokenOpcode token = some opcode := by
          simpa only [loadStepTokenOpcode, ordinary, scalar, signed, ↓reduceIte] using selected
        obtain ⟨notOrdinary, notScalar, notSigned⟩ := earlier_token_excludes_load token opcode earlier
        simp only [specializedLoadStep, ordinary, scalar, signed, ↓reduceIte]
        rw [imul_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
        unfold dispatchLoadStep
        cases dispatched : dispatchImulStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
          simp [dispatched, loadRegisters, notOrdinary, notScalar, notSigned]

theorem load_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : loadStepTokenOpcode token = some opcode)
    (binding : LoadStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedLoadStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [load_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact load_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem load_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : loadStepTokenOpcode token = some opcode)
    (binding : LoadStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedLoadStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := load_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩


/-- Packed memory BMI fields select the signed high32 displacement. SHIFTX
uses the AUX source byte as a count register and the immediate low byte as
its ALU selector; RORX consumes that low byte as its immediate count. -/
def bmiMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .shiftxMem ∨ code = GeneratedX86Opcode.code .rorxMem then do
    let width ← bswapWidthOf flags
    let destination ← registerOf dst
    let address ← memoryAddressRegisters env frame arena state src aux (((value >>> 32).setWidth 32).signExtend 64)
    if code = GeneratedX86Opcode.code .shiftxMem then do
      let count ← registerOf ((GeneratedX86MemAux.op aux).setWidth 8)
      let kind ← bmiShiftKindOf ((value.setWidth 8).setWidth 32)
      pure (bmiMemoryFrame env frame arena state width kind destination
        (registerValue env frame arena state count) address nextPc)
    else pure (bmiMemoryFrame env frame arena state width .rotate destination ((value.setWidth 8).setWidth 64) address nextPc)
  else none

inductive BmiMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | shift (width : Reference.X86.BzhiWidth) (kind : Reference.X86.BmiShift)
      (destination count : Register) (base index : Option Register) (ordinary : kind ≠ .rotate)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (kindField : (value.setWidth 8).setWidth 32 = BitVec.ofNat 32 (GeneratedX86AluDecode.code (bmiShiftAlu kind)))
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (countField : (GeneratedX86MemAux.op aux).setWidth 8 = registerByte count)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      BmiMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .shiftxMem)
        (.bmiShift width kind destination
          (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64))) (.register count) nextPc)
  | rotate (width : Reference.X86.BzhiWidth) (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      BmiMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .rorxMem)
        (.bmiShift width .rotate destination
          (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64)))
          (.immediate (value.setWidth 8)) nextPc)

theorem bmi_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : BmiMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    bmiMemoryRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | shift width kind destination count base index ordinary widthField kindField destinationField baseField countField indexField =>
      simp only [bmiMemoryRegisters, if_pos (Or.inl rfl), bswap_width_binding_decodes flags width widthField, Option.bind_some]
      rw [destinationField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state src base index aux _ baseField indexField]
      change (registerOf ((GeneratedX86MemAux.op aux).setWidth 8) >>= fun count =>
        bmiShiftKindOf ((value.setWidth 8).setWidth 32) >>= fun kind =>
          some (bmiMemoryFrame env frame arena state width kind destination
            (registerValue env frame arena state count) _ nextPc)) = _
      rw [countField, register_of_byte, bmi_shift_kind_decodes kind _ ordinary kindField]
      exact congrArg some (bmi_memory_frame_refines env frame arena state width kind destination (.register count) _ nextPc)
  | rotate width destination base index widthField destinationField baseField indexField =>
      simp only [bmiMemoryRegisters, GeneratedX86Opcode.code, Nat.reduceEqDiff, ↓reduceIte,
        bswap_width_binding_decodes flags width widthField, Option.bind_some]
      rw [destinationField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state src base index aux _ baseField indexField]
      exact congrArg some (bmi_memory_frame_refines env frame arena state width .rotate destination (.immediate (value.setWidth 8)) _ nextPc)

def dispatchBmiMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchLoadStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => bmiMemoryRegisters env frame arena code flags aux dst src value nextPc state

theorem before_bmi_memory_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (rotate : Bool) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchLoadStep env frame arena current (GeneratedX86Opcode.code (if rotate then .rorxMem else .shiftxMem))
      flags aux dst src value nextPc state = none := by
  cases rotate <;> rfl

theorem bmi_memory_binding_before_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : BmiMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    dispatchLoadStep env frame arena current code flags aux dst src value nextPc state = none := by
  cases binding
  · exact before_bmi_memory_none env frame arena current false flags aux dst src value nextPc state
  · exact before_bmi_memory_none env frame arena current true flags aux dst src value nextPc state

inductive BmiMemoryStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : LoadStepBinding flags aux dst src value nextPc nativeState code native) :
      BmiMemoryStepBinding flags aux dst src value nextPc nativeState code native
  | memory (code : Nat) (native : Reference.X86.Instruction)
      (fields : BmiMemoryBinding flags aux dst src value nextPc nativeState code native) :
      BmiMemoryStepBinding flags aux dst src value nextPc nativeState code native

theorem bmi_memory_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : BmiMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchBmiMemoryStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := load_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchBmiMemoryStep, dispatched], refined⟩
  | memory fields =>
      apply exact_dispatch_refines
      rw [dispatchBmiMemoryStep, bmi_memory_binding_before_none env frame arena current code flags aux dst src value nextPc state native fields]
      exact bmi_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields

/-- These two production tokens invoke RUN_OP with their constant opcode;
all fields flow through the same modeled generic dispatcher arm. -/
def specializedBmiMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .shiftxMem then dispatchBmiMemoryStep env frame arena current (GeneratedX86Opcode.code .shiftxMem) flags aux dst src value nextPc state
  else if token = .rorxMem then dispatchBmiMemoryStep env frame arena current (GeneratedX86Opcode.code .rorxMem) flags aux dst src value nextPc state
  else specializedLoadStep env frame arena current token flags aux dst src value nextPc state

def bmiMemoryStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .shiftxMem then some .shiftxMem else if token = .rorxMem then some .rorxMem else loadStepTokenOpcode token

theorem bmi_memory_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : bmiMemoryStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode,
    sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_bmi_memory (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : loadStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .shiftxMem ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .rorxMem := by
  cases token <;> simp only [loadStepTokenOpcode, imulStepTokenOpcode, sourceStepTokenOpcode,
    memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem bmi_memory_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : bmiMemoryStepTokenOpcode token = some opcode) :
    specializedBmiMemoryStep env frame arena current token flags aux dst src value nextPc state =
      dispatchBmiMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases shift : token = .shiftxMem
  · subst token
    simp only [bmiMemoryStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    rfl
  · by_cases rotate : token = .rorxMem
    · subst token
      simp only [bmiMemoryStepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
      subst opcode
      rfl
    · have earlier : loadStepTokenOpcode token = some opcode := by
        simpa only [bmiMemoryStepTokenOpcode, shift, rotate, ↓reduceIte] using selected
      obtain ⟨notShift, notRotate⟩ := earlier_token_excludes_bmi_memory token opcode earlier
      simp only [specializedBmiMemoryStep, shift, rotate, ↓reduceIte]
      rw [load_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
      unfold dispatchBmiMemoryStep
      cases dispatched : dispatchLoadStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
        simp [dispatched, bmiMemoryRegisters, notShift, notRotate]

theorem bmi_memory_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : bmiMemoryStepTokenOpcode token = some opcode)
    (binding : BmiMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedBmiMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [bmi_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact bmi_memory_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem bmi_memory_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : bmiMemoryStepTokenOpcode token = some opcode)
    (binding : BmiMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedBmiMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := bmi_memory_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩


/-- These memory bit-operation bodies use the full displacement. BZHI samples
its count GPR from AUX's high byte; POPCNT resolves its native16/32/64 width. -/
def bitMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .bzhiMem then do
    let width ← bswapWidthOf flags
    let destination ← registerOf dst
    let count ← registerOf ((GeneratedX86MemAux.op aux).setWidth 8)
    let address ← memoryAddressRegisters env frame arena state src aux value
    pure (bzhiMemoryFrame env frame arena state width destination count address nextPc)
  else if code = GeneratedX86Opcode.code .popcntMem then do
    let width ← cmovWidthOf flags
    let destination ← registerOf dst
    let address ← memoryAddressRegisters env frame arena state src aux value
    pure (populationCountMemoryFrame env frame arena state width destination address nextPc)
  else none

inductive BitMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | bzhi (width : Reference.X86.BzhiWidth) (destination count : Register) (base index : Option Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (countField : (GeneratedX86MemAux.op aux).setWidth 8 = registerByte count)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      BitMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .bzhiMem)
        (.bzhi width destination (.memory (leaAddress nativeState base index aux value)) count nextPc)
  | popcount (width : Reference.X86.CmovWidth) (destination : Register) (base index : Option Register)
      (widthField : WidthBinding flags (cmovScalarWidth width))
      (destinationField : dst = registerByte destination) (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      BitMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .popcntMem)
        (.popcount width destination (.memory (leaAddress nativeState base index aux value)) nextPc)

theorem bit_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : BitMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    bitMemoryRegisters env frame arena code flags aux dst src value nextPc state =
      some (Reference.X86.step native (nativeRegisters env frame arena state)) := by
  cases binding with
  | bzhi width destination count base index widthField destinationField baseField countField indexField =>
      simp only [bitMemoryRegisters, if_pos rfl, bswap_width_binding_decodes flags width widthField, Option.bind_some]
      rw [destinationField, register_of_byte, countField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
      exact congrArg some (bzhi_memory_frame_refines env frame arena state width destination count _ nextPc)
  | popcount width destination base index widthField destinationField baseField indexField =>
      simp only [bitMemoryRegisters, GeneratedX86Opcode.code, Nat.reduceEqDiff, ↓reduceIte,
        cmov_width_binding_decodes flags width widthField, Option.bind_some]
      rw [destinationField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state src base index aux value baseField indexField]
      exact congrArg some (population_count_memory_frame_refines env frame arena state width destination _ nextPc)

def dispatchBitMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchBmiMemoryStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => bitMemoryRegisters env frame arena code flags aux dst src value nextPc state

theorem before_bit_memory_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (rotate : Bool) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchBmiMemoryStep env frame arena current (GeneratedX86Opcode.code (if rotate then .popcntMem else .bzhiMem))
      flags aux dst src value nextPc state = none := by
  cases rotate <;> rfl

theorem bit_memory_binding_before_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : BitMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    dispatchBmiMemoryStep env frame arena current code flags aux dst src value nextPc state = none := by
  cases binding
  · exact before_bit_memory_none env frame arena current false flags aux dst src value nextPc state
  · exact before_bit_memory_none env frame arena current true flags aux dst src value nextPc state

inductive BitMemoryStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : BmiMemoryStepBinding flags aux dst src value nextPc nativeState code native) :
      BitMemoryStepBinding flags aux dst src value nextPc nativeState code native
  | memory (code : Nat) (native : Reference.X86.Instruction)
      (fields : BitMemoryBinding flags aux dst src value nextPc nativeState code native) :
      BitMemoryStepBinding flags aux dst src value nextPc nativeState code native

theorem bit_memory_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : BitMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchBitMemoryStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := bmi_memory_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchBitMemoryStep, dispatched], refined⟩
  | memory fields =>
      apply exact_dispatch_refines
      rw [dispatchBitMemoryStep, bit_memory_binding_before_none env frame arena current code flags aux dst src value nextPc state native fields]
      exact bit_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields

/-- These two production tokens invoke RUN_OP with their constant opcode;
all fields flow through the same modeled generic dispatcher arm. -/
def specializedBitMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .bzhiMem then dispatchBitMemoryStep env frame arena current (GeneratedX86Opcode.code .bzhiMem) flags aux dst src value nextPc state
  else if token = .popcntMem then dispatchBitMemoryStep env frame arena current (GeneratedX86Opcode.code .popcntMem) flags aux dst src value nextPc state
  else specializedBmiMemoryStep env frame arena current token flags aux dst src value nextPc state

def bitMemoryStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .bzhiMem then some .bzhiMem else if token = .popcntMem then some .popcntMem else bmiMemoryStepTokenOpcode token

theorem bit_memory_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : bitMemoryStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [bitMemoryStepTokenOpcode, bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode,
    sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_bit_memory (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : bmiMemoryStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .bzhiMem ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .popcntMem := by
  cases token <;> simp only [bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode, sourceStepTokenOpcode,
    memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem bit_memory_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : bitMemoryStepTokenOpcode token = some opcode) :
    specializedBitMemoryStep env frame arena current token flags aux dst src value nextPc state =
      dispatchBitMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases shift : token = .bzhiMem
  · subst token
    simp only [bitMemoryStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    rfl
  · by_cases rotate : token = .popcntMem
    · subst token
      simp only [bitMemoryStepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
      subst opcode
      rfl
    · have earlier : bmiMemoryStepTokenOpcode token = some opcode := by
        simpa only [bitMemoryStepTokenOpcode, shift, rotate, ↓reduceIte] using selected
      obtain ⟨notShift, notRotate⟩ := earlier_token_excludes_bit_memory token opcode earlier
      simp only [specializedBitMemoryStep, shift, rotate, ↓reduceIte]
      rw [bmi_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
      unfold dispatchBitMemoryStep
      cases dispatched : dispatchBmiMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
        simp [dispatched, bitMemoryRegisters, notShift, notRotate]

theorem bit_memory_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : bitMemoryStepTokenOpcode token = some opcode)
    (binding : BitMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedBitMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [bit_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact bit_memory_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem bit_memory_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : bitMemoryStepTokenOpcode token = some opcode)
    (binding : BitMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedBitMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := bit_memory_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩


/-- The two packed-memory bodies retain actual high32 displacement and byte
layouts. ANDN decodes its read width and AUX high-byte base independently. -/
def observedMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .andnMem then do
    let width ← bswapWidthOf flags
    let sourceWidth ← loadSourceWidthOf (bswapScalarWidth width) aux
    let destination ← registerOf dst
    let first ← registerOf src
    let address ← memoryAddressRegisters env frame arena state ((GeneratedX86MemAux.op aux).setWidth 8) aux
      (((value >>> 32).setWidth 32).signExtend 64)
    pure (andnMemoryFrame env frame arena state sourceWidth width destination first address nextPc)
  else if code = GeneratedX86Opcode.code .btMemImm then do
    let width ← cmovWidthOf flags
    let address ← memoryAddressRegisters env frame arena state dst aux (((value >>> 32).setWidth 32).signExtend 64)
    pure (bitTestMemoryFrame env frame arena state width value address nextPc)
  else none

inductive ObservedMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | andn (width : Reference.X86.BzhiWidth) (destination first : Register) (base index : Option Register)
      (widthField : WidthBinding flags (bswapScalarWidth width))
      (memoryField : LoadMemoryWidthBinding aux (bswapScalarWidth width) (bswapScalarWidth width))
      (destinationField : dst = registerByte destination) (firstField : src = registerByte first)
      (baseField : (GeneratedX86MemAux.op aux).setWidth 8 = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      ObservedMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .andnMem)
        (.andn width destination first
          (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64))) nextPc)
  | bit (width : Reference.X86.CmovWidth) (base index : Option Register)
      (widthField : WidthBinding flags (cmovScalarWidth width)) (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
      ObservedMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .btMemImm)
        (.bt width (.memory (leaAddress nativeState base index aux (((value >>> 32).setWidth 32).signExtend 64)))
          (.immediate (value.setWidth 8)) nextPc)

theorem observed_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ObservedMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, observedMemoryRegisters env frame arena code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | andn width destination first base index widthField memoryField destinationField firstField baseField indexField =>
      refine ⟨_, ?_, andn_memory_frame_refines env frame arena state width destination first
        (leaAddress (nativeRegisters env frame arena state) base index aux (((value >>> 32).setWidth 32).signExtend 64)) nextPc⟩
      simp only [observedMemoryRegisters, if_pos rfl, ↓reduceIte,
        bswap_width_binding_decodes flags width widthField, Option.bind_some]
      change (loadSourceWidthOf (bswapScalarWidth width) aux >>= fun sourceWidth =>
        registerOf dst >>= fun destination => registerOf src >>= fun first =>
          memoryAddressRegisters env frame arena state ((GeneratedX86MemAux.op aux).setWidth 8) aux
            (((value >>> 32).setWidth 32).signExtend 64) >>= fun address =>
              some (andnMemoryFrame env frame arena state sourceWidth width destination first address nextPc)) = _
      rw [load_source_width_decodes aux _ _ memoryField, destinationField, register_of_byte, firstField, register_of_byte]
      rw [memory_address_registers_refine env frame arena state _ base index aux _ baseField indexField]
      cases width <;> rfl
  | bit width base index widthField baseField indexField =>
      apply exact_dispatch_refines
      simp only [observedMemoryRegisters, GeneratedX86Opcode.code, Nat.reduceEqDiff, ↓reduceIte,
        cmov_width_binding_decodes flags width widthField, Option.bind_some]
      rw [memory_address_registers_refine env frame arena state dst base index aux _ baseField indexField]
      exact congrArg some (bit_test_memory_frame_refines env frame arena state width value _ nextPc)

def dispatchObservedMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchBitMemoryStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => observedMemoryRegisters env frame arena code flags aux dst src value nextPc state

theorem before_observed_memory_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (rotate : Bool) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchBitMemoryStep env frame arena current (GeneratedX86Opcode.code (if rotate then .btMemImm else .andnMem))
      flags aux dst src value nextPc state = none := by
  cases rotate <;> rfl

theorem observed_memory_binding_before_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ObservedMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    dispatchBitMemoryStep env frame arena current code flags aux dst src value nextPc state = none := by
  cases binding
  · exact before_observed_memory_none env frame arena current false flags aux dst src value nextPc state
  · exact before_observed_memory_none env frame arena current true flags aux dst src value nextPc state

inductive ObservedMemoryStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : BitMemoryStepBinding flags aux dst src value nextPc nativeState code native) :
      ObservedMemoryStepBinding flags aux dst src value nextPc nativeState code native
  | memory (code : Nat) (native : Reference.X86.Instruction)
      (fields : ObservedMemoryBinding flags aux dst src value nextPc nativeState code native) :
      ObservedMemoryStepBinding flags aux dst src value nextPc nativeState code native

theorem observed_memory_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ObservedMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchObservedMemoryStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := bit_memory_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchObservedMemoryStep, dispatched], refined⟩
  | memory fields =>
      obtain ⟨actual, dispatched, refined⟩ := observed_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      exact ⟨actual, by rw [dispatchObservedMemoryStep,
        observed_memory_binding_before_none env frame arena current code flags aux dst src value nextPc state native fields]; exact dispatched, refined⟩

/-- These two direct tokens select their actual fixed-opcode memory bodies.
Earlier tokens retain their established invocation routes. -/
def specializedObservedMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .andnMem then observedMemoryRegisters env frame arena (GeneratedX86Opcode.code .andnMem) flags aux dst src value nextPc state
  else if token = .btMemImm then observedMemoryRegisters env frame arena (GeneratedX86Opcode.code .btMemImm) flags aux dst src value nextPc state
  else specializedBitMemoryStep env frame arena current token flags aux dst src value nextPc state

def observedMemoryStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .andnMem then some .andnMem else if token = .btMemImm then some .btMemImm else bitMemoryStepTokenOpcode token

theorem observed_memory_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : observedMemoryStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [observedMemoryStepTokenOpcode, bitMemoryStepTokenOpcode, bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode,
    sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_observed_memory (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : bitMemoryStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .andnMem ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .btMemImm := by
  cases token <;> simp only [bitMemoryStepTokenOpcode, bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode, sourceStepTokenOpcode,
    memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem observed_memory_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : observedMemoryStepTokenOpcode token = some opcode) :
    specializedObservedMemoryStep env frame arena current token flags aux dst src value nextPc state =
      dispatchObservedMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases shift : token = .andnMem
  · subst token
    simp only [observedMemoryStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    have skipped := before_observed_memory_none env frame arena current false flags aux dst src value nextPc state
    change dispatchBitMemoryStep env frame arena current (GeneratedX86Opcode.code .andnMem) flags aux dst src value nextPc state = none at skipped
    rw [specializedObservedMemoryStep, if_pos rfl, dispatchObservedMemoryStep, skipped]
  · by_cases rotate : token = .btMemImm
    · subst token
      simp only [observedMemoryStepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
      subst opcode
      have skipped := before_observed_memory_none env frame arena current true flags aux dst src value nextPc state
      change dispatchBitMemoryStep env frame arena current (GeneratedX86Opcode.code .btMemImm) flags aux dst src value nextPc state = none at skipped
      rw [specializedObservedMemoryStep, if_neg (by decide), if_pos rfl, dispatchObservedMemoryStep, skipped]
    · have earlier : bitMemoryStepTokenOpcode token = some opcode := by
        simpa only [observedMemoryStepTokenOpcode, shift, rotate, ↓reduceIte] using selected
      obtain ⟨notShift, notRotate⟩ := earlier_token_excludes_observed_memory token opcode earlier
      simp only [specializedObservedMemoryStep, shift, rotate, ↓reduceIte]
      rw [bit_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
      unfold dispatchObservedMemoryStep
      cases dispatched : dispatchBitMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
        simp [dispatched, observedMemoryRegisters, notShift, notRotate]

theorem observed_memory_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : observedMemoryStepTokenOpcode token = some opcode)
    (binding : ObservedMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedObservedMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [observed_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact observed_memory_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem observed_memory_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : observedMemoryStepTokenOpcode token = some opcode)
    (binding : ObservedMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedObservedMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := observed_memory_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩

/-- The selected absolute-load argument includes its index; both generated
ordinary base forms then produce the same full native effective address. -/
theorem xmm_memory_ordinary_address_refines (store : Bool) (state : Reference.X86.State)
    (base index : Option Register) (aux : BitVec 32) (value : Reference.Word) :
    generatedX86Xmm0OrdinaryAddr (if store then .storeXmm0 else .loadXmm0) base.isNone
      (value + GeneratedX86MemOffset.value index.isSome
        ((GeneratedX86MemAux.scaleLog2 aux).setWidth 64) 0 ((index.map state.gpr).getD 0))
      ((base.map state.gpr).getD 0)
      (GeneratedX86MemOffset.value index.isSome
        ((GeneratedX86MemAux.scaleLog2 aux).setWidth 64) value ((index.map state.gpr).getD 0)) =
      leaAddress state base index aux value := by
  cases store <;> cases base <;> cases index <;>
    simp [generatedX86Xmm0OrdinaryAddr, generatedX86Xmm0BasePtr, generatedX86Xmm0AddsOffset,
      GeneratedX86Xmm0.baseForm, x86Xmm0ToOp, leaAddress, GeneratedX86MemOffset.value]

/-- Numeric observation of the actual selected generated base primitive.
Private-stack and physical-memory origins use the shared address interface. -/
def xmmMemoryAddressRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (store : Bool) (baseField : Byte)
    (aux : BitVec 32) (value : Reference.Word) : Option Reference.Word := do
  let base ← optionalRegisterOf baseField
  let index ← optionalRegisterOf ((GeneratedX86MemAux.index aux).setWidth 8)
  let native := nativeRegisters env frame arena state
  pure (generatedX86Xmm0OrdinaryAddr (if store then .storeXmm0 else .loadXmm0) base.isNone
    (value + GeneratedX86MemOffset.value index.isSome
      ((GeneratedX86MemAux.scaleLog2 aux).setWidth 64) 0 ((index.map native.gpr).getD 0))
    ((base.map native.gpr).getD 0)
    (GeneratedX86MemOffset.value index.isSome
      ((GeneratedX86MemAux.scaleLog2 aux).setWidth 64) value ((index.map native.gpr).getD 0)))

theorem xmm_memory_address_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (store : Bool) (baseField : Byte)
    (base index : Option Register) (aux : BitVec 32) (value : Reference.Word)
    (baseBinding : baseField = optionalRegisterByte base)
    (indexBinding : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index) :
    xmmMemoryAddressRegisters env frame arena state store baseField aux value =
      some (leaAddress (nativeRegisters env frame arena state) base index aux value) := by
  simp only [xmmMemoryAddressRegisters, baseBinding, indexBinding, optional_register_of_byte, Option.bind_some]
  exact congrArg some (xmm_memory_ordinary_address_refines store _ base index aux value)

/-- Fixed128-bit XMM0 memory bodies use the full displacement and the common
native optional-base/index/scale address. FLAGS and AUX width bytes leave the
vector width fixed; MOVAPS alignment belongs to the native field witness. -/
def xmmMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (_flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .loadXmm0 then do
    let address ← xmmMemoryAddressRegisters env frame arena state false src aux value
    pure (xmmMemoryFrame env frame arena state false address nextPc)
  else if code = GeneratedX86Opcode.code .storeXmm0 then do
    let address ← xmmMemoryAddressRegisters env frame arena state true dst aux value
    pure (xmmMemoryFrame env frame arena state true address nextPc)
  else none

inductive XmmMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | load (aligned : Bool) (base index : Option Register)
      (baseField : src = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index)
      (alignment : (aligned && leaAddress nativeState base index aux value &&& 15 != 0) = false)
      (permission : permitted nativeState.memory.readable (leaAddress nativeState base index aux value) 16 = true) :
      XmmMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .loadXmm0)
        (.xmm0Move false aligned (leaAddress nativeState base index aux value) nextPc)
  | store (aligned : Bool) (base index : Option Register)
      (baseField : dst = optionalRegisterByte base)
      (indexField : (GeneratedX86MemAux.index aux).setWidth 8 = optionalRegisterByte index)
      (alignment : (aligned && leaAddress nativeState base index aux value &&& 15 != 0) = false)
      (permission : permitted nativeState.memory.writable (leaAddress nativeState base index aux value) 16 = true) :
      XmmMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .storeXmm0)
        (.xmm0Move true aligned (leaAddress nativeState base index aux value) nextPc)

theorem xmm_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : XmmMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, xmmMemoryRegisters env frame arena code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | load aligned base index baseField indexField alignment permission =>
      refine ⟨_, ?_, xmm_memory_frame_step_refines env frame arena state false aligned
        (leaAddress (nativeRegisters env frame arena state) base index aux value) nextPc alignment permission⟩
      simp only [xmmMemoryRegisters, if_pos rfl, ↓reduceIte]
      rw [xmm_memory_address_registers_refine env frame arena state false src base index aux value baseField indexField]
      rfl
  | store aligned base index baseField indexField alignment permission =>
      refine ⟨_, ?_, xmm_memory_frame_step_refines env frame arena state true aligned
        (leaAddress (nativeRegisters env frame arena state) base index aux value) nextPc alignment permission⟩
      simp only [xmmMemoryRegisters, GeneratedX86Opcode.code, Nat.reduceEqDiff, ↓reduceIte]
      rw [xmm_memory_address_registers_refine env frame arena state true dst base index aux value baseField indexField]
      rfl

def dispatchXmmMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchObservedMemoryStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => xmmMemoryRegisters env frame arena code flags aux dst src value nextPc state

theorem before_xmm_memory_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (store : Bool) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchObservedMemoryStep env frame arena current (GeneratedX86Opcode.code (if store then .storeXmm0 else .loadXmm0))
      flags aux dst src value nextPc state = none := by
  cases store <;> rfl

theorem xmm_memory_binding_before_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : XmmMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    dispatchObservedMemoryStep env frame arena current code flags aux dst src value nextPc state = none := by
  cases binding
  · exact before_xmm_memory_none env frame arena current false flags aux dst src value nextPc state
  · exact before_xmm_memory_none env frame arena current true flags aux dst src value nextPc state

inductive XmmMemoryStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : ObservedMemoryStepBinding flags aux dst src value nextPc nativeState code native) :
      XmmMemoryStepBinding flags aux dst src value nextPc nativeState code native
  | memory (code : Nat) (native : Reference.X86.Instruction)
      (fields : XmmMemoryBinding flags aux dst src value nextPc nativeState code native) :
      XmmMemoryStepBinding flags aux dst src value nextPc nativeState code native

theorem xmm_memory_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : XmmMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchXmmMemoryStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := observed_memory_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchXmmMemoryStep, dispatched], refined⟩
  | memory fields =>
      obtain ⟨actual, dispatched, refined⟩ := xmm_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      exact ⟨actual, by rw [dispatchXmmMemoryStep,
        xmm_memory_binding_before_none env frame arena current code flags aux dst src value nextPc state native fields]; exact dispatched, refined⟩

/-- Both generic tokens retain the selected constant opcode and the complete
interpreter dispatch; earlier tokens keep their established body routes. -/
def specializedXmmMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .loadXmm0 then dispatchXmmMemoryStep env frame arena current (GeneratedX86Opcode.code .loadXmm0) flags aux dst src value nextPc state
  else if token = .storeXmm0 then dispatchXmmMemoryStep env frame arena current (GeneratedX86Opcode.code .storeXmm0) flags aux dst src value nextPc state
  else specializedObservedMemoryStep env frame arena current token flags aux dst src value nextPc state

def xmmMemoryStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .loadXmm0 then some .loadXmm0 else if token = .storeXmm0 then some .storeXmm0 else observedMemoryStepTokenOpcode token

theorem xmm_memory_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : xmmMemoryStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [xmmMemoryStepTokenOpcode, observedMemoryStepTokenOpcode, bitMemoryStepTokenOpcode, bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode,
    sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_xmm_memory (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : observedMemoryStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .loadXmm0 ∧
      GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .storeXmm0 := by
  cases token <;> simp only [observedMemoryStepTokenOpcode, bitMemoryStepTokenOpcode, bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode, sourceStepTokenOpcode,
    memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem xmm_memory_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : xmmMemoryStepTokenOpcode token = some opcode) :
    specializedXmmMemoryStep env frame arena current token flags aux dst src value nextPc state =
      dispatchXmmMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases load : token = .loadXmm0
  · subst token
    simp only [xmmMemoryStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    rfl
  · by_cases store : token = .storeXmm0
    · subst token
      simp only [xmmMemoryStepTokenOpcode, reduceCtorEq, ↓reduceIte, Option.some.injEq] at selected
      subst opcode
      rfl
    · have earlier : observedMemoryStepTokenOpcode token = some opcode := by
        simpa only [xmmMemoryStepTokenOpcode, load, store, ↓reduceIte] using selected
      obtain ⟨notLoad, notStore⟩ := earlier_token_excludes_xmm_memory token opcode earlier
      simp only [specializedXmmMemoryStep, load, store, ↓reduceIte]
      rw [observed_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
      unfold dispatchXmmMemoryStep
      cases dispatched : dispatchObservedMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
        simp [dispatched, xmmMemoryRegisters, notLoad, notStore]

theorem xmm_memory_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : xmmMemoryStepTokenOpcode token = some opcode)
    (binding : XmmMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedXmmMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [xmm_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact xmm_memory_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem xmm_memory_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : xmmMemoryStepTokenOpcode token = some opcode)
    (binding : XmmMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedXmmMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := xmm_memory_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩



/-- The REP opcode captures its immediate count and FLAGS width; the pointer
and memory frame commits the actual fixed64-loop body. -/
def repMemoryRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (_aux : BitVec 32) (_dst _src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .repMovs then do
    let width ← widthOf flags
    pure (repMemoryFrame env frame arena state width value.toNat nextPc)
  else none

inductive RepMemoryBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | copy (width : ScalarWidth) (widthField : WidthBinding flags width)
      (bound : value.toNat ≤ 64) (counter : nativeState.gpr 1 = value)
      (direction : nativeState.rflags.getLsbD 10 = false)
      (successful : (X86RepMovs.loop width nextPc value.toNat nativeState).fault = none) :
      RepMemoryBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .repMovs)
        (.repMovs width false 0 nextPc)

theorem rep_memory_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : RepMemoryBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, repMemoryRegisters env frame arena code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | copy width widthField bound counter direction successful =>
      refine ⟨_, ?_, rep_memory_frame_step_refines env frame arena state width value.toNat nextPc bound
        (by simpa using counter) direction successful⟩
      simp only [repMemoryRegisters, if_pos rfl, width_binding_decodes flags width widthField, Option.bind_some]
      rfl

def dispatchRepMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchXmmMemoryStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => repMemoryRegisters env frame arena code flags aux dst src value nextPc state

theorem before_rep_memory_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchXmmMemoryStep env frame arena current (GeneratedX86Opcode.code .repMovs) flags aux dst src value nextPc state = none := rfl

inductive RepMemoryStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : XmmMemoryStepBinding flags aux dst src value nextPc nativeState code native) :
      RepMemoryStepBinding flags aux dst src value nextPc nativeState code native
  | memory (code : Nat) (native : Reference.X86.Instruction)
      (fields : RepMemoryBinding flags aux dst src value nextPc nativeState code native) :
      RepMemoryStepBinding flags aux dst src value nextPc nativeState code native

theorem rep_memory_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : RepMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchRepMemoryStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := xmm_memory_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchRepMemoryStep, dispatched], refined⟩
  | memory fields =>
      obtain ⟨actual, dispatched, refined⟩ := rep_memory_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields
      exact ⟨actual, by rw [dispatchRepMemoryStep, before_rep_memory_none]; exact dispatched, refined⟩

/-- The generic REP token selects its fixed opcode through the complete
interpreter dispatcher; earlier tokens retain their established routes. -/
def specializedRepMemoryStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .repMovs then dispatchRepMemoryStep env frame arena current (GeneratedX86Opcode.code .repMovs) flags aux dst src value nextPc state
  else specializedXmmMemoryStep env frame arena current token flags aux dst src value nextPc state

def repMemoryStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .repMovs then some .repMovs else xmmMemoryStepTokenOpcode token

theorem rep_memory_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : repMemoryStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [repMemoryStepTokenOpcode, xmmMemoryStepTokenOpcode, observedMemoryStepTokenOpcode,
    bitMemoryStepTokenOpcode, bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode,
    sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_rep_memory (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : xmmMemoryStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .repMovs := by
  cases token <;> simp only [xmmMemoryStepTokenOpcode, observedMemoryStepTokenOpcode, bitMemoryStepTokenOpcode,
    bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode, sourceStepTokenOpcode,
    memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem rep_memory_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : repMemoryStepTokenOpcode token = some opcode) :
    specializedRepMemoryStep env frame arena current token flags aux dst src value nextPc state =
      dispatchRepMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases copy : token = .repMovs
  · subst token
    simp only [repMemoryStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    rfl
  · have earlier : xmmMemoryStepTokenOpcode token = some opcode := by
      simpa only [repMemoryStepTokenOpcode, copy, ↓reduceIte] using selected
    have different := earlier_token_excludes_rep_memory token opcode earlier
    simp only [specializedRepMemoryStep, copy, ↓reduceIte]
    rw [xmm_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
    unfold dispatchRepMemoryStep
    cases dispatched : dispatchXmmMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
      simp [dispatched, repMemoryRegisters, different]

theorem rep_memory_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : repMemoryStepTokenOpcode token = some opcode)
    (binding : RepMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedRepMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [rep_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact rep_memory_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem rep_memory_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : repMemoryStepTokenOpcode token = some opcode)
    (binding : RepMemoryStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedRepMemoryStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := rep_memory_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩

/-- CALL is a branch-emission token carrying its target and saved-return
words. The complete stack/register frame is shared with its interpreter arm. -/
def callLabelRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (_flags : Byte) (_aux : BitVec 32) (_dst _src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .call then some (callLabelFrame env frame arena state value nextPc) else none

inductive CallLabelBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | call (canonical : Reference.X86.canonicalTarget nativeState.addressWidth value = true)
      (writable : permitted nativeState.memory.writable (nativeState.gpr 4 - 8) 8 = true) :
      CallLabelBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .call)
        (.call (.immediate value) nextPc)

theorem call_label_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : CallLabelBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, callLabelRegisters env frame arena code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | call canonical writable =>
      exact ⟨_, by simp only [callLabelRegisters, if_pos rfl, ↓reduceIte],
        call_label_frame_step_refines env frame arena state value nextPc canonical writable⟩

def dispatchCallLabelStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchRepMemoryStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => callLabelRegisters env frame arena code flags aux dst src value nextPc state

theorem before_call_label_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchRepMemoryStep env frame arena current (GeneratedX86Opcode.code .call) flags aux dst src value nextPc state = none := rfl

inductive CallLabelStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : RepMemoryStepBinding flags aux dst src value nextPc nativeState code native) :
      CallLabelStepBinding flags aux dst src value nextPc nativeState code native
  | memory (code : Nat) (native : Reference.X86.Instruction)
      (fields : CallLabelBinding flags aux dst src value nextPc nativeState code native) :
      CallLabelStepBinding flags aux dst src value nextPc nativeState code native

theorem call_label_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : CallLabelStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchCallLabelStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := rep_memory_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchCallLabelStep, dispatched], refined⟩
  | memory fields =>
      obtain ⟨actual, dispatched, refined⟩ := call_label_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields
      exact ⟨actual, by rw [dispatchCallLabelStep, before_call_label_none]; exact dispatched, refined⟩

/-- The CALL branch token emits the same saved-word/target-label transfer.
Earlier tokens retain their established routes. -/
def specializedCallLabelStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .call then callLabelRegisters env frame arena (GeneratedX86Opcode.code .call) flags aux dst src value nextPc state
  else specializedRepMemoryStep env frame arena current token flags aux dst src value nextPc state

def callLabelStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .call then some .call else repMemoryStepTokenOpcode token

theorem call_label_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : callLabelStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [callLabelStepTokenOpcode, repMemoryStepTokenOpcode, xmmMemoryStepTokenOpcode, observedMemoryStepTokenOpcode,
    bitMemoryStepTokenOpcode, bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode,
    sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_call_label (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : repMemoryStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .call := by
  cases token <;> simp only [repMemoryStepTokenOpcode, xmmMemoryStepTokenOpcode, observedMemoryStepTokenOpcode, bitMemoryStepTokenOpcode,
    bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode, sourceStepTokenOpcode,
    memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem call_label_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : callLabelStepTokenOpcode token = some opcode) :
    specializedCallLabelStep env frame arena current token flags aux dst src value nextPc state =
      dispatchCallLabelStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases copy : token = .call
  · subst token
    simp only [callLabelStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    rw [specializedCallLabelStep, if_pos rfl, dispatchCallLabelStep, before_call_label_none]
  · have earlier : repMemoryStepTokenOpcode token = some opcode := by
      simpa only [callLabelStepTokenOpcode, copy, ↓reduceIte] using selected
    have different := earlier_token_excludes_call_label token opcode earlier
    simp only [specializedCallLabelStep, copy, ↓reduceIte]
    rw [rep_memory_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
    unfold dispatchCallLabelStep
    cases dispatched : dispatchRepMemoryStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
      simp [dispatched, callLabelRegisters, different]

theorem call_label_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : callLabelStepTokenOpcode token = some opcode)
    (binding : CallLabelStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedCallLabelStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [call_label_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact call_label_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem call_label_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : callLabelStepTokenOpcode token = some opcode)
    (binding : CallLabelStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedCallLabelStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := call_label_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩

/-- The subroutine RET emission samples the saved word, advances raw RSP
and selects its continuation label. The outer invocation exit retains its
separate low32 accumulator/context-copy relation. -/
def returnLabelRegisters (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (_flags : Byte) (_aux : BitVec 32) (_dst _src : Byte)
    (_value _nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  if code = GeneratedX86Opcode.code .ret then some (returnLabelFrame env frame arena state) else none

inductive ReturnLabelBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | ret (readable : permitted nativeState.memory.readable (nativeState.gpr 4) 8 = true)
      (canonical : Reference.X86.canonicalTarget nativeState.addressWidth
        (GeneratedX86MemAccess.load (fun i => nativeState.memory.value (nativeState.gpr 4 + BitVec.ofNat 64 i)) .w64) = true) :
      ReturnLabelBinding flags aux dst src value nextPc nativeState (GeneratedX86Opcode.code .ret)
        (.returnNear 0 nextPc)

theorem return_label_registers_refine (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ReturnLabelBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, returnLabelRegisters env frame arena code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | ret readable canonical =>
      exact ⟨_, by simp only [returnLabelRegisters, if_pos rfl, ↓reduceIte],
        return_label_frame_step_refines env frame arena state nextPc readable canonical⟩

def dispatchReturnLabelStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) : Option (Transition Reference.X86.State) :=
  match dispatchCallLabelStep env frame arena current code flags aux dst src value nextPc state with
  | some result => some result
  | none => returnLabelRegisters env frame arena code flags aux dst src value nextPc state

theorem before_return_label_none (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) :
    dispatchCallLabelStep env frame arena current (GeneratedX86Opcode.code .ret) flags aux dst src value nextPc state = none := rfl

inductive ReturnLabelStepBinding (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (nativeState : Reference.X86.State) : Nat → Reference.X86.Instruction → Prop where
  | earlier (code : Nat) (native : Reference.X86.Instruction)
      (fields : CallLabelStepBinding flags aux dst src value nextPc nativeState code native) :
      ReturnLabelStepBinding flags aux dst src value nextPc nativeState code native
  | memory (code : Nat) (native : Reference.X86.Instruction)
      (fields : ReturnLabelBinding flags aux dst src value nextPc nativeState code native) :
      ReturnLabelStepBinding flags aux dst src value nextPc nativeState code native

theorem return_label_simulator_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current code : Nat) (flags : Byte) (aux : BitVec 32) (dst src : Byte)
    (value nextPc : Reference.Word) (state : RegisterState) (native : Reference.X86.Instruction)
    (binding : ReturnLabelStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state) code native) :
    ∃ actual, dispatchReturnLabelStep env frame arena current code flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  cases binding with
  | earlier fields =>
      obtain ⟨actual, dispatched, refined⟩ := call_label_simulator_step_refines env frame arena current code flags aux dst src value nextPc state native fields
      exact ⟨actual, by simp only [dispatchReturnLabelStep, dispatched], refined⟩
  | memory fields =>
      obtain ⟨actual, dispatched, refined⟩ := return_label_registers_refine env frame arena code flags aux dst src value nextPc state native fields
      cases fields
      exact ⟨actual, by rw [dispatchReturnLabelStep, before_return_label_none]; exact dispatched, refined⟩

/-- This RET token interpretation covers the emitted SUB_RET branch.
The source emission relation selects this body for a subroutine return. -/
def specializedReturnLabelStep (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState) :
    Option (Transition Reference.X86.State) :=
  if token = .ret then returnLabelRegisters env frame arena (GeneratedX86Opcode.code .ret) flags aux dst src value nextPc state
  else specializedCallLabelStep env frame arena current token flags aux dst src value nextPc state

def returnLabelStepTokenOpcode (token : GeneratedX86Specialization.Op) : Option GeneratedX86Opcode.Op :=
  if token = .ret then some .ret else callLabelStepTokenOpcode token

theorem return_label_step_token_identity (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (selected : returnLabelStepTokenOpcode token = some opcode) :
    (GeneratedX86Specialization.dispatch token = .directMacro ∨
      GeneratedX86Specialization.dispatch token = .genericRunOp ∨
      GeneratedX86Specialization.dispatch token = .branchHandler) ∧
      GeneratedX86Specialization.tokenName token = GeneratedX86Opcode.define opcode := by
  cases token <;> simp only [returnLabelStepTokenOpcode, callLabelStepTokenOpcode, repMemoryStepTokenOpcode, xmmMemoryStepTokenOpcode, observedMemoryStepTokenOpcode,
    bitMemoryStepTokenOpcode, bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode,
    sourceStepTokenOpcode, memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

private theorem earlier_token_excludes_return_label (token : GeneratedX86Specialization.Op)
    (opcode : GeneratedX86Opcode.Op) (selected : callLabelStepTokenOpcode token = some opcode) :
    GeneratedX86Opcode.code opcode ≠ GeneratedX86Opcode.code .ret := by
  cases token <;> simp only [callLabelStepTokenOpcode, repMemoryStepTokenOpcode, xmmMemoryStepTokenOpcode, observedMemoryStepTokenOpcode, bitMemoryStepTokenOpcode,
    bmiMemoryStepTokenOpcode, loadStepTokenOpcode, imulStepTokenOpcode, sourceStepTokenOpcode,
    memoryStepTokenOpcode, stepTokenOpcode, registerTokenOpcode, directRegisterOpcode] at selected
  all_goals first | contradiction | cases selected
  all_goals decide

theorem return_label_step_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (selected : returnLabelStepTokenOpcode token = some opcode) :
    specializedReturnLabelStep env frame arena current token flags aux dst src value nextPc state =
      dispatchReturnLabelStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state := by
  by_cases copy : token = .ret
  · subst token
    simp only [returnLabelStepTokenOpcode, ↓reduceIte, Option.some.injEq] at selected
    subst opcode
    rw [specializedReturnLabelStep, if_pos rfl, dispatchReturnLabelStep, before_return_label_none]
  · have earlier : callLabelStepTokenOpcode token = some opcode := by
      simpa only [returnLabelStepTokenOpcode, copy, ↓reduceIte] using selected
    have different := earlier_token_excludes_return_label token opcode earlier
    simp only [specializedReturnLabelStep, copy, ↓reduceIte]
    rw [call_label_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state earlier]
    unfold dispatchReturnLabelStep
    cases dispatched : dispatchCallLabelStep env frame arena current (GeneratedX86Opcode.code opcode) flags aux dst src value nextPc state <;>
      simp [dispatched, returnLabelRegisters, different]

theorem return_label_simulator_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : returnLabelStepTokenOpcode token = some opcode)
    (binding : ReturnLabelStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) :
    ∃ actual, specializedReturnLabelStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step native (nativeRegisters env frame arena state) actual := by
  rw [return_label_step_token_body_matches env frame arena current token opcode flags aux dst src value nextPc state selected]
  exact return_label_simulator_step_refines env frame arena current _ flags aux dst src value nextPc state native binding

theorem return_label_simulator_token_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (token : GeneratedX86Specialization.Op) (opcode : GeneratedX86Opcode.Op)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) (state : RegisterState)
    (native : Reference.X86.Instruction) (selected : returnLabelStepTokenOpcode token = some opcode)
    (binding : ReturnLabelStepBinding flags aux dst src value nextPc (nativeRegisters env frame arena state)
      (GeneratedX86Opcode.code opcode) native) (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step native (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, specializedReturnLabelStep env frame arena current token flags aux dst src value nextPc state = some actual ∧
      Reference.X86.matchesTransition native nativeAfter actual := by
  obtain ⟨actual, dispatched, refined⟩ := return_label_simulator_token_step_refines env frame arena current token opcode
    flags aux dst src value nextPc state native selected binding
  exact ⟨actual, dispatched, successors_match native _ nativeAfter actual nativeStep refined⟩

/-- Source emission expands the finite continuation table into case/goto
arms. The saved word is sampled at the old stack offset; each selected arm
observes the same completed read/advance transfer. An exhausted table denotes
the source fallthrough, whose subsequent control retains a separate relation. -/
def generatedReturnSwitchBody (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) : List Reference.Word → Option (Transition Reference.X86.State)
  | [] => none
  | label :: rest =>
      if returnStackWord env frame arena state = label then
        some ⟨nativeRegisters env frame arena (registerPc (advanceStack state 8) label),
          returnStackReads env frame arena state, none⟩
      else generatedReturnSwitchBody env frame arena state rest

/-- Specialized SUB_RET loads once, advances RSP and uses its captured
continuation table. Membership describes the actual emitted case selection. -/
def specializedReturnSwitch (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (targets : List Reference.Word) :
    Option (Transition Reference.X86.State) :=
  if targets.contains (returnStackWord env frame arena state) then
    some (returnLabelFrame env frame arena state) else none

theorem return_switch_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (targets : List Reference.Word) :
    generatedReturnSwitchBody env frame arena state targets =
      specializedReturnSwitch env frame arena state targets := by
  induction targets with
  | nil => rfl
  | cons label rest ih =>
      by_cases selected : returnStackWord env frame arena state = label
      · simp [generatedReturnSwitchBody, specializedReturnSwitch, List.contains_cons,
          selected, returnLabelFrame]
      · simp only [generatedReturnSwitchBody, if_neg selected, ih]
        simp [specializedReturnSwitch, List.contains_cons, selected, Ne.symm selected]

theorem return_switch_selected (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (targets : List Reference.Word) :
    generatedReturnSwitchBody env frame arena state targets = some (returnLabelFrame env frame arena state) ↔
      targets.contains (returnStackWord env frame arena state) = true := by
  rw [return_switch_body_matches]
  simp only [specializedReturnSwitch]
  split <;> simp_all

theorem return_switch_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (targets : List Reference.Word) (nextPc : Reference.Word)
    (member : targets.contains (returnStackWord env frame arena state) = true)
    (readable : permitted state.raw.memory.readable (registerValue env frame arena state 4) 8 = true)
    (canonical : Reference.X86.canonicalTarget state.raw.addressWidth (returnStackWord env frame arena state) = true) :
    generatedReturnSwitchBody env frame arena state targets =
      some (Reference.X86.step (.returnNear 0 nextPc) (nativeRegisters env frame arena state)) := by
  rw [return_switch_body_matches]
  simp only [specializedReturnSwitch, member, ↓reduceIte]
  exact congrArg some (return_label_frame_refines env frame arena state nextPc readable canonical)

/-- The existing RET token body supplies this source-emitted finite switch.
All ignored fields and every table entry retain arbitrary values. -/
theorem return_switch_token_body_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (state : RegisterState) (targets : List Reference.Word)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word) :
    (if targets.contains (returnStackWord env frame arena state) then
      specializedReturnLabelStep env frame arena current .ret flags aux dst src value nextPc state else none) =
      generatedReturnSwitchBody env frame arena state targets := by
  rw [return_switch_body_matches]
  simp only [specializedReturnLabelStep, ↓reduceIte, returnLabelRegisters, ↓reduceIte,
    specializedReturnSwitch]

theorem return_switch_token_step_refines (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (current : Nat) (state : RegisterState) (targets : List Reference.Word)
    (flags : Byte) (aux : BitVec 32) (dst src : Byte) (value nextPc : Reference.Word)
    (member : targets.contains (returnStackWord env frame arena state) = true)
    (readable : permitted state.raw.memory.readable (registerValue env frame arena state 4) 8 = true)
    (canonical : Reference.X86.canonicalTarget state.raw.addressWidth (returnStackWord env frame arena state) = true) :
    ∃ actual, generatedReturnSwitchBody env frame arena state targets = some actual ∧
      specializedReturnLabelStep env frame arena current .ret flags aux dst src value nextPc state = some actual ∧
      Reference.X86.Step (.returnNear 0 nextPc) (nativeRegisters env frame arena state) actual := by
  refine ⟨returnLabelFrame env frame arena state, (return_switch_selected env frame arena state targets).2 member, ?_,
    return_label_frame_step_refines env frame arena state nextPc readable canonical⟩
  simp only [specializedReturnLabelStep, ↓reduceIte, returnLabelRegisters, ↓reduceIte]

theorem return_switch_native_matches (env : EntryEnvironment.Environment) (frame : EntryEnvironment.Frame)
    (arena : Reference.Word) (state : RegisterState) (targets : List Reference.Word) (nextPc : Reference.Word)
    (member : targets.contains (returnStackWord env frame arena state) = true)
    (readable : permitted state.raw.memory.readable (registerValue env frame arena state 4) 8 = true)
    (canonical : Reference.X86.canonicalTarget state.raw.addressWidth (returnStackWord env frame arena state) = true)
    (nativeAfter : Transition Reference.X86.State)
    (nativeStep : Reference.X86.Step (.returnNear 0 nextPc) (nativeRegisters env frame arena state) nativeAfter) :
    ∃ actual, generatedReturnSwitchBody env frame arena state targets = some actual ∧
      Reference.X86.matchesTransition (.returnNear 0 nextPc) nativeAfter actual := by
  refine ⟨returnLabelFrame env frame arena state, (return_switch_selected env frame arena state targets).2 member, ?_⟩
  exact successors_match _ _ nativeAfter _ nativeStep
    (return_label_frame_step_refines env frame arena state nextPc readable canonical)

end KProgFormal.Refinement.X86Dispatcher
