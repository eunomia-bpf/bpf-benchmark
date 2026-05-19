| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.370 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.459 | 16 | 21 | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 0.742 | 56 | 79 | 0.018 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 0.944 | 66 | 159 | 0.114 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 2.069 | 130 | 145 | 1.084 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 5.257 | 772 | 241 | 0.643 | 0.000 |  |
| `packet_checksum_fold` | ok | 1.067 | 99 | 70 | 0.447 | 0.000 |  |
| `payload_prefix_memcmp_scan` | run-fail | 2.804 | 228 | 138 | 0.000 | 0.012 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/payload_prefix_memcmp_scan.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/payload_prefix_memcmp_scan-20260519-094118.verifier.log |
| `packet_vlan_tcpopt_parser` | ok | 3.528 | 188 | 197 | 0.002 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 5.094 | 338 | 298 | 0.017 | 0.000 |  |
| `flow_5tuple_rss_hash` | ok | 3.626 | 266 | 161 | 0.001 | 0.000 |  |
| `katran_lb_consistent_hash_select` | ok | 12.941 | 730 | 687 | 0.004 | 0.000 |  |
| `cilium_policy_guard_tree_filter` | ok | 2.415 | 128 | 134 | 0.047 | 0.000 |  |
| `siphash_rotate64_mixer` | ok | 9.154 | 747 | 587 | 0.002 | 0.000 |  |
| `packet_record_bounds_window` | ok | 1.921 | 77 | 102 | 0.012 | 0.000 |  |
| `flow_record_field_scan` | ok | 2.136 | 92 | 91 | 0.009 | 0.000 |  |
| `packed_header_bitfield_decode` | ok | 5.261 | 246 | 256 | 0.022 | 0.000 |  |
| `bpftrace_string_search_prefix_scan` | ok | 2.713 | 158 | 164 | 0.650 | 0.000 |  |
| `tracee_syscall_name_table_lookup` | ok | 2.840 | 275 | 177 | 0.121 | 0.000 |  |
| `tracee_http_method_prefix_detect` | ok | 4.121 | 153 | 153 | 0.009 | 0.000 |  |
| `cilium_socket_lb_service_select` | ok | 2.963 | 151 | 218 | 0.102 | 0.000 |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 2.499 | 164 | 191 | 0.062 | 0.000 |  |
| `tetragon_process_event_arg_filter` | run-fail | 5.198 | 301 | 252 | 0.001 | 0.016 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tetragon_process_event_arg_filter.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tetragon_process_event_arg_filter-20260519-094118.verifier.log |
| `otel_stack_frame_unwind_scan` | ok | 2.386 | 123 | 214 | 0.027 | 0.000 |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 2.510 | 120 | 196 | 0.042 | 0.000 |  |
| `packet_toeplitz_rss_hash` | ok | 4.112 | 319 | 195 | 0.030 | 0.000 |  |
| `bpftrace_comm_key_fnv_hash` | ok | 4.955 | 252 | 219 | 0.048 | 0.000 |  |
| `tc_packet_checksum_fold` | run-fail | 2.350 | 116 | 55 | 0.000 | 0.013 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tc_packet_checksum_fold.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tc_packet_checksum_fold-20260519-094118.verifier.log |
| `cgroup_skb_hash_chain` | run-fail | 2.558 | 263 | 102 | 0.001 | 0.012 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/cgroup_skb_hash_chain.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/cgroup_skb_hash_chain-20260519-094118.verifier.log |
