import KProgFormal.ClightRefinement.X86LogicFlagStage
import KProgFormal.ClightRefinement.X86AluXorResultEntry

#check KProgFormal.ClightRefinement.X86ShiftWriteback.select_scalar
#print axioms KProgFormal.ClightRefinement.X86ShiftWriteback.select_scalar
#check KProgFormal.ClightRefinement.X86ShiftWriteback.narrow_writer
#print axioms KProgFormal.ClightRefinement.X86ShiftWriteback.narrow_writer
#check KProgFormal.ClightRefinement.X86ShiftWriteback.byte_register_table
#print axioms KProgFormal.ClightRefinement.X86ShiftWriteback.byte_register_table
#check KProgFormal.ClightRefinement.X86RegisterView.byte_writer_native
#print axioms KProgFormal.ClightRefinement.X86RegisterView.byte_writer_native
#check KProgFormal.ClightRefinement.X86RegisterView.byte_writer_writable
#print axioms KProgFormal.ClightRefinement.X86RegisterView.byte_writer_writable
#check KProgFormal.ClightRefinement.X86RegisterView.byte_writer_allocated
#print axioms KProgFormal.ClightRefinement.X86RegisterView.byte_writer_allocated
#check KProgFormal.ClightRefinement.X86RegisterView.byte_writer_allocated (code := 2#32)
#check KProgFormal.ClightRefinement.X86RegisterView.byte_writer_allocated (code := 3#32)
#check KProgFormal.ClightRefinement.X86RegisterView.byte_writer_allocated (code := 4#32)
#check KProgFormal.ClightRefinement.X86RegisterView.byte_writer_allocated (code := 5#32)
