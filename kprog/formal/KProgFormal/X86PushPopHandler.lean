import KProgFormal.Generated.GeneratedX86PushPop
import KProgFormal.TagErasure
import KProgFormal.X86MemAccess
import KProgFormal.X86RegWrite
import KProgFormal.X86StoreHandler
import KProgFormal.X86Width
import KProgFormal.Reference.X86
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86PushPop (FlagsWidth Op StepDirection WidthSource flagsWidth
  resolveWidth stackStep stepDirection widthSource)
open GeneratedX86Store (Code)

/-- The two stack-transfer opcodes this contract spans: `X86_OP_PUSH` (`0x12`)
and `X86_OP_POP` (`0x13`). -/
inductive X86PushPopOp
  | push
  | pop
  deriving DecidableEq, Repr

/-- Bridge from the handler's opcode type to the generated table's, so the
generated step-direction and width-source tables can be indexed. -/
def x86PushPopToOp : X86PushPopOp -> GeneratedX86PushPop.Op
  | .push => .push
  | .pop => .pop

/-- Independent statement of the step direction each body takes: `PUSH`
decrements the stack pointer before its store, `POP` increments it after its
load and destination write. -/
def x86PushPopStepDirectionSpec : X86PushPopOp -> StepDirection
  | .push => .preDecrement
  | .pop => .postIncrement

/-- The generated step-direction table agrees with the independent statement. -/
theorem x86_push_pop_step_direction_refines (op : X86PushPopOp) :
    stepDirection (x86PushPopToOp op) = x86PushPopStepDirectionSpec op := by
  cases op <;> rfl

/-- Both bodies resolve FLAGS, defaulting an absent code to64 bits. -/
def x86PushPopWidthSourceSpec : X86PushPopOp -> WidthSource
  | .push => .flagsOr64
  | .pop => .flagsOr64

/-- The generated width-source table agrees with the independent statement. -/
theorem x86_push_pop_width_source_refines (op : X86PushPopOp) :
    widthSource (x86PushPopToOp op) = x86PushPopWidthSourceSpec op := by
  cases op <;> rfl

/-- Direction differs, while both operations share the operand-width rule. -/
theorem x86_push_pop_facts :
    x86PushPopStepDirectionSpec .push = StepDirection.preDecrement ∧
      x86PushPopWidthSourceSpec .push = WidthSource.flagsOr64 ∧
      x86PushPopStepDirectionSpec .pop = StepDirection.postIncrement ∧
      x86PushPopWidthSourceSpec .pop = WidthSource.flagsOr64 ∧
      x86PushPopStepDirectionSpec .push ≠ x86PushPopStepDirectionSpec .pop ∧
      x86PushPopWidthSourceSpec .push = x86PushPopWidthSourceSpec .pop := by
  exact ⟨rfl, rfl, rfl, rfl,
    fun h => StepDirection.noConfusion h,
    rfl⟩

/-- An opcode's `FLAGS` code is `resolved` unless it carries none. -/
theorem x86_push_pop_flags_width_absent_iff (flags : Code) :
    flagsWidth flags = FlagsWidth.absent ↔ flags = Code.absent := by
  cases flags <;> simp [flagsWidth]

/-- Default64-bit transfer size; narrower operations use x86PushPopBytesSpec. -/
def x86PushPopStepAmountSpec : Nat := 8

/-- The generated stack-step literal equals the independent one. -/
theorem x86_push_pop_step_amount_refines :
    stackStep = x86PushPopStepAmountSpec := by
  rfl

/-- The default64-bit step amount is eight bytes. -/
theorem x86_push_pop_step_amount_is_eight :
    x86PushPopStepAmountSpec = 8 := by
  rfl

/-- The resolved FLAGS width used by both bodies. -/
def x86PushPopWidthCodeSpec (op : X86PushPopOp) (flags : Code) : Code :=
  match x86PushPopWidthSourceSpec op with
  | .flagsOr64 => resolveWidth flags

