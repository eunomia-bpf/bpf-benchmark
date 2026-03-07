# Pure JIT Rigorous Statistical Analysis

- Input JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/runtime_authoritative.json`
- Suite manifest: `/home/yunwei37/workspace/bpf-benchmark/config/micro_runtime.yaml`
- Generated at: `2026-03-07T03:38:27.489003+00:00`
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
| map_lookup_churn | llvmbpf | 30 | 420.43 | [410.63, 431.47] | 401.50 | 30.30 | 0.072 | 398.00 | 504.00 |
| map_lookup_churn | kernel | 30 | 321.60 | [309.60, 333.67] | 315.00 | 33.92 | 0.105 | 285.00 | 387.00 |
| map_roundtrip | llvmbpf | 30 | 469.37 | [461.63, 478.10] | 455.00 | 23.31 | 0.050 | 451.00 | 530.00 |
| map_roundtrip | kernel | 30 | 646.47 | [626.80, 672.50] | 648.00 | 67.01 | 0.104 | 592.00 | 953.00 |
| hash_map_lookup | llvmbpf | 30 | 377.97 | [369.57, 387.37] | 365.00 | 25.02 | 0.066 | 358.00 | 441.00 |
| hash_map_lookup | kernel | 30 | 554.87 | [532.30, 581.40] | 542.50 | 69.54 | 0.125 | 463.00 | 808.00 |
| percpu_map_update | llvmbpf | 30 | 193.23 | [185.83, 201.07] | 179.50 | 21.83 | 0.113 | 175.00 | 242.00 |
| percpu_map_update | kernel | 30 | 394.43 | [381.73, 407.47] | 381.00 | 36.15 | 0.092 | 326.00 | 471.00 |
| helper_call_1 | llvmbpf | 30 | 33.73 | [31.53, 36.53] | 31.00 | 7.19 | 0.213 | 31.00 | 58.00 |
| helper_call_1 | kernel | 30 | 32.23 | [26.07, 38.77] | 19.00 | 18.17 | 0.564 | 18.00 | 60.00 |
| helper_call_10 | llvmbpf | 30 | 174.13 | [167.57, 181.57] | 161.50 | 19.82 | 0.114 | 159.00 | 229.00 |
| helper_call_10 | kernel | 30 | 175.97 | [162.77, 189.53] | 192.50 | 38.10 | 0.216 | 137.00 | 250.00 |
| helper_call_100 | llvmbpf | 30 | 1,403.50 | [1,197.47, 1,665.40] | 1,149.00 | 664.64 | 0.474 | 1,106.00 | 3,627.00 |
| helper_call_100 | kernel | 30 | 1,459.37 | [1,430.60, 1,506.64] | 1,418.50 | 115.98 | 0.079 | 1,401.00 | 2,050.00 |
| probe_read_heavy | llvmbpf | 30 | 198.37 | [185.50, 219.37] | 182.00 | 50.98 | 0.257 | 181.00 | 454.00 |
| probe_read_heavy | kernel | 30 | 350.57 | [339.33, 362.70] | 328.50 | 33.07 | 0.094 | 326.00 | 418.00 |
| get_time_heavy | llvmbpf | 30 | 1,782.57 | [1,775.87, 1,790.10] | 1,770.00 | 20.24 | 0.011 | 1,768.00 | 1,837.00 |
| get_time_heavy | kernel | 30 | 1,717.43 | [1,703.77, 1,732.13] | 1,720.50 | 40.34 | 0.023 | 1,666.00 | 1,815.00 |

## Cross-runtime Comparison

| Benchmark | exec_ns Ratio (L/K) | 95% CI | Cohen's d | Paired Wilcoxon p | MWU p | Significant | Code-size Ratio (L/K) | Notes |
| --- | ---: | --- | ---: | ---: | ---: | --- | ---: | --- |
| map_lookup_churn | 1.307 | [1.251, 1.368] | 3.073 | 3.42e-06 | 2.82e-11 | Yes | 0.579 (289/499) |  |
| map_roundtrip | 0.726 | [0.695, 0.753] | -3.530 | 3.42e-06 | 2.89e-11 | Yes | 0.609 (308/506) |  |
| hash_map_lookup | 0.681 | [0.647, 0.715] | -3.385 | 3.42e-06 | 2.94e-11 | Yes | 0.871 (472/542) |  |
| percpu_map_update | 0.490 | [0.466, 0.516] | -6.738 | 3.42e-06 | 2.77e-11 | Yes | 0.654 (274/419) |  |
| helper_call_1 | 1.047 | [0.857, 1.312] | 0.109 | 0.8367 | 0.0429 | No | 0.649 (237/365) | kernel exec < 100ns: below ktime resolution |
| helper_call_10 | 0.990 | [0.909, 1.080] | -0.060 | 0.8367 | 0.8816 | No | 0.907 (790/871) |  |
| helper_call_100 | 0.962 | [0.818, 1.144] | -0.117 | 0.0201 | 7.92e-06 | Yes | 0.970 (5,666/5,839) |  |
| probe_read_heavy | 0.566 | [0.523, 0.629] | -3.542 | 3.42e-06 | 4.15e-10 | Yes | 0.654 (297/454) |  |
| get_time_heavy | 1.038 | [1.029, 1.048] | 2.041 | 3.69e-06 | 3.94e-10 | Yes | 0.804 (258/321) |  |

## Metric Scope Note

`wall_exec_ns` is not suitable for cross-runtime comparison because kernel `wall_exec_ns` includes `BPF_PROG_TEST_RUN` syscall dispatch overhead (~200us), while llvmbpf `wall_exec_ns` is pure function-call latency. `exec_ns` remains the primary comparison metric because both runtimes measure pure BPF execution time, despite using different clocks (kernel=`ktime`, llvmbpf=`rdtsc`).

Note: significance labels use BH-adjusted paired Wilcoxon p-values, while ratio CIs use unadjusted bootstrap intervals; a benchmark can be significant with a CI crossing 1.0 (or vice versa), which is expected rather than contradictory.

## Suite Summary

| Metric | Value |
| --- | --- |
| Benchmarks compared | 9 |
| Geometric mean exec_ns ratio (L/K) | 0.829 |
| Geometric mean exec_ns ratio 95% CI | [0.801, 0.859] |
| Benchmarks with valid paired Wilcoxon input | 9 / 9 |
| Statistically significant benchmarks (BH-adjusted paired Wilcoxon p < 0.05) | 7 / 9 |
| Benchmarks with kernel exec < 100ns (below ktime resolution) | 1 / 9 |
| Statistically significant benchmarks excluding sub-resolution kernels (BH-adjusted paired Wilcoxon p < 0.05) | 7 / 8 |

## Compile Time Analysis

| Benchmark | llvmbpf compile_ns (mean) | llvmbpf 95% CI | kernel compile_ns (mean) | kernel 95% CI | Ratio (L/K) |
| --- | ---: | --- | ---: | --- | ---: |
| map_lookup_churn | 7,575,119.53 | [7,478,185.86, 7,656,998.44] | 1,028,043.80 | [1,021,609.23, 1,034,124.11] | 7.368 |
| map_roundtrip | 7,551,562.17 | [7,470,253.97, 7,623,134.55] | 637,780.37 | [630,760.55, 644,726.09] | 11.840 |
| hash_map_lookup | 7,756,610.17 | [7,654,675.46, 7,850,017.30] | 1,478,852.13 | [1,423,828.00, 1,581,750.07] | 5.245 |
| percpu_map_update | 7,489,679.37 | [7,420,650.06, 7,555,564.94] | 617,439.30 | [611,603.25, 622,659.36] | 12.130 |
| helper_call_1 | 6,100,470.50 | [6,047,698.24, 6,149,672.45] | 339,938.23 | [335,352.11, 344,563.50] | 17.946 |
| helper_call_10 | 9,200,391.53 | [9,152,051.76, 9,244,742.90] | 375,957.60 | [371,143.01, 380,956.47] | 24.472 |
| helper_call_100 | 33,196,583.50 | [32,826,730.62, 33,623,976.61] | 662,870.30 | [658,175.86, 667,448.20] | 50.080 |
| probe_read_heavy | 8,616,143.80 | [8,557,313.20, 8,668,561.03] | 1,022,809.33 | [1,019,073.83, 1,026,558.69] | 8.424 |
| get_time_heavy | 6,653,369.97 | [6,589,276.96, 6,725,860.98] | 666,936.37 | [662,340.15, 671,416.61] | 9.976 |

**Suite geometric mean compile-time ratio (L/K):** 12.952
  (over 9 benchmarks)
