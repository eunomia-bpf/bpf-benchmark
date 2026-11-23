import KProgFormal.ClightRefinement.Arm64ProgramEntryFmovCall
import KProgFormal.ClightRefinement.Arm64FmovNative
open KProgFormal.ClightRefinement
#check Arm64ProgramEntryFmovCall.entry_valid
#print axioms Arm64ProgramEntryFmovCall.entry_valid
#check Arm64ProgramEntryFmovCall.source
#print axioms Arm64ProgramEntryFmovCall.source
#check Arm64ProgramEntryFmovCall.enter
#print axioms Arm64ProgramEntryFmovCall.enter
#check Arm64ProgramEntryFmovCall.leave
#print axioms Arm64ProgramEntryFmovCall.leave
#check Arm64Fmov.Native.decoded_word
#print axioms Arm64Fmov.Native.decoded_word
#check Arm64Fmov.Native.execute
#print axioms Arm64Fmov.Native.execute
#check Arm64Fmov.Native.destination
#print axioms Arm64Fmov.Native.destination
#check Arm64Fmov.Native.native_step
#print axioms Arm64Fmov.Native.native_step
#check Arm64Fmov.Native.reference_step
#print axioms Arm64Fmov.Native.reference_step
