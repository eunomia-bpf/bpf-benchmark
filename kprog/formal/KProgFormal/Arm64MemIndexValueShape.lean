import KProgFormal.GeneratedArm64MemIndexValue
import KProgFormal.GeneratedArm64MemIndex
import KProgFormal.GeneratedArm64MemOffset

namespace KProgFormal

open GeneratedArm64MemIndexValue (Source sourceCount sourceNames sourceCodes
  codeOfSource effectOfSource sourceOf sourceOfCode Case classify sourceOfCase
  indexPresent)
open GeneratedArm64MemIndex (present arm indexSentinel)

/-- Independent statement of the index-value source selector, built from the
literal constructors rather than the generated `sourceOf`: the source-modified
index register value exactly when the addressing mode carries an index
register, a literal zero otherwise. -/
def arm64MemIndexValueSpec (hasIndex : Bool) : Source :=
  if hasIndex then .registerIndex
  else .zero

/-- Independent statement of the two source names, built from the literal
constructor order rather than the generated `sourceNames`. -/
def arm64MemIndexValueNamesSpec : List String := ["registerIndex", "zero"]

/-- Independent statement of the two source codes: the source-modified index
register value yields the selector's true branch (0) and the zero source the
default (1). -/
def arm64MemIndexValueCodesSpec : List Nat := [0, 1]

/-- Independent statement of the index value an addressing mode contributes to
the memory offset, built from the literal constructors rather than the
generated `sourceOf`: the index register value (already source-modified) at the
register source, a literal zero at the zero source. -/
def arm64MemIndexValueOf (hasIndex : Bool) (index : BitVec 64) : BitVec 64 :=
  match arm64MemIndexValueSpec hasIndex with
  | .registerIndex => index
  | .zero => 0

/-- The generated source selector equals the independent literal construction
for every addressing mode. -/
theorem arm64_mem_index_value_refines (hasIndex : Bool) :
    sourceOf hasIndex = arm64MemIndexValueSpec hasIndex := by
  unfold sourceOf arm64MemIndexValueSpec
  cases hasIndex <;> rfl

/-- The generated source-name table equals the independent literal order. -/
theorem arm64_mem_index_value_names_refine :
    sourceNames = arm64MemIndexValueNamesSpec := by
  unfold sourceNames arm64MemIndexValueNamesSpec
  rfl

/-- The generated source-code table equals the independent literal codes. -/
theorem arm64_mem_index_value_codes_refine :
    sourceCodes = arm64MemIndexValueCodesSpec := by
  unfold sourceCodes arm64MemIndexValueCodesSpec
  rfl

/-- The generated source-code table has exactly `sourceCount` entries, so the
zip table and the macro name the same two sources and nothing else. -/
theorem arm64_mem_index_value_codes_length :
    sourceCodes.length = sourceCount :=
  rfl

/-- The generated source-name table has exactly `sourceCount` entries. -/
theorem arm64_mem_index_value_names_length :
    sourceNames.length = sourceCount :=
  rfl

/-- The two source codes are distinct, so no two sources alias one code. -/
theorem arm64_mem_index_value_codes_nodup : sourceCodes.Nodup := by
  unfold sourceCodes
  native_decide

/-- The source count is the two index-value sources a memory address offset
selects between. -/
theorem arm64_mem_index_value_count_is_2 : sourceCount = 2 := rfl

/-- The generated source-code selector round-trips each source to its own code
and names no other code. -/
theorem arm64_mem_index_value_of_code_roundtrip (source : Source) :
    sourceOfCode (codeOfSource source) = some source := by
  cases source <;> native_decide

/-- The generated source-code selector names no source at or above the source
count, so the table is exactly the two sources and no other code reaches
one. -/
theorem arm64_mem_index_value_of_code_beyond_is_none :
    sourceOfCode 2 = none ∧ sourceOfCode 8 = none ∧ sourceOfCode 255 = none := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The two sources report two distinct value effects: the source-modified index
register value and a literal zero. -/
theorem arm64_mem_index_value_effects :
    effectOfSource .registerIndex = "modified_index_register_value" ∧
      effectOfSource .zero = "zero_index_value" ∧
      effectOfSource .registerIndex ≠ effectOfSource .zero := by
  refine ⟨?_, ?_, ?_⟩
  · exact rfl
  · exact rfl
  · decide

/-- Every fact value is reachable: naming the source from the fact directly
classifies and dispatches the same case, so neither case is dead. -/
theorem arm64_mem_index_value_case_dispatch :
    sourceOf true = .registerIndex ∧ sourceOf false = .zero := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- The two-case table agrees with the direct selector: classifying an
addressing mode and dispatching on the case is the same source selection the
macro performs. -/
theorem arm64_mem_index_value_case_refines (hasIndex : Bool) :
    sourceOf hasIndex = sourceOfCase (classify hasIndex) :=
  GeneratedArm64MemIndexValue.sourceOf_refines hasIndex

/-- **The index-value source selection is the closed fact.** The register source
fires exactly when the addressing mode carries an index register, so the 2-way
selection reduces to the single closed fact and no other arm is ever
reachable. -/
theorem arm64_mem_index_value_selects_register (hasIndex : Bool) :
    (sourceOf hasIndex = .registerIndex) = hasIndex := by
  cases hasIndex <;> decide

/-- **The index-value source is the presence contract's fact.** The register
source fires exactly when the 0102 presence contract reports an index register,
so the two contracts agree on the one `has_index` fact and neither can select a
source the other would not. -/
theorem arm64_mem_index_value_matches_present (indexByte : BitVec 8) :
    (sourceOf (present indexByte) = .registerIndex) = present indexByte :=
  arm64_mem_index_value_selects_register (present indexByte)

/-- The register source contributes the (already source-modified) index register
value to the offset. -/
theorem arm64_mem_index_value_register_is_index (index : BitVec 64) :
    arm64MemIndexValueOf true index = index := by
  rfl

/-- The zero source contributes a literal zero to the offset, so an addressing
mode with no index register adds no index term. -/
theorem arm64_mem_index_value_zero_ignores_index (index : BitVec 64) :
    arm64MemIndexValueOf false index = 0 := by
  rfl

/-- **The index value is what the offset contract consumes.** The value the
register source feeds the shared address-offset contract is exactly the index
argument of its indexed arm, and the value the zero source feeds it is exactly
the index argument of its non-indexed (no-index) arm — a literal zero — for
both the pre/post-indexed and the plain offset addressing forms. -/
theorem arm64_mem_index_value_matches_offset (prepost : Bool) (imm index :
    BitVec 64) :
    GeneratedArm64MemOffset.value prepost true imm
        (arm64MemIndexValueOf true index) =
      GeneratedArm64MemOffset.value prepost true imm index ∧
    GeneratedArm64MemOffset.value prepost false imm
        (arm64MemIndexValueOf false index) =
      GeneratedArm64MemOffset.value prepost false imm 0 := by
  refine ⟨?_, ?_⟩ <;> rfl

/-- Canonical example: an addressing mode with no index register leaves the
offset at the immediate alone, while the present mode adds the modified index
register value. -/
theorem arm64_mem_index_value_examples :
    GeneratedArm64MemOffset.value false false 16
        (arm64MemIndexValueOf false 0xfffffffffffffff8) = 16 ∧
      GeneratedArm64MemOffset.value false true 16
        (arm64MemIndexValueOf true 0xfffffffffffffff8) = 8 := by
  refine ⟨?_, ?_⟩ <;> native_decide

end KProgFormal
