import KProgFormal.GeneratedX86PtrWrite
import KProgFormal.GeneratedPtrAdd
import KProgFormal.TagErasure
import KProgFormal.X86MovHandler
import KProgFormal.X86RegWrite
import KProgFormal.X86StoreHandler
import KProgFormal.X86Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86PtrWrite (Op code tagOf tagOfSelectors width64)

/-- Destination register state of the x86-64 pointer-write opcodes
`X86_OP_MOV_LOAD_MAP_PTR` and `X86_OP_MOV_LOAD_HELPER_ID`. Both bodies write one
register's pointer bits and provenance tag and define no flags. -/
structure X86PtrWriteState where
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- The two opcodes this contract spans: the map-pointer load installs pointer
bits with the map-pointer tag, the helper-id load performs a width-64 scalar
lane write and then installs the same pointer bits with the helper-id tag. -/
inductive X86PtrWriteOp
  | mapPtr
  | helperId
  deriving DecidableEq, Repr

/-- Bridge from the handler's opcode type to the generated table's, so the
generated tag and width-64 tables can be indexed. -/
def x86PtrWriteToOp : X86PtrWriteOp -> GeneratedX86PtrWrite.Op
  | .mapPtr => .movLoadMapPtr
  | .helperId => .movLoadHelperId

/-- Bridge from the generated tag type to the simulator's provenance tag type.
The generated table carries exactly the three tags a pointer write can install;
the simulator's `Tag` carries the full tag space, so the bridge is injective but
not surjective. -/
def x86PtrWriteTagOf : GeneratedX86PtrWrite.Tag -> KProgFormal.Tag
  | .scalar => .scalar
  | .mapPtr => .mapPtr
  | .helperId => .helperId

/-- Independent statement of the tag each opcode installs, written directly
rather than read from the generated table: the map-pointer load installs the
map-pointer tag, the helper-id load the helper-id tag. -/
def x86PtrWriteTagSpec : X86PtrWriteOp -> KProgFormal.Tag
  | .mapPtr => .mapPtr
  | .helperId => .helperId

/-- The generated opcode-to-tag table agrees with the independent statement for
both opcodes. -/
theorem x86_ptr_write_tag_refines (op : X86PtrWriteOp) :
    x86PtrWriteTagOf (tagOf (x86PtrWriteToOp op)) = x86PtrWriteTagSpec op := by
  cases op <;> rfl

/-- Independent statement of the tag codes, read from the simulator's raw
`X86_SIM_TAG_*` values rather than from the generated table: code 0 is the
scalar tag, 5 the map-pointer tag, 7 the helper-id tag, and every other code is
outside the pointer-write tag space. -/
def x86PtrWriteTagCodeSpec : Nat -> Option KProgFormal.Tag
  | 0 => some .scalar
  | 5 => some .mapPtr
  | 7 => some .helperId
  | _ => none

/-- **Generated-versus-independent bridge for the tag codes.** The generated
`code` table composed with the type bridge is exactly the independent raw-code
statement, for all three tags: a tag code is not a width, and the three codes
the contract carries are the sim's own `X86_SIM_TAG_SCALAR`/`_MAP_PTR`/
`_HELPER_ID` values. -/
theorem x86_ptr_write_tag_code_refines (t : GeneratedX86PtrWrite.Tag) :
    x86PtrWriteTagCodeSpec (code t) = some (x86PtrWriteTagOf t) := by
  cases t <;> rfl

/-- Independent statement of the tag selector: the map-pointer test first, then
the helper-id test, and no tag when neither fact holds — the C `if/else if`
chain's fallthrough. -/
def x86PtrWriteTagSelectSpec (isMapPtr isHelperId : Bool) :
    Option KProgFormal.Tag :=
  if isMapPtr then some .mapPtr
  else if isHelperId then some .helperId
  else none

/-- The generated selector agrees with the independent nesting for all four
fact pairs; composing with the type bridge gives the raw-code statement. -/
theorem x86_ptr_write_tag_select_refines (isMapPtr isHelperId : Bool) :
    (tagOfSelectors isMapPtr isHelperId).map x86PtrWriteTagOf =
      x86PtrWriteTagSelectSpec isMapPtr isHelperId := by
  cases isMapPtr <;> cases isHelperId <;> rfl

