import KProgFormal


-- m5-x86-xor-result-entry

#check KProgFormal.ClightRefinement.X86AluXorResultEntry.from_call
#print axioms KProgFormal.ClightRefinement.X86AluXorResultEntry.from_call
#check KProgFormal.ClightRefinement.X86AluXorResultEntry.shortcut_from_call
#print axioms KProgFormal.ClightRefinement.X86AluXorResultEntry.shortcut_from_call

-- m5-x86-logic-classifier

#check KProgFormal.ClightRefinement.X86LogicFlagClassify.branch_source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagClassify.branch_source
#check KProgFormal.ClightRefinement.X86LogicFlagClassify.internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagClassify.internal
#check KProgFormal.ClightRefinement.X86LogicFlagClassify.to_logic
#print axioms KProgFormal.ClightRefinement.X86LogicFlagClassify.to_logic
#check KProgFormal.ClightRefinement.X86LogicFlagClassify.from_flags
#print axioms KProgFormal.ClightRefinement.X86LogicFlagClassify.from_flags
#check KProgFormal.ClightRefinement.X86LogicFlagClassify.observations
#print axioms KProgFormal.ClightRefinement.X86LogicFlagClassify.observations

-- m5-x86-apply-width

#check KProgFormal.ClightRefinement.X86ApplyWidth.internal
#print axioms KProgFormal.ClightRefinement.X86ApplyWidth.internal

-- m5-x86-logic-width-entry

#check KProgFormal.ClightRefinement.X86LogicFlagWidths.source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagWidths.source
#check KProgFormal.ClightRefinement.X86LogicFlagWidths.enter
#print axioms KProgFormal.ClightRefinement.X86LogicFlagWidths.enter
#check KProgFormal.ClightRefinement.X86LogicFlagWidths.effective_internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagWidths.effective_internal
#check KProgFormal.ClightRefinement.X86LogicFlagWidths.to_apply
#print axioms KProgFormal.ClightRefinement.X86LogicFlagWidths.to_apply

-- m5-x86-logic-width-preparation

#check KProgFormal.ClightRefinement.X86LogicFlagWidths.apply_internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagWidths.apply_internal
#check KProgFormal.ClightRefinement.X86LogicFlagWidths.bits_internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagWidths.bits_internal
#check KProgFormal.ClightRefinement.X86LogicFlagWidths.prepare
#print axioms KProgFormal.ClightRefinement.X86LogicFlagWidths.prepare
#check KProgFormal.ClightRefinement.X86LogicFlagWidths.observations
#print axioms KProgFormal.ClightRefinement.X86LogicFlagWidths.observations
