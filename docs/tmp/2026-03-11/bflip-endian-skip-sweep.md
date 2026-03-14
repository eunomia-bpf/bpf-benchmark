# Branch-Flip / Endian Skip Sweep

## Scope

- Input tuned artifact: `corpus/results/corpus_v5_tuned_policy.json`
- Inventory: `docs/tmp/corpus-runnability-results.json`
- Selected programs: `38` high-confidence Calico regressors (`stock exec_ns >= 100`, tuned ratio `< 1.0x`)
- VM kernel: `vendor/linux-framework/arch/x86/boot/bzImage`
- Repeat count: `200`
- Preserve existing object-level skips: `True`

## Takeaway

- The remeasured tuned baseline on this 38-program slice is `0.844x` vs stock.
- `branch-flip: skip` alone is worse on the slice: `0.827x` vs stock, even though its policy-to-policy geomean vs round 1 is `1.034x`.
- `branch-flip: skip + endian: skip` is the best measured variant here: `0.857x` vs stock and `1.066x` policy-to-policy vs round 1. It improves over the current tuned policy, but it does not reach break-even against stock on this full high-confidence Calico regressor slice.

## Round Summary

| Round | Measured | Applied | Geomean vs stock | Policy geomean vs round 1 | Wins vs round 1 | Regressions vs round 1 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Round 1: current tuned policy | 38 | 38 | 0.844x | 1.000x | 0 | 0 |
| Round 2: branch-flip skip | 38 | 34 | 0.827x | 1.034x | 21 | 17 |
| Round 3: branch-flip + endian skip | 38 | 25 | 0.857x | 1.066x | 19 | 18 |

## Notes

- Round 1 remeasures the existing `corpus/policies/` tuned policy as the same-setup baseline.
- Round 2 and Round 3 use per-program version 2 policies generated from `scanner generate-policy` templates.
- When `preserve_object_skips=true`, existing object-level skip families (currently CMOV on some Calico objects) are copied into the per-program v2 files so the sweep isolates the branch-flip/endian change instead of silently re-enabling CMOV.

## Per-Program Results

