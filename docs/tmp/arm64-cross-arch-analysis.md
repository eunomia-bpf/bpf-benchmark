# ARM64 Cross-Architecture Benchmark Analysis

Inputs: `micro/results/arm64_pure_jit.json`, `micro/results/arm64_runtime.json`, `micro/results/pure_jit_with_cmov.json`, `micro/results/runtime_with_map_lookup_repeat.json`.

Method: use each benchmark/runtime pair's median `exec_ns`, then compute `L/K = llvmbpf / kernel`. Ratios below `1.0` favor `llvmbpf`; ratios above `1.0` favor the kernel JIT. Absolute nanoseconds are not directly comparable across the ARM64 CI VM and the x86 host, so the cross-architecture interpretation below uses L/K ratios rather than raw ns.

All 61 benchmarks match one-to-one across the ARM64 and x86 datasets; there are no missing entries in either direction.

## 1. ARM64 Standalone Results

| Suite | Benchmarks | ARM64 geomean L/K | llvmbpf wins | kernel wins |
| --- | ---: | ---: | ---: | ---: |
| Pure-JIT | 50 | 0.656 | 44 | 6 |
| Runtime | 11 | 1.076 | 3 | 8 |
| Overall | 61 | 0.717 | 47 | 14 |

ARM64 pure-JIT strongly favors `llvmbpf` overall: geomean `L/K = 0.656` with `44/50` llvmbpf wins. ARM64 runtime goes the other way: geomean `L/K = 1.076` with the kernel JIT winning `8/11` benchmarks.

Notable benchmarks where ARM64 behaves differently from x86:

- There are `18` direction flips overall (`15` pure-JIT, `3` runtime). The clearest pure-JIT flips are `bitcount` (`0.544` on ARM64 vs `1.480` on x86), `code_clone_2` (`0.525` vs `1.521`), `code_clone_8` (`0.607` vs `2.008`), `fixed_loop_large` (`0.551` vs `1.182`), and `branch_dense` (`0.762` vs `1.451`).
- ARM64 runtime also flips three cases that favor llvmbpf on x86: `map_roundtrip` (`1.264` vs `0.770`), `atomic_counter_xadd` (`1.031` vs `0.626`), and `helper_call_100` (`1.091` vs `0.778`).
- `switch_dispatch` reverses in the other direction: the kernel wins on ARM64 (`1.300`) but llvmbpf wins on x86 (`0.782`).
- Load-heavy kernels are mixed. `load_byte_recompose` stays a strong llvmbpf win on both arches (`0.351` ARM64, `0.511` x86), but `load_native_u64` and `struct_field_cluster` are much closer to parity on ARM64 (`0.887`, `0.953`) than on x86 (`0.418`, `0.463`).
- Very small baseline kernels (`simple`, `simple_packet`, `memory_pair_sum`) are close to the timing floor on both machines, so their cross-arch L/K swings are less informative than the larger kernels.

## 2. Cross-Architecture Comparison (ARM64 vs x86)

At suite level, ARM64 pure-JIT shows a larger llvmbpf advantage than x86 (`0.656` vs `0.797` geomean L/K), while ARM64 runtime shows a kernel advantage where x86 still slightly favors llvmbpf (`1.076` vs `0.875`). Overall, ARM64 ends at `0.717` geomean L/K versus `0.811` on x86.

Benchmarks with similar L/K on both arches (within 20% relative difference) look like consistent JIT-quality gaps or consistent kernel advantages:

- `map_lookup_repeat` (`2.588` ARM64 vs `2.551` x86), `map_lookup_churn` (`1.114` vs `1.057`), and `get_time_heavy` (`1.103` vs `1.049`) are consistently kernel-favored runtime cases.
- `load_byte` (`0.826` vs `0.842`), `const_fold_chain` (`0.478` vs `0.469`), `spill_pressure` (`0.632` vs `0.609`), and `bounds_ladder` (`0.427` vs `0.505`) are consistently llvmbpf-favored.
- `packet_parse_vlans_tcpopts` (`1.132` vs `1.146`) and `packet_rss_hash` (`1.314` vs `1.355`) are consistently kernel-favored packet/parser kernels.
- `probe_read_heavy` (`0.539` vs `0.455`) and `helper_call_10` (`1.008` vs `1.111`) are directionally stable even though the margins differ.

Benchmarks that diverge suggest architecture-specific JIT quality rather than one universal backend gap:

- Select/branch behavior diverges sharply: `switch_dispatch`, `branch_dense`, `branch_layout`, and `cmov_select` do not preserve the same magnitude or even the same winner across arches.
- Several loop/straight-line kernels flip from x86 kernel wins to ARM64 llvmbpf wins: `bitcount`, `dep_chain_short`, `fixed_loop_small`, `fixed_loop_large`, `code_clone_2`, `code_clone_8`, and `smallmul_strength_reduce`.
- Some load/struct kernels move much closer to parity on ARM64: `load_native_u64`, `struct_field_cluster`, and `memcmp_prefix_64`.
- Runtime helper/map behavior also differs: `map_roundtrip`, `atomic_counter_xadd`, and `helper_call_100` flip sign between arches.

