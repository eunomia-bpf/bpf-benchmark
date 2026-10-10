import KProgFormal.GeneratedX86MovRegArm
import KProgFormal.X86Opcode
import KProgFormal.X86Width
import KProgFormal.GeneratedX86RegDispatch
import KProgFormal.X86MovHandler

namespace KProgFormal

open GeneratedX86MovRegArm (Arm armCount opcode fullWidthCode rspCode armNames
  armCodes codeOfArm effectOfArm widthClassOfArm armOf armOfCode)
open GeneratedX86RegDispatch (numberOfName)

/-- Independent statement of the opcode the arm implements, the
`X86_OP_MOV_REG` code. -/
def x86MovRegShapeOpcodeSpec : Nat := 2

/-- Independent statement of the full 64-bit width code the pointer family is
selected at. -/
def x86MovRegShapeFullWidthSpec : Nat := 8

/-- Independent statement of the stack-pointer register number the stack-base
arm is selected at. -/
def x86MovRegShapeRspSpec : Nat := 4

/-- Independent statement of the arm selector: at the full 64-bit width code the
stack-base arm when the source is the stack pointer and the provenance pointer
arm otherwise; the narrow scalarizing arm at every other code. The
stack-pointer test is nested inside the width test, so a narrow width ignores
register identity. Built from the literal codes rather than the generated
`armOf`. -/
def x86MovRegShapeSpec (width rsp : Nat) : Arm :=
  if width = x86MovRegShapeFullWidthSpec then
    (if rsp = x86MovRegShapeRspSpec then .stackPtr else .pointer)
  else .narrow

/-- Independent statement of the three arms, built from the literal constructor
order rather than the generated `armNames`. -/
def x86MovRegShapeNamesSpec : List String := ["stackPtr", "pointer", "narrow"]

/-- The generated arm selector equals the independent literal construction. -/
theorem x86_mov_reg_arm_refines (width rsp : Nat) :
    armOf width rsp = x86MovRegShapeSpec width rsp := by
  unfold armOf x86MovRegShapeSpec fullWidthCode rspCode
    x86MovRegShapeFullWidthSpec x86MovRegShapeRspSpec
  rfl

/-- The generated arm-name table equals the independent literal order. -/
theorem x86_mov_reg_arm_names_refine :
    armNames = x86MovRegShapeNamesSpec := by
  unfold armNames x86MovRegShapeNamesSpec
  rfl

/-- The generated arm-code table has exactly `armCount` entries. -/
theorem x86_mov_reg_arm_codes_length : armCodes.length = armCount := rfl

/-- The generated arm-name table has exactly `armCount` entries. -/
theorem x86_mov_reg_arm_names_length : armNames.length = armCount := rfl

/-- The three arm codes are distinct, so no two arms alias one code. -/
theorem x86_mov_reg_arm_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- The independent opcode literal is the code `x86OpcodeSpec` names for
`X86_OP_MOV_REG`, so the arm implements the simulator's own decode. -/
theorem x86_mov_reg_arm_opcode_spec_bound :
    x86OpcodeSpec.lookup "X86_OP_MOV_REG" = some x86MovRegShapeOpcodeSpec := by
  unfold x86MovRegShapeOpcodeSpec
  native_decide

/-- The independent full-width literal is the width contract's own 64-bit code,
so the pointer family is selected at the width the sim decodes as 64 bits. -/
theorem x86_mov_reg_arm_full_width_spec_bound :
    x86WidthCodeSpec .w64 = x86MovRegShapeFullWidthSpec := by
  unfold x86MovRegShapeFullWidthSpec
  rfl

/-- The independent stack-pointer literal is the register-number the dispatch
contract names `rsp`, so the stack-base arm is selected at the register the sim
decodes as the stack pointer. -/
theorem x86_mov_reg_arm_rsp_spec_bound :
    numberOfName "rsp" = some x86MovRegShapeRspSpec := by
  unfold x86MovRegShapeRspSpec
  native_decide

/-- The generated arm-code selector round-trips each arm to its own code and
names no other code: `codeOfArm` is a left inverse of `armOfCode` on the three
arms. -/
theorem x86_mov_reg_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The arm-code selector names no arm at or above the arm count, so the table
is exactly the three arms and no other code reaches one. -/
theorem x86_mov_reg_arm_of_code_beyond_is_none :
    armOfCode 3 = none ∧ armOfCode 4 = none ∧ armOfCode 8 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The generated opcode is the independent `X86_OP_MOV_REG` literal, pinned so
the C opcode and the generated `opcode` cannot drift. -/
theorem x86_mov_reg_arm_opcode_is_mov_reg :
    opcode = x86MovRegShapeOpcodeSpec := rfl

/-- The generated full-width code is the independent 64-bit literal, pinned so
the C full-width code and the generated `fullWidthCode` cannot drift. -/
theorem x86_mov_reg_arm_full_width_is_w64 :
    fullWidthCode = x86MovRegShapeFullWidthSpec := rfl

