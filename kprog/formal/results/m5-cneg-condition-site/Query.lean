import KProgFormal.ClightRefinement.Arm64CnegCondition
open KProgFormal.ClightRefinement
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
