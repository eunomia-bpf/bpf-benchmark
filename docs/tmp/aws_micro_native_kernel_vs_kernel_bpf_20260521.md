# AWS micro native_kernel vs kernel_bpf, 2026-05-21

`kernel_bpf` is the micro runner `kernel` runtime. Times are per-run `exec_ns` from
`SAMPLES=1 WARMUPS=0 INNER_REPEAT=10`; `native/kernel` is
`native_kernel exec_ns / kernel_bpf exec_ns`, so values below 1.0 mean
`native_kernel` was faster for that row.

Validated result paths:

- x86 pure 29: `micro/results/aws_x86_micro_20260521_021842_488173`
- x86 stage2 13: `micro/results/aws_x86_micro_20260521_022752_872114`
- arm64 pure 29: `micro/results/aws_arm64_micro_20260521_023726_510990`
- arm64 stage2 13: `micro/results/aws_arm64_micro_20260521_024750_386500`

All four runs completed, covered the expected benchmark count, and had zero
`result`/`retval` mismatches between `native_kernel` and `kernel_bpf`.

## x86

| suite | bench | native_kernel ns | kernel_bpf ns | native/kernel | faster |
| --- | --- | ---: | ---: | ---: | --- |
| pure | `simple` | 115 | 134 | 0.858 | native_kernel |
| pure | `simple_packet` | 142 | 102 | 1.392 | kernel_bpf |
| pure | `bitmap_popcount_scan` | 718 | 1,462 | 0.491 | native_kernel |
| pure | `sorted_rule_binary_search` | 672 | 1,922 | 0.350 | native_kernel |
| pure | `bcc_runqlat_log2_histogram_bucket` | 3,984 | 3,289 | 1.211 | kernel_bpf |
| pure | `trace_event_type_switch_dispatch` | 1,512 | 1,420 | 1.065 | kernel_bpf |
| pure | `packet_checksum_fold` | 17,859 | 22,100 | 0.808 | native_kernel |
| pure | `payload_prefix_memcmp_scan` | 300 | 360 | 0.833 | native_kernel |
| pure | `packet_vlan_tcpopt_parser` | 132 | 150 | 0.880 | native_kernel |
| pure | `bpf_local_call_fanout_dispatch` | 333 | 421 | 0.791 | native_kernel |
| pure | `flow_5tuple_rss_hash` | 128 | 152 | 0.842 | native_kernel |
| pure | `katran_lb_consistent_hash_select` | 171 | 240 | 0.713 | native_kernel |
| pure | `cilium_policy_guard_tree_filter` | 331 | 314 | 1.054 | kernel_bpf |
| pure | `siphash_rotate64_mixer` | 216 | 240 | 0.900 | native_kernel |
| pure | `packet_record_bounds_window` | 294 | 398 | 0.739 | native_kernel |
| pure | `flow_record_field_scan` | 296 | 302 | 0.980 | native_kernel |
| pure | `packed_header_bitfield_decode` | 612 | 619 | 0.989 | native_kernel |
| pure | `bpftrace_string_search_prefix_scan` | 614 | 745 | 0.824 | native_kernel |
| pure | `tracee_syscall_name_table_lookup` | 516 | 536 | 0.963 | native_kernel |
| pure | `tracee_http_method_prefix_detect` | 293 | 275 | 1.065 | kernel_bpf |
| pure | `cilium_socket_lb_service_select` | 534 | 1,283 | 0.416 | native_kernel |
| pure | `bcc_tcpconnect_ipv4_tuple_filter` | 382 | 626 | 0.610 | native_kernel |
| pure | `tetragon_process_event_arg_filter` | 686 | 656 | 1.046 | kernel_bpf |
| pure | `otel_stack_frame_unwind_scan` | 289 | 494 | 0.585 | native_kernel |
| pure | `cilium_ct_nat_tuple_rewrite` | 389 | 556 | 0.700 | native_kernel |
| pure | `packet_toeplitz_rss_hash` | 932 | 973 | 0.958 | native_kernel |
| pure | `bpftrace_comm_key_fnv_hash` | 963 | 920 | 1.047 | kernel_bpf |
| pure | `tc_packet_checksum_fold` | 17,381 | 26,872 | 0.647 | native_kernel |
| pure | `cgroup_skb_hash_chain` | 336 | 638 | 0.527 | native_kernel |
| stage2 | `helper_only_uid_gid` | 185 | 175 | 1.057 | kernel_bpf |
| stage2 | `helper_chain_simple` | 654 | 564 | 1.160 | kernel_bpf |
| stage2 | `map_array_lookup` | 257 | 229 | 1.122 | kernel_bpf |
| stage2 | `map_array_index_packet` | 239 | 281 | 0.851 | native_kernel |
| stage2 | `map_hash_lookup` | 838 | 372 | 2.253 | kernel_bpf |
| stage2 | `map_hash_str_key` | 364 | 403 | 0.903 | native_kernel |
| stage2 | `map_percpu_array` | 348 | 159 | 2.189 | kernel_bpf |
| stage2 | `map_lru_hash_counter` | 756 | 386 | 1.959 | kernel_bpf |
| stage2 | `map_percpu_hash_counter` | 382 | 395 | 0.967 | native_kernel |
| stage2 | `combined_helper_map` | 843 | 255 | 3.306 | kernel_bpf |
| stage2 | `multi_map_policy` | 1,052 | 483 | 2.178 | kernel_bpf |
| stage2 | `packet_5tuple_classify` | 6,368 | 351 | 18.142 | kernel_bpf |
| stage2 | `stats_mixed_helpers` | 5,869 | 46,947 | 0.125 | native_kernel |

