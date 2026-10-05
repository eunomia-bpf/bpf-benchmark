# Corpus Batch Recompile Results

- Generated: 2026-03-22T15:43:51.582829+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 100
- Skip families: `none`
- Target programs: 152
- Compile pairs: 148
- Measured pairs: 94
- Recompile applied programs: 0
- Code-size ratio geomean (baseline/v5): 1.001x
- Exec-time ratio geomean (baseline/v5): 0.921x
- Total sites: 2403
- CMOV sites: 233
- WIDE sites: 330
- ROTATE sites: 1840
- LEA sites: 0
- EXTRACT sites: 0
- ENDIAN sites: 0
- BRANCH-FLIP sites: 0
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-g8a692389396c`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| calico | 59 | 59 | 54 | 0 | 196 | 108 | 10 | 0 | 0 | 0 | 0 | 1.000x | 0.950x | 51 |
| linux-selftests | 59 | 57 | 23 | 0 | 14 | 1 | 1810 | 0 | 0 | 0 | 0 | 1.000x | 0.864x | 16 |
| xdp-tutorial | 20 | 19 | 7 | 0 | 7 | 3 | 0 | 0 | 0 | 0 | 0 | 1.005x | 0.943x | 3 |
| katran | 5 | 5 | 2 | 0 | 6 | 4 | 20 | 0 | 0 | 0 | 0 | 1.000x | 0.816x | 1 |
| xdp-tools | 4 | 3 | 3 | 0 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 1.000x | 0.813x | 2 |
| tracee | 2 | 2 | 2 | 0 | 6 | 214 | 0 | 0 | 0 | 0 | 0 | 1.000x | 0.981x | 1 |
| libbpf-bootstrap | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1.000x | 0.925x | 1 |
| real_world_code_size | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1.000x | 1.000x | 0 |
| suricata | 1 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1.000x | 0.933x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 0 | 1840 | 0 | 4 | 2 | 1.000x | 0.963x | 1 |
| wide | 35 | 0 | 330 | 0 | 35 | 34 | 1.003x | 0.943x | 29 |
| cmov | 68 | 0 | 233 | 0 | 68 | 67 | 1.002x | 0.934x | 52 |
| branch-flip | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| endian | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| extract | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.244x | cmov |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 1.205x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 1.199x | cmov, wide |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1.072x | cmov |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 0.562x | cmov |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 0.575x | cmov, wide |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 0.667x | cmov |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 0.750x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 0.750x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | linux-selftests | sched_cls | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | linux-selftests | sched_cls | 0.750x |  |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.108x | cmov, wide |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 10 |  | 3267 | 3267 | 1.000x | 126 | 136 | 0.926x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 23 |  | 46216 | 46216 | 1.000x | 234 | 238 | 0.983x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 6 |  | 20985 | 20985 | 1.000x | 126 | 131 | 0.962x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 2419 | 2419 | 1.000x | 127 | 137 | 0.927x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 7 |  | 18459 | 18459 | 1.000x | 126 | 136 | 0.926x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 |  | 904 | 904 | 1.000x | 125 | 132 | 0.947x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 |  | 23553 | 23553 | 1.000x | 126 | 133 | 0.947x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 |  | 11905 | 11905 | 1.000x | 126 | 133 | 0.947x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 |  | 10995 | 10995 | 1.000x | 126 | 130 | 0.969x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 16 |  | 33230 | 33230 | 1.000x | 233 | 241 | 0.967x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 |  | 18958 | 18958 | 1.000x | 127 | 135 | 0.941x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 2419 | 2419 | 1.000x | 130 | 139 | 0.935x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 7 |  | 16649 | 16649 | 1.000x | 128 | 135 | 0.948x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 |  | 904 | 904 | 1.000x | 125 | 132 | 0.947x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 7 |  | 21257 | 21257 | 1.000x | 125 | 135 | 0.926x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 |  | 12021 | 12021 | 1.000x | 125 | 132 | 0.947x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 |  | 11114 | 11114 | 1.000x | 126 | 135 | 0.933x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 16 |  | 36713 | 36713 | 1.000x | 126 | 131 | 0.962x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 5 |  | 22205 | 22205 | 1.000x | 128 | 130 | 0.985x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 1738 | 1738 | 1.000x | 127 | 134 | 0.948x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 6 |  | 18069 | 18069 | 1.000x | 126 | 136 | 0.926x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 0 |  | 908 | 908 | 1.000x | 125 | 134 | 0.933x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 3 |  | 18696 | 18696 | 1.000x | 126 | 131 | 0.962x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 4 |  | 11780 | 11780 | 1.000x | 127 | 132 | 0.962x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 3 |  | 11016 | 11016 | 1.000x | 128 | 134 | 0.955x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 10 |  | 22249 | 22249 | 1.000x | 127 | 130 | 0.977x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 18 |  | 42812 | 42812 | 1.000x | 126 | 132 | 0.955x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 |  | 21900 | 21900 | 1.000x | 126 | 133 | 0.947x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 2412 | 2412 | 1.000x | 159 | 132 | 1.205x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 |  | 18811 | 18811 | 1.000x | 169 | 141 | 1.199x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 0 |  | 910 | 910 | 1.000x | 126 | 137 | 0.920x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 |  | 22613 | 22613 | 1.000x | 125 | 132 | 0.947x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 |  | 11471 | 11471 | 1.000x | 126 | 132 | 0.955x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 |  | 10496 | 10496 | 1.000x | 126 | 219 | 0.575x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 10 |  | 22131 | 22131 | 1.000x | 127 | 137 | 0.927x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 18 |  | 42727 | 42727 | 1.000x | 128 | 131 | 0.977x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 7 |  | 21777 | 21777 | 1.000x | 163 | 131 | 1.244x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 2412 | 2412 | 1.000x | 126 | 134 | 0.940x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 |  | 18678 | 18678 | 1.000x | 125 | 133 | 0.940x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 0 |  | 910 | 910 | 1.000x | 130 | 133 | 0.977x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 8 |  | 21952 | 21952 | 1.000x | 126 | 130 | 0.969x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 |  | 11471 | 11471 | 1.000x | 126 | 141 | 0.894x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 |  | 10496 | 10496 | 1.000x | 126 | 135 | 0.933x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 19 |  | 30369 | 30369 | 1.000x | 126 | 132 | 0.955x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 4 |  | 13959 | 13959 | 1.000x | 128 | 136 | 0.941x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 0 |  | 1741 | 1741 | 1.000x | 125 | 135 | 0.926x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 8 |  | 12417 | 12417 | 1.000x | 126 | 130 | 0.969x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 1 |  | 906 | 906 | 1.000x | 125 | 135 | 0.926x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 3 |  | 15711 | 15711 | 1.000x | 127 | 134 | 0.948x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 5 |  | 8039 | 8039 | 1.000x | 126 | 135 | 0.933x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 4 |  | 7265 | 7265 | 1.000x | 126 | 147 | 0.857x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 0 |  | 837 | 837 | 1.000x | n/a | 184 | n/a | stock phase missing from run-kernel output |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | calico | xdp | 0 |  | 1041 | 1041 | 1.000x | 248 | 256 | 0.969x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 4 |  | 4443 | 4443 | 1.000x | 128 | 129 | 0.992x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 125 | 125 | 1.000x | n/a | 185 | n/a | stock phase missing from run-kernel output |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 0 |  | 277 | 277 | 1.000x | n/a | 28 | n/a | stock phase missing from run-kernel output |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | calico | xdp | 0 |  | 280 | 280 | 1.000x | n/a | 26 | n/a | stock phase missing from run-kernel output |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 2 |  | 1829 | 1829 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 31 | 31 | 1.000x | n/a | 14 | n/a | stock phase missing from run-kernel output |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 29 |  | 13654 | 13654 | 1.000x | 19 | 19 | 1.000x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 1 |  | 1637 | 1637 | 1.000x | 4 | 6 | 0.667x |  |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | katran | sched_cls | 0 |  | 553 | 553 | 1.000x | n/a | 12 | n/a | stock phase missing from run-kernel output |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | katran | xdp | 0 |  | 180 | 180 | 1.000x | n/a | 12 | n/a | stock phase missing from run-kernel output |
| corpus/build/katran/xdp_root.bpf.o:xdp_root | katran | xdp | 0 |  | 188 | 188 | 1.000x | n/a | 15 | n/a | stock phase missing from run-kernel output |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 0 |  | 111 | 111 | 1.000x | 147 | 159 | 0.925x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | n/a | 6 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 |  | 53 | 53 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id | linux-selftests | sched_cls | 0 |  | 254 | 254 | 1.000x | n/a | 12 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access | linux-selftests | cgroup_skb | 0 |  | 48 | 48 | 1.000x | n/a | 8 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | sched_cls | 818 |  | 50290 | 50290 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 |  | 406 | 406 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1 |  | 264 | 264 | 1.000x | n/a | 19 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 440 | 440 | 1.000x | n/a | 31 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 122 | 122 | 1.000x | n/a | 275 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 156 | 156 | 1.000x | n/a | 29 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | linux-selftests | cgroup_skb | 0 |  | 77 | 77 | 1.000x | n/a | 9 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx | linux-selftests | sched_cls | 0 |  | 74 | 74 | 1.000x | n/a | 10 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | linux-selftests | cgroup_skb | 0 |  | 43 | 43 | 1.000x | n/a | 7 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | linux-selftests | xdp | 0 |  | 31 | 31 | 1.000x | n/a | 16 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 0 |  | 268 | 268 | 1.000x | 4831 | 4898 | 0.986x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | linux-selftests | sched_cls | 0 |  | 114 | 114 | 1.000x | n/a | 22 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0 |  | 150 | 150 | 1.000x | n/a | 23 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | TypeError: sequence item 0: expected str instance, bytes found (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog | linux-selftests | sched_cls | 0 |  | 129 | 129 | 1.000x | n/a | 6 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | n/a | 11 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs | linux-selftests | sched_cls | 0 |  | 107 | 107 | 1.000x | n/a | 15 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | n/a | 10 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress | linux-selftests | sched_cls | 0 |  | 1268 | 1268 | 1.000x | n/a | 13 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc | linux-selftests | sched_cls | 0 |  | 87 | 87 | 1.000x | n/a | 11 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers | linux-selftests | sched_cls | 0 |  | 116 | 116 | 1.000x | n/a | 22 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 |  | 171 | 171 | 1.000x | 4 | 5 | 0.800x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 |  | 402 | 402 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 |  | 558 | 558 | 1.000x | 15 | 16 | 0.938x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 |  | 527 | 527 | 1.000x | 15 | 15 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 |  | 514 | 514 | 1.000x | 15 | 15 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 0 |  | 479 | 479 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | linux-selftests | sched_cls | 0 |  | 448 | 448 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 0 |  | 435 | 435 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 0 |  | 407 | 407 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth | linux-selftests | sched_cls | 0 |  | 590 | 590 | 1.000x | 3 | 3 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | linux-selftests | sched_cls | 0 |  | 559 | 559 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 0 |  | 546 | 546 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 0 |  | 606 | 606 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | linux-selftests | sched_cls | 0 |  | 494 | 494 | 1.000x | 15 | 16 | 0.938x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 1 |  | 506 | 506 | 1.000x | 15 | 15 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 0 |  | 702 | 702 | 1.000x | 3 | 4 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 1 |  | 691 | 691 | 1.000x | 15 | 16 | 0.938x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | sched_cls | 1 |  | 658 | 658 | 1.000x | 15 | 15 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 1 |  | 645 | 645 | 1.000x | 15 | 15 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 1 |  | 707 | 707 | 1.000x | 15 | 16 | 0.938x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 1 |  | 698 | 698 | 1.000x | n/a | 17 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | sched_cls | 992 |  | 48576 | 48576 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | linux-selftests | sched_cls | 0 |  | 154 | 154 | 1.000x | n/a | 6 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | linux-selftests | xdp | 0 |  | 110 | 110 | 1.000x | n/a | 12 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect | linux-selftests | xdp | 0 |  | 266 | 266 | 1.000x | n/a | 14 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | n/a | 13 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | n/a | 10 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | n/a | 29 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | n/a | 27 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | n/a | 11 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | n/a | 16 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | n/a | 10 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu | linux-selftests | sched_cls | 0 |  | 54 | 54 | 1.000x | n/a | 10 | n/a | stock phase missing from run-kernel output |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect | linux-selftests | xdp | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | real_world_code_size | sched_cls | 0 |  | 111 | 111 | 1.000x | 151 | 151 | 1.000x |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 1 |  | 1645 | 1645 | 1.000x | 14 | 15 | 0.933x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 110 |  | 19482 | 19482 | 1.000x | 26 | 27 | 0.963x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 110 |  | 19482 | 19482 | 1.000x | 26 | 26 | 1.000x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1 |  | 702 | 702 | 1.000x | 21 | 22 | 0.955x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1 |  | 699 | 699 | 1.000x | 21 | 21 | 1.000x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 |  | 78 | 78 | 1.000x | 9 | 16 | 0.562x |  |
| corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | xdp-tools | xdp | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp-tutorial | xdp | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | n/a | 12 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | n/a | 8 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | n/a | 9 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp-tutorial | xdp | 0 |  | 110 | 110 | 1.000x | n/a | 17 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | xdp-tutorial | xdp | 0 |  | 150 | 150 | 1.000x | n/a | 12 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 151 | 151 | 1.000x | n/a | 12 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 151 | 151 | 1.000x | n/a | 14 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 0 |  | 555 | 555 | 1.000x | 5 | 6 | 0.833x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 1 |  | 521 | 521 | 1.000x | 5 | 6 | 0.833x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | n/a | 8 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 2 |  | 123 | 111 | 1.108x | 4 | 4 | 1.000x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 2 |  | 534 | 534 | 1.000x | 5 | 5 | 1.000x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | n/a | 11 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 2 |  | 250 | 250 | 1.000x | 5 | 5 | 1.000x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 2 |  | 385 | 385 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp-tutorial | xdp | 0 |  | 478 | 478 | 1.000x | n/a | 16 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 28 | 28 | 1.000x | n/a | 10 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 233 | 233 | 1.000x | n/a | 235 | n/a | stock phase missing from run-kernel output |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 |  | 171 | 171 | 1.000x | 149 | 139 | 1.072x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| stock phase missing from run-kernel output | 52 |
| bpf_object__load failed: Invalid argument (exit=1) | 6 |
| Katran balancer fixture requires vip_map, reals, ch_rings, and ctl_array (exit=1) | 2 |
| TypeError: sequence item 0: expected str instance, bytes found (exit=1) | 1 |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
