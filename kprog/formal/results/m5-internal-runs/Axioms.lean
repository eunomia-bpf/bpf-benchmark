import KProgFormal.ClightRefinement.Arm64NopEntry
#print axioms KProgFormal.ClightRefinement.internal_step_unique
#print axioms KProgFormal.ClightRefinement.internalRun_of_steps
#print axioms KProgFormal.ClightRefinement.InternalRun.trans
#print axioms KProgFormal.ClightRefinement.InternalRun.sound
#print axioms KProgFormal.ClightRefinement.InternalRun.finish_prefix
#print axioms KProgFormal.ClightRefinement.InternalRun.endpoint_unique
#print axioms KProgFormal.ClightRefinement.InternalRun.no_infinite
#print axioms KProgFormal.ClightRefinement.Arm64Width.internal
#print axioms KProgFormal.ClightRefinement.Arm64Nop.body_internal
#print axioms KProgFormal.ClightRefinement.Arm64Nop.call_internal
#print axioms KProgFormal.ClightRefinement.Arm64Nop.call_all_behaviors
#print axioms KProgFormal.ClightRefinement.Arm64Nop.return_flags_correspond
#print axioms KProgFormal.ClightRefinement.Arm64Width.executes
#print axioms KProgFormal.ClightRefinement.Arm64Width.returns
#print axioms KProgFormal.ClightRefinement.Arm64Nop.body_returns
#print axioms KProgFormal.ClightRefinement.Arm64Nop.call_returns
#print axioms KProgFormal.ClightRefinement.Arm64Nop.call_flags_correspond
#check @KProgFormal.ClightRefinement.Arm64Nop.call_internal
#check @KProgFormal.ClightRefinement.Arm64Nop.call_all_behaviors
#check @KProgFormal.ClightRefinement.Arm64Nop.return_flags_correspond
