import KProgFormal.GeneratedArm64CselPtr
import KProgFormal.GeneratedArm64Csel
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64CselPtr (ptrTagPath)
open GeneratedArm64Csel (Csel)
open GeneratedArm64Width (Width)

/-- Independent statement of the AArch64 conditional-select pointer path: the
destination carries the source provenance tag exactly when the operation is the
plain `CSEL` and the access is doubleword width, so the tag-copy register write
runs. Structurally separate from the generated table: it names the single
pointer-preserving operation and conjoins the width condition. -/
def arm64CselPtrSpec (op : Csel) (width : Width) : Bool :=
  op = .csel && width = .w64

/-- The generated conditional-select pointer-path table agrees with the
independent statement on every (operation, width) pair. -/
theorem arm64_csel_ptr_refines (op : Csel) (width : Width) :
    ptrTagPath op width = arm64CselPtrSpec op width := by
  cases op <;> cases width <;> decide

/-- Only the plain `CSEL` can ever take the pointer path, at any width. -/
theorem arm64_csel_ptr_only_csel (op : Csel) (h : op ≠ .csel) (width : Width) :
    ptrTagPath op width = false := by
  cases op <;> (cases width <;> simp_all [ptrTagPath])

/-- The plain `CSEL` preserves provenance exactly at doubleword width. -/
theorem arm64_csel_ptr_csel_iff_w64 (width : Width) :
    ptrTagPath .csel width = true ↔ width = .w64 := by
  cases width <;> simp [ptrTagPath]

/-- The plain `CSEL` drops provenance at every sub-word width. -/
theorem arm64_csel_ptr_csel_sub_word_drops (width : Width) (h : width ≠ .w64) :
    ptrTagPath .csel width = false := by
  cases width <;> simp_all [ptrTagPath]

/-- Every conditional-select family member other than the plain `CSEL` drops
provenance at every width. -/
theorem arm64_csel_ptr_family_drops (op : Csel) (h : op ≠ .csel) :
    ∀ width, ptrTagPath op width = false := by
  intro width
  exact arm64_csel_ptr_only_csel op h width

/-- The conditional-select family is pinned to its opcode numbers: the eight
opcodes are all reached by a numeric case label in the shared C macro. -/
theorem arm64_csel_ptr_code_dispatch :
    GeneratedArm64Csel.code .csel = 28 ∧
    GeneratedArm64Csel.code .cinc = 29 ∧
    GeneratedArm64Csel.code .cset = 30 ∧
    GeneratedArm64Csel.code .cinv = 52 ∧
    GeneratedArm64Csel.code .csinv = 61 ∧
    GeneratedArm64Csel.code .csinc = 62 ∧
    GeneratedArm64Csel.code .csetm = 68 ∧
    GeneratedArm64Csel.code .csneg = 69 := by
  decide

/-- The plain `CSEL` opcode lies inside the numeric case-label range the shared C
macro addresses. -/
theorem arm64_csel_ptr_code_in_range :
    28 ≤ GeneratedArm64Csel.code .csel ∧
    GeneratedArm64Csel.code .csel ≤ 69 := by
  decide

/-- Canonical example: the doubleword plain `CSEL` takes the pointer path. -/
theorem arm64_csel_ptr_example_ptr :
    arm64CselPtrSpec .csel .w64 = true := by
  decide

/-- Canonical example: a doubleword `CSINC` still drops provenance. -/
theorem arm64_csel_ptr_example_family :
    arm64CselPtrSpec .csinc .w64 = false := by
  decide

/-- Canonical example: a sub-word plain `CSEL` drops provenance. -/
theorem arm64_csel_ptr_example_sub_word :
    arm64CselPtrSpec .csel .w32 = false := by
  decide

end KProgFormal
