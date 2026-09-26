# BUILD_AND_EVALUATE Step 0018 Report

Date: 2026-09-26
Experiment: repeat the fresh provenance-complete causality triplet for a
**fifth application** (BCC) to test whether the shared methodology holds on a
third independent app of the component-less stress-ng shape, and to close the
last x86 causality app that the May batch already covers before otelcol. BCC
`map_inline`.
Result: supported — a fifth KVM triplet yields a `PASS` renderer row binding a
derived 19-instance / 83-site rewrite to a control-corrected 1.0075x throughput
ratio, with every file SHA256-bound, the BCC app path honored, and the fresh
corrected ratio sitting within restart drift of neutral beside the May BCC
batch's independent 0.7921.

## Source ownership and experiment selection

Step-0017 shipped Tracee as the fourth thin wrapper and the second component-less
`metrc` app. BCC is the natural next arm: its fresh workload is the identical
component-less shape (confirmed from a retained BCC app record before the runs —
its workload has `components: []` and its rate is the `stress-ng: metrc:`
bogo-ops column), and the May BCC batch already reports an independent corrected
`0.7921`. BCC also exercises a much deeper rewrite than Tracee or Tetragon — 19
changed load instances rather than a dozen — so it is the strongest test yet of
the bytecode-retention path at scale on this shape.

No frozen artifact changed: no workload, app runner, `corpus/driver.py`,
benchmark Makefile, runtime-image wiring, stressor, worker count, packet
topology, or CPU-count/duration setting was touched. The only repo-side setting
is `runner/config/passes/**` policy, which the repository rule frees, and the
runs reuse the existing two-start load-time protocol verbatim.

Three KVM runs were launched through `make corpus` (the only entrypoint), one at
a time because the prerequisites are shared:

| role | run dir | policy | shape |
|---|---|---|---|
| MI | `x86_kvm_corpus_20260926_070636_267511` | `BPFREJIT_BENCH_PASSES=map_inline` | `SAMPLES=3`, 60 s |
| null A | `x86_kvm_corpus_20260926_071903_072417` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |
| null B | `x86_kvm_corpus_20260926_073026_776920` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |

The no-pass control again used `BPFREJIT_BENCH_PASSES=,` — the only value that
survives container environment forwarding (`runner/libs/suite_commands.py` drops
empty strings) and still expands to an empty pass list
(`runner/libs/rejit.py::_expand_groups` filters empty tokens). Both controls
confirm it: each recorded `config.enabled_passes == []` with
`rejit_result = {"mode": "loadtime", "status": "skipped"}`.

All three runs started after the step-0017 push, so the triplet's
`source_commit` is `e7dbc26ccceca2fd526ad9203acfd9ee764d1d7a`.

## Valid result

Two independent derivations come out of the same triplet.

**Rewrite reconciliation.** The MI run's retained
`details/loadtime-reports/bcc__set.jsonl` holds 77 rows: 58 unchanged loads and
**19 changed load instances** totalling **83 applied sites**, instruction counts
2,263 → 1,530 (−733). All 19 changed workdirs are retained; every retained
`input.step.0.bin` / `output.next.0.bin` length equals 8× the reported
before/after instruction count, and every before/after image pair differs
(19/19, 0 missing, 0 length mismatches, 0 identical images). Every value is
computed by the renderer from the retained report stream and bytecode at render
time; none is transcribed.

**Throughput causality.** BCC's fresh workload is a single stress-ng invocation
with **no `components`**, so the workload-level fallback reads the
`stress-ng: metrc:` bogo-ops column, sums the samples' rows, takes the median
over three samples per phase, and forms the post/baseline ratio. Extractor parity
was confirmed against a retained BCC app record before the runs were accepted.

| quantity | value |
|---|---|
| MI raw median ratio | 1.010702 |
| null A ratio | 0.999475 |
| null B ratio | 1.006825 |
| control median | 1.003150 |
| **control-corrected** | **1.007528** |

The declared constants are frozen at four decimal places (`raw 1.0107`,
`corrected 1.0075`); a drift degrades the row to `PARTIAL` rather than silently
re-baselining. The corrected ratio is only just above 1.0 — within restart drift
of neutral — while the May BCC batch's independent generation reports `0.7921`
(below 1.0). The two generations sit on opposite sides of 1.0, so the row claims
the controlled measurement rather than a speedup; the sign disagreement is
reported plainly and the two are never merged.

The renderer emits **one** new row — `RQ2 BCC fresh map_inline causality +
retained bytecode (83 sites)` — reading `PASS`. The row set moves from 66 to 67
data rows. A full-row diff against the pre-edit renderer is exactly one added
line and zero changes to any pre-existing row text or status, including the
`PARTIAL` rows; `OVERALL AE EVIDENCE` remains `INCOMPLETE`.