The per-benchmark comparison for all 61 benchmarks is in the summary table below.

## 3. `cmov_select` Cross-Arch

ARM64 still shows the same qualitative LLVM advantage on the diamond-select kernel: `llvmbpf = 587 ns`, `kernel = 1,703 ns`, `L/K = 0.345`. That is about `2.90x` in llvmbpf's favor.

x86 shows an even larger version of the same effect: `llvmbpf = 147.5 ns`, `kernel = 815 ns`, `L/K = 0.181`. That is about `5.53x` in llvmbpf's favor.

Interpretation: the narrow assignment-only diamond is not an x86-only phenomenon. The pattern clearly exists on ARM64 too, but the profitability gap is smaller there. That is consistent with `cmov_select` being a real cross-arch pattern whose exact payoff remains arch-specific (`csel` on ARM64 versus `cmovcc` on x86).

## 4. Architecture-Specific Observations

- ARM64 does not reproduce the x86 backend gaps one-for-one. `load_byte_recompose`, `binary_search`, and `cmov_select` remain strong llvmbpf wins on both arches, so those patterns are genuinely cross-arch. But `switch_dispatch`, `branch_dense`, `map_roundtrip`, and several loop kernels change sign, so backend quality is still architecture-dependent.
- The current local kernel tree already has conditional callee-saved save/restore on both arches. On x86, `detect_reg_usage()` scans `BPF_REG_6..9` and `push_callee_regs()` / `pop_callee_regs()` save only the used subset in normal programs (`vendor/linux/arch/x86/net/bpf_jit_comp.c:355-389`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:1504-1519`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:1680-1701`).
- ARM64 does the same kind of adaptation: `find_used_callee_regs()` collects used `BPF_REG_6..9` plus FP/private-stack/arena state, and `push_callee_regs()` / `pop_callee_regs()` save only that discovered set outside exception-boundary mode (`vendor/linux/arch/arm64/net/bpf_jit_comp.c:374-489`, `vendor/linux/arch/arm64/net/bpf_jit_comp.c:581-582`, `vendor/linux/arch/arm64/net/bpf_jit_comp.c:1042`).
- Exception-boundary paths are still full-save on both backends, and both backends still pay fixed frame-record / tail-call setup costs in the prologue (`vendor/linux/arch/x86/net/bpf_jit_comp.c:506-556`, `vendor/linux/arch/arm64/net/bpf_jit_comp.c:349-360`, `vendor/linux/arch/arm64/net/bpf_jit_comp.c:565-581`). That likely matters most for the tiny sub-100ns kernels, not for the large cross-arch flips above.
- Relative to llvmbpf on the same machine, ARM64's kernel JIT looks stronger than x86 on `switch_dispatch` (`1.300` vs `0.782`), `map_roundtrip` (`1.264` vs `0.770`), `atomic_counter_xadd` (`1.031` vs `0.626`), `struct_field_cluster` (`0.953` vs `0.463`), `load_native_u64` (`0.887` vs `0.418`), and `memcmp_prefix_64` (`0.774` vs `0.368`). This is a ratio-based statement about JIT quality, not a claim that the ARM64 machine is absolutely faster.
- I did not find a generic `csel` lowering path in the local arm64 backend, and the x86 backend only contains a specialized `cmove` site rather than a general select-diamond lowering. That matches the benchmark result: the select pattern is still largely unrecovered by the stock JITs.

## 5. Implications for JIT Advisor

- `wide_load` still matters on ARM64. The byte-ladder case `load_byte_recompose` is an even stronger llvmbpf win on ARM64 than on x86 (`0.351` vs `0.511`), so the core wide-load story is cross-arch rather than x86-specific.
- Cross-arch verifier-level patterns still exist on ARM64: byte ladders (`load_byte_recompose`), bounds ladders (`bounds_ladder`, `packet_redundant_bounds`), and fixed-offset packet/ctx extraction (`packet_parse`, `packet_parse_vlans_tcpopts`, `packet_rss_hash`, `struct_field_cluster`). That supports the v7 split where structural patterns can be discovered once and validated in a verifier-level form.
- But the packet/ctx family is not uniformly an LLVM win on ARM64. `packet_parse_vlans_tcpopts` and `packet_rss_hash` are kernel wins on both arches, and `packet_parse` flips sign (`0.840` ARM64, `1.182` x86). So `packet_ctx_wide_load` and related verifier-level directives are still justified by pattern presence, but not every packet parser is a clean “LLVM already wins” exemplar.
- `cmov_select` still matters on ARM64, but as an arch-specific JIT-level directive rather than a universal rewrite. The benchmark itself is a clear llvmbpf win on ARM64, yet `switch_dispatch` flips to an ARM64 kernel win and the x86 gap is much larger. That is exactly the kind of policy-sensitive lowering decision v7 assigns to the backend stage.
- For cross-arch directives from v7, the strongest ARM64-supported carryovers are `wide_load`, `bounds_window`, and the broader packet/ctx structural patterns. For arch-specific directives, the obvious split is `csel` vs branch on ARM64 and `cmovcc` vs branch on x86.
- ARM64 also suggests a different load-side emphasis than x86. Because `load_native_u64` and `struct_field_cluster` are already near parity on ARM64, the higher-value ARM64 JIT work looks more like byte-ladder fusion and selective pair-load/store shaping (`ldp`/`stp`-style opportunities) than simply replaying the x86 “wider load” story unchanged.

