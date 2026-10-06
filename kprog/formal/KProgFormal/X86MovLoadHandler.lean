import KProgFormal.GeneratedX86MovLoad
import KProgFormal.TagErasure
import KProgFormal.X86MemAccess
import KProgFormal.X86Signed
import KProgFormal.X86RegWrite
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86MovLoad (Arm Code arm resolveWidth)

/-- Destination register state of the x86-64 `MOV_LOAD` handler
(`X86_SIM_L_EXEC_MOV_LOAD`), the single body shared by `X86_OP_MOV_LOAD`,
`X86_OP_MOV_LOAD_SCALAR`, and `X86_OP_MOVSX_LOAD`. The handler reads memory and
writes one register; it defines no flags. -/
structure X86MovLoadState where
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- The three opcodes the shared `MOV_LOAD` body implements. `mov` and
`movScalar` differ only in whether the ABI pointer arm is available; `movsx`
additionally sign-extends the loaded lane. -/
inductive X86MovLoadOp
  | mov
  | movScalar
  | movsx
  deriving DecidableEq, Repr

def x86MovLoadIsMovLoad : X86MovLoadOp -> Bool
  | .mov => true
  | .movScalar => false
  | .movsx => false

def x86MovLoadSignExtends : X86MovLoadOp -> Bool
  | .mov => false
  | .movScalar => false
  | .movsx => true

/-- Whether a resolved width is 64 bits, the form of the width test the C
handler performs. -/
def x86WidthIs64 : X86Width -> Bool
  | .w64 => true
  | .w8 => false
  | .w16 => false
  | .w32 => false

/-- Independent statement of the two resolved widths: the write width defaults
to 64 bits when the opcode carries none, and the memory width defaults to the
resolved write width when the addressing mode carries none. -/
def x86MovLoadResolveWidthSpec (aux flags : Code) : Code × Code :=
  let write := if flags = Code.absent then Code.b64 else flags
  let mem := if aux = Code.absent then write else aux
  (write, mem)

/-- Independent statement of the stack arm's read width. The C macro reads the
stack at `X86_SIM_L_MEM_EFFECTIVE_WIDTH(AUX, FLAGS)`, which is the auxiliary
memory width when present and otherwise the opcode's width with a 64-bit
fallback — exactly the resolved memory width. -/
def x86MovLoadStackReadWidthSpec (aux flags : Code) : Code :=
  if aux = Code.absent then
    (if flags = Code.absent then Code.b64 else flags)
  else aux

/-- Independent statement of the arm selection, written as the predicate
nesting the C `if/else` chain has: the stack-pointer test first (register
identity), then the ABI tag gated on the opcode, both 64-bit widths, and a
non-stack base, then the ordinary load. -/
def x86MovLoadArmSpec (isRsp isMovLoad memIs64 writeIs64 baseIsAbi : Bool) :
    Arm :=
  if isRsp then .stackRead
  else if isMovLoad && memIs64 && writeIs64 && baseIsAbi then .abiPtrWrite
  else .ordinary

/-- The generated width resolution equals the independent fallback statement
for all 25 code pairs. -/
theorem x86_mov_load_resolve_width_refines (aux flags : Code) :
    resolveWidth aux flags = x86MovLoadResolveWidthSpec aux flags := by
  cases aux <;> cases flags <;>
    simp [resolveWidth, x86MovLoadResolveWidthSpec]

/-- The stack arm's read width equals the resolved memory width, so the two C
expressions `X86_SIM_L_MEM_EFFECTIVE_WIDTH(AUX, FLAGS)` and the handler's own
`mem_width` fallback cannot disagree. -/
theorem x86_mov_load_stack_read_width (aux flags : Code) :
    x86MovLoadStackReadWidthSpec aux flags =
      (x86MovLoadResolveWidthSpec aux flags).2 := by
  cases aux <;> cases flags <;>
    simp [x86MovLoadStackReadWidthSpec, x86MovLoadResolveWidthSpec]

