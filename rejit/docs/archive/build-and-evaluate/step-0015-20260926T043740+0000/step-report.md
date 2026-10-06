# BUILD_AND_EVALUATE Step 0015 Report

Date: 2026-09-26
Experiment: repeat the step-0014 fresh provenance-complete causality triplet for
a **second application**, to test whether the single-artifact methodology — and
the shared renderer path it now needs — holds for an app with a different
workload shape and a far larger rewrite population, Cilium `map_inline`
Result: supported — a second KVM triplet yields a `PASS` renderer row binding a
derived 122-instance / 3,787-site rewrite to a control-corrected 0.9619x
throughput ratio, with every file SHA256-bound and the Cilium app path honored
rather than inherited from Katran

## Source ownership and experiment selection

Step-0014 closed the fresh-causality question for Katran, but shipped it as a
Katran-shaped renderer function (`katran_fresh_causality_rows`) whose app stem,
report filename, and label were hardcoded. A second application was the obvious
next experiment for two reasons: it tests whether the corrected effect found on
Katran is app-specific rather than a property of the environment, and it forces
the hardcoded Katran path to be generalized, which is the only way to know the
abstraction is real rather than a one-off.

No frozen artifact changed: no workload, app runner, `corpus/driver.py`,
benchmark Makefile, runtime-image wiring, stressor, worker count, packet
topology, or CPU/duration setting was touched. The only repo-side setting is
`runner/config/passes/**` policy, which the repository rule frees, and the runs
reuse the existing two-start load-time protocol verbatim.

Three KVM runs were launched through `make corpus` (the only entrypoint), one at
a time because the prerequisites are shared:

| role | run dir | policy | shape |
|---|---|---|---|
| MI | `x86_kvm_corpus_20260926_034321_368659` | `BPFREJIT_BENCH_PASSES=map_inline` | `SAMPLES=3`, 60 s |
| null A | `x86_kvm_corpus_20260926_035326_009026` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |
| null B | `x86_kvm_corpus_20260926_040241_545335` | `SKIP_REJIT=norejit BPFREJIT_BENCH_PASSES=,` | `SAMPLES=3`, 60 s |

The no-pass control again used `BPFREJIT_BENCH_PASSES=,` — the only value that
survives container environment forwarding (`runner/libs/suite_commands.py` drops
empty strings) and still expands to an empty pass list
(`runner/libs/rejit.py::_expand_groups` filters empty tokens). Both controls
confirm it: each recorded `config.enabled_passes == []` with
`rejit_result = {"mode": "loadtime", "status": "skipped"}`.

## Valid result

Two independent derivations come out of the same triplet.

**Rewrite reconciliation.** The MI run's retained
`details/loadtime-reports/cilium__agent.jsonl` holds 169 rows: 47 unchanged
loads and **122 changed load instances** totalling **3,787 applied sites**,
instruction counts 159,896 → 111,826 (−48,070). All 122 changed workdirs are
retained; every retained `input.step.0.bin` / `output.next.0.bin` length equals
8× the reported before/after instruction count, and every before/after image
pair differs (122/122, 0 missing, 0 length mismatches, 0 identical images).
Every value is computed by the renderer from the retained report stream and
bytecode at render time; none is transcribed.

**Throughput causality.** The fresh Cilium workload
(`cilium_endpoint_pktgen`) splits each phase into two kernel-pktgen components,
so the same summed-component extractor the Katran row uses applies unchanged:
sum every component's pktgen pps per workload, take the median over the three
samples per phase, and form the post/baseline ratio.

| quantity | value |
|---|---|
| MI raw median ratio | 1.032516 |
| null A ratio | 1.072739 |
| null B ratio | 1.074034 |
| control median | 1.073387 |
| **control-corrected** | **0.961923** |

The declared constants are frozen at four decimal places (`raw 1.0325`,
`corrected 0.9619`); a drift degrades the row to `PARTIAL` rather than silently
re-baselining. The corrected ratio is below 1.0 — under this host/toolchain
generation Cilium `map_inline` is within restart drift of neutral, and its sign
**agrees with the May Cilium batch's independent `0.9585`**. Two generations
taken months apart landing on the same sign for the same app is the reason this
row claims the controlled measurement rather than a speedup.

The renderer emits **one** new row — `RQ2 Cilium fresh map_inline causality +
retained bytecode (3787 sites)` — reading `PASS`. The row set moves from 63 to
64 data rows. A full-row diff against the pre-edit renderer is exactly one added
line and zero changes to any pre-existing row text or status, including the five
`PARTIAL` rows; `OVERALL AE EVIDENCE` remains `INCOMPLETE`.