/-- Resolved transfer width shared by the byte update, load and writeback. -/
def x86PushPopWidthSpec (op : X86PushPopOp) (flags : Code) : X86Width :=
  match x86PushPopWidthSourceSpec op with
  | .flagsOr64 =>
      match flags with
      | .absent => .w64
      | .b8 => .w8
      | .b16 => .w16
      | .b32 => .w32
      | .b64 => .w64

/-- The width code the generated tables select, restated for the step
definitions. -/
def generatedX86PushPopWidthCode (op : X86PushPopOp) (flags : Code) : Code :=
  match widthSource (x86PushPopToOp op) with
  | .flagsOr64 => resolveWidth flags

/-- The width the generated tables select, restated for the step
definitions. -/
def generatedX86PushPopWidth (op : X86PushPopOp) (flags : Code) : X86Width :=
  match generatedX86PushPopWidthCode op flags with
  | .absent => .w64
  | .b8 => .w8
  | .b16 => .w16
  | .b32 => .w32
  | .b64 => .w64

/-- The generated width equals the independent statement, for every opcode and
`FLAGS` code. -/
theorem x86_push_pop_width_refines (op : X86PushPopOp) (flags : Code) :
    generatedX86PushPopWidth op flags = x86PushPopWidthSpec op flags := by
  cases op <;> cases flags <;> rfl

/-- PUSH honors the same FLAGS width as POP. The former claim that PUSH
ignored FLAGS was a simulator bug; both operations now resolve it identically. -/
theorem x86_push_pop_push_ignores_flags (flags : Code) :
    x86PushPopWidthSpec .push flags = x86PushPopWidthSpec .pop flags := by rfl

/-- `POP` with an absent `FLAGS` code defaults to 64 bits. -/
theorem x86_push_pop_pop_absent_defaults :
    x86PushPopWidthSpec .pop .absent = .w64 := by
  rfl

/-- The actual operand byte count determines the transfer and RSP step. -/
def x86PushPopBytesSpec (width : X86Width) : Nat := x86WidthBitsSpec width / 8

theorem x86_push_pop_push_byte_count (flags : Code) :
    GeneratedX86PushPop.stepBytes flags =
      x86PushPopBytesSpec (x86PushPopWidthSpec .push flags) := by
  cases flags <;> rfl

def generatedX86PushPopAccessAt (op : X86PushPopOp) (rsp : BitVec 64) (flags : Code) : BitVec 64 :=
  match stepDirection (x86PushPopToOp op) with
  | .preDecrement => rsp - BitVec.ofNat 64 (GeneratedX86PushPop.stepBytes flags)
  | .postIncrement => rsp

def x86PushPopAccessAtSpec (op : X86PushPopOp) (rsp : BitVec 64) (width : X86Width) : BitVec 64 :=
  match x86PushPopStepDirectionSpec op with
  | .preDecrement => rsp - BitVec.ofNat 64 (x86PushPopBytesSpec width)
  | .postIncrement => rsp

def generatedX86PushPopRspAt (op : X86PushPopOp) (rsp : BitVec 64) (flags : Code) : BitVec 64 :=
  match stepDirection (x86PushPopToOp op) with
  | .preDecrement => rsp - BitVec.ofNat 64 (GeneratedX86PushPop.stepBytes flags)
  | .postIncrement => rsp + BitVec.ofNat 64 (GeneratedX86PushPop.stepBytes flags)

def x86PushPopRspAtSpec (op : X86PushPopOp) (rsp : BitVec 64) (width : X86Width) : BitVec 64 :=
  match x86PushPopStepDirectionSpec op with
  | .preDecrement => rsp - BitVec.ofNat 64 (x86PushPopBytesSpec width)
  | .postIncrement => rsp + BitVec.ofNat 64 (x86PushPopBytesSpec width)

/-- The stack address the body's single memory access uses: `PUSH`'s store goes
to the decremented pointer, `POP`'s load reads the pointer itself. -/
def generatedX86PushPopAccessAddr (op : X86PushPopOp) (rsp : BitVec 64) :
    BitVec 64 :=
  match stepDirection (x86PushPopToOp op) with
  | .preDecrement => rsp - BitVec.ofNat 64 stackStep
  | .postIncrement => rsp

