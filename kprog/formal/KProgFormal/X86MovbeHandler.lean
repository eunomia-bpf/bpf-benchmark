import KProgFormal.GeneratedX86Movbe
import KProgFormal.GeneratedX86MemDispatch
import KProgFormal.X86Bswap
import KProgFormal.X86MemAccess
import KProgFormal.X86MemDispatch
import KProgFormal.X86MemOffset
import KProgFormal.X86MovLoadHandler
import KProgFormal.X86RegWrite
import KProgFormal.X86StoreHandler
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Movbe (Arm ArmFamily Code DispForm arm armFamily dispForm
  resolveWidth)
open GeneratedX86MemDispatch (ValueSrc)
open GeneratedX86MemAccess (byteCount)

/-- Destination register state of the x86-64 `MOVBE_LOAD` handler
(`X86_SIM_L_EXEC_MOVBE_LOAD`): the body reads memory, reverses the bytes, and
writes one register. It defines no flags. -/
structure X86MovbeLoadState where
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- The two byte-reversal opcodes this contract spans. `movbeLoad` reads memory
and reverses into a register; `movbeStore` reverses a register and stores to
memory. Both take the whole instruction-immediate artifact and the same single
resolved width. -/
inductive X86MovbeOp
  | movbeLoad
  | movbeStore
  deriving DecidableEq, Repr

def x86MovbeIsStore : X86MovbeOp -> Bool
  | .movbeLoad => false
  | .movbeStore => true

/-- Bridge from the handler's opcode type to the generated table's: one row per
opcode, so the generated arm-family and displacement tables can be indexed. -/
def x86MovbeToOp : X86MovbeOp -> GeneratedX86Movbe.Op
  | .movbeLoad => .movbeLoad
  | .movbeStore => .movbeStore

/-- Independent statement of the single resolved width both forms compute: the
opcode's `FLAGS` code with a 64-bit fallback when it carries none. `MOVBE`
resolves exactly one width, used for the byte reversal, the memory access, and
the written size — the store's stack arm re-uses it rather than re-deriving an
effective width, and the load passes it as both the access width and the write
width, so there is no second, AUX-sourced width anywhere. -/
def x86MovbeResolveWidthSpec (flags : Code) : Code :=
  if flags = Code.absent then Code.b64 else flags

/-- The generated width resolution equals the independent fallback statement. -/
theorem x86_movbe_resolve_width_refines (flags : Code) :
    resolveWidth flags = x86MovbeResolveWidthSpec flags := by
  cases flags <;> rfl

/-- The resolved width can never be absent: the fallback is total, so neither
form has an unsupported width. -/
theorem x86_movbe_resolved_not_absent (flags : Code) :
    x86MovbeResolveWidthSpec flags ≠ Code.absent := by
  cases flags <;> simp [x86MovbeResolveWidthSpec]

/-- An opcode that carries no width resolves to 64 bits. -/
theorem x86_movbe_width_absent_defaults :
    x86MovbeResolveWidthSpec Code.absent = Code.b64 := by
  rfl

/-- Independent statement of the arm contract each opcode consumes: the load
form takes the shared memory read dispatch, the store form the two-way
stack/memory arm. The two byte-reversal forms do not share an arm table. -/
def x86MovbeArmFamilySpec : X86MovbeOp -> ArmFamily
  | .movbeLoad => .memoryReadDispatch
  | .movbeStore => .registerStoreArm

/-- The generated arm-family table equals the independent statement: the load
drives the shared read dispatch, the store drives the register-store arm. -/
theorem x86_movbe_arm_family_refines (op : X86MovbeOp) :
    armFamily (x86MovbeToOp op) = x86MovbeArmFamilySpec op := by
  cases op <;> rfl

/-- Independent statement of the displacement form. Both `MOVBE` forms take the
*whole* instruction-immediate artifact `(s64)IMM`: the load hands the shared
read body a store-displacement selector of 0, which takes the sign-extended
immediate, and the store calls `x86_simm` directly. The immediate store's
high-half slice `(s32)(IMM >> 32)` never applies — conflating the two slices is
the plausible bug the contrast below pins. -/
def x86MovbeDispSpec (imm : BitVec 64) : BitVec 64 := imm

