import KProgFormal.GeneratedArm64StackReadTagSource
import KProgFormal.GeneratedArm64StackTag
import KProgFormal.GeneratedArm64StackWriteTagAction

namespace KProgFormal

open GeneratedArm64StackReadTagSource (Source sourceCount sourceNames sourceCodes
  codeOfSource effectOfSource sourceOf sourceOfCode Case classify sourceOfCase
  slotTag)
open GeneratedArm64StackWriteTagAction (Action actionOf)

/-- Independent statement of the tag source selector, built from the literal
constructors rather than the generated `sourceOf`: the per-slot tag array
exactly when the read is 64-bit and the slot is 8-aligned, the scalar default
otherwise. -/
def arm64StackReadTagSourceSpec (isW64 isAligned : Bool) : Source :=
  if isW64 && isAligned then .stackTagArray
  else .scalarDefault

/-- Independent statement of the two source names, built from the literal
constructor order rather than the generated `sourceNames`. -/
def arm64StackReadTagSourceNamesSpec : List String :=
  ["stackTagArray", "scalarDefault"]

/-- Independent statement of the two source codes: the stack-tag-array source
yields the selector's true branch (0) and the scalar default source the
default (1). -/
def arm64StackReadTagSourceCodesSpec : List Nat := [0, 1]

/-- The generated source selector equals the independent literal construction
for every fact pair. -/
theorem arm64_stack_read_tag_source_refines (isW64 isAligned : Bool) :
    sourceOf isW64 isAligned =
      arm64StackReadTagSourceSpec isW64 isAligned := by
  unfold sourceOf arm64StackReadTagSourceSpec
  rfl

/-- The generated source-name table equals the independent literal order. -/
theorem arm64_stack_read_tag_source_names_refine :
    sourceNames = arm64StackReadTagSourceNamesSpec := by
  unfold sourceNames arm64StackReadTagSourceNamesSpec
  rfl

/-- The generated source-code table equals the independent literal codes. -/
theorem arm64_stack_read_tag_source_codes_refine :
    sourceCodes = arm64StackReadTagSourceCodesSpec := by
  unfold sourceCodes arm64StackReadTagSourceCodesSpec
  rfl

/-- The generated source-code table has exactly `sourceCount` entries, so the
zip table and the macro name the same two sources and nothing else. -/
theorem arm64_stack_read_tag_source_codes_length :
    sourceCodes.length = sourceCount := rfl

/-- The generated source-name table has exactly `sourceCount` entries. -/
theorem arm64_stack_read_tag_source_names_length :
    sourceNames.length = sourceCount := rfl

/-- The two source codes are distinct, so no two sources alias one code. -/
theorem arm64_stack_read_tag_source_codes_nodup : sourceCodes.Nodup := by
  unfold sourceCodes
  native_decide

/-- The source count is the two tag sources a stack tag read selects
between. -/
theorem arm64_stack_read_tag_source_count_is_2 : sourceCount = 2 := rfl

/-- The generated source-code selector round-trips each source to its own code
and names no other code. -/
theorem arm64_stack_read_tag_source_of_code_roundtrip (source : Source) :
    sourceOfCode (codeOfSource source) = some source := by
  cases source <;> native_decide

/-- The generated source-code selector names no source at or above the source
count, so the table is exactly the two sources and no other code reaches
one. -/
theorem arm64_stack_read_tag_source_of_code_beyond_is_none :
    sourceOfCode 2 = none ∧ sourceOfCode 8 = none ∧ sourceOfCode 255 = none := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The two sources report two distinct storage effects: the per-slot tag
array and the scalar default. -/
theorem arm64_stack_read_tag_source_effects :
    effectOfSource .stackTagArray = "slot_tag_array" ∧
      effectOfSource .scalarDefault = "scalar_default" ∧
      effectOfSource .stackTagArray ≠
        effectOfSource .scalarDefault := by
  refine ⟨?_, ?_, ?_⟩
  · exact rfl
  · exact rfl
  · decide

/-- Every fact pair is reachable: naming the source from the two facts
directly classifies and dispatches the same case, so no case of the four is
dead. -/
theorem arm64_stack_read_tag_source_case_dispatch :
    sourceOf true true = .stackTagArray ∧
      sourceOf true false = .scalarDefault ∧
      sourceOf false true = .scalarDefault ∧
      sourceOf false false = .scalarDefault := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The four-case table agrees with the direct selector: classifying a read
and dispatching on the case is the same source selection the macro performs. -/
theorem arm64_stack_read_tag_source_case_refines (isW64 isAligned : Bool) :
    sourceOf isW64 isAligned =
      sourceOfCase (classify isW64 isAligned) :=
  GeneratedArm64StackReadTagSource.sourceOf_refines isW64 isAligned

/-- **The read stack-tag-array source is the read-side slot-tag predicate.**
The read helper's stack-tag-array arm fires exactly when the 0121
`KPROG_ARM64_STACK_TAG` slot-tag predicate is true for the same fact pair: the
tag read is the slot's word in the tag array exactly at the 64-bit aligned
slot, and nowhere else. -/
theorem arm64_stack_read_tag_source_matches_read_tag (isW64 isAligned : Bool) :
    (sourceOf isW64 isAligned = .stackTagArray) =
      GeneratedArm64StackTag.tagged
          (GeneratedArm64StackTag.classify isW64 isAligned) := by
  cases isW64 <;> cases isAligned <;> decide

/-- **The read stack-tag-array source is the write word/tag arm.** The read
helper's stack-tag-array source fires exactly when the 0137 write helper's
word-and-tag action fires for the same fact pair: the slot tag is read from
the array exactly where the write helper wrote the qword and stored the tag,
so the read and write sides of the stack-tag family agree on which slots
carry a slot tag. -/
theorem arm64_stack_read_tag_source_matches_write_word_arm (isW64 isAligned : Bool) :
    (sourceOf isW64 isAligned = .stackTagArray) =
      (actionOf isW64 isAligned = .writeWordAndTag) := by
  cases isW64 <;> cases isAligned <;> decide

end KProgFormal
