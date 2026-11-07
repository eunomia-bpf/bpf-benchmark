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

end KProgFormal.Refinement.X86Dispatcher