/-- Both tags the opcode table selects are reachable and neither is the scalar
tag, so no pointer-write opcode scalarizes its provenance. -/
theorem x86_ptr_write_tag_all_reachable :
    x86PtrWriteTagSpec .mapPtr = .mapPtr ∧
      x86PtrWriteTagSpec .helperId = .helperId ∧
      x86PtrWriteTagSpec .mapPtr ≠ .scalar ∧
      x86PtrWriteTagSpec .helperId ≠ .scalar := by
  refine ⟨rfl, rfl, ?_, ?_⟩ <;> decide

/-- Independent statement of the width-64 test: only the helper-id opcode
performs the preliminary width-64 scalar lane write; the map-pointer opcode
writes no width at all. -/
def x86PtrWriteWidth64Spec : X86PtrWriteOp -> Bool
  | .mapPtr => false
  | .helperId => true

/-- The generated width-64 table agrees with the independent statement. -/
theorem x86_ptr_write_width64_refines (op : X86PtrWriteOp) :
    width64 (x86PtrWriteToOp op) = x86PtrWriteWidth64Spec op := by
  cases op <;> rfl

/-- The map-pointer opcode writes no width: its register write installs the
pointer bits and tag alone, so no lane is ever confined. -/
theorem x86_ptr_write_map_ptr_writes_no_width :
    x86PtrWriteWidth64Spec .mapPtr = false := by
  rfl

/-- Independent statement of the pointer bits both opcodes install: the *whole*
instruction-immediate artifact, cast to the pointer width. On x86-64 the
pointer is 64 bits, so the cast `(void *)(long)IMM` is the identity on all 64
bits — there is no shift and no truncation. -/
def x86PtrWriteBitsSpec (imm : BitVec 64) : BitVec 64 := imm

/-- Pointer writeback used by both opcodes after the value and the tag have been
selected: exactly the composition the 64-bit `MOV` path uses, the destination
receiving the pointer unchanged and the selected tag. -/
def generatedX86PtrWriteState (state : X86PtrWriteState) (value : BitVec 64)
    (tag : KProgFormal.Tag) : X86PtrWriteState :=
  { dst := (generatedX86MovPointerWrite { dst := state.dst } value tag).dst }

/-- Independent statement of the same writeback. -/
def x86PtrWriteStateSpec (state : X86PtrWriteState) (value : BitVec 64)
    (tag : KProgFormal.Tag) : X86PtrWriteState :=
  { state with dst := { bits := value, tag := tag } }

/-- The pointer writeback composes the already-proven 64-bit `MOV` pointer
write: the generated side inherits its refinement, so the destination receives
the value's whole 64 bits and the selected tag. -/
theorem x86_ptr_write_state_refines (state : X86PtrWriteState)
    (value : BitVec 64) (tag : KProgFormal.Tag) :
    generatedX86PtrWriteState state value tag =
      x86PtrWriteStateSpec state value tag := by
  cases state with
  | mk dst =>
      simp [generatedX86PtrWriteState, x86PtrWriteStateSpec,
        generatedX86MovPointerWrite, x86MovPointerWriteSpec,
        GeneratedPtrAdd.bits, GeneratedPtrAdd.tag]

