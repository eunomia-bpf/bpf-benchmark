import KProgFormal.Refinement.X86NumericAddress
import KProgFormal.Generated.GeneratedX86Specialization
import KProgFormal.Generated.GeneratedX86Opcode
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

namespace X86CallMemBody
abbrev Word := Reference.Word
open Reference
open Refinement.X86NumericAddress
abbrev Register := Reference.X86.Register

/-- The sixteen kind6 reads follow the production helper-clobber order:
eight GPRs, CF/ZF/SF/OF/PF/AF, then the two XMM0 halves. -/
abbrev Fresh := Fin 16 → Word

structure Frame where
  registers : RegisterState
  tags : Register → Byte

def rawWrite (s : Frame) (r : Register) (value : Word) (tag : Byte) : Frame :=
  ⟨⟨{ s.registers.raw with gpr := fun q => if q = r then value else s.registers.raw.gpr q },
    fun q => if q = r then tag == 4 else s.registers.stack q⟩,
    fun q => if q = r then tag else s.tags q⟩

def clobberIndex (r : Register) : Option (Fin 16) :=
  if r = 1 then some 0 else if r = 2 then some 1 else
  if r = 6 then some 2 else if r = 7 then some 3 else
  if r = 8 then some 4 else if r = 9 then some 5 else
  if r = 10 then some 6 else if r = 11 then some 7 else none

def freshFlags (fresh : Fresh) : Word :=
  (fresh 8 &&& 1) ||| ((fresh 9 &&& 1) <<< 6) |||
  ((fresh 10 &&& 1) <<< 7) ||| ((fresh 11 &&& 1) <<< 11) |||
  ((fresh 12 &&& 1) <<< 2) ||| ((fresh 13 &&& 1) <<< 4)

def flagsMask : Word := 0x8d5

def finishClobbers (s : Frame) (fresh : Fresh) : Frame :=
  { s with registers := { s.registers with raw := { s.registers.raw with
    rflags := (s.registers.raw.rflags &&& ~~~flagsMask) ||| freshFlags fresh,
    xmm0 := (fresh 14).setWidth 128 ||| ((fresh 15).setWidth 128 <<< 64) } } }

/-- Sequential raw writes model the eight assignments in HELPER_CLOBBERS. -/
def generatedClobbers (s : Frame) (fresh : Fresh) : Frame :=
  let s := rawWrite s 1 (fresh 0) 0
  let s := rawWrite s 2 (fresh 1) 0
  let s := rawWrite s 6 (fresh 2) 0
  let s := rawWrite s 7 (fresh 3) 0
  let s := rawWrite s 8 (fresh 4) 0
  let s := rawWrite s 9 (fresh 5) 0
  let s := rawWrite s 10 (fresh 6) 0
  let s := rawWrite s 11 (fresh 7) 0
  finishClobbers s fresh

/-- The independent ABI frame replaces caller registers from the supplied
fresh stream while retaining the complete callee frame and raw memory. -/
def clobbersSpec (s : Frame) (fresh : Fresh) : Frame :=
  finishClobbers
    ⟨⟨{ s.registers.raw with gpr := fun r => match clobberIndex r with
        | some i => fresh i | none => s.registers.raw.gpr r },
      fun r => if (clobberIndex r).isSome then false else s.registers.stack r⟩,
      fun r => if (clobberIndex r).isSome then 0 else s.tags r⟩ fresh

theorem helper_clobbers_frame (s : Frame) (fresh : Fresh) :
    generatedClobbers s fresh = clobbersSpec s fresh := by
  dsimp only [generatedClobbers, clobbersSpec, rawWrite]
  congr 1
  congr 1
  · congr 1
    · congr 1
      funext r
      rcases r with ⟨r, bound⟩
      have choices : r = 0 ∨ r = 1 ∨ r = 2 ∨ r = 3 ∨ r = 4 ∨ r = 5 ∨ r = 6 ∨ r = 7 ∨
          r = 8 ∨ r = 9 ∨ r = 10 ∨ r = 11 ∨ r = 12 ∨ r = 13 ∨ r = 14 ∨ r = 15 := by omega
      rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl
    · funext r
      rcases r with ⟨r, bound⟩
      have choices : r = 0 ∨ r = 1 ∨ r = 2 ∨ r = 3 ∨ r = 4 ∨ r = 5 ∨ r = 6 ∨ r = 7 ∨
          r = 8 ∨ r = 9 ∨ r = 10 ∨ r = 11 ∨ r = 12 ∨ r = 13 ∨ r = 14 ∨ r = 15 := by omega
      rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl
  · funext r
    rcases r with ⟨r, bound⟩
    have choices : r = 0 ∨ r = 1 ∨ r = 2 ∨ r = 3 ∨ r = 4 ∨ r = 5 ∨ r = 6 ∨ r = 7 ∨
        r = 8 ∨ r = 9 ∨ r = 10 ∨ r = 11 ∨ r = 12 ∨ r = 13 ∨ r = 14 ∨ r = 15 := by omega
    rcases choices with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

/-- The extracted loop reads before writing each byte, including overlapping
buffers. Access permissions and the raw/native memory relation are interfaces. -/
def generatedLoop (copy : Bool) (dst src value : Word) : Nat → Nat → Memory → Memory
  | 0, _, memory => memory
  | count + 1, index, memory =>
      let byte := if copy then memory.value (src + BitVec.ofNat 64 index) else value.setWidth 8
      generatedLoop copy dst src value count (index + 1)
        (storeMemory memory (dst + BitVec.ofNat 64 index) (byte.setWidth 64) 1)

