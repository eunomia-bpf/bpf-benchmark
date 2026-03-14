# Combined Benchmark Results Analysis

All medians below are `exec_ns` medians. Host rerun data comes from `micro/results/pure_jit_with_cmov.json` and `micro/results/runtime_with_map_lookup_repeat.json`; VM data comes from the matching `vm_*` files on kernel `7.0.0-rc2-gc23719abc330`; old authoritative baselines come from `micro/results/pure_jit_authoritative.json` and `micro/results/runtime_authoritative.json`.

## 1. Updated Authoritative Numbers

If the authoritative summary is refreshed today, the expanded host rerun produces the following top-line numbers:

| Scope | Benchmarks | L/K geomean | llvmbpf wins | kernel wins | ties |
| --- | ---: | ---: | ---: | ---: | ---: |
| Pure-JIT full rerun | 50 | 0.797x | 31 | 19 | 0 |
| Runtime full rerun | 11 | 0.875x | 6 | 5 | 0 |

The pure-JIT full-suite number is stronger than the 31-benchmark overlap because the 19 newly added pure-JIT cases are substantially more favorable to `llvmbpf`: they have a `0.628x` geomean and a `14/5/0` win split. The two new runtime cases (`map_lookup_repeat`, `atomic_counter_xadd`) roughly cancel each other in win count, but `map_lookup_repeat` pulls the 11-benchmark runtime geomean upward toward kernel.

For fair comparison against the old authoritative files, only the exact overlaps should be compared:

| Scope | Benchmarks | Current L/K geomean | Old authoritative L/K geomean | Relative shift | Current wins (L/K/T) | Old wins (L/K/T) |
| --- | ---: | ---: | ---: | ---: | --- | --- |
| Pure-JIT overlap | 31 | 0.923x | 0.811x | +13.9% | 17/14/0 | 23/8/0 |
| Runtime overlap | 9 | 0.806x | 0.826x | -2.5% | 5/4/0 | 6/3/0 |

Takeaway: the expanded 50-benchmark pure-JIT inventory still favors `llvmbpf` overall (`0.797x`), but on the original 31-benchmark authoritative overlap the rerun shifted materially toward kernel (`0.923x` vs `0.811x`). Runtime moved much less on the 9-benchmark overlap (`0.806x` vs `0.826x`).

## 2. `cmov_select` Deep Dive

- Host rerun: `llvmbpf 147.5 ns` vs `kernel 815 ns` = `0.181x` (`llvmbpf` is `5.53x` faster).
- VM kernel `7.0-rc2`: `kernel 760 ns` vs host-kernel `815 ns` = `0.933x` (`6.7%` faster than host kernel `6.15.11`).
- The VM did not change the qualitative result: `llvmbpf` is still far ahead there too (`165 ns` vs `760 ns`, `0.217x`).
- Native code size is available and strongly supports the same story: host `llvmbpf` emits `970 B`, while host kernel JIT emits `3,537 B` (`3.65x` larger). VM kernel code size is `3,548 B`, effectively unchanged from host kernel.
- This benchmark is exactly the kind of evidence the JIT advisor paper needs: a narrow pure-assignment diamond select whose source comment explicitly says to keep the diamond narrow so the backend result reflects select lowering, not extra control-flow work.

## 3. VM vs Host Kernel Comparison (`7.0-rc2` vs `6.15.11`)

| Scope | Benchmarks | Kernel VM/Host geomean | VM faster | VM slower | Unchanged |
| --- | ---: | ---: | ---: | ---: | ---: |
| Pure-JIT | 50 | 0.993x | 23 | 26 | 1 |
| Runtime | 11 | 1.049x | 5 | 6 | 0 |
| Combined | 61 | 1.003x | 28 | 32 | 1 |

On geomean, kernel `7.0-rc2` is basically flat against host kernel `6.15.11`: about `0.7%` faster on pure-JIT, `4.9%` slower on runtime, and `0.3%` slower overall. The per-benchmark picture is mixed, so the full table in Section 6 is the right place to inspect individual cases.

Most credible pure-JIT improvements on `7.0-rc2` (both host and VM kernel medians at or above `100 ns`):
- `spill_pressure`: host kernel `411 ns` -> VM kernel `248 ns` (`0.603x`).
- `stride_load_4`: host kernel `338 ns` -> VM kernel `233 ns` (`0.689x`).
- `multi_acc_4`: host kernel `361.5 ns` -> VM kernel `259 ns` (`0.716x`).
- `alu32_64_pingpong`: host kernel `488 ns` -> VM kernel `357 ns` (`0.732x`).
- `dep_chain_long`: host kernel `546 ns` -> VM kernel `424 ns` (`0.777x`).
- `const_fold_chain`: host kernel `396.5 ns` -> VM kernel `315 ns` (`0.794x`).