The generalization was made rather than duplicated: the body of
`katran_fresh_causality_rows` became a keyword-only
`fresh_causality_rows(root, *, app_stem, report_rel, label, evidence_dir,
declared)`, and both `katran_fresh_causality_rows` and the new
`cilium_fresh_causality_rows` are thin wrappers. A Cilium triplet therefore can
be satisfied only by `details/apps/cilium__agent.json` and
`details/loadtime-reports/cilium__agent.jsonl`; the self-test asserts exactly
that by writing a Cilium-evidence dir containing only a Katran app record and
requiring the row to fall to `UNAVAILABLE`.

`PASS` is gated on: the MI run's suite/app/rejit status and `samples`/
`workload_seconds`/`enabled_passes == ["map_inline"]` shape; the retained report
stream reconciling (at least one changed instance, every changed workdir
retaining bytecode whose lengths match and whose images differ); the receipt
hashing every retained file; both controls being `passes == []` loadtime skips
at the identical shape; and both derived ratios reproducing the frozen declared
constants. The self-test fixture drives the identical derivation over synthetic
matched runs and mutates each gate in turn — throughput drift, a control
carrying a pass, the MI run carrying the wrong pass, missing retained bytecode,
missing receipt hashes, and (new) a Cilium triplet with a Katran app record —
each flips the row off `PASS`; restoring it returns
`self-test: OK (12 evidence classes)`.

## Evidence packaging

The triplet is retained at
`docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality/` — 382 files
(381 hashed plus `receipt.json`): the MI `metadata.json`, normalized console
log, `details/{progress.json,result.json,apps/cilium__agent.json,loadtime-plans/cilium__agent.json,loadtime-reports/cilium__agent.jsonl,shim-logs/*,loadtime-workdirs/*}`
for all 122 changed instances, and each control's `metadata.json`, console log,
and app record. `receipt.json` binds the command, control command, source
commit, source and control run dirs, `enabled_passes`/`control_enabled_passes`,
the derived counts, the throughput causality block, and every retained file's
SHA256; `log_sha256` and the normalization rule are recorded. The MI console log
was sourced from the supervising job's `/tmp/fresh-cilium/mi.log`, since fresh
`make corpus` run dirs contain only `metadata.json` and `details/`.

`docs/artifacts/package-atc26.sh` was extended minimally: representative entries
in `required=(…)` (receipt, log, report stream, one retained before-image, both
control metadata records), the Cilium triplet receipt/log/report in the manifest
`validationEvidence` list, and one additive README paragraph. `bash -n` passes
and every new `required` entry exists on disk.

## Scientific boundary and next action

Latitude, stated plainly.

- This is a **single-application** (Cilium), **single-pass** (`map_inline`) fresh
  measurement. It generalizes to no other app, pass, policy path, or
  architecture; the paper's declared Cilium 4086 site figure and its June ratios
  are a separate generation and are never merged with the fresh 3,787-site
  figure or these ratios.
- The May Cilium corrected `0.9585` and this fresh `0.9619` are **two separate
  generations**; their agreement in sign is reported as corroboration, not as a
  single merged measurement.
- It is a **two-start load-time** experiment, so it establishes transparent
  loader interception, stock-verifier acceptance, and a measured throughput
  effect — not post-deployment re-specialization or phase-change recovery.
- The control-corrected ratio is a *median-of-ratios* correction with two
  controls; it measures drift magnitude, but a two-point control median is not a
  confidence interval. No CI is asserted and the 0.9619x is not a paper-grade
  claim.
- `SAMPLES=3` at 60 s is within the framework's authoritative policy; the row
  invents no additional validity gate (no matched no-op arm beyond the requested
  controls, no zero-drop assertion, no idle-CPU or `run_cnt` threshold).

The generalized `fresh_causality_rows` now makes a third triplet cheap, and the
natural next questions are (a) a third application (tetragon/tracee/bcc use a
stress-ng bogo-ops workload with no pktgen components, so the extractor must be
confirmed to yield a rate before that arm is chosen), or (b) the same triplet
under a different pass (`wide_mem`, `const_prop`, `dce`) to test whether the
methodology distinguishes passes. Neither was needed for this increment.

## Delivery

Two commits shipped and pushed to `origin/master`.

- `e9f0a591e` — "Add fresh provenance-complete Cilium map_inline causality
  evidence": the 382-file evidence dir, the `fresh_causality_rows` generalization
  with the `cilium_fresh_causality_rows` wrapper and frozen declared constants,
  the extended self-test fixture, the `package-atc26.sh` staging/`required`/
  README additions, and the AE-doc evidence-table row plus narrative paragraph.
- the step-0015 report commit (this file).

After the content commit the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
