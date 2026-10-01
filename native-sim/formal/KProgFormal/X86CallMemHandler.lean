import KProgFormal.GeneratedX86CallMem
import KProgFormal.X86MemAccess
import KProgFormal.TagErasure
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86CallMem (BoundForm CountSource Kind Op boundForm countSource
  fixedBound kind)

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
generated kind, count-source, and bound-form tables can be indexed. -/
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

/-- Independent statement of each opcode's array-bound form: the hardcoded
literal `1024`, or the instruction-immediate artifact. -/
def x86CallMemBoundFormSpec : X86CallMemOp -> BoundForm
  | .callMemcpy => .fixedBound
  | .callMemcpyReg => .imm
  | .callMemset => .fixedBound
  | .callMemsetReg => .imm

/-- The generated bound-form table agrees with the independent statement. -/
theorem x86_call_mem_bound_form_refines (op : X86CallMemOp) :
    boundForm (x86CallMemToOp op) = x86CallMemBoundFormSpec op := by
  cases op <;> rfl

/-- **The bound form and the count source are independent facts.** The two
immediate-count opcodes take the *literal* bound, the two register-count opcodes
take the *immediate* bound — the opposite of their count source. Reading one
fact as the other is the confusion this contract pins away: `callMemset` fills
the literal `1024` bytes bounded by the immediate count, whereas
`callMemsetReg` fills the immediate-bounded region bounded by the `RDX` count. -/
theorem x86_call_mem_bound_and_count_are_independent :
    x86CallMemCountSourceSpec .callMemset = CountSource.imm ∧
      x86CallMemBoundFormSpec .callMemset = BoundForm.fixedBound ∧
      x86CallMemCountSourceSpec .callMemsetReg = CountSource.reg ∧
      x86CallMemBoundFormSpec .callMemsetReg = BoundForm.imm ∧
      x86CallMemBoundFormSpec .callMemset ≠
        x86CallMemBoundFormSpec .callMemsetReg := by
  exact ⟨rfl, rfl, rfl, rfl, fun h => by cases h⟩

/-- The hardcoded bound the two immediate-count bodies iterate to, as an
independent `Nat` literal. -/
def x86CallMemFixedBoundSpec : Nat := 1024

/-- The generated fixed-bound literal equals the independent one. -/
theorem x86_call_mem_fixed_bound_refines :
    fixedBound = x86CallMemFixedBoundSpec := by
  rfl

/-- Independent statement of the array bound: the fixed literal for the two
immediate-count opcodes, the instruction-immediate artifact's value for the two
register-count opcodes. -/
def x86CallMemBoundSpec (op : X86CallMemOp) (imm : BitVec 64) : Nat :=
  match x86CallMemBoundFormSpec op with
  | .fixedBound => x86CallMemFixedBoundSpec
  | .imm => imm.toNat

/-- The generated bound-form's reading, restated for the step definitions. -/
def generatedX86CallMemBoundForm (op : X86CallMemOp) : BoundForm :=
  boundForm (x86CallMemToOp op)

/-- The generated bound's reading, restated for the step definitions. -/
def generatedX86CallMemBound (op : X86CallMemOp) (imm : BitVec 64) : Nat :=
  match generatedX86CallMemBoundForm op with
  | .fixedBound => fixedBound
  | .imm => imm.toNat

/-- The generated bound equals the independent bound statement, for every
opcode and artifact. -/
theorem generated_x86_call_mem_bound_refines (op : X86CallMemOp)
    (imm : BitVec 64) :
    generatedX86CallMemBound op imm = x86CallMemBoundSpec op imm := by
  cases op <;>
    simp only [generatedX86CallMemBound, x86CallMemBoundSpec,
      generatedX86CallMemBoundForm, boundForm, x86CallMemToOp,
      x86CallMemBoundFormSpec, x86CallMemFixedBoundSpec, fixedBound]

/-- The two immediate-count opcodes iterate to the literal bound regardless of
the instruction-immediate artifact, whereas the two register-count opcodes are
bounded by it. -/
theorem x86_call_mem_fixed_bound_is_literal (imm : BitVec 64) :
    x86CallMemBoundSpec .callMemcpy imm = 1024 ∧
      x86CallMemBoundSpec .callMemset imm = 1024 ∧
      x86CallMemBoundSpec .callMemcpyReg imm = imm.toNat ∧
      x86CallMemBoundSpec .callMemsetReg imm = imm.toNat := by
  refine ⟨rfl, rfl, rfl, rfl⟩

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

/-- The effect of one block-copy/block-fill handler. `kind`, `countSource`, and
`boundForm` record the three selected facts, `bound`/`count` the resolved array
bounds, `dst`/`dstTag` the result-register write's source, and `bytes` the byte
function of the updated destination buffer. -/
structure X86CallMemEffect where
  kind : Kind
  countSource : CountSource
  boundForm : BoundForm
  bound : Nat
  count : Nat
  dst : BitVec 64
  dstTag : Tag
  bytes : Nat -> X86MemByte

