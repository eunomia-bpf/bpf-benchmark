# Corpus Recompile Regression Analysis

- Date: 2026-03-11
- Sources: `docs/kernel-jit-optimization-plan.md`, `docs/tmp/corpus-batch-recompile-results.md`, `docs/tmp/corpus-runnability-report.md`
- Ratio definition: `baseline_ns / v5_ns` (same direction as the batch report; `> 1.0x` means v5 is faster)
- Tier rule: `sub-resolution` if either side `< 50ns`; `reliable` only if both sides `> 200ns`; everything else is `low-confidence`
- Program labels below use `<last-two-path-components>:<prog_name>` shorthand for readability

## 1. Noise Classification

| Tier | Rule | Programs | Share | Geomean | Notes |
| --- | --- | --- | --- | --- | --- |
| sub-resolution | < 50ns on either side | 32 | 41.0% | 0.767x | Pure timing noise; exclude |
| low-confidence | not sub-resolution, but not both > 200ns | 41 | 52.6% | 0.839x | Keep, but only as directional evidence |
| reliable | both baseline and v5 > 200ns | 5 | 6.4% | 0.915x | Best available rows under the requested rule |

Key observations:

- Only 5/78 rows (6.4%) satisfy the strict `both > 200ns` reliability rule.
- 46/78 rows (59.0%) remain after removing pure sub-resolution noise, but 43/46 of them are Calico, 44/46 are `sched_cls`, and 42/46 have CMOV applied.
- The strict rule is intentionally harsh: pairs like `169ns -> 215ns` and `200ns -> 229ns` stay `low-confidence`, not `reliable`.

## 2. Recalculated Geomeans After Excluding Noise

| Scope | Programs | Geomean | Delta vs Raw 0.813x | Comment |
| --- | --- | --- | --- | --- |
| Raw batch report | 78 | 0.813x | baseline | Includes all 32 sub-resolution rows |
| Reliable + low-confidence | 46 | 0.847x | +0.034x | Removes pure noise only |
| Reliable only | 5 | 0.915x | +0.102x | Strictest requested filter |
| Reliable only, directives applied | 3 | 0.919x | +0.106x | Drops the two no-op control rows |

Interpretation:

- Excluding pure sub-resolution noise moves the corpus geomean from `0.813x` to `0.847x`. The batch still points negative overall, but much less dramatically.
- The strict reliable-only geomean is `0.915x`, but that number is fragile because 2 of the 5 reliable rows are control rows where no directive was applied at all.

### Residual Noise Above 200ns

The runnability report provides an earlier paired measurement for the same programs. Even after removing sub-resolution rows, sign stability is weak:

- `21/46` non-sub rows flip sign between the runnability report and the batch rerun.
- This includes `2/5` strict-reliable rows and `19/41` low-confidence rows.

The two reliable no-op controls are the clearest proof that the batch still contains non-trivial measurement drift even when execution time is hundreds of ns:

| Program | Baseline JIT | v5 JIT | Runnability Ratio | Batch Ratio |
| --- | --- | --- | --- | --- |
| progs/core_kern:balancer_ingress | 50290 | 50290 | 1.004x | 1.130x |
| progs/test_verif_scale2:balancer_ingress | 48576 | 48576 | 0.946x | 0.734x |

These rows have identical JIT size before and after recompile, so their ratio movement is timing noise, not directive effect.

## 3. Per-Family Attribution Among Strict-Reliable Programs

Under the requested `both > 200ns` rule, the reliable pool is extremely sparse. Exact-family attribution looks like this:

| Bucket | Reliable Programs | Geomean | Status |
| --- | --- | --- | --- |
| CMOV-only | 0 | n/a | none |
| WIDE-only | 0 | n/a | none |
| CMOV+WIDE | 3 | 0.919x | 3 mixed rows |
| ROTATE (any) | 0 | n/a | none |
| No applied family | 2 | 0.910x | noise-control rows |

### CMOV-only reliable programs

None. The strict rule leaves zero reliable pure-CMOV rows, so the batch cannot make a clean reliable-only causal statement about CMOV in isolation.

### WIDE-only reliable programs

