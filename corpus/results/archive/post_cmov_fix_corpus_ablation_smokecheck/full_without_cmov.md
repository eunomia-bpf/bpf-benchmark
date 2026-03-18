# Corpus Batch Recompile Results

- Generated: 2026-03-12T23:18:53.627123+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/post_cmov_fix_corpus_ablation_smokecheck/full_sample_inventory.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 80
- Skip families: `none`
- Target programs: 10
- Compile pairs: 9
- Measured pairs: 9
- Recompile applied programs: 4
- Code-size ratio geomean (baseline/v5): 1.013x
- Exec-time ratio geomean (baseline/v5): 0.889x
- Total sites: 467
- CMOV sites: 76
- WIDE sites: 138
- ROTATE sites: 20
- LEA sites: 0
- EXTRACT sites: 20
- ZERO-EXT sites: 0
- ENDIAN sites: 121
- BRANCH-FLIP sites: 92
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 2 | 2 | 2 | 1 | 41 | 20 | 0 | 0 | 1 | 0 | 93 | 4 | 1.000x | 0.716x | 2 |
| linux-selftests | 2 | 2 | 2 | 0 | 8 | 6 | 0 | 0 | 16 | 0 | 20 | 22 | 1.000x | 0.667x | 2 |
| xdp-tutorial | 2 | 2 | 2 | 1 | 4 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 1.053x | 0.964x | 1 |
| katran | 1 | 1 | 1 | 0 | 8 | 4 | 20 | 0 | 2 | 0 | 4 | 56 | 1.000x | 1.240x | 0 |
| suricata | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| tracee | 1 | 1 | 1 | 1 | 13 | 107 | 0 | 0 | 1 | 0 | 2 | 9 | 1.003x | 1.000x | 0 |
| xdp-tools | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | 1.009x | 1.312x | 0 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| wide | 7 | 3 | 138 | 120 | 7 | 7 | 1.015x | 0.845x | 4 |
| endian | 7 | 3 | 121 | 56 | 7 | 7 | 1.002x | 0.868x | 4 |
| branch-flip | 7 | 0 | 92 | 0 | 7 | 7 | 1.000x | 0.817x | 5 |
| cmov | 10 | 0 | 76 | 0 | 9 | 9 | 1.013x | 0.889x | 5 |
| extract | 5 | 2 | 20 | 2 | 5 | 5 | 1.001x | 0.855x | 3 |
| rotate | 1 | 0 | 20 | 0 | 1 | 1 | 1.000x | 1.240x | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1.312x | endian |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.240x | cmov, wide, rotate, extract, endian, branch-flip |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.083x | wide |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 0.526x | cmov, wide, extract, endian, branch-flip |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.622x | cmov, wide, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.825x | wide, extract, endian |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 0.846x | cmov, wide, extract, endian, branch-flip |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 0.857x | cmov, branch-flip |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.109x | wide |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1.009x | endian |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.003x | wide, extract, endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 87 | wide, extract, endian | 46152 | 46152 | 1.000x | 496 | 601 | 0.825x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 |  | 36667 | 36667 | 1.000x | 209 | 336 | 0.622x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 94 |  | 13412 | 13412 | 1.000x | 31 | 25 | 1.240x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | 10 | 19 | 0.526x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | 11 | 13 | 0.846x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 132 | wide, extract, endian | 19383 | 19320 | 1.003x | 11 | 11 | 1.000x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 3 | endian | 697 | 691 | 1.009x | 21 | 16 | 1.312x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 | wide | 122 | 110 | 1.109x | 13 | 12 | 1.083x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 3 |  | 526 | 526 | 1.000x | 12 | 14 | 0.857x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Argument list too long (exit=1) | 2 |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
