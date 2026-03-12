# bpftrace Policy Artifacts

Date: 2026-03-12

## Summary

- `which bpftrace` resolved to `/usr/bin/bpftrace`.
- Generated 5 ELF objects under `corpus/build/bpftrace/` with `sudo -n bpftrace --emit-elf`.
- Scanned all 7 object programs with `./scanner/build/bpf-jit-scanner scan <object> --program-name <program> --all --v5 --json`.
- Site-positive programs: 2/7.
- Aggregate 8-family census: `total=12`, `cmov=12`, `wide=0`, `rotate=0`, `lea=0`, `extract=0`, `zero-ext=0`, `endian=0`, `branch-flip=0`.
- Generated 2 E2E-facing v2 policy files under `corpus/policies/bpftrace/`.

## Generated ELF Artifacts

| Script | Output ELF |
| --- | --- |
| `e2e/cases/bpftrace/scripts/exec_trace.bt` | `corpus/build/bpftrace/exec_trace.bpf.o` |
| `e2e/cases/bpftrace/scripts/open_latency.bt` | `corpus/build/bpftrace/open_latency.bpf.o` |
| `e2e/cases/bpftrace/scripts/scheduler_latency.bt` | `corpus/build/bpftrace/scheduler_latency.bpf.o` |
| `e2e/cases/bpftrace/scripts/tcp_connect.bt` | `corpus/build/bpftrace/tcp_connect.bpf.o` |
| `e2e/cases/bpftrace/scripts/vfs_read_count.bt` | `corpus/build/bpftrace/vfs_read_count.bpf.o` |

## Object Programs

| ELF | Programs |
| --- | --- |
| `exec_trace.bpf.o` | `tracepoint:sched:sched_process_exec` |
| `open_latency.bpf.o` | `kprobe:do_sys_openat2`, `kretprobe:do_sys_openat2` |
| `scheduler_latency.bpf.o` | `tracepoint:sched:sched_wakeup`, `tracepoint:sched:sched_switch` |
| `tcp_connect.bpf.o` | `kprobe:tcp_v4_connect` |
| `vfs_read_count.bpf.o` | `kprobe:vfs_read` |

## 8-Family Site Census

| ELF | Program | Total | cmov | wide | rotate | lea | extract | zero-ext | endian | branch-flip |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `exec_trace.bpf.o` | `tracepoint:sched:sched_process_exec` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `open_latency.bpf.o` | `kprobe:do_sys_openat2` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `open_latency.bpf.o` | `kretprobe:do_sys_openat2` | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `scheduler_latency.bpf.o` | `tracepoint:sched:sched_wakeup` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `scheduler_latency.bpf.o` | `tracepoint:sched:sched_switch` | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `tcp_connect.bpf.o` | `kprobe:tcp_v4_connect` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `vfs_read_count.bpf.o` | `kprobe:vfs_read` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| aggregate | all 7 programs | 12 | 12 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

## Generated Policies

The generated documents follow the current v2 steady-state shape:

- `version: 2`
- `default: apply`
- `families: {cmov: skip}` when CMOV sites exist
- `sites: []`

Files written:

| Policy file | Live program name | Source object program | Notes |
| --- | --- | --- | --- |
| `corpus/policies/bpftrace/open_latency/do_sys_openat2.policy.yaml` | `do_sys_openat2` | `kretprobe:do_sys_openat2` | The live bpftrace loader names both attached programs `do_sys_openat2`; only the kretprobe variant has scanner sites in the emitted ELF. |
| `corpus/policies/bpftrace/scheduler_latency/sched_switch.policy.yaml` | `sched_switch` | `tracepoint:sched:sched_switch` | Site-positive tracepoint program. |

## Validation

Static validation:

- `parse_policy_v2('corpus/policies/bpftrace/open_latency/do_sys_openat2.policy.yaml')` succeeded.
- `parse_policy_v2('corpus/policies/bpftrace/scheduler_latency/sched_switch.policy.yaml')` succeeded.

Lookup validation:

- `e2e/common/recompile.py` resolves policies via `resolve_policy_path(object_path, program_name=live_name)`.
- Live attach validation with `resolve_bpftrace_policy_files()` produced:
  - `open_latency`: two attached live programs both named `do_sys_openat2`; both resolved to `corpus/policies/bpftrace/open_latency/do_sys_openat2.policy.yaml`
  - `scheduler_latency`: `sched_switch` resolved to `corpus/policies/bpftrace/scheduler_latency/sched_switch.policy.yaml`

Important naming note:

- `discover_object_programs()` on the emitted ELF preserves the full attach-prefixed names such as `kretprobe:do_sys_openat2`.
- Live `bpftool`/E2E discovery reports bare names such as `do_sys_openat2` and `sched_switch`.
- Because `e2e/common/recompile.py` keys policy lookup on the live program name, the policy filenames for bpftrace must follow the live bare-name form to avoid stock fallback.

