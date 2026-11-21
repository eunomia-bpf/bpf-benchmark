# Tetragon in the main-configuration recipe (2026-11-20 14:38 UTC, source 87ba2b8ba)

Re-run of the 11:51 arm after the base's verified-loader was rebuilt from HEAD and replaced in place. Run
x86_kvm_corpus_20261120_143937_810796, recipe kprog/results/lto-apps-20261119/Makefile
(APP=tetragon/observer, 3 x 180 s per arm, stats on).

- Coverage: 142 requests, **141 native installed** (21 checked-sim-c, 120 direct-native), 1 failed. The post
  shim log records `native-loader replaced` 141 times and zero `kept on eBPF`. Against the stale-loader arm's
  46 of 134, this is the whole difference: the loader was the only cause.
- **Not the whole cause (OMP 2026-11-20T16:5xZ, coordinator 16:46Z):** the real defect is 0e4f2da6f, which
  made `get_current_task(_btf)` and `get_smp_processor_id` gs loads in native-helpers.h; the direct-native path
also crashed Tracee's guest with it. Fixed forward in 3b5fa4b40 (named helper calls again). This run predates
that fix and ran on the pre-3b5fa4b40 image, so its 141 of 142 is the loader-staleness fix alone; the arm is
re-run on the new image.
- The stale base (also real, one layer of the same failure): `/workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader` had been built
  11-19 11:59, before 02429959e (11-20 02:57) taught the link schema to bind `current_task`, `cpu_number` and
  `jiffies_64`. `strings` on it showed only `ktime_get_mono_fast_ns`. The guest ran a current native-link
  against that plan, so every object with a `current_task` GOT relocation failed. Fixed in place, same base.
- Per call, as measured: **2.790x** (733.1 / 262.7 ns, `kprog/results/flag-tuning-20261117/may29_ratio.py`); throughput
  2.995x (3.177 / 3.015 / 2.628). Beside them: the post arm recorded 129 program entries against the baseline's 287
  and 2.30e9 calls against 2.91e9, and the hottest baseline program (`generic_tracepo`, 1.34e9 calls) is absent from
  the post arm, so the two arms ran different program sets and the throughput above the per-call bound comes from
  that difference in work. Asymmetric arm records are usual for this app (11-19 runs read 287/287, 221/209, 287/192).
  Reported as measured per the 2026-11-20 16:48 decision (d514e9efc; operator 2026-11-18: "不应该拿调用次数做对比和
  gate? 调用次数很可能不同啊").
- What this run establishes: with the base corrected, Tetragon installs 141 of 142 native programs.

Raw: /workspaces/kprog-raw/omp/lto-tetragon-rerun-20261120T1438Z. The stale-loader arm is kept as
`README-stale-loader.md`.