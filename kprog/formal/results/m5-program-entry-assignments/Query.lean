import KProgFormal.ClightRefinement.Arm64ProgramEntryAssignments

open KProgFormal.ClightRefinement.Arm64ProgramEntryAssignments

#check scalar_store
#print axioms scalar_store
#check assignment
#print axioms assignment
#check assignment_sound
#print axioms assignment_sound
#check header_rhs
#print axioms header_rhs
#check header_assignment
#print axioms header_assignment
#check header_write
#print axioms header_write
#check production_header
#print axioms production_header
#check production_header_source
#print axioms production_header_source
#check header_initialized
#print axioms header_initialized

#eval (headerPrefix.map List.length).sum
