# BUILD_AND_EVALUATE Step 0025 Report

Date: 2026-09-26
Experiment: extend the **fresh causality-triplet** treatment to a **genuinely
distinct pass pipeline** — the kop-family `lea` pass, the first triplet whose
rewrite is not the shared generic O3 relift under a different name — by
measuring it on Cilium, the densest `lea` producer of the supported apps, with
the same one-optimized-run-plus-two-matched-no-pass-controls shape and the same
retained per-step bytecode plus the consumed `target.json`.
Result: supported — the fresh Cilium `lea` triplet completes all three legs
cleanly, retains bytecode for all 131 changed load instances, and its
control-corrected throughput ratio (0.9827x) is frozen; the renderer row flips
`PARTIAL` → `PASS`, and no other row in the table changes.

## Source ownership and experiment selection

Step 0024 shipped the fourth non-`map_inline` triplet (Tetragon `dce`) and, with
it, closed the "labelled generic pass name" axis: `dce` and `wide_mem` are
byte-identical on the same application, so a fifth generic-name triplet would
add a label, not information. The next axis that adds information is a **pass
whose rewrite is actually distinct**, so the row can assert more than "a
controlled measurement under another name".

`lea` is such a pass. Two independent properties separate it from the generic
aliases, both read from the source rather than inferred from the label:

- `bpfopt` selects per-name LLVM codegen policy for kop passes;
  `default_kop_mode_for_pass` gives `lea` →
  `all=disable,preemit-lea=force,scaled-index-mem=force`, so the codegen is
  selected by the pass name.
- The pass consumes a real per-site `--target` kop map that the shim synthesizes
  with `kopprober` (`bpfopt/shim/shim_loadtime.h`), whereas the generic
  names run `run_llvm_roundtrip(input, nullptr)` and apply the same generic
  repairs.

The densest producer was **measured, not copied**: probing the 179 retained
Cilium inputs on the isolated single-pass basis gives per-kop-sub-pass applied
totals `kop 4980`, `lea 2416`, `endian_fusion 768`, `prefetch 648`,
`bulk_memory 589`, `cond_select 334`, `extract 2`, `rotate 0`, so `lea` is the
densest genuinely-distinct kop axis and this controlled measurement sits on
2416 applied sites. `rotate` (0) and `extract` (2) would have been token
populations; `cond_select`/`endian_fusion`/`bulk_memory`/`prefetch` are smaller
than `lea`.

The pass under test is a policy knob, not a frozen artifact. The triplet used
the already-supported `BPFREJIT_BENCH_PASSES=lea` knob with the same `SAMPLES=3
WORKLOAD_DURATION=60 KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image` shape
every prior triplet used, so nothing about the workload, app runner,
`corpus/driver.py`, benchmark Makefile, runtime-image launch wiring, stressor,
worker count, packet topology, or CPU/duration setting changed.

## Valid result

**All three legs exited 0.** Driver log
`/workspaces/fresh-lea-cilium-logs.driver.log`:

```
=== mi    start 2026-09-26T20:50:45Z ===
=== mi    done  2026-09-26T21:15:20Z rc=0 ===
=== nullA start 2026-09-26T21:15:20Z ===
=== nullA done  2026-09-26T21:38:02Z rc=0 ===
=== nullB start 2026-09-26T21:38:02Z ===
=== nullB done  2026-09-26T22:02:11Z rc=0 ===
=== cilium lea triplet complete 2026-09-26T22:02:11Z ===
```

| leg | run dir | `enabled_passes` | suite | app | `rejit_result.status` |
|---|---|---|---|---|---|
| optimized | `x86_kvm_corpus_20260926_210350_394038` | `["lea"]` | `completed` | `ok` | `ok` |
| control A | `x86_kvm_corpus_20260926_212638_174173` | `[]` | `completed` | `ok` | `skipped` |
| control B | `x86_kvm_corpus_20260926_215101_823717` | `[]` | `completed` | `ok` | `skipped` |

All three are single-app `x86_kvm_corpus` with `samples=3` and
`workload_seconds=60.0`, no app `error`. The optimized run's `source_commit` is
`3b6ab6f1a2286f62b4fda0652b600ac612853827`, `HEAD` at launch; the correction
commit `309580500` landed at 21:08, after the 21:03 launch, and touches only
prose (no runtime image), so it does not affect this evidence.

**Rewrite reconciliation.** The optimized run's retained
`details/loadtime-reports/cilium__agent.jsonl` holds 169 report rows (all
`pass == lea`): 131 changed load instances, 2416 applied sites, instruction
counts 159,896 → 160,582 (+686), 38 unchanged rows. All 131 changed workdirs
retain `input.step.0.bin` + `output.next.0.bin` + `report.0.json` + the
`target.json` the pass consumed; the retained bytecode's raw `struct bpf_insn`
length (8 bytes each) matches the reported before/after instruction counts for
every one, and every before/after image differs. The `+686` sign is the
opposite of the generic relift's instruction *reduction* and is the visible
signature of a forced LEA expansion (e.g. `loadtime_3648_67` 605 → 626), which
is additional evidence that this pipeline is not the shared generic relift.

