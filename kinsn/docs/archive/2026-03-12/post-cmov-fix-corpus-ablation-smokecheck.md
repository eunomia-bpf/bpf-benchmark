# Post-CMOV-Fix Corpus Ablation

- Generated: 2026-03-12T23:16:08.709631+00:00
- Source inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Eligible runnable CMOV pool: 84 programs across 7 sources
- Full sample size: 10
- Smoke sample size: 10
- Kernel image: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage`

## Sample Selection

The sample is restricted to loadable `packet_test_run` programs whose existing v3 policy comments report at least one CMOV site. This excludes non-runnable corpus projects such as Tetragon/Cilium from the VM timing run, even if they have CMOV-bearing policies.

| Source | Selected | CMOV Sites |
| --- | --- | --- |
| calico | 2 | 41 |
| katran | 1 | 8 |
| linux-selftests | 2 | 6 |
| suricata | 1 | 2 |
| tracee | 1 | 13 |
| xdp-tools | 1 | 1 |
| xdp-tutorial | 2 | 4 |

## Full Run

- Group A (with CMOV) exec geomean vs stock: 0.892x
- Group B (without CMOV) exec geomean vs stock: 0.889x
- Normalized Group A / Group B geomean: 1.003x
- Direct Group B / Group A exec geomean: 0.912x
- Baseline drift geomean (Group B / Group A): 0.909x
- Compared programs: 10
- Wins for Group A: 4
- Regressions for Group A: 5
- Ties: 0
- Conclusion: `cmov-net-positive`

## By Source

| Source | Programs | CMOV Sites | A/B Normalized | A Wins | A Regressions |
| --- | --- | --- | --- | --- | --- |
| calico | 2 | 41 | 1.034x | 1 | 1 |
| katran | 1 | 8 | 0.774x | 0 | 1 |
| linux-selftests | 2 | 6 | 0.984x | 1 | 1 |
| suricata | 1 | 2 | n/a | 0 | 0 |
| tracee | 1 | 13 | 1.250x | 1 | 0 |
| xdp-tools | 1 | 1 | 0.876x | 0 | 1 |
| xdp-tutorial | 2 | 4 | 1.083x | 1 | 1 |

## Largest Group-A Wins

| Program | Source | CMOV Sites | A/B Normalized | Patterns |
| --- | --- | --- | --- | --- |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp-tutorial | 2 | 1.351x | cond-select-64=2 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | calico | 21 | 1.316x | cond-select-64=21 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | 3 | 1.267x | cond-select-64=3 |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | tracee | 13 | 1.250x | cond-select-64=13 |

## Largest Group-A Regressions

| Program | Source | CMOV Sites | A/B Normalized | Patterns |
| --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | linux-selftests | 3 | 0.765x | cond-select-64=3 |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | katran | 8 | 0.774x | cond-select-64=8 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | calico | 20 | 0.812x | cond-select-64=20 |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp-tutorial | 2 | 0.869x | cond-select-64=2 |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp-tools | 1 | 0.876x | cond-select-64=1 |

## CMOV Pattern-Kind Association

| Pattern Kind | Programs | CMOV Sites | A/B Normalized | A Wins | A Regressions |
| --- | --- | --- | --- | --- | --- |
| cond-select-64 | 9 | 73 | 1.003x | 4 | 5 |

The pattern-kind table is correlational rather than causal: a program can contain multiple CMOV sites and other non-CMOV directives, and the kernel may fail-close some requested CMOV sites back to stock emission.