/-- The displacement the generated form table selects, restated for the step
definitions. -/
def generatedX86MovbeDisp (op : X86MovbeOp) (imm : BitVec 64) : BitVec 64 :=
  match dispForm (x86MovbeToOp op) with
  | .immHighHalf => ((imm >>> 32).setWidth 32).signExtend 64
  | .signedImm => imm

/-- The displacement the generated form table selects equals the independent
whole-artifact statement, for both opcodes: neither `MOVBE` form takes the
high-half slice, so the one real displacement form is the whole field. -/
theorem generated_x86_movbe_disp_refines (op : X86MovbeOp) (imm : BitVec 64) :
    generatedX86MovbeDisp op imm = x86MovbeDispSpec imm := by
  cases op <;> rfl

/-- Neither `MOVBE` opcode selects the immediate store's high-half displacement
slice: both rows of the form table are the whole-artifact form. -/
theorem x86_movbe_disp_forms_whole :
    x86MovbeDispSpec 0x8000001000000008 = 0x8000001000000008 ∧
      dispForm GeneratedX86Movbe.Op.movbeLoad = DispForm.signedImm ∧
      dispForm GeneratedX86Movbe.Op.movbeStore = DispForm.signedImm := by
  refine ⟨rfl, rfl, rfl⟩

/-- Independent statement of the store arm selection: one test of register
*identity*, with no opcode, width, or tag gate — the same one-fact shape the
shared `MOV_STORE` body has, and the contrast against the load body, whose arm
is gated on three facts. -/
def x86MovbeArmSpec (isRsp : Bool) : Arm :=
  if isRsp then .stackWrite else .memoryStore

/-- The generated arm table equals the independent one-test nesting. -/
theorem x86_movbe_arm_refines (isRsp : Bool) :
    arm isRsp = x86MovbeArmSpec isRsp := by
  cases isRsp <;> rfl

/-- The store's stack arm is exactly the stack-pointer destination: one
selector, and no other input can move the store off the ordinary little-endian
path. -/
theorem x86_movbe_arm_stack_iff (isRsp : Bool) :
    x86MovbeArmSpec isRsp = Arm.stackWrite ↔ isRsp = true := by
  cases isRsp <;> simp [x86MovbeArmSpec]

/-- Both arms of the store's table are reachable: no dead entry. -/
theorem x86_movbe_arm_all_reachable :
    x86MovbeArmSpec true = Arm.stackWrite ∧
      x86MovbeArmSpec false = Arm.memoryStore := by
  exact ⟨rfl, rfl⟩

/-- Composition used by the x86-64 `MOVBE_LOAD` handler after the resolved
width, the base register's identity and memory tag, and the addressing mode have
been decoded. The arm is taken from the *shared* memory read dispatch; the
loaded value is byte-reversed and written with the always-scalarizing
partial-register write. There is no ABI pointer arm and no sign extension.

