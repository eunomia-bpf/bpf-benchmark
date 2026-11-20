import KProgFormal.ClightRefinement.Arm64AddOperandReads

open KProgFormal.ClightRefinement

#check Arm64AddOperandReads.sp_pointer
#print axioms Arm64AddOperandReads.sp_pointer

#check Arm64AddOperandReads.sp_tag
#print axioms Arm64AddOperandReads.sp_tag

#check Arm64AddOperandReads.zero_read
#print axioms Arm64AddOperandReads.zero_read

#check Arm64AddOperandReads.Linked.bindings
#print axioms Arm64AddOperandReads.Linked.bindings

#check Arm64AddOperandReads.Linked.sp_reads
#print axioms Arm64AddOperandReads.Linked.sp_reads

#check Arm64AddOperandReads.Linked.sp_native
#print axioms Arm64AddOperandReads.Linked.sp_native
