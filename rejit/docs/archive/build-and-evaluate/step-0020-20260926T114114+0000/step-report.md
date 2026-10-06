# BUILD_AND_EVALUATE Step 0020 Report

Date: 2026-09-26
Experiment: resolve the last unresolved RQ1 row — the paper's **0.99× x86
object-load overhead** claim — by root-causing the field the paper's Section 7.1
sentence actually describes, and by re-measuring the fresh-generation paired
open+load ratio under the paper's own micro protocol (`SAMPLES=3 WARMUPS=1
INNER_REPEAT=100000`) to test whether the fresh-generation gap is sampling noise.
Result: supported on both counts — the retained May 14 pair reproduces the paper's
0.99× on the open+load (`compile_ns`) quantity while the bare `object_load_ns`
field rounds to 1.00×, and the repeated-sample run confirms the fresh-generation
1.14×/1.17× is **not** reduced by additional samples.

## Source ownership and experiment selection

The RQ1 object-load row was the last `PARTIAL` micro row whose status could be
resolved by derivation rather than by a new measurement. Two facts had to be
established before any edit:

1. **Field semantics.** The paper
   (`docs/paper/sections/7-evaluation.tex:74`) names `object_load_ns` but
   parenthesizes it as "covering verification and JIT". In
   `runner/src/kernel_runner.cpp` the load region is two separately timed
   phases and `sample.compile_ns` is defined at line 1140 as
   `elapsed_ns(object_open_start, object_open_end) +
   elapsed_ns(object_load_start, object_load_end)` — i.e. the paper's
   "verification and JIT" quantity is open+load, not the bare load field.
2. **Value.** Over the exact 62-name intersection of the two retained May 14
   ReJIT runs and the April 29 population run
   (`micro/results/x86_kvm_micro_20260429_035938_203074`), the bare field gives
   0.995157 / 0.997839 and open+load gives 0.994270 / 0.990300. Both open+load
   values round to 0.99×; both bare values round to 1.00×.

A second question was whether the fresh-generation rows (1.161575× / 1.223405×
bare) were a sampling artifact: the prior fresh runs were `SAMPLES=1`. The
paper's own protocol is `SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000`, so one run
under that exact protocol settles it.

No frozen artifact changed: no workload, app runner, `corpus/driver.py`,
benchmark Makefile, runtime-image wiring, stressor, worker count, packet
topology, or CPU-count/duration setting was touched. `make micro` is the only
entrypoint, invoked with the retained run's own documented knobs.

## Valid result

**Decision: derive both quantities, gate on the paper-matched one.** The paper's
claim is not silently redefined — the row reports the bare `object_load_ns`
geomean beside the open+load geomean, and only the status is gated on open+load.

**Retained 62-case row.** The 62-case block in `micro_claim_rows` now:
requires both `object_open_ns` and `object_load_ns` positive per sample (a case
missing either is dropped), derives `median_object_compile_ns(data, runtime)`
over the same 62 names, and computes two geomeans — bare load and open+load.
Status is `PASS` iff **both** runs' open+load rounds to 0.99× **and** both pass
their live `micro_run_provenance_ok` check. The renderer prints:

```
RQ1 x86 62-case object-load overhead (paper 0.99x)  PASS
May14 ReJIT runs restricted to Apr29 62-name set (excludes katran_like); status on the
paper-matched open+load (compile_ns = object_open_ns + object_load_ns, evaluation sec 7.1
'verification and JIT') quantity: x86_kvm_micro_20260514_031744_210343=open+load 0.994270x
(rounds 0.99x), bare object_load_ns 0.995157x (rounds 1.00x, provenance valid=True);
x86_kvm_micro_20260514_181806_133778=open+load 0.990300x (rounds 0.99x), bare
object_load_ns 0.997839x (rounds 1.00x, provenance valid=True); open+load rounds to paper
0.99x=True; the bare object_load_ns field rounds to 1.00x in both runs;
population=micro/results/x86_kvm_micro_20260429_035938_203074/details/result.json
```

**Repeated-sample fresh run.** `x86_kvm_micro_20260926_105108_035832` was
launched through `make micro` under the paper's protocol
(`env PLATFORM=kvm ARCH=x86 RUNTIMES="kernel kernel_rejit" SAMPLES=3 WARMUPS=1
INNER_REPEAT=100000 make micro -o runtime-kernel-image`); the supervising job's
log records `start 2026-09-26T10:46:53Z` → `done 2026-09-26T11:02:35Z rc=0`.
It is registered as a third `FRESH_LOADTIME_RUNS` entry whose per-case value is
the median over that case's retained samples, and whose evidence string reports
the sample count read from the run itself:

| run | samples/case | paired cases | open+load geomean | bare `object_load_ns` geomean |
|---|---|---|---|---|
| `..._20260924_231824_136293` (full-x86) | 1 | 29 | 1.132157 (1.13×) | 1.161575 (1.16×) |
| `..._20260925_002201_525373` (kop) | 1 | 29 | 1.193679 (1.19×) | 1.223405 (1.22×) |
| `..._20260926_105108_035832` (full-x86, paper protocol) | 3 | 29 | **1.140258 (1.14×)** | **1.169998 (1.17×)** |

All three fresh rows stay `PARTIAL` against the paper's 0.99×, and the new row
agrees with the single-sample pair: repeated sampling does not shrink the
fresh-generation gap. The per-case-dominated ratios (`simple_packet` 2.155×,
`simple` 1.890×, `flow_5tuple_rss_hash` 1.784×) still point at a near-constant
per-case `bpfopt` subprocess cost inside the timed load region, which is a
generation property, not sample noise.

**Renderer integrity.** `python3 -m py_compile` passes;
`python3 docs/artifacts/render_claim_table.py --self-test` prints
`self-test: OK (13 evidence classes)`. The self-test gained one case: a
repeated-sample fixture whose rejit samples are `{open 99, load 990}`,
`{open 99, load 9000}`, `{open 99, load 990}` against `{open 100, load 1000}`,
asserting the row is `PASS`, reports `3 samples/case`, and derives
`0.990000x` — i.e. the row takes the **median**, so the outlier sample cannot
move it. The 62-case fixture assertions were aligned to the new evidence
wording (`open+load rounds to paper 0.99x=…`).

A full-row diff of the rendered table against the pre-edit renderer
(`git show HEAD~2:docs/artifacts/render_claim_table.py`) shows exactly the
intended changes and nothing else: line 17 flips `PARTIAL` → `PASS` with the
new dual-quantity evidence; lines 37–38 keep `PARTIAL` but report both
quantities and the sample count; line 39 is the one added repeated-sample row.
`OVERALL AE EVIDENCE` remains `INCOMPLETE`.

## Evidence packaging

The repeated-sample run is retained in-tree at
`micro/results/x86_kvm_micro_20260926_105108_035832/` with the same three-file
shape as the two single-sample fresh runs (`metadata.json`,
`details/result.json`, `details/progress.json`; the `details/` dir also holds
`code_compare/` and `jit_dumps/`, which the prior fresh runs also retained
untracked). It is raw counters only — no aggregate, ratio, or summary; every
number in the renderer row is derived at render time.

The AE document was updated **additively**: the claim-inventory row 458 now
names the open+load quantity and the `PASS` status; the 62-case paragraph
(600–617) documents the field-semantics finding and keeps the existing
"historical-name mapping is plausible, not proven" caveat; the fresh-run
paragraph documents the third run and the non-noise conclusion; limitation 5
carries the same dual-quantity values; the §12 Reproduced cell records the
derived 0.99× and the repeated-sample 1.140×. The RQ2 `/loadtime-reports` search
sentences that shared the 62-case paragraph were preserved verbatim (an earlier
replacement had dropped them; they were re-added before commit).

## Scientific boundary and next action

Latitude, stated plainly.

- The 0.99× reproduction rests on a **historical-name mapping** (May 14 runs
  restricted to the April 29 62 names) that the paper does not itself enumerate.
  It is plausible, not proven to be the paper's exact population, and the AE doc
  says so.
- The **field-semantics reading is inferred**, not stated by the paper: the
  paper names `object_load_ns` and describes it as "covering verification and
  JIT", and the runner's `compile_ns` is exactly that pair. Both quantities are
  reported so a reader who rejects the inference still sees the bare-field
  1.00×.
- The fresh-generation rows are a **different host/toolchain generation** (29
  cases, 2 names in common with the May 14 runs) and are never merged with the
  62-case row or the paper's figures.
- The repeated-sample run is `SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000`, the
  framework's authoritative micro policy; it invents no additional validity
  gate. Three samples bound sample noise for this configuration; they do not
  constitute a confidence interval.
- `PASS` remains local to the named row. `OVERALL AE EVIDENCE` stays
  `INCOMPLETE` until the `atc26-ae-2` ZIP is published on Zenodo.

The remaining natural axis is the same per-app causality triplet under a
different pass (`wide_mem`, `const_prop`, `dce`); the retained report streams
show non-`map_inline` sites for every app, so the `fresh_causality_rows` builder
would be reused unchanged. It was not needed for this increment.

## Delivery

Two commits shipped and pushed to `origin/master` (`4a3c7df71..a5803c68a`):

- `4063d23bc` — "Derive the paper-matched open+load quantity for the RQ1
  object-load claim": the 62-case dual-quantity derivation and status gate, the
  `FRESH_LOADTIME_RUNS` third entry with `_paired_sample_count`, the rewritten
  object-load self-test fixtures, and the additive AE-doc narrative.
- `a5803c68a` — "Retain the repeated-sample fresh paired micro run": the raw
  `metadata.json` / `details/result.json` / `details/progress.json` for
  `x86_kvm_micro_20260926_105108_035832`.
- this step-0020 report.

After the content commits the archival ZIP is rebuilt so
`ARTIFACT_MANIFEST.json.superprojectCommit` matches the new `HEAD`.
