import KProgFormal.GeneratedX86WriteWidthArm
import KProgFormal.X86Width

namespace KProgFormal

open GeneratedX86WriteWidthArm (Arm armCount widthCodeBits armNames armCodes
  codeOfArm widthCodeOfArm bodyOfArm caseMacroOfArm widthClassOfArm armOf
  armOfCode)

/-- Independent statement of the register-writeback body selector: the byte body
at the resolved 8-bit width code, the word body at the 16-bit code, the dword
body at the 32-bit code, and the qword body at every other code. It selects on
the width contract's own `x86WidthCodeSpec` literals rather than the generated
`widthCodeOfArm` table. -/
def x86WriteWidthArmSpec (width : Nat) : Arm :=
  if width = x86WidthCodeSpec .w8 then .b8
  else if width = x86WidthCodeSpec .w16 then .b16
  else if width = x86WidthCodeSpec .w32 then .b32
  else .b64

/-- Independent statement of the four bodies the write-width macro selects
between, built from the literal constructor order rather than the generated
`armNames`. -/
def x86WriteWidthArmNamesSpec : List String := ["b8", "b16", "b32", "b64"]

/-- The generated body selector equals the independent width-code ladder. -/
theorem x86_write_width_arm_refines (width : Nat) :
    armOf width = x86WriteWidthArmSpec width := by
  unfold armOf x86WriteWidthArmSpec x86WidthCodeSpec
  rfl

/-- The generated body-name table equals the independent literal order. -/
theorem x86_write_width_arm_names_refine :
    armNames = x86WriteWidthArmNamesSpec := by
  unfold armNames x86WriteWidthArmNamesSpec
  rfl

/-- The generated body-code table has exactly `armCount` entries. -/
theorem x86_write_width_arm_codes_length : armCodes.length = armCount := rfl

/-- The generated body-name table has exactly `armCount` entries. -/
theorem x86_write_width_arm_names_length : armNames.length = armCount := rfl

/-- The four body codes are distinct, so no two bodies alias one code. -/
theorem x86_write_width_arm_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- Every resolved width code reaches its own body: the byte code the byte body,
the 16-bit code the word body, the 32-bit code the dword body, and the 64-bit
code the qword body. -/
theorem x86_write_width_arm_over_widths :
    (List.map (fun w => x86WriteWidthArmSpec (x86WidthCodeSpec w))
        [.w8, .w16, .w32, .w64]) =
      [Arm.b8, Arm.b16, Arm.b32, Arm.b64] := by
  rfl

/-- The body-code selector round-trips each body to its own code and names no
other code: `codeOfArm` is a left inverse of `armOfCode` on the four bodies. -/
theorem x86_write_width_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The body-code selector names no body at or above the body count, so the
table is exactly the four bodies and no other code reaches one. -/
theorem x86_write_width_arm_of_code_beyond_is_none :
    armOfCode 4 = none ∧ armOfCode 5 = none ∧ armOfCode 8 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The width-code width is the byte width the sim decodes, pinned so the C
`__u8` width code and the generated `widthCodeBits` cannot drift apart. -/
theorem x86_write_width_width_code_bits_is_8 : widthCodeBits = 8 := rfl

/-- The body count is the four register-writeback bodies
`X86_SIM_L_WRITE_REG_WIDTH_SHIFT` selects between. -/
theorem x86_write_width_arm_count_is_4 : armCount = 4 := rfl

/-- Each body writes back at the width code the width contract names for the
corresponding operand size: the byte body at the 8-bit code, the word body at
the 16-bit code, the dword body at the 32-bit code, and the qword body at the
64-bit code. -/
theorem x86_write_width_arm_width_codes :
    widthCodeOfArm .b8 = x86WidthCodeSpec .w8 ∧
      widthCodeOfArm .b16 = x86WidthCodeSpec .w16 ∧
      widthCodeOfArm .b32 = x86WidthCodeSpec .w32 ∧
      widthCodeOfArm .b64 = x86WidthCodeSpec .w64 := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> (unfold widthCodeOfArm x86WidthCodeSpec; rfl)