## arm64

| suite | bench | native_kernel ns | kernel_bpf ns | native/kernel | faster |
| --- | --- | ---: | ---: | ---: | --- |
| pure | `simple` | 22 | 54 | 0.407 | native_kernel |
| pure | `simple_packet` | 19 | 75 | 0.253 | native_kernel |
| pure | `bitmap_popcount_scan` | 1,649 | 2,235 | 0.738 | native_kernel |
| pure | `sorted_rule_binary_search` | 761 | 2,032 | 0.375 | native_kernel |
| pure | `bcc_runqlat_log2_histogram_bucket` | 2,471 | 7,046 | 0.351 | native_kernel |
| pure | `trace_event_type_switch_dispatch` | 972 | 903 | 1.076 | kernel_bpf |
| pure | `packet_checksum_fold` | 26,126 | 40,006 | 0.653 | native_kernel |
| pure | `payload_prefix_memcmp_scan` | 184 | 352 | 0.523 | native_kernel |
| pure | `packet_vlan_tcpopt_parser` | 35 | 120 | 0.292 | native_kernel |
| pure | `bpf_local_call_fanout_dispatch` | 167 | 541 | 0.309 | native_kernel |
| pure | `flow_5tuple_rss_hash` | 33 | 128 | 0.258 | native_kernel |
| pure | `katran_lb_consistent_hash_select` | 45 | 174 | 0.259 | native_kernel |
| pure | `cilium_policy_guard_tree_filter` | 153 | 339 | 0.451 | native_kernel |
| pure | `siphash_rotate64_mixer` | 60 | 329 | 0.182 | native_kernel |
| pure | `packet_record_bounds_window` | 171 | 441 | 0.388 | native_kernel |
| pure | `flow_record_field_scan` | 150 | 260 | 0.577 | native_kernel |
| pure | `packed_header_bitfield_decode` | 513 | 928 | 0.553 | native_kernel |
| pure | `bpftrace_string_search_prefix_scan` | 379 | 724 | 0.523 | native_kernel |
| pure | `tracee_syscall_name_table_lookup` | 392 | 588 | 0.667 | native_kernel |
| pure | `tracee_http_method_prefix_detect` | 73 | 141 | 0.518 | native_kernel |
| pure | `cilium_socket_lb_service_select` | 354 | 1,197 | 0.296 | native_kernel |
| pure | `bcc_tcpconnect_ipv4_tuple_filter` | 187 | 420 | 0.445 | native_kernel |
| pure | `tetragon_process_event_arg_filter` | 304 | 776 | 0.392 | native_kernel |
| pure | `otel_stack_frame_unwind_scan` | 142 | 582 | 0.244 | native_kernel |
| pure | `cilium_ct_nat_tuple_rewrite` | 242 | 618 | 0.392 | native_kernel |
| pure | `packet_toeplitz_rss_hash` | 565 | 916 | 0.617 | native_kernel |
| pure | `bpftrace_comm_key_fnv_hash` | 1,307 | 1,632 | 0.801 | native_kernel |
| pure | `tc_packet_checksum_fold` | 26,043 | 40,804 | 0.638 | native_kernel |
| pure | `cgroup_skb_hash_chain` | 389 | 955 | 0.407 | native_kernel |
| stage2 | `helper_only_uid_gid` | 37 | 95 | 0.389 | native_kernel |
| stage2 | `helper_chain_simple` | 264 | 577 | 0.458 | native_kernel |
| stage2 | `map_array_lookup` | 39 | 100 | 0.390 | native_kernel |
| stage2 | `map_array_index_packet` | 37 | 109 | 0.339 | native_kernel |
| stage2 | `map_hash_lookup` | 164 | 221 | 0.742 | native_kernel |
| stage2 | `map_hash_str_key` | 145 | 259 | 0.560 | native_kernel |
| stage2 | `map_percpu_array` | 37 | 128 | 0.289 | native_kernel |
| stage2 | `map_lru_hash_counter` | 258 | 540 | 0.478 | native_kernel |
| stage2 | `map_percpu_hash_counter` | 132 | 305 | 0.433 | native_kernel |
| stage2 | `combined_helper_map` | 61 | 243 | 0.251 | native_kernel |
| stage2 | `multi_map_policy` | 166 | 722 | 0.230 | native_kernel |
| stage2 | `packet_5tuple_classify` | 140 | 311 | 0.450 | native_kernel |
| stage2 | `stats_mixed_helpers` | 247 | 454 | 0.544 | native_kernel |
