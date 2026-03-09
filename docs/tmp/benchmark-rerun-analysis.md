# Benchmark Rerun Analysis

Date: 2026-03-08 local / 2026-03-09 UTC

## Run Status

- Build command was `make -C micro clean` then `make -C micro`.
- `make clean` initially failed on a stale root-owned subtree under `micro/build`; I patched `micro/Makefile` so clean removes what it can and does not abort on undeletable top-level build entries from older privileged builds.
- `cmov_select` verification passed. `llvmbpf` returned the expected result `11332120082118096118`, and a kernel spot-check returned the same value.
- Full suites completed with both runtimes. No benchmark had to be skipped.
- Current result files:
  - `micro/results/pure_jit_with_cmov.json` (`generated_at`: `2026-03-09T01:38:37.735500+00:00`, `50` benchmarks)
  - `micro/results/runtime_with_map_lookup_repeat.json` (`generated_at`: `2026-03-09T01:40:15.031248+00:00`, `11` benchmarks)
- Historical baselines used for comparison:
  - `git show HEAD:micro/results/pure_jit_authoritative.json` (`generated_at`: `2026-03-07T03:30:21.761128+00:00`, `31` benchmarks)
  - `git show HEAD:micro/results/runtime_authoritative.json` (`generated_at`: `2026-03-07T03:38:27.489003+00:00`, `9` benchmarks)
  - `git show HEAD:tmp/directive_discovery_smoke.json` (`generated_at`: `2026-03-08T22:43:23.551407+00:00`, `5` benchmarks) for the older pure-jit `map_lookup_repeat` numbers
- Environment caveats from the runner:
  - CPU governor was `powersave`
  - turbo was enabled
  - no CPU affinity was set
  - `perf_event_paranoid=2`

## Key Findings

### `cmov_select`

- Current medians:
  - `llvmbpf`: `147.5 ns`
  - `kernel`: `815 ns`
  - `L/K`: `0.181x`
- Interpretation: `llvmbpf` is about `5.53x` faster on this benchmark. This is the cleanest positive result in the rerun and is consistent with the intended purpose of `cmov_select`.

### `map_lookup_repeat`: runtime suite vs old pure-jit data

- Old pure-jit smoke data (`2026-03-08`, `tmp/directive_discovery_smoke.json`):
  - `llvmbpf`: `1.744 us`
  - `kernel`: `678 ns`
  - `L/K`: `2.572x`
- New runtime-suite data (`2026-03-09`, `runtime_with_map_lookup_repeat.json`):
  - `llvmbpf`: `1.638 us`
  - `kernel`: `642 ns`
  - `L/K`: `2.551x`
- Change:
  - `llvmbpf` median improved by about `6.1%`
  - `kernel` median improved by about `5.3%`
  - `L/K` changed by only about `-0.8%`
- Interpretation: moving `map_lookup_repeat` into the runtime suite changed its classification but did not materially change the relative outcome. Kernel still wins by about `2.55x`.

### Overall Geomean Changes

- Current full pure-jit suite (`50` benchmarks): `L/K` exec-time geomean = `0.797x`
- Current full runtime suite (`11` benchmarks): `L/K` exec-time geomean = `0.875x`
- Those full-suite numbers are not directly comparable to the March 7 baselines because the benchmark inventories changed.
- Fair overlap comparisons:

| Scope | Current `L/K` geomean | Historical `L/K` geomean | Relative change | Notes |
| --- | ---: | ---: | ---: | --- |
| Pure-jit overlap with `pure_jit_authoritative.json` (`31` shared benchmarks) | `0.923x` | `0.811x` | `+13.9%` | Less `llvmbpf` advantage in this rerun |
| Pure-jit overlap excluding timer-floor baselines (`simple`, `simple_packet`, `memory_pair_sum`) | `0.841x` | `0.784x` | `+7.3%` | Same direction after removing the three shortest baseline cases |
| Runtime overlap with `runtime_authoritative.json` (`9` shared benchmarks) | `0.806x` | `0.826x` | `-2.5%` | Slightly more `llvmbpf` advantage on the raw overlap set |
| Runtime overlap excluding `helper_call_1` floor-sensitive case | `0.775x` | `0.759x` | `+2.1%` | Slightly less `llvmbpf` advantage once the shortest helper case is removed |

