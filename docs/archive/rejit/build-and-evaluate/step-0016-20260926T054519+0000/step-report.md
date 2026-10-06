# BUILD_AND_EVALUATE Step 0016 Report

Date: 2026-09-26
Experiment: repeat the fresh provenance-complete causality triplet for a
**third application**, chosen because its workload has a different *shape* — a
single component-less stress-ng run — so it exercises the throughput
extractor's workload-level fallback rather than a pktgen component sum.
Tetragon `map_inline`.
Result: supported — a third KVM triplet yields a `PASS` renderer row binding a
derived 126-instance / 148-site rewrite to a control-corrected 1.0357x
throughput ratio, with every file SHA256-bound, the Tetragon app path honored,
and the shared extractor confirmed on a new workload shape

## Source ownership and experiment selection

Steps 0014 and 0015 shipped fresh-causality triplets for Katran (kernel-pktgen
pps) and Cilium (two kernel-pktgen components), both handled by the same summed
component extractor. A third application was the highest-value next experiment
for one reason: the remaining candidate apps do not use pktgen at all. Tetragon,
tracee, and bcc drive a **single stress-ng run with no `components`**, emitting
their rate in the workload's own `stdout` as
`stress-ng: metrc: <pid> <stressor> <bogo_ops> ... <bogo_ops/s>` lines. If the
shared extractor were pktgen-only, the row would degrade to `UNAVAILABLE`; if it
handles the workload-level fallback, that is proven only by running it.
Tetragon was chosen over tracee/bcc because it is the smallest of the three
candidate populations and it already has a May causality row (`1.0840`), giving
an independent sign check.

No frozen artifact changed: no workload, app runner, `corpus/driver.py`,
benchmark Makefile, runtime-image wiring, stressor, worker count, packet
topology, or CPU-count/duration setting was touched. The only repo-side setting
is `runner/config/passes/**` policy, which the repository rule frees, and the
runs reuse the existing two-start load-time protocol verbatim.

Three KVM runs were launched through `make corpus` (the only entrypoint), one at
a time because the prerequisites are shared:

| role | run dir | policy | shape |
|---|---|---|---|
| MI | `x86_kvm_corpus_20260926_050153_382346` | `BPFREJIT_BENCH_PASSES=map_inline` | `SAMPLES=3`, 60 s |
| null A | `x86_kvm_corpus_20260926_051151_192774` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |
| null B | `x86_kvm_corpus_20260926_052116_597549` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |

The no-pass control again used `BPFREJIT_BENCH_PASSES=,` — the only value that
survives container environment forwarding (`runner/libs/suite_commands.py` drops
empty strings) and still expands to an empty pass list
(`runner/libs/rejit.py::_expand_groups` filters empty tokens). Both controls
confirm it: each recorded `config.enabled_passes == []` with
`rejit_result = {"mode": "loadtime", "status": "skipped"}`.

## Valid result

Two independent derivations come out of the same triplet.

**Rewrite reconciliation.** The MI run's retained
`details/loadtime-reports/tetragon__observer.jsonl` holds 228 rows: 102
unchanged loads and **126 changed load instances** totalling **148 applied
sites**, instruction counts 251,439 → 236,490 (−14,949). All 126 changed
workdirs are retained; every retained `input.step.0.bin` / `output.next.0.bin`
length equals 8× the reported before/after instruction count, and every
before/after image pair differs (126/126, 0 missing, 0 length mismatches, 0
identical images). Every value is computed by the renderer from the retained
report stream and bytecode at render time; none is transcribed.

**Throughput causality.** Tetragon's fresh workload is a single stress-ng
invocation with **no `components`**, so the pktgen component sum finds nothing.
The extractor's workload-level fallback (`_rate_scalar` on the workload's own
`stdout`) then reads the `stress-ng: metrc:` bogo-ops column, sums the samples'
rows, takes the median over three samples per phase, and forms the
post/baseline ratio. Byte-exact parity was confirmed against the builder's
independent `rate_scalar`/`summed` on the May tetragon runs before the fresh
runs were accepted.

| quantity | value |
|---|---|
| MI raw median ratio | 1.042310 |
| null A ratio | 0.997730 |
| null B ratio | 1.014964 |
| control median | 1.006347 |
| **control-corrected** | **1.035737** |

The declared constants are frozen at four decimal places (`raw 1.0423`,
`corrected 1.0357`); a drift degrades the row to `PARTIAL` rather than silently
re-baselining. The corrected ratio is above 1.0, and its sign **agrees with the
May Tetragon batch's independent `1.0840`** (also above 1.0). Two generations
taken months apart landing on the same sign for the same app is reported as
corroboration, not as a merged measurement.

The renderer emits **one** new row — `RQ2 Tetragon fresh map_inline causality +
retained bytecode (148 sites)` — reading `PASS`. The row set moves from 64 to 65
data rows. A full-row diff against the pre-edit renderer is exactly one added
line and zero changes to any pre-existing row text or status, including the five
`PARTIAL` rows; `OVERALL AE EVIDENCE` remains `INCOMPLETE`. The Katran and
Cilium rows are byte-identical, which confirms the new `metric_noun` parameter
defaults to the original `summed-pktgen` wording for those two apps.

