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

#check X86AluXorByteCall.execute
#print axioms X86AluXorByteCall.execute

#check X86AluXorByteNative.execute
#print axioms X86AluXorByteNative.execute

#check X86LogicByteOperands.scalar
#print axioms X86LogicByteOperands.scalar

#check X86LogicByteOperands.xor_step
#print axioms X86LogicByteOperands.xor_step

#check X86LogicReferenceView.flags
#print axioms X86LogicReferenceView.flags

#check X86LogicReferenceView.represented
#print axioms X86LogicReferenceView.represented

#check X86AluXorInputs.entry
#print axioms X86AluXorInputs.entry
