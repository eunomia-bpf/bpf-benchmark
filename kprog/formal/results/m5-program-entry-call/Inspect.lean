import KProgFormal.ClightRefinement.Arm64ProgramEntryCall
open KProgFormal.ClightRefinement
#eval (CC.Genv.findSymbol Arm64ProgramEntryAllocation.world.genv_genv Arm64ProgramFixture._arm64_execute_compile).map CC.Positive.toNat
#eval (CC.Genv.findSymbol Arm64ProgramEntryAllocation.world.genv_genv Arm64Entry._native_lab_entry_input).map CC.Positive.toNat
#eval Arm64ProgramEntrySource.initializationTemps.length
