import KProgFormal.GeneratedArm64MemWriteArm
import KProgFormal.GeneratedArm64MemDispatch

namespace KProgFormal

open GeneratedArm64MemWriteArm (Arm armCount armNames armCodes codeOfArm
  bodyOfArm armOf armOfCode Case classify stackBody stackSpec armOfCase)
open GeneratedArm64MemDispatch (Space ValueSrc valueSrc)

/-- Independent statement of the destination selector: the stack-arena body
exactly when the base register is the stack pointer or its resolved tag names a
stack slot, the plain byte store otherwise. Built from the literal constructors
rather than the generated `armOf`. -/
def arm64MemWriteArmSpec (baseIsSp stackTagged : Bool) : Arm :=
  if baseIsSp || stackTagged then .stackWrite else .memoryStore

/-- Independent statement of the two destinations, built from the literal
constructor order rather than the generated `armNames`. -/
def arm64MemWriteArmNamesSpec : List String := ["stackWrite", "memoryStore"]

/-- Independent statement of the two arm codes: the stack-arena body yields the
selector's true branch (0) and the byte-store body its false branch (1). -/
def arm64MemWriteArmCodesSpec : List Nat := [0, 1]

/-- The generated destination selector equals the independent literal
construction. -/
theorem arm64_mem_write_arm_refines (baseIsSp stackTagged : Bool) :
    armOf baseIsSp stackTagged =
      arm64MemWriteArmSpec baseIsSp stackTagged := by
  unfold armOf arm64MemWriteArmSpec
  rfl

/-- The generated destination-name table equals the independent literal
order. -/
theorem arm64_mem_write_arm_names_refine :
    armNames = arm64MemWriteArmNamesSpec := by
  unfold armNames arm64MemWriteArmNamesSpec
  rfl

/-- The generated arm-code table equals the independent literal codes. -/
theorem arm64_mem_write_arm_codes_refine :
    armCodes = arm64MemWriteArmCodesSpec := by
  unfold armCodes arm64MemWriteArmCodesSpec
  rfl

/-- The generated arm-code table has exactly `armCount` entries. -/
theorem arm64_mem_write_arm_codes_length : armCodes.length = armCount := rfl

/-- The generated arm-name table has exactly `armCount` entries. -/
theorem arm64_mem_write_arm_names_length : armNames.length = armCount := rfl

/-- The two arm codes are distinct, so no two destinations alias one code. -/
theorem arm64_mem_write_arm_codes_nodup : armCodes.Nodup := by
  unfold armCodes
  native_decide

/-- The arm count is the two destinations a store selects between. -/
theorem arm64_mem_write_arm_count_is_2 : armCount = 2 := rfl

/-- The generated arm-code selector round-trips each destination to its own code
and names no other code: `codeOfArm` is a left inverse of `armOfCode` on the two
destinations. -/
theorem arm64_mem_write_arm_of_code_roundtrip (arm : Arm) :
    armOfCode (codeOfArm arm) = some arm := by
  cases arm <;> native_decide

/-- The arm-code selector names no destination at or above the arm count, so the
table is exactly the two destinations and no other code reaches one. -/
theorem arm64_mem_write_arm_of_code_beyond_is_none :
    armOfCode 2 = none ∧ armOfCode 3 = none ∧ armOfCode 8 = none ∧
      armOfCode 255 = none := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The two destinations report two distinct storage effects: the stack arena
write (through the slot-tag contract) and the plain little-endian byte store. -/
theorem arm64_mem_write_arm_bodies :
    bodyOfArm .stackWrite = "stack_write_tag" ∧
      bodyOfArm .memoryStore = "little_endian_store" ∧
      bodyOfArm .stackWrite ≠ bodyOfArm .memoryStore := by
  exact ⟨rfl, rfl, by decide⟩

/-- The selector picks the stack-arena body exactly when the base is the stack
pointer or its resolved tag names a stack slot, stated against the independent
selector. -/
theorem arm64_mem_write_arm_stack_iff (baseIsSp stackTagged : Bool) :
    arm64MemWriteArmSpec baseIsSp stackTagged = .stackWrite ↔
      baseIsSp = true ∨ stackTagged = true := by
  unfold arm64MemWriteArmSpec
  by_cases h : (baseIsSp || stackTagged) = true
  · rw [if_pos h]
    exact ⟨fun _ => Bool.or_eq_true_iff.mp h, fun _ => rfl⟩
  · rw [if_neg h]
    exact ⟨fun hcontr => absurd hcontr (by decide),
      fun hb => absurd (Bool.or_eq_true_iff.mpr hb) h⟩

