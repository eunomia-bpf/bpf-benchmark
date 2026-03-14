# Corpus Runnability Report

- Generated: 2026-03-11T04:32:34.931342+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Corpus root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Packet repeat: 200
- Tracing repeat: 10
- Recompile mode: `v5`
- BPF objects scanned: 532
- Programs discovered: 1836
- Loadable programs: 1214
- Programs with directive sites: 274
- Packet-test-run candidates: 304
- Packet baseline-runnable programs: 166
- Packet paired baseline/recompile programs: 79
- Tracing attach+trigger candidates: 1007
- Tracing programs with positive run_cnt delta: 215
- Truly runnable programs: 381
- Truly runnable objects: 145
- Packet speedup geomean: 0.970x

## Strategy Summary

| Strategy | Programs |
| --- | --- |
| cgroup_custom_harness | 40 |
| iterator_custom_harness | 49 |
| kernel_registration_required | 58 |
| load_only_other | 44 |
| lsm_custom_harness | 67 |
| netfilter_custom_harness | 9 |
| packet_test_run | 304 |
| perf_event_custom | 21 |
| socket_custom_harness | 15 |
| synthetic_syscall_only | 74 |
| tracing_attach_trigger | 1007 |
| user_tracing_custom_target | 148 |

## Directive Totals

| Metric | Value |
| --- | --- |
| CMOV sites | 840 |
| WIDE sites | 389 |
| ROTATE sites | 1840 |
| LEA sites | 0 |
| Tracing avg ns/run min | 29.99 |
| Tracing avg ns/run max | 338334.50 |

## By Program Type

| Prog Type | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | Primary Strategy |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| kprobe | 78 | 508 | 405 | 115 | 0 | 0 | 52 | tracing_attach_trigger |
| tracing | 156 | 442 | 241 | 17 | 0 | 0 | 67 | tracing_attach_trigger |
| sched_cls | 53 | 185 | 109 | 61 | 109 | 61 | 0 | packet_test_run |
| tracepoint | 42 | 151 | 130 | 16 | 0 | 0 | 56 | tracing_attach_trigger |
| raw_tracepoint | 43 | 103 | 78 | 23 | 0 | 0 | 40 | tracing_attach_trigger |
| xdp | 39 | 91 | 45 | 16 | 45 | 16 | 0 | packet_test_run |
| lsm | 29 | 75 | 49 | 13 | 0 | 0 | 0 | lsm_custom_harness |
| syscall | 23 | 74 | 49 | 1 | 0 | 0 | 0 | synthetic_syscall_only |
| struct_ops | 13 | 51 | 35 | 5 | 0 | 0 | 0 | kernel_registration_required |
| unspec | 16 | 45 | 0 | 0 | 0 | 0 | 0 | load_only_other |
| perf_event | 17 | 21 | 19 | 1 | 0 | 0 | 0 | perf_event_custom |
| cgroup_sockopt | 6 | 14 | 11 | 0 | 0 | 0 | 0 | cgroup_custom_harness |
| cgroup_sock_addr | 5 | 12 | 6 | 0 | 0 | 0 | 0 | cgroup_custom_harness |
| sock_ops | 9 | 12 | 7 | 1 | 0 | 0 | 0 | socket_custom_harness |
| socket_filter | 4 | 10 | 7 | 0 | 7 | 0 | 0 | packet_test_run |
| netfilter | 4 | 9 | 3 | 0 | 0 | 0 | 0 | netfilter_custom_harness |
| cgroup_skb | 5 | 7 | 5 | 2 | 5 | 2 | 0 | packet_test_run |
| ext | 4 | 7 | 0 | 0 | 0 | 0 | 0 | kernel_registration_required |
| cgroup_sock | 2 | 5 | 3 | 0 | 0 | 0 | 0 | cgroup_custom_harness |
| sk_msg | 3 | 5 | 5 | 3 | 0 | 0 | 0 | packet_test_run |
| sk_skb | 5 | 5 | 5 | 0 | 0 | 0 | 0 | packet_test_run |
| cgroup_sysctl | 1 | 1 | 1 | 0 | 0 | 0 | 0 | cgroup_custom_harness |
| flow_dissector | 1 | 1 | 0 | 0 | 0 | 0 | 0 | packet_test_run |
| sk_lookup | 1 | 1 | 1 | 0 | 0 | 0 | 0 | socket_custom_harness |
| sk_reuseport | 1 | 1 | 0 | 0 | 0 | 0 | 0 | socket_custom_harness |

## By Source

| Source | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 275 | 878 | 552 | 53 | 71 | 20 | 57 | 128 |
| bcc | 57 | 365 | 289 | 30 | 0 | 0 | 91 | 91 |
| calico | 8 | 59 | 59 | 44 | 59 | 44 | 0 | 59 |
| tracee | 2 | 170 | 170 | 110 | 2 | 2 | 24 | 26 |
| xdp-tutorial | 25 | 51 | 29 | 10 | 20 | 6 | 0 | 20 |
| coroot-node-agent | 1 | 46 | 46 | 16 | 0 | 0 | 16 | 16 |
| real_world_code_size | 15 | 24 | 23 | 0 | 2 | 0 | 12 | 14 |
| libbpf-bootstrap | 12 | 21 | 20 | 0 | 1 | 0 | 11 | 12 |
| katran | 5 | 5 | 5 | 2 | 5 | 2 | 0 | 5 |
| xdp-tools | 13 | 99 | 5 | 3 | 4 | 3 | 0 | 4 |
| manual-test | 2 | 4 | 4 | 0 | 0 | 0 | 4 | 4 |
| suricata | 2 | 2 | 2 | 2 | 2 | 2 | 0 | 2 |
| systemd | 6 | 14 | 9 | 4 | 0 | 0 | 0 | 0 |
| KubeArmor | 3 | 63 | 0 | 0 | 0 | 0 | 0 | 0 |
| datadog-agent | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| loxilb | 3 | 18 | 0 | 0 | 0 | 0 | 0 | 0 |
| tetragon | 2 | 15 | 0 | 0 | 0 | 0 | 0 | 0 |
| tubular | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |

## Object Inventory

