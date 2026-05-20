# ReverseSim Full Micro Runtime With Native Kernel: 2026-05-20 04:44 UTC

Command:

```bash
make micro RUNTIMES="native kernel native_lab" SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000
```

Raw result:

- `micro/results/x86_kvm_micro_20260520_044439_120822/metadata.json`

Purpose:

- Verify the native kernel (`native_lab`) result channel fix for TC and cgroup
  skb programs.
- Compare native userspace, kernel eBPF, and native kernel execution on the
  same full 29-program micro dataset.

Fix validated by this run:

- The native kernel runner (`native_lab_runner`) now reads TC/cgroup benchmark results from
  `ctx_out.cb[0..1]`, matching kernel BPF `__sk_buff.cb[]` semantics and the
  proof loader.
- The earlier failed full run
  `micro/results/x86_kvm_micro_20260520_040517_640313/metadata.json` failed
  `cgroup_skb_hash_chain/native_lab` because it read the result from packet
  bytes instead of skb cb. That failure is now fixed.

Summary:

| Population | Programs | Ratio | Geomean | Speedup | Wins | Losses | Ties |
| --- | ---: | --- | ---: | ---: | ---: | ---: | ---: |
| All micro programs | 29 | native userspace/kernel | 0.588 | 1.70x | 27 | 2 | 0 |
| All micro programs | 29 | native kernel/kernel | 0.707 | 1.41x | 24 | 4 | 1 |
| All micro programs | 29 | native kernel/native userspace | 1.203 | 0.83x | 3 | 23 | 3 |
| Excluding `simple` and `simple_packet` | 27 | native userspace/kernel | 0.649 | 1.54x | 25 | 2 | 0 |
| Excluding `simple` and `simple_packet` | 27 | native kernel/kernel | 0.689 | 1.45x | 23 | 3 | 1 |
| Excluding `simple` and `simple_packet` | 27 | native kernel/native userspace | 1.062 | 0.94x | 3 | 21 | 3 |

Per-program median runtime table:

| Micro program | Native userspace ns | Kernel eBPF ns | Native kernel ns | Native userspace/kernel | Native kernel/kernel | Native kernel/native userspace |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `simple` | 1.0 | 7.0 | 6.0 | 7.00x | 1.17x | 6.00x |
| `simple_packet` | 1.0 | 6.0 | 7.0 | 6.00x | 0.86x | 7.00x |
| `bitmap_popcount_scan` | 464.0 | 1113.0 | 466.0 | 2.40x | 2.39x | 1.00x |
| `sorted_rule_binary_search` | 302.0 | 532.0 | 307.0 | 1.76x | 1.73x | 1.02x |
| `bcc_runqlat_log2_histogram_bucket` | 1075.0 | 1209.0 | 1149.0 | 1.12x | 1.05x | 1.07x |
| `trace_event_type_switch_dispatch` | 278.0 | 282.0 | 278.0 | 1.01x | 1.01x | 1.00x |
| `packet_checksum_fold` | 13358.0 | 17635.0 | 13337.0 | 1.32x | 1.32x | 1.00x |
| `payload_prefix_memcmp_scan` | 49.0 | 87.0 | 51.0 | 1.78x | 1.71x | 1.04x |
| `packet_vlan_tcpopt_parser` | 7.0 | 13.0 | 10.0 | 1.86x | 1.30x | 1.43x |
| `bpf_local_call_fanout_dispatch` | 68.0 | 123.0 | 70.0 | 1.81x | 1.76x | 1.03x |
| `flow_5tuple_rss_hash` | 8.0 | 16.0 | 10.0 | 2.00x | 1.60x | 1.25x |
| `katran_lb_consistent_hash_select` | 11.0 | 21.0 | 14.0 | 1.91x | 1.50x | 1.27x |
| `cilium_policy_guard_tree_filter` | 36.0 | 75.0 | 40.0 | 2.08x | 1.88x | 1.11x |
| `siphash_rotate64_mixer` | 27.0 | 54.0 | 29.0 | 2.00x | 1.86x | 1.07x |
| `packet_record_bounds_window` | 62.0 | 118.0 | 64.0 | 1.90x | 1.84x | 1.03x |
| `flow_record_field_scan` | 48.0 | 63.0 | 52.0 | 1.31x | 1.21x | 1.08x |
| `packed_header_bitfield_decode` | 199.0 | 223.0 | 199.0 | 1.12x | 1.12x | 1.00x |
| `bpftrace_string_search_prefix_scan` | 107.0 | 187.0 | 111.0 | 1.75x | 1.68x | 1.04x |
| `tracee_syscall_name_table_lookup` | 103.0 | 118.0 | 102.0 | 1.15x | 1.16x | 0.99x |
| `tracee_http_method_prefix_detect` | 16.0 | 18.0 | 18.0 | 1.12x | 1.00x | 1.12x |
| `cilium_socket_lb_service_select` | 169.0 | 371.0 | 173.0 | 2.20x | 2.14x | 1.02x |
| `bcc_tcpconnect_ipv4_tuple_filter` | 63.0 | 105.0 | 64.0 | 1.67x | 1.64x | 1.02x |
| `tetragon_process_event_arg_filter` | 105.0 | 153.0 | 110.0 | 1.46x | 1.39x | 1.05x |
| `otel_stack_frame_unwind_scan` | 39.0 | 112.0 | 43.0 | 2.87x | 2.60x | 1.10x |
| `cilium_ct_nat_tuple_rewrite` | 75.0 | 147.0 | 79.0 | 1.96x | 1.86x | 1.05x |
| `packet_toeplitz_rss_hash` | 297.0 | 229.0 | 283.0 | 0.77x | 0.81x | 0.95x |
| `bpftrace_comm_key_fnv_hash` | 433.0 | 435.0 | 437.0 | 1.00x | 1.00x | 1.01x |
| `tc_packet_checksum_fold` | 13357.0 | 17635.0 | 13357.0 | 1.32x | 1.32x | 1.00x |
| `cgroup_skb_hash_chain` | 288.0 | 285.0 | 291.0 | 0.99x | 0.98x | 1.01x |
