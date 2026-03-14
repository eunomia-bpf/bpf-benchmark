# Corpus Batch Recompile Results

- Generated: 2026-03-12T20:20:12.032222+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 20
- Skip families: `none`
- Target programs: 13
- Compile pairs: 13
- Measured pairs: 13
- Recompile applied programs: 11
- Code-size ratio geomean (baseline/v5): 1.000x
- Exec-time ratio geomean (baseline/v5): 1.055x
- Total sites: 122
- CMOV sites: 27
- WIDE sites: 12
- ROTATE sites: 0
- LEA sites: 0
- EXTRACT sites: 0
- ZERO-EXT sites: 0
- ENDIAN sites: 44
- BRANCH-FLIP sites: 39
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 6 | 6 | 6 | 6 | 22 | 12 | 0 | 0 | 0 | 0 | 42 | 12 | 1.003x | 0.900x | 5 |
| linux-selftests | 5 | 5 | 5 | 3 | 4 | 0 | 0 | 0 | 0 | 0 | 1 | 17 | 0.996x | 1.300x | 3 |
| katran | 2 | 2 | 2 | 2 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 10 | 1.002x | 1.010x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| endian | 8 | 8 | 44 | 44 | 8 | 8 | 1.003x | 0.828x | 7 |
| branch-flip | 10 | 10 | 39 | 39 | 10 | 10 | 1.000x | 1.167x | 7 |
| cmov | 10 | 3 | 27 | 6 | 10 | 10 | 1.000x | 1.067x | 8 |
| wide | 6 | 6 | 12 | 12 | 6 | 6 | 1.003x | 0.900x | 5 |
| extract | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| rotate | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 8.644x | cmov, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | linux-selftests | sched_cls | 1.227x |  |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | katran | sched_cls | 1.200x | branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.019x | wide, endian, branch-flip |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 0.492x | endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0.711x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 0.765x | wide, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 0.812x | wide, endian, branch-flip |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 0.850x | endian, branch-flip |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 0.896x | cmov, wide, endian, branch-flip |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 0.955x | wide, endian, branch-flip |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 0.978x | wide, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 1.000x | cmov, branch-flip |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 1.004x | endian |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 1.004x | endian, branch-flip |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.003x | wide, endian, branch-flip |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.003x | wide, endian, branch-flip |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.003x | wide, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.003x | wide, endian, branch-flip |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.003x | wide, endian, branch-flip |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.002x | cmov, wide, endian, branch-flip |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11888 | 11854 | 1.003x | 397 | 489 | 0.812x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 12004 | 11970 | 1.003x | 372 | 365 | 1.019x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 15 | wide, endian, branch-flip | 11762 | 11728 | 1.003x | 492 | 515 | 0.955x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11454 | 11420 | 1.003x | 405 | 414 | 0.978x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11454 | 11420 | 1.003x | 458 | 599 | 0.765x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 9 | cmov, wide, endian, branch-flip | 8023 | 8010 | 1.002x | 439 | 490 | 0.896x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 9 | endian, branch-flip | 1615 | 1608 | 1.004x | 34 | 40 | 0.850x |  |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | katran | sched_cls | 3 | branch-flip | 544 | 544 | 1.000x | 36 | 30 | 1.200x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 3 | cmov, branch-flip | 266 | 272 | 0.978x | 6111 | 707 | 8.644x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | linux-selftests | sched_cls | 0 |  | 114 | 114 | 1.000x | 54 | 44 | 1.227x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0 |  | 148 | 148 | 1.000x | 54 | 76 | 0.711x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 17 | cmov, branch-flip | 1676 | 1678 | 0.999x | 1000699606 | 1000719220 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 2 | endian | 689 | 686 | 1.004x | 32 | 65 | 0.492x |  |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- `--use-policy` only considers per-program version 2 policy files under `corpus/policies/`; if no match exists, the driver falls back to the auto-scan `--recompile-v5 --recompile-all` path.
- `--skip-families` filters families out of the auto-generated v5 policy; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
