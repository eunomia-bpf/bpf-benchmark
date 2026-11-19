import KProgFormal.ClightRefinement.Arm64ProgramEntryVectors
open KProgFormal.ClightRefinement
#eval (CC.Genv.findSymbol Arm64ProgramEntryAllocation.world.genv_genv Arm64ProgramFixture._kprog_arm64_payload_load).map CC.Positive.toNat
#eval (CC.Genv.findSymbol Arm64ProgramEntryAllocation.world.genv_genv Arm64ProgramFixture._kprog_arm64_payload_store).map CC.Positive.toNat
