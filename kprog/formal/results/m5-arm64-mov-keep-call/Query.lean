import KProgFormal.ClightRefinement.Arm64MovKeepZr
open KProgFormal.ClightRefinement
#check Arm64MovKeep.call_zr_returns
#print axioms Arm64MovKeep.call_zr_returns
#check Arm64MovKeep.call_zr_represents
#print axioms Arm64MovKeep.call_zr_represents
#check Arm64MovKeep.call_zr_all_behaviors
#print axioms Arm64MovKeep.call_zr_all_behaviors
#check Arm64MovKeep.Zr.native_step
#print axioms Arm64MovKeep.Zr.native_step
#check Arm64MovKeep.Zr.reference_step
#print axioms Arm64MovKeep.Zr.reference_step
#check Arm64MovKeep.Zr.call_corresponds
#print axioms Arm64MovKeep.Zr.call_corresponds
