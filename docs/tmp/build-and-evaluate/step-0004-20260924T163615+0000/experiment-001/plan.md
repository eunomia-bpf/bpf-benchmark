# Experiment 001 Plan: Recover Real-Application Throughput Evidence

Date: 2026-09-24T16:36:15+00:00
Phase: BUILD_AND_EVALUATE
Selected paper question: RQ1, "Does Load-Time Specialization Work End to End?"
The tested uncertainty is deliberately narrower than the whole RQ: whether the
six user-identified historical batches contain reconstructable paired workload
throughput evidence from the declared load-time path.

## Paper-value admission

This experiment consolidates already-completed, real KVM runs before spending
another KVM window.  Its decisive uncertainty is whether the retained Cilium
and Katran throughput claims can be reconstructed directly from the historical
Git objects using the recorded two-start path, exact pass list, workload
duration, successful application status, and raw workload output.  A positive
result lets the paper replace its results placeholder with source-linked RQ1
evidence.  A contradictory result removes the affected number from the paper;
a mixed result limits the result to the batches that pass reconstruction; an
inconclusive result requires a fresh Make-backed run.

The six batches are the complete set explicitly named in the current user
instruction, not a search over historical results for favorable rows.  The
consolidation adds independent evidence because every reported scalar is
recomputed from the raw phase-local stdout and checked against the lifecycle
and policy fields, rather than copied from the research log.  Its role remains
`supporting`: it can authorize a scoped throughput result in RQ1, but it cannot
substitute for the missing six-app pass-coverage and per-site evidence.

The strongest alternative use of the current experiment budget is a new
Katran `map_inline` confirmation.  That run is currently lower value because
OMP is already using the shared KVM and ten retained 180-second Katran runs can
answer the immediate provenance question without resource contention.  This
experiment is supporting evidence toward RQ1, not a new headline experiment
and not a causal comparison between batches collected on different days.

## Hypothesis and competing explanation

The hypothesis is that the baseline and declared load-time-policy phases in
the retained Cilium and Katran batches contain a repeated positive
workload-throughput difference.  The competing explanation is that
the reported values were derived from the wrong output field, from a different
lifecycle or pass list, or by comparing unrelated runs rather than the paired
baseline and optimized phases inside each artifact.

The retained lifecycle fields establish that the declared plan ran through the
load-time path.  They do not establish per-site pass engagement because the
historical per-step reports were not committed.  The experiment therefore does
not causally attribute the observed difference to a particular transformation.

The corrected Tracee and BCC `context_specialize` batches are reconstructed in
the same audit.  Their summed bogo-op calculation reproduces the exact
historical claim requested by the user, but the constituent stressors have
different operation meanings.  It is therefore an internal provenance check,
not a paper-facing aggregate.  The per-stressor rows remain in the source JSON.

## Inputs and comparison matrix

All cells are x86 KVM corpus artifacts at Git revision `5b130b6ec`, where the
last experiment-093 artifact is present.  Each cell contains ten independent
artifact directories and one paired baseline/optimized comparison per
artifact.

| Application | Passes | Run interval | Primary metric |
| --- | --- | --- | --- |
| Cilium | `hot_region_version,map_inline` | `20260813_172108_373028`--`20260813_201304_104628` | sum of the two raw pktgen `pps` fields |
| Cilium | `hot_region_version` | `20260730_095500_065399`--`20260730_135809_421407` | sum of the two raw pktgen `pps` fields |
| Cilium | `map_inline` | `20260730_143828_990498`--`20260730_183454_838901` | sum of the two raw pktgen `pps` fields |
| Katran | `map_inline` | `20260729_175727_128341`--`20260730_084820_320412` | sum of the four raw pktgen-thread `pps` fields |
| Tracee | `context_specialize` | `20260813_101212_102293`--`20260813_131003_298020` | sum of per-stressor raw stress-ng bogo ops |
| BCC | `context_specialize` | `20260813_134141_183681`--`20260813_164950_279285` | sum of per-stressor raw stress-ng bogo ops |

The per-artifact effect is optimized throughput divided by baseline
throughput.  The batch aggregate is the geometric mean of the ten ratios;
win/loss counts and the observed range are supplemental.  Batches remain
separate because their wall-clock dates and policies differ.

Classification does not filter any run.  A batch is directionally positive
when its geomean is above one, directionally negative when below one, and tied
when equal to one.  A batch containing ratios on both sides of one is reported
as mixed in addition to its aggregate direction.  Missing or unparsable raw
metrics, a nonterminal lifecycle, or a policy mismatch makes the affected row
invalid and the batch inconclusive until repaired or freshly rerun; the row is
still retained in the output.  These labels describe the evidence and are not
new benchmark admission gates.