None. The only non-sub WIDE-only row is `calico/xdp_debug:calico_xdp_main` at `170ns -> 198ns`, which remains low-confidence.

### CMOV+WIDE reliable programs

| Program | Project | Type | Baseline ns | v5 ns | Exec Ratio |
| --- | --- | --- | --- | --- | --- |
| calico/from_hep_debug:calico_tc_main | calico | sched_cls | 326 | 323 | 1.009x |
| calico/from_nat_debug:calico_tc_main | calico | sched_cls | 305 | 333 | 0.916x |
| calico/from_wep_debug:calico_tc_skb_send_tcp_rst | calico | sched_cls | 240 | 286 | 0.839x |

Pattern: this is the only directive-applied reliable bucket, and it is mixed even here: one marginal win (`1.009x`) and two losses (`0.916x`, `0.839x`). Two of the three rows are Calico `sched_cls` mainline paths; one is a TCP-RST helper. This is too little data for family isolation, but it is enough to say that blanket `cmov+wide` is not an always-win policy.

### ROTATE reliable programs

None. The only exact `rotate` row is `calico/from_hep_debug:calico_tc_maglev` at `169ns -> 215ns`, which stays low-confidence by rule. The `cmov,wide,rotate` Katran row is sub-resolution (`11ns -> 16ns`).

## 4. Policy-Sensitivity Signal Extraction

### Strict-reliable evidence

| Scope | Programs | Wins | Losses | Geomean |
| --- | --- | --- | --- | --- |
| CMOV applied, reliable only | 3 | 1 | 2 | 0.919x |
| CMOV-only, reliable only | 0 | 0 | 0 | n/a |

Reliable-only takeaway: there is not enough isolated CMOV data to prove the CMOV thesis from the strict-reliable subset alone.

### Directional evidence after removing only pure noise

| Scope | Programs | Wins | Losses | Geomean |
| --- | --- | --- | --- | --- |
| CMOV applied, reliable + low-confidence | 42 | 8 | 34 | 0.845x |
| CMOV-only, reliable + low-confidence | 16 | 2 | 14 | 0.797x |
| CMOV+WIDE, reliable + low-confidence | 26 | 6 | 20 | 0.876x |

- `41/42` non-sub CMOV-applied rows are Calico `sched_cls` programs. `33/41` of those regress.
- Pure-CMOV rows are almost entirely Calico too: `15/16` are Calico `sched_cls`, and `13/15` of those regress.
- That directional concentration is consistent with the plan’s policy-sensitivity thesis: CMOV tends to hurt predictable packet-policy control flow. It is not definitive proof here, because almost all of these rows are still low-confidence and many flip sign across reruns.

### Same directive helps some programs, hurts others

The cleanest way to show this is to group repeated Calico symbols after sub-resolution removal:

| Function family | Exact family set | Instances | Ratio range | Geomean |
| --- | --- | --- | --- | --- |
| calico_tc_host_ct_conflict | cmov, wide | 2 | 0.652x .. 1.079x | 0.838x |
| calico_tc_main | cmov, wide | 6 | 0.659x .. 1.009x | 0.846x |
| calico_tc_skb_accepted_entrypoint | cmov | 6 | 0.596x .. 1.089x | 0.774x |
| calico_tc_skb_icmp_inner_nat | cmov, wide | 6 | 0.680x .. 0.971x | 0.802x |
| calico_tc_skb_ipv4_frag | cmov | 3 | 0.606x .. 0.994x | 0.771x |
| calico_tc_skb_new_flow_entrypoint | cmov | 6 | 0.547x .. 1.140x | 0.811x |
| calico_tc_skb_send_icmp_replies | cmov, wide | 6 | 0.601x .. 1.197x | 0.862x |
| calico_tc_skb_send_tcp_rst | cmov, wide | 6 | 0.839x .. 1.711x | 1.022x |
| xdp_sample_prog | cmov | 1 | 0.951x .. 0.951x | 0.951x |

Important patterns:

