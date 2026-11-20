import KProgFormal.ClightRefinement.Arm64ProgramEntryBodyView

open KProgFormal.ClightRefinement

#check Arm64RegisterWrite.storage_vector
#print axioms Arm64RegisterWrite.storage_vector

#check Arm64ProgramEntryBodyView.setup
#print axioms Arm64ProgramEntryBodyView.setup

#check Arm64ProgramEntryBodyView.Result.storage
#print axioms Arm64ProgramEntryBodyView.Result.storage

#check Arm64ProgramEntryBodyView.Result.gpr
#print axioms Arm64ProgramEntryBodyView.Result.gpr

#check Arm64ProgramEntryBodyView.Result.vector
#print axioms Arm64ProgramEntryBodyView.Result.vector

#check Arm64ProgramEntryBodyView.Result.sp_read
#print axioms Arm64ProgramEntryBodyView.Result.sp_read

#check Arm64ProgramEntryBodyView.Result.flag_read
#print axioms Arm64ProgramEntryBodyView.Result.flag_read

#check Arm64ProgramEntryBodyView.native_other
#print axioms Arm64ProgramEntryBodyView.native_other

#check Arm64ProgramEntryBodyView.native_gpr
#print axioms Arm64ProgramEntryBodyView.native_gpr

#check Arm64ProgramEntryBodyView.native_sp
#print axioms Arm64ProgramEntryBodyView.native_sp

#check Arm64ProgramEntryBodyView.native_vector
#print axioms Arm64ProgramEntryBodyView.native_vector

#check Arm64ProgramEntryBodyView.native_resources
#print axioms Arm64ProgramEntryBodyView.native_resources

#check Arm64ProgramEntryBodyView.native_flag_values
#print axioms Arm64ProgramEntryBodyView.native_flag_values

#check Arm64ProgramEntryBodyView.Result.represents
#print axioms Arm64ProgramEntryBodyView.Result.represents

#check Arm64ProgramEntryBodyView.setup_represents
#print axioms Arm64ProgramEntryBodyView.setup_represents

#check Arm64ProgramEntryBodyView.entry_setup_represents
#print axioms Arm64ProgramEntryBodyView.entry_setup_represents
