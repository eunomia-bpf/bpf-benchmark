import KProgFormal.Reference.AArch64
import KProgFormal.Generated.GeneratedArm64Reduction
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.Arm64Reduction

open Reference
open Reference.AArch64 (ReductionOp)

def operation : ReductionOp → GeneratedArm64Reduction.Reduction
  | .count => .cnt | .unsignedSum => .uaddlv

/-- The handler invokes its generated 64-bit primitive on the active low/high
halves, then either concatenates byte counts or adds the two widened sums. -/
def handlerValue (op : ReductionOp) (wide : Bool) (value : BitVec 128) : BitVec 128 :=
  let low := GeneratedArm64Reduction.value (operation op) (value.setWidth 64)
  let high := if wide then GeneratedArm64Reduction.value (operation op) ((value >>> 64).setWidth 64) else 0
  match op with
  | .count => low.setWidth 128 ||| (high.setWidth 128 <<< 64)
  | .unsignedSum => (low + high).setWidth 128

set_option maxRecDepth 4096 in
set_option maxHeartbeats 4000000 in
theorem value_refines (op : ReductionOp) (wide : Bool) (value : BitVec 128) :
    handlerValue op wide value = Reference.AArch64.reductionValue op wide value := by
  cases op <;> cases wide <;>
    simp only [handlerValue, operation, Reference.AArch64.reductionValue,
      Reference.AArch64.vectorBytes, Reference.AArch64.byteCount, littleEndian,
      GeneratedArm64Reduction.value, GeneratedArm64Reduction.popCountBits,
      Bool.false_eq_true, if_false, if_true, List.range_succ, List.range_zero,
      List.map_append, List.map_cons, List.map_nil, List.foldl_append, List.foldl_cons,
      List.foldl_nil, List.nil_append, List.cons_append, List.append_nil, littleEndian] <;>
    bv_decide (config := { timeout := 60 })

def handlerStep (op : ReductionOp) (wide : Bool) (s : Reference.AArch64.State) : Transition Reference.AArch64.State :=
  ⟨{ s with vector0 := handlerValue op wide s.vector0, pc := s.pc + 4 }, [], none⟩

theorem step_refines (op : ReductionOp) (wide : Bool) (s : Reference.AArch64.State) :
    handlerStep op wide s = Reference.AArch64.step (.reduction op wide) s := by
  simp only [handlerStep, Reference.AArch64.step, Reference.AArch64.reductionStep, value_refines]

theorem handler_refines (op : ReductionOp) (wide : Bool) (s : Reference.AArch64.State) :
    Reference.AArch64.Step (.reduction op wide) s (handlerStep op wide s) := (step_refines op wide s).symm

end KProgFormal.Refinement.Arm64Reduction
