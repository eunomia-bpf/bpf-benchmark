# BUILD_AND_EVALUATE Step 0021 Report

Date: 2026-09-26
Experiment: generalize the fresh causality-triplet treatment from `map_inline`
(kfunc lowering) to a **pure BPF-to-BPF rewriting pass**, by measuring the
`wide_mem` pass on Tetragon with the same one-optimized-run-plus-two-matched-no-
pass-controls shape and the same retained per-step bytecode, and freezing its
derived ratios as the row's declared constants.
Result: supported — the fresh Tetragon `wide_mem` triplet completes all three
legs cleanly, retains bytecode for all 254 changed load instances, and its
controlled-corrected throughput ratio (1.0852x) is frozen; the renderer row
flips `PARTIAL` → `PASS`, and no other row in the table changes.

## Source ownership and experiment selection

The prior increment (step 0020) left the renderer's `fresh_causality_rows`
builder parameterized on the pass under test (`3b9ccc3bc`), so the axis was
ready but unmeasured. Two facts decided the target:

1. **Tetragon is the densest retained `wide_mem` producer** of the six supported
   applications: 616 applied sites across its retained report streams, against
   929 for Cilium (but Cilium already carries six triplets and a large
   attribution analysis), 299 for Tracee, 65 for BCC, 45 for otelcol, 10 for
   Katran. A controlled measurement is worth more where more sites sit behind
   it.
2. **`const_prop` is a poor next choice**: `docs/evaluation.md:342` records
   `bpfopt_failed[const_prop]` on 44 programs at the `bpfopt` CLI layer, so a
   triplet there would measure a mostly-failing pass.

The pass under test is a policy knob, not a frozen artifact. The triplet used
the already-supported `BPFREJIT_BENCH_PASSES=wide_mem` knob
(`Makefile:168`, `runner/libs/rejit.py:21`) with the same
`SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o
runtime-kernel-image` shape the six `map_inline` triplets used, so nothing
about the workload, app runner, `corpus/driver.py`, benchmark Makefile,
runtime-image launch wiring, stressor, worker count, packet topology, or CPU/
duration setting changed.

## Valid result

**All three legs exited 0.** Driver log:

```
=== mi    start 2026-09-26T12:26:12Z ===
=== mi    done  2026-09-26T12:39:04Z rc=0 ===
=== nullA start 2026-09-26T12:39:04Z ===
=== nullA done  2026-09-26T12:53:55Z rc=0 ===
=== nullB start 2026-09-26T12:53:55Z ===
=== nullB done  2026-09-26T13:10:19Z rc=0 ===
=== tetragon wide_mem triplet complete 2026-09-26T13:10:19Z ===
```

| leg | run dir | `enabled_passes` | suite | app | `rejit_result.status` |
|---|---|---|---|---|---|
| optimized | `x86_kvm_corpus_20260926_122945_897790` | `["wide_mem"]` | `completed` | `ok` | `ok` |
| control A | `x86_kvm_corpus_20260926_124505_606032` | `[]` | `completed` | `ok` | `skipped` |
| control B | `x86_kvm_corpus_20260926_130125_857040` | `[]` | `completed` | `ok` | `skipped` |

All three are single-app `x86_kvm_corpus` with `samples=3` and
`workload_seconds=60.0`, no app `error`.

**Rewrite reconciliation.** The optimized run's retained
`details/loadtime-reports/tetragon__observer.jsonl` holds 264 report rows: 254
changed load instances, 254 applied sites (report `pass` is `wide_mem` on every
row), instruction counts 373,141 → 343,261 (−29,880). All 254 changed workdirs
retain `input.step.0.bin` + `output.next.0.bin` + `report.0.json`; the retained
bytecode's raw `struct bpf_insn` length (8 bytes each) matches the reported
before/after instruction counts for every one, and every before/after image
differs.

**Throughput causality.**

| quantity | value |
|---|---|
| median raw ratio | 1.014183x |
| control A | 0.9358 |
| control B | 0.9334 |
| control median | 0.934581x |
| control-corrected | 1.085174x |

