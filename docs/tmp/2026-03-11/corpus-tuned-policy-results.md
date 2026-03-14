# Corpus Batch Recompile Results

- Generated: 2026-03-12T01:15:33.643587+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 166
- Compile pairs: 148
- Measured pairs: 142
- Recompile applied programs: 94
- Code-size ratio geomean (baseline/v5): 1.003x
- Exec-time ratio geomean (baseline/v5): 0.898x
- Total sites: 3690
- CMOV sites: 418
- WIDE sites: 342
- ROTATE sites: 1840
- LEA sites: 0
- EXTRACT sites: 50
- ZERO-EXT sites: 0
- ENDIAN sites: 826
- BRANCH-FLIP sites: 214
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-ge52504a75c05`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 71 | 60 | 54 | 18 | 27 | 13 | 1810 | 0 | 10 | 0 | 8 | 17 | 1.000x | 0.900x | 31 |
| calico | 59 | 59 | 59 | 57 | 361 | 108 | 10 | 0 | 37 | 0 | 805 | 118 | 1.003x | 0.914x | 39 |
| xdp-tutorial | 20 | 20 | 20 | 12 | 10 | 3 | 0 | 0 | 1 | 0 | 5 | 11 | 1.011x | 0.881x | 10 |
| katran | 5 | 5 | 5 | 4 | 9 | 4 | 20 | 0 | 2 | 0 | 5 | 68 | 1.006x | 0.777x | 3 |
| xdp-tools | 4 | 3 | 3 | 2 | 3 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | 0.976x | 1.040x | 0 |
| real_world_code_size | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| suricata | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| tracee | 2 | 0 | 0 | 0 | 6 | 214 | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| libbpf-bootstrap | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1.028x | 0.583x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 2 | 1840 | 30 | 4 | 4 | 1.018x | 0.833x | 2 |
| endian | 60 | 59 | 826 | 825 | 59 | 59 | 1.006x | 0.904x | 38 |
| cmov | 80 | 12 | 418 | 49 | 71 | 71 | 1.004x | 0.932x | 44 |
| wide | 39 | 33 | 342 | 116 | 33 | 33 | 1.011x | 0.915x | 21 |
| branch-flip | 73 | 73 | 214 | 214 | 73 | 73 | 1.004x | 0.931x | 47 |
| extract | 30 | 30 | 50 | 50 | 30 | 30 | 1.004x | 0.824x | 24 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 12.282x | cmov, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | linux-selftests | sched_cls | 1.571x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | linux-selftests | sched_cls | 1.429x | extract |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | linux-selftests | sched_cls | 1.364x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1.333x | branch-flip |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 1.315x | wide, extract, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 1.286x | wide, endian |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 1.275x | cmov, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | linux-selftests | sched_cls | 1.268x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 1.267x | wide, endian, branch-flip |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | linux-selftests | sched_cls | 0.467x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 0.471x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 0.538x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 0.562x | extract |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0.571x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 0.582x | rotate, endian, branch-flip |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 0.583x | endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | linux-selftests | cgroup_skb | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 0.583x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | linux-selftests | sched_cls | 0.588x |  |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.109x | wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 1.052x | wide, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 1.046x | rotate, endian, branch-flip |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 1.036x | extract, endian |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.033x | wide, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 1.028x | wide, endian |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 1.028x | endian |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.026x | wide, rotate, extract, endian, branch-flip |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 1.022x | wide, endian, branch-flip |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 1.014x | wide, endian, branch-flip |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 13 | rotate, endian, branch-flip | 3260 | 3117 | 1.046x | 181 | 311 | 0.582x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 87 | wide, extract, endian, branch-flip | 46152 | 45931 | 1.005x | 332 | 356 | 0.933x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 | endian, branch-flip | 20957 | 20910 | 1.002x | 173 | 182 | 0.951x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 | endian, branch-flip | 2408 | 2408 | 1.000x | 172 | 190 | 0.905x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 | wide, endian, branch-flip | 18440 | 18367 | 1.004x | 172 | 274 | 0.628x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 896 | 896 | 1.000x | 176 | 261 | 0.674x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 44 | extract, endian, branch-flip | 23489 | 23458 | 1.001x | 170 | 239 | 0.711x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11888 | 11854 | 1.003x | 214 | 271 | 0.790x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 10978 | 10944 | 1.003x | 177 | 241 | 0.734x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 | wide, extract, endian, branch-flip | 33180 | 33030 | 1.005x | 324 | 351 | 0.923x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 30 | endian, branch-flip | 18932 | 18907 | 1.001x | 175 | 176 | 0.994x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 | endian, branch-flip | 2408 | 2408 | 1.000x | 178 | 179 | 0.994x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 33 | wide, endian, branch-flip | 16630 | 16572 | 1.003x | 185 | 175 | 1.057x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 896 | 896 | 1.000x | 194 | 190 | 1.021x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 | extract, endian, branch-flip | 21185 | 21171 | 1.001x | 176 | 224 | 0.786x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 12004 | 11970 | 1.003x | 179 | 175 | 1.023x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 11097 | 11063 | 1.003x | 175 | 192 | 0.911x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 | wide, endian, branch-flip | 36667 | 36519 | 1.004x | 177 | 213 | 0.831x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 34 | endian, branch-flip | 22172 | 22129 | 1.002x | 189 | 178 | 1.062x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 | endian, branch-flip | 1729 | 1729 | 1.000x | 175 | 177 | 0.989x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 | wide, endian, branch-flip | 18044 | 17967 | 1.004x | 188 | 210 | 0.895x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 900 | 900 | 1.000x | 177 | 191 | 0.927x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 23 | extract, endian, branch-flip | 18632 | 18614 | 1.001x | 173 | 178 | 0.972x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 15 | wide, endian, branch-flip | 11762 | 11728 | 1.003x | 223 | 176 | 1.267x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 10999 | 10965 | 1.003x | 196 | 244 | 0.803x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, extract, endian, branch-flip | 22218 | 22134 | 1.004x | 234 | 178 | 1.315x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 77 | wide, extract, endian, branch-flip | 42747 | 42550 | 1.005x | 184 | 217 | 0.848x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 37 | endian, branch-flip | 21862 | 21818 | 1.002x | 174 | 237 | 0.734x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 | endian, branch-flip | 2401 | 2401 | 1.000x | 173 | 234 | 0.739x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 41 | wide, endian, branch-flip | 18781 | 18704 | 1.004x | 171 | 194 | 0.881x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 902 | 902 | 1.000x | 176 | 202 | 0.871x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 | extract, endian, branch-flip | 22542 | 22525 | 1.001x | 189 | 283 | 0.668x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11454 | 11420 | 1.003x | 179 | 178 | 1.006x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 10479 | 10445 | 1.003x | 182 | 175 | 1.040x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, extract, endian, branch-flip | 22100 | 22016 | 1.004x | 171 | 186 | 0.919x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 76 | wide, extract, endian, branch-flip | 42660 | 42467 | 1.005x | 195 | 195 | 1.000x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 | endian, branch-flip | 21739 | 21695 | 1.002x | 192 | 183 | 1.049x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 | endian, branch-flip | 2401 | 2401 | 1.000x | 175 | 223 | 0.785x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 40 | wide, endian, branch-flip | 18648 | 18571 | 1.004x | 176 | 174 | 1.011x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 902 | 902 | 1.000x | 168 | 193 | 0.870x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 38 | extract, endian, branch-flip | 21882 | 21865 | 1.001x | 172 | 232 | 0.741x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11454 | 11420 | 1.003x | 183 | 223 | 0.821x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 10479 | 10445 | 1.003x | 169 | 208 | 0.812x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 65 | cmov, wide, endian, branch-flip | 30314 | 30194 | 1.004x | 178 | 181 | 0.983x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 22 | cmov, endian, branch-flip | 13936 | 13949 | 0.999x | 227 | 178 | 1.275x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 | endian, branch-flip | 1732 | 1732 | 1.000x | 174 | 178 | 0.978x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 26 | cmov, wide, endian, branch-flip | 12395 | 12363 | 1.003x | 171 | 183 | 0.934x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | cmov, branch-flip | 898 | 904 | 0.993x | 192 | 179 | 1.073x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 18 | cmov, extract, endian, branch-flip | 15641 | 15656 | 0.999x | 176 | 182 | 0.967x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 9 | cmov, wide, endian, branch-flip | 8023 | 8010 | 1.002x | 197 | 175 | 1.126x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 12 | cmov, wide, extract, endian, branch-flip | 7250 | 7233 | 1.002x | 195 | 281 | 0.694x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1 | branch-flip | 831 | 831 | 1.000x | 173 | 168 | 1.030x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | calico | xdp | 6 | endian, branch-flip | 1035 | 1035 | 1.000x | 354 | 334 | 1.060x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 12 | wide, endian, branch-flip | 4427 | 4365 | 1.014x | 170 | 217 | 0.783x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 125 | 125 | 1.000x | 178 | 177 | 1.006x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1 | branch-flip | 271 | 271 | 1.000x | 16 | 12 | 1.333x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | calico | xdp | 2 | branch-flip | 274 | 274 | 1.000x | 15 | 16 | 0.938x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 8 | wide, endian, branch-flip | 1816 | 1777 | 1.022x | 16 | 16 | 1.000x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 31 | 31 | 1.000x | 9 | 8 | 1.125x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 94 | wide, rotate, extract, endian, branch-flip | 13412 | 13073 | 1.026x | 12 | 17 | 0.706x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 9 | endian, branch-flip | 1615 | 1608 | 1.004x | 9 | 9 | 1.000x |  |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | katran | sched_cls | 3 | branch-flip | 544 | 544 | 1.000x | 9 | 15 | 0.600x |  |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | katran | xdp | 2 | branch-flip | 174 | 174 | 1.000x | 9 | 9 | 1.000x |  |
| corpus/build/katran/xdp_root.bpf.o:xdp_root | katran | xdp | 0 |  | 188 | 188 | 1.000x | 10 | 15 | 0.667x |  |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 1 | endian | 111 | 108 | 1.028x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | 15 | 11 | 1.364x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 |  | 53 | 53 | 1.000x | 7 | 11 | 0.636x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id | linux-selftests | sched_cls | 0 |  | 253 | 253 | 1.000x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access | linux-selftests | cgroup_skb | 0 |  | 47 | 47 | 1.000x | 9 | 13 | 0.692x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | sched_cls | 818 |  | 50198 | 50198 | 1.000x | 579 | 502 | 1.153x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 |  | 403 | 403 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1 | cmov | 254 | 260 | 0.977x | 17 | 26 | 0.654x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 426 | 426 | 1.000x | 23 | 22 | 1.045x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 122 | 122 | 1.000x | 252 | 357 | 0.706x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 151 | 151 | 1.000x | 35 | 37 | 0.946x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | linux-selftests | cgroup_skb | 0 |  | 75 | 75 | 1.000x | 10 | 9 | 1.111x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx | linux-selftests | sched_cls | 0 |  | 72 | 72 | 1.000x | 11 | 14 | 0.786x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | linux-selftests | cgroup_skb | 0 |  | 42 | 42 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | linux-selftests | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 3 | cmov, branch-flip | 266 | 272 | 0.978x | 4483 | 365 | 12.282x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | linux-selftests | sched_cls | 0 |  | 114 | 114 | 1.000x | 17 | 18 | 0.944x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0 |  | 148 | 148 | 1.000x | 17 | 27 | 0.630x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 17 | cmov, branch-flip | 1676 | 1678 | 0.999x | 1000945852 | 1000828829 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog | linux-selftests | sched_cls | 0 |  | 129 | 129 | 1.000x | 9 | 12 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | 10 | 17 | 0.588x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs | linux-selftests | sched_cls | 0 |  | 107 | 107 | 1.000x | 11 | 11 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | 11 | 7 | 1.571x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple | linux-selftests | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple | linux-selftests | xdp | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress | linux-selftests | sched_cls | 1 |  | 1244 | n/a | n/a | 8 | n/a | n/a | recompile-branch-flip: no branch_flip sites found in xlated program (234 insns) (exit=-9) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc | linux-selftests | sched_cls | 0 |  | 86 | 86 | 1.000x | 7 | 8 | 0.875x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers | linux-selftests | sched_cls | 0 |  | 115 | 115 | 1.000x | 21 | 32 | 0.656x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 |  | 171 | 171 | 1.000x | 9 | 14 | 0.643x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 |  | 392 | 392 | 1.000x | 12 | 11 | 1.091x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 |  | 557 | 557 | 1.000x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 |  | 526 | 526 | 1.000x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 |  | 513 | 513 | 1.000x | 9 | 13 | 0.692x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 1 | extract | 479 | 479 | 1.000x | 9 | 16 | 0.562x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | linux-selftests | sched_cls | 1 | extract | 448 | 448 | 1.000x | 10 | 7 | 1.429x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 1 | extract | 435 | 435 | 1.000x | 8 | 17 | 0.471x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 1 | extract | 407 | 407 | 1.000x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth | linux-selftests | sched_cls | 1 | extract | 589 | 589 | 1.000x | 7 | 8 | 0.875x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | linux-selftests | sched_cls | 1 | extract | 558 | 558 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 1 | extract | 545 | 545 | 1.000x | 7 | 13 | 0.538x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 1 | extract | 605 | 605 | 1.000x | 7 | 8 | 0.875x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | linux-selftests | sched_cls | 1 | extract | 491 | 491 | 1.000x | 7 | 15 | 0.467x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 1 |  | 505 | 505 | 1.000x | 11 | 11 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 4 | extract, endian | 697 | 689 | 1.012x | 9 | 10 | 0.900x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 2 | endian | 689 | 686 | 1.004x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | sched_cls | 2 | endian | 656 | 653 | 1.005x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 2 | endian | 643 | 640 | 1.005x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 2 | endian | 705 | 702 | 1.004x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 3 | wide, endian | 696 | 677 | 1.028x | 9 | 7 | 1.286x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | sched_cls | 992 |  | 48574 | 48574 | 1.000x | 512 | 503 | 1.018x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | linux-selftests | sched_cls | 0 |  | 152 | 152 | 1.000x | 9 | 12 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | linux-selftests | xdp | 0 |  | 107 | 107 | 1.000x | 9 | 9 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect | linux-selftests | xdp | 0 |  | 251 | 251 | 1.000x | 11 | 9 | 1.222x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | 11 | 10 | 1.100x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | 9 | 9 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | 26 | 27 | 0.963x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | 52 | 41 | 1.268x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | 12 | 14 | 0.857x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6 | linux-selftests | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper | linux-selftests | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu | linux-selftests | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect | linux-selftests | xdp | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 5 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 5 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 5 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 5 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o:socket_handler | real_world_code_size | socket_filter | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | real_world_code_size | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 110 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 110 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | exec failed: [Errno 13] Permission denied: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 3 | cmov, endian | 694 | 694 | 1.000x | 10 | 10 | 1.000x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 | cmov | 78 | 84 | 0.929x | 18 | 16 | 1.125x |  |
| corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | xdp-tools | xdp | 0 |  | 91 | 91 | 1.000x | 11 | 11 | 1.000x |  |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp-tutorial | xdp | 2 | branch-flip | 215 | 215 | 1.000x | 11 | 10 | 1.100x |  |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 13 | 0.615x |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 8 | 1.000x |  |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp-tutorial | xdp | 1 | branch-flip | 108 | 108 | 1.000x | 13 | 15 | 0.867x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | xdp-tutorial | xdp | 1 | branch-flip | 145 | 145 | 1.000x | 10 | 10 | 1.000x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 1 | branch-flip | 146 | 146 | 1.000x | 10 | 17 | 0.588x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 1 | branch-flip | 146 | 146 | 1.000x | 10 | 9 | 1.111x |  |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 6 | extract, endian | 549 | 530 | 1.036x | 8 | 8 | 1.000x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 2 | branch-flip | 511 | 511 | 1.000x | 10 | 15 | 0.667x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 9 | 8 | 1.125x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 | wide | 122 | 110 | 1.109x | 9 | 8 | 1.125x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 3 | branch-flip | 526 | 526 | 1.000x | 10 | 11 | 0.909x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 14 | 0.571x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 4 | wide, branch-flip | 244 | 232 | 1.052x | 10 | 11 | 0.909x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 4 | wide, branch-flip | 378 | 366 | 1.033x | 16 | 23 | 0.696x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp-tutorial | xdp | 1 | branch-flip | 471 | 471 | 1.000x | 10 | 10 | 1.000x |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 28 | 28 | 1.000x | 9 | 8 | 1.125x |  |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 231 | 231 | 1.000x | 211 | 210 | 1.005x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 |  | 170 | 170 | 1.000x | 187 | 190 | 0.984x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| exec failed: [Errno 2] No such file or directory: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' | 28 |
| io-mode packet requires an XDP or skb packet context (exit=1) | 12 |
| bpf_object__load failed: Permission denied (exit=1) | 4 |
| exec failed: [Errno 13] Permission denied: '/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec' | 2 |
| recompile-branch-flip: no branch_flip sites found in xlated program (234 insns) (exit=-9) | 1 |

## Recompile Failures

| Reason | Count |
| --- | --- |
| BPF_PROG_JIT_RECOMPILE failed: Argument list too long (errno=7) | 4 |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- `--use-policy` prefers a matching per-program file under `corpus/policies/`, then falls back to object-level legacy policy files, and finally falls back to the legacy auto-scan `--recompile-v5 --recompile-all` path.
- `--skip-families` filters families out of the auto-generated v5 policy; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