/-- Composition used by the x86-64 pointer-write opcodes after the opcode, the
destination register's identity, and the instruction-immediate artifact have
been decoded. A `X86_REG_NONE` destination writes nothing (the C register
switch's `default: break;` arm). Otherwise the generated tag table selects the
provenance tag, the whole immediate is the pointer bits, and — for the helper-id
opcode only — a width-64 scalar lane write runs first, which the pointer write
then replaces bit for bit. -/
def generatedX86PtrWriteStep (state : X86PtrWriteState) (op : X86PtrWriteOp)
    (dstIsNone : Bool) (imm : BitVec 64) : X86PtrWriteState :=
  if dstIsNone then state
  else
    let tag := x86PtrWriteTagOf (tagOf (x86PtrWriteToOp op))
    let value := x86PtrWriteBitsSpec imm
    if width64 (x86PtrWriteToOp op) then
      let afterScalar := generatedX86RegWrite state.dst value .w64
      generatedX86PtrWriteState { dst := afterScalar } value tag
    else
      generatedX86PtrWriteState state value tag

/-- Independent statement of the same handler: the tag is the independent tag
statement, the pointer bits are the whole artifact, and the writeback is the
independent pointer write statement. The preliminary scalar lane write of the
helper-id opcode is stated as the partial-register write it is. -/
def x86PtrWriteStepSpec (state : X86PtrWriteState) (op : X86PtrWriteOp)
    (dstIsNone : Bool) (imm : BitVec 64) : X86PtrWriteState :=
  if dstIsNone then state
  else
    let tag := x86PtrWriteTagSpec op
    let value := x86PtrWriteBitsSpec imm
    if x86PtrWriteWidth64Spec op then
      let afterScalar := x86RegWriteSpec state.dst value .w64
      x86PtrWriteStateSpec { dst := afterScalar } value tag
    else
      x86PtrWriteStateSpec state value tag

/-- The pointer-write handler composition refines the independent
tag/pointer-bits/writeback statement for arbitrary destination state, opcode,
destination identity, and instruction-immediate artifact. -/
theorem x86_ptr_write_step_refines (state : X86PtrWriteState)
    (op : X86PtrWriteOp) (dstIsNone : Bool) (imm : BitVec 64) :
    generatedX86PtrWriteStep state op dstIsNone imm =
      x86PtrWriteStepSpec state op dstIsNone imm := by
  cases op <;> cases dstIsNone <;>
    simp only [generatedX86PtrWriteStep, x86PtrWriteStepSpec,
      x86_ptr_write_tag_refines, x86_ptr_write_width64_refines,
      x86PtrWriteWidth64Spec, x86PtrWriteBitsSpec, x86PtrWriteToOp,
      x86PtrWriteTagSpec, GeneratedX86PtrWrite.tagOf,
      GeneratedX86PtrWrite.width64, x86PtrWriteTagOf,
      x86_ptr_write_state_refines, x86_reg_write_refines,
      reduceCtorEq, ↓reduceIte]

/-- The two sides agree on both the pointer bits and the provenance tag: the
destination receives the whole immediate, and the tag is the one the opcode
table selects. -/
theorem x86_ptr_write_step_fields (state : X86PtrWriteState)
    (op : X86PtrWriteOp) (imm : BitVec 64) :
    (x86PtrWriteStepSpec state op false imm).dst.bits =
        x86PtrWriteBitsSpec imm ∧
      (x86PtrWriteStepSpec state op false imm).dst.tag =
        x86PtrWriteTagSpec op := by
  cases op <;>
    simp [x86PtrWriteStepSpec, x86PtrWriteWidth64Spec, x86PtrWriteStateSpec,
      x86PtrWriteBitsSpec, x86RegWriteSpec]

/-- The pointer bits both opcodes install are the whole artifact, definitionally. -/
theorem x86_ptr_write_bits_spec_is_id (imm : BitVec 64) :
    x86PtrWriteBitsSpec imm = imm := by
  rfl

/-- The pointer bits are the *whole* instruction-immediate artifact at both
opcodes: no 32-bit truncation and no high-half slice, the shape the immediate
store's `(s32)((IMM) >> 32)` displacement has and this contract does not. -/
theorem x86_ptr_write_bits_whole_artifact_example :
    x86PtrWriteBitsSpec 0x80000010deadbeef = 0x80000010deadbeef ∧
      x86StoreDispSpec true 0x80000010deadbeef = 0xffffffff80000010 := by
  decide

/-- A `X86_REG_NONE` destination writes nothing at all: neither the pointer
bits nor the tag of the destination change, the C register switch's
`default: break;` arm. -/
theorem x86_ptr_write_none_fallthrough (state : X86PtrWriteState)
    (op : X86PtrWriteOp) (imm : BitVec 64) :
    generatedX86PtrWriteStep state op true imm = state ∧
      x86PtrWriteStepSpec state op true imm = state := by
  cases op <;> exact ⟨rfl, rfl⟩

/-- The helper-id opcode's preliminary width-64 scalar lane write is absorbed:
because the pointer write installs the whole 64-bit value and the tag
afterwards, the observed destination is the pointer write alone, for every
starting destination state. -/
theorem x86_ptr_write_helper_id_absorbs_scalar (state : X86PtrWriteState)
    (imm : BitVec 64) :
    generatedX86PtrWriteStep state .helperId false imm =
      x86PtrWriteStateSpec state imm .helperId := by
  simp [generatedX86PtrWriteStep, x86PtrWriteBitsSpec,
    x86PtrWriteTagOf, GeneratedX86PtrWrite.tagOf,
    GeneratedX86PtrWrite.width64, x86PtrWriteToOp,
    x86_ptr_write_state_refines, x86PtrWriteStateSpec,
    x86RegWriteSpec, x86RegWriteBitsSpec]

/-- The map-pointer opcode reaches no scalar lane write at all: its step is the
pointer write directly, so no width from the shared dispatch chain's
`FLAGS ? FLAGS : 64` resolution touches the destination. -/
theorem x86_ptr_write_map_ptr_no_scalar_write (state : X86PtrWriteState)
    (imm : BitVec 64) :
    generatedX86PtrWriteStep state .mapPtr false imm =
      x86PtrWriteStateSpec state imm .mapPtr := by
  simp [generatedX86PtrWriteStep, x86PtrWriteBitsSpec,
    x86PtrWriteTagOf, GeneratedX86PtrWrite.tagOf,
    GeneratedX86PtrWrite.width64, x86PtrWriteToOp,
    x86_ptr_write_state_refines, x86PtrWriteStateSpec]

/-- Neither pointer-write opcode scalarizes the destination's provenance: the
installed tag is the map-pointer or helper-id tag for every immediate and every
starting state. -/
theorem x86_ptr_write_never_scalarizes (state : X86PtrWriteState)
    (op : X86PtrWriteOp) (imm : BitVec 64) :
    (x86PtrWriteStepSpec state op false imm).dst.tag ≠ .scalar := by
  cases op <;>
    simp [x86PtrWriteStepSpec, x86PtrWriteWidth64Spec, x86PtrWriteStateSpec,
      x86PtrWriteTagSpec, x86RegWriteSpec]

/-- Canonical example: the map-pointer opcode installs the whole immediate as
the pointer bits and the map-pointer tag, leaving the starting bits behind. -/
theorem x86_ptr_write_map_ptr_example :
    generatedX86PtrWriteStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .stack } }
      .mapPtr false 0x0000000000000042 =
      { dst := { bits := 0x0000000000000042, tag := .mapPtr } } := by
  decide

