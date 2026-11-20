import KProgFormal.ClightRefinement.Arm64ProgramEntryWarmRead

open KProgFormal.ClightRefinement

#check Arm64RegisterReads.sp_read_warm_bound
#print axioms Arm64RegisterReads.sp_read_warm_bound

#check Arm64RegisterReads.sp_read_warm
#print axioms Arm64RegisterReads.sp_read_warm

#check Arm64ProgramEntryWarmRead.read
#print axioms Arm64ProgramEntryWarmRead.read

#check Arm64ProgramEntryWarmRead.all_behaviors
#print axioms Arm64ProgramEntryWarmRead.all_behaviors
