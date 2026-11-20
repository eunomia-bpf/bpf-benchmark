# OTel in the main-configuration recipe (2026-11-20 08:11 UTC, source 5944c772b)

Run x86_kvm_corpus_20261120_081247_049639, recipe kprog/results/lto-apps-20261119/Makefile
(APP=otelcol-ebpf-profiler/profiling, 3 x 180 s per arm, stats on), started by omp under `flock -x` on
locks/timing after the coordinator's six-app read loop released it.

- Coverage: 14 programs, 14 native installed, 0 failed, 0 kept on eBPF. 7 ran checked native (B generated and
  passed the stock verifier); 7 ran direct native. So the numbers below cover 14/14 of the programs this app
  installs, which is the condition that makes them readable.
- `native_tracer_e` (the program that carries the app's calls): 3214 -> 3384 ns/inv, **0.950x**, i.e. the
  native body is 5 % slower per call than the JIT it replaces. Post body 2650 B against JIT 3815 B. This
  independently reproduces the median of 1.05 over the 39 runs of the same family in
  `kprog/results/ratio-spread-20261120/`, now on the accepted-coverage recipe and on 180 s samples. It is the
  measurement to fix, and it is not a sampling artefact.
- `tracepoint__sched_process_exit`: 1962 -> 1950 ns/inv, 1.006x, the only other program with a retained pair.
- Call parity: 418 697 682 base against 408 195 517 post, 0.97, so the two arms did equal work and the per-call
  ratio is comparable.
- Third independent confirmation: the coordinator's 3 x 60 s stats-on run of the same change (todo line
  2026-11-20T08:21:06Z) reads OTel at 0.945x per call. Three measurements of different sample counts and
  different recipes (0.945, 0.950, and the 1.05 median over 39 runs) agree, so the deficit is a property of the
  emitted body, not of a recipe.
- The 7 direct-native programs (B rejected) are why OTel's coverage matters for any claim from this app: the
  ratio above is the accepted-B subset, not the whole app.

Raw: /workspaces/kprog-raw/omp/lto-otel-20261120T0811Z (service archive with the verifier logs).
## The 5 % is a regression, not a constant (OMP 2026-11-20)

The baseline JIT for `native_tracer_e` is the same program on every date (3815 B, `insn_cnt` 1322, tag
`26449268576adffc`), so its ns/inv is the control. Grouping the surveys of `ratio-spread-20261120` by date,
with the JIT-controlled medians:

| date | JIT body B | JIT ns/inv | native body B | native ns/inv | ratio |
|---|---|---|---|---|---|
| 11-17 | 3815 | 3208 | 3542 | 3010 | **0.94** |
| 11-18 | 3815 | 3231 | 3567 | 3322 | 1.03 |
| 11-19 | 3815 | 3345 | 2729 | 3704 | 1.11 |
| 11-20 | 3815 | 3455 | 2729 | 4539 | 1.31 |

(11-20 covers 15 runs, whose median OTel per-call ratio is 1.08; the 4539 ns outlier above is one run. Use the
median, not the row, as the figure for that day.)

The emitter was **faster than the JIT** on 11-17 with a 3542 B body (0.94, and 8 of 11 runs that day were at or
below 1.00), and it is slower on 11-19 and 11-20 with a 2729 B body for the same JIT. So on this program the
deficit is not a fixed property of the design, and the 11-17 shape is an existence proof that this program can be
emitted natively faster than its JIT. That is the target to recover: 0.94, not merely 1.00.

**The window, time-ordered (OMP).** Small-body runs of the 11-17 .. 11-18 days, by completion time:

```text
11-17 01:18  3362 B  0.94      11-17 12:11  3932 B  0.93
11-17 03:14  3534 B  0.93      11-17 16:57  3798 B  1.38
11-17 03:39  3534 B  0.97      11-17 18:53  3798 B  0.85
11-17 04:08  3534 B  0.91      11-18 05:19  3567 B  1.05   <- first after the compaction commits
11-17 05:23  3542 B  0.85      11-18 08:29  3567 B  1.01
11-17 06:11  3542 B  0.92      11-18 10:01  3567 B  1.01
11-17 06:39  3542 B  0.91      11-19           2729 B  1.11 (8 runs)
11-17 07:12  3599 B  0.94      11-20           2729 B  1.08 (15 runs)
11-17 08:30  3591 B  0.98
```

10 of the 12 runs before 11-18 were at or below 1.00, one of them as low as 0.85; after the compaction commits
of 11-17 21:15 .. 22:47 (`2c46d5c52`, `b44b673aa`, `795483604`, `a4d1e0588`) no run returns below 1.00. So the
regression window is bounded on both sides by real runs, and the compaction commits are inside it, together with
`07d9c4c96` (11-18 20:31), which deleted the hand-written helper reimplementations and replaced inline
probe-read/ktime bodies with relocated calls to the real helpers.

**Checked, and it holds (OMP).** A `bytes_xlated` of 24 on the post side does not mean "kept on the JIT": the
11-20 post shim log records `native-loader replaced prog=...` for **14 of 14** programs, unwind programs included,
and 11-17 replaced 14 of 14 as well. `bytes_xlated` is the replaced program's own xlated size as the loader
reports it (24 B for the entry, 5296 B for `perf_unwind_sto`), so the two dates do have the same coverage and the
table above compares emitter versions after all. Within 11-20 the identical-coverage readings are 0.950x (180 s
arm) and 0.945x (coordinator), consistent with the 1.31 of the 11-20 row's own run.