`bcc_fresh_causality_rows` is the fifth thin wrapper over the shared
`fresh_causality_rows`, differing only in `app_stem`, `report_rel`, `label`,
`evidence_dir`, `declared`, and `metric_noun="stress-ng metrc bogo-ops"`. A BCC
triplet can be satisfied only by `details/apps/bcc__set.json` and
`details/loadtime-reports/bcc__set.jsonl`.

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
swapped for Tetragon's, and (new) a BCC triplet whose app record is swapped for
Tracee's — each flips the row off `PASS`; restoring it returns
`self-test: OK (13 evidence classes)`. The count stays at 13 because BCC
introduces no new derivation class: it reuses the same component-less `metrc`
shape, so the new case asserts only the app-path gate and the row's rate
wording.

## Evidence packaging

The triplet is retained at
`docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality/` — 73 files
(72 hashed plus `receipt.json`): the MI `metadata.json`, normalized console log,
`details/{progress.json,result.json,apps/bcc__set.json,loadtime-plans/bcc__set.json,loadtime-reports/bcc__set.jsonl,shim-logs/*,loadtime-workdirs/*}`
for all 19 changed instances, and each control's `metadata.json`, console log,
and app record. `receipt.json` binds the command, control command, source
commit, source and control run dirs, `enabled_passes`/`control_enabled_passes`,
the derived counts, the throughput causality block, and every retained file's
SHA256; `log_sha256` and the normalization rule are recorded. The MI console log
was sourced from the supervising job's `/workspaces/fresh-bcc-logs/mi.log`, since
fresh `make corpus` run dirs contain only `metadata.json` and `details/`.

`docs/artifacts/package-atc26.sh` was extended minimally: representative entries
in `required=(…)` (receipt, log, report stream, one retained before-image, both
control metadata records), the BCC triplet receipt/log/report in the manifest
`validationEvidence` list, and the README paragraph updated to five apps with
BCC's 83-site rewrite. `bash -n` passes and every new `required` entry exists on
disk.

The builder was reused rather than duplicated: `/workspaces/build_fresh_evidence.py`
reads `EV_SLUG`/`EV_STEM`/`EV_APP`/`EV_OUT`/`EV_NOUN`/`EV_LOGDIR`/`EV_SRC_COMMIT`
from the environment, and a regression rebuild of the Tracee triplet reproduced
the committed evidence tree byte-for-byte (`diff -r` identical) before this
triplet was built. (The builder is a throwaway under `/workspaces`, not shipped;
the shipped renderer is the durable artifact.)

## Scientific boundary and next action

Latitude, stated plainly.

- This is a **single-application** (BCC), **single-pass** (`map_inline`) fresh
  measurement. It generalizes to no other app, pass, policy path, or
  architecture; the paper's declared site counts and the May BCC ratios are a
  separate generation and are never merged with the fresh 83-site figure or
  these ratios.
- The May BCC corrected `0.7921` and this fresh `1.0075` are **two separate
  generations** and they disagree in sign; both are reported, neither is
  privilege over the other.
- It is a **two-start load-time** experiment, so it establishes transparent
  loader interception, stock-verifier acceptance, and a measured throughput
  effect — not post-deployment re-specialization or phase-change recovery.
- The control-corrected ratio is a *median-of-ratios* correction with two
  controls; a two-point control median is not a confidence interval. No CI is
  asserted and the 1.0075x is not a paper-grade claim.
- The BCC rate scalar is a stress-ng `bogo_ops` workload-level column, the same
  quantity the Tetragon and Tracee rows derive; the apps' corrected ratios are
  not cross-compared here.
- `SAMPLES=3` at 60 s is within the framework's authoritative policy; the row
  invents no additional validity gate.

The shared builder now serves five apps across two workload shapes, covering
every argument app whose May causality batch reported a corrected ratio except
otelcol-ebpf-profiler. The remaining natural axes are (a) the sixth and last
app, `otelcol-ebpf-profiler` (May corrected `0.9983`; its workload rate shape
must be checked against a retained app record first), and (b) the same triplet
under a different pass (`wide_mem`, `const_prop`, `dce`) to test whether the
methodology distinguishes passes. Neither was needed for this increment.

## Delivery

Two commits shipped and pushed to `origin/master`.

- `57c88bdc9` — "Add fresh provenance-complete BCC map_inline causality
  evidence": the 73-file evidence dir, the `bcc_fresh_causality_rows` wrapper
  with frozen declared constants, the extended self-test fixture, the
  `package-atc26.sh` `required`/`validationEvidence`/README additions, and the
  AE-doc evidence-table row plus eleventh-derivation narrative.
- the step-0018 report commit (this file).

After the content commit the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
