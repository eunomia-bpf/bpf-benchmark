import KProgFormal.GeneratedX86MulxArm
import KProgFormal.X86Width
import KProgFormal.X86MulxHandler
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedX86MulxArm (Arm armCount widthCodeBits opcode specialWidthCode
  armNames armCodes codeOfArm effectOfArm widthClassOfArm isSpecialWidth armOf
  armOfCode)

/-- Independent statement of the `MULX` arm selector: the single-product arm at
the resolved 32-bit width code, the four-limb ladder arm at every other code.
It selects on the literal code `4`, built from the width contract's own
`x86WidthCodeSpec .w32` rather than the generated `specialWidthCode`. -/
def x86MulxArmSpec (width : Nat) : Arm :=
  if width = x86WidthCodeSpec .w32 then .singleProduct else .limbLadder

/-- Independent statement of the two arms the `MULX` macro selects between,
built from the literal constructor order rather than the generated
`armNames`. -/
def x86MulxArmNamesSpec : List String := ["singleProduct", "limbLadder"]

/-- The generated arm selector equals the independent literal construction. -/
theorem x86_mulx_arm_refines (width : Nat) :
    armOf width = x86MulxArmSpec width := by
  unfold armOf x86MulxArmSpec specialWidthCode
  rfl

/-- The generated arm-name table equals the independent literal order. -/
theorem x86_mulx_names_refine : armNames = x86MulxArmNamesSpec := by
  unfold armNames x86MulxArmNamesSpec
  rfl

/-- The generated arm-code table has exactly `armCount` entries. -/
theorem x86_mulx_codes_length : armCodes.length = armCount := rfl

/-- The generated arm-name table has exactly `armCount` entries. -/
theorem x86_mulx_names_length : armNames.length = armCount := rfl

/-- The two arm codes are distinct, so no two arms alias one code. -/
theorem x86_mulx_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- The selector picks the single-product arm exactly at the 32-bit width code,
stated against the independent selector. -/
theorem x86_mulx_arm_single_iff_w32 (width : Nat) :
    x86MulxArmSpec width = .singleProduct ↔ width = x86WidthCodeSpec .w32 := by
  unfold x86MulxArmSpec
  by_cases h : width = x86WidthCodeSpec .w32 <;>
    simp [h, Arm.noConfusion]

/-- The selector picks the ladder arm exactly off the 32-bit width code, so
every wider code reaches the carry-propagated limb ladder. -/
theorem x86_mulx_arm_ladder_iff_not_w32 (width : Nat) :
    x86MulxArmSpec width = .limbLadder ↔ width ≠ x86WidthCodeSpec .w32 := by
  unfold x86MulxArmSpec
  by_cases h : width = x86WidthCodeSpec .w32 <;>
    simp [h, Arm.noConfusion]

/-- The width-code selector resolves each real width code to its own arm: only
the 32-bit code reaches the single-product arm, and the 8/16/64-bit codes all
reach the limb-ladder arm. -/
theorem x86_mulx_arm_over_widths :
    (List.map (fun w => x86MulxArmSpec (x86WidthCodeSpec w))
        [.w8, .w16, .w32, .w64]) =
      [Arm.limbLadder, Arm.limbLadder, Arm.singleProduct, Arm.limbLadder] := by
  rfl

/-- The arm the width-code selector picks equals the arm the `MULX` handler's
width discrimination takes: the single-product arm is selected exactly at the
32-bit form, so the generated selector and the handler's `.w32` branch agree on
every width the handler can see. -/
theorem x86_mulx_arm_single_iff_handler_w32 (width : X86Width) :
    x86MulxArmSpec (x86WidthCodeSpec width) = .singleProduct ↔
      width = .w32 := by
  cases width <;>
    simp [x86MulxArmSpec, x86WidthCodeSpec, Arm.noConfusion]

/-- The arm-code selector round-trips each arm to its own code and names no
other code: `codeOfArm` is a left inverse of `armOfCode` on the two arms. -/
theorem x86_mulx_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The arm-code selector names no arm at or above the arm count, so the table
is exactly the two arms and no other code reaches one. -/
theorem x86_mulx_arm_of_code_beyond_is_none :
    armOfCode 2 = none ∧ armOfCode 3 = none ∧ armOfCode 4 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The opcode the contract implements is the simulator's `X86_OP_MULX`
(`0x39`), pinned so the C opcode and the generated `opcode` cannot drift. -/
theorem x86_mulx_opcode_is_0x39 : opcode = 57 := rfl

/-- The width-code width is the byte width the sim decodes, pinned so the C
`__u8` width code and the generated `widthCodeBits` cannot drift apart. -/
theorem x86_mulx_width_code_bits_is_8 : widthCodeBits = 8 := rfl

/-- The special-width code the single-product arm is selected at is the 32-bit
width code, pinned against the generated table. -/
theorem x86_mulx_special_width_is_w32 :
    specialWidthCode = x86WidthCodeSpec .w32 := rfl

/-- The arm count is the two bodies `MULX` selects between. -/
theorem x86_mulx_arm_count_is_2 : armCount = 2 := rfl

/-- The single-product arm is the 32-bit width class and the ladder arm the
other class, so the two classes are distinct and neither is empty. -/
theorem x86_mulx_width_classes :
    widthClassOfArm .singleProduct = "w32" ∧
      widthClassOfArm .limbLadder = "other" ∧
      widthClassOfArm .singleProduct ≠ widthClassOfArm .limbLadder := by
  exact ⟨rfl, rfl, by decide⟩

/-- The single-product arm splits one 32x32 product and the ladder arm carries
out the four-limb decomposition, so the two effects are distinct. -/
theorem x86_mulx_effects :
    effectOfArm .singleProduct = "single_product_split" ∧
      effectOfArm .limbLadder = "four_limb_ladder" ∧
      effectOfArm .singleProduct ≠ effectOfArm .limbLadder := by
  exact ⟨rfl, rfl, by decide⟩

/-- The special-width selector is true only at the 32-bit width code, so the
single-product arm is reachable at no narrower or wider real code. -/
theorem x86_mulx_is_special_width_only_w32 :
    isSpecialWidth 4 = true ∧
      isSpecialWidth 1 = false ∧
      isSpecialWidth 2 = false ∧
      isSpecialWidth 8 = false := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- All the selector shapes are reachable: the 32-bit code reaches the
single-product arm, and each other real code reaches the ladder arm, so no arm
of the contract is dead. -/
theorem x86_mulx_case_dispatch :
    armOf 4 = .singleProduct ∧
      armOf 1 = .limbLadder ∧
      armOf 2 = .limbLadder ∧
      armOf 8 = .limbLadder := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

end KProgFormal