| Object | Source | Programs | Loadable | Site Programs | Sites | Packet Candidates | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable | Top Strategies |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o | linux-selftests | 19 | 19 | 9 | 9 | 19 | 19 | 9 | 0 | yes | packet_test_run |
| corpus/build/calico/from_hep_debug.bpf.o | calico | 9 | 9 | 8 | 62 | 9 | 9 | 8 | 0 | yes | packet_test_run |
| corpus/build/calico/to_hep_debug.bpf.o | calico | 9 | 9 | 7 | 60 | 9 | 9 | 7 | 0 | yes | packet_test_run |
| corpus/build/calico/to_nat_debug.bpf.o | calico | 9 | 9 | 7 | 60 | 9 | 9 | 7 | 0 | yes | packet_test_run |
| corpus/build/calico/from_nat_debug.bpf.o | calico | 8 | 8 | 7 | 45 | 8 | 8 | 7 | 0 | yes | packet_test_run |
| corpus/build/calico/to_wep_debug.bpf.o | calico | 8 | 8 | 7 | 44 | 8 | 8 | 7 | 0 | yes | packet_test_run |
| corpus/build/calico/from_wep_debug.bpf.o | calico | 8 | 8 | 6 | 37 | 8 | 8 | 6 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o | linux-selftests | 18 | 15 | 1 | 1 | 7 | 6 | 0 | 0 | yes | synthetic_syscall_only, packet_test_run, iterator_custom_harness |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o | xdp-tutorial | 5 | 5 | 3 | 6 | 5 | 5 | 3 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o | linux-selftests | 5 | 5 | 0 | 0 | 5 | 5 | 0 | 0 | yes | packet_test_run |
| corpus/build/calico/xdp_debug.bpf.o | calico | 4 | 4 | 1 | 4 | 4 | 4 | 1 | 0 | yes | packet_test_run |
| corpus/build/calico/xdp_no_log.bpf.o | calico | 4 | 4 | 1 | 2 | 4 | 4 | 1 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 4 | 4 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o | linux-selftests | 8 | 4 | 0 | 0 | 7 | 4 | 0 | 0 | yes | packet_test_run, lsm_custom_harness |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o | xdp-tutorial | 3 | 3 | 2 | 3 | 3 | 3 | 2 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o | linux-selftests | 6 | 6 | 0 | 0 | 3 | 3 | 0 | 0 | yes | packet_test_run, user_tracing_custom_target |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o | xdp-tutorial | 3 | 3 | 0 | 0 | 3 | 3 | 0 | 0 | yes | packet_test_run |
| corpus/build/tracee/tracee.bpf.o | tracee | 169 | 169 | 110 | 555 | 2 | 2 | 2 | 24 | yes | tracing_attach_trigger, user_tracing_custom_target, packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o | linux-selftests | 2 | 2 | 2 | 10 | 2 | 2 | 2 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o | linux-selftests | 2 | 2 | 2 | 10 | 2 | 2 | 2 | 0 | yes | packet_test_run |
| corpus/build/xdp-tools/xdp_forward.bpf.o | xdp-tools | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o | linux-selftests | 2 | 2 | 1 | 1 | 2 | 2 | 1 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 3 | 2 | 0 | 0 | yes | packet_test_run, socket_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o | linux-selftests | 12 | 2 | 0 | 0 | 12 | 2 | 0 | 0 | yes | packet_test_run |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o | xdp-tutorial | 2 | 2 | 0 | 0 | 2 | 2 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o | linux-selftests | 5 | 4 | 0 | 0 | 1 | 1 | 0 | 2 | yes | tracing_attach_trigger, cgroup_custom_harness, packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o | linux-selftests | 5 | 5 | 1 | 818 | 1 | 1 | 1 | 1 | yes | tracing_attach_trigger, packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o | linux-selftests | 1 | 1 | 1 | 992 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/katran/balancer.bpf.o | katran | 1 | 1 | 1 | 29 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o | linux-selftests | 1 | 1 | 1 | 2 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/katran/healthchecking.bpf.o | katran | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/suricata/xdp_filter.bpf.o | suricata | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/suricata/xdp_lb.bpf.o | suricata | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o | xdp-tools | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o | xdp-tutorial | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |
| corpus/build/katran/healthchecking_ipip.bpf.o | katran | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/katran/xdp_pktcntr.bpf.o | katran | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/katran/xdp_root.bpf.o | katran | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o | linux-selftests | 30 | 7 | 0 | 0 | 9 | 1 | 0 | 0 | yes | cgroup_custom_harness, packet_test_run, socket_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o | linux-selftests | 2 | 1 | 0 | 0 | 2 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o | real_world_code_size | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o | real_world_code_size | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/xdp-tools/xdpsock.bpf.o | xdp-tools | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o | xdp-tutorial | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o | xdp-tutorial | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o | xdp-tutorial | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o | xdp-tutorial | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o | xdp-tutorial | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o | xdp-tutorial | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/coroot-node-agent/ebpf.bpf.o | coroot-node-agent | 46 | 46 | 16 | 138 | 0 | 0 | 0 | 16 | yes | tracing_attach_trigger, user_tracing_custom_target |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o | bcc | 73 | 73 | 0 | 0 | 0 | 0 | 0 | 9 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o | bcc | 6 | 6 | 2 | 12 | 0 | 0 | 0 | 6 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o | bcc | 6 | 6 | 2 | 12 | 0 | 0 | 0 | 6 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o | bcc | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 6 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o | bcc | 16 | 16 | 0 | 0 | 0 | 0 | 0 | 6 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o | linux-selftests | 5 | 5 | 1 | 1 | 0 | 0 | 0 | 5 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o | bcc | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 5 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o | bcc | 7 | 7 | 0 | 0 | 0 | 0 | 0 | 5 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o | bcc | 7 | 7 | 0 | 0 | 0 | 0 | 0 | 5 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o | linux-selftests | 14 | 14 | 0 | 0 | 0 | 0 | 0 | 5 | yes | tracing_attach_trigger, user_tracing_custom_target, perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o | linux-selftests | 23 | 23 | 0 | 0 | 0 | 0 | 0 | 4 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 4 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o | bcc | 5 | 4 | 2 | 7 | 0 | 0 | 0 | 3 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o | bcc | 5 | 5 | 1 | 1 | 0 | 0 | 0 | 3 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o | bcc | 6 | 3 | 0 | 0 | 0 | 0 | 0 | 3 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o | linux-selftests | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 3 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o | bcc | 4 | 4 | 4 | 16 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o | bcc | 7 | 3 | 2 | 10 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o | bcc | 2 | 2 | 2 | 8 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o | bcc | 7 | 7 | 3 | 3 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o | bcc | 11 | 10 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/execsnoop.bpf.o | bcc | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/hardirqs.bpf.o | bcc | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o | bcc | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o | bcc | 7 | 7 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/softirqs.bpf.o | bcc | 4 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o | bcc | 12 | 12 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/syscount.bpf.o | bcc | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o | bcc | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcptop.bpf.o | bcc | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_tp_btf.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoattach.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoload.bpf.o | linux-selftests | 3 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger, perf_event_custom |
| corpus/build/manual-test/fentry.gen.bpf.o | manual-test | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/manual-test/fentry.tmp.bpf.o | manual-test | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap.bpf.o | real_world_code_size | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap_legacy.bpf.o | real_world_code_size | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/real_world_code_size/libbpf-bootstrap/fentry.bpf.o | real_world_code_size | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/real_world_code_size/libbpf-bootstrap/kprobe.bpf.o | real_world_code_size | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/bitesize.bpf.o | bcc | 1 | 1 | 1 | 4 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o | bcc | 2 | 2 | 2 | 4 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/biopattern.bpf.o | bcc | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcpify.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/exitsnoop.bpf.o | bcc | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcplife.bpf.o | bcc | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/tcpstates.bpf.o | bcc | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/minimal.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bench_local_storage_create.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger, lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o | linux-selftests | 7 | 7 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger, synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_attach_cgroup.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 1 | yes | cgroup_custom_harness, socket_custom_harness, tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_recursion.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern_overflow.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger, perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_success.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netif_receive_skb.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/socket_cookie_prog.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 1 | yes | cgroup_custom_harness, socket_custom_harness, tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map_skip.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_recursion.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_uptr.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_read_macros.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o | linux-selftests | 7 | 7 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_prog_array_init.bpf.o | linux-selftests | 2 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs_unused.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tracepoint.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/timer_start_deadlock.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger, synthetic_syscall_only |
| corpus/build/real_world_code_size/libbpf-bootstrap/ksyscall.bpf.o | real_world_code_size | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/real_world_code_size/libbpf-bootstrap/minimal.bpf.o | real_world_code_size | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/real_world_code_size/libbpf-bootstrap/minimal_legacy.bpf.o | real_world_code_size | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/real_world_code_size/libbpf-bootstrap/minimal_ns.bpf.o | real_world_code_size | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o | bcc | 20 | 10 | 5 | 30 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o | bcc | 4 | 2 | 1 | 6 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/setget_sockopt.bpf.o | linux-selftests | 3 | 3 | 2 | 6 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness, socket_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o | linux-selftests | 7 | 7 | 1 | 4 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o | linux-selftests | 7 | 7 | 2 | 4 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o | linux-selftests | 3 | 2 | 2 | 4 | 0 | 0 | 0 | 0 | no | lsm_custom_harness, tracing_attach_trigger |
| corpus/build/systemd/userns-restrict.bpf.o | systemd | 7 | 7 | 4 | 4 | 0 | 0 | 0 | 0 | no | lsm_custom_harness, tracing_attach_trigger |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o | xdp-tutorial | 8 | 8 | 4 | 4 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_ksym.bpf.o | linux-selftests | 1 | 1 | 1 | 3 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_vmas.bpf.o | linux-selftests | 1 | 1 | 1 | 3 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skmsg_load_helpers.bpf.o | linux-selftests | 4 | 4 | 3 | 3 | 4 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_pid_filter.bpf.o | linux-selftests | 3 | 3 | 3 | 3 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/bcc/libbpf-tools/ksnoop.bpf.o | bcc | 2 | 2 | 2 | 2 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o | linux-selftests | 5 | 5 | 2 | 2 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/token_lsm.bpf.o | linux-selftests | 2 | 2 | 2 | 2 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp.bpf.o | linux-selftests | 7 | 7 | 1 | 1 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_sockmap.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_unix.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_mod_race.bpf.o | linux-selftests | 3 | 3 | 1 | 1 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/get_func_ip_uprobe_test.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o | linux-selftests | 5 | 5 | 1 | 1 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lru_bug.bpf.o | linux-selftests | 2 | 2 | 1 | 1 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_write_sk_pacing.bpf.o | linux-selftests | 4 | 4 | 1 | 1 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kernel_flag.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_perf_skip.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_under_cgroup.bpf.o | linux-selftests | 2 | 2 | 1 | 1 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, lsm_custom_harness |
| corpus/build/KubeArmor/enforcer.bpf.o | KubeArmor | 7 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/KubeArmor/protectproc.bpf.o | KubeArmor | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/KubeArmor/system_monitor.bpf.o | KubeArmor | 55 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/bashreadline.bpf.o | bcc | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o | bcc | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/capable.bpf.o | bcc | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/cpudist.bpf.o | bcc | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/cpufreq.bpf.o | bcc | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, perf_event_custom |
| corpus/build/bcc/libbpf-tools/drsnoop.bpf.o | bcc | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o | bcc | 16 | 8 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/futexctn.bpf.o | bcc | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/gethostlatency.bpf.o | bcc | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/bcc/libbpf-tools/javagc.bpf.o | bcc | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/bcc/libbpf-tools/llcstat.bpf.o | bcc | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/bcc/libbpf-tools/mdflush.bpf.o | bcc | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o | bcc | 32 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target, tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o | bcc | 12 | 12 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o | bcc | 8 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/offcputime.bpf.o | bcc | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/oomkill.bpf.o | bcc | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/profile.bpf.o | bcc | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/bcc/libbpf-tools/runqlen.bpf.o | bcc | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/bcc/libbpf-tools/slabratetop.bpf.o | bcc | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/solisten.bpf.o | bcc | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o | bcc | 8 | 8 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/bcc/libbpf-tools/wakeuptime.bpf.o | bcc | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/datadog-agent/oom-kill-kern.bpf.o | datadog-agent | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/lsm.bpf.o | libbpf-bootstrap | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/libbpf-bootstrap/examples/c/profile.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/libbpf-bootstrap/examples/c/task_iter.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/libbpf-bootstrap/examples/c/uprobe.bpf.o | libbpf-bootstrap | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/libbpf-bootstrap/examples/c/usdt.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/arena_htab.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/arena_htab_asm.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/arena_list.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/async_stack_depth.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp_release.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o | linux-selftests | 13 | 13 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_hashmap_full_update_bench.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_hashmap_lookup.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_array_map.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_hash_map.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_link.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_map.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_percpu_array_map.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_percpu_hash_map.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_sk_storage_helpers.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_sk_storage_map.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_ipv6_route.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_map_elem.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_netlink.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_setsockopt.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_btf.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_file.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_stack.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_tasks.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern1.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern2.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern3.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern4.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern5.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern6.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_vma_offset.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop.bpf.o | linux-selftests | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop_bench.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_syscall_macro.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_tcp_nogpl.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_type_tag.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_type_tag_user.bpf.o | linux-selftests | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cb_refs.bpf.o | linux-selftests | 4 | 0 | 0 | 0 | 4 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_hierarchical_stats.bpf.o | linux-selftests | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_iter.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_mprog.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_preorder.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o | linux-selftests | 13 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_negative.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_sleepable.bpf.o | linux-selftests | 4 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o | linux-selftests | 12 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/dummy_st_ops_fail.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/dummy_st_ops_success.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/exhandler_kern.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/fexit_sleep.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma_fail1.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma_fail2.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_map_elem_write_key.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/freplace_unreliable_prog.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/get_branch_snapshot.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ima.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ip_check_defrag.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | netfilter_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o | linux-selftests | 6 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | tracing_attach_trigger, packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/jeq_infer_not_null_fail.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/jit_probe_mem.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_destructive.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o | linux-selftests | 8 | 0 | 0 | 0 | 6 | 0 | 0 | 0 | no | packet_test_run, synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_race.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o | linux-selftests | 10 | 0 | 0 | 0 | 8 | 0 | 0 | 0 | no | packet_test_run, synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test_subprog.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_implicit_args.bpf.o | linux-selftests | 4 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kprobe_multi_verifier.bpf.o | linux-selftests | 3 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kprobe_write_ctx.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ksym_race.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage_bench.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage_rcu_tasks_trace_bench.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop1.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop2.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop3.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop6.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness, tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup.bpf.o | linux-selftests | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup_nonvoid.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_tailcall.bpf.o | linux-selftests | 3 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o | linux-selftests | 13 | 0 | 0 | 0 | 6 | 0 | 0 | 0 | no | packet_test_run, synthetic_syscall_only, lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o | linux-selftests | 20 | 0 | 0 | 0 | 19 | 0 | 0 | 0 | no | packet_test_run, synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o | linux-selftests | 7 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | tracing_attach_trigger, packet_test_run, synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_percpu_stats.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe.bpf.o | linux-selftests | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe_recursion.bpf.o | linux-selftests | 7 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_tp_recursion.bpf.o | linux-selftests | 5 | 5 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mmap_inner_array.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcp_sock.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | socket_custom_harness, tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcp_sockmap.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 1 | 0 | 0 | 0 | no | socket_custom_harness, packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_acquire.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_failure.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/perf_event_stackmap.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_freplace_prog.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/raw_tp_null.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/raw_tp_null_fail.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/rcu_tasks_trace_gp.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/recursion.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/security_bpf_map.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sk_storage_omem_uncharge.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o | linux-selftests | 9 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog.bpf.o | linux-selftests | 5 | 5 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness, cgroup_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog_fail.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sockopt_qos_to_cc.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_ips.bpf.o | linux-selftests | 5 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization_freplace.bpf.o | linux-selftests | 4 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tailcall_bpf2bpf_fentry.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tailcall_bpf2bpf_fexit.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tailcall_bpf2bpf_hierarchy_fentry.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o | linux-selftests | 20 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage_exit_creds.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_storage_nodeadlock.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_incompl_cong_ops.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o | linux-selftests | 11 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_unsupp_cong_op.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_update.bpf.o | linux-selftests | 5 | 5 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_access_variable_array.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_kprobe_sleepable.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o | linux-selftests | 12 | 12 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target, tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe_manual.bpf.o | linux-selftests | 5 | 5 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target, tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_decl_tag.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_build_id.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_reloc_module.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_custom_sec_handlers.bpf.o | linux-selftests | 6 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other, tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path_check_rdonly_mem.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path_check_types.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_fill_link_info.bpf.o | linux-selftests | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, user_tracing_custom_target, perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func17.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o | linux-selftests | 9 | 9 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_map_resize.bpf.o | linux-selftests | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kfunc_dynptr_param.bpf.o | linux-selftests | 3 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf_null_check.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf_write_check.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_module.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_weak.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_libbpf_get_fd_by_id_opts.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_lookup_and_delete.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_init.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_lookup_percpu_elem.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_netfilter_link_attach.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | netfilter_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_perf_link.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_probe_user.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ptr_untrusted.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness, tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_raw_tp_test_run.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_trace_itself.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skc_to_unix_sock.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_change_tail.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_invalid_update.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | socket_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_progs_query.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_skb_verdict_attach.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs_extable.bpf.o | linux-selftests | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_local_data.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_pt_regs.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tcpbpf_kern.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | socket_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_trace_ext_tracing.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_unpriv_bpf_disabled.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe.bpf.o | linux-selftests | 6 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe_autoattach.bpf.o | linux-selftests | 5 | 5 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_urandom_usdt.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_devmap_tailcall.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/timer_crash.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/trace_printk.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/trace_vprintk.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_failure.bpf.o | linux-selftests | 4 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o | linux-selftests | 13 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct_many_args.bpf.o | linux-selftests | 6 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o | linux-selftests | 7 | 7 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_usdt.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_verifier.bpf.o | linux-selftests | 3 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall_executed.bpf.o | linux-selftests | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uptr_update_failure.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uretprobe_stack.bpf.o | linux-selftests | 7 | 7 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_globals1.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_globals2.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_large.bpf.o | linux-selftests | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o | linux-selftests | 13 | 10 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only, iterator_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_btf_unreliable_prog.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_default_trusted_ptr.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | synthetic_syscall_only |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_jit_inline.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o | linux-selftests | 12 | 9 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger, synthetic_syscall_only, perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o | linux-selftests | 16 | 8 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_netfilter_ctx.bpf.o | linux-selftests | 6 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | netfilter_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_typedef.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_unpriv_perf.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_flowtable.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_hw_metadata.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata2.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | kernel_registration_required |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xfrm_info.bpf.o | linux-selftests | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o | loxilb | 8 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/loxilb/llb_ebpf_main.bpf.o | loxilb | 8 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/loxilb/llb_xdp_main.bpf.o | loxilb | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/real_world_code_size/libbpf-bootstrap/lsm.bpf.o | real_world_code_size | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/real_world_code_size/libbpf-bootstrap/profile.bpf.o | real_world_code_size | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/real_world_code_size/libbpf-bootstrap/task_iter.bpf.o | real_world_code_size | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/real_world_code_size/libbpf-bootstrap/uprobe.bpf.o | real_world_code_size | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/real_world_code_size/libbpf-bootstrap/usdt.bpf.o | real_world_code_size | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/systemd/bind-iface.bpf.o | systemd | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/systemd/restrict-fs.bpf.o | systemd | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/systemd/restrict-ifaces.bpf.o | systemd | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/systemd/socket-bind.bpf.o | systemd | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/systemd/sysctl-monitor.bpf.o | systemd | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | cgroup_custom_harness |
| corpus/build/tetragon/bpf_execve_event.bpf.o | tetragon | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tetragon/bpf_generic_kprobe.bpf.o | tetragon | 12 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/tracee/lsm_check.bpf.o | tracee | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/tubular/inet-kern.bpf.o | tubular | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | socket_custom_harness |
| corpus/build/xdp-tools/xdp_basic.bpf.o | xdp-tools | 15 | 0 | 0 | 0 | 7 | 0 | 0 | 0 | no | tracing_attach_trigger, packet_test_run |
| corpus/build/xdp-tools/xdp_flowtable.bpf.o | xdp-tools | 2 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/xdp-tools/xdp_flowtable_sample.bpf.o | xdp-tools | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/xdp-tools/xdp_monitor.bpf.o | xdp-tools | 8 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o | xdp-tools | 10 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | no | tracing_attach_trigger, packet_test_run |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o | xdp-tools | 20 | 0 | 0 | 0 | 12 | 0 | 0 | 0 | no | packet_test_run, tracing_attach_trigger |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o | xdp-tools | 12 | 0 | 0 | 0 | 4 | 0 | 0 | 0 | no | tracing_attach_trigger, packet_test_run |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o | xdp-tools | 12 | 0 | 0 | 0 | 4 | 0 | 0 | 0 | no | tracing_attach_trigger, packet_test_run |
| corpus/build/xdp-tools/xdp_sample.bpf.o | xdp-tools | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o | xdp-tools | 14 | 0 | 0 | 0 | 6 | 0 | 0 | 0 | no | tracing_attach_trigger, packet_test_run |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail1.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail2.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail3.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern.bpf.o | xdp-tutorial | 5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern2.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern3.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern4.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_02.bpf.o | xdp-tutorial | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_03.bpf.o | xdp-tutorial | 5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/packet-solutions/xdp_vlan01_kern.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/packet-solutions/xdp_vlan02_kern.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | load_only_other |
| corpus/build/xdp-tutorial/packet01-parsing/xdp_prog_kern.bpf.o | xdp-tutorial | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | no | packet_test_run |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/trace_prog_kern.bpf.o | xdp-tutorial | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |

