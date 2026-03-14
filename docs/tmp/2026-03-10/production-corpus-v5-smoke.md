# Production Corpus v5 Results

- Generated: 2026-03-10T21:43:10.875274+00:00
- Repo root: `/home/yunwei37/workspace/bpf-benchmark`
- Kernel release: `7.0.0-rc2-g1572a4ddb52b-dirty`
- Kernel tree: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux`
- Kernel branch: ``
- Kernel commit: ``
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- BTF candidates: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/vmlinux`
- Repeat: 5

## Summary

| Metric | Value |
| --- | --- |
| Objects attempted | 1 |
| Objects discovered via libbpf | 1 |
| Objects with discovery failures | 0 |
| Programs attempted | 1 |
| Perf-capable targets | 1 |
| Compile-only targets | 0 |
| Baseline compile successes | 1 |
| v5 compile successes | 1 |
| Scanner successes | 1 |
| Programs with framework-detected sites | 1 |
| Programs with recompile applied | 0 |
| Compile-only size pairs | 1 |
| Measured runtime pairs | 1 |
| Speedup geomean | 1.562x |
| Speedup median | 1.562x |
| Speedup min | 1.562x |
| Speedup max | 1.562x |
| Code-size ratio geomean (baseline/v5) | 1.000x |
| Code-size median delta | +0.0% |
| Code-size min delta | +0.0% |
| Code-size max delta | +0.0% |
| Framework CMOV sites | 1 |
| Framework WIDE sites | 0 |
| Framework ROTATE sites | 0 |
| Framework LEA sites | 0 |

## Objects

| Object | Source | Discovery | Discovered Programs | Tested Programs | Compile Successes | Measured | Note |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o | xdp-tools | yes | 1 | 1 | 1 | 1 |  |

## Per-Program Results

| Program | Section | Perf-capable | Baseline Load | v5 Load | CMOV | WIDE | ROTATE | LEA | Applied | Baseline JIT Bytes | v5 JIT Bytes | Code Delta | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | no | 84 | 84 | +0.0% |  |

## Runtime Comparison

| Program | Section | Baseline ns | v5 ns | Speedup | Baseline JIT Bytes | v5 JIT Bytes |
| --- | --- | --- | --- | --- | --- | --- |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp | 150 | 96 | 1.562x | 84 | 84 |

## Notes

- These results were collected inside the framework guest booted from `vendor/linux`.
- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.
- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `vendor/linux/vmlinux` only for BTF/CO-RE-looking failures.
- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.
