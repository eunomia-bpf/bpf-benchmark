import KProgFormal.Generated.GeneratedX86CallMem
import KProgFormal.X86MemAccess
import KProgFormal.TagErasure
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86CallMem (CountSource Kind Op countSource kind)

/-- The four block-copy/block-fill opcodes this contract spans:
`X86_OP_CALL_MEMCPY` (`0x3f`), `X86_OP_CALL_MEMSET` (`0x3c`),
`X86_OP_CALL_MEMCPY_REG` (`0x46`), and `X86_OP_CALL_MEMSET_REG` (`0x45`). -/
inductive X86CallMemOp
  | callMemcpy
  | callMemcpyReg
  | callMemset
  | callMemsetReg
  deriving DecidableEq, Repr

/-- Bridge from the handler's opcode type to the generated table's, so the
generated kind and count-source tables can be indexed. -/
def x86CallMemToOp : X86CallMemOp -> GeneratedX86CallMem.Op
  | .callMemcpy => .callMemcpy
  | .callMemcpyReg => .callMemcpyReg
  | .callMemset => .callMemset
  | .callMemsetReg => .callMemsetReg

/-- Independent statement of each opcode's array-body shape, written directly
rather than read from the generated table. -/
def x86CallMemKindSpec : X86CallMemOp -> Kind
  | .callMemcpy => .copy
  | .callMemcpyReg => .copy
  | .callMemset => .fill
  | .callMemsetReg => .fill

/-- The generated kind table agrees with the independent statement. -/
theorem x86_call_mem_kind_refines (op : X86CallMemOp) :
    kind (x86CallMemToOp op) = x86CallMemKindSpec op := by
  cases op <;> rfl

/-- The two copy opcodes read a source byte, the two fill opcodes write one
constant byte; the two families are distinct, so neither row is dead. -/
theorem x86_call_mem_kind_shapes :
    x86CallMemKindSpec .callMemcpy = Kind.copy ∧
      x86CallMemKindSpec .callMemcpyReg = Kind.copy ∧
      x86CallMemKindSpec .callMemset = Kind.fill ∧
      x86CallMemKindSpec .callMemsetReg = Kind.fill ∧
      x86CallMemKindSpec .callMemcpy ≠ x86CallMemKindSpec .callMemset := by
  exact ⟨rfl, rfl, rfl, rfl, fun h => by cases h⟩

/-- Independent statement of where each opcode reads its copied/filled length:
the instruction-immediate artifact, or the `RDX` register. -/
def x86CallMemCountSourceSpec : X86CallMemOp -> CountSource
  | .callMemcpy => .imm
  | .callMemcpyReg => .reg
  | .callMemset => .imm
  | .callMemsetReg => .reg

/-- The generated count-source table agrees with the independent statement. -/
theorem x86_call_mem_count_source_refines (op : X86CallMemOp) :
    countSource (x86CallMemToOp op) = x86CallMemCountSourceSpec op := by
  cases op <;> rfl

/-- Independent statement of the copied/filled length: the instruction-immediate
artifact's value for the two immediate-count opcodes, the `RDX` register's value
for the two register-count opcodes. -/
def x86CallMemCountSpec (op : X86CallMemOp) (imm rdx : BitVec 64) : Nat :=
  match x86CallMemCountSourceSpec op with
  | .imm => imm.toNat
  | .reg => rdx.toNat

/-- The generated count's reading, restated for the step definitions. -/
def generatedX86CallMemCount (op : X86CallMemOp) (imm rdx : BitVec 64) : Nat :=
  match countSource (x86CallMemToOp op) with
  | .imm => imm.toNat
  | .reg => rdx.toNat

/-- The generated count equals the independent count statement, for every opcode
and pair of artifact/register values. -/
theorem generated_x86_call_mem_count_refines (op : X86CallMemOp)
    (imm rdx : BitVec 64) :
    generatedX86CallMemCount op imm rdx = x86CallMemCountSpec op imm rdx := by
  cases op <;>
    simp only [generatedX86CallMemCount, x86CallMemCountSpec, countSource,
      x86CallMemToOp, x86CallMemCountSourceSpec]

/-- The length source the opcode uses is `RDX` for the two register-count
opcodes and the artifact for the two immediate-count opcodes. -/
theorem x86_call_mem_count_sources (imm rdx : BitVec 64) :
    x86CallMemCountSpec .callMemcpy imm rdx = imm.toNat ∧
      x86CallMemCountSpec .callMemset imm rdx = imm.toNat ∧
      x86CallMemCountSpec .callMemcpyReg imm rdx = rdx.toNat ∧
      x86CallMemCountSpec .callMemsetReg imm rdx = rdx.toNat := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- The fill opcodes write the source value's *low byte*: the shared width-8
little-endian store byte at offset `0`, i.e. the value narrowed to eight bits,
never a wider slice. -/
def x86CallMemFillByteSpec (value : BitVec 64) : X86MemByte :=
  x86MemStoreByteSpec value .w8 0

