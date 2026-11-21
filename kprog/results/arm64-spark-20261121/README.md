# arm64 timing on two DGX Sparks under KVM (2026-11-21)

Operator 2026-11-05: "arm 后面可用 spark, 你先把模拟的跑通"; 2026-11-20: "你要确保弄好, 需要支持". Guest root, kernel and
module from the arm64 entry (kprog/perf/one-image-arm64, image of 66d96b9c7), `spark-rotate.sh` with the frozen x86 entry
defaults (3 x 180 s per arm, stats off then on), KVM `-cpu host` on the Cortex-X925 cluster, 4 vCPU, 8 GiB. spark-9773 ran
all six (its script copy predated ORDER), spark-d5fe Tetragon, Tracee and Katran. Raw: kprog-raw/coordinator/arm64-spark-20261121.

| App | Per call (stats on) | Throughput stats off | Throughput stats on | Host |
|---|---|---|---|---|
| OTel | 1.009x | 1.006x | 0.994x | 9773 |
| BCC | 0.915x | 1.008x | 0.941x | 9773 |
| Cilium | 0.998x | 1.008x | 1.033x | 9773 |
| Tetragon | 0.963x / 0.947x | 0.989x / 0.995x | 0.997x / 0.922x | 9773 / d5fe |
| Katran | 1.004x / 1.005x | 1.000x / 0.993x | 1.004x / 0.948x | 9773 / d5fe |
| Tracee | guest oops in the native trace_do_sigact (pc +0xd14) in the post phase, both hosts | | | |

On arm64 most programs keep their eBPF today (no native tail-call stub, cross-section calls; kprog/docs/todo.md item 10),
so these ratios measure little native code. Tracee's 10 s QEMU check passed; the 180 s workload reaches trace_do_sigact.
