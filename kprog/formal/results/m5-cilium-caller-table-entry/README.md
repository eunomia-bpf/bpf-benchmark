# Actual caller function entry through both pointer tables

The checked module composes the original captured Clight function entry,
its two context calls/stores, five CB zero words, nine defaults and all
31 actual GPR initializers with the SAME 186-step pointer-table execution.
It constructs both Table and both Cells resources from the SAME original
795-local allocation, then invokes GPREntry.entry and Initializers.execute_framed
once each. No second allocation, synthetic heap, repeated prefix or
initialized observer assumption supplies the result.

The final SAME heap, TempEnv and trace retain all 31 word/tag GPR readbacks,
both ABI context pointers, all five CB zero words and nine defaults. It
also exports all 62 real pointer-table slot readbacks and both genuine
TableWrites.Initialized resources at slot 30. Real allocated identifiers
and their block separation instantiate the non-table load frame from
that one 186-step execution. Caller memory, access and allocation frontier
are retained. Query.lean checks the five public declarations and their
actual axiom dependencies; validation.json contains exact source hash and
CPU/timing/build receipts. stage1.log.gz is the exact direct check before
canonical promotion; the promoted source is byte-identical.

The endpoint is the original Initializers.afterTables before vector/provider
preparation and the first LINK. Context/GPR external-call availability,
actual trace/heap/value/access/local/caller-frame obligations remain explicit
in their existing input interfaces. This does not discharge the helper
implementations or claim native execution, loaded-text equivalence,
global Clight refinement, universality, or any fixture/resource recount.
Actual Cilium LINKs remain BPF-helper calls, separate from memcpy.
The frozen captured AST and existing production/runtime evidence stay unchanged.
