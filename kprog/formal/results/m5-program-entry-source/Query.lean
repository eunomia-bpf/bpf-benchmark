import KProgFormal.ClightRefinement.Arm64ProgramEntryExpressions

open KProgFormal.ClightRefinement.Arm64ProgramEntrySource

#check Spine.reconstruct
#print axioms Spine.reconstruct
#check producer_source
#print axioms producer_source
#check production_source
#print axioms production_source
#check prefix_corresponds
#print axioms prefix_corresponds

open KProgFormal.ClightRefinement.Arm64ProgramEntryExpressions

#check declaration_type
#print axioms declaration_type
#check bound_lvalue
#print axioms bound_lvalue
#check bound_read
#print axioms bound_read
#check bound_address
#print axioms bound_address
#check allocated_local
#print axioms allocated_local

#check temporary_types
#print axioms temporary_types
#check temporary_names_distinct
#print axioms temporary_names_distinct
#eval initialization.map List.length
