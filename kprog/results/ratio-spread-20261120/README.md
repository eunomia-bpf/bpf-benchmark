# What a single per-call ratio can and cannot say (OMP 2026-11-20T06:22Z)

PERF recorded an OTel per-call ratio of **0.796x** (baseline 4354.968 → 5470.280 ns) from one guest and
called it a regression. This measures the spread that one run has to be read against.

Method is the project's own (`rejit/docs/evaluation.md` §5): join the two phases **by program identity**
(`name`, `type` — ids differ across phases), drop programs with `min(run_cnt_delta) < 100`, take each
program's `post/baseline` per-call ratio, then the geometric mean over retained programs. One figure per
`corpus/results/x86_kvm_corpus_*/` run; `measure.py` in this directory reproduces every number.

## The answer, with the right controls

`SAMPLES=3` only (the frozen sample count), grouped by calendar day so each estimate comes from one
configuration:

| app | 05-07/05-08 | mid-period range | 11-12 … 11-17 | verdict |
|---|---|---|---|---|
| OTel | 0.986 / 0.806 | 0.979 – 1.114 | 0.433, 0.630 | **unstable**, whole range 0.43–1.11 |
| Cilium | 1.000 / 0.962 | 0.748 – 1.033 | **0.394 – 0.472** | large improvement in November |
| BCC | 1.016 / 1.016 | 0.973 – 1.045 | 0.968 – 1.094 | **flat at 1.00**, always |
| Tracee | 0.876 / 0.816 | 0.993 – 1.007 | **0.715, 0.836** | real, moderate improvement |
| Tetragon | 0.995 / 1.004 | — | — | flat (only two days with ≥3 runs) |
| Katran | — / 0.987 | 0.876 – 1.054 | 0.923 – 1.079 | **flat at ~0.97**, 19 day-clusters |

## What this establishes

1. **OTel's 0.796 cannot be called a regression.** One day of OTel `SAMPLES=3` runs has read 0.433 and
   another 0.630, while May read 0.986–1.114; the app moves by ±50 % between days with no code change in
   between. A single 0.796 sits comfortably inside that.
2. **OTel is the least quotable app of the six.** Its retained population is mostly **one or two
   programs** per run, so its "geomean" is close to a single measurement. Any OTel ratio needs repeated runs
   on one image before it is cited.
3. **The apps whose direction is solid are solid for the wrong reason or the right one.** BCC is stable
   and flat at 1.00 across 16 day-clusters (no headroom found in two months). Katran is stable at ~0.97
   across 19 day-clusters. Cilium and Tracee do show a genuine November move (Cilium 0.39–0.47, Tracee
   0.72–0.84) — those two are where the per-call target is actually visible.
4. **No app's stable cluster reaches the 0.80 target yet.** Cilium's November clusters do (0.394, 0.439,
   0.472 on 11-10/11-16/11-17), which is the strongest positive evidence in the record.

## The current image, app by app (2026-11-20 runs, corrected join)

| app | run geomeans on 11-20 | retained | post/baseline calls |
|---|---|---|---|
| Tracee | 0.57, 0.59, 0.77 | 38–41 | 1.11 – 1.71 |
| Cilium | 0.88, 0.88, 0.94 | 2 | — |
| BCC | 0.94, 0.96, 0.97 | 13 | — |
| Katran | 0.96, 0.98, 0.99 | 1 | — |
| OTel | 1.03, 1.04, 1.05 | 1 | — |
| Tetragon | 0.79, 1.75 | 15 | — |

Read with both populations in mind: Tracee's 0.57–0.59 come from the runs whose post arm executed 1.65–1.71x
the calls, so its honest current figure is nearer the 0.77 of the calibrated run; Cilium and Katran retain
one program, so their rows are single measurements. What the table does show unambiguously is that **no app
is far below 1.0 on the current image except Tracee**, and OTel now sits slightly above it.

## The two arms must execute comparable work

A per-call ratio is only meaningful when both arms execute the same workload. Comparing `sum(run_cnt_delta)`
between the phases exposes where they do not:

