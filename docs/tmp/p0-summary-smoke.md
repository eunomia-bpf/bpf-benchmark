# Characterization Summary

## Environment

- Suite: `micro_staged_codegen`
- Host: `lab` on `Linux-6.15.11-061511-generic-x86_64-with-glibc2.39`
- Requested defaults: iterations=1, warmups=1, repeat=5, perf_counters=False
- Shuffle seed: `None`
- Bootstrap summary statistics: iterations=5000, seed=20260306

## Suite-Level Comparison

| Metric | Value | 95% bootstrap CI |
| --- | ---: | ---: |
| Raw exec `llvmbpf/kernel` geometric mean | n/a | n/a |
| Baseline-adjusted exec `llvmbpf/kernel` geometric mean | n/a | n/a |
| Raw wins (`llvmbpf / kernel / tie`) | `0 / 0 / 0` | n/a |
| Adjusted wins (`llvmbpf / kernel / tie`) | `0 / 0 / 0` | n/a |

## Benchmark-Level Comparison

The adjusted ratio subtracts each runtime's own `simple` median from the benchmark median before forming the `llvmbpf/kernel` ratio. This is the primary pure-jit view.
Calibration-oriented baseline rows are kept in the table, but excluded from directional rankings.

| Benchmark | Category | Family | Level | llvmbpf exec | kernel exec | Raw ratio | Adjusted ratio | Adjusted ratio 95% CI |
| --- | --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| `simple` | `baseline` | `baseline` | `tiny` | 225 ns | n/a | n/a | n/a | n/a |

## Category-Level Adjusted Summary

| Group | Benchmarks | Adjusted gmean | 95% bootstrap CI | Wins (`llvmbpf/kernel/tie`) |
| --- | ---: | ---: | ---: | --- |

## Family-Level Adjusted Summary

| Group | Benchmarks | Adjusted gmean | 95% bootstrap CI | Wins (`llvmbpf/kernel/tie`) |
| --- | ---: | ---: | ---: | --- |

## Directional Findings

### Strongest llvmbpf advantages


### Kernel-leading or parity cases


## Perf-Counter Signal

| Runtime | Benchmarks | HW counters observed | Median IPC across suite | Median branch-miss rate | Median cache-miss rate |
| --- | ---: | --- | ---: | ---: | ---: |
| `llvmbpf` | 1 | 0/1 | n/a | n/a | n/a |

## Corpus Snapshot

| Repo | Program sources |
| --- | ---: |
| `xdp-examples` | 13 |
| `xdp-tools` | 14 |
| `xdp-tutorial` | 16 |
| `bcc` | 57 |
| `katran` | 2 |
| `tetragon` | 28 |
| `cilium` | 9 |
| `libbpf-bootstrap` | 15 |
| `linux-selftests` | 916 |
| **Total** | **1070** |
