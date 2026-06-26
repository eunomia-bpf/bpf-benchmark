# tracee/monitor source-opt attempt: phase2-hot-syscall-arg-count

- Time: 2026-06-25 22:07
- App: `tracee/monitor`
- Status: planned
- Source file:
  - `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: `sys_enter_init()` currently reads six syscall arguments for
  every traced syscall. For x86 hot syscalls covered by
  `stress_ng_tracee_syscall_hot`, Tracee event definitions need fewer
  arguments. Reading only the needed argument slots reduces raw syscall
  fixed cost without changing event payloads.
- Expected hot path: `cap`, `set`, `sigfd`, `eventfd`, `kill`, and `prctl`
  stressors repeatedly enter `sys_enter_init()` before `sys_exit_submit()`.
- Correctness argument: only explicitly listed x86 syscall IDs use reduced
  argument counts, and each count matches Tracee's event field definition.
  Unknown or unlisted syscall IDs keep the original six-argument read path.
- Build command: `make -C vendor tracee-x86`
- Run command: see `run-command.sh`
- Result path: TBD
- Follow-up: this is the final planned tracee phase2 attempt. Keep only if it
  passes correctness and improves over the clean baseline.