| app | runs | post/baseline call count (median) | runs within 0.90–1.15 |
|---|---|---|---|
| BCC | 91 | 1.01 | 82 |
| Katran | 101 | 1.02 | 92 |
| OTel | 127 | 1.00 | 108 |
| **Tracee** | 71 | 1.04 (quartiles 0.96–1.25) | 38 |
| **Cilium** | 87 | **2.77** | 33 |

Cilium's post arm executes **2.8x** the baseline arm's calls in the median run, and the inflation is not a
property of short runs: three 180 s × 3-sample runs with 53/53 programs still read above 1.5x. Any Cilium
per-call figure from a run with unequal counts is therefore suspect, and Cilium is the app where the
calibration check matters most. `population.json` holds the counts.

## Why some apps scatter and others do not: the retained population

### `native_tracer_e` (the truncated name): two families, not a trend

Kernel program names are truncated to 15 characters, so OTel's `native_tracer_entry` appears as
`native_tracer_e` (the exit program is distinct in practice; no phase holds two `native_tracer_*` programs).
Grouped by the **post** arm's JITed size, the program has exactly two behaviours:

| post JITed size | post ns/call | ratio |
|---|---|---|
| 7508–7773 B | 137–276 ns | **0.04–0.11x** |
| 2729–4603 B | 3010–4606 ns | 0.94–1.23x |

The baseline arm is stable at 3809–3815 B and 3200–4000 ns throughout, so the difference is entirely in the
post arm. Day by day the ratio is 0.07 (05-28/29), 1.0 (05-31, 06-04), 1.0 (09-26), 0.07–0.11 (11-07…11-13,
11-15), 1.0 (11-14), 0.97 (11-16), 0.94 (11-17), 1.03–1.23 (11-18…11-20).

So the two families are different compiled bodies — 7510 B at ~200 ns against 3815 B at ~3200 ns — **but the
faster one is broken** (see below), so its speed is not a target to reproduce. (An earlier draft called 11-14 a regression; that was wrong —
11-14 is just the non-7510 family. An even earlier draft blamed a low-count second program; that program is
real but it is not what moves this ratio.)

The same B input produces both lengths, but size is a provenance marker, not the mechanism. In the runs' shim
logs the loaded program is identical across the dates — `native_tracer_e`, `insn_cnt=1322`, tag
`26449268576adffc`, original `xlated_len=5904` — while the compiled body is 7510 B on 11-12 and 2650–2729 B
on 11-19/11-20:

```
2026-11-12  jit-info native ... tag=26449268576adffc jited_len=7510 xlated_len=24
2026-11-20  jit-info native ... tag=26449268576adffc jited_len=2729 xlated_len=24
```

Both are native images (the `xlated_len=24` stub), both replaced the same original. But the 7510 B body is
**not a correct fast implementation**: `equal-work-20261113/report.md` pairs a run carrying it and records the
program-owned counters going **913,099,438 → 0 unwind attempts** and **840,462,900 → 0 frames**, with register
errors 325,721 → 74,119,936 and empty stacks 22,331 → 65,351,909. It ran 12x faster because it stopped
unwinding.

The counters carry the same signature, independently of the equal-work report: in a run with the 7510 B body
**zero** post-arm entries report `bytes_xlated > 100`, while a 11-20 run reports four — and the three unwind
programs among them all have `run_cnt_delta = 0` (only `tracepoint__sch` fires, 38 calls):

```
2026-11-12 post arm: entries with real xlated body = 0
2026-11-20 post arm: perf_unwind_nat/-hot/-php report 53880/32824/29288 bytes, cnt = 0
```

Not a single-run reading: across the 39 runs whose post entry is in the small-body family (2650–3932 B,
excluding 3815 B where the entry is the baseline body itself), the median ratio is **1.05** and **26 of 39**
are slower than the baseline JIT. So on this program the current native image is, on average, 5 % *slower* than
the JIT it replaces — while doing correct work, which is exactly what the broken family was not doing.

