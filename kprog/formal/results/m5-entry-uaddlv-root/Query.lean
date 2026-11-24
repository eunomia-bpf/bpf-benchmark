import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64ProgramEntryUaddlvPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryUaddlvPrefixNative.entry_corresponds
#check Arm64Uaddlv.Call.execute
#print axioms Arm64Uaddlv.Call.execute
#check Arm64Uaddlv.Call.returned
#print axioms Arm64Uaddlv.Call.returned
#check Arm64Uaddlv.Call.Result.all_behaviors
#print axioms Arm64Uaddlv.Call.Result.all_behaviors
#check Arm64Uaddlv.Call.Result.pointers
#print axioms Arm64Uaddlv.Call.Result.pointers
#check Arm64Uaddlv.Call.Result.borrowed
#print axioms Arm64Uaddlv.Call.Result.borrowed
#check Arm64Uaddlv.Call.Result.warm
#print axioms Arm64Uaddlv.Call.Result.warm
#check Arm64ProgramEntryUaddlvAdmission.next_admission
#print axioms Arm64ProgramEntryUaddlvAdmission.next_admission
#check Arm64ProgramEntryUaddlvAdmission.setup_next
#print axioms Arm64ProgramEntryUaddlvAdmission.setup_next
#check Arm64ProgramEntryCntPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryCntPrefixNative.entry_corresponds
#check Arm64Uaddlv.Body.corresponds
#print axioms Arm64Uaddlv.Body.corresponds
#check Arm64ProgramEntryUaddlvCall.enter
#print axioms Arm64ProgramEntryUaddlvCall.enter
#check Arm64ProgramEntryUaddlvCall.leave
#print axioms Arm64ProgramEntryUaddlvCall.leave
#check Arm64Uaddlv.Lanes.word
#print axioms Arm64Uaddlv.Lanes.word
#check Arm64Uaddlv.Lanes.halves128
#print axioms Arm64Uaddlv.Lanes.halves128
#check Arm64Uaddlv.Path.execute
#print axioms Arm64Uaddlv.Path.execute
#check Arm64Uaddlv.VectorWrite.execute
#print axioms Arm64Uaddlv.VectorWrite.execute
#check Arm64Uaddlv.Reduction.corresponds
#print axioms Arm64Uaddlv.Reduction.corresponds
#check Arm64Cnt.Body.corresponds
#print axioms Arm64Cnt.Body.corresponds
#check Arm64ProgramEntryCntAdmission.next_admission
#print axioms Arm64ProgramEntryCntAdmission.next_admission