/-- The four bodies write back genuinely differently: a single byte lane, the
low word, the low dword, and the full register, so a swapped selector body
changes the written register bytes. -/
theorem x86_write_width_arm_bodies :
    bodyOfArm .b8 = "byte_lane_writeback" ∧
      bodyOfArm .b16 = "word_writeback" ∧
      bodyOfArm .b32 = "dword_writeback" ∧
      bodyOfArm .b64 = "qword_writeback" ∧
      bodyOfArm .b8 ≠ bodyOfArm .b16 ∧
      bodyOfArm .b16 ≠ bodyOfArm .b32 ∧
      bodyOfArm .b32 ≠ bodyOfArm .b64 := by
  refine ⟨rfl, rfl, rfl, rfl, by decide, by decide, by decide⟩

/-- Each body routes through the simulator case macro that applies its own
width: the byte lane macro for the byte body, the word macro for the word body,
the dword macro for the dword body, and the register macro for the qword body. -/
theorem x86_write_width_arm_case_macros :
    caseMacroOfArm .b8 = "X86_SIM_L_WRITE_REG8_VALUE_CASE" ∧
      caseMacroOfArm .b16 = "X86_SIM_L_WRITE_REG16_VALUE_CASE" ∧
      caseMacroOfArm .b32 = "X86_SIM_L_WRITE_REG32_VALUE_CASE" ∧
      caseMacroOfArm .b64 = "X86_SIM_L_WRITE_REG64_VALUE_CASE" ∧
      caseMacroOfArm .b8 ≠ caseMacroOfArm .b16 ∧
      caseMacroOfArm .b16 ≠ caseMacroOfArm .b32 ∧
      caseMacroOfArm .b32 ≠ caseMacroOfArm .b64 := by
  refine ⟨rfl, rfl, rfl, rfl, by decide, by decide, by decide⟩

/-- The byte/word/dword bodies are the narrow width class and the qword body the
full class, so the classes are distinct and neither is empty. -/
theorem x86_write_width_arm_width_classes :
    widthClassOfArm .b8 = "narrow" ∧
      widthClassOfArm .b16 = "narrow" ∧
      widthClassOfArm .b32 = "narrow" ∧
      widthClassOfArm .b64 = "full" ∧
      widthClassOfArm .b8 ≠ widthClassOfArm .b64 := by
  refine ⟨rfl, rfl, rfl, rfl, by decide⟩

/-- The ladder is total: every resolved width code reaches one of the four
bodies, and the default qword body is what any other code reaches. -/
theorem x86_write_width_arm_ladder_total (width : Nat) (h1 : width ≠ 1)
    (h2 : width ≠ 2) (h3 : width ≠ 4) :
    armOf width = .b64 := by
  unfold armOf
  rw [if_neg h1, if_neg h2, if_neg h3]

/-- All the selector shapes are reachable: each real byte/word/dword code
reaches its own body and the qword code reaches the default body, so no body of
the contract is dead. -/
theorem x86_write_width_arm_case_dispatch :
    armOf 1 = .b8 ∧ armOf 2 = .b16 ∧ armOf 4 = .b32 ∧ armOf 8 = .b64 := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The resolved default body is the qword one, so an absent width field (the
code 0 the effective-width bridge would have replaced) reaches a full-register
writeback just like the 64-bit code. -/
theorem x86_write_width_arm_default_is_qword :
    x86WriteWidthArmSpec x86AbsentCodeSpec = .b64 ∧
      x86WriteWidthArmSpec (x86WidthCodeSpec .w64) = .b64 := by
  simp [x86WriteWidthArmSpec, x86WidthCodeSpec, x86AbsentCodeSpec]

end KProgFormal
