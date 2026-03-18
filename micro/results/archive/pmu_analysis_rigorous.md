# PMU Analysis

L = llvmbpf, K = kernel.

| Benchmark | IPC (L) | IPC (K) | Branch Miss% (L) | Branch Miss% (K) | Cache Miss% (L) | Cache Miss% (K) |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| simple | n/a | 0.121 | n/a | 0.45 | n/a | 15.10 |
| memory_pair_sum | n/a | 0.125 | n/a | 0.45 | n/a | 14.28 |
| bitcount | n/a | 4.866 | n/a | 0.13 | n/a | 18.12 |
| dep_chain_short | n/a | 0.622 | n/a | 0.62 | n/a | 21.85 |
| binary_search | n/a | 2.348 | n/a | 0.07 | n/a | 18.68 |
| switch_dispatch | 2.667 | 0.831 | 0.11 | 0.23 | 60.73 | 19.72 |
| checksum | n/a | 3.922 | n/a | 0.10 | n/a | 21.70 |
| packet_parse | n/a | 0.483 | n/a | 0.35 | n/a | 16.06 |
| bounds_ladder | n/a | 1.681 | n/a | 0.25 | n/a | 22.66 |
| stride_load_4 | n/a | 1.923 | n/a | 0.44 | n/a | 14.29 |
| stride_load_16 | n/a | 1.111 | n/a | 0.41 | n/a | 23.34 |
| spill_pressure | n/a | 1.880 | n/a | 1.02 | n/a | 18.35 |
| multi_acc_4 | 4.926 | 0.987 | 0.68 | 0.58 | 67.03 | 21.78 |
| multi_acc_8 | 6.277 | 2.632 | 0.68 | 0.70 | 55.77 | 14.60 |
| fibonacci_iter | n/a | 4.008 | n/a | 0.14 | n/a | 14.59 |
| fixed_loop_small | n/a | 0.367 | n/a | 1.08 | n/a | 41.57 |
| fixed_loop_large | n/a | 2.022 | n/a | 0.15 | n/a | 10.96 |
| code_clone_8 | n/a | 1.524 | n/a | 0.41 | n/a | 15.33 |

## Correlation

Benchmarks used: 3

- Pearson r (IPC diff vs exec ratio): 0.8346
- Spearman rho (IPC diff vs exec ratio): 0.5000