- Pure-CMOV families are mostly negative but not uniform: `accepted_entrypoint` spans `0.596x .. 1.089x`, `new_flow_entrypoint` spans `0.547x .. 1.140x`, and `ipv4_frag` stays below `1.0x` in all three non-sub instances.
- Mixed `cmov+wide` families are also split: `send_tcp_rst` is the only repeated mixed family with geomean above `1.0x` (`1.022x`), while `tc_main`, `icmp_inner_nat`, `send_icmp_replies`, and `host_ct_conflict` stay below `1.0x` on geomean.
- So the corpus does expose the key paper signal: the same CMOV directive is present in both winners and losers. The clean reliable-only subset is too small to isolate it, but the non-sub corpus shows the policy sensitivity directionally.

### Which programs benefit from CMOV? Which are harmed?

CMOV-applied winners (after removing sub-resolution rows):

| Program | Tier | Families | Baseline ns | v5 ns | Exec Ratio |
| --- | --- | --- | --- | --- | --- |
| calico/from_nat_debug:calico_tc_skb_send_tcp_rst | low-confidence | cmov, wide | 308 | 180 | 1.711x |
| calico/to_wep_debug:calico_tc_skb_send_icmp_replies | low-confidence | cmov, wide | 225 | 188 | 1.197x |
| calico/from_hep_debug:calico_tc_skb_send_icmp_replies | low-confidence | cmov, wide | 233 | 197 | 1.183x |
| calico/from_hep_debug:calico_tc_skb_new_flow_entrypoint | low-confidence | cmov | 196 | 172 | 1.140x |
| calico/from_nat_debug:calico_tc_skb_accepted_entrypoint | low-confidence | cmov | 195 | 179 | 1.089x |
| calico/to_hep_debug:calico_tc_host_ct_conflict | low-confidence | cmov, wide | 206 | 191 | 1.079x |
| calico/to_nat_debug:calico_tc_skb_send_tcp_rst | low-confidence | cmov, wide | 187 | 185 | 1.011x |
| calico/from_hep_debug:calico_tc_main | reliable | cmov, wide | 326 | 323 | 1.009x |

CMOV-applied losers (after removing sub-resolution rows):

