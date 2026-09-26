# BUILD_AND_EVALUATE Step 0022 Report

Date: 2026-09-26
Experiment: extend the **fresh causality-triplet** treatment to a second
non-`map_inline` application-pass pair, by measuring the `wide_mem` pass on
Cilium with the same one-optimized-run-plus-two-matched-no-pass-controls shape
and the same retained per-step bytecode, on a **different workload rate shape**
(two kernel-pktgen components rather than the component-less stress-ng column
the step-0021 Tetragon triplet used).
Result: supported — the fresh Cilium `wide_mem` triplet completes all three legs
cleanly, retains bytecode for all 164 changed load instances, and its
control-corrected throughput ratio (1.0974x) is frozen; the renderer row flips
`PARTIAL` → `PASS`, and no other row in the table changes.

## Source ownership and experiment selection

Step 0021 shipped the first non-`map_inline` triplet (Tetragon `wide_mem`) and
left the axis open: the builder is already parameterized on the pass under test,
so a second application needs only a new thin wrapper plus its two frozen
constants. This step takes the second application and, deliberately, one whose
derived workload scalar has a different shape.

The selection was re-derived from the retained report streams rather than
reused, because the step-0021 comparison had summed `sites_applied` over whole
report streams (which include `map_inline` and other steps), producing numbers
(616/929/299/65) that are not comparable with the isolated single-pass triplets.
Counting only the rows whose `step` is `wide_mem` in a single application
startup of the six-app default-policy run gives: Tetragon 254, Cilium 164,
Tracee 92, BCC 13, otelcol-ebpf-profiler 12, Katran 1. Measured on the
isolated single-pass basis the triplets themselves use, only three of the six
have an isolated `wide_mem` run: Tetragon 254, Cilium 164, Tracee 142. Cilium
is the second-densest `wide_mem` producer after the already-shipped Tetragon on
either basis, and — unlike Tetragon,
whose fresh workload is one component-less stress-ng run — Cilium's fresh
workload emits two kernel-pktgen components. Picking it tests the derivation
against a second rate shape as well as a second application.

`const_prop` was rejected for the reason step 0021 recorded:
`docs/evaluation.md:342` shows `bpfopt_failed[const_prop]` on 44 programs at the
`bpfopt` CLI layer, so a triplet there would measure a mostly-failing pass.

The pass under test is a policy knob, not a frozen artifact. The triplet used
the already-supported `BPFREJIT_BENCH_PASSES=wide_mem` knob with the same
`SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o
runtime-kernel-image` shape the `map_inline` triplets and the step-0021
Tetragon triplet used, so nothing about the workload, app runner,
`corpus/driver.py`, benchmark Makefile, runtime-image launch wiring, stressor,
worker count, packet topology, or CPU/duration setting changed.

## Valid result

**All three legs exited 0.** Driver log `/workspaces/fresh-widemem-cilium-logs.driver.log`:

```
=== mi    start 2026-09-26T13:36:49Z ===
=== mi    done  2026-09-26T13:48:43Z rc=0 ===
=== nullA start 2026-09-26T13:48:43Z ===
=== nullA done  2026-09-26T14:03:03Z rc=0 ===
=== nullB start 2026-09-26T14:03:03Z ===
=== nullB done  2026-09-26T14:17:39Z rc=0 ===
=== cilium wide_mem triplet complete 2026-09-26T14:17:39Z ===
```

| leg | run dir | `enabled_passes` | suite | app | `rejit_result.status` |
|---|---|---|---|---|---|
| optimized | `x86_kvm_corpus_20260926_133930_796763` | `["wide_mem"]` | `completed` | `ok` | `ok` |
| control A | `x86_kvm_corpus_20260926_135405_708186` | `[]` | `completed` | `ok` | `skipped` |
| control B | `x86_kvm_corpus_20260926_140808_071557` | `[]` | `completed` | `ok` | `skipped` |

All three are single-app `x86_kvm_corpus` with `samples=3` and
`workload_seconds=60.0`, no app `error`.

**Rewrite reconciliation.** The optimized run's retained
`details/loadtime-reports/cilium__agent.jsonl` holds 169 report rows (all
`pass == wide_mem`): 164 changed load instances, 164 applied sites, instruction
counts 159,896 → 156,508 (−3,388), 5 unchanged rows. All 164 changed workdirs
retain `input.step.0.bin` + `output.next.0.bin` + `report.0.json`; the retained
bytecode's raw `struct bpf_insn` length (8 bytes each) matches the reported
before/after instruction counts for every one, and every before/after image
differs.

**Throughput causality.**

| quantity | value |
|---|---|
| median raw ratio | 1.123150x |
| control A | 1.0187 |
| control B | 1.0282 |
| control median | 1.023440x |
| control-corrected | 1.097427x |