Uncertainty is a 95% percentile-bootstrap interval over the ten paired run
ratios: 100,000 resamples of size ten with replacement, seed `20260924`, and
the 2.5th/97.5th linearly interpolated percentiles.  An interval wholly above
one is reported as repeated positive evidence; an interval crossing one is
reported as a positive point estimate with unresolved run-level uncertainty.
The interval never removes an artifact or changes its raw validity.

## Validation and completion rule

Every declared artifact is inspected.  The analyzer reads suite status,
application status and error, load-time ReJIT status, the exact ordered pass
list, configured workload duration, and every leaf workload return code from
the same Git revision.  For pktgen it parses the integer immediately preceding
`pps` on the completed `Result: OK` report for each named leaf.  For stress-ng
it parses the raw `bogo ops` column from every `stress-ng: metrc:` row.  Missing
or contradictory fields are emitted as invalid rows rather than silently
excluded.

The full run is complete when all 60 artifacts have been inspected, every
valid row has its raw baseline/optimized total and ratio printed, every invalid
row and reason is printed, and an independent result review recomputes the
proposed paper numbers.  The introducing commit identifies when each raw app
JSON entered Git history; it does not identify the runtime kernel, application,
or optimizer revision, which these historical metadata do not record.  Raw
data remain in Git history; the experiment directory keeps the command output
and review, not copied result JSON.

## Execution and paper target

The analysis-side reader is `analysis/speculative_workload_history.py`.  The
real preflight is the first Cilium composed-policy artifact, selected with the
same Git-object, metadata, parser, and metric path as the full analysis:

```sh
timeout 120s python3 analysis/speculative_workload_history.py \
  --git-ref 5b130b6ec --expected-runs 1 --workload-seconds 180 \
  --app cilium/agent \
  --start-run x86_kvm_corpus_20260813_172108_373028 \
  --end-run x86_kvm_corpus_20260813_172108_373028 \
  --passes hot_region_version,map_inline --metric pktgen-pps
```

The full invocations are:

```sh
timeout 120s python3 analysis/speculative_workload_history.py --git-ref 5b130b6ec --expected-runs 10 --workload-seconds 180 --app cilium/agent --start-run x86_kvm_corpus_20260813_172108_373028 --end-run x86_kvm_corpus_20260813_201304_104628 --passes hot_region_version,map_inline --metric pktgen-pps
timeout 120s python3 analysis/speculative_workload_history.py --git-ref 5b130b6ec --expected-runs 10 --workload-seconds 180 --app cilium/agent --start-run x86_kvm_corpus_20260730_095500_065399 --end-run x86_kvm_corpus_20260730_135809_421407 --passes hot_region_version --metric pktgen-pps
timeout 120s python3 analysis/speculative_workload_history.py --git-ref 5b130b6ec --expected-runs 10 --workload-seconds 180 --app cilium/agent --start-run x86_kvm_corpus_20260730_143828_990498 --end-run x86_kvm_corpus_20260730_183454_838901 --passes map_inline --metric pktgen-pps
timeout 120s python3 analysis/speculative_workload_history.py --git-ref 5b130b6ec --expected-runs 10 --workload-seconds 180 --app katran --start-run x86_kvm_corpus_20260729_175727_128341 --end-run x86_kvm_corpus_20260730_084820_320412 --passes map_inline --metric pktgen-pps
timeout 120s python3 analysis/speculative_workload_history.py --git-ref 5b130b6ec --expected-runs 10 --workload-seconds 180 --app tracee/monitor --start-run x86_kvm_corpus_20260813_101212_102293 --end-run x86_kvm_corpus_20260813_131003_298020 --passes context_specialize --metric stress-ng-bogo-ops
timeout 120s python3 analysis/speculative_workload_history.py --git-ref 5b130b6ec --expected-runs 10 --workload-seconds 180 --app bcc/set --start-run x86_kvm_corpus_20260813_134141_183681 --end-run x86_kvm_corpus_20260813_164950_279285 --passes context_specialize --metric stress-ng-bogo-ops
```

The root captures each stdout block and writes it verbatim to
`raw-results.md` using the repository's required patch workflow.  Each
invocation has a 120-second timeout.  This does not modify the benchmark
framework, workloads, launchers, pass policy, or raw results.  Accepted
positive Cilium/Katran rows populate a compact partial-RQ1 result table.
Tracee/BCC remain in the result review and parent research log.
