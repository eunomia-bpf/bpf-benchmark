# BUILD_AND_EVALUATE Step 0019 Report

Date: 2026-09-26
Experiment: repeat the fresh provenance-complete causality triplet for the
**sixth and last application** (otelcol-ebpf-profiler) to complete the
per-application x86 causality coverage, and to test whether the shared
methodology holds on a **composite** workload (five interpreter sha256 workers
plus one stress-ng cpu component) rather than the component-less stress-ng
shape the previous two apps used. otelcol `map_inline`.
Result: supported — the final KVM triplet yields a `PASS` renderer row binding a
derived 13-instance / 1,078-site rewrite to a control-corrected 1.079808x
throughput ratio, with every file SHA256-bound, the otelcol app path honored,
and the fresh corrected ratio sitting above 1.0 beside the May otelcol batch's
independent 0.9983.

## Source ownership and experiment selection

Step-0018 shipped BCC as the fifth thin wrapper and the third component-less
`metrc` app. otelcol-ebpf-profiler is the only remaining app whose May causality
batch reported a corrected ratio, so it is the natural closing arm. Its fresh
workload differs from every prior arm: it is **composite** (six components), so
the rate-shape question could not be assumed. A pre-run check against the
retained May otelcol app record
(`corpus/results/x86_kvm_corpus_20260522_050233_401368`) resolved it before the
runs: `_rate_scalar` returns `None` for all five language components (their
stderr is `<lang> sha256 ops=N elapsed_s=T`, matching no recognized shape) and
`119007.0` for the stress-ng component (its `stress-ng: metrc:` bogo-ops
column); the ratio computed from that single rate-bearing component is
`0.998394`, matching the May declared `0.9984`. otelcol therefore derives the
**same** metric as BCC/Tetragon/Tracee, via the stress-ng *component* rather
than the workload-level stdout — and the shared `_summed_pktgen_throughput`
already sums rate-bearing components first, so no extractor change was required.

No frozen artifact changed: no workload, app runner, `corpus/driver.py`,
benchmark Makefile, runtime-image wiring, stressor, worker count, packet
topology, or CPU-count/duration setting was touched. The only repo-side setting
is `runner/config/passes/**` policy, which the repository rule frees, and the
runs reuse the existing two-start load-time protocol verbatim.

Three KVM runs were launched through `make corpus` (the only entrypoint), one at
a time because the prerequisites are shared:

| role | run dir | policy | shape |
|---|---|---|---|
| MI | `x86_kvm_corpus_20260926_082957_279287` | `BPFREJIT_BENCH_PASSES=map_inline` | `SAMPLES=3`, 60 s |
| null A | `x86_kvm_corpus_20260926_084138_823558` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |
| null B | `x86_kvm_corpus_20260926_085249_602113` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |

The no-pass control again used `BPFREJIT_BENCH_PASSES=,` — the only value that
survives container environment forwarding (`runner/libs/suite_commands.py` drops
empty strings) and still expands to an empty pass list
(`runner/libs/rejit.py::_expand_groups` filters empty tokens). Both controls
confirm it: each recorded `config.enabled_passes == []` with
`rejit_result = {"mode": "loadtime", "status": "skipped"}`.

All three runs started after the step-0018 push, so the triplet's
`source_commit` is `b315c435f2afd54fa4db115cb0689f473f8754a8`.

## Valid result

Two independent derivations come out of the same triplet.

**Rewrite reconciliation.** The MI run's retained
`details/loadtime-reports/otelcol-ebpf-profiler__profiling.jsonl` holds 16 rows:
3 unchanged loads and **13 changed load instances** totalling **1,078 applied
sites**, instruction counts 53,346 → 24,566 (−28,780). All 13 changed workdirs
are retained; every retained `input.step.0.bin` / `output.next.0.bin` length
equals 8× the reported before/after instruction count, and every before/after
image pair differs (13/13, 0 missing, 0 length mismatches, 0 identical images).
Every value is computed by the renderer from the retained report stream and
bytecode at render time; none is transcribed.

**Throughput causality.** otelcol's fresh workload is composite, but only the
stress-ng component carries a rate the extractor recognizes (`stress-ng:
metrc:` bogo-ops); the five interpreter components match no shape. The shared
summed extractor reads that component scalar, sums the samples' rows, takes the
median over three samples per phase, and forms the post/baseline ratio.

| quantity | value |
|---|---|
| MI raw median ratio | 1.018833 |
| null A ratio | 1.022799 |
| null B ratio | 0.864265 |
| control median | 0.943532 |
| **control-corrected** | **1.079808** |

The declared constants are frozen at four decimal places (`raw 1.0188`,
`corrected 1.0798`); a drift degrades the row to `PARTIAL` rather than silently
re-baselining. The corrected ratio is above 1.0, while the May otelcol batch's
independent generation reports `0.9983` (below 1.0). The two generations sit on
opposite sides of 1.0, so the row claims the controlled measurement rather than
a speedup; the sign disagreement is reported plainly and the two are never
merged. The two controls are far apart (1.0228 / 0.8643) — markedly wider than
the BCC/Tracee controls — because otelcol's no-pass restarts drift more; the
control median subtracts that drift and the spread is reported verbatim.

The renderer emits **one** new row — `RQ2 otelcol fresh map_inline causality +
retained bytecode (1078 sites)` — reading `PASS`. The row set moves from 67 to
68 data rows. A full-row diff against the pre-edit renderer is exactly one added
line and zero changes to any pre-existing row text or status, including the
`PARTIAL` rows; `OVERALL AE EVIDENCE` remains `INCOMPLETE`. All six fresh
triplet rows now read `PASS` in one render.

