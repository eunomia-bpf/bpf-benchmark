# Corpus Batch Recompile Results

- Generated: 2026-03-11T20:59:25.353666+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 166
- Compile pairs: 163
- Measured pairs: 163
- Recompile applied programs: 92
- Code-size ratio geomean (baseline/v5): 0.999x
- Exec-time ratio geomean (baseline/v5): 0.868x
- Total sites: 2714
- CMOV sites: 446
- WIDE sites: 342
- ROTATE sites: 1840
- LEA sites: 0
- EXTRACT sites: 86
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-ge52504a75c05`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 71 | 69 | 69 | 30 | 35 | 13 | 1810 | 0 | 42 | 0.996x | 0.802x | 49 |
| calico | 59 | 59 | 59 | 47 | 361 | 108 | 10 | 0 | 37 | 1.001x | 0.935x | 39 |
| xdp-tutorial | 20 | 20 | 20 | 7 | 10 | 3 | 0 | 0 | 1 | 0.999x | 0.983x | 9 |
| katran | 5 | 5 | 5 | 2 | 9 | 4 | 20 | 0 | 2 | 1.004x | 0.776x | 4 |
| xdp-tools | 4 | 4 | 4 | 3 | 3 | 0 | 0 | 0 | 0 | 0.977x | 1.003x | 1 |
| real_world_code_size | 2 | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 1.000x | 0.622x | 2 |
| suricata | 2 | 1 | 1 | 1 | 2 | 0 | 0 | 0 | 2 | 0.996x | 1.111x | 0 |
| tracee | 2 | 2 | 2 | 2 | 26 | 214 | 0 | 0 | 2 | 1.089x | 0.653x | 2 |
| libbpf-bootstrap | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1.000x | 0.583x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 2 | 1840 | 30 | 4 | 4 | 1.017x | 0.950x | 3 |
| cmov | 80 | 79 | 446 | 445 | 79 | 79 | 0.997x | 0.916x | 53 |
| wide | 39 | 39 | 342 | 342 | 39 | 39 | 1.008x | 0.885x | 28 |
| extract | 37 | 37 | 86 | 86 | 37 | 37 | 1.006x | 0.833x | 29 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 16.743x | cmov |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 1.571x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp-tutorial | xdp | 1.375x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | linux-selftests | sched_cls | 1.286x |  |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp-tutorial | xdp | 1.273x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 1.250x | cmov |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 1.250x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.203x | cmov, wide |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1.200x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 1.198x | cmov, extract |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region_nosleep | linux-selftests | socket_filter | 0.438x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice_nosleep | linux-selftests | socket_filter | 0.438x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 0.500x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 0.500x | cmov |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 0.529x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 0.538x | cmov, wide |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.551x | cmov, wide, extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | linux-selftests | cgroup_skb | 0.556x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 0.561x | cmov, wide |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 0.583x |  |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.089x | cmov, wide, extract |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 1.089x | cmov, wide, extract |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 1.046x | rotate |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.023x | cmov, wide, rotate, extract |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 1.016x | wide |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 1.015x | cmov, wide |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 1.011x | wide |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.008x | cmov, wide |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 1.007x | cmov, wide, extract |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 1.007x | cmov, wide, extract |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 10 | rotate | 3260 | 3117 | 1.046x | 192 | 174 | 1.103x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 33 | cmov, wide, extract | 46152 | 46072 | 1.002x | 334 | 359 | 0.930x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 10 | cmov | 20957 | 20993 | 0.998x | 175 | 228 | 0.768x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 2408 | 2408 | 1.000x | 187 | 301 | 0.621x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 | cmov, wide | 18440 | 18434 | 1.000x | 183 | 248 | 0.738x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 896 | 902 | 0.993x | 198 | 174 | 1.138x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 20 | cmov, extract | 23489 | 23502 | 0.999x | 195 | 214 | 0.911x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 6 | cmov, wide | 11888 | 11877 | 1.001x | 173 | 172 | 1.006x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 7 | cmov, wide, extract | 10978 | 10960 | 1.002x | 196 | 225 | 0.871x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 25 | cmov, wide, extract | 33180 | 33131 | 1.001x | 325 | 331 | 0.982x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 10 | cmov | 18932 | 18968 | 0.998x | 178 | 182 | 0.978x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 2408 | 2408 | 1.000x | 180 | 207 | 0.870x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 9 | cmov, wide | 16630 | 16629 | 1.000x | 187 | 296 | 0.632x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 896 | 902 | 0.993x | 184 | 175 | 1.051x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 22 | cmov, extract | 21185 | 21206 | 0.999x | 205 | 192 | 1.068x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 6 | cmov, wide | 12004 | 11993 | 1.001x | 213 | 177 | 1.203x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 7 | cmov, wide, extract | 11097 | 11079 | 1.002x | 177 | 191 | 0.927x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 29 | cmov, wide | 36667 | 36626 | 1.001x | 172 | 231 | 0.745x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 8 | cmov | 22172 | 22198 | 0.999x | 178 | 177 | 1.006x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 1729 | 1729 | 1.000x | 169 | 184 | 0.918x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 9 | cmov, wide | 18044 | 18026 | 1.001x | 171 | 305 | 0.561x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 900 | 902 | 0.998x | 182 | 187 | 0.973x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 7 | cmov, extract | 18632 | 18646 | 0.999x | 168 | 176 | 0.955x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 | cmov, wide | 11762 | 11744 | 1.002x | 212 | 224 | 0.946x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 7 | cmov, wide, extract | 10999 | 10978 | 1.002x | 175 | 201 | 0.871x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 23 | cmov, wide, extract | 22218 | 22219 | 1.000x | 173 | 180 | 0.961x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 26 | cmov, wide, extract | 42747 | 42671 | 1.002x | 178 | 323 | 0.551x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 10 | cmov | 21862 | 21900 | 0.998x | 192 | 195 | 0.985x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 2401 | 2401 | 1.000x | 174 | 178 | 0.978x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 10 | cmov, wide | 18781 | 18781 | 1.000x | 177 | 182 | 0.973x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 902 | 904 | 0.998x | 189 | 176 | 1.074x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 20 | cmov, extract | 22542 | 22557 | 0.999x | 174 | 208 | 0.837x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 6 | cmov, wide | 11454 | 11443 | 1.001x | 170 | 179 | 0.950x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 7 | cmov, wide, extract | 10479 | 10460 | 1.002x | 175 | 180 | 0.972x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 23 | cmov, wide, extract | 22100 | 22101 | 1.000x | 192 | 176 | 1.091x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 26 | cmov, wide, extract | 42660 | 42588 | 1.002x | 173 | 187 | 0.925x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 10 | cmov | 21739 | 21777 | 0.998x | 174 | 177 | 0.983x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 2401 | 2401 | 1.000x | 176 | 222 | 0.793x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 10 | cmov, wide | 18648 | 18648 | 1.000x | 173 | 182 | 0.951x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 902 | 904 | 0.998x | 177 | 182 | 0.973x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 19 | cmov, extract | 21882 | 21891 | 1.000x | 195 | 180 | 1.083x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 6 | cmov, wide | 11454 | 11443 | 1.001x | 210 | 220 | 0.955x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 7 | cmov, wide, extract | 10479 | 10460 | 1.002x | 174 | 173 | 1.006x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 27 | cmov, wide | 30314 | 30240 | 1.002x | 196 | 192 | 1.021x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 8 | cmov | 13936 | 13966 | 0.998x | 221 | 235 | 0.940x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 1732 | 1732 | 1.000x | 177 | 177 | 1.000x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 | cmov, wide | 12395 | 12387 | 1.001x | 173 | 175 | 0.989x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 898 | 904 | 0.993x | 173 | 175 | 0.989x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 | cmov, extract | 15641 | 15663 | 0.999x | 212 | 177 | 1.198x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 | cmov, wide | 8023 | 8010 | 1.002x | 177 | 178 | 0.994x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 7 | cmov, wide, extract | 7250 | 7234 | 1.002x | 174 | 174 | 1.000x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 0 |  | 831 | 831 | 1.000x | 169 | 173 | 0.977x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | calico | xdp | 0 |  | 1035 | 1035 | 1.000x | 353 | 339 | 1.041x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 4 | wide | 4427 | 4379 | 1.011x | 192 | 175 | 1.097x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 125 | 125 | 1.000x | 200 | 181 | 1.105x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 0 |  | 271 | 271 | 1.000x | 15 | 22 | 0.682x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | calico | xdp | 0 |  | 274 | 274 | 1.000x | 15 | 16 | 0.938x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 2 | wide | 1816 | 1788 | 1.016x | 16 | 15 | 1.067x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 8 | 1.000x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 34 | cmov, wide, rotate, extract | 13412 | 13113 | 1.023x | 11 | 13 | 0.846x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 1 | cmov | 1615 | 1618 | 0.998x | 9 | 17 | 0.529x |  |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | katran | sched_cls | 0 |  | 544 | 544 | 1.000x | 7 | 11 | 0.636x |  |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | katran | xdp | 0 |  | 174 | 174 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/katran/xdp_root.bpf.o:xdp_root | katran | xdp | 0 |  | 188 | 188 | 1.000x | 10 | 9 | 1.111x |  |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 0 |  | 111 | 111 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 | cmov | 53 | 59 | 0.898x | 9 | 12 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id | linux-selftests | sched_cls | 0 |  | 253 | 253 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access | linux-selftests | cgroup_skb | 0 |  | 47 | 47 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | sched_cls | 818 |  | 50198 | 50198 | 1.000x | 486 | 548 | 0.887x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 | cmov | 403 | 415 | 0.971x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1 | cmov | 254 | 260 | 0.977x | 19 | 25 | 0.760x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 426 | 426 | 1.000x | 23 | 36 | 0.639x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 122 | 122 | 1.000x | 264 | 220 | 1.200x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 151 | 151 | 1.000x | 44 | 39 | 1.128x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | linux-selftests | cgroup_skb | 0 |  | 75 | 75 | 1.000x | 10 | 18 | 0.556x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx | linux-selftests | sched_cls | 0 |  | 72 | 72 | 1.000x | 10 | 16 | 0.625x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | linux-selftests | cgroup_skb | 0 |  | 42 | 42 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | linux-selftests | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 8 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 1 | cmov | 266 | 272 | 0.978x | 4487 | 268 | 16.743x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | linux-selftests | sched_cls | 0 |  | 114 | 114 | 1.000x | 18 | 17 | 1.059x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0 |  | 148 | 148 | 1.000x | 17 | 17 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 2 | cmov | 1676 | 1678 | 0.999x | 1000815121 | 1000685007 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog | linux-selftests | sched_cls | 0 |  | 129 | 129 | 1.000x | 9 | 12 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | 11 | 11 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs | linux-selftests | sched_cls | 0 |  | 107 | 107 | 1.000x | 13 | 17 | 0.765x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple | linux-selftests | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple | linux-selftests | xdp | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress | linux-selftests | sched_cls | 0 |  | 1244 | 1244 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc | linux-selftests | sched_cls | 0 |  | 86 | 86 | 1.000x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers | linux-selftests | sched_cls | 0 |  | 115 | 115 | 1.000x | 21 | 32 | 0.656x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 | cmov | 171 | 176 | 0.972x | 10 | 16 | 0.625x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 | cmov | 392 | 398 | 0.985x | 11 | 17 | 0.647x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 | cmov | 557 | 563 | 0.989x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 | cmov | 526 | 532 | 0.989x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 | cmov | 513 | 519 | 0.988x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 1 | extract | 479 | 479 | 1.000x | 8 | 16 | 0.500x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | linux-selftests | sched_cls | 1 | extract | 448 | 448 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 1 | extract | 435 | 435 | 1.000x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 1 | extract | 407 | 407 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth | linux-selftests | sched_cls | 1 | extract | 589 | 589 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | linux-selftests | sched_cls | 1 | extract | 558 | 558 | 1.000x | 7 | 9 | 0.778x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 1 | extract | 545 | 545 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 1 | extract | 605 | 605 | 1.000x | 10 | 12 | 0.833x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | linux-selftests | sched_cls | 1 | extract | 491 | 491 | 1.000x | 9 | 13 | 0.692x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 1 | cmov | 505 | 511 | 0.988x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 2 | cmov, extract | 697 | 703 | 0.991x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 1 | cmov | 689 | 695 | 0.991x | 10 | 8 | 1.250x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | sched_cls | 1 | cmov | 656 | 662 | 0.991x | 9 | 8 | 1.125x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 1 | cmov | 643 | 649 | 0.991x | 8 | 16 | 0.500x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 1 | cmov | 705 | 711 | 0.992x | 7 | 9 | 0.778x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 2 | cmov, wide | 696 | 686 | 1.015x | 7 | 13 | 0.538x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | sched_cls | 992 |  | 48574 | 48574 | 1.000x | 476 | 483 | 0.986x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | linux-selftests | sched_cls | 0 |  | 152 | 152 | 1.000x | 9 | 7 | 1.286x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | linux-selftests | xdp | 0 |  | 107 | 107 | 1.000x | 8 | 10 | 0.800x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect | linux-selftests | xdp | 0 |  | 251 | 251 | 1.000x | 9 | 10 | 0.900x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | 11 | 11 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | 10 | 10 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | 10 | 11 | 0.909x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | 8 | 11 | 0.727x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | 8 | 11 | 0.727x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | 7 | 11 | 0.636x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | 7 | 16 | 0.438x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | 7 | 16 | 0.438x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | 28 | 26 | 1.077x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | 26 | 25 | 1.040x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | 12 | 13 | 0.923x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | 12 | 18 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu | linux-selftests | sched_cls | 0 |  | 54 | 54 | 1.000x | 10 | 16 | 0.625x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect | linux-selftests | xdp | 0 |  | 53 | 53 | 1.000x | 10 | 10 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 15 | cmov, wide, extract | 5424 | 5391 | 1.006x | 8 | 8 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 15 | cmov, wide, extract | 5454 | 5414 | 1.007x | 9 | 10 | 0.900x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 15 | cmov, wide, extract | 5424 | 5391 | 1.006x | 8 | 11 | 0.727x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 15 | cmov, wide, extract | 5454 | 5414 | 1.007x | 9 | 10 | 0.900x |  |
| corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o:socket_handler | real_world_code_size | socket_filter | 0 |  | 374 | 374 | 1.000x | 14 | 23 | 0.609x |  |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | real_world_code_size | sched_cls | 0 |  | 111 | 111 | 1.000x | 7 | 11 | 0.636x |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 3 | cmov, extract | 1628 | 1634 | 0.996x | 10 | 9 | 1.111x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 121 | cmov, wide, extract | 19383 | 17803 | 1.089x | 9 | 13 | 0.692x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 121 | cmov, wide, extract | 19383 | 17803 | 1.089x | 8 | 13 | 0.615x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1 | cmov | 697 | 703 | 0.991x | 10 | 9 | 1.111x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1 | cmov | 694 | 700 | 0.991x | 10 | 10 | 1.000x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 | cmov | 78 | 84 | 0.929x | 15 | 15 | 1.000x |  |
| corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | xdp-tools | xdp | 0 |  | 91 | 91 | 1.000x | 10 | 11 | 0.909x |  |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp-tutorial | xdp | 0 |  | 215 | 215 | 1.000x | 11 | 16 | 0.688x |  |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 11 | 10 | 1.100x |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 11 | 7 | 1.571x |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 10 | 0.800x |  |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp-tutorial | xdp | 0 |  | 108 | 108 | 1.000x | 14 | 11 | 1.273x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | xdp-tutorial | xdp | 0 |  | 145 | 145 | 1.000x | 10 | 15 | 0.667x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 146 | 146 | 1.000x | 10 | 10 | 1.000x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 146 | 146 | 1.000x | 10 | 9 | 1.111x |  |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 1 | extract | 549 | 549 | 1.000x | 9 | 10 | 0.900x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 1 | cmov | 511 | 514 | 0.994x | 10 | 12 | 0.833x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 11 | 8 | 1.375x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 | cmov, wide | 122 | 121 | 1.008x | 10 | 10 | 1.000x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 2 | cmov | 526 | 541 | 0.972x | 8 | 9 | 0.889x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 10 | 8 | 1.250x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 3 | cmov, wide | 244 | 243 | 1.004x | 11 | 10 | 1.100x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 3 | cmov, wide | 378 | 378 | 1.000x | 15 | 16 | 0.938x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp-tutorial | xdp | 0 |  | 471 | 471 | 1.000x | 10 | 17 | 0.588x |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 28 | 28 | 1.000x | 9 | 8 | 1.125x |  |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 231 | 231 | 1.000x | 231 | 214 | 1.079x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 | cmov | 170 | 169 | 1.006x | 193 | 206 | 0.937x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Permission denied (exit=1) | 4 |
| bpf_object__load failed: Argument list too long (exit=1) | 2 |

## Recompile Failures

| Reason | Count |
| --- | --- |
| BPF_PROG_JIT_RECOMPILE failed: Argument list too long (errno=7) | 4 |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- `--skip-families` filters families out of the auto-generated v5 policy; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
