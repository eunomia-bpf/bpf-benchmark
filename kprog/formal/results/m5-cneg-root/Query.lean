import KProgFormal
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
#check Arm64Cneg.ReadEntry.branch_source
#print axioms Arm64Cneg.ReadEntry.branch_source
#check Arm64Cneg.ReadEntry.body_source
#print axioms Arm64Cneg.ReadEntry.body_source
#check Arm64Cneg.ReadEntry.enter
#print axioms Arm64Cneg.ReadEntry.enter

#check Arm64Cneg.ReadEntry.returned
#print axioms Arm64Cneg.ReadEntry.returned
#check Arm64Cneg.ReadEntry.scalar
#print axioms Arm64Cneg.ReadEntry.scalar
#check Arm64Cneg.ReadEntry.ready
#print axioms Arm64Cneg.ReadEntry.ready

#check Arm64ConditionGe.native_result
#print axioms Arm64ConditionGe.native_result
#check Arm64Cneg.Condition.branch_source
#print axioms Arm64Cneg.Condition.branch_source
#check Arm64Cneg.Condition.execute
#print axioms Arm64Cneg.Condition.execute
#check Arm64Cneg.Condition.taken_value
#print axioms Arm64Cneg.Condition.taken_value
#check Arm64Cneg.Condition.temps_other
#print axioms Arm64Cneg.Condition.temps_other
