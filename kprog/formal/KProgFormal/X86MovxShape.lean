import KProgFormal.GeneratedX86MovxShape
import KProgFormal.X86Opcode
import KProgFormal.X86Width
import KProgFormal.X86Signed
import KProgFormal.X86MovxRegHandler

namespace KProgFormal

open GeneratedX86MovxShape (Arm armCount opcodeBits armNames armCodes codeOfArm
  opcodeOfArm resultOfArm effectOfArm armOf armOfCode)

/-- Independent statement of the opcode the `MOVSX` arm is keyed on, the
`X86_OP_MOVSX_REG` code. -/
def x86MovxShapeSignOpcodeSpec : Nat := 33

/-- Independent statement of the opcode the `MOVZX` arm is keyed on, the
`X86_OP_MOVZX_REG` code. -/
def x86MovxShapeZeroOpcodeSpec : Nat := 32

/-- Independent statement of the shape selector: the sign extension at the
`X86_OP_MOVSX_REG` opcode and the zero extension at every other opcode (the arm
only runs for the two MOVX opcodes), built from the literal opcode rather than
the generated `armOf`. -/
def x86MovxShapeSpec (op : Nat) : Arm :=
  if op = x86MovxShapeSignOpcodeSpec then .sign_extend else .zero_extend

/-- Independent statement of the two arms, built from the literal constructor
order rather than the generated `armNames`. -/
def x86MovxShapeNamesSpec : List String := ["sign_extend", "zero_extend"]

/-- Independent statement of the extension function each opcode selects:
`x86_sign_extend` at the `X86_OP_MOVSX_REG` opcode and `x86_apply_width` (the
zero extension) elsewhere. -/
def x86MovxShapeResultSpec (op : Nat) : String :=
  if op = x86MovxShapeSignOpcodeSpec then "sign_extend" else "zero_extend"

/-- The generated shape selector equals the independent literal construction. -/
theorem x86_movx_shape_refines (op : Nat) :
    armOf op = x86MovxShapeSpec op := by
  unfold armOf x86MovxShapeSpec x86MovxShapeSignOpcodeSpec
  rfl

/-- The generated result-function selector equals the independent construction
over the opcode literals, so the extension function the arm names cannot drift
from the `X86_OP_MOVSX_REG` / `X86_OP_MOVZX_REG` key. -/
theorem x86_movx_shape_result_refines (op : Nat) :
    resultOfArm (armOf op) = x86MovxShapeResultSpec op := by
  unfold resultOfArm armOf x86MovxShapeResultSpec x86MovxShapeSignOpcodeSpec
  by_cases h : op = 33 <;> simp [h]

/-- The generated arm-name table equals the independent literal order. -/
theorem x86_movx_shape_names_refine :
    armNames = x86MovxShapeNamesSpec := by
  unfold armNames x86MovxShapeNamesSpec
  rfl

/-- The generated arm-code table has exactly `armCount` entries. -/
theorem x86_movx_shape_codes_length : armCodes.length = armCount := rfl

/-- The generated arm-name table has exactly `armCount` entries. -/
theorem x86_movx_shape_names_length : armNames.length = armCount := rfl

/-- The two arm codes are distinct, so no two extension functions alias one
code. -/
theorem x86_movx_shape_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- The two arm opcodes are distinct, so the opcode key selects exactly one
extension function. -/
theorem x86_movx_shape_opcodes_nodup :
    opcodeOfArm .sign_extend ≠ opcodeOfArm .zero_extend := by
  native_decide

/-- The independent opcode literals are the codes `x86OpcodeSpec` names for
`X86_OP_MOVSX_REG` / `X86_OP_MOVZX_REG`, so the arm is keyed on the simulator's
own decodes. -/
theorem x86_movx_shape_opcode_spec_bound :
    x86OpcodeSpec.lookup "X86_OP_MOVSX_REG" = some x86MovxShapeSignOpcodeSpec ∧
    x86OpcodeSpec.lookup "X86_OP_MOVZX_REG" = some x86MovxShapeZeroOpcodeSpec := by
  unfold x86MovxShapeSignOpcodeSpec x86MovxShapeZeroOpcodeSpec
  native_decide

