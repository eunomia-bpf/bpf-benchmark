# Selective CMOV Policy Results

- Date: 2026-03-11T14:15:36.926783+00:00
- Blind-all input: `/home/yunwei37/workspace/bpf-benchmark/micro/results/corpus_v5_vm_batch.json`
- Selective input: `/home/yunwei37/workspace/bpf-benchmark/micro/results/corpus_v5_vm_batch_skip_cmov.json`
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Repeat: 200
- Kernel: `7.0.0-rc2-g2a6783cc77b6`
- Selective policy: `--recompile-v5 --recompile-all --skip-families cmov`
- Ratio definition: `baseline_ns / v5_ns` (`> 1.0x` is faster).
- Shared non-sub rule: all four execution measurements across the blind-all and selective reruns are `>= 50ns`.

## 1. Geomean Comparison

| Scope | Programs | Blind-all | Selective | Delta | Comment |
| --- | --- | --- | --- | --- | --- |
| Raw measured pairs | 78 | 0.826x | 0.813x | -0.013x | Full 78 measured pairs from both reruns. |
| Shared non-sub | 46 | 0.828x | 0.870x | +0.043x | All four execution measurements are >= 50ns. |
| Calico only | 44 | 0.828x | 0.865x | +0.037x | Predictable packet-policy heavy subset. |
| Calico shared non-sub | 43 | 0.823x | 0.865x | +0.041x | Main signal-bearing subset. |
| Calico CMOV-only shared non-sub | 15 | 0.811x | 0.886x | +0.075x | Selective becomes a no-op control on these rows. |
| Calico CMOV+WIDE shared non-sub | 26 | 0.819x | 0.846x | +0.027x | Selective keeps WIDE and drops CMOV. |

Key takeaways:

- Raw full-corpus selective did **not** beat blind-all on this rerun: `0.813x` vs `0.826x`.
- On the shared non-sub subset, selective **did** beat blind-all: `0.870x` vs `0.828x`.
- The signal is concentrated in Calico, the predictable-branch `sched_cls` workload that motivated the CMOV skip: raw Calico improves from `0.828x` to `0.865x`.

## 2. Why Raw Selective Still Loses

| Bucket | Programs | Blind-all | Selective | Explanation |
| --- | --- | --- | --- | --- |
| Shared sub/noisy rows | 32 | 0.825x | 0.737x | Mostly selftests/xdp-tools/tracee; 32 rows have at least one <50ns measurement. |
| Selective no-op rows | 38 | 0.807x | 0.801x | 38 measured rows; 36 are CMOV-only and 2 are rotate-only, so selective applies no directive at all. |
| Selective applied rows | 40 | 0.845x | 0.825x | 40 rows still receive WIDE and/or ROTATE under selective. |

The raw 78-program corpus is still dominated by two confounders:

- A large control bucket where selective applies no directives at all. Those rows should be near `1.0x`, but they still move because the benchmark has residual run-to-run drift on unchanged programs.
- A shared sub/noisy bucket with at least one `< 50ns` measurement. That bucket is heavily weighted toward linux-selftests, xdp-tools, xdp-tutorial, Katran, and Tracee, and it pushes selective down from `0.870x` on the shared non-sub subset to `0.813x` on the raw full corpus.

## 3. Project And Family Attribution

| Project | Programs | Blind-all | Selective | Selective Applied | Selective > Blind-all |
| --- | --- | --- | --- | --- | --- |
| calico | 44 | 0.828x | 0.865x | 29 | yes |
| katran | 2 | 0.815x | 2.089x | 1 | yes |
| linux-selftests | 20 | 0.759x | 0.745x | 5 | no |
| suricata | 1 | 1.250x | 0.600x | 0 | no |
| tracee | 2 | 1.231x | 0.385x | 2 | no |
| xdp-tools | 3 | 0.930x | 0.651x | 0 | no |
| xdp-tutorial | 6 | 0.837x | 0.762x | 3 | no |

The family-mix view explains where the CMOV skip helps and where it does not:

