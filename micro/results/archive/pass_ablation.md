# LLVM Pass Ablation

- Generated at: `2026-03-08T00:38:27.510930+00:00`
- Suite manifest: `/home/yunwei37/workspace/bpf-benchmark/config/micro_pure_jit.yaml`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Benchmarks: `simple, bitcount, binary_search, branch_layout, switch_dispatch, fibonacci_iter, checksum, stride_load_4, nested_loop_3, large_mixed_500, bpf_call_chain`
- Candidate passes: `InstCombinePass, GVNPass, LICMPass, LoopUnrollPass, SROAPass, JumpThreadingPass, DSEPass, SimplifyCFGPass, ADCEPass`
- Runtime: `llvmbpf` only
- Iterations per configuration: `5`
- Repeat per sample: `200`

## Benchmark Summary

| Benchmark | Baseline size | -InstCombinePass size | -GVNPass size | -LICMPass size | -LoopUnrollPass size | -SROAPass size | -JumpThreadingPass size | -DSEPass size | -SimplifyCFGPass size | -ADCEPass size | -InstCombinePass exec% | -GVNPass exec% | -LICMPass exec% | -LoopUnrollPass exec% | -SROAPass exec% | -JumpThreadingPass exec% | -DSEPass exec% | -SimplifyCFGPass exec% | -ADCEPass exec% |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| simple | 102 | 109 | 102 | 102 | 102 | 102 | 102 | 102 | 102 | 102 | -4.8% | -4.8% | -4.8% | +14.3% | -4.8% | -9.5% | -9.5% | -9.5% | -4.8% |
| bitcount | 268 | 261 | 268 | 268 | 268 | 268 | 268 | 268 | 268 | 268 | -9.2% | +1.5% | +1.4% | +0.9% | +0.2% | +0.5% | +2.1% | +0.5% | +0.6% |
| binary_search | 373 | 356 | 373 | 373 | 373 | 377 | 373 | 373 | 377 | 373 | -13.3% | +0.0% | +0.5% | +0.0% | -30.5% | +0.5% | +0.5% | -26.7% | +0.5% |
| branch_layout | 165 | 170 | 165 | 165 | 165 | 165 | 165 | 165 | 165 | 165 | -0.6% | -0.6% | -1.2% | -0.6% | +0.0% | +18.8% | +0.0% | -0.6% | +0.0% |
| switch_dispatch | 1293 | 1309 | 1293 | 1293 | 1293 | 1293 | 1293 | 1293 | 1250 | 1293 | -6.6% | -27.9% | -21.7% | +2.6% | -8.8% | +1.1% | -7.0% | +1.8% | -29.8% |
| fibonacci_iter | 183 | 196 | 183 | 183 | 183 | 186 | 183 | 183 | 165 | 183 | -7.4% | +0.0% | +0.0% | +0.0% | -4.6% | +0.7% | +0.0% | +2.9% | -2.6% |
| checksum | 200 | 205 | 200 | 200 | 200 | 200 | 200 | 200 | 200 | 200 | +0.1% | -0.1% | +0.0% | -0.1% | -0.1% | -0.1% | +0.0% | +0.1% | +0.0% |
| stride_load_4 | 168 | 173 | 168 | 168 | 168 | 168 | 168 | 168 | 168 | 168 | +0.0% | +2.9% | +0.0% | +0.0% | +0.0% | +1.0% | +0.0% | +6.8% | -1.0% |
| nested_loop_3 | 859 | 822 | 859 | 859 | 859 | 860 | 859 | 859 | 859 | 859 | -24.8% | -20.3% | -21.4% | -0.2% | -48.1% | -1.1% | -14.1% | -33.0% | +2.3% |
| large_mixed_500 | 1022 | 1603 | 1022 | 1022 | 1022 | 938 | 1022 | 1022 | 1868 | 1022 | -14.0% | -0.7% | +5.1% | +9.9% | +6.0% | +1.7% | -11.6% | +11.1% | +17.1% |
| bpf_call_chain | 580 | 580 | 580 | 554 | 580 | 580 | 580 | 580 | 596 | 580 | -9.6% | -9.9% | -10.3% | -9.6% | -9.6% | -9.9% | -9.6% | -9.6% | -9.6% |

## Configuration Summary

| Configuration | Successful benchmarks | Median size ratio | Geomean exec ratio | Median exec delta |
| --- | ---: | ---: | ---: | ---: |
| baseline | 11/11 | 1.000x | 1.000x | +0.0% |
| -InstCombinePass | 11/11 | 1.025x | 0.915x | -7.4% |
| -GVNPass | 11/11 | 1.000x | 0.940x | -0.6% |
| -LICMPass | 11/11 | 1.000x | 0.948x | +0.0% |
| -LoopUnrollPass | 11/11 | 1.000x | 1.014x | +0.0% |
| -SROAPass | 11/11 | 1.000x | 0.893x | -4.6% |
| -JumpThreadingPass | 11/11 | 1.000x | 1.001x | +0.5% |
| -DSEPass | 11/11 | 1.000x | 0.954x | +0.0% |
| -SimplifyCFGPass | 11/11 | 1.000x | 0.939x | +0.1% |
| -ADCEPass | 11/11 | 1.000x | 0.969x | +0.0% |

## Notes

- `code_size` is the median `native_code_bytes` across the `5` llvmbpf samples for that configuration.
- `exec%` is the percent change in median `exec_ns` versus the same benchmark's baseline.
- `ERR` means the configuration failed to compile or execute for that benchmark.

## Failures

- None.
