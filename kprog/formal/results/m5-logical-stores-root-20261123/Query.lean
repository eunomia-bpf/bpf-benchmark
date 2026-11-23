import KProgFormal


-- m5-x86-logic-zero-flags

#check KProgFormal.ClightRefinement.X86LogicFlagStores.source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.source
#check KProgFormal.ClightRefinement.X86LogicFlagStores.cf_source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.cf_source
#check KProgFormal.ClightRefinement.X86LogicFlagStores.of_source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.of_source
#check KProgFormal.ClightRefinement.X86LogicFlagStores.cf_internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.cf_internal
#check KProgFormal.ClightRefinement.X86LogicFlagStores.of_internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.of_internal

-- m5-x86-logic-zf-pf

#check KProgFormal.ClightRefinement.X86LogicFlagStores.zf_source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.zf_source
#check KProgFormal.ClightRefinement.X86LogicFlagStores.parity_source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.parity_source
#check KProgFormal.ClightRefinement.X86LogicFlagStores.zf_internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.zf_internal
#check KProgFormal.ClightRefinement.X86LogicFlagStores.parity_internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.parity_internal

-- m5-x86-logic-sign-flag

#check KProgFormal.ClightRefinement.X86LogicFlagStores.sf_source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.sf_source
#check KProgFormal.ClightRefinement.X86LogicFlagStores.sign_value
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.sign_value
#check KProgFormal.ClightRefinement.X86LogicFlagStores.sf_internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.sf_internal
#check KProgFormal.ClightRefinement.X86LogicFlagStores.native_values
#print axioms KProgFormal.ClightRefinement.X86LogicFlagStores.native_values

-- m5-x86-logic-flag-order

#check KProgFormal.ClightRefinement.X86LogicFlagOrder.source
#print axioms KProgFormal.ClightRefinement.X86LogicFlagOrder.source
#check KProgFormal.ClightRefinement.X86LogicFlagOrder.internal
#print axioms KProgFormal.ClightRefinement.X86LogicFlagOrder.internal
