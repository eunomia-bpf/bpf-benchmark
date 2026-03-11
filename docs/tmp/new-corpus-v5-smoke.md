# Production Corpus v5 Results

- Generated: 2026-03-10T22:28:29.144346+00:00
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
| Speedup geomean | 0.548x |
| Speedup median | 0.548x |
| Speedup min | 0.548x |
| Speedup max | 0.548x |
| Code-size ratio geomean (baseline/v5) | 0.996x |
| Code-size median delta | +0.4% |
| Code-size min delta | +0.4% |
| Code-size max delta | +0.4% |
| Framework CMOV sites | 1 |
| Framework WIDE sites | 0 |
| Framework ROTATE sites | 0 |
| Framework LEA sites | 0 |

## Objects

| Object | Source | Discovery | Discovered Programs | Tested Programs | Compile Successes | Measured | Note |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/suricata/xdp_filter.bpf.o | suricata | yes | 1 | 1 | 1 | 1 |  |

## Per-Program Results

| Program | Section | Perf-capable | Baseline Load | v5 Load | CMOV | WIDE | ROTATE | LEA | Applied | Baseline JIT Bytes | v5 JIT Bytes | Code Delta | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | yes | 1645 | 1651 | +0.4% |  |

## Runtime Comparison

| Program | Section | Baseline ns | v5 ns | Speedup | Baseline JIT Bytes | v5 JIT Bytes |
| --- | --- | --- | --- | --- | --- | --- |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | xdp | 46 | 84 | 0.548x | 1645 | 1651 |

## Notes

- These results were collected inside the guest booted from `vendor/linux`.
- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.
- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `vendor/linux/vmlinux` only for BTF/CO-RE-looking failures.
- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.
