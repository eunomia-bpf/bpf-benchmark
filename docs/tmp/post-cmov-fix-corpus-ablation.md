# Post-CMOV-Fix Corpus Ablation

- Generated: 2026-03-12T23:19:19.850845+00:00
- Source inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Eligible runnable CMOV pool: 84 programs across 7 sources
- Full sample size: 45
- Smoke sample size: 10
- Kernel image: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage`

## Sample Selection

The sample is restricted to loadable `packet_test_run` programs whose existing v3 policy comments report at least one CMOV site. This excludes non-runnable corpus projects such as Tetragon/Cilium from the VM timing run, even if they have CMOV-bearing policies.

| Source | Selected | CMOV Sites |
| --- | --- | --- |
| calico | 15 | 225 |
| katran | 2 | 9 |
| linux-selftests | 15 | 25 |
| suricata | 2 | 3 |
| tracee | 2 | 26 |
| xdp-tools | 3 | 3 |
| xdp-tutorial | 6 | 10 |

## Full Run

- Group A (with CMOV) exec geomean vs stock: 0.859x
- Group B (without CMOV) exec geomean vs stock: 0.947x
- Normalized Group A / Group B geomean: 0.906x
- Direct Group B / Group A exec geomean: 0.944x
- Baseline drift geomean (Group B / Group A): 1.041x
- Paired programs: 45
- Measured programs: 42
- Wins for Group A: 21
- Regressions for Group A: 20
- Ties: 1
- Conclusion: `cmov-net-negative`

## By Source

| Source | Programs | CMOV Sites | A/B Normalized | A Wins | A Regressions |
| --- | --- | --- | --- | --- | --- |
| calico | 15 | 225 | 1.056x | 9 | 6 |
| katran | 2 | 9 | 0.342x | 0 | 2 |
| linux-selftests | 15 | 25 | 1.029x | 8 | 5 |
| suricata | 2 | 3 | 0.871x | 0 | 1 |
| tracee | 2 | 26 | 0.802x | 0 | 1 |
| xdp-tools | 3 | 3 | 0.439x | 1 | 2 |
| xdp-tutorial | 6 | 10 | 0.982x | 3 | 3 |

## Largest Group-A Wins

| Program | Source | CMOV Sites | A/B Normalized | Patterns |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp-tools | 1 | 1.910x | cond-select-64=1 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | 8 | 1.706x | cond-select-64=8 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | 2 | 1.659x | cond-select-64=2 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | 3 | 1.556x | cond-select-64=3 |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | 3 | 1.556x | cond-select-64=3 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | 17 | 1.350x | cond-select-64=17 |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | linux-selftests | 1 | 1.312x | cond-select-64=1 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | calico | 18 | 1.296x | cond-select-64=18 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | calico | 10 | 1.253x | cond-select-64=10 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | linux-selftests | 1 | 1.250x | cond-select-64=1 |

## Largest Group-A Regressions

| Program | Source | CMOV Sites | A/B Normalized | Patterns |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp-tools | 1 | 0.133x | cond-select-64=1 |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | 8 | 0.187x | cond-select-64=8 |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | 1 | 0.333x | cond-select-64=1 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | linux-selftests | 1 | 0.479x | cond-select-64=1 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp-tutorial | 2 | 0.520x | cond-select-64=2 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | linux-selftests | 2 | 0.538x | cond-select-64=2 |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | katran | 1 | 0.625x | cond-select-64=1 |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | tracee | 13 | 0.643x | cond-select-64=13 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | calico | 17 | 0.714x | cond-select-64=17 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | calico | 7 | 0.728x | cond-select-64=7 |

## CMOV Pattern-Kind Association

| Pattern Kind | Programs | CMOV Sites | A/B Normalized | A Wins | A Regressions |
| --- | --- | --- | --- | --- | --- |
| cond-select-64 | 42 | 297 | 0.906x | 21 | 20 |

The pattern-kind table is correlational rather than causal: a program can contain multiple CMOV sites and other non-CMOV directives, and the kernel may fail-close some requested CMOV sites back to stock emission.

