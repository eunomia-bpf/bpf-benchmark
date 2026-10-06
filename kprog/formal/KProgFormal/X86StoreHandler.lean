import KProgFormal.GeneratedX86Store
import KProgFormal.X86Immediate
import KProgFormal.X86MemAccess
import KProgFormal.X86MemOffset
import KProgFormal.X86ShiftCount
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Store (Arm Code DispForm ShiftSource ValueSource arm dispForm
  resolveWidth shiftSource valueSource)

/-- The two opcodes the shared `MOV_STORE` body implements:
`X86_OP_MOV_STORE_IMM` (`0x07`) and `X86_OP_MOV_STORE_REG` (`0x08`). -/
inductive X86StoreOp
  | movStoreImm
  | movStoreReg
  deriving DecidableEq, Repr

/-- Whether the store takes the instruction-immediate form. The immediate form
selects the high-half displacement slice, the width-aware immediate value, and
no AUX shift; the register form selects the whole-field displacement, the
register read at the full 64 bits, and the AUX source shift. -/
def x86StoreIsImm : X86StoreOp -> Bool
  | .movStoreImm => true
  | .movStoreReg => false

/-- Destination state of the x86-64 `MOV_STORE` handler
(`X86_SIM_L_EXEC_STORE`), the single body shared by `X86_OP_MOV_STORE_IMM` and
`X86_OP_MOV_STORE_REG`. The store writes only memory: it defines no flags,
writes no register, and has no ABI arm. `arm` records which of the two
destinations was written, `width` and `value` record what was written, `addr`
records the effective address the body computed (the base pointer plus the
addressing offset; for the stack arm the stack-relative offset the C stack
helper is handed), and `bytes` is the byte function of the buffer that arm
wrote — the addressed little-endian bytes of process memory for the memory arm,
the C stack helper's indexed frame bytes for the stack arm. -/
structure X86StoreEffect where
  arm : Arm
  width : X86Width
  value : BitVec 64
  addr : BitVec 64
  bytes : Nat -> X86MemByte

/-- Independent statement of the store width resolution: the opcode's `FLAGS`
code with a 64-bit fallback when it carries none. The store resolves exactly one
width, used for both the immediate value and the memory write, and the stack arm
re-derives the same `FLAGS ? FLAGS : 64` expression — unlike the shared read
body there is no second, AUX-sourced memory width. -/
def x86StoreWidthSpec (flags : Code) : Code :=
  if flags = Code.absent then Code.b64 else flags

/-- The generated width resolution equals the independent fallback statement. -/
theorem x86_store_width_refines (flags : Code) :
    resolveWidth flags = x86StoreWidthSpec flags := by
  cases flags <;> simp [resolveWidth, x86StoreWidthSpec]

/-- The resolved width can never be absent: the fallback is total, so the
handler has no unsupported width. -/
theorem x86_store_width_not_absent (flags : Code) :
    x86StoreWidthSpec flags ≠ Code.absent := by
  cases flags <;> simp [x86StoreWidthSpec]

/-- An opcode that carries no width resolves to 64 bits. -/
theorem x86_store_width_absent_defaults :
    x86StoreWidthSpec Code.absent = Code.b64 := by
  rfl

/-- Independent statement of the displacement form: the immediate store takes
the high half of the instruction-immediate artifact, the register store the
whole field. -/
def x86StoreDispFormSpec : Bool -> DispForm
  | true => .immHighHalf
  | false => .signedImm

theorem x86_store_disp_form_refines (isImm : Bool) :
    dispForm isImm = x86StoreDispFormSpec isImm := by
  cases isImm <;> rfl

/-- Independent statement of the value's source: the width-aware immediate rule,
or the register read at the full 64 bits. -/
def x86StoreValueSourceSpec : Bool -> ValueSource
  | true => .immediateWidth
  | false => .registerRead

theorem x86_store_value_source_refines (isImm : Bool) :
    valueSource isImm = x86StoreValueSourceSpec isImm := by
  cases isImm <;> rfl

/-- Independent statement of the AUX shift source: only the register store
consults the AUX source-shift field. -/
def x86StoreShiftSourceSpec : Bool -> ShiftSource
  | true => .zero
  | false => .auxSrcShift

theorem x86_store_shift_source_refines (isImm : Bool) :
    shiftSource isImm = x86StoreShiftSourceSpec isImm := by
  cases isImm <;> rfl

/-- Independent statement of the arm selection, written as the predicate nesting
the C `if/else` chain has: one test of register *identity*, with no opcode,
width, or tag gate — unlike the shared read body, whose ABI arm is gated on four
facts. -/
def x86StoreArmSpec (isRsp : Bool) : Arm :=
  if isRsp then .stackWrite else .memoryStore

