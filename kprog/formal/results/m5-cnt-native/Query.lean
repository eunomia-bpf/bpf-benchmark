import KProgFormal.ClightRefinement.Arm64CntNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryCntCall
open KProgFormal.ClightRefinement
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
