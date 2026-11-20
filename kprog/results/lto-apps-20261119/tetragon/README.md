# Tetragon in the main-configuration recipe (2026-11-20 14:38 UTC, source 87ba2b8ba)

Re-run of the 11:51 arm after the base's verified-loader was rebuilt from HEAD and replaced in place. Run
x86_kvm_corpus_20261120_143937_810796, recipe kprog/results/lto-apps-20261119/Makefile
(APP=tetragon/observer, 3 x 180 s per arm, stats on).

- Coverage: 142 requests, **141 native installed** (21 checked-sim-c, 120 direct-native), 1 failed. The post
  shim log records `native-loader replaced` 141 times and zero `kept on eBPF`. Against the stale-loader arm's
  46 of 134, this is the whole difference: the loader was the only cause.
- The stale base: `/workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader` had been built
  11-19 11:59, before 02429959e (11-20 02:57) taught the link schema to bind `current_task`, `cpu_number` and
  `jiffies_64`. `strings` on it showed only `ktime_get_mono_fast_ns`. The guest ran a current native-link
  against that plan, so every object with a `current_task` GOT relocation failed. Fixed in place, same base.
- Per call: **not quotable from this run.** The post arm recorded 129 program entries against the baseline's
  287, and its hottest baseline program (`generic_tracepo`, 1.34e9 calls) has no post-arm entry at all, so the
  two arms' program sets are not the same; the pairing yields no retained pairs at the 1000-call threshold.
  Total calls 2.30e9 against 2.91e9 (0.79) is the only comparable figure, and it is a workload comparison.
  Asymmetric arm records are normal for this app (11-19 runs read 287/287, 221/209, 287/192), which is why the
  ratio needs a run whose two arms loaded the same set.
- What this run establishes: with the base corrected, Tetragon installs 141 of 142 native programs.

Raw: /workspaces/kprog-raw/omp/lto-tetragon-rerun-20261120T1438Z. The stale-loader arm is kept as
`README-stale-loader.md`.