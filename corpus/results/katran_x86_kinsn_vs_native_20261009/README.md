# Katran on x86-64 KVM: kinsn versus whole-program native

Analysis record, 2026-10-09. No new measurement: it compares retained runs that used the same host (the lab KVM guest, 8 vCPUs, 64 GB), the same Katran XDP program (`balancer_ingress`) and the same kernel-pktgen workload (`katran_kernel_pktgen_l2_udp`, 64-byte UDP, four sender threads, three 180-second samples per arm).

`python3 corpus/results/katran_x86_kinsn_vs_native_20261009/compare.py` (from the repository root) regenerates [output.md](output.md):

| Arm | Throughput (post / JIT, median) | BPF cost, ns per run (JIT -> post) |
|---|---:|---|
| kinsn, full policy (2026-06-04) | 1.030x | 177.7 -> 167.1 (1.06x) |
| kinsn, no bulk copy (2026-06-04/05) | 1.041x | 177.4 -> 167.1 (1.06x) |
| whole-program native (2026-05-29) | 1.102x | 178.3 -> 142.4 (1.25x) |
| whole-program native (2026-05-27) | 1.137x | 177.3 -> 144.9 (1.22x) |

The JIT baselines agree across the runs (about 2.93 million packets per second, 177-178 ns per run). On this host kinsn's full policy recovers about 29% of the native throughput gain, (1.030-1)/(1.102-1), and about 30% of the per-run cost reduction.

Method: throughput is the sender rate, the sum of the last `<n>pps` of each pktgen thread per sample, taken from the statistics-off run; median post over median baseline. BPF cost is `run_time_ns_delta / run_cnt_delta` of `balancer_ingress` from the statistics-on companion run.

Limits: these runs recorded neither XDP action counts (TX/PASS/DROP), Katran's stats map nor receiver packets, and pktgen reports large transmit errors on both arms (queue saturation), so they do not show that both arms processed packets identically. The native runs predate the kinsn runs by about a week. The Cilium native comparison from the same campaign is not valid (see `../cilium_native_audit_20261009/`); a counter-checked Katran rerun is pending.
