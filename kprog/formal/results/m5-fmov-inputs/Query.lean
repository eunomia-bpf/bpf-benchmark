import KProgFormal.ClightRefinement.Arm64FmovInputs
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