| Eligible Families | Programs | Blind-all | Selective | Selective Applied | Comment |
| --- | --- | --- | --- | --- | --- |
| cmov | 36 | 0.802x | 0.793x | 0 | Selective is a no-op here; ratio movement is control noise. |
| rotate | 3 | 0.933x | 0.960x | 1 | Small sample; selective only changes CMOV, not ROTATE. |
| wide | 3 | 0.844x | 0.796x | 3 | WIDE remains active under selective. |
| cmov, wide | 35 | 0.833x | 0.817x | 35 | The mixed Calico subset improves on the shared non-sub slice. |
| cmov, wide, rotate | 1 | 1.182x | 1.091x | 1 |  |

Calico is the decisive slice on the shared non-sub subset:

| Calico Shared Non-Sub Scope | Programs | Blind-all | Selective | Comment |
| --- | --- | --- | --- | --- |
| CMOV-only | 15 | 0.811x | 0.886x | Selective becomes a baseline/no-op control and recovers many CMOV losses. |
| CMOV+WIDE | 26 | 0.819x | 0.846x | Skipping CMOV while keeping WIDE improves the mixed Calico rows. |
| ROTATE-only | 1 | 1.000x | 0.989x | Single-row control; not material. |
| WIDE-only | 1 | 0.967x | 0.913x | Single-row WIDE regression; not enough to change the Calico geomean trend. |

## 4. Per-Program 3-Way Table

Baseline is measured separately in the blind-all and selective reruns, so both baseline columns are reported explicitly.