## Packet Paired Measurements

| Program | Type | Section | Baseline ns | Recompile ns | Speedup | Correct | Sites | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | sched_cls | tc | 523 | 553 | 0.946x | match | 992 | 0 | 0 | 992 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | sched_cls | tc | 488 | 486 | 1.004x | match | 818 | 0 | 0 | 818 | 0 |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | cgroup_skb | cgroup_skb/egress | 13 | 9 | 1.444x | match | 110 | 3 | 107 | 0 | 0 |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | cgroup_skb | cgroup_skb/ingress | 8 | 8 | 1.000x | match | 110 | 3 | 107 | 0 | 0 |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | xdp | xdp | 20 | 19 | 1.053x | match | 29 | 5 | 4 | 20 | 0 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main | sched_cls | tc | 201 | 219 | 0.918x | match | 23 | 11 | 12 | 0 | 0 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main | sched_cls | tc | 180 | 133 | 1.353x | match | 19 | 9 | 10 | 0 | 0 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_main | sched_cls | tc | 215 | 212 | 1.014x | match | 18 | 8 | 10 | 0 | 0 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_main | sched_cls | tc | 193 | 231 | 0.835x | match | 18 | 8 | 10 | 0 | 0 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_main | sched_cls | tc | 381 | 351 | 1.085x | match | 16 | 8 | 8 | 0 | 0 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_main | sched_cls | tc | 141 | 206 | 0.684x | match | 16 | 8 | 8 | 0 | 0 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | sched_cls | tc | 190 | 112 | 1.696x | match | 10 | 0 | 0 | 10 | 0 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_host_ct_conflict | sched_cls | tc | 182 | 112 | 1.625x | match | 10 | 6 | 4 | 0 | 0 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_host_ct_conflict | sched_cls | tc | 111 | 153 | 0.725x | match | 10 | 6 | 4 | 0 | 0 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | sched_cls | tc | 179 | 216 | 0.829x | match | 8 | 8 | 0 | 0 | 0 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | sched_cls | tc | 174 | 180 | 0.967x | match | 8 | 6 | 2 | 0 | 0 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | sched_cls | tc | 187 | 118 | 1.585x | match | 8 | 8 | 0 | 0 | 0 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | sched_cls | tc | 112 | 182 | 0.615x | match | 8 | 6 | 2 | 0 | 0 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | sched_cls | tc | 138 | 156 | 0.885x | match | 8 | 8 | 0 | 0 | 0 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | sched_cls | tc | 111 | 183 | 0.607x | match | 8 | 6 | 2 | 0 | 0 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | sched_cls | tc | 126 | 114 | 1.105x | match | 7 | 5 | 2 | 0 | 0 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | sched_cls | tc | 225 | 179 | 1.257x | match | 7 | 7 | 0 | 0 | 0 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_icmp_inner_nat | sched_cls | tc | 184 | 187 | 0.984x | match | 7 | 5 | 2 | 0 | 0 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | sched_cls | tc | 190 | 241 | 0.788x | match | 7 | 7 | 0 | 0 | 0 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | sched_cls | tc | 219 | 232 | 0.944x | match | 7 | 7 | 0 | 0 | 0 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_accepted_entrypoint | sched_cls | tc | 227 | 115 | 1.974x | match | 7 | 7 | 0 | 0 | 0 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | sched_cls | tc | 113 | 189 | 0.598x | match | 6 | 6 | 0 | 0 | 0 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_icmp_inner_nat | sched_cls | tc | 194 | 192 | 1.010x | match | 6 | 4 | 2 | 0 | 0 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | sched_cls | tc | 186 | 143 | 1.301x | match | 5 | 5 | 0 | 0 | 0 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | sched_cls | tc | 112 | 185 | 0.605x | match | 5 | 3 | 2 | 0 | 0 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | sched_cls | tc | 112 | 160 | 0.700x | match | 5 | 3 | 2 | 0 | 0 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | sched_cls | tc | 112 | 190 | 0.589x | match | 5 | 3 | 2 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | sched_cls | tc | 14 | 14 | 1.000x | match | 5 | 2 | 3 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | xdp | xdp | 14 | 22 | 0.636x | match | 5 | 2 | 3 | 0 | 0 |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | sched_cls | tc | 9 | 14 | 0.643x | match | 5 | 2 | 3 | 0 | 0 |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | xdp | xdp | 15 | 15 | 1.000x | match | 5 | 2 | 3 | 0 | 0 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_icmp_replies | sched_cls | tc | 112 | 177 | 0.633x | match | 4 | 2 | 2 | 0 | 0 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_icmp_replies | sched_cls | tc | 113 | 181 | 0.624x | match | 4 | 2 | 2 | 0 | 0 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_icmp_replies | sched_cls | tc | 192 | 182 | 1.055x | match | 4 | 2 | 2 | 0 | 0 |
| corpus/build/calico/to_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | sched_cls | tc | 114 | 191 | 0.597x | match | 4 | 2 | 2 | 0 | 0 |
| corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | sched_cls | tc | 180 | 192 | 0.938x | match | 4 | 2 | 2 | 0 | 0 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_accepted_entrypoint | sched_cls | tc | 158 | 180 | 0.878x | match | 4 | 4 | 0 | 0 | 0 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | sched_cls | tc | 112 | 150 | 0.747x | match | 4 | 2 | 2 | 0 | 0 |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | xdp | xdp | 140 | 140 | 1.000x | match | 4 | 0 | 4 | 0 | 0 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst | sched_cls | tc | 113 | 217 | 0.521x | match | 3 | 1 | 2 | 0 | 0 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst | sched_cls | tc | 218 | 220 | 0.991x | match | 3 | 1 | 2 | 0 | 0 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | sched_cls | tc | 219 | 141 | 1.553x | match | 3 | 3 | 0 | 0 | 0 |
| corpus/build/calico/from_wep_debug.bpf.o:calico_tc_skb_send_tcp_rst | sched_cls | tc | 111 | 166 | 0.669x | match | 3 | 1 | 2 | 0 | 0 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_new_flow_entrypoint | sched_cls | tc | 186 | 182 | 1.022x | match | 3 | 3 | 0 | 0 | 0 |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | xdp | xdp | 18 | 18 | 1.000x | match | 2 | 0 | 2 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | sched_cls | tc | 17 | 8 | 2.125x | match | 2 | 2 | 0 | 0 | 0 |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp | xdp | 8 | 18 | 0.444x | match | 2 | 1 | 1 | 0 | 0 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp | xdp | 21 | 21 | 1.000x | match | 2 | 2 | 0 | 0 | 0 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp | xdp | 21 | 21 | 1.000x | match | 2 | 1 | 1 | 0 | 0 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp | xdp | 38 | 39 | 0.974x | match | 2 | 1 | 1 | 0 | 0 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag | sched_cls | tc | 113 | 193 | 0.585x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/calico/from_nat_debug.bpf.o:calico_tc_skb_ipv4_frag | sched_cls | tc | 176 | 112 | 1.571x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/calico/to_wep_debug.bpf.o:calico_tc_skb_ipv4_frag | sched_cls | tc | 184 | 141 | 1.305x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | sched_cls | tc | 11 | 10 | 1.100x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | sched_cls | tcx/ingress | 8 | 17 | 0.471x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | sched_cls | tc | 49 | 46 | 1.065x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | sched_cls | tc | 21 | 11 | 1.909x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | sched_cls | tc/ingress | 23 | 11 | 2.091x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | sched_cls | tc | 8 | 8 | 1.000x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | sched_cls | tc | 19 | 17 | 1.118x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | sched_cls | tc | 8 | 8 | 1.000x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | sched_cls | tc | 9 | 9 | 1.000x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | sched_cls | tc | 18 | 9 | 2.000x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | sched_cls | tc | 10 | 8 | 1.250x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | sched_cls | tc | 17 | 9 | 1.889x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | sched_cls | tc | 8 | 9 | 0.889x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | sched_cls | tc | 8 | 18 | 0.444x | match | 1 | 0 | 1 | 0 | 0 |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | xdp | xdp | 41 | 16 | 2.562x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | xdp | xdp | 9 | 21 | 0.429x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp | xdp | 22 | 23 | 0.957x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp | xdp | 22 | 10 | 2.200x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp | xdp | 22 | 19 | 1.158x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp | xdp | 23 | 22 | 1.045x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp | xdp | 162 | 326 | 0.497x | match | 1 | 1 | 0 | 0 | 0 |

