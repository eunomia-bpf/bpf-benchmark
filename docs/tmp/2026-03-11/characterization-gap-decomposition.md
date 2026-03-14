# Characterization Gap Decomposition

## Inputs

- Characterization strict JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative_strict_20260312.json` (git:HEAD)
- Recompile strict JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/kernel_recompile_strict_20260312.json` (worktree)
- Context docs: `docs/kernel-jit-optimization-plan.md`, `docs/tmp/kernel-recompile-micro-strict.md`, `docs/tmp/sub-ktime-and-strict-analysis.md`, `micro/results/pass_ablation_authoritative.md`, `micro/results/causal_isolation_analysis.md`, `docs/tmp/directive-gap-analysis.md`, `docs/tmp/optimization-beyond-isel.md`

## Method Notes

- `characterization gap` is `kernel_stock(characterization) / llvmbpf`; `>1.0x` means llvmbpf is faster.
- `BpfReJIT recovery` is `kernel_stock(recompile) / kernel_recompile`; `>1.0x` means recompile is faster than stock in the recompile suite.
- `remaining gap (raw)` is the requested `kernel_recompile / llvmbpf`, but it combines two separate strict runs: characterization is `30x1000`, recompile is `2/10/500`.
- Because the two strict suites have different stock medians on sub-100ns kernels, `remaining gap (raw)` is not algebraically equal to `characterization gap / recovery` on the full 50-benchmark overlap.
- `remaining gap (implied)` is therefore also reported as `characterization gap / recovery`. This is the cleaner decomposition metric for answering how much of the characterization gap the recompile result actually closes.
- `recovery fraction` can be negative or exceed `1.0` on individual benchmarks. Negative means recompile widened the gap; values above `1.0` mean the local recovery exceeded the original characterization gap, usually on near-parity rows with a small denominator.
- The stock-alignment rows below show the mismatch source: on all 56 benchmarks, `kernel_stock(recompile) / kernel_stock(characterization)` geomean is low, but it returns to ~1.0x after excluding sub-100ns characterization kernels.

## Overall Summary

| Metric | Value | Notes |
| --- | --- | --- |
| Characterization gap geomean (all 56) | 1.641x | kernel_stock(char) / llvmbpf |
| Characterization gap geomean (valid recompile subset) | 1.642x | same 50-benchmark subset used for recovery |
| BpfReJIT recovery geomean (valid 50) | 1.028x | kernel_stock(recompile) / kernel_recompile |
| Remaining gap geomean, raw (valid 50) | 1.410x | kernel_recompile / llvmbpf across two separate strict runs |
| Remaining gap geomean, implied (valid 50) | 1.598x | characterization_gap / recovery; clean decomposition metric |
| Recovery fraction (overall, valid 50) | 4.3% | (recovery_geomean - 1) / (gap_geomean - 1) |
| Stock alignment geomean (all 56) | 0.896x | kernel_stock(recompile) / kernel_stock(characterization) |
| Stock alignment geomean (characterization stock >=100ns) | 0.997x | sub-100ns cases removed |
| Raw remaining gap geomean (characterization stock >=100ns) | 1.475x | raw vs implied largely agree once sub-100ns cases are removed |
| Raw remaining gap geomean (both characterization runtimes >=100ns) | 1.403x | 33-benchmark cleaner timing subset |

Interpretation: on the clean overlap, BpfReJIT closes only a small slice of the strict characterization gap. Using the aligned geomean formula, the recovered share is about one-twenty-fifth of the gap, leaving an implied remaining gap around `1.60x` on the valid 50-benchmark subset.

## Gap Buckets

| Bucket | All | Valid | Char gap gm | Recovery gm | Remaining raw gm | Remaining implied gm | Overall recovery fraction | Examples |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| >2x | 18 | 16 | 2.700x | 1.068x | 1.830x | 2.542x | 4.0% | branch_layout, memory_pair_sum, packet_parse_vlans_tcpopts |
| 1.5-2x | 9 | 8 | 1.725x | 1.022x | 1.460x | 1.689x | 3.1% | packet_rss_hash, alu32_64_pingpong, fixed_loop_small |
| 1.2-1.5x | 14 | 12 | 1.359x | 1.014x | 1.300x | 1.330x | 4.1% | packet_parse, load_byte, switch_dispatch |
| 1.0-1.2x | 12 | 12 | 1.097x | 0.988x | 1.139x | 1.110x | -12.7% | large_mixed_1000, log2_fold, mega_basic_block_2048 |
| <1.0x | 3 | 2 | 0.862x | 1.062x | 0.885x | 0.830x | -52.8% | cgroup_hash_chain, code_clone_8, branch_dense |

