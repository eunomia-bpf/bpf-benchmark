import KProgFormal.ClightRefinement.Arm64MovKeepLinked

open KProgFormal.ClightRefinement

#check Arm64RegisterWrite.program_layout
#print axioms Arm64RegisterWrite.program_layout
#check Arm64RegisterWrite.execute_stores_layout
#print axioms Arm64RegisterWrite.execute_stores_layout
#check Arm64RegisterWrite.execute_zr_layout
#print axioms Arm64RegisterWrite.execute_zr_layout
#check Arm64MovKeep.read_scalar_bound
#print axioms Arm64MovKeep.read_scalar_bound
#check Arm64MovKeep.scalar_writer_call_bound
#print axioms Arm64MovKeep.scalar_writer_call_bound
#check Arm64MovKeep.read_call_bound
#print axioms Arm64MovKeep.read_call_bound
#check Arm64MovKeep.after_read_bound
#print axioms Arm64MovKeep.after_read_bound
#check Arm64MovKeep.writer_call_bound
#print axioms Arm64MovKeep.writer_call_bound
#check Arm64MovImmediate.Suffix.after_writer_bound
#print axioms Arm64MovImmediate.Suffix.after_writer_bound
#check Arm64MovKeep.Linked.reader_layout
#print axioms Arm64MovKeep.Linked.reader_layout
#check Arm64MovKeep.Linked.writer_layout
#print axioms Arm64MovKeep.Linked.writer_layout
#check Arm64MovKeep.Linked.reader_binding
#print axioms Arm64MovKeep.Linked.reader_binding
#check Arm64MovKeep.Linked.writer_binding
#print axioms Arm64MovKeep.Linked.writer_binding
#check Arm64MovKeep.Linked.read_scalar
#print axioms Arm64MovKeep.Linked.read_scalar
#check Arm64MovKeep.Linked.write_scalar
#print axioms Arm64MovKeep.Linked.write_scalar
#check Arm64MovKeep.Linked.branch_returns
#print axioms Arm64MovKeep.Linked.branch_returns
#check Arm64MovKeep.Linked.branch_corresponds
#print axioms Arm64MovKeep.Linked.branch_corresponds
