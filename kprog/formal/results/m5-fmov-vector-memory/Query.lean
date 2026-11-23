import KProgFormal.ClightRefinement.Arm64FmovVectorMemory
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