- Interpretation:
  - Pure-jit drifted materially toward kernel on the historical overlap subset.
  - Runtime stayed much closer to the March 7 baseline; the sign of the change depends on whether `helper_call_1` is included.
  - The environment warnings above likely explain part of this drift, especially for the shortest cases.

## Unexpected Or Noteworthy Results

- `simple`, `simple_packet`, and `memory_pair_sum` should be treated as timer-floor cases in this rerun:
  - `simple`: `1.900x`
  - `simple_packet`: `4.385x`
  - `memory_pair_sum`: `1.259x`
- Those three cases dominate the raw overlap geomean shift, but their kernel medians are only `15 ns`, `6.5 ns`, and `13.5 ns`. They are not reliable as cross-run trend indicators.

- Non-floor pure-jit cases that flipped from historical `llvmbpf` win or near-parity to kernel win:
  - `fixed_loop_small`: `0.662x` -> `1.271x`
  - `dep_chain_short`: `0.782x` -> `1.126x`
  - `bounds_check_heavy`: `0.967x` -> `1.371x`
  - `log2_fold`: `0.948x` -> `1.188x`
  - `multi_acc_8`: `0.905x` -> `1.036x`

- Non-floor pure-jit case that flipped the other way:
  - `multi_acc_4`: `1.013x` -> `0.736x`

- Runtime case that changed winner:
  - `helper_call_10`: `0.839x` -> `1.111x`

- Runtime cases that are still floor-sensitive or close to parity:
  - `helper_call_1`: `1.632x` -> `1.102x`
  - `get_time_heavy`: `1.029x` -> `1.049x`
  - `map_lookup_churn`: `1.275x` -> `1.057x`

- The strongest stable takeaways from this rerun are:
  - `cmov_select` clearly favors `llvmbpf`
  - `map_lookup_repeat` still clearly favors kernel
  - the historical March 7 pure-jit geomean advantage for `llvmbpf` was not reproduced on the exact overlap subset under this host configuration

## Full Current Results

