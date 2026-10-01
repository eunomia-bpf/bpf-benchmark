import KProgFormal.GeneratedX86PushPop
import KProgFormal.TagErasure
import KProgFormal.X86MemAccess
import KProgFormal.X86RegWrite
import KProgFormal.X86StoreHandler
import KProgFormal.X86Width
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

/-- Independent statement of the width each body honours: `PUSH` hardcodes 64
bits and ignores the opcode's `FLAGS` code, `POP` resolves the `FLAGS` code
with a 64-bit fallback. -/
def x86PushPopWidthSourceSpec : X86PushPopOp -> WidthSource
  | .push => .hardcoded64
  | .pop => .flagsOr64

/-- The generated width-source table agrees with the independent statement. -/
theorem x86_push_pop_width_source_refines (op : X86PushPopOp) :
    widthSource (x86PushPopToOp op) = x86PushPopWidthSourceSpec op := by
  cases op <;> rfl

/-- **The step direction and the width source are independent facts.** The body
that pre-decrements is the one that hardcodes 64, and the body that
post-increments is the one that resolves the `FLAGS` code — so neither column
determines the other, and the two directions are distinct as are the two width
sources. Reading the pre-decrementing body's hardcoded width into the
`FLAGS`-honouring body (or its increment direction into the decrementing body)
is the confusion this contract pins away. -/
theorem x86_push_pop_facts :
    x86PushPopStepDirectionSpec .push = StepDirection.preDecrement ∧
      x86PushPopWidthSourceSpec .push = WidthSource.hardcoded64 ∧
      x86PushPopStepDirectionSpec .pop = StepDirection.postIncrement ∧
      x86PushPopWidthSourceSpec .pop = WidthSource.flagsOr64 ∧
      x86PushPopStepDirectionSpec .push ≠ x86PushPopStepDirectionSpec .pop ∧
      x86PushPopWidthSourceSpec .push ≠ x86PushPopWidthSourceSpec .pop := by
  exact ⟨rfl, rfl, rfl, rfl,
    fun h => StepDirection.noConfusion h,
    fun h => WidthSource.noConfusion h⟩

/-- An opcode's `FLAGS` code is `resolved` unless it carries none. -/
theorem x86_push_pop_flags_width_absent_iff (flags : Code) :
    flagsWidth flags = FlagsWidth.absent ↔ flags = Code.absent := by
  cases flags <;> simp [flagsWidth]

/-- The byte amount both bodies step the stack pointer by, as an independent
`Nat` literal. -/
def x86PushPopStepAmountSpec : Nat := 8

/-- The generated stack-step literal equals the independent one. -/
theorem x86_push_pop_step_amount_refines :
    stackStep = x86PushPopStepAmountSpec := by
  rfl

/-- The step amount is eight bytes. -/
theorem x86_push_pop_step_amount_is_eight :
    x86PushPopStepAmountSpec = 8 := by
  rfl

/-- The width each body honours, as a code with the `FLAGS`-code reading: the
hardcoded 64-bit code for `PUSH`, the resolved `FLAGS` code for `POP`. -/
def x86PushPopWidthCodeSpec (op : X86PushPopOp) (flags : Code) : Code :=
  match x86PushPopWidthSourceSpec op with
  | .hardcoded64 => Code.b64
  | .flagsOr64 => resolveWidth flags

/-- Independent statement of the width each body honours, written as the
`X86Width` the byte update, stack read, and destination write all share. `PUSH`
always writes 64 bits; `POP` resolves the `FLAGS` code and an absent code
defaults to 64 bits. -/
def x86PushPopWidthSpec (op : X86PushPopOp) (flags : Code) : X86Width :=
  match x86PushPopWidthSourceSpec op with
  | .hardcoded64 => .w64
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
  | .hardcoded64 => Code.b64
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

/-- `PUSH` hardcodes the 64-bit width whatever `FLAGS` code the opcode carries:
the source register is stored whole, and a narrow code never narrows it. -/
theorem x86_push_pop_push_ignores_flags (flags : Code) :
    x86PushPopWidthSpec .push flags = .w64 := by
  rfl

/-- `POP` with an absent `FLAGS` code defaults to 64 bits. -/
theorem x86_push_pop_pop_absent_defaults :
    x86PushPopWidthSpec .pop .absent = .w64 := by
  rfl

/-- `PUSH` stores exactly the step amount: the hardcoded 64-bit width's byte
count is the eight-byte step. -/
theorem x86_push_pop_push_byte_count (flags : Code) :
    x86WidthBitsSpec (x86PushPopWidthSpec .push flags) / 8 =
      x86PushPopStepAmountSpec := by
  cases flags <;> decide

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

