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

### What `native_tracer_entry` actually does, day by day

Per-day median ratio for that program, from the full record (`measure.py` reproduces the pipeline):

| period | median | note |
|---|---|---|
| 2026-05-03 … 05-23 | 0.96 – 1.16 | **~1.00**, ordinary scatter |
| 2026-05-28 … 05-29 | 0.07 | short window, 14x faster |
| 2026-05-31 … 06-05 | 0.97 – 1.12 | back to ~1.00 |
| 2026-06-21 … 06-22 | 0.11 | short window, 9x faster |
| 2026-06-27 … 10-01 | 0.99 – 1.09 | ~1.00 |
| 2026-11-06 | 1.01 | ~1.00 |
| 2026-11-07 … 11-13 | 0.08 – 0.12 | short window, 12x faster |
| **2026-11-14 … 11-20** | **1.01 – 1.08** | **back to ~1.00** |

So the program's **normal value is 1.00**, and the 0.07–0.12 readings are three short windows
(05-28/29, 06-21/22, 11-07…11-13) rather than the norm. An earlier draft of this file called 11-14 a
regression; that was wrong — 11-14 returned to the value May and June had. The interesting question is the
opposite one: what made the program 10x faster in those three windows, and why did it stop.

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