| Program | Tier | Families | Baseline ns | v5 ns | Exec Ratio |
| --- | --- | --- | --- | --- | --- |
| calico/to_nat_debug:calico_tc_skb_new_flow_entrypoint | low-confidence | cmov | 173 | 316 | 0.547x |
| calico/from_wep_debug:calico_tc_skb_accepted_entrypoint | low-confidence | cmov | 180 | 302 | 0.596x |
| calico/from_nat_debug:calico_tc_skb_send_icmp_replies | low-confidence | cmov, wide | 173 | 288 | 0.601x |
| calico/to_wep_debug:calico_tc_skb_ipv4_frag | low-confidence | cmov | 172 | 284 | 0.606x |
| calico/to_nat_debug:calico_tc_host_ct_conflict | low-confidence | cmov, wide | 174 | 267 | 0.652x |
| calico/to_wep_debug:calico_tc_main | low-confidence | cmov, wide | 197 | 299 | 0.659x |
| calico/to_wep_debug:calico_tc_skb_accepted_entrypoint | low-confidence | cmov | 171 | 254 | 0.673x |
| calico/from_wep_debug:calico_tc_skb_icmp_inner_nat | low-confidence | cmov, wide | 191 | 281 | 0.680x |
| calico/to_hep_debug:calico_tc_skb_send_icmp_replies | low-confidence | cmov, wide | 196 | 287 | 0.683x |
| calico/from_nat_debug:calico_tc_skb_icmp_inner_nat | low-confidence | cmov, wide | 194 | 282 | 0.688x |
| calico/from_nat_debug:calico_tc_skb_new_flow_entrypoint | low-confidence | cmov | 176 | 254 | 0.693x |
| calico/from_hep_debug:calico_tc_skb_icmp_inner_nat | low-confidence | cmov, wide | 170 | 244 | 0.697x |
| calico/from_wep_debug:calico_tc_skb_send_icmp_replies | low-confidence | cmov, wide | 171 | 238 | 0.718x |
| calico/from_hep_debug:calico_tc_skb_accepted_entrypoint | low-confidence | cmov | 172 | 233 | 0.738x |
| calico/from_nat_debug:calico_tc_skb_ipv4_frag | low-confidence | cmov | 172 | 226 | 0.761x |
| calico/to_nat_debug:calico_tc_skb_accepted_entrypoint | low-confidence | cmov | 173 | 227 | 0.762x |
| calico/to_hep_debug:calico_tc_skb_new_flow_entrypoint | low-confidence | cmov | 180 | 227 | 0.793x |
| calico/to_hep_debug:calico_tc_main | low-confidence | cmov, wide | 183 | 228 | 0.803x |
| calico/from_hep_debug:calico_tc_skb_send_tcp_rst | low-confidence | cmov, wide | 198 | 236 | 0.839x |
| calico/from_wep_debug:calico_tc_skb_send_tcp_rst | reliable | cmov, wide | 240 | 286 | 0.839x |
| calico/from_wep_debug:calico_tc_main | low-confidence | cmov, wide | 189 | 224 | 0.844x |
| calico/to_hep_debug:calico_tc_skb_icmp_inner_nat | low-confidence | cmov, wide | 200 | 229 | 0.873x |
| calico/from_wep_debug:calico_tc_skb_new_flow_entrypoint | low-confidence | cmov | 169 | 193 | 0.876x |
| calico/to_hep_debug:calico_tc_skb_accepted_entrypoint | low-confidence | cmov | 178 | 203 | 0.877x |
| calico/to_nat_debug:calico_tc_main | low-confidence | cmov, wide | 188 | 212 | 0.887x |
| calico/from_nat_debug:calico_tc_main | reliable | cmov, wide | 305 | 333 | 0.916x |
| calico/to_hep_debug:calico_tc_skb_send_tcp_rst | low-confidence | cmov, wide | 174 | 185 | 0.941x |
| calico/to_wep_debug:calico_tc_skb_new_flow_entrypoint | low-confidence | cmov | 195 | 206 | 0.947x |
| tracing04-xdp-tcpdump/xdp_sample_pkts_kern:xdp_sample_prog | low-confidence | cmov | 175 | 184 | 0.951x |
| calico/to_nat_debug:calico_tc_skb_icmp_inner_nat | low-confidence | cmov, wide | 170 | 177 | 0.960x |
| calico/to_wep_debug:calico_tc_skb_icmp_inner_nat | low-confidence | cmov, wide | 170 | 175 | 0.971x |
| calico/to_nat_debug:calico_tc_skb_send_icmp_replies | low-confidence | cmov, wide | 174 | 177 | 0.983x |
| calico/from_hep_debug:calico_tc_skb_ipv4_frag | low-confidence | cmov | 176 | 177 | 0.994x |
| calico/to_wep_debug:calico_tc_skb_send_tcp_rst | low-confidence | cmov, wide | 178 | 179 | 0.994x |

## 5. Recommendations

1. Default directive families

- Keep `wide_load` and `rotate_fusion` in the “substrate/default” bucket, but cite this batch carefully: it provides no strict-reliable isolated WIDE or ROTATE measurement (`0` reliable WIDE-only rows, `0` reliable ROTATE rows). The default-policy recommendation still comes mainly from the earlier fixed-baseline and microbenchmark evidence in the plan, not from this batch.
- `lea_fusion` is not present here (`0` sites), so this corpus says nothing new about LEA policy.

2. Families that need policy control

- `cmov_select` still needs per-program policy. In the non-sub corpus, CMOV-applied rows split `8` wins vs `34` losses, and pure-CMOV rows are `2` wins vs `14` losses with `0.797x` geomean.
- The CMOV signal is tightly coupled to Calico `sched_cls` packet-policy code, which is exactly the “predictable branch” regime where the plan already says blanket CMOV should fail.

3. Optimal per-program policy (`skip CMOV where it hurts`)

The exact counterfactual is not fully measured for mixed `cmov+wide` rows. The batch only gives `baseline` vs `v5-with-all-applied-families`, not `v5-with-wide-but-without-cmov`.

Given that limitation, the defensible answer is a range:

| Scope | Observed Geomean | Conservative Policy Geomean | Oracle Upper Bound | Meaning |
| --- | --- | --- | --- | --- |
| Reliable + low-confidence (46 rows) | 0.847x | 0.921x | 1.013x | Conservative: only disable pure-CMOV losers. Oracle: disable CMOV for any losing CMOV-applied row and assume it recovers to at least baseline. |
| Reliable only (5 rows) | 0.915x | 0.915x | 0.965x | Same assumptions, but the sample is too small to be decisive. |

