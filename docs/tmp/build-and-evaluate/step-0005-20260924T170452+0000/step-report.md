# BUILD_AND_EVALUATE Step 0005 Report

Date: 2026-09-24
Experiment: audit current Cilium `map_inline` engagement
Result: retained as `invalid/inconclusive`

## What changed

Added `analysis/audit_loadtime_evidence.py`, an analysis-only fail-fast audit
that validates corpus metadata and policy, parses raw pktgen output, checks
per-step reports, joins changed report workdirs bijectively to shim optimized
events and same-thread `PROG_LOAD` results, and inspects retained bytecode
files.  It does not modify the framework, workloads, launchers, pass policy, or
raw results.

The exact input was the local run
`corpus/results/x86_kvm_corpus_20260919_041801_813418`, recorded at source
revision `38476c24f6caf50b64956c4b44e80f464096dc78`.  Plan review approved the
claim and execution boundaries before the formal preflight.  The wrong-pass
negative test exited nonzero with the expected enabled-pass mismatch.

## Result

The audit independently exposed a retention defect rather than promoting a
partial mechanism claim.  Reports and logs agree on 3,787 applied sites, 122
changed load instances, and 122 successful optimized `BPF_PROG_LOAD` results.
However, the shim renamed every step output over `input.bin`: all retained
inputs are after images and all per-step output paths are absent.  The
pre-registered before/after bytecode oracle therefore produced 244 integrity
errors and the preflight exited one.  No formal full run was started.

An independent reviewer reproduced the report, log, file, and workload totals
and agreed with `invalid/inconclusive`.  The single paired workload observation
was 1,576,821 baseline versus 1,623,352 policy sender pps (ratio
`1.0295093736067695`); it is not promoted as a repeated estimate or compared
causally with older runs.

## Paper and lifecycle decision

No paper result is added in this step.  The paper continues to use only the
step-0004 historical repeated-run table, with its existing mechanism and
cross-day caveats.  The local raw artifact remains publication backlog, not a
public artifact and not a gate for continuing research.

The next highest-value step is a minimal shim evidence-retention fix followed
by a Make-backed current Cilium `map_inline` run.  That run must preserve the
actual per-step before and after bytecode while leaving the benchmark protocol
unchanged.