**Throughput causality.**

| quantity | value |
|---|---|
| median raw ratio | 1.023599x |
| control A | 1.1049 |
| control B | 0.9783 |
| control median | 1.041573x |
| control-corrected | 0.982743x |

Cilium's fresh workload is two kernel-pktgen components, so the derived scalar
is the summed kernel-pktgen pps, the same rate shape as the Cilium `wide_mem`
triplet rather than the component-less stress-ng shape. The shared builder
served this triplet unchanged; only the row's `pass_name`, `metric_noun`, and
the frozen constants differ.

**Declared constants frozen** to `("1.0236", "0.9827")` at four decimal places.

**Renderer integrity.** `python3 -m py_compile` passes;
`python3 docs/artifacts/render_claim_table.py --self-test` prints
`self-test: OK (13 evidence classes)`. A full-row diff of the rendered table
against `HEAD`'s renderer shows exactly one added line — the new row — and
`tail -1` is `OVERALL AE EVIDENCE: INCOMPLETE`:

```
RQ2 Cilium fresh lea causality + retained bytecode (2416 sites)   PASS   docs/artifacts/evidence/rq2-cilium-lea-fresh-causality: lea median summed kernel-pktgen pps ratio=1.023599x; no-pass controls ['1.1049', '0.9783'] (median 1.041573x); control-corrected=0.982743x (declared 1.0236/0.9827), 3+3 samples per run; 169 report rows, 131 changed load instances, 2416 applied sites, insn 159896->160582 (+686); bytecode retained for 131/131 changed workdirs, 0 length mismatches, 0 identical images; run status valid=True, controls valid=True, receipt file hashes valid=True
```

The self-test gained a Cilium `lea` case (after the Tetragon `dce` one) that
mutates the pass gate (rejecting a `wide_mem` run), the `metric_noun` wording,
and the app-stem gate in turn, each flipping the row off `PASS`. The class count
stays 13 because the `lea` triplet introduces no new derivation class — it is
the same shared builder.

## Evidence packaging

The triplet ships as
`docs/artifacts/evidence/rq2-cilium-lea-fresh-causality/` (540 tracked files; the
receipt hashes 539): `receipt.json` with a SHA256 for every retained file, the
normalized `make-corpus.log` plus `controls/null{A,B}/make-corpus.log`, the two
control `metadata.json` + app records, and the optimized run's status files,
shim logs, loadtime plan, report stream, and all 131 changed workdirs' three
bytecode files plus the consumed `target.json`. Raw counters only — no
aggregation; every number in the renderer row is derived at render time.

`docs/artifacts/package-atc26.sh` was extended so the archive stages the new
evidence dir (`validationEvidence`), requires its receipt/log/report/workdir/
`target.json`/control files in the clean-extraction existence check, asserts the
new row renders `PASS` from the archived sources alone, and names the triplet in
the archival README. `docs/atc26-artifact-evaluation.md` gained the §7
evidence-inventory row 406 and the §11 seventeenth derivation paragraph; both are
additive and were diffed against current state first. The §7 "Labelled pass names
vs distinct pipelines." note's forward reference was corrected from "below" to
"in the last row above" because the new row now sits above it.

## Scientific boundary and next action

Latitude, stated plainly.

- The control-corrected ratio is a **controlled measurement, not a speedup
  claim**: the two no-pass controls are matched restarts at the identical 60 s
  duration, so their median (1.0416x) measures restart drift. The corrected
  0.9827x is raw ÷ that median.
- The corrected ratio is **close to neutral** (0.9827x) and the two controls
  straddle 1.0 (1.1049x, 0.9783x), a **wider control spread than the other
  triplets**; the raw ratio alone (1.0236x) would read as a small gain while the
  matched controls show it is restart drift. The row's claim is the controlled
  measurement, exactly as with the Tracee `wide_mem` and Tetragon `dce`
  triplets.
- 2416 applied sites is the **largest genuinely-distinct kop population
  available** and an order of magnitude above the largest generic-name triplet
  (254), so the distinct-pipeline claim is shown on a dense population.
- This is the first triplet whose pass is **not the shared generic relift**: the
  per-name codegen policy and the consumed `--target` kop map are the mechanism,
  and the `+686` instruction change against the generic relift's reduction is
  the visible signature. The retained `target.json` makes the rewrite replayable
  from the archive.
- The row is gated on `enabled_passes == ["lea"]` and on Cilium's own app record
  and report path, so it can never be satisfied by a `wide_mem`, `dce`, or
  `map_inline` triplet or another application's files.
- `PASS` remains local to the named row. `OVERALL AE EVIDENCE` stays
  `INCOMPLETE` until the `atc26-ae-2` ZIP is published on Zenodo.

Further triplets on other passes need only a new wrapper plus two frozen
constants; the `lea` axis on Cilium is now closed.

## Delivery

Two content commits to `origin/master`: the evidence tree plus the frozen
declared constants (`41a59a507`), and the renderer/packager/AE-guide registration
plus this step-0025 report. After the content commits the archival ZIP is
rebuilt so `ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
