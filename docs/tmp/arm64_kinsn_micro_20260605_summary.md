# arm64 kinsn micro 2026-06-05

| Suite | Result source | Benchmarks | Mismatches | Speedup geomean | Wins / losses / ties | Matched sites | Applied sites | Code-size ratio |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| pure bytecode 29 | `micro/results/aws_arm64_micro_20260605_195615_598255/details/result.json` | 29 | 0 | 1.002x | 2 / 2 / 25 | 0 | 0 | 1.000x |
| with helpers/maps 13 | `micro/results/aws_arm64_micro_20260605_201826_257732/details/result.json` | 13 | 0 | 1.000x | 2 / 2 / 9 | 0 | 0 | 1.000x |

## Kinsn coverage

- pure bytecode 29: families -; names -
- with helpers/maps 13: families -; names -

## Top per-case speedups

### pure bytecode 29

| Case | Kernel ns | Kernel ReJIT ns | Speedup | Applied sites |
|---|---:|---:|---:|---:|
| `tracee_syscall_name_table_lookup` | 392 | 362 | 1.083x | 0 |
| `simple` | 15 | 14 | 1.071x | 0 |
| `packet_record_bounds_window` | 357 | 355 | 1.006x | 0 |
| `packet_checksum_fold` | 39661 | 39534 | 1.003x | 0 |
| `bcc_tcpconnect_ipv4_tuple_filter` | 341 | 340 | 1.003x | 0 |
| `bpftrace_comm_key_fnv_hash` | 1580 | 1579 | 1.001x | 0 |
| `simple_packet` | 14 | 14 | 1.000x | 0 |
| `payload_prefix_memcmp_scan` | 288 | 288 | 1.000x | 0 |

### with helpers/maps 13

| Case | Kernel ns | Kernel ReJIT ns | Speedup | Applied sites |
|---|---:|---:|---:|---:|
| `map_array_index_packet` | 30 | 29 | 1.034x | 0 |
| `map_hash_str_key` | 113 | 110 | 1.027x | 0 |
| `map_lru_hash_counter` | 221 | 220 | 1.005x | 0 |
| `helper_only_uid_gid` | 32 | 32 | 1.000x | 0 |
| `helper_chain_simple` | 247 | 247 | 1.000x | 0 |
| `map_array_lookup` | 28 | 28 | 1.000x | 0 |
| `map_hash_lookup` | 100 | 100 | 1.000x | 0 |
| `map_percpu_hash_counter` | 92 | 92 | 1.000x | 0 |

## Worst per-case speedups

### pure bytecode 29

| Case | Kernel ns | Kernel ReJIT ns | Speedup | Applied sites |
|---|---:|---:|---:|---:|
| `packet_toeplitz_rss_hash` | 476 | 498 | 0.956x | 0 |
| `packet_vlan_tcpopt_parser` | 43 | 44 | 0.977x | 0 |
| `trace_event_type_switch_dispatch` | 647 | 650 | 0.995x | 0 |
| `cilium_socket_lb_service_select` | 1122 | 1126 | 0.996x | 0 |
| `bpf_local_call_fanout_dispatch` | 357 | 358 | 0.997x | 0 |
| `bcc_runqlat_log2_histogram_bucket` | 4449 | 4460 | 0.998x | 0 |
| `otel_stack_frame_unwind_scan` | 407 | 408 | 0.998x | 0 |
| `bitmap_popcount_scan` | 2187 | 2192 | 0.998x | 0 |

### with helpers/maps 13

| Case | Kernel ns | Kernel ReJIT ns | Speedup | Applied sites |
|---|---:|---:|---:|---:|
| `map_percpu_array` | 31 | 32 | 0.969x | 0 |
| `combined_helper_map` | 46 | 47 | 0.979x | 0 |
| `multi_map_policy` | 124 | 125 | 0.992x | 0 |
| `helper_only_uid_gid` | 32 | 32 | 1.000x | 0 |
| `helper_chain_simple` | 247 | 247 | 1.000x | 0 |
| `map_array_lookup` | 28 | 28 | 1.000x | 0 |
| `map_hash_lookup` | 100 | 100 | 1.000x | 0 |
| `map_percpu_hash_counter` | 92 | 92 | 1.000x | 0 |

