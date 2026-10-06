# BUILD_AND_EVALUATE Step 0014 Report

Date: 2026-09-26
Experiment: answer whether a **fresh, provenance-complete** run can carry both
the per-pass throughput-causality ratio *and* the applied-site count in a single
experiment, for Katran `map_inline`
Result: supported — one KVM triplet (one optimized run, two matched no-pass
controls) yields a `PASS` renderer row binding the derived 16-site rewrite to a
control-corrected 1.0754x throughput ratio, with every file SHA256-bound

## Source ownership and experiment selection

Step-0013 closed the causality question from the *tracked historical* May batch,
but that batch has two provenance defects that its own report stated: it retains
no per-step bytecode, and it was recorded before the `metadata.command` format,
so it produces no `receipt.json`. It therefore answers "is the pass's own effect
separable from restart drift" and nothing about *which* bytecode changed. The
paper's boundary sentence named exactly that split: the fresh retained-bytecode
runs prove the rewrite, the May batch proves causality, and no single artifact
held both.

The follow-up step-0013 itself named was a fresh, provenance-complete causality
run that also retains loadtime artifacts, so one experiment carries both. That
is this step. No frozen artifact changed: no workload, app runner,
`corpus/driver.py`, benchmark Makefile, runtime-image wiring, stressor, worker
count, packet topology, or CPU/duration setting was touched. The only
repo-side setting is `runner/config/passes/**` policy, which the repository rule
frees, and the run reuses the existing two-start load-time protocol verbatim.

Three KVM runs were launched through `make corpus` (the only entrypoint), one at
a time because the prerequisites are shared:

| role | run dir | policy | shape |
|---|---|---|---|
| MI | `x86_kvm_corpus_20260926_005057_618064` | `BPFREJIT_BENCH_PASSES=map_inline` | `SAMPLES=3`, 60 s |
| null A | `x86_kvm_corpus_20260926_010023_572333` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |
| null B | `x86_kvm_corpus_20260926_010936_702976` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |

The no-pass control needed a value that survives the container environment
forwarding (`runner/libs/suite_commands.py` drops empty strings) *and* still
expands to an empty pass list (`runner/libs/rejit.py::_expand_groups` filters
empty tokens): `BPFREJIT_BENCH_PASSES=,` is the only such value, and the two
controls confirm it — each recorded `config.enabled_passes == []` with
`rejit_result = {"mode": "loadtime", "status": "skipped"}`.

## Valid result

Two independent derivations come out of the same triplet.

**Rewrite reconciliation.** The MI run's retained
`details/loadtime-reports/katran.jsonl` holds 6 rows: 5 unchanged socket-filter
loads (2/2/2/4/2 instructions, 0 sites) and **1 changed load instance** —
`balancer_ingress`, XDP, **16 applied sites**, instruction counts 2,554 → 2,284
(−270). The changed workdir `loadtime_3080_5` is retained: its
`input.step.0.bin` is 8×2,542 bytes and its `output.next.0.bin` is 8×2,272
bytes, so the raw `struct bpf_insn` lengths match the reported counts and the
two images differ. Every one of these values is computed by the renderer from
the retained report stream and bytecode at render time; none is transcribed.

