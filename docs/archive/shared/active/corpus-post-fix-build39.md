# Corpus Batch Recompile Results

- Generated: 2026-03-13T22:07:01.040174+00:00
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Repeat: 200
- Skip families: `none`
- Target programs: 166
- Compile pairs: 163
- Measured pairs: 152
- Recompile applied programs: 39
- Code-size ratio geomean (baseline/v5): 1.002x
- Exec-time ratio geomean (baseline/v5): 1.046x
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
- Guest kernel: `7.0.0-rc2-gac593b2c1c6f`

## By Project

| Project | Programs | Compile Pairs | Measured Pairs | Applied | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 71 | 69 | 59 | 16 | 35 | 13 | 1810 | 0 | 42 | 0 | 48 | 61 | 1.000x | 1.005x | 19 |
| calico | 59 | 59 | 59 | 13 | 361 | 108 | 10 | 0 | 37 | 0 | 805 | 118 | 1.000x | 1.097x | 17 |
| xdp-tutorial | 20 | 20 | 20 | 3 | 10 | 3 | 0 | 0 | 1 | 0 | 5 | 11 | 1.009x | 1.091x | 5 |
| katran | 5 | 5 | 5 | 0 | 9 | 4 | 20 | 0 | 2 | 0 | 5 | 68 | 1.000x | 0.872x | 3 |
| xdp-tools | 4 | 4 | 4 | 2 | 3 | 0 | 0 | 0 | 0 | 0 | 4 | 0 | 1.004x | 1.062x | 2 |
| real_world_code_size | 2 | 2 | 1 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 | 1.021x | 1.059x | 0 |
| suricata | 2 | 1 | 1 | 0 | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 6 | 1.000x | 0.857x | 1 |
| tracee | 2 | 2 | 2 | 2 | 26 | 214 | 0 | 0 | 2 | 0 | 4 | 18 | 1.003x | 0.990x | 1 |
| libbpf-bootstrap | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1.028x | 0.944x | 1 |

## By Family

| Family | Programs | Applied | Sites | Applied Sites | Compile Pairs | Measured Pairs | Code Ratio | Exec Ratio | Regressions |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| rotate | 4 | 0 | 1840 | 0 | 4 | 4 | 1.000x | 0.935x | 1 |
| endian | 69 | 27 | 874 | 366 | 69 | 64 | 1.002x | 1.066x | 20 |
| cmov | 80 | 0 | 446 | 0 | 79 | 75 | 1.003x | 1.058x | 24 |
| wide | 39 | 18 | 342 | 267 | 39 | 35 | 1.005x | 1.095x | 11 |
| branch-flip | 80 | 0 | 282 | 0 | 80 | 76 | 1.001x | 1.085x | 24 |
| extract | 37 | 18 | 86 | 32 | 37 | 33 | 1.001x | 0.979x | 17 |
| lea | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |
| zero-ext | 0 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 |

## Top Speedups

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp-tutorial | xdp | 4.000x | branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | linux-selftests | cgroup_skb | 2.714x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 2.099x | cmov, wide, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | linux-selftests | sched_cls | 2.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | linux-selftests | xdp | 1.714x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 1.686x | endian, branch-flip |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | calico | xdp | 1.600x | branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 1.600x | cmov |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1.583x | cmov |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 1.571x |  |

## Regressions

| Program | Project | Type | Exec Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 0.312x | cmov |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | linux-selftests | xdp | 0.455x |  |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp-tutorial | xdp | 0.538x | branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0.558x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 0.567x | cmov, wide, rotate, extract, endian, branch-flip |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0.645x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | linux-selftests | xdp | 0.667x |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0.692x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 0.696x | cmov, branch-flip |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 0.714x | branch-flip |

## Largest Code Shrinks

| Program | Project | Type | Code Ratio | Families |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 1.109x | wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 1.052x | wide |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 1.033x | wide |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 1.028x | endian |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | real_world_code_size | sched_cls | 1.028x | endian |
| corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o:socket_handler | real_world_code_size | socket_filter | 1.014x | endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 1.012x | extract, endian |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 1.009x | endian |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 1.009x | endian |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 1.005x | endian |

## Per-Program Results

