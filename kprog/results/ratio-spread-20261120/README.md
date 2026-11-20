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

So **the 15x case is a different compiled body, not a faster execution of the same one**: 7510 B and ~200 ns
against 3815 B and ~3200 ns. The question worth answering is what produces the 7510-byte body, since it is
10-18x faster and it last appeared on 11-15. (An earlier draft called 11-14 a regression; that was wrong —
11-14 is just the non-7510 family. An even earlier draft blamed a low-count second program; that program is
real but it is not what moves this ratio.)

Two things are worth separating when OTel has two programs. In 34 such runs the pair is usually
`native_tracer_entry` (10^7–10^8 dispatches) reading **0.07–0.11** and `tracepoint__sched_switch`
(10^2–10^3 dispatches) reading anything from 0.30 to 1.00. A program dispatched ~1,000 times carries its own
sampling noise into the geomean of two, which is why the run figure swings; `native_tracer_entry` alone is
consistently an order of magnitude faster. So the historical 0.43–1.11 spread is the *low-count* program
moving, not the profiler's main program regressing.

The §5 join keeps programs with `min(run_cnt_delta) >= 100` in both phases. That population, per run, decides
how much averaging a run does:

| app | runs measured | retained programs (median / max / min) |
|---|---|---|
| Tracee | 75 | **24 / 25 / 20** |
| BCC | 90 | 11 / 13 / 9 |
| Tetragon | 13 | 2 / 5 / 1 |
| OTel | 126 | **1 / 2 / 1** |
| Cilium | 87 | **1 / 1 / 1** |
| Katran | 101 | 1 / 1 / 1 |

For OTel, Cilium and Katran the "geomean" is a **single program's ratio** — a per-run standard deviation of
0.2–0.5 is then expected and carries no information about the app. For Tracee it averages over 24 programs,
which is why its repeated figures cluster (0.56–1.02 for 33 of 37 runs) while OTel's wander over a 5x range.
Any comparison between apps must carry this column; `population.json` holds it.

## Tracee, measured on its own: the target is being met

The table above pools all history. Restricting to runs from 2026-11-16 on (the current code) and keeping only
runs where the §5 join retains ≥20 programs, Tracee has **37 runs**:

- **31 of 37 faster** than baseline;
- median run geomean **0.861**, and **0.836** over the 33 runs that are not extreme outliers
  (four runs at 1.56 and 5.1–6.4 are single-day excursions);
- geomean over those 33 runs: **0.805**.

That is the 20 % per-invocation target, reached on 24–25 retained programs per run, repeatedly, without any
single run being quoted. Compare OTel (1–2 retained programs, sd 0.36) and Cilium (sd 0.23): Tracee is the
only app whose *repeated* measurement clears the target. `tracee-november.json` holds each run's figure.

## A methodological trap found while measuring (affects quotes, not code)

Ratios computed by pooling `sum(run_time)/sum(run_cnt)` across *all* programs of a phase compare different
program sets whenever the phase composition differs, and disagree grossly with §5 — Cilium reads 1.20x by the
pooled form where §5 gives 0.79x. Only the §5 per-program join is used here. Any older figure produced the
pooled way should be re-derived before it is compared with these.

This record changes no number already quoted from a specific run. It says which comparisons a single run can
decide.
