import KProgFormal.ClightRefinement.Arm64NopCall
#print axioms KProgFormal.ClightRefinement.FrameBelow.alloc
#print axioms KProgFormal.ClightRefinement.FrameBelow.allocVariables
#print axioms KProgFormal.ClightRefinement.FrameBelow.freeList
#print axioms KProgFormal.ClightRefinement.FrameBelow.load
#print axioms CC.allocVariables_env_other
#print axioms KProgFormal.ClightRefinement.Arm64NopDeclarations.vars_norepet
#print axioms KProgFormal.ClightRefinement.Arm64NopDeclarations.params_norepet
#print axioms KProgFormal.ClightRefinement.Arm64NopDeclarations.params_temps_disjoint
#print axioms KProgFormal.ClightRefinement.Arm64NopDeclarations.width_not_local
#print axioms KProgFormal.ClightRefinement.Arm64Nop.entry_valid
#print axioms KProgFormal.ClightRefinement.Arm64Nop.entry_unshadowed
#print axioms KProgFormal.ClightRefinement.Arm64Nop.entry_frame
#print axioms KProgFormal.ClightRefinement.Arm64Nop.call_returns
#print axioms KProgFormal.ClightRefinement.Arm64Nop.return_frame
#print axioms KProgFormal.ClightRefinement.Arm64Nop.call_corresponds
#print axioms CC.PTree.forall_elements_of_get
#print axioms CC.PTree.pairwise_elements_of_get
#print axioms KProgFormal.ClightRefinement.deallocate_locals
#check @KProgFormal.ClightRefinement.Arm64Nop.return_frame
#check @KProgFormal.ClightRefinement.Arm64Nop.call_returns
#check @KProgFormal.ClightRefinement.Arm64Nop.call_corresponds
