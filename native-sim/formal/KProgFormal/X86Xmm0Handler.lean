import KProgFormal.GeneratedX86Xmm0
import KProgFormal.X86MemAccess
import KProgFormal.X86MemOffset
import KProgFormal.X86StoreHandler
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Xmm0 (Arm BaseForm Direction DispForm Lane Op arm baseForm
  direction dispForm laneCount laneOffset)
open GeneratedX86MemAccess (byteCount)

/-- The XMM0 register pair the two handlers move: two 8-byte scalar lanes. The
pair is a plain scalar pair, not a tagged register value — neither body writes a
tag — and it is not a reversed or interleaved vector, so the two lanes are the
memory bytes at offsets `0` and `8` in order. -/
structure X86Xmm0Pair where
  lo : BitVec 64
  hi : BitVec 64
  deriving DecidableEq, Repr

/-- The two opcodes this contract spans: `X86_OP_LOAD_XMM0` (`0x30`) reads the
register pair from two consecutive 8-byte windows, `X86_OP_STORE_XMM0` (`0x31`)
writes it back to them. -/
inductive X86Xmm0Op
  | loadXmm0
  | storeXmm0
  deriving DecidableEq, Repr

/-- Whether the opcode is the store. The two opcodes are the two *directions* of
one pair move, and the direction is not a width: both move the same two 8-byte
lanes. -/
def x86Xmm0IsStore : X86Xmm0Op -> Bool
  | .loadXmm0 => false
  | .storeXmm0 => true

/-- Bridge from the handler's opcode type to the generated table's, so the
generated direction, displacement-form, base-form, and arm tables can be
indexed. -/
def x86Xmm0ToOp : X86Xmm0Op -> GeneratedX86Xmm0.Op
  | .loadXmm0 => .loadXmm0
  | .storeXmm0 => .storeXmm0

/-- Independent statement of each opcode's direction, written directly rather
than read from the generated table. -/
def x86Xmm0DirectionSpec : X86Xmm0Op -> Direction
  | .loadXmm0 => .load
  | .storeXmm0 => .store

/-- The generated direction table agrees with the independent statement for
both opcodes. -/
theorem x86_xmm0_direction_refines (op : X86Xmm0Op) :
    direction (x86Xmm0ToOp op) = x86Xmm0DirectionSpec op := by
  cases op <;> rfl

/-- The two opcodes move the pair in opposite directions, so neither row of the
direction table is dead. -/
theorem x86_xmm0_directions_differ :
    x86Xmm0DirectionSpec .loadXmm0 = Direction.load ∧
      x86Xmm0DirectionSpec .storeXmm0 = Direction.store ∧
      x86Xmm0DirectionSpec .loadXmm0 ≠ x86Xmm0DirectionSpec .storeXmm0 := by
  exact ⟨rfl, rfl, fun h => by cases h⟩

/-- Independent statement of the displacement both opcodes take from the
instruction-immediate artifact: the *whole* field, `x86_simm(IMM)`. On x86-64
the artifact is 64 bits, so `(s64)IMM` is the field itself. The immediate
store's high-half slice `(s32)(IMM >> 32)` is the plausible confusion, and the
contrast below pins it away. -/
def x86Xmm0DispSpec (imm : BitVec 64) : BitVec 64 := imm

/-- The displacement the generated form table selects, restated for the step
definitions. -/
def generatedX86Xmm0Disp (op : X86Xmm0Op) (imm : BitVec 64) : BitVec 64 :=
  match dispForm (x86Xmm0ToOp op) with
  | .immHighHalf => ((imm >>> 32).setWidth 32).signExtend 64
  | .signedImm => imm

/-- The displacement the generated form table selects equals the independent
whole-artifact statement, for both opcodes. -/
theorem generated_x86_xmm0_disp_refines (op : X86Xmm0Op) (imm : BitVec 64) :
    generatedX86Xmm0Disp op imm = x86Xmm0DispSpec imm := by
  cases op <;> rfl

/-- Both opcodes select the whole-artifact displacement form, and it is a
different slice of the field than the immediate store's high-half slice. -/
theorem x86_xmm0_disp_forms_whole :
    x86Xmm0DispSpec 0x8000001000000008 = 0x8000001000000008 ∧
      dispForm Op.loadXmm0 = DispForm.signedImm ∧
      dispForm Op.storeXmm0 = DispForm.signedImm ∧
      x86StoreDispSpec true 0x8000001000000008 = 0xffffffff80000010 := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- Independent statement of the arm selection, written as the one predicate
