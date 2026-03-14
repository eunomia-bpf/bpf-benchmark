# Production Corpus v5 Results

- Generated: 2026-03-10T22:34:54.307568+00:00
- Repo root: `/home/yunwei37/workspace/bpf-benchmark`
- Kernel release: `7.0.0-rc2-g1572a4ddb52b-dirty`
- Kernel tree: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux`
- Kernel branch: ``
- Kernel commit: ``
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- BTF candidates: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/vmlinux`
- Repeat: 100

## Summary

| Metric | Value |
| --- | --- |
| Objects attempted | 13 |
| Objects discovered via libbpf | 13 |
| Objects with discovery failures | 0 |
| Programs attempted | 79 |
| Perf-capable targets | 61 |
| Compile-only targets | 18 |
| Baseline compile successes | 60 |
| v5 compile successes | 60 |
| Scanner successes | 60 |
| Programs with framework-detected sites | 45 |
| Programs with recompile applied | 45 |
| Programs with recompile syscall failures | 0 |
| Compile-only size pairs | 60 |
| Measured runtime pairs | 60 |
| Speedup geomean | 1.024x |
| Speedup median | 1.031x |
| Speedup min | 0.489x |
| Speedup max | 1.842x |
| Code-size ratio geomean (baseline/v5) | 1.001x |
| Code-size median delta | +0.0% |
| Code-size min delta | -4.4% |
| Code-size max delta | +0.7% |
| Framework CMOV sites | 197 |
| Framework WIDE sites | 108 |
| Framework ROTATE sites | 10 |
| Framework LEA sites | 0 |

## Objects

| Object | Source | Discovery | Discovered Programs | Tested Programs | Compile Successes | Measured | Note |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o | calico | yes | 9 | 9 | 9 | 9 |  |
| corpus/build/calico/from_nat_debug.bpf.o | calico | yes | 8 | 8 | 8 | 8 |  |
| corpus/build/calico/from_wep_debug.bpf.o | calico | yes | 8 | 8 | 8 | 8 |  |
| corpus/build/calico/to_hep_debug.bpf.o | calico | yes | 9 | 9 | 9 | 9 |  |
| corpus/build/calico/to_nat_debug.bpf.o | calico | yes | 9 | 9 | 9 | 9 |  |
| corpus/build/calico/to_wep_debug.bpf.o | calico | yes | 8 | 8 | 8 | 8 |  |
| corpus/build/calico/xdp_debug.bpf.o | calico | yes | 4 | 4 | 4 | 4 |  |
| corpus/build/calico/xdp_no_log.bpf.o | calico | yes | 4 | 4 | 4 | 4 |  |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o | loxilb | yes | 8 | 8 | 0 | 0 |  |
| corpus/build/loxilb/llb_ebpf_main.bpf.o | loxilb | yes | 8 | 8 | 0 | 0 |  |
| corpus/build/loxilb/llb_xdp_main.bpf.o | loxilb | yes | 2 | 2 | 0 | 0 |  |
| corpus/build/suricata/xdp_filter.bpf.o | suricata | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/suricata/xdp_lb.bpf.o | suricata | yes | 1 | 1 | 0 | 0 |  |

## Per-Program Results