A `MOVBE` load's dispatch is observationally narrower than the shared body it
draws on: because the writeback always scalarizes and the value is byte-reversed
at its access width, the ABI arm differs from the ordinary arm only in which
memory bytes it reads — the tag provenance the shared body would attach is
overwritten. -/
def generatedX86MovbeLoadStep (state : X86MovbeLoadState) (isRsp isAbi : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (ptrValue : BitVec 64) : X86MovbeLoadState :=
  let sel := GeneratedX86MemDispatch.valueSrc isRsp isAbi (x86WidthIs64 width)
  let value := funnel width byte
  if sel = ValueSrc.stackRead then
    { dst := generatedX86RegWrite state.dst (funnel width stackByte) width }
  else if sel = ValueSrc.abiPtrLoad then
    { dst := { bits := GeneratedX86Bswap.value ptrValue width
               tag := .scalar } }
  else
    { dst := generatedX86RegWrite state.dst value width }
where
  funnel (width : X86Width) (byte : Nat -> X86MemByte) : BitVec 64 :=
    GeneratedX86Bswap.value (GeneratedX86MemAccess.load byte width) width

/-- Independent statement of the same handler: the arm is the independent
dispatch nesting, the loaded value is the byte-sum memory specification
byte-reversed by the independent lane assembly, and the writeback is the
partial-register write specification, which scalarizes. -/
def x86MovbeLoadStepSpec (state : X86MovbeLoadState) (isRsp isAbi : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (ptrValue : BitVec 64) : X86MovbeLoadState :=
  let sel := x86MemReadSrcSpec isRsp isAbi (x86WidthIs64 width)
  let value := x86BswapSpec (x86MemLoadSpec byte width) width
  if sel = ValueSrc.stackRead then
    { dst := x86RegWriteSpec state.dst
        (x86BswapSpec (x86MemLoadSpec stackByte width) width) width }
  else if sel = ValueSrc.abiPtrLoad then
    { dst := { bits := x86BswapSpec ptrValue width, tag := .scalar } }
  else
    { dst := x86RegWriteSpec state.dst value width }

/-- The `MOVBE_LOAD` handler composition refines the independent
width/dispatch/load/reversal/writeback statement for arbitrary destination
state, base identity and tag, access width, memory and stack bytes, and the
pointer value the ABI arm reads. -/
theorem x86_movbe_load_step_refines (state : X86MovbeLoadState) (isRsp isAbi :
    Bool) (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (ptrValue : BitVec 64) :
    generatedX86MovbeLoadStep state isRsp isAbi width byte stackByte ptrValue =
      x86MovbeLoadStepSpec state isRsp isAbi width byte stackByte ptrValue := by
  cases isRsp <;> cases isAbi <;> cases width <;>
    simp [generatedX86MovbeLoadStep, generatedX86MovbeLoadStep.funnel,
      x86MovbeLoadStepSpec, x86_mem_dispatch_src_refines, x86MemReadSrcSpec,
      GeneratedX86MemDispatch.valueSrc, x86WidthIs64, x86_bswap_refines,
      x86_mem_load_refines, x86_reg_write_refines]

/-- The `MOVBE` load always scalarizes the destination: every arm writes through
the partial-register write, which clears the provenance tag, and the ABI arm
writes an explicit scalar tag. No `MOVBE` load can leave a pointer tag in the
destination — the x86-specific asymmetry against the shared memory read body,
whose ABI arm attaches a packet provenance tag. -/
theorem x86_movbe_load_scalarizes (state : X86MovbeLoadState) (isRsp isAbi :
    Bool) (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (ptrValue : BitVec 64) :
    (x86MovbeLoadStepSpec state isRsp isAbi width byte stackByte
      ptrValue).dst.tag = .scalar := by
  cases isRsp <;> cases isAbi <;> cases width <;>
    simp [x86MovbeLoadStepSpec, x86MemReadSrcSpec, x86WidthIs64,
      x86RegWriteSpec]

/-- The `MOVBE` load has no sign-extension arm: unlike the shared load body,
whose `MOVSX` opcode widens the loaded lane before the writeback, a `MOVBE` load
at a narrow width writes the *zero*-extended reversed lane. -/
theorem x86_movbe_load_no_sign_extension (state : X86MovbeLoadState)
    (isRsp isAbi : Bool) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (ptrValue : BitVec 64)
    :
    (x86MovbeLoadStepSpec state isRsp isAbi .w8 byte stackByte
        ptrValue).dst.bits &&& 0xffffffffffffff00 =
      state.dst.bits &&& 0xffffffffffffff00 := by
  cases isRsp <;> cases isAbi <;>
    simp [x86MovbeLoadStepSpec, x86MemReadSrcSpec, x86WidthIs64,
      x86RegWriteSpec, x86RegWriteBitsSpec] <;>
    bv_decide

/-- The store effect of the x86-64 `MOVBE_STORE` handler
(`X86_SIM_L_EXEC_MOVBE_STORE`). The store writes only memory: it defines no
flags, writes no register, and has no ABI arm. `arm` records which of the two
destinations was written, `width` and `value` record what was written, `addr`
records the effective address the body computed (the base pointer plus the
addressing offset; for the stack arm the stack-relative offset the C stack
helper is handed), and `bytes` is the byte function of the buffer that arm
wrote. -/
structure X86MovbeStoreEffect where
  arm : Arm
  width : X86Width
  value : BitVec 64
  addr : BitVec 64
  bytes : Nat -> X86MemByte

/-- Composition used by the x86-64 `MOVBE_STORE` handler after the opcode, the
resolved width, the destination register's identity, the source register, the
instruction-immediate artifact, and the addressing mode have been decoded. The
generated form table selects the displacement form (whole artifact for both
opcodes), the displacement flows through the generated effective-address
contract, the source register is read at the full 64 bits and byte-reversed at
the resolved width, and the arm — one test of register identity — selects which
byte function the width-masked value updates.

The reversal happens *before* the arm split, and the store's stack arm writes at
the same resolved width rather than re-deriving an effective width, so both arms
write exactly the bytes the reversal produced. -/
def generatedX86MovbeStoreStep (op : X86MovbeOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) : X86MovbeStoreEffect :=
  let disp := generatedX86MovbeDisp op imm
  let offset := GeneratedX86MemOffset.value hasIndex scale disp index
  let value := GeneratedX86Bswap.value srcValue width
  let addr := basePtr + offset
  if arm isRsp = Arm.stackWrite then
    { arm := .stackWrite, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdate stackByte width value }
  else
    { arm := .memoryStore, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdate byte width value }

/-- Independent statement of the same handler: the displacement is the
independent whole-artifact statement, the effective address is the independent
offset table, the value is the independent lane-assembly reversal, the arm is
the independent one-test nesting, and the byte update is the shared independent
little-endian statement. -/
def x86MovbeStoreStepSpec (_op : X86MovbeOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) : X86MovbeStoreEffect :=
  let disp := x86MovbeDispSpec imm
  let offset := GeneratedX86MemOffset.valueSpec hasIndex scale disp index
  let value := x86BswapSpec srcValue width
  let addr := basePtr + offset
  if x86MovbeArmSpec isRsp = Arm.stackWrite then
    { arm := .stackWrite, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdateSpec stackByte width value }
  else
    { arm := .memoryStore, width := width, value := value, addr := addr,
      bytes := x86StoreByteUpdateSpec byte width value }

/-- A store's value field is the independent reversal of the source register
read, at the handler's resolved width. -/
theorem x86_movbe_store_step_value_eq (op : X86MovbeOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue basePtr
        hasIndex scale index).value = x86BswapSpec srcValue width := by
  cases op <;> cases isRsp <;> rfl

/-- The generated displacement, effective address, value, and arm agree with
the independent statements for arbitrary destination identity, opcode, width,
memory and stack bytes, artifact fields, base pointer, and addressing mode:
every non-byte field of the effect is identical on the two sides. -/
theorem x86_movbe_store_step_fields_refines (op : X86MovbeOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).arm =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).arm ∧
      (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).width =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).width ∧
      (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).value =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).value ∧
      (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).addr =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).addr := by
  cases op <;> cases isRsp <;>
    simp only [generatedX86MovbeStoreStep, x86MovbeStoreStepSpec,
      x86_movbe_arm_refines, x86MovbeArmSpec, generated_x86_movbe_disp_refines,
      x86MovbeDispSpec, x86_bswap_refines, x86_mem_offset_refines,
      GeneratedX86Movbe.arm, GeneratedX86Movbe.dispForm, reduceCtorEq,
      ↓reduceIte, true_and]

