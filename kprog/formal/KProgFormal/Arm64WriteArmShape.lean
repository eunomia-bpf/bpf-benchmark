import KProgFormal.GeneratedArm64WriteArm
import KProgFormal.Arm64Width

namespace KProgFormal

open GeneratedArm64WriteArm (Arm armCount w32Code armNames armCodes codeOfArm
  bodyOfArm armOf armOfCode Case classify fullBody fullSpec armOfCase)

/-- Independent statement of the 32-bit width code the narrow body is selected
at, built from the width contract's 32-bit literal rather than the generated
`w32Code`. -/
def arm64WriteArmW32Spec : Nat := 4

/-- Independent statement of the writeback body selector, built from the literal
constructors rather than the generated `armOf`: the 32-bit truncating body
exactly when the access width fact holds, the full-value body otherwise. -/
def arm64WriteArmSpec (isW32 : Bool) : Arm :=
  if isW32 then .narrow
  else .full

/-- Independent statement of the two writeback bodies, built from the literal
constructor order rather than the generated `armNames`. -/
def arm64WriteArmNamesSpec : List String := ["full", "narrow"]

/-- Independent statement of the two arm codes: the full-value body yields the
selector's false branch (0) and the narrow body its true branch (1). -/
def arm64WriteArmCodesSpec : List Nat := [0, 1]

/-- The generated writeback body selector equals the independent literal
construction for every width fact. -/
theorem arm64_write_arm_refines (isW32 : Bool) :
    armOf isW32 = arm64WriteArmSpec isW32 := by
  unfold armOf arm64WriteArmSpec
  cases isW32 <;> rfl

/-- The generated body-name table equals the independent literal order. -/
theorem arm64_write_arm_names_refine :
    armNames = arm64WriteArmNamesSpec := by
  unfold armNames arm64WriteArmNamesSpec
  rfl

/-- The generated arm-code table equals the independent literal codes. -/
theorem arm64_write_arm_codes_refine :
    armCodes = arm64WriteArmCodesSpec := by
  unfold armCodes arm64WriteArmCodesSpec
  rfl

/-- The generated arm-code table has exactly `armCount` entries, so the zip
table and the macro name the same two bodies and nothing else. -/
theorem arm64_write_arm_codes_length : armCodes.length = armCount := rfl

/-- The generated body-name table has exactly `armCount` entries. -/
theorem arm64_write_arm_names_length : armNames.length = armCount := rfl

/-- The two arm codes are distinct, so no two bodies alias one code. -/
theorem arm64_write_arm_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- The independent 32-bit literal is the width contract's own 32-bit code, so
the narrow body is selected at the code the simulator decodes as 32 bits. -/
theorem arm64_write_arm_w32_spec_bound :
    arm64WidthCodeSpec .w32 = arm64WriteArmW32Spec := by
  unfold arm64WriteArmW32Spec
  rfl

/-- The generated 32-bit code is the independent literal, pinned so the C width
code and the generated `w32Code` cannot drift. -/
theorem arm64_write_arm_w32_is_w32 :
    w32Code = arm64WriteArmW32Spec := rfl

/-- The arm count is the two writeback bodies the helper selects between. -/
theorem arm64_write_arm_count_is_2 : armCount = 2 := rfl

/-- The generated arm-code selector round-trips each body to its own code and
names no other code: `codeOfArm` is a left inverse of `armOfCode` on the two
bodies. -/
theorem arm64_write_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The arm-code selector names no body at or above the arm count, so the table
is exactly the two bodies and no other code reaches one. -/
theorem arm64_write_arm_of_code_beyond_is_none :
    armOfCode 2 = none ∧ armOfCode 8 = none ∧ armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The two bodies report two distinct writeback effects: the full-value
writeback and the 32-bit truncating writeback. -/
theorem arm64_write_arm_bodies :
    bodyOfArm .full = "full_width_writeback" ∧
      bodyOfArm .narrow = "narrow_width_writeback" ∧
      bodyOfArm .full ≠ bodyOfArm .narrow := by
  exact ⟨rfl, rfl, by decide⟩

/-- The selector picks the narrow body exactly when the access width is the
32-bit code, stated against the independent selector. -/
theorem arm64_write_arm_narrow_iff (isW32 : Bool) :
    arm64WriteArmSpec isW32 = .narrow ↔ isW32 = true := by
  unfold arm64WriteArmSpec
  cases isW32 <;> simp

/-- The selector picks the full-value body exactly when the access width is not
the 32-bit code. -/
theorem arm64_write_arm_full_iff (isW32 : Bool) :
    arm64WriteArmSpec isW32 = .full ↔ isW32 = false := by
  unfold arm64WriteArmSpec
  cases isW32 <;> simp

/-- The selector resolves each real width code to its own body: only the 32-bit
code reaches the narrow truncating body, and the 8/16/64-bit codes all reach the
full-value body. The 8/16-bit values are already masked narrower than 32 bits by
the pre-truncation step, so the full-value body carries them unchanged. -/
theorem arm64_write_arm_over_widths :
    (List.map
        (fun w => arm64WriteArmSpec
          (arm64WidthCodeSpec w == arm64WriteArmW32Spec))
        [.w8, .w16, .w32, .w64]) =
      [Arm.full, Arm.full, Arm.narrow, Arm.full] := by
  rfl

/-- Both bodies are reachable: the 32-bit code reaches the narrow body and every
other code the full-value body, so neither body of the contract is dead. -/
theorem arm64_write_arm_case_dispatch :
    armOf true = .narrow ∧ armOf false = .full := by
  exact ⟨rfl, rfl⟩

/-- The two-case table agrees with the direct `armOf`: classifying a writeback
and dispatching on the case is the same body selection the macro performs. -/
theorem arm64_write_arm_case_refines (isW32 : Bool) :
    armOf isW32 = armOfCase (classify isW32) :=
  GeneratedArm64WriteArm.armOf_refines isW32

/-- **The narrow arm is exactly the pre-truncation width's 32-bit code.** The
narrow body is selected exactly at the width the pre-truncation step
(`KPROG_ARM64_APPLY_WIDTH`) masks to 32 bits: the selector's fact is the width
contract's own 32-bit code, so the truncating body and the masking step agree on
one width and no other. -/
theorem arm64_write_arm_narrow_matches_pre_truncation (w : Arm64Width) :
    arm64WriteArmSpec (arm64WidthCodeSpec w == arm64WriteArmW32Spec) = .narrow ↔
      w = .w32 := by
  cases w <;> decide

/-- **The full arm covers every width the narrow arm skips.** Whenever the width
code is not the 32-bit code, the writeback reaches the full-value body, which
writes the already-width-masked value whole. -/
theorem arm64_write_arm_full_covers (w : Arm64Width)
    (h : w ≠ .w32) :
    arm64WriteArmSpec (arm64WidthCodeSpec w == arm64WriteArmW32Spec) = .full := by
  cases w <;> simp_all <;> decide

end KProgFormal
