# kinsn Cilium and Katran in the config-parity setup (follow-up, 2026-10-12)

Follow-up to `../cilium_x86_config_parity_counterbalanced_20261010/`, in the
same setup: a fresh 8-vCPU, 64-GiB guest per cell pinned to host P-cores 0-7
(`vng --pin 0-7`), 60-second phases, the same Cilium source, daemon
configuration, policy and pktgen workload, one guest at a time. The image was
rebuilt from `e3f503e1e` plus the driver fix below. kinsn uses the modules of
that commit (the current, scratch-free proof sequences), not the June modules
behind the paper's 1.074x.

## Result

**Cilium with kinsn: 1.042x** throughput over kernel JIT (statistics off,
median of six fresh guests, JIT then kinsn; IQR 1.031-1.060, range
1.029-1.070). The JIT-to-JIT restart controls of the same session give
1.014x (n=6, IQR 1.006-1.037, range 1.001-1.068). Two JIT-to-native bridge
guests give 1.211x and 1.223x, in line with the 1.201x median of the same
order block on 2026-10-10, so the host conditions are comparable.

| Measurement (Cilium) | n | Median | IQR | Range |
| --- | ---: | ---: | ---: | ---: |
| Stats off, kinsn/JIT throughput | 6 | 1.0422x | 1.0309-1.0597x | 1.0289-1.0696x |
| Stats off, JIT/JIT second/first | 6 | 1.0138x | 1.0063-1.0368x | 1.0006-1.0676x |
| Stats off, native/JIT throughput (bridge) | 2 | 1.2168x | - | 1.2108-1.2228x |
| Stats on, kinsn/JIT throughput | 3 | 1.0337x | 1.0275-1.0683x | 1.0213-1.1029x |
| Stats on, JIT/kinsn pooled BPF ns/run | 3 | 1.0716x | 1.0569-1.1637x | 1.0422-1.2559x |
| Stats on, JIT/JIT second/first | 3 | 0.9935x | 0.9673-1.0013x | 0.9410-1.0091x |

With statistics on, the across-guest medians are 794.1 ns/run (JIT) and
698.5 ns/run (kinsn), pooled entry-program cost as in the 2026-10-10 run.
Against the 1.194x native result, kinsn recovers (1.042-1)/(1.194-1) = 22% of
the gap; against the same-order bridge median (1.217x), 19%.

Every kinsn guest rewrote 131 Cilium programs at load time with 3,762 kinsn
sites (lea 2,406, endian_fusion 768, cond_select 334, bitops 252, extract 2),
and the kernel accepted every rewritten program; only Cilium's 4-instruction
feature probes failed, as originals. The 51 live programs total 235,188 bytes
of native code under kinsn against 233,646 under JIT (1.0066x).

All 40 Cilium phases forwarded every packet: zero pktgen errors, receiver
errors, receiver drops and reason-133 drops; receiver minus sent is the usual
startup traffic. Every guest passed the 51-versus-51 live-inventory parity
check (kernel-name granularity for kinsn and JIT/JIT guests, full names for
native).

This is not a reproduction of the paper's 1.074x (2026-06-04: June modules,
June kernel, three 180-second samples in one guest). The module set, kernel and
protocol all differ; see `../../../micro/results/kinsn_load_time_current_20261011/`
for how the current proof sequences change verification.

**Katran: no valid timing.**

- kinsn was never applied. In all six kinsn guests the verifier rejected the
  rewritten `balancer_ingress` with E2BIG (errno 7) and the shim loaded the
  original, so those guests ran JIT twice.
- Throughput is not usable. The transport is bimodal independent of the arm:
  19 phases ran at about 1.47 Mpps (median) with no pktgen errors, 29 at about
  2.69 Mpps with pktgen queue errors (983 million in total) and, in some
  phases, receiver loss after Katran. JIT/JIT controls range 0.45-1.61x.
- Katran itself did the same work in every phase: its counters show every sent
  packet hitting the VIP, transmitted with XDP_TX and counted for the real,
  with no Katran drop.
- Per-run cost depends on the transport mode too (JIT 181.2 ns/run in slow
  phases, 153.3 in fast ones). Restricted to statistics-on guests whose two
  phases ran in the same mode, JIT/native is 1.049x (n=5, 0.939-1.134x).

## Attempts and host conditions

The host boot ID was `04dc0087-5ccc-4c46-9997-b9a92f0e5167` throughout.

1. First attempt, 2026-10-11 23:45 to 2026-10-12 05:08 UTC: other lab
   workloads were stopped with SIGSTOP as on 2026-10-10. The gpu-smt lane
   noticed its stopped processes, killed them and restarted its work at 04:44
   UTC; a JIT/JIT guest then timed out and the series stopped. A load-time
   diagnostic guest also hung for four hours holding the host lock. Its seven
   cells are kept in `runs-cilium-attempt1-sigstop.tsv` and
   `logs-attempt1-sigstop/` and are not used.
2. Second attempt, 05:13 to 08:25 UTC: nothing was stopped. The gpu-smt and
   bpf-benchmark Workspace pods and telegram-desktop were limited to CPUs 8-23
   with runtime cgroup settings, reverted afterwards; the guests used CPUs 0-7.
   `logs/*.busy-start.txt` and `*.busy-end.txt` record the busiest host
   processes and their CPUs around every cell. Two cells timed out at the
   480-second bound (a Cilium bridge cell and a Katran JIT/JIT cell) and were
   rerun from fresh guests; all 44 cells were accepted.

## Fix made for this run

`corpus/driver.py` checked Cilium live-inventory parity on full program names.
A load-time kinsn rewrite leaves programs without BTF function names, so the
kinsn arm showed only the kernel's 15-byte names (`cil_from_contai`) against
the JIT arm's full names and every kinsn guest failed. When neither arm's names
come from the native loader's log, both arms are now compared at kernel-name
granularity (counts re-aggregated per truncated name); the native arms still
compare full names. `tests/python/test_cilium_inventory_parity.py` covers both
cases.

## Build notes

Two host problems had to be worked around to rebuild the image, without
changing tracked files: `/usr/bin/go` 1.22 cannot fetch the go1.24 toolchain
the OpenTelemetry collector build requests, so the collector was built with
`/snap/bin/go` 1.27.1 (OpenTelemetry is not part of these runs); and lab's
`/usr/bin/c++` is a Python wrapper that always exits 0, which made LLVM's
configure checks pass wrongly, so `llvm-backend/build-bpf-kinsn` was configured
with `/usr/bin/gcc` and `/usr/bin/g++` named explicitly.

## Files

`run-series.sh` drives a series (`cilium` or `katran`); `analyze.py`
regenerates `analysis.json`, `samples.csv` (one row per phase),
`guests.csv` (one row per guest) and `live-program-images.csv` from the raw
run directories listed in `runs-cilium.tsv` and `runs-katran.tsv`, which stay
on the lab host.
