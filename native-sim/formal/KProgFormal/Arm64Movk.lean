import KProgFormal.GeneratedArm64Movk
import KProgFormal.GeneratedArm64Width
import Std.Tactic.BVDecide

namespace KProgFormal
open KProgFormal.GeneratedArm64Movk (MovkShift value column)
open KProgFormal.GeneratedArm64Width (Width narrow)

/-- Independent statement of the AArch64 MOVK insertion: the destination keeps
every bit outside the 16-bit column and takes the low 16 bits of the immediate
at that column. The inserted term is stated as the narrowed immediate shifted
into place, structurally separate from the generated masked-shift term. -/
def arm64MovkValueSpec (shift : MovkShift) (dst imm : BitVec 64) : BitVec 64 :=
  let s := column shift
  (dst &&& ~~~((0xffff : BitVec 64) <<< s)) |||
    (((imm &&& 0xffff) : BitVec 64) <<< s)

/-- The generated MOVK contract agrees with the independent insertion statement
for all four architectural columns. -/
theorem arm64_movk_refines (shift : MovkShift) (dst imm : BitVec 64) :
    value shift dst imm = arm64MovkValueSpec shift dst imm := by
  cases shift <;>
    simp only [value, arm64MovkValueSpec, column] <;>
    bv_decide

/-- C hands the MOVK result to the width-narrowing register write; narrowing
commutes with the refinement. -/
theorem arm64_movk_width_refines (shift : MovkShift) (dst imm : BitVec 64)
    (width : Width) :
    narrow (value shift dst imm) width =
      narrow (arm64MovkValueSpec shift dst imm) width := by
  rw [arm64_movk_refines]

/-- Every MOVK column is one of the four architectural columns, so the AUX shift
field always lands in the closed column set. -/
theorem arm64_movk_column_is_architectural (shift : MovkShift) :
    column shift = 0 ∨ column shift = 16 ∨ column shift = 32 ∨
      column shift = 48 := by
  cases shift <;> decide

/-- The column dispatch: the four constructors map onto the four architectural
columns the C macro switches on. -/
theorem arm64_movk_column_dispatch :
    column .col0 = 0 ∧ column .col16 = 16 ∧
    column .col32 = 32 ∧ column .col48 = 48 := by
  decide

/-- Canonical example: inserting at column 0 sets the low halfword and clears
nothing else above it in an otherwise-empty destination. -/
theorem arm64_movk_col0_example :
    arm64MovkValueSpec .col0 0 0x1234 = 0x1234 := by
  native_decide

/-- Canonical example: inserting at column 16 places the immediate in the second
halfword. -/
theorem arm64_movk_col16_example :
    arm64MovkValueSpec .col16 0 0x1234 = 0x12340000 := by
  native_decide

/-- Canonical example: inserting at column 32 places the immediate in the third
halfword. -/
theorem arm64_movk_col32_example :
    arm64MovkValueSpec .col32 0 0x1234 = 0x123400000000 := by
  native_decide

/-- Canonical example: inserting at column 48 places the immediate in the top
halfword. -/
theorem arm64_movk_col48_example :
    arm64MovkValueSpec .col48 0 0x1234 = 0x1234000000000000 := by
  native_decide

/-- Canonical example: MOVK keeps the destination bits outside the column. -/
theorem arm64_movk_preserves_other_bits_example :
    arm64MovkValueSpec .col16 0xffffffffffffffff 0x0 = 0xffffffff0000ffff := by
  native_decide

/-- Canonical example: only the low 16 bits of a wider immediate are inserted. -/
theorem arm64_movk_narrows_immediate_example :
    arm64MovkValueSpec .col0 0 0xffffffffffffabcd = 0xabcd := by
  native_decide

end KProgFormal