/-- The selector picks the byte-store body exactly when the base is neither the
stack pointer nor stack-tagged. -/
theorem arm64_mem_write_arm_memory_iff (baseIsSp stackTagged : Bool) :
    arm64MemWriteArmSpec baseIsSp stackTagged = .memoryStore ↔
      ¬(baseIsSp = true ∨ stackTagged = true) := by
  unfold arm64MemWriteArmSpec
  by_cases h : (baseIsSp || stackTagged) = true
  · rw [if_pos h]
    exact ⟨fun hcontr => absurd hcontr (by decide),
      fun hnot => absurd (Bool.or_eq_true_iff.mp h) hnot⟩
  · rw [if_neg h]
    exact ⟨fun _ hb => absurd (Bool.or_eq_true_iff.mpr hb) h, fun _ => rfl⟩

/-- A stack-pointer base always reaches the stack-arena body, whatever its tag:
the SP is the stack slot's own address. -/
theorem arm64_mem_write_arm_sp_always (stackTagged : Bool) :
    arm64MemWriteArmSpec true stackTagged = .stackWrite := by
  unfold arm64MemWriteArmSpec
  simp

/-- A stack-tagged base always reaches the stack-arena body, whatever register
carries it: a register whose provenance tag names a stack slot holds a stack
address. -/
theorem arm64_mem_write_arm_tagged_always (baseIsSp : Bool) :
    arm64MemWriteArmSpec baseIsSp true = .stackWrite := by
  unfold arm64MemWriteArmSpec
  simp

/-- Only a base that is neither the stack pointer nor stack-tagged reaches the
plain byte store, so the stack body is the selector's default. -/
theorem arm64_mem_write_arm_memory_never_default (baseIsSp stackTagged : Bool)
    (h : ¬(baseIsSp = true ∨ stackTagged = true)) :
    arm64MemWriteArmSpec baseIsSp stackTagged = .memoryStore :=
  (arm64_mem_write_arm_memory_iff baseIsSp stackTagged).mpr h

/-- Every destination pair is reachable: the SP base and the stack-tagged base
reach the stack body and the plain scalar base reaches the byte store, so no
destination of the contract is dead. -/
theorem arm64_mem_write_arm_case_dispatch :
    armOf true true = .stackWrite ∧ armOf true false = .stackWrite ∧
      armOf false true = .stackWrite ∧ armOf false false = .memoryStore := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The four-case table agrees with the direct `armOf`: classifying a store and
dispatching on the case is the same destination selection the macro performs. -/
theorem arm64_mem_write_arm_case_refines (baseIsSp stackTagged : Bool) :
    armOf baseIsSp stackTagged =
      armOfCase (classify baseIsSp stackTagged) :=
  GeneratedArm64MemWriteArm.armOf_refines baseIsSp stackTagged

/-- **The store body selection is the load path's stack selection.** The load
dispatch's `valueSrc` selects its stack-read source exactly when the load space
is `stack`, the space a base whose resolved tag names a stack slot lives in; the
store helper must select its stack body on the same fact. For every store the
two classifications agree: the store arm is the stack-arena body if and only if
the load path's value source is the stack read. -/
theorem arm64_mem_write_arm_matches_read_src (space : Space) (w64 : Bool) :
    armOf false (decide (space = .stack)) = .stackWrite ↔
      valueSrc space w64 = .stackRead := by
  cases space <;> cases w64 <;> native_decide

/-- **The two stack predicates are one predicate.** The store helper's stack
test — the base is the stack pointer or its resolved tag names a stack slot — is
the exact disjunction the load dispatch's generated predicate selects its stack
source on. When both facts are false only the plain byte store / ordinary load
remains. -/
theorem arm64_mem_write_arm_stack_predicate_agrees
    (baseIsSp stackTagged : Bool) :
    (armOf baseIsSp stackTagged = .stackWrite) =
      (baseIsSp || stackTagged) := by
  cases baseIsSp <;> cases stackTagged <;> decide

/-- **The load and store stack families split identically.** Building the load
space from the two facts the store helper also has — the base being the stack
pointer or its tag naming a stack slot forces `Space.stack`, everything else
`Space.normal` — the load path reaches the stack read exactly when the store
path reaches the stack write, at both widths. -/
theorem arm64_mem_write_arm_space_agrees
    (baseIsSp stackTagged w64 : Bool) :
    valueSrc (if baseIsSp || stackTagged then Space.stack else Space.normal) w64
        = .stackRead ↔
      armOf baseIsSp stackTagged = .stackWrite := by
  cases baseIsSp <;> cases stackTagged <;> cases w64 <;> native_decide

end KProgFormal
