# Pure JIT Rigorous Statistical Analysis

- Input JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/runtime_full_9.json`
- Suite manifest: `/home/yunwei37/workspace/bpf-benchmark/config/micro_runtime.yaml`
- Generated at: `2026-03-07T03:28:24.903308+00:00`
- Bootstrap iterations: `10000`
- Bootstrap seed: `0`
- Selected execution metric: `exec_ns`.
- Metric timing source: `exec_ns` from each sample's `exec_ns` field; `timing_source` by runtime: kernel=ktime, llvmbpf=rdtsc.
- Exec ratio is defined as `mean(exec_ns_llvmbpf) / mean(exec_ns_kernel)`.
- Ratio interpretation: values below `1.0` favor `llvmbpf`; values above `1.0` favor `kernel`.
- Primary significance test: paired Wilcoxon signed-rank on matched `iteration_index` values with Benjamini-Hochberg correction.
- Secondary significance test: raw Mann-Whitney U p-values are reported as supplementary context.

## Benchmark x Runtime Statistics

| Benchmark | Runtime | N | Mean exec_ns | 95% CI (mean) | Median exec_ns | Stdev exec_ns | CV | Min exec_ns | Max exec_ns |
| --- | --- | ---: | ---: | --- | ---: | ---: | ---: | ---: | ---: |
| map_lookup_churn | llvmbpf | 10 | 513.30 | [446.50, 583.70] | 476.50 | 119.28 | 0.232 | 405.00 | 705.00 |
| map_lookup_churn | kernel | 10 | 451.00 | [365.10, 539.70] | 406.50 | 148.81 | 0.330 | 289.00 | 677.00 |
| map_roundtrip | llvmbpf | 10 | 595.10 | [521.10, 665.90] | 621.00 | 124.86 | 0.210 | 458.00 | 735.00 |
| map_roundtrip | kernel | 10 | 929.60 | [802.50, 1,053.80] | 969.00 | 212.86 | 0.229 | 595.00 | 1,304.00 |
| hash_map_lookup | llvmbpf | 10 | 418.20 | [387.60, 457.00] | 390.00 | 59.56 | 0.142 | 379.00 | 549.00 |
| hash_map_lookup | kernel | 10 | 787.40 | [683.60, 881.20] | 851.50 | 167.35 | 0.213 | 540.00 | 951.00 |
| percpu_map_update | llvmbpf | 10 | 242.20 | [197.80, 293.00] | 194.50 | 81.93 | 0.338 | 179.00 | 401.00 |
| percpu_map_update | kernel | 10 | 546.20 | [439.90, 662.00] | 509.00 | 190.68 | 0.349 | 335.00 | 896.00 |
| helper_call_1 | llvmbpf | 10 | 70.40 | [47.60, 93.40] | 67.00 | 39.04 | 0.555 | 34.00 | 133.00 |
| helper_call_1 | kernel | 10 | 40.80 | [28.60, 52.90] | 41.50 | 21.11 | 0.517 | 20.00 | 62.00 |
| helper_call_10 | llvmbpf | 10 | 202.50 | [171.00, 246.00] | 166.50 | 65.10 | 0.322 | 162.00 | 367.00 |
| helper_call_10 | kernel | 10 | 183.70 | [139.80, 244.70] | 139.50 | 99.90 | 0.544 | 139.00 | 442.00 |
| helper_call_100 | llvmbpf | 10 | 2,455.60 | [1,253.30, 4,197.61] | 1,312.00 | 2,478.56 | 1.009 | 1,052.00 | 7,276.00 |
| helper_call_100 | kernel | 10 | 1,544.10 | [1,471.90, 1,618.90] | 1,545.00 | 124.65 | 0.081 | 1,418.00 | 1,750.00 |
| probe_read_heavy | llvmbpf | 10 | 264.70 | [188.80, 374.60] | 188.50 | 159.77 | 0.604 | 187.00 | 685.00 |
| probe_read_heavy | kernel | 10 | 584.00 | [472.30, 688.90] | 654.00 | 188.21 | 0.322 | 330.00 | 798.00 |
| get_time_heavy | llvmbpf | 10 | 1,887.90 | [1,805.79, 1,977.01] | 1,795.50 | 144.21 | 0.076 | 1,771.00 | 2,119.00 |
| get_time_heavy | kernel | 10 | 1,809.40 | [1,723.50, 1,898.00] | 1,783.50 | 150.04 | 0.083 | 1,667.00 | 2,016.00 |

## Cross-runtime Comparison

| Benchmark | exec_ns Ratio (L/K) | 95% CI | Cohen's d | Paired Wilcoxon p | MWU p | Significant | Code-size Ratio (L/K) | Notes |
| --- | ---: | --- | ---: | ---: | ---: | --- | ---: | --- |
| map_lookup_churn | 1.138 | [0.904, 1.449] | 0.462 | 0.4219 | 0.2725 | No | 0.579 (289/499) |  |
| map_roundtrip | 0.640 | [0.536, 0.771] | -1.917 | 0.0117 | 0.0028 | Yes | 0.609 (308/506) |  |
| hash_map_lookup | 0.531 | [0.464, 0.625] | -2.939 | 0.0088 | 0.0002 | Yes | 0.871 (472/542) |  |
| percpu_map_update | 0.443 | [0.336, 0.593] | -2.072 | 0.0088 | 0.0005 | Yes | 0.654 (274/419) |  |
| helper_call_1 | 1.725 | [1.079, 2.733] | 0.943 | 0.2285 | 0.0625 | No | 0.649 (237/365) |  |
| helper_call_10 | 1.102 | [0.768, 1.564] | 0.223 | 0.4131 | 0.0201 | No | 0.907 (790/871) |  |
| helper_call_100 | 1.590 | [0.806, 2.694] | 0.519 | 0.4316 | 0.0539 | No | 0.970 (5,666/5,839) |  |
| probe_read_heavy | 0.453 | [0.311, 0.673] | -1.829 | 0.0132 | 0.0028 | Yes | 0.654 (297/454) |  |
| get_time_heavy | 1.043 | [0.977, 1.115] | 0.533 | 0.4219 | 0.1850 | No | 0.804 (258/321) |  |

## Suite Summary

| Metric | Value |
| --- | --- |
| Benchmarks compared | 9 |
| Geometric mean exec_ns ratio (L/K) | 0.856 |
| Geometric mean exec_ns ratio 95% CI | [0.756, 0.951] |
| Benchmarks with valid paired Wilcoxon input | 9 / 9 |
| Statistically significant benchmarks (BH-adjusted paired Wilcoxon p < 0.05) | 4 / 9 |

## Compile Time Analysis

| Benchmark | llvmbpf compile_ns (mean) | llvmbpf 95% CI | kernel compile_ns (mean) | kernel 95% CI | Ratio (L/K) |
| --- | ---: | --- | ---: | --- | ---: |
| map_lookup_churn | 7,515,476.00 | [7,371,834.82, 7,648,151.69] | 1,021,194.80 | [1,000,864.06, 1,041,418.51] | 7.359 |
| map_roundtrip | 7,412,845.60 | [7,196,229.58, 7,592,854.80] | 703,230.80 | [576,434.31, 932,202.14] | 10.541 |
| hash_map_lookup | 7,825,847.30 | [7,765,064.55, 7,869,326.28] | 1,403,960.70 | [1,385,824.00, 1,420,955.43] | 5.574 |
| percpu_map_update | 7,191,992.50 | [6,899,863.33, 7,441,021.89] | 729,525.20 | [612,484.97, 934,762.43] | 9.858 |
| helper_call_1 | 5,775,250.50 | [5,531,652.49, 6,005,641.29] | 348,204.50 | [328,266.67, 373,486.79] | 16.586 |
| helper_call_10 | 8,907,598.20 | [8,644,487.82, 9,128,916.53] | 350,099.80 | [334,116.80, 365,371.34] | 25.443 |
| helper_call_100 | 32,105,594.80 | [31,760,416.39, 32,464,383.88] | 613,730.80 | [598,054.12, 628,910.85] | 52.312 |
| probe_read_heavy | 8,067,595.10 | [7,821,015.38, 8,323,761.86] | 994,288.00 | [976,474.88, 1,012,194.68] | 8.114 |
| get_time_heavy | 6,409,365.90 | [6,201,340.28, 6,598,776.50] | 644,699.70 | [632,378.83, 655,607.01] | 9.942 |

**Suite geometric mean compile-time ratio (L/K):** 12.526
  (over 9 benchmarks)
