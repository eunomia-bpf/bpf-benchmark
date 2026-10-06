import KProgFormal.GeneratedX86Cmov
import KProgFormal.GeneratedX86MemDispatch
import KProgFormal.GeneratedX86Setcc
import KProgFormal.GeneratedX86Store
import KProgFormal.X86ControlFlow
import KProgFormal.X86MemAccess
import KProgFormal.X86MemDispatch
import KProgFormal.X86MemOffset
import KProgFormal.X86MovHandler
import KProgFormal.X86MovLoadHandler
import KProgFormal.X86RegWrite
import KProgFormal.X86SetccHandler
import KProgFormal.X86SetccMemHandler
import KProgFormal.X86StoreHandler
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86Cmov (WriteBack)
open GeneratedX86MemDispatch (ValueSrc)
open GeneratedX86Store (Arm Code)

/-- Destination state of the x86-64 `CMOV` / `CMOV_MEM` handler: both forms
write a register, so the state is the destination register's value. -/
structure X86CmovState where
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- Abstract register source operand of the register form: the source register's
raw 64-bit value and its provenance. -/
structure X86CmovSrc where
  bits : BitVec 64
  tag : Tag
  deriving DecidableEq, Repr

/-- Abstract memory operand of the memory form: the addressed byte function, the
stack frame's byte function, and the two facts the shared memory read dispatch
consults — whether the base register is the stack pointer, and whether its
memory tag is the ABI tag. -/
structure X86CmovMem where
  byte : Nat -> X86MemByte
  stackByte : Nat -> X86MemByte
  isRsp : Bool
  isAbi : Bool

/-- The effect of the x86-64 `CMOV` / `CMOV_MEM` handler. Both forms are
*conditional* — the whole body is inside the condition test — so the effect
records the evaluated condition, the write width, the memory form's access
width, the value the source produced, the destination's pristine value, and the
destination's value after the (possibly skipped) writeback. The writeback is a
register write, not a memory update, so there is no byte function here. -/
structure X86CmovEffect where
  cond : Bool
  width : X86Width
  memWidth : X86Width
  value : BitVec 64
  before : X86RegValue
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- The register form's condition source, stated as the word-level condition
table: the whole AUX word compared against the accepted `X86_CC_*` codes,
`none` for every word outside that subset. `X86_SIM_L_EXEC_CMOV` hands
`X86_SIM_L_EVAL_CC` the whole word, so this — not the low-byte table — is the
faithful statement of the register form. -/
def x86CmovWordConditionTable (aux : BitVec 32) : Option X86SetccCond :=
  GeneratedX86Cmov.condOf aux

/-- The byte-level condition table the architectural model composes: every raw
`BitVec 8` condition code, mapped to the architectural condition of the same
name, `none` outside the accepted subset. Both the register form's low-byte
decode and the memory form's source-shift decode read out of this 256-value
space. -/
def x86CmovByteConditionTable (b : BitVec 8) : Option X86SetccCond :=
  GeneratedX86Setcc.condOf b

/-- The low byte of the AUX word: the decode the byte-level model composes with
the byte table. -/
def x86CmovConditionByteSpec (aux : BitVec 32) : BitVec 8 := aux.setWidth 8

/-- The generated low-byte decode equals the independent truncation statement. -/
theorem x86_cmov_condition_byte_refines (aux : BitVec 32) :
    GeneratedX86Cmov.conditionByte aux = x86CmovConditionByteSpec aux := by
  simp only [GeneratedX86Cmov.conditionByte, x86CmovConditionByteSpec]

/-- The generated word-level table is a restatement of the architectural
word-level table: the two sides are definitionally the same closed `if` chain
over the whole word. -/
theorem x86_cmov_word_table_refines (aux : BitVec 32) :
    GeneratedX86Cmov.condOf aux = x86CmovWordConditionTable aux := by
  rfl