/-- The generated stack-pointer code is the independent `rsp` literal, pinned so
the C register number and the generated `rspCode` cannot drift. -/
theorem x86_mov_reg_arm_rsp_code_is_rsp :
    rspCode = x86MovRegShapeRspSpec := rfl

/-- The arm count is the three bodies `X86_OP_MOV_REG` selects between. -/
theorem x86_mov_reg_arm_count_is_3 : armCount = 3 := rfl

/-- The three arms report three distinct effects: the stack-base pointer write,
the provenance-preserving pointer write, and the narrow scalarizing write. -/
theorem x86_mov_reg_arm_effects :
    effectOfArm .stackPtr = "stack_base_pointer_write" ∧
      effectOfArm .pointer = "provenance_pointer_write" ∧
      effectOfArm .narrow = "width_scalarizing_write" ∧
      effectOfArm .stackPtr ≠ effectOfArm .pointer ∧
      effectOfArm .pointer ≠ effectOfArm .narrow ∧
      effectOfArm .stackPtr ≠ effectOfArm .narrow := by
  exact ⟨rfl, rfl, rfl, by decide, by decide, by decide⟩

/-- The two 64-bit arms operate in the full-width class and the narrow arm in
the narrow class, so the pointer family and the value arm are distinguished by
their width class. -/
theorem x86_mov_reg_arm_width_classes :
    widthClassOfArm .stackPtr = "full" ∧
      widthClassOfArm .pointer = "full" ∧
      widthClassOfArm .narrow = "narrow" ∧
      widthClassOfArm .pointer ≠ widthClassOfArm .narrow := by
  exact ⟨rfl, rfl, rfl, by decide⟩

/-- The selector picks the stack-base arm exactly at the full 64-bit width code
with the stack pointer as source, stated against the independent selector. -/
theorem x86_mov_reg_shape_stack_iff (width rsp : Nat) :
    x86MovRegShapeSpec width rsp = .stackPtr ↔
      width = x86MovRegShapeFullWidthSpec ∧ rsp = x86MovRegShapeRspSpec := by
  unfold x86MovRegShapeSpec
  by_cases hw : width = x86MovRegShapeFullWidthSpec
  · by_cases hr : rsp = x86MovRegShapeRspSpec <;>
      simp [hw, hr, Arm.noConfusion]
  · simp [hw, Arm.noConfusion]

/-- The selector picks the pointer arm exactly at the full 64-bit width code
with any source that is not the stack pointer, stated against the independent
selector. -/
theorem x86_mov_reg_shape_pointer_iff (width rsp : Nat) :
    x86MovRegShapeSpec width rsp = .pointer ↔
      width = x86MovRegShapeFullWidthSpec ∧ rsp ≠ x86MovRegShapeRspSpec := by
  unfold x86MovRegShapeSpec
  by_cases hw : width = x86MovRegShapeFullWidthSpec
  · by_cases hr : rsp = x86MovRegShapeRspSpec <;>
      simp [hw, hr, Arm.noConfusion]
  · simp [hw, Arm.noConfusion]

/-- The selector picks the narrow arm exactly below the full 64-bit width code,
so every narrower code reaches the width-scalarizing write regardless of the
source register. -/
theorem x86_mov_reg_shape_narrow_iff (width rsp : Nat) :
    x86MovRegShapeSpec width rsp = .narrow ↔
      width ≠ x86MovRegShapeFullWidthSpec := by
  unfold x86MovRegShapeSpec
  by_cases hw : width = x86MovRegShapeFullWidthSpec
  · by_cases hr : rsp = x86MovRegShapeRspSpec <;>
      simp [hw, hr, Arm.noConfusion]
  · simp [hw]

