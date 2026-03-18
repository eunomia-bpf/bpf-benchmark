# Benchmark Stability Analysis

- Input: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative.json`
- Generated from suite: `micro_staged_codegen`
- Rolling window: 5
- ACF(1) threshold: |ACF(1)| > 0.3
- Drift significance level: p < 0.05

## Time-Series Stability Table

| Benchmark | Runtime | N | ACF(1) | Drift p-value | 1st-half mean | 2nd-half mean | Drift% |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| simple | llvmbpf | 30 | -0.1416 | 0.8133 | 20.73 | 21.07 | 1.61 |
| simple | kernel | 30 | 0.0386 | 0.2566 | 14.93 | 12.47 | -16.52 |
| simple_packet | llvmbpf | 30 | 0.0063 | 0.1305 | 19.27 | 16.13 | -16.26 |
| simple_packet | kernel | 30 | 0.1314 | 0.7874 | 13.47 | 13.33 | -0.99 |
| memory_pair_sum | llvmbpf | 30 | -0.0022 | 0.9441 | 18.93 | 19.27 | 1.76 |
| memory_pair_sum | kernel | 30 | 0.0291 | 0.3428 | 16.67 | 13.87 | -16.80 |
| bitcount | llvmbpf | 30 | -0.0122 | 0.5894 | 4651.87 | 4641.27 | -0.23 |
| bitcount | kernel | 30 | 0.2929 | 0.9341 | 2974.87 | 2995.80 | 0.70 |
| log2_fold | llvmbpf | 30 | 0.1558 | 0.1053 | 305.73 | 318.87 | 4.30 |
| log2_fold | kernel | 30 | -0.1859 | 0.4101 | 303.73 | 317.27 | 4.46 |
| dep_chain_short | llvmbpf | 30 | -0.2162 | 0.1241 | 121.87 | 131.80 | 8.15 |
| dep_chain_short | kernel | 30 | 0.2544 | 0.4702 | 141.27 | 153.20 | 8.45 |
| dep_chain_long | llvmbpf | 30 | 0.0003 | 0.8260 | 419.13 | 419.67 | 0.13 |
| dep_chain_long | kernel | 30 | -0.0304 | 0.1817 | 443.13 | 426.67 | -3.72 |
| binary_search | llvmbpf | 30 | -0.1554 | 0.4236 | 209.87 | 215.67 | 2.76 |
| binary_search | kernel | 30 | 0.0519 | 0.2454 | 436.73 | 447.60 | 2.49 |
| branch_layout | llvmbpf | 30 | -0.1650 | 0.6374 | 162.00 | 162.07 | 0.04 |
| branch_layout | kernel | 30 | -0.0971 | 0.9163 | 547.07 | 573.93 | 4.91 |
| switch_dispatch | llvmbpf | 30 | 0.0216 | 0.2449 | 209.80 | 213.53 | 1.78 |
| switch_dispatch | kernel | 30 | -0.1629 | 0.6092 | 267.00 | 269.67 | 1.00 |
| branch_dense | llvmbpf | 30 | 0.1716 | 0.0735 | 622.33 | 634.00 | 1.87 |
| branch_dense | kernel | 30 | 0.1120 | 0.0652 | 435.20 | 456.60 | 4.92 |
| checksum | llvmbpf | 30 | 0.1234 | 0.3340 | 10829.13 | 10829.07 | -0.00 |
| checksum | kernel | 30 | -0.1516 | 0.2293 | 11999.07 | 12063.80 | 0.54 |
| packet_parse | llvmbpf | 30 | -0.1287 | 0.2135 | 95.53 | 102.33 | 7.12 |
| packet_parse | kernel | 30 | 0.3396 | 0.5301 | 97.87 | 107.40 | 9.74 |
| bounds_ladder | llvmbpf | 30 | -0.2414 | 0.8335 | 91.80 | 89.40 | -2.61 |
| bounds_ladder | kernel | 30 | 0.0277 | 0.3939 | 195.93 | 182.20 | -7.01 |
| bounds_check_heavy | llvmbpf | 30 | -0.0271 | 0.7332 | 245.27 | 321.00 | 30.88 |
| bounds_check_heavy | kernel | 30 | -0.2229 | 0.6387 | 252.47 | 253.73 | 0.50 |
| stride_load_4 | llvmbpf | 30 | -0.2331 | 0.9249 | 106.00 | 107.07 | 1.01 |
| stride_load_4 | kernel | 30 | 0.1498 | 0.0131 | 223.20 | 259.20 | 16.13 |
| stride_load_16 | llvmbpf | 30 | -0.0507 | 0.3440 | 102.80 | 105.60 | 2.72 |
| stride_load_16 | kernel | 30 | -0.0606 | 0.5894 | 250.27 | 242.53 | -3.09 |
| mixed_alu_mem | llvmbpf | 30 | -0.0779 | 0.2078 | 496.67 | 528.27 | 6.36 |
| mixed_alu_mem | kernel | 30 | 0.0775 | 0.0308 | 711.47 | 679.73 | -4.46 |
| spill_pressure | llvmbpf | 30 | -0.2340 | 0.7775 | 254.80 | 256.33 | 0.60 |
| spill_pressure | kernel | 30 | -0.0395 | 0.5245 | 286.53 | 300.47 | 4.86 |
| multi_acc_4 | llvmbpf | 30 | 0.1895 | 0.9320 | 274.13 | 271.87 | -0.83 |
| multi_acc_4 | kernel | 30 | 0.0923 | 0.4321 | 280.27 | 293.60 | 4.76 |
| multi_acc_8 | llvmbpf | 30 | 0.1627 | 0.2326 | 438.27 | 433.40 | -1.11 |
| multi_acc_8 | kernel | 30 | -0.3338 | 0.3304 | 464.40 | 452.53 | -2.56 |
| fibonacci_iter | llvmbpf | 30 | -0.1220 | 0.8068 | 577.40 | 576.67 | -0.13 |
| fibonacci_iter | kernel | 30 | -0.0362 | 0.9095 | 718.73 | 719.20 | 0.06 |
| fibonacci_iter_packet | llvmbpf | 30 | 0.0433 | 0.9248 | 598.80 | 599.73 | 0.16 |
| fibonacci_iter_packet | kernel | 30 | -0.2345 | 0.0843 | 721.73 | 742.67 | 2.90 |
| fixed_loop_small | llvmbpf | 30 | 0.1163 | 0.1239 | 98.00 | 109.07 | 11.29 |
| fixed_loop_small | kernel | 30 | -0.1142 | 0.8469 | 133.73 | 139.13 | 4.04 |
| fixed_loop_large | llvmbpf | 30 | -0.1166 | 0.0426 | 1470.07 | 1515.87 | 3.12 |
| fixed_loop_large | kernel | 30 | 0.1529 | 0.6089 | 1243.47 | 1258.73 | 1.23 |
| nested_loop_2 | llvmbpf | 30 | -0.1600 | 0.7776 | 435.67 | 445.47 | 2.25 |
| nested_loop_2 | kernel | 30 | -0.3809 | 0.7529 | 540.00 | 530.53 | -1.75 |
| nested_loop_3 | llvmbpf | 30 | 0.0208 | 0.5508 | 266.07 | 288.47 | 8.42 |
| nested_loop_3 | kernel | 30 | 0.0318 | 0.6832 | 688.93 | 679.33 | -1.39 |
| code_clone_2 | llvmbpf | 30 | 0.2131 | 0.1117 | 396.53 | 422.33 | 6.51 |
| code_clone_2 | kernel | 30 | -0.1002 | 0.1004 | 317.27 | 332.40 | 4.77 |
| code_clone_8 | llvmbpf | 30 | 0.0459 | 0.7332 | 2263.00 | 2270.87 | 0.35 |
| code_clone_8 | kernel | 30 | 0.0313 | 0.2933 | 1238.67 | 1175.27 | -5.12 |
| large_mixed_500 | llvmbpf | 30 | 0.1811 | 0.5300 | 352.20 | 357.13 | 1.40 |
| large_mixed_500 | kernel | 30 | -0.1605 | 0.6153 | 509.27 | 514.67 | 1.06 |
| large_mixed_1000 | llvmbpf | 30 | 0.0941 | 0.2329 | 755.13 | 732.20 | -3.04 |
| large_mixed_1000 | kernel | 30 | 0.0845 | 0.1028 | 1008.60 | 994.60 | -1.39 |

## Summary

- Total benchmark x runtime pairs analyzed: **62**
- Pairs with significant drift (Wilcoxon p < 0.05): **3 / 62**
- Pairs with strong autocorrelation (|ACF(1)| > 0.3): **3 / 62**

### Benchmarks with significant drift

- **stride_load_4** [kernel]: p=0.0131, drift=16.13%
- **mixed_alu_mem** [kernel]: p=0.0308, drift=-4.46%
- **fixed_loop_large** [llvmbpf]: p=0.0426, drift=3.12%

### Benchmarks with strong autocorrelation

- **packet_parse** [kernel]: ACF(1)=0.3396
- **multi_acc_8** [kernel]: ACF(1)=-0.3338
- **nested_loop_2** [kernel]: ACF(1)=-0.3809

Plots saved to `/home/yunwei37/workspace/bpf-benchmark/micro/results/stability/`.
