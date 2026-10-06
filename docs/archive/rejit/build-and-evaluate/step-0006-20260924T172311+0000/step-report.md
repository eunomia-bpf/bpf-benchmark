# BUILD_AND_EVALUATE Step 0006 Report

Date: 2026-09-24
Experiment: preserve load-time bytecode evidence
Result: source dependency fixed; positive KVM artifact pending

## Delivered increment

The load-time shim now retains an immutable per-step input and output whenever
`KEEP_WORKDIRS` is enabled.  It advances the optimizer pipeline by copying the
verified output to mutable `input.bin`, preserving both evidence files.  The
default non-retained path is unchanged.  IO failures are fatal and cannot
downgrade to the old destructive rename behavior.

The analysis audit now treats `input.step.0.bin` and `output.next.0.bin` as the
one-step bytecode oracle.  The shim build, Python compilation, whitespace check,
and historical negative regression oracle all behaved as planned.  Independent
review approved fail-fast semantics, multi-step ordering, scope, and code size.

## Research and paper decision

This step produces no new throughput or mechanism result for the paper.  It
closes the concrete evidence-retention dependency discovered in step 0005.
The old run remains invalid/inconclusive for direct byte comparison and its
single throughput observation remains out of the paper.

The next exact experiment is a current Cilium `map_inline`, `SAMPLES=1`,
30-second, `KEEP_WORKDIRS=1` run through `make corpus`, followed by the same
audit.  It is deferred only because a concurrent owner has uncommitted changes
to the tested `map_inline` implementation; running now would record incomplete
source provenance.  The dirty files are preserved untouched.