theorem x86_store_arm_refines (isRsp : Bool) :
    arm isRsp = x86StoreArmSpec isRsp := by
  cases isRsp <;> rfl

/-- The stack arm is exactly the stack-pointer destination: one selector, and
no other input can move the store off the ordinary little-endian path. -/
theorem x86_store_arm_stack_iff (isRsp : Bool) :
    x86StoreArmSpec isRsp = Arm.stackWrite ↔ isRsp = true := by
  cases isRsp <;> simp [x86StoreArmSpec]

/-- Independent statement of the displacement the store uses. The immediate form
consumes the *high* 32 bits of the artifact, `(s32)(IMM >> 32)`, sign-extended
into the 64-bit displacement field; the register form takes the whole artifact
sign-extended, `(s64)IMM`. These are different slices of the same field, and
conflating them is the plausible bug of this handler. -/
def x86StoreDispSpec (isImm : Bool) (imm : BitVec 64) : BitVec 64 :=
  if isImm then ((imm >>> 32).setWidth 32).signExtend 64 else imm

/-- The displacement the generated form table selects, restated for the step
definition. -/
def generatedX86StoreDisp (isImm : Bool) (imm : BitVec 64) : BitVec 64 :=
  match dispForm isImm with
  | .immHighHalf => ((imm >>> 32).setWidth 32).signExtend 64
  | .signedImm => imm

/-- The displacement the generated form table selects equals the independent
two-slice statement. -/
theorem generated_x86_store_disp_refines (isImm : Bool) (imm : BitVec 64) :
    generatedX86StoreDisp isImm imm = x86StoreDispSpec isImm imm := by
  cases isImm <;> simp [generatedX86StoreDisp, x86StoreDispSpec,
    GeneratedX86Store.dispForm]

/-- Independent statement of the stored value's source. The immediate form takes
the width-aware `KPROG_X86_IMMEDIATE_VALUE` rule; the register form takes the
register read at the full 64 bits, regardless of the store width. -/
def x86StoreValueSpec (isImm : Bool) (imm srcValue : BitVec 64)
    (width : X86Width) : BitVec 64 :=
  if isImm then x86ImmediateValueSpec imm width else srcValue

/-- The value the generated source table selects, restated for the step
definition. -/
def generatedX86StoreValue (isImm : Bool) (imm srcValue : BitVec 64)
    (width : X86Width) : BitVec 64 :=
  match valueSource isImm with
  | .immediateWidth => GeneratedX86Immediate.value imm width
  | .registerRead => srcValue

/-- The value the generated source table selects equals the independent
statement: the immediate arm is the generated immediate rule, bridged to its
independent statement, and the register arm is the untouched register read. -/
theorem generated_x86_store_value_refines (isImm : Bool) (imm srcValue : BitVec 64)
    (width : X86Width) :
    generatedX86StoreValue isImm imm srcValue width =
      x86StoreValueSpec isImm imm srcValue width := by
  cases isImm <;>
    simp [generatedX86StoreValue, x86StoreValueSpec,
      GeneratedX86Store.valueSource, x86_immediate_value_refines]

/-- Independent statement of the AUX shift amount. The immediate store shifts by
nothing; the register store shifts its (already read) 64-bit source right by the
AUX source-shift byte, whose amount is taken modulo 64.

The modulo is not decoration: the C body's `>>=` shifts a `__u64` by a `__u8`
count, and on x86-64 the `shr` instruction takes the count modulo 64, so the
host oracle and this statement must fix that reading — BitVec's own `>>>`
instead *saturates* to zero for amounts at or above the word width, and the two
readings differ over the whole byte range 64..255. -/
def x86StoreShiftSpec (isImm : Bool) (srcShift : BitVec 64) : Nat :=
  if isImm then 0 else x86ShiftCountSpec srcShift .w64

/-- The shift the generated source table selects, restated for the step
definition. -/
def generatedX86StoreShift (isImm : Bool) (srcShift : BitVec 64) : Nat :=
  match shiftSource isImm with
  | .zero => 0
  | .auxSrcShift => (GeneratedX86ShiftCount.count srcShift .w64).toNat

/-- The shift the generated source table selects equals the independent
statement: the register arm is the generated shift-count contract, bridged to
its modulo statement. -/
theorem generated_x86_store_shift_refines (isImm : Bool) (srcShift : BitVec 64) :
    generatedX86StoreShift isImm srcShift = x86StoreShiftSpec isImm srcShift := by
  cases isImm
  case false =>
    simp [generatedX86StoreShift, x86StoreShiftSpec, GeneratedX86Store.shiftSource,
      GeneratedX86ShiftCount.count, GeneratedX86ShiftCount.mask, BitVec.toNat_and]
    exact Nat.and_two_pow_sub_one_eq_mod srcShift.toNat 6
  case true =>
    simp [generatedX86StoreShift, x86StoreShiftSpec, GeneratedX86Store.shiftSource]

