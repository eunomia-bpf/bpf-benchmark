# Corpus Batch Recompile Results

- Generated: 2026-03-12T23:17:31.956316+00:00
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
- Recompile applied programs: 5
- Code-size ratio geomean (baseline/v5): 1.005x
- Exec-time ratio geomean (baseline/v5): 0.892x
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
| calico | 2 | 2 | 2 | 1 | 41 | 20 | 0 | 0 | 1 | 0 | 93 | 4 | 1.000x | 0.741x | 2 |
| linux-selftests | 2 | 2 | 2 | 0 | 8 | 6 | 0 | 0 | 16 | 0 | 20 | 22 | 1.000x | 0.657x | 2 |
| xdp-tutorial | 2 | 2 | 2 | 2 | 4 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 1.016x | 1.044x | 1 |
| katran | 1 | 1 | 1 | 0 | 8 | 4 | 20 | 0 | 2 | 0 | 4 | 56 | 1.000x | 0.960x | 1 |
| suricata | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| tracee | 1 | 1 | 1 | 1 | 13 | 107 | 0 | 0 | 1 | 0 | 2 | 9 | 1.003x | 1.250x | 0 |
| xdp-tools | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | 1.009x | 1.150x | 0 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| wide | 7 | 3 | 138 | 120 | 7 | 7 | 1.009x | 0.828x | 6 |
| endian | 7 | 3 | 121 | 56 | 7 | 7 | 1.002x | 0.852x | 5 |
| branch-flip | 7 | 0 | 92 | 0 | 7 | 7 | 0.996x | 0.853x | 5 |
| cmov | 10 | 5 | 76 | 38 | 9 | 9 | 1.005x | 0.892x | 6 |
| extract | 5 | 2 | 20 | 2 | 5 | 5 | 1.001x | 0.809x | 4 |
| rotate | 1 | 0 | 20 | 0 | 1 | 1 | 1.000x | 0.960x | 1 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.250x | cmov, wide, extract, endian |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 1.158x | cmov |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1.150x | cmov, endian |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 0.647x | cmov, wide, extract, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 0.667x | cmov, wide, extract, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.670x | cmov, wide, extract, endian |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.819x | cmov, wide, endian, branch-flip |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 0.941x | cmov, wide |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 0.960x | cmov, wide, rotate, extract, endian, branch-flip |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.061x | cmov, wide |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1.009x | cmov, endian |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.003x | cmov, wide, extract, endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 87 | cmov, wide, extract, endian | 46152 | 46152 | 1.000x | 386 | 576 | 0.670x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 |  | 36667 | 36667 | 1.000x | 203 | 248 | 0.819x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 94 |  | 13412 | 13412 | 1.000x | 24 | 25 | 0.960x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | 12 | 18 | 0.667x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | 11 | 17 | 0.647x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 132 | cmov, wide, extract, endian | 19383 | 19320 | 1.003x | 15 | 12 | 1.250x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 3 | cmov, endian | 697 | 691 | 1.009x | 23 | 20 | 1.150x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 | cmov, wide | 122 | 115 | 1.061x | 16 | 17 | 0.941x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 3 | cmov | 526 | 541 | 0.972x | 22 | 19 | 1.158x |  |

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