## Tracing Measurements

| Program | Type | Section | Trigger | Runs | Run Time ns | Avg ns/run | Sites |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/coroot-node-agent/ebpf.bpf.o:inet_sock_set_state | tracepoint | tracepoint/sock/inet_sock_set_state | tcp-loopback | 104 | 11952 | 114.92 | 21 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_exit_read | tracepoint | tracepoint/syscalls/sys_exit_read | generic-syscalls | 21 | 1772 | 84.38 | 9 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_exit_recvfrom | tracepoint | tracepoint/syscalls/sys_exit_recvfrom | generic-syscalls | 2 | 657 | 328.50 | 9 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_sendmsg | tracepoint | tracepoint/syscalls/sys_enter_sendmsg | generic-syscalls | 1 | 1388 | 1388.00 | 7 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_complete | raw_tracepoint | raw_tp/block_rq_complete | disk-io | 50 | 5991 | 119.82 | 6 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_complete_btf | tracing | tp_btf/block_rq_complete | disk-io | 50 | 6631 | 132.62 | 6 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_switch | raw_tracepoint | raw_tp/sched_switch | sched | 693 | 114119 | 164.67 | 6 |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:block_io_done | tracing | tp_btf/block_io_done | disk-io | 41 | 7323 | 178.61 | 6 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_switch | tracing | tp_btf/sched_switch | sched | 558 | 108224 | 193.95 | 6 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_write | tracepoint | tracepoint/syscalls/sys_enter_write | write-devnull | 27 | 6249 | 231.44 | 6 |
| corpus/build/tracee/tracee.bpf.o:vfs_write_magic_return | kprobe | kretprobe/vfs_write | write-devnull | 20 | 5969 | 298.45 | 6 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_sendto | tracepoint | tracepoint/syscalls/sys_enter_sendto | generic-syscalls | 1 | 602 | 602.00 | 6 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:folio_mark_accessed | tracing | fentry/folio_mark_accessed | disk-io | 4453 | 258835 | 58.13 | 5 |
| corpus/build/tracee/tracee.bpf.o:trace_security_file_open | kprobe | kprobe/security_file_open | open-close | 11 | 11695 | 1063.18 | 5 |
| corpus/build/tracee/tracee.bpf.o:trace_security_socket_accept | kprobe | kprobe/security_socket_accept | tcp-loopback | 10 | 13078 | 1307.80 | 5 |
| corpus/build/bcc/libbpf-tools/bitesize.bpf.o:block_rq_issue | tracing | tp_btf/block_rq_issue | disk-io | 40 | 9484 | 237.10 | 4 |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v4_syn_recv | tracing | fentry/tcp_v4_syn_recv_sock | tcp-loopback | 10 | 2396 | 239.60 | 4 |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o:tcp_rcv_kprobe | kprobe | kprobe/tcp_rcv_established | tcp-loopback | 54 | 14074 | 260.63 | 4 |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o:tcp_rcv | tracing | fentry/tcp_rcv_established | tcp-loopback | 44 | 12209 | 277.48 | 4 |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v4_syn_recv_kprobe | kprobe | kprobe/tcp_v4_syn_recv_sock | tcp-loopback | 10 | 3001 | 300.10 | 4 |
| corpus/build/tracee/tracee.bpf.o:tracepoint__sched__sched_process_exec | raw_tracepoint | raw_tracepoint/sched_process_exec | execve | 10 | 73360 | 7336.00 | 4 |
| corpus/build/tracee/tracee.bpf.o:trace_security_socket_setsockopt | kprobe | kprobe/security_socket_setsockopt | tcp-loopback | 5 | 43775 | 8755.00 | 4 |
| corpus/build/tracee/tracee.bpf.o:trace_security_socket_listen | kprobe | kprobe/security_socket_listen | tcp-loopback | 1 | 14814 | 14814.00 | 4 |
| corpus/build/tracee/tracee.bpf.o:trace_security_socket_connect | kprobe | kprobe/security_socket_connect | tcp-loopback | 37 | 98783 | 2669.81 | 3 |
| corpus/build/tracee/tracee.bpf.o:trace_security_socket_bind | kprobe | kprobe/security_socket_bind | tcp-loopback | 1 | 14215 | 14215.00 | 3 |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o:vfs_write_entry | kprobe | kprobe/vfs_write | write-devnull | 12 | 1596 | 133.00 | 2 |
| corpus/build/tracee/tracee.bpf.o:trace_ret_vfs_write | kprobe | kretprobe/vfs_write | write-devnull | 30 | 8786 | 292.87 | 2 |
| corpus/build/tracee/tracee.bpf.o:tracepoint__sched__sched_switch | raw_tracepoint | raw_tracepoint/sched_switch | sched | 1045 | 659031 | 630.65 | 2 |
| corpus/build/tracee/tracee.bpf.o:trace_security_socket_recvmsg | kprobe | kprobe/security_socket_recvmsg | tcp-loopback | 270 | 176465 | 653.57 | 2 |
| corpus/build/tracee/tracee.bpf.o:trace_security_inode_unlink | kprobe | kprobe/security_inode_unlink | unlink | 10 | 12054 | 1205.40 | 2 |
| corpus/build/tracee/tracee.bpf.o:trace_security_socket_sendmsg | kprobe | kprobe/security_socket_sendmsg | tcp-loopback | 95 | 162955 | 1715.32 | 2 |
| corpus/build/tracee/tracee.bpf.o:trace_ret_sock_alloc_file | kprobe | kretprobe/sock_alloc_file | tcp-loopback | 51 | 103376 | 2026.98 | 2 |
| corpus/build/tracee/tracee.bpf.o:trace_security_socket_create | kprobe | kprobe/security_socket_create | tcp-loopback | 39 | 110504 | 2833.44 | 2 |
| corpus/build/tracee/tracee.bpf.o:tracepoint__sched__sched_process_exit | raw_tracepoint | raw_tracepoint/sched_process_exit | execve | 10 | 58983 | 5898.30 | 2 |
| corpus/build/tracee/tracee.bpf.o:trace_security_bprm_check | kprobe | kprobe/security_bprm_check | execve | 10 | 67001 | 6700.10 | 2 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcpify.bpf.o:mptcpify | tracing | fmod_ret/update_socket_protocol | tcp-loopback | 14 | 1623 | 115.93 | 1 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler_exit | tracepoint | tp/syscalls/sys_exit_getpid | generic-syscalls | 122 | 22615 | 185.37 | 1 |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:block_io_done | tracing | tp_btf/block_io_done | disk-io | 40 | 9556 | 238.90 | 1 |
| corpus/build/bcc/libbpf-tools/biopattern.bpf.o:handle__block_rq_complete | tracepoint | tracepoint/block/block_rq_complete | disk-io | 50 | 16790 | 335.80 | 1 |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_merge_bio | kprobe | kprobe/blk_account_io_merge_bio | disk-io | 77 | 40848 | 530.49 | 1 |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:kprobe_folio_account_dirtied | kprobe | kprobe/folio_account_dirtied | disk-io | 266 | 7977 | 29.99 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoattach.bpf.o:prog2 | raw_tracepoint | raw_tp/sys_exit | generic-syscalls | 3321 | 101703 | 30.62 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoload.bpf.o:prog2 | raw_tracepoint | raw_tp/sys_exit | generic-syscalls | 10188 | 312950 | 30.72 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoload.bpf.o:prog1 | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 3547 | 120616 | 34.01 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:fentry_tcp_rcv_state_process | tracing | fentry/tcp_rcv_state_process | tcp-loopback | 50 | 1703 | 34.06 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_recursion.bpf.o:on_enter | tracing | tp_btf/sys_enter | generic-syscalls | 3833 | 131868 | 34.40 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o:entry_probe | kprobe | ksyscall/kill | signal | 10 | 402 | 40.20 | 0 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:filemap_alloc_folio_noprof_ret | tracing | fexit/filemap_alloc_folio_noprof | disk-io | 274 | 11081 | 40.44 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_raw_tp | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 3138 | 128730 | 41.02 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:core_relo_proto | raw_tracepoint | raw_tracepoint/sys_enter | generic-syscalls | 2618 | 109622 | 41.87 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma.bpf.o:handle_getpid | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 3198 | 136880 | 42.80 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_tp_btf.bpf.o:on_enter | tracing | tp_btf/sys_enter | generic-syscalls | 3090 | 133868 | 43.32 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path.bpf.o:prog_stat | tracing | fentry/security_inode_getattr | open-close | 12 | 550 | 45.83 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o:sys_enter | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 2154 | 99701 | 46.29 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink_ret | kprobe | kretprobe/vfs_unlink | unlink | 10 | 492 | 49.20 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:map_val_prog | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 2123 | 107686 | 50.72 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_unlink | tracing | fentry/vfs_unlink | unlink | 10 | 531 | 53.10 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern_overflow.bpf.o:core_relo_proto | raw_tracepoint | raw_tracepoint/sys_enter | generic-syscalls | 896 | 48000 | 53.57 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/ksyscall.bpf.o:entry_probe | kprobe | ksyscall/kill | signal | 11 | 632 | 57.45 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs_unused.bpf.o:main_prog | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 912 | 53158 | 58.29 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/socket_cookie_prog.bpf.o:update_cookie_tracing | tracing | fexit/inet_stream_connect | tcp-loopback | 10 | 594 | 59.40 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler32_signed | tracepoint | tp/raw_syscalls/sys_exit | generic-syscalls | 897 | 53297 | 59.42 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoattach.bpf.o:prog1 | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 859 | 54626 | 63.59 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_write | tracing | fentry/vfs_write | write-devnull | 11 | 701 | 63.73 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage.bpf.o:on_exit | tracing | tp_btf/sys_exit | generic-syscalls | 909 | 58305 | 64.14 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler32_unsigned | tracepoint | tp/raw_syscalls/sys_enter | generic-syscalls | 1025 | 65982 | 64.37 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_prog_array_init.bpf.o:tailcall_1 | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 854 | 55157 | 64.59 | 0 |
| corpus/build/tracee/tracee.bpf.o:vfs_write_magic_enter | kprobe | kprobe/vfs_write | write-devnull | 11 | 733 | 66.64 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_exit_openat | tracepoint | tracepoint/syscalls/sys_exit_openat | open-close | 41 | 2748 | 67.02 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog4 | raw_tracepoint | raw_tp/sys_exit | generic-syscalls | 4406 | 296268 | 67.24 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler64_signed | raw_tracepoint | raw_tp/sys_exit | generic-syscalls | 944 | 64517 | 68.34 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink | kprobe | kprobe/vfs_unlink | unlink | 10 | 688 | 68.80 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_read_macros.bpf.o:handler | raw_tracepoint | raw_tracepoint/sys_enter | generic-syscalls | 935 | 65035 | 69.56 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:rdonly_map_prog | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 1021 | 72029 | 70.55 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/timer_start_deadlock.bpf.o:tp_hrtimer_cancel | tracing | tp_btf/hrtimer_cancel | generic-syscalls | 1164 | 82417 | 70.80 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tracepoint.bpf.o:oncpu | tracepoint | tracepoint/sched/sched_switch | sched | 568 | 40462 | 71.24 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage.bpf.o:on_enter | tracing | tp_btf/sys_enter | generic-syscalls | 839 | 60068 | 71.59 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_attach_cgroup.bpf.o:update_cookie_tracing | tracing | fexit/inet_stream_connect | tcp-loopback | 10 | 728 | 72.80 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_rcv_state_process | kprobe | kprobe/tcp_rcv_state_process | tcp-loopback | 65 | 4873 | 74.97 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_open | tracing | fentry/vfs_open | open-close | 22 | 1654 | 75.18 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_uptr.bpf.o:on_enter | tracing | tp_btf/sys_enter | generic-syscalls | 860 | 65501 | 76.16 | 0 |
| corpus/build/tracee/tracee.bpf.o:tracepoint__raw_syscalls__sys_exit | raw_tracepoint | raw_tracepoint/sys_exit | generic-syscalls | 1355 | 104343 | 77.01 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp_btf | tracing | tp_btf/sys_enter | generic-syscalls | 887 | 68447 | 77.17 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_write | kprobe | kprobe/vfs_write | write-devnull | 11 | 870 | 79.09 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_unlink | kprobe | kprobe/vfs_unlink | unlink | 10 | 791 | 79.10 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler64_unsigned | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 1065 | 85475 | 80.26 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_tp_btf.bpf.o:on_exit | tracing | tp_btf/sys_exit | generic-syscalls | 936 | 76003 | 81.20 | 0 |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newfstat_return | tracepoint | tracepoint/syscalls/sys_exit_newfstat | generic-syscalls | 40 | 3358 | 83.95 | 0 |
| corpus/build/tracee/tracee.bpf.o:tracepoint__raw_syscalls__sys_enter | raw_tracepoint | raw_tracepoint/sys_enter | generic-syscalls | 1057 | 91461 | 86.53 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_success.bpf.o:test_skb_field | tracing | tp_btf/tcp_probe | tcp-loopback | 59 | 5138 | 87.08 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_open | kprobe | kprobe/vfs_open | open-close | 11 | 960 | 87.27 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bench_local_storage_create.bpf.o:kmalloc | raw_tracepoint | raw_tp/kmalloc | generic-syscalls | 469 | 41552 | 88.60 | 0 |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:kill_exit | tracepoint | tracepoint/syscalls/sys_exit_kill | signal | 11 | 984 | 89.45 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/minimal.bpf.o:handle_tp | tracepoint | tp/syscalls/sys_enter_write | write-devnull | 11 | 986 | 89.64 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf.bpf.o:handler | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 878 | 79073 | 90.06 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_recursion.bpf.o:on_enter | tracing | tp_btf/sys_enter | generic-syscalls | 2632 | 239453 | 90.98 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp1 | tracepoint | tp/syscalls/sys_enter_nanosleep | generic-syscalls | 12 | 1158 | 96.50 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_openat | tracepoint | tracepoint/syscalls/sys_enter_openat | open-close | 12 | 1182 | 98.50 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog2 | raw_tracepoint | raw_tp/sys_exit | generic-syscalls | 980 | 116314 | 118.69 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp3 | tracepoint | tp/syscalls/sys_enter_nanosleep | generic-syscalls | 12 | 1430 | 119.17 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_exit_open | tracepoint | tracepoint/syscalls/sys_exit_open | open-close | 4 | 490 | 122.50 | 0 |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:block_rq_complete | tracing | tp_btf/block_rq_complete | disk-io | 50 | 6226 | 124.52 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog1 | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 854 | 107291 | 125.63 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_read | tracepoint | tracepoint/syscalls/sys_enter_read | generic-syscalls | 185 | 23247 | 125.66 | 0 |
| corpus/build/bcc/libbpf-tools/syscount.bpf.o:sys_enter | tracepoint | tracepoint/raw_syscalls/sys_enter | generic-syscalls | 2769 | 356600 | 128.78 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_destroy_sock | tracepoint | tracepoint/tcp/tcp_destroy_sock | tcp-loopback | 21 | 2720 | 129.52 | 0 |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_rcv_space_adjust_btf | tracing | tp_btf/tcp_rcv_space_adjust | tcp-loopback | 20 | 2604 | 130.20 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o:send_signal_tp_sched | tracepoint | tracepoint/sched/sched_switch | sched | 648 | 86231 | 133.07 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:enter_tcp_set_state | kprobe | kprobe/tcp_set_state | tcp-loopback | 91 | 12477 | 137.11 | 0 |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:blk_account_io_merge_bio | kprobe | kprobe/blk_account_io_merge_bio | disk-io | 76 | 11284 | 148.47 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_killable_exit | kprobe | kretprobe/down_read_killable | signal | 20 | 2998 | 149.90 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog3 | raw_tracepoint | raw_tp/sys_enter | generic-syscalls | 949 | 142918 | 150.60 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_read_killable_exit | tracing | fexit/down_read_killable | signal | 12 | 1815 | 151.25 | 0 |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_exit_openat | tracepoint | tracepoint/syscalls/sys_exit_openat | open-close | 12 | 1824 | 152.00 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/minimal.bpf.o:handle_tp | tracepoint | tp/syscalls/sys_enter_write | write-devnull | 35 | 5476 | 156.46 | 0 |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newfstat_entry | tracepoint | tracepoint/syscalls/sys_enter_newfstat | generic-syscalls | 49 | 7866 | 160.53 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_open | kprobe | kprobe/vfs_open | open-close | 11 | 1779 | 161.73 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_close | tracepoint | tracepoint/syscalls/sys_enter_close | generic-syscalls | 68 | 11196 | 164.65 | 0 |
| corpus/build/bcc/libbpf-tools/syscount.bpf.o:sys_exit | tracepoint | tracepoint/raw_syscalls/sys_exit | generic-syscalls | 920 | 151989 | 165.21 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o:send_signal_tp | tracepoint | tracepoint/syscalls/sys_enter_nanosleep | generic-syscalls | 11 | 1913 | 173.91 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/minimal_legacy.bpf.o:handle_tp | tracepoint | tp/syscalls/sys_enter_write | write-devnull | 24 | 4488 | 187.00 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v4_connect_ret | kprobe | kretprobe/tcp_v4_connect | tcp-loopback | 10 | 1884 | 188.40 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_update | tracepoint | tp/syscalls/sys_enter_getpid | generic-syscalls | 119 | 22670 | 190.50 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_exit | kprobe | kretprobe/down_write | write-devnull | 10 | 1949 | 194.90 | 0 |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_enter_openat | tracepoint | tracepoint/syscalls/sys_enter_openat | open-close | 11 | 2172 | 197.45 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:tcp_v4_connect_ret | kprobe | kretprobe/tcp_v4_connect | tcp-loopback | 10 | 1992 | 199.20 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_switch | tracing | tp_btf/sched_switch | sched | 644 | 131726 | 204.54 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_switch | raw_tracepoint | raw_tp/sched_switch | sched | 524 | 114665 | 218.83 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:trace_inet_sock_set_state | tracing | tp_btf/inet_sock_set_state | tcp-loopback | 102 | 22349 | 219.11 | 0 |
| corpus/build/bcc/libbpf-tools/softirqs.bpf.o:softirq_entry_btf | tracing | tp_btf/softirq_entry | generic-syscalls | 130 | 33727 | 259.44 | 0 |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:block_rq_issue | tracing | tp_btf/block_rq_issue | disk-io | 40 | 10827 | 270.68 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_wakeup_new | tracing | tp_btf/sched_wakeup_new | sched | 10 | 2778 | 277.80 | 0 |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_destroy_sock_btf | tracing | tp_btf/tcp_destroy_sock | tcp-loopback | 21 | 5852 | 278.67 | 0 |
| corpus/build/bcc/libbpf-tools/tcpstates.bpf.o:handle_set_state | tracepoint | tracepoint/sock/inet_sock_set_state | tcp-loopback | 102 | 28916 | 283.49 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_issue_btf | tracing | tp_btf/block_rq_issue | disk-io | 40 | 11542 | 288.55 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_wakeup_new | raw_tracepoint | raw_tp/sched_wakeup_new | sched | 10 | 2921 | 292.10 | 0 |
| corpus/build/bcc/libbpf-tools/tcplife.bpf.o:inet_sock_set_state | tracepoint | tracepoint/sock/inet_sock_set_state | tcp-loopback | 102 | 30060 | 294.71 | 0 |
| corpus/build/bcc/libbpf-tools/softirqs.bpf.o:softirq_entry | raw_tracepoint | raw_tp/softirq_entry | generic-syscalls | 211 | 62513 | 296.27 | 0 |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_probe_btf | tracing | tp_btf/tcp_probe | tcp-loopback | 47 | 14293 | 304.11 | 0 |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:kill_entry | tracepoint | tracepoint/syscalls/sys_enter_kill | signal | 10 | 3195 | 319.50 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_wakeup_new | tracing | tp_btf/sched_wakeup_new | sched | 10 | 3211 | 321.10 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:exit_inet_csk_accept | kprobe | kretprobe/inet_csk_accept | tcp-loopback | 10 | 3265 | 326.50 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_get_release | tracing | tp_btf/cgroup_mkdir | generic-syscalls | 1 | 329 | 329.00 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:entry_trace_close | kprobe | kprobe/tcp_close | tcp-loopback | 21 | 7201 | 342.90 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:up_write | tracing | fentry/up_write | write-devnull | 7 | 2444 | 349.14 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_populate | tracing | tp_btf/task_newtask | generic-syscalls | 2 | 707 | 353.50 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:tcp_v4_connect | kprobe | kprobe/tcp_v4_connect | tcp-loopback | 10 | 3635 | 363.50 | 0 |
| corpus/build/tracee/tracee.bpf.o:trace_sock_alloc_file | kprobe | kprobe/sock_alloc_file | tcp-loopback | 22 | 8064 | 366.55 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_wakeup_new | raw_tracepoint | raw_tp/sched_wakeup_new | sched | 10 | 3677 | 367.70 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:fentry_tcp_v4_connect | tracing | fentry/tcp_v4_connect | tcp-loopback | 10 | 3727 | 372.70 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v4_connect | kprobe | kprobe/tcp_v4_connect | tcp-loopback | 10 | 3786 | 378.60 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_write_exit | tracing | fexit/down_write | write-devnull | 5 | 1938 | 387.60 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp2 | tracepoint | tp/syscalls/sys_enter_nanosleep | generic-syscalls | 1 | 401 | 401.00 | 0 |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:block_io_start | tracing | tp_btf/block_io_start | disk-io | 30 | 12164 | 405.47 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_first_firstzero_cpu | tracing | tp_btf/task_newtask | generic-syscalls | 4 | 1672 | 418.00 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_exit_connect | tracepoint | tracepoint/syscalls/sys_exit_connect | tcp-loopback | 46 | 19730 | 428.91 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_insert_btf | tracing | tp_btf/block_rq_insert | disk-io | 10 | 4431 | 443.10 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_issue | raw_tracepoint | raw_tp/block_rq_issue | disk-io | 40 | 17739 | 443.48 | 0 |
| corpus/build/bcc/libbpf-tools/exitsnoop.bpf.o:sched_process_exit | tracepoint | tracepoint/sched/sched_process_exit | execve | 10 | 4557 | 455.70 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_up_write | kprobe | kprobe/up_write | write-devnull | 8 | 3664 | 458.00 | 0 |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:block_io_start | tracing | tp_btf/block_io_start | disk-io | 30 | 13792 | 459.73 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_recvfrom | tracepoint | tracepoint/syscalls/sys_enter_recvfrom | generic-syscalls | 2 | 952 | 476.00 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_nested_rcu | tracing | tp_btf/task_newtask | generic-syscalls | 2 | 1050 | 525.00 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:sock_do_ioctl | tracing | fentry/sock_do_ioctl | tcp-loopback | 9 | 4778 | 530.89 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_v4_connect | kprobe | kprobe/tcp_v4_connect | tcp-loopback | 10 | 5394 | 539.40 | 0 |
| corpus/build/tracee/tracee.bpf.o:trace_vfs_write | kprobe | kprobe/vfs_write | write-devnull | 30 | 16360 | 545.33 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_wakeup | tracing | tp_btf/sched_wakeup | sched | 254 | 144685 | 569.63 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_recvmsg | tracepoint | tracepoint/syscalls/sys_enter_recvmsg | generic-syscalls | 2 | 1157 | 578.50 | 0 |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:tracepoint__writeback_dirty_folio | tracepoint | tracepoint/writeback/writeback_dirty_folio | write-devnull | 1 | 582 | 582.00 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_sock_do_ioctl_exit | kprobe | kretprobe/sock_do_ioctl | tcp-loopback | 4 | 2338 | 584.50 | 0 |
| corpus/build/tracee/tracee.bpf.o:sched_process_exit_signal | raw_tracepoint | raw_tracepoint/sched_process_exit | execve | 10 | 5891 | 589.10 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_wakeup | tracing | tp_btf/sched_wakeup | sched | 272 | 161038 | 592.05 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_wakeup | raw_tracepoint | raw_tp/sched_wakeup | sched | 255 | 160247 | 628.42 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_insert | raw_tracepoint | raw_tp/block_rq_insert | disk-io | 10 | 6476 | 647.60 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o:handle_exit | tracepoint | tp/sched/sched_process_exit | execve | 10 | 6744 | 674.40 | 0 |
| corpus/build/bcc/libbpf-tools/execsnoop.bpf.o:tracepoint__syscalls__sys_exit_execve | tracepoint | tracepoint/syscalls/sys_exit_execve | execve | 10 | 7014 | 701.40 | 0 |
| corpus/build/bcc/libbpf-tools/tcptop.bpf.o:tcp_sendmsg | kprobe | kprobe/tcp_sendmsg | tcp-loopback | 20 | 14144 | 707.20 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap_legacy.bpf.o:handle_exit | tracepoint | tp/sched/sched_process_exit | execve | 10 | 7093 | 709.30 | 0 |
| corpus/build/bcc/libbpf-tools/tcptop.bpf.o:tcp_cleanup_rbuf | kprobe | kprobe/tcp_cleanup_rbuf | tcp-loopback | 23 | 16365 | 711.52 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_wakeup | raw_tracepoint | raw_tp/sched_wakeup | sched | 261 | 187490 | 718.35 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map_skip.bpf.o:oncpu | tracepoint | tracepoint/sched/sched_switch | sched | 1133 | 816437 | 720.60 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap_legacy.bpf.o:handle_exec | tracepoint | tp/sched/sched_process_exec | execve | 10 | 7472 | 747.20 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o:handle_exec | tracepoint | tp/sched/sched_process_exec | execve | 10 | 7577 | 757.70 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/minimal_ns.bpf.o:handle_tp | tracepoint | tp/syscalls/sys_enter_write | write-devnull | 34 | 26094 | 767.47 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_connect | tracepoint | tracepoint/syscalls/sys_enter_connect | tcp-loopback | 38 | 29373 | 772.97 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o:do_unlinkat_exit | kprobe | kretprobe/do_unlinkat | unlink | 10 | 7951 | 795.10 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:inet_csk_accept | tracing | fexit/inet_csk_accept | tcp-loopback | 10 | 8030 | 803.00 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap.bpf.o:handle_exit | tracepoint | tp/sched/sched_process_exit | execve | 10 | 8512 | 851.20 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/kprobe.bpf.o:do_unlinkat_exit | kprobe | kretprobe/do_unlinkat | unlink | 10 | 8820 | 882.00 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap.bpf.o:handle_exec | tracepoint | tp/sched/sched_process_exec | execve | 10 | 9137 | 913.70 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o:handle_exit | tracepoint | tp/sched/sched_process_exit | execve | 10 | 9620 | 962.00 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat | tracing | fentry/do_unlinkat | unlink | 10 | 9640 | 964.00 | 0 |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:block_rq_insert | tracing | tp_btf/block_rq_insert | disk-io | 10 | 9746 | 974.60 | 0 |
| corpus/build/manual-test/fentry.gen.bpf.o:do_unlinkat | tracing | fentry/do_unlinkat | unlink | 10 | 9768 | 976.80 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o:do_unlinkat | kprobe | kprobe/do_unlinkat | unlink | 10 | 10079 | 1007.90 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/kprobe.bpf.o:do_unlinkat | kprobe | kprobe/do_unlinkat | unlink | 10 | 10120 | 1012.00 | 0 |
| corpus/build/manual-test/fentry.tmp.bpf.o:do_unlinkat | tracing | fentry/do_unlinkat | unlink | 10 | 10185 | 1018.50 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/fentry.bpf.o:do_unlinkat | tracing | fentry/do_unlinkat | unlink | 10 | 10317 | 1031.70 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:trace_tcp_connect | tracing | fentry/tcp_connect | tcp-loopback | 10 | 10447 | 1044.70 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o:handle_exec | tracepoint | tp/sched/sched_process_exec | execve | 13 | 13849 | 1065.31 | 0 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sched_process_exit | tracepoint | tracepoint/sched/sched_process_exit | execve | 10 | 10676 | 1067.60 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat_exit | tracing | fexit/do_unlinkat | unlink | 10 | 10759 | 1075.90 | 0 |
| corpus/build/real_world_code_size/libbpf-bootstrap/fentry.bpf.o:do_unlinkat_exit | tracing | fexit/do_unlinkat | unlink | 10 | 11151 | 1115.10 | 0 |
| corpus/build/manual-test/fentry.tmp.bpf.o:do_unlinkat_exit | tracing | fexit/do_unlinkat | unlink | 10 | 11305 | 1130.50 | 0 |
| corpus/build/manual-test/fentry.gen.bpf.o:do_unlinkat_exit | tracing | fexit/do_unlinkat | unlink | 10 | 11345 | 1134.50 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_nested_deep_array_rcu | tracing | tp_btf/task_newtask | generic-syscalls | 1 | 1349 | 1349.00 | 0 |
| corpus/build/bcc/libbpf-tools/hardirqs.bpf.o:irq_handler_exit | raw_tracepoint | raw_tp/irq_handler_exit | generic-syscalls | 2 | 2719 | 1359.50 | 0 |
| corpus/build/bcc/libbpf-tools/hardirqs.bpf.o:irq_handler_exit_btf | tracing | tp_btf/irq_handler_exit | generic-syscalls | 1 | 1448 | 1448.00 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map.bpf.o:oncpu | tracepoint | tracepoint/sched/sched_switch | sched | 720 | 1369072 | 1901.49 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_killable | kprobe | kprobe/down_read_killable | signal | 21 | 43129 | 2053.76 | 0 |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:block_io_start | tracing | tp_btf/block_io_start | disk-io | 30 | 78637 | 2621.23 | 0 |
| corpus/build/bcc/libbpf-tools/execsnoop.bpf.o:tracepoint__syscalls__sys_enter_execve | tracepoint | tracepoint/syscalls/sys_enter_execve | execve | 10 | 36313 | 3631.30 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o:tgkill_entry | kprobe | ksyscall/tgkill | signal | 1 | 3915 | 3915.00 | 0 |
| corpus/build/tracee/tracee.bpf.o:sched_process_exec_signal | raw_tracepoint | raw_tracepoint/sched_process_exec | execve | 10 | 49824 | 4982.40 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netif_receive_skb.bpf.o:trace_netif_receive_skb | tracing | tp_btf/netif_receive_skb | generic-syscalls | 2 | 676669 | 338334.50 | 0 |

