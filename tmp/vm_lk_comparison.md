# VM 7.0-rc2 L/K Comparison

## Run metadata

- VM kernel results: `/home/yunwei37/workspace/bpf-benchmark/tmp/vm_authoritative.json`
- llvmbpf results: `/home/yunwei37/workspace/bpf-benchmark/tmp/vm_llvmbpf.json`
- Host authoritative results: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative.json`
- VM kernel version: `7.0.0-rc2-gc23719abc330`
- llvmbpf source host/kernel: `Linux-7.0.0-rc2-gc23719abc330-x86_64-with-glibc2.39`
- Host authoritative kernel: `6.15.11-061511-generic`
- Metric: median `exec_ns`; `L/K` means `llvmbpf_exec_ns / kernel_exec_ns`, so larger values mean the kernel is faster relative to llvmbpf.

## Summary

- Benchmarks with both VM kernel and llvmbpf data: `36`
- Overlap with host authoritative L/K data: `31`
- VM 7.0-rc2 geomean L/K across all available benchmarks: `0.829x`
- VM 7.0-rc2 geomean L/K on host-overlap subset: `0.850x`
- Host authoritative geomean L/K on the same subset: `0.811x`
- Geomean VM/Host L/K shift on overlap subset: `1.049x`; values above `1.0x` mean 7.0-rc2 is faster relative to llvmbpf than the host baseline.
- Geomean parity-gap change (`VM gap / host gap`): `1.123x`
- Benchmarks closer to parity on 7.0-rc2: `16`
- Benchmarks farther from parity on 7.0-rc2: `15`
- Benchmarks unchanged vs host parity gap: `0`
- VM-only benchmarks without host authoritative L/K baseline: `bpf_call_chain, load_byte, load_byte_recompose, load_native_u64, load_word32`

Largest parity-gap closures:
- `code_clone_8`: VM L/K 1.217x, host L/K 1.909x, parity gap 0.909 -> 0.217
- `branch_dense`: VM L/K 1.131x, host L/K 1.450x, parity gap 0.450 -> 0.131
- `fixed_loop_small`: VM L/K 0.897x, host L/K 0.662x, parity gap 0.338 -> 0.103
- `fibonacci_iter_packet`: VM L/K 1.007x, host L/K 0.791x, parity gap 0.209 -> 0.007
- `fixed_loop_large`: VM L/K 0.990x, host L/K 1.198x, parity gap 0.198 -> 0.010

Largest parity-gap widenings:
- `simple_packet`: VM L/K 2.357x, host L/K 0.941x, parity gap 0.059 -> 1.357
- `memory_pair_sum`: VM L/K 2.000x, host L/K 0.971x, parity gap 0.029 -> 1.000
- `simple`: VM L/K 2.000x, host L/K 1.458x, parity gap 0.458 -> 1.000
- `bounds_check_heavy`: VM L/K 1.321x, host L/K 0.967x, parity gap 0.033 -> 0.321
- `packet_parse`: VM L/K 1.253x, host L/K 1.040x, parity gap 0.040 -> 0.253

## Per-benchmark Ratios

| Benchmark | llvmbpf exec median | VM kernel exec median | VM L/K | Host L/K | VM/Host L/K shift | Parity gap change | Interpretation |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| `binary_search` | 210.5 | 475.5 | 0.443x | 0.450x | 0.983x | 1.014x | farther from parity |
| `bitcount` | 1743.5 | 2990.5 | 0.583x | 1.522x | 0.383x | 0.798x | closer to parity |
| `bounds_check_heavy` | 251.0 | 190.0 | 1.321x | 0.967x | 1.366x | 9.745x | farther from parity |
| `bounds_ladder` | 81.0 | 217.5 | 0.372x | 0.401x | 0.929x | 1.048x | farther from parity |
| `bpf_call_chain` | 266.5 | 338.0 | 0.788x | n/a | n/a | n/a | no host baseline |
| `branch_dense` | 490.5 | 433.5 | 1.131x | 1.450x | 0.780x | 0.292x | closer to parity |
| `branch_layout` | 135.0 | 539.0 | 0.250x | 0.293x | 0.854x | 1.061x | farther from parity |
| `checksum` | 9179.5 | 11939.0 | 0.769x | 0.898x | 0.857x | 2.255x | farther from parity |
| `code_clone_2` | 306.5 | 369.0 | 0.831x | 1.287x | 0.646x | 0.591x | closer to parity |
| `code_clone_8` | 1256.0 | 1032.0 | 1.217x | 1.909x | 0.637x | 0.239x | closer to parity |
| `dep_chain_long` | 373.0 | 366.5 | 1.018x | 0.998x | 1.020x | 7.307x | farther from parity |
| `dep_chain_short` | 122.5 | 152.5 | 0.803x | 0.782x | 1.027x | 0.902x | closer to parity |
| `fibonacci_iter` | 605.0 | 686.0 | 0.882x | 0.798x | 1.106x | 0.583x | closer to parity |
| `fibonacci_iter_packet` | 618.0 | 614.0 | 1.007x | 0.791x | 1.272x | 0.031x | closer to parity |
| `fixed_loop_large` | 1035.0 | 1045.5 | 0.990x | 1.198x | 0.826x | 0.051x | closer to parity |
| `fixed_loop_small` | 100.0 | 111.5 | 0.897x | 0.662x | 1.355x | 0.305x | closer to parity |
| `large_mixed_1000` | 746.5 | 839.5 | 0.889x | 0.746x | 1.191x | 0.437x | closer to parity |
| `large_mixed_500` | 360.0 | 451.5 | 0.797x | 0.705x | 1.131x | 0.687x | closer to parity |
| `load_byte` | 174.5 | 219.0 | 0.797x | n/a | n/a | n/a | no host baseline |
| `load_byte_recompose` | 74.0 | 163.5 | 0.453x | n/a | n/a | n/a | no host baseline |
| `load_native_u64` | 78.0 | 91.5 | 0.852x | n/a | n/a | n/a | no host baseline |
| `load_word32` | 75.0 | 99.5 | 0.754x | n/a | n/a | n/a | no host baseline |
| `log2_fold` | 232.5 | 271.0 | 0.858x | 0.948x | 0.905x | 2.755x | farther from parity |
| `memory_pair_sum` | 26.0 | 13.0 | 2.000x | 0.971x | 2.059x | 35.000x | farther from parity |
| `mixed_alu_mem` | 492.5 | 606.5 | 0.812x | 0.707x | 1.149x | 0.641x | closer to parity |
| `multi_acc_4` | 267.0 | 287.5 | 0.929x | 1.013x | 0.916x | 5.297x | farther from parity |
| `multi_acc_8` | 307.5 | 307.5 | 1.000x | 0.905x | 1.104x | 0.000x | closer to parity |
| `nested_loop_2` | 385.0 | 439.5 | 0.876x | 0.817x | 1.073x | 0.676x | closer to parity |
| `nested_loop_3` | 273.0 | 584.5 | 0.467x | 0.392x | 1.190x | 0.877x | closer to parity |
| `packet_parse` | 99.0 | 79.0 | 1.253x | 1.040x | 1.204x | 6.257x | farther from parity |
| `simple` | 25.0 | 12.5 | 2.000x | 1.458x | 1.371x | 2.182x | farther from parity |
| `simple_packet` | 16.5 | 7.0 | 2.357x | 0.941x | 2.504x | 23.071x | farther from parity |
| `spill_pressure` | 256.5 | 221.0 | 1.161x | 0.877x | 1.323x | 1.306x | farther from parity |
| `stride_load_16` | 89.0 | 198.0 | 0.449x | 0.383x | 1.173x | 0.892x | closer to parity |
| `stride_load_4` | 91.0 | 220.0 | 0.414x | 0.416x | 0.994x | 1.004x | farther from parity |
| `switch_dispatch` | 191.5 | 252.5 | 0.758x | 0.761x | 0.997x | 1.009x | farther from parity |