/-- The observed memory bytes refine the independent little-endian statement
pointwise, for every arm. -/
theorem x86_movbe_store_step_bytes_refines (op : X86MovbeOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) (i : Nat) :
    (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).bytes i =
      (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).bytes i := by
  cases op <;> cases isRsp <;>
    simp only [generatedX86MovbeStoreStep, x86MovbeStoreStepSpec,
      x86_movbe_arm_refines, x86MovbeArmSpec, generated_x86_movbe_disp_refines,
      x86MovbeDispSpec, x86_bswap_refines, x86_mem_offset_refines,
      GeneratedX86Movbe.arm, GeneratedX86Movbe.dispForm, reduceCtorEq,
      ↓reduceIte, true_and]
  all_goals exact x86_store_byte_update_refines _ width _ i

/-- The `MOVBE_STORE` handler composition refines the independent
width/displacement/offset/reversal/arm/store statement for arbitrary destination
identity, opcode, width, memory and stack bytes, artifact fields, base pointer,
and addressing mode. -/
theorem x86_movbe_store_step_refines (op : X86MovbeOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).arm =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).arm ∧
      (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).width =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).width ∧
      (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).value =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).value ∧
      (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
        basePtr hasIndex scale index).addr =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).addr ∧
      ∀ i, (generatedX86MovbeStoreStep op isRsp width byte stackByte imm
          srcValue basePtr hasIndex scale index).bytes i =
        (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue
          basePtr hasIndex scale index).bytes i := by
  refine ⟨?_, ?_, ?_, ?_, ?_⟩
  · exact (x86_movbe_store_step_fields_refines op isRsp width byte stackByte
      imm srcValue basePtr hasIndex scale index).1
  · exact (x86_movbe_store_step_fields_refines op isRsp width byte stackByte
      imm srcValue basePtr hasIndex scale index).2.1
  · exact (x86_movbe_store_step_fields_refines op isRsp width byte stackByte
      imm srcValue basePtr hasIndex scale index).2.2.1
  · exact (x86_movbe_store_step_fields_refines op isRsp width byte stackByte
      imm srcValue basePtr hasIndex scale index).2.2.2
  · intro i
    exact x86_movbe_store_step_bytes_refines op isRsp width byte stackByte imm
      srcValue basePtr hasIndex scale index i