/-- The generated fill byte's reading, restated for the step definitions. -/
def generatedX86CallMemFillByte (value : BitVec 64) : X86MemByte :=
  GeneratedX86MemAccess.storeByte value .w8 0

/-- The generated fill byte equals the independent low-byte statement. -/
theorem generated_x86_call_mem_fill_byte_refines (value : BitVec 64) :
    generatedX86CallMemFillByte value = x86CallMemFillByteSpec value := by
  rw [generatedX86CallMemFillByte, x86CallMemFillByteSpec,
    x86_mem_store_byte_refines]

/-- The fill byte is exactly the value's low eight bits, so no wider slice of
the source leaks into the filled region. -/
theorem x86_call_mem_fill_byte_is_low_byte :
    x86CallMemFillByteSpec 0x1122334455667788 = 0x88 ∧
      x86CallMemFillByteSpec 0xff = 0xff ∧
      x86CallMemFillByteSpec 0x100 = 0x00 := by
  refine ⟨rfl, rfl, rfl⟩

/-- Exact-count effect of a memory intrinsic. This is a byte-buffer contract;
permissions, native call ABI and whole-program correspondence remain separate. -/
structure X86CallMemEffect where
  kind : Kind
  countSource : CountSource
  count : Nat
  dst : BitVec 64
  dstTag : Tag
  bytes : Nat -> X86MemByte

/-- Process every position below the native count, with no separate cap. -/
def x86CallMemByte (k : Kind) (count : Nat)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) (i : Nat) : X86MemByte :=
  if i < count then
    match k with
    | .copy => src i
    | .fill => GeneratedX86MemAccess.storeByte value .w8 0
  else dst i

def x86CallMemByteSpec (k : Kind) (count : Nat)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) (i : Nat) : X86MemByte :=
  if i < count then
    match k with
    | .copy => src i
    | .fill => x86CallMemFillByteSpec value
  else dst i

theorem x86_call_mem_byte_refines (k : Kind) (count : Nat)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) :
    x86CallMemByte k count dst src value =
      x86CallMemByteSpec k count dst src value := by
  funext i
  cases k <;>
    simp only [x86CallMemByte, x86CallMemByteSpec, x86CallMemFillByteSpec,
      x86_mem_store_byte_refines]

def generatedX86CallMemStep (op : X86CallMemOp) (imm rdx : BitVec 64)
    (dst src : Nat -> X86MemByte) (value dstPtr : BitVec 64)
    (dstTag : Tag) : X86CallMemEffect :=
  { kind := kind (x86CallMemToOp op),
    countSource := countSource (x86CallMemToOp op),
    count := generatedX86CallMemCount op imm rdx,
    dst := dstPtr, dstTag := dstTag,
    bytes := x86CallMemByte (kind (x86CallMemToOp op))
      (generatedX86CallMemCount op imm rdx) dst src value }

def x86CallMemStepSpec (op : X86CallMemOp) (imm rdx : BitVec 64)
    (dst src : Nat -> X86MemByte) (value dstPtr : BitVec 64)
    (dstTag : Tag) : X86CallMemEffect :=
  { kind := x86CallMemKindSpec op,
    countSource := x86CallMemCountSourceSpec op,
    count := x86CallMemCountSpec op imm rdx,
    dst := dstPtr, dstTag := dstTag,
    bytes := x86CallMemByteSpec (x86CallMemKindSpec op)
      (x86CallMemCountSpec op imm rdx) dst src value }

theorem x86_call_mem_step_refines (op : X86CallMemOp) (imm rdx : BitVec 64)
    (dst src : Nat -> X86MemByte) (value dstPtr : BitVec 64) (dstTag : Tag) :
    generatedX86CallMemStep op imm rdx dst src value dstPtr dstTag =
      x86CallMemStepSpec op imm rdx dst src value dstPtr dstTag := by
  cases op <;>
    simp only [generatedX86CallMemStep, x86CallMemStepSpec,
      x86_call_mem_kind_refines, x86CallMemKindSpec,
      x86_call_mem_count_source_refines, x86CallMemCountSourceSpec,
      generated_x86_call_mem_count_refines, x86_call_mem_byte_refines]

/-- Bytes outside the requested range are unchanged; no shorter region is used. -/
theorem x86_call_mem_beyond_count_unchanged (op : X86CallMemOp)
    (imm rdx : BitVec 64) (dst src : Nat -> X86MemByte) (value dstPtr : BitVec 64)
    (dstTag : Tag) (i : Nat) (h : x86CallMemCountSpec op imm rdx ≤ i) :
    (x86CallMemStepSpec op imm rdx dst src value dstPtr dstTag).bytes i = dst i := by
  simp only [x86CallMemStepSpec, x86CallMemByteSpec]
  simp [Nat.not_lt.mpr h]

/-- Counts above the removed cap, including high-32-bit counts, stay intact. -/
theorem x86_call_mem_full_count_examples :
    x86CallMemCountSpec .callMemset 2048 0 = 2048 ∧
    x86CallMemCountSpec .callMemsetReg 1 4294967297 = 4294967297 := by
  decide

end KProgFormal