## 6. Summary Table

`LK_diff = arm64_LK - x86_LK`. Positive values mean the ARM64 kernel JIT is relatively stronger against llvmbpf than the x86 kernel JIT on that benchmark; negative values mean the opposite.

| name | suite | arm64_llvmbpf_ns | arm64_kernel_ns | arm64_LK | x86_llvmbpf_ns | x86_kernel_ns | x86_LK | LK_diff |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| simple | pure-jit | 40 | 12 | 3.333 | 28.5 | 15 | 1.900 | 1.433 |
| simple_packet | pure-jit | 38 | 19 | 2.000 | 28.5 | 6.5 | 4.385 | -2.385 |
| memory_pair_sum | pure-jit | 41 | 18 | 2.278 | 17 | 13.5 | 1.259 | 1.019 |
| bitcount | pure-jit | 5,012 | 9,205 | 0.544 | 4,667 | 3,152.5 | 1.480 | -0.936 |
| log2_fold | pure-jit | 374 | 480 | 0.779 | 319.5 | 269 | 1.188 | -0.409 |
| dep_chain_short | pure-jit | 132 | 222 | 0.595 | 120.5 | 107 | 1.126 | -0.532 |
| dep_chain_long | pure-jit | 417 | 866 | 0.482 | 433 | 546 | 0.793 | -0.312 |
| binary_search | pure-jit | 236 | 1,051 | 0.225 | 204.5 | 527.5 | 0.388 | -0.163 |
| branch_layout | pure-jit | 642 | 1,062 | 0.605 | 155 | 550 | 0.282 | 0.323 |
| switch_dispatch | pure-jit | 416 | 320 | 1.300 | 246 | 314.5 | 0.782 | 0.518 |
| branch_dense | pure-jit | 743 | 975 | 0.762 | 624.5 | 430.5 | 1.451 | -0.689 |
| cmov_select | pure-jit | 587 | 1,703 | 0.345 | 147.5 | 815 | 0.181 | 0.164 |
| checksum | pure-jit | 19,169 | 29,047 | 0.660 | 10,830.5 | 12,029.5 | 0.900 | -0.240 |
| load_word32 | pure-jit | 143 | 184 | 0.777 | 82 | 77.5 | 1.058 | -0.281 |
| load_byte | pure-jit | 266 | 322 | 0.826 | 192 | 228 | 0.842 | -0.016 |
| load_byte_recompose | pure-jit | 126 | 359 | 0.351 | 102 | 199.5 | 0.511 | -0.160 |
| load_native_u64 | pure-jit | 134 | 151 | 0.887 | 81 | 194 | 0.418 | 0.470 |
| packet_parse | pure-jit | 136 | 162 | 0.840 | 91 | 77 | 1.182 | -0.342 |
| bounds_ladder | pure-jit | 119 | 279 | 0.427 | 82 | 162.5 | 0.505 | -0.078 |
| bounds_check_heavy | pure-jit | 309 | 461 | 0.670 | 273.5 | 199.5 | 1.371 | -0.701 |
| stride_load_4 | pure-jit | 181 | 412 | 0.439 | 114.5 | 338 | 0.339 | 0.101 |
| stride_load_16 | pure-jit | 184 | 427 | 0.431 | 111.5 | 207 | 0.539 | -0.108 |
| mixed_alu_mem | pure-jit | 784 | 1,504 | 0.521 | 493.5 | 719 | 0.686 | -0.165 |
| spill_pressure | pure-jit | 359 | 568 | 0.632 | 250.5 | 411 | 0.609 | 0.023 |
| multi_acc_4 | pure-jit | 268 | 560 | 0.479 | 266 | 361.5 | 0.736 | -0.257 |
| multi_acc_8 | pure-jit | 466 | 960 | 0.485 | 428 | 413 | 1.036 | -0.551 |
| fibonacci_iter | pure-jit | 882 | 1,584 | 0.557 | 587 | 681.5 | 0.861 | -0.305 |
| fibonacci_iter_packet | pure-jit | 888 | 1,582 | 0.561 | 635 | 680.5 | 0.933 | -0.372 |
| fixed_loop_small | pure-jit | 135 | 170 | 0.794 | 129 | 101.5 | 1.271 | -0.477 |
| fixed_loop_large | pure-jit | 1,346 | 2,441 | 0.551 | 1,519 | 1,285.5 | 1.182 | -0.630 |
| nested_loop_2 | pure-jit | 571 | 1,156 | 0.494 | 442 | 514 | 0.860 | -0.366 |
| nested_loop_3 | pure-jit | 975 | 1,397 | 0.698 | 298.5 | 663.5 | 0.450 | 0.248 |
| code_clone_2 | pure-jit | 304 | 579 | 0.525 | 442.5 | 291 | 1.521 | -0.996 |
| code_clone_8 | pure-jit | 1,173 | 1,933 | 0.607 | 2,255.5 | 1,123 | 2.008 | -1.402 |
| large_mixed_500 | pure-jit | 603 | 1,070 | 0.564 | 428.5 | 499.5 | 0.858 | -0.294 |
| large_mixed_1000 | pure-jit | 1,233 | 2,137 | 0.577 | 779 | 999.5 | 0.779 | -0.202 |
| bpf_call_chain | pure-jit | 285 | 1,039 | 0.274 | 278 | 420 | 0.662 | -0.388 |
| memcmp_prefix_64 | pure-jit | 144 | 186 | 0.774 | 70.5 | 191.5 | 0.368 | 0.406 |
| packet_parse_vlans_tcpopts | pure-jit | 43 | 38 | 1.132 | 27.5 | 24 | 1.146 | -0.014 |
| local_call_fanout | pure-jit | 116 | 233 | 0.498 | 113 | 96.5 | 1.171 | -0.673 |
| packet_rss_hash | pure-jit | 46 | 35 | 1.314 | 21 | 15.5 | 1.355 | -0.041 |
| imm64_storm | pure-jit | 217 | 319 | 0.680 | 200.5 | 280 | 0.716 | -0.036 |
| alu32_64_pingpong | pure-jit | 494 | 584 | 0.846 | 252 | 488 | 0.516 | 0.329 |
| branch_fanout_32 | pure-jit | 460 | 551 | 0.835 | 254 | 383.5 | 0.662 | 0.173 |
| deep_guard_tree_8 | pure-jit | 103 | 171 | 0.602 | 59.5 | 140 | 0.425 | 0.177 |
| mega_basic_block_2048 | pure-jit | 1,026 | 1,647 | 0.623 | 679 | 803.5 | 0.845 | -0.222 |
| packet_redundant_bounds | pure-jit | 113 | 204 | 0.554 | 59 | 135 | 0.437 | 0.117 |
| const_fold_chain | pure-jit | 311 | 651 | 0.478 | 186 | 396.5 | 0.469 | 0.009 |
| struct_field_cluster | pure-jit | 102 | 107 | 0.953 | 57 | 123 | 0.463 | 0.490 |
| smallmul_strength_reduce | pure-jit | 323 | 656 | 0.492 | 364 | 321 | 1.134 | -0.642 |
| map_lookup_churn | runtime | 657 | 590 | 1.114 | 400 | 378.5 | 1.057 | 0.057 |
| map_roundtrip | runtime | 809 | 640 | 1.264 | 458 | 595 | 0.770 | 0.494 |
| map_lookup_repeat | runtime | 2,824 | 1,091 | 2.588 | 1,638 | 642 | 2.551 | 0.037 |
| hash_map_lookup | runtime | 746 | 852 | 0.876 | 405.5 | 644 | 0.630 | 0.246 |
| percpu_map_update | runtime | 309 | 409 | 0.756 | 204.5 | 332 | 0.616 | 0.140 |
| helper_call_1 | runtime | 72 | 52 | 1.385 | 65 | 59 | 1.102 | 0.283 |
| helper_call_10 | runtime | 368 | 365 | 1.008 | 160 | 144 | 1.111 | -0.103 |
| helper_call_100 | runtime | 3,482 | 3,193 | 1.091 | 1,142 | 1,467.5 | 0.778 | 0.312 |
| probe_read_heavy | runtime | 293 | 544 | 0.539 | 200.5 | 441 | 0.455 | 0.084 |
| get_time_heavy | runtime | 4,248 | 3,853 | 1.103 | 1,774 | 1,690.5 | 1.049 | 0.053 |
| atomic_counter_xadd | runtime | 268 | 260 | 1.031 | 185 | 295.5 | 0.626 | 0.405 |