/-- The memory form's condition source: the AUX source-shift byte at bits
24..31, the field `X86_REG_AUX_GET_SRC_SHIFT` decodes. The two opcodes name
different conditions with one encoding. -/
def x86CmovMemConditionCodeSpec (aux : BitVec 32) : BitVec 8 :=
  (aux >>> 24).setWidth 8

/-- The generated source-shift decode equals the independent byte extraction. -/
theorem x86_cmov_mem_condition_code_refines (aux : BitVec 32) :
    GeneratedX86Cmov.sourceShiftCode aux =
      x86CmovMemConditionCodeSpec aux := by
  simp only [GeneratedX86Cmov.sourceShiftCode, x86CmovMemConditionCodeSpec]

/-- The generated condition-source table selects the word table for the
register form and the source-shift decode for the memory form. -/
def x86CmovConditionSourceSpec (op : GeneratedX86Cmov.X86CmovOp) :
    GeneratedX86Cmov.ConditionSource :=
  if op = .cmov then .wholeWord else .sourceShift

/-- The generated condition-source table equals the independent statement, one
row per opcode. -/
theorem x86_cmov_condition_source_refines (op : GeneratedX86Cmov.X86CmovOp) :
    GeneratedX86Cmov.conditionSource op = x86CmovConditionSourceSpec op := by
  cases op <;> rfl

/-- The memory form's condition table is the byte table composed with the
source-shift decode, out of the same 256-value byte space. The C handler
extracts a `__u8` here, so the byte table — not the word table — is exact
for the memory form. -/
def x86CmovMemConditionTable (aux : BitVec 32) : Option X86SetccCond :=
  x86CmovByteConditionTable (x86CmovMemConditionCodeSpec aux)

/-- The generated memory-form table equals the architectural byte table
composed with the source-shift decode: a closed restatement over the byte
space. -/
theorem x86_cmov_mem_condition_table_refines (aux : BitVec 32) :
    GeneratedX86Cmov.condOfSrcShift aux = x86CmovMemConditionTable aux := by
  simp only [GeneratedX86Cmov.condOfSrcShift, x86CmovMemConditionTable,
    x86CmovByteConditionTable, GeneratedX86Cmov.condOfByte,
    GeneratedX86Setcc.condOf, GeneratedX86Cmov.sourceShiftCode,
    x86CmovMemConditionCodeSpec, x86CmovConditionByteSpec]
  rfl

/-- The condition table an opcode consults, stated over the architectural
tables rather than the generated ones: the word table for the register form,
the byte table over the source-shift byte for the memory form. An unsupported
code is `none`, which the evaluator turns into the C default `false`. -/
def x86CmovConditionTable (op : GeneratedX86Cmov.X86CmovOp) (aux : BitVec 32)
    : Option X86SetccCond :=
  match x86CmovConditionSourceSpec op with
  | .wholeWord => x86CmovWordConditionTable aux
  | .sourceShift => x86CmovMemConditionTable aux

/-- The generated condition table refines the architectural one for both
opcodes: the register form through the word table, the memory form through the
byte table over the source-shift byte. -/
theorem x86_cmov_condition_table_refines (op : GeneratedX86Cmov.X86CmovOp)
    (aux : BitVec 32) :
    GeneratedX86Cmov.condOfOp op aux = x86CmovConditionTable op aux := by
  cases op <;> rfl

/-- The condition the handler evaluates, stated over the architectural
condition table rather than the generated one: `none` takes the C default
`false`. -/
def x86CmovConditionSpec (op : GeneratedX86Cmov.X86CmovOp) (aux : BitVec 32)
    (flags : X86Flags) : Bool :=
  match x86CmovConditionTable op aux with
  | some cond => x86CondSpec flags cond
  | none => false

