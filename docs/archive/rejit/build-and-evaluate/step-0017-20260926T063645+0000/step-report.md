# BUILD_AND_EVALUATE Step 0017 Report

Date: 2026-09-26
Experiment: repeat the fresh provenance-complete causality triplet for a
**fourth application** (Tracee) to test whether the shared methodology holds on
a second independent app of the component-less stress-ng shape, and to close the
last remaining x86 causality app that the May batch already covers. Tracee
`map_inline`.
Result: supported — a fourth KVM triplet yields a `PASS` renderer row binding a
derived 12-instance / 12-site rewrite to a control-corrected 1.0152x throughput
ratio, with every file SHA256-bound, the Tracee app path honored, and the
correction sign agreeing with the May Tracee batch

## Source ownership and experiment selection

Step-0016 proved the component-less stress-ng shape with Tetragon and shipped it
as the third thin wrapper over the shared builder. Tracee is the obvious next
arm: it uses the identical component-less `metrc` shape (confirmed from a
retained Tracee app record before the runs — its workload has `components: []`
and its rate is the `stress-ng: metrc:` bogo-ops column), it is the app whose
`trace_security_` program previously exposed an optimizer defect (now fixed), and
its May causality batch already reports an independent corrected `1.0114`. A
matching sign here would corroborate both the shape and the May direction.

No frozen artifact changed: no workload, app runner, `corpus/driver.py`,
benchmark Makefile, runtime-image wiring, stressor, worker count, packet
topology, or CPU-count/duration setting was touched. The only repo-side setting
is `runner/config/passes/**` policy, which the repository rule frees, and the
runs reuse the existing two-start load-time protocol verbatim.

Three KVM runs were launched through `make corpus` (the only entrypoint), one at
a time because the prerequisites are shared:

| role | run dir | policy | shape |
|---|---|---|---|
| MI | `x86_kvm_corpus_20260926_055043_248321` | `BPFREJIT_BENCH_PASSES=map_inline` | `SAMPLES=3`, 60 s |
| null A | `x86_kvm_corpus_20260926_060155_936788` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |
| null B | `x86_kvm_corpus_20260926_061150_119248` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |

The no-pass control again used `BPFREJIT_BENCH_PASSES=,` — the only value that
survives container environment forwarding (`runner/libs/suite_commands.py` drops
empty strings) and still expands to an empty pass list
(`runner/libs/rejit.py::_expand_groups` filters empty tokens). Both controls
confirm it: each recorded `config.enabled_passes == []` with
`rejit_result = {"mode": "loadtime", "status": "skipped"}`.

## Valid result

Two independent derivations come out of the same triplet.

**Rewrite reconciliation.** The MI run's retained
`details/loadtime-reports/tracee__monitor.jsonl` holds 162 rows: 150 unchanged
loads and **12 changed load instances** totalling **12 applied sites**,
instruction counts 400,640 → 398,817 (−1,823). All 12 changed workdirs are
retained; every retained `input.step.0.bin` / `output.next.0.bin` length equals
8× the reported before/after instruction count, and every before/after image
pair differs (12/12, 0 missing, 0 length mismatches, 0 identical images). Every
value is computed by the renderer from the retained report stream and bytecode
at render time; none is transcribed.

**Throughput causality.** Tracee's fresh workload is a single stress-ng
invocation with **no `components`**, so the workload-level fallback reads the
`stress-ng: metrc:` bogo-ops column, sums the samples' rows, takes the median
over three samples per phase, and forms the post/baseline ratio. Extractor
parity was confirmed against a retained Tracee app record before the runs were
accepted.

| quantity | value |
|---|---|
| MI raw median ratio | 1.011006 |
| null A ratio | 0.994790 |
| null B ratio | 0.996940 |
| control median | 0.995865 |
| **control-corrected** | **1.015204** |

The declared constants are frozen at four decimal places (`raw 1.0110`,
`corrected 1.0152`); a drift degrades the row to `PARTIAL` rather than silently
re-baselining. The corrected ratio is above 1.0, and its sign **agrees with the
May Tracee batch's independent `1.0114`** (also above 1.0). Two generations
taken months apart landing on the same sign for the same app is reported as
corroboration, not as a merged measurement.

The renderer emits **one** new row — `RQ2 Tracee fresh map_inline causality +
retained bytecode (12 sites)` — reading `PASS`. The row set moves from 65 to 66
data rows. A full-row diff against the pre-edit renderer is exactly one added
line and zero changes to any pre-existing row text or status, including the five
`PARTIAL` rows; `OVERALL AE EVIDENCE` remains `INCOMPLETE`.

