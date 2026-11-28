# Actual function entry through all vector initializers

entry invokes the accepted LR.entry once and VectorSequence.execute once.
It takes the actual Storage resource from the SAME original 795-local
allocation, available by VectorSource.storage, and retains each reached
heap, external trace and actual TempEnv update through all 64 vector visits.
It does not allocate another environment or rerun any earlier prefix.

Kernel checks establish that all actual GPR word/tag, ABI, default, table,
flag and LR identifiers lie outside the vector identifier. Their actual
allocation bindings turn the SAME sequence's named-local frame into physical
block-load frames. The final heap therefore has all 64 vector lane reads,
31 GPR pairs, four flags, LR zero, 62 table slots, two ABI pointers, five CB
zero words and nine defaults, plus caller memory, access and frontier.

Both genuine table initialization resources keep the same original before/
initialized heaps, TempEnv, continuation, execution and store fields.
Only their current-memory load frames are extended through the SAME suffix.
Actual context/GPR/flag/vector availability and external call effects remain
explicit; no purity, oracle, successful initialized reader or old allocator
correspondence is supplied.

The endpoint is the untouched original after-64 continuation. Remaining
prologue/instruction-prefix and LINK reachability, native/loaded-text,
global/universal refinement and recount remain open. Cilium LINKs are BPF
helpers, separate from memcpy. Query.lean checks three public declarations
and actual axioms. validation.json records exact source, original resource/
timing policy and full checks; promotion preserves direct snapshot bytes.
