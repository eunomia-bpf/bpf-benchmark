# Tetragon arm with the stale base loader (2026-11-20 11:51 UTC, source e10ec26c4) — superseded

**Root cause (OMP 2026-11-20T14:37Z): the base's verified-loader (built 11-19 11:59) predates 02429959e
(11-20 02:57), which taught the link schema to bind `current_task`/`cpu_number`/`jiffies_64`. `strings` on the
base binary showed only `ktime_get_mono_fast_ns`. The guest ran a current native-link against that stale plan,
so every object referencing `current_task` failed. The loader was rebuilt from HEAD and the base replaced in
place; the arm is re-run and this file kept as the record of the failure.**

Run x86_kvm_corpus_20261120_121231_178650, recipe kprog/results/lto-apps-20261119/Makefile
(APP=tetragon/observer, 3 x 180 s per arm, stats on), omp's arm under `flock -x` on locks/timing.

- Coverage: 134 requests, **46 native installed** (4 checked-sim-c, 42 direct-native), **88 failed** and kept
  on eBPF. All 88 failures are the same error, `native-link: GOT-relative reloc against unknown symbol
  current_task; add it to link-plan helpers or maps` (72 seen in `load-direct.stderr`, 16 in the kernel-link
  stderr of the generated request). The symbol went away when 07d9c4c96 (11-18 20:31) deleted x86_task.rs.
- The post arm therefore records 123 programs against the baseline's 287, and executed 1.58e9 calls against the
  baseline's 2.96e9 (0.53): the 88 JIT-kept programs carry the missing calls, so **no per-call ratio from this
  run is comparable** and none is quoted. The shim log shows 87 `verified program kept on eBPF` and 91
  `no manifest match` lines, all downstream of the same refusal.
- The coordinator's 10 s check of the same image (x86_kvm_corpus_20261120_120226_379788) read 0.899x over 6
  pairs; it predates nothing and is a check, not a timing run.
- What this arm measures is the defect, not the app: with `current_task` unresolved, Tetragon's verified-path
  coverage is 46/134. Compare 11-19, when the same recipe replaced 288/288 (todo line 2026-11-19T23:40Z).

Raw: /workspaces/kprog-raw/omp/lto-tetragon-20261120T1151Z (service archive with all 88 failure archives).