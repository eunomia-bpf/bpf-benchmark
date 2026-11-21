import KProgFormal.ClightRefinement.Arm64ProgramEntryAddPrefixNative
open KProgFormal.ClightRefinement
#check Arm64AddImmediate.Call.entry_valid
#print axioms Arm64AddImmediate.Call.entry_valid
#check Arm64AddImmediate.Call.execute
#print axioms Arm64AddImmediate.Call.execute
#check Arm64AddImmediate.Call.corresponds
#print axioms Arm64AddImmediate.Call.corresponds
#check Arm64AddImmediate.Call.all_behaviors
#print axioms Arm64AddImmediate.Call.all_behaviors
#check Arm64ProgramEntryAddCall.source
#print axioms Arm64ProgramEntryAddCall.source
#check Arm64ProgramEntryAddCall.enter
#print axioms Arm64ProgramEntryAddCall.enter
#check Arm64ProgramEntryAddCall.leave
#print axioms Arm64ProgramEntryAddCall.leave
#check Arm64ProgramEntryAddCall.corresponds
#print axioms Arm64ProgramEntryAddCall.corresponds
#check Arm64ProgramEntryAddPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryAddPrefixNative.entry_corresponds
