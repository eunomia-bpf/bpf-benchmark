# Production Corpus v5 Results

- Generated: 2026-03-10T22:06:41.944690+00:00
- Repo root: `/home/yunwei37/workspace/bpf-benchmark`
- Kernel release: `7.0.0-rc2-g1572a4ddb52b-dirty`
- Kernel tree: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux`
- Kernel branch: ``
- Kernel commit: ``
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- BTF candidates: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/vmlinux`
- Repeat: 10

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
| Programs with recompile applied | 1 |
| Programs with recompile syscall failures | 0 |
| Compile-only size pairs | 1 |
| Measured runtime pairs | 1 |
| Speedup geomean | 1.189x |
| Speedup median | 1.189x |
| Speedup min | 1.189x |
| Speedup max | 1.189x |
| Code-size ratio geomean (baseline/v5) | 1.002x |
| Code-size median delta | -0.2% |
| Code-size min delta | -0.2% |
| Code-size max delta | -0.2% |
| Framework CMOV sites | 5 |
| Framework WIDE sites | 4 |
| Framework ROTATE sites | 0 |
| Framework LEA sites | 0 |

## Objects

| Object | Source | Discovery | Discovered Programs | Tested Programs | Compile Successes | Measured | Note |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/katran/balancer.bpf.o | katran | yes | 1 | 1 | 1 | 1 |  |

## Per-Program Results

| Program | Section | Perf-capable | Baseline Load | v5 Load | CMOV | WIDE | ROTATE | LEA | Applied | Baseline JIT Bytes | v5 JIT Bytes | Code Delta | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | xdp | yes | yes | yes | 5 | 4 | 0 | 0 | yes | 13654 | 13626 | -0.2% |  |

## Runtime Comparison

| Program | Section | Baseline ns | v5 ns | Speedup | Baseline JIT Bytes | v5 JIT Bytes |
| --- | --- | --- | --- | --- | --- | --- |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | xdp | 145 | 122 | 1.189x | 13654 | 13626 |

## Notes

- These results were collected inside the framework guest booted from `vendor/linux`.
- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.
- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `vendor/linux/vmlinux` only for BTF/CO-RE-looking failures.
- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.