/-- Each real MOVX opcode reaches its own arm, so the opcode-keyed selector is
total over the two opcodes the arm runs for. -/
theorem x86_movx_shape_arm_over_opcodes :
    (List.map (fun op => x86MovxShapeSpec op)
        [x86MovxShapeZeroOpcodeSpec, x86MovxShapeSignOpcodeSpec]) =
      [Arm.zero_extend, Arm.sign_extend] := by
  unfold x86MovxShapeZeroOpcodeSpec x86MovxShapeSignOpcodeSpec x86MovxShapeSpec
  rfl

/-- The arm-code selector round-trips each arm to its own code and names no
other code: `codeOfArm` is a left inverse of `armOfCode` on the two arms. -/
theorem x86_movx_shape_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The arm-code selector names no arm at or above the arm count, so the table
is exactly the two arms and no other code reaches one. -/
theorem x86_movx_shape_arm_of_code_beyond_is_none :
    armOfCode 2 = none ∧ armOfCode 3 = none ∧ armOfCode 32 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The arm selects on a byte-wide opcode, pinned so the C opcode's `__u8`
width and the generated `opcodeBits` cannot drift apart. -/
theorem x86_movx_shape_opcode_bits_is_8 : opcodeBits = 8 := rfl

/-- The arm count is the two extension functions the opcode selects between. -/
theorem x86_movx_shape_arm_count_is_2 : armCount = 2 := rfl

/-- The two arms implement the `X86_OP_MOVZX_REG` (`32`) and `X86_OP_MOVSX_REG`
(`33`) opcodes, pinned so the C opcodes and the generated `opcodeOfArm` table
cannot drift. -/
theorem x86_movx_shape_arm_opcodes :
    opcodeOfArm .zero_extend = x86MovxShapeZeroOpcodeSpec ∧
      opcodeOfArm .sign_extend = x86MovxShapeSignOpcodeSpec := by
  refine ⟨?_, ?_⟩ <;> decide

/-- The sign-extending arm reports `x86_sign_extend` and the zero-extending arm
`x86_apply_width` (the zero extension), so the extension function is selected by
the opcode and the two names are distinct. -/
theorem x86_movx_shape_arm_results :
    resultOfArm .sign_extend = "sign_extend" ∧
      resultOfArm .zero_extend = "zero_extend" ∧
      resultOfArm .sign_extend ≠ resultOfArm .zero_extend := by
  exact ⟨rfl, rfl, by decide⟩

/-- The opcode→extension-function mapping is exactly the two extension
functions, stated over the opcode literals. -/
theorem x86_movx_shape_opcode_result :
    (x86MovxShapeSpec x86MovxShapeSignOpcodeSpec = .sign_extend ∧
      x86MovxShapeResultSpec x86MovxShapeSignOpcodeSpec = "sign_extend") ∧
    (x86MovxShapeSpec x86MovxShapeZeroOpcodeSpec = .zero_extend ∧
      x86MovxShapeResultSpec x86MovxShapeZeroOpcodeSpec = "zero_extend") := by
  refine ⟨⟨?_, ?_⟩, ⟨?_, ?_⟩⟩ <;> native_decide

/-- The two arms perform two distinct effects on the widened source lane: the
sign arm extends the lane's sign bit and the zero arm discards it. -/
theorem x86_movx_shape_arm_effects :
    effectOfArm .sign_extend = "sign_extend_source_lane" ∧
      effectOfArm .zero_extend = "zero_extend_source_lane" ∧
      effectOfArm .sign_extend ≠ effectOfArm .zero_extend := by
  exact ⟨rfl, rfl, by decide⟩