| Program | Section | Perf-capable | Baseline Load | v5 Load | CMOV | WIDE | ROTATE | LEA | Applied | Baseline JIT Bytes | v5 JIT Bytes | Code Delta | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | tc | yes | yes | yes | 0 | 0 | 10 | 0 | yes | 3267 | 3124 | -4.4% |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | tc | yes | yes | yes | 11 | 12 | 0 | 0 | yes | 46216 | 46113 | -0.2% |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | yes | yes | yes | 6 | 0 | 0 | 0 | yes | 20985 | 21008 | +0.1% |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 2419 | 2419 | +0.0% |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | yes | yes | yes | 5 | 2 | 0 | 0 | yes | 18459 | 18454 | -0.0% |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | yes | yes | yes | 1 | 0 | 0 | 0 | yes | 904 | 910 | +0.7% |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | yes | yes | yes | 8 | 0 | 0 | 0 | yes | 23553 | 23566 | +0.1% |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | yes | yes | yes | 2 | 2 | 0 | 0 | yes | 11905 | 11889 | -0.1% |  |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | yes | yes | yes | 1 | 2 | 0 | 0 | yes | 10995 | 10977 | -0.2% |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | tc | yes | yes | yes | 8 | 8 | 0 | 0 | yes | 33230 | 33157 | -0.2% |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | yes | yes | yes | 7 | 0 | 0 | 0 | yes | 18958 | 18980 | +0.1% |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 2419 | 2419 | +0.0% |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | yes | yes | yes | 5 | 2 | 0 | 0 | yes | 16649 | 16650 | +0.0% |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | yes | yes | yes | 1 | 0 | 0 | 0 | yes | 904 | 910 | +0.7% |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | yes | yes | yes | 7 | 0 | 0 | 0 | yes | 21257 | 21277 | +0.1% |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | yes | yes | yes | 2 | 2 | 0 | 0 | yes | 12021 | 12005 | -0.1% |  |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | yes | yes | yes | 1 | 2 | 0 | 0 | yes | 11114 | 11096 | -0.2% |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | tc | yes | yes | yes | 8 | 8 | 0 | 0 | yes | 36713 | 36647 | -0.2% |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | yes | yes | yes | 5 | 0 | 0 | 0 | yes | 22205 | 22227 | +0.1% |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 1738 | 1738 | +0.0% |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | yes | yes | yes | 4 | 2 | 0 | 0 | yes | 18069 | 18060 | -0.0% |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 908 | 908 | +0.0% |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | yes | yes | yes | 3 | 0 | 0 | 0 | yes | 18696 | 18704 | +0.0% |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | yes | yes | yes | 2 | 2 | 0 | 0 | yes | 11780 | 11762 | -0.2% |  |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | yes | yes | yes | 1 | 2 | 0 | 0 | yes | 11016 | 10995 | -0.2% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | tc | yes | yes | yes | 6 | 4 | 0 | 0 | yes | 22249 | 22226 | -0.1% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | tc | yes | yes | yes | 8 | 10 | 0 | 0 | yes | 42812 | 42714 | -0.2% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | yes | yes | yes | 7 | 0 | 0 | 0 | yes | 21900 | 21925 | +0.1% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 2412 | 2412 | +0.0% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | yes | yes | yes | 6 | 2 | 0 | 0 | yes | 18811 | 18813 | +0.0% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 910 | 910 | +0.0% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | yes | yes | yes | 8 | 0 | 0 | 0 | yes | 22613 | 22630 | +0.1% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | yes | yes | yes | 3 | 2 | 0 | 0 | yes | 11471 | 11454 | -0.1% |  |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | yes | yes | yes | 2 | 2 | 0 | 0 | yes | 10496 | 10477 | -0.2% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | tc | yes | yes | yes | 6 | 4 | 0 | 0 | yes | 22131 | 22108 | -0.1% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | tc | yes | yes | yes | 8 | 10 | 0 | 0 | yes | 42727 | 42633 | -0.2% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | yes | yes | yes | 7 | 0 | 0 | 0 | yes | 21777 | 21802 | +0.1% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 2412 | 2412 | +0.0% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | yes | yes | yes | 6 | 2 | 0 | 0 | yes | 18678 | 18680 | +0.0% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 910 | 910 | +0.0% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | yes | yes | yes | 8 | 0 | 0 | 0 | yes | 21952 | 21969 | +0.1% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | yes | yes | yes | 3 | 2 | 0 | 0 | yes | 11471 | 11454 | -0.1% |  |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | yes | yes | yes | 2 | 2 | 0 | 0 | yes | 10496 | 10477 | -0.2% |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | tc | yes | yes | yes | 9 | 10 | 0 | 0 | yes | 30369 | 30282 | -0.3% |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | yes | yes | yes | 4 | 0 | 0 | 0 | yes | 13959 | 13976 | +0.1% |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 1741 | 1741 | +0.0% |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | yes | yes | yes | 6 | 2 | 0 | 0 | yes | 12417 | 12409 | -0.1% |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | yes | yes | yes | 1 | 0 | 0 | 0 | yes | 906 | 912 | +0.7% |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | yes | yes | yes | 3 | 0 | 0 | 0 | yes | 15711 | 15725 | +0.1% |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | yes | yes | yes | 3 | 2 | 0 | 0 | yes | 8039 | 8026 | -0.2% |  |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | yes | yes | yes | 2 | 2 | 0 | 0 | yes | 7265 | 7249 | -0.2% |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 837 | 837 | +0.0% |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 1041 | 1041 | +0.0% |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | xdp | yes | yes | yes | 0 | 4 | 0 | 0 | yes | 4443 | 4395 | -1.1% |  |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 125 | 125 | +0.0% |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 277 | 277 | +0.0% |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 280 | 280 | +0.0% |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | xdp | yes | yes | yes | 0 | 2 | 0 | 0 | yes | 1829 | 1801 | -1.5% |  |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 31 | 31 | +0.0% |  |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_csum_func1 | tc_packet_hook4 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_csum_func2 | tc_packet_hook5 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func | tc_packet_hook1 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func_fast | tc_packet_hook0 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func_fw | tc_packet_hook3 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func_masq | tc_packet_hook7 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func_slow | tc_packet_hook2 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_slow_unp_func | tc_packet_hook6 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_csum_func1 | tc_packet_hook4 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_csum_func2 | tc_packet_hook5 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func | tc_packet_hook1 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func_fast | tc_packet_hook0 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func_fw | tc_packet_hook3 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func_masq | tc_packet_hook7 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func_slow | tc_packet_hook2 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_slow_unp_func | tc_packet_hook6 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_xdp_main.bpf.o:xdp_packet_func | xdp_packet_hook | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_xdp_main.bpf.o:xdp_pass_func | xdp_pass | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | yes | 1645 | 1651 | +0.4% |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |

## Runtime Comparison