My recommendation is to quote the range, not a fabricated single number. If a single “oracle” number is required for the paper, use `1.013x` and label it clearly as an upper bound under independent CMOV control. If you want the most conservative measured-policy statement, use `0.921x` on the 46 non-sub rows.

4. Reporting guidance

- Do not present the raw `0.813x` as the directive-framework verdict; it is heavily contaminated by 32 sub-resolution rows.
- If you need one cleaned corpus number, use `0.847x` with the explicit note that only 5/78 rows are strict-reliable and 2 of those 5 are no-op controls.
- The stronger paper narrative is policy sensitivity, not aggregate slowdown: the corpus shows that CMOV participates in both wins and losses, so blanket fixed policy is wrong.

## Appendix A. Sub-Resolution Programs

| Program | Project | Type | Families | Baseline ns | v5 ns | Exec Ratio |
| --- | --- | --- | --- | --- | --- | --- |
| calico/xdp_no_log:calico_xdp_main | calico | xdp | wide | 16 | 15 | 1.067x |
| katran/balancer:balancer_ingress | katran | xdp | cmov, wide, rotate | 11 | 16 | 0.688x |
| katran/healthchecking:healthcheck_encap | katran | sched_cls | cmov | 10 | 15 | 0.667x |
| linux-selftests/test_tc_bpf:pkt_ptr | linux-selftests | sched_cls | cmov | 7 | 12 | 0.583x |
| linux-selftests/xdp_synproxy_kern:syncookie_tc | linux-selftests | sched_cls | cmov, wide | 10 | 14 | 0.714x |
| linux-selftests/xdp_synproxy_kern:syncookie_xdp | linux-selftests | xdp | cmov, wide | 9 | 15 | 0.600x |
| progs/decap_sanity:decap_sanity | linux-selftests | sched_cls | cmov | 8 | 8 | 1.000x |
| progs/for_each_array_map_elem:test_pkt_access | linux-selftests | sched_cls | cmov | 17 | 27 | 0.630x |
| progs/test_sockmap_update:copy_sock_map | linux-selftests | sched_cls | cmov | 9 | 16 | 0.562x |
| progs/test_tc_change_tail:change_tail | linux-selftests | sched_cls | cmov | 9 | 17 | 0.529x |
| progs/test_tc_tunnel:__encap_gre_eth | linux-selftests | sched_cls | cmov | 8 | 13 | 0.615x |
| progs/test_tc_tunnel:__encap_gre_mpls | linux-selftests | sched_cls | cmov | 8 | 13 | 0.615x |
| progs/test_tc_tunnel:__encap_gre_none | linux-selftests | sched_cls | cmov | 9 | 7 | 1.286x |
| progs/test_tc_tunnel:__encap_ipip_none | linux-selftests | sched_cls | cmov | 10 | 12 | 0.833x |
| progs/test_tc_tunnel:__encap_udp_eth | linux-selftests | sched_cls | cmov | 8 | 12 | 0.667x |
| progs/test_tc_tunnel:__encap_udp_mpls | linux-selftests | sched_cls | cmov | 8 | 12 | 0.667x |
| progs/test_tc_tunnel:__encap_udp_none | linux-selftests | sched_cls | cmov | 7 | 7 | 1.000x |
| progs/test_tc_tunnel:__encap_vxlan_eth | linux-selftests | sched_cls | cmov | 7 | 16 | 0.438x |
| progs/test_tc_tunnel:decap_f | linux-selftests | sched_cls | wide | 7 | 16 | 0.438x |
| progs/xdp_synproxy_kern:syncookie_tc | linux-selftests | sched_cls | cmov, wide | 8 | 14 | 0.571x |
| progs/xdp_synproxy_kern:syncookie_xdp | linux-selftests | xdp | cmov, wide | 10 | 10 | 1.000x |
| suricata/xdp_filter:xdp_hashfilter | suricata | xdp | cmov | 10 | 9 | 1.111x |
| tracee/tracee:cgroup_skb_egress | tracee | cgroup_skb | cmov, wide | 8 | 10 | 0.800x |
| tracee/tracee:cgroup_skb_ingress | tracee | cgroup_skb | cmov, wide | 8 | 16 | 0.500x |
| xdp-tools/xdp_forward:xdp_fwd_fib_direct | xdp-tools | xdp | cmov | 9 | 9 | 1.000x |
| xdp-tools/xdp_forward:xdp_fwd_fib_full | xdp-tools | xdp | cmov | 9 | 8 | 1.125x |
| xdp-tools/xdp_load_bytes:xdp_probe_prog | xdp-tools | xdp | cmov | 15 | 15 | 1.000x |
| packet02-rewriting/xdp_prog_kern:xdp_parser_func | xdp-tutorial | xdp | cmov | 9 | 10 | 0.900x |
| packet02-rewriting/xdp_prog_kern:xdp_vlan_swap_func | xdp-tutorial | xdp | cmov, wide | 10 | 9 | 1.111x |
| packet03-redirecting/xdp_prog_kern:xdp_icmp_echo_func | xdp-tutorial | xdp | cmov | 10 | 10 | 1.000x |
| packet03-redirecting/xdp_prog_kern:xdp_redirect_func | xdp-tutorial | xdp | cmov, wide | 10 | 11 | 0.909x |
| packet03-redirecting/xdp_prog_kern:xdp_redirect_map_func | xdp-tutorial | xdp | cmov, wide | 15 | 15 | 1.000x |