test both bodies' branch chains perform: whether the operand register is the
stack pointer. There is no opcode, width, or tag gate, and `X86_REG_NONE` is
not a third arm — it is an ordinary-arm base form. -/
def x86Xmm0ArmSpec (isRsp : Bool) : Arm :=
  if isRsp then .stackPair else .memoryPair

/-- The generated arm table equals the independent one-test nesting. -/
theorem x86_xmm0_arm_refines (isRsp : Bool) :
    arm isRsp = x86Xmm0ArmSpec isRsp := by
  cases isRsp <;> rfl

/-- The stack arm is exactly a stack-pointer operand: one selector, and no
other input can move either body off the process-memory path. -/
theorem x86_xmm0_arm_stack_iff (isRsp : Bool) :
    x86Xmm0ArmSpec isRsp = Arm.stackPair ↔ isRsp = true := by
  cases isRsp <;> simp [x86Xmm0ArmSpec]

/-- Both arms of the table are reachable: no dead entry. -/
theorem x86_xmm0_arm_all_reachable :
    x86Xmm0ArmSpec true = Arm.stackPair ∧
      x86Xmm0ArmSpec false = Arm.memoryPair := by
  exact ⟨rfl, rfl⟩

/-- Independent statement of the ordinary arm's base form: the load's operand
*is* the raw absolute immediate pointer, the store's operand is the null
pointer. The two opcodes take opposite forms. -/
def x86Xmm0BaseFormSpec : X86Xmm0Op -> BaseForm
  | .loadXmm0 => .absImmPtr
  | .storeXmm0 => .nullBasePlusDisp

/-- The generated base-form table agrees with the independent statement for
both opcodes. -/
theorem x86_xmm0_base_form_refines (op : X86Xmm0Op) :
    baseForm (x86Xmm0ToOp op) = x86Xmm0BaseFormSpec op := by
  cases op <;> rfl

/-- The two opcodes take *opposite* ordinary-arm base forms: if they ever
agreed, the two opcodes would share one addressing rule for `X86_REG_NONE`. -/
theorem x86_xmm0_base_forms_differ :
    x86Xmm0BaseFormSpec .loadXmm0 = BaseForm.absImmPtr ∧
      x86Xmm0BaseFormSpec .storeXmm0 = BaseForm.nullBasePlusDisp ∧
      x86Xmm0BaseFormSpec .loadXmm0 ≠ x86Xmm0BaseFormSpec .storeXmm0 := by
  exact ⟨rfl, rfl, fun h => by cases h⟩

/-- Independent statement of the ordinary arm's base pointer. For the load's
absolute-immediate form a `X86_REG_NONE` operand *is* the raw artifact; for the
store's null-base form it is the null pointer; either way a register operand
contributes the register's pointer value. -/
def x86Xmm0BasePtrSpec (op : X86Xmm0Op) (baseIsNone : Bool)
    (imm regPtr : BitVec 64) : BitVec 64 :=
  match x86Xmm0BaseFormSpec op with
  | .absImmPtr => if baseIsNone then imm else regPtr
  | .nullBasePlusDisp => if baseIsNone then 0 else regPtr

/-- Independent statement of whether the ordinary arm adds the addressing
offset to its base: the load's absolute-immediate form discards it for a
`X86_REG_NONE` operand, every other shape adds it. -/
def x86Xmm0AddsOffsetSpec (op : X86Xmm0Op) (baseIsNone : Bool) : Bool :=
  match x86Xmm0BaseFormSpec op with
  | .absImmPtr => !baseIsNone
  | .nullBasePlusDisp => true

/-- The generated base-pointer table's reading, restated for the step
definitions. -/
def generatedX86Xmm0BasePtr (op : X86Xmm0Op) (baseIsNone : Bool)
    (imm regPtr : BitVec 64) : BitVec 64 :=
  match baseForm (x86Xmm0ToOp op) with
  | .absImmPtr => if baseIsNone then imm else regPtr
  | .nullBasePlusDisp => if baseIsNone then 0 else regPtr

/-- The generated offset-adding test's reading, restated. -/
def generatedX86Xmm0AddsOffset (op : X86Xmm0Op) (baseIsNone : Bool) : Bool :=
  match baseForm (x86Xmm0ToOp op) with
  | .absImmPtr => !baseIsNone
  | .nullBasePlusDisp => true

