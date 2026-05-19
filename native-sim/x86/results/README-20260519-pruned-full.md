| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.564 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.656 | 16 | 21 | 0.001 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 0.963 | 56 | 78 | 0.019 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 1.204 | 65 | 160 | 0.095 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 3.885 | 115 | 146 | 0.994 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 6.910 | 775 | 239 | 0.686 | 0.000 |  |
| `packet_checksum_fold` | ok | 2.246 | 163 |  | 0.456 | 0.000 | missing direct xlated.bin in micro result |
| `payload_prefix_memcmp_scan` | ok | 6.332 | 184 |  | 0.007 | 0.000 | missing direct xlated.bin in micro result |
| `packet_vlan_tcpopt_parser` | run-fail | 6.596 | 218 |  | 0.001 | 0.015 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/packet_vlan_tcpopt_parser.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/packet_vlan_tcpopt_parser-20260519-042555.verifier.log; missing direct xlated.bin in micro result |
| `bpf_local_call_fanout_dispatch` | ok | 10.748 | 277 |  | 0.016 | 0.000 | missing direct xlated.bin in micro result |
| `flow_5tuple_rss_hash` | run-fail | 6.017 | 269 |  | 0.001 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/flow_5tuple_rss_hash.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/flow_5tuple_rss_hash-20260519-042555.verifier.log; missing direct xlated.bin in micro result |
| `katran_lb_consistent_hash_select` | ok | 25.521 | 723 |  | 0.004 | 0.000 | missing direct xlated.bin in micro result |
| `cilium_policy_guard_tree_filter` | ok | 4.304 | 164 |  | 0.032 | 0.000 | missing direct xlated.bin in micro result |
| `siphash_rotate64_mixer` | ok | 20.475 | 747 |  | 0.002 | 0.000 | missing direct xlated.bin in micro result |
| `packet_record_bounds_window` | ok | 3.147 | 97 |  | 0.011 | 0.000 | missing direct xlated.bin in micro result |
| `flow_record_field_scan` | ok | 3.674 | 97 |  | 0.010 | 0.000 | missing direct xlated.bin in micro result |
| `packed_header_bitfield_decode` | run-fail | 11.598 | 331 |  | 0.001 | 0.015 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/packed_header_bitfield_decode.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/packed_header_bitfield_decode-20260519-042555.verifier.log; missing direct xlated.bin in micro result |
| `bpftrace_string_search_prefix_scan` | ok | 4.073 | 161 |  | 0.471 | 0.000 | missing direct xlated.bin in micro result |
| `tracee_syscall_name_table_lookup` | ok | 3.954 | 275 |  | 0.122 | 0.000 | missing direct xlated.bin in micro result |
| `tracee_http_method_prefix_detect` | ok | 5.932 | 209 |  | 0.009 | 0.000 | missing direct xlated.bin in micro result |
| `cilium_socket_lb_service_select` | ok | 3.549 | 210 |  | 0.123 | 0.000 | missing direct xlated.bin in micro result |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 4.253 | 180 |  | 0.052 | 0.000 | missing direct xlated.bin in micro result |
| `tetragon_process_event_arg_filter` | ok | 6.054 | 310 |  | 0.190 | 0.000 | missing direct xlated.bin in micro result |
| `otel_stack_frame_unwind_scan` | ok | 4.255 | 156 |  | 0.044 | 0.000 | missing direct xlated.bin in micro result |
| `cilium_ct_nat_tuple_rewrite` | ok | 4.525 | 197 |  | 0.047 | 0.000 | missing direct xlated.bin in micro result |
| `packet_toeplitz_rss_hash` | ok | 5.781 | 334 |  | 0.032 | 0.000 | missing direct xlated.bin in micro result |
| `bpftrace_comm_key_fnv_hash` | ok | 7.029 | 305 |  | 0.049 | 0.000 | missing direct xlated.bin in micro result |
| `tc_packet_checksum_fold` | ok | 2.888 | 167 |  | 0.419 | 0.000 | missing direct xlated.bin in micro result |
| `cgroup_skb_hash_chain` | run-fail | 3.191 | 829 |  | 0.007 | 0.022 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/cgroup_skb_hash_chain.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/cgroup_skb_hash_chain-20260519-042555.verifier.log; missing direct xlated.bin in micro result |