| Program | Project | Type | Sites | Applied Families | Baseline JIT | v5 JIT | Code Ratio | Baseline ns | v5 ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | sched_cls | 13 |  | 3260 | 3260 | 1.000x | 170 | 150 | 1.133x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 87 | wide, extract, endian | 46152 | 46152 | 1.000x | 291 | 276 | 1.054x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 |  | 20957 | 20957 | 1.000x | 205 | 170 | 1.206x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2408 | 2408 | 1.000x | 165 | 158 | 1.044x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 |  | 18440 | 18440 | 1.000x | 150 | 189 | 0.794x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 896 | 896 | 1.000x | 175 | 171 | 1.023x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 44 |  | 23489 | 23489 | 1.000x | 165 | 150 | 1.100x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 |  | 11888 | 11888 | 1.000x | 203 | 147 | 1.381x |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 10978 | 10978 | 1.000x | 187 | 162 | 1.154x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 63 |  | 33180 | 33180 | 1.000x | 355 | 280 | 1.268x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 30 |  | 18932 | 18932 | 1.000x | 186 | 192 | 0.969x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2408 | 2408 | 1.000x | 188 | 165 | 1.139x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 33 | wide, endian | 16630 | 16626 | 1.000x | 156 | 145 | 1.076x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 896 | 896 | 1.000x | 161 | 154 | 1.045x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 21185 | 21185 | 1.000x | 155 | 164 | 0.945x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 |  | 12004 | 12004 | 1.000x | 167 | 152 | 1.099x |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 11097 | 11097 | 1.000x | 192 | 149 | 1.289x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 72 |  | 36667 | 36667 | 1.000x | 319 | 152 | 2.099x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 34 |  | 22172 | 22172 | 1.000x | 195 | 152 | 1.283x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 |  | 1729 | 1729 | 1.000x | 263 | 156 | 1.686x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 38 | wide, endian | 18044 | 18042 | 1.000x | 196 | 145 | 1.352x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 900 | 900 | 1.000x | 151 | 147 | 1.027x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 23 |  | 18632 | 18632 | 1.000x | 170 | 189 | 0.899x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 15 |  | 11762 | 11762 | 1.000x | 181 | 150 | 1.207x |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 10999 | 10999 | 1.000x | 173 | 186 | 0.930x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, extract, endian | 22218 | 22184 | 1.002x | 166 | 168 | 0.988x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | sched_cls | 77 |  | 42747 | 42747 | 1.000x | 163 | 172 | 0.948x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 37 | endian | 21862 | 21860 | 1.000x | 167 | 144 | 1.160x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2401 | 2401 | 1.000x | 154 | 152 | 1.013x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 41 | wide, endian | 18781 | 18777 | 1.000x | 198 | 146 | 1.356x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 902 | 902 | 1.000x | 171 | 153 | 1.118x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 40 |  | 22542 | 22542 | 1.000x | 212 | 148 | 1.432x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian | 11454 | 11454 | 1.000x | 156 | 168 | 0.929x |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 10479 | 10479 | 1.000x | 185 | 178 | 1.039x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | sched_cls | 47 | wide, extract, endian | 22100 | 22066 | 1.002x | 189 | 144 | 1.312x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | sched_cls | 76 | wide, extract, endian | 42660 | 42648 | 1.000x | 244 | 224 | 1.089x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 36 | endian | 21739 | 21737 | 1.000x | 168 | 156 | 1.077x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 7 |  | 2401 | 2401 | 1.000x | 156 | 150 | 1.040x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 40 | wide, endian | 18648 | 18644 | 1.000x | 189 | 234 | 0.808x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 902 | 902 | 1.000x | 176 | 188 | 0.936x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 38 |  | 21882 | 21882 | 1.000x | 185 | 153 | 1.209x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 16 | wide, endian | 11454 | 11454 | 1.000x | 202 | 144 | 1.403x |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 18 |  | 10479 | 10479 | 1.000x | 164 | 166 | 0.988x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | sched_cls | 65 |  | 30314 | 30314 | 1.000x | 215 | 161 | 1.335x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | sched_cls | 22 |  | 13936 | 13936 | 1.000x | 197 | 150 | 1.313x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | calico | sched_cls | 6 |  | 1732 | 1732 | 1.000x | 149 | 145 | 1.028x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | sched_cls | 26 | wide, endian | 12395 | 12391 | 1.000x | 152 | 165 | 0.921x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | sched_cls | 3 |  | 898 | 898 | 1.000x | 197 | 158 | 1.247x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | 18 |  | 15641 | 15641 | 1.000x | 157 | 192 | 0.818x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | sched_cls | 9 |  | 8023 | 8023 | 1.000x | 160 | 146 | 1.096x |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | sched_cls | 12 |  | 7250 | 7250 | 1.000x | 186 | 214 | 0.869x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1 |  | 831 | 831 | 1.000x | 213 | 239 | 0.891x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | calico | xdp | 6 |  | 1035 | 1035 | 1.000x | 448 | 414 | 1.082x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | xdp | 12 |  | 4427 | 4427 | 1.000x | 202 | 171 | 1.181x |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 125 | 125 | 1.000x | 193 | 171 | 1.129x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | calico | xdp | 1 |  | 271 | 271 | 1.000x | 10 | 14 | 0.714x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | calico | xdp | 2 |  | 274 | 274 | 1.000x | 16 | 10 | 1.600x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | xdp | 8 |  | 1816 | 1816 | 1.000x | 15 | 15 | 1.000x |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | calico | xdp | 0 |  | 31 | 31 | 1.000x | 6 | 8 | 0.750x |  |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | xdp | 94 |  | 13412 | 13412 | 1.000x | 34 | 60 | 0.567x |  |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | sched_cls | 9 |  | 1615 | 1615 | 1.000x | 8 | 6 | 1.333x |  |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | katran | sched_cls | 3 |  | 544 | 544 | 1.000x | 7 | 7 | 1.000x |  |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | katran | xdp | 2 |  | 174 | 174 | 1.000x | 6 | 7 | 0.857x |  |
| corpus/build/katran/xdp_root.bpf.o:xdp_root | katran | xdp | 0 |  | 188 | 188 | 1.000x | 7 | 9 | 0.778x |  |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | libbpf-bootstrap | sched_cls | 1 | endian | 111 | 108 | 1.028x | 218 | 231 | 0.944x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:cls | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | 6 | 5 | 1.200x |  |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | sched_cls | 1 |  | 53 | 53 | 1.000x | 5 | 16 | 0.312x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id | linux-selftests | sched_cls | 0 |  | 253 | 253 | 1.000x | 7 | 6 | 1.167x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access | linux-selftests | cgroup_skb | 0 |  | 47 | 47 | 1.000x | 7 | 6 | 1.167x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | sched_cls | 818 |  | 50198 | 50198 | 1.000x | 558 | 477 | 1.170x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | sched_cls | 2 |  | 403 | 403 | 1.000x | 8 | 5 | 1.600x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 1 |  | 254 | 254 | 1.000x | 13 | 13 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 426 | 426 | 1.000x | 21 | 22 | 0.955x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 122 | 122 | 1.000x | 226 | 405 | 0.558x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access | linux-selftests | sched_cls | 0 |  | 151 | 151 | 1.000x | 32 | 29 | 1.103x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | linux-selftests | cgroup_skb | 0 |  | 75 | 75 | 1.000x | 19 | 7 | 2.714x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx | linux-selftests | sched_cls | 0 |  | 72 | 72 | 1.000x | 9 | 11 | 0.818x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | linux-selftests | cgroup_skb | 0 |  | 42 | 42 | 1.000x | 8 | 6 | 1.333x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | linux-selftests | xdp | 0 |  | 31 | 31 | 1.000x | 5 | 11 | 0.455x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | linux-selftests | sched_cls | 3 |  | 266 | 266 | 1.000x | 5345 | 7677 | 0.696x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | linux-selftests | sched_cls | 0 |  | 114 | 114 | 1.000x | 20 | 19 | 1.053x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | linux-selftests | sched_cls | 0 |  | 148 | 148 | 1.000x | 20 | 31 | 0.645x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | linux-selftests | sched_cls | 17 |  | 1676 | 1676 | 1.000x | 1000683459 | 1000947360 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog | linux-selftests | sched_cls | 0 |  | 129 | 129 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | 6 | 7 | 0.857x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs | linux-selftests | sched_cls | 0 |  | 107 | 107 | 1.000x | 8 | 8 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | linux-selftests | sched_cls | 0 |  | 28 | 28 | 1.000x | 6 | 7 | 0.857x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple | linux-selftests | sched_cls | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple | linux-selftests | xdp | 0 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress | linux-selftests | sched_cls | 1 |  | 1244 | 1244 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc | linux-selftests | sched_cls | 0 |  | 86 | 86 | 1.000x | 7 | 6 | 1.167x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers | linux-selftests | sched_cls | 0 |  | 115 | 115 | 1.000x | 17 | 13 | 1.308x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | sched_cls | 1 |  | 171 | 171 | 1.000x | 7 | 7 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | sched_cls | 1 |  | 392 | 392 | 1.000x | 8 | 6 | 1.333x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | sched_cls | 1 |  | 557 | 557 | 1.000x | 20 | 20 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | sched_cls | 1 |  | 526 | 526 | 1.000x | 23 | 21 | 1.095x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | sched_cls | 1 |  | 513 | 513 | 1.000x | 27 | 22 | 1.227x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | linux-selftests | sched_cls | 1 | extract | 479 | 479 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | linux-selftests | sched_cls | 1 | extract | 448 | 448 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | linux-selftests | sched_cls | 1 | extract | 435 | 435 | 1.000x | 6 | 7 | 0.857x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | linux-selftests | sched_cls | 1 | extract | 407 | 407 | 1.000x | 6 | 7 | 0.857x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth | linux-selftests | sched_cls | 1 | extract | 589 | 589 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | linux-selftests | sched_cls | 1 | extract | 558 | 558 | 1.000x | 7 | 6 | 1.167x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | linux-selftests | sched_cls | 1 | extract | 545 | 545 | 1.000x | 6 | 7 | 0.857x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | linux-selftests | sched_cls | 1 | extract | 605 | 605 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | linux-selftests | sched_cls | 1 | extract | 491 | 491 | 1.000x | 23 | 27 | 0.852x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | sched_cls | 1 |  | 505 | 505 | 1.000x | 24 | 20 | 1.200x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | linux-selftests | sched_cls | 4 | extract, endian | 697 | 689 | 1.012x | 6 | 8 | 0.750x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | sched_cls | 2 | endian | 689 | 686 | 1.004x | 20 | 20 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | sched_cls | 2 | endian | 656 | 653 | 1.005x | 20 | 20 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | sched_cls | 2 | endian | 643 | 640 | 1.005x | 21 | 20 | 1.050x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | sched_cls | 2 | endian | 705 | 702 | 1.004x | 20 | 20 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | sched_cls | 3 |  | 696 | 696 | 1.000x | 12 | 12 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | sched_cls | 992 |  | 48574 | 48574 | 1.000x | 473 | 465 | 1.017x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | linux-selftests | sched_cls | 0 |  | 152 | 152 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | linux-selftests | xdp | 0 |  | 107 | 107 | 1.000x | 6 | 9 | 0.667x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect | linux-selftests | xdp | 0 |  | 251 | 251 | 1.000x | 11 | 10 | 1.100x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | 11 | 12 | 0.917x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | linux-selftests | xdp | 0 |  | 38 | 38 | 1.000x | 12 | 7 | 1.714x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve1_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve2_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice_nosleep | linux-selftests | socket_filter | 0 |  | 28 | 28 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | 36 | 23 | 1.565x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | linux-selftests | sched_cls | 0 |  | 79 | 79 | 1.000x | 20 | 26 | 0.769x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | 10 | 5 | 2.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6 | linux-selftests | sched_cls | 0 |  | 58 | 58 | 1.000x | 9 | 8 | 1.125x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper | linux-selftests | sched_cls | 0 |  | 35 | 35 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu | linux-selftests | sched_cls | 0 |  | 54 | 54 | 1.000x | 8 | 7 | 1.143x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect | linux-selftests | xdp | 0 |  | 53 | 53 | 1.000x | 6 | 7 | 0.857x |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 36 | wide, extract, endian | 5454 | 5452 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | sched_cls | 36 |  | 5424 | 5424 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | xdp | 36 | wide, extract, endian | 5454 | 5452 | 1.000x | n/a | n/a | n/a |  |
| corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o:socket_handler | real_world_code_size | socket_filter | 1 | endian | 374 | 369 | 1.014x | n/a | n/a | n/a |  |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | real_world_code_size | sched_cls | 1 | endian | 111 | 108 | 1.028x | 179 | 169 | 1.059x |  |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | xdp | 9 |  | 1628 | 1628 | 1.000x | 24 | 28 | 0.857x |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | xdp | 1 |  | n/a | n/a | n/a | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cgroup_skb | 132 | wide, extract, endian | 19383 | 19320 | 1.003x | 54 | 61 | 0.885x |  |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cgroup_skb | 132 | wide, extract, endian | 19383 | 19320 | 1.003x | 41 | 37 | 1.108x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | xdp | 3 | endian | 697 | 691 | 1.009x | 33 | 37 | 0.892x |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | xdp | 3 | endian | 694 | 688 | 1.009x | 30 | 38 | 0.789x |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | xdp | 1 |  | 78 | 78 | 1.000x | 19 | 12 | 1.583x |  |
| corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | xdp-tools | xdp | 0 |  | 91 | 91 | 1.000x | 8 | 7 | 1.143x |  |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp-tutorial | xdp | 2 |  | 215 | 215 | 1.000x | 7 | 13 | 0.538x |  |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 7 | 7 | 1.000x |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 6 | 6 | 1.000x |  |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp-tutorial | xdp | 1 |  | 108 | 108 | 1.000x | 10 | 9 | 1.111x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | xdp-tutorial | xdp | 1 |  | 145 | 145 | 1.000x | 7 | 6 | 1.167x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 1 |  | 146 | 146 | 1.000x | 9 | 8 | 1.125x |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 1 |  | 146 | 146 | 1.000x | 7 | 8 | 0.875x |  |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | xdp-tutorial | sched_cls | 6 |  | 549 | 549 | 1.000x | 6 | 8 | 0.750x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | xdp | 2 |  | 511 | 511 | 1.000x | 9 | 8 | 1.125x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 8 | 6 | 1.333x |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | xdp | 3 | wide | 122 | 110 | 1.109x | 8 | 6 | 1.333x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | xdp | 3 |  | 526 | 526 | 1.000x | 10 | 10 | 1.000x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp-tutorial | xdp | 0 |  | 31 | 31 | 1.000x | 11 | 7 | 1.571x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | xdp | 4 | wide | 244 | 232 | 1.052x | 8 | 7 | 1.143x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | xdp | 4 | wide | 378 | 366 | 1.033x | 19 | 15 | 1.267x |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp-tutorial | xdp | 1 |  | 471 | 471 | 1.000x | 44 | 11 | 4.000x |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp-tutorial | xdp | 0 |  | 28 | 28 | 1.000x | 9 | 13 | 0.692x |  |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | xdp-tutorial | xdp | 0 |  | 231 | 231 | 1.000x | 322 | 314 | 1.025x |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | xdp | 1 |  | 170 | 170 | 1.000x | 215 | 249 | 0.863x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| io-mode packet requires an XDP or skb packet context (exit=1) | 14 |
| bpf_prog_test_run_opts failed: No space left on device (exit=1) | 8 |
| bpf_object__load failed: Permission denied (exit=1) | 4 |
| bpf_object__load failed: Argument list too long (exit=1) | 2 |

## Recompile Failures

| Reason | Count |
| --- | --- |
| BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) | 4 |

## Notes

- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current scanner pass determines whether v5 has any eligible families.
- In strict VM mode, each target boots the framework v5 guest once and runs baseline compile-only, v5 compile-only, baseline test_run, and v5 test_run in that order.
- Default steady-state semantics are stock: without `--use-policy` or `--blind-apply`, the v5 lane does not request recompile.
- `--use-policy` only considers per-program version 3 policy files under `corpus/policies/`; if no match exists, the driver stays on stock JIT.
- `--blind-apply` forces the old debug/exploration path with `--recompile-v5 --recompile-all`.
- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.
- Host fallback mode only does baseline compile-only plus offline scanner scan; it does not attempt recompile or runtime measurement.
- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.
