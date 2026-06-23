# RQ1 workload-category geomean speedup

数据来源：`micro/results/figures/kinsn-rq1-micro-percase-20260606.csv`。
口径：排除 `simple` 和 `simple_packet` 后的 27 个 microbenchmark；每类 workload 内对 per-benchmark speedup 取几何平均。

| workload category | benchmarks | x86 geomean | ARM64 geomean | ARM64 / x86 | x86 code-size reduction | ARM64 code-size reduction |
|---|---:|---:|---:|---:|---:|---:|
| packet/Cilium | 9 | 1.267x | 1.303x | 1.03x | 27.7% | 25.8% |
| bit/hash | 4 | 1.320x | 1.205x | 0.91x | 33.3% | 20.0% |
| scan/search | 4 | 1.312x | 1.155x | 0.88x | 22.4% | 0.9% |
| dispatch/table | 4 | 1.251x | 1.100x | 0.88x | 22.8% | 8.4% |

## Benchmark grouping

- `packet/Cilium`: `packet_checksum_fold`, `tc_packet_checksum_fold`, `packet_vlan_tcpopt_parser`, `packet_record_bounds_window`, `cilium_socket_lb_service_select`, `cilium_ct_nat_tuple_rewrite`, `cilium_policy_guard_tree_filter`, `bcc_tcpconnect_ipv4_tuple_filter`, `katran_lb_consistent_hash_select`
- `bit/hash`: `siphash_rotate64_mixer`, `packet_toeplitz_rss_hash`, `flow_5tuple_rss_hash`, `bpftrace_comm_key_fnv_hash`
- `scan/search`: `bitmap_popcount_scan`, `bpftrace_string_search_prefix_scan`, `payload_prefix_memcmp_scan`, `sorted_rule_binary_search`
- `dispatch/table`: `bpf_local_call_fanout_dispatch`, `trace_event_type_switch_dispatch`, `tracee_syscall_name_table_lookup`, `tracee_http_method_prefix_detect`

## Takeaway

总体 geomean 接近，但类别结构不同：ARM64 在 packet/Cilium 类 workload 上略强于 x86，而 x86 在 bit/hash、scan/search、dispatch/table 类 workload 上更强。这支持“跨架构收益成立，但收益机制和命中的 workload idiom 不同”的解释。