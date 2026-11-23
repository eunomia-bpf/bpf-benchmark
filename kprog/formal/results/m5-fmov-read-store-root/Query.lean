import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64VectorWritable.allocated
#print axioms Arm64VectorWritable.allocated
#check Arm64VectorWritable.store
#print axioms Arm64VectorWritable.store
#check Arm64VectorWritable.frame
#print axioms Arm64VectorWritable.frame
#check Arm64VectorWritable.half
#print axioms Arm64VectorWritable.half
#check Arm64VectorWritable.half_pointer
#print axioms Arm64VectorWritable.half_pointer
#check Arm64Fmov.ReadEntry.branch_source
#print axioms Arm64Fmov.ReadEntry.branch_source
#check Arm64Fmov.ReadEntry.body_source
#print axioms Arm64Fmov.ReadEntry.body_source
#check Arm64Fmov.ReadEntry.prepare
#print axioms Arm64Fmov.ReadEntry.prepare
#check Arm64Fmov.ReadEntry.returned
#print axioms Arm64Fmov.ReadEntry.returned
#check Arm64Fmov.ReadEntry.scalar
#print axioms Arm64Fmov.ReadEntry.scalar
#check Arm64Fmov.ReadOperands.ready
#print axioms Arm64Fmov.ReadOperands.ready
#check Arm64Fmov.ReadOperands.from_storage
#print axioms Arm64Fmov.ReadOperands.from_storage
#check Arm64Fmov.Numeric.source
#print axioms Arm64Fmov.Numeric.source
#check Arm64Fmov.Numeric.execute
#print axioms Arm64Fmov.Numeric.execute
#check Arm64Fmov.StoreEntry.execute
#print axioms Arm64Fmov.StoreEntry.execute
