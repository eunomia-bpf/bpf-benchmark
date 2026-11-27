# Actual function entry through NZCV initialization

The module invokes the accepted TableEntry.entry once and the accepted
four-visit FlagSequence.execute once. Their actual heap, external traces
and TempEnv updates are sequenced from the original internal function
call to Flags.after, immediately before the real LR zero assignment.

Kernel checks prove that the actual 31 GPR word/tag names, ABI identifier,
nine defaults and both table identifiers lie outside the four flag names.
Their actual allocation bindings turn the SAME named-local frame into
physical block-load frames. The final heap therefore retains all 31 GPR
pairs, all 62 pointer slots, both ABI pointers, five CB zeros, nine defaults
and all four initialized flags, plus caller memory, access and frontier.

Both genuine TableWrites.Initialized resources retain their original
before/initialized heaps, TempEnv, continuation, execution and store fields.
Only their current-memory load frame is extended through that SAME suffix.
There is no rebuilt initializer witness, second allocation or prefix rerun.
Actual context/GPR/flag external availability and effect obligations remain
explicit in their existing interfaces; no purity or successful reader is
silently supplied.

The endpoint precedes LR zero, 64 vector inputs, the instruction prefix and
the first LINK. Native execution, loaded text, global/universal refinement
and fixture/resource recount remain open. Actual Cilium LINKs remain BPF
helper calls, separate from memcpy. Query.lean checks four public interfaces
and actual axioms; validation.json records exact source, original resource
caps, timing policy and full checks. Promotion keeps the direct snapshot bytes.
