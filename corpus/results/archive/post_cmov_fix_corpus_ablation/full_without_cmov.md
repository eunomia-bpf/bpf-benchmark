# Corpus Batch Recompile Results

- Generated: 2026-03-12T23:44:44.644753+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/post_cmov_fix_corpus_ablation/full_sample_inventory.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 45
- Compile pairs: 44
- Measured pairs: 42
- Recompile applied programs: 15
- Code-size ratio geomean (baseline/v5): 1.005x
- Exec-time ratio geomean (baseline/v5): 0.947x
- Total sites: 1276
- CMOV sites: 302
- WIDE sites: 281
- ROTATE sites: 20
- LEA sites: 0
- EXTRACT sites: 51
- ZERO-EXT sites: 0
- ENDIAN sites: 438
- BRANCH-FLIP sites: 184
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 15 | 15 | 15 | 6 | 225 | 48 | 0 | 0 | 13 | 0 | 385 | 32 | 1.000x | 0.915x | 10 |
| linux-selftests | 15 | 15 | 13 | 2 | 27 | 12 | 0 | 0 | 32 | 0 | 40 | 61 | 1.000x | 0.843x | 6 |
| xdp-tutorial | 6 | 6 | 6 | 3 | 10 | 3 | 0 | 0 | 0 | 0 | 0 | 4 | 1.032x | 1.009x | 2 |
| xdp-tools | 3 | 3 | 3 | 2 | 3 | 0 | 0 | 0 | 0 | 0 | 4 | 0 | 1.006x | 1.547x | 1 |
| katran | 2 | 2 | 2 | 0 | 9 | 4 | 20 | 0 | 2 | 0 | 5 | 63 | 1.000x | 1.268x | 1 |
| suricata | 2 | 1 | 1 | 0 | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 6 | 1.000x | 1.071x | 0 |
| tracee | 2 | 2 | 2 | 2 | 26 | 214 | 0 | 0 | 2 | 0 | 4 | 18 | 1.003x | 0.734x | 2 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| endian | 25 | 12 | 438 | 209 | 25 | 25 | 1.001x | 0.972x | 15 |
| cmov | 43 | 0 | 302 | 0 | 42 | 42 | 1.005x | 0.947x | 22 |
| wide | 17 | 12 | 281 | 255 | 17 | 17 | 1.012x | 0.942x | 11 |
| branch-flip | 30 | 0 | 184 | 0 | 30 | 30 | 1.003x | 0.942x | 16 |
| extract | 16 | 7 | 51 | 21 | 16 | 16 | 1.001x | 0.959x | 9 |
| rotate | 1 | 0 | 20 | 0 | 1 | 1 | 1.000x | 1.786x | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 2.000x | endian |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1.929x | endian |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.786x | cmov, wide, rotate, extract, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 1.714x | wide, extract, endian |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 1.667x | wide |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1.286x | cmov |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 1.285x | cmov, extract, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 1.263x | cmov, extract, endian, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 1.144x | wide, extract, endian |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.130x | wide |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 0.529x | cmov |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 0.556x | cmov, endian, branch-flip |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 0.562x | cmov, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 0.571x | cmov, wide, extract, endian, branch-flip |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 0.571x | cmov, wide, extract, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 0.583x | cmov |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 0.615x | wide, extract, endian |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.623x | cmov, wide, endian, branch-flip |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 0.667x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 0.706x | cmov |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.109x | wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 1.052x | wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.033x | wide |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1.009x | endian |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1.009x | endian |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.003x | wide, extract, endian |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 1.003x | wide, extract, endian |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 1.002x | wide, extract, endian |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 1.002x | wide, extract, endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 1.000x | wide, extract, endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 87 | wide, extract, endian | 46152 | 46152 | 1.000x | 374 | 327 | 1.144x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 |  | 20957 | 20957 | 1.000x | 217 | 208 | 1.043x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 44 |  | 23489 | 23489 | 1.000x | 226 | 179 | 1.263x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 |  | 33180 | 33180 | 1.000x | 308 | 337 | 0.914x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 30 |  | 18932 | 18932 | 1.000x | 187 | 198 | 0.944x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 21185 | 21185 | 1.000x | 172 | 217 | 0.793x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 |  | 36667 | 36667 | 1.000x | 177 | 284 | 0.623x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 34 | endian | 22172 | 22170 | 1.000x | 216 | 206 | 1.049x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 | wide, endian | 18044 | 18042 | 1.000x | 174 | 204 | 0.853x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, extract, endian | 22218 | 22184 | 1.002x | 197 | 208 | 0.947x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 22542 | 22542 | 1.000x | 248 | 193 | 1.285x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, extract, endian | 22100 | 22066 | 1.002x | 170 | 212 | 0.802x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 38 |  | 21882 | 21882 | 1.000x | 227 | 262 | 0.866x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 65 | wide, endian | 30314 | 30309 | 1.000x | 190 | 196 | 0.969x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 22 |  | 13936 | 13936 | 1.000x | 174 | 313 | 0.556x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 94 |  | 13412 | 13412 | 1.000x | 25 | 14 | 1.786x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 9 |  | 1615 | 1615 | 1.000x | 9 | 10 | 0.900x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 |  | 53 | 53 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 |  | 403 | 403 | 1.000x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 3 |  | 266 | 266 | 1.000x | 7105 | 6840 | 1.039x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 17 |  | 1676 | 1676 | 1.000x | 1000863480 | 1000829908 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 |  | 171 | 171 | 1.000x | 9 | 17 | 0.529x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 |  | 392 | 392 | 1.000x | 12 | 17 | 0.706x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 |  | 557 | 557 | 1.000x | 9 | 7 | 1.286x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 |  | 526 | 526 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 |  | 513 | 513 | 1.000x | 8 | 8 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | 8 | 14 | 0.571x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 36 | wide, extract, endian | 5454 | 5452 | 1.000x | 24 | 14 | 1.714x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | 8 | 14 | 0.571x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 36 | wide, extract, endian | 5454 | 5452 | 1.000x | 13 | 13 | 1.000x |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 9 |  | 1628 | 1628 | 1.000x | 15 | 14 | 1.071x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 132 | wide, extract, endian | 19383 | 19320 | 1.003x | 8 | 13 | 0.615x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 132 | wide, extract, endian | 19383 | 19320 | 1.003x | 7 | 8 | 0.875x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 3 | endian | 697 | 691 | 1.009x | 18 | 9 | 2.000x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 3 | endian | 694 | 688 | 1.009x | 27 | 14 | 1.929x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 |  | 78 | 78 | 1.000x | 24 | 25 | 0.960x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 2 |  | 511 | 511 | 1.000x | 18 | 16 | 1.125x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 | wide | 122 | 110 | 1.109x | 14 | 16 | 0.875x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 3 |  | 526 | 526 | 1.000x | 9 | 16 | 0.562x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 4 | wide | 244 | 232 | 1.052x | 25 | 15 | 1.667x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 4 | wide | 378 | 366 | 1.033x | 26 | 23 | 1.130x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 |  | 170 | 170 | 1.000x | 271 | 268 | 1.011x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| io-mode packet requires an XDP or skb packet context (exit=1) | 4 |
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