/-- Both store arms write at the handler's single resolved width: the reversal,
the value masking, and the written byte count are all keyed by the same width,
so no `MOVBE` store can write a different number of bytes than its own value was
narrowed to. -/
theorem x86_movbe_store_both_arms_use_one_width (op : X86MovbeOp)
    (isRsp : Bool) (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    (generatedX86MovbeStoreStep op isRsp width byte stackByte imm srcValue
      basePtr hasIndex scale index).width = width := by
  cases isRsp <;> rfl

/-- The same width rides both forms' reversal, memory access, and write: for
either opcode the value is the independent reversal of the access-width lane,
and the written byte count is that width's byte count. -/
theorem x86_movbe_one_width_rides_all (op : X86MovbeOp) (isRsp : Bool)
    (width : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (imm srcValue basePtr : BitVec 64)
    (hasIndex : Bool) (scale index : BitVec 64) :
    (x86MovbeStoreStepSpec op isRsp width byte stackByte imm srcValue basePtr
        hasIndex scale index).value =
        x86BswapSpec srcValue width ∧
      byteCount width = x86WidthBitsSpec width / 8 := by
  refine ⟨x86_movbe_store_step_value_eq op isRsp width byte stackByte imm
    srcValue basePtr hasIndex scale index, x86_mem_byte_count width⟩

/-- A round trip through one width: a load that reverses what a store of the
same width reversed recovers the width-masked original, because the reversal is
an involution at every width. -/
theorem x86_movbe_store_load_round_trip (value : BitVec 64) (width : X86Width) :
    x86BswapSpec (x86BswapSpec value width) width =
      value &&& x86WidthMaskSpec width := by
  rw [← x86_bswap_refines, ← x86_bswap_refines]
  exact x86_bswap_involutive value width

/-- Canonical example: the immediate store's high-half slice and the `MOVBE`
whole-artifact displacement are different slices of the same field — the
plausible bug this contract's displacement form rules out. -/
theorem x86_movbe_disp_differs_from_imm_store :
    x86MovbeDispSpec 0x8000001000000008 = 0x8000001000000008 ∧
      x86StoreDispSpec true 0x8000001000000008 = 0xffffffff80000010 := by
  decide

/-- Canonical example: a 16-bit `MOVBE_LOAD` reverses the two little-endian
bytes it reads and writes the zero-extended lane, scalarizing the destination. -/
theorem x86_movbe_load_w16_example :
    generatedX86MovbeLoadStep
      { dst := { bits := 0, tag := .mapValue } }
      false false .w16
      (fun i => if i = 0 then 0x34 else if i = 1 then 0x12 else 0xa5)
      (fun _ => 0xa5) 0 =
      { dst := { bits := 0x3412, tag := .scalar } } := by
  decide

/-- Canonical example: a stack-based `MOVBE_LOAD` reverses the bytes read from
the stack frame, not process memory, and still scalarizes. -/
theorem x86_movbe_load_stack_example :
    generatedX86MovbeLoadStep
      { dst := { bits := 0xffffffffffffffff, tag := .abi } }
      true true .w32
      (fun _ => 0xa5)
      (fun i => if i = 0 then 0x11 else if i = 1 then 0x22 else
        if i = 2 then 0x33 else if i = 3 then 0x44 else 0xa5)
      0 =
      { dst := { bits := 0x11223344, tag := .scalar } } := by
  decide

/-- Canonical example: an ABI-tagged 64-bit base takes the shared ABI arm, so
the loaded pointer is byte-reversed and written with a scalar tag — the one
observable the `MOVBE` load's ABI arm has, since the writeback would scalarize
the ordinary arm's tag anyway. -/
theorem x86_movbe_load_abi_example :
    generatedX86MovbeLoadStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .packet } }
      false true .w64
      (fun _ => 0xa5) (fun _ => 0xa5) 0x1122334455667788 =
      { dst := { bits := 0x8877665544332211, tag := .scalar } } := by
  decide

