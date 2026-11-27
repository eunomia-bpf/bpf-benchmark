import KProgFormal.ClightRefinement.Arm64ByteStoreNative
import KProgFormal.ClightRefinement.Arm64MemsetByteNative

open KProgFormal.ClightRefinement

example : (Arm64ByteStoreNative.instruction 1).encoding = (0x39000001#32) := by decide +kernel
example : (Arm64ByteStoreNative.instruction 3).encoding = (0x39000003#32) := by decide +kernel

#check Arm64ByteStoreNative.decoded_word
#print axioms Arm64ByteStoreNative.decoded_word
#check Arm64ByteStoreNative.reference_step
#print axioms Arm64ByteStoreNative.reference_step
#check Arm64MemsetByteNative.reference_step
#print axioms Arm64MemsetByteNative.reference_step