/-- The immediate store never shifts, whatever the AUX source-shift byte holds. -/
theorem x86_store_imm_shift_is_zero (srcShift : BitVec 64) :
    x86StoreShiftSpec true srcShift = 0 := by
  rfl

/-- The register store's shift amount is the AUX source-shift byte modulo 64,
and so always a legal x86 shift count. -/
theorem x86_store_reg_shift_is_mod64 (srcShift : BitVec 64) :
    x86StoreShiftSpec false srcShift = srcShift.toNat % 64 ∧
      x86StoreShiftSpec false srcShift < 64 := by
  refine ⟨rfl, ?_⟩
  simp [x86StoreShiftSpec, x86ShiftCountSpec, Nat.mod_lt]

/-- The little-endian byte update both store arms perform: the width's low bytes
are replaced, every byte at or beyond the access width is left alone. -/
def x86StoreByteUpdate (byte : Nat -> X86MemByte) (width : X86Width)
    (value : BitVec 64) (i : Nat) : X86MemByte :=
  if i < GeneratedX86MemAccess.byteCount width then
    GeneratedX86MemAccess.storeByte value width i
  else byte i

/-- Independent statement of the same update: exactly `width / 8` bytes are
replaced, by the independently specified little-endian decomposition. -/
def x86StoreByteUpdateSpec (byte : Nat -> X86MemByte) (width : X86Width)
    (value : BitVec 64) (i : Nat) : X86MemByte :=
  if i < x86WidthBitsSpec width / 8 then
    x86MemStoreByteSpec value width i
  else byte i

theorem x86_store_byte_update_refines (byte : Nat -> X86MemByte)
    (width : X86Width) (value : BitVec 64) (i : Nat) :
    x86StoreByteUpdate byte width value i =
      x86StoreByteUpdateSpec byte width value i := by
  simp only [x86StoreByteUpdate, x86StoreByteUpdateSpec]
  rw [x86_mem_byte_count]
  by_cases h : i < x86WidthBitsSpec width / 8
  · simp only [h, ↓reduceIte]
    rw [x86_mem_store_byte_refines]
  · simp only [h, ↓reduceIte]

/-- Composition used by the x86-64 `MOV_STORE` handler after the opcode, the
resolved width, the destination register's identity, the register source and its
AUX shift field, the instruction-immediate artifact, and the addressing mode
have been decoded. The generated selector tables choose the displacement slice,
the value's source, the AUX shift source, and the arm; the displacement then
flows through the generated effective-address contract, and the arm selects
which byte function the width-masked value updates.

Two x86-specific asymmetries are worth naming. Only the register form consults
the AUX source-shift field, and it consults it *after* the register read, so the
immediate form is unaffected by any AUX byte; and the register source is read at
the full 64 bits even at a narrow store width, so a 32-bit store of a shifted
64-bit register value discards the shift's high half in the mask rather than in
the read. -/
def generatedX86StoreStep (op : X86StoreOp) (isRsp : Bool) (width : X86Width)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (imm srcValue srcShift basePtr : BitVec 64) (hasIndex : Bool)
    (scale index : BitVec 64) : X86StoreEffect :=
  let isImm := x86StoreIsImm op
  let disp := generatedX86StoreDisp isImm imm
  let offset := GeneratedX86MemOffset.value hasIndex scale disp index
  let value := generatedX86StoreValue isImm imm srcValue width
  let value := value >>> generatedX86StoreShift isImm srcShift
  let addr := basePtr + offset
  if arm isRsp = Arm.stackWrite then
    { arm := .stackWrite, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdate stackByte width value }
  else
    { arm := .memoryStore, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdate byte width value }

/-- Independent statement of the same handler: the selectors are the predicate
nestings, the displacement is the independent two-slice statement, the value is
the independent source statement (with the generated immediate rule replaced by
its independent statement), the shift is the independent modulo-64 statement,
the effective address is the independent offset table, the arm is the
independent one-test nesting, and the byte update is the independent
little-endian statement. -/
def x86StoreStepSpec (op : X86StoreOp) (isRsp : Bool) (width : X86Width)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (imm srcValue srcShift basePtr : BitVec 64) (hasIndex : Bool)
    (scale index : BitVec 64) : X86StoreEffect :=
  let isImm := x86StoreIsImm op
  let disp := x86StoreDispSpec isImm imm
  let offset := GeneratedX86MemOffset.valueSpec hasIndex scale disp index
  let value := x86StoreValueSpec isImm imm srcValue width
  let value := value >>> x86StoreShiftSpec isImm srcShift
  let addr := basePtr + offset
  if x86StoreArmSpec isRsp = Arm.stackWrite then
    { arm := .stackWrite, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdateSpec stackByte width value }
  else
    { arm := .memoryStore, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdateSpec byte width value }

