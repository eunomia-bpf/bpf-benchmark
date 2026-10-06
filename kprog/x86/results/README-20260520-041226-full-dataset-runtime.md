# ReverseSim Full Micro Runtime: 2026-05-20 04:12 UTC

Command:

```bash
make micro RUNTIMES="native kernel" SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000
```

Raw result:

- `micro/results/x86_kvm_micro_20260520_041226_759303/metadata.json`

Proof result for the same generated dataset/direct BPF dumps:

- `native-sim/x86/results/README-20260520-041226-full-proof.md`

Summary:

| Population | Programs | Native userspace/kernel geomean | Native userspace speedup | Wins | Losses |
| --- | ---: | ---: | ---: | ---: | ---: |
| All micro programs | 29 | 0.594 | 1.68x | 27 | 2 |
| Excluding `simple` and `simple_packet` | 27 | 0.656 | 1.53x | 25 | 2 |
| Excluding baselines, per-program sample medians | 27 | 0.649 | 1.54x | 25 | 2 |

Comparison to the previous full native userspace / kernel eBPF / LLVM-BPF run:

- Previous raw result: `micro/results/x86_kvm_micro_20260520_023753_401581/metadata.json`
- Previous all-program native userspace speedup: `1.71x`; current: `1.68x`.
- Previous non-baseline native userspace speedup: `1.55x`; current: `1.53x`.
- The main regression is `payload_prefix_memcmp_scan`: source shaping made
  the kernel eBPF version faster, so native userspace speedup dropped from `2.03x` to
  `1.29x` in this full run. A targeted SAMPLES=5 run measured the same shaped
  source at native userspace `48 ns`, kernel eBPF `82.2 ns`, native kernel
  `51 ns`.

Comparison to the older pre-local-simulator full run:

- Older raw result: `micro/results/x86_kvm_micro_20260520_012923_324142/metadata.json`
- Older all-program native userspace speedup was `0.19x` because native
  userspace was slower than kernel eBPF on 27/29 programs. Current all-program
  native userspace speedup is `1.68x`.
- Older non-baseline native userspace speedup was `0.21x`; current
  non-baseline native userspace speedup is `1.53x`.

The earlier failed full native userspace / kernel eBPF / native kernel attempt
is also recorded:

- `micro/results/x86_kvm_micro_20260520_040517_640313/metadata.json`
- It completed native userspace / kernel eBPF / native kernel for 28 programs,
  but failed raw runtime case `cgroup_skb_hash_chain/native_lab` warmup with
  result `0` instead of
  `12027228624407116210`.
- Root cause: the native kernel runner (`native_lab_runner`) read TC/cgroup
  benchmark results from packet bytes, while the kernel and proof paths use
  BPF-visible `__sk_buff.cb[]`.
- Fixed full native userspace / kernel eBPF / native kernel run:
  `micro/results/x86_kvm_micro_20260520_044439_120822/metadata.json`.
  See `native-sim/x86/results/README-20260520-044439-full-native-lab.md`.

Per-program runtime table:

| Micro program | Native userspace ns | Kernel eBPF ns | Current speedup | Previous speedup | Delta |
| --- | ---: | ---: | ---: | ---: | ---: |
| `simple` | 1.0 | 6.0 | 6.00x | 6.33x | -0.33x |
| `simple_packet` | 1.0 | 6.7 | 6.67x | 6.33x | +0.33x |
| `bitmap_popcount_scan` | 464.3 | 1113.3 | 2.40x | 2.40x | +0.00x |
| `sorted_rule_binary_search` | 302.0 | 529.7 | 1.75x | 1.75x | +0.00x |
| `bcc_runqlat_log2_histogram_bucket` | 1070.3 | 1218.3 | 1.14x | 1.16x | -0.02x |
| `trace_event_type_switch_dispatch` | 274.7 | 282.0 | 1.03x | 1.03x | -0.00x |
| `packet_checksum_fold` | 13366.7 | 18087.7 | 1.35x | 1.32x | +0.03x |
| `payload_prefix_memcmp_scan` | 67.3 | 87.0 | 1.29x | 2.03x | -0.74x |
| `packet_vlan_tcpopt_parser` | 7.0 | 12.3 | 1.76x | 1.76x | +0.00x |
| `bpf_local_call_fanout_dispatch` | 68.0 | 123.3 | 1.81x | 1.82x | -0.00x |
| `flow_5tuple_rss_hash` | 8.0 | 15.7 | 1.96x | 2.00x | -0.04x |
| `katran_lb_consistent_hash_select` | 11.0 | 22.7 | 2.06x | 1.91x | +0.15x |
| `cilium_policy_guard_tree_filter` | 36.3 | 75.0 | 2.06x | 2.06x | +0.00x |
| `siphash_rotate64_mixer` | 27.0 | 54.3 | 2.01x | 2.01x | -0.00x |
| `packet_record_bounds_window` | 62.0 | 118.0 | 1.90x | 1.90x | +0.00x |
| `flow_record_field_scan` | 48.0 | 63.0 | 1.31x | 1.33x | -0.01x |
| `packed_header_bitfield_decode` | 199.3 | 223.3 | 1.12x | 1.11x | +0.01x |
| `bpftrace_string_search_prefix_scan` | 107.0 | 188.0 | 1.76x | 1.77x | -0.01x |
| `tracee_syscall_name_table_lookup` | 103.7 | 117.3 | 1.13x | 1.14x | -0.01x |
| `tracee_http_method_prefix_detect` | 16.0 | 18.3 | 1.15x | 1.12x | +0.02x |
| `cilium_socket_lb_service_select` | 170.0 | 370.3 | 2.18x | 2.19x | -0.01x |
| `bcc_tcpconnect_ipv4_tuple_filter` | 62.3 | 105.7 | 1.70x | 1.71x | -0.02x |
| `tetragon_process_event_arg_filter` | 105.0 | 153.7 | 1.46x | 1.45x | +0.01x |
| `otel_stack_frame_unwind_scan` | 39.0 | 112.0 | 2.87x | 2.89x | -0.02x |
| `cilium_ct_nat_tuple_rewrite` | 75.7 | 148.3 | 1.96x | 1.95x | +0.01x |
| `packet_toeplitz_rss_hash` | 298.7 | 227.3 | 0.76x | 0.75x | +0.01x |
| `bpftrace_comm_key_fnv_hash` | 434.7 | 435.7 | 1.00x | 1.01x | -0.00x |
| `tc_packet_checksum_fold` | 13358.7 | 17634.7 | 1.32x | 1.32x | +0.00x |
| `cgroup_skb_hash_chain` | 287.7 | 285.3 | 0.99x | 0.99x | +0.00x |
