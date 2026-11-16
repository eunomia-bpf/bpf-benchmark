# Check round after cleanups 1-10

Coordinator, 2026-11-16T17:20:41Z. Operator 2026-11-16: "发现问题你自己主动推进清理整改, 别的 lane 停下来, 清理整理好再继续?"

The cleaned tree (HEAD fb862ec54 at the start) built the one image with the frozen recipe
`make -f kprog/perf/one-image/Makefile image` (2026-11-16 16:21-16:30 UTC, image sha256:6641a7e1...,
log /workspaces/kprog-raw/builds/one-image-20261116T1621Z-cleanup.log), after
`make -C kprog/libnativeloader checked-sim-stage` refreshed the checked-sim-c tools from source.
`make -f kprog/perf/one-image/Makefile check` then ran every app once (SAMPLES=1, WORKLOAD_DURATION=10,
stats on) through the frozen corpus entry. One 10-second sample is a functional check; its ratios are indicative.

| App | Run | Status | Native programs | Both arms' paths | Installed native / JIT |
|---|---|---|---|---|---|
| OTel | 163206_529710 | completed | 14 | 1/1 track | 1.82x (3a1906ab1: 1.98x) |
| BCC | 163548_274084 | completed | 25 | 7/9 track; sched_switch, sched_wakeup 0.246 | 1.57x (3a1906ab1: 5.09x) |
| Cilium | 163855_372136 | completed | 113 | native runs cil_to_host, cil_from_host 12.18 M times, eBPF 1-2 | 1.26x |
| Tetragon | 164202_038065 | error | 13, native runs 0 | 0/3 | 1.00x |
| Tracee | 164517_019844 | completed | 169 | 24/24 track | 0.86x |
| Katran | 165007_017475 | completed | 1 | 1/1 track | 0.77x (3a1906ab1: 0.95x) |

`inventory.txt` holds the full output: compare_code.py against the 2026-05-29 build, paths.py, per-call and
throughput ratios and installed sizes for each run.
