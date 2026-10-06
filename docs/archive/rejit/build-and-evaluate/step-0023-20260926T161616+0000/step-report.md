# BUILD_AND_EVALUATE Step 0023 Report

Date: 2026-09-26
Experiment: extend the **fresh causality-triplet** treatment to a third
non-`map_inline` application-pass pair, by measuring the `wide_mem` pass on
Tracee with the same one-optimized-run-plus-two-matched-no-pass-controls shape
and the same retained per-step bytecode, and to close the axis on the **smallest**
of the three `wide_mem` site populations.
Result: supported — the fresh Tracee `wide_mem` triplet completes all three legs
cleanly, retains bytecode for all 142 changed load instances, and its
control-corrected throughput ratio (1.0039x) is frozen; the renderer row flips
`PARTIAL` → `PASS`, and no other row in the table changes.

## Source ownership and experiment selection

Step 0022 shipped the second non-`map_inline` triplet (Cilium `wide_mem`) and
named the natural third: another application on the same already-parameterized
builder. This step takes Tracee, which is the third-densest `wide_mem` producer
on the basis the triplets use and therefore completes the pass's three
applications.

The site count was **measured, not copied**, because step 0022 discovered the
earlier figures were a mixed-basis list. Counting only the rows whose `step` is
`wide_mem` in the six-app default-policy run
(`x86_kvm_corpus_20260923_114624_121697`) gives Tetragon 254, Cilium 164,
Tracee 92, BCC 13, otelcol-ebpf-profiler 12, Katran 1. But the triplets are
**isolated single-pass** runs, and in the multi-pass stream earlier passes shrink
`wide_mem`'s input, so 92 is not comparable with the triplets' own 254/164. Only
three applications have an isolated `wide_mem` run at all — Tetragon 254, Cilium
164, Tracee **142** — confirmed by inspecting each `enabled_passes ==
["wide_mem"]` run's own report stream. The document's count lists were corrected
to the isolated basis (while keeping the default-policy stream figures, labelled,
where a step report compares bases), which is also why this step's own Tracee
figures are 142 applied sites and not 92.

`const_prop` was rejected again for the reason step 0021 recorded:
`docs/evaluation.md:342` shows `bpfopt_failed[const_prop]` on 44 programs at the
`bpfopt` CLI layer, so a triplet there would measure a mostly-failing pass.

The pass under test is a policy knob, not a frozen artifact. The triplet used
the already-supported `BPFREJIT_BENCH_PASSES=wide_mem` knob with the same
`SAMPLES=3 WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o
runtime-kernel-image` shape every prior triplet used, so nothing about the
workload, app runner, `corpus/driver.py`, benchmark Makefile, runtime-image
launch wiring, stressor, worker count, packet topology, or CPU/duration setting
changed.

## Valid result

**All three legs exited 0.** Driver log
`/workspaces/fresh-widemem-tracee-logs.driver.log`:

```
=== mi    start 2026-09-26T15:22:25Z ===
=== mi    done  2026-09-26T15:36:53Z rc=0 ===
=== nullA start 2026-09-26T15:36:53Z ===
=== nullA done  2026-09-26T15:51:45Z rc=0 ===
=== nullB start 2026-09-26T15:51:45Z ===
=== nullB done  2026-09-26T16:05:56Z rc=0 ===
=== tracee wide_mem triplet complete 2026-09-26T16:05:56Z ===
```

| leg | run dir | `enabled_passes` | suite | app | `rejit_result.status` |
|---|---|---|---|---|---|
| optimized | `x86_kvm_corpus_20260926_152627_089782` | `["wide_mem"]` | `completed` | `ok` | `ok` |
| control A | `x86_kvm_corpus_20260926_154230_879447` | `[]` | `completed` | `ok` | `skipped` |
| control B | `x86_kvm_corpus_20260926_155641_973127` | `[]` | `completed` | `ok` | `skipped` |

All three are single-app `x86_kvm_corpus` with `samples=3` and
`workload_seconds=60.0`, no app `error`.

**Rewrite reconciliation.** The optimized run's retained
`details/loadtime-reports/tracee__monitor.jsonl` holds 162 report rows (all
`pass == wide_mem`): 142 changed load instances, 142 applied sites, instruction
counts 400,640 → 322,310 (−78,330), 20 unchanged rows. All 142 changed workdirs
retain `input.step.0.bin` + `output.next.0.bin` + `report.0.json`; the retained
bytecode's raw `struct bpf_insn` length (8 bytes each) matches the reported
before/after instruction counts for every one, and every before/after image
differs.

**Throughput causality.**

| quantity | value |
|---|---|
| median raw ratio | 0.992749x |
| control A | 0.9962 |
| control B | 0.9815 |
| control median | 0.988867x |
| control-corrected | 1.003926x |