Bucket takeaway: recovery is concentrated in a handful of large-gap benchmarks, but even the `>2x` bucket still retains a large implied remaining gap. The `1.0-1.2x` bucket is noisy enough that blind all-apply often regresses rather than closes the gap.

## Benchmarks With Strong Recovery

Filtered to valid recompile rows with characterization stock `>=100ns`, characterization gap `>=1.2x`, and at least one applied site.

| Benchmark | Family | Char gap | Recovery | Remaining implied | Recovery fraction | Sites | Applied | Status |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| bounds_check_heavy | bounds-style | 1.246x | 1.144x | 1.089x | 0.588 | 14 | yes | ok |
| rotate64_hash | rotate-hash | 2.625x | 1.600x | 1.641x | 0.369 | 123 | yes | ok |
| packet_redundant_bounds | bounds-density | 2.493x | 1.508x | 1.653x | 0.340 | 8 | yes | ok |
| imm64_storm | immediate-stress | 1.275x | 1.080x | 1.181x | 0.291 | 68 | yes | ok |
| load_word32 | load-width | 1.519x | 1.143x | 1.329x | 0.275 | 2 | yes | ok |
| fixed_loop_small | fixed-loop | 1.784x | 1.198x | 1.489x | 0.252 | 4 | yes | ok |
| bitfield_extract | bitfield-extract | 1.385x | 1.083x | 1.279x | 0.215 | 11 | yes | ok |
| dep_chain_short | dep-chain | 1.307x | 1.056x | 1.239x | 0.181 | 2 | yes | ok |
| deep_guard_tree_8 | deep-guards | 2.663x | 1.298x | 2.052x | 0.179 | 2 | yes | ok |
| multi_acc_8 | multi-acc | 1.338x | 1.056x | 1.267x | 0.166 | 4 | yes | ok |

These are the clear positive cases. The best closures are `bounds_check_heavy`, `rotate64_hash`, and `packet_redundant_bounds`; after them the recovery drops quickly into partial-gap territory rather than majority closure.

## Benchmarks With No Recovery Or Regression

Same filter as above, but sorted by worst recovery fraction first.

| Benchmark | Family | Char gap | Recovery | Remaining implied | Recovery fraction | Sites | Applied | Status |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| packet_parse | parser | 1.457x | 0.832x | 1.752x | -0.368 | 5 | yes | ok |
| large_mixed_500 | large-mixed | 1.347x | 0.876x | 1.537x | -0.356 | 11 | yes | ok |
| struct_field_cluster | field-access | 2.034x | 0.924x | 2.202x | -0.074 | 0 | no | ok |
| load_byte_recompose | causal-isolation | 2.806x | 0.877x | 3.199x | -0.068 | 1 | yes | ok |
| memcmp_prefix_64 | byte-compare | 2.084x | 0.966x | 2.157x | -0.031 | 4 | yes | ok |
| tc_bitcount | popcount | 1.765x | 0.979x | 1.803x | -0.027 | 2 | yes | ok |
| load_byte | load-width | 1.450x | 0.992x | 1.461x | -0.017 | 2 | yes | ok |
| nested_loop_3 | nested-loop | 2.315x | 0.995x | 2.327x | -0.004 | 3 | yes | ok |
| branch_fanout_32 | branch-fanout | 1.335x | 0.999x | 1.337x | -0.004 | 9 | yes | ok |
| bitcount | popcount | 1.637x | 0.999x | 1.639x | -0.002 | 2 | yes | ok |
| checksum | reduction | 1.333x | 0.999x | 1.333x | -0.002 | 2 | yes | ok |
| stride_load_4 | stride-load | 2.638x | 1.002x | 2.633x | 0.001 | 3 | yes | ok |
| branch_layout | branch-skew | 4.257x | 1.010x | 4.214x | 0.003 | 2 | yes | ok |
| stride_load_16 | stride-load | 2.537x | 1.006x | 2.523x | 0.004 | 3 | yes | ok |
| tc_checksum | reduction | 1.329x | 1.002x | 1.327x | 0.005 | 2 | yes | ok |

