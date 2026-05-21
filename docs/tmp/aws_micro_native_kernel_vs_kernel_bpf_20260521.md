# AWS micro native_kernel vs kernel_bpf, 2026-05-21

`kernel_bpf` is the micro runner `kernel` runtime. Times are per-run `exec_ns`.
For x86, the table uses the median of `SAMPLES=3 INNER_REPEAT=100000`; for arm64,
the table preserves the earlier smoke data with `SAMPLES=1 WARMUPS=0 INNER_REPEAT=10`.
`speedup` is `kernel_bpf exec_ns / native_kernel exec_ns`, so values above 1.0 mean
`native_kernel` was faster for that row.

Validated result paths:

- x86 pure: `micro/results/aws_x86_micro_20260521_032223_857289`; status=completed, programs=29, samples=[3], inner=[100000], mismatches=0
- x86 stage2: `micro/results/aws_x86_micro_20260521_033443_371646`; status=completed, programs=13, samples=[3], inner=[100000], mismatches=0
- x86 KVM pure cross-check: `micro/results/x86_kvm_micro_20260521_035600_826130`; status=completed, programs=29, samples=[3], inner=[100000], mismatches=0
- x86 KVM stage2 cross-check: `micro/results/x86_kvm_micro_20260521_040152_335017`; status=completed, programs=13, samples=[3], inner=[100000], mismatches=0
- x86 KVM previous native-kernel baseline: `micro/results/x86_kvm_micro_20260520_044439_120822`; status=completed, programs=29, samples=[3], inner=[100000], mismatches=0
- arm64 pure: `micro/results/aws_arm64_micro_20260521_023726_510990`; status=completed, programs=29, samples=[1], inner=[10], mismatches=0
- arm64 stage2: `micro/results/aws_arm64_micro_20260521_024750_386500`; status=completed, programs=13, samples=[1], inner=[10], mismatches=0

![AWS micro native_kernel speedup over kernel_bpf](../figures/aws-micro-native-kernel-vs-kernel-bpf-20260521.png)

![Micro native runtime KVM/AWS trend](../figures/micro-native-kernel-kvm-aws-trend-20260521.png)

## Trend read

The x86 pure trend does not show a native-kernel regression against the previous
KVM baseline: old KVM `native_lab` pure was 1.414x and current KVM
`native_kernel` pure is 1.425x. The earlier 1.6x-1.7x number came from the
separate native userspace runtime, not from the in-kernel native runtime.

The outlier is x86 AWS stage2 helper/map performance. It remains slow even with
`SAMPLES=3 INNER_REPEAT=100000`, but the same stage2 suite on KVM is faster than
kernel eBPF. That points to an AWS x86 environment / CPU / helper-call-path
interaction rather than a broad x86 native-kernel regression.

| result | suite | runtime | samples | inner | speedup | native/kernel/tie |
| --- | --- | --- | ---: | ---: | ---: | ---: |
| old x86 KVM | pure | `native_lab` | 3 | 100000 | 1.414x | 24 / 4 / 1 |
| current x86 KVM | pure | `native_kernel` | 3 | 100000 | 1.425x | 24 / 4 / 1 |
| x86 AWS smoke | pure | `native_kernel` | 1 | 10 | 1.249x | 22 / 7 / 0 |
| x86 AWS current | pure | `native_kernel` | 3 | 100000 | 1.503x | 26 / 3 / 0 |
| x86 AWS smoke | stage2 helpers/maps | `native_kernel` | 1 | 10 | 0.676x | 4 / 9 / 0 |
| x86 AWS current | stage2 helpers/maps | `native_kernel` | 3 | 100000 | 0.690x | 0 / 12 / 1 |
| x86 KVM current | stage2 helpers/maps | `native_kernel` | 3 | 100000 | 1.300x | 9 / 2 / 2 |
| arm64 AWS smoke | pure | `native_kernel` | 1 | 10 | 2.318x | 28 / 1 / 0 |
| arm64 AWS smoke | stage2 helpers/maps | `native_kernel` | 1 | 10 | 2.460x | 13 / 0 / 0 |

## x86

Summary: native_kernel wins 26/42; geomean speedup `kernel_bpf/native_kernel` = 1.181x.

