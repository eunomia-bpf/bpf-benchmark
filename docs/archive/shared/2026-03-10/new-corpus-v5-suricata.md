# Production Corpus v5 Results

- Generated: 2026-03-10T22:31:59.117481+00:00
- Repo root: `/home/yunwei37/workspace/bpf-benchmark`
- Kernel release: `7.0.0-rc2-g1572a4ddb52b-dirty`
- Kernel tree: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux`
- Kernel branch: ``
- Kernel commit: ``
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- BTF candidates: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/vmlinux`
- Repeat: 100

## Summary

| Metric | Value |
| --- | --- |
| Objects attempted | 2 |
| Objects discovered via libbpf | 2 |
| Objects with discovery failures | 0 |
| Programs attempted | 2 |
| Perf-capable targets | 2 |
| Compile-only targets | 0 |
| Baseline compile successes | 1 |
| v5 compile successes | 1 |
| Scanner successes | 1 |
| Programs with framework-detected sites | 1 |
| Programs with recompile applied | 1 |
| Programs with recompile syscall failures | 0 |
| Compile-only size pairs | 1 |
| Measured runtime pairs | 1 |
| Speedup geomean | 1.200x |
| Speedup median | 1.200x |
| Speedup min | 1.200x |
| Speedup max | 1.200x |
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
| corpus/build/suricata/xdp_lb.bpf.o | suricata | yes | 1 | 1 | 0 | 0 |  |

## Per-Program Results

| Program | Section | Perf-capable | Baseline Load | v5 Load | CMOV | WIDE | ROTATE | LEA | Applied | Baseline JIT Bytes | v5 JIT Bytes | Code Delta | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | yes | 1645 | 1651 | +0.4% |  |
| corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Argument list too long (exit=1) |

## Runtime Comparison

| Program | Section | Baseline ns | v5 ns | Speedup | Baseline JIT Bytes | v5 JIT Bytes |
| --- | --- | --- | --- | --- | --- | --- |
| corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter | xdp | 12 | 10 | 1.200x | 1645 | 1651 |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Argument list too long (exit=1) | 1 |

## Notes

- These results were collected inside the guest booted from `vendor/linux`.
- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.
- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `vendor/linux/vmlinux` only for BTF/CO-RE-looking failures.
- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.
