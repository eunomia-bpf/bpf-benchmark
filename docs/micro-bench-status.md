# eBPF Micro Benchmark Status

Last updated: 2026-05-14

This document tracks the current micro benchmark suite used for BPFReJIT correctness, apply coverage, and post-hoc performance/code-size analysis.

Framework rule: micro/corpus result payloads store raw samples and raw counters only. Ratios, geomeans, win/loss counts, and summaries below are post-hoc analysis from `metadata.json`, not framework-generated fields.

## Current Suite

Config: `micro/config/micro_pure_jit.yaml`

- Suite name: `micro_staged_codegen`
- Current case count: `29`
- Default runtimes: `native`, `llvmbpf`, `kernel`
- ReJIT runtime: `kernel_rejit` is added when `BPFREJIT_BENCH_PASSES` is set
- Default `INNER_REPEAT`: `1000`
- Inputs: mostly staged input, with packet-backed cases where packet/context behavior matters
- Scope: helper/map-free or helper-minimized workload patterns, not full application workloads

## Coverage

| Category | Workload Patterns |
|---|---|
| baseline | `simple`, `simple_packet` |
| packet/load-balancer/hash | `flow_5tuple_rss_hash`, `katran_lb_consistent_hash_select`, `packet_toeplitz_rss_hash`, `cgroup_skb_hash_chain` |
| tracing/security filters | `bcc_runqlat_log2_histogram_bucket`, `bcc_tcpconnect_ipv4_tuple_filter`, `bpftrace_comm_key_fnv_hash`, `bpftrace_string_search_prefix_scan`, `tracee_syscall_name_table_lookup`, `tracee_http_method_prefix_detect`, `tetragon_process_event_arg_filter` |
| cilium-shaped paths | `cilium_policy_guard_tree_filter`, `cilium_socket_lb_service_select`, `cilium_ct_nat_tuple_rewrite` |
| parser/bounds/memory | `packet_vlan_tcpopt_parser`, `packet_record_bounds_window`, `payload_prefix_memcmp_scan`, `flow_record_field_scan`, `packed_header_bitfield_decode`, `otel_stack_frame_unwind_scan` |
| scalar algorithms | `bitmap_popcount_scan`, `sorted_rule_binary_search`, `trace_event_type_switch_dispatch`, `packet_checksum_fold`, `siphash_rotate64_mixer`, `tc_packet_checksum_fold` |
| subprogram/local call | `bpf_local_call_fanout_dispatch` |

The current suite is intentionally closer to workload patterns than unit tests. It still has limits: no helper-heavy map path, no full tail-call application chain, limited interprocedural coverage, and no real app startup/workload behavior. Those belong in corpus.

## Validation Runs

### Native Symbol-Size Smoke

Command:

```sh
BPFREJIT_BENCH_PASSES=lea BENCH="simple" SAMPLES=1 WARMUPS=0 make micro
```

Result:

- Result path: `micro/results/x86_kvm_micro_20260514_204331_406449/metadata.json`
- `simple` code size:
  - `native`: 58 B
  - `llvmbpf`: 59 B
  - `kernel`: 107 B
  - `kernel_rejit`: 101 B

This validates that native code size is now recording the entry symbol size rather than the whole `.native.so` file size.

### LEA Full Micro Correctness

Command:

```sh
BPFREJIT_BENCH_PASSES=lea SAMPLES=1 WARMUPS=0 make micro
```

Result:

- Result path: `micro/results/x86_kvm_micro_20260514_203603_510400/metadata.json`
- `29/29` benchmarks completed
- `native`, `llvmbpf`, `kernel`, and `kernel_rejit` all matched expected results
- LEA applied `184/184` per full-suite sample, skipped `0`
- No verifier error

### Full-Pass Micro Correctness And Performance

Command:

```sh
BPFREJIT_BENCH_PASSES=default WARMUPS=0 make micro
```

Result:

- Result path: `micro/results/x86_kvm_micro_20260514_205607_714679/metadata.json`
- `SAMPLES=3`, `INNER_REPEAT=1000`, `WARMUPS=0`
- `29/29` benchmarks completed
- `87/87` `kernel_rejit` samples returned ReJIT status `ok`
- No verifier error
- No expected-result mismatch

Environment caveat from runner warnings:

- CPU governor reported as `unknown`
- turbo boost enabled
- no CPU affinity set
- PMU unavailable except software events

Use this as KVM smoke/performance-direction data. It is good enough to catch correctness regressions and large performance shifts, but not a final publication-quality measurement environment.

## Full-Pass Apply Counts

Totals below are across `29` benchmarks x `3` samples.

