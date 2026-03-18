# PMU Analysis

L = llvmbpf, K = kernel.

| Benchmark | IPC (L) | IPC (K) | Branch Miss% (L) | Branch Miss% (K) | Cache Miss% (L) | Cache Miss% (K) |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| bitcount | n/a | 4.786 | n/a | 0.13 | n/a | 19.14 |
| checksum | n/a | 3.865 | n/a | 0.10 | n/a | 16.16 |
| code_clone_8 | n/a | 0.153 | n/a | 9.11 | n/a | 39.87 |
| binary_search | n/a | 2.029 | n/a | 0.09 | n/a | 20.05 |
| nested_loop_3 | 4.225 | n/a | 0.04 | n/a | 55.01 | n/a |
| large_mixed_1000 | 2.492 | 0.156 | 0.10 | 9.22 | 52.93 | 16.27 |

## Correlation

Benchmarks used: 1

- Pearson r (IPC diff vs exec ratio): n/a
- Spearman rho (IPC diff vs exec ratio): n/a
