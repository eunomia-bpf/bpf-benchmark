# Corpus Batch Recompile Results

- Generated: 2026-03-13T21:34:46.543772+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `host-fallback`
- Repeat: 200
- Skip families: `none`
- Target programs: 166
- Compile pairs: 0
- Measured pairs: 0
- Recompile applied programs: 0
- Code-size ratio geomean (baseline/v5): n/a
- Exec-time ratio geomean (baseline/v5): n/a
- Total sites: 3763
- CMOV sites: 439
- WIDE sites: 342
- ROTATE sites: 1840
- LEA sites: 0
- EXTRACT sites: 60
- ZERO-EXT sites: 0
- ENDIAN sites: 836
- BRANCH-FLIP sites: 246
- Fallback reason: vm unavailable: ERROR: not a valid pts, try to run vng with a valid PTS (e.g., inside tmux or screen) (exit=1)
- Kernel build: ok (0.00s)

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 71 | 0 | 0 | 0 | 27 | 13 | 1810 | 0 | 10 | 0 | 8 | 17 | n/a | n/a | 0 |
| calico | 59 | 0 | 0 | 0 | 361 | 108 | 10 | 0 | 37 | 0 | 807 | 118 | n/a | n/a | 0 |
| xdp-tutorial | 20 | 0 | 0 | 0 | 10 | 3 | 0 | 0 | 1 | 0 | 5 | 11 | n/a | n/a | 0 |
| katran | 5 | 0 | 0 | 0 | 9 | 4 | 20 | 0 | 2 | 0 | 5 | 68 | n/a | n/a | 0 |
| xdp-tools | 4 | 0 | 0 | 0 | 3 | 0 | 0 | 0 | 0 | 0 | 4 | 0 | n/a | n/a | 0 |
| real_world_code_size | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | n/a | n/a | 0 |
| suricata | 2 | 0 | 0 | 0 | 3 | 0 | 0 | 0 | 8 | 0 | 0 | 14 | n/a | n/a | 0 |
| tracee | 2 | 0 | 0 | 0 | 26 | 214 | 0 | 0 | 2 | 0 | 4 | 18 | n/a | n/a | 0 |
| libbpf-bootstrap | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | n/a | n/a | 0 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 0 | 1840 | 0 | 0 | 0 | n/a | n/a | 0 |
| endian | 65 | 0 | 836 | 0 | 0 | 0 | n/a | n/a | 0 |
| cmov | 80 | 0 | 439 | 0 | 0 | 0 | n/a | n/a | 0 |
| wide | 39 | 0 | 342 | 0 | 0 | 0 | n/a | n/a | 0 |
| branch-flip | 77 | 0 | 246 | 0 | 0 | 0 | n/a | n/a | 0 |
| extract | 34 | 0 | 60 | 0 | 0 | 0 | n/a | n/a | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 13 |  | 3252 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 89 |  | 47898 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 |  | 20979 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2406 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 |  | 18448 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 893 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 44 |  | 23540 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 |  | 11894 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 10984 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 |  | 33209 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 30 |  | 18952 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2406 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 33 |  | 16638 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 893 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 21246 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 |  | 12010 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 11103 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 |  | 36696 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 34 |  | 22199 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 |  | 1727 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 |  | 18058 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 897 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 23 |  | 18685 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 15 |  | 11769 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 11005 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 |  | 22232 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 77 |  | 42793 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 37 |  | 21896 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2399 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 41 |  | 18800 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 899 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 22602 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 |  | 11460 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 10485 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 |  | 22114 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 76 |  | 42708 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 |  | 21773 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2399 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 40 |  | 18667 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 899 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 38 |  | 21941 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 |  | 11460 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 10485 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 65 |  | 30352 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 22 |  | 13955 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 |  | 1730 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 26 |  | 12406 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 895 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 18 |  | 15700 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 9 |  | 8028 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 12 |  | 7254 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1 |  | 826 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | calico | xdp | 6 |  | 1030 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 12 |  | 4430 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 114 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1 |  | 266 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | calico | xdp | 2 |  | 269 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 8 |  | 1816 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 20 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 94 |  | 13652 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 9 |  | 1648 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | katran | sched_cls | 3 |  | 542 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | katran | xdp | 2 |  | 169 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/katran/xdp_root.bpf.o:xdp_root | katran | xdp | 0 |  | 177 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 1 |  | 100 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | linux-selftests | sched_cls | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 |  | 42 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id | linux-selftests | sched_cls | 0 |  | 243 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access | linux-selftests | cgroup_skb | 0 |  | 37 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | sched_cls | 818 |  | 50279 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 |  | 395 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1 |  | 231 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 407 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 100 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 134 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | linux-selftests | cgroup_skb | 0 |  | 66 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx | linux-selftests | sched_cls | 0 |  | 63 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | linux-selftests | cgroup_skb | 0 |  | 32 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | linux-selftests | xdp | 0 |  | 20 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 3 |  | 257 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | linux-selftests | sched_cls | 0 |  | 103 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0 |  | 139 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 17 |  | 1682 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog | linux-selftests | sched_cls | 0 |  | 118 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | linux-selftests | sched_cls | 0 |  | 24 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs | linux-selftests | sched_cls | 0 |  | 74 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | linux-selftests | sched_cls | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple | linux-selftests | sched_cls | 0 |  | 66 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple | linux-selftests | xdp | 0 |  | 66 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress | linux-selftests | sched_cls | 1 |  | 1246 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc | linux-selftests | sched_cls | 0 |  | 76 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers | linux-selftests | sched_cls | 0 |  | 90 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 |  | 160 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 |  | 391 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 |  | 547 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 |  | 516 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 |  | 503 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 1 |  | 468 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | linux-selftests | sched_cls | 1 |  | 437 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 1 |  | 424 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 1 |  | 396 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth | linux-selftests | sched_cls | 1 |  | 579 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | linux-selftests | sched_cls | 1 |  | 548 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 1 |  | 535 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 1 |  | 595 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | linux-selftests | sched_cls | 1 |  | 483 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 1 |  | 495 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 4 |  | 691 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 2 |  | 680 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | sched_cls | 2 |  | 647 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 2 |  | 634 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 2 |  | 696 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 3 |  | 676 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | sched_cls | 992 |  | 48565 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | linux-selftests | sched_cls | 0 |  | 143 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | linux-selftests | xdp | 0 |  | 99 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect | linux-selftests | xdp | 0 |  | 255 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | linux-selftests | xdp | 0 |  | 27 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | linux-selftests | xdp | 0 |  | 27 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | linux-selftests | socket_filter | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | linux-selftests | socket_filter | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve1_nosleep | linux-selftests | socket_filter | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve2_nosleep | linux-selftests | socket_filter | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region_nosleep | linux-selftests | socket_filter | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice_nosleep | linux-selftests | socket_filter | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | linux-selftests | sched_cls | 0 |  | 68 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | linux-selftests | sched_cls | 0 |  | 68 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | linux-selftests | sched_cls | 0 |  | 47 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6 | linux-selftests | sched_cls | 0 |  | 47 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper | linux-selftests | sched_cls | 0 |  | 24 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu | linux-selftests | sched_cls | 0 |  | 43 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect | linux-selftests | xdp | 0 |  | 42 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 5 |  | n/a | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 5 |  | n/a | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 5 |  | n/a | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 5 |  | n/a | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o:socket_handler | real_world_code_size | socket_filter | 1 |  | 363 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | real_world_code_size | sched_cls | 1 |  | 100 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 9 |  | 1634 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 16 |  | 1960 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 132 |  | 19471 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 132 |  | 19471 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 3 |  | 691 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 3 |  | 688 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 |  | 67 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | xdp-tools | xdp | 0 |  | 83 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp-tutorial | xdp | 2 |  | 210 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 20 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 20 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 20 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp-tutorial | xdp | 1 |  | 99 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | xdp-tutorial | xdp | 1 |  | 139 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 1 |  | 140 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 1 |  | 140 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 6 |  | 544 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 2 |  | 510 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp-tutorial | xdp | 0 |  | 20 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 |  | 112 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 3 |  | 523 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 20 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 4 |  | 239 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 4 |  | 374 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp-tutorial | xdp | 1 |  | 467 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 17 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 222 | n/a | n/a | n/a | n/a | n/a |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 |  | 160 | n/a | n/a | n/a | n/a | n/a |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Invalid argument (exit=1) | 4 |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