| Program | Project | Eligible | Baseline (all) | Blind-all | Blind Ratio | Baseline (sel) | Selective | Selective Ratio | Delta | Selective Families | Tier |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | calico | rotate | 177 | 177 | 1.000x | 178 | 180 | 0.989x | -0.011x | rotate | shared-non-sub |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | cmov, wide | 329 | 329 | 1.000x | 327 | 342 | 0.956x | -0.044x | wide | shared-non-sub |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | cmov | 193 | 175 | 1.103x | 176 | 182 | 0.967x | -0.136x | (none) | shared-non-sub |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | cmov, wide | 171 | 308 | 0.555x | 174 | 265 | 0.657x | +0.101x | wide | shared-non-sub |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | cmov | 198 | 241 | 0.822x | 173 | 175 | 0.989x | +0.167x | (none) | shared-non-sub |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | cmov | 189 | 303 | 0.624x | 172 | 177 | 0.972x | +0.348x | (none) | shared-non-sub |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | cmov, wide | 174 | 219 | 0.795x | 177 | 203 | 0.872x | +0.077x | wide | shared-non-sub |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | cmov, wide | 178 | 192 | 0.927x | 172 | 193 | 0.891x | -0.036x | wide | shared-non-sub |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | calico | cmov, wide | 304 | 328 | 0.927x | 328 | 444 | 0.739x | -0.188x | wide | shared-non-sub |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | cmov | 172 | 276 | 0.623x | 173 | 278 | 0.622x | -0.001x | (none) | shared-non-sub |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | cmov, wide | 172 | 281 | 0.612x | 193 | 244 | 0.791x | +0.179x | wide | shared-non-sub |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | cmov | 179 | 223 | 0.803x | 175 | 242 | 0.723x | -0.080x | (none) | shared-non-sub |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | cmov | 170 | 198 | 0.859x | 171 | 178 | 0.961x | +0.102x | (none) | shared-non-sub |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | cmov, wide | 169 | 184 | 0.918x | 176 | 251 | 0.701x | -0.217x | wide | shared-non-sub |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | cmov, wide | 233 | 170 | 1.371x | 175 | 189 | 0.926x | -0.445x | wide | shared-non-sub |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | cmov, wide | 172 | 199 | 0.864x | 212 | 249 | 0.851x | -0.013x | wide | shared-non-sub |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | cmov | 175 | 196 | 0.893x | 180 | 176 | 1.023x | +0.130x | (none) | shared-non-sub |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | cmov, wide | 176 | 194 | 0.907x | 176 | 330 | 0.533x | -0.374x | wide | shared-non-sub |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | cmov | 169 | 201 | 0.841x | 193 | 202 | 0.955x | +0.115x | (none) | shared-non-sub |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | cmov, wide | 172 | 238 | 0.723x | 172 | 189 | 0.910x | +0.187x | wide | shared-non-sub |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | cmov, wide | 170 | 200 | 0.850x | 170 | 205 | 0.829x | -0.021x | wide | shared-non-sub |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | calico | cmov, wide | 175 | 307 | 0.570x | 175 | 190 | 0.921x | +0.351x | wide | shared-non-sub |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | calico | cmov, wide | 193 | 199 | 0.970x | 179 | 182 | 0.984x | +0.014x | wide | shared-non-sub |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | cmov | 195 | 284 | 0.687x | 192 | 227 | 0.846x | +0.159x | (none) | shared-non-sub |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | cmov, wide | 189 | 269 | 0.703x | 191 | 183 | 1.044x | +0.341x | wide | shared-non-sub |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | cmov | 173 | 175 | 0.989x | 175 | 178 | 0.983x | -0.005x | (none) | shared-non-sub |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | cmov, wide | 189 | 237 | 0.797x | 175 | 179 | 0.978x | +0.180x | wide | shared-non-sub |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | cmov, wide | 175 | 360 | 0.486x | 193 | 177 | 1.090x | +0.604x | wide | shared-non-sub |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | cmov, wide | 217 | 247 | 0.879x | 180 | 174 | 1.034x | +0.156x | wide | shared-non-sub |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | calico | cmov, wide | 176 | 177 | 0.994x | 187 | 198 | 0.944x | -0.050x | wide | shared-non-sub |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | cmov | 179 | 179 | 1.000x | 194 | 279 | 0.695x | -0.305x | (none) | shared-non-sub |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | cmov, wide | 170 | 232 | 0.733x | 175 | 181 | 0.967x | +0.234x | wide | shared-non-sub |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | cmov | 178 | 283 | 0.629x | 176 | 323 | 0.545x | -0.084x | (none) | shared-non-sub |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | cmov, wide | 175 | 189 | 0.926x | 170 | 178 | 0.955x | +0.029x | wide | shared-non-sub |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | cmov, wide | 172 | 188 | 0.915x | 175 | 217 | 0.806x | -0.108x | wide | shared-non-sub |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | calico | cmov, wide | 174 | 190 | 0.916x | 198 | 183 | 1.082x | +0.166x | wide | shared-non-sub |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | cmov | 172 | 294 | 0.585x | 193 | 183 | 1.055x | +0.470x | (none) | shared-non-sub |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | cmov, wide | 185 | 285 | 0.649x | 188 | 280 | 0.671x | +0.022x | wide | shared-non-sub |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | calico | cmov | 177 | 177 | 1.000x | 173 | 179 | 0.966x | -0.034x | (none) | shared-non-sub |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | cmov | 171 | 179 | 0.955x | 232 | 180 | 1.289x | +0.334x | (none) | shared-non-sub |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | calico | cmov, wide | 177 | 176 | 1.006x | 173 | 306 | 0.565x | -0.440x | wide | shared-non-sub |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | calico | cmov, wide | 177 | 219 | 0.808x | 176 | 257 | 0.685x | -0.123x | wide | shared-non-sub |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | calico | wide | 177 | 183 | 0.967x | 190 | 208 | 0.913x | -0.054x | wide | shared-non-sub |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | calico | wide | 16 | 15 | 1.067x | 13 | 15 | 0.867x | -0.200x | wide | shared-sub/noisy |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | cmov, wide, rotate | 13 | 11 | 1.182x | 12 | 11 | 1.091x | -0.091x | wide, rotate | shared-sub/noisy |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | cmov | 9 | 16 | 0.562x | 36 | 9 | 4.000x | +3.438x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | cmov | 9 | 11 | 0.818x | 8 | 15 | 0.533x | -0.285x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | linux-selftests | rotate | 485 | 563 | 0.861x | 535 | 524 | 1.021x | +0.160x | (none) | shared-non-sub |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | cmov | 7 | 13 | 0.538x | 8 | 16 | 0.500x | -0.038x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | linux-selftests | cmov | 18 | 28 | 0.643x | 20 | 17 | 1.176x | +0.534x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | linux-selftests | cmov | 10 | 15 | 0.667x | 9 | 15 | 0.600x | -0.067x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | linux-selftests | cmov | 11 | 16 | 0.688x | 11 | 17 | 0.647x | -0.040x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | cmov | 8 | 7 | 1.143x | 8 | 7 | 1.143x | +0.000x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | linux-selftests | cmov | 7 | 13 | 0.538x | 9 | 16 | 0.562x | +0.024x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | cmov | 7 | 12 | 0.583x | 8 | 13 | 0.615x | +0.032x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | linux-selftests | cmov | 7 | 12 | 0.583x | 8 | 12 | 0.667x | +0.083x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | linux-selftests | cmov | 8 | 7 | 1.143x | 9 | 12 | 0.750x | -0.393x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | linux-selftests | cmov | 7 | 7 | 1.000x | 8 | 12 | 0.667x | -0.333x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | linux-selftests | cmov | 10 | 8 | 1.250x | 7 | 12 | 0.583x | -0.667x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | linux-selftests | cmov | 8 | 12 | 0.667x | 7 | 12 | 0.583x | -0.083x | (none) | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | linux-selftests | wide | 7 | 12 | 0.583x | 7 | 11 | 0.636x | +0.053x | wide | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | linux-selftests | rotate | 474 | 502 | 0.944x | 473 | 539 | 0.878x | -0.067x | (none) | shared-non-sub |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | cmov, wide | 8 | 9 | 0.889x | 8 | 8 | 1.000x | +0.111x | wide | shared-sub/noisy |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | cmov, wide | 9 | 9 | 1.000x | 9 | 9 | 1.000x | +0.000x | wide | shared-sub/noisy |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | cmov, wide | 8 | 14 | 0.571x | 9 | 8 | 1.125x | +0.554x | wide | shared-sub/noisy |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | linux-selftests | cmov, wide | 9 | 14 | 0.643x | 8 | 10 | 0.800x | +0.157x | wide | shared-sub/noisy |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | suricata | cmov | 10 | 8 | 1.250x | 9 | 15 | 0.600x | -0.650x | (none) | shared-sub/noisy |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | suricata | cmov | n/a | n/a | n/a | n/a | n/a | n/a | n/a | (none) | shared-non-sub |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | cmov, wide | 8 | 13 | 0.615x | 8 | 54 | 0.148x | -0.467x | wide | shared-sub/noisy |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | cmov, wide | 32 | 13 | 2.462x | 8 | 8 | 1.000x | -1.462x | wide | shared-sub/noisy |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | cmov | 9 | 14 | 0.643x | 10 | 14 | 0.714x | +0.071x | (none) | shared-sub/noisy |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | cmov | 10 | 9 | 1.111x | 9 | 15 | 0.600x | -0.511x | (none) | shared-sub/noisy |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | cmov | 18 | 16 | 1.125x | 18 | 28 | 0.643x | -0.482x | (none) | shared-sub/noisy |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp-tutorial | cmov | 11 | 11 | 1.000x | 7 | 15 | 0.467x | -0.533x | (none) | shared-sub/noisy |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | cmov, wide | 8 | 9 | 0.889x | 10 | 13 | 0.769x | -0.120x | wide | shared-sub/noisy |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | cmov | 11 | 17 | 0.647x | 8 | 9 | 0.889x | +0.242x | (none) | shared-sub/noisy |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | cmov, wide | 10 | 10 | 1.000x | 10 | 15 | 0.667x | -0.333x | wide | shared-sub/noisy |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp-tutorial | cmov, wide | 17 | 25 | 0.680x | 15 | 16 | 0.938x | +0.257x | wide | shared-sub/noisy |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp-tutorial | cmov | 211 | 240 | 0.879x | 179 | 182 | 0.984x | +0.104x | (none) | shared-non-sub |

## 5. Conclusion

- The implementation is correct: `--skip-families cmov` removes CMOV from the generated v5 policy blob, and the batch pipeline records the resulting applied families correctly.
- The measured outcome is mixed. On the raw 78-program corpus, selective CMOV skip does **not** beat blind-all (`0.813x` vs `0.826x`).
- On the shared non-sub subset, selective **does** beat blind-all (`0.870x` vs `0.828x`), and the improvement is concentrated in Calico (`0.865x` vs `0.828x`; CMOV-only `0.886x` vs `0.811x`; CMOV+WIDE `0.846x` vs `0.819x`).
- The remaining gap to a clean raw-corpus win comes from control/no-op rows and from non-Calico regressions that are unrelated to CMOV skipping, especially WIDE-heavy or very short-running programs.
- The defensible conclusion from this rerun is therefore narrower than the original hypothesis: global `--skip-families cmov` helps the intended predictable-branch Calico subset, but it is not enough by itself to produce a raw full-corpus win.
