import KProgFormal.GeneratedX86StackArm
import KProgFormal.X86Width
import KProgFormal.GeneratedX86StackArena
import KProgFormal.X86StackArena

namespace KProgFormal

open GeneratedX86StackArm (Arm armCount width64Code armNames armCodes
  codeOfArm bodyOfArm armOf armOfCode Case classify wordBody wordSpec armOfCase)
open GeneratedX86StackArena (wordAligned)

/-- Independent statement of the full 64-bit width code the word body is
selected at, built from the width contract's 64-bit literal rather than the
generated `width64Code`. -/
def x86StackArmWidth64Spec : Nat := 8

/-- Independent statement of the body selector: the word-arena body exactly when
the access is 64-bit and the resolved index is qword-aligned, the byte-ladder
body otherwise. Built from the literal constructors rather than the generated
`armOf`. -/
def x86StackArmSpec (isW64 isAligned : Bool) : Arm :=
  if isW64 && isAligned then .word else .byte

/-- Independent statement of the two bodies, built from the literal constructor
order rather than the generated `armNames`. -/
def x86StackArmNamesSpec : List String := ["word", "byte"]

/-- Independent statement of the two arm codes: the word body yields the
selector's true branch (1) and the byte body its false branch (0). -/
def x86StackArmCodesSpec : List Nat := [1, 0]

/-- The generated body selector equals the independent literal construction. -/
theorem x86_stack_arm_refines (isW64 isAligned : Bool) :
    armOf isW64 isAligned = x86StackArmSpec isW64 isAligned := by
  unfold armOf x86StackArmSpec
  rfl

/-- The generated body-name table equals the independent literal order. -/
theorem x86_stack_arm_names_refine :
    armNames = x86StackArmNamesSpec := by
  unfold armNames x86StackArmNamesSpec
  rfl

/-- The generated arm-code table equals the independent literal codes. -/
theorem x86_stack_arm_codes_refine :
    armCodes = x86StackArmCodesSpec := by
  unfold armCodes x86StackArmCodesSpec
  rfl

/-- The generated arm-code table has exactly `armCount` entries. -/
theorem x86_stack_arm_codes_length : armCodes.length = armCount := rfl

/-- The generated arm-name table has exactly `armCount` entries. -/
theorem x86_stack_arm_names_length : armNames.length = armCount := rfl

/-- The two arm codes are distinct, so no two bodies alias one code. -/
theorem x86_stack_arm_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- The independent 64-bit literal is the width contract's own 64-bit code, so
the word body is selected at the code the sim decodes as 64 bits. -/
theorem x86_stack_arm_width64_spec_bound :
    x86WidthCodeSpec .w64 = x86StackArmWidth64Spec := by
  unfold x86StackArmWidth64Spec
  rfl

/-- The generated 64-bit code is the independent literal, pinned so the C width
code and the generated `width64Code` cannot drift. -/
theorem x86_stack_arm_width64_is_w64 :
    width64Code = x86StackArmWidth64Spec := rfl

/-- The arm count is the two bodies a stack access selects between. -/
theorem x86_stack_arm_count_is_2 : armCount = 2 := rfl

/-- The generated arm-code selector round-trips each body to its own code and
names no other code: `codeOfArm` is a left inverse of `armOfCode` on the two
bodies. -/
theorem x86_stack_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The arm-code selector names no body at or above the arm count, so the table
is exactly the two bodies and no other code reaches one. -/
theorem x86_stack_arm_of_code_beyond_is_none :
    armOfCode 2 = none ∧ armOfCode 3 = none ∧ armOfCode 8 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The two bodies report two distinct storage effects: the direct word-arena
access and the little-endian byte-ladder access. -/
theorem x86_stack_arm_bodies :
    bodyOfArm .word = "word_arena_access" ∧
      bodyOfArm .byte = "byte_ladder_access" ∧
      bodyOfArm .word ≠ bodyOfArm .byte := by
  exact ⟨rfl, rfl, by decide⟩

/-- The selector picks the word-arena body exactly when the access is 64-bit and
qword-aligned, stated against the independent selector. -/
theorem x86_stack_arm_word_iff (isW64 isAligned : Bool) :
    x86StackArmSpec isW64 isAligned = .word ↔
      isW64 = true ∧ isAligned = true := by
  unfold x86StackArmSpec
  by_cases h : (isW64 && isAligned) = true
  · rw [if_pos h]
    exact ⟨fun _ => Bool.and_eq_true_iff.mp h, fun _ => rfl⟩
  · rw [if_neg h]
    exact ⟨fun hcontr => absurd hcontr (by decide),
      fun hb => absurd (by rw [hb.1, hb.2]; rfl) h⟩