| Suite | Benchmark | llvmbpf exec median | kernel exec median | `L/K` exec ratio | Winner |
| --- | --- | ---: | ---: | ---: | --- |
| pure-jit | simple | 28.5 ns | 15 ns | 1.900x | kernel |
| pure-jit | simple_packet | 28.5 ns | 6.5 ns | 4.385x | kernel |
| pure-jit | memory_pair_sum | 17 ns | 13.5 ns | 1.259x | kernel |
| pure-jit | bitcount | 4.667 us | 3.152 us | 1.480x | kernel |
| pure-jit | log2_fold | 319.5 ns | 269 ns | 1.188x | kernel |
| pure-jit | dep_chain_short | 120.5 ns | 107 ns | 1.126x | kernel |
| pure-jit | dep_chain_long | 433 ns | 546 ns | 0.793x | llvmbpf |
| pure-jit | binary_search | 204.5 ns | 527.5 ns | 0.388x | llvmbpf |
| pure-jit | branch_layout | 155 ns | 550 ns | 0.282x | llvmbpf |
| pure-jit | switch_dispatch | 246 ns | 314.5 ns | 0.782x | llvmbpf |
| pure-jit | branch_dense | 624.5 ns | 430.5 ns | 1.451x | kernel |
| pure-jit | cmov_select | 147.5 ns | 815 ns | 0.181x | llvmbpf |
| pure-jit | checksum | 10.831 us | 12.030 us | 0.900x | llvmbpf |
| pure-jit | load_word32 | 82 ns | 77.5 ns | 1.058x | kernel |
| pure-jit | load_byte | 192 ns | 228 ns | 0.842x | llvmbpf |
| pure-jit | load_byte_recompose | 102 ns | 199.5 ns | 0.511x | llvmbpf |
| pure-jit | load_native_u64 | 81 ns | 194 ns | 0.418x | llvmbpf |
| pure-jit | packet_parse | 91 ns | 77 ns | 1.182x | kernel |
| pure-jit | bounds_ladder | 82 ns | 162.5 ns | 0.505x | llvmbpf |
| pure-jit | bounds_check_heavy | 273.5 ns | 199.5 ns | 1.371x | kernel |
| pure-jit | stride_load_4 | 114.5 ns | 338 ns | 0.339x | llvmbpf |
| pure-jit | stride_load_16 | 111.5 ns | 207 ns | 0.539x | llvmbpf |
| pure-jit | mixed_alu_mem | 493.5 ns | 719 ns | 0.686x | llvmbpf |
| pure-jit | spill_pressure | 250.5 ns | 411 ns | 0.609x | llvmbpf |
| pure-jit | multi_acc_4 | 266 ns | 361.5 ns | 0.736x | llvmbpf |
| pure-jit | multi_acc_8 | 428 ns | 413 ns | 1.036x | kernel |
| pure-jit | fibonacci_iter | 587 ns | 681.5 ns | 0.861x | llvmbpf |
| pure-jit | fibonacci_iter_packet | 635 ns | 680.5 ns | 0.933x | llvmbpf |
| pure-jit | fixed_loop_small | 129 ns | 101.5 ns | 1.271x | kernel |
| pure-jit | fixed_loop_large | 1.519 us | 1.286 us | 1.182x | kernel |
| pure-jit | nested_loop_2 | 442 ns | 514 ns | 0.860x | llvmbpf |
| pure-jit | nested_loop_3 | 298.5 ns | 663.5 ns | 0.450x | llvmbpf |
| pure-jit | code_clone_2 | 442.5 ns | 291 ns | 1.521x | kernel |
| pure-jit | code_clone_8 | 2.256 us | 1.123 us | 2.008x | kernel |
| pure-jit | large_mixed_500 | 428.5 ns | 499.5 ns | 0.858x | llvmbpf |
| pure-jit | large_mixed_1000 | 779 ns | 999.5 ns | 0.779x | llvmbpf |
| pure-jit | bpf_call_chain | 278 ns | 420 ns | 0.662x | llvmbpf |
| pure-jit | memcmp_prefix_64 | 70.5 ns | 191.5 ns | 0.368x | llvmbpf |
| pure-jit | packet_parse_vlans_tcpopts | 27.5 ns | 24 ns | 1.146x | kernel |
| pure-jit | local_call_fanout | 113 ns | 96.5 ns | 1.171x | kernel |
| pure-jit | packet_rss_hash | 21 ns | 15.5 ns | 1.355x | kernel |
| pure-jit | imm64_storm | 200.5 ns | 280 ns | 0.716x | llvmbpf |
| pure-jit | alu32_64_pingpong | 252 ns | 488 ns | 0.516x | llvmbpf |
| pure-jit | branch_fanout_32 | 254 ns | 383.5 ns | 0.662x | llvmbpf |
| pure-jit | deep_guard_tree_8 | 59.5 ns | 140 ns | 0.425x | llvmbpf |
| pure-jit | mega_basic_block_2048 | 679 ns | 803.5 ns | 0.845x | llvmbpf |
| pure-jit | packet_redundant_bounds | 59 ns | 135 ns | 0.437x | llvmbpf |
| pure-jit | const_fold_chain | 186 ns | 396.5 ns | 0.469x | llvmbpf |
| pure-jit | struct_field_cluster | 57 ns | 123 ns | 0.463x | llvmbpf |
| pure-jit | smallmul_strength_reduce | 364 ns | 321 ns | 1.134x | kernel |
| runtime | map_lookup_churn | 400 ns | 378.5 ns | 1.057x | kernel |
| runtime | map_roundtrip | 458 ns | 595 ns | 0.770x | llvmbpf |
| runtime | map_lookup_repeat | 1.638 us | 642 ns | 2.551x | kernel |
| runtime | hash_map_lookup | 405.5 ns | 644 ns | 0.630x | llvmbpf |
| runtime | percpu_map_update | 204.5 ns | 332 ns | 0.616x | llvmbpf |
| runtime | helper_call_1 | 65 ns | 59 ns | 1.102x | kernel |
| runtime | helper_call_10 | 160 ns | 144 ns | 1.111x | kernel |
| runtime | helper_call_100 | 1.142 us | 1.468 us | 0.778x | llvmbpf |
| runtime | probe_read_heavy | 200.5 ns | 441 ns | 0.455x | llvmbpf |
| runtime | get_time_heavy | 1.774 us | 1.690 us | 1.049x | kernel |
| runtime | atomic_counter_xadd | 185 ns | 295.5 ns | 0.626x | llvmbpf |