Cilium's fresh workload emits two kernel-pktgen components, so the derived
scalar is the **sum over both components' pktgen pps**. The shared summed
extractor already accepts both this shape and the component-less stress-ng shape
the step-0021 Tetragon triplet used, so the same builder served this triplet
unchanged; only the row's `metric_noun` differs.

**Declared constants frozen** to `("1.1232", "1.0974")` at four decimal places.

**Renderer integrity.** `python3 -m py_compile` passes;
`python3 docs/artifacts/render_claim_table.py --self-test` prints
`self-test: OK (13 evidence classes)`. A full-row diff of the rendered table
against the pre-change renderer (`ec2a401ba`'s predecessor) shows exactly one
added line — the new row — and `tail -1` is `OVERALL AE EVIDENCE: INCOMPLETE`:

```
RQ2 Cilium fresh wide_mem causality + retained bytecode (164 sites)   PASS   docs/artifacts/evidence/rq2-cilium-wide-mem-fresh-causality: wide_mem median summed kernel-pktgen pps ratio=1.123150x; no-pass controls ['1.0187', '1.0282'] (median 1.023440x); control-corrected=1.097427x (declared 1.1232/1.0974), 3+3 samples per run; 169 report rows, 164 changed load instances, 164 applied sites, insn 159896->156508 (-3388); bytecode retained for 164/164 changed workdirs, 0 length mismatches, 0 identical images; run status valid=True, controls valid=True, receipt file hashes valid=True
```

The self-test gained a Cilium `wide_mem` case (after the Tetragon one) that
mutates the pass gate, the `metric_noun` wording, and the app-stem gate in turn,
each flipping the row off `PASS`. The class count stays 13 because Cilium
`wide_mem` introduces no new derivation class — it reuses the same summed
extractor with a different `metric_noun`.

## Evidence packaging

The triplet ships as
`docs/artifacts/evidence/rq2-cilium-wide-mem-fresh-causality/` (508 tracked
files; the receipt hashes 507): `receipt.json` with a SHA256 for every retained
file, the normalized `make-corpus.log` plus `controls/null{A,B}/make-corpus.log`,
the two control `metadata.json` + app records, and the optimized run's status
files, shim logs, loadtime plan, report stream, and all 164 changed workdirs'
three bytecode files each. Raw counters only — no aggregation; every number in
the renderer row is derived at render time.

`docs/artifacts/package-atc26.sh` was extended so the archive stages the new
evidence dir (`validationEvidence`), requires its receipt/log/report/workdir/
control files in the clean-extraction existence check, asserts the new row
renders `PASS` from the archived sources alone, and names the triplet in the
archival README. `docs/atc26-artifact-evaluation.md` gained the §7
evidence-inventory row and the §11 fourteenth derivation paragraph; both are
additive and were diffed against current state first.

## Scientific boundary and next action

Latitude, stated plainly.

- The control-corrected ratio is a **controlled measurement, not a speedup
  claim**: the two no-pass controls are matched restarts at the identical 60 s
  duration, so their median (1.0234x) measures restart drift. The corrected
  1.0974x is raw ÷ that median.
- The corrected ratio is **above 1.0** here, whereas Cilium's `map_inline`
  triplet lands below it. They are different passes measured in separate
  generations; the two are never merged.
- Different workload rate shape from the Tetragon `wide_mem` triplet is a
  feature: it shows the derivation is independent of both the pass family and
  the workload's rate shape.
- The row is gated on `enabled_passes == ["wide_mem"]` and on Cilium's own app
  record and report path, so it can never be satisfied by a `map_inline` triplet
  or another application's files.
- `PASS` remains local to the named row. `OVERALL AE EVIDENCE` stays
  `INCOMPLETE` until the `atc26-ae-2` ZIP is published on Zenodo.

The same axis is available for a third `wide_mem` app (Tracee, 142 applied
sites in an isolated single-pass run; shipped as step 0023) and for other
pure-bytecode passes; each needs only a new wrapper plus its two frozen
constants.

## Delivery

Three content commits shipped and pushed to `origin/master`
(`efb9197e5..58f09bd86`):

- `ec2a401ba` — "Add a second non-map_inline fresh causality triplet: Cilium
  wide_mem": the evidence tree plus the frozen declared constants.
- `02b81fc3f` — "Ship the Cilium wide_mem triplet in the packager and AE
  guide": the packager staging/required/assertion/README edits and the AE-doc
  §7 row and §11 paragraph.
- `58f09bd86` — "Correct the wide_mem site-density comparison to a per-startup
  basis": fixes the step-0021 report's summed-over-streams counts
  (616/929/299/65) to the per-single-startup counts (254/164/92/13/12/1) in
  both the step-0021 report and the AE guide's thirteenth derivation.
- this step-0022 report.

After the content commits the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
