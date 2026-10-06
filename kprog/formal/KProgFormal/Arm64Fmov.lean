import KProgFormal.GeneratedArm64Fmov
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal

open GeneratedArm64Fmov (Fmov)
open GeneratedArm64Width (Width narrow)

/-- Independent statement of the four AArch64 FMOV directions. It separates the
two questions the generated contract answers from one arm: whether the direction
writes the register, and which width the moved value carries. The register-writing
arms narrow `v0` to the destination width with an explicit `narrow`, whereas the
generated contract returns the raw `v0` and leaves the width to the caller. -/
def arm64FmovSpec (dir : Fmov) (v0 src : BitVec 64) (width : Width) :
    BitVec 64 :=
  if dir = .x_from_d ∨ dir = .w_from_s then
    -- register destination: supply the value; the caller narrows on write.
    narrow v0 width
  else
    -- vector destination: the value is the source register, already narrowed by
    -- the caller's register read.
    narrow src width

/-- The generated FMOV selection, after the caller's width write, agrees with the
independent statement for all four directions and all widths the handler emits. -/
theorem arm64_fmov_refines (dir : Fmov) (v0 src : BitVec 64) (width : Width) :
    narrow (GeneratedArm64Fmov.value dir v0 src) width =
      arm64FmovSpec dir v0 src width := by
  cases dir <;> cases width <;>
    simp only [GeneratedArm64Fmov.value, arm64FmovSpec, narrow,
      GeneratedArm64Width.mask, reduceCtorEq, reduceIte,
      GeneratedArm64Fmov.writesReg] <;>
    bv_decide

/-- The generated direction code range `0..3` covers the complete `Fmov`. -/
theorem arm64_fmov_code_in_range (dir : Fmov) :
    GeneratedArm64Fmov.code dir < 4 := by
  cases dir <;> decide

/-- The direction table splits into the two vector-destination directions and the
two register-destination directions, and only the register-destination directions
have `writesReg` true. -/
theorem arm64_fmov_direction_dispatch :
    GeneratedArm64Fmov.code .d_from_x = 0 ∧
    GeneratedArm64Fmov.code .x_from_d = 1 ∧
    GeneratedArm64Fmov.code .s_from_w = 2 ∧
    GeneratedArm64Fmov.code .w_from_s = 3 ∧
    GeneratedArm64Fmov.writesReg .d_from_x = false ∧
    GeneratedArm64Fmov.writesReg .x_from_d = true ∧
    GeneratedArm64Fmov.writesReg .s_from_w = false ∧
    GeneratedArm64Fmov.writesReg .w_from_s = true := by
  refine ⟨rfl, rfl, rfl, rfl, rfl, rfl, rfl, rfl⟩

/-- The vector-destination directions move the source through unchanged (before
the caller's width write). -/
theorem arm64_fmov_vector_destination (v0 src : BitVec 64) :
    GeneratedArm64Fmov.value .d_from_x v0 src = src ∧
    GeneratedArm64Fmov.value .s_from_w v0 src = src := by
  refine ⟨rfl, rfl⟩

/-- The register-destination directions supply the current `v0` (before the
caller's width write). -/
theorem arm64_fmov_register_destination (v0 src : BitVec 64) :
    GeneratedArm64Fmov.value .x_from_d v0 src = v0 ∧
    GeneratedArm64Fmov.value .w_from_s v0 src = v0 := by
  refine ⟨rfl, rfl⟩

/-- Canonical example: a 64-bit D_FROM_X write of v0 followed by a 64-bit
X_FROM_D read round-trips the register value. -/
theorem arm64_fmov_roundtrip_example :
    narrow (GeneratedArm64Fmov.value .x_from_d
      (GeneratedArm64Fmov.value .d_from_x 0 0xdeadbeefcafef00d) 0) .w64 =
      0xdeadbeefcafef00d := by
  native_decide

/-- Canonical example: a 32-bit W_FROM_S write narrows v0 to the low word. -/
theorem arm64_fmov_w_from_s_example :
    narrow (GeneratedArm64Fmov.value .w_from_s 0x123456789abcdef0 0) .w32 =
      0x9abcdef0 := by
  native_decide

end KProgFormal
