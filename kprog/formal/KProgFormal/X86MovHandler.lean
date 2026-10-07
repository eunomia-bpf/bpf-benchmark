import KProgFormal.X86RegWrite
import KProgFormal.X86RegRead
import KProgFormal.X86RegLaneAux
import KProgFormal.GeneratedX86RegRead
import KProgFormal.TagErasure
import KProgFormal.GeneratedPtrAdd

namespace KProgFormal

/-- Destination register state of the x86 MOV handlers. As with LEA, only the
destination register is written: MOV defines no flags. -/
structure X86MovState where
  dst : X86RegValue
  deriving DecidableEq, Repr

/-- Abstract source operand of the register-to-register MOV handler. `bits` is
the source register's raw 64-bit value, `tag` its provenance, and `isRsp` is
true when the encoded source is the stack pointer register. -/
structure X86MovSrc where
  bits : BitVec 64
  tag : Tag
  isRsp : Bool
  deriving DecidableEq, Repr

/-- Pointer writeback used by the 64-bit MOV path: the destination receives the
source pointer unchanged and the (already selected) provenance tag, exactly as
`KPROG_PTR_ADD64_BITS`/`KPROG_PTR_ADD64_TAG` do with a zero right-hand side. -/
def generatedX86MovPointerWrite (state : X86MovState) (ptr : BitVec 64)
    (tag : Tag) : X86MovState :=
  { state with dst := { bits := GeneratedPtrAdd.bits ptr 0,
                        tag := GeneratedPtrAdd.tag tag } }

def x86MovPointerWriteSpec (state : X86MovState) (ptr : BitVec 64)
    (tag : Tag) : X86MovState :=
  { state with dst := { bits := ptr, tag := tag } }

theorem x86_mov_pointer_write_refines (state : X86MovState) (ptr : BitVec 64)
    (tag : Tag) :
    generatedX86MovPointerWrite state ptr tag =
      x86MovPointerWriteSpec state ptr tag := by
  cases state
  simp [generatedX86MovPointerWrite, x86MovPointerWriteSpec,
    GeneratedPtrAdd.bits, GeneratedPtrAdd.tag]

/-- Composition used by the x86 register-destination MOV-immediate handler
(`X86_SIM_L_EXEC_MOV_IMM` / `_MOV_IMM_AUX`) after the destination width and byte
lane have been decoded. The raw encoded immediate is written through the
partial-register writeback: no sign extension or truncation happens before the
write, so the low-lane forms of `mov` and the high-byte form of `mov ah, imm`
are the same contract with a different lane. -/
def generatedX86MovImmStep (state : X86MovState) (imm : BitVec 64)
    (width : X86Width) (dstLane : X86ByteLane) : X86MovState :=
  { dst := generatedX86RegWriteAt state.dst imm width dstLane }

/-- Independent statement of the same handler. -/
def x86MovImmStepSpec (state : X86MovState) (imm : BitVec 64)
    (width : X86Width) (dstLane : X86ByteLane) : X86MovState :=
  { dst := x86RegWriteAtSpec state.dst imm width dstLane }

/-- The MOV-immediate handler composition refines the independent
partial-register writeback for arbitrary destination state, encoded immediate,
destination width, and destination byte lane. -/
theorem x86_mov_imm_step_refines (state : X86MovState) (imm : BitVec 64)
    (width : X86Width) (dstLane : X86ByteLane) :
    generatedX86MovImmStep state imm width dstLane =
      x86MovImmStepSpec state imm width dstLane := by
  simp only [generatedX86MovImmStep, x86MovImmStepSpec,
    x86_reg_write_at_refines]

/-- The non-AUX `X86_SIM_L_EXEC_MOV_IMM` carries the zero aux word, whose decoded
destination lane is the low lane; the handler then degenerates to the plain
partial-register writeback with no byte selection. -/
theorem x86_mov_imm_low_lane_is_plain (state : X86MovState) (imm : BitVec 64)
    (width : X86Width) :
    x86MovImmStepSpec state imm width .low =
      { dst := x86RegWriteSpec state.dst imm width } := by
  cases state with
  | mk dst =>
      cases dst with
      | mk oldBits oldTag =>
          cases width <;>
            simp [x86MovImmStepSpec, x86RegWriteAtSpec, x86RegWriteBitsAtSpec,
              x86RegWriteSpec, x86RegWriteBitsSpec, x86ByteShiftSpec] <;>
            bv_decide