/-- Independent statement of the access address. -/
def x86PushPopAccessAddrSpec (op : X86PushPopOp) (rsp : BitVec 64) :
    BitVec 64 :=
  match x86PushPopStepDirectionSpec op with
  | .preDecrement => rsp - BitVec.ofNat 64 x86PushPopStepAmountSpec
  | .postIncrement => rsp

/-- The generated access address equals the independent statement. -/
theorem x86_push_pop_access_addr_refines (op : X86PushPopOp) (rsp : BitVec 64) :
    generatedX86PushPopAccessAddr op rsp = x86PushPopAccessAddrSpec op rsp := by
  cases op <;>
    simp only [generatedX86PushPopAccessAddr, x86PushPopAccessAddrSpec,
      stepDirection, x86PushPopToOp, x86PushPopStepDirectionSpec,
      x86PushPopStepAmountSpec, stackStep]

/-- The stack pointer both bodies leave behind: the decremented pointer for
`PUSH`, the incremented pointer for `POP`. -/
def generatedX86PushPopRspAfter (op : X86PushPopOp) (rsp : BitVec 64) :
    BitVec 64 :=
  match stepDirection (x86PushPopToOp op) with
  | .preDecrement => rsp - BitVec.ofNat 64 stackStep
  | .postIncrement => rsp + BitVec.ofNat 64 stackStep

/-- Independent statement of the stack pointer after the body. -/
def x86PushPopRspAfterSpec (op : X86PushPopOp) (rsp : BitVec 64) : BitVec 64 :=
  match x86PushPopStepDirectionSpec op with
  | .preDecrement => rsp - BitVec.ofNat 64 x86PushPopStepAmountSpec
  | .postIncrement => rsp + BitVec.ofNat 64 x86PushPopStepAmountSpec

/-- The generated stack-pointer update equals the independent statement. -/
theorem x86_push_pop_rsp_after_refines (op : X86PushPopOp) (rsp : BitVec 64) :
    generatedX86PushPopRspAfter op rsp = x86PushPopRspAfterSpec op rsp := by
  cases op <;>
    simp only [generatedX86PushPopRspAfter, x86PushPopRspAfterSpec,
      stepDirection, x86PushPopToOp, x86PushPopStepDirectionSpec,
      x86PushPopStepAmountSpec, stackStep]

/-- `PUSH` pre-decrements the stack pointer before its store and leaves it
decremented; `POP` reads and writes at the incoming pointer and post-increments
it. The two directions are inverses, so a real push/pop pair is a no-op on the
pointer — the two bodies never both move the pointer the same way. -/
theorem x86_push_pop_rsp_round_trip (rsp : BitVec 64) :
    x86PushPopRspAfterSpec .pop (x86PushPopRspAfterSpec .push rsp) = rsp := by
  simp [x86PushPopRspAfterSpec, x86PushPopStepDirectionSpec,
    x86PushPopStepAmountSpec, BitVec.sub_add_cancel]

/-- `PUSH`'s store addresses the decremented pointer, so the pointer it leaves
behind is exactly the address it wrote. -/
theorem x86_push_pop_push_addr_is_new_rsp (rsp : BitVec 64) :
    x86PushPopAccessAddrSpec .push rsp =
      x86PushPopRspAfterSpec .push rsp := by
  rfl

/-- `POP`'s load addresses the incoming pointer while the pointer it leaves
behind is that address plus the step. -/
theorem x86_push_pop_pop_addr_is_old_rsp (rsp : BitVec 64) :
    x86PushPopAccessAddrSpec .pop rsp = rsp ∧
      x86PushPopRspAfterSpec .pop rsp =
        rsp + BitVec.ofNat 64 x86PushPopStepAmountSpec := by
  exact ⟨rfl, rfl⟩

/-- At the default64-bit width, direction selects plus or minus eight.
Narrow transfers use the width-indexed functions below. -/
theorem x86_push_pop_step_independent_of_width (op : X86PushPopOp)
    (rsp : BitVec 64) :
    x86PushPopRspAfterSpec op rsp =
        rsp - BitVec.ofNat 64 x86PushPopStepAmountSpec ∨
      x86PushPopRspAfterSpec op rsp =
        rsp + BitVec.ofNat 64 x86PushPopStepAmountSpec := by
  cases op
  · exact Or.inl rfl
  · exact Or.inr rfl