These rows matter more than the wins for the decomposition question. `load_byte_recompose`, `stride_load_*`, `branch_layout`, and `cmov_select` are especially important because prior characterization evidence says they are backend-heavy, yet the current blind all-apply path barely helps or actively hurts them.

## Missing / Invalid Recompile Data

| Benchmark | Family | Char gap | Sites | Applied | Status | Failure reason | Observed recompile median |
| --- | --- | --- | --- | --- | --- | --- | --- |
| bounds_ladder | bounds-density | 2.612x | 0 | no | vm-crash | - | n/a |
| binary_search | search | 2.569x | 3 | yes | result-mismatch | result-mismatch | 44 ns |
| mixed_alu_mem | mixed-alu-mem | 1.710x | 0 | no | vm-crash | - | n/a |
| switch_dispatch | switch-dispatch | 1.424x | 3 | yes | result-mismatch | result-mismatch | 318 ns |
| bpf_call_chain | bpf-local-call | 1.418x | 3 | yes | result-mismatch | result-mismatch | 24 ns |
| branch_dense | branch-density | 0.825x | 7 | yes | result-mismatch | result-mismatch | 20 ns |

Important missing-data note: `binary_search`, `switch_dispatch`, `branch_dense`, and `bpf_call_chain` were site-positive but failed with `result-mismatch`; `bounds_ladder` and `mixed_alu_mem` failed with VM crashes. These six rows sit directly on the decomposition critical path, because several of them are among the larger characterization gaps.

## Gap Source Discussion

| Heuristic bucket | Rows | Valid | Char gap gm | Recovery gm | Remaining implied gm | Examples | Reading |
| --- | --- | --- | --- | --- | --- | --- | --- |
| backend_demonstrated | 6 | 6 | 1.744x | 1.264x | 1.380x | rotate64_hash, packet_redundant_bounds, fixed_loop_small | already showing real backend-lowering recovery |
| backend_unrecovered | 19 | 16 | 1.911x | 0.973x | 2.000x | branch_layout, cmov_select, load_byte_recompose | backend-like headroom exists, but blind all-apply is not recovering it yet |
| llvm_pass_likely | 11 | 9 | 1.714x | 0.962x | 1.737x | packet_parse_vlans_tcpopts, binary_search, nested_loop_3 | likely dominated by LLVM InstCombine/SimplifyCFG style IR cleanup |
| overhead_likely | 8 | 6 | 2.152x | 1.015x | 2.134x | memory_pair_sum, simple, simple_packet | likely fixed overhead, function-boundary cost, or non-site runtime effects |

### 1. Backend lowering that BpfReJIT already demonstrably recovers

- Best evidence: `rotate64_hash`, `packet_redundant_bounds`, `bounds_check_heavy`, `load_word32`, `fixed_loop_small`, `imm64_storm`.
- These are the benchmarks where the current directive families actually move runtime in the right direction. The positive set is dominated by local lowering wins: rotate fusion, bounds/check simplification, and some load-width or extract-style cases.
- Even here, recovery is usually partial. Only `bounds_check_heavy` clears the 50% recovery-fraction line, and that happens on a modest `1.246x` gap rather than on the largest llvmbpf wins.

### 2. Backend lowering that should be recoverable, but is not recovered by the current blind path

- Strong examples: `load_byte_recompose`, `stride_load_4`, `stride_load_16`, `branch_layout`, `cmov_select`, plus invalid site-positive rows `binary_search`, `switch_dispatch`, `bounds_ladder`, and `bpf_call_chain`.
- This bucket matters most for #125. Prior characterization attributes the largest native-code headroom to byte-recompose (`50.7%` of surplus, `2.24x` isolated penalty in `load_byte_recompose`) and to branch/control-flow (`19.9%` of surplus). But the current recompile run does not convert that headroom into whole-benchmark closure.
- The current data therefore support a sharper conclusion than "backend lowering does not matter": backend lowering clearly matters, but the present BpfReJIT implementation is recovering only a small, selective subset of the backend gap.

