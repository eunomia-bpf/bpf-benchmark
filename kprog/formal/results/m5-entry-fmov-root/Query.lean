import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64ProducerRegisterStorage.of_header
#print axioms Arm64ProducerRegisterStorage.of_header
#check Arm64ProducerRegisterStorage.Storage.frame
#print axioms Arm64ProducerRegisterStorage.Storage.frame
#check Arm64RegisterStorageFrontier.storage_frame
#print axioms Arm64RegisterStorageFrontier.storage_frame
#check Arm64Fmov.Inputs.writable
#print axioms Arm64Fmov.Inputs.writable
#check Arm64Fmov.Inputs.old_vector
#print axioms Arm64Fmov.Inputs.old_vector
#check Arm64Fmov.Call.Result.pointers
#print axioms Arm64Fmov.Call.Result.pointers
#check Arm64Fmov.Call.Result.borrowed
#print axioms Arm64Fmov.Call.Result.borrowed
#check Arm64Fmov.Call.Result.warm
#print axioms Arm64Fmov.Call.Result.warm
#check Arm64ProgramEntryFmovPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryFmovPrefixNative.entry_corresponds
#check Arm64Cnt.Native.decoded_word
#print axioms Arm64Cnt.Native.decoded_word
#check Arm64Cnt.Native.execute
#print axioms Arm64Cnt.Native.execute
#check Arm64Cnt.Native.destination
#print axioms Arm64Cnt.Native.destination
#check Arm64Cnt.Native.native_step
#print axioms Arm64Cnt.Native.native_step
#check Arm64Cnt.Native.reference_step
#print axioms Arm64Cnt.Native.reference_step
#check Arm64ProgramEntryCntCall.entry_valid
#print axioms Arm64ProgramEntryCntCall.entry_valid
#check Arm64ProgramEntryCntCall.source
#print axioms Arm64ProgramEntryCntCall.source
#check Arm64ProgramEntryCntCall.enter
#print axioms Arm64ProgramEntryCntCall.enter
#check Arm64ProgramEntryCntCall.leave
#print axioms Arm64ProgramEntryCntCall.leave
