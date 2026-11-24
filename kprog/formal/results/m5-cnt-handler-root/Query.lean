import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64Cnt.Body.execute
#print axioms Arm64Cnt.Body.execute
#check Arm64Cnt.Body.corresponds
#print axioms Arm64Cnt.Body.corresponds
#check Arm64Cnt.Dispatch.body_source
#print axioms Arm64Cnt.Dispatch.body_source
#check Arm64Cnt.Dispatch.body_dispatch
#print axioms Arm64Cnt.Dispatch.body_dispatch
#check Arm64Cnt.Path.execute
#print axioms Arm64Cnt.Path.execute
#check Arm64Cnt.VectorWrite.source
#print axioms Arm64Cnt.VectorWrite.source
#check Arm64Cnt.VectorWrite.execute
#print axioms Arm64Cnt.VectorWrite.execute
#check Arm64Cnt.VectorWrite.retained
#print axioms Arm64Cnt.VectorWrite.retained
#check Arm64Cnt.High.source
#print axioms Arm64Cnt.High.source
#check Arm64Cnt.High.execute
#print axioms Arm64Cnt.High.execute
#check Arm64Cnt.High.result
#print axioms Arm64Cnt.High.result
#check Arm64Cnt.High.entry
#print axioms Arm64Cnt.High.entry
#check Arm64Cnt.High.opcode
#print axioms Arm64Cnt.High.opcode
#check Arm64Cnt.ReadReduction.execute
#print axioms Arm64Cnt.ReadReduction.execute
#check Arm64Cnt.ReadReduction.from_storage
#print axioms Arm64Cnt.ReadReduction.from_storage
#check Arm64Cnt.ReadReduction.result
#print axioms Arm64Cnt.ReadReduction.result
#check Arm64Cnt.ReadReduction.entry
#print axioms Arm64Cnt.ReadReduction.entry
#check Arm64Cnt.ReadReduction.opcode
#print axioms Arm64Cnt.ReadReduction.opcode
#check Arm64Cnt.ReadEntry.source
#print axioms Arm64Cnt.ReadEntry.source
#check Arm64Cnt.ReadEntry.prepare
#print axioms Arm64Cnt.ReadEntry.prepare
#check Arm64Cnt.ReadEntry.from_storage
#print axioms Arm64Cnt.ReadEntry.from_storage
#check Arm64Cnt.ReadEntry.input
#print axioms Arm64Cnt.ReadEntry.input
#check Arm64Cnt.ReadEntry.retained
#print axioms Arm64Cnt.ReadEntry.retained
#check Arm64Cnt.Reduction.packed_native
#print axioms Arm64Cnt.Reduction.packed_native
#check Arm64Cnt.Reduction.corresponds
#print axioms Arm64Cnt.Reduction.corresponds
#check Arm64Cnt.Packing.word
#print axioms Arm64Cnt.Packing.word
#check Arm64Cnt.Lanes.writes64
#print axioms Arm64Cnt.Lanes.writes64
#check Arm64Cnt.Lanes.bytes64
#print axioms Arm64Cnt.Lanes.bytes64
#check Arm64Cnt.Lanes.writes128
#print axioms Arm64Cnt.Lanes.writes128
#check Arm64Cnt.Lanes.bytes128
#print axioms Arm64Cnt.Lanes.bytes128
#check Arm64Cnt.Lanes.halves128
#print axioms Arm64Cnt.Lanes.halves128
#check Arm64Cnt.Reduction.execute
#print axioms Arm64Cnt.Reduction.execute
#check Arm64ProgramEntryFmovPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryFmovPrefixNative.entry_corresponds
