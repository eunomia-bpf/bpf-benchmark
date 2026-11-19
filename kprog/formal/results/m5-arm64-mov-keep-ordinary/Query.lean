import KProgFormal.ClightRefinement.Arm64MovKeepNative
open KProgFormal.ClightRefinement
#check Arm64MovKeep.call_scalar_returns
#print axioms Arm64MovKeep.call_scalar_returns
#check Arm64MovKeep.call_scalar_represents
#print axioms Arm64MovKeep.call_scalar_represents
#check Arm64MovKeep.call_scalar_all_behaviors
#print axioms Arm64MovKeep.call_scalar_all_behaviors
#check Arm64MovKeep.Native.merge_low_word
#print axioms Arm64MovKeep.Native.merge_low_word
#check Arm64MovKeep.Native.native_step
#print axioms Arm64MovKeep.Native.native_step
#check Arm64MovKeep.Native.reference_step
#print axioms Arm64MovKeep.Native.reference_step
#check Arm64MovKeep.Native.call_corresponds
#print axioms Arm64MovKeep.Native.call_corresponds
