# Corpus Batch Recompile Results

- Generated: 2026-03-11T14:15:36.926783+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `cmov`
- Target programs: 79
- Compile pairs: 78
- Measured pairs: 78
- Recompile applied programs: 40
- Code-size ratio geomean (baseline/v5): 1.007x
- Exec-time ratio geomean (baseline/v5): 0.813x
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
| calico | 44 | 44 | 44 | 29 | 196 | 108 | 10 | 1.003x | 0.865x | 37 |
| linux-selftests | 20 | 20 | 20 | 5 | 22 | 13 | 1810 | 1.002x | 0.745x | 14 |
| xdp-tutorial | 6 | 6 | 6 | 3 | 7 | 3 | 0 | 1.031x | 0.762x | 6 |
| xdp-tools | 3 | 3 | 3 | 0 | 3 | 0 | 0 | 1.000x | 0.651x | 3 |
| katran | 2 | 2 | 2 | 1 | 6 | 4 | 20 | 1.012x | 2.089x | 0 |
| suricata | 2 | 1 | 1 | 0 | 2 | 0 | 0 | 1.000x | 0.600x | 1 |
| tracee | 2 | 2 | 2 | 2 | 6 | 214 | 0 | 1.090x | 0.385x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 2 | 1840 | 30 | 4 | 4 | 1.018x | 0.992x | 2 |
| wide | 39 | 39 | 342 | 342 | 39 | 39 | 1.013x | 0.821x | 30 |
| cmov | 73 | 0 | 242 | 0 | 72 | 72 | 1.007x | 0.808x | 57 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 4.000x | cmov |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 1.289x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1.176x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1.143x | cmov |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 1.125x | wide |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.091x | wide, rotate |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 1.090x | wide |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 1.082x | wide |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.055x | cmov |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 1.044x | wide |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 0.148x | wide |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 0.467x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 0.500x | cmov |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 0.533x | wide |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 0.533x | cmov |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 0.545x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 0.562x | cmov |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 0.565x | wide |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 0.583x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 0.583x | cmov |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.108x | wide |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.090x | wide |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 1.090x | wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 1.050x | wide |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 1.046x | rotate |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.032x | wide |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.025x | wide, rotate |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 1.023x | wide |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 1.016x | wide |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 1.011x | wide |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 10 | rotate | 3267 | 3124 | 1.046x | 178 | 180 | 0.989x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 23 | wide | 46216 | 46064 | 1.003x | 327 | 342 | 0.956x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 6 |  | 20985 | 20985 | 1.000x | 176 | 182 | 0.967x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 7 | wide | 18459 | 18435 | 1.001x | 174 | 265 | 0.657x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 |  | 904 | 904 | 1.000x | 173 | 175 | 0.989x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 |  | 23553 | 23553 | 1.000x | 172 | 177 | 0.972x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 | wide | 11905 | 11881 | 1.002x | 177 | 203 | 0.872x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 | wide | 10995 | 10971 | 1.002x | 172 | 193 | 0.891x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 16 | wide | 33230 | 33124 | 1.003x | 328 | 444 | 0.739x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 |  | 18958 | 18958 | 1.000x | 173 | 278 | 0.622x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 7 | wide | 16649 | 16625 | 1.001x | 193 | 244 | 0.791x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 |  | 904 | 904 | 1.000x | 175 | 242 | 0.723x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 7 |  | 21257 | 21257 | 1.000x | 171 | 178 | 0.961x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 | wide | 12021 | 11997 | 1.002x | 176 | 251 | 0.701x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 | wide | 11114 | 11090 | 1.002x | 175 | 189 | 0.926x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 16 | wide | 36713 | 36613 | 1.003x | 212 | 249 | 0.851x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 5 |  | 22205 | 22205 | 1.000x | 180 | 176 | 1.023x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 6 | wide | 18069 | 18045 | 1.001x | 176 | 330 | 0.533x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 3 |  | 18696 | 18696 | 1.000x | 193 | 202 | 0.955x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 | wide | 11780 | 11756 | 1.002x | 172 | 189 | 0.910x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 | wide | 11016 | 10992 | 1.002x | 170 | 205 | 0.829x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 10 | wide | 22249 | 22197 | 1.002x | 175 | 190 | 0.921x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 18 | wide | 42812 | 42678 | 1.003x | 179 | 182 | 0.984x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 |  | 21900 | 21900 | 1.000x | 192 | 227 | 0.846x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 | wide | 18811 | 18787 | 1.001x | 191 | 183 | 1.044x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 |  | 22613 | 22613 | 1.000x | 175 | 178 | 0.983x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 | wide | 11471 | 11447 | 1.002x | 175 | 179 | 0.978x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 | wide | 10496 | 10472 | 1.002x | 193 | 177 | 1.090x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 10 | wide | 22131 | 22079 | 1.002x | 180 | 174 | 1.034x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 18 | wide | 42727 | 42597 | 1.003x | 187 | 198 | 0.944x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 |  | 21777 | 21777 | 1.000x | 194 | 279 | 0.695x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 | wide | 18678 | 18654 | 1.001x | 175 | 181 | 0.967x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 |  | 21952 | 21952 | 1.000x | 176 | 323 | 0.545x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 | wide | 11471 | 11447 | 1.002x | 170 | 178 | 0.955x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 | wide | 10496 | 10472 | 1.002x | 175 | 217 | 0.806x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 19 | wide | 30369 | 30238 | 1.004x | 198 | 183 | 1.082x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 4 |  | 13959 | 13959 | 1.000x | 193 | 183 | 1.055x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 | wide | 12417 | 12393 | 1.002x | 188 | 280 | 0.671x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 |  | 906 | 906 | 1.000x | 173 | 179 | 0.966x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 3 |  | 15711 | 15711 | 1.000x | 232 | 180 | 1.289x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 | wide | 8039 | 8015 | 1.003x | 173 | 306 | 0.565x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 | wide | 7265 | 7241 | 1.003x | 176 | 257 | 0.685x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 4 | wide | 4443 | 4395 | 1.011x | 190 | 208 | 0.913x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 2 | wide | 1829 | 1801 | 1.016x | 13 | 15 | 0.867x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 29 | wide, rotate | 13654 | 13319 | 1.025x | 12 | 11 | 1.091x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 1 |  | 1637 | 1637 | 1.000x | 36 | 9 | 4.000x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 |  | 53 | 53 | 1.000x | 8 | 15 | 0.533x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | sched_cls | 818 |  | 50290 | 50290 | 1.000x | 535 | 524 | 1.021x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 |  | 406 | 406 | 1.000x | 8 | 16 | 0.500x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1 |  | 264 | 264 | 1.000x | 20 | 17 | 1.176x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 |  | 171 | 171 | 1.000x | 9 | 15 | 0.600x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 |  | 402 | 402 | 1.000x | 11 | 17 | 0.647x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 |  | 558 | 558 | 1.000x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 |  | 527 | 527 | 1.000x | 9 | 16 | 0.562x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 |  | 514 | 514 | 1.000x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 1 |  | 506 | 506 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 1 |  | 691 | 691 | 1.000x | 9 | 12 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | sched_cls | 1 |  | 658 | 658 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 1 |  | 645 | 645 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 1 |  | 707 | 707 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 1 | wide | 698 | 682 | 1.023x | 7 | 11 | 0.636x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | sched_cls | 992 |  | 48576 | 48576 | 1.000x | 473 | 539 | 0.878x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 5 | wide | 5492 | 5456 | 1.007x | 8 | 8 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 5 | wide | 5522 | 5486 | 1.007x | 9 | 9 | 1.000x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 5 | wide | 5492 | 5456 | 1.007x | 9 | 8 | 1.125x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 5 | wide | 5522 | 5486 | 1.007x | 8 | 10 | 0.800x |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 1 |  | 1645 | 1645 | 1.000x | 9 | 15 | 0.600x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 110 | wide | 19482 | 17871 | 1.090x | 8 | 54 | 0.148x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 110 | wide | 19482 | 17871 | 1.090x | 8 | 8 | 1.000x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1 |  | 702 | 702 | 1.000x | 10 | 14 | 0.714x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1 |  | 699 | 699 | 1.000x | 9 | 15 | 0.600x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 |  | 78 | 78 | 1.000x | 18 | 28 | 0.643x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 1 |  | 521 | 521 | 1.000x | 7 | 15 | 0.467x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 2 | wide | 123 | 111 | 1.108x | 10 | 13 | 0.769x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 2 |  | 534 | 534 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 2 | wide | 250 | 238 | 1.050x | 10 | 15 | 0.667x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 2 | wide | 385 | 373 | 1.032x | 15 | 16 | 0.938x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 |  | 171 | 171 | 1.000x | 179 | 182 | 0.984x |  |

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
