# Pure-JIT Benchmark Audit

## Scope

This audit covers every benchmark listed in `config/micro_pure_jit.yaml` as of 2026-03-08 and the corresponding source in `micro/programs/<base_name>.bpf.c`.

Audit rule:

- Pure-JIT benchmarks may use `DEFINE_STAGED_INPUT_XDP_BENCH`, because the `input_map` lookup happens in the wrapper, not in `bench_*` (`micro/programs/common.h:140-161`).
- Pure-JIT benchmarks must not perform extra map operations or helper calls inside `bench_*`, or inside helper subroutines that `bench_*` invokes on the hot path.
- `DEFINE_MAP_BACKED_XDP_BENCH` would be wrong for this suite. No current pure-JIT benchmark uses it.

## Summary

- Total pure-JIT benchmarks audited: `50`
- Benchmarks needing fixes: `1`
- Benchmarks with direct map activity in the hot path: `1`
- Benchmarks with non-map helper calls in the hot path: `0`
- Benchmarks using `DEFINE_MAP_BACKED_XDP_BENCH`: `0`

Only `map_lookup_repeat` violates the pure-computation rule. Its hot path both populates an auxiliary map and performs repeated `bpf_map_lookup_elem()` calls. All other benchmarks are clean under the stated policy: their `bench_*` bodies are pure computation over staged or packet-fed input, and any allowed `input_map` staging happens outside `bench_*`.

## Benchmark Table

| name | macro_used | has_map_in_hot_path | has_helper_in_hot_path | verdict |
| --- | --- | --- | --- | --- |
| `simple` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `simple_packet` | `DEFINE_PACKET_BACKED_XDP_BENCH` | no | no | OK |
| `memory_pair_sum` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `bitcount` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `log2_fold` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `dep_chain_short` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `dep_chain_long` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `binary_search` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `branch_layout` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `switch_dispatch` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `branch_dense` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `checksum` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `load_word32` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `load_byte` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `load_byte_recompose` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `load_native_u64` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `packet_parse` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `bounds_ladder` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `bounds_check_heavy` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `stride_load_4` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `stride_load_16` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `mixed_alu_mem` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `spill_pressure` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `multi_acc_4` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `multi_acc_8` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `fibonacci_iter` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `fibonacci_iter_packet` | `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` | no | no | OK |
| `fixed_loop_small` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `fixed_loop_large` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `nested_loop_2` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `nested_loop_3` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `code_clone_2` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `code_clone_8` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `large_mixed_500` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `large_mixed_1000` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `bpf_call_chain` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `memcmp_prefix_64` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `packet_parse_vlans_tcpopts` | `manual packet-backed wrapper` | no | no | OK |
| `local_call_fanout` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `packet_rss_hash` | `manual packet-backed wrapper` | no | no | OK |
| `imm64_storm` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `alu32_64_pingpong` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `branch_fanout_32` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `deep_guard_tree_8` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `mega_basic_block_2048` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `packet_redundant_bounds` | `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` | no | no | OK |
| `const_fold_chain` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `map_lookup_repeat` | `DEFINE_STAGED_INPUT_XDP_BENCH` | yes | no | NEEDS_FIX |
| `struct_field_cluster` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |
| `smallmul_strength_reduce` | `DEFINE_STAGED_INPUT_XDP_BENCH` | no | no | OK |

## NEEDS_FIX Details

### `map_lookup_repeat`

File: `micro/programs/map_lookup_repeat.bpf.c`

What is wrong:

- It defines an extra runtime map, `lookup_map`, at `micro/programs/map_lookup_repeat.bpf.c:18-23`.
- `bench_map_lookup_repeat()` calls `populate_map_lookup_repeat()` on the benchmark path at `micro/programs/map_lookup_repeat.bpf.c:56`.
- `populate_map_lookup_repeat()` performs `bpf_map_update_elem(&lookup_map, ...)` at `micro/programs/map_lookup_repeat.bpf.c:36`.
- The hot loop in `bench_map_lookup_repeat()` performs repeated `bpf_map_lookup_elem(&lookup_map, ...)` calls at `micro/programs/map_lookup_repeat.bpf.c:64`, `:72`, and `:79`.

Why this is not pure-JIT:

- The benchmark is measuring helper and map runtime behavior, not just generated arithmetic and control-flow code.
- The staged wrapper macro is not the problem here. The contamination is inside the benchmark logic itself.

Suggested fix:

- If this benchmark is meant to stay in the pure-JIT suite, remove `lookup_map`, remove `populate_map_lookup_repeat()`, and replace the repeated lookups with repeated direct loads from staged input data or a local stack array populated from staged input once without helpers.
- If the real goal is to study repeated same-key map lookup behavior, move `map_lookup_repeat` to the runtime/helper suite instead of keeping it in `micro_pure_jit.yaml`.

Recommended direction:

- Move it to the runtime suite or rename/rework it as a pure repeated-load benchmark. Its current behavior matches a future `map_lookup_cache` runtime benchmark, not a pure-JIT benchmark.

## Fix Categories

- `map-in-hot-path`: `1` benchmark
  - `map_lookup_repeat`
- `non-map-helper-in-hot-path`: `0` benchmarks
- `wrong-wrapper-macro`: `0` benchmarks

## Coverage Assessment

The suite remains strong for pure JIT codegen coverage once `map_lookup_repeat` is excluded or fixed.

Well covered:

- `wide_load` / byte-recompose:
  - `load_word32`, `load_byte`, `load_byte_recompose`, `load_native_u64`
  - packet and structured-field variants: `packet_parse`, `packet_parse_vlans_tcpopts`, `packet_rss_hash`, `struct_field_cluster`
- `branch_reorder` / hot-fallthrough / branch lowering:
  - `branch_layout`, `branch_dense`, `branch_fanout_32`, `deep_guard_tree_8`
  - parser and bounds variants: `bounds_ladder`, `bounds_check_heavy`, `packet_redundant_bounds`, `packet_parse_vlans_tcpopts`
- `rotate_fusion`:
  - `packet_rss_hash` has explicit `micro_rotl32`
  - `local_call_fanout` and several ALU kernels use repeated `micro_rotl64`
- `lea_fusion` / strength reduction / address-generation quality:
  - `smallmul_strength_reduce` is the clearest dedicated case
  - supporting pressure comes from `local_call_fanout`, `mixed_alu_mem`, parser/indexed-record kernels, and fixed-offset record walks such as `struct_field_cluster`
- register allocation, code size, and straight-line scheduling:
  - `spill_pressure`, `multi_acc_4`, `multi_acc_8`, `large_mixed_500`, `large_mixed_1000`, `mega_basic_block_2048`, `imm64_storm`

Partial coverage:

- `cmov_select`
  - `switch_dispatch`, `binary_search`, `branch_layout`, and some guard-style kernels provide branch-vs-branchless opportunities.
  - But the suite still does not cleanly isolate the narrow pure-assignment single-diamond shape that a frozen `cmov_select` transform would target. Current coverage is useful, but indirect.

Bottom line:

- For the main pure codegen opportunities you named, coverage is broadly adequate and in several areas strong.
- The main contamination issue is `map_lookup_repeat`.
- The main remaining representational gap is still a cleaner dedicated `cmov_select` microbenchmark, not widespread helper/map misuse.
