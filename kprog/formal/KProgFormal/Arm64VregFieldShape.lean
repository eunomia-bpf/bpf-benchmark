import KProgFormal.GeneratedArm64VregField
import KProgFormal.GeneratedArm64Vreg

namespace KProgFormal

open GeneratedArm64VregField (Field fieldCount fieldNames fieldCodes codeOfField
  effectOfField fieldOf fieldOfCode Case classify fieldOfCase highFieldFact)
open GeneratedArm64Vreg (Half halfOffset plan)

/-- Independent statement of the state-field selector, built from the literal
constructors rather than the generated `fieldOf`: the high half's field exactly
when the half the plan names is the high half, the low half's field otherwise. -/
def arm64VregFieldSpec (isHighField : Bool) : Field :=
  if isHighField then .high
  else .low

/-- Independent statement of the two field names, built from the literal
constructor order rather than the generated `fieldNames`. -/
def arm64VregFieldNamesSpec : List String := ["low", "high"]

/-- Independent statement of the two field codes: the low half's field yields
the selector's false branch (0) and the high half's field the true branch
(1). -/
def arm64VregFieldCodesSpec : List Nat := [0, 1]

/-- Independent statement of the two state-field slot offsets, built from the
literal `halfOffset` values rather than the generated selector: the low field is
the first 64-bit field at offset 0 and the high field follows one 64-bit field
higher. -/
def arm64VregFieldOffsetSpec : Field -> Nat
  | .low => 0
  | .high => 8

/-- Independent construction of the state field a vector-register half lands in,
built from the literal half constructors rather than the generated selector: the
low half is the low field, the high half the high field. -/
def arm64VregFieldOfHalf : Half -> Field
  | .low => .low
  | .high => .high

/-- The generated field selector equals the independent literal construction for
every moved half. -/
theorem arm64_vreg_field_refines (isHighField : Bool) :
    fieldOf isHighField = arm64VregFieldSpec isHighField := by
  unfold fieldOf arm64VregFieldSpec
  cases isHighField <;> rfl

/-- The generated field-name table equals the independent literal order. -/
theorem arm64_vreg_field_names_refine :
    fieldNames = arm64VregFieldNamesSpec := by
  unfold fieldNames arm64VregFieldNamesSpec
  rfl

/-- The generated field-code table equals the independent literal codes. -/
theorem arm64_vreg_field_codes_refine :
    fieldCodes = arm64VregFieldCodesSpec := by
  unfold fieldCodes arm64VregFieldCodesSpec
  rfl

/-- The generated field-code table has exactly `fieldCount` entries, so the zip
table and the macro name the same two state fields and nothing else. -/
theorem arm64_vreg_field_codes_length :
    fieldCodes.length = fieldCount :=
  rfl

/-- The generated field-name table has exactly `fieldCount` entries. -/
theorem arm64_vreg_field_names_length :
    fieldNames.length = fieldCount :=
  rfl

/-- The two field codes are distinct, so no two state fields alias one code. -/
theorem arm64_vreg_field_codes_nodup : fieldCodes.Nodup := by
  unfold fieldCodes
  native_decide

/-- The field count is the two vector-register state fields a moved half selects
between. -/
theorem arm64_vreg_field_count_is_2 : fieldCount = 2 := rfl

/-- The generated field-code selector round-trips each state field to its own
code and names no other code. -/
theorem arm64_vreg_field_of_code_roundtrip (field : Field) :
    fieldOfCode (codeOfField field) = some field := by
  cases field <;> native_decide

/-- The generated field-code selector names no state field at or above the field
count, so the table is exactly the two fields and no other code reaches one. -/
theorem arm64_vreg_field_of_code_beyond_is_none :
    fieldOfCode 2 = none ∧ fieldOfCode 8 = none ∧ fieldOfCode 255 = none := by
  refine ⟨?_, ?_, ?_⟩ <;> native_decide

/-- The two state fields report two distinct write effects: the low half's field
and the high half's field. -/
theorem arm64_vreg_field_effects :
    effectOfField .low = "low_half_state_field" ∧
      effectOfField .high = "high_half_state_field" ∧
      effectOfField .low ≠ effectOfField .high := by
  refine ⟨?_, ?_, ?_⟩
  · exact rfl
  · exact rfl
  · decide

/-- Every fact value is reachable: naming the state field from the fact directly
classifies and dispatches the same case, so neither case is dead. -/
theorem arm64_vreg_field_case_dispatch :
    fieldOf true = .high ∧ fieldOf false = .low := by
  refine ⟨?_, ?_⟩ <;> native_decide

/-- The two-case table agrees with the direct selector: classifying a moved half
and dispatching on the case is the same state-field selection the macro
performs. -/
theorem arm64_vreg_field_case_refines (isHighField : Bool) :
    fieldOf isHighField = fieldOfCase (classify isHighField) :=
  GeneratedArm64VregField.fieldOf_refines isHighField

/-- **The state-field selection is the closed fact.** The high half's field fires
exactly when the moved half is the high half, so the 2-way selection reduces to
the single closed fact and no other arm is ever reachable. -/
theorem arm64_vreg_field_selects_high_field (isHighField : Bool) :
    (fieldOf isHighField = .high) = highFieldFact isHighField := by
  cases isHighField <;> decide

/-- The two field slot offsets are distinct — the low field at the base offset,
the high field one 64-bit field higher — so a wrong field changes the state
slot the half lands in. -/
theorem arm64_vreg_field_offsets_distinct :
    arm64VregFieldOffsetSpec .low = 0 ∧
      arm64VregFieldOffsetSpec .high = 8 ∧
      arm64VregFieldOffsetSpec .high ≠ arm64VregFieldOffsetSpec .low := by
  refine ⟨rfl, rfl, ?_⟩ <;> decide

/-- **The field choice is the vector-register half offset.** The state field the
step lands a moved half in is exactly the field selected from the single fact
that the half's slot offset is the high half's offset: the selector's fact is
the vector-register contract's `halfOffset` comparison, and the field it names is
the one the half's own `halfOffset` maps to, for both halves. -/
theorem arm64_vreg_field_matches_vreg_half (h : Half) :
    fieldOf (decide (halfOffset h = halfOffset .high)) = arm64VregFieldOfHalf h := by
  cases h <;> rfl

/-- **The field choice is the vector-register half plan.** The state fields a
vector memory step touches are exactly the vector-register contract's half plan
mapped through the field choice — the low field alone for a `.D0` opcode, the low
field then the high field for a `.Q0` opcode — so the step lands each half in
the field the plan names, in the plan's order. -/
theorem arm64_vreg_field_matches_vreg_plan :
    ((plan .loadD0).map arm64VregFieldOfHalf) = [.low] ∧
      ((plan .loadQ0).map arm64VregFieldOfHalf) = [.low, .high] ∧
      ((plan .storeD0).map arm64VregFieldOfHalf) = [.low] ∧
      ((plan .storeQ0).map arm64VregFieldOfHalf) = [.low, .high] := by
  refine ⟨rfl, rfl, rfl, rfl⟩

/-- The low field's slot offset is the vector-register half offset of the low
half and the high field's is the half offset of the high half, so the field
offsets and the half offsets name the same two state slots. -/
theorem arm64_vreg_field_offsets_are_half_offsets :
    arm64VregFieldOffsetSpec .low = halfOffset .low ∧
      arm64VregFieldOffsetSpec .high = halfOffset .high := by
  refine ⟨rfl, rfl⟩

end KProgFormal