## Directive-Bearing But Not Yet Runnable

| Program | Type | Section | Strategy | Sites | Reason |
| --- | --- | --- | --- | --- | --- |
| corpus/build/tracee/tracee.bpf.o:tracepoint__exec_test | raw_tracepoint | raw_tracepoint/exec_test | tracing_attach_trigger | 20 | requires load + attach + external trigger to collect runtime |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_sendmmsg | tracepoint | tracepoint/syscalls/sys_enter_sendmmsg | tracing_attach_trigger | 15 | requires load + attach + external trigger to collect runtime |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_exit_readv | tracepoint | tracepoint/syscalls/sys_exit_readv | tracing_attach_trigger | 9 | requires load + attach + external trigger to collect runtime |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_exit_recvmsg | tracepoint | tracepoint/syscalls/sys_exit_recvmsg | tracing_attach_trigger | 9 | requires load + attach + external trigger to collect runtime |
| corpus/build/coroot-node-agent/ebpf.bpf.o:go_crypto_tls_read_exit | kprobe | uprobe/go_crypto_tls_read_exit | user_tracing_custom_target | 8 | requires a matching userspace binary/probe target, so only loadability and sites are recorded |
| corpus/build/coroot-node-agent/ebpf.bpf.o:openssl_SSL_read_exit | kprobe | uprobe/openssl_SSL_read_exit | user_tracing_custom_target | 8 | requires a matching userspace binary/probe target, so only loadability and sites are recorded |
| corpus/build/coroot-node-agent/ebpf.bpf.o:sys_enter_writev | tracepoint | tracepoint/syscalls/sys_enter_writev | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:sys_exit_submit | raw_tracepoint | raw_tracepoint/sys_exit_submit | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_arch_prctl | kprobe | kretprobe/arch_prctl | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_dup | kprobe | kretprobe/dup | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_dup2 | kprobe | kretprobe/dup2 | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_dup3 | kprobe | kretprobe/dup3 | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_process_vm_writev | kprobe | kretprobe/process_vm_writev | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_ptrace | kprobe | kretprobe/ptrace | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_file_mprotect | kprobe | kprobe/security_file_mprotect | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_mmap_file | kprobe | kprobe/security_mmap_file | tracing_attach_trigger | 7 | requires load + attach + external trigger to collect runtime |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_exit | kprobe | kretprobe/dummy_file_open | tracing_attach_trigger | 6 | requires load + attach + external trigger to collect runtime |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_exit | kprobe | kretprobe/dummy_file_read | tracing_attach_trigger | 6 | requires load + attach + external trigger to collect runtime |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_exit | kprobe | kretprobe/dummy_file_sync | tracing_attach_trigger | 6 | requires load + attach + external trigger to collect runtime |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_exit | kprobe | kretprobe/dummy_file_write | tracing_attach_trigger | 6 | requires load + attach + external trigger to collect runtime |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_exit | kprobe | kretprobe/dummy_getattr | tracing_attach_trigger | 6 | requires load + attach + external trigger to collect runtime |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_kretprobe | kprobe | kretprobe/dummy_kretprobe | tracing_attach_trigger | 6 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:kernel_write_magic_return | kprobe | kretprobe/__kernel_write | tracing_attach_trigger | 6 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:vfs_writev_magic_return | kprobe | kretprobe/vfs_writev | tracing_attach_trigger | 6 | requires load + attach + external trigger to collect runtime |
| corpus/build/coroot-node-agent/ebpf.bpf.o:go_crypto_tls_write_enter | kprobe | uprobe/go_crypto_tls_write_enter | user_tracing_custom_target | 6 | requires a matching userspace binary/probe target, so only loadability and sites are recorded |
| corpus/build/coroot-node-agent/ebpf.bpf.o:openssl_SSL_write_enter | kprobe | uprobe/openssl_SSL_write_enter | user_tracing_custom_target | 6 | requires a matching userspace binary/probe target, so only loadability and sites are recorded |
| corpus/build/coroot-node-agent/ebpf.bpf.o:openssl_SSL_write_enter_v1_1_1 | kprobe | uprobe/openssl_SSL_write_enter_v1_1_1 | user_tracing_custom_target | 6 | requires a matching userspace binary/probe target, so only loadability and sites are recorded |
| corpus/build/coroot-node-agent/ebpf.bpf.o:openssl_SSL_write_enter_v3_0 | kprobe | uprobe/openssl_SSL_write_enter_v3_0 | user_tracing_custom_target | 6 | requires a matching userspace binary/probe target, so only loadability and sites are recorded |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:mark_page_accessed | tracing | fentry/mark_page_accessed | tracing_attach_trigger | 5 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:sys_dup_exit_tail | kprobe | kprobe/sys_dup | tracing_attach_trigger | 5 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:syscall__accept4 | raw_tracepoint | raw_tracepoint/syscall__accept4 | tracing_attach_trigger | 5 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_mmap_alert | kprobe | kprobe/security_mmap_addr | tracing_attach_trigger | 5 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_bpf | kprobe | kprobe/security_bpf | tracing_attach_trigger | 5 | requires load + attach + external trigger to collect runtime |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o:bpf_cubic_cong_control | struct_ops | struct_ops | kernel_registration_required | 4 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v6_syn_recv | tracing | fentry/tcp_v6_syn_recv_sock | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v6_syn_recv_kprobe | kprobe | kprobe/tcp_v6_syn_recv_sock | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:syscall_checker | kprobe | kprobe/syscall_checker | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_do_init_module | kprobe | kretprobe/do_init_module | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_kernel_write_tail | kprobe | kretprobe/__kernel_write_tail | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_vfs_write_tail | kprobe | kretprobe/vfs_write_tail | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_vfs_writev_tail | kprobe | kretprobe/vfs_writev_tail | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_file_ioctl | kprobe | kprobe/security_file_ioctl | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:tracepoint__sched__sched_process_fork | raw_tracepoint | raw_tracepoint/sched_process_fork | tracing_attach_trigger | 4 | requires load + attach + external trigger to collect runtime |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/setget_sockopt.bpf.o:socket_post_create | lsm | lsm_cgroup/socket_post_create | cgroup_custom_harness | 3 | requires cgroup/socket/sysctl-specific setup beyond the generic packet harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_ksym.bpf.o:dump_ksym | tracing | iter/ksym | iterator_custom_harness | 3 | iterator programs require seq_file/iterator context rather than packet test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_vmas.bpf.o:proc_maps | tracing | iter/task_vma | iterator_custom_harness | 3 | iterator programs require seq_file/iterator context rather than packet test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/setget_sockopt.bpf.o:skops_sockopt | sock_ops | sockops | socket_custom_harness | 3 | requires socket lifecycle or listener setup beyond packet test_run |
| corpus/build/tracee/tracee.bpf.o:trace_do_sigaction | kprobe | kprobe/do_sigaction | tracing_attach_trigger | 3 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_execute_finished | kprobe | kretprobe/execute_finished | tracing_attach_trigger | 3 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret__register_chrdev | kprobe | kretprobe/__register_chrdev | tracing_attach_trigger | 3 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_file_permission | kprobe | kprobe/security_file_permission | tracing_attach_trigger | 3 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_set_fs_pwd | kprobe | kprobe/set_fs_pwd | tracing_attach_trigger | 3 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:tracepoint__module__module_load | raw_tracepoint | raw_tracepoint/module_load | tracing_attach_trigger | 3 | requires load + attach + external trigger to collect runtime |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_acked | struct_ops | struct_ops | kernel_registration_required | 2 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_cong_avoid | struct_ops | struct_ops | kernel_registration_required | 2 | requires struct_ops registration or freplace target registration instead of plain test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o:lsm_run | lsm | lsm/bpf | lsm_custom_harness | 2 | requires security hook attachment; current automation only records loadability and sites |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o:lsm_s_run | lsm | lsm.s/bpf | lsm_custom_harness | 2 | requires security hook attachment; current automation only records loadability and sites |
| corpus/build/tracee/tracee.bpf.o:lsm_file_open_test | lsm | lsm/file_open | lsm_custom_harness | 2 | requires security hook attachment; current automation only records loadability and sites |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o:vfs_read_entry | kprobe | kprobe/vfs_read | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:sys_enter_submit | raw_tracepoint | raw_tracepoint/sys_enter_submit | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:syscall__execve_enter | raw_tracepoint | raw_tracepoint/sys_execve | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:syscall__execve_exit | raw_tracepoint | raw_tracepoint/sys_execve | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:syscall__execveat_enter | raw_tracepoint | raw_tracepoint/sys_execveat | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:syscall__execveat_exit | raw_tracepoint | raw_tracepoint/sys_execveat | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace___debugfs_create_file | kprobe | kprobe/__debugfs_create_file | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_bpf_check | kprobe | kprobe/bpf_check | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_call_usermodehelper | kprobe | kprobe/call_usermodehelper | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_cap_capable | kprobe | kprobe/cap_capable | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_check_helper_call | kprobe | kprobe/check_helper_call | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_check_map_func_compatibility | kprobe | kprobe/check_map_func_compatibility | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_chmod_common | kprobe | kprobe/chmod_common | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_commit_creds | kprobe | kprobe/commit_creds | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_debugfs_create_dir | kprobe | kprobe/debugfs_create_dir | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_device_add | kprobe | kprobe/device_add | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_do_exit | kprobe | kprobe/do_exit | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_do_truncate | kprobe | kprobe/do_truncate | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_exec_binprm | kprobe | kprobe/exec_binprm | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_fd_install | kprobe | kprobe/fd_install | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_filldir64 | kprobe | kprobe/filldir64 | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_filp_close | kprobe | kprobe/filp_close | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_load_elf_phdrs | kprobe | kprobe/load_elf_phdrs | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_proc_create | kprobe | kprobe/proc_create | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_do_mmap | kprobe | kretprobe/do_mmap | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_do_splice | kprobe | kretprobe/do_splice | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_file_modified | kprobe | kretprobe/file_modified | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_file_update_time | kprobe | kretprobe/file_update_time | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_inotify_find_inode | kprobe | kretprobe/inotify_find_inode | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_kallsyms_lookup_name | kprobe | kretprobe/kallsyms_lookup_name | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_kernel_write | kprobe | kretprobe/__kernel_write | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_register_kprobe | kprobe | kretprobe/register_kprobe | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_vfs_read | kprobe | kretprobe/vfs_read | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_vfs_readv | kprobe | kretprobe/vfs_readv | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_ret_vfs_writev | kprobe | kretprobe/vfs_writev | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_bpf_map | kprobe | kprobe/security_bpf_map | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_bpf_prog | kprobe | kprobe/security_bpf_prog | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_bprm_creds_for_exec | kprobe | kprobe/security_bprm_creds_for_exec | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_inode_mknod | kprobe | kprobe/security_inode_mknod | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_inode_rename | kprobe | kprobe/security_inode_rename | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_inode_symlink | kprobe | kprobe/security_inode_symlink | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |
| corpus/build/tracee/tracee.bpf.o:trace_security_kernel_post_read_file | kprobe | kprobe/security_kernel_post_read_file | tracing_attach_trigger | 2 | requires load + attach + external trigger to collect runtime |