/-- The generated base pointer equals the independent base-form statement. -/
theorem generated_x86_xmm0_base_ptr_refines (op : X86Xmm0Op)
    (baseIsNone : Bool) (imm regPtr : BitVec 64) :
    generatedX86Xmm0BasePtr op baseIsNone imm regPtr =
      x86Xmm0BasePtrSpec op baseIsNone imm regPtr := by
  cases op <;> cases baseIsNone <;> rfl

/-- The generated offset-adding test equals the independent base-form
statement. -/
theorem generated_x86_xmm0_adds_offset_refines (op : X86Xmm0Op)
    (baseIsNone : Bool) :
    generatedX86Xmm0AddsOffset op baseIsNone =
      x86Xmm0AddsOffsetSpec op baseIsNone := by
  cases op <;> cases baseIsNone <;> rfl

/-- Independent statement of the ordinary arm's effective address: the base
pointer plus the addressing offset, added only when the base form adds it. -/
def x86Xmm0OrdinaryAddrSpec (op : X86Xmm0Op) (baseIsNone : Bool)
    (imm regPtr offset : BitVec 64) : BitVec 64 :=
  x86Xmm0BasePtrSpec op baseIsNone imm regPtr +
    (if x86Xmm0AddsOffsetSpec op baseIsNone then offset else 0)

/-- The generated ordinary-arm address, restated for the step definitions. -/
def generatedX86Xmm0OrdinaryAddr (op : X86Xmm0Op) (baseIsNone : Bool)
    (imm regPtr offset : BitVec 64) : BitVec 64 :=
  generatedX86Xmm0BasePtr op baseIsNone imm regPtr +
    (if generatedX86Xmm0AddsOffset op baseIsNone then offset else 0)

/-- The generated ordinary-arm address equals the independent base-form and
offset-adding statements. -/
theorem generated_x86_xmm0_ordinary_addr_refines (op : X86Xmm0Op)
    (baseIsNone : Bool) (imm regPtr offset : BitVec 64) :
    generatedX86Xmm0OrdinaryAddr op baseIsNone imm regPtr offset =
      x86Xmm0OrdinaryAddrSpec op baseIsNone imm regPtr offset := by
  cases op <;> cases baseIsNone <;>
    simp only [generatedX86Xmm0OrdinaryAddr, x86Xmm0OrdinaryAddrSpec,
      generated_x86_xmm0_base_ptr_refines,
      generated_x86_xmm0_adds_offset_refines, x86Xmm0BasePtrSpec,
      x86Xmm0AddsOffsetSpec, x86Xmm0BaseFormSpec] <;>
    rfl