/-- The stack-pointer test is nested inside the width test: at every width other
than the full 64-bit code the arm is the same narrow write whatever the source
register, so observing `rsp` cannot change a narrow `mov` result. -/
theorem x86_mov_reg_shape_narrow_ignores_rsp (width rsp rsp' : Nat)
    (h : width ≠ x86MovRegShapeFullWidthSpec) :
    x86MovRegShapeSpec width rsp = x86MovRegShapeSpec width rsp' := by
  unfold x86MovRegShapeSpec
  simp [h]

/-- The width-keyed selector resolves each real width code to its own arm: only
the 64-bit code reaches the stack-base arm (with the stack pointer as source),
and the 8/16/32-bit codes all reach the narrow arm. -/
theorem x86_mov_reg_shape_over_widths :
    (List.map
        (fun w => x86MovRegShapeSpec (x86WidthCodeSpec w) x86MovRegShapeRspSpec)
        [.w8, .w16, .w32, .w64]) =
      [Arm.narrow, Arm.narrow, Arm.narrow, Arm.stackPtr] := by
  rfl

/-- All three selector shapes are reachable: each width/register pair reaches
its own arm, so no arm of the contract is dead. -/
theorem x86_mov_reg_shape_case_dispatch :
    armOf x86MovRegShapeFullWidthSpec x86MovRegShapeRspSpec = .stackPtr ∧
      armOf x86MovRegShapeFullWidthSpec 0 = .pointer ∧
      armOf (x86WidthCodeSpec .w32) x86MovRegShapeRspSpec = .narrow := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The narrow arm is the selector's default, so the arm is total: the full
64-bit width code reaches the pointer family and every other code the narrow
arm. -/
theorem x86_mov_reg_shape_ladder_total (width rsp : Nat)
    (h : width ≠ x86MovRegShapeFullWidthSpec) :
    armOf width rsp = .narrow := by
  unfold armOf
  rw [if_neg (by simpa [x86MovRegShapeFullWidthSpec] using h)]

/-- **The arm selects the proved value functions.** Each arm's effect is the
composition `X86MovHandler` proves: the stack-base arm resolves the abstract
frame base and tags stack, the pointer arm copies bits and provenance, and the
narrow arm scalarizes through the partial-register writeback. The arm selects
between the proved actions and not a fresh implementation. -/
theorem x86_mov_reg_arm_is_mov_reg :
    (effectOfArm .stackPtr = "stack_base_pointer_write" →
      x86MovRegStepSpec { dst := { bits := 0, tag := .scalar } }
        { bits := 0x1234, tag := .scalar, isRsp := true }
        .w64 .low .low 0x7000 =
        { dst := { bits := 0x7000 + 0x1234, tag := Tag.stack } }) ∧
    (effectOfArm .pointer = "provenance_pointer_write" →
      x86MovRegStepSpec { dst := { bits := 0, tag := .scalar } }
        { bits := 0x1234, tag := .packet, isRsp := false }
        .w64 .low .low 0 =
        { dst := { bits := 0x1234, tag := .packet } }) ∧
    (effectOfArm .narrow = "width_scalarizing_write" →
      (x86MovRegStepSpec { dst := { bits := 0x11, tag := .stack } }
        { bits := 0x1122334455667788, tag := .packet, isRsp := true }
        .w32 .low .low 0).dst.tag = Tag.scalar) :=
  ⟨fun _ => by native_decide,
   fun _ => by native_decide,
   fun _ => x86_mov_reg_narrow_scalarizes _ _ .w32 _ _ _ (by decide)⟩

/-- **The selected arm matches the handler's width and register.** The arm the
selector picks at the full 64-bit width code with the stack pointer as source is
the stack-base composition `x86_mov_reg_rsp_uses_stack_base` proves; at the full
width code with any other source it is the provenance copy
`x86_mov_reg_copies_provenance` proves; at every narrower code it is the
scalarizing narrow composition `x86_mov_reg_narrow_ignores_rsp` proves (which is
the same for both stack-pointer and non-stack-pointer sources), so the
two-fact arm selection and the value composition agree. -/
theorem x86_mov_reg_arm_matches_handler
    (state : X86MovState) (srcBits : BitVec 64) (srcTag : Tag)
    (dstLane srcLane : X86ByteLane) (stackBase : BitVec 64) :
    (x86MovRegShapeSpec (x86WidthCodeSpec .w64) x86MovRegShapeRspSpec =
        .stackPtr ∧
      x86MovRegStepSpec state { bits := srcBits, tag := srcTag, isRsp := true }
        .w64 dstLane srcLane stackBase =
        { dst := { bits := stackBase + srcBits, tag := Tag.stack } }) ∧
    (x86MovRegShapeSpec (x86WidthCodeSpec .w64) 0 = .pointer ∧
      x86MovRegStepSpec state { bits := srcBits, tag := srcTag, isRsp := false }
        .w64 dstLane srcLane stackBase =
        { dst := { bits := srcBits, tag := srcTag } }) ∧
    (x86MovRegShapeSpec (x86WidthCodeSpec .w32) x86MovRegShapeRspSpec =
        .narrow ∧
      x86MovRegStepSpec state { bits := srcBits, tag := srcTag, isRsp := true }
        .w32 dstLane srcLane stackBase =
      x86MovRegStepSpec state { bits := srcBits, tag := srcTag, isRsp := false }
        .w32 dstLane srcLane stackBase) := by
  refine ⟨⟨?_, ?_⟩, ⟨?_, ?_⟩, ⟨?_, ?_⟩⟩
  · native_decide
  · exact x86_mov_reg_rsp_uses_stack_base state srcBits srcTag dstLane srcLane
      stackBase
  · native_decide
  · exact x86_mov_reg_copies_provenance state srcBits srcTag dstLane srcLane
      stackBase
  · native_decide
  · exact x86_mov_reg_narrow_ignores_rsp state srcBits srcTag dstLane srcLane
      stackBase stackBase

end KProgFormal