/-- The generated selectors, displacement, value, shift, effective address, and
arm agree with the independent statements for arbitrary destination identity,
opcode, width, memory and stack bytes, artifact fields, base pointer, and
addressing mode: every non-byte field of the effect is identical on the two
sides. -/
theorem x86_store_step_fields_refines (op : X86StoreOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue srcShift basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).arm =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).arm ∧
      (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).width =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).width ∧
      (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).value =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).value ∧
      (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).addr =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).addr := by
  cases op <;> cases isRsp <;>
    simp only [generatedX86StoreStep, x86StoreStepSpec, x86StoreIsImm,
      x86_store_arm_refines, x86StoreArmSpec, generated_x86_store_disp_refines,
      generated_x86_store_value_refines, generated_x86_store_shift_refines,
      x86StoreDispSpec, x86StoreValueSpec, x86StoreShiftSpec,
      x86_mem_offset_refines, GeneratedX86Store.arm, reduceCtorEq, ↓reduceIte, true_and]

/-- The observed memory bytes refine the independent little-endian statement
pointwise, for every arm. -/
theorem x86_store_step_bytes_refines (op : X86StoreOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue srcShift basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) (i : Nat) :
    (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).bytes i =
      (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).bytes i := by
  cases op <;> cases isRsp <;>
    simp only [generatedX86StoreStep, x86StoreStepSpec, x86StoreIsImm,
      x86_store_arm_refines, x86StoreArmSpec, generated_x86_store_disp_refines,
      generated_x86_store_value_refines, generated_x86_store_shift_refines,
      x86StoreDispSpec, x86StoreValueSpec, x86StoreShiftSpec,
      x86_mem_offset_refines, GeneratedX86Store.arm, reduceCtorEq, ↓reduceIte, true_and]
  all_goals exact x86_store_byte_update_refines _ width _ i

/-- The `MOV_STORE` handler composition refines the independent
selector/width/form/source/shift/offset/arm/store statement for arbitrary
destination identity, opcode, width, memory and stack bytes, artifact fields,
base pointer, and addressing mode. -/
theorem x86_store_step_refines (op : X86StoreOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue srcShift basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).arm =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).arm ∧
      (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).width =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).width ∧
      (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).value =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).value ∧
      (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
        basePtr hasIndex scale index).addr =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).addr ∧
      ∀ i, (generatedX86StoreStep op isRsp width byte stackByte imm srcValue
          srcShift basePtr hasIndex scale index).bytes i =
        (x86StoreStepSpec op isRsp width byte stackByte imm srcValue srcShift
          basePtr hasIndex scale index).bytes i := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩
  · exact (x86_store_step_fields_refines op isRsp width byte stackByte imm
      srcValue srcShift basePtr hasIndex scale index).1
  · exact (x86_store_step_fields_refines op isRsp width byte stackByte imm
      srcValue srcShift basePtr hasIndex scale index).2.1
  · exact (x86_store_step_fields_refines op isRsp width byte stackByte imm
      srcValue srcShift basePtr hasIndex scale index).2.2.1
  · exact (x86_store_step_fields_refines op isRsp width byte stackByte imm
      srcValue srcShift basePtr hasIndex scale index).2.2.2
  · intro i
    exact x86_store_step_bytes_refines op isRsp width byte stackByte imm
      srcValue srcShift basePtr hasIndex scale index i

/-- Both arms write at the handler's single resolved width: the stack arm's
`X86_SIM_L_EFFECTIVE_WIDTH(FLAGS)` and the memory arm's own `width` are the same
expression, so no store can write a different number of bytes than its own value
was narrowed to. -/
theorem x86_store_both_arms_use_one_width (op : X86StoreOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue srcShift basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86StoreStep op isRsp width byte stackByte imm srcValue srcShift
      basePtr hasIndex scale index).width = width := by
  cases isRsp <;> rfl

