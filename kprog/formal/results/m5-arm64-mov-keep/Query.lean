import KProgFormal.ClightRefinement.Arm64MovKeepSuffix
open KProgFormal.ClightRefinement
#check Arm64MovImmediate.Dispatch.Keep.call_dispatch
#print axioms Arm64MovImmediate.Dispatch.Keep.call_dispatch
#check Arm64MovKeep.read_call
#print axioms Arm64MovKeep.read_call
#check Arm64MovKeep.call_read
#print axioms Arm64MovKeep.call_read
#check Arm64MovKeep.read_zr
#print axioms Arm64MovKeep.read_zr
#check Arm64MovKeep.after_read
#print axioms Arm64MovKeep.after_read
#check Arm64MovKeep.writer_call
#print axioms Arm64MovKeep.writer_call
#check Arm64MovKeep.merge_eq_partInstall
#print axioms Arm64MovKeep.merge_eq_partInstall
#check Arm64MovKeep.zr_writer_call
#print axioms Arm64MovKeep.zr_writer_call
