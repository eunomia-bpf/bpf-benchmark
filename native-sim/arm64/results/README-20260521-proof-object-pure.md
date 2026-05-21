| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 1.269 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 1.053 | 16 |  | 0.000 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `bitmap_popcount_scan` | ok | 2.258 | 306 |  | 0.176 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `sorted_rule_binary_search` | ok | 4.984 | 160 |  | 0.291 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `bcc_runqlat_log2_histogram_bucket` | ok | 3.385 | 153 |  | 1.166 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `trace_event_type_switch_dispatch` | ok | 9.838 | 705 |  | 0.445 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `packet_checksum_fold` | ok | 1.702 | 72 |  | 0.724 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `payload_prefix_memcmp_scan` | ok | 4.422 | 122 |  | 0.009 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `packet_vlan_tcpopt_parser` | ok | 9.936 | 217 |  | 0.002 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `bpf_local_call_fanout_dispatch` | ok | 9.248 | 440 |  | 0.027 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `flow_5tuple_rss_hash` | ok | 9.153 | 264 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `katran_lb_consistent_hash_select` | ok | 19.439 | 849 |  | 0.004 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `cilium_policy_guard_tree_filter` | ok | 4.147 | 144 |  | 0.031 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `siphash_rotate64_mixer` | ok | 18.453 | 1029 |  | 0.003 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `packet_record_bounds_window` | ok | 4.614 | 137 |  | 0.019 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `flow_record_field_scan` | ok | 3.760 | 196 |  | 0.025 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `packed_header_bitfield_decode` | ok | 9.089 | 230 |  | 0.018 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `bpftrace_string_search_prefix_scan` | ok | 4.743 | 149 |  | 0.435 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `tracee_syscall_name_table_lookup` | ok | 8.666 | 265 |  | 0.114 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `tracee_http_method_prefix_detect` | ok | 8.367 | 171 |  | 0.010 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `cilium_socket_lb_service_select` | ok | 5.520 | 221 |  | 0.128 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 6.379 | 233 |  | 0.083 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `tetragon_process_event_arg_filter` | ok | 8.506 | 287 |  | 0.146 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `otel_stack_frame_unwind_scan` | ok | 4.130 | 220 |  | 0.043 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `cilium_ct_nat_tuple_rewrite` | ok | 3.920 | 202 |  | 0.049 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `packet_toeplitz_rss_hash` | ok | 6.712 | 256 |  | 0.021 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `bpftrace_comm_key_fnv_hash` | ok | 8.483 | 221 |  | 0.035 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `tc_packet_checksum_fold` | ok | 2.311 | 84 |  | 0.533 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `cgroup_skb_hash_chain` | ok | 3.126 | 118 |  | 0.037 | 0.000 | missing direct xlated.bin in arm64 micro result |