| Program | Stock ns | Source tuned | Round 1 | Round 2 | Round 3 | Round 2 vs R1 | Round 3 vs R1 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag` | 176 | 0.674x | 0.434x | 0.548x | 0.872x | 1.545x | 2.119x |
| `calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 172 | 0.741x | 0.538x | 0.989x | 1.000x | 1.881x | 1.936x |
| `calico/to_nat_debug.bpf.o:calico_tc_skb_drop` | 175 | 0.785x | 0.546x | 0.989x | 0.893x | 2.033x | 1.858x |
| `calico/to_wep_debug.bpf.o:calico_tc_skb_drop` | 174 | 0.978x | 0.552x | 0.651x | 1.000x | 1.171x | 1.790x |
| `calico/from_wep_debug.bpf.o:calico_tc_main` | 177 | 0.831x | 0.536x | 0.708x | 1.054x | 1.284x | 1.735x |
| `calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | 175 | 0.994x | 0.585x | 0.799x | 0.854x | 1.365x | 1.459x |
| `calico/to_hep_debug.bpf.o:calico_tc_main` | 184 | 0.848x | 1.190x | 1.027x | 0.856x | 1.579x | 1.431x |
| `calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies` | 183 | 0.821x | 0.692x | 0.955x | 0.961x | 1.388x | 1.388x |
| `calico/xdp_debug.bpf.o:calico_xdp_main` | 170 | 0.783x | 0.609x | 1.133x | 1.193x | 1.512x | 1.377x |
| `calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 173 | 0.972x | 0.775x | 1.107x | 0.994x | 1.371x | 1.371x |
| `calico/from_nat_debug.bpf.o:calico_tc_main` | 324 | 0.923x | 0.697x | 0.987x | 0.962x | 1.185x | 1.363x |
| `calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 196 | 0.803x | 0.612x | 1.097x | 0.788x | 1.482x | 1.302x |
| `calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | 173 | 0.951x | 0.772x | 0.730x | 0.752x | 1.300x | 1.295x |
| `calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag` | 177 | 0.927x | 0.644x | 0.580x | 0.750x | 0.885x | 1.205x |
| `calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict` | 171 | 0.919x | 1.498x | 0.988x | 1.006x | 1.185x | 1.152x |
| `calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | 171 | 0.934x | 0.833x | 0.862x | 0.829x | 1.148x | 1.110x |
| `calico/from_hep_debug.bpf.o:calico_tc_maglev` | 181 | 0.582x | 1.070x | 0.944x | 1.000x | 1.039x | 1.081x |
| `calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | 172 | 0.628x | 0.972x | 1.079x | 1.023x | 0.994x | 1.029x |
| `calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag` | 176 | 0.871x | 1.112x | 0.932x | 0.966x | 0.937x | 1.029x |
| `calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 176 | 0.967x | 0.971x | 0.570x | 1.057x | 0.519x | 1.000x |
| `calico/to_hep_debug.bpf.o:calico_tc_skb_drop` | 173 | 0.739x | 0.901x | 1.000x | 0.794x | 1.190x | 0.995x |
| `calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 170 | 0.711x | 0.977x | 0.665x | 1.107x | 0.640x | 0.983x |
| `calico/from_nat_debug.bpf.o:calico_tc_skb_drop` | 178 | 0.994x | 1.012x | 0.842x | 0.972x | 0.856x | 0.977x |
| `calico/from_hep_debug.bpf.o:calico_tc_main` | 332 | 0.933x | 0.988x | 0.812x | 0.960x | 0.891x | 0.927x |
| `calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies` | 214 | 0.790x | 1.330x | 0.972x | 0.964x | 0.989x | 0.907x |
| `calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 189 | 0.668x | 0.636x | 0.906x | 0.555x | 1.417x | 0.883x |
| `calico/from_wep_debug.bpf.o:calico_tc_skb_drop` | 175 | 0.989x | 0.933x | 0.972x | 0.739x | 1.167x | 0.882x |
| `calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint` | 174 | 0.734x | 1.102x | 0.681x | 0.822x | 0.638x | 0.846x |
| `calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag` | 168 | 0.870x | 0.847x | 0.739x | 0.635x | 0.996x | 0.827x |
| `calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 169 | 0.812x | 1.107x | 1.088x | 0.862x | 0.973x | 0.812x |
| `calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | 171 | 0.881x | 0.972x | 0.581x | 0.886x | 0.591x | 0.809x |
| `calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 195 | 0.694x | 0.971x | 0.936x | 0.768x | 0.843x | 0.782x |
| `calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint` | 176 | 0.786x | 1.006x | 0.476x | 0.857x | 0.476x | 0.768x |
| `calico/from_hep_debug.bpf.o:calico_tc_skb_drop` | 172 | 0.905x | 1.017x | 0.553x | 0.888x | 0.576x | 0.747x |
| `calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 177 | 0.734x | 0.989x | 1.018x | 0.760x | 1.024x | 0.707x |
| `calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat` | 188 | 0.895x | 0.946x | 1.000x | 0.567x | 0.953x | 0.666x |
| `calico/to_wep_debug.bpf.o:calico_tc_main` | 178 | 0.983x | 1.127x | 0.501x | 0.635x | 0.548x | 0.656x |
| `calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 175 | 0.911x | 0.841x | 0.921x | 0.547x | 1.084x | 0.542x |

## Installed Policies

