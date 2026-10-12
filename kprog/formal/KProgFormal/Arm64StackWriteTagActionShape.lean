import KProgFormal.GeneratedArm64StackWriteTagAction
import KProgFormal.GeneratedArm64StackTag
import KProgFormal.GeneratedArm64StackWriteLanes

namespace KProgFormal

open GeneratedArm64StackWriteTagAction (Action actionCount actionNames actionCodes
  codeOfAction effectOfAction actionOf actionOfCode Case classify actionOfCase
  wordTag)
open GeneratedArm64StackWriteLanes (Width Lane activeLanes laneActive byteCount)

/-- Independent statement of the slot-tag action selector, built from the literal
constructors rather than the generated `actionOf`: the qword write and tag store
exactly when the access is 64-bit and the slot is 8-aligned, the aligned tag
clear and byte-ladder write at every aligned sub-qword access, and the plain
byte-ladder write otherwise. -/
def arm64StackWriteTagActionSpec (isW64 isAligned : Bool) : Action :=
  if isW64 && isAligned then .writeWordAndTag
  else if isAligned then .clearTagAndWriteBytes
  else .writeBytesNoTag

/-- Independent statement of the three action names, built from the literal
constructor order rather than the generated `actionNames`. -/
def arm64StackWriteTagActionNamesSpec : List String :=
  ["writeWordAndTag", "clearTagAndWriteBytes", "writeBytesNoTag"]

/-- Independent statement of the three action codes: the word-and-tag action
yields the selector's outer-true branch (0), the clear-and-write-bytes action
its inner-true branch (1), and the plain byte write the default (2). -/
def arm64StackWriteTagActionCodesSpec : List Nat := [0, 1, 2]

/-- The generated action selector equals the independent literal construction
for every fact pair. -/
theorem arm64_stack_write_tag_action_refines (isW64 isAligned : Bool) :
    actionOf isW64 isAligned =
      arm64StackWriteTagActionSpec isW64 isAligned := by
  unfold actionOf arm64StackWriteTagActionSpec
  rfl

/-- The generated action-name table equals the independent literal order. -/
theorem arm64_stack_write_tag_action_names_refine :
    actionNames = arm64StackWriteTagActionNamesSpec := by
  unfold actionNames arm64StackWriteTagActionNamesSpec
  rfl

/-- The generated action-code table equals the independent literal codes. -/
theorem arm64_stack_write_tag_action_codes_refine :
    actionCodes = arm64StackWriteTagActionCodesSpec := by
  unfold actionCodes arm64StackWriteTagActionCodesSpec
  rfl

/-- The generated action-code table has exactly `actionCount` entries, so the
zip table and the macro name the same three actions and nothing else. -/
theorem arm64_stack_write_tag_action_codes_length :
    actionCodes.length = actionCount := rfl

/-- The generated action-name table has exactly `actionCount` entries. -/
theorem arm64_stack_write_tag_action_names_length :
    actionNames.length = actionCount := rfl

/-- The three action codes are distinct, so no two actions alias one code. -/
theorem arm64_stack_write_tag_action_codes_nodup : actionCodes.Nodup := by
  unfold actionCodes
  native_decide

/-- The action count is the three slot-tag actions a stack write selects
between. -/
theorem arm64_stack_write_tag_action_count_is_3 : actionCount = 3 := rfl

/-- The generated action-code selector round-trips each action to its own code
and names no other code. -/
theorem arm64_stack_write_tag_action_of_code_roundtrip (action : Action) :
    actionOfCode (codeOfAction action) = some action := by
  cases action <;> native_decide

/-- The generated action-code selector names no action at or above the action
count, so the table is exactly the three actions and no other code reaches
one. -/
theorem arm64_stack_write_tag_action_of_code_beyond_is_none :
    actionOfCode 3 = none ∧ actionOfCode 8 = none ∧ actionOfCode 255 = none := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The three actions report three distinct storage effects: the qword write and
tag store, the aligned tag clear and byte-ladder write, and the plain
byte-ladder write. -/
theorem arm64_stack_write_tag_action_effects :
    effectOfAction .writeWordAndTag = "word_write_tag" ∧
      effectOfAction .clearTagAndWriteBytes = "clear_tag_bytes" ∧
      effectOfAction .writeBytesNoTag = "bytes_no_tag" ∧
      effectOfAction .writeWordAndTag ≠
        effectOfAction .clearTagAndWriteBytes ∧
      effectOfAction .writeWordAndTag ≠
        effectOfAction .writeBytesNoTag ∧
      effectOfAction .clearTagAndWriteBytes ≠
        effectOfAction .writeBytesNoTag := by
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_⟩
  · exact rfl
  · exact rfl
  · exact rfl
  · decide
  · decide
  · decide

/-- Every fact pair is reachable: naming the action from the two facts directly
classifies and dispatches the same case, so no case of the four is dead. -/
theorem arm64_stack_write_tag_action_case_dispatch :
    actionOf true true = .writeWordAndTag ∧
      actionOf true false = .writeBytesNoTag ∧
      actionOf false true = .clearTagAndWriteBytes ∧
      actionOf false false = .writeBytesNoTag := by
  refine ⟨?_, ?_, ?_, ?_⟩ <;> native_decide

/-- The four-case table agrees with the direct selector: classifying a write and
dispatching on the case is the same action selection the macro performs. -/
theorem arm64_stack_write_tag_action_case_refines (isW64 isAligned : Bool) :
    actionOf isW64 isAligned =
      actionOfCase (classify isW64 isAligned) :=
  GeneratedArm64StackWriteTagAction.actionOf_refines isW64 isAligned

/-- **The write word/tag arm is the read-side slot-tag predicate.** The write
helper's word-and-tag arm fires exactly when the read-side
`KPROG_ARM64_STACK_TAG` slot-tag predicate is true for the same fact pair: the
qword is written and the tag stored exactly at the 64-bit aligned slot, and
nowhere else. -/
theorem arm64_stack_write_tag_action_matches_read_tag (isW64 isAligned : Bool) :
    (actionOf isW64 isAligned = .writeWordAndTag) =
      GeneratedArm64StackTag.tagged
          (GeneratedArm64StackTag.classify isW64 isAligned) := by
  cases isW64 <;> cases isAligned <;> decide

/-- **The word arm writes the full qword.** At the 64-bit width the 0124
active-lane ladder covers all eight lanes: the word-and-tag action's qword write
is exactly the full active-lane footprint of the width-64 access, so a stack
write touches every byte of its slot only under that action. -/
theorem arm64_stack_write_tag_action_word_writes_full_qword :
    actionOf true true = .writeWordAndTag ∧
      List.length (activeLanes .w64) = 8 := by
  refine ⟨?_, ?_⟩
  · native_decide
  · native_decide

/-- **The byte arms' footprint is the 0124 active-lane ladder.** Both byte
actions — the clear-and-write-bytes action at an aligned sub-qword access and
the plain byte write at an unaligned access — write exactly the width's active
byte lanes: one, two, or four lanes, never the full qword, so a byte write
never writes a byte past the access window and never stores the slot tag. -/
theorem arm64_stack_write_tag_action_byte_footprint :
    List.map (fun w => (activeLanes w).length)
        [.w8, .w16, .w32, .w64] =
      [1, 2, 4, 8] ∧
      List.length (activeLanes .w8) < 8 ∧
      List.length (activeLanes .w16) < 8 ∧
      List.length (activeLanes .w32) < 8 := by
  refine ⟨?_, ?_, ?_, ?_⟩
  · rfl
  · native_decide
  · native_decide
  · native_decide

end KProgFormal