## Appendix B. Low-Confidence Programs

| Program | Project | Type | Families | Baseline ns | v5 ns | Exec Ratio |
| --- | --- | --- | --- | --- | --- | --- |
| calico/from_hep_debug:calico_tc_maglev | calico | sched_cls | rotate | 169 | 215 | 0.786x |
| calico/from_hep_debug:calico_tc_skb_accepted_entrypoint | calico | sched_cls | cmov | 172 | 233 | 0.738x |
| calico/from_hep_debug:calico_tc_skb_icmp_inner_nat | calico | sched_cls | cmov, wide | 170 | 244 | 0.697x |
| calico/from_hep_debug:calico_tc_skb_ipv4_frag | calico | sched_cls | cmov | 176 | 177 | 0.994x |
| calico/from_hep_debug:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | cmov | 196 | 172 | 1.140x |
| calico/from_hep_debug:calico_tc_skb_send_icmp_replies | calico | sched_cls | cmov, wide | 233 | 197 | 1.183x |
| calico/from_hep_debug:calico_tc_skb_send_tcp_rst | calico | sched_cls | cmov, wide | 198 | 236 | 0.839x |
| calico/from_nat_debug:calico_tc_skb_accepted_entrypoint | calico | sched_cls | cmov | 195 | 179 | 1.089x |
| calico/from_nat_debug:calico_tc_skb_icmp_inner_nat | calico | sched_cls | cmov, wide | 194 | 282 | 0.688x |
| calico/from_nat_debug:calico_tc_skb_ipv4_frag | calico | sched_cls | cmov | 172 | 226 | 0.761x |
| calico/from_nat_debug:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | cmov | 176 | 254 | 0.693x |
| calico/from_nat_debug:calico_tc_skb_send_icmp_replies | calico | sched_cls | cmov, wide | 173 | 288 | 0.601x |
| calico/from_nat_debug:calico_tc_skb_send_tcp_rst | calico | sched_cls | cmov, wide | 308 | 180 | 1.711x |
| calico/from_wep_debug:calico_tc_main | calico | sched_cls | cmov, wide | 189 | 224 | 0.844x |
| calico/from_wep_debug:calico_tc_skb_accepted_entrypoint | calico | sched_cls | cmov | 180 | 302 | 0.596x |
| calico/from_wep_debug:calico_tc_skb_icmp_inner_nat | calico | sched_cls | cmov, wide | 191 | 281 | 0.680x |
| calico/from_wep_debug:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | cmov | 169 | 193 | 0.876x |
| calico/from_wep_debug:calico_tc_skb_send_icmp_replies | calico | sched_cls | cmov, wide | 171 | 238 | 0.718x |
| calico/to_hep_debug:calico_tc_host_ct_conflict | calico | sched_cls | cmov, wide | 206 | 191 | 1.079x |
| calico/to_hep_debug:calico_tc_main | calico | sched_cls | cmov, wide | 183 | 228 | 0.803x |
| calico/to_hep_debug:calico_tc_skb_accepted_entrypoint | calico | sched_cls | cmov | 178 | 203 | 0.877x |
| calico/to_hep_debug:calico_tc_skb_icmp_inner_nat | calico | sched_cls | cmov, wide | 200 | 229 | 0.873x |
| calico/to_hep_debug:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | cmov | 180 | 227 | 0.793x |
| calico/to_hep_debug:calico_tc_skb_send_icmp_replies | calico | sched_cls | cmov, wide | 196 | 287 | 0.683x |
| calico/to_hep_debug:calico_tc_skb_send_tcp_rst | calico | sched_cls | cmov, wide | 174 | 185 | 0.941x |
| calico/to_nat_debug:calico_tc_host_ct_conflict | calico | sched_cls | cmov, wide | 174 | 267 | 0.652x |
| calico/to_nat_debug:calico_tc_main | calico | sched_cls | cmov, wide | 188 | 212 | 0.887x |
| calico/to_nat_debug:calico_tc_skb_accepted_entrypoint | calico | sched_cls | cmov | 173 | 227 | 0.762x |
| calico/to_nat_debug:calico_tc_skb_icmp_inner_nat | calico | sched_cls | cmov, wide | 170 | 177 | 0.960x |
| calico/to_nat_debug:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | cmov | 173 | 316 | 0.547x |
| calico/to_nat_debug:calico_tc_skb_send_icmp_replies | calico | sched_cls | cmov, wide | 174 | 177 | 0.983x |
| calico/to_nat_debug:calico_tc_skb_send_tcp_rst | calico | sched_cls | cmov, wide | 187 | 185 | 1.011x |
| calico/to_wep_debug:calico_tc_main | calico | sched_cls | cmov, wide | 197 | 299 | 0.659x |
| calico/to_wep_debug:calico_tc_skb_accepted_entrypoint | calico | sched_cls | cmov | 171 | 254 | 0.673x |
| calico/to_wep_debug:calico_tc_skb_icmp_inner_nat | calico | sched_cls | cmov, wide | 170 | 175 | 0.971x |
| calico/to_wep_debug:calico_tc_skb_ipv4_frag | calico | sched_cls | cmov | 172 | 284 | 0.606x |
| calico/to_wep_debug:calico_tc_skb_new_flow_entrypoint | calico | sched_cls | cmov | 195 | 206 | 0.947x |
| calico/to_wep_debug:calico_tc_skb_send_icmp_replies | calico | sched_cls | cmov, wide | 225 | 188 | 1.197x |
| calico/to_wep_debug:calico_tc_skb_send_tcp_rst | calico | sched_cls | cmov, wide | 178 | 179 | 0.994x |
| calico/xdp_debug:calico_xdp_main | calico | xdp | wide | 170 | 198 | 0.859x |
| tracing04-xdp-tcpdump/xdp_sample_pkts_kern:xdp_sample_prog | xdp-tutorial | xdp | cmov | 175 | 184 | 0.951x |

## Appendix C. Reliable Programs

| Program | Project | Type | Families | Baseline ns | v5 ns | Exec Ratio |
| --- | --- | --- | --- | --- | --- | --- |
| calico/from_hep_debug:calico_tc_main | calico | sched_cls | cmov, wide | 326 | 323 | 1.009x |
| calico/from_nat_debug:calico_tc_main | calico | sched_cls | cmov, wide | 305 | 333 | 0.916x |
| calico/from_wep_debug:calico_tc_skb_send_tcp_rst | calico | sched_cls | cmov, wide | 240 | 286 | 0.839x |
| progs/core_kern:balancer_ingress | linux-selftests | sched_cls | (none) | 548 | 485 | 1.130x |
| progs/test_verif_scale2:balancer_ingress | linux-selftests | sched_cls | (none) | 471 | 642 | 0.734x |