/-- The little-endian byte update `PUSH`'s store performs: the width's low bytes
are replaced, every byte at or beyond the access width is left alone. -/
def generatedX86PushPopByte (byte : Nat -> X86MemByte) (width : X86Width)
    (value : BitVec 64) (i : Nat) : X86MemByte :=
  x86StoreByteUpdate byte width value i

/-- Independent statement of the same update. -/
def x86PushPopByteSpec (byte : Nat -> X86MemByte) (width : X86Width)
    (value : BitVec 64) (i : Nat) : X86MemByte :=
  x86StoreByteUpdateSpec byte width value i

/-- The generated byte update equals the independent little-endian statement. -/
theorem x86_push_pop_byte_refines (byte : Nat -> X86MemByte) (width : X86Width)
    (value : BitVec 64) :
    generatedX86PushPopByte byte width value =
      x86PushPopByteSpec byte width value := by
  funext i
  exact x86_store_byte_update_refines byte width value i

/-- The effect of one stack-transfer body. `step` and `width` record the two
selected facts, `stepAmount` the resolved operand byte count, `addr` the
address the single memory access used, `value` the transferred value (the stored
source for `PUSH`, the stack load for `POP`), `stackBytes` the byte function of
the stack frame afterwards, `dst` the destination-register write (`POP` writes
one, `PUSH` none), and `rsp` the pointer the body leaves behind. -/
structure X86PushPopEffect where
  step : StepDirection
  width : X86Width
  stepAmount : Nat
  addr : BitVec 64
  value : BitVec 64
  stackBytes : Nat -> X86MemByte
  dst : Option X86RegValue
  rsp : BitVec 64

/-- The composed handler transition used by the two bodies: the generated
step-direction and width-source tables select the direction and the honoured
width, the direction fixes where the single memory access goes, and `PUSH`
updates the stack frame with the 64-bit source register while `POP` reads the
width-masked stack value, writes it to the destination register, and leaves the
frame alone. -/
def generatedX86PushPopStep (op : X86PushPopOp) (flags : Code) (rsp : BitVec 64)
    (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) : X86PushPopEffect :=
  let width := generatedX86PushPopWidth op flags
  let addr := generatedX86PushPopAccessAt op rsp flags
  match stepDirection (x86PushPopToOp op) with
  | .preDecrement =>
      { step := .preDecrement, width := width, stepAmount := GeneratedX86PushPop.stepBytes flags,
        addr := addr, value := srcValue,
        stackBytes := generatedX86PushPopByte stackByte width srcValue,
        dst := none, rsp := generatedX86PushPopRspAt op rsp flags }
  | .postIncrement =>
      let value := GeneratedX86MemAccess.load stackByte width
      { step := .postIncrement, width := width, stepAmount := GeneratedX86PushPop.stepBytes flags,
        addr := addr, value := value, stackBytes := stackByte,
        dst := some (generatedX86RegWrite old value width),
        rsp := generatedX86PushPopRspAt op rsp flags }

/-- Independent statement of the same handler: the direction and width are the
independent statements, the address and the stack-pointer update the independent
ones, the byte update the independent little-endian statement, the stack read
the independent little-endian load, and the destination write the independent
partial-register writeback. -/
def x86PushPopStepSpec (op : X86PushPopOp) (flags : Code) (rsp : BitVec 64)
    (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) : X86PushPopEffect :=
  let width := x86PushPopWidthSpec op flags
  let addr := x86PushPopAccessAtSpec op rsp width
  match x86PushPopStepDirectionSpec op with
  | .preDecrement =>
      { step := .preDecrement, width := width,
        stepAmount := x86PushPopBytesSpec width,
        addr := addr, value := srcValue,
        stackBytes := x86PushPopByteSpec stackByte width srcValue,
        dst := none, rsp := x86PushPopRspAtSpec op rsp width }
  | .postIncrement =>
      let value := x86MemLoadSpec stackByte width
      { step := .postIncrement, width := width,
        stepAmount := x86PushPopBytesSpec width,
        addr := addr, value := value, stackBytes := stackByte,
        dst := some (x86RegWriteSpec old value width),
        rsp := x86PushPopRspAtSpec op rsp width }

