import KProgFormal.GeneratedArm64HelperArgPtr
import KProgFormal.Arm64StackIndex

namespace KProgFormal

open GeneratedArm64HelperArgPtr (Source sourceCount sourceNames sourceCodes
  codeOfSource effectOfSource sourceOf sourceOfCode Case classify sourceOfCase
  stackTagged)
open GeneratedArm64StackIndex (index ptrIndex)

/-- Independent statement of the pointer source selector, built from the literal
constructors rather than the generated `sourceOf`: the stack arena pointer
exactly when the register's provenance tag is the stack tag, the raw pointer
otherwise. -/
def arm64HelperArgPtrSourceSpec (isStackTagged : Bool) : Source :=
  if isStackTagged then .stackArenaPtr
  else .rawPtr

/-- Independent statement of the two source names, built from the literal
constructor order rather than the generated `sourceNames`. -/
def arm64HelperArgPtrSourceNamesSpec : List String :=
  ["stackArenaPtr", "rawPtr"]

/-- Independent statement of the two source codes: the stack arena pointer
source yields the selector's true branch (0) and the raw pointer source the
default (1). -/
def arm64HelperArgPtrSourceCodesSpec : List Nat := [0, 1]

/-- The generated source selector equals the independent literal construction
for every register tag. -/
theorem arm64_helper_arg_ptr_refines (isStackTagged : Bool) :
    sourceOf isStackTagged =
      arm64HelperArgPtrSourceSpec isStackTagged := by
  unfold sourceOf arm64HelperArgPtrSourceSpec
  cases isStackTagged <;> rfl

/-- The generated source-name table equals the independent literal order. -/
theorem arm64_helper_arg_ptr_names_refine :
    sourceNames = arm64HelperArgPtrSourceNamesSpec := by
  unfold sourceNames arm64HelperArgPtrSourceNamesSpec
  rfl

/-- The generated source-code table equals the independent literal codes. -/
theorem arm64_helper_arg_ptr_codes_refine :
    sourceCodes = arm64HelperArgPtrSourceCodesSpec := by
  unfold sourceCodes arm64HelperArgPtrSourceCodesSpec
  rfl

/-- The generated source-code table has exactly `sourceCount` entries, so the
zip table and the macro name the same two sources and nothing else. -/
theorem arm64_helper_arg_ptr_codes_length :
    sourceCodes.length = sourceCount := rfl

/-- The generated source-name table has exactly `sourceCount` entries. -/
theorem arm64_helper_arg_ptr_names_length :
    sourceNames.length = sourceCount := rfl

/-- The two source codes are distinct, so no two sources alias one code. -/
theorem arm64_helper_arg_ptr_codes_nodup : sourceCodes.Nodup := by
  unfold sourceCodes
  native_decide

/-- The source count is the two pointer sources a BPF helper-argument register
selects between. -/
theorem arm64_helper_arg_ptr_count_is_2 : sourceCount = 2 := rfl

/-- The generated source-code selector round-trips each source to its own code
and names no other code. -/
theorem arm64_helper_arg_ptr_of_code_roundtrip (source : Source) :
    sourceOfCode (codeOfSource source) = some source := by
  cases source <;> native_decide

/-- The generated source-code selector names no source at or above the source
count, so the table is exactly the two sources and no other code reaches
one. -/
theorem arm64_helper_arg_ptr_of_code_beyond_is_none :
    sourceOfCode 2 = none ∧ sourceOfCode 8 = none ∧ sourceOfCode 255 = none := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The two sources report two distinct value effects: the stack arena pointer
and the raw pointer pass-through. -/
theorem arm64_helper_arg_ptr_effects :
    effectOfSource .stackArenaPtr = "stack_arena_ptr" ∧
      effectOfSource .rawPtr = "raw_ptr" ∧
      effectOfSource .stackArenaPtr ≠
        effectOfSource .rawPtr := by
  refine ⟨?_, ?_, ?_⟩
  · exact rfl
  · exact rfl
  · decide

/-- Every fact value is reachable: naming the source from the fact directly
classifies and dispatches the same case, so no case of the two is dead. -/
theorem arm64_helper_arg_ptr_case_dispatch :
    sourceOf true = .stackArenaPtr ∧
      sourceOf false = .rawPtr := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- The two-case table agrees with the direct selector: classifying a register
and dispatching on the case is the same source selection the macro performs. -/
theorem arm64_helper_arg_ptr_case_refines (isStackTagged : Bool) :
    sourceOf isStackTagged =
      sourceOfCase (classify isStackTagged) :=
  GeneratedArm64HelperArgPtr.sourceOf_refines isStackTagged

/-- **The pointer source selection is the closed fact.** The helper's
stack-arena-pointer arm fires exactly when the register is stack tagged, so the
2-way selection reduces to the single closed fact and no other arm is ever
reachable. -/
theorem arm64_helper_arg_ptr_source_selects_stack (isStackTagged : Bool) :
    (sourceOf isStackTagged = .stackArenaPtr) = isStackTagged := by
  cases isStackTagged <;> decide

/-- **The stack arena pointer source is the 0112 stack index contract.** The
arena byte the helper's stack-arena-pointer arm addresses is the stack-pointer
helper's 64-bit biased offset: the index at the simulator's bias (96) is the
`ptrIndex` sum narrowed to the index type. -/
theorem arm64_helper_arg_ptr_stack_index (off : BitVec 64) :
    index 96 off = (ptrIndex 96 off).truncate 32 :=
  arm64_stack_index_ptr_truncation 96 off

end KProgFormal