Most credible runtime improvements on `7.0-rc2`:
- `probe_read_heavy`: host kernel `441 ns` -> VM kernel `242 ns` (`0.549x`).
- `atomic_counter_xadd`: host kernel `295.5 ns` -> VM kernel `198 ns` (`0.670x`).
- `hash_map_lookup`: host kernel `644 ns` -> VM kernel `484 ns` (`0.752x`).
- `map_lookup_repeat`: host kernel `642 ns` -> VM kernel `639 ns` (`0.995x`).

Most credible regressions on `7.0-rc2`:
- `stride_load_16`: host kernel `207 ns` -> VM kernel `276 ns` (`1.333x`).
- `switch_dispatch`: host kernel `314.5 ns` -> VM kernel `422 ns` (`1.342x`).
- `log2_fold`: host kernel `269 ns` -> VM kernel `376 ns` (`1.398x`).
- `dep_chain_short`: host kernel `107 ns` -> VM kernel `178 ns` (`1.664x`).
- `load_byte_recompose`: host kernel `199.5 ns` -> VM kernel `332 ns` (`1.664x`).
- `packet_redundant_bounds`: host kernel `135 ns` -> VM kernel `236 ns` (`1.748x`).
- `helper_call_100`: host kernel `1467.5 ns` -> VM kernel `1968 ns` (`1.341x`).
- `get_time_heavy`: host kernel `1690.5 ns` -> VM kernel `2408 ns` (`1.424x`).
- `percpu_map_update`: host kernel `332 ns` -> VM kernel `534 ns` (`1.608x`).
- `helper_call_10`: host kernel `144 ns` -> VM kernel `467 ns` (`3.243x`).

Interpretation: the best pure-JIT wins cluster around register-pressure / callee-saved-adjacent shapes (`spill_pressure`, `multi_acc_4`, `alu32_64_pingpong`, `dep_chain_long`) plus a few memory-local kernels. The biggest runtime regressions are helper-heavy (`helper_call_10`, `helper_call_100`, `get_time_heavy`) or map-update-heavy (`percpu_map_update`).

## 4. `map_lookup_repeat` Migration Analysis

| Placement | llvmbpf_ns | kernel_ns | L/K ratio |
| --- | ---: | ---: | ---: |
| Old pure-JIT smoke run | 1744 | 678 | 2.572x |
| New runtime rerun | 1638 | 642 | 2.551x |

- `llvmbpf` improved by about `6.1%` between the old smoke run and the runtime rerun; kernel improved by about `5.3%`; the ratio only moved by `-0.8%`.
- That stability confirms the migration was correct. The benchmark literally performs repeated `bpf_map_lookup_elem()` calls in a hot loop over a map-backed path, so it belongs in the runtime suite, not the pure-JIT suite.
- Kernel is still about `2.5x` faster in both placements. That is strong evidence that this benchmark is dominated by helper/runtime overhead rather than by code-generation quality.

## 5. Data Quality Assessment

- Host rerun caveats: `cpu_governor=powersave`, `turbo_state=0` in the harness (`intel_pstate/no_turbo=0`, so turbo was allowed), `cpu_affinity=None`, `perf_event_paranoid=2`, and lighter sampling than the old authoritative data (`10/2/500` vs `30/5/1000`).
- VM rerun caveats: `cpu_governor` and `turbo_state` were both `unknown`, `cpu_affinity=None`, `perf_event_paranoid=2`, and sampling was lighter again (`5/1/200`). Host and VM are therefore useful for directional comparison, not publication-grade replacement.
- Timer-floor sensitivity matters here. `14/50` host pure-JIT benchmarks and `1/11` host runtime benchmarks have at least one median below `100 ns`: pure-JIT `simple, simple_packet, memory_pair_sum, load_word32, load_native_u64, packet_parse, bounds_ladder, memcmp_prefix_64, packet_parse_vlans_tcpopts, local_call_fanout, packet_rss_hash, deep_guard_tree_8, packet_redundant_bounds, struct_field_cluster`; runtime `helper_call_1`.
- You can see the effect in the overlap geomeans. On the 31 pure-JIT overlap, raw rerun vs old authoritative is `0.923x` vs `0.811x` (`+13.9%` toward kernel), but excluding the three shortest floor-sensitive cases (`simple`, `simple_packet`, `memory_pair_sum`) the shift shrinks to `0.841x` vs `0.784x` (`+7.3%`).
- Runtime is more stable, but the same caveat applies. On the 9-benchmark overlap, raw rerun vs old authoritative is `0.806x` vs `0.826x` (`-2.5%`), while excluding the shortest helper case (`helper_call_1`) gives `0.775x` vs `0.759x` (`+2.1%`).
- Practical reading: within-run host L/K comparisons are the most trustworthy numbers in this dataset; VM-vs-host kernel deltas are useful when the medians are comfortably above `100 ns`; and cross-run trend claims should be framed as provisional unless the environment is tightened.

