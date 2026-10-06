| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.261 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.237 | 16 | 21 | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 0.455 | 56 | 80 | 0.018 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 0.644 | 66 | 162 | 0.098 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 1.393 | 130 | 148 | 0.932 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 3.510 | 772 | 244 | 0.485 | 0.000 |  |
| `packet_checksum_fold` | ok | 0.701 | 99 | 73 | 0.332 | 0.000 |  |
| `payload_prefix_memcmp_scan` | run-fail | 1.953 | 228 | 139 | 0.000 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/payload_prefix_memcmp_scan.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/payload_prefix_memcmp_scan-20260519-055540.verifier.log |
| `packet_vlan_tcpopt_parser` | ok | 2.278 | 188 | 197 | 0.002 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 3.278 | 338 | 301 | 0.017 | 0.000 |  |
| `flow_5tuple_rss_hash` | ok | 2.531 | 266 | 162 | 0.001 | 0.000 |  |
| `katran_lb_consistent_hash_select` | ok | 8.311 | 728 | 688 | 0.003 | 0.000 |  |
| `cilium_policy_guard_tree_filter` | ok | 1.656 | 128 | 135 | 0.025 | 0.000 |  |
| `siphash_rotate64_mixer` | ok | 6.261 | 747 | 588 | 0.002 | 0.000 |  |
| `packet_record_bounds_window` | ok | 1.115 | 77 | 105 | 0.011 | 0.000 |  |
| `flow_record_field_scan` | ok | 1.405 | 92 | 91 | 0.009 | 0.000 |  |
| `packed_header_bitfield_decode` | ok | 3.441 | 246 | 259 | 0.022 | 0.000 |  |
| `bpftrace_string_search_prefix_scan` | ok | 1.637 | 154 | 165 | 0.647 | 0.000 |  |
| `tracee_syscall_name_table_lookup` | ok | 1.886 | 275 | 180 | 0.121 | 0.000 |  |
| `tracee_http_method_prefix_detect` | ok | 2.320 | 167 | 156 | 0.008 | 0.000 |  |
| `cilium_socket_lb_service_select` | ok | 1.660 | 151 | 221 | 0.105 | 0.000 |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 1.864 | 164 | 192 | 0.062 | 0.000 |  |
| `tetragon_process_event_arg_filter` | run-fail | 3.059 | 301 | 255 | 0.001 | 0.013 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tetragon_process_event_arg_filter.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tetragon_process_event_arg_filter-20260519-055540.verifier.log |
| `otel_stack_frame_unwind_scan` | ok | 1.520 | 123 | 217 | 0.027 | 0.000 |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 1.592 | 120 | 197 | 0.042 | 0.000 |  |
| `packet_toeplitz_rss_hash` | ok | 2.366 | 319 | 196 | 0.030 | 0.000 |  |
| `bpftrace_comm_key_fnv_hash` | ok | 3.297 | 252 | 222 | 0.050 | 0.000 |  |
| `tc_packet_checksum_fold` | run-fail | 1.322 | 110 | 58 | 0.000 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tc_packet_checksum_fold.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tc_packet_checksum_fold-20260519-055540.verifier.log |
| `cgroup_skb_hash_chain` | run-fail | 1.672 | 257 | 105 | 0.000 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/cgroup_skb_hash_chain.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/cgroup_skb_hash_chain-20260519-055540.verifier.log |
