# Benchmark Stability Analysis

- Input: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_rigorous.json`
- Generated from suite: `micro_pure_jit`
- Rolling window: 5
- ACF(1) threshold: |ACF(1)| > 0.3
- Drift significance level: p < 0.05

## Time-Series Stability Table

| Benchmark | Runtime | N | ACF(1) | Drift p-value | 1st-half mean | 2nd-half mean | Drift% |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| simple | llvmbpf | 30 | -0.0500 | 0.3173 | 15.73 | 15.87 | 0.85 |
| simple | kernel | 30 | 0.0877 | 0.6648 | 16.27 | 17.67 | 8.61 |
| memory_pair_sum | llvmbpf | 30 | -0.2443 | 1.0000 | 16.33 | 16.40 | 0.41 |
| memory_pair_sum | kernel | 30 | 0.0840 | 0.8382 | 14.07 | 13.53 | -3.79 |
| bitcount | llvmbpf | 30 | 0.0687 | 0.3342 | 4755.93 | 4699.67 | -1.18 |
| bitcount | kernel | 30 | 0.3578 | 0.0637 | 3182.20 | 2972.87 | -6.58 |
| log2_fold | llvmbpf | 30 | -0.0433 | 0.1663 | 303.13 | 300.53 | -0.86 |
| log2_fold | kernel | 30 | 0.2769 | 0.7332 | 305.80 | 299.67 | -2.01 |
| dep_chain_short | llvmbpf | 30 | -0.0444 | 0.1236 | 114.87 | 114.87 | 0.00 |
| dep_chain_short | kernel | 30 | -0.0245 | 0.6002 | 129.60 | 137.60 | 6.17 |
| dep_chain_long | llvmbpf | 30 | 0.0112 | 0.0353 | 407.67 | 409.13 | 0.36 |
| dep_chain_long | kernel | 30 | 0.0611 | 0.3303 | 554.13 | 464.53 | -16.17 |
| binary_search | llvmbpf | 30 | -0.0620 | 0.8378 | 204.00 | 229.80 | 12.65 |
| binary_search | kernel | 30 | 0.2098 | 0.9341 | 430.00 | 433.33 | 0.78 |
| branch_layout | llvmbpf | 30 | 0.3602 | 0.0260 | 153.87 | 153.00 | -0.56 |
| branch_layout | kernel | 30 | 0.0109 | 0.1514 | 582.07 | 558.73 | -4.01 |
| switch_dispatch | llvmbpf | 30 | -0.1329 | 0.2211 | 181.07 | 178.73 | -1.29 |
| switch_dispatch | kernel | 30 | -0.0516 | 0.4602 | 251.13 | 246.20 | -1.96 |
| checksum | llvmbpf | 30 | -0.0494 | 0.5687 | 10853.47 | 10817.00 | -0.34 |
| checksum | kernel | 30 | -0.2365 | 1.0000 | 12121.13 | 12122.53 | 0.01 |
| packet_parse | llvmbpf | 30 | -0.0582 | 0.1797 | 90.00 | 90.27 | 0.30 |
| packet_parse | kernel | 30 | 0.0638 | 0.6496 | 93.60 | 98.13 | 4.84 |
| bounds_ladder | llvmbpf | 30 | -0.0401 | 0.7127 | 88.07 | 81.47 | -7.49 |
| bounds_ladder | kernel | 30 | -0.1123 | 0.1358 | 152.67 | 168.00 | 10.04 |
| stride_load_4 | llvmbpf | 30 | -0.0318 | 0.5102 | 97.67 | 123.27 | 26.21 |
| stride_load_4 | kernel | 30 | -0.0840 | 0.3624 | 245.93 | 223.13 | -9.27 |
| stride_load_16 | llvmbpf | 30 | -0.1315 | 0.5879 | 97.67 | 97.40 | -0.27 |
| stride_load_16 | kernel | 30 | -0.2012 | 0.0500 | 213.40 | 235.93 | 10.56 |
| spill_pressure | llvmbpf | 30 | -0.0765 | 0.6080 | 247.33 | 255.67 | 3.37 |
| spill_pressure | kernel | 30 | -0.0974 | 0.9250 | 305.33 | 421.67 | 38.10 |
| multi_acc_4 | llvmbpf | 30 | -0.0623 | 0.7170 | 257.40 | 260.73 | 1.30 |
| multi_acc_4 | kernel | 30 | -0.0787 | 0.5318 | 306.60 | 286.00 | -6.72 |
| multi_acc_8 | llvmbpf | 30 | -0.0704 | 0.5320 | 449.60 | 431.40 | -4.05 |
| multi_acc_8 | kernel | 30 | -0.2088 | 0.2329 | 460.60 | 427.00 | -7.29 |
| fibonacci_iter | llvmbpf | 30 | -0.0807 | 0.0280 | 577.60 | 588.67 | 1.92 |
| fibonacci_iter | kernel | 30 | -0.2665 | 0.7969 | 687.27 | 688.80 | 0.22 |
| fixed_loop_small | llvmbpf | 30 | -0.1649 | 0.4054 | 94.47 | 95.00 | 0.56 |
| fixed_loop_small | kernel | 30 | -0.0090 | 0.8588 | 96.73 | 98.27 | 1.59 |
| fixed_loop_large | llvmbpf | 30 | -0.0592 | 0.5268 | 1507.87 | 1503.87 | -0.27 |
| fixed_loop_large | kernel | 30 | -0.2127 | 0.7763 | 1258.33 | 1265.27 | 0.55 |
| code_clone_2 | llvmbpf | 30 | -0.1398 | 0.3078 | 412.20 | 427.87 | 3.80 |
| code_clone_2 | kernel | 30 | -0.0805 | 0.7267 | 369.53 | 346.47 | -6.24 |
| code_clone_8 | llvmbpf | 30 | -0.0684 | 0.7197 | 2330.87 | 2225.13 | -4.54 |
| code_clone_8 | kernel | 30 | -0.0539 | 0.0597 | 1141.47 | 1232.73 | 8.00 |

## Summary

- Total benchmark x runtime pairs analyzed: **44**
- Pairs with significant drift (Wilcoxon p < 0.05): **3 / 44**
- Pairs with strong autocorrelation (|ACF(1)| > 0.3): **2 / 44**

### Benchmarks with significant drift

- **dep_chain_long** [llvmbpf]: p=0.0353, drift=0.36%
- **branch_layout** [llvmbpf]: p=0.0260, drift=-0.56%
- **fibonacci_iter** [llvmbpf]: p=0.0280, drift=1.92%

### Benchmarks with strong autocorrelation

- **bitcount** [kernel]: ACF(1)=0.3578
- **branch_layout** [llvmbpf]: ACF(1)=0.3602

Plots saved to `/home/yunwei37/workspace/bpf-benchmark/micro/results/stability/`.
