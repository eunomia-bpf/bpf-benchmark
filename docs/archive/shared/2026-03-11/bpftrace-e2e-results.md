# bpftrace E2E Results

- Generated: `2026-03-11T15:33:09.855930+00:00`
- Host: `Linux-6.15.11-061511-generic-x86_64-with-glibc2.39`
- bpftrace: `bpftrace v0.20.2`
- stress-ng: `stress-ng, version 0.17.06 (gcc 13.2.0, x86_64 Linux 6.15.11-061511-generic)`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Artifact dir: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/bpftrace-artifacts`

## Summary

- Scripts run: 5
- `--emit-elf` successes: 5
- Artifact load-probe successes: 0
- Live attach successes: 5
- Live recompile successes: 0
- Aggregate sites: 9 (cmov=9, wide=0, rotate=0, lea=0)
- Geomean speedup: n/a

## Per-Script

| Script | Program Type | Sites | Stock ns | ReJIT ns | Speedup | ELF | Live | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| open_latency | kprobe | 5 | 99.13 | n/a | n/a | yes | yes | do_sys_openat2: BPF_PROG_JIT_RECOMPILE: Invalid argument |
| exec_tracing | tracepoint | 0 | 955.25 | n/a | n/a | yes | yes | bpf_object__load failed: Invalid argument |
| scheduler_latency | tracepoint | 4 | 74.96 | n/a | n/a | yes | yes | sched_switch: BPF_PROG_JIT_RECOMPILE: Invalid argument |
| vfs_read_count | kprobe | 0 | 78.34 | n/a | n/a | yes | yes | bpf_object__load failed: Invalid argument |
| tcp_connect | kprobe | 0 | 436.50 | n/a | n/a | yes | yes | bpf_object__load failed: Invalid argument |

## Notes

- `Sites` prefer live scanner counts on loaded programs; when live attach fails, the report falls back to raw emitted-ELF candidate sites.
- The artifact-first path emits `.bpf.o` files, scans them, renames sections into libbpf-like forms, and then attempts `micro_exec run-kernel --compile-only` as a generic load probe.
- `Stock ns` and `ReJIT ns` are weighted averages derived from `delta(run_time_ns) / delta(run_cnt)` across the bpftrace-owned programs for the same script.
- If the running kernel returns `BPF_PROG_JIT_RECOMPILE: EINVAL`, the script records the failure and leaves `ReJIT ns` / `Speedup` as `n/a` instead of reporting a fake comparison.