Tetragon's fresh workload is a single component-less stress-ng run, so the
derived scalar is the workload-level `stress-ng: metrc:` bogo-ops column, which
the shared `_rate_scalar` fallback already covers.

**Declared constants frozen** to `("1.0142", "1.0852")` at four decimal places.
The builder's placeholder constants were `("1.0", "1.0")`, deliberately chosen
so the row could not accidentally `PASS` before the measurement existed; the
rendered row was `PARTIAL` before this change and is `PASS` after.

**Renderer integrity.** `python3 -m py_compile` passes;
`python3 docs/artifacts/render_claim_table.py --self-test` prints
`self-test: OK (13 evidence classes)`. A full-row diff of the rendered table
against `HEAD~1`'s renderer shows exactly one changed line — the new row —
which flips `PARTIAL` → `PASS` and prints the frozen constants:

```
RQ2 Tetragon fresh wide_mem causality + retained bytecode (254 sites)  PASS
  docs/artifacts/evidence/rq2-tetragon-wide-mem-fresh-causality: wide_mem median
  stress-ng metrc bogo-ops ratio=1.014183x; no-pass controls ['0.9358', '0.9334']
  (median 0.934581x); control-corrected=1.085174x (declared 1.0142/1.0852), 3+3
  samples per run; 264 report rows, 254 changed load instances, 254 applied sites,
  insn 373141->343261 (-29880); bytecode retained for 254/254 changed workdirs,
  0 length mismatches, 0 identical images; run status valid=True, controls
  valid=True, receipt file hashes valid=True
```

`OVERALL AE EVIDENCE` remains `INCOMPLETE`.

## Evidence packaging

The triplet ships as `docs/artifacts/evidence/rq2-tetragon-wide-mem-fresh-
causality/` (777 hashed files): `receipt.json` with a SHA256 for every retained
file, the normalized `make-corpus.log` plus `controls/null{A,B}/make-corpus.log`,
the two control `metadata.json` + app records, and the optimized run's status
files, shim logs, loadtime plan, report stream, and all 254 changed workdirs'
three bytecode files each. Raw counters only — no aggregation; every number in
the renderer row is derived at render time.

`docs/artifacts/package-atc26.sh` was extended so the archive stages the new
evidence dir (`validationEvidence`), requires its receipt/log/report/workdir/
control files in the clean-extraction existence check, asserts the new row
renders `PASS` from the archived sources alone, and names the triplet in the
archival README. `docs/atc26-artifact-evaluation.md` gained the §7
evidence-inventory row and the §11 thirteenth derivation paragraph; both are
additive and were diffed against current state first.

## Scientific boundary and next action

Latitude, stated plainly.

- The control-corrected ratio is a **controlled measurement, not a speedup
  claim**: the two no-pass controls are matched restarts at the identical 60 s
  duration, so their median (0.9346x) measures restart drift. The corrected
  1.0852x is raw ÷ that median.
- The sign agrees with the May Tetragon `map_inline` batch's independent
  `1.0840`, but that batch is a **different pass and a different
  host/toolchain generation**; the two are never merged.
- The row is gated on `enabled_passes == ["wide_mem"]`, so it can never be
  satisfied by a `map_inline` triplet's files.
- `PASS` remains local to the named row. `OVERALL AE EVIDENCE` stays
  `INCOMPLETE` until the `atc26-ae-2` ZIP is published on Zenodo.

The same axis is available for a second `wide_mem` app (Cilium, 929 retained
sites, or Tracee, 299) and for other pure-bytecode passes; each needs only a
new wrapper plus its two frozen constants.

## Delivery

Two content commits shipped and pushed to `origin/master`
(`3b9ccc3bc..688b0898c`):

- `9811b2adb` — "Add the first non-map_inline fresh causality triplet: Tetragon
  wide_mem": the evidence tree plus the frozen declared constants.
- `688b0898c` — "Ship the Tetragon wide_mem triplet in the packager and AE
  guide": the packager staging/required/assertion/README edits and the AE-doc
  §7 row and §11 paragraph.
- this step-0021 report.

After the content commits the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
