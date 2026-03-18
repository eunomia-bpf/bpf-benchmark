# Combined 40 Summary

Generated at `2026-03-08T20:17:15.075061+00:00`.

## Inputs

- Selected `micro/results/pure_jit_authoritative.json` as the original pure-JIT source because it exists and contains 31 benchmarks.
- Checked `micro/results/pure_jit.latest.json`: 2 benchmarks; not used for the original 31.
- Original pure-JIT authoritative input: `micro/results/pure_jit_authoritative.json` (31 benchmarks; generated `2026-03-07T03:30:21.761128+00:00`).
- New pure-JIT input: `micro/results/new_benchmarks_authoritative.json` (9 benchmarks; generated `2026-03-08T09:58:08.781102+00:00`).
- Original runtime input: `micro/results/runtime_authoritative.json` (9 benchmarks; generated `2026-03-07T03:38:27.489003+00:00`).
- New runtime input: `micro/results/new_runtime_authoritative.json` (1 benchmark; generated `2026-03-08T09:59:14.014344+00:00`).

## Key Results

| Scope | Benchmarks | Exec ratio geomean (L/K) | Code-size ratio geomean (L/K) | llvmbpf exec wins | kernel exec wins | llvmbpf smaller code | kernel smaller code | Significant |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| Combined pure-JIT | 40 | 0.844x | 0.528x | 29 | 11 | 39 | 1 | 33 / 40 |
| Combined runtime | 10 | 0.845x | n/a | 6 | 4 | n/a | n/a | 7 / 10 |

## Requested Figures

1. Combined 40 pure-JIT exec ratio geomean (L/K): **0.844x**
2. Combined 40 pure-JIT code-size ratio geomean (L/K): **0.528x**
3. Combined runtime exec ratio geomean (requested as `10+1`, repo inputs available as `9+1=10`): **0.845x**
4. Updated pure-JIT win/lose counts: exec `llvmbpf 29` / `kernel 11`; code size `llvmbpf 39` / `kernel 1`.
5. Significant pure-JIT benchmarks (BH-adjusted paired Wilcoxon p < 0.05 from matched iteration data): **33 / 40**.
- Additional context: excluding sub-resolution kernel timings (`<100ns`), 29 / 35 pure-JIT benchmarks remain significant.

## Win Sets

- Pure-JIT kernel execution wins (11): simple, simple_packet, memory_pair_sum, bitcount, log2_fold, branch_dense, bounds_check_heavy, fixed_loop_large, code_clone_2, code_clone_8, packet_rss_hash
- Pure-JIT kernel smaller-code wins (1): branch_fanout_32
- Pure-JIT non-significant after BH correction (7): simple_packet, log2_fold, dep_chain_long, packet_parse, bounds_check_heavy, multi_acc_4, imm64_storm
- Runtime kernel execution wins (4): map_lookup_churn, helper_call_1, get_time_heavy, atomic_counter_xadd

## Pure-JIT Benchmark Detail