`tracee_fresh_causality_rows` is the fourth thin wrapper over the shared
`fresh_causality_rows`, differing only in `app_stem`, `report_rel`, `label`,
`evidence_dir`, `declared`, and `metric_noun="stress-ng metrc bogo-ops"`. A
Tracee triplet can be satisfied only by
`details/apps/tracee__monitor.json` and
`details/loadtime-reports/tracee__monitor.jsonl`.

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
component-less `metrc` Tetragon triplet, and (new) a Tracee triplet whose app
record is swapped for Tetragon's — each flips the row off `PASS`; restoring it
returns `self-test: OK (13 evidence classes)`. The count stays at 13 because
Tracee introduces no new derivation class: it reuses the component-less
`metrc` shape the Tetragon case already covers, so the new case asserts only the
app-path gate and the row's rate wording.

## Evidence packaging

The triplet is retained at
`docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality/` — 52 files
(51 hashed plus `receipt.json`): the MI `metadata.json`, normalized console log,
`details/{progress.json,result.json,apps/tracee__monitor.json,loadtime-plans/tracee__monitor.json,loadtime-reports/tracee__monitor.jsonl,shim-logs/*,loadtime-workdirs/*}`
for all 12 changed instances, and each control's `metadata.json`, console log,
and app record. `receipt.json` binds the command, control command, source
commit, source and control run dirs, `enabled_passes`/`control_enabled_passes`,
the derived counts, the throughput causality block, and every retained file's
SHA256; `log_sha256` and the normalization rule are recorded. The MI console log
was sourced from the supervising job's `/tmp/fresh-tracee/mi.log`, since fresh
`make corpus` run dirs contain only `metadata.json` and `details/`.

`docs/artifacts/package-atc26.sh` was extended minimally: representative entries
in `required=(…)` (receipt, log, report stream, one retained before-image, both
control metadata records), the Tracee triplet receipt/log/report in the manifest
`validationEvidence` list, and the README paragraph updated to four apps with
Tracee's 12-site rewrite. `bash -n` passes and every new `required` entry exists
on disk.

The builder was generalized rather than duplicated: `/tmp/build_fresh_evidence.py`
now reads `EV_SLUG`/`EV_STEM`/`EV_APP`/`EV_OUT`/`EV_NOUN`/`EV_WL_DESC` from the
environment, and a regression rebuild of the Tetragon triplet reproduced the
committed `files_sha256`, derived counts, and ratios byte-for-byte. (The builder
is a throwaway in `/tmp`, not shipped; the shipped renderer is the durable
artifact.)

## Scientific boundary and next action

Latitude, stated plainly.

- This is a **single-application** (Tracee), **single-pass** (`map_inline`) fresh
  measurement. It generalizes to no other app, pass, policy path, or
  architecture; the paper's declared site counts and the May tracee ratios are a
  separate generation and are never merged with the fresh 12-site figure or
  these ratios.
- The May Tracee corrected `1.0114` and this fresh `1.0152` are **two separate
  generations**; their agreement in sign is reported as corroboration, not as a
  single merged measurement.
- It is a **two-start load-time** experiment, so it establishes transparent
  loader interception, stock-verifier acceptance, and a measured throughput
  effect — not post-deployment re-specialization or phase-change recovery.
- The control-corrected ratio is a *median-of-ratios* correction with two
  controls; a two-point control median is not a confidence interval. No CI is
  asserted and the 1.0152x is not a paper-grade claim.
- The Tracee rate scalar is a stress-ng `bogo_ops` workload-level column, the
  same quantity the Tetragon row derives; the two apps' corrected ratios are not
  cross-compared here.
- `SAMPLES=3` at 60 s is within the framework's authoritative policy; the row
  invents no additional validity gate.

The shared builder now serves four apps across two workload shapes. The
remaining natural axes are (a) the fifth app, `bcc` (`stress_ng_bcc_*`, the same
component-less `metrc` shape, May corrected `0.7921`), and (b) the same triplet
under a different pass (`wide_mem`, `const_prop`, `dce`) to test whether the
methodology distinguishes passes. Neither was needed for this increment.

## Delivery

Two commits shipped and pushed to `origin/master`.

- `ad770e3ee` — "Add fresh provenance-complete Tracee map_inline causality
  evidence": the 52-file evidence dir, the `tracee_fresh_causality_rows` wrapper
  with frozen declared constants, the extended self-test fixture, the
  `package-atc26.sh` staging/`required`/README additions, and the AE-doc
  evidence-table row plus tenth-derivation narrative.
- the step-0017 report commit (this file).

After the content commit the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