## 6. Summary Table

`vm_kernel_ns` is the VM kernel median on `7.0-rc2`; compare it directly against `kernel_ns` for the per-benchmark host-vs-VM kernel delta.

| name | suite | llvmbpf_ns | kernel_ns | L/K_ratio | winner | vm_kernel_ns |
| --- | --- | ---: | ---: | ---: | --- | ---: |
| `simple` | pure-jit | 28.5 | 15 | 1.900x | kernel | 15 |
| `simple_packet` | pure-jit | 28.5 | 6.5 | 4.385x | kernel | 7 |
| `memory_pair_sum` | pure-jit | 17 | 13.5 | 1.259x | kernel | 11 |
| `bitcount` | pure-jit | 4667 | 3152.5 | 1.480x | kernel | 3330 |
| `log2_fold` | pure-jit | 319.5 | 269 | 1.188x | kernel | 376 |
| `dep_chain_short` | pure-jit | 120.5 | 107 | 1.126x | kernel | 178 |
| `dep_chain_long` | pure-jit | 433 | 546 | 0.793x | llvmbpf | 424 |
| `binary_search` | pure-jit | 204.5 | 527.5 | 0.388x | llvmbpf | 499 |
| `branch_layout` | pure-jit | 155 | 550 | 0.282x | llvmbpf | 537 |
| `switch_dispatch` | pure-jit | 246 | 314.5 | 0.782x | llvmbpf | 422 |
| `branch_dense` | pure-jit | 624.5 | 430.5 | 1.451x | kernel | 442 |
| `cmov_select` | pure-jit | 147.5 | 815 | 0.181x | llvmbpf | 760 |
| `checksum` | pure-jit | 10830.5 | 12029.5 | 0.900x | llvmbpf | 12599 |
| `load_word32` | pure-jit | 82 | 77.5 | 1.058x | kernel | 93 |
| `load_byte` | pure-jit | 192 | 228 | 0.842x | llvmbpf | 229 |
| `load_byte_recompose` | pure-jit | 102 | 199.5 | 0.511x | llvmbpf | 332 |
| `load_native_u64` | pure-jit | 81 | 194 | 0.418x | llvmbpf | 68 |
| `packet_parse` | pure-jit | 91 | 77 | 1.182x | kernel | 72 |
| `bounds_ladder` | pure-jit | 82 | 162.5 | 0.505x | llvmbpf | 146 |
| `bounds_check_heavy` | pure-jit | 273.5 | 199.5 | 1.371x | kernel | 198 |
| `stride_load_4` | pure-jit | 114.5 | 338 | 0.339x | llvmbpf | 233 |
| `stride_load_16` | pure-jit | 111.5 | 207 | 0.539x | llvmbpf | 276 |
| `mixed_alu_mem` | pure-jit | 493.5 | 719 | 0.686x | llvmbpf | 909 |
| `spill_pressure` | pure-jit | 250.5 | 411 | 0.609x | llvmbpf | 248 |
| `multi_acc_4` | pure-jit | 266 | 361.5 | 0.736x | llvmbpf | 259 |
| `multi_acc_8` | pure-jit | 428 | 413 | 1.036x | kernel | 419 |
| `fibonacci_iter` | pure-jit | 587 | 681.5 | 0.861x | llvmbpf | 688 |
| `fibonacci_iter_packet` | pure-jit | 635 | 680.5 | 0.933x | llvmbpf | 682 |
| `fixed_loop_small` | pure-jit | 129 | 101.5 | 1.271x | kernel | 87 |
| `fixed_loop_large` | pure-jit | 1519 | 1285.5 | 1.182x | kernel | 1220 |
| `nested_loop_2` | pure-jit | 442 | 514 | 0.860x | llvmbpf | 516 |
| `nested_loop_3` | pure-jit | 298.5 | 663.5 | 0.450x | llvmbpf | 658 |
| `code_clone_2` | pure-jit | 442.5 | 291 | 1.521x | kernel | 294 |
| `code_clone_8` | pure-jit | 2255.5 | 1123 | 2.008x | kernel | 1153 |
| `large_mixed_500` | pure-jit | 428.5 | 499.5 | 0.858x | llvmbpf | 509 |
| `large_mixed_1000` | pure-jit | 779 | 999.5 | 0.779x | llvmbpf | 1007 |
| `bpf_call_chain` | pure-jit | 278 | 420 | 0.662x | llvmbpf | 368 |
| `memcmp_prefix_64` | pure-jit | 70.5 | 191.5 | 0.368x | llvmbpf | 174 |
| `packet_parse_vlans_tcpopts` | pure-jit | 27.5 | 24 | 1.146x | kernel | 18 |
| `local_call_fanout` | pure-jit | 113 | 96.5 | 1.171x | kernel | 215 |
| `packet_rss_hash` | pure-jit | 21 | 15.5 | 1.355x | kernel | 31 |
| `imm64_storm` | pure-jit | 200.5 | 280 | 0.716x | llvmbpf | 256 |
| `alu32_64_pingpong` | pure-jit | 252 | 488 | 0.516x | llvmbpf | 357 |
| `branch_fanout_32` | pure-jit | 254 | 383.5 | 0.662x | llvmbpf | 395 |
| `deep_guard_tree_8` | pure-jit | 59.5 | 140 | 0.425x | llvmbpf | 71 |
| `mega_basic_block_2048` | pure-jit | 679 | 803.5 | 0.845x | llvmbpf | 847 |
| `packet_redundant_bounds` | pure-jit | 59 | 135 | 0.437x | llvmbpf | 236 |
| `const_fold_chain` | pure-jit | 186 | 396.5 | 0.469x | llvmbpf | 315 |
| `struct_field_cluster` | pure-jit | 57 | 123 | 0.463x | llvmbpf | 117 |
| `smallmul_strength_reduce` | pure-jit | 364 | 321 | 1.134x | kernel | 328 |
| `map_lookup_churn` | runtime | 400 | 378.5 | 1.057x | kernel | 464 |
| `map_roundtrip` | runtime | 458 | 595 | 0.770x | llvmbpf | 711 |
| `map_lookup_repeat` | runtime | 1638 | 642 | 2.551x | kernel | 639 |
| `hash_map_lookup` | runtime | 405.5 | 644 | 0.630x | llvmbpf | 484 |
| `percpu_map_update` | runtime | 204.5 | 332 | 0.616x | llvmbpf | 534 |
| `helper_call_1` | runtime | 65 | 59 | 1.102x | kernel | 25 |
| `helper_call_10` | runtime | 160 | 144 | 1.111x | kernel | 467 |
| `helper_call_100` | runtime | 1142 | 1467.5 | 0.778x | llvmbpf | 1968 |
| `probe_read_heavy` | runtime | 200.5 | 441 | 0.455x | llvmbpf | 242 |
| `get_time_heavy` | runtime | 1774 | 1690.5 | 1.049x | kernel | 2408 |
| `atomic_counter_xadd` | runtime | 185 | 295.5 | 0.626x | llvmbpf | 198 |