| suite | bench | native_kernel ns | kernel_bpf ns | speedup | faster |
| --- | --- | ---: | ---: | ---: | --- |
| pure | `simple` | 10 | 12 | 1.200 | native_kernel |
| pure | `simple_packet` | 10 | 11 | 1.100 | native_kernel |
| pure | `bitmap_popcount_scan` | 505 | 1,366 | 2.705 | native_kernel |
| pure | `sorted_rule_binary_search` | 544 | 1,233 | 2.267 | native_kernel |
| pure | `bcc_runqlat_log2_histogram_bucket` | 2,827 | 3,195 | 1.130 | native_kernel |
| pure | `trace_event_type_switch_dispatch` | 405 | 552 | 1.363 | native_kernel |
| pure | `packet_checksum_fold` | 16,979 | 21,670 | 1.276 | native_kernel |
| pure | `payload_prefix_memcmp_scan` | 131 | 213 | 1.626 | native_kernel |
| pure | `packet_vlan_tcpopt_parser` | 28 | 32 | 1.143 | native_kernel |
| pure | `bpf_local_call_fanout_dispatch` | 110 | 237 | 2.155 | native_kernel |
| pure | `flow_5tuple_rss_hash` | 24 | 33 | 1.375 | native_kernel |
| pure | `katran_lb_consistent_hash_select` | 33 | 47 | 1.424 | native_kernel |
| pure | `cilium_policy_guard_tree_filter` | 129 | 186 | 1.442 | native_kernel |
| pure | `siphash_rotate64_mixer` | 48 | 96 | 2.000 | native_kernel |
| pure | `packet_record_bounds_window` | 135 | 251 | 1.859 | native_kernel |
| pure | `flow_record_field_scan` | 137 | 129 | 0.942 | kernel_bpf |
| pure | `packed_header_bitfield_decode` | 461 | 499 | 1.082 | native_kernel |
| pure | `bpftrace_string_search_prefix_scan` | 314 | 560 | 1.783 | native_kernel |
| pure | `tracee_syscall_name_table_lookup` | 278 | 328 | 1.180 | native_kernel |
| pure | `tracee_http_method_prefix_detect` | 47 | 44 | 0.936 | kernel_bpf |
| pure | `cilium_socket_lb_service_select` | 455 | 1,117 | 2.455 | native_kernel |
| pure | `bcc_tcpconnect_ipv4_tuple_filter` | 162 | 257 | 1.586 | native_kernel |
| pure | `tetragon_process_event_arg_filter` | 267 | 398 | 1.491 | native_kernel |
| pure | `otel_stack_frame_unwind_scan` | 118 | 286 | 2.424 | native_kernel |
| pure | `cilium_ct_nat_tuple_rewrite` | 176 | 346 | 1.966 | native_kernel |
| pure | `packet_toeplitz_rss_hash` | 368 | 462 | 1.255 | native_kernel |
| pure | `bpftrace_comm_key_fnv_hash` | 783 | 771 | 0.985 | kernel_bpf |
| pure | `tc_packet_checksum_fold` | 16,896 | 26,935 | 1.594 | native_kernel |
| pure | `cgroup_skb_hash_chain` | 315 | 578 | 1.835 | native_kernel |
| stage2 | `helper_only_uid_gid` | 23 | 23 | 1.000 | tie |
| stage2 | `helper_chain_simple` | 159 | 133 | 0.836 | kernel_bpf |
| stage2 | `map_array_lookup` | 51 | 25 | 0.490 | kernel_bpf |
| stage2 | `map_array_index_packet` | 50 | 24 | 0.480 | kernel_bpf |
| stage2 | `map_hash_lookup` | 85 | 73 | 0.859 | kernel_bpf |
| stage2 | `map_hash_str_key` | 86 | 75 | 0.872 | kernel_bpf |
| stage2 | `map_percpu_array` | 58 | 25 | 0.431 | kernel_bpf |
| stage2 | `map_lru_hash_counter` | 174 | 143 | 0.822 | kernel_bpf |
| stage2 | `map_percpu_hash_counter` | 97 | 68 | 0.701 | kernel_bpf |
| stage2 | `combined_helper_map` | 69 | 42 | 0.609 | kernel_bpf |
| stage2 | `multi_map_policy` | 162 | 96 | 0.593 | kernel_bpf |
| stage2 | `packet_5tuple_classify` | 92 | 78 | 0.848 | kernel_bpf |
| stage2 | `stats_mixed_helpers` | 197 | 142 | 0.721 | kernel_bpf |

## arm64

Summary: native_kernel wins 41/42; geomean speedup `kernel_bpf/native_kernel` = 2.361x.