/-- Neither resolved width can be absent: the write width has a 64-bit default
and the memory width falls back to the write width, so the resolution is total
and the handler has no unsupported width. -/
theorem x86_mov_load_resolved_not_absent (aux flags : Code) :
    (x86MovLoadResolveWidthSpec aux flags).1 ≠ Code.absent ∧
      (x86MovLoadResolveWidthSpec aux flags).2 ≠ Code.absent := by
  cases aux <;> cases flags <;>
    simp [x86MovLoadResolveWidthSpec]

/-- An opcode that carries no width resolves to a 64-bit write width, and the
memory width then also becomes 64 bits when the addressing mode carries none. -/
theorem x86_mov_load_absent_defaults (aux : Code) :
    x86MovLoadResolveWidthSpec aux Code.absent =
      (Code.b64, if aux = Code.absent then Code.b64 else aux) := by
  cases aux <;> simp [x86MovLoadResolveWidthSpec]

/-- The generated arm table equals the independent predicate nesting for all 32
combinations of the five selector facts. -/
theorem x86_mov_load_arm_refines (isRsp isMovLoad memIs64 writeIs64 baseIsAbi :
    Bool) :
    arm isRsp isMovLoad memIs64 writeIs64 baseIsAbi =
      x86MovLoadArmSpec isRsp isMovLoad memIs64 writeIs64 baseIsAbi := by
  cases isRsp <;> cases isMovLoad <;> cases memIs64 <;> cases writeIs64 <;>
    cases baseIsAbi <;> simp [arm, x86MovLoadArmSpec]

/-- The stack arm comes first and is a test of register identity, not of the
base register's tag or the opcode: a stack-pointer base always reads the stack,
at any width and for any opcode. -/
theorem x86_mov_load_arm_stack_ignores_op_and_tag (isMovLoad memIs64 writeIs64
    baseIsAbi : Bool) :
    x86MovLoadArmSpec true isMovLoad memIs64 writeIs64 baseIsAbi =
      Arm.stackRead := by
  cases isMovLoad <;> cases memIs64 <;> cases writeIs64 <;> cases baseIsAbi <;>
    rfl

/-- The ABI pointer arm is exactly the conjunction of its four gates: the plain
`_MOV_LOAD` opcode, a 64-bit memory width, a 64-bit write width, and an
ABI-tagged non-stack base. Neither a non-`_MOV_LOAD` opcode nor a narrow access
can take it. -/
theorem x86_mov_load_arm_abi_iff (isRsp isMovLoad memIs64 writeIs64
    baseIsAbi : Bool) :
    x86MovLoadArmSpec isRsp isMovLoad memIs64 writeIs64 baseIsAbi =
        Arm.abiPtrWrite ↔
      isRsp = false ∧ isMovLoad = true ∧ memIs64 = true ∧ writeIs64 = true ∧
        baseIsAbi = true := by
  cases isRsp <;> cases isMovLoad <;> cases memIs64 <;> cases writeIs64 <;>
    cases baseIsAbi <;> simp [x86MovLoadArmSpec]

/-- Every arm of the contract is reachable: the table has no dead entry. -/
theorem x86_mov_load_arm_all_reachable :
    x86MovLoadArmSpec true false false false false = Arm.stackRead ∧
      x86MovLoadArmSpec false true true true true = Arm.abiPtrWrite ∧
      x86MovLoadArmSpec false true true true false = Arm.ordinary := by
  refine ⟨rfl, rfl, rfl⟩

/-- **Generated-versus-independent bridge for the ABI provenance tag.**
`KPROG_ABI_LOAD_TAG` was generated from `abi_load_spec.json` as
`GeneratedAbiLoad.tag`; the declarative provenance policy `abiTagSpec` was
written independently in `TagErasure`. They agree for both ABI kinds at every
offset, so the handler's ABI arm and its spec cannot drift apart on the
provenance code. -/
theorem generated_abi_load_tag_refines (kind : AbiKind) (offset : Int) :
    GeneratedAbiLoad.tag (α := Tag) .scalar .packet .packetEnd kind offset =
      abiTagSpec kind offset := by
  cases kind <;> rfl

