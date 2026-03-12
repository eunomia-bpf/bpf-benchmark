# Sub-ktime Filtering And Strict Micro Analysis

## Inputs

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/corpus-tuned-policy-comparison.md`
- `corpus/results/corpus_v5_tuned_policy.json`
- `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json`
- `micro/results/pure_jit_authoritative_20260312.json`
- `micro/results/pure_jit_authoritative_strict_20260312.json`

## Method

- Corpus: include a program only when both `baseline_run` and `v5_run` are `ok=true` with positive `exec_ns`. Stock time is `baseline_run.sample.exec_ns`. Corpus ratio is `stock_exec_ns / v5_exec_ns`, so `>1.0x` means the recompiled program is faster.
- Corpus thresholds are applied to the stock/kernel median (`baseline_run.sample.exec_ns`) to test how sensitive the result is to sub-`ktime` windows.
- Micro: use the aggregated `runs[].exec_ns` stats from `pure_jit_authoritative_strict_20260312.json`. Micro ratio is `llvmbpf_median / kernel_median`, so `<1.0x` means llvmbpf is faster.
- Non-strict micro comparison uses `pure_jit_authoritative_20260312.json` (3 iterations x 100 repeats). Strict uses `30` iterations x `1000` repeats.
- Geomean formula in both sections: `exp(mean(log(ratio_i)))` over the included per-program or per-benchmark ratios.

## Part 1: Corpus Sub-ktime Filtering

### Coverage By Stock Median

| Run | Measured pairs | `<50ns` | `50-99ns` | `100-199ns` | `>=200ns` | Overall geomean (`stock/v5`) |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Tuned policy | 142 | 79 | 1 | 49 | 13 | 0.898x |
| Blind all-apply | 163 | 101 | 0 | 46 | 16 | 0.868x |

### Threshold Sensitivity

| Run | Threshold on stock median | N | Share of measured | Geomean (`stock/v5`) | Wins | Losses | Ties |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Tuned policy | `>=50ns` | 63 | 44.4% | 0.952x | 22 | 40 | 1 |
| Tuned policy | `>=100ns` | 62 | 43.7% | 0.948x | 21 | 40 | 1 |
| Tuned policy | `>=200ns` | 13 | 9.2% | 1.236x | 9 | 4 | 0 |
| Blind all-apply | `>=50ns` | 62 | 38.0% | 0.988x | 20 | 40 | 2 |
| Blind all-apply | `>=100ns` | 62 | 38.0% | 0.988x | 20 | 40 | 2 |
| Blind all-apply | `>=200ns` | 16 | 9.8% | 1.226x | 9 | 7 | 0 |

### Comparable Shared Subset

| Threshold on stock median in both runs | Shared N | Tuned geomean | Blind geomean |
| --- | ---: | ---: | ---: |
| `>=50ns` | 62 | 0.948x | 0.988x |
| `>=100ns` | 62 | 0.948x | 0.988x |
| `>=200ns` | 11 | 1.280x | 1.287x |

### Corpus Takeaways

- `>=50ns` and `>=100ns` tell essentially the same story. The blind run has no measured programs in the `50-99ns` band, and the tuned run has only one.
- Filtering to `>=100ns` does **not** flip the corpus story. Tuned policy stays below break-even at `0.948x`, and blind all-apply stays just below break-even at `0.988x`.
- Only the tiny `>=200ns` tail flips above `1.0x` (`1.236x` tuned, `1.226x` blind), but that leaves only `13` tuned programs and `16` blind programs (`11` shared). That is too small to carry the paper’s primary claim.
- On the fair shared reliable subset (`62` programs at `>=100ns` in both runs), blind all-apply is actually slightly better than tuned policy (`0.988x` vs `0.948x`). The raw tuned-policy advantage therefore does not survive the thresholded reliable slice.
- Paper recommendation for corpus `ktime` results: use `>=100ns` as the main reliability sensitivity cut, keep `>=200ns` only as a stress-test appendix/sensitivity point, and do not use `>=50ns` as a separate headline because it adds almost no information.

## Part 2: Strict Micro 30x1000 Analysis

### Summary

| Metric | Value |
| --- | ---: |
| Strict geomean (`llvmbpf/kernel`, all `56`) | 0.609x |
| Strict geomean (`kernel>=100ns`, `50` benchmarks) | 0.645x |
| Strict geomean (`llvmbpf>=100ns` and `kernel>=100ns`, `38` benchmarks) | 0.707x |
| Non-strict geomean on same `56` benchmarks | 0.848x |
| Strict benchmarks with ratio `<1.0x` | 53 / 56 |
| Strict benchmarks with ratio `>1.0x` | 3 / 56 |
| Benchmarks with `kernel median <100ns` | 6 |
| Benchmarks with either runtime median `<100ns` | 18 |
| Benchmarks where strict ratio is lower/better than non-strict | 46 / 56 |
| Benchmarks that flipped from non-strict `>1.0x` to strict `<1.0x` | 17 |

### Remaining Strict Regressions (`llvmbpf/kernel > 1.0x`)

| Benchmark | Strict ratio | llvmbpf median ns | kernel median ns | Non-strict ratio |
| --- | ---: | ---: | ---: | ---: |
| cgroup_hash_chain | 1.083x | 314 | 290 | 1.320x |
| code_clone_8 | 1.188x | 1772 | 1492 | 1.983x |
| branch_dense | 1.212x | 671 | 553.5 | 1.316x |

### Biggest Strict-vs-Non-strict Corrections

| Benchmark | Strict ratio | Non-strict ratio | Delta (strict - non-strict) |
| --- | ---: | ---: | ---: |
| simple | 0.324x | 1.909x | -1.585 |
| memory_pair_sum | 0.276x | 1.692x | -1.416 |
| fixed_loop_small | 0.561x | 1.908x | -1.347 |
| simple_packet | 0.348x | 1.467x | -1.119 |
| packet_parse_vlans_tcpopts | 0.304x | 1.200x | -0.896 |
| packet_rss_hash | 0.505x | 1.400x | -0.895 |
| bitcount | 0.611x | 1.465x | -0.854 |
| code_clone_8 | 1.188x | 1.983x | -0.796 |
| rotate64_hash | 0.381x | 1.012x | -0.631 |
| local_call_fanout | 0.489x | 1.062x | -0.574 |

### Per-benchmark Strict Ratios (sorted by strict `llvmbpf/kernel`)

Stats columns are `median / mean / p95 / stdev` in ns. `Sub-100ns` is a value-range flag, not a measurement-validity warning; the strict run uses `rdtsc`, pinned CPU, `performance` governor, and turbo disabled.

| Benchmark | Family | llvmbpf stats | kernel stats | Strict ratio | Non-strict ratio | Delta | Sub-100ns |
| --- | --- | --- | --- | ---: | ---: | ---: | --- |
| branch_layout | branch-skew | 144 / 148.9 / 165 / 13.2 | 613 / 609.0 / 663 / 31.5 | 0.235x | 0.291x | -0.057 | none |
| memory_pair_sum | baseline | 12 / 12.8 / 15 / 1.2 | 43.5 / 41.0 / 56 / 13.3 | 0.276x | 1.692x | -1.416 | both<100 |
| packet_parse_vlans_tcpopts | parser | 17 / 18.3 / 26 / 2.8 | 56 / 52.9 / 87 / 27.5 | 0.304x | 1.200x | -0.896 | both<100 |
| simple | baseline | 12 / 14.0 / 26 / 5.4 | 37 / 32.4 / 45 / 11.5 | 0.324x | 1.909x | -1.585 | both<100 |
| cmov_select | select-diamond | 204 / 207.6 / 267 / 18.6 | 597.5 / 596.6 / 642 / 31.7 | 0.341x | 0.539x | -0.198 | none |
| simple_packet | baseline | 12 / 13.7 / 23 / 4.1 | 34.5 / 29.2 / 41 / 12.0 | 0.348x | 1.467x | -1.119 | both<100 |
| load_byte_recompose | causal-isolation | 80 / 86.0 / 128 / 14.8 | 224.5 / 228.1 / 280 / 30.5 | 0.356x | 0.467x | -0.110 | llvmbpf<100 |
| deep_guard_tree_8 | deep-guards | 52 / 57.6 / 113 / 16.8 | 138.5 / 138.1 / 175 / 26.4 | 0.375x | 0.768x | -0.392 | llvmbpf<100 |
| stride_load_4 | stride-load | 109 / 114.8 / 126 / 19.1 | 287.5 / 282.7 / 323 / 26.4 | 0.379x | 0.205x | +0.174 | none |
| rotate64_hash | rotate-hash | 40 / 41.8 / 47 / 3.1 | 105 / 108.9 / 163 / 30.9 | 0.381x | 1.012x | -0.631 | llvmbpf<100 |
| bounds_ladder | bounds-density | 89 / 90.6 / 97 / 3.3 | 232.5 / 224.9 / 267 / 31.5 | 0.383x | 0.531x | -0.148 | llvmbpf<100 |
| binary_search | search | 239 / 239.7 / 248 / 5.3 | 614 / 607.4 / 653 / 35.9 | 0.389x | 0.287x | +0.102 | none |
| stride_load_16 | stride-load | 109 / 113.6 / 136 / 12.8 | 276.5 / 277.9 / 338 / 31.0 | 0.394x | 0.425x | -0.031 | none |
| packet_redundant_bounds | bounds-density | 74 / 77.1 / 86 / 10.5 | 184.5 / 183.8 / 215 / 23.4 | 0.401x | 0.627x | -0.226 | llvmbpf<100 |
| nested_loop_3 | nested-loop | 351 / 353.9 / 364 / 15.1 | 812.5 / 822.6 / 882 / 32.0 | 0.432x | 0.374x | +0.058 | none |
| memcmp_prefix_64 | byte-compare | 77.5 / 79.6 / 95 / 7.8 | 161.5 / 155.3 / 195 / 26.8 | 0.480x | 0.895x | -0.415 | llvmbpf<100 |
| local_call_fanout | bpf-local-call | 88 / 90.2 / 101 / 3.6 | 180 / 177.0 / 221 / 26.7 | 0.489x | 1.062x | -0.574 | llvmbpf<100 |
| struct_field_cluster | field-access | 58 / 58.9 / 66 / 3.3 | 118 / 120.2 / 152 / 21.6 | 0.492x | 0.909x | -0.418 | llvmbpf<100 |
| packet_rss_hash | packet-hash | 25 / 26.4 / 30 / 2.1 | 49.5 / 49.4 / 82 / 24.2 | 0.505x | 1.400x | -0.895 | both<100 |
| alu32_64_pingpong | mixed-width | 281 / 283.7 / 295 / 4.2 | 544 / 535.6 / 566 / 24.6 | 0.517x | 0.787x | -0.271 | none |
| fixed_loop_small | fixed-loop | 81 / 84.0 / 94 / 4.6 | 144.5 / 144.8 / 186 / 23.2 | 0.561x | 1.908x | -1.347 | llvmbpf<100 |
| tc_bitcount | popcount | 2557.5 / 2564.0 / 2635 / 27.1 | 4514 / 4567.7 / 4738 / 111.8 | 0.567x | 1.121x | -0.555 | none |
| mixed_alu_mem | mixed-alu-mem | 490.5 / 491.1 / 501 / 5.2 | 839 / 846.4 / 927 / 40.2 | 0.585x | 0.654x | -0.069 | none |
| bitcount | popcount | 2774.5 / 2790.1 / 2886 / 45.6 | 4542 / 4637.9 / 4949 / 173.3 | 0.611x | 1.465x | -0.854 | none |
| cmov_dense | select-diamond | 54 / 56.1 / 65 / 5.3 | 88 / 89.0 / 132 / 22.6 | 0.614x | 0.879x | -0.265 | both<100 |
| const_fold_chain | const-fold | 200.5 / 209.3 / 242 / 14.2 | 324 / 326.6 / 368 / 20.6 | 0.619x | 0.636x | -0.017 | none |
| load_word32 | load-width | 80 / 86.0 / 121 / 12.3 | 121.5 / 121.3 / 164 / 23.3 | 0.658x | 0.960x | -0.301 | llvmbpf<100 |
| packet_parse | parser | 93 / 93.6 / 102 / 3.1 | 135.5 / 133.6 / 177 / 29.0 | 0.686x | 0.446x | +0.240 | llvmbpf<100 |
| load_byte | load-width | 219 / 223.9 / 254 / 11.1 | 317.5 / 320.4 / 348 / 23.8 | 0.690x | 0.785x | -0.095 | none |
| switch_dispatch | switch-dispatch | 251 / 252.4 / 276 / 10.6 | 357.5 / 355.4 / 401 / 28.8 | 0.702x | 0.769x | -0.067 | none |
| bpf_call_chain | bpf-local-call | 293 / 297.7 / 319 / 10.0 | 415.5 / 412.2 / 448 / 22.5 | 0.705x | 0.808x | -0.103 | none |
| load_native_u64 | causal-isolation | 80 / 85.4 / 111 / 12.0 | 112 / 113.3 / 163 / 23.0 | 0.714x | 1.010x | -0.296 | llvmbpf<100 |
| bitfield_extract | bitfield-extract | 214.5 / 218.0 / 232 / 13.4 | 297 / 293.8 / 353 / 31.9 | 0.722x | 0.767x | -0.044 | none |
| large_mixed_500 | large-mixed | 468 / 475.6 / 516 / 19.8 | 630.5 / 633.3 / 671 / 22.8 | 0.742x | 0.737x | +0.005 | none |
| multi_acc_8 | multi-acc | 395.5 / 398.1 / 419 / 9.4 | 529 / 526.8 / 588 / 36.6 | 0.748x | 0.954x | -0.206 | none |
| branch_fanout_32 | branch-fanout | 327 / 323.1 / 336 / 13.4 | 436.5 / 436.9 / 476 / 24.5 | 0.749x | 0.510x | +0.240 | none |
| checksum | reduction | 13250.5 / 13259.4 / 13314 / 24.4 | 17658 / 17656.9 / 17710 / 27.6 | 0.750x | 0.866x | -0.116 | none |
| tc_checksum | reduction | 13254 / 13262.5 / 13309 / 23.7 | 17616.5 / 17625.4 / 17673 / 21.1 | 0.752x | 0.885x | -0.133 | none |
| dep_chain_short | dep-chain | 135 / 144.6 / 203 / 21.3 | 176.5 / 180.6 / 223 / 27.7 | 0.765x | 1.079x | -0.314 | none |
| imm64_storm | immediate-stress | 183.5 / 189.0 / 207 / 15.3 | 234 / 240.8 / 292 / 30.0 | 0.784x | 0.818x | -0.034 | none |
| bounds_check_heavy | bounds-style | 236 / 231.8 / 244 / 11.2 | 294 / 291.0 / 342 / 25.1 | 0.803x | 0.866x | -0.064 | none |
| large_mixed_1000 | large-mixed | 1040 / 1043.6 / 1059 / 10.8 | 1223 / 1220.5 / 1261 / 26.5 | 0.850x | 0.746x | +0.104 | none |
| log2_fold | log2-fold | 303 / 307.7 / 333 / 8.8 | 350 / 350.9 / 393 / 24.9 | 0.866x | 1.055x | -0.189 | none |
| mega_basic_block_2048 | mega-block | 876.5 / 877.2 / 887 / 4.1 | 987 / 982.2 / 1020 / 24.8 | 0.888x | 0.933x | -0.045 | none |
| nested_loop_2 | nested-loop | 521 / 524.6 / 565 / 14.2 | 582.5 / 585.2 / 618 / 24.0 | 0.894x | 0.827x | +0.067 | none |
| spill_pressure | spill-pressure | 329.5 / 333.8 / 353 / 8.1 | 367 / 369.8 / 419 / 30.4 | 0.898x | 0.980x | -0.082 | none |
| fibonacci_iter | recurrence | 848 / 849.9 / 867 / 7.2 | 939 / 938.2 / 995 / 31.5 | 0.903x | 0.864x | +0.039 | none |
| fibonacci_iter_packet | recurrence | 848 / 849.0 / 863 / 6.4 | 937 / 934.8 / 981 / 34.7 | 0.905x | 0.867x | +0.038 | none |
| code_clone_2 | code-clone | 400.5 / 407.0 / 466 / 20.5 | 428 / 423.9 / 472 / 26.5 | 0.936x | 1.403x | -0.468 | none |
| smallmul_strength_reduce | strength-reduce | 349 / 352.2 / 384 / 11.6 | 371 / 373.7 / 417 / 27.2 | 0.941x | 1.097x | -0.156 | none |
| multi_acc_4 | multi-acc | 293 / 298.0 / 313 / 8.8 | 311 / 308.4 / 343 / 21.4 | 0.942x | 0.984x | -0.042 | none |
| dep_chain_long | dep-chain | 513 / 512.5 / 521 / 4.3 | 536.5 / 539.8 / 581 / 23.3 | 0.956x | 1.057x | -0.101 | none |
| fixed_loop_large | fixed-loop | 1459 / 1460.4 / 1472 / 5.6 | 1503 / 1500.5 / 1546 / 23.4 | 0.971x | 1.033x | -0.062 | none |
| cgroup_hash_chain | hash-chain | 314 / 318.4 / 344 / 8.8 | 290 / 296.9 / 333 / 16.2 | 1.083x | 1.320x | -0.237 | none |
| code_clone_8 | code-clone | 1772 / 1778.2 / 1804 / 16.5 | 1492 / 1492.0 / 1539 / 27.2 | 1.188x | 1.983x | -0.796 | none |
| branch_dense | branch-density | 671 / 675.6 / 707 / 15.3 | 553.5 / 553.9 / 587 / 21.9 | 1.212x | 1.316x | -0.104 | none |

### Micro Takeaways

- The strict rerun is much stronger than the provisional `3x100` run: geomean improves from `0.848x` to `0.609x` on the same `56` benchmarks, and the count of llvmbpf wins rises from `36/56` to `53/56`.
- The strict result is not driven only by ultra-short cases. Even after excluding all benchmarks with `kernel median <100ns`, the geomean is still `0.645x`; requiring both runtimes to be at least `100ns` still leaves a `0.707x` geomean across `38` benchmarks.
- Short benchmarks were exactly where the non-strict run was least trustworthy: `17` benchmarks flipped from apparent kernel wins (`>1.0x`) to llvmbpf wins (`<1.0x`) under the stricter protocol.
- For the paper, the strict `30x1000` dataset should be treated as the authoritative micro result. The older `3x100` run is useful only as provisional history and should not be cited as the main micro headline.

## Paper-facing Threshold Recommendation

- Corpus (`ktime`): use the unfiltered result plus a primary sensitivity analysis at `stock exec_ns >= 100ns`. That cut removes the obviously sub-resolution tail while retaining a still-meaningful sample (`62` programs in each run).
- Corpus (`ktime`): report `>=200ns` only as a sensitivity/robustness appendix, not as the main figure, because it changes the sign with only `13-16` programs.
- Micro (`rdtsc` strict): do not apply the corpus `ktime` threshold logic mechanically. The strict setup already provides cycle-level timing, and the headline remains strong even after removing the short-latency cases.