The generalization was extended rather than duplicated: `fresh_causality_rows`
gained a keyword-only `metric_noun` (default `"summed-pktgen"`, so Katran and
Cilium wording is unchanged), and `tetragon_fresh_causality_rows` is the third
thin wrapper, differing only in `app_stem`, `report_rel`, `label`, `evidence_dir`,
`declared`, and `metric_noun="stress-ng metrc bogo-ops"`. A Tetragon triplet can
be satisfied only by `details/apps/tetragon__observer.json` and
`details/loadtime-reports/tetragon__observer.jsonl`.

`PASS` is gated on: the MI run's suite/app/rejit status and `samples`/
`workload_seconds`/`enabled_passes == ["map_inline"]` shape; the retained report
stream reconciling (at least one changed instance, every changed workdir
retaining bytecode whose lengths match and whose images differ); the receipt
hashing every retained file; both controls being `passes == []` loadtime skips
at the identical shape; and both derived ratios reproducing the frozen declared
constants. The self-test fixture drives the identical derivation over synthetic
matched runs and mutates each gate in turn — throughput drift, a control
carrying a pass, the MI run carrying the wrong pass, missing retained bytecode,
missing receipt hashes, a Cilium triplet with a Katran app record, and (new) a
**component-less `metrc`-shaped** Tetragon triplet — each flips the row off
`PASS`; restoring it returns `self-test: OK (13 evidence classes)`. The new
fixture case is the one that matters: it emits a workload with an empty
`components` list and the rate only in its `stdout`, so a pktgen-component-only
extractor would fail it.

## Evidence packaging

The triplet is retained at
`docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality/` — 394 files
(393 hashed plus `receipt.json`): the MI `metadata.json`, normalized console
log, `details/{progress.json,result.json,apps/tetragon__observer.json,loadtime-plans/tetragon__observer.json,loadtime-reports/tetragon__observer.jsonl,shim-logs/*,loadtime-workdirs/*}`
for all 126 changed instances, and each control's `metadata.json`, console log,
and app record. `receipt.json` binds the command, control command, source
commit, source and control run dirs, `enabled_passes`/`control_enabled_passes`,
the derived counts, the throughput causality block, and every retained file's
SHA256; `log_sha256` and the normalization rule are recorded. The MI console log
was sourced from the supervising job's `/tmp/fresh-tetragon/mi.log`, since fresh
`make corpus` run dirs contain only `metadata.json` and `details/`.

`docs/artifacts/package-atc26.sh` was extended minimally: representative entries
in `required=(…)` (receipt, log, report stream, one retained before-image, both
control metadata records), the Tetragon triplet receipt/log/report in the
manifest `validationEvidence` list, and one additive README paragraph naming the
third app and its 148-site rewrite. `bash -n` passes and every new `required`
entry exists on disk.

## Scientific boundary and next action

Latitude, stated plainly.

- This is a **single-application** (Tetragon), **single-pass** (`map_inline`)
  fresh measurement. It generalizes to no other app, pass, policy path, or
  architecture; the paper's declared site counts and the May tetragon ratios are
  a separate generation and are never merged with the fresh 148-site figure or
  these ratios.
- The May Tetragon corrected `1.0840` and this fresh `1.0357` are **two separate
  generations**; their agreement in sign is reported as corroboration, not as a
  single merged measurement.
- It is a **two-start load-time** experiment, so it establishes transparent
  loader interception, stock-verifier acceptance, and a measured throughput
  effect — not post-deployment re-specialization or phase-change recovery.
- The control-corrected ratio is a *median-of-ratios* correction with two
  controls; it measures drift magnitude, but a two-point control median is not a
  confidence interval. No CI is asserted and the 1.0357x is not a paper-grade
  claim.
- The Tetragon rate scalar is a stress-ng `bogo_ops` workload-level column, a
  different quantity from the pktgen pps the Katran and Cilium rows derive. The
  row names the metric it actually derived (`stress-ng metrc bogo-ops`); a
  cross-app comparison of the three corrected ratios compares three different
  workload-rate scalars and is not asserted here.
- `SAMPLES=3` at 60 s is within the framework's authoritative policy; the row
  invents no additional validity gate (no matched no-op arm beyond the requested
  controls, no zero-drop assertion, no idle-CPU or `run_cnt` threshold).

The shared `fresh_causality_rows` now serves three apps across two workload
shapes, and a fourth triplet is cheap: tracee and bcc use the same
component-less `metrc` shape proven here, while `otelcol`'s mixed workload would
need its rate-emitting component confirmed first. A different pass (`wide_mem`,
`const_prop`, `dce`) is the alternative axis. Neither was needed for this
increment.

## Delivery

Two commits shipped and pushed to `origin/master`.

- `c4a184d15` — "Add fresh provenance-complete Tetragon map_inline causality
  evidence": the 394-file evidence dir, the `metric_noun` generalization with
  the `tetragon_fresh_causality_rows` wrapper and frozen declared constants, the
  extended self-test fixture, the `package-atc26.sh` staging/`required`/README
  additions, and the AE-doc evidence-table row plus ninth-derivation narrative.
- the step-0016 report commit (this file).

After the content commit the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
