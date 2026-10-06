import KProgFormal.GeneratedArm64LoadTag
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64LoadTag (preserve code)
open GeneratedArm64Width (Width bits)

/-- Independent statement of the plain-load tag-preservation rule: the memory-read
provenance tag survives a load exactly when the access width is the full 64 bits
and the tag is not the bare scalar tag. Phrased on the bit count rather than the
width constructor, deliberately not a restatement of the generated equation. -/
def arm64LoadTagPreserveSpec (width : Width) (tagIsScalar : Bool) : Bool :=
  bits width == 64 && tagIsScalar = false

/-- The generated plain-load preservation rule agrees with the independent
bit-count-keyed statement at every width and every tag class. -/
theorem arm64_load_tag_refines (width : Width) (tagIsScalar : Bool) :
    preserve width tagIsScalar =
      arm64LoadTagPreserveSpec width tagIsScalar := by
  cases width <;> cases tagIsScalar <;> decide

/-- A sub-word load never preserves the tag, whatever the tag is. -/
theorem arm64_load_tag_sub_word_drops (width : Width) (tagIsScalar : Bool)
    (h : bits width < 64) :
    preserve width tagIsScalar = false := by
  cases width <;> simp_all [preserve, bits]

/-- A doubleword load of a scalar value preserves nothing. -/
theorem arm64_load_tag_scalar_drops :
    preserve .w64 true = false := by
  decide

/-- A doubleword load of a non-scalar value takes the tag-copy path: this is the
only case that carries provenance. -/
theorem arm64_load_tag_w64_non_scalar_preserves :
    preserve .w64 false = true := by
  decide

/-- The preservation decision is trichotomous in the width and the tag class:
either the width is sub-word, or it is doubleword and the tag is scalar, or it is
doubleword and the tag is non-scalar. -/
theorem arm64_load_tag_preserve_iff :
    ∀ width tagIsScalar,
      preserve width tagIsScalar = true ↔
        width = .w64 ∧ tagIsScalar = false := by
  intro width tagIsScalar
  cases width <;> cases tagIsScalar <;> decide

/-- The only width that can preserve a tag is the doubleword width. -/
theorem arm64_load_tag_preserving_width_is_w64 (width : Width)
    (tagIsScalar : Bool) (h : preserve width tagIsScalar = true) :
    width = .w64 := by
  cases width <;> simp_all [preserve]

/-- The opcode is pinned to its numeric case-label code. -/
theorem arm64_load_tag_code_dispatch : code = 31 := by
  decide

/-- The plain-load opcode lies inside the byte range the shared C macro's
numeric case label addresses. -/
theorem arm64_load_tag_code_in_range : 31 ≤ code ∧ code ≤ 31 := by
  decide

/-- Canonical example: a doubleword non-scalar load preserves provenance. -/
theorem arm64_load_tag_example_preserve :
    arm64LoadTagPreserveSpec .w64 false = true := by
  decide

/-- Canonical example: a sub-word load drops provenance. -/
theorem arm64_load_tag_example_drop :
    arm64LoadTagPreserveSpec .w32 false = false := by
  decide

end KProgFormal