## 7. Recommended Authoritative Update

- Replace the benchmark inventory now, but not the methodology label. The best current working reference set is the expanded host rerun: `pure_jit_with_cmov.json` for pure-JIT and `runtime_with_map_lookup_repeat.json` for runtime. Those files add `cmov_select`, move `map_lookup_repeat` into runtime, and cover the full `50 + 11` benchmark inventory the project is now using.
- Preserve the old caveat language, and strengthen it. The March 9, 2026 rerun is not methodologically equivalent to the March 7, 2026 authoritative run: it used fewer iterations/warmups/repeats, no CPU pinning, `powersave`, and turbo allowed. The VM rerun is even less controlled and should remain comparative evidence, not authoritative replacement data.
- For the paper argument today, `cmov_select` is strong enough to cite as substantive evidence even before a stricter rerun, because the effect size is large (`0.181x`) and persists in the VM kernel comparison. `map_lookup_repeat` should be treated as a runtime benchmark permanently.
- Recommended next steps for a rigorous replacement rerun: pin to an isolated CPU, switch to `performance`, set `intel_pstate/no_turbo=1`, match at least the old `30/5/1000` sampling, raise repeat counts or batch size for sub-`100 ns` kernels, and collect at least one second independent rerun so the authoritative update carries both medians and run-to-run stability.
- If kernel-version attribution matters, rerun host `6.15.11` and VM `7.0-rc2` with matched parameters. Right now the VM data is valuable directional evidence, but it is not clean enough to conclude that every individual delta is kernel-caused.