### 3. Remaining gap likely dominated by LLVM passes / CFG cleanup

- Likely cases: `large_mixed_500`, `large_mixed_1000`, `packet_parse`, `nested_loop_3`, `smallmul_strength_reduce`, `branch_dense`, and parts of the `code-clone` / `dep-chain` families.
- Reasoning: these rows retain sizable characterization gaps while seeing little or negative recovery from backend-only recompile. That pattern matches the prior pass-ablation result that only `InstCombinePass` and `SimplifyCFGPass` materially move BPF output.
- This is an inference, not a direct proof per benchmark. The evidence is: backend-only recompile does not close the gap; the repo's pass-ablation says the remaining LLVM leverage is concentrated in IR-level combination and CFG cleanup; and these families are exactly the ones where that style of simplification is plausible.

### 4. Prologue / epilogue overhead and other runtime effects

- Likely rows: `simple`, `simple_packet`, `memory_pair_sum`, `load_native_u64`, `mega_basic_block_2048`, and `struct_field_cluster`.
- These rows have either no applied sites or zero detected sites, yet some still show noticeable characterization gaps. That points away from current directive-covered lowering and toward fixed overhead, function-boundary cost, or other non-site effects.
- Caution: the current stock kernel is already on a `7.0-rc2` lineage where per-function callee-saved trimming exists upstream, so the earlier `18.5%` prologue/epilogue surplus share should be treated as historical upper-bound context, not as the exact remaining share in this strict 56-benchmark run.

## Full Per-Benchmark Table

