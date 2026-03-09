# Pure-JIT Map/Helper Audit

## Scope

This audit covers every benchmark listed in `config/micro_pure_jit.yaml` and the corresponding source in `micro/programs/*.bpf.c`.

The key harness definitions are in `micro/programs/common.h`:

- `DEFINE_PACKET_BACKED_XDP_BENCH` (`common.h:89-111`) is helper-free.
- `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` (`common.h:113-138`) is helper-free.
- `DEFINE_STAGED_INPUT_XDP_BENCH` (`common.h:140-161`) is not helper-free; it unconditionally calls `bpf_map_lookup_elem(&input_map, &key)` at `common.h:151`.

## Summary

- Total pure-jit benchmarks: `50`
- `clean`: `5`
- `staged-only`: `44`
- `needs-map`: `1`

Only one pure-jit benchmark contains helper calls inside its own hot path:

- `micro/programs/map_lookup_repeat.bpf.c`
  - extra map definition: `lookup_map` at `map_lookup_repeat.bpf.c:18-23`
  - `bpf_map_update_elem` in `populate_map_lookup_repeat()` at `map_lookup_repeat.bpf.c:36`
  - `bpf_map_lookup_elem` in `bench_map_lookup_repeat()` at `map_lookup_repeat.bpf.c:64`, `:72`, and `:79`

No other benchmark in this suite contains `bpf_map_lookup_elem`, `bpf_map_update_elem`, `bpf_ktime_get_ns`, `bpf_probe_read*`, or any other `bpf_*` helper call inside its `bench_*` path.

All `44` `staged-only` programs already use the fixed-packet-compatible bench signature `int bench_*(const u8 *data, u32 len, u64 *out)`, so the conversion is mechanical:

1. Replace `DEFINE_STAGED_INPUT_XDP_BENCH(...)` with `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(...)`.
2. Reuse the exact input-size argument shown in the table below.
3. Remove the staged input wrapper type plus the `input_map` definition from the `.bpf.c` file.
4. Change that benchmark's `io_mode` to `packet` in `config/micro_pure_jit.yaml` or flip the suite default after the staged entries are removed.

## Benchmark Table

| Benchmark | Harness Today | Fixed-Size Arg / Note | `bench_*` Helper Use | Category |
| --- | --- | --- | --- | --- |
| `simple` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `64U` | none beyond staged macro | `staged-only` |
| `simple_packet` | `DEFINE_PACKET_BACKED_XDP_BENCH` | already packet-backed | none | `clean` |
| `memory_pair_sum` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `MEMORY_PAIR_SUM_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `bitcount` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `BITCOUNT_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `log2_fold` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `LOG2_FOLD_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `dep_chain_short` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `DEP_CHAIN_SHORT_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `dep_chain_long` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `DEP_CHAIN_LONG_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `binary_search` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `BINARY_SEARCH_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `branch_layout` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `BRANCH_LAYOUT_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `switch_dispatch` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `SWITCH_DISPATCH_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `branch_dense` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `BRANCH_DENSE_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `checksum` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `CHECKSUM_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `load_word32` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `LOAD_WORD32_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `load_byte` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `LOAD_BYTE_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `load_byte_recompose` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `LBR_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `load_native_u64` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `LNU_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `packet_parse` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `PACKET_PARSE_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `bounds_ladder` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `BOUNDS_LADDER_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `bounds_check_heavy` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `BOUNDS_CHECK_HEAVY_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `stride_load_4` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `STRIDE_LOAD_4_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `stride_load_16` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `STRIDE_LOAD_16_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `mixed_alu_mem` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `MIXED_ALU_MEM_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `spill_pressure` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `SPILL_PRESSURE_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `multi_acc_4` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `MULTI_ACC_4_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `multi_acc_8` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `MULTI_ACC_8_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `fibonacci_iter` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `FIBONACCI_ITER_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `fibonacci_iter_packet` | `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` | already fixed packet-backed | none | `clean` |
| `fixed_loop_small` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `FIXED_LOOP_SMALL_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `fixed_loop_large` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `FIXED_LOOP_LARGE_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `nested_loop_2` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `NESTED_LOOP_2_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `nested_loop_3` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `NESTED_LOOP_3_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `code_clone_2` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `CODE_CLONE_2_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `code_clone_8` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `CODE_CLONE_8_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `large_mixed_500` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `LARGE_MIXED_500_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `large_mixed_1000` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `LARGE_MIXED_1000_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `bpf_call_chain` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `BPF_CALL_CHAIN_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `memcmp_prefix_64` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `MEMCMP_PREFIX_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `packet_parse_vlans_tcpopts` | handwritten packet-backed XDP wrapper | already packet-backed | none | `clean` |
| `local_call_fanout` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `LOCAL_CALL_FANOUT_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `packet_rss_hash` | handwritten packet-backed XDP wrapper | already packet-backed | none | `clean` |
| `imm64_storm` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `IMM64_STORM_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `alu32_64_pingpong` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `ALU32_64_PINGPONG_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `branch_fanout_32` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `BRANCH_FANOUT_32_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `deep_guard_tree_8` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `DEEP_GUARD_TREE_8_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `mega_basic_block_2048` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `MEGA_BASIC_BLOCK_2048_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `packet_redundant_bounds` | `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` | already fixed packet-backed | none | `clean` |
| `const_fold_chain` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `CONST_FOLD_CHAIN_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `map_lookup_repeat` | `DEFINE_STAGED_INPUT_XDP_BENCH` | do not convert; remove from pure-jit | `bpf_map_update_elem`, `bpf_map_lookup_elem` | `needs-map` |
| `struct_field_cluster` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `STRUCT_FIELD_CLUSTER_INPUT_SIZE` | none beyond staged macro | `staged-only` |
| `smallmul_strength_reduce` | `DEFINE_STAGED_INPUT_XDP_BENCH` | `SMALLMUL_STRENGTH_REDUCE_INPUT_SIZE` | none beyond staged macro | `staged-only` |

## Recommendations

1. Convert all `44` `staged-only` benchmarks to `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` and set them to `io_mode: packet`.
2. Remove `map_lookup_repeat` from `config/micro_pure_jit.yaml`; it belongs in a runtime/helper/map-focused suite, not a pure-JIT suite.
3. Keep the existing packet-backed clean cases as-is: `simple_packet`, `fibonacci_iter_packet`, `packet_parse_vlans_tcpopts`, `packet_rss_hash`, and `packet_redundant_bounds`.
4. After conversion, the pure-jit suite should no longer depend on staged input maps at all. At that point, `benchmark_defaults.io_mode: staged` in `config/micro_pure_jit.yaml` should be changed to `packet` or removed.
