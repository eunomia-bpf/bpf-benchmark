import KProgFormal.X86RegWrite
import KProgFormal.X86MemOffset
import KProgFormal.TagErasure
import KProgFormal.GeneratedPtrAdd

namespace KProgFormal

/-- Destination register state of the x86 LEA handler. -/
structure X86LeaState where
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- Abstract source operand of the x86 LEA handler. `bits` is the source
register's raw 64-bit value (zero when the mode has no source register),
`tag` its provenance, `isNone` is true when the encoded source is
`X86_REG_NONE`, and `isRsp` is true when the encoded source is the stack
pointer. -/
structure X86LeaSrc where
  bits : BitVec 64
  tag : Tag
  isNone : Bool
  isRsp : Bool
  deriving DecidableEq, Repr

/-- Pointer writeback used by the 64-bit LEA path: the destination receives
the pointer sum and the (already selected) provenance tag, exactly as
`KPROG_PTR_ADD64_BITS`/`KPROG_PTR_ADD64_TAG` do. -/
def generatedX86LeaPointerWrite (state : X86LeaState) (ptr rhs : BitVec 64)
    (tag : Tag) : X86LeaState :=
  { state with dst := { bits := GeneratedPtrAdd.bits ptr rhs,
                        tag := GeneratedPtrAdd.tag tag } }

def x86LeaPointerWriteSpec (state : X86LeaState) (ptr rhs : BitVec 64)
    (tag : Tag) : X86LeaState :=
  { state with dst := { bits := ptr + rhs, tag := tag } }

theorem x86_lea_pointer_write_refines (state : X86LeaState)
    (ptr rhs : BitVec 64) (tag : Tag) :
    generatedX86LeaPointerWrite state ptr rhs tag =
      x86LeaPointerWriteSpec state ptr rhs tag := by
  cases state
  simp [generatedX86LeaPointerWrite, x86LeaPointerWriteSpec,
    GeneratedPtrAdd.bits, GeneratedPtrAdd.tag]

/-- Composition used by the x86 effective-address handler
(`X86_SIM_L_EXEC_LEA`) once the addressing mode and source operand have been
decoded. `rawImm` is the encoded immediate — `x86_simm` is the identity on
its 64 bits, so it doubles as the sign-extended displacement — `isRodata`
records whether the aux field is `X86_LEA_AUX_RODATA`, `hasIndex`/`scale`/
`index` are the decoded effective-address terms, and `stackBase` is the
abstract frame base the simulator's `X86_SIM_L_STACK_PTR` resolves to.

The handler has three exits: the 64-bit RODATA fast path writes the raw
immediate, the 64-bit pointer path sums the source pointer with the offset and
carries provenance (the stack tag on the stack-pointer path), and the
narrower paths truncate the summed pointer through the partial-register
writeback. -/
def generatedX86LeaStep (state : X86LeaState) (src : X86LeaSrc)
    (rawImm : BitVec 64) (isRodata : Bool) (width : X86Width)
    (hasIndex : Bool) (scale index stackBase : BitVec 64) : X86LeaState :=
  let off := GeneratedX86MemOffset.value hasIndex scale rawImm index
  match width with
  | .w64 =>
      if src.isNone && isRodata then
        { dst := generatedX86RegWrite state.dst rawImm .w64 }
      else if src.isRsp then
        generatedX86LeaPointerWrite state (stackBase + src.bits) off
          Tag.stack
      else
        generatedX86LeaPointerWrite state src.bits off src.tag
  | _ =>
      { dst := generatedX86RegWrite state.dst
          (GeneratedPtrAdd.bits src.bits off) width }

/-- Independent statement of the same handler: the effective-address offset is
the shared dedicated contract, and the three exits are stated separately. -/
def x86LeaStepSpec (state : X86LeaState) (src : X86LeaSrc)
    (rawImm : BitVec 64) (isRodata : Bool) (width : X86Width)
    (hasIndex : Bool) (scale index stackBase : BitVec 64) : X86LeaState :=
  let off := GeneratedX86MemOffset.valueSpec hasIndex scale rawImm index
  match width with
  | .w64 =>
      if src.isNone && isRodata then
        { dst := x86RegWriteSpec state.dst rawImm .w64 }
      else if src.isRsp then
        x86LeaPointerWriteSpec state (stackBase + src.bits) off Tag.stack
      else
        x86LeaPointerWriteSpec state src.bits off src.tag
  | _ =>
      { dst := x86RegWriteSpec state.dst (src.bits + off) width }

/-- The LEA handler composition refines the independent statement for
arbitrary destination state, source operand, decoded immediate, rodata flag,
destination width, and effective-address terms. The RODATA fast path and the
narrow-width exit both scalarize through the partial-register writeback; only
the 64-bit pointer exits carry provenance. -/
theorem x86_lea_step_refines (state : X86LeaState) (src : X86LeaSrc)
    (rawImm : BitVec 64) (isRodata : Bool) (width : X86Width)
    (hasIndex : Bool) (scale index stackBase : BitVec 64) :
    generatedX86LeaStep state src rawImm isRodata width hasIndex scale index
        stackBase =
      x86LeaStepSpec state src rawImm isRodata width hasIndex scale index
        stackBase := by
  unfold generatedX86LeaStep x86LeaStepSpec
  cases width <;> cases src.isNone <;> cases isRodata <;> cases src.isRsp <;>
    simp only [GeneratedPtrAdd.bits, GeneratedPtrAdd.tag,
      x86_mem_offset_refines, x86_lea_pointer_write_refines,
      x86_reg_write_refines]