| Benchmark | Family | llvmbpf | kernel stock (char) | kernel recompile | Char gap | Recovery | Remaining raw | Remaining implied | Recovery fraction | Sites | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| branch_layout | branch-skew | 144 ns | 613 ns | 644 ns | 4.257x | 1.010x | 4.472x | 4.214x | 0.003 | 2 | ok |
| memory_pair_sum | baseline | 12 ns | 43.5 ns | 13 ns | 3.625x | 0.808x | 1.083x | 4.488x | -0.073 | 2 | ok |
| packet_parse_vlans_tcpopts | parser | 17 ns | 56 ns | 26 ns | 3.294x | 1.000x | 1.529x | 3.294x | 0.000 | 7 | ok |
| simple | baseline | 12 ns | 37 ns | 11 ns | 3.083x | 1.000x | 0.917x | 3.083x | 0.000 | 0 | ok / no-sites |
| cmov_select | select-diamond | 204 ns | 597.5 ns | 594.5 ns | 2.929x | 1.031x | 2.914x | 2.841x | 0.016 | 11 | ok |
| simple_packet | baseline | 12 ns | 34.5 ns | 7 ns | 2.875x | 1.286x | 0.583x | 2.236x | 0.152 | 0 | ok / no-sites |
| load_byte_recompose | causal-isolation | 80 ns | 224.5 ns | 236 ns | 2.806x | 0.877x | 2.950x | 3.199x | -0.068 | 1 | ok |
| deep_guard_tree_8 | deep-guards | 52 ns | 138.5 ns | 114 ns | 2.663x | 1.298x | 2.192x | 2.052x | 0.179 | 2 | ok |
| stride_load_4 | stride-load | 109 ns | 287.5 ns | 269 ns | 2.638x | 1.002x | 2.468x | 2.633x | 0.001 | 3 | ok |
| rotate64_hash | rotate-hash | 40 ns | 105 ns | 65 ns | 2.625x | 1.600x | 1.625x | 1.641x | 0.369 | 123 | ok |
| bounds_ladder | bounds-density | 89 ns | 232.5 ns | n/a | 2.612x | n/a | n/a | n/a | n/a | 0 | vm-crash |
| binary_search | search | 239 ns | 614 ns | 44 ns | 2.569x | n/a | n/a | n/a | n/a | 3 | result-mismatch (result-mismatch) |
| stride_load_16 | stride-load | 109 ns | 276.5 ns | 272 ns | 2.537x | 1.006x | 2.495x | 2.523x | 0.004 | 3 | ok |
| packet_redundant_bounds | bounds-density | 74 ns | 184.5 ns | 120 ns | 2.493x | 1.508x | 1.622x | 1.653x | 0.340 | 8 | ok |
| nested_loop_3 | nested-loop | 351 ns | 812.5 ns | 828 ns | 2.315x | 0.995x | 2.359x | 2.327x | -0.004 | 3 | ok |
| memcmp_prefix_64 | byte-compare | 77.5 ns | 161.5 ns | 148 ns | 2.084x | 0.966x | 1.910x | 2.157x | -0.031 | 4 | ok |
| local_call_fanout | bpf-local-call | 88 ns | 180 ns | 140.5 ns | 2.045x | 1.075x | 1.597x | 1.903x | 0.071 | 21 | ok |
| struct_field_cluster | field-access | 58 ns | 118 ns | 105 ns | 2.034x | 0.924x | 1.810x | 2.202x | -0.074 | 0 | ok / no-sites |
| packet_rss_hash | packet-hash | 25 ns | 49.5 ns | 22 ns | 1.980x | 1.273x | 0.880x | 1.556x | 0.278 | 13 | ok |
| alu32_64_pingpong | mixed-width | 281 ns | 544 ns | 499.5 ns | 1.936x | 1.040x | 1.778x | 1.861x | 0.043 | 4 | ok |
| fixed_loop_small | fixed-loop | 81 ns | 144.5 ns | 134 ns | 1.784x | 1.198x | 1.654x | 1.489x | 0.252 | 4 | ok |
| tc_bitcount | popcount | 2.558 us | 4.514 us | 4.659 us | 1.765x | 0.979x | 1.822x | 1.803x | -0.027 | 2 | ok |
| mixed_alu_mem | mixed-alu-mem | 490.5 ns | 839 ns | n/a | 1.710x | n/a | n/a | n/a | n/a | 0 | vm-crash |
| bitcount | popcount | 2.775 us | 4.542 us | 4.456 us | 1.637x | 0.999x | 1.606x | 1.639x | -0.002 | 2 | ok |
| cmov_dense | select-diamond | 54 ns | 88 ns | 73.5 ns | 1.630x | 0.612x | 1.361x | 2.662x | -0.616 | 32 | ok |
| const_fold_chain | const-fold | 200.5 ns | 324 ns | 306.5 ns | 1.616x | 1.100x | 1.529x | 1.470x | 0.162 | 2 | ok |
| load_word32 | load-width | 80 ns | 121.5 ns | 105 ns | 1.519x | 1.143x | 1.312x | 1.329x | 0.275 | 2 | ok |
| packet_parse | parser | 93 ns | 135.5 ns | 151.5 ns | 1.457x | 0.832x | 1.629x | 1.752x | -0.368 | 5 | ok |
| load_byte | load-width | 219 ns | 317.5 ns | 326 ns | 1.450x | 0.992x | 1.489x | 1.461x | -0.017 | 2 | ok |
| switch_dispatch | switch-dispatch | 251 ns | 357.5 ns | 318 ns | 1.424x | n/a | n/a | n/a | n/a | 3 | result-mismatch (result-mismatch) |
| bpf_call_chain | bpf-local-call | 293 ns | 415.5 ns | 24 ns | 1.418x | n/a | n/a | n/a | n/a | 3 | result-mismatch (result-mismatch) |
| load_native_u64 | causal-isolation | 80 ns | 112 ns | 90.5 ns | 1.400x | 1.099x | 1.131x | 1.273x | 0.249 | 0 | ok / no-sites |
| bitfield_extract | bitfield-extract | 214.5 ns | 297 ns | 260 ns | 1.385x | 1.083x | 1.212x | 1.279x | 0.215 | 11 | ok |
| large_mixed_500 | large-mixed | 468 ns | 630.5 ns | 704 ns | 1.347x | 0.876x | 1.504x | 1.537x | -0.356 | 11 | ok |
| multi_acc_8 | multi-acc | 395.5 ns | 529 ns | 535 ns | 1.338x | 1.056x | 1.353x | 1.267x | 0.166 | 4 | ok |
| branch_fanout_32 | branch-fanout | 327 ns | 436.5 ns | 398.5 ns | 1.335x | 0.999x | 1.219x | 1.337x | -0.004 | 9 | ok |
| checksum | reduction | 13.251 us | 17.658 us | 17.741 us | 1.333x | 0.999x | 1.339x | 1.333x | -0.002 | 2 | ok |
| tc_checksum | reduction | 13.254 us | 17.616 us | 17.704 us | 1.329x | 1.002x | 1.336x | 1.327x | 0.005 | 2 | ok |
| dep_chain_short | dep-chain | 135 ns | 176.5 ns | 171 ns | 1.307x | 1.056x | 1.267x | 1.239x | 0.181 | 2 | ok |
| imm64_storm | immediate-stress | 183.5 ns | 234 ns | 200 ns | 1.275x | 1.080x | 1.090x | 1.181x | 0.291 | 68 | ok |
| bounds_check_heavy | bounds-style | 236 ns | 294 ns | 270 ns | 1.246x | 1.144x | 1.144x | 1.089x | 0.588 | 14 | ok |
| large_mixed_1000 | large-mixed | 1.040 us | 1.223 us | 1.182 us | 1.176x | 1.002x | 1.137x | 1.173x | 0.012 | 16 | ok |
| log2_fold | log2-fold | 303 ns | 350 ns | 353 ns | 1.155x | 1.016x | 1.165x | 1.137x | 0.100 | 3 | ok |
| mega_basic_block_2048 | mega-block | 876.5 ns | 987 ns | 959.5 ns | 1.126x | 1.036x | 1.095x | 1.087x | 0.285 | 520 | ok |
| nested_loop_2 | nested-loop | 521 ns | 582.5 ns | 708.5 ns | 1.118x | 0.852x | 1.360x | 1.313x | -1.255 | 3 | ok |
| spill_pressure | spill-pressure | 329.5 ns | 367 ns | 368 ns | 1.114x | 1.034x | 1.117x | 1.077x | 0.298 | 2 | ok |
| fibonacci_iter | recurrence | 848 ns | 939 ns | 996.5 ns | 1.107x | 0.990x | 1.175x | 1.118x | -0.089 | 4 | ok |
| fibonacci_iter_packet | recurrence | 848 ns | 937 ns | 911 ns | 1.105x | 1.023x | 1.074x | 1.080x | 0.220 | 4 | ok |
| code_clone_2 | code-clone | 400.5 ns | 428 ns | 389.5 ns | 1.069x | 1.018x | 0.973x | 1.050x | 0.262 | 2 | ok |
| smallmul_strength_reduce | strength-reduce | 349 ns | 371 ns | 464 ns | 1.063x | 0.880x | 1.330x | 1.207x | -1.897 | 2 | ok |
| multi_acc_4 | multi-acc | 293 ns | 311 ns | 303 ns | 1.061x | 1.002x | 1.034x | 1.060x | 0.027 | 3 | ok |
| dep_chain_long | dep-chain | 513 ns | 536.5 ns | 562 ns | 1.046x | 0.980x | 1.096x | 1.068x | -0.447 | 2 | ok |
| fixed_loop_large | fixed-loop | 1.459 us | 1.503 us | 1.716 us | 1.030x | 1.042x | 1.176x | 0.989x | 1.391 | 4 | ok |
| cgroup_hash_chain | hash-chain | 314 ns | 290 ns | 314 ns | 0.924x | 1.046x | 1.000x | 0.883x | -0.604 | 2 | ok |
| code_clone_8 | code-clone | 1.772 us | 1.492 us | 1.387 us | 0.842x | 1.079x | 0.783x | 0.780x | -0.499 | 3 | ok |
| branch_dense | branch-density | 671 ns | 553.5 ns | 20 ns | 0.825x | n/a | n/a | n/a | n/a | 7 | result-mismatch (result-mismatch) |

## Bottom Line

- Strict characterization says llvmbpf is about `1.64x` faster than stock kernel geomean on the 56-benchmark suite.
- Strict recompile says blind all-apply BpfReJIT recovers only about `1.028x` geomean on the valid 50-benchmark overlap, which translates to roughly `4.3%` of the strict characterization gap.
- The dominant unresolved story is not "BpfReJIT proved backend lowering irrelevant". It is "backend-only headroom is real, but the current directive set and blind policy recover only a small fraction of it, while LLVM pass cleanup and uncovered function-boundary/runtime effects still account for most of the remaining gap."