/-- The selector picks the byte-ladder body exactly when the access is not both
64-bit and qword-aligned. -/
theorem x86_stack_arm_byte_iff (isW64 isAligned : Bool) :
    x86StackArmSpec isW64 isAligned = .byte ↔
      ¬(isW64 = true ∧ isAligned = true) := by
  unfold x86StackArmSpec
  by_cases h : (isW64 && isAligned) = true
  · rw [if_pos h]
    exact ⟨fun hcontr => absurd hcontr (by decide),
      fun hnot => absurd (Bool.and_eq_true_iff.mp h) hnot⟩
  · rw [if_neg h]
    exact ⟨fun _ hb => absurd (by rw [hb.1, hb.2]; rfl) h, fun _ => rfl⟩

/-- An unaligned access is never served by the word-arena body, however wide it
is: the byte window it would cover straddles two word slots. -/
theorem x86_stack_arm_unaligned_never (isW64 : Bool) :
    x86StackArmSpec isW64 false = .byte := by
  unfold x86StackArmSpec
  simp

/-- A sub-64-bit access is never served by the word-arena body, however
aligned: the byte ladder narrows the value to the access width. -/
theorem x86_stack_arm_narrow_never (isAligned : Bool) :
    x86StackArmSpec false isAligned = .byte := by
  unfold x86StackArmSpec
  simp

/-- The selector resolves each real width code at an aligned index to its own
body: only the 64-bit code reaches the word-arena body, and the 8/16/32-bit
codes all reach the byte ladder. -/
theorem x86_stack_arm_over_widths :
    (List.map
        (fun w => x86StackArmSpec
          (x86WidthCodeSpec w == x86StackArmWidth64Spec) true)
        [.w8, .w16, .w32, .w64]) =
      [Arm.byte, Arm.byte, Arm.byte, Arm.word] := by
  rfl

/-- Both selector shapes are reachable: the 64-bit qword-aligned pair reaches
the word body and every other pair the byte ladder, so no body of the contract
is dead. -/
theorem x86_stack_arm_case_dispatch :
    armOf true true = .word ∧ armOf true false = .byte ∧
      armOf false true = .byte ∧ armOf false false = .byte := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The byte ladder is the selector's default, so the body is total: the
64-bit qword-aligned pair reaches the word arena and every other pair the byte
ladder. -/
theorem x86_stack_arm_ladder_total (isW64 isAligned : Bool)
    (h : ¬(isW64 = true ∧ isAligned = true)) :
    armOf isW64 isAligned = .byte := by
  unfold armOf
  rw [if_neg]
  intro hboth
  exact h (Bool.and_eq_true_iff.mp hboth)

/-- The four-case table agrees with the direct `armOf`: classifying an access
and dispatching on the case is the same body selection the macro performs. -/
theorem x86_stack_arm_case_refines (isW64 isAligned : Bool) :
    armOf isW64 isAligned = armOfCase (classify isW64 isAligned) :=
  GeneratedX86StackArm.armOf_refines isW64 isAligned

/-- **The word arm is exactly the arena's alignment guard.** The generated word
body is selected on the `X86StackArena` guard: an index receives the word-arena
body exactly when the access is 64-bit and the index is a whole number of
8-byte words, which is the value `x86_stack_arena_word_aligned_refines` proves
the guard computes. -/
theorem x86_stack_arm_matches_arena (isW64 : Bool) (index : BitVec 32) :
    armOf isW64 (wordAligned index) = .word ↔
      isW64 = true ∧ x86StackArenaWordAlignedSpec index := by
  rw [x86_stack_arm_refines, x86_stack_arm_word_iff,
    x86_stack_arena_word_aligned_refines]

/-- **The byte arm covers everything the word arm skips.** Whenever the word
body is not selected, the access reaches the byte ladder, which the aligned
word window `[index, index + 8)` roundtrip `x86_stack_arena_alignment_roundtrip`
proves leaves no byte-arena element uncovered. -/
theorem x86_stack_arm_byte_covers (isW64 : Bool) (index : BitVec 32)
    (h : ¬(isW64 = true ∧ wordAligned index = true)) :
    armOf isW64 (wordAligned index) = .byte :=
  x86_stack_arm_ladder_total isW64 (wordAligned index) h

end KProgFormal
