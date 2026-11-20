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