import KProgFormal.ClightRefinement.Arm64ProgramEntryCnegCall
import KProgFormal.ClightRefinement.Arm64CnegNative

open KProgFormal.ClightRefinement

#check Arm64ProgramEntryCnegCall.entry_valid
#print axioms Arm64ProgramEntryCnegCall.entry_valid
#check Arm64ProgramEntryCnegCall.enter
#print axioms Arm64ProgramEntryCnegCall.enter
#check Arm64ProgramEntryCnegCall.leave
#print axioms Arm64ProgramEntryCnegCall.leave
#check Arm64Cneg.Native.inverse_condition
#print axioms Arm64Cneg.Native.inverse_condition
#check Arm64Cneg.Native.execute
#print axioms Arm64Cneg.Native.execute
#check Arm64Cneg.Native.native_step
#print axioms Arm64Cneg.Native.native_step
#check Arm64Cneg.Native.reference_step
#print axioms Arm64Cneg.Native.reference_step
