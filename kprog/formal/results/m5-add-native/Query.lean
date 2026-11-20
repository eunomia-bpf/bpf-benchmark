import KProgFormal.ClightRefinement.Arm64AddImmediateNative

open KProgFormal.ClightRefinement

#check Arm64AddImmediate.Native.execute
#print axioms Arm64AddImmediate.Native.execute

#check Arm64AddImmediate.Native.native_step
#print axioms Arm64AddImmediate.Native.native_step

#check Arm64AddImmediate.Native.reference_step
#print axioms Arm64AddImmediate.Native.reference_step

#check Arm64AddImmediate.Native.pointer_update
#print axioms Arm64AddImmediate.Native.pointer_update
