# tracee/monitor source-opt attempt: phase2-hot-syscall-arg-count

- Time: 2026-06-25 22:07
- App: `tracee/monitor`
- Status: rejected-no-signal
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
- Result path: `corpus/results/x86_kvm_corpus_20260626_051548_824007`
- Performance: `stress_ng_sum_bogo_ops_s mean=456957.04`, samples
  `453757.34, 460873.01, 456240.77`, -0.85% vs clean baseline.
- Follow-up: correctness passed, but the added syscall-id branching did not
  pay for itself on this workload. Do not use this patch as a stacked base.