/-- Both bodies step the stack pointer by exactly the step amount whatever width
they honour: the update depends on the opcode and the incoming pointer alone,
never on the `FLAGS` code, so a narrow `POP` still steps a full eight bytes. -/
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
selected facts, `stepAmount` the fixed byte amount both step by, `addr` the
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
  let addr := generatedX86PushPopAccessAddr op rsp
  match stepDirection (x86PushPopToOp op) with
  | .preDecrement =>
      { step := .preDecrement, width := width, stepAmount := stackStep,
        addr := addr, value := srcValue,
        stackBytes := generatedX86PushPopByte stackByte width srcValue,
        dst := none, rsp := generatedX86PushPopRspAfter op rsp }
  | .postIncrement =>
      let value := GeneratedX86MemAccess.load stackByte width
      { step := .postIncrement, width := width, stepAmount := stackStep,
        addr := addr, value := value, stackBytes := stackByte,
        dst := some (generatedX86RegWrite old value width),
        rsp := generatedX86PushPopRspAfter op rsp }

/-- Independent statement of the same handler: the direction and width are the
independent statements, the address and the stack-pointer update the independent
ones, the byte update the independent little-endian statement, the stack read
the independent little-endian load, and the destination write the independent
partial-register writeback. -/
def x86PushPopStepSpec (op : X86PushPopOp) (flags : Code) (rsp : BitVec 64)
    (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) : X86PushPopEffect :=
  let width := x86PushPopWidthSpec op flags
  let addr := x86PushPopAccessAddrSpec op rsp
  match x86PushPopStepDirectionSpec op with
  | .preDecrement =>
      { step := .preDecrement, width := width,
        stepAmount := x86PushPopStepAmountSpec,
        addr := addr, value := srcValue,
        stackBytes := x86PushPopByteSpec stackByte width srcValue,
        dst := none, rsp := x86PushPopRspAfterSpec op rsp }
  | .postIncrement =>
      let value := x86MemLoadSpec stackByte width
      { step := .postIncrement, width := width,
        stepAmount := x86PushPopStepAmountSpec,
        addr := addr, value := value, stackBytes := stackByte,
        dst := some (x86RegWriteSpec old value width),
        rsp := x86PushPopRspAfterSpec op rsp }

/-- The `PUSH`/`POP` handler composition refines the independent
direction/width/address/value/byte/writeback statement for every opcode,
`FLAGS` code, stack pointer, stack frame, source register, and destination
register. -/
theorem x86_push_pop_step_refines (op : X86PushPopOp) (flags : Code)
    (rsp : BitVec 64) (stackByte : Nat -> X86MemByte) (srcValue : BitVec 64)
    (old : X86RegValue) :
    generatedX86PushPopStep op flags rsp stackByte srcValue old =
      x86PushPopStepSpec op flags rsp stackByte srcValue old := by
  cases op
  · simp only [generatedX86PushPopStep, x86PushPopStepSpec, x86PushPopToOp,
      stepDirection, widthSource, x86PushPopStepDirectionSpec,
      x86PushPopWidthSourceSpec, x86_push_pop_width_refines,
      x86_push_pop_access_addr_refines, x86_push_pop_rsp_after_refines,
      x86_push_pop_step_amount_refines, x86_push_pop_byte_refines]
  · simp only [generatedX86PushPopStep, x86PushPopStepSpec, x86PushPopToOp,
      stepDirection, widthSource, x86PushPopStepDirectionSpec,
      x86PushPopWidthSourceSpec, x86_push_pop_width_refines,
      x86_push_pop_access_addr_refines, x86_push_pop_rsp_after_refines,
      x86_push_pop_step_amount_refines, x86_mem_load_refines,
      x86_reg_write_refines]

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

/-- Canonical example: `PUSH` ignores a narrow `FLAGS` code, pre-decrements the
pointer by eight, and addresses its store at the pointer it leaves behind — with
no destination-register write. -/
theorem x86_push_pop_push_example :
    (x86PushPopStepSpec .push .b8 0x100 (fun _ => 0) 0x1122334455667788
      ⟨0, .scalar⟩).addr = 0xf8 ∧
    (x86PushPopStepSpec .push .b8 0x100 (fun _ => 0) 0x1122334455667788
      ⟨0, .scalar⟩).rsp = 0xf8 ∧
    (x86PushPopStepSpec .push .b8 0x100 (fun _ => 0) 0x1122334455667788
      ⟨0, .scalar⟩).width = .w64 ∧
    (x86PushPopStepSpec .push .b8 0x100 (fun _ => 0) 0x1122334455667788
      ⟨0, .scalar⟩).dst = none := by
  native_decide

/-- Canonical example: a 16-bit `POP` reads the low sixteen bits of the frame
little-endian, writes them over the destination's low half while preserving its
upper bits and scalarizing its tag, and *still* steps the pointer a full eight
bytes. -/
theorem x86_push_pop_pop_example :
    (x86PushPopStepSpec .pop .b16 0xf8
      (fun i => if i = 0 then 0x88 else if i = 1 then 0x77 else 0)
      0 ⟨0x112233445566dead, .mapValue⟩).addr = 0xf8 ∧
    (x86PushPopStepSpec .pop .b16 0xf8
      (fun i => if i = 0 then 0x88 else if i = 1 then 0x77 else 0)
      0 ⟨0x112233445566dead, .mapValue⟩).rsp = 0x100 ∧
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
    x86PushPopStepDirectionSpec, x86PushPopAccessAddrSpec,
    x86PushPopRspAfterSpec, x86PushPopStepAmountSpec, x86MemLoadSpec,
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

end KProgFormal
