import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64ProgramEntryOrnCall.source
#print axioms Arm64ProgramEntryOrnCall.source
#check Arm64ProgramEntryOrnCall.entry_valid
#print axioms Arm64ProgramEntryOrnCall.entry_valid
#check Arm64ProgramEntryOrnCall.enter
#print axioms Arm64ProgramEntryOrnCall.enter
#check Arm64ProgramEntryOrnCall.leave
#print axioms Arm64ProgramEntryOrnCall.leave
#check Arm64Orn.Native.execute
#print axioms Arm64Orn.Native.execute
#check Arm64Orn.Native.native_step
#print axioms Arm64Orn.Native.native_step
#check Arm64Orn.Native.reference_step
#print axioms Arm64Orn.Native.reference_step
#check Arm64Modified.Modifier.execute_lsl_zero
#print axioms Arm64Modified.Modifier.execute_lsl_zero
#check Arm64Modified.Modifier.execute_lsl_one
#print axioms Arm64Modified.Modifier.execute_lsl_one
#check Arm64Modified.LslOne.execute
#print axioms Arm64Modified.LslOne.execute
