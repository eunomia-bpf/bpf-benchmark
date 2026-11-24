import KProgFormal.ClightRefinement.Arm64UaddlvLanes

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Uaddlv.Reduction

/-- The complete original op37 C call returns the zero-extended imported
word sum, retaining arbitrary memory and its actual return continuation. -/
theorem corresponds (world : CC.CGenv) (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    ∃ count, InternalRun world count
      (.Callstate (.Internal handler) [.Vlong (37#64),.Vlong value] k m)
      (.Returnstate (.Vlong ((DPSFP.simd_unsigned_sum_long 8 value).setWidth 64)) (CC.callCont k) m) := by
  simpa only [Lanes.word] using execute world value k m

end KProgFormal.ClightRefinement.Arm64Uaddlv.Reduction