| suite | bench | native_kernel ns | kernel_bpf ns | speedup | faster |
| --- | --- | ---: | ---: | ---: | --- |
| pure | `simple` | 22 | 54 | 2.455 | native_kernel |
| pure | `simple_packet` | 19 | 75 | 3.947 | native_kernel |
| pure | `bitmap_popcount_scan` | 1,649 | 2,235 | 1.355 | native_kernel |
| pure | `sorted_rule_binary_search` | 761 | 2,032 | 2.670 | native_kernel |
| pure | `bcc_runqlat_log2_histogram_bucket` | 2,471 | 7,046 | 2.851 | native_kernel |
| pure | `trace_event_type_switch_dispatch` | 972 | 903 | 0.929 | kernel_bpf |
| pure | `packet_checksum_fold` | 26,126 | 40,006 | 1.531 | native_kernel |
| pure | `payload_prefix_memcmp_scan` | 184 | 352 | 1.913 | native_kernel |
| pure | `packet_vlan_tcpopt_parser` | 35 | 120 | 3.429 | native_kernel |
| pure | `bpf_local_call_fanout_dispatch` | 167 | 541 | 3.240 | native_kernel |
| pure | `flow_5tuple_rss_hash` | 33 | 128 | 3.879 | native_kernel |
| pure | `katran_lb_consistent_hash_select` | 45 | 174 | 3.867 | native_kernel |
| pure | `cilium_policy_guard_tree_filter` | 153 | 339 | 2.216 | native_kernel |
| pure | `siphash_rotate64_mixer` | 60 | 329 | 5.483 | native_kernel |
| pure | `packet_record_bounds_window` | 171 | 441 | 2.579 | native_kernel |
| pure | `flow_record_field_scan` | 150 | 260 | 1.733 | native_kernel |
| pure | `packed_header_bitfield_decode` | 513 | 928 | 1.809 | native_kernel |
| pure | `bpftrace_string_search_prefix_scan` | 379 | 724 | 1.910 | native_kernel |
| pure | `tracee_syscall_name_table_lookup` | 392 | 588 | 1.500 | native_kernel |
| pure | `tracee_http_method_prefix_detect` | 73 | 141 | 1.932 | native_kernel |
| pure | `cilium_socket_lb_service_select` | 354 | 1,197 | 3.381 | native_kernel |
| pure | `bcc_tcpconnect_ipv4_tuple_filter` | 187 | 420 | 2.246 | native_kernel |
| pure | `tetragon_process_event_arg_filter` | 304 | 776 | 2.553 | native_kernel |
| pure | `otel_stack_frame_unwind_scan` | 142 | 582 | 4.099 | native_kernel |
| pure | `cilium_ct_nat_tuple_rewrite` | 242 | 618 | 2.554 | native_kernel |
| pure | `packet_toeplitz_rss_hash` | 565 | 916 | 1.621 | native_kernel |
| pure | `bpftrace_comm_key_fnv_hash` | 1,307 | 1,632 | 1.249 | native_kernel |
| pure | `tc_packet_checksum_fold` | 26,043 | 40,804 | 1.567 | native_kernel |
| pure | `cgroup_skb_hash_chain` | 389 | 955 | 2.455 | native_kernel |
| stage2 | `helper_only_uid_gid` | 37 | 95 | 2.568 | native_kernel |
| stage2 | `helper_chain_simple` | 264 | 577 | 2.186 | native_kernel |
| stage2 | `map_array_lookup` | 39 | 100 | 2.564 | native_kernel |
| stage2 | `map_array_index_packet` | 37 | 109 | 2.946 | native_kernel |
| stage2 | `map_hash_lookup` | 164 | 221 | 1.348 | native_kernel |
| stage2 | `map_hash_str_key` | 145 | 259 | 1.786 | native_kernel |
| stage2 | `map_percpu_array` | 37 | 128 | 3.459 | native_kernel |
| stage2 | `map_lru_hash_counter` | 258 | 540 | 2.093 | native_kernel |
| stage2 | `map_percpu_hash_counter` | 132 | 305 | 2.311 | native_kernel |
| stage2 | `combined_helper_map` | 61 | 243 | 3.984 | native_kernel |
| stage2 | `multi_map_policy` | 166 | 722 | 4.349 | native_kernel |
| stage2 | `packet_5tuple_classify` | 140 | 311 | 2.221 | native_kernel |
| stage2 | `stats_mixed_helpers` | 247 | 454 | 1.838 | native_kernel |