/-- A store leaves every byte at or beyond the access width untouched, in either
arm: the update is confined to the little-endian span the width masks. -/
theorem x86_store_bytes_above_width_unchanged (byte : Nat -> X86MemByte)
    (width : X86Width) (value : BitVec 64) (i : Nat)
    (h : x86WidthBitsSpec width / 8 ≤ i) :
    x86StoreByteUpdateSpec byte width value i = byte i := by
  simp only [x86StoreByteUpdateSpec, Nat.not_lt.mpr h, ↓reduceIte]

/-- The immediate store's displacement is the artifact's high half sign-extended,
while the register store's is the whole artifact: the same field yields different
displacements, which is what keeps the two opcodes from being unifiable. -/
theorem x86_store_disp_forms_differ :
    x86StoreDispSpec true 0x8000001000000008 = 0xffffffff80000010 ∧
      x86StoreDispSpec false 0x8000001000000008 = 0x8000001000000008 := by
  decide

/-- The immediate store's value is the width-aware low-32-bit rule, so at width
64 the sign bit of the artifact's low half is extended; the register store's
value is the register read unchanged at every width. -/
theorem x86_store_value_sources_differ :
    x86StoreValueSpec true 0x0000000080000001 0xdeadbeefdeadbeef .w64 =
        0xffffffff80000001 ∧
      x86StoreValueSpec false 0x0000000080000001 0xdeadbeefdeadbeef .w64 =
        0xdeadbeefdeadbeef ∧
      x86StoreValueSpec false 0x0000000080000001 0xdeadbeefdeadbeef .w16 =
        0xdeadbeefdeadbeef := by
  decide

/-- Canonical example: an immediate 16-bit store writes the artifact's low half
sign-extended and width-masked, little-endian into the addressed bytes, and
leaves the third byte alone. -/
theorem x86_store_imm_w16_example :
    let old : Nat -> X86MemByte := fun i => 0xa5 + (i : X86MemByte)
    (generatedX86StoreStep .movStoreImm false .w16
        old (fun _ => 0x5a) 0x0000000012348001 0x1111111111111111
        0x00 0x4000 false 0 7).value = 0x12348001 ∧
      (generatedX86StoreStep .movStoreImm false .w16
        old (fun _ => 0x5a) 0x0000000012348001 0x1111111111111111
        0x00 0x4000 false 0 7).bytes 0 = 0x01 ∧
      (generatedX86StoreStep .movStoreImm false .w16
        old (fun _ => 0x5a) 0x0000000012348001 0x1111111111111111
        0x00 0x4000 false 0 7).bytes 1 = 0x80 ∧
      (generatedX86StoreStep .movStoreImm false .w16
        old (fun _ => 0x5a) 0x0000000012348001 0x1111111111111111
        0x00 0x4000 false 0 7).bytes 2 = old 2 ∧
      (generatedX86StoreStep .movStoreImm false .w16
        old (fun _ => 0x5a) 0x0000000012348001 0x1111111111111111
        0x00 0x4000 false 0 7).addr = 0x4000 := by
  decide

/-- Canonical example: a register store shifts its 64-bit source right by the
AUX source-shift byte and then masks into the narrow access width, while an
immediate store of the same AUX field shifts by nothing — the AUX shift is read
only on the register form. -/
theorem x86_store_reg_shift_example :
    (generatedX86StoreStep .movStoreReg false .w32
      (fun _ => 0xa5) (fun _ => 0x5a) 0x1234001000000008 0x00000000abcd1234
      0x08 0x2000 false 0 0).value = 0xabcd12 ∧
      (generatedX86StoreStep .movStoreImm false .w32
        (fun _ => 0xa5) (fun _ => 0x5a) 0x0000000010000008 0x00000000abcd1234
        0x08 0x2000 false 0 0).value = 0x10000008 := by
  decide

/-- Canonical example: a stack-pointer destination takes the stack arm and
writes the stack frame, at the same width and with the same value as the memory
arm would have written, leaving the byte past the access width alone. -/
theorem x86_store_stack_arm_example :
    (generatedX86StoreStep .movStoreImm true .w8
        (fun _ => 0x11) (fun i => 0xa5 + (i : X86MemByte)) 0x0000000012340011
        0 0 0x20 false 0 0).arm = Arm.stackWrite ∧
      (generatedX86StoreStep .movStoreImm true .w8
        (fun _ => 0x11) (fun i => 0xa5 + (i : X86MemByte)) 0x0000000012340011
        0 0 0x20 false 0 0).bytes 0 = 0x11 ∧
      (generatedX86StoreStep .movStoreImm true .w8
        (fun _ => 0x11) (fun i => 0xa5 + (i : X86MemByte)) 0x0000000012340011
        0 0 0x20 false 0 0).bytes 1 = 0xa6 := by
  decide

end KProgFormal
