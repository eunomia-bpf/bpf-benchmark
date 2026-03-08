# VM 7.0-rc2 L/K Comparison

## Run metadata

- VM kernel results: `/home/yunwei37/workspace/bpf-benchmark/tmp/vm_authoritative.json`
- llvmbpf results: `/home/yunwei37/workspace/bpf-benchmark/tmp/_llvmbpf_dryrun.json`
- Host authoritative results: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative.json`
- VM kernel version: `7.0.0-rc2-gc23719abc330`
- llvmbpf source host/kernel: `Linux-6.15.11-061511-generic-x86_64-with-glibc2.39`
- Host authoritative kernel: `6.15.11-061511-generic`
- Metric: median `exec_ns`; `L/K` means `llvmbpf_exec_ns / kernel_exec_ns`, so smaller values mean the kernel is faster relative to llvmbpf.

## Summary

- Benchmarks with both VM kernel and llvmbpf data: `1`
- Overlap with host authoritative L/K data: `1`
- VM 7.0-rc2 geomean L/K across all available benchmarks: `4.800x`
- VM 7.0-rc2 geomean L/K on host-overlap subset: `4.800x`
- Host authoritative geomean L/K on the same subset: `1.458x`
- Geomean VM/Host L/K shift on overlap subset: `3.291x`
- Geomean parity-gap change (`VM gap / host gap`): `8.291x`
- Benchmarks closer to parity on 7.0-rc2: `0`
- Benchmarks farther from parity on 7.0-rc2: `1`
- Benchmarks unchanged vs host parity gap: `0`

Largest parity-gap closures:
- `simple`: VM L/K 4.800x, host L/K 1.458x, parity gap 0.458 -> 3.800

Largest parity-gap widenings:
- `simple`: VM L/K 4.800x, host L/K 1.458x, parity gap 0.458 -> 3.800

## Per-benchmark Ratios

| Benchmark | llvmbpf exec median | VM kernel exec median | VM L/K | Host L/K | VM/Host L/K shift | Parity gap change | Interpretation |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | 60.0 | 12.5 | 4.800x | 1.458x | 3.291x | 8.291x | farther from parity |
