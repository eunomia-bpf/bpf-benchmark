# Micro compilation receipts

## output-micro-x86

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.805 | 51 |  | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.897 | 48 |  | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 18.252 | 121 |  | 0.000 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 4.454 | 137 |  | 0.000 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 18.690 | 201 |  | 0.000 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 8.746 | 373 |  | 0.000 | 0.000 |  |
| `packet_checksum_fold` | ok | 9.223 | 126 |  | 0.000 | 0.000 |  |
| `payload_prefix_memcmp_scan` | ok | 17.452 | 361 |  | 0.000 | 0.000 |  |
| `packet_vlan_tcpopt_parser` | ok | 52.399 | 429 |  | 0.000 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 49.957 | 1066 |  | 0.000 | 0.000 |  |
| `flow_5tuple_rss_hash` | ok | 32.105 | 461 |  | 0.000 | 0.000 |  |
| `katran_lb_consistent_hash_select` | ok | 70.766 | 1264 |  | 0.000 | 0.000 |  |
| `cilium_policy_guard_tree_filter` | ok | 18.510 | 306 |  | 0.000 | 0.000 |  |
| `siphash_rotate64_mixer` | ok | 37.012 | 920 |  | 0.000 | 0.000 |  |
| `packet_record_bounds_window` | ok | 21.385 | 291 |  | 0.000 | 0.000 |  |
| `flow_record_field_scan` | ok | 22.695 | 228 |  | 0.000 | 0.000 |  |
| `packed_header_bitfield_decode` | ok | 44.386 | 1351 |  | 0.000 | 0.000 |  |
| `bpftrace_string_search_prefix_scan` | ok | 8.005 | 285 |  | 0.000 | 0.000 |  |
| `tracee_syscall_name_table_lookup` | ok | 21.813 | 327 |  | 0.000 | 0.000 |  |
| `tracee_http_method_prefix_detect` | ok | 14.811 | 583 |  | 0.000 | 0.000 |  |
| `cilium_socket_lb_service_select` | ok | 21.072 | 447 |  | 0.000 | 0.000 |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 24.092 | 556 |  | 0.000 | 0.000 |  |
| `tetragon_process_event_arg_filter` | ok | 44.344 | 1721 |  | 0.000 | 0.000 |  |
| `otel_stack_frame_unwind_scan` | ok | 17.490 | 353 |  | 0.000 | 0.000 |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 16.532 | 451 |  | 0.000 | 0.000 |  |
| `packet_toeplitz_rss_hash` | ok | 31.533 | 294 |  | 0.000 | 0.000 |  |
| `bpftrace_comm_key_fnv_hash` | ok | 50.027 | 2216 |  | 0.000 | 0.000 |  |
| `tc_packet_checksum_fold` | ok | 7.841 | 171 |  | 0.000 | 0.000 |  |
| `cgroup_skb_hash_chain` | ok | 12.088 | 474 |  | 0.000 | 0.000 |  |

## output-negative-x86

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `unchecked_packet_read` | ok | 0.288 | 30 |  | 0.000 | 0.000 |  |

## output-micro-arm64

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.755 | 122 |  | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.562 | 119 |  | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 1.126 | 169 |  | 0.000 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 2.414 | 268 |  | 0.000 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 3.311 | 280 |  | 0.000 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 3.802 | 446 |  | 0.000 | 0.000 |  |
| `packet_checksum_fold` | ok | 1.787 | 179 |  | 0.000 | 0.000 |  |
| `payload_prefix_memcmp_scan` | ok | 2.429 | 254 |  | 0.000 | 0.000 |  |
| `packet_vlan_tcpopt_parser` | ok | 6.265 | 440 |  | 0.000 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 11.564 | 868 |  | 0.000 | 0.000 |  |
| `flow_5tuple_rss_hash` | ok | 3.905 | 397 |  | 0.000 | 0.000 |  |
| `katran_lb_consistent_hash_select` | ok | 17.677 | 893 |  | 0.000 | 0.000 |  |
| `cilium_policy_guard_tree_filter` | ok | 2.771 | 267 |  | 0.000 | 0.000 |  |
| `siphash_rotate64_mixer` | ok | 12.122 | 939 |  | 0.000 | 0.000 |  |
| `packet_record_bounds_window` | ok | 3.181 | 222 |  | 0.000 | 0.000 |  |
| `flow_record_field_scan` | ok | 2.731 | 252 |  | 0.000 | 0.000 |  |
| `packed_header_bitfield_decode` | ok | 11.135 | 1015 |  | 0.000 | 0.000 |  |
| `bpftrace_string_search_prefix_scan` | ok | 5.212 | 328 |  | 0.000 | 0.000 |  |
| `tracee_syscall_name_table_lookup` | ok | 5.546 | 594 |  | 0.000 | 0.000 |  |
| `tracee_http_method_prefix_detect` | ok | 4.581 | 358 |  | 0.000 | 0.000 |  |
| `cilium_socket_lb_service_select` | ok | 4.038 | 293 |  | 0.000 | 0.000 |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 3.517 | 356 |  | 0.000 | 0.000 |  |
| `tetragon_process_event_arg_filter` | ok | 10.165 | 1004 |  | 0.000 | 0.000 |  |
| `otel_stack_frame_unwind_scan` | ok | 1.937 | 259 |  | 0.000 | 0.000 |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 3.411 | 291 |  | 0.000 | 0.000 |  |
| `packet_toeplitz_rss_hash` | ok | 2.816 | 357 |  | 0.000 | 0.000 |  |
| `bpftrace_comm_key_fnv_hash` | ok | 8.402 | 580 |  | 0.000 | 0.000 |  |
| `tc_packet_checksum_fold` | ok | 1.634 | 216 |  | 0.000 | 0.000 |  |
| `cgroup_skb_hash_chain` | ok | 8.942 | 814 |  | 0.000 | 0.000 |  |

## output-negative-arm64

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `unchecked_packet_read` | ok | 0.310 | 106 |  | 0.000 | 0.000 |  |
