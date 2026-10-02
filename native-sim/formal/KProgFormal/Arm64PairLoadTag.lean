import KProgFormal.GeneratedArm64PairLoadTag
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64PairLoadTag (pairGate routeMask slotPreserve slotCount code)
open GeneratedArm64Width (Width bits)

/-- Independent statement of the pair-load routing: the two-bit mask has bit 0
set exactly when the low slot preserves its tag and bit 1 exactly when the high
slot does. Keyed on the width's bit count and each tag's scalar class, and
deliberately not phrased through the generated outer gate, so the theorem shows
the gate is redundant with the per-slot rule rather than restating it. -/
def arm64PairLoadTagRouteSpec (width : Width) (loScalar hiScalar : Bool) : Nat :=
  (if bits width == 64 && loScalar = false then 1 else 0) +
    (if bits width == 64 && hiScalar = false then 2 else 0)

/-- The generated pair-load routing mask equals the independent per-slot
statement at every width and every pair of tag classes. -/
theorem arm64_pair_load_tag_refines (width : Width) (loScalar hiScalar : Bool) :
    routeMask width loScalar hiScalar =
      arm64PairLoadTagRouteSpec width loScalar hiScalar := by
  cases width <;> cases loScalar <;> cases hiScalar <;> decide

/-- A pair load of two scalar slots routes neither slot to the tag-copy write,
whatever the width. -/
theorem arm64_pair_load_tag_both_scalar (width : Width) :
    routeMask width true true = 0 := by
  cases width <;> decide

/-- The outer pair gate clears both slot bits together: it is false exactly when
no slot preserves a tag. -/
theorem arm64_pair_load_tag_gate_iff (width : Width) (loScalar hiScalar : Bool) :
    pairGate width loScalar hiScalar = true ↔
      bits width == 64 ∧ (loScalar = false ∨ hiScalar = false) := by
  cases width <;> cases loScalar <;> cases hiScalar <;> decide

/-- At a sub-word width the pair gate is false, so neither slot's tag survives. -/
theorem arm64_pair_load_tag_sub_word_drops (width : Width) (loScalar hiScalar : Bool)
    (h : bits width < 64) :
    routeMask width loScalar hiScalar = 0 := by
  cases width <;> simp_all [routeMask, pairGate, slotPreserve, bits]

/-- A doubleword pair whose low slot is a scalar and whose high slot is not routes
only the high slot to the tag-copy write. -/
theorem arm64_pair_load_tag_only_high_preserves :
    routeMask .w64 true false = 2 := by
  decide

/-- A doubleword pair whose high slot is a scalar and whose low slot is not routes
only the low slot to the tag-copy write. -/
theorem arm64_pair_load_tag_only_low_preserves :
    routeMask .w64 false true = 1 := by
  decide

/-- A doubleword pair of two non-scalar slots routes both slots to the tag-copy
write. -/
theorem arm64_pair_load_tag_both_preserve :
    routeMask .w64 false false = 3 := by
  decide

/-- The only width that can route any slot to the tag-copy write is the doubleword
width. -/
theorem arm64_pair_load_tag_routing_width_is_w64 (width : Width)
    (loScalar hiScalar : Bool)
    (h : routeMask width loScalar hiScalar ≠ 0) :
    width = .w64 := by
  cases width <;> simp_all [routeMask, pairGate, slotPreserve]

/-- A pair load transfers exactly two slots. -/
theorem arm64_pair_load_tag_slot_count : slotCount = 2 := by
  decide

/-- The pair-load opcode is pinned to its numeric case-label code. -/
theorem arm64_pair_load_tag_code_dispatch : code = 33 := by
  decide

/-- The pair-load opcode lies inside the byte range the shared C macro's numeric
case label addresses. -/
theorem arm64_pair_load_tag_code_in_range : 33 ≤ code ∧ code ≤ 33 := by
  decide

/-- Canonical example: a doubleword pair with a non-scalar low slot and scalar
high slot routes only the low slot. -/
theorem arm64_pair_load_tag_example_low :
    arm64PairLoadTagRouteSpec .w64 false true = 1 := by
  decide

/-- Canonical example: a sub-word pair routes neither slot. -/
theorem arm64_pair_load_tag_example_subword :
    arm64PairLoadTagRouteSpec .w32 false false = 0 := by
  decide

end KProgFormal