/-- **The base-form asymmetry, pinned as a difference.** For a `X86_REG_NONE`
operand the load's ordinary address *ignores* the addressing offset entirely —
it is the raw artifact, whatever the offset — whereas the store's is the offset
itself. This is the one fact that keeps the two opcodes from sharing an
addressing rule. -/
theorem x86_xmm0_ordinary_addr_load_ignores_offset
    (imm regPtr off off' : BitVec 64) :
    generatedX86Xmm0OrdinaryAddr .loadXmm0 true imm regPtr off =
      generatedX86Xmm0OrdinaryAddr .loadXmm0 true imm regPtr off' ∧
      x86Xmm0OrdinaryAddrSpec .loadXmm0 true imm regPtr off = imm := by
  constructor
  · simp [generatedX86Xmm0OrdinaryAddr, generatedX86Xmm0BasePtr,
      generatedX86Xmm0AddsOffset, GeneratedX86Xmm0.baseForm, x86Xmm0ToOp]
  · simp [x86Xmm0OrdinaryAddrSpec, x86Xmm0BasePtrSpec,
      x86Xmm0AddsOffsetSpec, x86Xmm0BaseFormSpec]

/-- For a `X86_REG_NONE` operand the store's ordinary address *is* the
addressing offset, so two different offsets give two different addresses. -/
theorem x86_xmm0_ordinary_addr_store_uses_offset
    (regPtr off off' : BitVec 64) (h : off ≠ off') :
    x86Xmm0OrdinaryAddrSpec .storeXmm0 true 0 regPtr off ≠
      x86Xmm0OrdinaryAddrSpec .storeXmm0 true 0 regPtr off' := by
  simpa [x86Xmm0OrdinaryAddrSpec, x86Xmm0BasePtrSpec, x86Xmm0AddsOffsetSpec,
    x86Xmm0BaseFormSpec] using h

/-- For a register operand both opcodes agree: the base form only decides what
a `X86_REG_NONE` operand means, and a register operand is the register's
pointer value plus the addressing offset either way. -/
theorem x86_xmm0_ordinary_addr_reg_base_agrees (op : X86Xmm0Op)
    (imm regPtr off : BitVec 64) :
    x86Xmm0OrdinaryAddrSpec op false imm regPtr off = regPtr + off ∧
      generatedX86Xmm0OrdinaryAddr op false imm regPtr off = regPtr + off := by
  cases op <;>
    simp [x86Xmm0OrdinaryAddrSpec, generatedX86Xmm0OrdinaryAddr,
      x86Xmm0BasePtrSpec, x86Xmm0AddsOffsetSpec, x86Xmm0BaseFormSpec,
      generatedX86Xmm0BasePtr, generatedX86Xmm0AddsOffset,
      GeneratedX86Xmm0.baseForm, x86Xmm0ToOp]

/-- Independent statement of the pair's lane layout: two lanes, the low at byte
offset 0 and the high exactly one lane width (`8` bytes) past it. -/
def x86Xmm0LaneOffsetSpec : Lane -> Nat
  | .lo => 0
  | .hi => 8

/-- The generated lane-offset table equals the independent statement. -/
theorem x86_xmm0_lane_offset_refines (lane : Lane) :
    laneOffset lane = x86Xmm0LaneOffsetSpec lane := by
  cases lane <;> rfl

/-- The pair carries exactly two lanes, and the lanes are consecutive: lane `hi`
sits exactly one lane width past lane `lo`, so the pair is two independent
little-endian windows rather than a reversed or interleaved vector. -/
theorem x86_xmm0_pair_layout :
    laneCount = 2 ∧
      laneOffset .lo = 0 ∧
      laneOffset .hi = laneOffset .lo + 8 ∧
      x86WidthBitsSpec .w64 / 8 = 8 := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- The little-endian byte update the store performs over the pair: the first
lane width's bytes are the low lane, the next lane width's bytes the high lane,
and every byte at or beyond the pair is left alone. -/
def x86Xmm0StoreBytes (byte : Nat -> X86MemByte) (pair : X86Xmm0Pair)
    (i : Nat) : X86MemByte :=
  if i < byteCount .w64 then
    GeneratedX86MemAccess.storeByte pair.lo .w64 i
  else if i < 2 * byteCount .w64 then
    GeneratedX86MemAccess.storeByte pair.hi .w64 (i - byteCount .w64)
  else byte i

/-- Independent statement of the same update: exactly `2 * 8` bytes are
replaced, by the independently specified little-endian decomposition of each
lane in order. -/
def x86Xmm0StoreBytesSpec (byte : Nat -> X86MemByte) (pair : X86Xmm0Pair)
    (i : Nat) : X86MemByte :=
  if i < x86WidthBitsSpec .w64 / 8 then
    x86MemStoreByteSpec pair.lo .w64 i
  else if i < 2 * (x86WidthBitsSpec .w64 / 8) then
    x86MemStoreByteSpec pair.hi .w64 (i - x86WidthBitsSpec .w64 / 8)
  else byte i

/-- The generated pair byte update equals the independent statement, pointwise. -/
theorem x86_xmm0_store_bytes_refines (byte : Nat -> X86MemByte)
    (pair : X86Xmm0Pair) (i : Nat) :
    x86Xmm0StoreBytes byte pair i = x86Xmm0StoreBytesSpec byte pair i := by
  simp only [x86Xmm0StoreBytes, x86Xmm0StoreBytesSpec, x86_mem_byte_count]
  by_cases h0 : i < x86WidthBitsSpec .w64 / 8
  · simp only [h0, ↓reduceIte]
    rw [x86_mem_store_byte_refines]
  · by_cases h1 : i < 2 * (x86WidthBitsSpec .w64 / 8)
    · simp only [h0, h1, ↓reduceIte]
      rw [x86_mem_store_byte_refines]
    · simp only [h0, h1, ↓reduceIte]

/-- The store leaves every byte past the pair untouched, so the two bodies write
exactly the pair's sixteen bytes and nothing else. -/
theorem x86_xmm0_store_bytes_above_pair_unchanged (byte : Nat -> X86MemByte)
    (pair : X86Xmm0Pair) (i : Nat) (h : 2 * (x86WidthBitsSpec .w64 / 8) ≤ i) :
    x86Xmm0StoreBytesSpec byte pair i = byte i := by
  have h0 : ¬ i < x86WidthBitsSpec .w64 / 8 := by omega
  have h1 : ¬ i < 2 * (x86WidthBitsSpec .w64 / 8) := Nat.not_lt.mpr h
  simp only [x86Xmm0StoreBytesSpec, if_neg h0, if_neg h1]

/-- The pair as a byte function: each lane's little-endian bytes, in order. -/
def x86Xmm0PairBytes (pair : X86Xmm0Pair) (i : Nat) : X86MemByte :=
  if i < x86WidthBitsSpec .w64 / 8 then
    x86MemStoreByteSpec pair.lo .w64 i
  else if i < 2 * (x86WidthBitsSpec .w64 / 8) then
    x86MemStoreByteSpec pair.hi .w64 (i - x86WidthBitsSpec .w64 / 8)
  else 0

/-- The load effect of the x86-64 `LOAD_XMM0` handler. `arm` records which of
the two buffers was read, `addr` records the effective address of the low lane
(the high lane is one lane width past it, and the stack arm's address is the
stack-relative offset the C stack helper is handed), and `pair` records the two
lanes read. -/
structure X86Xmm0LoadEffect where
  arm : Arm
  addr : BitVec 64
  pair : X86Xmm0Pair
  deriving DecidableEq, Repr

/-- Composition used by the x86-64 `LOAD_XMM0` handler after the opcode, the
base register's identity, the instruction-immediate artifact, and the
addressing mode have been decoded. The generated displacement form and the
generated effective-address contract compute the addressing offset, the arm —
one test of register identity — selects which byte function is read, and the
ordinary arm's base form decides whether a `X86_REG_NONE` operand contributes
the raw artifact (offset discarded) or a register pointer (offset added).

Both lanes are read at the hardcoded width 64: the low lane at the access
address, the high lane one lane width past it. There is no width resolution and
no reversal, so the pair is the two windows in order. -/
def generatedX86Xmm0LoadStep (isRsp baseIsNone : Bool) (op : X86Xmm0Op)
    (byte stackByte : Nat -> X86MemByte) (imm regPtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) : X86Xmm0LoadEffect :=
  let disp := generatedX86Xmm0Disp op imm
  let offset := GeneratedX86MemOffset.value hasIndex scale disp index
  if arm isRsp = Arm.stackPair then
    { arm := .stackPair, addr := regPtr + offset,
      pair := { lo := GeneratedX86MemAccess.load stackByte .w64,
                hi := GeneratedX86MemAccess.load
                  (fun i => stackByte (i + byteCount .w64)) .w64 } }
  else
    { arm := .memoryPair,
      addr := generatedX86Xmm0OrdinaryAddr op baseIsNone imm regPtr offset,
      pair := { lo := GeneratedX86MemAccess.load byte .w64,
                hi := GeneratedX86MemAccess.load
                  (fun i => byte (i + byteCount .w64)) .w64 } }

/-- Independent statement of the same handler: the displacement is the
independent whole-artifact statement, the effective address is the independent
base-form and offset statement, the arm is the independent one-test nesting,
and the lanes are the shared independent little-endian load statement at both
windows. -/
def x86Xmm0LoadStepSpec (isRsp baseIsNone : Bool) (op : X86Xmm0Op)
    (byte stackByte : Nat -> X86MemByte) (imm regPtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) : X86Xmm0LoadEffect :=
  let disp := x86Xmm0DispSpec imm
  let offset := GeneratedX86MemOffset.valueSpec hasIndex scale disp index
  if x86Xmm0ArmSpec isRsp = Arm.stackPair then
    { arm := .stackPair, addr := regPtr + offset,
      pair := { lo := x86MemLoadSpec stackByte .w64,
                hi := x86MemLoadSpec
                  (fun i => stackByte (i + x86WidthBitsSpec .w64 / 8)) .w64 } }
  else
    { arm := .memoryPair,
      addr := x86Xmm0OrdinaryAddrSpec op baseIsNone imm regPtr offset,
      pair := { lo := x86MemLoadSpec byte .w64,
                hi := x86MemLoadSpec
                  (fun i => byte (i + x86WidthBitsSpec .w64 / 8)) .w64 } }

/-- The `LOAD_XMM0` handler composition refines the independent
displacement/address/arm/load statement for arbitrary base identity, opcode,
memory and stack bytes, artifact, base pointer, and addressing mode. -/
theorem x86_xmm0_load_step_refines (isRsp baseIsNone : Bool)
    (op : X86Xmm0Op) (byte stackByte : Nat -> X86MemByte) (imm regPtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    generatedX86Xmm0LoadStep isRsp baseIsNone op byte stackByte imm regPtr
        hasIndex scale index =
      x86Xmm0LoadStepSpec isRsp baseIsNone op byte stackByte imm regPtr
        hasIndex scale index := by
  cases op <;> cases isRsp <;> cases baseIsNone <;>
    simp only [generatedX86Xmm0LoadStep, x86Xmm0LoadStepSpec,
      x86_xmm0_arm_refines, x86Xmm0ArmSpec, generated_x86_xmm0_disp_refines,
      x86Xmm0DispSpec, x86_mem_offset_refines, x86_mem_load_refines,
      x86_mem_byte_count, generated_x86_xmm0_ordinary_addr_refines,
      x86Xmm0OrdinaryAddrSpec, GeneratedX86Xmm0.arm,
      GeneratedX86Xmm0.dispForm, GeneratedX86Xmm0.baseForm, x86Xmm0ToOp,
      reduceCtorEq, ↓reduceIte]

/-- The store effect of the x86-64 `STORE_XMM0` handler. The store writes only
memory: it defines no flags, writes no register, and has no tag. `arm` records
which of the two buffers was written, `pair` records the lanes written, `addr`
records the effective address of the low lane, and `bytes` is the byte function
of the buffer that arm wrote. -/
structure X86Xmm0StoreEffect where
  arm : Arm
  addr : BitVec 64
  pair : X86Xmm0Pair
  bytes : Nat -> X86MemByte

/-- Composition used by the x86-64 `STORE_XMM0` handler. The generated
displacement form and effective-address contract compute the addressing offset,
the arm — one test of register identity — selects which byte function the pair
updates, and the ordinary arm's base form decides the `X86_REG_NONE` operand's
contribution.

Unlike the load, the store's ordinary arm always adds the addressing offset to
its base — a `X86_REG_NONE` destination contributes the null pointer, not the
raw artifact. Both lanes are written at the hardcoded width 64. -/
def generatedX86Xmm0StoreStep (isRsp baseIsNone : Bool) (op : X86Xmm0Op)
    (pair : X86Xmm0Pair) (byte stackByte : Nat -> X86MemByte)
    (imm regPtr : BitVec 64) (hasIndex : Bool)
    (scale index : BitVec 64) : X86Xmm0StoreEffect :=
  let disp := generatedX86Xmm0Disp op imm
  let offset := GeneratedX86MemOffset.value hasIndex scale disp index
  if arm isRsp = Arm.stackPair then
    { arm := .stackPair, addr := regPtr + offset, pair := pair,
      bytes := x86Xmm0StoreBytes stackByte pair }
  else
    { arm := .memoryPair,
      addr := generatedX86Xmm0OrdinaryAddr op baseIsNone imm regPtr offset,
      pair := pair, bytes := x86Xmm0StoreBytes byte pair }

/-- Independent statement of the same handler. -/
def x86Xmm0StoreStepSpec (isRsp baseIsNone : Bool) (op : X86Xmm0Op)
    (pair : X86Xmm0Pair) (byte stackByte : Nat -> X86MemByte)
    (imm regPtr : BitVec 64) (hasIndex : Bool)
    (scale index : BitVec 64) : X86Xmm0StoreEffect :=
  let disp := x86Xmm0DispSpec imm
  let offset := GeneratedX86MemOffset.valueSpec hasIndex scale disp index
  if x86Xmm0ArmSpec isRsp = Arm.stackPair then
    { arm := .stackPair, addr := regPtr + offset, pair := pair,
      bytes := x86Xmm0StoreBytesSpec stackByte pair }
  else
    { arm := .memoryPair,
      addr := x86Xmm0OrdinaryAddrSpec op baseIsNone imm regPtr offset,
      pair := pair, bytes := x86Xmm0StoreBytesSpec byte pair }

/-- The `STORE_XMM0` handler composition refines the independent
displacement/address/arm/update statement for arbitrary base identity, opcode,
register pair, memory and stack bytes, artifact, base pointer, and addressing
mode. -/
theorem x86_xmm0_store_step_refines (isRsp baseIsNone : Bool)
    (op : X86Xmm0Op) (pair : X86Xmm0Pair) (byte stackByte : Nat -> X86MemByte)
    (imm regPtr : BitVec 64) (hasIndex : Bool) (scale index : BitVec 64) :
    generatedX86Xmm0StoreStep isRsp baseIsNone op pair byte stackByte imm
        regPtr hasIndex scale index =
      x86Xmm0StoreStepSpec isRsp baseIsNone op pair byte stackByte imm
        regPtr hasIndex scale index := by
  cases op <;> cases isRsp <;> cases baseIsNone <;>
    simp only [generatedX86Xmm0StoreStep, x86Xmm0StoreStepSpec,
      x86_xmm0_arm_refines, x86Xmm0ArmSpec, generated_x86_xmm0_disp_refines,
      x86Xmm0DispSpec, x86_mem_offset_refines, x86_mem_byte_count,
      generated_x86_xmm0_ordinary_addr_refines, x86Xmm0OrdinaryAddrSpec,
      GeneratedX86Xmm0.arm, GeneratedX86Xmm0.dispForm,
      GeneratedX86Xmm0.baseForm, x86Xmm0ToOp, x86_xmm0_store_bytes_refines,
      reduceCtorEq, ↓reduceIte] <;>
    rfl

/-- The store's byte function is exactly the independently specified
little-endian decomposition of the pair it was handed, in both arms — no tag,
no reversed or interleaved layout, and no extra bytes. -/
theorem x86_xmm0_store_writes_pair (isRsp baseIsNone : Bool) (op : X86Xmm0Op)
    (pair : X86Xmm0Pair) (byte stackByte : Nat -> X86MemByte)
    (imm regPtr : BitVec 64) (hasIndex : Bool) (scale index : BitVec 64) :
    (∀ i, (x86Xmm0StoreStepSpec isRsp baseIsNone op pair byte stackByte imm
        regPtr hasIndex scale index).bytes i =
      x86Xmm0StoreBytesSpec
        (if isRsp then stackByte else byte) pair i) ∧
      (x86Xmm0StoreStepSpec isRsp baseIsNone op pair byte stackByte imm
        regPtr hasIndex scale index).pair = pair := by
  cases isRsp <;> cases baseIsNone <;> cases op <;>
    refine ⟨fun i => ?_, rfl⟩ <;>
    simp only [x86Xmm0StoreStepSpec, x86Xmm0ArmSpec, GeneratedX86Xmm0.arm,
      reduceCtorEq, ↓reduceIte] <;>
    rw [x86_xmm0_store_bytes_refines]

/-- The pair moves at the hardcoded width 64 — both lanes, both directions:
each lane's byte count is `8`, so no narrower width is resolved anywhere in
either body. -/
theorem x86_xmm0_lane_width_is_64 :
    byteCount .w64 = 8 ∧ x86WidthBitsSpec .w64 / 8 = 8 ∧
      x86WidthCodeSpec .w64 = 8 ∧ laneCount = 2 := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- A store of the pair then a load from the same bytes recovers both lanes: the
pair byte function the store writes is exactly what the load's two windows
assemble, so neither lane is reversed or interleaved. -/
theorem x86_xmm0_load_store_round_trip (pair : X86Xmm0Pair) :
    x86MemLoadSpec (fun i => x86Xmm0PairBytes pair i) .w64 = pair.lo ∧
      x86MemLoadSpec (fun i => x86Xmm0PairBytes pair (i + 8)) .w64 =
        pair.hi := by
  constructor <;>
    simp only [x86MemLoadSpec, x86MemAssembleSpec, x86MemStoreByteSpec,
      x86Xmm0PairBytes, x86WidthMaskSpec, x86WidthBitsSpec] <;>
    bv_decide

/-- Canonical example: a `X86_REG_NONE` load reads both lanes from the raw
artifact as the address, ignoring the addressing offset, and the pair is the two
windows in little-endian order with the low lane first. -/
theorem x86_xmm0_load_none_example :
    (generatedX86Xmm0LoadStep false true .loadXmm0
      (fun i => match i with
        | 0 => 0x11 | 1 => 0x22 | 2 => 0x33 | 3 => 0x44
        | 4 => 0x55 | 5 => 0x66 | 6 => 0x77 | 7 => 0x88
        | 8 => 0x01 | 9 => 0x02 | 10 => 0x03 | 11 => 0x04
        | 12 => 0x05 | 13 => 0x06 | 14 => 0x07 | 15 => 0x08
        | _ => 0xa5)
      (fun _ => 0x5a) 0x2000 0xdeadbeef false 0 0).pair =
      { lo := 0x8877665544332211, hi := 0x0807060504030201 } ∧
      (generatedX86Xmm0LoadStep false true .loadXmm0
        (fun _ => 0) (fun _ => 0) 0x2000 0xdeadbeef false 0 0).addr =
        0x2000 := by
  native_decide

/-- Canonical example: a stack-pointer load reads both lanes from the stack byte
function, one lane width apart, at the same width. -/
theorem x86_xmm0_load_stack_example :
    (generatedX86Xmm0LoadStep true false .loadXmm0
      (fun _ => 0xa5)
      (fun i => match i with
        | 0 => 0xaa | 1 => 0xbb | 2 => 0xcc | 3 => 0xdd
        | 4 => 0xee | 5 => 0xff | 6 => 0x00 | 7 => 0x11
        | 8 => 0x22 | 9 => 0x33 | _ => 0x44)
      0 0x1000000000000000 false 0 0).pair =
      { lo := 0x1100ffeeddccbbaa, hi := 0x4444444444443322 } ∧
      (generatedX86Xmm0LoadStep true false .loadXmm0
        (fun _ => 0xa5) (fun _ => 0xa5) 0 0x1000000000000000
        false 0 0).arm = Arm.stackPair := by
  native_decide

/-- Canonical example: a `X86_REG_NONE` store writes the pair to the addressing
offset itself (the null base plus the offset), not to the raw artifact. -/
theorem x86_xmm0_store_none_example :
    (generatedX86Xmm0StoreStep false true .storeXmm0
      { lo := 0x8877665544332211, hi := 0x0807060504030201 }
      (fun _ => 0xcc) (fun _ => 0x5a) 0x1234 0xdeadbeef false 0 0).addr =
        0x1234 ∧
      (generatedX86Xmm0StoreStep false true .storeXmm0
        { lo := 0x8877665544332211, hi := 0x0807060504030201 }
        (fun _ => 0xcc) (fun _ => 0x5a) 0x1234 0xdeadbeef false 0 0).bytes
        0 = 0x11 ∧
      (generatedX86Xmm0StoreStep false true .storeXmm0
        { lo := 0x8877665544332211, hi := 0x0807060504030201 }
        (fun _ => 0xcc) (fun _ => 0x5a) 0x1234 0xdeadbeef false 0 0).bytes
        8 = 0x01 := by
  native_decide

/-- Canonical example: a stack-pointer store writes both lanes to the stack byte
function, one lane width apart. -/
theorem x86_xmm0_store_stack_example :
    (generatedX86Xmm0StoreStep true false .storeXmm0
      { lo := 0x11, hi := 0x22 } (fun _ => 0x5a) (fun _ => 0x5a)
      0 0x100000008 false 0 0).arm = Arm.stackPair ∧
      (generatedX86Xmm0StoreStep true false .storeXmm0
        { lo := 0x11, hi := 0x22 } (fun _ => 0x5a) (fun _ => 0x5a)
        0 0x100000008 false 0 0).addr = 0x100000008 := by
  native_decide

/-- Canonical example: the two opcodes' ordinary arms differ for a
`X86_REG_NONE` operand with a nonzero offset — the load's address is the raw
artifact, the store's is the offset. -/
theorem x86_xmm0_base_form_asymmetry_example :
    generatedX86Xmm0OrdinaryAddr .loadXmm0 true 0x8000 0x1111 0x40 =
        0x8000 ∧
      generatedX86Xmm0OrdinaryAddr .storeXmm0 true 0x8000 0x1111 0x40 =
        0x40 := by
  native_decide

/-- Canonical example: with a register operand the two opcodes' ordinary arms
agree, both being the register pointer plus the offset. -/
theorem x86_xmm0_reg_base_agrees_example :
    generatedX86Xmm0OrdinaryAddr .loadXmm0 false 0x8000 0x1111 0x40 =
        0x1151 ∧
      generatedX86Xmm0OrdinaryAddr .storeXmm0 false 0x8000 0x1111 0x40 =
        0x1151 := by
  native_decide

end KProgFormal
