# Experiment 001 Plan: Audit Katran `map_inline` Opportunity Stability

Date: 2026-09-25T01:53:37+00:00
Phase: BUILD_AND_EVALUATE
Selected paper question: RQ2, "When Do Runtime Side Inputs Add Value?"

This experiment asks one narrower question: did two completed, current-protocol
Katran application starts expose the same phase-stable `map_inline` entry
multiset in the same XDP program, despite being collected on different days?
It does not ask whether `map_inline` caused either run's throughput change.

## Paper-value admission

Katran has the strongest reconstructed repeated throughput difference in the
paper (`1.091x` for ten historical `map_inline` runs), but those committed
artifacts lack per-step reports.  Two newer local Katran artifacts retain
per-step reports and logs.  Establishing whether their runtime map-entry
opportunities agree is the highest-value analysis that does not execute the
AE supervisor's uncommitted optimizer source or consume KVM.  Agreement would
select Katran as the next clean, retained, single-pass causal experiment;
disagreement would show that a fixed phase-stable policy cannot be interpreted
without additional state controls.

This is not provenance-only work: the decisive inputs are the raw embedded
`map_inline` reports produced while the real Katran loader created and loaded
`balancer_ingres`.  The result changes the next paper experiment and the
strength of RQ2's stability premise.  It does not close RQ2 by itself.

The two inputs are the complete local artifacts:

- `corpus/results/x86_kvm_corpus_20260919_225748_512435`
- `corpus/results/x86_kvm_corpus_20260922_213414_889964`

They were selected before analysis because they are the two completed local
Katran runs that retain both a `map_inline` JSONL report stream and the
post-policy shim log.  No run is selected or removed based on its workload
ratio or on whether the stability hypothesis holds.

## Hypothesis and competing explanation

The hypothesis is that both artifacts load the same raw Katran XDP program and
their one changed `map_inline` report contains an identical multiset of
`(key_hex, value_hex, stability)` entries with the same applied-site count.
Runtime `map_id` values are printed but excluded from cross-run identity because
kernel object IDs are ephemeral.  The competing explanation is that the
deployment snapshot or selected entries differ across application starts.

Each artifact used the eleven-pass default policy, not a one-pass
`map_inline` policy.  Instruction counts entering `map_inline` may therefore
reflect earlier passes.  A final successful `BPF_PROG_LOAD` shows acceptance of
the whole composed candidate, not acceptance attributable to `map_inline`
alone.  The artifacts retain no actual per-step before/after bytecode and were
collected on different dates.  No instruction-count difference, workload
difference, or cross-run difference will be interpreted causally.

## Declared measurements and classifications

An analysis-only tool will validate, for each artifact:

- completed x86 KVM corpus metadata, `SAMPLES=1`, 10-second workload, and the
  exact eleven-pass default policy;
- Katran application status `ok`, empty error, and a load-time plan whose step
  names equal the metadata pass list;
- every JSONL row is parseable and internally consistent for matched, applied,
  skipped, and instruction counts;
- exactly one `map_inline` row has applied sites, it names XDP program
  `balancer_ingres`, and its inlined-entry count equals its applied-site count;
- every inlined entry has integer `map_id` plus hexadecimal key/value and
  `stability == phase-stable`;
- the shim log's `BPF_PROG_LOAD` record for that program has the same raw
  program hash in both runs; and
- the final whole-plan optimized event for that workdir is followed on the same
  PID/TID by a successful stock `PROG_LOAD`.

The output prints raw per-artifact program hashes, pass input/output instruction
counts, applied sites, entry multisets including occurrence counts and runtime
map IDs, and whole-plan load results.  It does not parse or aggregate workload
throughput because performance is outside this stability question.

The predeclared result is:

- **supported:** both structurally valid artifacts have the same raw program
  hash, applied-site count, and normalized entry multiset;
- **contradicted:** both artifacts are structurally valid but at least one of
  those three quantities differs;
- **invalid/inconclusive:** either artifact is missing required raw evidence,
  violates its declared protocol, has inconsistent reports, or cannot pair its
  changed program with a unique successful whole-plan load.

Supported and contradicted are both valid results and exit zero.  Invalid input
exits nonzero.  The report will always preserve the multi-pass, missing-bytecode,
different-day, and whole-plan-load limitations.

## Execution and completion

After plan review, the real preflight and formal run use the same two full
artifacts.  The preflight is:

```sh
timeout 120s python3 analysis/audit_katran_map_inline_stability.py \
  corpus/results/x86_kvm_corpus_20260919_225748_512435 \
  corpus/results/x86_kvm_corpus_20260922_213414_889964
```

After it succeeds, the root repeats the command as the formal run and retains
both outputs.  A negative parameter test substitutes the completed Cilium
artifact `corpus/results/x86_kvm_corpus_20260924_055034_080806`; it must exit
nonzero and report that the application is not Katran or its required Katran
evidence is absent.

An independent result reviewer must recompute the raw program hash, changed
row count, applied sites, normalized entry multiset, and load result directly
from both artifacts without importing the new analyzer.  Completion requires
the analyzer, preflight, formal output, negative test, and review.  A supported
result updates the parent evaluation record as an internal RQ2 stability
result and makes a clean Katran `map_inline`, `KEEP_WORKDIRS=1`, `SAMPLES=3`,
30-second Make-backed run the next experiment.  It does not enter the paper's
throughput table.  The paper changes only after a retained single-pass artifact
supports a reader-facing claim.

This experiment modifies no workload, application, runner, Makefile, runtime
image, pass policy, or raw artifact.
