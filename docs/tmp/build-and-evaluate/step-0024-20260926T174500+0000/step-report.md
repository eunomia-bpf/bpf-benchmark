# BUILD_AND_EVALUATE Step 0024 Report

Date: 2026-09-26
Experiment: extend the **fresh causality-triplet** treatment to a **new pass
family** — the `dce` dead-code-elimination pass, the first non-`map_inline`
triplet that is neither `map_inline` (kfunc lowering) nor `wide_mem` — by
measuring it on Tetragon, the densest `dce` producer of the six applications,
with the same one-optimized-run-plus-two-matched-no-pass-controls shape and the
same retained per-step bytecode.
Result: supported — the fresh Tetragon `dce` triplet completes all three legs
cleanly, retains bytecode for all 254 changed load instances, and its
control-corrected throughput ratio (1.0088x) is frozen; the renderer row flips
`PARTIAL` → `PASS`, and no other row in the table changes.

## Source ownership and experiment selection

Step 0023 shipped the third `wide_mem` triplet (Tracee) and closed the `wide_mem`
axis for the three applications that have an isolated `wide_mem` run. The
renderer's shared builder is already parameterized on `pass_name`, so the next
axis that adds information is a **different pass family**, not a fourth
application on `wide_mem`.

`dce` is a pure BPF-to-BPF rewriting pass like `wide_mem`, so the same
single-pass prefilter, report reconciliation, and control-corrected ratio apply
unchanged, and the row is still gated on `enabled_passes == ["dce"]` rather than
on word shape. Its densest producer is Tetragon: in the six-app default-policy
run `x86_kvm_corpus_20260923_114624_121697`, the per-step `sites_applied` sums to
`dce: 308` for Tetragon, ahead of `tracee: 196`, `bcc: 26`, `otelcol: 24`,
`katran: 2`, with Cilium unparsable. The figure was **measured, not copied** —
the per-step counts for that run are `{noop: 410, map_inline: 108, const_prop:
318, dce: 308, wide_mem: 154, bounds_check_merge: 154, skb_load_bytes_spec:
154, kop: 2753}` — and the default-policy stream is labelled as such, because the
triplet itself is an **isolated single-pass** run and earlier passes shrink
`dce`'s input. As with the `wide_mem` triplets, the row's own site count (254
applied sites) is derived from the isolated run's retained report stream, not
from this default-policy figure.

`const_prop` was rejected again for the reason step 0021 recorded:
`docs/evaluation.md:342` shows `bpfopt_failed[const_prop]` on 44 programs at the
`bpfopt` CLI layer, so a triplet there would measure a mostly-failing pass.

The pass under test is a policy knob, not a frozen artifact. The triplet used
the already-supported `BPFREJIT_BENCH_PASSES=dce` knob with the same `SAMPLES=3
WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image` shape
every prior triplet used, so nothing about the workload, app runner,
`corpus/driver.py`, benchmark Makefile, runtime-image launch wiring, stressor,
worker count, packet topology, or CPU/duration setting changed.

## Valid result

**All three legs exited 0.** Driver log
`/workspaces/fresh-dce-tetragon-logs.driver.log`:

```
=== mi    start 2026-09-26T16:37:07Z ===
=== mi    done  2026-09-26T16:56:37Z rc=0 ===
=== nullA start 2026-09-26T16:56:37Z ===
=== nullA done  2026-09-26T17:17:02Z rc=0 ===
=== nullB start 2026-09-26T17:17:02Z ===
=== nullB done  2026-09-26T17:41:22Z rc=0 ===
=== tetragon dce triplet complete 2026-09-26T17:41:22Z ===
```

| leg | run dir | `enabled_passes` | suite | app | `rejit_result.status` |
|---|---|---|---|---|---|
| optimized | `x86_kvm_corpus_20260926_164707_409188` | `["dce"]` | `completed` | `ok` | `ok` |
| control A | `x86_kvm_corpus_20260926_170758_323681` | `[]` | `completed` | `ok` | `skipped` |
| control B | `x86_kvm_corpus_20260926_173231_340346` | `[]` | `completed` | `ok` | `skipped` |

All three are single-app `x86_kvm_corpus` with `samples=3` and
`workload_seconds=60.0`, no app `error`.

**Rewrite reconciliation.** The optimized run's retained
`details/loadtime-reports/tetragon__observer.jsonl` holds 264 report rows (all
`pass == dce`): 254 changed load instances, 254 applied sites, instruction
counts 373,141 → 343,261 (−29,880), 10 unchanged rows. All 254 changed workdirs
retain `input.step.0.bin` + `output.next.0.bin` + `report.0.json`; the retained
bytecode's raw `struct bpf_insn` length (8 bytes each) matches the reported
before/after instruction counts for every one, and every before/after image
differs.