/-- Composition used by the x86-64 `MOV_LOAD` handler after the opcode, the two
width codes, the base register's identity and tag, and the effective address
have been decoded. The generated arm table selects the arm; the ordinary arm
loads the auxiliary bytes at the *memory* width, sign-extends that lane for
`_MOVSX_LOAD`, and confines the writeback to the *write* width; the stack arm
reads the stack at the same memory width with no sign extension; the ABI arm
writes the loaded pointer together with its ABI provenance tag instead of
scalarizing. -/
def generatedX86MovLoadStep (state : X86MovLoadState) (op : X86MovLoadOp)
    (isRsp isAbi : Bool) (memWidth writeWidth : X86Width)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (kind : AbiKind) (disp addr : BitVec 64) : X86MovLoadState :=
  let sel := arm isRsp (x86MovLoadIsMovLoad op) (x86WidthIs64 memWidth)
    (x86WidthIs64 writeWidth) isAbi
  let value := GeneratedX86MemAccess.load byte memWidth
  let value := if x86MovLoadSignExtends op then
    GeneratedX86Signed.signExtend value memWidth else value
  if sel = Arm.stackRead then
    { dst := generatedX86RegWrite state.dst
        (GeneratedX86MemAccess.load stackByte memWidth) writeWidth }
  else if sel = Arm.abiPtrWrite then
    { dst :=
        { bits := addr
          tag := GeneratedAbiLoad.tag (α := Tag) .scalar .packet .packetEnd kind
            disp.toInt } }
  else
    { dst := generatedX86RegWrite state.dst value writeWidth }

/-- Independent statement of the same handler: the arm is the predicate
nesting, the load is the byte-sum memory specification, the sign extension is
the independent `signExtend` statement, the writeback is the partial-register
write specification, and the ABI provenance code is the declarative
`abiTagSpec` policy. -/
def x86MovLoadStepSpec (state : X86MovLoadState) (op : X86MovLoadOp)
    (isRsp isAbi : Bool) (memWidth writeWidth : X86Width)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (kind : AbiKind) (disp addr : BitVec 64) : X86MovLoadState :=
  let sel := x86MovLoadArmSpec isRsp (x86MovLoadIsMovLoad op)
    (x86WidthIs64 memWidth) (x86WidthIs64 writeWidth) isAbi
  let value := x86MemLoadSpec byte memWidth
  let value := if x86MovLoadSignExtends op then
    x86SignExtendSpec value memWidth else value
  if sel = Arm.stackRead then
    { dst := x86RegWriteSpec state.dst (x86MemLoadSpec stackByte memWidth)
        writeWidth }
  else if sel = Arm.abiPtrWrite then
    { dst := { bits := addr, tag := abiTagSpec kind disp.toInt } }
  else
    { dst := x86RegWriteSpec state.dst value writeWidth }

/-- The `MOV_LOAD` handler composition refines the independent
arm/width/load/sign-extend/tag/writeback statement for arbitrary destination
state, opcode, base identity and tag, both widths, memory and stack bytes, ABI
kind, and displacement and effective address. -/
theorem x86_mov_load_step_refines (state : X86MovLoadState) (op : X86MovLoadOp)
    (isRsp isAbi : Bool) (memWidth writeWidth : X86Width)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (kind : AbiKind) (disp addr : BitVec 64) :
    generatedX86MovLoadStep state op isRsp isAbi memWidth writeWidth byte
        stackByte kind disp addr =
      x86MovLoadStepSpec state op isRsp isAbi memWidth writeWidth byte
        stackByte kind disp addr := by
  simp only [generatedX86MovLoadStep, x86MovLoadStepSpec,
    x86_mov_load_arm_refines, x86_mem_load_refines, x86_sign_extend_refines,
    x86_reg_write_refines, generated_abi_load_tag_refines]