/-- The `PUSH`/`POP` handler composition refines the independent
direction/width/address/value/byte/writeback statement for every opcode,
`FLAGS` code, stack pointer, stack frame, source register, and destination
register. -/
theorem x86_push_pop_step_refines (op : X86PushPopOp) (flags : Code)
    (rsp : BitVec 64) (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) :
    generatedX86PushPopStep op flags rsp stackByte srcValue old =
      x86PushPopStepSpec op flags rsp stackByte srcValue old := by
  cases op <;> cases flags <;>
    simp [generatedX86PushPopStep, x86PushPopStepSpec, generatedX86PushPopWidth,
      generatedX86PushPopWidthCode, x86PushPopWidthSpec, x86PushPopWidthSourceSpec,
      generatedX86PushPopAccessAt, x86PushPopAccessAtSpec, generatedX86PushPopRspAt,
      x86PushPopRspAtSpec, x86PushPopBytesSpec, GeneratedX86PushPop.stepBytes,
      GeneratedX86PushPop.resolveWidth, GeneratedX86PushPop.stackStep,
      GeneratedX86PushPop.stepDirection, GeneratedX86PushPop.widthSource,
      x86PushPopStepDirectionSpec, x86PushPopToOp, x86WidthBitsSpec,
      x86_push_pop_byte_refines, x86_mem_load_refines, x86_reg_write_refines]

/-- `PUSH` performs no destination-register write: its only register effect is
the stack-pointer move, so the effect's `dst` is `none` and the source register
is untouched. -/
theorem x86_push_pop_push_has_no_dst (flags : Code) (rsp : BitVec 64)
    (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) :
    (x86PushPopStepSpec .push flags rsp stackByte srcValue old).dst = none := by
  rfl

/-- `POP` always writes its destination register, at the same width it read the
stack, and scalarizes the tag. -/
theorem x86_push_pop_pop_writes_dst (flags : Code) (rsp : BitVec 64)
    (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) :
    (x86PushPopStepSpec .pop flags rsp stackByte srcValue old).dst =
      some (x86RegWriteSpec old
        (x86MemLoadSpec stackByte (x86PushPopWidthSpec .pop flags))
        (x86PushPopWidthSpec .pop flags)) := by
  rfl

/-- `POP` leaves the stack frame unchanged: it only reads, and its other two
effects are the destination write and the pointer increment. -/
theorem x86_push_pop_pop_frame_unchanged (flags : Code) (rsp : BitVec 64)
    (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) :
    (x86PushPopStepSpec .pop flags rsp stackByte srcValue old).stackBytes =
      stackByte := by
  rfl

/-- `PUSH` replaces exactly the step amount's bytes of the stack frame and leaves
every other byte alone. -/
theorem x86_push_pop_push_frame_updates_eight (flags : Code)
    (rsp : BitVec 64) (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) (i : Nat) :
    (x86PushPopStepSpec .push flags rsp stackByte srcValue old).stackBytes i =
      x86StoreByteUpdateSpec stackByte
        (x86PushPopWidthSpec .push flags) srcValue i := by
  rfl

/-- Generalized byte-transfer example: PUSH honors the narrow width and
pre-decrements by one. Native PUSH encodings select16 or64 bits. -/
theorem x86_push_pop_push_example :
    (x86PushPopStepSpec .push .b8 0x100 (fun _ => 0) 0x1122334455667788
      ⟨0, .scalar⟩).addr = 0xff ∧
    (x86PushPopStepSpec .push .b8 0x100 (fun _ => 0) 0x1122334455667788
      ⟨0, .scalar⟩).rsp = 0xff ∧
    (x86PushPopStepSpec .push .b8 0x100 (fun _ => 0) 0x1122334455667788
      ⟨0, .scalar⟩).width = .w8 ∧
    (x86PushPopStepSpec .push .b8 0x100 (fun _ => 0) 0x1122334455667788
      ⟨0, .scalar⟩).dst = none := by
  native_decide

