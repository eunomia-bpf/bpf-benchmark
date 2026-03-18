# Deep Performance Analysis

- Input JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative.json`
- Program objects: `/home/yunwei37/workspace/bpf-benchmark/micro/programs`
- Generated at: `2026-03-07T22:57:35.863904+00:00`
- Benchmarks analyzed: `31`
- Branch-count source: static bytecode analysis of `micro/programs/*.bpf.o` (`31/31` coverage) because the manifest does not expose numeric branch counts.

## Key Findings

- llvmbpf wins `21/31` benchmarks overall with a suite exec geomean of `0.849x` and a code-size geomean of `0.496x`.
- The biggest LLVM-friendly categories are `control-flow` (0.627x), `memory-local` (0.665x), `program-scale` (0.717x), while `call-size` and `baseline` regress.
- Code-size reduction is a weak predictor of steady-state speed: Pearson `r=0.131` (p=`0.4819`) and Spearman `rho=0.261` (p=`0.1566`).
- The largest code-size/performance paradox outliers are `code_clone_8`, `bitcount`, `nested_loop_3`, `branch_layout`, `simple`; positive residuals mean llvmbpf is slower than its code shrink alone would suggest.
- Kernel execution timing is noisier on `23/31` benchmarks versus `8/31` for llvmbpf. Most differences are practically meaningful: `22` large, `5` medium, `4` small.
- Compile-time penalty falls only weakly with size (Pearson `r=-0.343`, p=`0.0591`); the fitted crossover is `756` BPF insns, but the data do not show a clean monotonic threshold. The static-feature runtime model is also weak (`R²=0.070`).

## 1. Per-Category Performance Breakdown

| Category | Benchmarks | Exec geomean (L/K) | Code-size geomean (L/K) | llvmbpf wins | kernel wins |
| --- | ---: | ---: | ---: | ---: | ---: |
| baseline | 3 | 1.361x | 0.417x | 0 | 3 |
| alu-mix | 3 | 1.049x | 0.622x | 1 | 2 |
| control-flow | 4 | 0.627x | 0.552x | 3 | 1 |
| dependency-ilp | 5 | 0.919x | 0.576x | 5 | 0 |
| loop-shape | 6 | 0.764x | 0.457x | 5 | 1 |
| memory-local | 6 | 0.665x | 0.440x | 5 | 1 |
| program-scale | 2 | 0.717x | 0.441x | 2 | 0 |
| call-size | 2 | 1.539x | 0.517x | 0 | 2 |

| Rank | Category | Exec geomean (L/K) | Interpretation |
| --- | --- | ---: | --- |
| 1 | control-flow | 0.627x | llvmbpf benefit |
| 2 | memory-local | 0.665x | llvmbpf benefit |
| 3 | program-scale | 0.717x | llvmbpf benefit |
| 4 | loop-shape | 0.764x | llvmbpf benefit |
| 5 | dependency-ilp | 0.919x | llvmbpf benefit |
| 6 | alu-mix | 1.049x | kernel benefit |
| 7 | baseline | 1.361x | kernel benefit |
| 8 | call-size | 1.539x | kernel benefit |

## 2. Performance-vs-Code-Size Correlation

| Metric | Value |
| --- | ---: |
| Pearson r | 0.131 |
| Pearson p-value | 0.4819 |
| Spearman rho | 0.261 |
| Spearman p-value | 0.1566 |
| Linear fit slope | 0.279 |
| Linear fit intercept | 0.779 |
| Linear-fit R² | 0.017 |

Outliers below use standardized residuals from the linear fit `exec_ratio = 0.779 + 0.279 * code_ratio`; threshold is `|z| >= 1.5`.

| Benchmark | Code ratio (L/K) | Exec ratio (L/K) | Predicted exec ratio | Residual | Residual z-score | Reading |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| code_clone_8 | 0.542x | 1.878x | 0.930x | 0.948 | 2.57 | slower than code size suggests |
| bitcount | 0.446x | 1.556x | 0.903x | 0.653 | 1.77 | slower than code size suggests |
| nested_loop_3 | 0.884x | 0.405x | 1.026x | -0.620 | -1.68 | faster than code size suggests |
| branch_layout | 0.354x | 0.289x | 0.878x | -0.589 | -1.59 | faster than code size suggests |
| simple | 0.622x | 1.526x | 0.952x | 0.573 | 1.55 | slower than code size suggests |

## 3. Execution Time Distribution Analysis

High-variance benchmarks are flagged when either runtime has `CV > 10.0%`. Kernel-noisier means the kernel CV exceeds llvmbpf's CV for the same benchmark.

| Benchmark | llvmbpf CV | kernel CV | High variance? | Noisier runtime |
| --- | ---: | ---: | --- | --- |
| bounds_check_heavy | 73.3% | 22.7% | Yes | llvmbpf |
| memory_pair_sum | 24.8% | 58.9% | Yes | kernel |
| simple | 30.6% | 49.9% | Yes | kernel |
| simple_packet | 42.1% | 49.8% | Yes | kernel |
| packet_parse | 13.9% | 35.2% | Yes | kernel |
| nested_loop_3 | 30.1% | 5.6% | Yes | llvmbpf |
| fixed_loop_small | 14.1% | 28.4% | Yes | kernel |
| dep_chain_short | 14.6% | 25.4% | Yes | kernel |
| bounds_ladder | 20.2% | 22.6% | Yes | kernel |
| switch_dispatch | 20.5% | 11.6% | Yes | llvmbpf |
| spill_pressure | 6.1% | 18.1% | Yes | kernel |
| stride_load_16 | 13.3% | 16.3% | Yes | kernel |
| branch_layout | 8.5% | 15.8% | Yes | kernel |
| stride_load_4 | 12.6% | 15.5% | Yes | kernel |
| mixed_alu_mem | 15.2% | 6.2% | Yes | llvmbpf |
| code_clone_8 | 2.6% | 13.5% | Yes | kernel |
| multi_acc_4 | 7.8% | 13.4% | Yes | kernel |
| nested_loop_2 | 11.5% | 6.3% | Yes | llvmbpf |
| code_clone_2 | 9.9% | 11.4% | Yes | kernel |
| log2_fold | 5.6% | 11.2% | Yes | kernel |
| bitcount | 1.8% | 9.6% | No | kernel |
| multi_acc_8 | 4.4% | 8.9% | No | kernel |
| branch_dense | 3.0% | 7.9% | No | kernel |
| binary_search | 7.5% | 7.7% | No | kernel |
| dep_chain_long | 4.0% | 7.7% | No | kernel |
| large_mixed_500 | 7.2% | 5.7% | No | llvmbpf |
| large_mixed_1000 | 5.6% | 2.8% | No | llvmbpf |
| fibonacci_iter_packet | 3.2% | 5.5% | No | kernel |
| fixed_loop_large | 5.4% | 3.9% | No | llvmbpf |
| fibonacci_iter | 2.4% | 4.6% | No | kernel |
| checksum | 0.2% | 0.9% | No | kernel |

| Summary metric | Value |
| --- | ---: |
| Benchmarks with CV > 10% in either runtime | 20 / 31 |
| llvmbpf-only high variance | 3 |
| kernel-only high variance | 6 |
| high variance in both runtimes | 11 |
| Kernel noisier benchmarks | 23 / 31 |
| llvmbpf noisier benchmarks | 8 / 31 |
| Median llvmbpf CV | 8.5% |
| Median kernel CV | 11.4% |

## 4. Effect Size Spectrum

| Class | Count | Favoring llvmbpf | Favoring kernel |
| --- | ---: | ---: | ---: |
| small | 4 | 2 | 2 |
| medium | 5 | 3 | 2 |
| large | 22 | 16 | 6 |

| Benchmark | Cohen's d | Magnitude | Direction | Exec ratio (L/K) |
| --- | ---: | --- | --- | ---: |
| checksum | -14.959 | large | llvmbpf | 0.900x |
| code_clone_8 | 8.692 | large | kernel | 1.878x |
| binary_search | -8.580 | large | llvmbpf | 0.481x |
| bitcount | 7.863 | large | kernel | 1.556x |
| large_mixed_1000 | -7.237 | large | llvmbpf | 0.742x |
| branch_dense | 6.474 | large | kernel | 1.409x |
| branch_layout | -6.303 | large | llvmbpf | 0.289x |
| nested_loop_3 | -6.282 | large | llvmbpf | 0.405x |
| large_mixed_500 | -5.735 | large | llvmbpf | 0.693x |
| fibonacci_iter | -5.624 | large | llvmbpf | 0.803x |
| stride_load_4 | -4.794 | large | llvmbpf | 0.442x |
| stride_load_16 | -4.725 | large | llvmbpf | 0.423x |
| fibonacci_iter_packet | -4.212 | large | llvmbpf | 0.818x |
| fixed_loop_large | 3.634 | large | kernel | 1.193x |
| bounds_ladder | -2.991 | large | llvmbpf | 0.479x |
| mixed_alu_mem | -2.901 | large | llvmbpf | 0.737x |
| nested_loop_2 | -2.200 | large | llvmbpf | 0.823x |
| code_clone_2 | 2.180 | large | kernel | 1.260x |
| switch_dispatch | -1.502 | large | llvmbpf | 0.789x |
| fixed_loop_small | -1.125 | large | llvmbpf | 0.759x |
| simple | 1.087 | large | kernel | 1.526x |
| spill_pressure | -0.970 | large | llvmbpf | 0.871x |
| multi_acc_8 | -0.709 | medium | llvmbpf | 0.951x |
| dep_chain_short | -0.691 | medium | llvmbpf | 0.861x |
| simple_packet | 0.608 | medium | kernel | 1.321x |
| dep_chain_long | -0.583 | medium | llvmbpf | 0.964x |
| memory_pair_sum | 0.533 | medium | kernel | 1.251x |
| multi_acc_4 | -0.449 | small | llvmbpf | 0.951x |
| bounds_check_heavy | 0.197 | small | kernel | 1.119x |
| packet_parse | -0.135 | small | llvmbpf | 0.964x |
| log2_fold | 0.065 | small | kernel | 1.006x |

## 5. Compile Time vs Program Complexity

| Metric | Value |
| --- | ---: |
| Pearson r (insns vs compile ratio) | -0.343 |
| Pearson p-value | 0.0591 |
| Spearman rho | -0.349 |
| Spearman p-value | 0.0546 |
| Linear fit slope | -0.008 |
| Linear fit intercept | 7.293 |
| Linear-fit R² | 0.117 |
| Estimated ratio=1 crossover | 756 BPF insns |

Empirically, llvmbpf already beats kernel compile time for a handful of mid-sized programs, so program size alone is not a reliable crossover predictor.

| Benchmark | BPF insns | Compile ratio (L/K) | Winner |
| --- | ---: | ---: | --- |
| simple_packet | 21 | 13.080x | kernel |
| simple | 29 | 12.368x | kernel |
| memory_pair_sum | 83 | 15.113x | kernel |
| fibonacci_iter_packet | 97 | 3.906x | kernel |
| packet_parse | 99 | 5.667x | kernel |
| branch_layout | 100 | 0.760x | llvmbpf |
| fibonacci_iter | 102 | 3.872x | kernel |
| checksum | 103 | 0.189x | llvmbpf |
| dep_chain_long | 108 | 5.897x | kernel |
| dep_chain_short | 108 | 12.398x | kernel |
| stride_load_4 | 109 | 6.891x | kernel |
| stride_load_16 | 109 | 7.702x | kernel |
| fixed_loop_small | 113 | 14.961x | kernel |
| fixed_loop_large | 115 | 3.278x | kernel |
| code_clone_2 | 118 | 8.625x | kernel |
| multi_acc_4 | 132 | 9.652x | kernel |
| log2_fold | 133 | 1.315x | kernel |
| bitcount | 134 | 0.122x | llvmbpf |
| nested_loop_2 | 158 | 5.751x | kernel |
| branch_dense | 181 | 1.004x | kernel |
| binary_search | 184 | 0.382x | llvmbpf |
| code_clone_8 | 189 | 6.165x | kernel |
| bounds_ladder | 190 | 6.624x | kernel |
| multi_acc_8 | 201 | 5.904x | kernel |
| spill_pressure | 210 | 9.696x | kernel |
| nested_loop_3 | 229 | 4.845x | kernel |
| mixed_alu_mem | 275 | 1.396x | kernel |
| switch_dispatch | 326 | 0.424x | llvmbpf |
| bounds_check_heavy | 333 | 4.682x | kernel |
| large_mixed_500 | 553 | 2.486x | kernel |
| large_mixed_1000 | 1016 | 2.145x | kernel |

| Empirical compile-time win set | BPF insn count | Compile ratio (L/K) |
| --- | ---: | ---: |
| bitcount | 134 | 0.122x |
| checksum | 103 | 0.189x |
| binary_search | 184 | 0.382x |
| switch_dispatch | 326 | 0.424x |
| branch_layout | 100 | 0.760x |

## 6. Performance Prediction from Static Features

This model uses benchmark-level `exec_ratio` as the target and `bpf_insn_count`, `branch_count`, and `code_ratio` as features. Branch counts come from static bytecode analysis of the compiled benchmark objects.

| Metric | Value |
| --- | ---: |
| Benchmarks with full feature coverage | 31 / 31 |
| Model R² | 0.070 |
| Intercept | 0.795 |

| Feature | Raw coefficient | Standardized beta | Drop in R² when removed | Univariate R² |
| --- | ---: | ---: | ---: | ---: |
| code_ratio | 0.417 | 0.196 | 0.034 | 0.017 |
| bpf_insn_count | -0.000 | -0.182 | 0.030 | 0.033 |
| branch_count | -0.001 | -0.112 | 0.011 | 0.010 |

Interpretation: positive coefficients increase `llvmbpf/kernel` exec ratio and therefore predict worse llvmbpf runtime. Negative coefficients predict relative llvmbpf speedups. The low `R²` means these static features explain only a small fraction of the runtime spread.

