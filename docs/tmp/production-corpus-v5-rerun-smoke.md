# Production Corpus v5 Results

- Generated: 2026-03-10T22:03:26.996050+00:00
- Repo root: `/home/yunwei37/workspace/bpf-benchmark`
- Kernel release: `6.15.11-061511-generic`
- Kernel tree: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux`
- Kernel branch: `jit-fixed-baselines`
- Kernel commit: `1572a4ddb`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- BTF candidates: `/sys/kernel/btf/vmlinux`, `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/vmlinux`
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
| Baseline compile successes | 0 |
| v5 compile successes | 1 |
| Scanner successes | 0 |
| Programs with framework-detected sites | 1 |
| Programs with recompile applied | 0 |
| Programs with recompile syscall failures | 0 |
| Compile-only size pairs | 0 |
| Measured runtime pairs | 0 |
| Speedup geomean | n/a |
| Speedup median | n/a |
| Speedup min | n/a |
| Speedup max | n/a |
| Code-size ratio geomean (baseline/v5) | n/a |
| Code-size median delta | n/a |
| Code-size min delta | n/a |
| Code-size max delta | n/a |
| Framework CMOV sites | 5 |
| Framework WIDE sites | 4 |
| Framework ROTATE sites | 0 |
| Framework LEA sites | 0 |

## Objects

| Object | Source | Discovery | Discovered Programs | Tested Programs | Compile Successes | Measured | Note |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/katran/balancer.bpf.o | katran | yes | 1 | 1 | 0 | 0 |  |

## Per-Program Results

| Program | Section | Perf-capable | Baseline Load | v5 Load | CMOV | WIDE | ROTATE | LEA | Applied | Baseline JIT Bytes | v5 JIT Bytes | Code Delta | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | xdp | yes | no | yes | 5 | 4 | 0 | 0 | no | n/a | 13652 | n/a | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| unable to open file for writing: /tmp/production-corpus-g121pr9e.xlated (exit=1) | 1 |

## Notes

- These results were collected inside the framework guest booted from `vendor/linux`.
- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.
- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `vendor/linux/vmlinux` only for BTF/CO-RE-looking failures.
- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.