/-- Canonical example: a 16-bit `POP` reads the low sixteen bits of the frame
little-endian, writes them over the destination's low half while preserving its
upper bits and scalarizing its tag, and steps the pointer by two bytes. -/
theorem x86_push_pop_pop_example :
    (x86PushPopStepSpec .pop .b16 0xf8
      (fun i => if i = 0 then 0x88 else if i = 1 then 0x77 else 0)
      0 ⟨0x112233445566dead, .mapValue⟩).addr = 0xf8 ∧
    (x86PushPopStepSpec .pop .b16 0xf8
      (fun i => if i = 0 then 0x88 else if i = 1 then 0x77 else 0)
      0 ⟨0x112233445566dead, .mapValue⟩).rsp = 0xfa ∧
    (x86PushPopStepSpec .pop .b16 0xf8
      (fun i => if i = 0 then 0x88 else if i = 1 then 0x77 else 0)
      0 ⟨0x112233445566dead, .mapValue⟩).width = .w16 ∧
    (x86PushPopStepSpec .pop .b16 0xf8
      (fun i => if i = 0 then 0x88 else if i = 1 then 0x77 else 0)
      0 ⟨0x112233445566dead, .mapValue⟩).value = 0x7788 ∧
    (x86PushPopStepSpec .pop .b16 0xf8
      (fun i => if i = 0 then 0x88 else if i = 1 then 0x77 else 0)
      0 ⟨0x112233445566dead, .mapValue⟩).dst =
      some ⟨0x1122334455667788, .scalar⟩ := by
  simp only [x86PushPopStepSpec, x86PushPopWidthSpec, x86PushPopWidthSourceSpec,
    x86PushPopStepDirectionSpec, x86PushPopAccessAtSpec,
    x86PushPopRspAtSpec, x86PushPopBytesSpec, x86MemLoadSpec,
    x86MemAssembleSpec, x86RegWriteSpec, x86RegWriteBitsSpec,
    x86WidthMaskSpec, x86WidthBitsSpec]
  decide

/-- Canonical example: a push-then-pop pair round-trips both the pointer and the
stored 64-bit value — `PUSH` stores the whole source register at the decremented
pointer and `POP` reads it back at 64-bit width. -/
theorem x86_push_pop_round_trip_example :
    let pushed := x86PushPopStepSpec .push .absent 0x100 (fun _ => 0)
      0x1122334455667788 ⟨0, .scalar⟩
    let popped := x86PushPopStepSpec .pop .b64 pushed.rsp pushed.stackBytes
      0 ⟨0, .scalar⟩
    popped.rsp = 0x100 ∧
      popped.addr = pushed.addr ∧
      popped.value = 0x1122334455667788 ∧
      popped.dst = some ⟨0x1122334455667788, .scalar⟩ := by
  native_decide

/-- The production POP RSP/SP order: increment old RSP, then do the generated
width-aware destination write. The register tag does not affect its bits. -/
def generatedX86PopRsp (rsp value : BitVec 64) (width : X86Width) (tag : Tag) : BitVec 64 :=
  (generatedX86RegWrite ⟨rsp + BitVec.ofNat 64 (GeneratedX86Width.bits width / 8), tag⟩
    value width).bits

theorem x86_pop_rsp_alias_refines (rsp value : BitVec 64) (width : X86Width) (tag : Tag) :
    generatedX86PopRsp rsp value width tag =
      Reference.X86.popRsp rsp value (x86WidthBitsSpec width) := by
  cases width <;>
    simp only [generatedX86PopRsp, generatedX86RegWrite, GeneratedX86RegWrite.write,
      GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt,
      GeneratedX86RegWrite.bits, GeneratedX86RegWrite.byteShift, GeneratedX86Width.bits,
      Reference.X86.popRsp, x86WidthBitsSpec, Reference.Word] <;> bv_decide

/-- POP RSP does not add8 to the loaded value; POP SP merges into the high
bits of the already incremented pointer, including a low16-bit carry. -/
theorem x86_pop_rsp_alias_examples :
    Reference.X86.popRsp 0x1000 0x3000 64 = 0x3000 ∧
      Reference.X86.popRsp 0xffff 0x1234 16 = 0x11234 := by decide

end KProgFormal
