# Micro compilation receipts

## x86 standard29

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.645 | 51 |  | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.578 | 48 |  | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 10.548 | 121 |  | 0.000 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 2.098 | 137 |  | 0.000 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 11.036 | 201 |  | 0.000 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 4.800 | 373 |  | 0.000 | 0.000 |  |
| `packet_checksum_fold` | ok | 4.634 | 126 |  | 0.000 | 0.000 |  |
| `payload_prefix_memcmp_scan` | ok | 9.727 | 361 |  | 0.000 | 0.000 |  |
| `packet_vlan_tcpopt_parser` | ok | 29.627 | 429 |  | 0.000 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 29.248 | 1076 |  | 0.000 | 0.000 |  |
| `flow_5tuple_rss_hash` | ok | 18.612 | 461 |  | 0.000 | 0.000 |  |
| `katran_lb_consistent_hash_select` | ok | 40.323 | 1264 |  | 0.000 | 0.000 |  |
| `cilium_policy_guard_tree_filter` | ok | 12.209 | 268 |  | 0.000 | 0.000 |  |
| `siphash_rotate64_mixer` | ok | 22.370 | 920 |  | 0.000 | 0.000 |  |
| `packet_record_bounds_window` | ok | 13.615 | 263 |  | 0.000 | 0.000 |  |
| `flow_record_field_scan` | ok | 14.248 | 228 |  | 0.000 | 0.000 |  |
| `packed_header_bitfield_decode` | ok | 26.847 | 1335 |  | 0.000 | 0.000 |  |
| `bpftrace_string_search_prefix_scan` | ok | 4.946 | 285 |  | 0.000 | 0.000 |  |
| `tracee_syscall_name_table_lookup` | ok | 11.902 | 327 |  | 0.000 | 0.000 |  |
| `tracee_http_method_prefix_detect` | ok | 7.754 | 488 |  | 0.000 | 0.000 |  |
| `cilium_socket_lb_service_select` | ok | 13.284 | 395 |  | 0.000 | 0.000 |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 14.191 | 457 |  | 0.000 | 0.000 |  |
| `tetragon_process_event_arg_filter` | ok | 28.382 | 1659 |  | 0.000 | 0.000 |  |
| `otel_stack_frame_unwind_scan` | ok | 9.640 | 336 |  | 0.000 | 0.000 |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 10.523 | 407 |  | 0.000 | 0.000 |  |
| `packet_toeplitz_rss_hash` | ok | 21.433 | 293 |  | 0.000 | 0.000 |  |
| `bpftrace_comm_key_fnv_hash` | ok | 37.198 | 2155 |  | 0.000 | 0.000 |  |
| `tc_packet_checksum_fold` | ok | 5.302 | 171 |  | 0.000 | 0.000 |  |
| `cgroup_skb_hash_chain` | ok | 7.743 | 474 |  | 0.000 | 0.000 |  |

## x86 negative1

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `unchecked_packet_read` | ok | 0.271 | 30 |  | 0.000 | 0.000 |  |

## AArch64 standard29 after final SP change

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.426 | 122 |  | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.388 | 119 |  | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 0.742 | 169 |  | 0.000 | 0.000 |  |
| `sorted_rule_binary_search` | ok | 1.966 | 268 |  | 0.000 | 0.000 |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 1.709 | 280 |  | 0.000 | 0.000 |  |
| `trace_event_type_switch_dispatch` | ok | 2.218 | 446 |  | 0.000 | 0.000 |  |
| `packet_checksum_fold` | ok | 0.857 | 179 |  | 0.000 | 0.000 |  |
| `payload_prefix_memcmp_scan` | ok | 1.808 | 254 |  | 0.000 | 0.000 |  |
| `packet_vlan_tcpopt_parser` | ok | 3.520 | 440 |  | 0.000 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 7.525 | 868 |  | 0.000 | 0.000 |  |
| `flow_5tuple_rss_hash` | ok | 2.791 | 397 |  | 0.000 | 0.000 |  |
| `katran_lb_consistent_hash_select` | ok | 8.764 | 893 |  | 0.000 | 0.000 |  |
| `cilium_policy_guard_tree_filter` | ok | 1.920 | 267 |  | 0.000 | 0.000 |  |
| `siphash_rotate64_mixer` | ok | 7.273 | 939 |  | 0.000 | 0.000 |  |
| `packet_record_bounds_window` | ok | 1.654 | 222 |  | 0.000 | 0.000 |  |
| `flow_record_field_scan` | ok | 1.877 | 252 |  | 0.000 | 0.000 |  |
| `packed_header_bitfield_decode` | ok | 7.368 | 1015 |  | 0.000 | 0.000 |  |
| `bpftrace_string_search_prefix_scan` | ok | 2.910 | 328 |  | 0.000 | 0.000 |  |
| `tracee_syscall_name_table_lookup` | ok | 3.478 | 594 |  | 0.000 | 0.000 |  |
| `tracee_http_method_prefix_detect` | ok | 3.386 | 358 |  | 0.000 | 0.000 |  |
| `cilium_socket_lb_service_select` | ok | 1.947 | 293 |  | 0.000 | 0.000 |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 2.300 | 356 |  | 0.000 | 0.000 |  |
| `tetragon_process_event_arg_filter` | ok | 6.298 | 1004 |  | 0.000 | 0.000 |  |
| `otel_stack_frame_unwind_scan` | ok | 1.556 | 259 |  | 0.000 | 0.000 |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 1.941 | 290 |  | 0.000 | 0.000 |  |
| `packet_toeplitz_rss_hash` | ok | 2.018 | 357 |  | 0.000 | 0.000 |  |
| `bpftrace_comm_key_fnv_hash` | ok | 5.799 | 580 |  | 0.000 | 0.000 |  |
| `tc_packet_checksum_fold` | ok | 1.037 | 216 |  | 0.000 | 0.000 |  |
| `cgroup_skb_hash_chain` | ok | 5.452 | 814 |  | 0.000 | 0.000 |  |

## AArch64 negative1 after final SP change

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `unchecked_packet_read` | ok | 0.144 | 106 |  | 0.000 | 0.000 |  |
