import KProgFormal.ClightRefinement.Arm64MovImmediateZr
open KProgFormal.ClightRefinement
#check Arm64RegisterWrite.execute_zr_bound
#print axioms Arm64RegisterWrite.execute_zr_bound
#check Arm64MovImmediate.Suffix.writer_call_register
#print axioms Arm64MovImmediate.Suffix.writer_call_register
#check Arm64MovImmediate.call_zr_returns
#print axioms Arm64MovImmediate.call_zr_returns
#check Arm64MovImmediate.call_zr_represents
#print axioms Arm64MovImmediate.call_zr_represents
#check Arm64MovImmediate.Zr.native_step
#print axioms Arm64MovImmediate.Zr.native_step
#check Arm64MovImmediate.Zr.reference_step
#print axioms Arm64MovImmediate.Zr.reference_step
#check Arm64MovImmediate.Zr.call_corresponds
#print axioms Arm64MovImmediate.Zr.call_corresponds
