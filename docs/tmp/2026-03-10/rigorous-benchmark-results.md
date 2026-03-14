# Rigorous Framework-VM Benchmark Results

- Generated at: `2026-03-10T22:36:36.254401+00:00`
- Kernel target: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework`
- Git SHA: `0222397044425b170887247d16d93929bfeb1aa8`
- Methodology: `10` measured iterations, `5` warmups, `1000` repeats per `micro_exec` invocation
- Pinning: single guest vCPU pinned to host CPU `23` via `vng --cpus 1 --pin`

## System Configuration

- Host CPU: `Intel(R) Core(TM) Ultra 9 285K`
- Host kernel: `6.15.11-061511-generic`
- Host governor: `performance`
- Host turbo disabled: `True` via `/sys/devices/system/cpu/intel_pstate/no_turbo`
- Guest kernel: `7.0.0-rc2-g8e9cfbc1e1a2-dirty`
- Guest CPU: `Intel(R) Core(TM) Ultra 9 285K`
- Guest governor cpu0: `None`
- Guest turbo interface raw value: `None`
- Publication-ready host environment: `False` (false here means the host lacks isolated CPUs even though governor/turbo/pinning were controlled)

## Preflight

- `cpu_governor`: `pass`
- `turbo_boost`: `pass`
- `cpu_pinning`: `pass`
- `heavy_processes`: `pass`

## log2_fold

- Comparison: `stock` vs `recompile-v5-cmov`
- Case: policy-sensitivity case

| Mode | N | Median exec_ns | Mean exec_ns | Stdev | 95% CI (mean) | Median code bytes | Mean code bytes |
| --- | ---: | ---: | ---: | ---: | --- | ---: | ---: |
| stock | 10 | 383.50 | 385.70 | 3.92 | [383.70, 388.20] | 648.00 | 648.00 |
| recompile-v5-cmov | 10 | 590.00 | 590.70 | 7.59 | [586.30, 595.20] | 682.00 | 682.00 |

- Wilcoxon signed-rank: `p=0.0020` (BH-adjusted `q=0.0033`)
- Median speedup (`stock / recompile-v5-cmov`): `0.655x`
- Mean delta (`stock - recompile-v5-cmov`): `-205.00` ns
- Code size delta (`recompile-v5-cmov - stock`): `34.00` bytes (`5.25%`)
- Iteration wins: `recompile-v5-cmov=0`, `stock=10`, `ties=0`

## rotate64_hash

- Comparison: `stock` vs `recompile-v5-all`
- Case: best perf improvement case

| Mode | N | Median exec_ns | Mean exec_ns | Stdev | 95% CI (mean) | Median code bytes | Mean code bytes |
| --- | ---: | ---: | ---: | ---: | --- | ---: | ---: |
| stock | 10 | 68.00 | 69.30 | 3.06 | [67.80, 71.30] | 3,559.00 | 3,559.00 |
| recompile-v5-all | 10 | 57.00 | 56.90 | 0.57 | [56.60, 57.20] | 2,313.00 | 2,313.00 |

- Wilcoxon signed-rank: `p=0.0020` (BH-adjusted `q=0.0033`)
- Median speedup (`stock / recompile-v5-all`): `1.193x`
- Mean delta (`stock - recompile-v5-all`): `12.40` ns
- Code size delta (`recompile-v5-all - stock`): `-1,246.00` bytes (`-35.01%`)
- Iteration wins: `recompile-v5-all=10`, `stock=0`, `ties=0`

## load_byte_recompose

- Comparison: `stock` vs `recompile-v5-wide`
- Case: byte-load recomposition case

| Mode | N | Median exec_ns | Mean exec_ns | Stdev | 95% CI (mean) | Median code bytes | Mean code bytes |
| --- | ---: | ---: | ---: | ---: | --- | ---: | ---: |
| stock | 10 | 223.00 | 222.20 | 5.55 | [219.20, 225.60] | 422.00 | 422.00 |
| recompile-v5-wide | 10 | 226.00 | 234.30 | 19.79 | [223.60, 246.50] | 410.00 | 410.00 |

- Wilcoxon signed-rank: `p=0.1641` (BH-adjusted `q=0.1641`)
- Median speedup (`stock / recompile-v5-wide`): `0.978x`
- Mean delta (`stock - recompile-v5-wide`): `-12.10` ns
- Code size delta (`recompile-v5-wide - stock`): `-12.00` bytes (`-2.84%`)
- Iteration wins: `recompile-v5-wide=2`, `stock=7`, `ties=1`

## stride_load_16

- Comparison: `stock` vs `recompile-v5-lea`
- Case: address-generation case

| Mode | N | Median exec_ns | Mean exec_ns | Stdev | 95% CI (mean) | Median code bytes | Mean code bytes |
| --- | ---: | ---: | ---: | ---: | --- | ---: | ---: |
| stock | 10 | 293.00 | 309.80 | 49.68 | [293.00, 341.50] | 517.00 | 517.00 |
| recompile-v5-lea | 10 | 281.00 | 283.80 | 8.95 | [279.10, 289.40] | 511.00 | 511.00 |

- Wilcoxon signed-rank: `p=0.0117` (BH-adjusted `q=0.0146`)
- Median speedup (`stock / recompile-v5-lea`): `1.052x`
- Mean delta (`stock - recompile-v5-lea`): `26.00` ns
- Code size delta (`recompile-v5-lea - stock`): `-6.00` bytes (`-1.16%`)
- Iteration wins: `recompile-v5-lea=9`, `stock=1`, `ties=0`

## packet_rss_hash

- Comparison: `stock` vs `recompile-v5-rotate`
- Case: rotate lowering case

| Mode | N | Median exec_ns | Mean exec_ns | Stdev | 95% CI (mean) | Median code bytes | Mean code bytes |
| --- | ---: | ---: | ---: | ---: | --- | ---: | ---: |
| stock | 10 | 21.00 | 21.60 | 1.58 | [21.00, 22.60] | 1,021.00 | 1,021.00 |
| recompile-v5-rotate | 10 | 17.00 | 17.70 | 0.95 | [17.20, 18.30] | 865.00 | 865.00 |

- Wilcoxon signed-rank: `p=0.0020` (BH-adjusted `q=0.0033`)
- Median speedup (`stock / recompile-v5-rotate`): `1.235x`
- Mean delta (`stock - recompile-v5-rotate`): `3.90` ns
- Code size delta (`recompile-v5-rotate - stock`): `-156.00` bytes (`-15.28%`)
- Iteration wins: `recompile-v5-rotate=10`, `stock=0`, `ties=0`