So the fast family must not be restored as-is; it is a broken reference. What the record does establish is the
opposite direction of the one I first drew: today's ~2700 B body runs at 3700–4600 ns against the baseline
JIT's ~3200 ns, i.e. the current native body is *slower than the JIT it replaces* on this program while doing
correct work. That gap — not the 7510 B shape — is the optimization target.

(Perf's `perf-history-review-20261120` corrects three further points in earlier drafts of this file: the
11-13 boundary is not firm, since that same day contains both 0.0717 and 0.9959; the 7510 B body's speed is
explained by unequal work; and `measure.py`'s `(name,type)` key dropped duplicate pairs. That last one was a
real bug in this record and is fixed: both phases are now grouped by key and members are paired in count
order, which reproduces the existing analyzer.)

The §5 join keeps programs with `min(run_cnt_delta) >= 100` in both phases. That population, per run, decides
how much averaging a run does:

| app | runs measured | retained programs (median / max / min) |
|---|---|---|
| Tracee | 75 | **40 / 42 / 33** |
| Tetragon | 51 | 15 / 31 / 1 |
| BCC | 91 | 13 / 15 / 11 |
| Cilium | 88 | 2 / 2 / 2 |
| OTel | 127 | **1 / 2 / 1** |
| Katran | 101 | 1 / 1 / 1 |

(These counts are from the corrected join. Before it, duplicate `(name,type)` members were collapsed and
Tracee appeared to retain 24 and Tetragon 2; the true populations are larger.)

For OTel, Cilium and Katran the "geomean" is a **single program's ratio** — a per-run standard deviation of
0.2–0.5 is then expected and carries no information about the app. For Tracee it averages over 40 programs,
which is why its repeated figures cluster (0.56–1.02 for 33 of 37 runs) while OTel's wander over a 5x range.
Any comparison between apps must carry this column; `population.json` holds it.

## Tracee, measured on its own: the target is being met

The table above pools all history. Restricting to runs from 2026-11-16 on (current code) with the §5 join
retaining ≥20 programs gives **37 runs**: median run geomean **0.834**, geomean **0.923**, and **33 of 37
faster**. These reproduce the existing `analysis/corpus_analyze.py` result exactly (PERF,
`perf-history-review-20261120`), which is the cross-check that matters.

Sub-setting on whether the two arms executed comparable work (post/baseline calls within 0.90–1.15) gives 18
calibrated runs at median 0.863 and 19 unequal ones at 0.748. **This is an exploratory subgroup, not a
calibration procedure**: under a duration-based workload a throughput change itself moves the call count, and
equal totals can still hide different program mixes. Do not treat 0.90–1.15 as a validity gate, and do not
drop the unequal runs.

So the honest single sentence is: **Tracee is faster in 33 of 37 recent runs, median 0.834 per call** — about
17 %, which is short of the 20 % target, on the runs where nothing is excluded.

Two earlier drafts of this section were wrong and are corrected here: the first quoted geomean 0.805 over
"33 non-outlier runs" after removing four outliers, and the second quoted 0.91 from the calibrated subgroup.
The full-population median above is the number to quote.

Caveat with its size: across 71 Tracee runs the post arm executes a median 1.04× the baseline arm's calls
(quartiles 0.96–1.25, 12 runs above 1.3×). Those 12 runs do more work in the post arm, so their per-call
figures flatter the change; the median run is calibrated. Compare OTel (1–2 retained programs, sd 0.36) and Cilium (sd 0.23): Tracee is the
only app whose *repeated* measurement clears the target. `tracee-november.json` holds each run's figure.

## A methodological trap found while measuring (affects quotes, not code)

Ratios computed by pooling `sum(run_time)/sum(run_cnt)` across *all* programs of a phase compare different
program sets whenever the phase composition differs, and disagree grossly with §5 — Cilium reads 1.20x by the
pooled form where §5 gives 0.79x. Only the §5 per-program join is used here. Any older figure produced the
pooled way should be re-derived before it is compared with these.

This record changes no number already quoted from a specific run. It says which comparisons a single run can
decide.
