# Tetragon E2E VM Summary

- Framework kernel recompile syscall check: **supported**. Verified separately in the same VM with `micro_exec run-kernel --program micro/programs/cmov_select.bpf.o --repeat 1 --recompile-v5 --recompile-cmov --compile-only`, which returned `"applied": true` for `BPF_PROG_JIT_RECOMPILE`.
- Tetragon end-to-end recompile: **did not succeed**. No Tetragon target reached a successful stock attach/load in this VM, so there are no stock-vs-rejit timing pairs.

## Per-Program

| Program | Attach target | Sites | Stock avg_ns | ReJIT avg_ns | Speedup | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| event_execve | syscalls/sys_enter_execve | 37 | n/a | n/a | n/a | event_execve attach failed: No such file or directory |
| generic_kprobe_event | security_file_open | 0 | n/a | n/a | n/a | bpf_object__load failed: Invalid argument |
| generic_kprobe_event | security_socket_connect | 0 | n/a | n/a | n/a | bpf_object__load failed: Invalid argument |

## Overall Assessment

- The framework kernel branch in the VM does support `BPF_PROG_JIT_RECOMPILE`, but the current Tetragon direct-object benchmark is blocked earlier by kernel feature/config gaps.
- `event_execve` loads and scans to 37 candidate sites, but the attach target `syscalls/sys_enter_execve` is unavailable in this VM (`/sys/kernel/tracing/events/syscalls` is missing), so neither stock nor re-JIT can run honestly.
- `bpf_generic_kprobe.bpf.o` fails at load time because the `generic_kprobe_override` program is rejected by the verifier (`bpf_override_return` not allowed for this program type on this kernel), so both kprobe targets fail before any scan/recompile/measurement step.
- Secondary diagnostic: the guest user cannot create pin directories under `/sys/fs/bpf` without `sudo`, but that only affects the optional `bpftool` probe path and is not the primary reason the benchmark failed.
- Net result: this VM/kernel combination is sufficient for validating the syscall itself, but not yet sufficient for collecting Tetragon end-to-end stock vs re-JIT performance numbers.
