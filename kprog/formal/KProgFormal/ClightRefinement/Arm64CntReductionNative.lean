import KProgFormal.ClightRefinement.Arm64CntReduction
import KProgFormal.ClightRefinement.Arm64CntLanes
import KProgFormal.ClightRefinement.Arm64CntPacking

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Reduction

/-- The actual C accumulator has the imported complete word result. -/
theorem packed_native (value : BitVec 64) :
    packed value = DPSFP.simd_count_bytes value := by
  simpa only [packed,lane,Lanes.byte] using Packing.word value

/-- The complete original C reduction call refines the mature full-word
count, retaining the original heap and actual return continuation. -/
theorem corresponds (value : BitVec 64) (k : CC.Cont) (m : CC.Mem) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.Callstate (.Internal handler) [.Vlong (36#64),.Vlong value] k m)
      (.Returnstate (.Vlong (DPSFP.simd_count_bytes value)) (CC.callCont k) m) := by
  simpa only [packed_native] using execute value k m

end KProgFormal.ClightRefinement.Arm64Cnt.Reduction
