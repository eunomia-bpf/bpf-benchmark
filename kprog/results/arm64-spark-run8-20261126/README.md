# arm64 run 8, 2026-11-26

Operator 2026-11-26 10:54Z: "arm 也要确保出数字"; 10:55Z: "要确保每一个应用的数字都是最好的, 不能倒退."

Step 1 (`chain.sh`) rebuilds the arm64 image from the committed tree. The tree carries the key-size C hash routines for
every key size from 1 to 512 bytes (42cd0d591), whose x86 six-app check passed on image 7a11cb60285a (4ce03654f). It then
runs the QEMU six-app functional check (`make -C kprog/perf/one-image-arm64 check`). Logs and exit codes go to
/workspaces/kprog-raw/coordinator/arm64-run8-20261126/.

Step 2 is the Spark timing with the frozen arm64 entry (kprog/perf/one-image-arm64/spark-rotate.sh: 3 x 180 s per arm,
stats off then on, breadth first), six applications over the two Sparks. DeepSeek is paused for this single test and
restored right after, as in runs 5-7 (spark-manage docs/configuration-decisions/2026-11-21-kprog-arm64-spark-kvm-timing.md).
Results follow below.

## Step 1 result

The arm64 image built 2026-11-26 13:24Z (rc 0). The QEMU six-app check passed: OTel 13:46Z, BCC 13:48Z, Cilium 13:59Z,
Tetragon 14:19Z, Tracee 14:32Z and Katran 14:35Z, all rc 0 (/workspaces/kprog-raw/one-image-arm64-runs/check.log).

## Step 2 result: Spark timing, 2026-11-26 15:34Z – 18:06Z

`spark-9773` ran OTel, BCC and Cilium; `spark-d5fe` ran Tetragon, Tracee and Katran. Each used the frozen arm64 entry
(kprog/perf/one-image-arm64/spark-rotate.sh) with 3 x 180 s per arm, stats off then on, breadth first, in container
`kprog-qemu-arm64:24.04` on CPUs 15-19 (Cortex-X925). The guest root is the one checked in step 1, and the kernel Image
is the Workspace's arm64 build (md5 eb774da0), whose modules the root carries. All 12 runs returned rc=0 with app
status ok. DeepSeek was paused 15:23–18:1xZ (spark-manage 69a7b9dc and the swap-back commit after it).

`summary.py` reads the raw runs with the 05-29 evaluator, as check_summary.py does. Per call comes from the stats-on
arm (eBPF aggregate ns/call over native). Throughput is the native median over the eBPF median, followed by the
per-sample ratios in sample order. Raw runs, guest logs and progress logs:
/workspaces/kprog-raw/arm64-spark-run8/{spark-9773,spark-d5fe}/.

| App | Per call, stats on | Throughput, stats off | Throughput, stats on | Run 7 (30e401e37) | Run 6 (30e401e37) |
|---|---|---|---|---|---|
| OTel | 1.055x (253.6 / 240.4 ns) | 0.999x (1.000, 0.992, 1.007) | 1.001x (1.005, 0.995, 1.009) | – | 1.017x per call |
| BCC | 0.971x (94.6 / 97.5 ns) | 1.021x (1.023, 0.979, 1.042) | 0.923x (0.926, 0.923, 0.943) | 0.956x / 1.071x / 0.940x | 0.938x / 0.980x / 0.988x |
| Cilium | 1.020x (988.4 / 969.4 ns) | 1.009x (1.009, 0.992, 1.019) | 0.958x (0.950, 0.982, 0.958) | 1.035x / 1.124x / 1.098x | 1.017x / 1.050x / 1.091x |
| Tetragon | 1.435x (447.8 / 312.1 ns) | 1.230x (1.232, 1.288, 1.189) | 1.150x (1.142, 1.189, 1.150) | 1.400x / 1.245x / 1.130x | 1.384x / 1.222x / 1.181x |
| Tracee | 1.645x (334.2 / 203.1 ns) | 1.512x (1.493, 1.538, 1.507) | 1.255x (1.255, 1.286, 1.232) | – | 1.534x per call |
| Katran | 0.993x (164.2 / 165.3 ns) | 1.015x (1.016, 1.016, 1.008) | 1.259x (1.251, 1.273, 1.242) | 0.954x / 1.001x / 0.923x | 0.932x / 0.991x / 0.823x |

Run columns are per call / stats-off throughput / stats-on throughput. Run 7 timed BCC, Cilium, Katran and Tetragon only.

Per call, run 8 is above every earlier arm64 run for OTel, BCC, Tetragon, Tracee and Katran; BCC (0.971x) and Katran
(0.993x) stay below 1. Cilium is 1.020x per call against run 7's 1.035x, and 1.009x stats-off throughput against
1.124x. Since run 7 the Cilium P objects carry the agent's own compile-time switches again (6cdde0600, the switches
its eBPF objects use). The arm64 changes since run 7 are the ARRAY_OF_MAPS lookup, get_current_task as the arm64 JIT
emits it, and the key-size C hash routines for 1–512 bytes.
