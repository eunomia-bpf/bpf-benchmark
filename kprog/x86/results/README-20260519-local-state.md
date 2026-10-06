| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.426 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.371 | 16 | 21 | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 0.886 | 56 | 87 | 0.018 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 1.104 | 65 | 158 | 0.115 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 2.577 | 115 | 153 | 0.989 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 6.035 | 775 | 239 | 0.570 | 0.000 |  |
| `packet_checksum_fold` | ok | 1.273 | 163 | 67 | 0.450 | 0.000 |  |
| `payload_prefix_memcmp_scan` | ok | 4.107 | 184 | 135 | 0.007 | 0.000 |  |
| `packet_vlan_tcpopt_parser` | run-fail | 4.784 | 218 | 222 | 0.001 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/packet_vlan_tcpopt_parser.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/packet_vlan_tcpopt_parser-20260519-025825.verifier.log |
| `bpf_local_call_fanout_dispatch` | run-fail | 8.199 | 3750 | 466 | 0.001 | 0.020 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/bpf_local_call_fanout_dispatch.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/bpf_local_call_fanout_dispatch-20260519-025825.verifier.log |
| `flow_5tuple_rss_hash` | run-fail | 5.381 | 269 | 179 | 0.001 | 0.015 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/flow_5tuple_rss_hash.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/flow_5tuple_rss_hash-20260519-025825.verifier.log |
| `katran_lb_consistent_hash_select` | ok | 24.382 | 723 | 682 | 0.003 | 0.000 |  |
| `cilium_policy_guard_tree_filter` | ok | 3.229 | 164 | 134 | 0.030 | 0.000 |  |
| `siphash_rotate64_mixer` | ok | 18.738 | 747 | 772 | 0.002 | 0.000 |  |
| `packet_record_bounds_window` | ok | 2.452 | 97 | 118 | 0.010 | 0.000 |  |
| `flow_record_field_scan` | ok | 2.543 | 97 | 91 | 0.010 | 0.000 |  |
| `packed_header_bitfield_decode` | run-fail | 8.818 | 410 | 254 | 0.001 | 0.015 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/packed_header_bitfield_decode.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/packed_header_bitfield_decode-20260519-025825.verifier.log |
| `bpftrace_string_search_prefix_scan` | ok | 2.769 | 161 | 164 | 0.606 | 0.000 |  |
| `tracee_syscall_name_table_lookup` | ok | 3.394 | 275 | 176 | 0.122 | 0.000 |  |
| `tracee_http_method_prefix_detect` | ok | 4.271 | 209 | 151 | 0.009 | 0.000 |  |
| `cilium_socket_lb_service_select` | ok | 3.551 | 210 | 216 | 0.124 | 0.000 |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 3.176 | 180 | 190 | 0.051 | 0.000 |  |
| `tetragon_process_event_arg_filter` | run-fail | 5.970 | 568 | 250 | 0.001 | 0.012 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tetragon_process_event_arg_filter.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tetragon_process_event_arg_filter-20260519-025825.verifier.log |
| `otel_stack_frame_unwind_scan` | ok | 3.069 | 156 | 212 | 0.044 | 0.000 |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 3.189 | 197 | 195 | 0.047 | 0.000 |  |
| `packet_toeplitz_rss_hash` | ok | 4.368 | 334 | 211 | 0.032 | 0.000 |  |
| `bpftrace_comm_key_fnv_hash` | run-fail | 6.682 | 631 | 217 | 0.001 | 0.013 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/bpftrace_comm_key_fnv_hash.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/bpftrace_comm_key_fnv_hash-20260519-025825.verifier.log |
| `tc_packet_checksum_fold` | ok | 2.233 | 167 | 52 | 0.341 | 0.000 |  |
| `cgroup_skb_hash_chain` | run-fail | 2.814 | 829 | 100 | 0.007 | 0.022 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/cgroup_skb_hash_chain.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/cgroup_skb_hash_chain-20260519-025825.verifier.log |