**Throughput causality.**

| quantity | value |
|---|---|
| median raw ratio | 0.952573x |
| control A | 0.9458 |
| control B | 0.9427 |
| control median | 0.944262x |
| control-corrected | 1.008801x |

Tetragon's fresh workload is a single component-less stress-ng run, so the
derived scalar is the same workload-level `stress-ng: metrc:` bogo-ops column the
Tetragon `wide_mem`/`map_inline` triplets use, not Cilium's summed kernel-pktgen
pps. The shared builder served this triplet unchanged; only the row's
`pass_name` and the frozen constants differ.

**Declared constants frozen** to `("0.9526", "1.0088")` at four decimal places.

**Renderer integrity.** `python3 -m py_compile` passes;
`python3 docs/artifacts/render_claim_table.py --self-test` prints
`self-test: OK (13 evidence classes)`. A full-row diff of the rendered table
against `HEAD`'s renderer shows exactly one added line — the new row — and
`tail -1` is `OVERALL AE EVIDENCE: INCOMPLETE`:

```
RQ2 Tetragon fresh dce causality + retained bytecode (254 sites)   PASS   docs/artifacts/evidence/rq2-tetragon-dce-fresh-causality: dce median stress-ng metrc bogo-ops ratio=0.952573x; no-pass controls ['0.9458', '0.9427'] (median 0.944262x); control-corrected=1.008801x (declared 0.9526/1.0088), 3+3 samples per run; 264 report rows, 254 changed load instances, 254 applied sites, insn 373141->343261 (-29880); bytecode retained for 254/254 changed workdirs, 0 length mismatches, 0 identical images; run status valid=True, controls valid=True, receipt file hashes valid=True
```

The self-test gained a Tetragon `dce` case (after the Tracee `wide_mem` one) that
mutates the pass gate (rejecting a `wide_mem` run), the `metric_noun` wording,
and the app-stem gate in turn, each flipping the row off `PASS`. The class count
stays 13 because the `dce` triplet introduces no new derivation class — it is the
same shared builder.

## Evidence packaging

The triplet ships as
`docs/artifacts/evidence/rq2-tetragon-dce-fresh-causality/` (778 tracked files;
the receipt hashes 777): `receipt.json` with a SHA256 for every retained file,
the normalized `make-corpus.log` plus `controls/null{A,B}/make-corpus.log`, the
two control `metadata.json` + app records, and the optimized run's status files,
shim logs, loadtime plan, report stream, and all 254 changed workdirs' three
bytecode files each. Raw counters only — no aggregation; every number in the
renderer row is derived at render time.

`docs/artifacts/package-atc26.sh` was extended so the archive stages the new
evidence dir (`validationEvidence`), requires its receipt/log/report/workdir/
control files in the clean-extraction existence check, asserts the new row
renders `PASS` from the archived sources alone, and names the triplet in the
archival README. `docs/atc26-artifact-evaluation.md` gained the §7
evidence-inventory row and the §11 sixteenth derivation paragraph; both are
additive and were diffed against current state first.

## Scientific boundary and next action

Latitude, stated plainly.

- The control-corrected ratio is a **controlled measurement, not a speedup
  claim**: the two no-pass controls are matched restarts at the identical 60 s
  duration, so their median (0.9443x) measures restart drift. The corrected
  1.0088x is raw ÷ that median.
- The corrected ratio is **close to neutral** (1.0088x) and both controls sit
  below 1.0, so the raw ratio alone (0.9526x) would read as a regression while
  the matched controls show it is restart drift; the row's claim is the
  controlled measurement, exactly as with the Tracee `wide_mem` triplet.
- 254 applied sites is the **largest `dce` population available** and ties the
  largest `wide_mem` triplet (Tetragon 254), so the pass-family independence is
  shown on a dense population, not a token one.
- The row is gated on `enabled_passes == ["dce"]` and on Tetragon's own app
  record and report path, so it can never be satisfied by a `wide_mem` or
  `map_inline` triplet or another application's files.
- `PASS` remains local to the named row. `OVERALL AE EVIDENCE` stays
  `INCOMPLETE` until the `atc26-ae-2` ZIP is published on Zenodo.

Further triplets on other passes need only a new wrapper plus two frozen
constants; the `dce` axis on Tetragon is now closed.

## Delivery

Two content commits to `origin/master`: the evidence tree plus the frozen
declared constants, and the renderer/packager/AE-guide registration plus this
step-0024 report. After the content commits the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
