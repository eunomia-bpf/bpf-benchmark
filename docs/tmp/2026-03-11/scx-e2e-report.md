# scx_rusty End-to-End Report

Generated: 2026-03-11

Task: `#76`

Kernel / environment:

- Framework kernel: `7.0.0-rc2-g2a6783cc77b6`
- VM configuration: `vng`, `4` vCPU, `4G` RAM
- Scheduler binary: `corpus/repos/scx/target/release/scx_rusty`
- Scheduler object: `corpus/build/scx/scx_rusty_main.bpf.o`

## Summary

- The primary path works: `scx_rusty` can be started inside the framework VM and successfully enables `sched_ext`.
- The loader exposes `13` live `struct_ops` programs owned by `scx_rusty`.
- The end-to-end baseline workloads all ran successfully for `30s` each under the active scheduler:
  - `hackbench -g 4 -l 1000`: `2.524` runs/s, median run latency `381.5 ms`, about `194,764` context switches/s
  - `stress-ng --cpu 4 --timeout 30s --metrics-brief`: `7927.96` bogo-ops/s, about `355` context switches/s
  - `sysbench cpu --threads=4 --time=30 run`: `12047.28` events/s, median latency `0.33 ms`, about `340` context switches/s
- The userspace scheduler overhead was low in this VM run: `0.0666%` to `0.1333%` total CPU for the `scx_rusty` process across the three workloads.

## Directive Site Census

Scanner results on the live loaded programs:

- Total accepted sites: `28`
- CMOV sites: `27`
- LEA sites: `1`
- WIDE / ROTATE sites: `0`

Site-bearing callbacks:

- `rusty_enqueue`: `12` CMOV
- `rusty_stopping`: `10` CMOV
- `rusty_set_cpumask`: `2` CMOV
- `rusty_runnable`: `1` CMOV
- `rusty_quiescent`: `1` CMOV
- `rusty_init_task`: `1` CMOV
- `rusty_init`: `1` LEA

This is the strongest non-networking hot-path signal in the current local tree so far: the loaded scheduler is clearly CMOV-heavy, with a small but real LEA opportunity.

## What Did Not Work

### Raw `bpftool struct_ops register`

- Command: `/usr/local/sbin/bpftool struct_ops register corpus/build/scx/scx_rusty_main.bpf.o`
- Result: return code `0`, libbpf reports `Registered sched_ext_ops rusty map id 19 link id 1`
- But after the command exits:
  - `/sys/kernel/sched_ext/state` remains `disabled`
  - no `ops` entry remains active
  - `bpftool prog show` sees `0` surviving `struct_ops` programs

Conclusion: this is not a usable standalone loader path for the e2e benchmark in the current environment. The upstream `scx_rusty` userspace loader is required.

### `BPF_PROG_JIT_RECOMPILE`

- `apply` was attempted on all `13` loaded `struct_ops` programs
- `0 / 13` programs reported a successful apply
- The common explicit failure string was `BPF_PROG_JIT_RECOMPILE: Invalid argument`

Conclusion: the current kernel/userspace combination can load and run `scx_rusty`, but cannot yet produce a post-reJIT comparison for these live `struct_ops` programs.

### Runtime counters from `bpftool`

- `bpftool -j -p prog show` exposes `bytes_xlated`, `bytes_jited`, map IDs, and owning PID for the `struct_ops` programs
- It does **not** expose `run_cnt` / `run_time_ns` for these callbacks on this kernel

Conclusion: the scx e2e harness can currently report honest workload throughput, latency, context-switch rate, and scheduler-process CPU, but not per-callback BPF runtime deltas.

## Artifacts

- JSON result: `e2e/results/scx-e2e.json`
- Markdown summary: `e2e/results/scx-e2e.md`

## Bottom Line

`scx_rusty` e2e is now real enough to support the paper's scheduler story:

- the framework kernel can boot and run a real `sched_ext` scheduler,
- the scheduler can be exercised by real scheduler-sensitive workloads,
- the loaded callbacks carry meaningful directive sites (`28`, almost entirely CMOV),
- and the main remaining blocker is specifically recompile support for live `struct_ops`, not scheduler bring-up.

`scx_lavd` remains future work once the same loader and recompile questions are resolved for the larger scheduler.
