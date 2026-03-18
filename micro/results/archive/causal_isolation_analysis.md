# Pure JIT Rigorous Statistical Analysis

- Input JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/causal_isolation_authoritative.json`
- Suite manifest: `/home/yunwei37/workspace/bpf-benchmark/config/micro_pure_jit.yaml`
- Generated at: `2026-03-07T22:59:06.245946+00:00`
- Bootstrap iterations: `10000`
- Bootstrap seed: `0`
- Selected execution metric: `exec_ns`.
- Metric timing source: `exec_ns` from each sample's `exec_ns` field; `timing_source` by runtime: kernel=ktime, llvmbpf=rdtsc.
- Primary ratio is defined as `mean(exec_ns_llvmbpf) / mean(exec_ns_kernel)`.
- Ratio interpretation: values below `1.0` favor `llvmbpf`; values above `1.0` favor `kernel`.
- Primary significance test: paired Wilcoxon signed-rank on matched `iteration_index` values with Benjamini-Hochberg correction.
- Secondary significance test: raw Mann-Whitney U p-values are reported as supplementary context.

## Benchmark x Runtime Statistics

| Benchmark | Runtime | N | Mean exec_ns | 95% CI (mean) | Median exec_ns | Stdev exec_ns | CV | Min exec_ns | Max exec_ns |
| --- | --- | ---: | ---: | --- | ---: | ---: | ---: | ---: | ---: |
| load_word32 | llvmbpf | 30 | 86.83 | [83.63, 90.60] | 81.00 | 9.83 | 0.113 | 81.00 | 111.00 |
| load_word32 | kernel | 30 | 111.40 | [100.30, 122.93] | 117.00 | 32.23 | 0.289 | 73.00 | 208.00 |
| load_byte | llvmbpf | 30 | 187.03 | [185.13, 189.73] | 185.00 | 6.65 | 0.036 | 184.00 | 217.00 |
| load_byte | kernel | 30 | 267.57 | [241.63, 307.13] | 228.00 | 99.14 | 0.371 | 227.00 | 763.00 |
| load_byte_recompose | llvmbpf | 30 | 78.70 | [76.33, 81.60] | 76.00 | 7.61 | 0.097 | 75.00 | 105.00 |
| load_byte_recompose | kernel | 30 | 175.93 | [165.37, 187.30] | 151.50 | 31.42 | 0.179 | 150.00 | 237.00 |
| load_native_u64 | llvmbpf | 30 | 83.60 | [81.23, 86.17] | 79.00 | 7.06 | 0.084 | 79.00 | 101.00 |
| load_native_u64 | kernel | 30 | 107.67 | [96.60, 118.03] | 113.50 | 30.69 | 0.285 | 66.00 | 160.00 |

## Cross-runtime Comparison

| Benchmark | exec_ns Ratio (L/K) | 95% CI | Cohen's d | Paired Wilcoxon p | MWU p | Significant | Code-size Ratio (L/K) | Notes |
| --- | ---: | --- | ---: | ---: | ---: | --- | ---: | --- |
| load_word32 | 0.779 | [0.699, 0.869] | -1.031 | 0.0011 | 0.0160 | Yes | 0.381 (137/360) |  |
| load_byte | 0.699 | [0.607, 0.774] | -1.146 | 3.34e-06 | 1.64e-11 | Yes | 0.420 (162/386) |  |
| load_byte_recompose | 0.447 | [0.417, 0.481] | -4.253 | 3.34e-06 | 1.91e-11 | Yes | 0.343 (141/411) |  |
| load_native_u64 | 0.776 | [0.703, 0.868] | -1.081 | 0.0003 | 0.0079 | Yes | 0.505 (140/277) |  |

## Metric Scope Note

`wall_exec_ns` is not suitable for cross-runtime comparison because kernel `wall_exec_ns` includes `BPF_PROG_TEST_RUN` syscall dispatch overhead (~200us), while llvmbpf `wall_exec_ns` is pure function-call latency. `exec_ns` remains the primary comparison metric because both runtimes measure pure BPF execution time, despite using different clocks (kernel=`ktime`, llvmbpf=`rdtsc`).


## Suite Summary

| Metric | Value |
| --- | --- |
| Benchmarks compared | 4 |
| Geometric mean exec_ns ratio (L/K) | 0.660 |
| Geometric mean exec_ns ratio 95% CI | [0.625, 0.696] |
| Benchmarks with valid paired Wilcoxon input | 4 / 4 |
| Statistically significant benchmarks (BH-adjusted paired Wilcoxon p < 0.05) | 4 / 4 |
| Benchmarks with kernel exec < 100ns (below ktime resolution) | 0 / 4 |
| Statistically significant benchmarks excluding sub-resolution kernels (BH-adjusted paired Wilcoxon p < 0.05) | 4 / 4 |

## Compile Time Analysis

| Benchmark | llvmbpf compile_ns (mean) | llvmbpf 95% CI | kernel compile_ns (mean) | kernel 95% CI | Ratio (L/K) |
| --- | ---: | --- | ---: | --- | ---: |
| load_word32 | 6,820,380.47 | [6,702,161.90, 6,928,825.82] | 661,018.37 | [656,246.08, 666,090.69] | 10.318 |
| load_byte | 7,249,357.63 | [7,142,127.81, 7,346,838.34] | 833,511.40 | [828,321.78, 839,502.47] | 8.697 |
| load_byte_recompose | 7,440,922.07 | [7,342,594.59, 7,538,507.99] | 775,589.83 | [766,626.54, 786,331.85] | 9.594 |
| load_native_u64 | 6,563,827.43 | [6,434,243.72, 6,696,138.44] | 519,561.80 | [514,964.56, 524,456.65] | 12.633 |

**Suite geometric mean compile-time ratio (L/K):** 10.212
  (over 4 benchmarks)