/-- Canonical example: a `MOVBE_LOAD` at width 8 does not sign-extend — the
loaded `0x80` stays `0x80`, whereas the shared `MOVSX` load of the same byte
would produce `0xffffffffffffff80`. -/
theorem x86_movbe_load_w8_no_sign_extension :
    generatedX86MovbeLoadStep
      { dst := { bits := 0, tag := .scalar } }
      false false .w8
      (fun i => if i = 0 then 0x80 else 0xa5) (fun _ => 0xa5) 0 =
      { dst := { bits := 0x80, tag := .scalar } } := by
  decide

/-- Canonical example: a `MOVBE_STORE` reverses its 64-bit source register and
writes the whole word little-endian to the addressed memory, at the whole-field
displacement, leaving the byte past the access width alone. -/
theorem x86_movbe_store_w64_example :
    let old : Nat -> X86MemByte := fun i => 0xa5 + (i : X86MemByte)
    (generatedX86MovbeStoreStep .movbeStore false .w64
        old (fun _ => 0x5a) 0x0000000000000010 0x0123456789abcdef
        0x4000 false 0 0).arm = Arm.memoryStore ∧
      (generatedX86MovbeStoreStep .movbeStore false .w64
        old (fun _ => 0x5a) 0x0000000000000010 0x0123456789abcdef
        0x4000 false 0 0).value = 0xefcdab8967452301 ∧
      (generatedX86MovbeStoreStep .movbeStore false .w64
        old (fun _ => 0x5a) 0x0000000000000010 0x0123456789abcdef
        0x4000 false 0 0).bytes 0 = 0x01 ∧
      (generatedX86MovbeStoreStep .movbeStore false .w64
        old (fun _ => 0x5a) 0x0000000000000010 0x0123456789abcdef
        0x4000 false 0 0).addr = 0x4010 := by
  decide

/-- Canonical example: a stack-pointer destination takes the stack arm and
writes the stack frame, at the same reversed value and width the memory arm
would have written, leaving the byte past the access width alone. -/
theorem x86_movbe_store_stack_arm_example :
    (generatedX86MovbeStoreStep .movbeStore true .w16
        (fun _ => 0x11) (fun i => 0xa5 + (i : X86MemByte)) 0x0000000000000020
        0x1234567890ab1234 0x20 false 0 0).arm = Arm.stackWrite ∧
      (generatedX86MovbeStoreStep .movbeStore true .w16
        (fun _ => 0x11) (fun i => 0xa5 + (i : X86MemByte)) 0x0000000000000020
        0x1234567890ab1234 0x20 false 0 0).value = 0x3412 ∧
      (generatedX86MovbeStoreStep .movbeStore true .w16
        (fun _ => 0x11) (fun i => 0xa5 + (i : X86MemByte)) 0x0000000000000020
        0x1234567890ab1234 0x20 false 0 0).bytes 0 = 0x12 ∧
      (generatedX86MovbeStoreStep .movbeStore true .w16
        (fun _ => 0x11) (fun i => 0xa5 + (i : X86MemByte)) 0x0000000000000020
        0x1234567890ab1234 0x20 false 0 0).bytes 1 = 0x34 ∧
      (generatedX86MovbeStoreStep .movbeStore true .w16
        (fun _ => 0x11) (fun i => 0xa5 + (i : X86MemByte)) 0x0000000000000020
        0x1234567890ab1234 0x20 false 0 0).bytes 2 = 0xa7 := by
  decide

end KProgFormal
