import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64Fmov.VectorMemory.write
#print axioms Arm64Fmov.VectorMemory.write
#check Arm64Fmov.VectorMemory.Effect.low
#print axioms Arm64Fmov.VectorMemory.Effect.low
#check Arm64Fmov.VectorMemory.Effect.high
#print axioms Arm64Fmov.VectorMemory.Effect.high
#check Arm64Fmov.VectorMemory.Effect.other
#print axioms Arm64Fmov.VectorMemory.Effect.other
#check Arm64Fmov.VectorMemory.Effect.other_half
#print axioms Arm64Fmov.VectorMemory.Effect.other_half
#check Arm64Fmov.VectorMemory.Effect.access
#print axioms Arm64Fmov.VectorMemory.Effect.access
#check Arm64Fmov.VectorMemory.Effect.nextblock
#print axioms Arm64Fmov.VectorMemory.Effect.nextblock
#check Arm64Fmov.VectorStorage.separate
#print axioms Arm64Fmov.VectorStorage.separate
#check Arm64Fmov.VectorStorage.local_load
#print axioms Arm64Fmov.VectorStorage.local_load
#check Arm64Fmov.VectorStorage.storage
#print axioms Arm64Fmov.VectorStorage.storage
#check Arm64Fmov.VectorStorage.cell
#print axioms Arm64Fmov.VectorStorage.cell
#check Arm64Fmov.VectorStorage.flag
#print axioms Arm64Fmov.VectorStorage.flag
#check Arm64Fmov.VectorWrite.source
#print axioms Arm64Fmov.VectorWrite.source
#check Arm64Fmov.VectorWrite.execute
#print axioms Arm64Fmov.VectorWrite.execute
#check Arm64Fmov.VectorWrite.retained
#print axioms Arm64Fmov.VectorWrite.retained
#check Arm64Fmov.Path.execute
#print axioms Arm64Fmov.Path.execute
