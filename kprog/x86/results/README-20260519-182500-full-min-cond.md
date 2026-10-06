| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.375 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.324 | 16 | 21 | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 0.674 | 56 | 79 | 0.018 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 0.946 | 66 | 159 | 0.096 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 2.059 | 130 | 145 | 0.792 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 5.277 | 772 | 241 | 0.479 | 0.000 |  |
| `packet_checksum_fold` | ok | 1.011 | 99 | 70 | 0.410 | 0.000 |  |
| `payload_prefix_memcmp_scan` | run-fail | 2.829 | 228 | 137 | 0.000 | 0.093 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/payload_prefix_memcmp_scan.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/payload_prefix_memcmp_scan-20260519-134534.verifier.log |
| `packet_vlan_tcpopt_parser` | ok | 3.909 | 188 | 197 | 0.002 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 4.976 | 338 | 292 | 0.018 | 0.000 |  |
| `flow_5tuple_rss_hash` | ok | 3.638 | 266 | 160 | 0.001 | 0.000 |  |
| `katran_lb_consistent_hash_select` | ok | 12.358 | 730 | 688 | 0.004 | 0.000 |  |
| `cilium_policy_guard_tree_filter` | ok | 2.747 | 128 | 134 | 0.049 | 0.000 |  |
| `siphash_rotate64_mixer` | ok | 8.847 | 747 | 587 | 0.002 | 0.000 |  |
| `packet_record_bounds_window` | ok | 1.557 | 77 | 102 | 0.011 | 0.000 |  |
| `flow_record_field_scan` | ok | 2.050 | 92 | 91 | 0.009 | 0.000 |  |
| `packed_header_bitfield_decode` | ok | 5.184 | 246 | 256 | 0.023 | 0.000 |  |
| `bpftrace_string_search_prefix_scan` | ok | 2.260 | 158 | 163 | 0.497 | 0.000 |  |
| `tracee_syscall_name_table_lookup` | ok | 2.924 | 275 | 177 | 0.103 | 0.000 |  |
| `tracee_http_method_prefix_detect` | ok | 3.245 | 153 | 153 | 0.010 | 0.000 |  |
| `cilium_socket_lb_service_select` | ok | 2.565 | 151 | 218 | 0.095 | 0.000 |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 2.498 | 164 | 190 | 0.515 | 0.000 |  |
| `tetragon_process_event_arg_filter` | run-fail | 4.576 | 301 | 252 | 0.001 | 0.018 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tetragon_process_event_arg_filter.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tetragon_process_event_arg_filter-20260519-134534.verifier.log |
| `otel_stack_frame_unwind_scan` | ok | 2.199 | 123 | 214 | 0.027 | 0.000 |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 2.362 | 120 | 195 | 0.042 | 0.000 |  |
| `packet_toeplitz_rss_hash` | ok | 3.521 | 319 | 195 | 0.030 | 0.000 |  |
| `bpftrace_comm_key_fnv_hash` | ok | 4.818 | 252 | 219 | 0.048 | 0.000 |  |
| `tc_packet_checksum_fold` | ok | 1.352 | 118 | 55 | 0.338 | 0.000 |  |
| `cgroup_skb_hash_chain` | ok | 1.554 | 236 | 102 | 0.006 | 0.000 |  |
