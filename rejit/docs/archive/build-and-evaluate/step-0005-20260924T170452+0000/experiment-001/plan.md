# Experiment 001 Plan: Audit Current Cilium `map_inline` Engagement

Date: 2026-09-24T17:04:52+00:00
Phase: BUILD_AND_EVALUATE
Selected paper question: RQ1, "Does Load-Time Specialization Work End to End?"
The tested uncertainty is narrower than the whole RQ: whether one retained,
current-protocol Cilium run proves that `map_inline` changed bytecode and that
the changed programs were accepted during real application startup, while
preserving the raw paired pktgen observation without over-interpreting one
sample.

## Paper-value admission

Step 0004 recovered repeated historical throughput differences, but those old
artifacts did not retain per-step optimizer reports.  This experiment addresses
that missing mechanism-engagement evidence using an already-completed KVM
artifact with reports, workdirs, verifier logs, shim logs, and raw workloads.
It does not consume the shared KVM while the ATC and kprog work continues.

The decisive uncertainty is whether the report totals can be joined to actual
bytecode files and successful `BPF_PROG_LOAD` events.  A positive result lets
the paper say that a real Cilium startup generated and successfully loaded
`map_inline` candidates before the application completed startup and its
workload, not merely that a plan was configured.  A successful load proves
stock verifier/JIT acceptance; this experiment does not separately prove that
each changed program was attached or executed.  A contradictory result blocks
the mechanism claim.  A mixed result must report successful and failed changed
loads separately.  This is supporting RQ1 evidence, not a replacement for a
repeated throughput batch and not proof that any observed throughput difference
was caused by a particular rewritten site.

The strongest alternative use of the experiment budget is a fresh repeated
Cilium `map_inline` KVM batch.  The retained artifact has higher immediate
information value because it can close the missing engagement/provenance link
without contending for KVM.  A later repeated batch remains necessary for a
current quantitative performance estimate.

## Hypothesis and competing explanation

The hypothesis is that the declared Cilium load-time plan produced non-identical
candidate bytecode at reported `map_inline` sites and every reported changed
load was subsequently accepted by the stock verifier/JIT path during the real
application start.  The competing explanation is that report counters were
generated without matching bytecode outputs, or that candidates were rejected
or never paired with a successful load event.  A successful load is not called
deployment, attachment, or execution in the result or paper.

The paired pktgen phases are retained as a descriptive observation from the
same artifact.  With `SAMPLES=1`, they carry no repeated-run uncertainty claim.
They are not combined with, compared causally against, or used to validate the
July historical batch from step 0004.

## Input and declared measurements

The sole input is a local result directory rather than a Git-tracked or public
artifact.  Its core JSON/report/provenance files are untracked, while its shim
logs and workdirs are ignored:

`corpus/results/x86_kvm_corpus_20260919_041801_813418`

Its provenance records source revision
`38476c24f6caf50b64956c4b44e80f464096dc78` and the Make-backed command in
`provenance/start.json`.  The report preserves that revision, command, exact
relative path, and an ordinary inventory of core-file sizes and mtimes plus
workdir file counts/bytes.  Publication of the raw directory remains an
explicit backlog item and is not an experiment gate; the paper must not call
the local path a public artifact before publication.  The audit must validate
rather than assume:

- completed corpus metadata, x86 KVM run type, `SAMPLES=1`, 30-second workload,
  and exact enabled pass list `map_inline`;
- Cilium application status `ok`, empty application error, and an exact
  one-step Cilium load-time plan named `map_inline`;
- every nonblank JSONL report row parses, names `map_inline` at step zero, has
  internally consistent matched/applied/skipped and instruction counts, and
  matches its retained `report.0.json`;
- every changed row has `input.bin` and `output.next.0.bin`, both aligned to
  eight-byte BPF instructions, with lengths matching reported before/after
  counts and non-identical contents;
- changed reports and `loadtime optimized` shim events form a strict bijection
  by exact workdir, including matching program name and before/after instruction
  counts; each optimized event is then paired by PID/TID with exactly one
  following `PROG_LOAD` result before another optimized event for that PID/TID;
  successful and failed changed loads, unmatched events, original-preflight
  pass-throughs, and other candidate errors are printed separately;
- both workload phases contain exactly the forward and reverse kernel-pktgen
  leaves, zero return-code failures, a completed `Result: OK` line, and raw
  packet count, pps, and error count.

Report totals are raw engagement counts: report rows, changed load instances,
matched/applied/skipped sites, and aggregate before/after instruction counts
over changed load instances.  Program-name/type rows are printed without
deduplicating repeated application loads.  Workload output includes both raw
component pps values, their phase sums, and the single paired policy/baseline
ratio; the ratio is descriptive only.

At least one changed report and at least one applied site are required for a
supported outcome.  The predeclared outcome classification is:

- **supported:** the changed set is nonempty, the report/event bijection is
  complete, and every changed candidate load succeeds;
- **mixed:** the bijection is complete and changed candidates include at least
  one successful and at least one failed load;
- **contradicted:** the evidence is structurally complete but there is no
  changed report/applied site, or a nonempty changed set has no successful load;
- **invalid/inconclusive:** required reports/files/logs are missing, internally
  inconsistent, or cannot be paired uniquely, so the mechanism outcome cannot
  be determined.

Original-bytecode preflight pass-throughs are analysis caveats, not candidate
failures and not a new validity gate.  They do not erase successful changed-load
evidence.  Supported, mixed, and contradicted are valid scientific outcomes and
the tool exits zero after printing their full evidence.  It exits nonzero only
for invalid/inconclusive inputs, contract or parsing errors, or the deliberate
wrong-parameter test.

## Execution and completion rule

Exploratory discovery used the existing summary script and inspected one
changed report before this plan.  Those readings are not the formal result.
After plan approval, the real preflight uses the new analysis-only tool and the
same complete evidence path as the formal audit:

```sh
timeout 120s python3 analysis/audit_loadtime_evidence.py \
  corpus/results/x86_kvm_corpus_20260919_041801_813418 \
  --app cilium/agent --expected-pass map_inline \
  --expected-samples 1 --expected-workload-seconds 30
```

After the preflight succeeds, the root repeats that exact command as the formal
full run and preserves both outputs so deterministic agreement is visible.  A
deliberate parameter-negative test is then run as:

```sh
timeout 120s python3 analysis/audit_loadtime_evidence.py \
  corpus/results/x86_kvm_corpus_20260919_041801_813418 \
  --app cilium/agent --expected-pass const_prop \
  --expected-samples 1 --expected-workload-seconds 30
```

It must exit nonzero and identify the enabled-pass mismatch on stderr.  The
formal experiment is complete when the full command finishes, its stdout is
preserved in `raw-results.md`, the negative-test status and stderr are
preserved, and an independent reviewer recomputes report/file/load/workload
totals directly from the artifact without importing the new analyzer.

The experiment does not modify benchmark workloads, application code, runner
code, launch wiring, Makefiles, pass policy, or the raw artifact.  If accepted,
the paper receives a narrowly worded candidate-generation and
stock-verifier/JIT-acceptance paragraph adjacent to the historical throughput
table, with the source revision and local artifact path and an explicit
separation from the historical repeated-run evidence.  It must also state that
per-program attachment/execution was not separately established and that
raw-artifact publication is pending.
