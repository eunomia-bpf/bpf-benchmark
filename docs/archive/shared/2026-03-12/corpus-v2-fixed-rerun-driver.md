# Corpus Batch Recompile Results

- Generated: 2026-03-12T21:25:12.901626+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 166
- Compile pairs: 163
- Measured pairs: 156
- Recompile applied programs: 91
- Code-size ratio geomean (baseline/v5): 1.004x
- Exec-time ratio geomean (baseline/v5): 0.875x
- Total sites: 3870
- CMOV sites: 446
- WIDE sites: 342
- ROTATE sites: 1840
- LEA sites: 0
- EXTRACT sites: 86
- ZERO-EXT sites: 0
- ENDIAN sites: 874
- BRANCH-FLIP sites: 282
- Kernel build: ok (0.00s)
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 71 | 69 | 63 | 20 | 35 | 13 | 1810 | 0 | 42 | 0 | 48 | 61 | 1.000x | 0.859x | 41 |
| calico | 59 | 59 | 59 | 54 | 361 | 108 | 10 | 0 | 37 | 0 | 805 | 118 | 1.003x | 0.862x | 44 |
| xdp-tutorial | 20 | 20 | 20 | 6 | 10 | 3 | 0 | 0 | 1 | 0 | 5 | 11 | 1.011x | 1.012x | 8 |
| katran | 5 | 5 | 5 | 2 | 9 | 4 | 20 | 0 | 2 | 0 | 5 | 68 | 1.006x | 0.803x | 3 |
| xdp-tools | 4 | 4 | 4 | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 4 | 0 | 0.982x | 1.045x | 1 |
| real_world_code_size | 2 | 2 | 1 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | 1.021x | 0.583x | 1 |
| suricata | 2 | 1 | 1 | 1 | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 6 | 0.996x | 1.000x | 0 |
| tracee | 2 | 2 | 2 | 2 | 26 | 214 | 0 | 0 | 2 | 0 | 4 | 18 | 1.091x | 0.615x | 2 |
| libbpf-bootstrap | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1.028x | 0.727x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 2 | 1840 | 30 | 4 | 4 | 1.018x | 0.971x | 2 |
| endian | 69 | 67 | 874 | 872 | 69 | 68 | 1.008x | 0.828x | 47 |
| cmov | 80 | 13 | 446 | 50 | 79 | 79 | 1.006x | 0.880x | 51 |
| wide | 39 | 38 | 342 | 341 | 39 | 39 | 1.014x | 0.850x | 24 |
| branch-flip | 80 | 69 | 282 | 266 | 80 | 80 | 1.006x | 0.913x | 53 |
| extract | 37 | 37 | 86 | 86 | 37 | 37 | 1.009x | 0.812x | 23 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 24.377x | cmov, branch-flip |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 4.300x | branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | linux-selftests | xdp | 2.000x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 1.583x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1.565x | cmov |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp-tutorial | xdp | 1.562x | branch-flip |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 1.500x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 1.429x |  |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | katran | xdp | 1.417x | branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | linux-selftests | xdp | 1.385x |  |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0.267x | branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 0.303x | wide, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | linux-selftests | sched_cls | 0.321x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 0.438x | extract |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 0.438x | endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 0.500x | endian |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 0.501x | wide, endian, branch-flip |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 0.531x | wide, extract, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 0.533x | cmov |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 0.533x | extract, endian |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.109x | wide |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 1.091x | wide, extract, endian, branch-flip |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 1.091x | wide, extract, endian, branch-flip |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 1.052x | wide, branch-flip |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 1.046x | rotate, endian, branch-flip |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 1.036x | extract, endian |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.033x | wide, branch-flip |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 1.028x | endian |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | real_world_code_size | sched_cls | 1.028x | endian |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 1.026x | wide, rotate, extract, endian, branch-flip |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 13 | rotate, endian, branch-flip | 3260 | 3117 | 1.046x | 192 | 184 | 1.043x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 87 | wide, extract, endian, branch-flip | 46152 | 45931 | 1.005x | 342 | 330 | 1.036x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 | endian, branch-flip | 20957 | 20910 | 1.002x | 174 | 178 | 0.978x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 | endian, branch-flip | 2408 | 2408 | 1.000x | 176 | 210 | 0.838x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 | wide, endian, branch-flip | 18440 | 18367 | 1.004x | 189 | 623 | 0.303x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 896 | 896 | 1.000x | 174 | 249 | 0.699x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 44 | extract, endian, branch-flip | 23489 | 23458 | 1.001x | 185 | 315 | 0.587x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11888 | 11854 | 1.003x | 194 | 257 | 0.755x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 10978 | 10944 | 1.003x | 196 | 183 | 1.071x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 | wide, extract, endian, branch-flip | 33180 | 33030 | 1.005x | 340 | 328 | 1.037x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 30 | endian, branch-flip | 18932 | 18907 | 1.001x | 179 | 185 | 0.968x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 | endian, branch-flip | 2408 | 2408 | 1.000x | 192 | 236 | 0.814x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 33 | wide, endian, branch-flip | 16630 | 16572 | 1.003x | 174 | 181 | 0.961x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 896 | 896 | 1.000x | 178 | 178 | 1.000x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 | extract, endian, branch-flip | 21185 | 21171 | 1.001x | 278 | 328 | 0.848x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 12004 | 11970 | 1.003x | 177 | 179 | 0.989x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 11097 | 11063 | 1.003x | 196 | 175 | 1.120x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 | wide, endian, branch-flip | 36667 | 36519 | 1.004x | 175 | 314 | 0.557x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 34 | endian, branch-flip | 22172 | 22129 | 1.002x | 196 | 209 | 0.938x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 | endian, branch-flip | 1729 | 1729 | 1.000x | 193 | 230 | 0.839x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 | wide, endian, branch-flip | 18044 | 17967 | 1.004x | 173 | 176 | 0.983x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 900 | 900 | 1.000x | 177 | 199 | 0.889x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 23 | extract, endian, branch-flip | 18632 | 18614 | 1.001x | 173 | 250 | 0.692x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 15 | wide, endian, branch-flip | 11762 | 11728 | 1.003x | 190 | 212 | 0.896x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 10999 | 10965 | 1.003x | 175 | 174 | 1.006x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, extract, endian, branch-flip | 22218 | 22134 | 1.004x | 231 | 212 | 1.090x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 77 | wide, extract, endian, branch-flip | 42747 | 42550 | 1.005x | 180 | 339 | 0.531x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 37 | endian, branch-flip | 21862 | 21818 | 1.002x | 170 | 271 | 0.627x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 | endian, branch-flip | 2401 | 2401 | 1.000x | 172 | 177 | 0.972x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 41 | wide, endian, branch-flip | 18781 | 18704 | 1.004x | 202 | 181 | 1.116x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 902 | 902 | 1.000x | 217 | 240 | 0.904x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 | extract, endian, branch-flip | 22542 | 22525 | 1.001x | 186 | 198 | 0.939x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11454 | 11420 | 1.003x | 173 | 181 | 0.956x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 10479 | 10445 | 1.003x | 172 | 278 | 0.619x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, extract, endian, branch-flip | 22100 | 22016 | 1.004x | 181 | 187 | 0.968x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 76 | wide, extract, endian, branch-flip | 42660 | 42467 | 1.005x | 205 | 285 | 0.719x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 | endian, branch-flip | 21739 | 21695 | 1.002x | 198 | 189 | 1.048x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 | endian, branch-flip | 2401 | 2401 | 1.000x | 177 | 184 | 0.962x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 40 | wide, endian, branch-flip | 18648 | 18571 | 1.004x | 192 | 201 | 0.955x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | branch-flip | 902 | 902 | 1.000x | 189 | 238 | 0.794x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 38 | extract, endian, branch-flip | 21882 | 21865 | 1.001x | 188 | 186 | 1.011x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian, branch-flip | 11454 | 11420 | 1.003x | 224 | 179 | 1.251x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 | wide, extract, endian, branch-flip | 10479 | 10445 | 1.003x | 171 | 215 | 0.795x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 65 | cmov, wide, endian, branch-flip | 30314 | 30194 | 1.004x | 178 | 280 | 0.636x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 22 | cmov, endian, branch-flip | 13936 | 13949 | 0.999x | 177 | 186 | 0.952x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 | endian, branch-flip | 1732 | 1732 | 1.000x | 173 | 191 | 0.906x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 26 | cmov, wide, endian, branch-flip | 12395 | 12363 | 1.003x | 168 | 220 | 0.764x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 | cmov, branch-flip | 898 | 904 | 0.993x | 169 | 193 | 0.876x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 18 | cmov, extract, endian, branch-flip | 15641 | 15656 | 0.999x | 193 | 178 | 1.084x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 9 | cmov, wide, endian, branch-flip | 8023 | 8010 | 1.002x | 175 | 174 | 1.006x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 12 | cmov, wide, extract, endian, branch-flip | 7250 | 7233 | 1.002x | 173 | 182 | 0.951x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1 |  | 831 | 831 | 1.000x | 312 | 316 | 0.987x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | calico | xdp | 6 | endian, branch-flip | 1035 | 1035 | 1.000x | 340 | 407 | 0.835x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 12 | wide, endian, branch-flip | 4427 | 4365 | 1.014x | 168 | 335 | 0.501x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 125 | 125 | 1.000x | 189 | 309 | 0.612x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1 |  | 271 | 271 | 1.000x | 23 | 24 | 0.958x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | calico | xdp | 2 |  | 274 | 274 | 1.000x | 23 | 24 | 0.958x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 8 | wide, endian, branch-flip | 1816 | 1777 | 1.022x | 19 | 26 | 0.731x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 31 | 31 | 1.000x | 10 | 7 | 1.429x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 94 | wide, rotate, extract, endian, branch-flip | 13412 | 13073 | 1.026x | 19 | 17 | 1.118x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 9 | endian, branch-flip | 1615 | 1608 | 1.004x | 9 | 16 | 0.562x |  |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | katran | sched_cls | 3 |  | 544 | 544 | 1.000x | 9 | 15 | 0.600x |  |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | katran | xdp | 2 |  | 174 | 174 | 1.000x | 17 | 12 | 1.417x |  |
| corpus/build/katran/xdp_root.bpf.o:xdp_root | katran | xdp | 0 |  | 188 | 188 | 1.000x | 10 | 16 | 0.625x |  |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 1 | endian | 111 | 108 | 1.028x | 8 | 11 | 0.727x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | 9 | 7 | 1.286x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 |  | 53 | 53 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id | linux-selftests | sched_cls | 0 |  | 253 | 253 | 1.000x | 9 | 9 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access | linux-selftests | cgroup_skb | 0 |  | 47 | 47 | 1.000x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | sched_cls | 818 |  | 50198 | 50198 | 1.000x | 491 | 583 | 0.842x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 |  | 403 | 403 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1 |  | 254 | 254 | 1.000x | 16 | 27 | 0.593x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 426 | 426 | 1.000x | 25 | 36 | 0.694x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 122 | 122 | 1.000x | 233 | 218 | 1.069x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 151 | 151 | 1.000x | 41 | 39 | 1.051x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | linux-selftests | cgroup_skb | 0 |  | 75 | 75 | 1.000x | 9 | 15 | 0.600x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx | linux-selftests | sched_cls | 0 |  | 72 | 72 | 1.000x | 9 | 10 | 0.900x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | linux-selftests | cgroup_skb | 0 |  | 42 | 42 | 1.000x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | linux-selftests | xdp | 0 |  | 31 | 31 | 1.000x | 18 | 13 | 1.385x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 3 | cmov, branch-flip | 266 | 272 | 0.978x | 4656 | 191 | 24.377x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | linux-selftests | sched_cls | 0 |  | 114 | 114 | 1.000x | 22 | 24 | 0.917x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0 |  | 148 | 148 | 1.000x | 27 | 39 | 0.692x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 17 | cmov, branch-flip | 1676 | 1678 | 0.999x | 1000547248 | 1000649370 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog | linux-selftests | sched_cls | 0 |  | 129 | 129 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | 10 | 8 | 1.250x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs | linux-selftests | sched_cls | 0 |  | 107 | 107 | 1.000x | 14 | 17 | 0.824x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple | linux-selftests | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple | linux-selftests | xdp | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress | linux-selftests | sched_cls | 1 |  | 1244 | 1244 | 1.000x | 9 | 12 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc | linux-selftests | sched_cls | 0 |  | 86 | 86 | 1.000x | 7 | 9 | 0.778x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers | linux-selftests | sched_cls | 0 |  | 115 | 115 | 1.000x | 18 | 19 | 0.947x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 |  | 171 | 171 | 1.000x | 8 | 15 | 0.533x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 |  | 392 | 392 | 1.000x | 12 | 17 | 0.706x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 |  | 557 | 557 | 1.000x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 |  | 526 | 526 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 |  | 513 | 513 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 1 | extract | 479 | 479 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | linux-selftests | sched_cls | 1 | extract | 448 | 448 | 1.000x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 1 | extract | 435 | 435 | 1.000x | 8 | 9 | 0.889x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 1 | extract | 407 | 407 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth | linux-selftests | sched_cls | 1 | extract | 589 | 589 | 1.000x | 9 | 12 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | linux-selftests | sched_cls | 1 | extract | 558 | 558 | 1.000x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 1 | extract | 545 | 545 | 1.000x | 8 | 10 | 0.800x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 1 | extract | 605 | 605 | 1.000x | 7 | 16 | 0.438x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | linux-selftests | sched_cls | 1 | extract | 491 | 491 | 1.000x | 8 | 12 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 1 |  | 505 | 505 | 1.000x | 7 | 8 | 0.875x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 4 | extract, endian | 697 | 689 | 1.012x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 2 | endian | 689 | 686 | 1.004x | 7 | 16 | 0.438x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | sched_cls | 2 | endian | 656 | 653 | 1.005x | 7 | 12 | 0.583x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 2 | endian | 643 | 640 | 1.005x | 8 | 16 | 0.500x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 2 | endian | 705 | 702 | 1.004x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 3 |  | 696 | 696 | 1.000x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | sched_cls | 992 |  | 48574 | 48574 | 1.000x | 544 | 602 | 0.904x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | linux-selftests | sched_cls | 0 |  | 152 | 152 | 1.000x | 9 | 13 | 0.692x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | linux-selftests | xdp | 0 |  | 107 | 107 | 1.000x | 14 | 12 | 1.167x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect | linux-selftests | xdp | 0 |  | 251 | 251 | 1.000x | 14 | 13 | 1.077x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | 18 | 9 | 2.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | 16 | 14 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | 25 | 78 | 0.321x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | 32 | 41 | 0.780x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | 11 | 18 | 0.611x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | 12 | 18 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | 8 | 13 | 0.615x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu | linux-selftests | sched_cls | 0 |  | 54 | 54 | 1.000x | 9 | 9 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect | linux-selftests | xdp | 0 |  | 53 | 53 | 1.000x | 15 | 15 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 | wide, extract, endian, branch-flip | 5424 | 5389 | 1.006x | 9 | 15 | 0.600x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 36 | wide, extract, endian, branch-flip | 5454 | 5419 | 1.006x | 17 | 13 | 1.308x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 | wide, extract, endian, branch-flip | 5424 | 5389 | 1.006x | 9 | 8 | 1.125x |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 36 | wide, extract, endian, branch-flip | 5454 | 5419 | 1.006x | 13 | 13 | 1.000x |  |
| corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o:socket_handler | real_world_code_size | socket_filter | 1 | endian | 374 | 369 | 1.014x | n/a | n/a | n/a |  |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | real_world_code_size | sched_cls | 1 | endian | 111 | 108 | 1.028x | 7 | 12 | 0.583x |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 9 | cmov, extract, branch-flip | 1628 | 1634 | 0.996x | 14 | 14 | 1.000x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 132 | wide, extract, endian, branch-flip | 19383 | 17768 | 1.091x | 8 | 13 | 0.615x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 132 | wide, extract, endian, branch-flip | 19383 | 17768 | 1.091x | 8 | 13 | 0.615x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 3 | cmov, endian | 697 | 697 | 1.000x | 16 | 14 | 1.143x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 3 | cmov, endian | 694 | 694 | 1.000x | 35 | 28 | 1.250x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 | cmov | 78 | 84 | 0.929x | 24 | 24 | 1.000x |  |
| corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | xdp-tools | xdp | 0 |  | 91 | 91 | 1.000x | 35 | 42 | 0.833x |  |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp-tutorial | xdp | 2 |  | 215 | 215 | 1.000x | 25 | 16 | 1.562x |  |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 18 | 12 | 1.500x |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 15 | 12 | 1.250x |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 13 | 12 | 1.083x |  |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp-tutorial | xdp | 1 |  | 108 | 108 | 1.000x | 18 | 17 | 1.059x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | xdp-tutorial | xdp | 1 |  | 145 | 145 | 1.000x | 14 | 14 | 1.000x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 1 |  | 146 | 146 | 1.000x | 8 | 30 | 0.267x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 1 |  | 146 | 146 | 1.000x | 43 | 10 | 4.300x |  |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 6 | extract, endian | 549 | 530 | 1.036x | 8 | 15 | 0.533x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 2 | branch-flip | 511 | 511 | 1.000x | 10 | 15 | 0.667x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 7 | 11 | 0.636x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 | wide | 122 | 110 | 1.109x | 14 | 12 | 1.167x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 3 | branch-flip | 526 | 526 | 1.000x | 17 | 16 | 1.062x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 19 | 12 | 1.583x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 4 | wide, branch-flip | 244 | 232 | 1.052x | 14 | 15 | 0.933x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 4 | wide, branch-flip | 378 | 366 | 1.033x | 15 | 24 | 0.625x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp-tutorial | xdp | 1 |  | 471 | 471 | 1.000x | 19 | 16 | 1.188x |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 28 | 28 | 1.000x | 15 | 16 | 0.938x |  |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 231 | 231 | 1.000x | 268 | 368 | 0.728x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 |  | 170 | 170 | 1.000x | 313 | 200 | 1.565x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| io-mode packet requires an XDP or skb packet context (exit=1) | 14 |
| bpf_object__load failed: Permission denied (exit=1) | 4 |
| bpf_object__load failed: Argument list too long (exit=1) | 2 |

## Recompile Failures

| Reason | Count |
| --- | --- |
| BPF_PROG_JIT_RECOMPILE failed: Argument list too long (errno=7) | 4 |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 2 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