- Installed per-program branch-flip policy files: `38`
- `corpus/policies/calico/from_hep_debug/calico_tc_maglev.policy.yaml`
- `corpus/policies/calico/from_hep_debug/calico_tc_main.policy.yaml`
- `corpus/policies/calico/from_hep_debug/calico_tc_skb_accepted_entrypoint.policy.yaml`
- `corpus/policies/calico/from_hep_debug/calico_tc_skb_drop.policy.yaml`
- `corpus/policies/calico/from_hep_debug/calico_tc_skb_icmp_inner_nat.policy.yaml`
- `corpus/policies/calico/from_hep_debug/calico_tc_skb_ipv4_frag.policy.yaml`
- `corpus/policies/calico/from_hep_debug/calico_tc_skb_new_flow_entrypoint.policy.yaml`
- `corpus/policies/calico/from_hep_debug/calico_tc_skb_send_icmp_replies.policy.yaml`
- `corpus/policies/calico/from_hep_debug/calico_tc_skb_send_tcp_rst.policy.yaml`
- `corpus/policies/calico/from_nat_debug/calico_tc_main.policy.yaml`
- `corpus/policies/calico/from_nat_debug/calico_tc_skb_accepted_entrypoint.policy.yaml`
- `corpus/policies/calico/from_nat_debug/calico_tc_skb_drop.policy.yaml`
- `corpus/policies/calico/from_nat_debug/calico_tc_skb_new_flow_entrypoint.policy.yaml`
- `corpus/policies/calico/from_nat_debug/calico_tc_skb_send_tcp_rst.policy.yaml`
- `corpus/policies/calico/from_wep_debug/calico_tc_main.policy.yaml`
- `corpus/policies/calico/from_wep_debug/calico_tc_skb_drop.policy.yaml`
- `corpus/policies/calico/from_wep_debug/calico_tc_skb_icmp_inner_nat.policy.yaml`
- `corpus/policies/calico/from_wep_debug/calico_tc_skb_ipv4_frag.policy.yaml`
- `corpus/policies/calico/from_wep_debug/calico_tc_skb_new_flow_entrypoint.policy.yaml`
- `corpus/policies/calico/from_wep_debug/calico_tc_skb_send_tcp_rst.policy.yaml`
- `corpus/policies/calico/to_hep_debug/calico_tc_main.policy.yaml`
- `corpus/policies/calico/to_hep_debug/calico_tc_skb_accepted_entrypoint.policy.yaml`
- `corpus/policies/calico/to_hep_debug/calico_tc_skb_drop.policy.yaml`
- `corpus/policies/calico/to_hep_debug/calico_tc_skb_icmp_inner_nat.policy.yaml`
- `corpus/policies/calico/to_hep_debug/calico_tc_skb_ipv4_frag.policy.yaml`
- `corpus/policies/calico/to_hep_debug/calico_tc_skb_new_flow_entrypoint.policy.yaml`
- `corpus/policies/calico/to_nat_debug/calico_tc_host_ct_conflict.policy.yaml`
- `corpus/policies/calico/to_nat_debug/calico_tc_skb_drop.policy.yaml`
- `corpus/policies/calico/to_nat_debug/calico_tc_skb_ipv4_frag.policy.yaml`
- `corpus/policies/calico/to_nat_debug/calico_tc_skb_new_flow_entrypoint.policy.yaml`
- `corpus/policies/calico/to_nat_debug/calico_tc_skb_send_icmp_replies.policy.yaml`
- `corpus/policies/calico/to_nat_debug/calico_tc_skb_send_tcp_rst.policy.yaml`
- `corpus/policies/calico/to_wep_debug/calico_tc_main.policy.yaml`
- `corpus/policies/calico/to_wep_debug/calico_tc_skb_drop.policy.yaml`
- `corpus/policies/calico/to_wep_debug/calico_tc_skb_icmp_inner_nat.policy.yaml`
- `corpus/policies/calico/to_wep_debug/calico_tc_skb_new_flow_entrypoint.policy.yaml`
- `corpus/policies/calico/to_wep_debug/calico_tc_skb_send_tcp_rst.policy.yaml`
- `corpus/policies/calico/xdp_debug/calico_xdp_main.policy.yaml`
