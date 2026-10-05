# Framework Kernel Rebuild Report

## Summary

- Task: `#73`
- Kernel tree: `vendor/linux-framework/`
- Built image: `vendor/linux-framework/arch/x86/boot/bzImage`
- Booted kernel release: `7.0.0-rc2-g2a6783cc77b6`
- Build time: `131.43s`
- Scope: `.config` only; no kernel source files were modified

## CONFIG Changes

| Symbol | Before | After | Notes |
| --- | --- | --- | --- |
| `CONFIG_FTRACE_SYSCALLS` | `n` | `y` | Needed for Tetragon syscall tracepoints |
| `CONFIG_BPF_KPROBE_OVERRIDE` | `undef` | `y` | Needed for `bpf_override_return` support |
| `CONFIG_SCHED_CLASS_EXT` | `n` | `y` | Needed for `sched_ext` / scx |
| `CONFIG_FUNCTION_ERROR_INJECTION` | `n` | `y` | Required dependency for `CONFIG_BPF_KPROBE_OVERRIDE` |

## Verification

### Build Artifact

- `arch/x86/boot/bzImage` exists after rebuild (`18191360` bytes).

### Runtime Feature Checks

- VM booted successfully with `vendor/linux-framework/arch/x86/boot/bzImage`.
- Host `.config` confirms:
  - `CONFIG_FTRACE_SYSCALLS=y`
  - `CONFIG_BPF_KPROBE_OVERRIDE=y`
  - `CONFIG_SCHED_CLASS_EXT=y`
  - `CONFIG_FUNCTION_ERROR_INJECTION=y`
- In-guest feature probes:
  - `syscall_tracepoints=present` via `/sys/kernel/tracing/events/syscalls/sys_enter_execve`
  - `sched_ext_sysfs=present` via `/sys/kernel/sched_ext`

### BPF_PROG_JIT_RECOMPILE Smoke Test

- The task snippet needed adjustment for the current `micro_exec` CLI:
  - `--iterations` / `--warmups` are not accepted by `run-kernel`
  - `cmov_select` must run with `--io-mode staged --input-size 4104`
  - `--recompile-v5` must be paired with a family flag (`--recompile-cmov`)
- Successful in-guest run:
  - program: `micro/programs/cmov_select.bpf.o`
  - result: `11332120082118096118`
  - `exec_ns=1512`
  - `directive_scan.total_sites=1`
  - `recompile.requested=true`
  - `recompile.mode=auto-scan-v5`
  - `recompile.applied=true`

### Tetragon Load / Attach Verification

- Raw `bpftool prog loadall ... autoattach` no longer fails due missing syscall tracepoints, but it is not sufficient for this object because one program does not autoattach cleanly and the pinning flow fails.
- The repo’s direct-object Tetragon harness was used for the authoritative check:
  - command form: `PYTHONPATH=micro python3 e2e/run_e2e_tetragon.py --force-direct --smoke --bpftool /usr/local/sbin/bpftool`
  - summary:
    - `Targets=3`
    - `Stock OK=3`
    - `ReJIT OK=3`
- Per target:
  - `event_execve` on `syscalls/sys_enter_execve`: `stock=ok`, `rejit=ok`
  - `generic_kprobe_event` on `security_file_open`: `stock=ok`, `rejit=ok`
  - `generic_kprobe_event` on `security_socket_connect`: `stock=ok`, `rejit=ok`

## Issues / Notes

- `/proc/config.gz` is not available in this kernel, so the exact `zcat /proc/config.gz` check from the task could not be used. Runtime validation was done with host `.config` plus in-guest feature probes.
- In the guest, `/usr/sbin/bpftool` is an Ubuntu wrapper that looks for a kernel-version-matched package and fails for this custom kernel. `/usr/local/sbin/bpftool` works and was used for validation.
- `vng` prints `vendor/linux-framework/modules.order not found ... kernel modules disabled` on boot. This is informational here because modules are disabled and did not block boot or BPF validation.
- The `.config` change was left as a local build artifact and was not committed.