| Benchmark | Exec ratio (L/K) | Code-size ratio (L/K) | Exec winner | Smaller code | BH-adjusted paired Wilcoxon p | Significant | Notes |
| --- | ---: | ---: | --- | --- | ---: | --- | --- |
| simple | 1.526x | 0.622x | kernel | llvmbpf | 0.0001579 | Yes | kernel exec < 100ns: below ktime resolution |
| simple_packet | 1.321x | 0.490x | kernel | llvmbpf | 0.0759 | No | kernel exec < 100ns: below ktime resolution |
| memory_pair_sum | 1.251x | 0.238x | kernel | llvmbpf | 0.03508 | Yes | kernel exec < 100ns: below ktime resolution |
| bitcount | 1.556x | 0.446x | kernel | llvmbpf | 3.829e-06 | Yes |  |
| log2_fold | 1.006x | 0.659x | kernel | llvmbpf | 0.8036 | No |  |
| dep_chain_short | 0.861x | 0.413x | llvmbpf | llvmbpf | 0.0403 | Yes |  |
| dep_chain_long | 0.964x | 0.414x | llvmbpf | llvmbpf | 0.0687 | No |  |
| binary_search | 0.481x | 0.449x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| branch_layout | 0.289x | 0.354x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| switch_dispatch | 0.789x | 0.800x | llvmbpf | llvmbpf | 6.511e-05 | Yes |  |
| branch_dense | 1.409x | 0.732x | kernel | llvmbpf | 3.829e-06 | Yes |  |
| checksum | 0.900x | 0.418x | llvmbpf | llvmbpf | 7.451e-08 | Yes |  |
| packet_parse | 0.964x | 0.496x | llvmbpf | llvmbpf | 0.7591 | No |  |
| bounds_ladder | 0.479x | 0.394x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| bounds_check_heavy | 1.119x | 0.807x | kernel | llvmbpf | 0.7691 | No |  |
| stride_load_4 | 0.442x | 0.332x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| stride_load_16 | 0.423x | 0.332x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| mixed_alu_mem | 0.737x | 0.817x | llvmbpf | llvmbpf | 4.722e-06 | Yes |  |
| spill_pressure | 0.871x | 0.759x | llvmbpf | llvmbpf | 0.004841 | Yes |  |
| multi_acc_4 | 0.951x | 0.646x | llvmbpf | llvmbpf | 0.2604 | No |  |
| multi_acc_8 | 0.951x | 0.756x | llvmbpf | llvmbpf | 0.02257 | Yes |  |
| fibonacci_iter | 0.803x | 0.395x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| fibonacci_iter_packet | 0.818x | 0.343x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| fixed_loop_small | 0.759x | 0.359x | llvmbpf | llvmbpf | 0.001059 | Yes |  |
| fixed_loop_large | 1.193x | 0.425x | kernel | llvmbpf | 3.829e-06 | Yes |  |
| nested_loop_2 | 0.823x | 0.501x | llvmbpf | llvmbpf | 4.321e-05 | Yes |  |
| nested_loop_3 | 0.405x | 0.884x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| code_clone_2 | 1.260x | 0.492x | kernel | llvmbpf | 3.829e-06 | Yes |  |
| code_clone_8 | 1.878x | 0.542x | kernel | llvmbpf | 3.829e-06 | Yes |  |
| large_mixed_500 | 0.693x | 0.464x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| large_mixed_1000 | 0.742x | 0.419x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| memcmp_prefix_64 | 0.860x | 0.743x | llvmbpf | llvmbpf | 2.234e-05 | Yes |  |
| packet_parse_vlans_tcpopts | 0.924x | 0.609x | llvmbpf | llvmbpf | 0.008589 | Yes | kernel exec < 100ns: below ktime resolution |
| local_call_fanout | 0.731x | 0.367x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| packet_rss_hash | 1.124x | 0.624x | kernel | llvmbpf | 0.009343 | Yes | kernel exec < 100ns: below ktime resolution |
| imm64_storm | 0.962x | 0.719x | llvmbpf | llvmbpf | 0.0736 | No |  |
| alu32_64_pingpong | 0.594x | 0.760x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| branch_fanout_32 | 0.843x | 1.200x | llvmbpf | kernel | 3.829e-06 | Yes |  |
| deep_guard_tree_8 | 0.612x | 0.558x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |
| mega_basic_block_2048 | 0.955x | 0.621x | llvmbpf | llvmbpf | 3.829e-06 | Yes |  |

## Runtime Benchmark Detail

| Benchmark | Exec ratio (L/K) | Exec winner | BH-adjusted paired Wilcoxon p | Significant | Notes |
| --- | ---: | --- | ---: | --- | --- |
| map_lookup_churn | 1.307x | kernel | 3.797e-06 | Yes |  |
| map_roundtrip | 0.726x | llvmbpf | 3.797e-06 | Yes |  |
| hash_map_lookup | 0.681x | llvmbpf | 3.797e-06 | Yes |  |
| percpu_map_update | 0.490x | llvmbpf | 3.797e-06 | Yes |  |
| helper_call_1 | 1.047x | kernel | 0.8367 | No | kernel exec < 100ns: below ktime resolution |
| helper_call_10 | 0.990x | llvmbpf | 0.8367 | No |  |
| helper_call_100 | 0.962x | llvmbpf | 0.02236 | Yes |  |
| probe_read_heavy | 0.566x | llvmbpf | 3.797e-06 | Yes |  |
| get_time_heavy | 1.038x | kernel | 4.103e-06 | Yes |  |
| atomic_counter_xadd | 1.003x | kernel | 0.8367 | No |  |