| Pass | Applied | Matched | Skipped |
|---|---:|---:|---:|
| `lea` | 552 | 552 | 0 |
| `rotate` | 492 | 492 | 0 |
| `wide_mem` | 186 | 255 | 69 |
| `dce` | 126 | 126 | 0 |
| `cond_select` | 33 | 33 | 0 |
| `extract` | 33 | 33 | 0 |
| `prefetch` | 9 | 9 | 0 |
| `ccmp` | 0 | 87 | 87 |
| `const_prop` | 0 | 567 | 567 |
| `bounds_check_merge` | 0 | 0 | 0 |
| `bulk_memory` | 0 | 0 | 0 |
| `endian_fusion` | 0 | 0 | 0 |
| `map_inline` | 0 | 0 | 0 |
| `skb_load_bytes_spec` | 0 | 0 | 0 |

Per full-suite sample, divide by 3: `lea=184`, `rotate=164`, `wide_mem=62`, `dce=42`, `cond_select=11`, `extract=11`, `prefetch=3`.

## Performance Summary

Ratios use median `exec_ns` per benchmark/runtime from the `SAMPLES=3` full-pass run. Ratio `< 1.0` means the left side is faster.

| Comparison | Exec Geomean | Wins / Losses / Ties | Interpretation |
|---|---:|---:|---|
| `kernel_rejit / kernel` | 0.933 | 14 / 8 / 7 | Full-pass ReJIT is about 6.7% faster on micro median geomean |
| `kernel / native` | 2.058 | 0 / 28 / 1 | Kernel JIT remains about 2.1x slower than native C entry code |
| `kernel_rejit / native` | 1.920 | 1 / 26 / 2 | ReJIT narrows but does not close the native gap |
| `llvmbpf / native` | 1.180 | 8 / 14 / 7 | llvmbpf is closer to native; some cases beat native |

Compile/load-time medians:

| Comparison | Compile Geomean |
|---|---:|
| `kernel_rejit / kernel` | 0.989 |
| `kernel / native` | 63.946 |
| `kernel_rejit / native` | 63.225 |
| `llvmbpf / native` | 272.126 |

Native `compile_ns` is `dlopen+dlsym`, not native compilation time. These numbers are useful as harness/load cost context, not as a JIT compile-time claim.

## Binary Size Summary

Recorded size sources:

- `native`: entry symbol size from `.native.so`
- `llvmbpf`: compiled-code size
- `kernel` / `kernel_rejit`: kernel `jited_prog_len`

| Comparison | Code-Size Geomean | Avg Delta | Smaller / Larger / Tie |
|---|---:|---:|---:|
| `kernel_rejit / kernel` | 0.879 | -143 B | 27 / 0 / 2 |
| `kernel / native` | 2.361 | +589 B | 0 / 29 / 0 |
| `kernel_rejit / native` | 2.077 | +446 B | 0 / 28 / 1 |
| `llvmbpf / native` | 1.325 | +147 B | 3 / 23 / 3 |

Native size caveat: entry-symbol size undercounts total reachable native code when static native subprograms are used. Example: `bpf_local_call_fanout_dispatch_xdp` has a 269 B entry symbol, about 752 B of reachable local native symbols, and a 971 B `.text` section.

Using full native `.text` instead of entry-symbol size gives:

- `kernel / native_text`: 1.376 code-size geomean
- `kernel_rejit / native_text`: 1.210 code-size geomean
- `llvmbpf / native_text`: 0.772 code-size geomean

Entry-symbol size is useful for single-entry/single-function micro cases. `.text` or reachable-symbol accounting is better for total native binary footprint.

## Representative Cases

Median rows from the `SAMPLES=3` full-pass run:

| Benchmark | Runtime | Exec Median | Code Size | Compile/Load Median |
|---|---|---:|---:|---:|
| `katran_lb_consistent_hash_select` | native | 12 ns | 1945 B | 0.041 ms |
|  | llvmbpf | 12 ns | 1824 B | 30.074 ms |
|  | kernel | 43 ns | 3463 B | 0.641 ms |
|  | kernel_rejit | 29 ns | 2969 B | 0.621 ms |
| `packet_record_bounds_window` | native | 64 ns | 248 B | 0.044 ms |
|  | llvmbpf | 62 ns | 280 B | 9.992 ms |
|  | kernel | 146 ns | 716 B | 1.176 ms |
|  | kernel_rejit | 103 ns | 511 B | 1.175 ms |
| `flow_5tuple_rss_hash` | native | 9 ns | 520 B | 0.042 ms |
|  | llvmbpf | 13 ns | 633 B | 13.205 ms |
|  | kernel | 26 ns | 1009 B | 0.355 ms |
|  | kernel_rejit | 20 ns | 795 B | 0.327 ms |
| `packet_toeplitz_rss_hash` | native | 245 ns | 321 B | 0.043 ms |
|  | llvmbpf | 117 ns | 846 B | 13.413 ms |
|  | kernel | 266 ns | 1086 B | 2.108 ms |
|  | kernel_rejit | 239 ns | 1098 B | 2.119 ms |
| `packet_checksum_fold` | native | 13369 ns | 170 B | 0.039 ms |
|  | llvmbpf | 13332 ns | 161 B | 8.300 ms |
|  | kernel | 17656 ns | 424 B | 34.056 ms |
|  | kernel_rejit | 17633 ns | 340 B | 34.014 ms |
| `trace_event_type_switch_dispatch` | native | 55 ns | 170 B | 0.040 ms |
|  | llvmbpf | 255 ns | 1261 B | 15.297 ms |
|  | kernel | 289 ns | 1621 B | 30.528 ms |
|  | kernel_rejit | 296 ns | 1531 B | 30.451 ms |

