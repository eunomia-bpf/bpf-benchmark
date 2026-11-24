import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64ProgramEntryCntPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryCntPrefixNative.entry_corresponds
#check Arm64Cnt.Call.execute
#print axioms Arm64Cnt.Call.execute
#check Arm64Cnt.Call.returned
#print axioms Arm64Cnt.Call.returned
#check Arm64Cnt.Call.Result.all_behaviors
#print axioms Arm64Cnt.Call.Result.all_behaviors
#check Arm64Cnt.Call.Result.pointers
#print axioms Arm64Cnt.Call.Result.pointers
#check Arm64Cnt.Call.Result.borrowed
#print axioms Arm64Cnt.Call.Result.borrowed
#check Arm64Cnt.Call.Result.warm
#print axioms Arm64Cnt.Call.Result.warm
#check Arm64ProgramEntryCntAdmission.next_admission
#print axioms Arm64ProgramEntryCntAdmission.next_admission
#check Arm64ProgramEntryCntAdmission.setup_next
#print axioms Arm64ProgramEntryCntAdmission.setup_next
#check Arm64ProgramEntryFmovPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryFmovPrefixNative.entry_corresponds
#check Arm64Cnt.Body.corresponds
#print axioms Arm64Cnt.Body.corresponds
#check Arm64ProgramEntryCntCall.enter
#print axioms Arm64ProgramEntryCntCall.enter
#check Arm64ProgramEntryCntCall.leave
#print axioms Arm64ProgramEntryCntCall.leave
