import KProgFormal.Reference.X86
import KProgFormal.Generated.GeneratedX86AuxFlags
import Std.Tactic.BVDecide

namespace KProgFormal.Refinement.X86AuxFlags
open Reference
open Reference.X86 (ScalarWidth)

theorem parity_refines (value : Reference.Word) :
    GeneratedX86AuxFlags.parity value = Reference.X86.evenParity value := by
  simp only [GeneratedX86AuxFlags.parity, Reference.X86.evenParity,
    List.range_succ, List.range_zero, List.foldl_append, List.foldl_cons, List.foldl_nil]
  bv_decide

set_option maxRecDepth 4096 in
set_option maxHeartbeats 4000000 in
theorem auxiliary_refines (width : ScalarWidth) (subtract carry : Bool) (left right : Reference.Word) :
    GeneratedX86AuxFlags.auxiliary left right (Reference.X86.arithmeticValue width subtract carry left right) =
      Reference.X86.auxiliaryCarry subtract carry left right := by
  cases width <;> cases subtract <;> cases carry <;>
    simp only [GeneratedX86AuxFlags.auxiliary, Reference.X86.arithmeticValue, Reference.X86.auxiliaryCarry,
      Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, Reference.Word,
      Nat.reduceMul, Bool.false_eq_true, if_false, if_true] <;>
    bv_decide (config := { timeout := 60 })

end KProgFormal.Refinement.X86AuxFlags
