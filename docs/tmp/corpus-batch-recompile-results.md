# Corpus Batch Recompile Results

- Generated: 2026-03-11T14:09:26.065737+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 79
- Compile pairs: 78
- Measured pairs: 78
- Recompile applied programs: 76
- Code-size ratio geomean (baseline/v5): 1.000x
- Exec-time ratio geomean (baseline/v5): 0.826x
- Total sites: 2424
- CMOV sites: 242
- WIDE sites: 342
- ROTATE sites: 1840
- LEA sites: 0
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-g2a6783cc77b6`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 44 | 44 | 44 | 44 | 196 | 108 | 10 | 1.002x | 0.828x | 36 |
| linux-selftests | 20 | 20 | 20 | 18 | 22 | 13 | 1810 | 0.988x | 0.759x | 15 |
| xdp-tutorial | 6 | 6 | 6 | 6 | 7 | 3 | 0 | 1.013x | 0.837x | 4 |
| xdp-tools | 3 | 3 | 3 | 3 | 3 | 0 | 0 | 0.970x | 0.930x | 1 |
| katran | 2 | 2 | 2 | 2 | 6 | 4 | 20 | 1.011x | 0.815x | 1 |
| suricata | 2 | 1 | 1 | 1 | 2 | 0 | 0 | 0.996x | 1.250x | 0 |
| tracee | 2 | 2 | 2 | 2 | 6 | 214 | 0 | 1.090x | 1.231x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 2 | 1840 | 30 | 4 | 4 | 1.017x | 0.990x | 2 |
| wide | 39 | 39 | 342 | 342 | 39 | 39 | 1.010x | 0.841x | 31 |
| cmov | 73 | 72 | 242 | 241 | 72 | 72 | 0.999x | 0.821x | 54 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 2.462x | cmov, wide |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 1.371x | cmov, wide |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 1.250x | cmov |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 1.250x | cmov |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.182x | cmov, wide, rotate |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1.143x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 1.143x | cmov |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1.125x | cmov |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1.111x | cmov |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.103x | cmov |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 0.486x | cmov, wide |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 0.538x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 0.538x | cmov |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 0.555x | cmov, wide |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 0.562x | cmov |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 0.570x | cmov, wide |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 0.571x | cmov, wide |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 0.583x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 0.583x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 0.583x | wide |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.090x | cmov, wide |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 1.090x | cmov, wide |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.060x | cmov, wide |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 1.046x | rotate |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 1.029x | cmov, wide |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.024x | cmov, wide, rotate |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 1.023x | wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.016x | cmov, wide |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 1.016x | wide |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 1.011x | wide |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 10 | rotate | 3267 | 3124 | 1.046x | 177 | 177 | 1.000x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 23 | cmov, wide | 46216 | 46113 | 1.002x | 329 | 329 | 1.000x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 6 | cmov | 20985 | 21008 | 0.999x | 193 | 175 | 1.103x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 7 | cmov, wide | 18459 | 18454 | 1.000x | 171 | 308 | 0.555x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 904 | 910 | 0.993x | 198 | 241 | 0.822x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 | cmov | 23553 | 23566 | 0.999x | 189 | 303 | 0.624x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 | cmov, wide | 11905 | 11889 | 1.001x | 174 | 219 | 0.795x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 | cmov, wide | 10995 | 10977 | 1.002x | 178 | 192 | 0.927x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 16 | cmov, wide | 33230 | 33157 | 1.002x | 304 | 328 | 0.927x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 | cmov | 18958 | 18980 | 0.999x | 172 | 276 | 0.623x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 7 | cmov, wide | 16649 | 16650 | 1.000x | 172 | 281 | 0.612x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 904 | 910 | 0.993x | 179 | 223 | 0.803x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 7 | cmov | 21257 | 21277 | 0.999x | 170 | 198 | 0.859x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 | cmov, wide | 12021 | 12005 | 1.001x | 169 | 184 | 0.918x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 | cmov, wide | 11114 | 11096 | 1.002x | 233 | 170 | 1.371x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 16 | cmov, wide | 36713 | 36647 | 1.002x | 172 | 199 | 0.864x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 5 | cmov | 22205 | 22227 | 0.999x | 175 | 196 | 0.893x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 6 | cmov, wide | 18069 | 18060 | 1.000x | 176 | 194 | 0.907x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 3 | cmov | 18696 | 18704 | 1.000x | 169 | 201 | 0.841x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 | cmov, wide | 11780 | 11762 | 1.002x | 172 | 238 | 0.723x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 | cmov, wide | 11016 | 10995 | 1.002x | 170 | 200 | 0.850x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 10 | cmov, wide | 22249 | 22226 | 1.001x | 175 | 307 | 0.570x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 18 | cmov, wide | 42812 | 42714 | 1.002x | 193 | 199 | 0.970x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 | cmov | 21900 | 21925 | 0.999x | 195 | 284 | 0.687x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 | cmov, wide | 18811 | 18813 | 1.000x | 189 | 269 | 0.703x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 | cmov | 22613 | 22630 | 0.999x | 173 | 175 | 0.989x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 | cmov, wide | 11471 | 11454 | 1.001x | 189 | 237 | 0.797x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 | cmov, wide | 10496 | 10477 | 1.002x | 175 | 360 | 0.486x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 10 | cmov, wide | 22131 | 22108 | 1.001x | 217 | 247 | 0.879x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 18 | cmov, wide | 42727 | 42633 | 1.002x | 176 | 177 | 0.994x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 | cmov | 21777 | 21802 | 0.999x | 179 | 179 | 1.000x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 | cmov, wide | 18678 | 18680 | 1.000x | 170 | 232 | 0.733x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 | cmov | 21952 | 21969 | 0.999x | 178 | 283 | 0.629x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 | cmov, wide | 11471 | 11454 | 1.001x | 175 | 189 | 0.926x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 | cmov, wide | 10496 | 10477 | 1.002x | 172 | 188 | 0.915x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 19 | cmov, wide | 30369 | 30282 | 1.003x | 174 | 190 | 0.916x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 4 | cmov | 13959 | 13976 | 0.999x | 172 | 294 | 0.585x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 | cmov, wide | 12417 | 12409 | 1.001x | 185 | 285 | 0.649x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 | cmov | 906 | 912 | 0.993x | 177 | 177 | 1.000x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 3 | cmov | 15711 | 15725 | 0.999x | 171 | 179 | 0.955x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 | cmov, wide | 8039 | 8026 | 1.002x | 177 | 176 | 1.006x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 | cmov, wide | 7265 | 7249 | 1.002x | 177 | 219 | 0.808x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 4 | wide | 4443 | 4395 | 1.011x | 177 | 183 | 0.967x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 2 | wide | 1829 | 1801 | 1.016x | 16 | 15 | 1.067x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 29 | cmov, wide, rotate | 13654 | 13339 | 1.024x | 13 | 11 | 1.182x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 1 | cmov | 1637 | 1640 | 0.998x | 9 | 16 | 0.562x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 | cmov | 53 | 59 | 0.898x | 9 | 11 | 0.818x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | sched_cls | 818 |  | 50290 | 50290 | 1.000x | 485 | 563 | 0.861x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 | cmov | 406 | 418 | 0.971x | 7 | 13 | 0.538x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1 | cmov | 264 | 270 | 0.978x | 18 | 28 | 0.643x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 | cmov | 171 | 176 | 0.972x | 10 | 15 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 | cmov | 402 | 408 | 0.985x | 11 | 16 | 0.688x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 | cmov | 558 | 564 | 0.989x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 | cmov | 527 | 533 | 0.989x | 7 | 13 | 0.538x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 | cmov | 514 | 520 | 0.988x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 1 | cmov | 506 | 512 | 0.988x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 1 | cmov | 691 | 697 | 0.991x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | sched_cls | 1 | cmov | 658 | 664 | 0.991x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 1 | cmov | 645 | 651 | 0.991x | 10 | 8 | 1.250x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 1 | cmov | 707 | 713 | 0.992x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 1 | wide | 698 | 682 | 1.023x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | sched_cls | 992 |  | 48576 | 48576 | 1.000x | 474 | 502 | 0.944x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 5 | cmov, wide | 5492 | 5462 | 1.005x | 8 | 9 | 0.889x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 5 | cmov, wide | 5522 | 5492 | 1.005x | 9 | 9 | 1.000x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 5 | cmov, wide | 5492 | 5462 | 1.005x | 8 | 14 | 0.571x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 5 | cmov, wide | 5522 | 5492 | 1.005x | 9 | 14 | 0.643x |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 1 | cmov | 1645 | 1651 | 0.996x | 10 | 8 | 1.250x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 110 | cmov, wide | 19482 | 17880 | 1.090x | 8 | 13 | 0.615x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 110 | cmov, wide | 19482 | 17880 | 1.090x | 32 | 13 | 2.462x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1 | cmov | 702 | 708 | 0.992x | 9 | 14 | 0.643x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1 | cmov | 699 | 705 | 0.991x | 10 | 9 | 1.111x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 | cmov | 78 | 84 | 0.929x | 18 | 16 | 1.125x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 1 | cmov | 521 | 524 | 0.994x | 11 | 11 | 1.000x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 2 | cmov, wide | 123 | 116 | 1.060x | 8 | 9 | 0.889x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 2 | cmov | 534 | 549 | 0.973x | 11 | 17 | 0.647x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 2 | cmov, wide | 250 | 243 | 1.029x | 10 | 10 | 1.000x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 2 | cmov, wide | 385 | 379 | 1.016x | 17 | 25 | 0.680x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 | cmov | 171 | 170 | 1.006x | 211 | 240 | 0.879x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Argument list too long (exit=1) | 2 |

## Recompile Failures

| Reason | Count |
| --- | --- |
| BPF_PROG_JIT_RECOMPILE failed: Argument list too long (errno=7) | 4 |

## Notes

- Target selection comes from the runnability inventory and keeps only the 79 packet-test-run programs that previously formed a paired baseline/recompile set with directive sites.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- `--skip-families` filters families out of the auto-generated v5 policy; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