/-- The selector picks the sign-extending arm exactly at the `X86_OP_MOVSX_REG`
opcode, stated against the independent selector. -/
theorem x86_movx_shape_sign_iff (op : Nat) :
    x86MovxShapeSpec op = .sign_extend ↔ op = x86MovxShapeSignOpcodeSpec := by
  unfold x86MovxShapeSpec
  by_cases h : op = x86MovxShapeSignOpcodeSpec <;>
    simp [h, Arm.noConfusion]

/-- The selector picks the zero-extending arm at every opcode that is not the
`X86_OP_MOVSX_REG` opcode, so both MOVX opcodes reach an extension function. -/
theorem x86_movx_shape_zero_iff (op : Nat) :
    x86MovxShapeSpec op = .zero_extend ↔ op ≠ x86MovxShapeSignOpcodeSpec := by
  unfold x86MovxShapeSpec
  by_cases h : op = x86MovxShapeSignOpcodeSpec <;>
    simp [h, Arm.noConfusion]

/-- All the selector shapes are reachable: each MOVX opcode reaches its own arm,
so neither arm of the contract is dead. -/
theorem x86_movx_shape_case_dispatch :
    armOf x86MovxShapeSignOpcodeSpec = .sign_extend ∧
      armOf x86MovxShapeZeroOpcodeSpec = .zero_extend := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- The zero-extending arm is the selector's default, so the arm is total: the
`X86_OP_MOVSX_REG` opcode reaches the sign arm and every other opcode the zero
arm. -/
theorem x86_movx_shape_ladder_total (op : Nat)
    (h : op ≠ x86MovxShapeSignOpcodeSpec) :
    armOf op = .zero_extend := by
  unfold armOf
  rw [if_neg (by simpa [x86MovxShapeSignOpcodeSpec] using h)]

/-- **The arm selects the proved value functions.** The sign arm's extension
function is the source-lane sign extension `X86MovxRegHandler` proves for
`movsx`, and the zero arm's is the narrowing it proves for `movzx`, so the arm
selects between the proved value functions and not a fresh implementation. The
sign arm extends a negative lane's sign bit; the zero arm discards it. -/
theorem x86_movx_shape_is_movx :
    (resultOfArm .sign_extend = "sign_extend" →
      x86MovxRegStepSpec { dst := { bits := 0, tag := .scalar } }
        0x0000000000000080 .movsx .w8 .w32 =
        ({ dst := x86RegWriteSpec { bits := 0, tag := .scalar }
            (x86SignExtendSpec 0x0000000000000080 .w8) .w32 })) ∧
    (resultOfArm .zero_extend = "zero_extend" →
      x86MovxRegStepSpec { dst := { bits := 0, tag := .scalar } }
        0x11223344556688ff .movzx .w8 .w32 =
        ({ dst := x86RegWriteSpec { bits := 0, tag := .scalar }
            (x86NarrowSpec 0x11223344556688ff .w8) .w32 })) :=
  ⟨fun _ => x86_movsx_is_sign_extend _ _ _ _,
   fun _ => x86_movzx_is_narrow _ _ _ _⟩

/-- **The selected shape matches the handler's opcode.** The arm the selector
picks at each MOVX opcode is the `X86MovxRegHandler` opcode whose extension
function it names, so the opcode-keyed shape selection and the value composition
agree on which opcode means which extension. -/
theorem x86_movx_shape_matches_handler :
    (x86MovxShapeSpec x86MovxShapeSignOpcodeSpec = .sign_extend ∧
      resultOfArm (x86MovxShapeSpec x86MovxShapeSignOpcodeSpec) =
        "sign_extend") ∧
    (x86MovxShapeSpec x86MovxShapeZeroOpcodeSpec = .zero_extend ∧
      resultOfArm (x86MovxShapeSpec x86MovxShapeZeroOpcodeSpec) =
        "zero_extend") := by
  refine ⟨⟨?_, ?_⟩, ⟨?_, ?_⟩⟩ <;> native_decide

end KProgFormal