/-- The replacement a byte position receives: when the position is both inside
the array bound and below the copied/filled length, a copy takes the source byte
and a fill takes the value's low byte; every other position keeps its old byte. -/
def x86CallMemByte (k : Kind) (bound count : Nat)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) (i : Nat) : X86MemByte :=
  if i < bound ∧ i < count then
    match k with
    | .copy => src i
    | .fill => GeneratedX86MemAccess.storeByte value .w8 0
  else dst i

/-- The same replacement stated with the independent fill-byte statement. -/
def x86CallMemByteSpec (k : Kind) (bound count : Nat)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) (i : Nat) : X86MemByte :=
  if i < bound ∧ i < count then
    match k with
    | .copy => src i
    | .fill => x86CallMemFillByteSpec value
  else dst i

/-- The generated replacement equals the independent one, as functions. -/
theorem x86_call_mem_byte_refines (k : Kind) (bound count : Nat)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) :
    x86CallMemByte k bound count dst src value =
      x86CallMemByteSpec k bound count dst src value := by
  funext i
  cases k <;>
    simp only [x86CallMemByte, x86CallMemByteSpec, x86CallMemFillByteSpec,
      x86_mem_store_byte_refines]
/-- The composed handler transition used by the four bodies: the generated kind
and count-source tables select the body's shape and length source, the generated
bound-form table selects the array bound, and the shared byte replacement writes
the destination region. -/
def generatedX86CallMemStep (op : X86CallMemOp) (imm rdx : BitVec 64)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) (dstPtr : BitVec 64)
    (dstTag : Tag) : X86CallMemEffect :=
  { kind := kind (x86CallMemToOp op),
    countSource := countSource (x86CallMemToOp op),
    boundForm := boundForm (x86CallMemToOp op),
    bound := generatedX86CallMemBound op imm,
    count := generatedX86CallMemCount op imm rdx,
    dst := dstPtr, dstTag := dstTag,
    bytes := x86CallMemByte (kind (x86CallMemToOp op))
      (generatedX86CallMemBound op imm) (generatedX86CallMemCount op imm rdx)
      dst src value }

/-- Independent statement of the same handler, reading the three facts from the
independent statements and the bounds from the independent bound/count
statements. -/
def x86CallMemStepSpec (op : X86CallMemOp) (imm rdx : BitVec 64)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) (dstPtr : BitVec 64)
    (dstTag : Tag) : X86CallMemEffect :=
  { kind := x86CallMemKindSpec op,
    countSource := x86CallMemCountSourceSpec op,
    boundForm := x86CallMemBoundFormSpec op,
    bound := x86CallMemBoundSpec op imm,
    count := x86CallMemCountSpec op imm rdx,
    dst := dstPtr, dstTag := dstTag,
    bytes := x86CallMemByteSpec (x86CallMemKindSpec op)
      (x86CallMemBoundSpec op imm) (x86CallMemCountSpec op imm rdx)
      dst src value }

/-- The block-copy/block-fill handler composition refines the independent
kind/count/bound/replacement statement for every opcode, artifact, register
count, destination and source buffer, element value, and result-register write. -/
theorem x86_call_mem_step_refines (op : X86CallMemOp) (imm rdx : BitVec 64)
    (dst src : Nat -> X86MemByte) (value : BitVec 64) (dstPtr : BitVec 64)
    (dstTag : Tag) :
    generatedX86CallMemStep op imm rdx dst src value dstPtr dstTag =
      x86CallMemStepSpec op imm rdx dst src value dstPtr dstTag := by
  cases op <;>
    simp only [generatedX86CallMemStep, x86CallMemStepSpec,
      x86_call_mem_kind_refines, x86CallMemKindSpec,
      x86_call_mem_count_source_refines, x86CallMemCountSourceSpec,
      x86_call_mem_bound_form_refines, x86CallMemBoundFormSpec,
      generatedX86CallMemBound, generatedX86CallMemCount,
      generatedX86CallMemBoundForm, generated_x86_call_mem_count_refines,
      x86_call_mem_byte_refines, boundForm, countSource, kind, x86CallMemToOp,
      x86CallMemBoundSpec, x86CallMemCountSpec, x86CallMemFixedBoundSpec,
      fixedBound]

/-- No block-copy/block-fill handler touches a byte at or beyond its array
bound, so the four bodies write exactly their bounded region and nothing else. -/
theorem x86_call_mem_beyond_bound_unchanged (op : X86CallMemOp)
    (imm rdx : BitVec 64) (dst src : Nat -> X86MemByte) (value : BitVec 64)
    (dstPtr : BitVec 64) (dstTag : Tag) (i : Nat)
    (h : x86CallMemBoundSpec op imm ≤ i) :
    (x86CallMemStepSpec op imm rdx dst src value dstPtr dstTag).bytes i =
      dst i := by
  have hb : ¬ i < x86CallMemBoundSpec op imm := Nat.not_lt.mpr h
  cases op <;>
    simp only [x86CallMemStepSpec, x86CallMemByteSpec, x86CallMemKindSpec,
      x86CallMemBoundSpec, x86CallMemBoundFormSpec,
      x86CallMemFixedBoundSpec] at hb ⊢ <;>
    simp [hb]

end KProgFormal