/-- List execution states the ordered byte effects independently of the
recursive C-loop model. Every read uses the preceding write's memory image. -/
def loopSpec (kind : GeneratedX86CallMem.Kind) (dst src value : Word)
    (count index : Nat) (memory : Memory) : Memory :=
  (List.range' index count).foldl (fun m i =>
    let byte := match kind with
      | .copy => m.value (src + BitVec.ofNat 64 i)
      | .fill => value.setWidth 8
    storeMemory m (dst + BitVec.ofNat 64 i) (byte.setWidth 64) 1) memory

theorem ordered_loop_refines (kind : GeneratedX86CallMem.Kind) (dst src value : Word)
    (count index : Nat) (memory : Memory) :
    generatedLoop (kind == .copy) dst src value count index memory =
      loopSpec kind dst src value count index memory := by
  induction count generalizing index memory with
  | zero => rfl
  | succ count ih =>
      let byte : Reference.Byte := match kind with
        | .copy => memory.value (src + BitVec.ofNat 64 index)
        | .fill => value.setWidth 8
      have step := ih (index + 1) (storeMemory memory (dst + BitVec.ofNat 64 index) (byte.setWidth 64) 1)
      cases kind <;> simpa [generatedLoop, loopSpec, List.range'_succ, byte] using step

def generatedBody (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (arena : Word)
    (s : Frame) (fresh : Fresh) (op : X86CallMemOp) (imm nextPc : Word) : Frame :=
  let dst := s.registers.raw.gpr 7
  let src := s.registers.raw.gpr 6
  let value := registerValue env frame arena s.registers 6
  let count := generatedX86CallMemCount op imm (registerValue env frame arena s.registers 2)
  let memory := generatedLoop (GeneratedX86CallMem.kind (x86CallMemToOp op) == .copy)
    dst src value count 0 s.registers.raw.memory
  let written := { s with registers := { s.registers with raw := { s.registers.raw with memory := memory } } }
  let result := generatedClobbers (rawWrite written 0 dst (s.tags 7)) fresh
  { result with registers := registerPc result.registers nextPc }

def bodySpec (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (arena : Word)
    (s : Frame) (fresh : Fresh) (op : X86CallMemOp) (imm nextPc : Word) : Frame :=
  let memory := loopSpec (x86CallMemKindSpec op) (s.registers.raw.gpr 7) (s.registers.raw.gpr 6)
    (registerValue env frame arena s.registers 6)
    (x86CallMemCountSpec op imm (registerValue env frame arena s.registers 2)) 0 s.registers.raw.memory
  let written := { s with registers := { s.registers with raw := { s.registers.raw with memory := memory } } }
  let result := clobbersSpec (rawWrite written 0 (s.registers.raw.gpr 7) (s.tags 7)) fresh
  { result with registers := registerPc result.registers nextPc }

theorem call_mem_body_refines (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (arena : Word)
    (s : Frame) (fresh : Fresh) (op : X86CallMemOp) (imm nextPc : Word) :
    generatedBody env frame arena s fresh op imm nextPc = bodySpec env frame arena s fresh op imm nextPc := by
  simp only [generatedBody, bodySpec, x86_call_mem_kind_refines,
    generated_x86_call_mem_count_refines, ordered_loop_refines, helper_clobbers_frame]

def opcode : X86CallMemOp → GeneratedX86Opcode.Op
  | .callMemcpy => .callMemcpy | .callMemcpyReg => .callMemcpyReg
  | .callMemset => .callMemset | .callMemsetReg => .callMemsetReg

def token : X86CallMemOp → GeneratedX86Specialization.Op
  | .callMemcpy => .callMemcpy | .callMemcpyReg => .callMemcpyReg
  | .callMemset => .callMemset | .callMemsetReg => .callMemsetReg

def callPrefix (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (arena : Word) (s : Frame) (fresh : Fresh)
    (code : Nat) (imm nextPc : Word) : Option Frame :=
  if code = GeneratedX86Opcode.code .callMemset then some (generatedBody env frame arena s fresh .callMemset imm nextPc)
  else if code = GeneratedX86Opcode.code .callMemcpy then some (generatedBody env frame arena s fresh .callMemcpy imm nextPc)
  else if code = GeneratedX86Opcode.code .callMemsetReg then some (generatedBody env frame arena s fresh .callMemsetReg imm nextPc)
  else if code = GeneratedX86Opcode.code .callMemcpyReg then some (generatedBody env frame arena s fresh .callMemcpyReg imm nextPc)
  else none

theorem call_mem_token_identity (op : X86CallMemOp) :
    GeneratedX86Specialization.dispatch (token op) = .directMacro ∧
    GeneratedX86Specialization.tokenName (token op) = GeneratedX86Opcode.define (opcode op) := by
  cases op <;> decide

theorem call_mem_token_body_matches (env : Refinement.EntryEnvironment.Environment)
    (frame : Refinement.EntryEnvironment.Frame) (arena : Word) (s : Frame) (fresh : Fresh)
    (op : X86CallMemOp) (imm nextPc : Word) :
    callPrefix env frame arena s fresh (GeneratedX86Opcode.code (opcode op)) imm nextPc =
      some (bodySpec env frame arena s fresh op imm nextPc) := by
  cases op <;> simp [callPrefix, opcode, GeneratedX86Opcode.code, call_mem_body_refines]

end X86CallMemBody

end KProgFormal