`otelcol_fresh_causality_rows` is the sixth thin wrapper over the shared
`fresh_causality_rows`, differing only in `app_stem`, `report_rel`, `label`,
`evidence_dir`, `declared`, and `metric_noun="stress-ng metrc bogo-ops"`. An
otelcol triplet can be satisfied only by
`details/apps/otelcol-ebpf-profiler__profiling.json` and
`details/loadtime-reports/otelcol-ebpf-profiler__profiling.jsonl`.

`PASS` is gated on: the MI run's suite/app/rejit status and `samples`/
`workload_seconds`/`enabled_passes == ["map_inline"]` shape; the retained report
stream reconciling (at least one changed instance, every changed workdir
retaining bytecode whose lengths match and whose images differ); the receipt
hashing every retained file; both controls being `passes == []` loadtime skips
at the identical shape; and both derived ratios reproducing the frozen declared
constants. The self-test fixture drives the identical derivation over synthetic
matched runs and mutates each gate in turn — throughput drift, a control
carrying a pass, the MI run carrying the wrong pass, missing retained bytecode,
missing receipt hashes, a Cilium triplet with a Katran app record, a
component-less `metrc` Tetragon triplet, a Tracee triplet whose app record is
swapped for Tetragon's, a BCC triplet whose app record is swapped for Tracee's,
and (new) an otelcol triplet whose app record is swapped for BCC's — each flips
the row off `PASS`; restoring it returns
`self-test: OK (13 evidence classes)`. The count stays at 13 because otelcol
introduces no new derivation class: it reuses the same `metrc` scalar, so the
new case asserts only the app-path gate and the row's rate wording.

## Evidence packaging

The triplet is retained at
`docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality/` — 55 files
(54 hashed plus `receipt.json`): the MI `metadata.json`, normalized console log,
`details/{progress.json,result.json,apps/otelcol-ebpf-profiler__profiling.json,loadtime-plans/*,loadtime-reports/otelcol-ebpf-profiler__profiling.jsonl,loadtime-workdirs/*}`
for all 13 changed instances, and each control's `metadata.json`, console log,
and app record. `receipt.json` binds the command, control command, source
commit, source and control run dirs, `enabled_passes`/`control_enabled_passes`,
the derived counts, the throughput-causality block, and every retained file's
SHA256; `log_sha256` and the normalization rule are recorded. The MI console log
was sourced from the supervising job's `/workspaces/fresh-otelcol-logs/mi.log`,
since fresh `make corpus` run dirs contain only `metadata.json` and `details/`.

`docs/artifacts/package-atc26.sh` was extended minimally: representative entries
in `required=(…)` (receipt, log, report stream, one retained before-image, both
control metadata records), the otelcol triplet receipt/log/report in the
manifest `validationEvidence` list, and the README paragraph updated to six apps
with otelcol's 1,078-site rewrite. `bash -n` passes and every new `required`
entry exists on disk.

The builder was reused rather than duplicated: `/workspaces/build_fresh_evidence.py`
reads `EV_SLUG`/`EV_STEM`/`EV_APP`/`EV_OUT`/`EV_NOUN`/`EV_LOGDIR`/`EV_SRC_COMMIT`
from the environment, and it had already been regression-verified byte-identical
against the committed Tracee evidence tree. (The builder is a throwaway under
`/workspaces`, not shipped; the shipped renderer is the durable artifact.)

## Scientific boundary and next action

Latitude, stated plainly.

- This is a **single-application** (otelcol-ebpf-profiler), **single-pass**
  (`map_inline`) fresh measurement. It generalizes to no other app, pass, policy
  path, or architecture; the paper's declared site counts and the May otelcol
  ratios are a separate generation and are never merged with the fresh
  1,078-site figure or these ratios.
- The May otelcol corrected `0.9983` and this fresh `1.0798` are **two separate
  generations** and they disagree in sign; both are reported, neither is
  privileged over the other.
- The otelcol rate is a stress-ng **component** `bogo_ops` scalar, the same
  quantity the BCC/Tetragon/Tracee rows derive; the apps' corrected ratios are
  not cross-compared here. The wide control spread (1.0228/0.8643) is a
  restart-drift measure from a two-point control median, not a confidence
  interval.
- It is a **two-start load-time** experiment, so it establishes transparent
  loader interception, stock-verifier acceptance, and a measured throughput
  effect — not post-deployment re-specialization or phase-change recovery.
- `SAMPLES=3` at 60 s is within the framework's authoritative policy; the row
  invents no additional validity gate.

The shared builder now serves all six supported applications. Every app whose
May causality batch reported a corrected ratio has a matching fresh
provenance-complete triplet. The remaining natural axis is the same triplet
under a different pass (`wide_mem`, `const_prop`, `dce`) to test whether the
methodology distinguishes passes; it was not needed for this increment.

## Delivery

Two commits shipped and pushed to `origin/master`.

- `fb2508057` — "Add fresh provenance-complete otelcol map_inline causality
  evidence": the 55-file evidence dir, the `otelcol_fresh_causality_rows`
  wrapper with frozen declared constants, the extended self-test fixture, the
  `package-atc26.sh` `required`/`validationEvidence`/README additions, and the
  AE-doc evidence-table row plus twelfth-derivation narrative.
- the step-0019 report commit (this file).

After the content commit the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