/-- The ordinary arm scalarizes the destination's provenance: because the ABI
arm requires an ABI-tagged base and the stack arm requires a stack-pointer
base, any non-stack, non-ABI base is loaded and scalarized at the write width. -/
theorem x86_mov_load_ordinary_scalarizes (state : X86MovLoadState)
    (op : X86MovLoadOp) (isRsp : Bool) (memWidth writeWidth : X86Width)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (kind : AbiKind) (disp addr : BitVec 64) :
    (x86MovLoadStepSpec state op isRsp false memWidth writeWidth byte
        stackByte kind disp addr).dst.tag = .scalar := by
  cases op <;> cases isRsp <;> cases memWidth <;> cases writeWidth <;>
    simp [x86MovLoadStepSpec, x86MovLoadArmSpec, x86MovLoadIsMovLoad,
      x86WidthIs64, x86RegWriteSpec]

/-- The ABI pointer arm writes the ABI provenance tag and leaves the loaded
pointer bits intact, rather than scalarizing: the tag survives the writeback
because the pointer arm bypasses the register-lane logic entirely. -/
theorem x86_mov_load_abi_arm_tag (state : X86MovLoadState)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (kind : AbiKind) (disp addr : BitVec 64) :
    x86MovLoadStepSpec state .mov false true .w64 .w64 byte stackByte kind disp
        addr =
      { dst := { bits := addr, tag := abiTagSpec kind disp.toInt } } := by
  simp [x86MovLoadStepSpec, x86MovLoadArmSpec, x86MovLoadIsMovLoad,
    x86WidthIs64]

/-- The ABI arm's tag is exactly `GeneratedAbiLoad.tag` at the displacement, so
the packet/data-end offsets map to packet provenance and every other offset is
scalar — no tag widening at an arbitrary displacement. -/
theorem x86_mov_load_abi_arm_tag_at_end (state : X86MovLoadState)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte) (disp : BitVec 64) :
    (x86MovLoadStepSpec state .mov false true .w64 .w64 byte stackByte .xdp 8
        disp).dst.tag = .packetEnd := by
  simp [x86_mov_load_abi_arm_tag, abiTagSpec]

/-- The stack arm never sign-extends, even for `_MOVSX_LOAD`: because the
register-identity test precedes the opcode test, a stack-based `MOVSX` reads
the stack at the memory width and writes the same zero-extended lane an
ordinary `MOV` would. This is the x86-specific asymmetry against the
register-source narrow/wide body, whose opcode alone selects the extension. -/
theorem x86_mov_load_stack_arm_ignores_sign_extension
    (state : X86MovLoadState) (writeWidth : X86Width)
    (byte : Nat -> X86MemByte) (stackByte : Nat -> X86MemByte)
    (kind : AbiKind) (disp addr : BitVec 64) :
    x86MovLoadStepSpec state .movsx true false .w8 writeWidth byte stackByte
        kind disp addr =
      x86MovLoadStepSpec state .mov true false .w8 writeWidth byte stackByte
        kind disp addr := by
  simp [x86MovLoadStepSpec, x86MovLoadArmSpec, x86MovLoadIsMovLoad,
    x86MovLoadSignExtends, x86WidthIs64]

/-- A narrow ordinary load confines the value to the memory width before the
writeback, so bytes above the access width cannot enter the product: at a
64-bit write width the result is exactly the width-masked loaded lane. -/
theorem x86_mov_load_ordinary_w64_masks_mem (state : X86MovLoadState)
    (op : X86MovLoadOp) (memWidth : X86Width) (byte : Nat -> X86MemByte)
    (stackByte : Nat -> X86MemByte) (kind : AbiKind) (disp addr : BitVec 64)
    (h : x86MovLoadSignExtends op = false) :
    (x86MovLoadStepSpec state op false false memWidth .w64 byte stackByte kind
        disp addr).dst.bits =
      x86MemLoadSpec byte memWidth := by
  cases op <;>
    simp [x86MovLoadStepSpec, x86MovLoadArmSpec, x86MovLoadIsMovLoad,
      x86MovLoadSignExtends, x86WidthIs64, x86RegWriteSpec,
      x86RegWriteBitsSpec] at h ⊢