/-- Composition used by the x86 register-source MOV handler
(`X86_SIM_L_EXEC_MOV_REG` / `_MOV_REG_AUX`) once the source operand and the
decoded byte lanes have been supplied. The 64-bit forms move the pointer and its
provenance — through the abstract frame base on the stack-pointer arm; the
narrow forms observe the source through its decoded lane, write the low width
through the destination lane, and scalarize provenance (`MOV r32, r32` zeroes
the destination's upper half rather than preserving it). -/
def generatedX86MovRegStep (state : X86MovState) (src : X86MovSrc)
    (width : X86Width) (dstLane srcLane : X86ByteLane)
    (stackBase : BitVec 64) : X86MovState :=
  match width with
  | .w64 =>
      if src.isRsp then
        generatedX86MovPointerWrite state (stackBase + src.bits) Tag.stack
      else
        generatedX86MovPointerWrite state src.bits src.tag
  | _ =>
      { dst := generatedX86RegWriteAt state.dst
          (GeneratedX86RegRead.readAt src.bits width srcLane) width dstLane }

/-- Independent statement of the same handler. -/
def x86MovRegStepSpec (state : X86MovState) (src : X86MovSrc)
    (width : X86Width) (dstLane srcLane : X86ByteLane)
    (stackBase : BitVec 64) : X86MovState :=
  match width with
  | .w64 =>
      if src.isRsp then
        { dst := { bits := stackBase + src.bits, tag := Tag.stack } }
      else
        { dst := { bits := src.bits, tag := src.tag } }
  | _ =>
      { dst := x86RegWriteAtSpec state.dst
          (x86RegReadAtSpec src.bits width srcLane) width dstLane }

/-- The register-source MOV handler composition refines the independent
statement for arbitrary destination state, source operand, destination width,
decoded byte lanes, and abstract frame base. Only the 64-bit arms carry
provenance; every narrow arm scalarizes through the partial-register
writeback. -/
theorem x86_mov_reg_step_refines (state : X86MovState) (src : X86MovSrc)
    (width : X86Width) (dstLane srcLane : X86ByteLane)
    (stackBase : BitVec 64) :
    generatedX86MovRegStep state src width dstLane srcLane stackBase =
      x86MovRegStepSpec state src width dstLane srcLane stackBase := by
  cases state with
  | mk dst =>
    cases width <;> cases src.isRsp <;>
      simp [generatedX86MovRegStep, x86MovRegStepSpec,
        generatedX86MovPointerWrite, x86MovPointerWriteSpec,
        x86RegReadAtSpec, x86RegWriteAtSpec, GeneratedPtrAdd.bits,
        GeneratedPtrAdd.tag, x86_reg_read_at_refines,
        x86_reg_write_at_refines]

/-- A 64-bit `MOV` from a non-stack-pointer register copies both the source bits
and the source provenance unchanged: the destination tag is exactly the source
tag, so packet/map/ABI pointers survive a `mov`. -/
theorem x86_mov_reg_copies_provenance (state : X86MovState)
    (srcBits : BitVec 64) (srcTag : Tag) (dstLane srcLane : X86ByteLane)
    (stackBase : BitVec 64) :
    x86MovRegStepSpec state
        { bits := srcBits, tag := srcTag, isRsp := false }
        .w64 dstLane srcLane stackBase =
      { dst := { bits := srcBits, tag := srcTag } } := by
  simp [x86MovRegStepSpec]

/-- A 64-bit `MOV` from the stack pointer resolves to the abstract frame base
plus the source value and tags the destination as stack provenance, exactly like
the corresponding LEA arm (with a zero offset). -/
theorem x86_mov_reg_rsp_uses_stack_base (state : X86MovState)
    (srcBits : BitVec 64) (srcTag : Tag) (dstLane srcLane : X86ByteLane)
    (stackBase : BitVec 64) :
    x86MovRegStepSpec state
        { bits := srcBits, tag := srcTag, isRsp := true }
        .w64 dstLane srcLane stackBase =
      { dst := { bits := (stackBase + srcBits), tag := Tag.stack } } := by
  simp [x86MovRegStepSpec]

/-- A narrow `MOV` ignores the stack-pointer distinction: the two 64-bit arms
collapse to the same scalarizing partial-register writeback, so observing RSP
cannot change a `mov r32, r32` result. -/
theorem x86_mov_reg_narrow_ignores_rsp (state : X86MovState)
    (srcBits : BitVec 64) (srcTag : Tag) (dstLane srcLane : X86ByteLane)
    (stackBase stackBase' : BitVec 64) :
    x86MovRegStepSpec state
        { bits := srcBits, tag := srcTag, isRsp := true }
        .w32 dstLane srcLane stackBase =
      x86MovRegStepSpec state
        { bits := srcBits, tag := srcTag, isRsp := false }
        .w32 dstLane srcLane stackBase' := by
  simp [x86MovRegStepSpec]

/-- Every narrow `MOV` scalarizes the destination provenance, regardless of the
incoming tag and of the source tag. -/
theorem x86_mov_reg_narrow_scalarizes (state : X86MovState)
    (src : X86MovSrc) (width : X86Width) (dstLane srcLane : X86ByteLane)
    (stackBase : BitVec 64) (isNarrow : width ≠ .w64) :
    (x86MovRegStepSpec state src width dstLane srcLane stackBase).dst.tag =
      Tag.scalar := by
  cases width <;> simp_all [x86MovRegStepSpec, x86RegWriteAtSpec]

/-- Canonical example: a 64-bit `mov r, imm` writes the raw immediate and
scalarizes provenance, regardless of the incoming destination tag. -/
theorem x86_mov_imm64_example :
    generatedX86MovImmStep
      { dst := { bits := 0xdeadbeefdeadbeef, tag := .mapValue } }
      0x0000000000004000 .w64 .low =
      { dst := { bits := 0x0000000000004000, tag := .scalar } } := by
  native_decide

/-- Canonical example: an 8-bit `mov ah, imm` merges the immediate into the
destination's high byte and leaves the other seven bytes intact. -/
theorem x86_mov_imm_high8_example :
    generatedX86MovImmStep
      { dst := { bits := 0x1122334455667788, tag := .stack } }
      0x00000000000000aa .w8 .high =
      { dst := { bits := 0x112233445566aa88, tag := .scalar } } := by
  native_decide

/-- Canonical example: a 64-bit `mov rsp`-sourced register move resolves through
the abstract frame base and tags the destination as stack provenance. -/
theorem x86_mov_reg_stack_example :
    generatedX86MovRegStep
      { dst := { bits := 0x123456789abcdef0, tag := .scalar } }
      { bits := 0x0000000000000000, tag := .scalar, isRsp := true }
      .w64 .low .low 0x0000000000007000 =
      { dst := { bits := 0x0000000000007000, tag := .stack } } := by
  native_decide

/-- Canonical example: a 32-bit `mov r32, r32` zero-extends the source's low half
and scalarizes provenance, discarding both the incoming destination upper bits
and the incoming destination tag. -/
theorem x86_mov_reg_w32_example :
    generatedX86MovRegStep
      { dst := { bits := 0xffffffffffffffff, tag := .mapValue } }
      { bits := 0xffffffff00001234, tag := .packet, isRsp := false }
      .w32 .low .low 0 =
      { dst := { bits := 0x0000000000001234, tag := .scalar } } := by
  native_decide

/-- Canonical example: an 8-bit `mov r8, rh`-style lane-to-lane move selects the
source's high byte and the destination's low byte, so the pair of decoded lanes
is observable in the result. -/
theorem x86_mov_reg_lane_example :
    generatedX86MovRegStep
      { dst := { bits := 0xffffffffffffffff, tag := .stack } }
      { bits := 0x112233445566aa88, tag := .scalar, isRsp := false }
      .w8 .low .high 0 =
      { dst := { bits := 0xffffffffffffffaa, tag := .scalar } } := by
  native_decide

end KProgFormal