**Throughput causality.** The fresh kernel-pktgen workload splits each phase
into four nondeterministically ordered components, so a first-rate-bearing-
component extractor (the May path's `workload_throughput`) would sample one
quarter. The fresh derivation sums every component's pktgen pps per workload,
takes the median over the three samples per phase, and forms the post/baseline
ratio:

| quantity | value |
|---|---|
| MI raw median ratio | 1.075146 |
| null A ratio | 1.002921 |
| null B ratio | 0.996561 |
| control median | 0.999741 |
| **control-corrected** | **1.075425** |

The two controls bracket 1.000 within 0.03%, so the restart drift this triplet
carries is small and the correction is a genuine subtraction rather than a
large rescaling. The declared constants are frozen at four decimal places
(`raw 1.0751`, `corrected 1.0754`); a drift degrades the row to `PARTIAL`
rather than silently re-baselining.

The renderer emits **one** new row — `RQ2 Katran fresh map_inline causality +
retained bytecode (16 sites)` — reading `PASS`. The row set moves from 62 to 63
data rows. All 62 pre-existing row labels and their statuses are byte-identical
to the pre-edit dump (verified by rendering HEAD's renderer and diffing full row
text), including the five `PARTIAL` rows, and `OVERALL AE EVIDENCE` remains
`INCOMPLETE`.

`PASS` is gated on: the MI run's suite/app/rejit status and `samples`/
`workload_seconds`/`enabled_passes == ["map_inline"]` shape; the retained report
stream reconciling (at least one changed instance, every changed workdir
retaining bytecode whose lengths match and whose images differ); the receipt
hashing every retained file; both controls being `passes == []` loadtime skips
at the identical shape; and both derived ratios reproducing the frozen declared
constants. The self-test fixture drives the identical derivation over synthetic
matched runs and mutates each gate in turn: throughput drift, a control carrying
a pass, the MI run carrying the wrong pass, missing retained bytecode, and
missing receipt hashes each flip the row off `PASS`; restoring it returns
`self-test: OK (12 evidence classes)`.

## Evidence packaging

The triplet is retained at
`docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality/` — 19 files (18
hashed plus `receipt.json`): the MI `metadata.json`, normalized console log,
`details/{progress.json,result.json,apps/katran.json,loadtime-plans/katran.json,loadtime-reports/katran.jsonl,shim-logs/*,loadtime-workdirs/loadtime_3080_5/*}`,
and each control's `metadata.json`, console log, and app record. `receipt.json`
binds the command, control command, source commit, source and control run dirs,
`enabled_passes`/`control_enabled_passes`, the derived counts, the throughput
causality block, and every retained file's SHA256; `log_sha256` and the
normalization rule are recorded, and the log is verified to contain
`BPFREJIT_BENCH_PASSES="map_inline"` (MI) and `BPFREJIT_BENCH_PASSES=","` with
`SKIP_REJIT="norejit"` (both controls). The controls were launched with
`SKIP_REJIT=norejit` so the no-pass policy is explicit rather than implied.

`docs/artifacts/package-atc26.sh` was extended minimally: representative
entries in `required=(…)` (receipt, log, report stream, one retained
before-image, both control metadata records) and one additive README paragraph.
`bash -n` passes and every new `required` entry exists on disk.

## Scientific boundary and next action

Latitude, stated plainly.

- This is a **single-application** (Katran), **single-pass** (`map_inline`)
  fresh measurement. It generalizes to no other app, pass, policy path, or
  architecture; the paper's declared Katran 21/62 site figures and its June
  ratios are a separate generation and are never merged with the fresh 16-site
  figure or these ratios.
- It is a **two-start load-time** experiment, so it establishes transparent
  loader interception, stock-verifier acceptance, and a measured throughput
  effect — not post-deployment re-specialization or phase-change recovery.
- The control-corrected ratio is a *median-of-ratios* correction with two
  controls; it measures drift magnitude, but a two-point control median is not
  a confidence interval. The 1.0754x is the declared value of this triplet, not
  a paper-grade speedup claim, and no CI is asserted.
- `SAMPLES=3` at 60 s is within the framework's authoritative policy; the row
  does not invent any additional validity gate (no matched no-op arm beyond the
  requested controls, no zero-drop assertion, no idle-CPU or `run_cnt`
  threshold).

With causality now available in a single provenance-complete artifact for
Katran, the next runnable questions are (a) the same fresh triplet for a second
application to test whether the corrected effect is app-specific, or (b) the
same triplet under a different pass, to test whether the methodology
distinguishes passes. Neither was needed for this increment.

## Delivery

Two commits shipped and pushed to `origin/master`.

- `5fde1455d` — "Add fresh provenance-complete Katran map_inline causality
  evidence": the 19-file evidence dir, the summed-pktgen extractor and
  `katran_fresh_causality_rows` renderer row with frozen declared constants and
  the self-test fixture, the `package-atc26.sh` staging/`required`/README
  additions, and additive AE-doc narrative plus the evidence-table row.
- the step-0014 report commit (this file).

After the content commit the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