/-- Canonical example: an ordinary 16-bit load merges the zero-extended lane
into a 64-bit destination and scalarizes its provenance. -/
theorem x86_mov_load_ordinary_w16_example :
    generatedX86MovLoadStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .mapValue } }
      .mov false false .w16 .w64
      (fun i => if i = 0 then 0x34 else if i = 1 then 0x12 else 0xa5)
      (fun _ => 0xa5) .xdp 0x10 0x4000 =
      { dst := { bits := 0x1234, tag := .scalar } } := by
  decide

/-- Canonical example: `_MOVSX_LOAD` sign-extends the loaded 8-bit lane before a
32-bit write, so `0x80` becomes `0xffffff80` and the destination's upper half is
zeroed. -/
theorem x86_mov_load_movsx_w8_example :
    generatedX86MovLoadStep
      { dst := { bits := 0xffffffffffffffff, tag := .packet } }
      .movsx false false .w8 .w32
      (fun i => if i = 0 then 0x80 else 0xa5)
      (fun _ => 0xa5) .xdp 0x20 0x4000 =
      { dst := { bits := 0xffffff80, tag := .scalar } } := by
  decide

/-- Canonical example: the ABI pointer arm writes the loaded pointer with its
packet provenance, from the `_MOV_LOAD` opcode at both 64-bit widths off an
ABI-tagged non-stack base. -/
theorem x86_mov_load_abi_arm_example :
    generatedX86MovLoadStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .scalar } }
      .mov false true .w64 .w64
      (fun _ => 0xa5) (fun _ => 0xa5) .xdp 0
      0x1122334455667788 =
      { dst := { bits := 0x1122334455667788, tag := .packet } } := by
  decide

/-- Canonical example: a stack-based `_MOVSX_LOAD` still takes the stack arm, so
the loaded `0x80` is *not* sign-extended and the destination receives the
zero-extended `0x80`. -/
theorem x86_mov_load_stack_movsx_example :
    generatedX86MovLoadStep
      { dst := { bits := 0xffffffffffffffff, tag := .abi } }
      .movsx true true .w8 .w64
      (fun _ => 0xa5)
      (fun i => if i = 0 then 0x80 else 0xa5) .xdp 0x30 0x7ff0 =
      { dst := { bits := 0x80, tag := .scalar } } := by
  decide

/-- Canonical example: an ABI-tagged base reached by a narrow write falls
through to the ordinary scalar load and is scalarized — the ABI arm needs both
resolved widths at 64 bits. -/
theorem x86_mov_load_abi_narrow_write_example :
    generatedX86MovLoadStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .abi } }
      .mov false true .w64 .w32
      (fun i => match i with
        | 0 => 0x11 | 1 => 0x22 | 2 => 0x33 | 3 => 0x44
        | 4 => 0x55 | 5 => 0x66 | 6 => 0x77 | _ => 0x88)
      (fun _ => 0xa5) .xdp 0 0x40000 =
      { dst := { bits := 0x44332211, tag := .scalar } } := by
  decide

/-- Canonical example: `_MOV_LOAD_SCALAR` below the ABI gates behaves exactly
like `_MOV_LOAD`, since neither opcode sign-extends and the arm agrees. -/
theorem x86_mov_load_movscalar_example :
    generatedX86MovLoadStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .mapPtr } }
      .movScalar false false .w32 .w64
      (fun i => if i = 0 then 0x11 else if i = 1 then 0x22 else
        if i = 2 then 0x33 else if i = 3 then 0x44 else 0xa5)
      (fun _ => 0xa5) .skb 0x40 0x50000 =
      { dst := { bits := 0x44332211, tag := .scalar } } := by
  decide

end KProgFormal
