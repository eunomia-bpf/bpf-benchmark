import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64Cneg.Path.execute
#print axioms Arm64Cneg.Path.execute
#check Arm64Cneg.Dispatch.body_source
#print axioms Arm64Cneg.Dispatch.body_source
#check Arm64Cneg.Dispatch.body_dispatch
#print axioms Arm64Cneg.Dispatch.body_dispatch
#check Arm64Cneg.Body.execute
#print axioms Arm64Cneg.Body.execute
#check Arm64Cneg.Body.corresponds
#print axioms Arm64Cneg.Body.corresponds
#check Arm64Cneg.Call.execute
#print axioms Arm64Cneg.Call.execute
#check Arm64Cneg.Call.Result.all_behaviors
#print axioms Arm64Cneg.Call.Result.all_behaviors
#check Arm64Cneg.Call.returned
#print axioms Arm64Cneg.Call.returned
#check Arm64ProgramEntryCnegAdmission.next_admission
#print axioms Arm64ProgramEntryCnegAdmission.next_admission
#check Arm64ProgramEntryCnegAdmission.setup_next
#print axioms Arm64ProgramEntryCnegAdmission.setup_next
