# LLVM Pass Ablation

- Generated at: `2026-03-08T00:45:22.590827+00:00`
- Suite manifest: `/home/yunwei37/workspace/bpf-benchmark/config/micro_pure_jit.yaml`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Benchmarks: `simple, simple_packet, memory_pair_sum, bitcount, log2_fold, dep_chain_short, dep_chain_long, binary_search, branch_layout, switch_dispatch, branch_dense, checksum, packet_parse, bounds_ladder, bounds_check_heavy, stride_load_4, stride_load_16, mixed_alu_mem, spill_pressure, multi_acc_4, multi_acc_8, fibonacci_iter, fibonacci_iter_packet, fixed_loop_small, fixed_loop_large, nested_loop_2, nested_loop_3, code_clone_2, code_clone_8, large_mixed_500, large_mixed_1000`
- Candidate passes: `InstCombinePass, SimplifyCFGPass`
- Runtime: `llvmbpf` only
- Iterations per configuration: `10`
- Warmups per configuration: `2`
- Repeat per sample: `500`

## Benchmark Summary

| Benchmark | Baseline size | -InstCombinePass size | -SimplifyCFGPass size | -InstCombinePass exec% | -SimplifyCFGPass exec% |
| --- | --- | --- | --- | --- | --- |
| simple | 102 | 109 | 102 | +0.0% | +6.7% |
| simple_packet | 47 | 54 | 47 | +11.1% | +0.0% |
| memory_pair_sum | 92 | 99 | 92 | -2.9% | -5.7% |
| bitcount | 268 | 261 | 268 | +14.6% | +1.5% |
| log2_fold | 420 | 395 | 427 | -4.2% | -34.6% |
| dep_chain_short | 201 | 190 | 201 | -7.4% | -14.8% |
| dep_chain_long | 204 | 193 | 204 | -1.3% | +6.0% |
| binary_search | 373 | 356 | 377 | -23.2% | -37.9% |
| branch_layout | 165 | 170 | 165 | +0.0% | +0.0% |
| switch_dispatch | 1293 | 1309 | 1250 | -2.5% | +11.4% |
| branch_dense | 581 | 571 | 585 | -16.0% | -35.3% |
| checksum | 200 | 205 | 200 | +0.2% | -0.3% |
| packet_parse | 235 | 227 | 235 | -1.2% | -1.7% |
| bounds_ladder | 328 | 318 | 319 | +0.7% | -20.0% |
| bounds_check_heavy | 1241 | 1280 | 1241 | -5.5% | -0.2% |
| stride_load_4 | 168 | 173 | 168 | -1.2% | +3.1% |
| stride_load_16 | 168 | 173 | 168 | -20.8% | -21.2% |
| mixed_alu_mem | 935 | 935 | 962 | -2.4% | +1.9% |
| spill_pressure | 659 | 548 | 659 | +0.9% | -13.7% |
| multi_acc_4 | 380 | 274 | 380 | -10.4% | -5.7% |
| multi_acc_8 | 637 | 617 | 637 | -16.0% | +0.2% |
| fibonacci_iter | 183 | 196 | 165 | -4.8% | -2.0% |
| fibonacci_iter_packet | 140 | 160 | 124 | -7.2% | -4.8% |
| fixed_loop_small | 184 | 189 | 174 | -1.7% | -29.3% |
| fixed_loop_large | 222 | 225 | 213 | -1.9% | -23.3% |
| nested_loop_2 | 348 | 337 | 351 | +1.4% | +7.6% |
| nested_loop_3 | 859 | 822 | 859 | -10.2% | -11.8% |
| code_clone_2 | 260 | 262 | 260 | +16.2% | +3.4% |
| code_clone_8 | 422 | 470 | 422 | -23.5% | +0.5% |
| large_mixed_500 | 1022 | 1603 | 1868 | +3.2% | -2.3% |
| large_mixed_1000 | 1662 | 2992 | 1792 | +1.3% | -18.5% |

## Configuration Summary

| Configuration | Successful benchmarks | Median size ratio | Geomean exec ratio | Median exec delta |
| --- | ---: | ---: | ---: | ---: |
| baseline | 31/31 | 1.000x | 1.000x | +0.0% |
| -InstCombinePass | 31/31 | 1.012x | 0.959x | -1.9% |
| -SimplifyCFGPass | 31/31 | 1.000x | 0.912x | -2.0% |

## Notes

- `code_size` is the median `native_code_bytes` across the `10` llvmbpf samples for that configuration.
- `exec%` is the percent change in median `exec_ns` versus the same benchmark's baseline.
- `ERR` means the configuration failed to compile or execute for that benchmark.

## Failures

- None.
