# Actual caller vector reader view

The actual caller's64 data inputs map low/high as2*i/2*i+1 at16*i+0/8. Its Header and VectorStorage pointer/data postconditions derive both pointer-slot reads and both pointee loads for all32 vector pairs.

Only the mature allocation-independent vector_readback theorem is reused. Its old producer HeaderLocal/VectorLocal allocation assumptions are not imported. A native-vector view follows with explicit provider-input matching to the existing LNSym vectorHalf definition; that matching remains a premise.

Four public queries check input_offsets, data_readbacks, vector_readbacks and native_vectors. This is not whole-state refinement or an instruction-loop/native-fetch proof. Direct/focused/full-library/public logs remain attached. CPU17/one worker/nice0/32GiB and Lean caps stay fixed, outside timingSH per coordinator2026-11-28T05:43Z during the existing x86 rotate; formal-full-check exclusion remains.
