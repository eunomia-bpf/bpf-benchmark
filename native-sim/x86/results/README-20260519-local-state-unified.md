| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.428 | 19 |  | 0.000 | 0.000 | missing direct xlated.bin in micro result |
| `simple_packet` | ok | 0.371 | 16 |  | 0.000 | 0.000 | missing direct xlated.bin in micro result |
| `bitmap_popcount_scan` | ok | 0.772 | 56 |  | 0.018 | 0.000 | missing direct xlated.bin in micro result |
| `sorted_rule_binary_search` | ok | 1.108 | 65 |  | 0.108 | 0.000 | missing direct xlated.bin in micro result |
| `bcc_runqlat_log2_histogram_bucket` | ok | 2.579 | 115 |  | 0.729 | 0.000 | missing direct xlated.bin in micro result |
| `trace_event_type_switch_dispatch` | ok | 6.047 | 775 |  | 0.526 | 0.000 | missing direct xlated.bin in micro result |
| `packet_checksum_fold` | ok | 1.330 | 163 |  | 0.347 | 0.000 | missing direct xlated.bin in micro result |
| `payload_prefix_memcmp_scan` | ok | 4.086 | 184 |  | 0.021 | 0.000 | missing direct xlated.bin in micro result |
| `packet_vlan_tcpopt_parser` | run-fail | 4.710 | 218 |  | 0.001 | 0.015 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/packet_vlan_tcpopt_parser.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/packet_vlan_tcpopt_parser-20260519-041703.verifier.log; missing direct xlated.bin in micro result |
| `bpf_local_call_fanout_dispatch` | ok | 8.549 | 277 |  | 0.016 | 0.000 | missing direct xlated.bin in micro result |
| `flow_5tuple_rss_hash` | run-fail | 5.378 | 269 |  | 0.001 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/flow_5tuple_rss_hash.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/flow_5tuple_rss_hash-20260519-041703.verifier.log; missing direct xlated.bin in micro result |
| `katran_lb_consistent_hash_select` | ok | 24.865 | 723 |  | 0.004 | 0.000 | missing direct xlated.bin in micro result |
| `cilium_policy_guard_tree_filter` | ok | 2.874 | 164 |  | 0.030 | 0.000 | missing direct xlated.bin in micro result |
| `siphash_rotate64_mixer` | ok | 19.494 | 747 |  | 0.002 | 0.000 | missing direct xlated.bin in micro result |
| `packet_record_bounds_window` | ok | 2.218 | 97 |  | 0.010 | 0.000 | missing direct xlated.bin in micro result |
| `flow_record_field_scan` | ok | 2.518 | 97 |  | 0.010 | 0.000 | missing direct xlated.bin in micro result |
| `packed_header_bitfield_decode` | run-fail | 8.844 | 331 |  | 0.001 | 0.015 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/packed_header_bitfield_decode.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/packed_header_bitfield_decode-20260519-041703.verifier.log; missing direct xlated.bin in micro result |
| `bpftrace_string_search_prefix_scan` | ok | 2.737 | 161 |  | 0.444 | 0.000 | missing direct xlated.bin in micro result |
| `tracee_syscall_name_table_lookup` | ok | 3.444 | 275 |  | 0.122 | 0.000 | missing direct xlated.bin in micro result |
| `tracee_http_method_prefix_detect` | ok | 4.166 | 209 |  | 0.009 | 0.000 | missing direct xlated.bin in micro result |
| `cilium_socket_lb_service_select` | ok | 3.299 | 210 |  | 0.128 | 0.000 | missing direct xlated.bin in micro result |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 3.212 | 180 |  | 0.052 | 0.000 | missing direct xlated.bin in micro result |
| `tetragon_process_event_arg_filter` | ok | 6.104 | 310 |  | 0.179 | 0.000 | missing direct xlated.bin in micro result |
| `otel_stack_frame_unwind_scan` | ok | 3.090 | 156 |  | 0.044 | 0.000 | missing direct xlated.bin in micro result |
| `cilium_ct_nat_tuple_rewrite` | ok | 3.187 | 197 |  | 0.047 | 0.000 | missing direct xlated.bin in micro result |
| `packet_toeplitz_rss_hash` | ok | 4.350 | 334 |  | 0.032 | 0.000 | missing direct xlated.bin in micro result |
| `bpftrace_comm_key_fnv_hash` | ok | 6.571 | 305 |  | 0.048 | 0.000 | missing direct xlated.bin in micro result |
| `tc_packet_checksum_fold` | ok | 2.333 | 167 |  | 0.339 | 0.000 | missing direct xlated.bin in micro result |
| `cgroup_skb_hash_chain` | run-fail | 2.938 | 829 |  | 0.007 | 0.020 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/cgroup_skb_hash_chain.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/cgroup_skb_hash_chain-20260519-041703.verifier.log; missing direct xlated.bin in micro result |
