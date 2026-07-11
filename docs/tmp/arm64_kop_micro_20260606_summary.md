# arm64 kop micro 2026-06-06

- Artifact: `micro/results/aws_arm64_micro_20260606_001225_821028/details/result.json`
- Generated at: 2026-06-06T00:12:25.821028+00:00
- Benchmarks: 29
- Mismatches: 0
- Speedup geomean: 1.208x
- KOperation-bearing geomean: 1.222x over 27 benchmarks
- Wins / losses / ties: 24 / 2 / 3
- Matched/applied sites, median sample: 308 / 308
- Matched/applied calls, all samples: 924 / 924
- Code-size ratio geomean: 0.879x
- KOperation calls by name, all samples: bpf_arm64_extr_x=387, bpf_arm64_ldr_w=198, bpf_arm64_ubfm_x=144, bpf_arm64_ldrh=114, bpf_arm64_rev16_w=39, bpf_arm64_stp_x=21, bpf_arm64_rev_w=15, bpf_arm64_ldp_x=6

## Helpers/maps rerun

- Artifact: `micro/results/aws_arm64_micro_20260606_160621_594885/details/result.json`
- Generated at: 2026-06-06T16:06:21.594885+00:00
- Benchmarks: 13
- Mismatches: 0
- Speedup geomean: 1.009x
- KOperation-bearing geomean: N/A
- Wins / losses / ties: 3 / 0 / 10
- Matched/applied sites, median sample: 0 / 0
- Matched/applied calls, all samples: 0 / 0
- Code-size ratio geomean: 1.000x
- KOperation calls by name, all samples: -

## Per-case results

| Case | Kernel ns | Kernel ReJIT ns | Speedup | Applied median sample | KOperation calls by name, all samples |
|---|---:|---:|---:|---:|---|
| `simple` | 15 | 14 | 1.071x | 0 | - |
| `simple_packet` | 14 | 14 | 1.000x | 0 | - |
| `bitmap_popcount_scan` | 2190 | 2266 | 0.966x | 2 | bpf_arm64_ldr_w=6 |
| `sorted_rule_binary_search` | 1942 | 1937 | 1.003x | 2 | bpf_arm64_ldr_w=6 |
| `bcc_runqlat_log2_histogram_bucket` | 4461 | 3845 | 1.160x | 3 | bpf_arm64_ldr_w=6, bpf_arm64_ubfm_x=3 |
| `trace_event_type_switch_dispatch` | 657 | 646 | 1.017x | 2 | bpf_arm64_ldr_w=6 |
| `packet_checksum_fold` | 39569 | 33024 | 1.198x | 3 | bpf_arm64_ldr_w=6, bpf_arm64_ldrh=3 |
| `payload_prefix_memcmp_scan` | 290 | 246 | 1.179x | 3 | bpf_arm64_extr_x=6, bpf_arm64_ldr_w=3 |
| `packet_vlan_tcpopt_parser` | 43 | 41 | 1.049x | 18 | bpf_arm64_ldrh=21, bpf_arm64_rev16_w=21, bpf_arm64_ldr_w=6, bpf_arm64_rev_w=6 |
| `bpf_local_call_fanout_dispatch` | 357 | 302 | 1.182x | 21 | bpf_arm64_extr_x=30, bpf_arm64_ldr_w=18, bpf_arm64_ldrh=15 |
| `flow_5tuple_rss_hash` | 52 | 47 | 1.106x | 19 | bpf_arm64_ubfm_x=39, bpf_arm64_ldrh=6, bpf_arm64_rev16_w=6, bpf_arm64_ldr_w=3, bpf_arm64_rev_w=3 |
| `katran_lb_consistent_hash_select` | 68 | 60 | 1.133x | 34 | bpf_arm64_ubfm_x=75, bpf_arm64_ldrh=12, bpf_arm64_rev16_w=9, bpf_arm64_ldr_w=6 |
| `cilium_policy_guard_tree_filter` | 249 | 203 | 1.227x | 2 | bpf_arm64_ldr_w=6 |
| `siphash_rotate64_mixer` | 194 | 102 | 1.902x | 124 | bpf_arm64_extr_x=348, bpf_arm64_ldrh=21, bpf_arm64_ldr_w=3 |
| `packet_record_bounds_window` | 355 | 279 | 1.272x | 6 | bpf_arm64_ldr_w=9, bpf_arm64_ldrh=9 |
| `flow_record_field_scan` | 194 | 177 | 1.096x | 1 | bpf_arm64_ldp_x=3 |
| `packed_header_bitfield_decode` | 857 | 756 | 1.134x | 12 | bpf_arm64_ubfm_x=27, bpf_arm64_ldr_w=6, bpf_arm64_stp_x=3 |
| `bpftrace_string_search_prefix_scan` | 642 | 412 | 1.558x | 2 | bpf_arm64_extr_x=3, bpf_arm64_ldr_w=3 |
| `tracee_syscall_name_table_lookup` | 370 | 315 | 1.175x | 1 | bpf_arm64_ldr_w=3 |
| `tracee_http_method_prefix_detect` | 59 | 57 | 1.035x | 2 | bpf_arm64_ldr_w=6 |
| `cilium_socket_lb_service_select` | 1126 | 666 | 1.691x | 7 | bpf_arm64_ldr_w=15, bpf_arm64_ldrh=6 |
| `bcc_tcpconnect_ipv4_tuple_filter` | 341 | 210 | 1.624x | 8 | bpf_arm64_ldr_w=15, bpf_arm64_ldrh=6, bpf_arm64_stp_x=3 |
| `tetragon_process_event_arg_filter` | 573 | 427 | 1.342x | 6 | bpf_arm64_ldr_w=12, bpf_arm64_ldrh=3, bpf_arm64_stp_x=3 |
| `otel_stack_frame_unwind_scan` | 411 | 340 | 1.209x | 6 | bpf_arm64_ldr_w=9, bpf_arm64_stp_x=6, bpf_arm64_ldp_x=3 |
| `cilium_ct_nat_tuple_rewrite` | 495 | 334 | 1.482x | 10 | bpf_arm64_ldr_w=21, bpf_arm64_ldrh=6, bpf_arm64_stp_x=3 |
| `packet_toeplitz_rss_hash` | 479 | 412 | 1.163x | 6 | bpf_arm64_ldr_w=6, bpf_arm64_rev_w=6, bpf_arm64_ldrh=3, bpf_arm64_rev16_w=3 |
| `bpftrace_comm_key_fnv_hash` | 1581 | 1835 | 0.862x | 3 | bpf_arm64_ldr_w=6, bpf_arm64_stp_x=3 |
| `tc_packet_checksum_fold` | 39651 | 33102 | 1.198x | 3 | bpf_arm64_ldr_w=6, bpf_arm64_ldrh=3 |
| `cgroup_skb_hash_chain` | 965 | 597 | 1.616x | 2 | bpf_arm64_ldr_w=6 |