## Inventory Failures

| Object | Failure |
| --- | --- |
| corpus/build/cilium/bpf_lxc.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/cilium/bpf_overlay.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/cilium/bpf_xdp.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/datadog-agent/noisy-neighbor-kern.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/minimal_sched_ext.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/minimal_sched_ext.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_dim.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_dim.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_val_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_val_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___equiv_zero_sz_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___equiv_zero_sz_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_signed_arr_elem_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_signed_arr_elem_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_zero_sz_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_zero_sz_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_non_array.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_non_array.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_shallow.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_shallow.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_small.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_small.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_wrong_val_type.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_wrong_val_type.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___fixed_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___fixed_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bit_sz_change.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bit_sz_change.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bitfield_vs_int.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bitfield_vs_int.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___err_too_big_bitfield.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___err_too_big_bitfield.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___just_big_enough.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___just_big_enough.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___err_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___err_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___val3_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___val3_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___err_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___err_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___val3_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___val3_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___minimal.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___minimal.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___wrong_field_defs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___wrong_field_defs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors__err_wrong_name.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors__err_wrong_name.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___bool.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___bool.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___reverse_sign.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___reverse_sign.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_misc.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_misc.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___mod_swap.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___mod_swap.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___typedefs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___typedefs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___anon_embed.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___anon_embed.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___dup_compat_types.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___dup_compat_types.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_field.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_field.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_dup_incompat_types.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_dup_incompat_types.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_field.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_field.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_nonstruct_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_nonstruct_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_partial_match_dups.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_partial_match_dups.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_too_deep.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_too_deep.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___extra_nesting.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___extra_nesting.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___struct_union_mixup.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___struct_union_mixup.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_enum_def.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_enum_def.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_func_proto.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_func_proto.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_ptr_type.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_ptr_type.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_enum.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_enum.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_int.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_int.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_ptr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_ptr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_offs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_offs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___err_ambiguous.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___err_ambiguous.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___all_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___all_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___fn_wrong_args.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___fn_wrong_args.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___incompat.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___incompat.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id___missing_targets.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id___missing_targets.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_data.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_data.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_bitfields.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_bitfields.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_multidim.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_multidim.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_namespacing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_namespacing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_ordering.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_ordering.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_packing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_packing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_padding.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_padding.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_syntax.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_syntax.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_funcs1.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_funcs2.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_maps1.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_maps2.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_vars1.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_vars2.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_map.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_map.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_pinning_htab.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_pinning_htab.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt_multispec.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uptr_map_failure.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uptr_map_failure.bpf.o (exit=1) |
| corpus/build/netbird/prog.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/opentelemetry-ebpf-profiler/generic_probe.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/opentelemetry-ebpf-profiler/sched_monitor.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/scx/scx_lavd_main.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/scx/scx_rusty_main.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |

## Top Load Failures

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Invalid argument (exit=1) | 453 |
| bpf_object__load failed: Permission denied (exit=1) | 82 |
| bpf_object__load failed: No such process (exit=1) | 67 |
| bpf_object__load failed: Bad file descriptor (exit=1) | 17 |
| bpf_object__load failed: No such file or directory (exit=1) | 1 |
| bpf_object__load failed: Argument list too long (exit=1) | 1 |
| bpf_object__load failed: Unknown error 524 (exit=1) | 1 |

## Top Packet Baseline Failures

| Reason | Count |
| --- | --- |
| bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) | 10 |

## Top Tracing Failures

| Reason | Count |
| --- | --- |
| bpf_program__attach failed: No such file or directory | 34 |
| bpf_program__attach failed: Invalid argument | 2 |
| [Errno 97] Address family not supported by protocol | 1 |

## Top Tracing Skip Reasons

| Reason | Count |
| --- | --- |
| missing attach target in section name | 24 |
| dynamic attach target placeholder | 20 |
| no trigger heuristic for section `fentry/blk_account_io_start` / program `blk_account_io_start` | 2 |
| no trigger heuristic for section `fentry/__x64_sys_getpgid` / program `benchmark` | 2 |
| no trigger heuristic for section `fentry/bpf_fentry_test1` / program `sub` | 2 |
| no trigger heuristic for section `fentry/bpf_local_storage_update` / program `on_update` | 2 |
| no trigger heuristic for section `fentry/__x64_sys_getpgid` / program `get_local` | 2 |
| no trigger heuristic for section `fentry/__x64_sys_nanosleep` / program `sys_enter` | 2 |
| no trigger heuristic for section `kprobe/inet_bind` / program `ipv4_bind_entry` | 1 |
| no trigger heuristic for section `kretprobe/inet_bind` / program `ipv4_bind_exit` | 1 |
| no trigger heuristic for section `kprobe/inet6_bind` / program `ipv6_bind_entry` | 1 |
| no trigger heuristic for section `kretprobe/inet6_bind` / program `ipv6_bind_exit` | 1 |

## Notes

- Program type comes from `micro_exec list-programs`, which now surfaces libbpf-inferred `prog_type` and `expected_attach_type` per program.
- Packet-backed measurements use `bpf_prog_test_run_opts()` and the existing `micro_exec run-kernel` path.
- Tracing measurements use real load + attach + trigger, then read `run_cnt` and `run_time_ns` from `bpf_prog_info`.
- Directive counts prefer the live recompile probe. When that fails but the program still loads, the report falls back to `dump-xlated` plus `bpf-jit-scanner scan --xlated --v5`.
- `syscall` programs are counted separately because the kernel has a synthetic test-run path, but this report does not treat that as a real attached workload benchmark.