Tracee's fresh workload is a single component-less stress-ng run, so the derived
scalar is the same workload-level `stress-ng: metrc:` bogo-ops column the
step-0021 Tetragon `wide_mem` triplet uses, not Cilium's summed kernel-pktgen
pps. The shared builder served this triplet unchanged; only the row's
`metric_noun` differs.

**Declared constants frozen** to `("0.9927", "1.0039")` at four decimal places.

**Renderer integrity.** `python3 -m py_compile` passes;
`python3 docs/artifacts/render_claim_table.py --self-test` prints
`self-test: OK (13 evidence classes)`. A full-row diff of the rendered table
against `HEAD`'s renderer shows exactly one added line — the new row — and
`tail -1` is `OVERALL AE EVIDENCE: INCOMPLETE`:

```
RQ2 Tracee fresh wide_mem causality + retained bytecode (142 sites)   PASS   docs/artifacts/evidence/rq2-tracee-wide-mem-fresh-causality: wide_mem median stress-ng metrc bogo-ops ratio=0.992749x; no-pass controls ['0.9962', '0.9815'] (median 0.988867x); control-corrected=1.003926x (declared 0.9927/1.0039), 3+3 samples per run; 162 report rows, 142 changed load instances, 142 applied sites, insn 400640->322310 (-78330); bytecode retained for 142/142 changed workdirs, 0 length mismatches, 0 identical images; run status valid=True, controls valid=True, receipt file hashes valid=True
```

The self-test gained a Tracee `wide_mem` case (after the Cilium one) that
mutates the pass gate, the `metric_noun` wording, and the app-stem gate in turn,
each flipping the row off `PASS`. The class count stays 13 because Tracee
`wide_mem` introduces no new derivation class.

## Evidence packaging

The triplet ships as
`docs/artifacts/evidence/rq2-tracee-wide-mem-fresh-causality/` (442 tracked
files; the receipt hashes 441): `receipt.json` with a SHA256 for every retained
file, the normalized `make-corpus.log` plus `controls/null{A,B}/make-corpus.log`,
the two control `metadata.json` + app records, and the optimized run's status
files, shim logs, loadtime plan, report stream, and all 142 changed workdirs'
three bytecode files each. Raw counters only — no aggregation; every number in
the renderer row is derived at render time.

`docs/artifacts/package-atc26.sh` was extended so the archive stages the new
evidence dir (`validationEvidence`), requires its receipt/log/report/workdir/
control files in the clean-extraction existence check, asserts the new row
renders `PASS` from the archived sources alone, and names the triplet in the
archival README. `docs/atc26-artifact-evaluation.md` gained the §7
evidence-inventory row and the §11 fifteenth derivation paragraph; both are
additive and were diffed against current state first.

## Scientific boundary and next action

Latitude, stated plainly.

- The control-corrected ratio is a **controlled measurement, not a speedup
  claim**: the two no-pass controls are matched restarts at the identical 60 s
  duration, so their median (0.9889x) measures restart drift. The corrected
  1.0039x is raw ÷ that median.
- The corrected ratio is **just above 1.0** — the smallest of the three
  `wide_mem` triplets — and, with the two controls straddling 1.0, it is the
  clearest instance yet of why the matched controls matter: the raw ratio alone
  (0.9927x) would read as a regression.
- 142 applied sites is the **smallest** of the three `wide_mem` triplets
  (Tetragon 254, Cilium 164), so this one shows the derivation does not need a
  large rewritten population.
- The row is gated on `enabled_passes == ["wide_mem"]` and on Tracee's own app
  record and report path, so it can never be satisfied by a `map_inline`
  triplet or another application's files.
- `PASS` remains local to the named row. `OVERALL AE EVIDENCE` stays
  `INCOMPLETE` until the `atc26-ae-2` ZIP is published on Zenodo.

The `wide_mem` axis is now closed for the three applications that have an
isolated `wide_mem` run. Further triplets on other passes need only a new
wrapper plus two frozen constants.

## Delivery

Two content commits shipped and pushed to `origin/master`
(`45b055f51..0133e25d2`):

- `2322aa73f` — "evidence: tracee wide_mem fresh causality triplet + retained
  bytecode": the evidence tree plus the frozen declared constants.
- `0133e25d2` — "docs: register tracee wide_mem triplet in renderer, packager
  and AE guide": the renderer wrapper/registration/self-test block, the packager
  staging/required/assertion/README edits, the AE-doc §7 row and §11 paragraph,
  the isolated-basis site-count corrections, and this step-0023 report's
  predecessor edits (step-0021/0022 report count bases).

After the content commits the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