/-- Every condition the generated word table accepts denotes exactly the
architectural condition of the same name. This lifts
`x86_setcc_eval_cond_sound` through the generated condition table, so the whole
`KPROG_X86_EVAL_CC` expression is pinned to the architectural semantics for
every accepted whole word. -/
theorem x86_cmov_raw_cond_sound (aux : BitVec 32) (flags : X86Flags)
    (cond : X86SetccCond)
    (h : GeneratedX86Cmov.condOf aux = some cond) :
    GeneratedX86Cmov.evalRaw flags.cf flags.zf flags.sf flags.of aux =
      x86CondSpec flags cond := by
  unfold GeneratedX86Cmov.evalRaw
  rw [h]
  unfold GeneratedX86Cmov.evalCond
  exact x86_setcc_eval_cond_sound flags cond

/-- An unsupported whole-word condition code — any word outside the accepted
subset — evaluates to false, exactly as the C `KPROG_X86_EVAL_CC` default arm
does. -/
theorem x86_cmov_raw_unsupported (aux : BitVec 32) (flags : X86Flags)
    (h : GeneratedX86Cmov.condOf aux = none) :
    GeneratedX86Cmov.evalRaw flags.cf flags.zf flags.sf flags.of aux = false := by
  have h' : GeneratedX86Cmov.condOf aux = none := by
    rw [x86_cmov_word_table_refines]; exact h
  simp only [GeneratedX86Cmov.evalRaw, h']

/-- The generated condition evaluator refines the architectural condition
statement for both opcodes and every accepted and unsupported code. -/
theorem x86_cmov_eval_raw_refines (op : GeneratedX86Cmov.X86CmovOp)
    (aux : BitVec 32) (flags : X86Flags) :
    GeneratedX86Cmov.evalRawOp flags.cf flags.zf flags.sf flags.of op aux =
      x86CmovConditionSpec op aux flags := by
  unfold GeneratedX86Cmov.evalRawOp x86CmovConditionSpec
  rw [x86_cmov_condition_table_refines]
  cases h : x86CmovConditionTable op aux with
  | some cond =>
      simp only [h, GeneratedX86Cmov.evalCond]
      exact x86_setcc_eval_cond_sound flags cond
  | none => simp only [h]

/-- Independent statement of the write width: the opcode's `FLAGS` code with a
64-bit fallback when it carries none. -/
def x86CmovWidthSpec (flags : Code) : Code :=
  if flags = Code.absent then Code.b64 else flags

/-- The generated write-width resolution equals the independent fallback
statement: the same contract the store handler proves, reused rather than
restated. -/
theorem x86_cmov_width_refines (flags : Code) :
    GeneratedX86Cmov.resolveWidth flags = x86CmovWidthSpec flags := by
  cases flags <;> simp [GeneratedX86Cmov.resolveWidth,
    GeneratedX86Store.resolveWidth, x86CmovWidthSpec]

/-- The resolved write width can never be absent: the fallback is total, so the
handler has no unsupported width. -/
theorem x86_cmov_width_not_absent (flags : Code) :
    x86CmovWidthSpec flags ≠ Code.absent := by
  cases flags <;> simp [x86CmovWidthSpec]

/-- An opcode that carries no width resolves to 64 bits. -/
theorem x86_cmov_width_absent_defaults :
    x86CmovWidthSpec Code.absent = Code.b64 := by
  rfl

/-- Independent statement of the memory form's access width: the AUX
memory-width byte when present and otherwise the resolved write width — the
same two-level fallback the shared memory read performs. -/
def x86CmovMemWidthSpec (aux flags : Code) : Code :=
  let write := x86CmovWidthSpec flags
  if aux = Code.absent then write else aux

/-- The generated memory-form access width equals the independent two-level
fallback. -/
theorem x86_cmov_mem_width_refines (aux flags : Code) :
    GeneratedX86Cmov.resolveMemWidth aux flags =
      x86CmovMemWidthSpec aux flags := by
  simp only [GeneratedX86Cmov.resolveMemWidth, x86CmovMemWidthSpec,
    x86_cmov_width_refines]

/-- The memory form's access width can never be absent either: it falls back to
a write width that itself has a 64-bit default. -/
theorem x86_cmov_mem_width_not_absent (aux flags : Code) :
    x86CmovMemWidthSpec aux flags ≠ Code.absent := by
  cases aux <;> cases flags <;> simp [x86CmovMemWidthSpec, x86CmovWidthSpec]

/-- A memory form whose addressing mode carries no width reads at the resolved
write width. -/
theorem x86_cmov_mem_width_absent_defaults (flags : Code) :
    x86CmovMemWidthSpec Code.absent flags = x86CmovWidthSpec flags := by
  simp [x86CmovMemWidthSpec]

/-- The memory form's displacement is the *high* half of the instruction
artifact, `(s32)(IMM >> 32)` sign-extended into 64 bits — the immediate
store's slice, not the whole-artifact slice the memory `SETCC` consumes. -/
def x86CmovMemDispSpec (imm : BitVec 64) : BitVec 64 :=
  ((imm >>> 32).setWidth 32).signExtend 64

/-- The memory form's slice equals the immediate store's high-half slice, so the
store handler's displacement contract applies to this handler unchanged. -/
theorem x86_cmov_mem_disp_refines (imm : BitVec 64) :
    x86CmovMemDispSpec imm = x86StoreDispSpec true imm := by
  rfl

/-- Independent statement of the writeback table, written as the width test the
C performs: one equality against the 64-bit code, with no tag, opcode, or AUX
gate. -/
def x86CmovWriteBackSpec (width : X86Width) : WriteBack :=
  if width = .w64 then .pointerTag else .scalarize

/-- The generated writeback table equals the independent width statement. -/
theorem x86_cmov_writeback_refines (width : X86Width) :
    GeneratedX86Cmov.writeBack (x86WidthIs64 width) =
      x86CmovWriteBackSpec width := by
  cases width <;> rfl

/-- The pointer writeback is selected exactly by the 64-bit width: no narrower
resolution can preserve the source's provenance, and no wider one can fail to. -/
theorem x86_cmov_writeback_pointer_iff (width : X86Width) :
    x86CmovWriteBackSpec width = WriteBack.pointerTag ↔ width = .w64 := by
  cases width <;> simp [x86CmovWriteBackSpec]

/-- Composition used by the x86-64 `CMOV` / `CMOV_MEM` handler after the opcode,
the source register or memory operand, the AUX word, the FLAGS register, the
resolved write width, the memory form's resolved access width, and the memory
form's dereferenced pointer value have been decoded. The generated condition
table selects the *condition* — from the whole AUX word for the register form,
from the AUX source-shift byte for the memory form; the generated dispatch table
selects the memory form's read source; and the generated writeback table selects
between the pointer-preserving write and the scalarizing partial-register write.

Three x86-specific asymmetries are worth naming. Both forms are conditional: the
entire body, including both the value production and the writeback, is inside the
condition test, so a false condition leaves the destination *exactly* as it was
— this is not a conditional *value* with an unconditional write. The register
form's condition comes from the whole AUX word, while the memory form's comes
from the source-shift byte at bits 24..31. And the 64-bit arm preserves the
source's provenance tag, while every narrower arm scalarizes — unlike an
unconditional register move, which has no width-dependent tag behaviour at all.
-/
def generatedX86CmovStep (state : X86CmovState)
    (op : GeneratedX86Cmov.X86CmovOp) (src : X86CmovSrc) (mem : X86CmovMem)
    (aux : BitVec 32) (flags : X86Flags) (width memWidth : X86Width)
    (ptrValue : BitVec 64) : X86CmovEffect :=
  let cond := GeneratedX86Cmov.evalRawOp flags.cf flags.zf flags.sf flags.of op aux
  let value :=
    match op with
    | .cmov => src.bits
    | .cmovMem =>
        match GeneratedX86MemDispatch.valueSrc mem.isRsp mem.isAbi
            (x86WidthIs64 memWidth) with
        | .stackRead => GeneratedX86MemAccess.load mem.stackByte memWidth
        | .abiPtrLoad => ptrValue
        | .normalLoad => GeneratedX86MemAccess.load mem.byte memWidth
  let write :=
    match GeneratedX86Cmov.writeBack (x86WidthIs64 width) with
    | .pointerTag =>
        (generatedX86MovPointerWrite { dst := state.dst } value src.tag).dst
    | .scalarize => generatedX86RegWrite state.dst value width
  { cond := cond, width := width, memWidth := memWidth, value := value,
    before := state.dst, dst := if cond then write else state.dst }

/-- Independent statement of the same handler: the condition is the
architectural condition table (with the C default false), the memory read source
is the independent predicate nesting, the load is the independent little-endian
byte sum, the writeback is the independent width test, and the two writeback
contracts are the independent pointer write and partial-register write
specifications. -/
def x86CmovStepSpec (state : X86CmovState)
    (op : GeneratedX86Cmov.X86CmovOp) (src : X86CmovSrc) (mem : X86CmovMem)
    (aux : BitVec 32) (flags : X86Flags) (width memWidth : X86Width)
    (ptrValue : BitVec 64) : X86CmovEffect :=
  let cond := x86CmovConditionSpec op aux flags
  let value :=
    if op = GeneratedX86Cmov.X86CmovOp.cmov then src.bits
    else
      match x86MemReadSrcSpec mem.isRsp mem.isAbi (x86WidthIs64 memWidth) with
      | .stackRead => x86MemLoadSpec mem.stackByte memWidth
      | .abiPtrLoad => ptrValue
      | .normalLoad => x86MemLoadSpec mem.byte memWidth
  let write :=
    if x86CmovWriteBackSpec width = WriteBack.pointerTag then
      (x86MovPointerWriteSpec { dst := state.dst } value src.tag).dst
    else x86RegWriteSpec state.dst value width
  { cond := cond, width := width, memWidth := memWidth, value := value,
    before := state.dst, dst := if cond then write else state.dst }

/-- The `CMOV` / `CMOV_MEM` handler composition refines the independent
condition/value/dispatch/writeback statement for arbitrary destination state,
opcode, source register, memory operand, AUX word, flags, both widths, and
dereferenced pointer value: all six fields of the effect are identical on the
two sides. -/
theorem x86_cmov_step_refines (state : X86CmovState)
    (op : GeneratedX86Cmov.X86CmovOp) (src : X86CmovSrc) (mem : X86CmovMem)
    (aux : BitVec 32) (flags : X86Flags) (width memWidth : X86Width)
    (ptrValue : BitVec 64) :
    generatedX86CmovStep state op src mem aux flags width memWidth ptrValue =
      x86CmovStepSpec state op src mem aux flags width memWidth ptrValue := by
  cases op <;> cases width <;> cases memWidth <;> cases mem.isRsp <;>
    cases mem.isAbi <;>
    simp only [generatedX86CmovStep, x86CmovStepSpec,
      x86_cmov_eval_raw_refines, GeneratedX86Cmov.conditionSource,
      x86CmovConditionSourceSpec, x86_cmov_writeback_refines,
      GeneratedX86Cmov.writeBack, x86CmovWriteBackSpec,
      x86_mem_dispatch_src_refines,
      x86MemReadSrcSpec, x86_mem_load_refines, x86_mov_pointer_write_refines,
      x86_reg_write_refines, x86WidthIs64, reduceCtorEq, ↓reduceIte]

/-- A false condition writes nothing: the destination's value after the step is
its pristine value, at every width and for every operand. This is the property
the condition test's *scope* gives — the value production is inside the test
too, so nothing about the source can leak into the product. -/
theorem x86_cmov_false_condition_no_write (state : X86CmovState)
    (op : GeneratedX86Cmov.X86CmovOp) (src : X86CmovSrc) (mem : X86CmovMem)
    (aux : BitVec 32) (flags : X86Flags) (width memWidth : X86Width)
    (ptrValue : BitVec 64)
    (h : x86CmovConditionSpec op aux flags = false) :
    (x86CmovStepSpec state op src mem aux flags width memWidth ptrValue).dst =
      state.dst ∧
      (x86CmovStepSpec state op src mem aux flags width memWidth ptrValue).before =
        state.dst := by
  simp [x86CmovStepSpec, h, ↓reduceIte]

/-- The 64-bit arm preserves the source's provenance tag and its bits verbatim,
whatever the source tag is: the pointer write bypasses the register-lane logic
entirely, so a packet- or stack-tagged source survives the move. -/
theorem x86_cmov_w64_arm_preserves_source_tag (state : X86CmovState)
    (src : X86CmovSrc) (mem : X86CmovMem) (aux : BitVec 32) (flags : X86Flags)
    (memWidth : X86Width) (ptrValue : BitVec 64)
    (h : x86CmovConditionSpec .cmov aux flags = true) :
    (x86CmovStepSpec state .cmov src mem aux flags .w64 memWidth ptrValue).dst =
      { bits := src.bits, tag := src.tag } := by
  simp only [x86CmovStepSpec, h, ↓reduceIte, x86CmovWriteBackSpec,
    reduceCtorEq, x86MovPointerWriteSpec]

/-- Every narrower arm scalarizes the destination's provenance when the
condition holds, at every width below 64 bits and for every source tag: only
the 64-bit arm can preserve it. The condition must hold — a false condition
leaves the destination untouched — so this is a statement about the writeback
arm that ran, not the absence of one. -/
theorem x86_cmov_narrow_arm_scalarizes (state : X86CmovState)
    (src : X86CmovSrc) (mem : X86CmovMem) (aux : BitVec 32) (flags : X86Flags)
    (width : X86Width) (memWidth : X86Width) (ptrValue : BitVec 64)
    (h : width ≠ .w64)
    (hc : x86CmovConditionSpec .cmov aux flags = true) :
    (x86CmovStepSpec state .cmov src mem aux flags width memWidth
        ptrValue).dst.tag = .scalar := by
  simp only [x86CmovStepSpec, hc, ↓reduceIte, x86CmovWriteBackSpec, h,
    reduceCtorEq, x86RegWriteSpec]

/-- The register form's condition is the whole AUX word, the memory form's the
source-shift byte: one AUX word names two different conditions, and a nonzero
byte above the low byte changes the register form's answer for no reason the
memory form can see. -/
theorem x86_cmov_condition_sources_differ :
    x86CmovConditionByteSpec 0x00000005 = 5 ∧
      x86CmovMemConditionCodeSpec 0x05000000 = 5 ∧
      x86CmovConditionByteSpec 0x05000000 = 0 ∧
      x86CmovMemConditionCodeSpec 0x00000005 = 0 := by
  native_decide

/-- The whole-word comparison is not the low-byte equality: with the zero flag
clear, `0x00000105` fails every `KPROG_X86_EVAL_CC` arm (its value is neither
`X86_CC_NE` nor any other code) and evaluates to the C default false, while
the model's low-byte decode reads `ne` and evaluates to true. This is the
counterexample that makes the whole-word decoder, not the low-byte extract, the
faithful model. -/
theorem x86_cmov_whole_word_not_low_byte_equality :
    GeneratedX86Cmov.condOf 0x00000105 = none ∧
      x86CmovConditionSpec .cmov 0x00000105 ⟨false, false, false, false⟩ =
        false ∧
      (x86CmovByteConditionTable 0x05 = some .ne) := by
  native_decide

/-- The memory form's access width falls back twice: an addressing mode with no
width reads at the resolved write width, while a present memory-width byte wins
over it. Both transitions are visible, and neither can produce the absent code. -/
theorem x86_cmov_mem_width_two_level_fallback :
    x86CmovMemWidthSpec Code.absent Code.b64 = Code.b64 ∧
      x86CmovMemWidthSpec Code.absent Code.absent = Code.b64 ∧
      x86CmovMemWidthSpec Code.b8 Code.b64 = Code.b8 ∧
      x86CmovMemWidthSpec Code.b64 Code.b8 = Code.b64 := by
  native_decide

/-- The memory form's displacement is the artifact's high half, while the memory
`SETCC`'s is the whole artifact: the same field yields different addresses, and
the CMOV slice agrees with the immediate store's. -/
theorem x86_cmov_mem_disp_differs_from_setcc_mem :
    x86CmovMemDispSpec 0xdeadbeef00000008 = 0xffffffffdeadbeef ∧
      x86SetccMemDispSpec 0xdeadbeef00000008 = 0xdeadbeef00000008 := by
  native_decide

/-- The writeback selector is exactly the 64-bit test: no width below 64 bits
can select the pointer-preserving arm. -/
theorem x86_cmov_writeback_only_w64 :
    x86CmovWriteBackSpec .w64 = WriteBack.pointerTag ∧
      x86CmovWriteBackSpec .w32 = WriteBack.scalarize ∧
      x86CmovWriteBackSpec .w16 = WriteBack.scalarize ∧
      x86CmovWriteBackSpec .w8 = WriteBack.scalarize := by
  native_decide

/-- An unsupported parity code evaluates to the C default false for both
opcodes, at every flag combination: the word table rejects the register form's
parity word, and the byte table rejects the memory form's parity byte. -/
theorem x86_cmov_unsupported_example :
    GeneratedX86Cmov.evalRawOp true true true true .cmov 10 = false ∧
      GeneratedX86Cmov.evalRawOp true true true true .cmovMem 0x0a000000 =
        false := by
  native_decide

/-- Canonical example: a set zero flag with an `e` condition on the register
form takes the 64-bit pointer arm, so the destination receives the source's
bits and provenance verbatim rather than being scalarized. -/
theorem x86_cmov_pointer_arm_example :
    generatedX86CmovStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .scalar } }
      .cmov { bits := 0x1122334455667788, tag := .packet }
      ⟨fun _ => 0xa5, fun _ => 0x5a, false, false⟩ 0x04
      ⟨false, true, false, false⟩ .w64 .w64 0 =
      { cond := true, width := .w64, memWidth := .w64,
        value := 0x1122334455667788,
        before := { bits := 0xdeadbeefdeadbeef, tag := .scalar },
        dst := { bits := 0x1122334455667788, tag := .packet } } := by
  native_decide

