import KProgFormal

open KProgFormal.ClightRefinement
#check Arm64MemcpyIterationPhysical.execute
#print axioms Arm64MemcpyIterationPhysical.execute
#check Arm64KernelMemcpyCode.pairs
#print axioms Arm64KernelMemcpyCode.pairs
#check Arm64KernelMemcpyPrologue.execute
#print axioms Arm64KernelMemcpyPrologue.execute
#check Arm64KernelMemcpySmallGates.execute
#print axioms Arm64KernelMemcpySmallGates.execute
