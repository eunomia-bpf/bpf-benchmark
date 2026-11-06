import KProgFormal.Reference.AArch64
import KProgFormal.Generated.GeneratedArm64DqMem
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.Arm64VectorMemory
open Reference

/-- The actual D-load lane transfer plus the generated upper-half action. -/
def dLoad (old : BitVec 128) (low : Word) : BitVec 128 :=
  let high : Word := if GeneratedArm64DqMem.clearHigh .loadD0 then 0 else (old >>> 64).setWidth 64
  low.setWidth 128 ||| (high.setWidth 128 <<< 64)

theorem d_load_refines (old : BitVec 128) (m : Memory) (address : Word) :
    dLoad old (wordAt m address 8) = littleEndian 128 (bytesAt m address 8) := by
  simp [dLoad, GeneratedArm64DqMem.clearHigh, if_true, wordAt,
    bytesAt, littleEndian, List.range_succ, Reference.Word, BitVec.add_assoc]
  bv_decide

/-- Both transferred Q lanes form the one 128-bit architectural value. -/
def qLoad (low high : Word) : BitVec 128 :=
  low.setWidth 128 ||| (high.setWidth 128 <<< 64)

theorem q_load_refines (m : Memory) (address : Word) :
    qLoad (wordAt m address 8) (wordAt m (address + 8) 8) =
      littleEndian 128 (bytesAt m address 16) := by
  simp [qLoad, wordAt, bytesAt, littleEndian, List.range_succ, Reference.Word, BitVec.add_assoc]
  bv_decide

end KProgFormal.Refinement.Arm64VectorMemory