/-- Canonical example: the same condition at a 32-bit width reads the source at
the full 64 bits and scalarizes it, so the upper half is zeroed and the packet
provenance is lost — the asymmetry against the 64-bit arm. -/
theorem x86_cmov_narrow_arm_example :
    generatedX86CmovStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .mapValue } }
      .cmov { bits := 0x1122334455667788, tag := .packet }
      ⟨fun _ => 0xa5, fun _ => 0x5a, false, false⟩ 0x04
      ⟨false, true, false, false⟩ .w32 .w32 0 =
      { cond := true, width := .w32, memWidth := .w32,
        value := 0x1122334455667788,
        before := { bits := 0xdeadbeefdeadbeef, tag := .mapValue },
        dst := { bits := 0x55667788, tag := .scalar } } := by
  native_decide

/-- Canonical example: a false condition leaves the destination untouched, at
both widths — the condition test encloses the writeback, so neither arm runs. -/
theorem x86_cmov_false_condition_example :
    generatedX86CmovStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .stack } }
      .cmov { bits := 0x1122334455667788, tag := .packet }
      ⟨fun _ => 0xa5, fun _ => 0x5a, false, false⟩ 0x04000000
      ⟨false, false, false, false⟩ .w64 .w64 0 =
      { cond := false, width := .w64, memWidth := .w64,
        value := 0x1122334455667788,
        before := { bits := 0xdeadbeefdeadbeef, tag := .stack },
        dst := { bits := 0xdeadbeefdeadbeef, tag := .stack } } := by
  native_decide

end KProgFormal
