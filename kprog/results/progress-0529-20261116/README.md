# Since 2026-05-29: code, kernel patch, churn and performance

Coordinator, 2026-11-16T23:36:46Z, checked by the coordinator itself. Operator 2026-11-16: "为啥越来越慢, 源代码有没有也审计?",
"内核公共路径 为啥改? 我觉得内核是不是应该几乎不要修改, 整体 patch 也要少于 500 loc?", "你来查, 不要交给别人",
"代码量有多少? 一直在改什么 所有的代码? 对比 5/29 之后的所有进展?"

## Code (lines; results, docs, json/tsv/csv/txt/md, vmlinux.h and generated files left out)

| Area | 05-29 (82ec89cb4) | now |
|---|---:|---:|
| kprog/formal | 0 | 68,411 |
| kprog/x86 | 25,363 | 37,628 |
| kprog/arm64 | 17,001 | 20,561 |
| kinsn/module | 12,000 | 9,973 |
| bpfopt/shim | 8,650 | 8,198 |
| kprog/libnativeloader | 4,893 | 6,578 |
| kprog/perf | 0 | 3,856 |
| kprog/fidelity | 0 | 3,503 |
| kprog/test | 942 (+1,474 other) | 2,473 |
| kprog/stock-path | 0 | 1,557 |
| kprog top files | 620 | 1,341 |
| kprog/build | 0 | 443 |
| kprog/loader | 1,566 | 0 |
| **total** | **72,509** | **164,522** |

Kernel: stock c23719abc330 plus 12 commits, 13 files, +423/-4. Common paths: kernel/fork.c +7 and include/linux/sched.h +3
(74d1097af561, 11-12: per-task native image slot), arch/x86/mm/fault.c +9 and arch/arm64/mm/fault.c +6 (e25108bc9d73, 11-09:
SMAP fault path reuses BPF exception recovery). The rest is load-time binding (syscall.c +18, core.c +39, verifier.c +4,
btf.c +1, uapi +3, bpf.h +1, bpf_native.h +46) and JIT emission (x86 +134, arm64 +156).

## What kept changing since 11-09 (commits per file, code only)

native-relocations.mk 112 (deleted), perf/native-context/Makefile 79 (deleted), libnativeloader/Makefile 69,
native_link x86.rs 61, formal/Makefile 56, x86_sim_local_bpf.h 47, native_loader.cpp 42, scalar-spill-precision.mk 38
(deleted), native_link main.rs 32, vendor/bpf/Makefile 29, kprog/tv/Makefile 21 (deleted), perf/one-image/Makefile 20
(the timing entry), trusted_specializer.py 20. Since 11-09: +73,890 / -239,321 lines (cleanup). 7,750 commits since 05-29.

## Why the numbers fell (source audit plus data)

- eBPF arm: four BCC stats-off runs (11-12 14:42, 11-16 04:16, 11:16, 18:19) have identical run configuration in
  metadata.json, identical shim activity (about 147 KB, 1,380 log lines each), a one-line shim/runner diff between their
  images, and a kernel common-path change of one task pointer. Their eBPF arms are 636,049, 661,016, 566,917, 501,333.
  Same code, falling baseline: the host got busier (lanes' builds and guests on CPUs 8-23 beside the timing guest on 0-7).
- OTel native: eBPF arm 39.2 M -> 39.6 M (stable) while native 40.3 M -> 32.9 M between images 3a1906ab1 and 6641a7e1.
  Installed code differs only by the removed hash copies (6a86ae8f1); the shared-vs-copied diagnostic gives 2.5%. Open.
- Early highs: OTel 1.85x and Katran 1.11x on 05-29 and 11-11/12 had unequal work (context read wrong, no unwinding;
  LRU lookups skipped). Tetragon 1.25-1.33x on 11-11/12 errors since 11-16.
