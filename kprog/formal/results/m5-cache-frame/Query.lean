import KProgFormal.ClightRefinement.Arm64ProgramEntryCacheFrame

open KProgFormal.ClightRefinement

#check Arm64RegisterWrite.storage_flag
#print axioms Arm64RegisterWrite.storage_flag

#check Arm64ProgramEntryCacheFrame.Frame.trans
#print axioms Arm64ProgramEntryCacheFrame.Frame.trans

#check Arm64ProgramEntryCacheFrame.Frame.storage
#print axioms Arm64ProgramEntryCacheFrame.Frame.storage

#check Arm64ProgramEntryCacheFrame.Frame.gpr
#print axioms Arm64ProgramEntryCacheFrame.Frame.gpr

#check Arm64ProgramEntryCacheFrame.Frame.sp
#print axioms Arm64ProgramEntryCacheFrame.Frame.sp

#check Arm64ProgramEntryCacheFrame.Frame.vector
#print axioms Arm64ProgramEntryCacheFrame.Frame.vector

#check Arm64ProgramEntryCacheFrame.Frame.flag
#print axioms Arm64ProgramEntryCacheFrame.Frame.flag

#check Arm64ProgramEntryCacheFrame.Frame.represents
#print axioms Arm64ProgramEntryCacheFrame.Frame.represents

#check Arm64ProgramEntryCacheFrame.stores_frame
#print axioms Arm64ProgramEntryCacheFrame.stores_frame

#check Arm64ProgramEntryCacheFrame.cache_storage
#print axioms Arm64ProgramEntryCacheFrame.cache_storage

#check Arm64ProgramEntryCacheFrame.read_framed
#print axioms Arm64ProgramEntryCacheFrame.read_framed
