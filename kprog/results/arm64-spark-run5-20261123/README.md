# arm64 frozen-entry run on one DGX Spark pair under KVM, 2026-11-23T08:12Z – 10:44Z

Operator 2026-11-23: "x86 / arm 性能都要完整汇报并且检查是不是和设计完全符合".

Code: bpf-benchmark dcf4a1aef (jiffies_64 address kept, frozen .rodata constants), the same path code
as the x86 frozen-entry run that started 2026-11-23T08:03Z. Guest image checked in the Workspace on
2026-11-23 06:38–07:48Z (QEMU): six applications rc=0, every running program replaced natively
(OTel 13, BCC 23, Cilium 102, Tetragon 91, Tracee 73, Katran 1; Tetragon's library runtime probe stays
eBPF). Timing: `kprog/perf/one-image-arm64/spark-rotate.sh` in container `kprog-qemu-arm64:24.04`,
`--cpuset-cpus 15-19` (Cortex-X925 cluster), 4 vCPU / 8 GiB guest, kernel Image md5 4888c1c4;
`spark-9773` OTel, BCC, Cilium; `spark-d5fe` Tetragon, Tracee, Katran; 3 × 180 s per arm, breadth first,
stats off then on. Every run rc=0 with three samples per arm. DeepSeek paused 08:12–10:56Z
(spark-manage 9de77c5e, 390d5ade). Ratios native/eBPF from kprog/results/flag-tuning-20261117/may29_ratio.py.

| App | Throughput, stats off | Per call, stats on | Throughput, stats on | 5/27 arm64 AWS t4g.small (throughput / per call) |
|---|---|---|---|---|
| OTel | 1.013x (1.005, 1.013, 1.008) | 1.004x (eBPF 253.1 ns, native 252.1 ns) | 0.988x | 0.989x / 1.02x |
| BCC | 1.011x (1.010, 1.097, 1.005) | 0.952x (eBPF 93.3 ns, native 98.0 ns) | 0.927x | 1.005x / 0.96x |
| Cilium | 1.084x (1.084, 1.084, 1.087) | 1.015x (eBPF 1000.6 ns, native 985.7 ns) | 1.061x | 4.060x / 4.75x |
| Tetragon | 1.237x (1.208, 1.241, 1.232) | 1.384x (eBPF 446.0 ns, native 322.2 ns) | 1.171x | 1.164x / 1.31x |
| Tracee | 1.398x (1.428, 1.410, 1.369) | 1.585x (eBPF 334.1 ns, native 210.8 ns) | 1.283x | 0.273x / 0.27x |
| Katran | 1.008x (1.009, 1.005, 1.010) | 0.957x (eBPF 165.3 ns, native 172.8 ns) | 0.991x | 1.081x / 1.10x |

Raw results: /workspaces/kprog-raw/arm64-spark-run5/{spark-9773,spark-d5fe}/ (run directories under
workspaces/repository/corpus/results/ as the guest wrote them, and each Spark's progress.log).

- The 5/27 arm64 numbers come from another machine (AWS t4g.small, Neoverse N1) and the 06-14 artifacts;
  these come from the Cortex-X925 cluster of a DGX Spark.
- Katran: both arms report pktgen errors of the same order (690 in the stats-off column), a property of
  the workload.