| Program | Section | Baseline ns | v5 ns | Speedup | Baseline JIT Bytes | v5 JIT Bytes |
| --- | --- | --- | --- | --- | --- | --- |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | tc | 344 | 279 | 1.233x | 3267 | 3124 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | tc | 417 | 453 | 0.921x | 46216 | 46113 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | 226 | 379 | 0.596x | 20985 | 21008 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_drop | tc | 238 | 212 | 1.123x | 2419 | 2419 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | 247 | 338 | 0.731x | 18459 | 18454 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | 342 | 268 | 1.276x | 904 | 910 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | 337 | 327 | 1.031x | 23553 | 23566 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | 290 | 211 | 1.374x | 11905 | 11889 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | 332 | 224 | 1.482x | 10995 | 10977 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | tc | 621 | 358 | 1.735x | 33230 | 33157 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | 333 | 207 | 1.609x | 18958 | 18980 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_drop | tc | 237 | 217 | 1.092x | 2419 | 2419 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | 233 | 208 | 1.120x | 16649 | 16650 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | 222 | 224 | 0.991x | 904 | 910 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | 217 | 336 | 0.646x | 21257 | 21277 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | 209 | 209 | 1.000x | 12021 | 12005 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | 201 | 298 | 0.674x | 11114 | 11096 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | tc | 341 | 258 | 1.322x | 36713 | 36647 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | 271 | 217 | 1.249x | 22205 | 22227 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_drop | tc | 208 | 379 | 0.549x | 1738 | 1738 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | 212 | 207 | 1.024x | 18069 | 18060 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | 217 | 341 | 0.636x | 908 | 908 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | 385 | 209 | 1.842x | 18696 | 18704 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | 268 | 212 | 1.264x | 11780 | 11762 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | 215 | 336 | 0.640x | 11016 | 10995 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | tc | 266 | 259 | 1.027x | 22249 | 22226 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | tc | 211 | 374 | 0.564x | 42812 | 42714 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | 338 | 338 | 1.000x | 21900 | 21925 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_drop | tc | 214 | 332 | 0.645x | 2412 | 2412 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | 203 | 211 | 0.962x | 18811 | 18813 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | 216 | 222 | 0.973x | 910 | 910 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | 215 | 257 | 0.837x | 22613 | 22630 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | 323 | 216 | 1.495x | 11471 | 11454 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | 228 | 221 | 1.032x | 10496 | 10477 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | tc | 259 | 268 | 0.966x | 22131 | 22108 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | tc | 413 | 348 | 1.187x | 42727 | 42633 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | 260 | 301 | 0.864x | 21777 | 21802 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_drop | tc | 208 | 249 | 0.835x | 2412 | 2412 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | 212 | 235 | 0.902x | 18678 | 18680 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | 218 | 327 | 0.667x | 910 | 910 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | 369 | 209 | 1.766x | 21952 | 21969 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | 263 | 213 | 1.235x | 11471 | 11454 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | 388 | 222 | 1.748x | 10496 | 10477 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | tc | 327 | 278 | 1.176x | 30369 | 30282 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | tc | 337 | 342 | 0.985x | 13959 | 13976 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_drop | tc | 219 | 448 | 0.489x | 1741 | 1741 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | tc | 376 | 318 | 1.182x | 12417 | 12409 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | tc | 265 | 247 | 1.073x | 906 | 912 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | tc | 342 | 214 | 1.598x | 15711 | 15725 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | tc | 403 | 300 | 1.343x | 8039 | 8026 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | tc | 334 | 239 | 1.397x | 7265 | 7249 |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_accepted_entrypoint | xdp | 249 | 254 | 0.980x | 837 | 837 |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_drop | xdp | 435 | 444 | 0.980x | 1041 | 1041 |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | xdp | 251 | 207 | 1.213x | 4443 | 4395 |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_norm_pol_tail | xdp | 257 | 221 | 1.163x | 125 | 125 |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_accepted_entrypoint | xdp | 23 | 22 | 1.045x | 277 | 277 |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_drop | xdp | 24 | 18 | 1.333x | 280 | 280 |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | xdp | 18 | 28 | 0.643x | 1829 | 1801 |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_norm_pol_tail | xdp | 9 | 11 | 0.818x | 31 | 31 |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | xdp | 12 | 10 | 1.200x | 1645 | 1651 |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Invalid argument (exit=1) | 18 |
| bpf_object__load failed: Argument list too long (exit=1) | 1 |

## Notes

- These results were collected inside the guest booted from `vendor/linux`.
- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.
- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `vendor/linux/vmlinux` only for BTF/CO-RE-looking failures.
- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.
- The three `loxilb` objects enumerate cleanly, but all baseline loads fail in libbpf because section names like `tc_packet_hook*`, `xdp_packet_hook`, and `xdp_pass` do not map to known program types in the current loader path. That prevents scanner and v5 recompile measurement for the 863-site TC targets.
- `corpus/build/suricata/xdp_lb.bpf.o` never reached recompile: baseline `bpf_object__load()` failed with `Argument list too long` inside the guest.