## ReJIT Improvements And Regressions

Largest `kernel_rejit / kernel` median improvements:

| Benchmark | Ratio | Kernel -> ReJIT |
|---|---:|---|
| `packet_vlan_tcpopt_parser` | 0.571 | 28 ns -> 16 ns |
| `katran_lb_consistent_hash_select` | 0.674 | 43 ns -> 29 ns |
| `packet_record_bounds_window` | 0.705 | 146 ns -> 103 ns |
| `siphash_rotate64_mixer` | 0.720 | 75 ns -> 54 ns |
| `flow_5tuple_rss_hash` | 0.769 | 26 ns -> 20 ns |
| `bcc_tcpconnect_ipv4_tuple_filter` | 0.832 | 143 ns -> 119 ns |
| `bpftrace_string_search_prefix_scan` | 0.897 | 252 ns -> 226 ns |
| `tracee_syscall_name_table_lookup` | 0.898 | 137 ns -> 123 ns |
| `packet_toeplitz_rss_hash` | 0.898 | 266 ns -> 239 ns |
| `bpf_local_call_fanout_dispatch` | 0.902 | 144 ns -> 130 ns |

Largest slowdowns:

| Benchmark | Ratio | Kernel -> ReJIT |
|---|---:|---|
| `cilium_policy_guard_tree_filter` | 1.188 | 96 ns -> 114 ns |
| `tracee_http_method_prefix_detect` | 1.154 | 26 ns -> 30 ns |
| `tetragon_process_event_arg_filter` | 1.122 | 188 ns -> 211 ns |
| `cilium_ct_nat_tuple_rewrite` | 1.063 | 191 ns -> 203 ns |
| `payload_prefix_memcmp_scan` | 1.060 | 116 ns -> 123 ns |
| `flow_record_field_scan` | 1.054 | 74 ns -> 78 ns |

## Native-Code Gap

The native runtime works and gives a useful upper-bound reference: all 29 benchmarks execute through `native`, `llvmbpf`, `kernel`, and `kernel_rejit` with matching results.

Current interpretation:

- Full x86 ReJIT works on micro: all 87 ReJIT samples succeeded.
- Full-pass ReJIT usually shrinks code: 27/29 programs are smaller than kernel baseline.
- Runtime improves on more cases than it regresses: 14 wins, 8 losses, 7 ties.
- Native remains substantially faster: `kernel/native = 2.058`, `kernel_rejit/native = 1.920`.

The remaining gap is not mainly LEA. Machine-code inspection points to missing optimization classes that current BPF bytecode peepholes do not cover:

- dense switch/table reconstruction, visible in `trace_event_type_switch_dispatch`
- loop-level optimization or checksum-specific recognition, visible in `packet_checksum_fold`
- BPF subprogram ABI/prologue/register-save cleanup and possible local-call inlining, visible in `bpf_local_call_fanout_dispatch`
- deeper scheduling/register allocation and loop/key-table lowering, visible in `packet_toeplitz_rss_hash`
- broader packet hot-path cleanup after local transforms, visible in `katran_lb_consistent_hash_select`

## Current TODO

- Add an analysis-side script, outside the framework result writer, that reads `metadata.json` and reproduces the comparisons in this document.
- Add an optional analysis-only native `.text` / reachable-symbol size extractor for micro `.native.so` files.
- Add a controlled artifact mode for selected post-ReJIT `bpftool prog dump jited` captures, without changing benchmark result payloads.
- Investigate dense switch/table lowering first; it has a clear native lowering difference and a large code-size gap.
- Investigate checksum/loop workloads separately; current local peepholes shrink code but do not move runtime there.
- Treat local-call native size carefully until reachable-symbol accounting is available.

## Reference Artifacts

| Artifact | Purpose |
|---|---|
| `docs/tmp/micro_native_runtime_report_20260514.md` | Detailed post-hoc native/ReJIT report |
| `micro/results/x86_kvm_micro_20260514_204331_406449/metadata.json` | Native symbol-size smoke |
| `micro/results/x86_kvm_micro_20260514_203603_510400/metadata.json` | LEA full micro correctness |
| `micro/results/x86_kvm_micro_20260514_205607_714679/metadata.json` | Full-pass micro correctness/performance |
