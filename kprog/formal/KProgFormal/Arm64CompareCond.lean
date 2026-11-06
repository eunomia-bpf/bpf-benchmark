import KProgFormal.Generated.GeneratedArm64Flags
import KProgFormal.Generated.GeneratedArm64Cond
import Std.Tactic.BVDecide

namespace KProgFormal

private def compareCond (lhs rhs : BitVec 64)
    (width : GeneratedArm64Width.Width) (cond : GeneratedArm64Cond.Cond) : Bool :=
  let flags := GeneratedArm64Flags.applySub lhs rhs width
  GeneratedArm64Cond.eval flags.n flags.z flags.c flags.v cond

theorem arm64_compare_gt_w32 (lhs rhs : BitVec 64) :
    compareCond lhs rhs .w32 .gt = (rhs.setWidth 32).slt (lhs.setWidth 32) := by
  simp only [compareCond, GeneratedArm64Flags.applySub, GeneratedArm64Flags.subCarry,
    GeneratedArm64Flags.subOverflow, GeneratedArm64Width.narrow,
    GeneratedArm64Width.sign, GeneratedArm64Width.mask, GeneratedArm64Width.signMask,
    GeneratedArm64Width.bits, GeneratedArm64Cond.eval]
  bv_decide

theorem arm64_compare_gt_w64 (lhs rhs : BitVec 64) :
    compareCond lhs rhs .w64 .gt = rhs.slt lhs := by
  simp only [compareCond, GeneratedArm64Flags.applySub, GeneratedArm64Flags.subCarry,
    GeneratedArm64Flags.subOverflow, GeneratedArm64Width.narrow,
    GeneratedArm64Width.sign, GeneratedArm64Width.mask, GeneratedArm64Width.signMask,
    GeneratedArm64Width.bits, GeneratedArm64Cond.eval]
  bv_decide

end KProgFormal
