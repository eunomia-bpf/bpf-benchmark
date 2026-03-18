# Corpus Batch Recompile Results

- Generated: 2026-03-12T23:31:49.772815+00:00
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
- Recompile applied programs: 26
- Code-size ratio geomean (baseline/v5): 0.996x
- Exec-time ratio geomean (baseline/v5): 0.859x
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
| calico | 15 | 15 | 15 | 6 | 225 | 48 | 0 | 0 | 13 | 0 | 385 | 32 | 1.000x | 0.965x | 9 |
| linux-selftests | 15 | 15 | 13 | 9 | 27 | 12 | 0 | 0 | 32 | 0 | 40 | 61 | 0.987x | 0.867x | 10 |
| xdp-tutorial | 6 | 6 | 6 | 6 | 10 | 3 | 0 | 0 | 0 | 0 | 0 | 4 | 1.009x | 0.991x | 3 |
| xdp-tools | 3 | 3 | 3 | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 4 | 0 | 0.981x | 0.679x | 2 |
| katran | 2 | 2 | 2 | 0 | 9 | 4 | 20 | 0 | 2 | 0 | 5 | 63 | 1.000x | 0.433x | 2 |
| suricata | 2 | 1 | 1 | 0 | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 6 | 1.000x | 0.933x | 1 |
| tracee | 2 | 2 | 2 | 2 | 26 | 214 | 0 | 0 | 2 | 0 | 4 | 18 | 1.003x | 0.588x | 2 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| endian | 25 | 12 | 438 | 209 | 25 | 25 | 1.001x | 0.821x | 18 |
| cmov | 43 | 26 | 302 | 143 | 42 | 42 | 0.995x | 0.859x | 29 |
| wide | 17 | 12 | 281 | 255 | 17 | 17 | 1.007x | 0.835x | 12 |
| branch-flip | 30 | 0 | 184 | 0 | 30 | 30 | 1.001x | 0.893x | 21 |
| extract | 16 | 7 | 51 | 21 | 16 | 16 | 1.001x | 0.871x | 12 |
| rotate | 1 | 0 | 20 | 0 | 1 | 1 | 1.000x | 0.333x | 1 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1.833x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 1.500x | cmov, wide, extract, endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1.250x | cmov |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.241x | cmov, endian |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1.199x | cmov |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.183x | cmov, endian, branch-flip |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 1.169x | cmov, extract, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 1.072x | cmov, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.047x | cmov, endian, branch-flip |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.043x | cmov, wide |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 0.256x | cmov, endian |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 0.333x | cmov, wide, rotate, extract, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 0.538x | cmov |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 0.562x | cmov, endian, branch-flip |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 0.562x | cmov, wide, extract, endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 0.615x | cmov |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 0.615x | cmov, wide, extract, endian |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 0.621x | cmov, wide, endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 0.643x | cmov |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 0.667x | cmov, endian |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.061x | cmov, wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 1.030x | cmov, wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.016x | cmov, wide |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1.009x | cmov, endian |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1.009x | cmov, endian |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.003x | cmov, wide, extract, endian |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 1.003x | cmov, wide, extract, endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1.003x | cmov |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 1.002x | cmov, wide, extract, endian |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 1.002x | cmov, wide, extract, endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 87 | cmov, wide, extract, endian | 46152 | 46152 | 1.000x | 347 | 333 | 1.042x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 |  | 20957 | 20957 | 1.000x | 245 | 234 | 1.047x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 44 |  | 23489 | 23489 | 1.000x | 174 | 193 | 0.902x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 |  | 33180 | 33180 | 1.000x | 304 | 336 | 0.905x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 30 |  | 18932 | 18932 | 1.000x | 213 | 180 | 1.183x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 21185 | 21185 | 1.000x | 187 | 190 | 0.984x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 |  | 36667 | 36667 | 1.000x | 222 | 308 | 0.721x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 34 | cmov, endian | 22172 | 22170 | 1.000x | 216 | 174 | 1.241x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 | cmov, wide, endian | 18044 | 18042 | 1.000x | 190 | 306 | 0.621x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | cmov, wide, extract, endian | 22218 | 22184 | 1.002x | 169 | 179 | 0.944x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 22542 | 22542 | 1.000x | 174 | 182 | 0.956x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | cmov, wide, extract, endian | 22100 | 22066 | 1.002x | 289 | 278 | 1.040x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 38 |  | 21882 | 21882 | 1.000x | 207 | 177 | 1.169x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 65 | cmov, wide, endian | 30314 | 30309 | 1.000x | 186 | 189 | 0.984x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 22 |  | 13936 | 13936 | 1.000x | 220 | 232 | 0.948x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 94 |  | 13412 | 13412 | 1.000x | 16 | 48 | 0.333x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 9 |  | 1615 | 1615 | 1.000x | 9 | 16 | 0.562x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 | cmov | 53 | 59 | 0.898x | 7 | 8 | 0.875x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 | cmov | 403 | 415 | 0.971x | 7 | 13 | 0.538x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 3 |  | 266 | 266 | 1.000x | 5427 | 5061 | 1.072x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 17 |  | 1676 | 1676 | 1.000x | 1000570917 | 1000782988 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 | cmov | 171 | 176 | 0.972x | 9 | 14 | 0.643x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 | cmov | 392 | 391 | 1.003x | 14 | 17 | 0.824x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 | cmov | 557 | 563 | 0.989x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 | cmov | 526 | 532 | 0.989x | 9 | 13 | 0.692x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 | cmov | 513 | 519 | 0.988x | 10 | 8 | 1.250x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 36 | cmov, wide, extract, endian | 5454 | 5452 | 1.000x | 21 | 14 | 1.500x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 36 | cmov, wide, extract, endian | 5454 | 5452 | 1.000x | 13 | 14 | 0.929x |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 9 |  | 1628 | 1628 | 1.000x | 14 | 15 | 0.933x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 132 | cmov, wide, extract, endian | 19383 | 19320 | 1.003x | 8 | 13 | 0.615x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 132 | cmov, wide, extract, endian | 19383 | 19320 | 1.003x | 9 | 16 | 0.562x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 3 | cmov, endian | 697 | 691 | 1.009x | 10 | 15 | 0.667x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 3 | cmov, endian | 694 | 688 | 1.009x | 10 | 39 | 0.256x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 | cmov | 78 | 84 | 0.929x | 33 | 18 | 1.833x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 2 | cmov | 511 | 514 | 0.994x | 15 | 16 | 0.938x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 | cmov, wide | 122 | 115 | 1.061x | 13 | 13 | 1.000x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 3 | cmov | 526 | 541 | 0.972x | 14 | 15 | 0.933x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 4 | cmov, wide | 244 | 237 | 1.030x | 13 | 15 | 0.867x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 4 | cmov, wide | 378 | 372 | 1.016x | 24 | 23 | 1.043x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 | cmov | 170 | 173 | 0.983x | 259 | 216 | 1.199x |  |

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