/-- Canonical example: the helper-id opcode installs the whole immediate and the
helper-id tag; the width-64 scalar lane write it performs first is invisible in
the result. -/
theorem x86_ptr_write_helper_id_example :
    generatedX86PtrWriteStep
      { dst := { bits := 0, tag := .abi } }
      .helperId false 0x0000000000000007 =
      { dst := { bits := 0x0000000000000007, tag := .helperId } } := by
  decide

/-- Canonical example: a `X86_REG_NONE` destination is left untouched, so a
resolved-but-unencoded register costs no state change. -/
theorem x86_ptr_write_none_example :
    generatedX86PtrWriteStep
      { dst := { bits := 0x1122334455667788, tag := .mapValue } }
      .mapPtr true 0xff =
      { dst := { bits := 0x1122334455667788, tag := .mapValue } } := by
  decide

/-- Canonical example: the two opcodes install different tags for the same
immediate, so the tag table is observable — the map-pointer and helper-id
opcodes are not interchangeable. -/
theorem x86_ptr_write_tag_differs_example :
    (generatedX86PtrWriteStep { dst := { bits := 0, tag := .scalar } }
        .mapPtr false 0x10).dst.tag ≠
      (generatedX86PtrWriteStep { dst := { bits := 0, tag := .scalar } }
        .helperId false 0x10).dst.tag := by
  decide

end KProgFormal