/-- The RODATA fast path applies exactly when the mode is 64-bit, has no source
register, and carries the rodata aux value; it writes the raw immediate and
scalarizes provenance. -/
theorem x86_lea_rodata_fast_path (state : X86LeaState) (rawImm : BitVec 64)
    (hasIndex : Bool) (scale index stackBase : BitVec 64) :
    x86LeaStepSpec state
        { bits := 0, tag := .scalar, isNone := true, isRsp := false }
        rawImm true .w64 hasIndex scale index stackBase =
      { dst := { bits := rawImm, tag := .scalar } } := by
  simp [x86LeaStepSpec, GeneratedX86MemOffset.valueSpec, x86RegWriteSpec,
    x86RegWriteBitsSpec]

/-- A 64-bit mode that has a source register bypasses the RODATA fast path even
when the aux value is rodata: the source pointer is summed with the offset and
the source provenance is carried. -/
theorem x86_lea_rodata_needs_no_source (state : X86LeaState)
    (srcBits : BitVec 64) (srcTag : Tag) (rawImm : BitVec 64)
    (hasIndex : Bool) (scale index stackBase : BitVec 64) :
    x86LeaStepSpec state
        { bits := srcBits, tag := srcTag, isNone := false, isRsp := false }
        rawImm true .w64 hasIndex scale index stackBase =
      { dst := { bits := (srcBits + GeneratedX86MemOffset.valueSpec hasIndex scale rawImm index), tag := srcTag } } := by
  simp [x86LeaStepSpec, x86LeaPointerWriteSpec]

/-- The stack-pointer path resolves to the abstract frame base plus the source
value plus the offset and tags the result as stack provenance. -/
theorem x86_lea_rsp_uses_stack_base (state : X86LeaState)
    (srcBits : BitVec 64) (rawImm : BitVec 64) (hasIndex : Bool)
    (scale index stackBase : BitVec 64) :
    x86LeaStepSpec state
        { bits := srcBits, tag := .scalar, isNone := false, isRsp := true }
        rawImm false .w64 hasIndex scale index stackBase =
      { dst := { bits := (stackBase + srcBits + GeneratedX86MemOffset.valueSpec hasIndex scale rawImm index), tag := .stack } } := by
  simp [x86LeaStepSpec, x86LeaPointerWriteSpec]

/-- A narrow-width LEA ignores the stack-pointer distinction and truncates the
summed pointer through the partial-register writeback, scalarizing
provenance. -/
theorem x86_lea_narrow_ignores_rsp (state : X86LeaState)
    (srcBits : BitVec 64) (srcTag : Tag) (rawImm : BitVec 64)
    (hasIndex : Bool) (scale index stackBase stackBase' : BitVec 64) :
    x86LeaStepSpec state
        { bits := srcBits, tag := srcTag, isNone := false, isRsp := true }
        rawImm false .w32 hasIndex scale index stackBase =
      x86LeaStepSpec state
        { bits := srcBits, tag := srcTag, isNone := false, isRsp := false }
        rawImm false .w32 hasIndex scale index stackBase' := by
  simp [x86LeaStepSpec, x86RegWriteSpec, x86RegWriteBitsSpec]

/-- Canonical example: a 64-bit RODATA LEA writes the raw immediate and
scalarizes, regardless of the incoming destination tag. -/
theorem x86_lea_rodata_example :
    generatedX86LeaStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .mapValue } }
      { bits := 0, tag := .scalar, isNone := true, isRsp := false }
      0x0000000000004000 true .w64 false 0 0 0 =
      { dst := { bits := 0x0000000000004000, tag := .scalar } } := by
  native_decide

/-- Canonical example: a 64-bit indexed LEA sums the source pointer, the
sign-extended displacement, and the scaled index, carrying the source
provenance. -/
theorem x86_lea_indexed_example :
    generatedX86LeaStep
      { dst := { bits := 0xaaaaaaaaaaaaaaaa, tag := .scalar } }
      { bits := 0x0000000000001000, tag := .packet, isNone := false,
        isRsp := false }
      0x0000000000000010 false .w64 true 3 4 0 =
      { dst := { bits := 0x0000000000001030, tag := .packet } } := by
  native_decide

/-- Canonical example: a 64-bit stack-pointer LEA resolves through the abstract
frame base and tags the destination as stack provenance. -/
theorem x86_lea_stack_example :
    generatedX86LeaStep
      { dst := { bits := 0x123456789abcdef0, tag := .scalar } }
      { bits := 0x0000000000000000, tag := .scalar, isNone := false,
        isRsp := true }
      0x0000000000000020 false .w64 false 0 0 0x0000000000007000 =
      { dst := { bits := 0x0000000000007020, tag := .stack } } := by
  native_decide

/-- Canonical example: a 32-bit LEA zero-extends the low half of the summed
pointer and scalarizes provenance, discarding the incoming destination upper
bits. -/
theorem x86_lea_w32_example :
    generatedX86LeaStep
      { dst := { bits := 0xffffffffffffffff, tag := .mapValue } }
      { bits := 0x0000000000001000, tag := .packet, isNone := false,
        isRsp := false }
      0x0000000000000010 false .w32 false 0 0 0 =
      { dst := { bits := 0x0000000000001010, tag := .scalar } } := by
  native_decide

end KProgFormal
