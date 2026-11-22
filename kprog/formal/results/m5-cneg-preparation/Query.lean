import KProgFormal.ClightRefinement.Arm64ProgramEntryCnegCall
import KProgFormal.ClightRefinement.Arm64CnegNative
import KProgFormal.ClightRefinement.Arm64ConditionGe

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
#check Arm64ConditionGe.internal
#print axioms Arm64ConditionGe.internal
#check Arm64ConditionGe.from_storage
#print axioms Arm64ConditionGe.from_storage
#check Arm64ConditionGe.native_truth
#print axioms Arm64ConditionGe.native_truth
